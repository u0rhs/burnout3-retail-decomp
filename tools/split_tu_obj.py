"""split_tu_obj.py <tu.o> <outdir> <symbol>=<unit> [...]: cut one relocatable object per function out of a merged
translation unit's MWCC object, as <outdir>/<unit>.o -- the same shape as a unit compiled alone (.text, .rel.text,
.symtab, .strtab, .shstrtab, the input's e_flags), so the link script and wire-in stay per function.

MWCC emits every function in its own .text section with its relocations against symbols, so a function's object is its
section plus its relocations; a symbol defined in another section becomes an undefined global (it is defined by that
function's own object). Refuses (exit 2) a merged object with allocated data (strings, tables, statics) or a reloc
against a local symbol outside the function: those cannot be attributed to one function.

.lit4 (float literal pools) is the one allocated section allowed: tools/lit4_retarget.py --apply, run on the merged
object first (tools/tu_build.sh), renames each referenced literal to a weak global lit4_<ADDR> that the link resolves
at retail's shared pool (build/lit4_retarget_defs.txt), so the split object references it as an undefined global and
drops the private copy, as the link script drops a unit's own .lit4. A literal left local (not retargeted: unknown
retail address, or a VALUE MISMATCH, i.e. the function is not exact) still refuses the split."""
import struct
import sys

SHT_SYMTAB, SHT_STRTAB, SHT_REL, SHT_RELA, SHT_NOBITS = 2, 3, 9, 4, 8
SHF_ALLOC, SHF_EXEC = 2, 4
STB_LOCAL, STB_GLOBAL = 0, 1
STT_NOTYPE, STT_FUNC, STT_SECTION = 0, 2, 3
STB_MW_INLINE = 13      # MWCC's binding for an inline function emitted out of line (weak-like; ld treats it as local)


class Refuse(Exception):
    pass


def read_elf(path):
    d = open(path, "rb").read()
    if d[:4] != b"\x7fELF" or d[4] != 1 or d[5] != 1:
        raise Refuse("not ELF32 LE")
    e = struct.unpack_from("<16sHHIIIIIHHHHHH", d, 0)
    shoff, flags, shentsize, shnum, shstrndx = e[6], e[7], e[11], e[12], e[13]
    secs = []
    for i in range(shnum):
        sh = struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize)
        secs.append({"name_off": sh[0], "type": sh[1], "flags": sh[2], "addr": sh[3], "off": sh[4], "size": sh[5],
                     "link": sh[6], "info": sh[7], "align": sh[8], "entsize": sh[9]})
    shs = secs[shstrndx]
    strtab = d[shs["off"]:shs["off"] + shs["size"]]
    for s in secs:
        s["name"] = strtab[s["name_off"]:strtab.index(b"\0", s["name_off"])].decode()
        s["data"] = b"" if s["type"] == SHT_NOBITS else d[s["off"]:s["off"] + s["size"]]
    return e, flags, secs


def symbols(secs):
    st = [s for s in secs if s["type"] == SHT_SYMTAB][0]
    strs = secs[st["link"]]["data"]
    out = []
    for k in range(st["size"] // 16):
        name, value, size, info, other, shndx = struct.unpack_from("<IIIBBH", st["data"], k * 16)
        out.append({"name": strs[name:strs.index(b"\0", name)].decode(), "value": value, "size": size,
                    "bind": info >> 4, "type": info & 15, "other": other, "shndx": shndx})
    return out


def write_obj(path, flags, text, align, relocs, syms, comment=None):
    """syms: list of (name, value, size, bind, type, shndx) -- locals first; shndx 1 = .text, 0 = undefined."""
    strtab = b"\0"
    sym_off = {}
    for s in syms:
        if s[0] and s[0] not in sym_off:
            sym_off[s[0]] = len(strtab)
            strtab += s[0].encode() + b"\0"
    symdata = b"\0" * 16
    for name, value, size, bind, typ, shndx in syms:
        symdata += struct.pack("<IIIBBH", sym_off.get(name, 0), value, size, (bind << 4) | typ, 0, shndx)
    first_global = 1 + sum(1 for s in syms if s[3] == STB_LOCAL)
    reldata = b"".join(struct.pack("<II", off, (si << 8) | rt) for off, si, rt in relocs)
    names = ["", ".text", ".rel.text", ".symtab", ".strtab", ".shstrtab"]
    shstr = b""
    noff = []
    for n in names:
        noff.append(len(shstr))
        shstr += n.encode() + b"\0"
    body = bytearray(b"\0" * 52)
    def put(data, al):
        while len(body) % al:
            body.append(0)
        o = len(body)
        body.extend(data)
        return o
    o_text = put(text, max(align, 1))
    o_rel = put(reldata, 4)
    o_sym = put(symdata, 4)
    o_str = put(strtab, 1)
    o_shs = put(shstr, 1)
    while len(body) % 4:
        body.append(0)
    shoff = len(body)
    sh = [(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
          (noff[1], 1, SHF_ALLOC | SHF_EXEC, 0, o_text, len(text), 0, 0, align, 0),
          (noff[2], SHT_REL, 0x40, 0, o_rel, len(reldata), 3, 1, 4, 8),
          (noff[3], SHT_SYMTAB, 0, 0, o_sym, len(symdata), 4, first_global, 4, 16),
          (noff[4], SHT_STRTAB, 0, 0, o_str, len(strtab), 0, 0, 1, 0),
          (noff[5], SHT_STRTAB, 0, 0, o_shs, len(shstr), 0, 0, 1, 0)]
    if not relocs:
        sh[2] = (noff[2], SHT_REL, 0x40, 0, o_rel, 0, 3, 1, 4, 8)
    for x in sh:
        body.extend(struct.pack("<IIIIIIIIII", *x))
    hdr = struct.pack("<16sHHIIIIIHHHHHH", b"\x7fELF\x01\x01\x01" + b"\0" * 9, 1, 8, 1, 0, 0, shoff, flags,
                      52, 0, 0, 40, len(sh), 5)
    body[0:52] = hdr
    open(path, "wb").write(bytes(body))


def own_bind(sym):
    """A mapped function's object defines it for the whole link (other units call it by name), so an inline emitted out
    of line (binding 13, which ld would keep local) is written GLOBAL, as a unit compiled alone defines it."""
    return STB_GLOBAL if sym["bind"] == STB_MW_INLINE else sym["bind"]


def split(tu, outdir, want):
    e, flags, secs = read_elf(tu)
    syms = symbols(secs)
    for i, s in enumerate(secs):
        if s["flags"] & SHF_ALLOC and not s["flags"] & SHF_EXEC and s["size"] and s["name"] not in (".vtables", ".lit4"):
            raise Refuse("allocated data section %s (0x%X bytes)" % (s["name"], s["size"]))
    rels = {}
    for s in secs:
        if s["type"] == SHT_RELA:
            raise Refuse("RELA relocations")
        if s["type"] == SHT_REL:
            rels[s["info"]] = s
    made = {}
    for k, sym in enumerate(syms):
        if sym["type"] != STT_FUNC or sym["name"] not in want:
            continue
        si = sym["shndx"]
        sec = secs[si]
        if not sec["flags"] & SHF_EXEC or sym["value"] != 0 or sym["size"] != sec["size"]:
            raise Refuse("%s is not alone in its section" % sym["name"])
        out_syms, index = [], {}
        relocs = []
        if si in rels:
            rs = rels[si]
            for j in range(rs["size"] // 8):
                off, info = struct.unpack_from("<II", rs["data"], j * 8)
                t = syms[info >> 8]
                if t["type"] == STT_SECTION:
                    if t["shndx"] != si:
                        raise Refuse("%s: relocation against section %s" % (sym["name"], secs[t["shndx"]]["name"]))
                    key = ("", "sec")
                    ent = ("", 0, 0, STB_LOCAL, STT_SECTION, 1)
                elif t["shndx"] == si:
                    key = (t["name"], "def")
                    ent = (t["name"], t["value"], t["size"], own_bind(t), t["type"], 1)
                elif t["bind"] == STB_LOCAL and t["shndx"] != 0 and secs[t["shndx"]]["name"] == ".lit4":
                    raise Refuse("%s: float literal %s not retargeted (tools/lit4_retarget.py)" % (sym["name"], t["name"]))
                elif t["bind"] == STB_LOCAL and t["shndx"] != 0:
                    raise Refuse("%s: relocation against local %s of another section" % (sym["name"], t["name"]))
                else:
                    key = (t["name"], "und")
                    ent = (t["name"], 0, 0, STB_GLOBAL, STT_NOTYPE, 0)
                if key not in index:
                    index[key] = ent
                relocs.append((off, key, info & 0xFF))
        own = (sym["name"], 0, sym["size"], own_bind(sym), STT_FUNC, 1)
        ents = list(index.values())
        if own not in ents:
            ents.append(own)
        ents = sorted(set(ents), key=lambda x: (x[3] != STB_LOCAL, x[0] != sym["name"], x[0]))
        pos = {}
        for n, x in enumerate(ents):
            pos[x] = n + 1
        keymap = {k: pos[v] for k, v in index.items()}
        relocs = [(off, keymap[key], rt) for off, key, rt in relocs]
        write_obj("%s/%s.o" % (outdir, want[sym["name"]]), flags, sec["data"], sec["align"], relocs, ents)
        made[sym["name"]] = want[sym["name"]]
    missing = set(want) - set(made)
    if missing:
        raise Refuse("functions not found: %s" % ", ".join(sorted(missing)))


if __name__ == "__main__":
    want = dict(a.split("=", 1) for a in sys.argv[3:])
    try:
        split(sys.argv[1], sys.argv[2], want)
    except Refuse as e:
        print("REFUSED", e)
        sys.exit(2)
