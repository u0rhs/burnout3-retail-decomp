# Non-matching sources

Near-misses: C/C++ whose logic is believed right but whose compiled code still differs from retail (registers,
scheduling, frame layout). Each file's first line gives the remaining diff from the harness. These are **not built and
not counted** -- the retail assembly stays in the build for these functions. They are kept so the work is not lost and
can be picked up later (written by build/vt/hand/nonmatch.py).
