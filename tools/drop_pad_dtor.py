"""drop_pad_dtor.py <obj.o> [...]: remove the out-of-line copy MWCC emits of a placeholder pad object's destructor.

Why (docs/known.md N140): retail's unused 16+-byte frame slots come from an unused local object with a constructor
and destructor; tools/tiny_lift.py's variant declares one (`UnkStruct_<addr>_pad`). MWCC inlines its (empty)
destructor where the object dies -- the code retail has -- but also emits an out-of-line copy
(`__dt__<n>UnkStruct_<addr>_padFv`: its own .text, a .mwcats section linked to it, that section's relocations), which
a one-function unit must not carry into the link (the original's copy lived once, in the class's own file).

Only an object with such a destructor is rewritten: its sections and symbols are deleted, every other section, symbol
and relocation renumbered, contents kept byte for byte. Anything still referring to a deleted symbol -> the object is
left as it was (and the link reports it). Called by tools/vu0_ni_fixup.py, so every compile path applies it."""
import re
import struct
import sys

PAD = re.compile(r"__dt__\d+UnkStruct_[0-9A-F]{8}_padFv$")
SHT_SYMTAB, SHT_STRTAB, SHT_REL, SHT_NOBITS = 2, 3, 9, 8


def drop(path):
    try:
        d = open(path, "rb").read()
    except FileNotFoundError:
        return 0
    if d[:4] != b"\x7fELF" or d[4] != 1 or d[5] != 1:
        return 0
    shoff, = struct.unpack_from("<I", d, 32)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 46)
    secs = []
    for i in range(shnum):
        f = list(struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize))
        secs.append({"h": f, "data": d[f[4]:f[4] + f[5]] if f[1] != SHT_NOBITS else b""})
    symi = [i for i, s in enumerate(secs) if s["h"][1] == SHT_SYMTAB]
    if len(symi) != 1:
        return 0
    symsec = secs[symi[0]]
    strtab = secs[symsec["h"][6]]["data"]
    syms = []
    for k in range(len(symsec["data"]) // 16):
        name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", symsec["data"], k * 16)
        nm = strtab[name:strtab.index(b"\0", name)].decode("latin1")
        syms.append([name, value, size, info, other, shndx, nm])
    targets = {s[5] for s in syms if PAD.match(s[6]) and 0 < s[5] < shnum}
    if not targets:
        return 0
    dropsec = set(targets)
    changed = True
    while changed:
        changed = False
        for i, s in enumerate(secs):
            if i in dropsec or i == 0:
                continue
            typ, link, inf = s["h"][1], s["h"][6], s["h"][7]
            if (typ == SHT_REL and inf in dropsec) or (typ not in (SHT_REL, SHT_SYMTAB, SHT_STRTAB) and link in dropsec):
                dropsec.add(i)
                changed = True
    dropsym = {k for k, s in enumerate(syms) if s[5] in dropsec or PAD.match(s[6])}
    # nothing kept may refer to a dropped symbol
    for i, s in enumerate(secs):
        if i in dropsec or s["h"][1] != SHT_REL:
            continue
        for j in range(len(s["data"]) // 8):
            off, info = struct.unpack_from("<II", s["data"], j * 8)
            if info >> 8 in dropsym:
                return 0
    keep = [i for i in range(shnum) if i not in dropsec]
    smap = {old: new for new, old in enumerate(keep)}
    ksyms = [k for k in range(len(syms)) if k not in dropsym]
    ymap = {old: new for new, old in enumerate(ksyms)}
    nloc = sum(1 for k in ksyms if syms[k][3] >> 4 == 0)
    if any(syms[k][3] >> 4 == 0 for k in ksyms[nloc:]):
        return 0                         # locals not first: leave it alone
    out_syms = b""
    for k in ksyms:
        name, value, size, info, other, shndx, nm = syms[k]
        if 0 < shndx < 0xFF00:
            shndx = smap[shndx]
        out_syms += struct.pack("<IIIBBH", name, value, size, info, other, shndx)
    for i in keep:
        s = secs[i]
        h = s["h"]
        if i == symi[0]:
            s["data"] = out_syms
            h[7] = nloc
        elif h[1] == SHT_REL:
            b = bytearray(s["data"])
            for j in range(len(b) // 8):
                off, info = struct.unpack_from("<II", b, j * 8)
                struct.pack_into("<II", b, j * 8, off, (ymap[info >> 8] << 8) | (info & 0xFF))
            s["data"] = bytes(b)
            h[7] = smap[h[7]]
        if h[6] and h[1] in (SHT_REL, SHT_SYMTAB) or (h[6] and h[6] in smap and h[1] not in (SHT_STRTAB,)):
            h[6] = smap.get(h[6], h[6])
    # write: ELF header, section data in order, section header table
    out = bytearray(d[:52])
    for i in keep[1:]:
        s = secs[i]
        h = s["h"]
        al = max(h[8], 1)
        while len(out) % al:
            out.append(0)
        if h[1] != SHT_NOBITS:
            h[4] = len(out)
            out += s["data"]
        h[5] = len(s["data"]) if h[1] != SHT_NOBITS else h[5]
    while len(out) % 4:
        out.append(0)
    new_shoff = len(out)
    for i in keep:
        out += struct.pack("<IIIIIIIIII", *secs[i]["h"]) if i else bytes(40)
    struct.pack_into("<I", out, 32, new_shoff)
    struct.pack_into("<HH", out, 48, len(keep), smap[shstrndx])
    open(path, "wb").write(bytes(out))
    return 1


if __name__ == "__main__":
    n = sum(drop(p) for p in sys.argv[1:])
    if n:
        print("drop_pad_dtor: %d object(s) rewritten" % n)
