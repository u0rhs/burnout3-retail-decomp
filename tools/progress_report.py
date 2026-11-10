#!/usr/bin/env python3
"""Macro-level decompilation progress tracker.

Scriptable replacement for vague byte estimates. Computes, from the current splat config and
on-disk disassembly (not from prose in docs/known.md), four numbers:
  - total functions in the whole retail binary (every `glabel` splat ever emitted)
  - total functions in Criterion's own game code specifically (library/glue code excluded)
  - total .text bytes for game code specifically (vs. the whole 4,073,088-byte binary)
  - how many of each are proven, per config/proven_units.txt (hand-curated: see that file's header)

"Game code" = anything under assembly/asm/{game,b3}/ (b3/ holds the renamed units whose physical .s file splat
relocated when it was re-run; the rest still sit at their original game/unit_XXXXXXXX.s path, since a yaml/ld rename
alone does not move the file -- see docs/known.md N34's general lesson about not trusting a static artifact over a
fresh computation). Everything else (sce/, rw/, rwa/, ea/, lg/, runtime/, data/) is third-party middleware.
The units once under d2-d6/ (Criterion code: boot, the main loop, stages, front end, CGTFileSystem, memory manager,
pools, ustr*, vdb, vehicle init/transmission) and the static initialisers (sinit*.s, .init) were classed as glue until
gaps1 (2026-11-02, docs/known.md N296) renamed them game/unit_<vram>; the .init units are dict-form yaml entries, so
the byte scan below reads those too.

Function-count TOTALS are frozen constants (see FROZEN_TOTAL_* below), not a live re-scan: once a
unit is proven, its glabel(s) may get physically deleted/split out of assembly/asm/ (first happened
in N41's chunk split), which would make a live scan *undercount* the true total by however many
proven functions no longer have an on-disk glabel. The frozen numbers were captured by this same
scan (see N39) at a point when nothing had yet been removed, so they are the true, complete count
and should only ever change if a genuinely new function is discovered (never by proving one).
Byte totals don't have this problem -- they come from yaml VRAM deltas, never from .s content --
so those stay a live scan.
"""
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
YAML = REPO / "config" / "b3_retail.yaml"
ASM_DIR = REPO / "assembly" / "asm"
PROVEN_MANIFEST = REPO / "config" / "proven_units.txt"

GAME_DIRS = {"game", "b3"}

# Captured 2026-10-20 (N39), before any glabel had ever been physically removed from assembly/asm/
# -- see the module docstring for why these are frozen constants, not a live re-scan. Reclassifications since (the
# total 9,133 stays): +6 static initialisers proven out of sinit.s into b3/ (N102-N108, counted as proven but never
# added here), -2 libvib.o (N290), +318 d2-d6 and sinit* functions (gaps1, N296): 5,330 + 6 - 2 + 318 = 5,652.
FROZEN_TOTAL_GAME_FUNCS = 5_652
FROZEN_TOTAL_LIBRARY_FUNCS = 3_481

BRACKET_RE = re.compile(r"^\s*-\s*\[0x([0-9A-Fa-f]+),\s*([a-z0-9_]+),\s*([^\]]+)\]")


def classify(name: str) -> str:
    top = name.split("/", 1)[0]
    return "game" if top in GAME_DIRS else "library"


DICT_RE = re.compile(r"^\s*-\s*\{\s*start:\s*0x([0-9A-Fa-f]+),\s*type:\s*([a-z0-9_]+),\s*name:\s*([^,}\s]+)")


def scan_yaml_asm_entries():
    """Return [(vram, name)] for every `asm`-type entry in the main segment, in file order; the dict-form entries
    (`{ start: ..., type: asm, name: ... }`, the .init static initialisers) are included."""
    entries = []
    others = []
    in_main = False
    with open(YAML, encoding="utf-8") as f:
        for line in f:
            if line.startswith("  - name: main"):
                in_main = True
            if not in_main:
                continue
            m = BRACKET_RE.match(line) or DICT_RE.match(line)
            if m and m.group(2) == "asm":
                entries.append((int(m.group(1), 16), m.group(3).strip()))
            elif m:
                others.append(int(m.group(1), 16))
    entries.sort()
    # Each asm entry runs to the next entry of any type. Without that bound the last .text entry (before the VU
    # microcode at 0x369E00) was never counted, and splitting it made the game total appear to grow.
    bounds = sorted(set(others + [v for v, _ in entries]))
    out = []
    for vram, name in entries:
        nxt = next(b for b in bounds if b > vram)
        out.append((vram, name, nxt - vram))
    return out


def total_text_bytes_by_category(entries):
    """Sum each asm entry's size (delta to the next entry's start) bucketed by game/library."""
    totals = {"game": 0, "library": 0}
    for vram, name, size in entries:
        totals[classify(name)] += size
    return totals


def scan_glabel_counts():
    """Count every `glabel NAME` in every .s file under assembly/asm, bucketed by top directory."""
    totals = {"game": 0, "library": 0}
    glabel_re = re.compile(r"^glabel\s+[A-Za-z_]")
    for s_file in ASM_DIR.rglob("*.s"):
        rel = s_file.relative_to(ASM_DIR)
        top = rel.parts[0]
        bucket = "game" if top in GAME_DIRS else "library"
        with open(s_file, encoding="utf-8", errors="ignore") as f:
            for line in f:
                if glabel_re.match(line):
                    totals[bucket] += 1
    return totals


def load_proven_manifest():
    units = []
    with open(PROVEN_MANIFEST, encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            vram, size, funcs, name, path = line.split(",", 4)
            units.append({
                "vram": int(vram, 16),
                "size": int(size, 16),
                "funcs": int(funcs),
                "name": name,
                "path": path,
            })
    return units


def main():
    entries = scan_yaml_asm_entries()
    text_bytes = total_text_bytes_by_category(entries)
    func_counts = scan_glabel_counts()
    proven = load_proven_manifest()

    proven_units = len(proven)
    proven_funcs = sum(u["funcs"] for u in proven)
    proven_bytes = sum(u["size"] for u in proven)

    total_game_funcs = FROZEN_TOTAL_GAME_FUNCS
    total_library_funcs = FROZEN_TOTAL_LIBRARY_FUNCS
    live_scan_game_funcs = func_counts["game"]  # sanity check only, see below
    total_binary_bytes = 4_073_088  # build/SLUS_210.50.rom's .main section, fixed fact (N21/N31/N33)

    print("=== Burnout 3 Retail decompilation progress ===\n")

    print(f"Whole retail binary: {total_binary_bytes:,} bytes")
    print(f"  Game-code .text:    {text_bytes['game']:,} bytes "
          f"({text_bytes['game'] / total_binary_bytes:.3%} of the whole binary)")
    print(f"  Library/glue .text: {text_bytes['library']:,} bytes\n")

    total_funcs = total_game_funcs + total_library_funcs
    print(f"Total functions (frozen baseline, N39 -- see module docstring): {total_funcs:,}")
    print(f"  Game-code functions:    {total_game_funcs:,}")
    print(f"  Library/glue functions: {total_library_funcs:,}\n")

    print(f"Proven (byte-exact via wire-in-and-relink, config/proven_units.txt): "
          f"{proven_units} units, {proven_funcs} functions, {proven_bytes:,} bytes\n")

    print("--- Completion, against game code only (this repo's actual charter) ---")
    print(f"  By function count: {proven_funcs}/{total_game_funcs:,} "
          f"= {proven_funcs / total_game_funcs:.4%}")
    print(f"  By byte count:      {proven_bytes:,}/{text_bytes['game']:,} "
          f"= {proven_bytes / text_bytes['game']:.4%}")

    # Sanity bound only: a live glabel scan can be LOWER than the frozen total (some proven units'
    # asm has been physically deleted/split out, e.g. N41 -- this is normal and expected, not every
    # proven unit's .s file gets removed, see docs/known.md N39/N41), but it should never exceed
    # the frozen total -- that would mean a genuinely new function was found and the constant above
    # needs updating.
    if live_scan_game_funcs > total_game_funcs:
        print(f"\nWARNING: live glabel scan found {live_scan_game_funcs:,} game functions, more "
              f"than the frozen total of {total_game_funcs:,} -- a new function was likely found; "
              f"update FROZEN_TOTAL_GAME_FUNCS at the top of this script.")


if __name__ == "__main__":
    sys.exit(main())
