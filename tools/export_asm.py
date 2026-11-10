"""Export one function from an EE ELF as GNU-style MIPS asm for m2c / decomp-permuter.
usage: export_asm.py <elf> <names.csv (elf_addr,name)> <addr_hex> <size_hex> [funcname] > out.s
EE-specific lq/sq are decoded here (capstone mis-decodes them); other undecodable words become .word."""
import csv, re, struct, sys, os
sys.path.insert(0, os.path.dirname(__file__)); from mipsdis import Elf, md
from vu0dis import decode as vu0decode
REG = ["zero","at","v0","v1","a0","a1","a2","a3","t0","t1","t2","t3","t4","t5","t6","t7","s0","s1","s2","s3","s4","s5","s6","s7","t8","t9","k0","k1","gp","sp","fp","ra"]
def sym(name): return re.sub(r"[^A-Za-z0-9_]", "_", name)
def main():
    elf, names, a, s = sys.argv[1], sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4], 16)
    nm = {int(r["elf_addr"], 16): r["name"] for r in csv.DictReader(open(names))}
    fname = sys.argv[5] if len(sys.argv) > 5 else sym(nm.get(a, f"func_{a:08X}"))
    e = Elf(elf); code = e.bytes(a, s); lines = []; targets = set()
    for o in range(0, s, 4):
        w = struct.unpack_from("<I", code, o)[0]; va = a + o; op = w >> 26
        rs, rt, imm = (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm
        if op in (0x1E, 0x1F):  # lq / sq
            lines.append((va, f"{'lq' if op == 0x1E else 'sq'} ${REG[rt]}, {hex(simm) if simm >= 0 else '-' + hex(-simm)}(${REG[rs]})")); continue
        rd = (w >> 11) & 31
        if op == 0x12:  # COP2 / VU0 macro mode: keep raw word, annotate
            lines.append((va, f".word 0x{w:08X} /* {vu0decode(w) or 'cop2?'} */")); continue
        if op in (0x36, 0x3E):  # lqc2 / sqc2 (VU0 128-bit load/store)
            lines.append((va, f"{'lqc2' if op == 0x36 else 'sqc2'} $vf{rt}, {hex(simm) if simm >= 0 else '-' + hex(-simm)}(${REG[rs]})")); continue
        if op == 0 and (w & 0x3F) in (0x18, 0x19) and rd:  # EE 3-operand mult/multu
            lines.append((va, f"{'mult' if (w & 0x3F) == 0x18 else 'multu'} ${REG[rd]}, ${REG[rs]}, ${REG[rt]}")); continue
        if w & 0xFFE0003F == 0x46000024:  # cvt.w.s: binutils rejects it for r5900, emit raw
            lines.append((va, f".word 0x{w:08X} /* cvt.w.s */")); continue
        got = list(md.disasm(code[o:o+4], va))
        if not got: lines.append((va, f".word 0x{w:08X}")); continue
        g = got[0]; txt = f"{g.mnemonic} {g.op_str}".strip()
        if op in (2, 3):  # j/jal
            t = ((va + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            if a <= t < a + s: targets.add(t); txt = f"{g.mnemonic} .L{t:08X}"
            else: txt = f"{g.mnemonic} {sym(nm.get(t, f'func_{t:08X}'))}"
        elif g.group(capstone_branch) if False else (op in (4, 5, 6, 7, 1, 0x14, 0x15, 0x16, 0x17) or (op == 0x11 and rs == 8)):
            t = va + 4 + (simm << 2); targets.add(t)
            txt = re.sub(r"0x[0-9a-f]+$", f".L{t:08X}", txt)
        txt = re.sub(r"\$(\d+)\b", lambda m: "$" + REG[int(m.group(1))], txt) if g.mnemonic not in ("mtc1", "mfc1", "lwc1", "swc1") else txt
        lines.append((va, txt))
    print(".set noat\n.set noreorder\n\nglabel " + fname)
    for va, t in lines:
        if va in targets: print(f".L{va:08X}:")
        print(f"/* {va:06X} */ {t}")
capstone_branch = None
main()
