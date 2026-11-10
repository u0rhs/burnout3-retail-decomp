#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# hc_verify.sh <list> <srcdir> <incdir> <outdir>: compile every listed unit (file names, one per line) from <srcdir>
# with <incdir> as an extra include directory, 32 at a time, and compare each object with build/mw/<unit>.o
# (tools/obj_same.py). Prints "SAME <file>" / "DIFF <file> <reason>" / "ERROR <file> <message>" lines.
# Builds exactly as the reference objects were built (cloud review 2026-10-28): through mwcc_run (the configured host,
# wibo by default -- not wine directly), and units with their own tools/compile_<unit>.sh run a copy of that script
# retargeted at <srcdir>/<outdir>, so its lit4/jtbl/sdata post-processing is applied like verify_all.sh does.
cd ${B3_ROOT}
export LIST="$1" SRCD="$2" INCD="$3" OUTD="$4"
mkdir -p "$OUTD"
one() {
  f="$(echo "$1" | tr -d '\r')"; u="${f%.cpp}"
  . tools/mwcc_flags.sh
  R="Z:${B3_ROOT_WIN}\\"
  export WINEDEBUG=-all MWCIncludes="${R}include" LM_LICENSE_FILE="${B3_LICENSE_WIN}"
  src="${R}$(echo "$SRCD/$f" | tr '/' '\\')"; out="${R}$(echo "$OUTD/$u.o" | tr '/' '\\')"; inc="${R}$(echo "$INCD" | tr '/' '\\')"
  rm -f "$OUTD/$u.o"
  script=$(grep -l "\\\\$u.cpp\"" tools/compile_*.sh 2>/dev/null | grep -v compile_all.sh | head -1)
  if [ -n "$script" ]; then
    # same compile + post-processing as the reference build, pointed at the candidate source/include/object
    tmp="$OUTD/${u}.compile.sh"
    python3 -I - "$script" "$tmp" "$u" "$SRCD/$f" "$OUTD/$u.o" "$INCD" <<'PY'
import re, sys
script, tmp, u, src, obj, inc = sys.argv[1:7]
t = open(script).read()
win = lambda p: "$R\\" + p.replace("/", "\\")
t = re.sub(r'"\$R\\[^"]*\\%s\.cpp"' % re.escape(u), '"%s"' % win(src).replace("\\", "\\\\"), t)
t = t.replace("$R\\build\\mw\\%s.o" % u, win(obj)).replace("build/mw/%s.o" % u, obj)
t = t.replace("mwcc_run $MWCC_FLAGS", 'mwcc_run $MWCC_FLAGS -i "%s"' % win(inc).replace("\\", "\\\\"), 1)
open(tmp, "w").write(t)
PY
    msg=$(bash "$tmp" 2>&1)
  else
    msg=$(cd ${B3_MWCC_DIR} && mwcc_run $MWCC_FLAGS -i "$inc" -c "$src" -o "$out" 2>&1)
  fi
  if [ ! -f "$OUTD/$u.o" ] || echo "$msg" | grep -qiE "error|COMPILE EXIT: [1-9]"; then
    echo "ERROR $f $(echo "$msg" | grep -i -A2 error | tr '\n' ' ' | cut -c1-300)"; return
  fi
  [ -z "$script" ] && python3 -I tools/vu0_ni_fixup.py "$OUTD/$u.o" > /dev/null
  # a regrouped translation unit (config/tu_units.txt): split per function, every piece against its unit's object
  tl=$(grep -E "(^|/)$f " config/tu_units.txt 2>/dev/null | head -1)
  if [ -n "$tl" ]; then
    pd="$OUTD/${u}_pieces"; rm -rf "$pd"; mkdir -p "$pd"
    pairs=$(echo "$tl" | cut -d' ' -f2-)
    s=$(python3 -I tools/split_tu_obj.py "$OUTD/$u.o" "$pd" $pairs) || { echo "DIFF $f split: $s"; return; }
    for pr in $pairs; do
      un="${pr#*=}"
      r=$(python3 -I tools/obj_same.py "$pd/$un.o" "build/mw/$un.o") || { echo "DIFF $f $un: $r"; return; }
    done
    echo "SAME $f"; return
  fi
  r=$(python3 -I tools/obj_same.py "$OUTD/$u.o" "build/mw/$u.o")
  if [ $? = 0 ]; then echo "SAME $f"; else echo "DIFF $f $r"; fi
}
export -f one
xargs -a "$LIST" -P 32 -I{} bash -c 'one {}'
