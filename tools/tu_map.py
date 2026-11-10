"""tu_map.py: the game-code function map (every glabel under assembly/asm/{game,b3}) with each function's source file
from research/retail_names.csv and whether it is proven (config/proven_units.txt), grouped into per-file address spans.
Writes build/tu_map.json; prints a feasibility summary for translation-unit merges.

A function's file is [C] when retail_names.csv names it; an unnamed function strictly inside one file's span, between
two functions of that file, is [L] that file by contiguity (N2: a TU's functions are emitted contiguously)."""
import csv
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
funcs = {}
for d in ("game", "b3"):
    for s in (ROOT / "assembly" / "asm" / d).rglob("*.s"):
        name = None
        for line in open(s, errors="ignore"):
            if line.startswith("glabel "):
                name = line.split()[1]
                start = None
                n = 0
            elif line.startswith("endlabel") and name:
                if start is not None:
                    funcs.setdefault(start, {"addr": start, "name": name, "size": n * 4,
                                             "asm": str(s.relative_to(ROOT)).replace("\\", "/")})
                name = None
            elif name:
                m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/", line)
                if m:
                    if start is None:
                        start = int(m.group(1), 16)
                    n += 1
names, medium = {}, {}
for r in csv.DictReader(open(ROOT / "research" / "retail_names.csv", encoding="utf-8")):
    if r["source"].endswith(".cpp") and r["confidence"] == "high":
        names[int(r["elf_addr"], 16)] = r["source"]
    elif r["source"].endswith(".cpp") and r["confidence"] == "medium":
        medium[int(r["elf_addr"], 16)] = r["source"]
# a medium-confidence file counts when the nearest named function before or after it (in address order) names the
# same file -- confirmed by contiguity; its evidence is then [L]
_all = sorted(set(names) | set(medium))
med_ok = set()
changed = True
while changed:                       # a chain of confirmations must reach a high-confidence name
    changed = False
    for k, a in enumerate(_all):
        if a in medium and a not in med_ok:
            for b in ([_all[k - 1]] if k else []) + ([_all[k + 1]] if k + 1 < len(_all) else []):
                if (names.get(b) or medium.get(b)) == medium[a] and (b in names or b in med_ok):
                    med_ok.add(a)
                    changed = True
                    break
proven = {}
for line in open(ROOT / "config" / "proven_units.txt"):
    if line.startswith("#") or not line.strip():
        continue
    f = line.strip().split(",")
    lo, size = int(f[0], 16), int(f[1], 16)
    proven[lo] = (lo + size, f[3], f[4])
order = sorted(funcs)
pr_ranges = sorted((lo, hi) for lo, (hi, _, _) in proven.items())


def is_proven(a):
    import bisect
    i = bisect.bisect_right(pr_ranges, (a, 1 << 40)) - 1
    return i >= 0 and pr_ranges[i][0] <= a < pr_ranges[i][1]


for a in order:
    F = funcs[a]
    F["file"] = names.get(a) or (medium[a] if a in med_ok else None)
    F["file_ev"] = "C" if a in names else ("Lm" if F["file"] else None)
    F["proven"] = is_proven(a)
# contiguity: unnamed functions between two functions of one file
named_idx = [i for i, a in enumerate(order) if funcs[a]["file"]]
for j in range(len(named_idx) - 1):
    i0, i1 = named_idx[j], named_idx[j + 1]
    f0, f1 = funcs[order[i0]]["file"], funcs[order[i1]]["file"]
    if f0 == f1:
        for i in range(i0 + 1, i1):
            funcs[order[i]]["file"] = f0
            funcs[order[i]]["file_ev"] = "L"
# spans: maximal runs of consecutive functions sharing a file
spans = []
cur = None
for a in order:
    F = funcs[a]
    if cur and F["file"] and F["file"] == cur["file"]:
        cur["funcs"].append(a)
    else:
        cur = {"file": F["file"], "funcs": [a]} if F["file"] else None
        if cur:
            spans.append(cur)
byfile = {}
for sp in spans:
    byfile.setdefault(sp["file"], []).append(sp)
json.dump({"funcs": [funcs[a] for a in order], "spans": spans}, open(ROOT / "build" / "tu_map.json", "w"))
full = [sp for sp in spans if all(funcs[a]["proven"] for a in sp["funcs"])]
multi = [sp for sp in full if len(sp["funcs"]) > 1]
print("game functions:", len(order), " named (file [C]):", sum(1 for a in order if funcs[a]["file_ev"] == "C"),
      " placed by contiguity [L]:", sum(1 for a in order if funcs[a]["file_ev"] == "L"))
print("files:", len(byfile), " split into", len(spans), "spans;", sum(1 for f, v in byfile.items() if len(v) > 1),
      "files in more than one span")
print("fully proven spans:", len(full), "(", sum(len(s["funcs"]) for s in full), "functions);  of those with 2+ functions:",
      len(multi), "(", sum(len(s["funcs"]) for s in multi), "functions)")
pp = [a for a in order if funcs[a]["proven"]]
print("proven functions:", len(pp), " with a file:", sum(1 for a in pp if funcs[a]["file"]), " unnamed + no contiguity:",
      sum(1 for a in pp if not funcs[a]["file"]))
