#!/usr/bin/env python3
"""Add `// TRACK:` / `// EQUIV:` lines to src/nonmatching archives that have none (docs/conventions.md "Non-matching
track"). Mechanical first pass: `partial` when the notes say skeleton / not decoded / scalar stand-in for VU code, or
ours has under 85% of retail's instructions; otherwise `near`. EQUIV is `unreviewed` (nobody has checked it yet).
Usage: python3 -I tools/tag_nonmatching_track.py [--apply] [--skip <list of names>] [--only <list of names>]   (dry run by default)"""
import os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
D = os.path.join(ROOT, "src", "nonmatching")
HEAD = re.compile(r"// NONMATCHING: (\S+) -- retail (\d+) / ours (\d+) instructions")
PARTIAL = re.compile(r"skeleton|not decoded|scalar (stand-?in|placeholder|version)|stand-?ins? for (the )?VU", re.I)


def classify(text, retail, ours):
    m = PARTIAL.search(text)
    if m:
        return "partial", m.group(0).lower()
    if retail and ours < 0.85 * retail:
        return "partial", "ours %d of retail %d instructions" % (ours, retail)
    return "near", ""


def main():
    apply = "--apply" in sys.argv
    skip = set()
    if "--skip" in sys.argv:
        skip = set(open(sys.argv[sys.argv.index("--skip") + 1]).read().split())
    only = None
    if "--only" in sys.argv:
        only = set(open(sys.argv[sys.argv.index("--only") + 1]).read().split())
    counts = {"near": 0, "partial": 0, "tagged already": 0, "no header": 0, "skipped": 0}
    for f in sorted(os.listdir(D)):
        if not f.endswith((".cpp", ".c")):
            continue
        p = os.path.join(D, f)
        lines = open(p, encoding="utf-8", errors="replace").read().split("\n")
        m = HEAD.match(lines[0])
        if not m:
            counts["no header"] += 1
            continue
        if m.group(1) in skip or (only is not None and m.group(1) not in only):
            counts["skipped"] += 1
            continue
        if any(l.startswith("// TRACK:") for l in lines[:12]):
            counts["tagged already"] += 1
            continue
        track, why = classify("\n".join(lines[:12]), int(m.group(2)), int(m.group(3)))
        counts[track] += 1
        at = next((i + 1 for i, l in enumerate(lines[:12]) if l.startswith("// Archived near-miss")), 1)
        new = ["// TRACK: %s%s" % (track, " (%s)" % why if why else ""),
               "// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)"]
        if apply:
            open(p, "w", encoding="utf-8").write("\n".join(lines[:at] + new + lines[at:]))
    print(("applied: " if apply else "dry run: ") + ", ".join("%s %d" % kv for kv in counts.items()))


if __name__ == "__main__":
    main()
