"""readme_progress.py: rewrite README.md's progress block from tools/progress_report.py (run by .githooks/pre-commit,
so every commit carries the count it reached). Leaves README.md alone if the report can't run (e.g. no assembly/)."""
import re
import subprocess
import sys
from datetime import date
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
START, END = "<!-- progress:start -->", "<!-- progress:end -->"

r = subprocess.run([sys.executable, str(ROOT / "tools" / "progress_report.py")], capture_output=True, text=True,
                   cwd=ROOT)
out = r.stdout
m_p = re.search(r"Proven .*?: ([\d,]+) units, ([\d,]+) functions, ([\d,]+) bytes", out)
m_f = re.search(r"By function count: ([\d,]+)/([\d,]+) = ([\d.]+)%", out)
m_b = re.search(r"By byte count: +([\d,]+)/([\d,]+) = ([\d.]+)%", out)
if r.returncode != 0 or not (m_p and m_f and m_b):
    sys.exit(0)
sys.path.insert(0, str(ROOT / "tools"))
import progress_stats  # noqa: E402

FN, FTOT = int(m_f.group(1).replace(",", "")), int(m_f.group(2).replace(",", ""))
BN, BTOT = int(m_b.group(1).replace(",", "")), int(m_b.group(2).replace(",", ""))
try:
    NS = progress_stats.stats(str(ROOT))
except Exception:
    NS = None


def split(rest, key):
    """The not-yet-matched remainder of the official total, split in the proportions of the per-function scan
    (the scan's sizes leave out inter-function padding, so its totals differ slightly from the baseline's)."""
    if not NS:
        return {"complete": 0, "partial": 0, "none": rest}
    tot = sum(v[key] for v in NS.values()) or 1
    c = int(round(rest * NS["complete"][key] / tot))
    p = int(round(rest * NS["partial"][key] / tot))
    return {"complete": c, "partial": p, "none": rest - c - p}


FS, BS = split(FTOT - FN, 0), split(BTOT - BN, 1)
SEG = [("matched", "Byte-matched", "#2ea043"), ("complete", "Complete C", "#388bfd"),
       ("partial", "Partial C", "#d29922"), ("none", "No C yet", "#484f58")]


def kb(n):
    return "%d KB" % (n // 1000) if n < 1000000 else "%.2f MB" % (n / 1000000)


def pct(n, tot):
    return 100.0 * n / tot if tot else 0.0


def svg():
    """docs/progress_bars.svg: two stacked bars (functions, code bytes) on the same dark card as the map."""
    W, H, X0, BW = 1000, 236, 200, 580
    font = "font-family=\"-apple-system,BlinkMacSystemFont,'Segoe UI',Helvetica,Arial,sans-serif\""
    o = ['<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 %d %d" width="%d" height="%d">' % (W, H, W, H),
         '<rect width="%d" height="%d" rx="12" fill="#0d1117"/>' % (W, H)]
    rows = [("Functions", "{:,} total".format(FTOT), dict(FS, matched=FN), FTOT, lambda n: "{:,}".format(n)),
            ("Code", kb(BTOT) + " total", dict(BS, matched=BN), BTOT, kb)]
    for i, (label, sub, vals, tot, fmt) in enumerate(rows):
        y = 34 + i * 74
        o.append('<text x="28" y="%d" %s font-size="20" font-weight="600" fill="#e6edf3">%s</text>' % (y + 17, font, label))
        o.append('<text x="28" y="%d" %s font-size="13" fill="#8b949e">%s</text>' % (y + 37, font, sub))
        o.append('<clipPath id="c%d"><rect x="%d" y="%d" width="%d" height="30" rx="7"/></clipPath>' % (i, X0, y, BW))
        o.append('<g clip-path="url(#c%d)"><rect x="%d" y="%d" width="%d" height="30" fill="#21262d"/>' % (i, X0, y, BW))
        x = float(X0)
        for key, name, col in SEG:
            w = BW * vals[key] / tot if tot else 0
            if w > 0:
                o.append('<rect x="%.1f" y="%d" width="%.1f" height="30" fill="%s"><title>%s: %s (%.1f%%)</title></rect>'
                         % (x, y, w, col, name, fmt(vals[key]), pct(vals[key], tot)))
            x += w
        o.append("</g>")
        withc = vals["matched"] + vals["complete"]
        o.append('<text x="%d" y="%d" %s font-size="20" font-weight="700" fill="#3fb950">%.1f%% <tspan font-size="14" font-weight="400" fill="#8b949e">matched</tspan></text>'
                 % (X0 + BW + 18, y + 17, font, pct(vals["matched"], tot)))
        o.append('<text x="%d" y="%d" %s font-size="13" fill="#79c0ff">%.1f%% with complete C</text>'
                 % (X0 + BW + 18, y + 37, font, pct(withc, tot)))
    lx = 28
    for key, name, col in SEG:
        o.append('<rect x="%d" y="196" width="14" height="14" rx="3" fill="%s"/>' % (lx, col))
        o.append('<text x="%d" y="208" %s font-size="14" fill="#c9d1d9">%s</text>' % (lx + 22, font, name))
        lx += 44 + 9 * len(name)
    o.append('<text x="%d" y="208" text-anchor="end" %s font-size="12" fill="#6e7681">green = proven by relinking '
             'the whole game byte for byte</text>' % (W - 28, font))
    o.append("</svg>")
    (ROOT / "docs" / "progress_bars.svg").write_text("\n".join(o) + "\n", encoding="utf-8", newline="\n")


svg()


def table():
    rows = [("🟩 &nbsp;**Byte-matched**", FN, BN), ("🟦 &nbsp;**Complete C**", FS["complete"], BS["complete"]),
            ("🟧 &nbsp;**Partial C**", FS["partial"], BS["partial"]), ("⬛ &nbsp;**No C yet**", FS["none"], BS["none"])]
    out = ["| State | Functions | | Code | |", "|:---|---:|---:|---:|---:|"]
    for name, f, b in rows:
        out.append("| %s | %s | %.1f%% | %s | %.1f%% |" % (name, "{:,}".format(f), pct(f, FTOT), kb(b), pct(b, BTOT)))
    out.append("| **Total game code** | **%s** | | **%s** | |" % ("{:,}".format(FTOT), kb(BTOT)))
    out += ["",
            "- **Byte-matched:** rebuilt byte for byte, proven by relinking the whole game against retail.",
            "- **Complete C:** behaviour-equivalent to retail and audited against it (`tools/behaviour_audit.py`), "
            "but compiles to different bytes. Lives in `src/nonmatching/` for the PC port.",
            "- **Partial C:** drafted, with regions still missing."]
    return out


pmo = subprocess.run([sys.executable, str(ROOT / "tools" / "progress_map.py")], capture_output=True, text=True,
                     cwd=ROOT).stdout
pm = re.search(r"files (\d+), complete (\d+), started (\d+)", pmo)
pm = pm.groups() if pm else ("?", "?", "?")
try:
    import json as _json
    cyc = _json.load(open(ROOT / "build" / "cycle" / "state.json"))["cycle"]
except Exception:
    cyc = "?"
n = subprocess.run(["git", "rev-list", "--count", "HEAD"], capture_output=True, text=True, cwd=ROOT).stdout.strip()
def name_counts(dirs):
    """(total glabels, func_XXXXXXXX placeholders) over assembly/asm/<dirs>."""
    tot = ph = 0
    for d in dirs:
        for f in (ROOT / "assembly" / "asm" / d).rglob("*.s"):
            for line in f.read_text(encoding="utf-8", errors="ignore").splitlines():
                m = re.match(r"\s*glabel\s+(\S+)", line)
                if m:
                    tot += 1
                    ph += bool(re.fullmatch(r"func_[0-9A-Fa-f]{8}", m.group(1)))
    return tot, ph


try:
    GT, GP = name_counts(["b3", "game"])
    LT, LP = name_counts(["ea", "lg", "runtime", "rw", "rwa", "sce"])
except Exception:
    GT = 0
commits = int(n) + 1 if n.isdigit() else 1
block = "\n".join([
    START,
    "## Progress",
    "",
    "[![progress: byte-matched, complete C, partial C, no C yet](docs/progress_bars.svg)](docs/progress.md)",
    "",
] + table() + [
    "",
    "<sub>%s of %s known source files complete &middot; %s started &middot; %s units proven &middot; pipeline cycle %s "
    "&middot; updated %s (commit #%d) &middot; game code only; only byte-matched code counts toward the match, and "
    "non-matching C is never linked into the matching build</sub>"
    % (pm[1], pm[0], pm[2], "{:,}".format(int(m_p.group(1).replace(",", ""))), cyc, date.today().isoformat(), commits),
    "",
] + ([
    "<sub>Function names: game code %s of %s named (%.0f%%), %s still `func_XXXXXXXX`; libraries %s of %s named (%.0f%%), "
    "%s still `func_XXXXXXXX` (glabels in `assembly/asm`)</sub>"
    % ("{:,}".format(GT - GP), "{:,}".format(GT), pct(GT - GP, GT), "{:,}".format(GP),
       "{:,}".format(LT - LP), "{:,}".format(LT), pct(LT - LP, LT), "{:,}".format(LP)),
    "",
] if GT else []) + [
    "[![progress map: one tile per original source file, sized by code bytes, shaded by the proven share]"
    "(docs/progress_map.svg)](docs/progress.md)",
    "",
    "<sub>One tile per original source file, sized by its code and shaded by how much of it is proven. "
    "Tiles marked `? 0x...` hold functions whose file is not evidenced yet.</sub>",
    END,
])


def badge(label, value, color, alt, link="#progress"):
    return ('  <a href="%s"><img alt="%s" src="https://img.shields.io/badge/%s-%s-%s?style=for-the-badge&'
            'labelColor=0d1117"></a>' % (link, alt, label.replace("-", "--").replace(" ", "%20"), value.replace("-", "--").replace("%", "%25")
                                       .replace(" ", "%20"), color))


BSTART, BEND = "<!-- badges:start -->", "<!-- badges:end -->"
WITHC = pct(BN + BS["complete"], BTOT)
badges = "\n".join([
    BSTART,
    '<p align="center">',
    badge("functions matched", "%.1f%%" % pct(FN, FTOT), "2ea043", "Functions byte-matched %.1f%%" % pct(FN, FTOT)),
    badge("code matched", "%.1f%%" % pct(BN, BTOT), "2ea043", "Code byte-matched %.1f%%" % pct(BN, BTOT)),
    badge("code with complete C", "%.1f%%" % WITHC, "388bfd", "Code with complete C %.1f%%" % WITHC),
    badge("game names", "%.0f%%" % pct(GT - GP, GT), "8957e5", "Game functions with a name %.0f%%" % pct(GT - GP, GT)) if GT else "",
    badge("build", "matches retail", "1f6feb", "Build matches retail", "#target"),
    "</p>",
    BEND,
]).replace("\n\n  <a", "\n  <a")
p = ROOT / "README.md"
s = p.read_text(encoding="utf-8")
for a, b, text in ((START, END, block), (BSTART, BEND, badges)):
    if a in s and b in s:
        s = s[:s.index(a)] + text + s[s.index(b) + len(b):]
    elif a == START:
        s = s.rstrip("\n") + "\n\n" + text + "\n"
p.write_text(s, encoding="utf-8", newline="\n")
