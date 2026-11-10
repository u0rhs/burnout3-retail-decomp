"""Minimal ELF32-LE inspector (no deps): header, sections, segments, symtab summary."""
import struct, sys
def main(p):
    d = open(p, "rb").read()
    print("file", p, len(d), "bytes; magic", d[:4])
    if d[:4] != b"\x7fELF":
        print("NOT AN ELF; first 64 bytes:", d[:64].hex()); return
    (typ, mach, ver, entry, phoff, shoff, flags, ehsz, phes, phn, shes, shn, shstr) = struct.unpack_from("<HHIIIIIHHHHHH", d, 16)
    print(f"type={typ} machine={mach:#x} entry={entry:#x} flags={flags:#x} phnum={phn} shnum={shn} shoff={shoff:#x}")
    for i in range(phn):
        t, o, va, pa, fs, ms, fl, al = struct.unpack_from("<8I", d, phoff+i*phes)
        print(f"  PH{i}: type={t:#x} off={o:#x} vaddr={va:#x} filesz={fs:#x} memsz={ms:#x} flags={fl:#x}")
    if not shn or shoff > len(d): print("  no section headers"); return
    secs = [struct.unpack_from("<10I", d, shoff+i*shes) for i in range(shn)]
    so = secs[shstr][4]
    def nm(o, base):
        e = d.index(b"\0", base+o); return d[base+o:e].decode("latin1")
    for i, s in enumerate(secs):
        print(f"  SH{i:<2} {nm(s[0], so):<14} type={s[1]:#x} addr={s[3]:#x} off={s[4]:#x} size={s[5]:#x}")
    for i, s in enumerate(secs):
        if s[1] in (2, 11):
            strs = secs[s[6]][4]; n = s[5]//16
            print(f"  symtab SH{i}: {n} symbols")
            for k in range(min(n, 40)):
                a = struct.unpack_from("<IIIBBH", d, s[4]+k*16)
                print("   ", hex(a[1]), nm(a[0], strs))
main(sys.argv[1])
