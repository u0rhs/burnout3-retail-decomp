"""obj_same.py <a.o> <b.o>: exit 0 when two MWCC objects link to the same bytes: same disassembly and relocations of
every code section, same contents of every other allocated section, same defined symbols (sizes included).
Ignored: .mwcats / .comment (metadata), .vtables (discarded by the link script), and symbol binding (wire-in weakens
__vt__ symbols in build/mw). Prints the first difference otherwise. Runs under WSL (mips-linux-gnu binutils)."""
import re
import subprocess
import sys

SKIP = (".mwcats", ".rel.mwcats", ".comment", ".vtables", ".rel.vtables")


def run(*a):
    return subprocess.run(a, capture_output=True, text=True).stdout


def canon(o):
    dis = run("mips-linux-gnu-objdump", "-dr", "--no-show-raw-insn", o)
    dis = [l for l in dis.split("\n")[3:] if l.strip() and not l.startswith("Disassembly of")]
    secs = []
    for l in run("mips-linux-gnu-readelf", "-SW", o).split("\n"):
        m = re.match(r"\s*\[\s*\d+\]\s+(\S+)\s+(\S+)\s+\S+\s+\S+\s+(\S+)\s+\S+\s+(\S*)", l)
        if m and m.group(1) not in SKIP and m.group(2) in ("PROGBITS", "NOBITS") and "A" in m.group(4) \
                and m.group(1) != ".text":
            secs.append((m.group(1), m.group(2), m.group(3)))
    data = []
    for name, typ, size in sorted(set(secs)):
        data.append("%s %s %s" % (name, typ, size))
        if typ == "PROGBITS":
            data += run("mips-linux-gnu-objdump", "-s", "-j", name, o).split("\n")[4:]
    syms = []
    for l in run("mips-linux-gnu-readelf", "-sW", o).split("\n"):
        f = l.split()
        # name and section index from the end (the visibility column can carry extra words)
        if len(f) >= 8 and f[0].endswith(":") and f[-2] != "UND" and f[3] in ("FUNC", "OBJECT") and \
                not f[-1].startswith("__vt__"):
            syms.append("%s %s %s" % (f[-1], f[3], f[2]))
    return dis, data, sorted(syms)


def anon(lines):
    """MWCC's anonymous locals (@NNN: string literals and the like) are numbered per translation unit, so a header
    that declares more shifts the numbers; the names never reach the link (local), their contents are compared."""
    return [re.sub(r"@\d+", "@N", l) for l in lines]


a, b = [tuple(anon(x) for x in canon(o)) for o in (sys.argv[1], sys.argv[2])]
for what, x, y in zip(("code", "data", "symbols"), a, b):
    if x != y:
        for i, (p, q) in enumerate(zip(x, y)):
            if p != q:
                print("%s differs: %r / %r" % (what, p.strip(), q.strip()))
                break
        else:
            print("%s differs: %d / %d lines" % (what, len(x), len(y)))
        sys.exit(1)
sys.exit(0)
