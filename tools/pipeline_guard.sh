# tools/pipeline_guard.sh: sourced by tools/verify_all.sh and tools/wire_in_full_check.sh. They share build/va and
# build/mw with the pipeline, so a manual run while tools/cycle.py is running corrupts its gate (memory: no manual
# gate while the pipeline runs). Refuses unless the caller descends from the running cycle.py (its own gate).
# Stop the pipeline first: touch build/cycle.stop, wait until `pgrep -f tools/cycle.py` is empty.
b3_pipeline_guard() {
  local pids p
  pids=" $(pgrep -f '^python[0-9.]* .*tools/cycle\.py' | tr '\n' ' ')"
  [ "$pids" = " " ] && return 0
  p=$$
  while [ -n "$p" ] && [ "$p" -gt 1 ]; do
    case "$pids" in *" $p "*) return 0 ;; esac
    p=$(ps -o ppid= -p "$p" 2>/dev/null | tr -d ' ')
  done
  echo "pipeline_guard: refused, tools/cycle.py is running (pid$pids); it shares build/va and build/mw." >&2
  echo "pipeline_guard: stop it first (touch build/cycle.stop; wait for pgrep -f tools/cycle.py to be empty)." >&2
  exit 3
}
b3_pipeline_guard
