"""List/extract an Xbox XDVDFS image. usage: xdvdfs.py <img> <outdir> [--list] [--only substr]"""
import os, struct, sys
img = sys.argv[1]; out = sys.argv[2]; lst = "--list" in sys.argv
only = sys.argv[sys.argv.index("--only")+1].upper() if "--only" in sys.argv else None
f = open(img, "rb"); S = 2048
def rd(sec, n): f.seek(sec*S); return f.read(n)
# game partition may sit at an offset in full-disc images
for base in (0, 0x30600000//S, 0x18300000//S, 0xFD90000//S, 0x89D80000//S):
    if rd(32+base, 20) == b"MICROSOFT*XBOX*MEDIA": break
else: sys.exit("no XDVDFS header")
root, rsz = struct.unpack("<II", rd(32+base, 28)[20:28])
def walk(sec, size, prefix):
    data = rd(sec+base, size); seen = set()
    def node(off):
        if off in seen or off*4 >= len(data): return
        seen.add(off); o = off*4
        l, r, s, sz, at, nl = struct.unpack_from("<HHIIBB", data, o)
        if l == 0xFFFF and r == 0xFFFF and s == 0xFFFFFFFF: return
        name = data[o+14:o+14+nl].decode("latin1")
        yield from node(l) if l else []
        if at & 0x10: yield from walk(s, sz, prefix+"/"+name)
        else: yield prefix+"/"+name, s, sz
        yield from node(r) if r else []
    yield from node(0)
tot = 0
for p, s, sz in walk(root, rsz, ""):
    if only and only not in p.upper(): continue
    print(f"{sz:>12} lba={s:<8} {p}"); tot += sz
    if lst: continue
    dst = os.path.join(out, p.lstrip("/")); os.makedirs(os.path.dirname(dst), exist_ok=True)
    with open(dst, "wb") as o:
        left, cur = sz, s+base
        while left > 0:
            n = min(left, S*512); f.seek(cur*S); o.write(f.read(n)[:left]); left -= n; cur += n//S + (n % S > 0)
print("total", tot)
