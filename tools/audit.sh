#!/bin/bash
. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# tools/audit.sh: fresh all-asm build, all C units rebuilt + wired, every proven object is the linked one.
cd ${B3_ROOT}
echo "== all-asm baseline"; bash tools/fresh_asm_baseline.sh 2>&1 | grep -v RWX | tail -1
echo "== C units"; bash tools/build_c_units.sh 2>&1 | grep -E "FAILED|built all|MATCHES|DIFFERS"
echo "== wire-in alone"; bash tools/wire_in_full_check.sh 2>&1 | grep -E "MATCHES|DIFFERS|undefined|discarded" | head -3
echo "== proven manifest vs linked objects"
n=0; bad=0
for b in $(grep -v '^#' config/proven_units.txt | awk -F, 'NF>=5 {print $4}' | sort -u); do
  n=$((n+1))
  dst=$(grep -ho "build/assembly/asm/[^ ]*/$b\.o" tools/wire_in_full_check.sh tools/wire_in_batch.sh | head -1)
  [ -z "$dst" ] && dst=$(grep -o "build/assembly/asm/b3/$b\.o\|\${name}" tools/wire_in_full_check.sh | head -1)
  if [ -z "$dst" ] || [ "$dst" = '${name}' ]; then
    if grep -q "for name in .*\b$b\b" tools/wire_in_full_check.sh; then dst=build/assembly/asm/b3/$b.o; fi
  fi
  if [ -z "$dst" ] || ! cmp -s build/mw/$b.o "$dst"; then echo "  NOT LINKED/DIFFERENT: $b ($dst)"; bad=$((bad+1)); fi
done
echo "  units: $n, problems: $bad"
echo "== drafts (DRAFT banner) not in the manifest"
for f in $(grep -rl "^// DRAFT" src); do b=$(basename $f .cpp); grep -q ",$b," config/proven_units.txt && echo "  WIRED DRAFT: $b" || echo "  draft: $b"; done
echo "== leftover experiment markers"; grep -rn "TEMP\|EXPERIMENT" include src | grep -v "TEMPLATE" | head
python3 tools/progress_report.py 2>/dev/null | tail -2
