#!/usr/bin/env python3
"""rescore_archives.py [jobs]: recompile every src/nonmatching archive of an UNPROVEN function against the current
include tree and compare with the score in its header (score = changed + 4 x |length diff|). Archives written before a
header round can be closer (or exact) now. Output: build/vt/rescore/result.tsv (name, old, new, header line) and a
summary; exact ones are listed for build/vt/hand/finish.py. Compiles in build/vt/rescore/ only (no build/va)."""
import concurrent.futures as cf, glob, os, re, subprocess, sys
sys.path.insert(0, "tools")
import tiny_batch
OUT = "build/vt/rescore"
os.makedirs(OUT, exist_ok=True)
HEAD = re.compile(r"retail (\d+) / ours (\d+) instructions, (\d+) in changed runs")
RUN = re.compile(r"retail (\d+) instrs, ours (\d+) instrs, (\d+) instrs")


def score(r, o, c):
    return int(c) + 4 * abs(int(r) - int(o))


def one(path):
    h = open(path, errors="replace").readline()
    m = re.match(r"// NONMATCHING: (\S+) -- ", h)
    hm = HEAD.search(h)
    if not m or not hm:
        return None
    name = m.group(1)
    unit = tiny_batch.where(name)
    if not unit:
        return None                                  # proven already (stale archive)
    obj = "%s/%d.o" % (OUT, abs(hash(path)))
    rc, o = tiny_batch.wsl("bash tools/tiny_compile.sh %s %s >/dev/null 2>&1; python3 -I tools/diff_vs_retail.py %s "
                           "assembly/asm/%s.s %s --seq --targets | tail -1" % (path, obj, obj, unit, name))
    try:
        os.remove(obj)
    except OSError:
        pass
    rm = RUN.search(o)
    new = score(*rm.groups()) if rm else None
    exact = bool(rm) and rm.group(3) == "0" and rm.group(1) == rm.group(2) and "(not a match)" not in o
    return name, score(*hm.groups()), new, exact, o.strip()[-120:]


def main():
    jobs = int(sys.argv[1]) if len(sys.argv) > 1 else 12
    paths = sorted(glob.glob("src/nonmatching/*.cpp"))
    rows = [r for r in cf.ThreadPoolExecutor(jobs).map(one, paths) if r]
    with open(OUT + "/result.tsv", "w") as f:
        for r in rows:
            f.write("%s\t%s\t%s\t%s\t%s\n" % r)
    better = [r for r in rows if r[2] is not None and r[2] < r[1]]
    worse = [r for r in rows if r[2] is not None and r[2] > r[1]]
    print("rescored %d: better %d, worse %d, failed %d, exact %d" % (
        len(rows), len(better), len(worse), sum(1 for r in rows if r[2] is None), sum(1 for r in rows if r[3])))
    for r in sorted(better, key=lambda r: r[2])[:25]:
        print("  %s%s: %s -> %s" % ("EXACT " if r[3] else "", r[0][:70], r[1], r[2]))


if __name__ == "__main__":
    main()
