#!/usr/bin/env python3
"""glabel_addrs.py: write build/glabel_addrs.txt -- every glabel/dlabel in the split assembly with its address
(`name = 0xADDR;`). tools/diff_vs_retail.py reads it to resolve symbols splat used in %hi/%lo operands that are in no
symbol table (e.g. libgcc's __moddi3, whose +0x4C splat used for a plain constant). Rerun after a re-split."""
import os
import re

INS = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ")
out = {}
for dp, _, fns in os.walk("assembly/asm"):
    for fn in fns:
        if not fn.endswith(".s"):
            continue
        pend = None
        for l in open(os.path.join(dp, fn), errors="replace"):
            if l.startswith(("glabel ", "dlabel ")):
                pend = l.split()[1]
                continue
            if pend:
                m = INS.match(l)
                if m:
                    out.setdefault(pend, int(m.group(1), 16))
                    pend = None
open("build/glabel_addrs.txt", "w", newline="\n").write("".join("%s = 0x%08X;\n" % kv for kv in sorted(out.items())))
print(len(out), "labels")
