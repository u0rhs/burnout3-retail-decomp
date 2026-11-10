"""dnat_align.py <name regex> ...: find functions of the Jun 8 2004 prototype (orig/dnat/DNAT_200.45) by name.

The link map on that disc (DNAT_200.MAP, mirrored in research/E_dnat_symbols.csv) is not the map of that exact
executable: addresses are shifted by an offset that varies by region (CGtV4d::operator*(CGtV4d) is listed at 0x19B140
and sits at 0x1987D0, known.md N81). The map's own layout is consistent, so for a target the shift is the one at which
the most of its map neighbours (+-12 functions) end in `jr ra` (plus delay slot) in the executable at their listed
size; prints "<name> map 0x... -> elf 0x... (score k/n)" per match. Used to recover GtMathPs2 inline bodies."""
import csv
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ELF = (ROOT / "orig" / "dnat" / "DNAT_200.45").read_bytes()
BASE, OFF = 0x100000, 0x100           # first LOAD segment: vaddr 0x100000 at file offset 0x100
JR_RA = 0x03E00008


def word(a):
    o = a - BASE + OFF
    return struct.unpack_from("<I", ELF, o)[0] if 0 <= o < len(ELF) - 4 else None


def ends_at(a, n):
    return n >= 8 and word(a + n - 8) == JR_RA


rows = [r for r in csv.DictReader(open(ROOT / "research" / "E_dnat_symbols.csv", encoding="utf-8"))
        if r["section"] == ".text" and int(r["size"], 16) > 0]
rows.sort(key=lambda r: int(r["addr"], 16))


def align(k, span=12, rng=0x8000):
    a0 = int(rows[k]["addr"], 16)
    nb = [(int(rows[j]["addr"], 16), int(rows[j]["size"], 16)) for j in range(max(0, k - span), min(len(rows), k + span + 1))]
    best = None
    for d in range(-rng, rng + 1, 16):
        if not ends_at(a0 + d, int(rows[k]["size"], 16)):
            continue
        sc = sum(1 for a, n in nb if ends_at(a + d, n))
        if best is None or sc > best[0]:
            best = (sc, d)
    return best, len(nb)


if __name__ == "__main__":
    pats = [re.compile(p) for p in sys.argv[1:]]
    for k, r in enumerate(rows):
        if any(p.search(r["name"]) for p in pats):
            best, n = align(k)
            if best is None or best[0] < n // 2:
                best, n = align(k, rng=0x40000)       # a larger shift further into the executable
            a0 = int(r["addr"], 16)
            if best:
                print("%s  map 0x%X -> elf 0x%X  size 0x%s  (score %d/%d)  [%s]" % (r["name"], a0, a0 + best[1], r["size"],
                                                                                best[0], n, r["source"]))
            else:
                print("%s  map 0x%X -> not found" % (r["name"], a0))
