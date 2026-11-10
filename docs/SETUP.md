# Setup

This repository contains **no game data**: no disc image, no executable, no assets, no disassembly dumps.
You supply your own copy of *Burnout 3: Takedown* (PlayStation 2, NTSC-U, SLUS-21050) and your own compiler.

## What you provide

| What | Where it goes |
|---|---|
| The retail `SLUS_210.50` executable from your own disc | `orig/SLUS_210.50` |
| CodeWarrior for PS2 3.0.1 (b119) with your own licence | folder in `B3_MWCC_DIR`, licence in `B3_LICENSE` |
| A Linux shell (WSL works), Python 3, and `wibo` or `wine` to run the Windows compiler | on your PATH / `~/tools/wibo/wibo` |

Copy nothing from your disc into git: `orig/` and `build/` are git-ignored.

## Local settings

Create `tools/local.env` (git-ignored):

```sh
B3_MWCC_DIR=$HOME/compilers/mwcps2-3.0.1b119p
B3_LICENSE=$HOME/licenses/my-codewarrior-licence-file
```

Every script that needs a path reads it from `tools/env.sh`, which also sets `B3_ROOT` to this checkout.
Some scripts were written for one particular machine and may still need small path fixes; please report or fix them.

## Layout, conventions, status

See `docs/conventions.md` (naming and matching workflow), `docs/layout.md` (folder structure and the evidence for it),
`docs/known.md` (ledger of what is proven, believed or retracted) and `docs/matching-patterns.md`.
Not every function matches yet: `src/b3/` holds functions that reproduce the retail bytes, `src/nonmatching/` holds
behaviour-equivalent C/C++ for the rest.

## Legal

*Burnout 3: Takedown* is the property of its rights holders. This project is not affiliated with them. Third-party
SDKs, compilers and libraries are **not** included and are referenced by name only.
