"""run_queue.py <queue.json> <out.txt>: run tools/tiny_batch.py over a queue to the end, re-launching it on the
candidates not yet logged if the process is terminated from outside (seen 2026-10-23: no traceback, exit 127).
tiny_batch.py's own start-up recovery (build/batch_bak/INPROGRESS.json) undoes a half-wired candidate first."""
import json
import subprocess
import sys

queue, out = sys.argv[1], sys.argv[2]
cands = json.load(open(queue))
open(out, "w").close()
for attempt in range(8):
    done = set()
    for l in open(out):
        f = l.split()
        if len(f) > 1 and f[0] in ("PROVEN", "PARKED", "SKIP"):
            done.add(f[1][:60])
    rest = [c for c in cands if c["name"][:60] not in done]
    if not rest:
        break
    json.dump(rest, open("build/_run_queue.json", "w"), indent=1)
    with open(out, "a") as f:
        f.write("== run_queue attempt %d: %d candidates\n" % (attempt, len(rest)))
        f.flush()
        r = subprocess.run([sys.executable, "-X", "faulthandler", "-u", "tools/tiny_batch.py", "build/_run_queue.json",
                            "--retry"], stdout=f, stderr=subprocess.STDOUT)
        f.write("== exit %d\n" % r.returncode)
    text = open(out).read()
    if "halting" in text:
        break
    if r.returncode == 0 and text.rstrip().split("\n")[-2].startswith("proven this run"):
        break
print(open(out).read().count("\nPROVEN"), "proven;", open(out).read().count("\nPARKED"), "parked")
