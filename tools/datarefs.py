"""Data references from code: lui/addiu|load|store pairs and $gp-relative accesses, per function and instruction index.
refs(features, gp) -> list of (func_entry, instr_index_of_low_part, target_addr, kind)."""
import struct
LOADSTORE = {0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x28, 0x29, 0x2B, 0x31, 0x35, 0x37, 0x39, 0x3D, 0x3F, 0x1E, 0x1F, 0x36, 0x3E, 0x1A, 0x1B, 0x2C, 0x2D, 0x22, 0x26, 0x2A, 0x2E}
def gp_of(path):
    d = open(path, 'rb').read(); shoff = struct.unpack_from('<I', d, 32)[0]; n = struct.unpack_from('<H', d, 48)[0]
    for i in range(n):
        s = struct.unpack_from('<10I', d, shoff + 40 * i)
        if s[1] == 0x70000006: return struct.unpack_from('<i', d, s[4] + 20)[0] & 0xFFFFFFFF
def refs_of(entry, W, gp):
    out = []; hi = {}
    for i, w in enumerate(W):
        op = w >> 26; rs = (w >> 21) & 31; rt = (w >> 16) & 31; imm = w & 0xFFFF; simm = imm - 0x10000 if imm & 0x8000 else imm
        if op == 0xF: hi[rt] = (imm << 16, i); continue
        if op in (0x9,) or op in LOADSTORE:
            if rs == 28 and gp is not None: out.append((entry, i, (gp + simm) & 0xFFFFFFFF, 'gp'))
            elif rs in hi:
                out.append((entry, i, (hi[rs][0] + simm) & 0xFFFFFFFF, 'hilo'))
            if op == 0x9 or op in (0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x37, 0x1E, 0x1A, 0x1B, 0x22, 0x26, 0x31, 0x35):
                hi.pop(rt, None)  # rt overwritten (loads / addiu); stores and lwc1/lqc2 keep it
            continue
        if op in (2, 3) or (op == 0 and (w & 0x3F) in (8, 9)): continue
        # any other instruction writing a GPR invalidates its hi
        if op == 0: hi.pop((w >> 11) & 31, None)
        elif op in (0x8, 0xA, 0xB, 0xC, 0xD, 0xE, 0x18, 0x19): hi.pop(rt, None)
        elif op == 0x1C: hi.pop((w >> 11) & 31, None)
    return out
def refs(F, gp):
    out = []
    for a, f in F.items(): out += refs_of(a, f['W'], gp)
    return out
