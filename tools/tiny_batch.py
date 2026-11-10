#!/usr/bin/env python3
"""Tiny-function batch: generate, verify, split, wire in and commit template-able functions one by one.

Input: the JSON from tools/tiny_scan.py. For each candidate, sequentially:
  1. generate C/C++ from its template (tools/tiny_gen.py) into src/b3/_unclassified/<File>_<ADDR>.cpp (or
     func_XXXXXXXX.cpp), declaring classes locally with only what it touches (placeholder names, widths from the
     instructions); skipped if the class already has a header in include/. A candidate with "manual": <src path>
     uses that hand-written file instead (kept on failure; "extra": more files to commit, e.g. headers);
  2. compile it and diff it against the function in its current asm chunk (must be 0 changed, same length, no data);
  3. split the function out of its chunk into its own asm unit, re-assemble the pieces and check the all-asm link
     still reproduces retail (SHA-1 817cfb41...);
  4. register it (config/proven_units.txt, tools/wire_in_batch.sh) and run tools/wire_in_full_check.sh -> MATCHES RETAIL;
  5. append its docs/layout.md row and commit.
Any failure restores every file it touched and moves on; the reason goes to build/tiny_batch.log (JSON lines).
Run from Git Bash in the repo root:  python tools/tiny_batch.py build/tiny_candidates.json [--limit N] [--dry]
"""
import json, os, re, shutil, subprocess, sys, time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import tiny_gen  # noqa: E402
import tiny_lift  # noqa: E402
# run bash directly on Linux (repo on WSL's filesystem), through wsl.exe from Windows
BASH = ["bash"] if os.name != "nt" else ["wsl.exe", "bash"]

REPO = os.getcwd()
WSL_REPO = "${B3_ROOT}"
RETAIL_SHA = "817cfb412af2d81d4b5fda7b57837b4e28442dfc"
LOG = "build/tiny_batch.log"

def wsl(cmd, timeout=1800):
    r = subprocess.run(BASH + ["-c", "cd %s && %s" % (WSL_REPO, cmd)], capture_output=True, text=True,
                       timeout=timeout, env=dict(os.environ, MSYS_NO_PATHCONV="1"))
    return r.returncode, r.stdout + r.stderr


def git_commit(files, msg):
    """Stage and commit a proven unit's files. The proof is already verified by the full link at this point, so a git
    failure (index.lock held by a concurrent commit) must not roll it back: retry, then leave the files for the next
    snapshot commit (cloud review 2026-10-28: a failed commit used to restore the working tree but not the index, so
    the staged files rode along with the next candidate and the proven function was logged PARKED)."""
    for attempt in range(6):
        a = subprocess.run(["git", "add"] + files, capture_output=True)
        c = subprocess.run(["git", "commit", "-q", "-m", msg], capture_output=True) if a.returncode == 0 else a
        if c.returncode == 0:
            return True
        time.sleep(5)
    sys.stderr.write("git commit deferred (%s): %s\n" % (msg[:60], (c.stderr or b"").decode(errors="replace")[-200:]))
    return False


def log(rec):
    rec["time"] = time.strftime("%H:%M:%S")
    with open(LOG, "a") as f:
        f.write(json.dumps(rec) + "\n")
    print("%-8s %-60s %s" % (rec.get("status"), rec.get("name", "")[:60], rec.get("reason", "")), flush=True)


_headers = None


def class_has_header(cls):
    global _headers
    if _headers is None:
        _headers = ""
        for root, _, files in os.walk("include"):
            if os.path.normpath(root).replace("\\", "/").startswith("include/b3/classes"):
                continue      # tools/hdr_consolidate.py's merged headers: lifted units still declare those locally
            for f in files:
                if f.endswith(".h"):
                    _headers += open(os.path.join(root, f), errors="replace").read()
    return re.search(r"\b(class|struct)\s+%s\b" % re.escape(cls), _headers) is not None


_where = {}


def where(name):
    """The asm file (path under assembly/asm, no extension) that currently holds `name`."""
    if not _where:
        import glob
        y_ = open("config/b3_retail.yaml").read()
        live = set(re.findall(r"asm, (game/unit_[0-9A-F]+)\]", y_))
        # gaps1: the .init static initialiser units are dict-form entries ({ start: ..., type: asm, name: ... })
        live |= set(re.findall(r"type: asm, name: (game/unit_[0-9A-F]+),", y_))
        for f in glob.glob("assembly/asm/game/*.s"):
            rel = f.replace("\\", "/")[len("assembly/asm/"):-2]
            if rel not in live:
                continue
            for m in re.finditer(r"^glabel (\S+)", open(f).read(), re.M):
                _where[m.group(1)] = rel
    return _where.get(name)


# the fixups (VU0 interlock bit, pad destructor: tools/vu0_ni_fixup.py) run before the retargets, as in tiny_compile.sh --
# reversed, drop_pad_dtor bails out on the retargeted object (UpdateWibbleAnimationIn, cycle 434 gate)
LIT4_SCRIPT = r'''#!/bin/bash
# %(unit)s: float literals in retail's shared .lit4 pool, retargeted after the compile (tools/tiny_batch.py; N23/N64).
set -e
cd ${B3_MWCC_DIR}
export WINEDEBUG=-all
R="Z:${B3_ROOT_WIN}"
export MWCIncludes="$R\include"
export LM_LICENSE_FILE="${B3_LICENSE_WIN}"
. ${B3_ROOT}/tools/mwcc_flags.sh; mwcc_run $MWCC_FLAGS \
  -c "$R\%(src)s" \
  -o "$R\build\mw\%(unit)s.o"
echo "COMPILE EXIT: $?"
cd ${B3_ROOT}
python3 -I tools/vu0_ni_fixup.py build/mw/%(unit)s.o > /dev/null
'''
LIT4_LINE = ("python3 -I tools/lit4_retarget.py build/mw/%(unit)s.o orig/SLUS_210.50.rom build/lit4_retarget_defs.txt "
             "--apply --addr %(name)s=0x%(addr)X | tail -3\n")
# switch jump tables: retarget at retail's own table in the shared .rodata (tools/jtbl_retarget.py, entry by entry)
JTBL_LINE = ("python3 -I tools/jtbl_retarget.py build/mw/%(unit)s.o orig/SLUS_210.50.rom build/jtbl_retarget_defs.txt "
             "%(name)s=0x%(addr)X --apply | tail -2\n")
# local-array initialisers (MWCC's @NN templates in .sdata): retarget at retail's copy in the shared .sdata
# (tools/sdata_retarget.py; defs go to build/lit4_retarget_defs.txt, which every link and diff_vs_retail already read)
SDATA_TOOL = "tools/sdata_retarget.py"
SDATA_LINE = ("python3 -I %(tool)s build/mw/%(unit)s.o orig/SLUS_210.50.rom build/lit4_retarget_defs.txt "
              "%(name)s=0x%(addr)X --apply | tail -2\n")


def lit4_script(c, unit, src_rel):
    """A proven unit whose object has a .lit4 section (float literals), a .rodata section (switch jump tables) and/or
    a .sdata section (local-array initialisers): write tools/compile_<unit>.sh that compiles it and retargets them at
    retail's copies (verify_all.sh rebuilds such units with their script; tu_merge.py leaves them out of merged files)
    -> its path, or None."""
    rc, secs = wsl("mips-linux-gnu-readelf -SW build/batch/%s.o | grep -oE ' \\.(lit4|rodata|sdata|sbss) ' | sort -u" % unit)
    kinds = set(secs.split())
    if not kinds:
        return None
    v = {"unit": unit, "src": src_rel.replace("/", "\\"), "name": c["name"], "addr": c["addr"], "tool": SDATA_TOOL}
    body = LIT4_SCRIPT % v
    if ".lit4" in kinds:
        body += LIT4_LINE % v
    if ".rodata" in kinds:
        body += JTBL_LINE % v
    if ".sdata" in kinds or ".sbss" in kinds:     # .sbss: function-local statics (near1; same tool)
        body += SDATA_LINE % v
    path = "tools/compile_%s.sh" % unit.lower()
    open(path, "w", newline="\n").write(body)
    return path


def rodata_used_by_code(obj):
    """The .rodata symbols the object's code refers to, besides retargeted jump tables (jtbl_*). .rodata no code refers
    to -- a key function's RTTI (__RTTI__*, its @NNN class-name strings; referenced only from .rel.rodata/.rel.vtables)
    -- never reaches the link: the ld script takes .text and /DISCARD/s the rest, and wire_in_full_check.sh weakens
    __vt__* (objcopy also turns MWCC's binding-13 __RTTI__ symbols LOCAL), as for the proven component units
    (B3HeadingComponent_003193D0 ...). A string or constant table loaded by code still parks."""
    rc, secs = wsl("mips-linux-gnu-readelf -SW %s" % obj)
    rod = {m.group(1) for m in re.finditer(r"^\s*\[\s*(\d+)\]\s+\.rodata\s", secs, re.M)}
    rc, st = wsl("mips-linux-gnu-readelf -sW %s" % obj)
    # last two fields (Ndx, Name): MWCC's binding-13 symbols print as "<processor specific>: 13", two extra fields
    in_rod = {p[-1] for p in (l.split() for l in st.splitlines()) if len(p) >= 8 and p[0].endswith(":") and p[-2] in rod}
    rc, rl = wsl("mips-linux-gnu-readelf -rW %s" % obj)
    used, cur = set(), None
    for line in rl.splitlines():
        m = re.match(r"^Relocation section '([^']+)'", line)
        if m:
            cur = m.group(1)
            continue
        p = line.split()
        if cur == ".rel.text" and len(p) >= 5 and re.fullmatch(r"[0-9a-f]{8}", p[0]):
            if p[4] in in_rod or p[4] == ".rodata":
                used.add(p[4])
    return {s for s in used if not s.startswith("jtbl_")}


def compile_and_diff(c, unit, src_rel):
    out = "build/batch/%s.o" % unit
    os.makedirs("build/batch", exist_ok=True)
    rc, o = wsl("bash tools/tiny_compile.sh %s %s" % (src_rel, out))
    if rc != 0 or "rror" in o or not os.path.exists(out):
        return False, "compile: " + o.strip().splitlines()[-1][:120] if o.strip() else "compile failed"
    rc, secs = wsl("mips-linux-gnu-readelf -SW %s | grep -oE ' \\.(rodata|data|sdata|bss|sbss|lit4|lit8) ' | sort -u" % out)
    kinds = set(secs.split())
    if kinds - {".lit4", ".rodata", ".sdata", ".sbss"}:
        return False, "object has data sections"
    if ".sdata" in kinds or ".sbss" in kinds:
        # .sbss (near1): a function-local static (PresentDrawBuffer's lnRotate = retail D_004E294C), retargeted by the
        # same tool at retail's .sbss dlabel (size checked; no bytes to compare)
        # MWCC's anonymous initialiser of a local array (`unsigned short sep[2] = {0x20, 0};` -> @NN in .sdata, copied
        # with $gp loads): retarget at retail's copy in the shared .sdata (tools/sdata_retarget.py: each reference's
        # retail $gp target, the bytes checked against ours; sdata pass: func_003B8670 -> D_004E1E88, func_00376880 ->
        # D_004E1E38). A global .sdata variable, .rel.sdata or a non-GPREL16 reference stays unsupported (parks).
        rc, r = wsl("python3 -I %s %s orig/SLUS_210.50.rom build/lit4_retarget_defs.txt %s=0x%X --apply"
                    % (SDATA_TOOL, out, c["name"], c["addr"]))
        if rc != 0 or "MISMATCH" in r or "UNSUPPORTED" in r or "redefined" not in r:
            return False, "sdata retarget: " + r.strip().replace("\n", " | ")[-120:]
    if ".rodata" in kinds:
        # switch jump tables: verify ours entry by entry against retail's table and retarget at it
        # (tools/jtbl_retarget.py); anything else in .rodata (strings, constants) stays unsupported
        rc, r = wsl("python3 -I tools/jtbl_retarget.py %s orig/SLUS_210.50.rom build/jtbl_retarget_defs.txt %s=0x%X "
                    "--apply" % (out, c["name"], c["addr"]))
        # "No jump-table references found." is not a failure by itself: a class's key function also emits its RTTI
        # (__RTTI__* + the @NNN name strings, in .rodata) and vtable (.vtables) -- parkfix: Update__16CB3MyBurnoutPage,
        # Update__19CB3PromptsComponentFf, Release__19CB3PromptsComponent (try.py said exact). The check below decides.
        if rc != 0 or "MISMATCH" in r or ("redefined" not in r and "No jump-table references found." not in r):
            return False, "jtbl retarget: " + r.strip().replace("\n", " | ")[-120:]
        left = rodata_used_by_code(out)
        if left:
            return False, "object has .rodata besides jump tables (%s)" % ", ".join(sorted(left))[:80]
    if ".lit4" in kinds:
        # float literals: retarget them at retail's shared .lit4 pool (tools/lit4_retarget.py, N23/N64; each value
        # checked against retail); the unit then gets its own tools/compile_<unit>.sh doing the same (lit4_script)
        rc, r = wsl("python3 -I tools/lit4_retarget.py %s orig/SLUS_210.50.rom build/lit4_retarget_defs.txt --apply "
                    "--addr %s=0x%X" % (out, c["name"], c["addr"]))
        if rc != 0 or "MISMATCH" in r or "SKIP" in r or "redefined" not in r:
            return False, "lit4 retarget: " + r.strip().replace("\n", " | ")[-120:]
    rc, d = wsl("python3 -I tools/diff_vs_retail.py %s assembly/asm/%s.s %s --seq --targets | tail -1" % (out, where(c["name"]), c["name"]))
    m = re.search(r"retail (\d+) instrs, ours (\d+) instrs, (\d+) instrs in changed runs", d)
    if not m:
        return False, "diff: " + d.strip()[:120]
    if m.group(1) != m.group(2) or m.group(3) != "0":
        # a label holding several entries (a stub + an unlabelled or `alabel` second function): the source defines each
        # as its own symbol, so compare retail's whole glabel..endlabel with all of our object's text (a166, a113)
        rc2, nm = wsl("mips-linux-gnu-nm --defined-only %s" % out)
        if len([l for l in nm.splitlines() if len(l.split()) == 3 and l.split()[1] in "Tt"]) > 1:
            rc3, w = wsl("python3 -I build/vt/hand/a146_cmp.py %s assembly/asm/%s.s %s" % (out, where(c["name"]), c["name"]))
            mw = re.search(r"retail (\d+) ours (\d+)", w)
            cw = re.search(r"changed (\d+)", w)
            if mw and cw and mw.group(1) == mw.group(2) and cw.group(1) == "0":
                return True, out
        return False, "diff: " + m.group(0)
    return True, out


def isolate(c, unit):
    """Split c's function out of its chunk; return (new asm paths to assemble with their VRAMs, removed paths)."""
    src = where(c["name"])
    L = open("assembly/asm/%s.s" % src).read().split("\n")
    if L[-1] == "":
        L.pop()
    h = next(i for i, l in enumerate(L) if l.startswith("nonmatching "))
    a = next(i for i, l in enumerate(L) if l.startswith("nonmatching %s," % c["name"]))
    nx = [i for i, l in enumerate(L) if l.startswith("nonmatching ") and i > a]
    b = nx[0] if nx else len(L)
    pre, mid, post = L[h:a], L[a:b], L[b:]
    def vram_of(lines):
        for l in lines:
            m = re.match(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ", l)
            if m:
                return int(m.group(1), 16)
        return None
    for piece in (pre, mid, post):
        t = "\n".join(piece)
        if set(re.findall(r"(\.L[0-9A-F]+)\b", t)) - set(re.findall(r"^\s*(?:jlabel )?(\.L[0-9A-F]+):?", t, re.M)):
            raise RuntimeError("cross-piece label")
    has_pre = any(l.startswith("glabel ") for l in pre)
    has_post = any(l.startswith("glabel ") for l in post)
    midp = "b3/_unclassified/%s" % unit
    pieces = []
    if has_pre:
        pieces.append((src, pre, vram_of(pre)))
    pieces.append((midp, mid, c["addr"]))
    if has_post:
        pv = vram_of(post)
        pieces.append(("game/unit_%08X" % pv, post, pv))
    for path, body, _ in pieces:
        os.makedirs(os.path.dirname("assembly/asm/" + path), exist_ok=True)
        open("assembly/asm/%s.s" % path, "w", newline="\n").write("\n".join(L[:h] + body) + "\n")
    removed = []
    if not has_pre:
        os.remove("assembly/asm/%s.s" % src)
        removed.append(src)
    y = open("config/b3_retail.yaml").read()
    m = re.search(r"      - \[0x([0-9A-F]+), asm, %s\]\n" % re.escape(src), y)
    if m:
        y = y.replace(m.group(0), "".join("      - [0x%06X, asm, %s]\n" % (v - 0x100000, p) for p, _, v in pieces), 1)
    else:
        # gaps1: a dict-form .init unit keeps its form (and its linker_section_order) in every piece
        m = re.search(r"      - \{ start: 0x([0-9A-F]+), type: asm, name: %s, linker_section_order: (\S+) \}[^\n]*\n"
                      % re.escape(src), y)
        if not m:
            raise RuntimeError("yaml entry not found")
        y = y.replace(m.group(0), "".join("      - { start: 0x%06X, type: asm, name: %s, linker_section_order: %s }\n"
                                          % (v - 0x100000, p, m.group(2)) for p, _, v in pieces), 1)
    open("config/b3_retail.yaml", "w", newline="\n").write(y)
    ld = open("build/SLUS_210.50.clean.ld").read()
    old = "        build/assembly/asm/%s.o(.text);\n" % src
    if ld.count(old) != 1:
        raise RuntimeError("ld line not found")
    ld = ld.replace(old, "".join("        build/assembly/asm/%s.o(.text);\n" % p for p, _, _ in pieces))
    open("build/SLUS_210.50.clean.ld", "w", newline="\n").write(ld)
    for p, body, _ in pieces:
        for l in body:
            if l.startswith("glabel "):
                _where[l.split()[1]] = p
    return [(p, v) for p, _, v in pieces], removed


def asm_check(pieces):
    cmds = []
    for p, v in pieces:
        al = next(a for a in (16, 8, 4, 2, 1) if v % a == 0)
        cmds.append("mkdir -p build/assembly/asm/$(dirname %s) && mips-linux-gnu-as -EL -march=r5900 -mabi=o64 -G 0 "
                    "-no-pad-sections -I . -I assembly/include -o build/assembly/asm/%s.o assembly/asm/%s.s" % (p, p, p))
        if al < 16:
            cmds.append("mips-linux-gnu-objcopy --set-section-alignment=.text=%d build/assembly/asm/%s.o" % (al, p))
    cmds.append("mips-linux-gnu-ld -EL -T build/SLUS_210.50.clean.ld build/undefined_syms_auto.txt "
                "config/undefined_syms_manual.txt build/lit4_retarget_defs.txt build/jtbl_retarget_defs.txt "
                "--no-check-sections --no-warn-mismatch -o build/SLUS_210.50.elf.batch 2>&1 | grep -v RWX | head -3")
    cmds.append("mips-linux-gnu-objcopy -O binary -j .main build/SLUS_210.50.elf.batch build/SLUS_210.50.rom.batch")
    cmds.append("sha1sum build/SLUS_210.50.rom.batch")
    rc, o = wsl(" && ".join(cmds))
    return RETAIL_SHA in o, o.strip()[-200:]


def reassemble(path):
    """Re-assemble one restored asm unit (a rollback after isolate() rewrote its object)."""
    t = open("assembly/asm/%s.s" % path).read()
    m = re.search(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ", t, re.M)
    v = int(m.group(1), 16) if m else 16
    al = next(a for a in (16, 8, 4, 2, 1) if v % a == 0)
    cmd = ("mips-linux-gnu-as -EL -march=r5900 -mabi=o64 -G 0 -no-pad-sections -I . -I assembly/include "
           "-o build/assembly/asm/%s.o assembly/asm/%s.s" % (path, path))
    if al < 16:
        cmd += " && mips-linux-gnu-objcopy --set-section-alignment=.text=%d build/assembly/asm/%s.o" % (al, path)
    wsl(cmd)


MARK = "build/batch_bak/INPROGRESS.json"


def mark(d):
    open(MARK, "w").write(json.dumps(d))


def recover():
    """A run killed mid-candidate (the process terminated from outside, 2026-10-23) leaves MARK: undo that candidate
    like the in-run rollback (restore the backups, delete what it created, re-assemble the chunk), unless its commit
    landed; then require a retail build. Returns False if the tree could not be restored."""
    if not os.path.exists(MARK):
        return True
    d = json.load(open(MARK))
    head = subprocess.run(["git", "log", "-1", "--format=%s"], capture_output=True, text=True).stdout.strip()
    if head == d["commit"]:
        print("recover: %s was committed before the stop" % d["name"], flush=True)
        log({"status": "PROVEN", "name": d["name"], "unit": d["unit"], "addr": d["addr"], "size": d["size"],
             "kind": d["kind"], "note": "recovered after commit"})
    else:
        for t in d["touched"]:
            shutil.copy(os.path.join(d["bak"], t.replace("/", "__")), t)
        for f in d["created"]:
            if os.path.exists(f):
                os.remove(f)
        for ch in d.get("chunks", [d["chunk"]]):        # tools/group_prove.py: every chunk of the group
            if os.path.exists("assembly/asm/%s.s" % ch):
                reassemble(ch)
        log({"status": "PARKED", "name": d["name"], "reason": "run stopped mid-candidate (recovered)", "kind": d["kind"]})
        print("recover: rolled back %s" % d["name"], flush=True)
    os.remove(MARK)
    rc, o = wsl("bash tools/wire_in_full_check.sh 2>&1 | grep -v RWX | tail -2")
    if "MATCHES RETAIL" not in o:
        print("recover: the build is not retail; halting: %s" % o.strip()[-160:], flush=True)
        return False
    return True


def main():
    if not recover():
        return
    cands = json.load(open(sys.argv[1]))
    limit = int(sys.argv[sys.argv.index("--limit") + 1]) if "--limit" in sys.argv else len(cands)
    dry = "--dry" in sys.argv
    retry = "--retry" in sys.argv      # retry names logged PARKED/SKIP (e.g. after a generator change)
    proven, tried = set(), set()
    if os.path.exists(LOG):
        for l in open(LOG):
            r = json.loads(l)
            if r.get("status") == "PROVEN":
                proven.add(r["name"])
            elif r.get("status") in ("PARKED", "SKIP"):
                tried.add(r["name"])
    n_ok = 0
    for c in cands[:limit]:
        if os.path.exists("build/tiny_batch.stop"):
            # graceful stop between candidates (create the file; it is removed here)
            os.remove("build/tiny_batch.stop")
            print("stopped by build/tiny_batch.stop", flush=True)
            break
        if c["name"] in proven or (c["name"] in tried and not retry and not c.get("manual")):
            continue
        if c.get("manual"):
            src_rel = c["manual"]
            text, unit = None, os.path.splitext(os.path.basename(src_rel))[0]
        else:
            gen, why = (tiny_lift if c["kind"] == "lift" else tiny_gen).generate(c, class_has_header)
            if not gen:
                log({"status": "SKIP", "name": c["name"], "reason": why, "kind": c["kind"]})
                continue
            text, unit = gen
            src_rel = "src/b3/_unclassified/%s.cpp" % unit
            if os.path.exists(src_rel):
                log({"status": "SKIP", "name": c["name"], "reason": "source file already exists"})
                continue
        if dry:
            print("---", src_rel); print(text)
            continue
        chunk = where(c["name"])
        if not chunk or not chunk.startswith("game/"):
            log({"status": "SKIP", "name": c["name"], "reason": "not in a game/ chunk (%s)" % chunk})
            continue
        index_backup = dict(_where)
        touched = ["config/b3_retail.yaml", "build/SLUS_210.50.clean.ld", "config/proven_units.txt", "tools/wire_in_batch.sh",
                   "docs/layout.md", "assembly/asm/%s.s" % chunk, "build/lit4_retarget_defs.txt",
                   "build/jtbl_retarget_defs.txt"]
        bak = "build/batch_bak"
        os.makedirs(bak, exist_ok=True)
        for t in touched:
            shutil.copy(t, os.path.join(bak, t.replace("/", "__")))
        created = [] if text is None else [src_rel]
        stage = "compile"
        commit_msg = "Batch: %s (0x%X, %s)" % (c["demangled"] or c["name"], c["addr"], c["kind"])
        mk = dict(name=c["name"], unit=unit, addr=c["addr"], size=c["size"], kind=c["kind"], chunk=chunk,
                  touched=touched, bak=bak, created=created, commit=commit_msg)
        mark(mk)
        try:
            if text is not None:
                os.makedirs(os.path.dirname(src_rel), exist_ok=True)
                open(src_rel, "w", newline="\n").write(text)
            ok, res = compile_and_diff(c, unit, src_rel)
            variants = list(tiny_lift.LAST_VARIANTS) if (text is not None and c["kind"] == "lift") else [0]
            tried_texts = {text}
            t_var = time.time()
            for v in variants[1:]:
                if ok or not res.startswith("diff"):
                    break
                if time.time() - t_var > 360:
                    # variants run fewest changes first: past the budget only many-change combinations are left
                    res = "%s | variant budget spent" % res
                    break
                # other source forms (tools/tiny_lift.py: early return vs block if, if/else returns)
                gen2, _ = tiny_lift.generate(dict(c, variant=v), class_has_header)
                if not gen2 or gen2[1] != unit or gen2[0] in tried_texts:
                    continue
                tried_texts.add(gen2[0])
                text = gen2[0]
                open(src_rel, "w", newline="\n").write(text)
                ok, res2 = compile_and_diff(c, unit, src_rel)
                if not ok:
                    res = "%s | variant %d: %s" % (res.split(" | ")[0], v, res2)
            if not ok:
                raise RuntimeError(res)
            stage = "isolate"
            pieces, removed = isolate(c, unit)
            created += ["assembly/asm/%s.s" % p for p, _ in pieces if p != chunk]
            created += ["build/assembly/asm/%s.o" % p for p, _ in pieces if p != chunk]
            mark(mk)
            ok, res = asm_check(pieces)
            if not ok:
                raise RuntimeError("all-asm link changed: " + res)
            stage = "wire"
            shutil.copy("build/batch/%s.o" % unit, "build/mw/%s.o" % unit)
            created.append("build/mw/%s.o" % unit)
            script = lit4_script(c, unit, src_rel)
            if script:
                created.append(script)
                c = dict(c, extra=list(c.get("extra", [])) + [script, "build/lit4_retarget_defs.txt", "build/jtbl_retarget_defs.txt"])
            mark(mk)
            open("config/proven_units.txt", "a", newline="\n").write(
                "0x%X,0x%X,1,%s,%s\n" % (c["addr"], c["size"], unit, src_rel))
            open("tools/wire_in_batch.sh", "a", newline="\n").write(
                "cp build/mw/%s.o build/assembly/asm/b3/_unclassified/%s.o\n" % (unit, unit))
            rc, o = wsl("bash tools/wire_in_full_check.sh 2>&1 | grep -v RWX | tail -12")
            if "MATCHES RETAIL" not in o:
                raise RuntimeError("wire-in: " + o.strip()[-700:])     # keep the real link error (wirefix: 160 hid it)
            with open("docs/layout.md", "a", newline="\n") as f:
                if c.get("manual") and not c["name"].startswith("func_"):
                    f.write("| `%s` | placed + proven %s (batch, hand-written) | `[C]` name: retail tables (%s); file `%s` "
                            "(retail_names.csv). Area not evidenced. |\n" % (src_rel, time.strftime("%Y-%m-%d"),
                                                                            c.get("conf") or "high", c["file"]))
                elif c["name"].startswith("func_"):
                    f.write("| `%s` | placed + proven %s (batch) | Unnamed (`func_` placeholder, C linkage); file and Area unknown. "
                            "%s template. |\n" % (src_rel, time.strftime("%Y-%m-%d"), c["kind"]))
                else:
                    f.write("| `%s` | placed + proven %s (batch) | `[C]` name: retail tables (%s); file `%s` (retail_names.csv). "
                            "Area not evidenced. %s template. |\n" % (src_rel, time.strftime("%Y-%m-%d"), c.get("conf") or "high",
                                                                      c["file"], c["kind"]))
            files = [src_rel, "config/b3_retail.yaml", "config/proven_units.txt", "tools/wire_in_batch.sh",
                     "docs/layout.md"] + c.get("extra", [])
            git_commit(files, commit_msg)
            n_ok += 1
            log({"status": "PROVEN", "name": c["name"], "unit": unit, "addr": c["addr"], "size": c["size"], "kind": c["kind"]})
            os.remove(MARK)
        except Exception as e:
            for t in touched:
                shutil.copy(os.path.join(bak, t.replace("/", "__")), t)
            for f in created:
                if os.path.exists(f):
                    os.remove(f)
            _where.clear(); _where.update(index_backup)
            log({"status": "PARKED", "name": c["name"], "reason": str(e)[:200], "kind": c["kind"]})
            if os.path.exists(MARK):
                os.remove(MARK)
            if stage != "compile":
                # isolate() re-assembled the chunk's object from a piece: rebuild it from the restored source,
                # then make sure the tree is back to retail before going on (halt otherwise)
                if os.path.exists("assembly/asm/%s.s" % chunk):
                    reassemble(chunk)
                rc, o = wsl("bash tools/wire_in_full_check.sh 2>&1 | grep -v RWX | tail -2")
                if "MATCHES RETAIL" not in o:
                    print("rollback of %s did not restore a retail build; halting: %s" % (c["name"], o.strip()[-160:]),
                          flush=True)
                    break
    print("proven this run: %d" % n_ok)


if __name__ == "__main__":
    main()
