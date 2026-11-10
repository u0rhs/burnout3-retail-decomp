"""syscall_stubs.py: name retail's EE kernel syscall stubs (`addiu v1,zero,N; syscall`) by their syscall number.

Number -> name: research/ext/ps2sdk/ee/kernel/include/syscallnr.h (the kernel ABI; ps2sdk is a re-creation, so a
name is only accepted where our own evidence has it too: the E-build maps' Libkernl.a klib.o entries,
research/E_*_symbols.csv). Output: research/syscall_stubs.csv -- address, number, ps2sdk name, in an E map (y/n),
current name in config/symbol_addrs_b3names.txt."""
import csv
import glob
import re
import struct

d = open("orig/SLUS_210.50", "rb").read()
# ELF program headers: file offset -> vaddr
phoff, = struct.unpack_from("<I", d, 0x1C)
phentsize, phnum = struct.unpack_from("<HH", d, 0x2A)
segs = []
for i in range(phnum):
    p_type, p_offset, p_vaddr, _, p_filesz = struct.unpack_from("<IIIII", d, phoff + i * phentsize)
    if p_type == 1:
        segs.append((p_offset, p_vaddr, p_filesz))


def vaddr(off):
    for o, v, n in segs:
        if o <= off < o + n:
            return v + off - o
    return None


nr = {}
for l in open("research/ext/ps2sdk/ee/kernel/include/syscallnr.h"):
    m = re.match(r"#define __NR_(\w+)\s+\(?(-?(?:0x[0-9A-Fa-f]+|\d+))\)?\s*(//.*)?$", l.strip())
    if m:
        nr.setdefault(int(m.group(2), 0), (m.group(1), "arbitrar" in (m.group(3) or "").lower()))
emap = set()
for f in glob.glob("research/E_*_symbols.csv"):
    for row in csv.reader(open(f, errors="replace")):
        if len(row) >= 4 and "libkernl" in row[3].lower():
            emap.add(row[2])
cur = {}
for l in open("config/symbol_addrs_b3names.txt"):
    m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);", l)
    if m:
        cur[int(m.group(2), 16)] = m.group(1)
rows = []
for i in range(4, len(d) - 4, 4):
    if struct.unpack_from("<I", d, i)[0] != 0x0000000C:
        continue
    p = struct.unpack_from("<I", d, i - 4)[0]
    if p >> 16 != 0x2403:                       # addiu v1, zero, imm
        continue
    n = p & 0xFFFF
    n = n - 0x10000 if n & 0x8000 else n
    a = vaddr(i - 4)
    name, arb = nr.get(n, ("", False))
    rows.append((a, n, name, "y" if name in emap else ("arbitrary" if arb else "n"), cur.get(a, "")))
rows.sort()
with open("research/syscall_stubs.csv", "w", newline="\n") as f:
    w = csv.writer(f, lineterminator="\n")
    w.writerow(["address", "syscall", "ps2sdk_name", "in_E_map", "current_name"])
    for a, n, name, e, c in rows:
        w.writerow(["0x%08X" % a if a else "", n, name, e, c])
print(len(rows), "stubs;", sum(1 for r in rows if r[3] == "y"), "named and in an E map;",
      sum(1 for r in rows if r[4]), "already named in our table")
