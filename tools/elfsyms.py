"""Dump an ELF .symtab: elfsyms.py <elf> [out.csv] -> addr,size,type,bind,section,name"""
import struct, sys, csv
d = open(sys.argv[1], 'rb').read(); shoff, = struct.unpack_from('<I', d, 32); n, = struct.unpack_from('<H', d, 48); si, = struct.unpack_from('<H', d, 50)
S = [struct.unpack_from('<10I', d, shoff + 40 * i) for i in range(n)]
nm = lambda off, base: d[base + off:d.index(b'\0', base + off)].decode('latin1')
shn = [nm(s[0], S[si][4]) for s in S]
rows = []
for s in S:
    if s[1] != 2: continue
    sb = S[s[6]][4]
    for k in range(s[5] // 16):
        a, v, z, info, o, x = struct.unpack_from('<IIIBBH', d, s[4] + 16 * k)
        rows.append([f'{v:08x}', z, info & 15, info >> 4, shn[x] if x < len(shn) else hex(x), nm(a, sb)])
w = csv.writer(open(sys.argv[2], 'w', newline='', encoding='utf-8') if len(sys.argv) > 2 else sys.stdout)
w.writerow(['addr', 'size', 'type', 'bind', 'section', 'name']); w.writerows(rows)
