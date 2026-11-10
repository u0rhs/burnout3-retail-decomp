"""Read-only extractor for InstallShield v6 cabinets (data1.hdr + dataN.cab), following unshield's documented layout.
usage: is6_extract.py <dir containing data1.hdr> <outdir> [--list] [--only substr]
Never executes anything; writes files only under <outdir>."""
import os, struct, sys, zlib
def u16(b, o): return struct.unpack_from("<H", b, o)[0]
def u32(b, o): return struct.unpack_from("<I", b, o)[0]
def u64(b, o): return struct.unpack_from("<Q", b, o)[0]
def cstr(b, o): return b[o:b.index(b"\0", o)].decode("latin1")
def main():
    src, out = sys.argv[1], sys.argv[2]; lst = "--list" in sys.argv
    only = sys.argv[sys.argv.index("--only")+1].lower() if "--only" in sys.argv else None
    h = open(os.path.join(src, "data1.hdr"), "rb").read()
    assert h[:4] == b"ISc(", "not an InstallShield cabinet header"
    cdo = u32(h, 12); p = cdo + 0xc
    fto = u32(h, p); p += 8; fts = u32(h, p); p += 4; fts2 = u32(h, p); p += 4
    ndir = u32(h, p); p += 4 + 8; nfile = u32(h, p); p += 4; fto2 = u32(h, p)
    base = cdo + fto
    table = [u32(h, base + 4*i) for i in range(ndir)]
    dirs = [cstr(h, base + o) for o in table]
    vols = {}
    def vol(n):
        if n not in vols:
            fn = os.path.join(src, f"data{n}.cab")
            vols[n] = open(fn, "rb").read() if os.path.exists(fn) else None
        return vols[n]
    tot = 0; bad = 0
    for i in range(nfile):
        q = base + fto2 + i * 0x57
        flags = u16(h, q); exp = u64(h, q+2); comp = u64(h, q+10); doff = u64(h, q+18)
        nameo = u32(h, q+0x3a); dirx = u16(h, q+0x3e); volume = u16(h, q+0x55)
        if flags & 8 or nameo == 0: continue
        name = cstr(h, base + nameo); path = os.path.join(dirs[dirx] if dirx < len(dirs) else "", name).replace("\\", "/").lstrip("/")
        if only and only not in path.lower(): continue
        print(f"{exp:>10} {comp:>10} f={flags:x} v={volume} {path}")
        if lst: continue
        # gather compressed bytes, possibly spanning volumes
        data = bytearray(); v = volume; off = doff; left = comp
        while left > 0:
            vb = vol(v)
            if vb is None: break
            take = min(left, len(vb) - off); data += vb[off:off+take]; left -= take
            if left > 0:
                v += 1; nb = vol(v)
                if nb is None: break
                off = u32(nb, 20 + 0x10)  # first_file_offset in next volume header (v6 layout)
        if flags & 2: bad += 1; print("   (obfuscated, skipped)"); continue
        if flags & 4:
            res = bytearray(); o = 0
            while o + 2 <= len(data) and len(res) < exp:
                n = u16(data, o); o += 2
                try: res += zlib.decompressobj(-15).decompress(bytes(data[o:o+n]))
                except zlib.error: bad += 1; print("   (inflate error)"); break
                o += n
            data = res
        if len(data) != exp: print(f"   size mismatch {len(data)} != {exp}"); bad += 1
        dst = os.path.join(out, path); os.makedirs(os.path.dirname(dst) or out, exist_ok=True)
        open(dst, "wb").write(data); tot += 1
    print("dirs", ndir, "files", nfile, "written", tot, "problems", bad)
main()
