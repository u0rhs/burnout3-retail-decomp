"""Compare two extracted discs: per-file hash, and ELF function-level similarity (MIPS, immediates masked)."""
import hashlib, os, re, struct, sys
A, B = sys.argv[1], sys.argv[2]
def files(root):
    out = {}
    for dp, _, fs in os.walk(root):
        for f in fs:
            p = os.path.join(dp, f); out[os.path.relpath(p, root).replace("\\", "/")] = p
    return out
h = lambda p: hashlib.md5(open(p, "rb").read()).hexdigest()
fa, fb = files(A), files(B)
same = diff = 0
print("--- files only in A:", sorted(set(fa)-set(fb)))
print("--- files only in B:", sorted(set(fb)-set(fa)))
for k in sorted(set(fa)&set(fb)):
    if h(fa[k]) == h(fb[k]): same += 1
    else: diff += 1; print("DIFF", k, os.path.getsize(fa[k]), os.path.getsize(fb[k]))
print("identical:", same, "different:", diff)

def load(p):
    d = open(p, "rb").read(); off, va, fs = struct.unpack_from("<III", d, 0x34+4)[0:3]
    return d, d[off:off+fs] if False else d[0x100:0x100+struct.unpack_from("<I", d, 0x34+16)[0]]
def funcs(code, base=0x100000):
    w = struct.unpack("<%dI" % (len(code)//4), code[:len(code)//4*4])
    starts = [i for i, x in enumerate(w) if (x >> 16) == 0x27BD and (x & 0x8000)]  # addiu sp,sp,-N
    return w, starts
def norm(x):
    op = x >> 26
    if op in (2, 3): return x & 0xFC000000                 # j/jal: mask target
    if op == 0xF: return x & 0xFFFF0000                    # lui: mask imm
    if op in (0x9, 0xC, 0xD) : return x & 0xFFFF0000 if (x>>16 & 0x1F)!=29 and (x>>21&0x1F)!=29 else x   # addiu/andi/ori: mask unless sp-relative
    if op in (0x20,0x21,0x23,0x24,0x25,0x28,0x29,0x2B,0x31,0x39,0x37,0x3F,0x1E,0x1F,0x2F,0x26,0x22,0x2A,0x2E,0x32,0x3A) and (x>>21&0x1F) in (28,):
        return x & 0xFFFF0000                               # gp-relative
    return x
ea = os.path.join(A, sys.argv[3] if len(sys.argv)>3 else "SLED_525.97"); eb = os.path.join(B, sys.argv[4] if len(sys.argv)>4 else "SLUS_291.13")
_, ca = load(ea); _, cb = load(eb)
wa, sa = funcs(ca); wb, sb = funcs(cb)
def fh(w, s):
    out = {}
    for i, st in enumerate(s):
        en = s[i+1] if i+1 < len(s) else len(w)
        out.setdefault(hashlib.md5(struct.pack("<%dI" % (en-st), *[norm(x) for x in w[st:en]])).hexdigest(), []).append(0x100000+st*4)
    return out
ha, hb = fh(wa, sa), fh(wb, sb)
common = set(ha)&set(hb)
print(f"funcs(approx, sp-prologue) A={len(sa)} B={len(sb)}; normalised-identical hashes={len(common)} ({100*len(common)/max(1,len(ha)):.1f}% of A)")
exact = sum(1 for a, b in zip(wa, wb) if a == b)
print(f"raw word-for-word equal at same offset: {exact}/{min(len(wa),len(wb))}")
# string-set diff
def strs(p):
    return {m.group().decode() for m in re.finditer(rb'[\x20-\x7e]{6,}', open(p,'rb').read())}
sA, sB = strs(ea), strs(eb)
print("strings only in A:", len(sA-sB), "only in B:", len(sB-sA))
for s in sorted(sA-sB)[:0]: print("  A:", s)
import json; json.dump({"onlyA": sorted(sA-sB), "onlyB": sorted(sB-sA)}, open("research/string_diff.json","w"), indent=1)
