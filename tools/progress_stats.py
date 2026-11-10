"""progress_stats.py: the unmatched game functions by non-matching state, for the README counters.
stats(root) -> {"complete": (funcs, bytes), "partial": (...), "none": (...)} over game functions not in a proven unit.
State comes from each src/nonmatching archive's `// TRACK:` line (near/clean = complete C; partial = partial C;
no TRACK line = complete if the header line reports a full instruction count). Same function scan as
tools/nonmatching_coverage.py. Run directly for a summary: python3 -I tools/progress_stats.py ."""
import glob
import os
import re
import sys


def _proven(root):
    rs = []
    for l in open(os.path.join(root, "config", "proven_units.txt")):
        l = l.strip()
        if not l or l.startswith("#"):
            continue
        v, s, _ = l.split(",", 2)
        v = int(v, 16)
        rs.append((v, v + int(s, 16)))
    return rs


def _functions(root):
    funcs = {}
    nm = re.compile(r"^nonmatching (\S+), 0x([0-9A-Fa-f]+)")
    ins = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ")
    for top in ("game", "b3"):
        for f in glob.glob(os.path.join(root, "assembly", "asm", top, "**", "*.s"), recursive=True):
            cur = None
            for line in open(f, errors="ignore"):
                m = nm.match(line)
                if m:
                    cur = [m.group(1), int(m.group(2), 16)]
                    continue
                if cur:
                    m = ins.match(line)
                    if m:
                        funcs[cur[0]] = (int(m.group(1), 16), cur[1])
                        cur = None
    return funcs


def _archives(root):
    """name -> state ('complete' / 'partial') for every src/nonmatching archive."""
    d = os.path.join(root, "src", "nonmatching")
    out = {}
    for f in os.listdir(d):
        if not f.endswith((".cpp", ".c")):
            continue
        text = open(os.path.join(d, f), errors="replace").read(4000)
        m = re.search(r"^// TRACK: (\w+)", text, re.M)
        if m:
            state = "partial" if m.group(1) == "partial" else "complete"
        else:
            h = re.match(r"// NONMATCHING: \S+ -- retail (\d+) / ours (\d+)", text)
            state = "complete" if h and h.group(1) == h.group(2) else "partial"
        names = {os.path.splitext(f)[0]}
        h = re.match(r"// NONMATCHING: (\S+)", text)
        if h:
            names.add(h.group(1))
        for n in names:
            out[n] = state
    return out


def stats(root):
    rs = _proven(root)
    arch = _archives(root)
    res = {"complete": [0, 0], "partial": [0, 0], "none": [0, 0]}
    for name, (addr, size) in _functions(root).items():
        if any(lo <= addr < hi for lo, hi in rs):
            continue
        state = arch.get(name) or arch.get("func_%08X" % addr) or "none"
        res[state][0] += 1
        res[state][1] += size
    return {k: tuple(v) for k, v in res.items()}


if __name__ == "__main__":
    s = stats(sys.argv[1] if len(sys.argv) > 1 else ".")
    for k in ("complete", "partial", "none"):
        print("%-9s %5d functions %9d bytes" % (k, s[k][0], s[k][1]))
