"""Score how well a symbol map's .text function starts fit an ELF: fraction of starts preceded (within 5 words) by 'jr ra'.
usage: map_fit.py <elf>... ; maps are fixed below. Random baseline ~5%."""
import sys, struct, csv, collections, os
sys.path.insert(0, os.path.dirname(__file__)); import parse_mwmap as P
maps = {"DNAT_200.MAP(text)": [(a, s) for a, s, sec, n, src in P.parse("research/E_jun8/DNAT_200.MAP") if sec == ".text" and s >= 8]}
for n in ("B3DEBUG", "B3INTERN", "B3O0PCH"):
    rows = P.parse_bin(f"research/E_jun8/{n}.MAP")
    # binary maps lack section; use entries until first non-text marker: keep those with size>=8 below rodata start (heuristic: sorted, stop at '.data'/.rodata' label)
    stop = min([a for a, s, nm, src in rows if nm in (".rodata", ".data", ".vutext")] or [1 << 32])
    maps[n] = [(a, s) for a, s, nm, src in rows if s >= 8 and a < stop]
def load(p):
    d = open(p, "rb").read(); fs = struct.unpack_from("<I", d, 0x34 + 16)[0]
    return d[0x100:0x100 + fs]
for e in sys.argv[1:]:
    code = load(e); n = len(code) // 4; W = struct.unpack("<%dI" % n, code[:n*4])
    line = f"{os.path.basename(os.path.dirname(e))+'/'+os.path.basename(e):34}"
    for mn, fl in maps.items():
        ok = tot = 0
        for a, s in fl:
            i = (a - 0x100000) // 4
            if 6 <= i < n: tot += 1; ok += any(W[i-k-1] == 0x03E00008 for k in range(1, 6))
        line += f" {mn[:10]}={100*ok/max(tot,1):4.1f}%"
    print(line)
for mn, fl in maps.items(): print(mn, "text funcs", len(fl), "end", hex(max(a+s for a, s in fl)))
