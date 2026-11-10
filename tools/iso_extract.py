"""Extract files from a raw MODE2/2352 (or MODE1/2352, or 2048) ISO9660 image.
Usage: python -I iso_extract.py <image.bin> <outdir> [--list]
"""
import os, struct, sys

def detect(f):
    f.seek(0); h = f.read(16)
    if h[:12] == b"\x00" + b"\xff"*10 + b"\x00":
        return 2352, (24 if h[15] == 2 else 16)
    return 2048, 0

class Img:
    def __init__(self, path):
        self.f = open(path, "rb"); self.ss, self.off = detect(self.f)
    def read(self, lba, n=1):
        out = []
        for i in range(n):
            self.f.seek((lba+i)*self.ss + self.off); out.append(self.f.read(2048))
        return b"".join(out)

def parse_dir(img, lba, size):
    data = img.read(lba, (size+2047)//2048); pos = 0; ents = []
    while pos < size:
        l = data[pos]
        if l == 0: pos = (pos//2048 + 1)*2048; continue
        rec = data[pos:pos+l]
        elba, esz = struct.unpack_from("<I", rec, 2)[0], struct.unpack_from("<I", rec, 10)[0]
        flags = rec[25]; nlen = rec[32]; name = rec[33:33+nlen]
        if name not in (b"\x00", b"\x01"):
            ents.append((name.decode("latin1"), elba, esz, bool(flags & 2)))
        pos += l
    return ents

def walk(img, lba, size, prefix=""):
    for name, elba, esz, isdir in parse_dir(img, lba, size):
        p = prefix + "/" + name
        if isdir: yield from walk(img, elba, esz, p)
        else: yield p, elba, esz

def main():
    path, out = sys.argv[1], sys.argv[2]; listonly = "--list" in sys.argv
    only = sys.argv[sys.argv.index("--only")+1].upper() if "--only" in sys.argv else None
    img = Img(path); pvd = img.read(16)
    assert pvd[1:6] == b"CD001", "no ISO9660 PVD"
    root = pvd[156:190]
    rlba, rsz = struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0]
    print("volume:", pvd[40:72].decode().strip(), "| sector size", img.ss)
    for p, lba, sz in walk(img, rlba, rsz):
        if only and only not in p.upper(): continue
        print(f"{sz:>12}  lba={lba:<8} {p}")
        if listonly: continue
        dst = os.path.join(out, p.lstrip("/").replace(";1", ""))
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "wb") as o:
            left = sz; cur = lba
            while left > 0:
                n = min(left, 2048*512); chunk = img.read(cur, (n+2047)//2048)[:n]
                o.write(chunk); left -= n; cur += (n+2047)//2048
main()
