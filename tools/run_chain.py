"""run_chain.py <N> [<N> ...]: run tools/run_queue.py over build/lift_candidates<N>.json -> build/tiny_batch_lift<N>.txt
for each N in turn, committing a full working-tree snapshot (`git add -A`) after each queue (docs/conventions.md commit policy;
.githooks/post-commit pushes it). Stops at a queue that halts, or when build/tiny_batch.stop exists."""
import os
import subprocess
import sys

for n in sys.argv[1:]:
    # build/run_chain.stop stops the chain (tiny_batch.py deletes build/tiny_batch.stop when it obeys it, so that one
    # only ends the current queue)
    if os.path.exists("build/run_chain.stop") or os.path.exists("build/tiny_batch.stop"):
        print("stop file present: not starting lift%s" % n, flush=True)
        break
    q, out = "build/lift_candidates%s.json" % n, "build/tiny_batch_lift%s.txt" % n
    r = subprocess.run([sys.executable, "-X", "faulthandler", "-u", "tools/run_queue.py", q, out],
                       capture_output=True, text=True)
    print("lift%s: %s" % (n, r.stdout.strip()), flush=True)
    subprocess.run(["git", "add", "-A"], capture_output=True)
    c = subprocess.run(["git", "commit", "-q", "-m", "Data snapshot after lift%s (%s)" % (n, r.stdout.strip())],
                       capture_output=True, text=True)
    print("  snapshot commit:", "ok" if c.returncode == 0 else (c.stdout + c.stderr).strip()[:200], flush=True)
    text = open(out).read()
    if "halting" in text or r.returncode != 0:
        print("halted in lift%s" % n, flush=True)
        break
