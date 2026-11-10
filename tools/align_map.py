"""Drift-tracking alignment of a link map (ordered .text functions with sizes) onto a related stripped ELF.
A candidate start p for map function (a,size) must satisfy: 'jr ra' within 5 words before p (previous function end)
AND 'jr ra' exactly at p+size-8 (own end, delay slot last). Search window around a+delta; prefer candidate nearest
the predicted address; update delta. Output CSV: map_addr,size,name,source,elf_addr,delta,status.
usage: align_map.py <map: DNAT|B3DEBUG|B3INTERN|B3O0PCH> <elf> <out.csv> [window_bytes]"""
import sys, os, struct, csv
sys.path.insert(0, os.path.dirname(__file__)); import parse_mwmap as P
JR = 0x03E00008
def maprows(m):
    if m == "DNAT":
        return [(a, s, n, src) for a, s, sec, n, src in P.parse("research/E_jun8/DNAT_200.MAP") if sec == ".text"]
    rows = P.parse_bin(f"research/E_jun8/{m}.MAP")
    stop = min([a for a, s, n, src in rows if n in (".rodata", ".data", ".vutext")] or [1 << 32])
    return [r for r in rows if r[0] < stop]
def main():
    m, elf, out = sys.argv[1:4]; win = int(sys.argv[4], 0) if len(sys.argv) > 4 else 0x4000
    d = open(elf, "rb").read(); fs = struct.unpack_from("<I", d, 0x34 + 16)[0]
    W = struct.unpack("<%dI" % (fs // 4), d[0x100:0x100 + fs // 4 * 4]); N = len(W)
    def ok(i, words):
        if i < 6 or i + words > N or words < 3: return False
        return W[i + words - 2] == JR and any(W[i - k - 1] == JR for k in range(0, 5))
    rows = sorted(set(maprows(m)), key=lambda r: (r[0], -r[1])); delta = 0; res = []; hit = small = 0
    for a, s, n, src in rows:
        if s < 16 or s % 4: res.append((a, s, n, src, "", "", "skip-small")); small += 1; continue
        words = s // 4; pi = (a + delta - 0x100000) // 4; best = None
        for off in range(0, win // 4):
            for i in ((pi + off, pi - off) if off else (pi,)):
                if ok(i, words): best = i; break
            if best is not None: break
        if best is None: res.append((a, s, n, src, "", "", "nofit")); continue
        ea = 0x100000 + best * 4; delta = ea - a; hit += 1
        res.append((a, s, n, src, f"{ea:08x}", delta, "fit"))
    w = csv.writer(open(out, "w", newline="")); w.writerow(["map_addr", "size", "name", "source", "elf_addr", "delta", "status"])
    for r in res: w.writerow([f"{r[0]:08x}", f"{r[1]:x}"] + list(r[2:]))
    big = len(rows) - small
    print(f"{m:8} -> {os.path.basename(elf):14} fit {hit}/{big} ({100*hit/max(big,1):.1f}%) funcs>=16B; final delta {delta:#x}")
if __name__ == "__main__": main()
