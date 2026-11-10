"""vu0_mine.py [--top N]: the VU0 macro-mode idioms of the unproven game functions (assembly/asm/{game,b3}).

Per function, the sequence of its VU0 instructions in order (lqc2/sqc2, qmtc2/qmfc2, ctc2/cfc2, v*), mnemonic with
field mask, registers dropped, interleaved scalar code skipped. Prints: functions using VU0 (and their bytes), the most
common mnemonics (by functions using them), and the most common runs of 2-5 consecutive VU0 operations (by
functions containing them) -- the inlined GtMathPs2 bodies to recognise, ranked by how many functions they would
unlock. Writes build/vu0_mine.json (per function: name, size, sequence)."""
import collections
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOP = int(sys.argv[sys.argv.index("--top") + 1]) if "--top" in sys.argv else 30
VU = re.compile(r"^(lqc2|sqc2|qmtc2|qmfc2|ctc2|cfc2|v[a-z]+[a-z0-9]*(\.[xyzw]+)?)$")
INS = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$")
proven = open(ROOT / "config" / "proven_units.txt").read()
pr_addr = set()
for line in proven.split("\n"):
    if line and not line.startswith("#"):
        f = line.split(",")
        lo, n = int(f[0], 16), int(f[1], 16)
        pr_addr.add(lo)
funcs = []
for d in ("game", "b3"):
    for s in (ROOT / "assembly" / "asm" / d).rglob("*.s"):
        name, seq, start, n = None, [], None, 0
        for line in open(s, errors="ignore"):
            if line.startswith("glabel "):
                name, seq, start, n = line.split()[1], [], None, 0
            elif line.startswith("endlabel") and name:
                if start not in pr_addr and seq:
                    funcs.append({"name": name, "addr": start, "size": n * 4, "seq": seq})
                name = None
            elif name:
                m = INS.match(line)
                if m:
                    if start is None:
                        start = int(m.group(1), 16)
                    n += 1
                    mn = m.group(2)
                    if VU.match(mn) and mn not in ("vcallms",):
                        seq.append(mn)
                    elif mn == "vcallms":
                        seq.append("vcallms")
uniq = {f["addr"]: f for f in funcs}
funcs = list(uniq.values())
print("unproven game functions using VU0: %d (%d bytes)" % (len(funcs), sum(f["size"] for f in funcs)))
mc = collections.Counter()
for f in funcs:
    for m in set(f["seq"]):
        mc[m] += 1
print("\nmnemonics (functions using them):")
for m, c in mc.most_common(TOP):
    print("  %4d  %s" % (c, m))
for k in (2, 3, 4, 5):
    ng = collections.Counter()
    for f in funcs:
        seen = set()
        for i in range(len(f["seq"]) - k + 1):
            g = " ".join(f["seq"][i:i + k])
            if g not in seen:
                seen.add(g)
                ng[g] += 1
    print("\nruns of %d (functions containing):" % k)
    for g, c in ng.most_common(12 if k > 2 else 20):
        print("  %4d  %s" % (c, g))
json.dump(sorted(funcs, key=lambda f: f["size"]), open(ROOT / "build" / "vu0_mine.json", "w"))
