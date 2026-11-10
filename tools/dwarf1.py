"""Minimal DWARF 1 (.debug) reader for Metrowerks PS2 ELFs: struct/class/union layouts with member names and offsets.
usage: dwarf1.py <elf> <out.csv>   ->  type_tag,type_name,type_size,member,offset,member_type
DWARF 1: entries = u32 length (< 8: padding), u16 tag, attributes (u16 code = name << 4 | form).
Forms: 1 addr(4) 2 ref(4) 3 block2 4 block4 5 data2 6 data4 7 data8 8 string.
Children of an entry with AT_sibling are the entries between its end and the sibling offset."""
import struct, sys, csv
TAG = {0x02: 'class', 0x13: 'struct', 0x17: 'union', 0x0d: 'member', 0x1c: 'inheritance', 0x16: 'typedef', 0x04: 'enum'}
FUND = {1: 'char', 2: 'signed char', 3: 'unsigned char', 4: 'short', 5: 'signed short', 6: 'unsigned short', 7: 'int',
        8: 'signed int', 9: 'unsigned int', 0xa: 'long', 0xb: 'signed long', 0xc: 'unsigned long', 0xd: 'pointer',
        0xe: 'float', 0xf: 'double', 0x10: 'long double', 0x14: 'void', 0x15: 'bool', 0x8000: 'long long', 0x8008: 'u_long128'}
def sections(d):
    shoff, = struct.unpack_from('<I', d, 32); n, = struct.unpack_from('<H', d, 48); si, = struct.unpack_from('<H', d, 50)
    S = [struct.unpack_from('<10I', d, shoff + 40 * i) for i in range(n)]
    nm = lambda off: d[S[si][4] + off:d.index(b'\0', S[si][4] + off)].decode('latin1')
    return {nm(s[0]): (s[4], s[5]) for s in S}
def parse(d, off, size):
    ents = {}; p = off; end = off + size
    while p < end:
        ln, = struct.unpack_from('<I', d, p)
        if ln < 8: p += max(ln, 4); continue
        tag, = struct.unpack_from('<H', d, p + 4); q = p + 6; at = {}
        while q < p + ln:
            code, = struct.unpack_from('<H', d, q); q += 2; form = code & 0xf; name = code >> 4
            if form in (1, 2, 6): v, = struct.unpack_from('<I', d, q); q += 4
            elif form == 5: v, = struct.unpack_from('<H', d, q); q += 2
            elif form == 7: v = d[q:q + 8]; q += 8
            elif form == 3: l, = struct.unpack_from('<H', d, q); v = d[q + 2:q + 2 + l]; q += 2 + l
            elif form == 4: l, = struct.unpack_from('<I', d, q); v = d[q + 4:q + 4 + l]; q += 4 + l
            elif form == 8: z = d.index(b'\0', q); v = d[q:z].decode('latin1'); q = z + 1
            else: break
            at[name] = v
        ents[p - off] = (tag, at, ln); p += ln
    return ents
def loc_offset(b):   # OP_CONST(4) u32 ... OP_ADD(7)
    if isinstance(b, bytes) and len(b) >= 5 and b[0] == 4: return struct.unpack_from('<I', b, 1)[0]
    return None
def tname(at, ents):
    if 0x5 in at: return FUND.get(at[0x5], 'fund%x' % at[0x5])
    if 0x7 in at: return ents.get(at[0x7], (0, {}, 0))[1].get(0x3, '?')
    if 0x6 in at or 0x8 in at:  # modified type: block (modifiers..., then fund u16 or udt ref u32)
        b = at.get(0x6) or at.get(0x8); ptr = '*' * sum(1 for c in b[:-2 if 0x6 in at else -4] if c == 1)
        base = FUND.get(struct.unpack_from('<H', b, len(b) - 2)[0], '?') if 0x6 in at else ents.get(struct.unpack_from('<I', b, len(b) - 4)[0], (0, {}, 0))[1].get(0x3, '?')
        return base + ptr
    return ''
def main():
    d = open(sys.argv[1], 'rb').read(); off, size = sections(d)['.debug']
    ents = parse(d, off, size); keys = sorted(ents)
    w = csv.writer(open(sys.argv[2], 'w', newline='', encoding='utf-8')); w.writerow(['type_tag', 'type_name', 'type_size', 'member', 'offset', 'member_type'])
    nt = nm_ = 0
    import bisect
    for k in keys:
        tag, at, ln = ents[k]
        if tag not in (0x02, 0x13, 0x17) or 0x3 not in at or 0x1 not in at: continue
        sib = at[0x1] - 0 if at[0x1] else k + ln
        i = bisect.bisect_right(keys, k)
        nt += 1
        while i < len(keys) and keys[i] < sib:
            c = keys[i]; ct, ca, cl = ents[c]
            if ct in (0x0d, 0x1c):
                o = loc_offset(ca.get(0x2))
                w.writerow([TAG[tag], at[0x3], at.get(0xb, ''), ca.get(0x3, '(base)' if ct == 0x1c else ''), '' if o is None else hex(o), tname(ca, ents)]); nm_ += 1
            nxt = ca.get(0x1)
            if nxt and nxt > c: i = bisect.bisect_left(keys, nxt)
            else: i += 1
    print('types', nt, 'members', nm_)
if __name__ == '__main__': main()
