"""layout_tu_table.py: (re)write docs/layout.md's generated table of regrouped translation units (tools/tu_merge.py)
between its <!-- tu-table:start --> / <!-- tu-table:end --> markers, from config/tu_units.txt and each merged file's
evidence header lines."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
rows = []
for line in open(ROOT / "config" / "tu_units.txt"):
    if not line.strip() or line.startswith("#"):
        continue
    src, *units = line.split()
    text = open(ROOT / src, encoding="utf-8").read().split("\n")
    mem = next((l[3:] for l in text if l.startswith("// [C]/[L] membership:")), "")
    area = next((l[3:] for l in text if l.startswith("// Area")), "")
    ev = re.sub(r"^\[C\]/\[L\] membership: ", "", mem).rstrip(".")
    aev = re.sub(r"^Area: [^,]+, ", "", area).rstrip(".")
    rows.append("| `%s` | %d | %s | %s |" % (src, len(units), ev, aev))
table = ["<!-- tu-table:start -->",
         "## Regrouped translation units (generated: tools/layout_tu_table.py)",
         "",
         "One source file per retail .cpp, merged from proven per-function units by tools/tu_merge.py (each function's",
         "object is still placed at its own retail address; the merged object is split per function). Membership",
         "evidence is per function; the folder evidence is Revenge's file of the same name, `[L]` (B14 lineage).",
         "",
         "| File | Functions | Membership | Folder evidence |",
         "|---|---:|---|---|"] + sorted(rows) + ["<!-- tu-table:end -->"]
p = ROOT / "docs" / "layout.md"
s = open(p, encoding="utf-8").read()
blk = "\n".join(table)
if "<!-- tu-table:start -->" in s:
    s = re.sub(r"<!-- tu-table:start -->.*?<!-- tu-table:end -->", lambda m: blk, s, flags=re.S)
else:
    s = s.rstrip("\n") + "\n\n" + blk + "\n"
open(p, "w", encoding="utf-8", newline="\n").write(s)
print(len(rows), "rows")
