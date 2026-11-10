#!/usr/bin/env python3
"""Drop empty per-object section references from a splat-generated linker script.

splat lists every object once per section kind (.text, .data, .rodata, .bss, ...), but a pure-code
object has no real .data/.rodata/.bss content, and an empty section reference can still shift the
alignment of what follows it. Keep .text references and any object that is itself a genuine data
slice (filename ending in .data.o/.rodata.o/.sdata.o/.sbss.o/.bss.o/.ctor.o); drop everything else.

Usage: clean_ld_script.py <in.ld> <out.ld>
"""
import re
import sys

SLICE_OBJ = re.compile(r"\.(data|rodata|sdata|sbss|bss|ctor)\.o$")
ENTRY = re.compile(r"\s+(\S+\.o)\((.*)\);$")


def main() -> None:
    src, dst = sys.argv[1], sys.argv[2]
    kept = []
    with open(src) as f:
        for line in f:
            m = ENTRY.match(line.rstrip("\n"))
            if m and m.group(2) != ".text" and not SLICE_OBJ.search(m.group(1)):
                continue
            kept.append(line.rstrip("\n"))
    with open(dst, "w") as f:
        f.write("\n".join(kept) + "\n")


if __name__ == "__main__":
    main()
