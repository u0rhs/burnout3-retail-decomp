"""Tiny helper: read words from an EE ELF by vaddr and disassemble with capstone (MIPS64 LE; R5900-specific ops may show as .word)."""
import struct, capstone
class Elf:
    def __init__(self, p):
        self.d = open(p, "rb").read(); self.fs = struct.unpack_from("<I", self.d, 0x34+16)[0]
    def bytes(self, va, n): o = 0x100 + va - 0x100000; return self.d[o:o+n]
    def words(self, va, n): return list(struct.unpack("<%dI" % (n//4), self.bytes(va, n)))
md = capstone.Cs(capstone.CS_ARCH_MIPS, capstone.CS_MODE_MIPS64 + capstone.CS_MODE_LITTLE_ENDIAN)
def dis(code, va):
    out = []; o = 0
    while o < len(code):
        got = list(md.disasm(code[o:o+4], va+o))
        out.append(f"{va+o:08x}: {code[o:o+4][::-1].hex()}  " + (f"{got[0].mnemonic} {got[0].op_str}" if got else ".word"))
        o += 4
    return "\n".join(out)
