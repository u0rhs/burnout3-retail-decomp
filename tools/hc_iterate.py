"""hc_iterate.py [--apply]: run tools/hdr_consolidate.py and tools/hc_verify.sh in rounds, excluding every unit whose
object changed or failed to compile, until a round verifies every adopting unit unchanged (build/hc/exclude.txt keeps
the exclusions, build/hc/rounds.log the counts). --apply then installs the result (headers + rewritten units).
Run only while no batch is running: the units and build/mw objects must not change underneath."""
import os
import subprocess
import sys
# run bash directly on Linux (repo on WSL's filesystem), through wsl.exe from Windows
BASH = ["bash"] if os.name != "nt" else ["wsl.exe", "bash"]

ex = "build/hc/exclude.txt"
open(ex, "a").close()
for rnd in range(12):
    r = subprocess.run([sys.executable, "tools/hdr_consolidate.py", "--exclude", ex], capture_output=True, text=True)
    print(r.stdout.strip(), flush=True)
    if r.returncode:
        print(r.stderr)
        sys.exit(1)
    out = "build/hc/round%d.out" % rnd
    with open(out, "w") as f:
        vr = subprocess.run(BASH + [ "tools/hc_verify.sh", "build/hc/adopted.txt", "build/hc/src",
                        "build/hc/include", "build/hc/obj"], stdout=f, stderr=subprocess.STDOUT)
    res = [l.split(None, 2) for l in open(out) if l.split(None, 1)[0:1] in (["SAME"], ["DIFF"], ["ERROR"])]
    res = [x for x in res if len(x) >= 2]
    bad = [x[1] for x in res if x[0] != "SAME"]
    adopted = [l.strip() for l in open("build/hc/adopted.txt") if l.strip()]
    missing = set(adopted) - {x[1] for x in res}
    msg = "round %d: %d adopted, %d same, %d excluded now, %d not reported" % (
        rnd, len(adopted), len(res) - len(bad), len(bad), len(missing))
    print(msg, flush=True)
    open("build/hc/rounds.log", "a").write(msg + "\n")
    if missing:
        bad += sorted(missing)
    if not bad:
        break
    # a verifier/environment failure (non-zero exit, nothing reported, or most units failing at once) is not evidence
    # against the units: stop without excluding anything (cloud review 2026-10-28; exclude.txt is permanent)
    if vr.returncode != 0 or not res or len(bad) > max(60, len(adopted) // 2):
        print("verifier failure suspected (rc %d, %d reported, %d bad of %d): nothing excluded"
              % (vr.returncode, len(res), len(bad), len(adopted)), flush=True)
        sys.exit(2)
    with open(ex, "a", newline="\n") as f:
        for b in bad:
            f.write(b + "\n")
else:
    print("no fixpoint after 12 rounds")
    sys.exit(1)
if "--apply" in sys.argv:
    r = subprocess.run([sys.executable, "tools/hdr_consolidate.py", "--exclude", ex, "--apply"], capture_output=True,
                       text=True)
    print(r.stdout.strip())
