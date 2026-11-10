#!/usr/bin/env python3
"""progress_map.py: docs/progress_map.svg, a treemap of the game code -- one tile per original source file (retail
names: build/tu_map.json, from tools/tu_map.py), its area the file's code bytes, its shade the proven share of those
bytes (config/proven_units.txt, read fresh). Functions with no evidenced file are grouped by 256 KB address region
(tiles "? 0x..."), never given a guessed name. Called by tools/readme_progress.py on every commit; prints a one-line
summary ("files N, complete M") for the README note."""
import json
import os
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
W, H = 1000, 540


def proven_ranges():
    rs = []
    for line in open(ROOT / "config" / "proven_units.txt"):
        if line.startswith("#") or not line.strip():
            continue
        f = line.split(",")
        rs.append((int(f[0], 16), int(f[0], 16) + int(f[1], 16)))
    rs.sort()
    return rs


def is_proven(addr, rs, cache={}):
    import bisect
    i = bisect.bisect_right(rs, (addr, 1 << 40)) - 1
    return i >= 0 and rs[i][0] <= addr < rs[i][1]


def tiles():
    tm = json.load(open(ROOT / "build" / "tu_map.json"))
    rs = proven_ranges()
    groups = {}
    for f in tm["funcs"]:
        key = f["file"][:-4] if f.get("file") else "? 0x%X" % ((f["addr"] >> 18) << 18)
        g = groups.setdefault(key, [0, 0, f.get("file") is None])
        g[0] += f["size"]
        if is_proven(f["addr"], rs):
            g[1] += f["size"]
    return sorted(((k, t, p, u) for k, (t, p, u) in groups.items() if t > 0), key=lambda x: -x[1])


def squarify(items, x, y, w, h):
    """items: [(value, payload)] sorted descending -> [(x, y, w, h, payload)] (Bruls et al., squarified)."""
    out = []
    total = float(sum(v for v, _ in items))
    if total <= 0:
        return out
    scale = w * h / total
    rest = [(v * scale, p) for v, p in items]

    def worst(row, side):
        s = sum(a for a, _ in row)
        return max(max(side * side * a / (s * s), (s * s) / (side * side * a)) for a, _ in row)

    while rest:
        side = min(w, h)
        row = [rest.pop(0)]
        while rest and worst(row + [rest[0]], side) <= worst(row, side):
            row.append(rest.pop(0))
        s = sum(a for a, _ in row)
        if w >= h:                       # lay the row out as a column on the left
            cw = s / h
            cy = y
            for a, p in row:
                ch = a / cw
                out.append((x, cy, cw, ch, p))
                cy += ch
            x, w = x + cw, w - cw
        else:                            # a row along the top
            rh = s / w
            cx = x
            for a, p in row:
                rw = a / rh
                out.append((cx, y, rw, rh, p))
                cx += rw
            y, h = y + rh, h - rh
    return out


def shade(frac, unattributed):
    # 0 % dark grey -> 100 % green (unattributed regions a cooler grey base)
    a = (0x26, 0x29, 0x30) if unattributed else (0x30, 0x30, 0x30)
    b = (0x2e, 0xa0, 0x43)
    if frac >= 0.9999:
        b = (0x3f, 0xb9, 0x50)
    c = tuple(int(a[i] + (b[i] - a[i]) * (frac ** 0.8)) for i in range(3))
    return "#%02x%02x%02x" % c


def main():
    ts = tiles()
    rects = squarify([(t, (k, t, p, u)) for k, t, p, u in ts], 0, 0, W, H)
    font = "ui-monospace,SFMono-Regular,Menlo,Consolas,'Liberation Mono',monospace"
    out = ['<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 %d %d" width="%d" height="%d">' % (W, H, W, H),
           '<rect width="%d" height="%d" rx="10" fill="#0d1117"/>' % (W, H)]
    for x, y, w, h, (k, t, p, u) in rects:
        frac = p / float(t)
        out.append('<rect x="%.1f" y="%.1f" width="%.1f" height="%.1f" fill="%s" stroke="#0d1117" stroke-width="1.5">'
                   '<title>%s: %d / %d bytes (%.1f%%)</title></rect>'
                   % (x, y, w, h, shade(frac, u), k, p, t, 100 * frac))
        fs = 11 if w > 70 and h > 26 else (9 if w > 46 and h > 20 else 0)
        if fs:
            name = k if len(k) * fs * 0.6 < w - 6 else k[:max(3, int((w - 6) / (fs * 0.6)) - 1)] + "…"
            col = "#e6edf3" if frac < 0.6 else "#0d1117"
            out.append('<text x="%.1f" y="%.1f" font-family="%s" font-size="%d" fill="%s">%s</text>'
                       % (x + 4, y + fs + 3, font, fs, col, name.replace("&", "&amp;")))
            if h > 2.4 * fs + 8:
                out.append('<text x="%.1f" y="%.1f" font-family="%s" font-size="%d" fill="%s" opacity="0.8">%.0f%%</text>'
                           % (x + 4, y + 2 * fs + 7, font, fs, col, 100 * frac))
    out.append("</svg>")
    (ROOT / "docs").mkdir(exist_ok=True)
    (ROOT / "docs" / "progress_map.svg").write_text("\n".join(out) + "\n", encoding="utf-8", newline="\n")
    files = [x for x in ts if not x[3]]
    print("files %d, complete %d, started %d" % (len(files), sum(1 for x in files if x[2] >= x[1]),
                                                 sum(1 for x in files if 0 < x[2] < x[1])))


if __name__ == "__main__":
    main()
