"""Project symbols from a mapped ELF onto stripped ELFs by normalised function-body matching.
usage: transfer_symbols.py <src.elf> <src_symbols.csv> <out.csv> <target.elf> [<target.elf> ...]
Only .text symbols with >=MINW words are matched. A match must be unique in the target to be 'unique'."""
import csv, struct, sys, hashlib, collections, os
MINW = 8
def code(p):
    d = open(p, "rb").read(); fs = struct.unpack_from("<I", d, 0x34 + 16)[0]; va = struct.unpack_from("<I", d, 0x34 + 8)[0]
    return va, struct.unpack("<%dI" % (fs // 4), d[0x100:0x100 + fs // 4 * 4])
def norm(x):
    op = x >> 26
    if op in (2, 3): return x & 0xFC000000
    if op == 0xF: return x & 0xFFFF0000
    if op in (0x9, 0xC, 0xD) and (x >> 21 & 31) != 29 and (x >> 16 & 31) != 29: return x & 0xFFFF0000
    if (x >> 21 & 31) == 28 and op >= 0x20: return x & 0xFFFF0000
    return x
def main():
    src, symcsv, out = sys.argv[1:4]; targets = sys.argv[4:]
    sva, sw = code(src); sn = [norm(x) for x in sw]
    syms = [r for r in csv.DictReader(open(symcsv)) if r["section"] == ".text" and int(r["size"], 16) // 4 >= MINW]
    print(len(syms), "source functions >=", MINW, "words")
    rows = []; res = {}
    for t in targets:
        tva, tw = code(t); tn = [norm(x) for x in tw]
        idx = collections.defaultdict(list)
        for i in range(len(tn) - 3): idx[tuple(tn[i:i+4])].append(i)
        ok = uniq = 0; found = {}
        for s in syms:
            a = int(s["addr"], 16); n = int(s["size"], 16) // 4; i0 = (a - sva) // 4
            body = sn[i0:i0 + n]
            if len(body) < n: continue
            hits = [j for j in idx.get(tuple(body[:4]), []) if tn[j:j + n] == body]
            if hits:
                ok += 1
                if len(hits) == 1: uniq += 1
                found[(s["addr"])] = [tva + 4 * j for j in hits]
        res[t] = (ok, uniq, found)
        print(f"{os.path.basename(t):16} matched {ok}/{len(syms)} ({100*ok/len(syms):.1f}%), unique {uniq}")
    w = csv.writer(open(out, "w", newline="")); w.writerow(["src_addr", "name", "source"] + [os.path.basename(t) for t in targets])
    for s in syms:
        w.writerow([s["addr"], s["name"], s["source"]] + [";".join(f"{x:08x}" for x in res[t][2].get(s["addr"], [])) for t in targets])
main()
