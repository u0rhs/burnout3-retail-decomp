#!/usr/bin/env python3
"""group_prove.py <candidates.json> [--group 10]: prove hand-finished ("manual") candidates in groups.

tools/tiny_batch.py proves one function at a time: compile + diff (seconds), then two full relinks (the all-asm link
after splitting the function out of its chunk, and tools/wire_in_full_check.sh with the C object wired in), about
80 s a function. The relinks dominate, so this proves a group of functions with one pair of relinks: each one is
compiled and diffed first (the same compile_and_diff, .lit4 retarget included), then all are split out of their
chunks, one all-asm link must still reproduce retail, all objects are wired in, and one wire_in_full_check must
say MATCHES RETAIL. A failing group is rolled back and halved until the culprit is alone; a lone failure is left
for tools/tiny_batch.py (which retries it and records why it parks). One commit per proven group; tiny_batch.log
gets a PROVEN line per function, so the batch that follows skips them. Stops between groups on
build/tiny_batch.stop (left in place for the batch)."""
import json
import os
import shutil
import subprocess
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import tiny_batch as tb  # noqa: E402

SHARED = ["config/b3_retail.yaml", "build/SLUS_210.50.clean.ld", "config/proven_units.txt", "tools/wire_in_batch.sh",
          "docs/layout.md", "build/lit4_retarget_defs.txt", "build/jtbl_retarget_defs.txt"]
BAK = "build/batch_bak/group"


def layout_row(c, src_rel):
    if c.get("manual") and not c["name"].startswith("func_"):
        return ("| `%s` | placed + proven %s (batch, hand-written) | `[C]` name: retail tables (%s); file `%s` "
                "(retail_names.csv). Area not evidenced. |\n" % (src_rel, time.strftime("%Y-%m-%d"),
                                                                c.get("conf") or "high", c.get("file")))
    return ("| `%s` | placed + proven %s (batch, hand-written) | Unnamed (`func_` placeholder, C linkage); file and "
            "Area unknown. |\n" % (src_rel, time.strftime("%Y-%m-%d")))


def try_group(group):
    """Prove every candidate of group together -> True (committed) or False (rolled back)."""
    os.makedirs(BAK, exist_ok=True)
    index_backup = dict(tb._where)
    chunks = []
    for c in group:
        ch = tb.where(c["name"])
        if ch and ch not in chunks:
            chunks.append(ch)
    touched = SHARED + ["assembly/asm/%s.s" % ch for ch in chunks]
    for t in touched:
        shutil.copy(t, os.path.join(BAK, t.replace("/", "__")))
    created = []
    names = [c["name"] for c in group]
    msg = "Batch group: %d hand-finished functions (%s)" % (len(group), ", ".join(n[:40] for n in names[:6]) +
                                                              (", ..." if len(names) > 6 else ""))
    tb.mark(dict(name=names[0], unit="(group)", addr=group[0]["addr"], size=0, kind="manual", chunk=chunks[0],
                 chunks=chunks, touched=touched, bak=BAK, created=created, commit=msg))
    try:
        pieces = {}
        units = []
        for c in group:
            src_rel = c["manual"]
            unit = os.path.splitext(os.path.basename(src_rel))[0]
            ch = tb.where(c["name"])
            if not ch or not ch.startswith("game/"):
                raise RuntimeError("%s: not in a game/ chunk" % c["name"])
            ps, removed = tb.isolate(c, unit)
            for p, v in ps:
                pieces[p] = v
                if p not in chunks and "assembly/asm/%s.s" % p not in created:
                    created += ["assembly/asm/%s.s" % p, "build/assembly/asm/%s.o" % p]
            units.append((c, unit, src_rel))
        live = [(p, v) for p, v in pieces.items() if os.path.exists("assembly/asm/%s.s" % p)]
        tb.mark(dict(name=names[0], unit="(group)", addr=group[0]["addr"], size=0, kind="manual", chunk=chunks[0],
                     chunks=chunks, touched=touched, bak=BAK, created=created, commit=msg))
        ok, res = tb.asm_check(live)
        if not ok:
            raise RuntimeError("all-asm link changed: " + res)
        extra = []
        for c, unit, src_rel in units:
            shutil.copy("build/batch/%s.o" % unit, "build/mw/%s.o" % unit)
            created.append("build/mw/%s.o" % unit)
            script = tb.lit4_script(c, unit, src_rel)
            if script:
                created.append(script)
                extra.append(script)
            open("config/proven_units.txt", "a", newline="\n").write(
                "0x%X,0x%X,1,%s,%s\n" % (c["addr"], c["size"], unit, src_rel))
            open("tools/wire_in_batch.sh", "a", newline="\n").write(
                "cp build/mw/%s.o build/assembly/asm/b3/_unclassified/%s.o\n" % (unit, unit))
        rc, o = tb.wsl("bash tools/wire_in_full_check.sh 2>&1 | grep -v RWX | tail -2")
        if "MATCHES RETAIL" not in o:
            raise RuntimeError("wire-in: " + o.strip()[-160:])
        with open("docs/layout.md", "a", newline="\n") as f:
            for c, unit, src_rel in units:
                f.write(layout_row(c, src_rel))
        files = [src for _, _, src in units] + SHARED + extra
        for c, _, _ in units:
            files += c.get("extra", [])
        tb.git_commit(files, msg)          # never rolls a verified proof back (tiny_batch.git_commit)
        for c, unit, _ in units:
            tb.log({"status": "PROVEN", "name": c["name"], "unit": unit, "addr": c["addr"], "size": c["size"],
                    "kind": "manual", "note": "group of %d" % len(group)})
        os.remove(tb.MARK)
        return True
    except Exception as e:
        for t in touched:
            shutil.copy(os.path.join(BAK, t.replace("/", "__")), t)
        for f in created:
            if os.path.exists(f):
                os.remove(f)
        for ch in chunks:
            tb.reassemble(ch)
        tb._where.clear()
        tb._where.update(index_backup)
        os.remove(tb.MARK)
        print("group of %d rolled back: %s" % (len(group), str(e)[:160]), flush=True)
        return False


def prove(group, out):
    if not group or os.path.exists("build/tiny_batch.stop"):
        return
    if try_group(group):
        out += [c["name"] for c in group]
        return
    if len(group) == 1:
        return                      # left for tiny_batch.py
    h = len(group) // 2
    prove(group[:h], out)
    prove(group[h:], out)


def main():
    if not tb.recover():
        return
    cands = [c for c in json.load(open(sys.argv[1])) if c.get("manual")]
    size = int(sys.argv[sys.argv.index("--group") + 1]) if "--group" in sys.argv else 10
    proven = set()
    if os.path.exists(tb.LOG):
        for l in open(tb.LOG):
            r = json.loads(l)
            if r.get("status") == "PROVEN":
                proven.add(r["name"])
    ready = []
    for c in cands:
        if c["name"] in proven or not os.path.exists(c["manual"]):
            continue
        unit = os.path.splitext(os.path.basename(c["manual"]))[0]
        ok, res = tb.compile_and_diff(c, unit, c["manual"])
        if ok:
            ready.append(c)
        else:
            print("not ready (left for the batch): %s: %s" % (c["name"], res[:120]), flush=True)
    out = []
    for i in range(0, len(ready), size):
        if os.path.exists("build/tiny_batch.stop"):
            break
        prove(ready[i:i + size], out)
    print("group_prove: %d of %d proven" % (len(out), len(cands)), flush=True)


if __name__ == "__main__":
    main()
