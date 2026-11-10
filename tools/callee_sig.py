"""callee_sig.py: how many argument registers a function reads, from its retail asm (assembly/asm/**/*.s).

params(name) -> (n_gpr, n_fpr, exact) or None. n_gpr counts a0..a3,t0..t3 up to the highest one the function reads before
writing it; n_fpr likewise for f12..f19. A linear scan of the function's instructions (entry block first, as
spimdisasm lays them out): a branch-merged write ahead of a read on another path is missed [G]. A delay slot runs
before its call. A direct call (jal / tail j) reads what its own callee reads (followed to depth 4); an indirect one
(jalr / jr through a register) makes the answer unknown (None). Used by tools/tiny_lift.py to drop phantom
arguments (leftover register values) and to pass a parameter the callee reads (hand matching, N145)."""
import glob
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if not os.path.isdir(os.path.join(ROOT, "assembly")):          # build/vt/tools2/ -> the repo root
    ROOT = os.path.dirname(os.path.dirname(ROOT))
GPR = ["a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3"]
FPR = ["f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19"]
CALLER_SAVED = {"v0", "v1", "at", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9"} | \
    {"f%d" % i for i in range(20)}
REGTOK = re.compile(r"\$(v[01]|a[0-3]|t[0-9]|s[0-7]|fp|ra|at|f[0-9]+|zero|sp|gp)\b")
LINE = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s+(\S+)\s*(.*)$")
STORES = {"sw", "sh", "sb", "sd", "swc1", "sq", "sqc2", "swl", "swr", "sdl", "sdr", "usw"}
READ_ALL = {"mult", "multu", "div", "divu", "mult1", "multu1", "div1", "divu1", "mtlo", "mthi", "mtlo1", "mthi1",
            "jr", "teq", "tne", "mtsa"}
FIRST_READ = {"mtc1", "qmtc2", "ctc1", "ctc2", "mtc0", "dmtc1"}   # reads its first operand, writes the second

_index = None
_memo = {}


def _build_index():
    idx = {}
    for p in glob.glob(os.path.join(ROOT, "assembly", "asm", "**", "*.s"), recursive=True):
        with open(p, errors="replace") as f:
            for line in f:
                if line.startswith("glabel "):
                    idx.setdefault(line.split()[1], p)
    return idx


def body(name, retry=True):
    """The function's instructions [(mnemonic, operands)], or None. The batch splits and renames asm files as it
    proves functions, so a stale index entry (file gone, label moved) rebuilds the index once."""
    global _index
    if _index is None:
        _index = _build_index()
    p = _index.get(name)
    if not p or not os.path.exists(p):
        if retry:
            _index = _build_index()
            return body(name, False)
        return None
    out, on = [], False
    with open(p, errors="replace") as f:
        for line in f:
            if line.startswith("glabel " + name) and line.split()[1] == name:
                on = True
                continue
            if on:
                if line.startswith("endlabel ") or (line.startswith("glabel ") and out):
                    break
                m = LINE.match(line)
                if m:
                    out.append((m.group(1), m.group(2).split("#")[0].strip()))
    if not out and retry:                     # the label moved to another file
        _index = _build_index()
        return body(name, False)
    return out or None


def _rw(m, a):
    toks = REGTOK.findall(a)
    toks = [t for t in toks if t not in ("zero",)]
    # 3-operand EE mult/multu (rd, rs, rt) writes rd: test before READ_ALL, which holds the 2-operand forms (the
    # cloud review 2026-10-28 found this branch unreachable, so rd was counted as an argument read)
    if m in ("mult", "multu", "mult1", "multu1") and len(toks) == 3:
        return set(toks[1:]), {toks[0]}
    # COP2 transfers: REGTOK does not match $vf/$vi, so only the GPR side is seen -- lqc2/sqc2 read their base
    # register, qmtc2/ctc2 read their GPR source, qmfc2/cfc2 write their GPR destination
    if m.split(".")[0] in ("lqc2", "sqc2", "qmtc2", "ctc2"):
        return set(toks), set()
    if m.split(".")[0] in ("qmfc2", "cfc2"):
        return set(), set(toks[:1])
    if m in STORES or m in READ_ALL or m.startswith("b") or m.startswith("c.") or m in ("j", "nop"):
        return set(toks), set()
    if m in FIRST_READ:
        return set(toks[:1]), set(toks[1:2])
    if not toks:
        return set(), set()
    return set(toks[1:]), {toks[0]}


def params(name, depth=0, stack=()):
    """(n_gpr, n_fpr, exact): the argument registers read before written (a lower bound); exact is False when an
    indirect call, an unresolved callee or a recursion cut could read more. None: no asm for it."""
    if name in _memo:
        return _memo[name]
    if depth > 4 or name in stack:
        return None
    ins = body(name)
    if not ins:
        return None
    written, reads = set(), set()
    exact = True
    i = 0
    while i < len(ins):
        m, a = ins[i]
        if m in ("jal", "jalr", "j") or (m == "jr" and "$ra" not in a):
            if i + 1 < len(ins):               # the delay slot runs first
                m2, a2 = ins[i + 1]
                r2, w2 = _rw(m2, a2)
                reads |= {r for r in r2 if r not in written}
                written |= w2
            sub = params(a.split()[0].strip(), depth + 1, stack + (name,)) if m in ("jal", "j") else None
            if sub is None:
                exact = False                  # whatever it reads of ours is not known
            else:
                reads |= {r for r in set(GPR[:sub[0]]) | set(FPR[:sub[1]]) if r not in written}
                exact = exact and sub[2]
            if m in ("jal", "jalr"):
                written |= CALLER_SAVED
            i += 2
            continue
        r, w = _rw(m, a)
        reads |= {x for x in r if x not in written}
        written |= w
        i += 1
    g = max([GPR.index(r) + 1 for r in reads if r in GPR] + [0])
    f = max([FPR.index(r) + 1 for r in reads if r in FPR] + [0])
    _memo[name] = (g, f, exact)
    return _memo[name]


if __name__ == "__main__":
    import sys
    for n in sys.argv[1:]:
        print(n, params(n))
