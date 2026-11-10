"""Audit placed names on an ELF. For each placed .text name, run independent checks:
  S = start boundary: 'jr ra' (or j/b) in the 5 words before the start, or alignment padding (nops)
  E = end boundary: function's last-but-one word is 'jr ra' or an unconditional jump (j/b) (tail call / shared epilogue)
  N = neighbour contiguity: the next map function (if placed) starts at align16(end)
Class: verified = S & E & N; boundary = S & E; inferred = anything else (incl. block-inferred placements).
usage: audit_names.py <elf> <blk_csv>... -> prints summary, writes research/name_audit_<elf>.csv"""
import csv, struct, sys, os, collections
elf = sys.argv[1]; d = open(elf, "rb").read(); fs = struct.unpack_from("<I", d, 0x34+16)[0]
W = struct.unpack("<%dI" % (fs//4), d[0x100:0x100+fs//4*4]); N = len(W)
JR = 0x03E00008
def w(a): i = (a - 0x100000) // 4; return W[i] if 0 <= i < N else None
def is_jump(x): return x is not None and (x == JR or (x >> 26) == 2 or (x & 0xFFFF0000) == 0x10000000)
placed = {}
for f in sys.argv[2:]:
    for r in csv.DictReader(open(f)):
        if r["status"] in ("exact", "inferred") and r["elf_addr"]:
            a = int(r["elf_addr"], 16)
            placed.setdefault(a, []).append((os.path.basename(f), r["name"], int(r["size"], 16), r["status"], int(r["map_addr"], 16)))
rows = []; cnt = collections.Counter()
starts = sorted(placed)
for a in starts:
    src, name, size, st, ma = placed[a][0]
    S = any(is_jump(w(a - 4*k)) for k in range(1, 6)) or a == 0x100000
    E = is_jump(w(a + size - 8)) if size >= 8 else False
    nxt = [b for b in starts if b > a][:1]
    Nn = bool(nxt) and nxt[0] == ((a + size + 15) & ~15) or (bool(nxt) and nxt[0] == a + size)
    cls = "verified" if (S and E and Nn) else ("boundary" if (S and E) else "inferred")
    if st == "inferred" and cls == "verified": cls = "boundary"   # never fully trust block-inferred names
    agree = len({p[1] for p in placed[a]}) == 1
    if not agree: cls = "conflict"
    cnt[(cls, st)] += 1
    rows.append([f"{a:08x}", name, size, st, int(S), int(E), int(Nn), cls, len(placed[a])])
out = f"research/name_audit_{os.path.basename(elf)}.csv"
w_ = csv.writer(open(out, "w", newline="")); w_.writerow(["elf_addr","name","size","placement","start_ok","end_ok","neighbour_ok","class","maps"]); w_.writerows(rows)
tot = collections.Counter(); [tot.__setitem__(k[0], tot[k[0]] + v) for k, v in cnt.items()]
print(os.path.basename(elf), "placed", len(rows), dict(tot)); print("  by (class, placement):", dict(cnt))
