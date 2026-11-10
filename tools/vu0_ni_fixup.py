"""vu0_ni_fixup.py <obj.o> [...]: clear the interlock bit (I, bit 0) of every QMFC2/QMTC2 in the objects' code.

Why: retail's inlined GtMathPs2 bodies keep their GPR<->VU0
moves as `qmfc2.ni`/`qmtc2.ni` (bit 0 clear). Written that way in inline asm, MWCC treats the moves as plain copies
and folds them away (N94); written `.i` they stay exactly where retail has them, but the assembler sets bit 0. This
step clears it after compiling -- a toolchain workaround in the line of lit4_retarget.py / jtbl_retarget.py, applied
by every compile path (tiny_compile.sh, tu_build.sh, hc_verify.sh, build_c_units.sh). An object with no `.i` move is
left byte for byte as it was (no proven object has one: none would have matched).

Encodings (EE COP2): QMFC2 = 010010 00001 rt rd 0000000000 I, QMTC2 = 010010 00101 rt rd 0000000000 I."""
import struct
import sys

SHF_EXECINSTR = 4


def fix(path):
    try:
        d = bytearray(open(path, "rb").read())
    except FileNotFoundError:
        return 0                      # a failed compile: nothing to fix (the caller reports the error)
    if d[:4] != b"\x7fELF" or d[4] != 1 or d[5] != 1:
        return 0
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum = struct.unpack_from("<HH", d, 46)
    n = 0
    for i in range(shnum):
        name, typ, flags, addr, off, size = struct.unpack_from("<IIIIII", d, shoff + i * shentsize)
        if typ != 1 or not flags & SHF_EXECINSTR:     # PROGBITS code sections only
            continue
        keep = _keep_offsets(d, shoff, shentsize, shnum, i, off)
        for o in range(off, off + size - 3, 4):
            w, = struct.unpack_from("<I", d, o)
            if w & 1 and (w & 0xFFE007FE) in (0x48200000, 0x48A00000) and o not in keep:
                struct.pack_into("<I", d, o, w & ~1)
                n += 1
    if n:
        open(path, "wb").write(bytes(d))
    return n


def _load_keep():
    """config/vu0_keep_i.txt: `<function symbol> <k>[,<k>...]` -- leave the k-th interlocked qmtc2/qmfc2 (0-based, address
    order, counting only moves written .i) of that function untouched: retail has real `.i` moves in a few places (the
    first move into VU0 after an UploadVu0Code DMA; setc, IntersectLineTriangle). Every entry needs retail-byte evidence."""
    import os
    path = os.environ.get("VU0_KEEP_I") or os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "config",
                                                        "vu0_keep_i.txt")   # VU0_KEEP_I: an helper's test copy
    keep = {}
    if os.path.exists(path):
        for line in open(path):
            line = line.split("//")[0].strip()
            if line:
                sym, ks = line.split()[:2]
                keep[sym] = {int(k) for k in ks.split(",")}
    return keep


KEEP = _load_keep()


def _keep_offsets(d, shoff, shentsize, shnum, secidx, secoff):
    """File offsets of the moves KEEP protects in code section `secidx` (empty when KEEP names nothing here)."""
    if not KEEP:
        return set()
    out = set()
    for i in range(shnum):
        name, typ, flags, addr, off, size, link = struct.unpack_from("<IIIIIII", d, shoff + i * shentsize)
        if typ != 2:                                   # SHT_SYMTAB
            continue
        stroff = struct.unpack_from("<IIIIII", d, shoff + link * shentsize)[4]
        for e in range(off, off + size, 16):
            nm, val, sz, info, other, shndx = struct.unpack_from("<IIIBBH", d, e)
            if shndx != secidx or not sz:
                continue
            s = d[stroff + nm:d.index(b"\0", stroff + nm)].decode("latin-1")
            if s not in KEEP:
                continue
            k = 0
            for o in range(secoff + val, secoff + val + sz - 3, 4):
                w, = struct.unpack_from("<I", d, o)
                # count every qmtc2/qmfc2 whatever its I bit: counting only moves still flagged .i renumbered them on
                # a second pass over the same object (verify_all / build_c_units re-run this), so a kept index could
                # be cleared (cloud review 2026-10-28)
                if (w & 0xFFE007FE) in (0x48200000, 0x48A00000):
                    if k in KEEP[s]:
                        out.add(o)
                    k += 1
    return out


def drop_pad(paths):
    """tools/drop_pad_dtor.py on the same objects (every compile path calls this script)."""
    import importlib.util
    import os
    spec = importlib.util.spec_from_file_location("drop_pad_dtor", os.path.join(os.path.dirname(os.path.abspath(
        __file__)), "drop_pad_dtor.py"))
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return sum(m.drop(p) for p in paths)


if __name__ == "__main__":
    total = sum(fix(p) for p in sys.argv[1:])
    if total:
        print("vu0_ni_fixup: %d move(s) made .ni" % total)
    dropped = drop_pad(sys.argv[1:])
    if dropped:
        print("drop_pad_dtor: %d object(s) rewritten" % dropped)
