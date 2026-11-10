#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# relink_check.sh <workdir> [<unit>=<object> ...]: the full retail link of tools/wire_in_full_check.sh (same link script,
# symbol files and flags, every currently wired object), except that each named unit's object is replaced by the
# given file -- through a private copy of the link script, so several checks run in parallel. Prints MATCHES RETAIL or
# DIFFERS FROM RETAIL; exit status 0 only on a match. Needs a completed wire-in (build/assembly/asm/... populated).
cd ${B3_ROOT}
W="$1"; shift
mkdir -p "$W"
cp build/SLUS_210.50.clean.ld "$W/link.ld"
for a in "$@"; do
  u="${a%%=*}"; o="${a#*=}"
  grep -q "/$u\.o(" "$W/link.ld" || { echo "unit $u not in the link script"; exit 3; }
  sed -i "s#[^ ]*/$u\.o(#$o(#" "$W/link.ld"
done
mips-linux-gnu-ld -EL -T "$W/link.ld" build/undefined_syms_auto.txt config/undefined_syms_manual.txt \
  build/lit4_retarget_defs.txt build/jtbl_retarget_defs.txt --no-check-sections --no-warn-mismatch \
  -o "$W/out.elf" 2> "$W/ld.err" || { echo "LINK FAILED: $(head -3 "$W/ld.err")"; exit 1; }
mips-linux-gnu-objcopy -O binary -j .main "$W/out.elf" "$W/out.rom"
if cmp -s "$W/out.rom" orig/SLUS_210.50.rom; then echo "MATCHES RETAIL"; rm -f "$W/out.elf"; exit 0; fi
echo "DIFFERS FROM RETAIL: $(cmp -l "$W/out.rom" orig/SLUS_210.50.rom | wc -l) bytes"
exit 1
