#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# hc_verify_installed.sh: after tools/hdr_consolidate.py --apply, recompile every adopted unit from its installed
# location (src/b3/_unclassified/<file>, or a regrouped file's path in config/tu_units.txt) against include/ and
# compare with build/mw (tools/hc_verify.sh). Output: build/hc/installed.out.
cd ${B3_ROOT}
mkdir -p build/hc/inst
rm -f build/hc/inst/*.cpp
while read -r f; do
  f="${f%$'\r'}"
  [ -z "$f" ] && continue
  p=$(grep -E "(^|/)$f " config/tu_units.txt | cut -d' ' -f1)
  [ -z "$p" ] && p="src/b3/_unclassified/$f"
  cp "$p" "build/hc/inst/$f"
done < build/hc/adopted.txt
bash tools/hc_verify.sh build/hc/adopted.txt build/hc/inst include build/hc/obj3 > build/hc/installed.out 2>&1
awk '{print $1}' build/hc/installed.out | sort | uniq -c
