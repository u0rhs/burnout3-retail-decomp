"""Parse a Metrowerks text link map ('# .main' section) into CSV: addr,size,section,name,source."""
import re, sys, csv
def parse(path):
    rows = []; insec = False
    for l in open(path, "rb").read().decode("latin1").split("\n"):
        l = l.rstrip("\r")
        if l.startswith("# ."): insec = l.startswith("# .main"); continue
        if not insec: continue
        m = re.match(r"\s+([0-9A-F]{8}) ([0-9A-F]{8}) (\S+)\s+(.*)$", l)
        if not m: continue
        body = m.group(4); src = ""
        if "\t(" in body: body, src = body.rsplit("\t(", 1); src = src.rstrip(") ").strip()
        rows.append((int(m[1], 16), int(m[2], 16), m[3], body.strip(), src))
    return rows
if __name__ == "__main__":
    rows = parse(sys.argv[1]); w = csv.writer(open(sys.argv[2], "w", newline=""))
    w.writerow(["addr", "size", "section", "name", "source"])
    for r in rows: w.writerow([f"{r[0]:08x}", f"{r[1]:x}", r[2], r[3], r[4]])
    print(len(rows), "symbols")

def parse_bin(path):
    """Binary CW map: u32 ver, u32 count, then count * 0x108-byte records (u32 addr, u32 size, 256-byte name+'\t(source)', 0xCD pad)."""
    import struct
    d = open(path, "rb").read(); ver, n = struct.unpack_from("<II", d, 0); out = []
    for i in range(n):
        o = 8 + i * 0x108; a, s = struct.unpack_from("<II", d, o)
        t = d[o+8:o+0x108].split(b"\0")[0].decode("latin1"); name, _, src = t.partition("\t(")
        out.append((a, s, name, src.rstrip(") ").strip()))
    return out
