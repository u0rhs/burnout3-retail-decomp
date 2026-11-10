"""Apply new splat symbol names to the existing assembly without re-running splat.

usage: python3 -I tools/apply_symbol_renames.py <old symbol_addrs_b3names.txt> [--dry-run]

assembly/asm/ is no longer a pure splat output (chunk splits, hand-written pieces: N41 onward), so re-splitting to
pick up names from config/symbol_addrs_b3names.txt would undo that work. Instead, for every symbol the current file
has and <old> doesn't, rename its placeholder (func_XXXXXXXX / D_XXXXXXXX, whichever the assembly uses) to the new
name, as whole words, in assembly/asm/**/*.s and the generated link inputs in build/ (undefined_syms_auto.txt,
*_defs.txt). File names are left alone (the linker script names objects, not symbols). No bytes change; the full
rebuild proves it.
Refuses to run when a new name already appears anywhere in those files or in config/undefined_syms_manual.txt
(a second definition), or when a placeholder is referenced from src/, include/ or the manual symbol file (our own
C links against it; tools/gen_symbols.py should have kept it as a comment).
"""
import glob, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SYM = re.compile(r"^(\S+) = 0x([0-9A-F]{8});")


def symbols(path):
    out = {}
    for line in open(path, encoding="utf-8"):
        m = SYM.match(line)
        if m:
            out[int(m.group(2), 16)] = m.group(1)
    return out


def main():
    old, new = symbols(sys.argv[1]), symbols(os.path.join(ROOT, "config", "symbol_addrs_b3names.txt"))
    added = {a: n for a, n in new.items() if a not in old}
    changed = {a: (old[a], n) for a, n in new.items() if a in old and old[a] != n}
    if changed:
        sys.exit("names changed for existing symbols (not handled): %s" % sorted(changed)[:5])

    files = [f for f in glob.glob(os.path.join(ROOT, "assembly", "asm", "**", "*.s"), recursive=True)]
    files.append(os.path.join(ROOT, "build", "undefined_syms_auto.txt"))   # not the .ld: it names files, and some
    # splat files are named after their placeholder (d4/func_00130BF0.s); file names stay as they are
    files += glob.glob(os.path.join(ROOT, "build", "*_defs.txt"))
    texts = {f: open(f, encoding="utf-8", errors="surrogateescape").read() for f in files if os.path.exists(f)}
    ours = open(os.path.join(ROOT, "config", "undefined_syms_manual.txt"), encoding="utf-8").read()
    for top in ("src", "include"):
        for f in glob.glob(os.path.join(ROOT, top, "**", "*.*"), recursive=True):
            ours += open(f, encoding="utf-8", errors="replace").read()
    blob = "\n".join(texts.values())

    plan, problems = [], []
    for a, name in sorted(added.items()):
        if re.search(r"(?<![\w.$])%s(?![\w.$])" % re.escape(name), blob + ours):
            problems.append("0x%08X %s: name already present" % (a, name))
            continue
        ph = [p for p in ("func_%08X" % a, "D_%08X" % a) if re.search(r"\b%s\b" % p, blob)]
        if not ph:
            problems.append("0x%08X %s: no placeholder in the assembly" % (a, name))
            continue
        if any(re.search(r"\b%s\b" % p, ours) for p in ph):
            problems.append("0x%08X %s: placeholder used by our own C / manual symbols" % (a, name))
            continue
        plan.append((ph[0], name))
    print("%d new symbols, %d to rename, %d problems" % (len(added), len(plan), len(problems)))
    for p in problems:
        print("  PROBLEM", p)
    if problems or "--dry-run" in sys.argv:
        sys.exit(1 if problems else 0)

    pat = re.compile(r"\b(%s)\b" % "|".join(re.escape(p) for p, _ in plan))
    to = dict(plan)
    edits = 0
    for f, t in texts.items():
        u, n = pat.subn(lambda m: to[m.group(1)], t)
        if n:
            open(f, "w", encoding="utf-8", errors="surrogateescape", newline="").write(u)
            edits += n
    print("renamed %d placeholders: %d occurrences" % (len(plan), edits))


if __name__ == "__main__":
    main()
