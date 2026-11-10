"""Block-voting alignment of a link map onto a related stripped ELF.
Map .text functions are cut into blocks of K consecutive functions (relative layout taken from the map).
For each block we vote over ELF offsets p where function ends (jr ra at end-8) line up; a block is placed
if best votes >= NEED and the runner-up has <= NEED-3 votes. Names inside placed blocks are assigned only to
functions whose own end matched (status 'exact') or whose start lies between matched neighbours ('inferred').
usage: align_blocks.py <DNAT|B3DEBUG|B3INTERN|B3O0PCH> <elf> <out.csv> [K=8] [NEED=6]"""
import sys, os, struct, csv, collections, bisect
sys.path.insert(0, os.path.dirname(__file__)); import parse_mwmap as P
from align_map import maprows
JR = 0x03E00008
m, elf, out = sys.argv[1:4]; K = int(sys.argv[4]) if len(sys.argv) > 4 else 12; NEED = int(sys.argv[5]) if len(sys.argv) > 5 else 8
d = open(elf, "rb").read(); fs = struct.unpack_from("<I", d, 0x34 + 16)[0]
W = struct.unpack("<%dI" % (fs // 4), d[0x100:0x100 + fs // 4 * 4])
J = [i for i, x in enumerate(W) if x == JR]; Jset = set(J)
rows = sorted({(a, s, n, src) for a, s, n, src in maprows(m) if s >= 8}, key=lambda r: r[0])
res = {}; placed = 0; blocks = 0; deltas = []
for b0 in range(0, len(rows) - K + 1, K):
    blk = rows[b0:b0 + K]; base = blk[0][0]; blocks += 1
    E = [((a - base) + s - 8) // 4 for a, s, n, src in blk]
    lo = bisect.bisect_left(J, (base - 0x100000 - 0x80000) // 4 if base > 0x180000 else 0)
    hi = bisect.bisect_right(J, (base - 0x100000 + 0x200000) // 4)
    votes = collections.Counter()
    for j in J[lo:hi]:
        for e in E: votes[j - e] += 1
    top = votes.most_common(2)
    if not top or top[0][1] < NEED or (len(top) > 1 and top[1][1] > top[0][1] - 3): continue
    p = top[0][0]; placed += 1; deltas.append((base, 0x100000 + 4 * p - base))
    for (a, s, n, src), e in zip(blk, E):
        ea = 0x100000 + 4 * p + (a - base)
        res[a] = (ea, "exact" if (p + e) in Jset else "inferred")
w = csv.writer(open(out, "w", newline="")); w.writerow(["map_addr", "size", "name", "source", "elf_addr", "status"])
ex = inf = 0
for a, s, n, src in rows:
    if a in res and res[a][1] == 'exact' or (a in res): ea, st = res[a]; ex += st == "exact"; inf += st == "inferred"; w.writerow([f"{a:08x}", f"{s:x}", n, src, f"{ea:08x}", st])
    else: w.writerow([f"{a:08x}", f"{s:x}", n, src, "", "unplaced"])
print(f"{m:8} -> {os.path.basename(os.path.dirname(elf))+'/'+os.path.basename(elf):30} blocks placed {placed}/{blocks} ({100*placed/max(blocks,1):.0f}%), names exact {ex} inferred {inf} of {len(rows)}")
if deltas: print("   delta samples:", [(f"{b:x}", hex(dl)) for b, dl in deltas[::max(1, len(deltas)//8)]])
