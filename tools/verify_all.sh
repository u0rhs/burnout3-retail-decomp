#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# verify_all.sh [pattern]: recompile every proven unit (config/proven_units.txt; only sources matching the optional
# grep pattern) and compare each object with the one in build/mw (tools/obj_same.py) -- the gate for a shared-header
# change (GtMathPs2.h, include/b3/classes). build/mw is snapshotted first and restored afterwards, so a run never
# changes the build. Plain units compile 32 at a time (tools/tiny_compile.sh); regrouped files compile once and are
# split per function (config/tu_units.txt); units with their own tools/compile_*.sh (post-processing: lit4/jtbl
# retargets) run those scripts one at a time. Output: build/va/result.txt, lines SAME|DIFF|ERROR <source> [why].
cd ${B3_ROOT}
. tools/pipeline_guard.sh
PAT="${1:-.}"
rm -rf build/va && mkdir -p build/va/obj build/va/snap
cp -p build/mw/*.o build/va/snap/
srcs=$(grep -v '^#' config/proven_units.txt | awk -F, 'NF>=5 {print $5}' | sort -u | grep -E "$PAT")
: > build/va/plain.txt; : > build/va/script.txt; : > build/va/tu.txt
for s in $srcs; do
  b=$(basename "$s" .cpp)
  if grep -q "^$s " config/tu_units.txt 2>/dev/null; then echo "$s" >> build/va/tu.txt
  elif grep -l "\\\\$b.cpp\"" tools/compile_*.sh 2>/dev/null | grep -qv compile_all.sh; then echo "$s" >> build/va/script.txt
  else echo "$s" >> build/va/plain.txt; fi
done
plain() {
  s="$1"; b=$(basename "$s" .cpp); o=build/va/obj/$b.o
  bash tools/tiny_compile.sh "$s" "$o" > build/va/obj/$b.log 2>&1
  [ -f "$o" ] || { echo "ERROR $s $(grep -i -A2 error build/va/obj/$b.log | tr '\n' ' ' | cut -c1-200)"; return; }
  r=$(python3 -I tools/obj_same.py "$o" build/va/snap/$b.o) && echo "SAME $s" || echo "DIFF $s $r"
}
tu() {
  s="$1"; stem=$(basename "$s" .cpp); o=build/va/obj/tu_$stem.o; pd=build/va/obj/p_$stem; mkdir -p "$pd"
  bash tools/tiny_compile.sh "$s" "$o" > /dev/null 2>&1
  [ -f "$o" ] || { echo "ERROR $s compile"; return; }
  python3 -I tools/lit4_retarget.py "$o" orig/SLUS_210.50.rom "$pd/lit4_defs.txt" --apply > "$pd/lit4.log" 2>&1 \
    || { echo "DIFF $s lit4 $(tail -1 "$pd/lit4.log")"; return; }
  pairs=$(grep "^$s " config/tu_units.txt | cut -d' ' -f2-)
  python3 -I tools/split_tu_obj.py "$o" "$pd" $pairs > /dev/null || { echo "DIFF $s split"; return; }
  for pr in $pairs; do u="${pr#*=}"
    r=$(python3 -I tools/obj_same.py "$pd/$u.o" build/va/snap/$u.o) || { echo "DIFF $s $u: $r"; return; }
  done
  echo "SAME $s"
}
export -f plain tu
{
  xargs -a build/va/plain.txt -P 32 -I{} bash -c 'plain {}'
  xargs -a build/va/tu.txt -P 32 -I{} bash -c 'tu {}'
  while read -r s; do
    b=$(basename "$s" .cpp)
    script=$(grep -l "\\\\$b.cpp\"" tools/compile_*.sh | grep -v compile_all.sh | head -1)
    rm -f build/mw/$b.o
    bash "$script" > build/va/obj/$b.slog 2>&1
    python3 -I tools/vu0_ni_fixup.py build/mw/$b.o > /dev/null
    if [ ! -f build/mw/$b.o ]; then echo "ERROR $s (script)"
    else r=$(python3 -I tools/obj_same.py build/mw/$b.o build/va/snap/$b.o) && echo "SAME $s" || echo "DIFF $s $r"; fi
  done < build/va/script.txt
} > build/va/result.txt 2>&1
cp -p build/va/snap/*.o build/mw/
awk '{print $1}' build/va/result.txt | sort | uniq -c
echo "plain $(wc -l < build/va/plain.txt), regrouped $(wc -l < build/va/tu.txt), scripted $(wc -l < build/va/script.txt)"
