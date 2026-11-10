"""cycle.py [--cycles N] [--max 150]: the batch pipeline (docs/progress.md "Unattended plan", approved
2026-10-24). Each cycle:

  0. promote: if build/cycle/PROMOTE exists, copy build/vt/tools2/tiny_lift.py over tools/tiny_lift.py (the scratch
     copy lifter work happens in -- never edited live), commit it, delete the flag;
  1. queue: a fresh scan (tools/tiny_scan.py, <= 4 KB functions), keep the unproven ones the current lifter generates
     and that were not tried under this lifter (build/cycle/tried.json: name -> lifter hash), smallest first, <= --max;
  2. batch: tools/run_queue.py over it (each proof wired in, checked against retail and committed by tiny_batch.py);
  3. housekeeping: header consolidation (tools/hc_iterate.py --apply, then tools/verify_all.sh: any unit not identical
     -> the consolidation is reverted), translation-unit regrouping (tools/tu_merge.py: per-unit relink checks inside),
     docs/layout.md table; then the gate tools/verify_all.sh + tools/wire_in_full_check.sh;
  4. commit the snapshot (the hooks push it).

Stops before the next cycle when build/cycle.stop or build/run_chain.stop exists, when no candidates are left, or
when the build stops matching retail and reverting the cycle's housekeeping doesn't restore it -- then it writes
build/cycle/STOPPED with the reason. Log: build/cycle/log.txt (one block per cycle)."""
import glob
import hashlib
import json
import os
import shutil
import subprocess
import sys
import time
# run bash directly on Linux (repo on WSL's filesystem), through wsl.exe from Windows
BASH = ["bash"] if os.name != "nt" else ["wsl.exe", "bash"]

sys.path.insert(0, "tools")
REPO = "${B3_ROOT}"
D = "build/cycle"
RETRY_CAP = 40       # retries of parked functions per cycle (build_queue)
os.makedirs(D, exist_ok=True)
LOG = open(os.path.join(D, "log.txt"), "a", buffering=1)


def log(s):
    line = "%s %s" % (time.strftime("%Y-%m-%d %H:%M:%S"), s)
    print(line, flush=True)
    LOG.write(line + "\n")


def sh(cmd, timeout=None):
    r = subprocess.run(cmd, shell=isinstance(cmd, str), capture_output=True, text=True, timeout=timeout)
    return r.returncode, r.stdout + r.stderr


def wsl(cmd, timeout=None):
    return sh(BASH + ["-c", "cd %s && %s" % (REPO, cmd)], timeout)


def git(*a):
    rc, out = sh(["git"] + list(a))
    if rc != 0 and a[0] in ("add", "commit"):
        log("  git %s failed (rc %d): %s" % (a[0], rc, out.strip().replace("\n", " | ")[-200:]))
    return rc, out


def lifter_hash():
    # the lifter and the helper modules it imports: a change to a helper alone must re-check earlier refusals too
    h = hashlib.sha1()
    for f in ("tools/tiny_lift.py", "tools/callee_sig.py"):
        if os.path.exists(f):
            h.update(open(f, "rb").read())
    return h.hexdigest()[:12]


def stopped():
    return os.path.exists("build/cycle.stop") or os.path.exists("build/run_chain.stop")


def gate():
    """(ok, text): every proven unit recompiles identically and the full link matches retail."""
    rc, out = wsl("bash tools/verify_all.sh")
    res = open("build/va/result.txt").read().split("\n")
    bad = [l for l in res if l and not l.startswith("SAME")]
    rc2, out2 = wsl("bash tools/wire_in_full_check.sh 2>&1 | grep -v RWX | tail -2")
    ok = not bad and "MATCHES RETAIL" in out2
    return ok, "verify_all: %d not identical%s; %s" % (len(bad), (" (" + bad[0][:120] + ")") if bad else "",
                                                        out2.strip().split("\n")[-1])


def promote():
    if not os.path.exists(os.path.join(D, "PROMOTE")):
        return
    src = "build/vt/tools2/tiny_lift.py"
    msg = open(os.path.join(D, "PROMOTE")).read().strip() or "tiny_lift: promoted from the scratch copy"
    log("tried entries keyed to their generated source: %d" % migrate_tried())
    shutil.copy(src, "tools/tiny_lift.py")
    git("add", "tools/tiny_lift.py")
    for mod in ("callee_sig.py",):           # helper modules the scratch lifter imports
        if os.path.exists("build/vt/tools2/" + mod):
            shutil.copy("build/vt/tools2/" + mod, "tools/" + mod)
            git("add", "tools/" + mod)
    rc, out = git("commit", "-q", "-m", msg)
    os.remove(os.path.join(D, "PROMOTE"))
    log("promoted the scratch lifter: %s" % msg.split("\n")[0])


def gen_key(tiny_lift, tiny_batch, c):
    """A hash of what the batch would try for c (variant 0's source + the variant list), or None if refused."""
    try:
        g, w = tiny_lift.generate(c, tiny_batch.class_has_header)
    except Exception:
        g = None
    if not g:
        return None
    return hashlib.sha1((g[0] + repr(list(tiny_lift.LAST_VARIANTS))).encode()).hexdigest()[:16]


def build_queue(maxn):
    """tried.json: name -> lifter hash (refused under that lifter) or {"gen": key} (tried with that source: only
    re-queued when a lifter change alters what it generates)."""
    import importlib
    import tiny_batch
    import tiny_lift
    import callee_sig
    importlib.reload(callee_sig)          # helper modules first: a promotion may have replaced them too (cloud review
    importlib.reload(tiny_lift)           # 2026-10-28: only tiny_lift was reloaded, so an old callee_sig stayed live)
    rc, out = sh([sys.executable, "tools/tiny_scan.py", "--max", "0x1000", "--func", "--lift-only", "--branch",
                  "--medium"])
    cands = json.loads(out[out.index("["):]) if "[" in out else []
    tried_p = os.path.join(D, "tried.json")
    tried = json.load(open(tried_p)) if os.path.exists(tried_p) else {}
    h = lifter_hash()
    proven = open("config/proven_units.txt").read()
    q = []
    for c in cands:
        t = tried.get(c["name"])
        if c["name"] in proven or t == h or not tiny_batch.where(c["name"]):
            continue
        k = gen_key(tiny_lift, tiny_batch, c)
        if k is None:
            tried[c["name"]] = h              # refused under this lifter: no need to re-check until it changes
        elif not (isinstance(t, dict) and t.get("gen") == k):
            c["_gen"] = k
            c["_retry"] = isinstance(t, dict)    # tried before with another source: rarely matches, costs most
            q.append(c)
    # never-tried candidates first; retries (a changed source of a parked function) capped per cycle so a lifter
    # change that touches many parked functions cannot hold back the next promotion for hours (cycle 16)
    new = sorted((c for c in q if not c["_retry"]), key=lambda c: c["size"])
    old = sorted((c for c in q if c["_retry"]), key=lambda c: c["size"])
    q = (new + old[:RETRY_CAP])[:maxn]
    # hand-finished near-misses (build/cycle/manual.json: candidates with "manual": <src path>, matched by hand)
    # go first; the file is consumed
    man = []
    for mp in sorted(glob.glob(os.path.join(D, "manual*.json"))):   # manual.json, manual_<helper>.json
        man += json.load(open(mp))
        os.remove(mp)
    if man:
        names = {c["name"] for c in man}
        q = man + [c for c in q if c["name"] not in names]
        log("  manual candidates queued: %d" % len(man))
    json.dump(tried, open(tried_p, "w"))
    return q, h


def mark_tried(q, h, out):
    """Only the candidates the batch logged (a stopped batch leaves the rest untried)."""
    tried_p = os.path.join(D, "tried.json")
    tried = json.load(open(tried_p)) if os.path.exists(tried_p) else {}
    logged = open(out).read() if os.path.exists(out) else ""
    for c in q:
        if c["name"][:60] in logged:
            tried[c["name"]] = {"gen": c.get("_gen")}
    json.dump(tried, open(tried_p, "w"))


def park_manual(q):
    """A hand-finished source the batch did not prove leaves src/ (it is not matched source) for
    build/vt/hand/failed/, so the snapshot commit does not file it as a unit."""
    proven = open("config/proven_units.txt").read()
    for c in q:
        p = c.get("manual")
        # proven_units.txt lists unit names and source paths (not mangled names): match the source path
        if p and os.path.exists(p) and ("," + p) not in proven:
            os.makedirs("build/vt/hand/failed", exist_ok=True)
            os.replace(p, os.path.join("build/vt/hand/failed", os.path.basename(p)))
            log("  manual candidate not proven, parked: %s" % c["name"])


def migrate_tried():
    """Old entries (a lifter hash for a tried candidate) -> {"gen": key} under the lifter in tools/ (run before a
    promotion replaces it), so a promotion re-queues only what it changes."""
    import tiny_batch
    import tiny_lift
    tried_p = os.path.join(D, "tried.json")
    tried = json.load(open(tried_p)) if os.path.exists(tried_p) else {}
    queued = {}
    for f in os.listdir(D):
        if f.startswith("queue") and f.endswith(".json"):
            for c in json.load(open(os.path.join(D, f))):
                queued[c["name"]] = c
    n = 0
    for name, c in queued.items():
        if isinstance(tried.get(name), str):
            k = gen_key(tiny_lift, tiny_batch, {x: y for x, y in c.items() if x != "_gen"})
            if k:
                tried[name] = {"gen": k}
                n += 1
    json.dump(tried, open(tried_p, "w"))
    return n


def housekeeping(n):
    # header consolidation, gated: revert unless every unit stays identical (paused while build/cycle/NO_HC exists:
    # since cycle 20 every run broke ~85 already-adopted units, e.g. B3OnlineSelectLoginPage_00349840 -- open)
    if os.path.exists(os.path.join(D, "NO_HC")):
        log("  headers: consolidation paused (build/cycle/NO_HC)")
        return regroup(n)
    rc, out = sh([sys.executable, "-u", "tools/hc_iterate.py", "--apply"])
    log("  headers: %s" % " ".join(out.strip().split("\n")[-2:])[:200])
    if rc != 0:
        # hc_iterate stopped (no fixpoint / verifier failure) before --apply: nothing was installed
        git("checkout", "--", "src", "include")
        git("clean", "-fdq", "--", "include")
        return regroup(n)
    ok, why = gate()
    if not ok:
        # hc_iterate verifies only the units adopting a header this round; units that broke in the full gate are
        # excluded from consolidation from now on, so the next cycle consolidates around them (self-healing)
        bad = [l.split()[1] for l in open("build/va/result.txt").read().split("\n")
               if l and not l.startswith("SAME") and len(l.split()) > 1]
        ex = set(open("build/hc/exclude.txt").read().split()) if os.path.exists("build/hc/exclude.txt") else set()
        new = sorted({os.path.basename(b) for b in bad} - ex)
        if len(new) > 60:
            # far more than a header change plausibly breaks: an environment/verifier failure, not evidence against
            # these units (cloud review 2026-10-28) -- exclude nothing and pause consolidation for a human to look
            open(os.path.join(D, "NO_HC"), "w").write("paused %s: gate failure after consolidation with %d non-SAME units "
                                                      "(suspected environment failure; nothing excluded)\n"
                                                      % (time.strftime("%Y-%m-%d %H:%M"), len(new)))
            new = []
        if new:
            with open("build/hc/exclude.txt", "a") as f:
                f.write("".join(n + "\n" for n in new))
        git("checkout", "--", "src", "include")
        git("clean", "-fdq", "--", "include")     # new consolidated headers are untracked: checkout leaves them
        log("  headers reverted (%s); %d units excluded from consolidation" % (why, len(new)))
    else:
        git("add", "src", "include")
        git("commit", "-q", "-m", "Cycle %d: header consolidation (tools/hc_iterate.py; verify_all identical, MATCHES RETAIL)" % n)
    return regroup(n)


def regroup(n):
    # translation-unit regrouping (each unit relinked against retail before it is installed)
    def tu_paths():
        try:
            return {l.split()[0] for l in open("config/tu_units.txt") if l.strip() and not l.startswith("#")}
        except OSError:
            return set()
    before = tu_paths()
    rc, out = sh([sys.executable, "-u", "tools/tu_merge.py", "--jobs", "24"])
    created = tu_paths() - before        # merged TU sources this run wrote (untracked until committed)
    inst = [l for l in out.split("\n") if l.startswith("installed")]
    log("  regrouping: %s" % (inst[-1] if inst else out.strip().split("\n")[-1][:160]))
    sh([sys.executable, "tools/layout_tu_table.py"])
    ok, why = gate()
    if not ok:
        for p in created:              # checkout does not remove new files; leave no orphan merged TU behind
            if git("ls-files", "--error-unmatch", p)[0] != 0 and os.path.exists(p):
                os.remove(p)
        git("checkout", "--", "src", "config", "docs/layout.md")
        wsl("bash tools/tu_build.sh")
        ok2, why2 = gate()
        log("  regrouping reverted (%s) -> %s" % (why, why2))
        if not ok2:
            return False, why2
    else:
        git("add", "src", "config", "docs/layout.md")
        if git("diff", "--cached", "--quiet")[0] != 0:      # nothing staged when no unit was regrouped
            git("commit", "-q", "-m", "Cycle %d: translation-unit regrouping (tools/tu_merge.py; MATCHES RETAIL)" % n)
    return True, why


def main():
    cycles = int(sys.argv[sys.argv.index("--cycles") + 1]) if "--cycles" in sys.argv else 1000
    maxn = int(sys.argv[sys.argv.index("--max") + 1]) if "--max" in sys.argv else 150
    state_p = os.path.join(D, "state.json")
    state = json.load(open(state_p)) if os.path.exists(state_p) else {"cycle": 0}
    for _ in range(cycles):
        if stopped():
            log("stop file present: not starting a cycle")
            break
        state["cycle"] += 1
        n = state["cycle"]
        json.dump(state, open(state_p, "w"))
        promote()
        q, h = build_queue(maxn)
        log("cycle %d: lifter %s, queue %d candidates" % (n, h, len(q)))
        if q:
            qp = os.path.join(D, "queue%d.json" % n)
            out = os.path.join(D, "batch%d.txt" % n)
            json.dump(q, open(qp, "w"))
            if any(c.get("manual") for c in q):
                # hand-finished candidates first, in groups (one pair of relinks per group: tools/group_prove.py)
                rc, o = sh([sys.executable, "-X", "faulthandler", "-u", "tools/group_prove.py", qp])
                for _l in o.strip().split("\n")[:-1]:      # why a hand-finished candidate wasn't proven (L264)
                    if _l.startswith(("not ready", "group of")):
                        log("  %s" % _l[:400])
                log("  %s" % (o.strip().split("\n")[-1] if o.strip() else "group_prove: no output (rc %s)" % rc))
            rc, o = sh([sys.executable, "-X", "faulthandler", "-u", "tools/run_queue.py", qp, out])
            mark_tried(q, h, out)
            log("  batch: %s" % o.strip().split("\n")[-1])
            park_manual(q)
        ok, why = housekeeping(n)
        log("  gate: %s" % why)
        if not ok:
            open(os.path.join(D, "STOPPED"), "w").write("cycle %d: the build no longer matches retail after "
                                                       "reverting its housekeeping: %s\n" % (n, why))
            log("STOPPED: %s" % why)
            sys.exit(1)
        sh([sys.executable, "tools/progress_report.py"])
        # `git add -A` can collide with hand matching rewriting their scratch files (cycle 19: "failed to
        # insert into database"): retry a few times before giving up on the snapshot
        for attempt in range(5):
            rc, _ = git("add", "-A")
            if rc == 0:
                break
            time.sleep(30)
        git("commit", "-q", "-m", "Cycle %d snapshot (%d candidates queued; %s)" % (n, len(q), why[:80]))
        if not q:
            log("no candidates left for this lifter: waiting for a promotion or hand-finished candidates")
            while not (stopped() or os.path.exists(os.path.join(D, "PROMOTE"))
                       or glob.glob(os.path.join(D, "manual*.json"))):
                time.sleep(60)


if __name__ == "__main__":
    main()
