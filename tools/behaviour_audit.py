#!/usr/bin/env python3
"""behaviour_audit.py: static behaviour audit of non-matching archives (audit1, 2026-11-01).

"Calls identical" is not enough (hard1, draftAI, port6): wrong branch senses, swapped argument registers, missing
arguments, a 1-byte vs 4-byte fill, a wrong loop count all passed it. This tool compiles each archive and compares
ours vs retail per function on behaviour features computed by a small symbolic dataflow over the MIPS code, so the
comparison does not depend on register allocation, stack-slot numbering or scheduling:

  calls     ordered callee list (jal targets, jalr as `vcall[+slot]` with its vtable chain) aligned with difflib, and
            for every aligned call the SOURCE of each argument register (a0-a3, t0-t3, f12-f19): constant, incoming
            parameter, load base+offset (recursively), result of an earlier call, stack address, computed; plus which
            argument registers are set at all (missing / extra arguments). Which registers a callee takes comes from
            retail's own call sites of that callee in the analysed functions (set at every site).
  branches  census by kind (c.lt/c.le/c.eq + bc1t/bc1f, beq/bne/beqz/bnez/bgez/bltz/blez/bgtz, likely forms) and
            the float compare operand pairs.
  stores    non-stack stores as (base source, offset, width) with the stored value's source; width mismatches.
  consts    integer immediates (li, andi/ori/xori, slti/sltiu) and float literals (lit4/rodata loads, lui+mtc1).
  returns   the value of v0/f0 on each path into `jr ra` (missing early exits, wrong return values).

Usage (repo root, WSL):
  python3 -I tools/behaviour_audit.py [--jobs 12] [--only SUBSTR ...] [--matched N] [--out build/vt/audit1]
     archives:   every src/nonmatching/*.cpp whose function is still unproven (as tools/rescore_archives.py)
     --matched N: instead, N proven units from src/b3 (a correct tool reports nothing there: calibration)
     --file a.cpp --sym NAME: one source, one function
Output: <out>/report.tsv (archive, symbol, retail addr, score, category, detail) and <out>/summary.txt.
Compiles only into <out>/obj (never build/va). A finding is a SUSPICION to triage against the asm, not a verdict.
"""
import argparse, collections, concurrent.futures as cf, difflib, glob, os, re, struct, subprocess, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import tiny_batch  # noqa: E402
import diff_vs_retail  # noqa: E402

ROM = "orig/SLUS_210.50"
_rom = None


def rom_read(addr, n):
    global _rom
    if _rom is None:
        _rom = open(ROM, "rb").read()
    o = addr - 0x100000 + 0x100
    if addr < 0x100000 or o + n > 0x100 + 0x3E2680:
        return None
    return _rom[o:o + n]


_alias = None
# names no table maps: N66 (config/undefined_syms_manual.txt comment) -- asm callers use func_00319C80
MANUAL_ALIAS = {"Prepare__19CB3HeadingComponentF14EGlobalStringsQ219CB3HeadingComponent12EHeadingType": 0x319C80,
                # comparison only, not names: libm's wrappers whose bodies are `j __ieee754_<f>` [C] runtime/libm.s
                "acosf": 0x11E328, "asinf": 0x11E340, "logf": 0x11E370}


# fix2: include/b3/_unclassified/CV3dRandomiser.h defines the per-file randomiser pair as `static` (every includer gets its
# own, as retail); retail's pair is D_01D9D190 / D_004BBFB0 in B3EffectsManager and D_01EA4BA0 / D_004C9A00 in
# B3ExplosionManager. audit_one sets this per function from the retail unit's text.
RANDOMISER_ALIAS = {}
RANDOMISER_PAIRS = {"D_01EA4BA0": {"gEffectsRandomiserScales": 0x1EA4BA0, "kEffectsRandomiser2E23": 0x4C9A00},
                    "D_01D9D190": {"gEffectsRandomiserScales": 0x1D9D190, "kEffectsRandomiser2E23": 0x4BBFB0}}
_unit_text = {}


def set_randomiser_alias(spath):
    if spath not in _unit_text:
        try:
            t = open(spath, errors="replace").read()
        except OSError:
            t = ""
        _unit_text[spath] = next((v for k, v in RANDOMISER_PAIRS.items() if k in t), RANDOMISER_PAIRS["D_01D9D190"])
    RANDOMISER_ALIAS.clear()
    RANDOMISER_ALIAS.update(_unit_text[spath])


def sym_addr(name, depth=0):
    """a symbol's retail address: the project's symbol tables, `A = B;` aliases (undefined_syms_manual), func_XXXXXXXX"""
    global _alias
    a = diff_vs_retail.sym_addr(name)
    if a is not None:
        return a
    if _alias is None:
        _alias = {}
        for p in ("config/undefined_syms_manual.txt", "build/undefined_syms_auto.txt"):
            try:
                for l in open(p, errors="replace"):
                    m = re.match(r"\s*(?:PROVIDE\()?\s*([A-Za-z_.$@][\w.$@]*)\s*=\s*([A-Za-z_.$@][\w.$@]*)\s*\)?\s*;", l)
                    if m:
                        _alias.setdefault(m.group(1), m.group(2))
            except OSError:
                pass
    if name in MANUAL_ALIAS:
        return MANUAL_ALIAS[name]
    if name in RANDOMISER_ALIAS:
        return RANDOMISER_ALIAS[name]
    m = re.match(r"^(?:func|D|jtbl|lit4)_([0-9A-Fa-f]{8})$", name)
    if m:
        return int(m.group(1), 16)
    if name in _alias and depth < 4:
        return sym_addr(_alias[name], depth + 1)
    return glabel_addr(name)


_glabels = None


_gpath = {}
_byaddr = {}


def glabel_addr(name):
    """address of a glabel anywhere in assembly/asm (cached in build/vt/audit1/glabels.tsv with its file; the live
    game/ units and the proven b3/ units win over older split folders)"""
    global _glabels
    if _glabels is None:
        _glabels = {}
        cache = os.path.join(OUT, "glabels.tsv")
        # stale once the yaml changes (units renamed or split: gaps1 found d6/ paths that no longer existed, so callee
        # live-ins came back unknown and every register retail set was claimed as an argument)
        fresh = os.path.exists(cache) and os.path.getmtime(cache) >= os.path.getmtime("config/b3_retail.yaml")
        if fresh and len(open(cache).readline().split("\t")) == 3:
            for l in open(cache):
                n, a, f = l.rstrip("\n").split("\t")
                _glabels[n] = int(a, 16)
                _gpath[n] = f
        else:
            files = glob.glob("assembly/asm/**/*.s", recursive=True)
            files.sort(key=lambda f: (0 if f.startswith(("assembly/asm/b3/", "assembly/asm/game/")) else 1, f))
            for f in files:
                pend = None
                for l in open(f, errors="replace"):
                    if l.startswith(("glabel ", "alabel ")):
                        pend = l.split()[1]
                    elif pend:
                        m = re.match(r"\s*/\* \w+ (\w+) ", l)
                        if m:
                            if pend not in _glabels:
                                _glabels[pend] = int(m.group(1), 16)
                                _gpath[pend] = f
                            pend = None
            os.makedirs(OUT, exist_ok=True)
            with open(cache, "w") as fo:
                for n, a in sorted(_glabels.items()):
                    fo.write("%s\t%X\t%s\n" % (n, a, _gpath[n]))
        for n, a in _glabels.items():
            if not n.startswith(("func_", "D_")) or a not in _byaddr:
                _byaddr[a] = n
    return _glabels.get(name)


def _uses_defs(ins):
    """(uses, defs) register sets of one instruction (arguments analysis)"""
    op, ops = ins.op, ins.ops
    regs = [o[1] for o in ops if o[0] == "r"]
    mems = [o[2] for o in ops if o[0] == "m"]
    if op in STORES:
        return set(regs + mems), set()
    if op in LOADS:
        return set(mems), set(regs[:1])
    if op in BR or op in ("jr", "jalr", "tailj"):
        return set(regs + mems), set()
    if op in DEF2:
        return set(regs[:1]), set(regs[1:2])
    if op.startswith("c.") or op in ("mult", "multu", "div", "divu", "mult1", "multu1", "div1", "divu1") and len(regs) == 2:
        return set(regs), set()
    if op.startswith(("vmula", "vmadda", "vmsuba", "vadda", "vsuba")) or op in ("vdiv", "vsqrt", "vrsqrt"):
        return set(regs), set()
    if not regs:
        return set(mems), set()
    return set(regs[1:] + mems), set(regs[:1])


_livein = {}


def live_in(addr, depth=0):
    """argument registers retail's function at addr reads before writing them (its real parameter list), or None.
    A call inside forwards the registers its own callee reads (wrappers)."""
    if addr in _livein:
        return _livein[addr]
    glabel_addr("")
    name = _byaddr.get(addr)
    path = _gpath.get(name)
    if not name or not path or depth > 3 or not path.startswith(("assembly/asm/game/", "assembly/asm/b3/", "assembly/asm/d",
                                                                 "assembly/asm/sce/", "assembly/asm/rw", "assembly/asm/runtime/")):
        return None       # library code (gcc's libgcc reads uninitialised temps on purpose): no claim
    _livein[addr] = None              # recursion guard
    try:
        insns, base = parse_retail(path, name)
    except Exception:  # noqa
        return None
    if not insns:
        return None
    bl, succ, idx = blocks_of(insns)
    allr = set(ARGI + ARGF)
    must = [None] * len(bl)
    must[0] = frozenset()
    live = set()
    work = [0]
    seen = 0
    while work and seen < 20 * len(bl) + 50:
        seen += 1
        k = work.pop()
        d = set(must[k])
        s0, e0 = bl[k]
        i = s0
        while i < e0:
            ins = insns[i]
            seq = [ins]
            if (ins.op in BR or ins.op in ("jr", "jal", "jalr", "tailj")) and i + 1 < e0:
                seq = [insns[i + 1], ins]      # the delay slot runs first
                i += 1
            for x in seq:
                if x.op in ("jal", "tailj") and x.callee:
                    a2 = sym_addr(x.callee)
                    lib = a2 is not None and _gpath.get(_byaddr.get(a2), "").startswith(
                        ("assembly/asm/runtime/", "assembly/asm/sce/", "assembly/asm/rw"))
                    li = live_in(a2, depth + 1) if a2 is not None and not lib else None
                    if lib:
                        # a library callee (strstr, RenderWare's DMA helpers): only its mangled list, else just a0
                        # (gcc library code reads registers it never needs; forwarding its live-in over-claims)
                        li = mangled_regs(_byaddr.get(a2)) or {"a0"}
                    if li:
                        live |= (li & allr) - d
                    d -= set(CLOBBER)
                    d |= {"v0", "v1", "f0"}
                    continue
                u, w = _uses_defs(x)
                live |= (u & allr) - d
                d |= w
            i += 1
        for (t, kind) in succ[k]:
            nd = frozenset(d)
            if must[t] is None:
                must[t] = nd
                work.append(t)
            elif not must[t] <= nd:
                must[t] = must[t] & nd
                work.append(t)
    _livein[addr] = frozenset(live)
    return _livein[addr]


# ---------------------------------------------------------------- instruction parsing

GPR = set("zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra".split())
ARGI = ["a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3"]
ARGF = ["f%d" % i for i in range(12, 20)]
CLOBBER = (["at", "v0", "v1"] + ARGI + ["t4", "t5", "t6", "t7", "t8", "t9", "HI", "LO", "FCC"] +
           ["f%d" % i for i in range(0, 20)])


def reg(tok):
    t = tok.strip().lstrip("$")
    if t == "s8":
        t = "fp"
    if t in GPR:
        return t
    m = re.match(r"^(f\d+)$", t)
    if m:
        return t
    m = re.match(r"^(vf\d+)[xyzw]*$", t)
    if m:
        return m.group(1)
    m = re.match(r"^(vi\d+)$", t)
    if m:
        return t
    m = re.match(r"^(ACC)[xyzw]*$", t)
    if m:
        return "ACC"
    if t in ("Q", "I", "R", "P"):
        return t
    return None


def split_ops(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "(":
            depth += 1
        elif ch == ")":
            depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def ev_int(s):
    s = s.strip()
    m = re.match(r"^\(\s*(-?0x[0-9A-Fa-f]+|-?\d+)\s*>>\s*16\s*\)$", s)
    if m:
        return (int(m.group(1), 0) >> 16) & 0xFFFF
    m = re.match(r"^\(\s*(-?0x[0-9A-Fa-f]+|-?\d+)\s*&\s*0xFFFF\s*\)$", s, re.I)
    if m:
        return int(m.group(1), 0) & 0xFFFF
    try:
        return int(s, 0)
    except ValueError:
        return None


def sext16(n):
    return ((n & 0xFFFF) ^ 0x8000) - 0x8000 if 0 <= n <= 0xFFFF else n


class Insn:
    __slots__ = ("off", "op", "ops", "rel", "tgt", "callee")

    def __init__(self, off, op, ops):
        self.off, self.op, self.ops, self.rel, self.tgt, self.callee = off, op, ops, None, None, None

    def __repr__(self):
        return "%x %s %s %s" % (self.off, self.op, self.ops, self.rel or "")


RELOC_RE = re.compile(r"%(hi|lo|gp_rel)\(\s*([A-Za-z_.$@][\w.$@]*)\s*(?:\+\s*(0x[0-9A-Fa-f]+|\d+))?\s*\)")


def parse_operand(t):
    """('r', reg) | ('i', int) | ('m', off, base, rel) | ('x', text); rel = (kind, sym, addend)."""
    t = t.strip()
    rel = None
    m = RELOC_RE.search(t)
    if m:
        rel = (m.group(1), m.group(2), int(m.group(3), 0) if m.group(3) else 0)
        rest = t[m.end():].strip()
        mm = re.match(r"^\(\s*\$?(\w+)\s*\)$", rest)
        if mm:
            return ("m", 0, reg(mm.group(1)), rel)
        return ("i", 0, rel)
    m = re.match(r"^(-?0x[0-9A-Fa-f]+|-?\d+)?\(\s*\$?(\w+)\s*\)$", t)
    if m and reg(m.group(2)):
        return ("m", int(m.group(1), 0) if m.group(1) else 0, reg(m.group(2)), None)
    m = re.match(r"^(\(.*\))\(\s*\$?(\w+)\s*\)$", t)       # splat: (0x32664 & 0xFFFF)($v0)
    if m and reg(m.group(2)) and ev_int(m.group(1)) is not None:
        return ("m", sext16(ev_int(m.group(1))), reg(m.group(2)), None)
    r = reg(t)
    if r:
        return ("r", r)
    v = ev_int(t)
    if v is not None:
        return ("i", v, None)
    return ("x", t)


ALIAS = {"daddu": "addu", "daddiu": "addiu", "dsubu": "subu", "dsll": "sll", "dsrl": "srl", "dsra": "sra",
         "dsllv": "sllv", "dsrlv": "srlv", "dsrav": "srav", "dsll32": "sll32", "dsrl32": "srl32", "dsra32": "sra32",
         "beqzl": "beqzl"}


def canon_insn(off, op, ops):
    op = op.lower()
    if op.startswith("v") and "." in op and op.split(".")[1] and re.match(r"^[xyzw]+$", op.split(".")[1]):
        op = op.split(".")[0]          # VU lane masks: semantics opaque here
    op = re.sub(r"\.ni$", "", op)
    ops = [parse_operand(o) for o in ops]
    op = ALIAS.get(op, op)
    # aliases
    if op in ("addu", "or") and len(ops) == 3 and ops[2] == ("r", "zero"):
        op, ops = "move", ops[:2]
    elif op in ("addu", "or") and len(ops) == 3 and ops[1] == ("r", "zero"):
        op, ops = "move", [ops[0], ops[2]]
    elif op in ("addiu", "ori") and len(ops) == 3 and ops[1] == ("r", "zero") and ops[2][0] == "i" and not ops[2][2]:
        op, ops = "li", [ops[0], ops[2]]
    elif op == "li":
        pass
    elif op == "beqz":
        op, ops = "beq", [ops[0], ("r", "zero")] + ops[1:]
    elif op == "bnez":
        op, ops = "bne", [ops[0], ("r", "zero")] + ops[1:]
    elif op == "beqzl":
        op, ops = "beql", [ops[0], ("r", "zero")] + ops[1:]
    elif op == "bnezl":
        op, ops = "bnel", [ops[0], ("r", "zero")] + ops[1:]
    elif op == "not":
        op, ops = "nor", ops + [("r", "zero")]
    elif op == "negu":
        op, ops = "subu", [ops[0], ("r", "zero"), ops[1]]
    if op == "beq" and len(ops) == 3 and ops[0] == ("r", "zero") and ops[1] == ("r", "zero"):
        op, ops = "b", ops[2:]
    return Insn(off, op, ops)


BR = {"beq", "bne", "beql", "bnel", "bgez", "bltz", "blez", "bgtz", "bgezl", "bltzl", "blezl", "bgtzl",
      "bc1t", "bc1f", "bc1tl", "bc1fl", "bc0t", "bc0f", "bc0tl", "bc0fl", "bc2t", "bc2f", "b", "j"}
LIKELY = {"beql", "bnel", "bgezl", "bltzl", "blezl", "bgtzl", "bc1tl", "bc1fl", "bc0tl", "bc0fl"}


def parse_retail(path, label, rng=None):
    """retail function `label` (up to its endlabel, or the next alabel/glabel); with rng=(start, end) instead every
    instruction of the file in that address range (a matched unit's object holds functions retail labels as one)"""
    insns, on, base = [], rng is not None, (rng[0] if rng else None)
    for line in open(path, errors="replace"):
        sp = line.split()
        if rng is None and sp[:2] == ["glabel", label]:
            on = True
            continue
        if rng is None and on and (sp[:2] == ["endlabel", label] or sp[:1] == ["glabel"]
                                   or (sp[:1] == ["alabel"] and not sp[1].startswith("D_"))):
            break             # an alabel inside a glabel range starts the next function -- unless it is a D_ data
            #                   label: splat names an address some data or offset constant equals (gaps1: D_001320D8
            #                   in UpdatePreSimulation__7CB3GameFv is func_0038CA60's 0x1320D8 struct offset)
        if not on:
            continue
        m = re.match(r"\s*/\* \w+ (\w+) (\w+) \*/\s+(.*)", line)
        if not m:
            continue
        addr, word, text = int(m.group(1), 16), int(m.group(2), 16), m.group(3)
        if rng is not None and not (rng[0] <= addr < rng[1]):
            continue
        if base is None:
            base = addr
        text = re.sub(r"\s*/\*.*?\*/", "", text).strip()
        mm = re.match(r"\.word\s+(0x[0-9A-Fa-f]+|\d+)\s*#\s*(\S+)\s*(.*)$", text)
        if mm:
            op, rest = mm.group(2), mm.group(3).split("#")[0]
            if op == "cvt.w.s":
                op = "trunc.w.s"
        else:
            parts = text.split(None, 1)
            op, rest = parts[0], (parts[1] if len(parts) > 1 else "")
        ops = split_ops(rest)
        tgt = callee = None
        if op in ("jal",):
            callee = ops[0].strip()
            ops = []
        elif op.lower() in BR or op.lower() in ("beqz", "bnez", "beqzl", "bnezl"):
            t = ops[-1].strip()
            if re.match(r"^\.L[0-9A-Fa-f]{8}$", t):
                tgt = int(t[2:], 16) - base
                if rng is not None and not (rng[0] <= int(t[2:], 16) < rng[1]):
                    tgt, callee, op = None, t, "j"      # leaves the range: a tail branch
                ops = ops[:-1]
            elif op == "j":
                callee = t       # tail call
                ops = []
        ins = canon_insn(addr - base, op, ops)
        ins.tgt, ins.callee = tgt, callee
        if ins.op == "j" and callee:
            ins.op = "tailj"
        insns.append(ins)
    return insns, base


# ---- our object: a minimal ELF32 reader for literal values


class Obj:
    def __init__(self, path):
        d = open(path, "rb").read()
        self.d = d
        shoff, = struct.unpack_from("<I", d, 0x20)
        shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
        self.sh = []
        for i in range(shnum):
            self.sh.append(struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize))
        sstr = self.sh[shstrndx]
        self.secname = [self._str(sstr[4], s[0]) for s in self.sh]
        self.syms = {}
        for i, s in enumerate(self.sh):
            if s[1] == 2:      # SYMTAB
                strt = self.sh[s[6]]
                for k in range(s[5] // 16):
                    nm, val, size, info, oth, shn = struct.unpack_from("<IIIBBH", d, s[4] + k * 16)
                    name = self._str(strt[4], nm)
                    if name and shn and shn < len(self.sh):
                        self.syms.setdefault(name, (shn, val, size))

    def _str(self, off, i):
        e = self.d.index(b"\0", off + i)
        return self.d[off + i:e].decode(errors="replace")

    def read(self, name, off, n):
        if name in self.syms:
            shn, val, _ = self.syms[name]
        elif name in self.secname:
            shn, val = self.secname.index(name), 0
        else:
            return None, None
        s = self.sh[shn]
        if s[1] == 8:      # NOBITS
            return None, self.secname[shn]
        o = s[4] + val + off
        if val + off + n > s[5]:
            return None, self.secname[shn]
        return self.d[o:o + n], self.secname[shn]


def parse_ours(objpath, label):
    txt = subprocess.run(["mips-linux-gnu-objdump", "-dr", "-z", "--no-show-raw-insn", objpath],
                         capture_output=True, text=True).stdout
    insns, on, base = [], False, 0
    for line in txt.splitlines():
        h = re.match(r"^([0-9a-f]+) <([^>]+)>:", line)
        if h:
            on = h.group(2).strip() == label
            base = int(h.group(1), 16)
            continue
        if not on:
            continue
        r = re.match(r"\s*([0-9a-f]+): (R_MIPS_\w+)\s+(\S+)", line)
        if r and insns:
            kind, sym = r.group(2), r.group(3)
            add = 0
            mm = re.match(r"^(.*?)([+-]0x[0-9a-f]+)$", sym)
            if mm:
                sym, add = mm.group(1), int(mm.group(2), 16)
            last = insns[-1]
            if kind == "R_MIPS_26":
                last.callee = sym
                if last.op == "j":            # tail call
                    last.op, last.tgt = "tailj", None
            else:
                k = {"R_MIPS_HI16": "hi", "R_MIPS_LO16": "lo", "R_MIPS_GPREL16": "gp_rel",
                     "R_MIPS_LITERAL": "lit"}.get(kind, kind)
                last.rel = (k, sym, add)
            continue
        m = re.match(r"\s*([0-9a-f]+):\s+(\S+)\s*(.*)$", line)
        if not m:
            continue
        off = int(m.group(1), 16) - base
        op, rest = m.group(2), re.sub(r"\s*<[^>]*>$", "", m.group(3)).strip()
        ops = split_ops(rest)
        tgt = None
        if op == "jal":
            ops = []
        elif op in BR or op in ("beqz", "bnez", "beqzl", "bnezl"):
            t = ops[-1].strip() if ops else ""
            if re.match(r"^[0-9a-f]+$", t):
                tgt = int(t, 16) - base
                ops = ops[:-1]
        if op == "c2" and ops:
            op, ops = "cop2word", []
        if op == "c1" and ops:
            op, ops = "cop1word", []
        ins = canon_insn(off, op, ops)
        ins.tgt = tgt
        insns.append(ins)
    # move relocs from the pseudo operand into rel (a relocated insn's immediate is the REL addend)
    for ins in insns:
        if ins.rel:
            k, sym, add = ins.rel
            for i, o in enumerate(ins.ops):
                if o[0] == "i":
                    ins.ops[i] = ("i", 0, (k, sym, o[1] + add))
                    break
                if o[0] == "m":
                    ins.ops[i] = ("m", 0, o[2], (k, sym, o[1] + add))
                    break
        if ins.op == "jal" and ins.callee is None:
            ins.callee = "?"
        if ins.op == "j" and ins.tgt is None:
            ins.op = "tailj"
    return insns, base


# ---------------------------------------------------------------- symbolic values
# K(int) | F(bits) | P(reg) | R(callee, reg) | L(base, off, width) | A(base, off) | S(name) | SP | O(op, args) | U | Q('?')

U = ("U",)
PHIS = {}          # ('PHI', block, key) -> incoming values (per analysed function; reset in analyse())
TOP = ("?",)
SPB = ("SP",)
GB = ("G",)


def K(n):
    return ("K", n & 0xFFFFFFFFFFFFFFFF if n >= 0 else n)


def is_k(v):
    return v[0] == "K"


def addr_split(v):
    """pointer value -> (base, off)"""
    if v[0] == "K":
        return GB, v[1]
    if v[0] == "A":
        return v[1], v[2]
    return v, 0


def addv(v, n):
    if n == 0:
        return v
    if v[0] == "K":
        return K(v[1] + n)
    if v[0] == "A":
        return ("A", v[1], v[2] + n)
    if v[0] in ("U", "?", "SPX"):
        return v
    return ("A", v, n)


def depth_cut(v, d=3):
    if d <= 0 and v[0] in ("O", "L", "A"):
        return ("O", "...", ())
    if v[0] == "O":
        return ("O", v[1], tuple(depth_cut(a, d - 1) for a in v[2]))
    if v[0] == "L":
        return ("L", depth_cut(v[1], d - 1), v[2], v[3])
    if v[0] == "A":
        return ("A", depth_cut(v[1], d - 1), v[2])
    return v


def opv(op, *args):
    if any(a == TOP for a in args):
        return TOP
    return depth_cut(("O", op, tuple(args)))


def fbits_str(b):
    f = struct.unpack("<f", struct.pack("<I", b & 0xFFFFFFFF))[0]
    return "%.7g" % f


class Ctx:
    """per-side environment: how to resolve relocations and literal loads."""

    def __init__(self, side, obj=None):
        self.side, self.obj = side, obj

    def symbase(self, sym):
        a = None if sym.startswith(("@", ".")) else sym_addr(sym)
        if a is not None:
            return GB, a
        return ("S", sym), 0

    def literal(self, rel, width):
        """value of a load through a relocation to a literal (ours) -> F/K or None"""
        k, sym, add = rel
        if self.obj is None:
            return None
        b, sec = self.obj.read(sym, add, width)
        if b is None or not sec:
            return None
        if sec.startswith((".lit", ".rodata", ".sdata2")) or sec == ".sdata" and sym.startswith("@"):
            return b
        return None


def val_canon(v):
    """allocation-independent canonical text of a value"""
    t = v[0]
    if t == "K":
        n = v[1]
        if n >= 0x100000 and n < 0x2000000:
            return "&%X" % n
        return "#%d" % (n if n < 1 << 63 else n - (1 << 64))
    if t == "F":
        return "%sf" % fbits_str(v[1])
    if t == "P":
        return "arg:" + v[1]
    if t == "R":
        return "ret(%s).%s" % (callee_disp(v[1]), v[2])
    if t == "L":
        b = v[1]
        if b == GB:
            return "[&%X]%s" % (v[2], v[3])
        if b == SPB:
            return "[stack]%s" % v[3]
        return "[%s+%X]%s" % (val_canon(b), v[2], v[3])
    if t == "A":
        if v[1] == SPB:
            return "&stack"
        if v[1][0] == "S":
            return "&%s+%X" % (local_disp(v[1][1]), v[2])
        return "(%s+%X)" % (val_canon(v[1]), v[2])
    if t == "S":
        return "&" + local_disp(v[1])
    if t == "SP":
        return "&stack"
    if t == "LS":
        return "[stack]?"
    if t == "O":
        return "%s(%s)" % (v[1], ",".join(val_canon(a) for a in v[2]))
    if t == "HI":
        return "hi?"
    if t == "U":
        return "unset"
    if t == "PHI":
        return phi_canon(v)
    if t == "PHIC":
        return v[1]
    if t in ("V4", "V2"):
        return "vec(%s)" % ",".join(val_canon(c) for c in v[1:])
    if t == "LANE":
        # fix2: lane k of a quad load is the word at +4k (a 128-bit copy vs four scalar copies: Update__20CB3SoundCrashManager)
        if v[2] < 4 and v[1][0] == "L" and isinstance(v[1][2], int) and v[1][1] != SPB:
            return val_canon(("L", v[1][1], v[1][2] + 4 * v[2], v[1][3]))
        return "%s.%s" % (val_canon(v[1]), "xyzw"[v[2]] if v[2] < 4 else v[2])
    return "?"


_phi_stack = []


def phi_canon(v):
    """a merge of values: its incoming SOURCES (computed ones are `x`, nested merges `phi`, itself `self`)"""
    if v in _phi_stack or len(_phi_stack) > 0:
        return "self" if v in _phi_stack else "phi"
    _phi_stack.append(v)
    try:
        parts = sorted(set(cc(x) for x in PHIS.get(v, [])))
    finally:
        _phi_stack.pop()
    parts = [p for p in parts if p not in ("self", "phi")]
    if not parts or any(p == "x" for p in parts):
        return "x"            # one unknown incoming value makes the merge unknown (load-of-merge vs merge-of-loads)
    if len(parts) == 1:
        return parts[0]         # a loop-invariant value (the back edge brings itself)
    return ("phi{%s}" % "|".join(parts))[:100]


def local_disp(name):
    return "LOCAL" if name.startswith("@") or name.startswith(".") else name


def strength(v):
    """2 = concrete source (comparable exactly), 1 = computed, 0 = unknown/unset"""
    t = v[0]
    if t in ("K", "F", "P", "R", "S"):
        return 2
    if t in ("L", "A"):
        return 2 if strength(v[1]) == 2 or v[1] in (GB, SPB) else 1
    if t in ("SP", "LS"):
        return 2
    if t == "O":
        return 1
    if t in ("V4", "V2"):
        return min(strength(c) for c in v[1:])
    if t == "LANE":
        return strength(v[1])
    if t in ("PHI", "PHIC"):
        return 1
    return 0


_names = {}


def callee_key(name):
    """canonical callee id (address when known on either side)"""
    a = None if name.startswith(("@", ".")) else sym_addr(name)
    k = "%X" % a if a is not None else name
    _names.setdefault(k, name)
    return k


def callee_disp(k):
    return _names.get(k, k)


# ---------------------------------------------------------------- CFG + dataflow

def blocks_of(insns):
    n = len(insns)
    idx = {ins.off: i for i, ins in enumerate(insns)}
    starts = {0}
    for i, ins in enumerate(insns):
        if ins.tgt is not None and ins.tgt in idx:
            starts.add(idx[ins.tgt])
        if ins.op in BR or ins.op in ("jr", "tailj", "jalr_tail"):
            if i + 2 < n:
                starts.add(i + 2)
    starts = sorted(s for s in starts if s < n)
    bl = []
    for k, s in enumerate(starts):
        e = starts[k + 1] if k + 1 < len(starts) else n
        bl.append((s, e))
    bidx = {s: k for k, (s, e) in enumerate(bl)}
    succ = []
    for k, (s, e) in enumerate(bl):
        # the control instruction is the second-to-last if a delay slot follows
        ctl = None
        for i in range(s, e):
            if insns[i].op in BR or insns[i].op in ("jr", "tailj"):
                ctl = i
                break
        out = []
        if ctl is None:
            if e < n:
                out.append((bidx[e], "fall"))
        else:
            ins = insns[ctl]
            if ins.op == "jr" or ins.op == "tailj":
                pass
            elif ins.op in ("b", "j"):
                if ins.tgt is not None and ins.tgt in idx:
                    out.append((bidx[idx[ins.tgt]], "taken"))
            else:
                if ins.tgt is not None and ins.tgt in idx:
                    out.append((bidx[idx[ins.tgt]], "taken"))
                if e < n:
                    out.append((bidx[e], "fall"))
        succ.append(out)
    return bl, succ, idx


class State:
    __slots__ = ("r", "m")

    def __init__(self, r=None, m=None):
        self.r = dict(r or {})
        self.m = dict(m or {})

    def copy(self):
        return State(self.r, self.m)

    def get(self, rg):
        if rg == "zero":
            return K(0)
        return self.r.get(rg, U)

    def join(self, o, blk=None):
        """merge o into self at block blk: differing values become ('PHI', blk, key), whose incoming values are kept
        in PHIS (so a loop counter reads `phi{#0|self+1}` on both sides, independent of its register)"""
        ch = False
        for d1, d2, tag in ((self.r, o.r, "r"), (self.m, o.m, "m")):
            for k in set(d1) | set(d2):
                a, b = d1.get(k, U), d2.get(k, U)
                if a == b or a == TOP or b == U:
                    continue
                if a == U:              # unset on one path: the compiler only reads it on the other
                    d1[k] = b
                    ch = True
                    continue
                if blk is None:
                    d1[k] = TOP
                    ch = True
                    continue
                ph = ("PHI", blk, tag + repr(k))
                inc = PHIS.setdefault(ph, [])
                if a != ph:
                    if a not in inc:
                        inc.append(a)
                    d1[k] = ph
                    ch = True
                if b != ph and b not in inc:
                    if len(inc) >= 6:
                        d1[k] = TOP
                    else:
                        inc.append(b)
                    ch = True
        return ch


def entry_state():
    s = State()
    for r in ARGI + ARGF + ["s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp", "ra", "gp"]:
        s.r[r] = ("P", r)
    for i in range(20, 32):
        s.r["f%d" % i] = ("P", "f%d" % i)
    s.r["sp"] = ("A", SPB, 0)
    return s


LOADS = {"lb": "1s", "lbu": "1", "lh": "2s", "lhu": "2", "lw": "4", "lwu": "4", "ld": "8", "lq": "16", "lwc1": "4f",
         "ldc1": "8f", "lqc2": "16", "lwl": "4l", "lwr": "4r", "ldl": "8l", "ldr": "8r"}
STORES = {"sb": "1", "sh": "2", "sw": "4", "sd": "8", "sq": "16", "swc1": "4", "sdc1": "8", "sqc2": "16",
          "swl": "4l", "swr": "4r", "sdl": "8l", "sdr": "8r"}
DEF2 = {"mtc1", "qmtc2", "ctc2", "ctc1", "dmtc1", "mtc0"}


class Analyzer:
    def __init__(self, insns, ctx, record=None):
        self.insns, self.ctx = insns, ctx
        self.rec = record
        self.ijump = []

    # value of an immediate operand (with relocation) given the source register value
    def imm_val(self, o, basev=None):
        _, n, rel = o
        if rel is None:
            return None, n
        k, sym, add = rel
        return rel, add

    def mem_addr(self, st, o):
        _, off, base, rel = o
        bv = st.get(base)
        if rel is None:
            return addv(bv, off) if bv not in (U, TOP) else (TOP if bv == TOP else ("A", bv, off))
        return self.lo_value(bv, rel)

    def lo_value(self, bv, rel):
        """the value of `%lo(sym)` added to bv (a lui %hi(sym), possibly added to a register first)"""
        k, sym, add = rel
        sb, so = self.ctx.symbase(sym)
        a = so + add
        if k == "lo" and bv[0] == "PHI":
            # a lui %hi merged with values from paths that never reach this %lo
            his = [x for x in PHIS.get(bv, []) if x[0] in ("HI", "HIP")]
            if his:
                bv = his[0]
        if k == "lo" and bv[0] in ("HI", "HIP"):
            hb, ha = (bv[1], bv[2]) if bv[0] == "HI" else (bv[2], bv[3])
            if self.ctx.side == "retail":
                # %hi of one symbol, %lo of another (MWCC shares a lui between neighbouring fields)
                tot = ha if sb != GB else ((ha + 0x8000) & ~0xFFFF) + sext16(a & 0xFFFF)
            else:
                tot = ha + sext16(add & 0xFFFF)
            v = K(tot) if hb == GB else ("A", hb, tot)
            if bv[0] == "HIP":       # splat's %hi(D_0012ACF8) on a plain offset: this + 0x12ACF8
                return addv(bv[1], tot) if hb == GB and bv[1] not in (U, TOP) else TOP
            return v
        if k == "lo" and sb == GB and bv not in (U, TOP) and not (bv[0] == "P" and bv[1] in ("gp", "zero")):
            # %lo(D_x)(reg) where reg = something + a plain lui: only the low half is added here
            return addv(bv, (((a & 0xFFFF) ^ 0x8000) - 0x8000)) if self.ctx.side == "retail" else addv(bv, a)
        return K(a) if sb == GB else ("A", sb, a)

    def load(self, st, ins, addr, width):
        b, o = addr_split(addr)
        if b == SPB:
            return stack_load(st, o, width.rstrip("sf"))
        if b[0] == "SPX":
            return ("LS", width)
        if b == GB and ("G:%X:%s" % (o, width.rstrip("sf"))) in st.r:
            # fix3: a global this function stored earlier (no call since): the value stored, not a reload
            # (BeginRendering__6B3Im3dFv: retail keeps _gpau128Registers in a register, ours re-reads it)
            gv = st.r["G:%X:%s" % (o, width.rstrip("sf"))]
            if gv not in (U, TOP):
                return gv
        if b == GB and width in ("4f", "4"):
            # an absolute word with initial data: its value (lit4 pools are read as int or float; a mutable global
            # reads as its initial value on both sides alike)
            raw = rom_read(o, 4)
            if raw is not None:
                return ("F", struct.unpack("<I", raw)[0]) if width == "4f" else K(struct.unpack("<i", raw)[0])
        if b[0] == "S" and self.ctx.obj is not None:
            raw = self.ctx.literal(("lit", b[1], o), int(width.rstrip("sflr")))
            if raw is not None and width == "4f":
                return ("F", struct.unpack("<I", raw)[0])
            if raw is not None and width in ("4", "4s"):
                return K(struct.unpack("<i", raw)[0])
        if b == TOP or b == U:
            return opv("load" + width, TOP if b == TOP else U)
        return depth_cut(("L", b, o, width))

    def step(self, st, ins, final=False):
        op, ops = ins.op, ins.ops
        R = self.rec if final else None

        def g(i):
            o = ops[i]
            if o[0] == "r":
                return st.get(o[1])
            if o[0] == "i":
                return K(o[1])
            return TOP

        def d(i, v):
            o = ops[i]
            if o[0] == "r" and o[1] != "zero":
                st.r[o[1]] = v

        if op in ("nop", "sync", "sync.l", "sync.p", "ssnop", "vnop", "vwaitq", "ei", "di", "break"):
            return
        if op == "li":
            v = ops[1][1]
            d(0, K(v))
            if R is not None:
                R.const(("K", v), ins)
            return
        if op == "move":
            d(0, g(1))
            return
        if op == "lui":
            o = ops[1]
            if o[0] == "i" and o[2]:
                k, sym, add = o[2]
                sb, so = self.ctx.symbase(sym)
                if self.ctx.side == "retail":
                    d(0, ("HI", sb, so + add))
                else:
                    d(0, ("HI", sb, so + (add << 16)))
            else:
                d(0, K((o[1] & 0xFFFF) << 16 if o[0] == "i" else 0))
            return
        if op in ("addiu", "addi"):
            o = ops[2]
            src = g(1)
            if o[0] == "i" and o[2]:
                k, sym, add = o[2]
                d(0, self.lo_value(src, o[2]))
                return
            n = sext16(o[1]) if o[0] == "i" else 0
            if src == U or src == TOP:
                d(0, src)
            else:
                d(0, addv(src, n))
            return
        if op == "addu":
            a, b = g(1), g(2)
            if b[0] == "HI" and a[0] not in ("HI", "K"):
                a, b = b, a
            if a[0] == "HI" and b[0] not in ("HI", "K"):
                d(0, ("HIP", b, a[1], a[2]))
                return
            if a[0] == "HI" and a[1] == GB:
                a = K((a[2] + 0x8000) & ~0xFFFF) if self.ctx.side == "retail" else K(a[2])
            if b[0] == "HI" and b[1] == GB:
                b = K((b[2] + 0x8000) & ~0xFFFF) if self.ctx.side == "retail" else K(b[2])
            if (a[0] == "A" and a[1] == SPB or a[0] == "SPX") and not is_k(b) or \
                    (b[0] == "A" and b[1] == SPB or b[0] == "SPX") and not is_k(a):
                d(0, ("SPX",))           # an indexed stack array
                return
            if is_k(b):
                d(0, addv(a, b[1]) if a not in (U, TOP) else a)
            elif is_k(a):
                d(0, addv(b, a[1]) if b not in (U, TOP) else b)
            else:
                x, y = sorted([a, b], key=repr)
                d(0, opv("add", x, y))
            return
        if op == "subu":
            a, b = g(1), g(2)
            if is_k(b) and a not in (U, TOP):
                d(0, addv(a, -b[1]))
            elif is_k(a) and is_k(b):
                d(0, K(a[1] - b[1]))
            else:
                d(0, opv("sub", a, b))
            return
        if op in ("ori", "andi", "xori", "slti", "sltiu"):
            a = g(1)
            n = ops[2][1] if ops[2][0] == "i" else 0
            if op in ("slti", "sltiu"):
                n = sext16(n)
            if op == "ori" and is_k(a):
                d(0, K(a[1] | n))
                return
            if op == "andi" and is_k(a):
                d(0, K(a[1] & n))
                return
            if R is not None and not (op == "ori" and a[0] == "HI"):
                R.const(("K", n), ins, op)
            d(0, opv(op, a, K(n)))
            return
        if op in ("sll", "sll32") and is_k(g(1)) and ops[2][0] == "i":
            d(0, K(g(1)[1] << (ops[2][1] + (32 if op == "sll32" else 0))))
            return
        if op in LOADS:
            o = ops[1]
            if o[0] != "m":
                d(0, TOP)
                return
            if ops[1][3] and ops[1][3][0] == "lit" and self.ctx.obj is not None:
                raw = self.ctx.literal(ops[1][3], 4 if LOADS[op] in ("4f", "4", "4s") else 8)
                if raw is not None:
                    v = ("F", struct.unpack("<I", raw[:4])[0]) if LOADS[op] == "4f" else K(struct.unpack("<i", raw[:4])[0])
                    d(0, v)
                    if R is not None and v[0] == "F":
                        R.const(v, ins)
                    return
            addr = self.mem_addr(st, o)
            v = self.load(st, ins, addr, LOADS[op])
            if R is not None:
                if v[0] == "F":
                    R.const(v, ins)
                R.load(addr, LOADS[op], ins)
            d(0, v)
            return
        if op in STORES:
            o = ops[1]
            if o[0] != "m":
                return
            addr = self.mem_addr(st, o)
            v = g(0)
            b, off = addr_split(addr)
            w = STORES[op]
            if b == SPB:
                stack_store(st, off, w, v)
                return
            if b[0] == "SPX":
                return
            if b == GB and w in ("4", "8", "16"):
                n = int(w)
                for k in [k for k in st.r if k.startswith("G:")]:
                    ko, kw = k[2:].split(":")
                    if int(ko, 16) < off + n and off < int(ko, 16) + _wid(kw):
                        del st.r[k]
                st.r["G:%X:%s" % (off, w)] = v
            if R is not None:
                R.store(addr, w, v, ins)
            return
        if op in ("mtc1", "qmtc2", "dmtc1"):
            v = g(0)
            if is_k(v):
                fv = ("F", v[1] & 0xFFFFFFFF)
                if R is not None:
                    R.const(fv, ins)
                v = fv
            d(1, v)
            return
        if op in ("mfc1", "qmfc2", "dmfc1"):
            d(0, g(1))
            return
        if op in ("mov.s",):
            d(0, g(1))
            return
        if op.startswith("c.") and (op.endswith(".s") or op.endswith(".d")):
            a, b = g(0), g(1)
            st.r["FCC"] = ("FCC", op, a, b)
            if R is not None:
                R.fcmp(op, a, b, ins)
            return
        if op in ("mult", "multu", "div", "divu", "mult1", "multu1", "div1", "divu1", "madd", "maddu", "madd1"):
            vals = [g(i) for i in range(len(ops)) if ops[i][0] == "r"]
            v = opv(op, *vals[-2:])
            st.r["LO"] = v
            st.r["HI"] = v
            if len(ops) == 3:
                d(0, v)
            return
        if op in ("mflo", "mfhi", "mflo1", "mfhi1"):
            d(0, st.r.get("LO" if "lo" in op else "HI", TOP))
            return
        if op in ("ctc2", "ctc1", "mtc0"):
            d(1, g(0))
            return
        if op.startswith("vmula") or op.startswith("vmadda") or op.startswith("vmsuba") or op.startswith("vadda") \
                or op.startswith("vsuba") or op == "vopmula":
            st.r["ACC"] = opv(op, *[g(i) for i in range(len(ops)) if ops[i][0] == "r" and ops[i][1] != "ACC"])
            return
        if op in ("vdiv", "vsqrt", "vrsqrt", "cop2word"):
            st.r["Q"] = opv(op, *[g(i) for i in range(len(ops))])
            return
        if op in ("vrinit", "vrxor"):
            st.r["R"] = opv(op, st.r.get("R", U), g(1) if len(ops) > 1 else U)
            return
        if op in ("vrnext", "vrget"):
            st.r["R"] = opv(op, st.r.get("R", U))
            d(0, st.r["R"])
            return
        if op in ("vsqi", "vlqi", "vsqd", "vlqd", "vilwr", "viswr", "vmfir", "vmtir"):
            for i, o in enumerate(ops):
                if o[0] == "r":
                    st.r[o[1]] = TOP
            return
        if op.startswith("b") or op in ("j", "jr", "jal", "jalr", "tailj"):
            return
        # generic: def first register operand, uses the rest
        regs = [i for i, o in enumerate(ops) if o[0] == "r"]
        if not regs:
            return
        srcs = []
        for i in regs[1:]:
            srcs.append(g(i))
        if op.startswith("v") and ops[regs[0]][1].startswith("vf"):
            srcs.append(st.get(ops[regs[0]][1]))   # partial-lane write keeps the other lanes
        for i, o in enumerate(ops):
            if o[0] == "i" and i > 0:
                srcs.append(K(o[1]))
        if op.startswith("v") and any(o[0] == "r" and o[1] in ("Q", "I", "ACC", "R") for o in ops[1:]) is False and \
                op[1:4] in ("mad", "msu") or op.startswith("vmadd") or op.startswith("vmsub"):
            srcs.append(st.r.get("ACC", U))
        d(regs[0], opv(op, *srcs))

    def call(self, st, ins, key, R):
        if R is not None:
            R.call(st, ins, key)
        esc = [st.get(r)[2] for r in ARGI if st.get(r)[0] == "A" and st.get(r)[1] == SPB]
        esc += [0] if any(st.get(r)[0] == "SPX" for r in ARGI) else []
        for r in CLOBBER:
            st.r[r] = U
        for k in [k for k in st.r if k.startswith("G:")]:
            del st.r[k]           # fix3: the callee may change any global
        for e in esc:
            # the callee may fill what it was handed: a window above the address (spill slots elsewhere survive)
            for k in list(st.m):
                if k[0] != "any" and e <= k[0] < e + 0x100:
                    st.m[k] = ("LS", k[1])
        st.r["v0"] = ("R", key, "v0")
        st.r["v1"] = ("R", key, "v1")
        st.r["f0"] = ("R", key, "f0")

    def run_block(self, st, s, e, final=False, edge=None):
        """execute insns[s:e]; the delay slot of a control instruction runs before it. Returns (state, taken_state)
        where taken_state differs for likely branches (delay slot only on the taken path)."""
        ins_l = self.insns
        i = s
        taken = None
        while i < e:
            ins = ins_l[i]
            if ins.op in BR or ins.op in ("jr", "tailj", "jal", "jalr"):
                ds = ins_l[i + 1] if i + 1 < e else None
                if ins.op in LIKELY:
                    if final and self.rec is not None:
                        self.rec.branch(st, ins)
                    t = st.copy()
                    if ds:
                        self.step(t, ds, final)
                    taken = t
                    i += 2
                    continue
                if ins.op in ("jal", "jalr", "tailj"):
                    if ds:
                        self.step(st, ds, final)
                    if ins.op == "jalr":
                        rr = [o for o in ins.ops if o[0] == "r"]
                        tv = st.get(rr[-1][1]) if rr else TOP
                        key = "vcall" + jalr_key(tv)
                    else:
                        key = callee_key(ins.callee or "?")
                    self.call(st, ins, key, self.rec if final else None)
                    if ins.op == "tailj" and final and self.rec is not None:
                        self.rec.ret(st, ins)
                    i += 2
                    continue
                if final and self.rec is not None:
                    if ins.op == "jr":
                        pass
                    else:
                        self.rec.branch(st, ins)
                if ds:
                    self.step(st, ds, final)
                if ins.op == "jr" and not final and ins.ops and ins.ops[0] != ("r", "ra"):
                    self.ijump.append(st.copy())
                if ins.op == "jr" and final and self.rec is not None:
                    if ins.ops and ins.ops[0] == ("r", "ra"):
                        self.rec.ret(st, ins)
                i += 2
                continue
            self.step(st, ins, final)
            i += 1
        return st, (taken or st)

    def run(self):
        bl, succ, idx = blocks_of(self.insns)
        nb = len(bl)
        ins_state = [None] * nb
        if nb == 0:
            return
        ins_state[0] = entry_state()
        pending = [0]
        seeded = {0}
        iters = 0
        while True:
            while pending and iters < 60 * nb + 200:
                iters += 1
                k = pending.pop(0)
                st, tk = self.run_block(ins_state[k].copy(), *bl[k])
                for (t, kind) in succ[k]:
                    src = tk if kind == "taken" else st
                    if ins_state[t] is None:
                        ins_state[t] = src.copy()
                        pending.append(t)
                    elif ins_state[t].join(src, t):
                        if t not in pending:
                            pending.append(t)
            unreached = [k for k in range(nb) if ins_state[k] is None]
            if not unreached:
                break
            k = unreached[0]
            if self.ijump:
                # a jump-table target: the state at the indirect jump(s)
                s = self.ijump[0].copy()
                for o in self.ijump[1:]:
                    s.join(o)
                ins_state[k] = s
                pending.append(k)
                continue
            s = entry_state()
            for r in list(s.r):
                if r != "sp":
                    s.r[r] = TOP
            # a jump-table target: no idea of the registers, keep the frame
            # the frame: the stack pointer most reached blocks see (block 0's is the pre-prologue one)
            sps = collections.Counter(ins_state[kk].r.get("sp") for kk in range(nb) if ins_state[kk] is not None)
            s.r["sp"] = sps.most_common(1)[0][0] if sps else TOP
            ins_state[k] = s
            pending.append(k)
        # final recording pass in address order; return values are taken per edge into the jr-ra block
        self.blocks, self.succ, self.ins_state = bl, succ, ins_state
        preds = collections.defaultdict(list)
        for k in range(nb):
            for (t, kind) in succ[k]:
                preds[t].append((k, kind))
        outs = {}
        for k in range(nb):
            if self.rec:
                self.rec.cur_block = k
            st, tk = self.run_block(ins_state[k].copy(), *bl[k], final=True)
            outs[k] = (st, tk)
        # return paths: re-run each block containing jr ra once per predecessor edge
        if self.rec is not None:
            self.rec.returns = []
            for k in range(nb):
                s, e = bl[k]
                if not any(self.insns[i].op == "jr" and self.insns[i].ops[:1] == [("r", "ra")] for i in range(s, e)):
                    continue
                ps = preds.get(k) or [(None, None)]
                for (p, kind) in ps:
                    st0 = entry_state() if p is None else (outs[p][1] if kind == "taken" else outs[p][0])
                    sub = Analyzer(self.insns, self.ctx, None)
                    st1, _ = sub.run_block(st0.copy(), s, e)
                    self.rec.returns.append((st1.get("v0"), st1.get("f0"), self.insns[s].off))


def _wid(w):
    try:
        return int(w.rstrip("lrsf"))
    except ValueError:
        return 4


def stack_store(st, off, w, v):
    n = _wid(w)
    if w[-1:] in ("l", "r"):
        n, w = 0, w      # swl/swr: unaligned halves, treat as opaque
    # split a wider value this store partly overwrites into 4-byte lanes, then drop what overlaps
    for k in list(st.m):
        if k[0] == "any":
            continue
        ko, kw = k[0], _wid(k[1])
        if ko < off + max(n, 1) and ko + kw > off and k != (off, w):
            old = st.m.pop(k)
            if kw > 4 and kw % 4 == 0:
                for i in range(kw // 4):
                    lo = ko + 4 * i
                    if not (lo < off + n and lo + 4 > off):
                        st.m[(lo, "4")] = lane_of(old, i)
    if n:
        st.m[(off, w)] = v


def lane_of(v, i):
    if v[0] == "V4" and i < 4:
        return v[1 + i]
    if v[0] in ("U", "?", "LS"):
        return v
    return ("LANE", v, i)


def stack_load(st, o, w):
    v = st.m.get((o, w))
    if v is not None:
        return v
    n = _wid(w)
    if n in (16, 8) and w[-1:] not in ("l", "r"):
        lanes = [st.m.get((o + 4 * i, "4")) for i in range(n // 4)]
        if all(x is not None for x in lanes):
            return ("V4",) + tuple(lanes) if n == 16 else ("V2",) + tuple(lanes)
        if n == 16:
            h = [st.m.get((o, "8")), st.m.get((o + 8, "8"))]
            if all(x is not None for x in h):
                return ("V4",) + tuple(lane_of(h[0], 0), ) + (lane_of(h[0], 1), lane_of(h[1], 0), lane_of(h[1], 1))
    if n == 4:
        for k, kv in st.m.items():
            if k[0] != "any" and _wid(k[1]) > 4 and k[0] <= o < k[0] + _wid(k[1]) and (o - k[0]) % 4 == 0:
                return lane_of(kv, (o - k[0]) // 4)
    v = st.m.get(("any", 0))
    return ("LS", w) if v is None else v


def cc(v, d=3):
    """operand text for condition keys: sources only, computed values are `x`"""
    t = v[0]
    if d <= 0:
        return "x"
    if t == "P" and v[1] in CALLEE_SAVED:
        return "x"        # fix2: a callee-saved register read before any write is the caller's leftover (func_0045FC80)
    if t in ("K", "F", "P", "R", "S"):
        return val_canon(v)
    if t == "L":
        b = v[1]
        if b == GB:
            return "[&%X]" % v[2]
        if b == SPB:
            return "[stack]"
        bb = cc(b, d - 1)
        if bb == "&stack":
            return "[stack]"
        m = re.match(r"^\((.*)\+([0-9A-F]+)\)$", bb)      # a merged pointer (phi of one value) still folds
        if m:
            return "[%s+%X]" % (m.group(1), int(m.group(2), 16) + v[2])
        if bb == "x" and v[2] == 0:
            return "x"
        return "[%s+%X]" % (bb, v[2])
    if t == "A":
        if v[1][0] == "S":
            return "&%s%s" % (local_disp(v[1][1]), "+%X" % v[2] if v[2] else "")
        b = cc(v[1], d - 1) if v[1] != SPB else "&stack"
        if b == "&stack":
            return "&stack"
        m = re.match(r"^\((.*)\+(-?[0-9A-F]+)\)$", b)          # nested offsets fold: ((X+-1)+260) = (X+25F)
        if m:
            n = int(m.group(2), 16) + v[2]
            return "(%s+%s)" % (m.group(1), ("%X" % n) if n >= 0 else "-%X" % -n)
        return "(%s+%s)" % (b, ("%X" % v[2]) if v[2] >= 0 else "-%X" % -v[2])
    if t == "PHI":
        return phi_canon(v)
    if t == "PHIC":
        return v[1]
    if t in ("V4", "V2"):
        parts = [cc(c, d - 1) for c in v[1:]]
        return "x" if all(p == "x" for p in parts) else "vec(%s)" % ",".join(parts)
    if t == "LANE":
        x = cc(v[1], d - 1)
        m = re.match(r"^\[(.*)\+([0-9A-F]+)\]$", x) if v[2] < 4 and x != "[stack]" else None
        if m:   # fix2: lane k of a quad load = the word at +4k (one lq vs four lw)
            return "[%s+%X]" % (m.group(1), int(m.group(2), 16) + 4 * v[2])
        m = re.match(r"^\[&([0-9A-F]+)\]$", x) if v[2] < 4 else None
        if m:
            return "[&%X]" % (int(m.group(1), 16) + 4 * v[2])
        return "x" if x == "x" else "%s.%s" % (x, "xyzw"[v[2]] if v[2] < 4 else v[2])
    if t == "SP":
        return "&stack"
    if t == "O" and v[1] == "andi" and len(v[2]) == 2 and v[2][1][0] == "K":
        if v[2][1][1] in (0xFF, 0xFFFF):
            return cc(v[2][0], d)                # a u8/u16 truncation: type noise, not behaviour
        x = cc(v[2][0], d - 1)
        sh = v[2][0]
        if x == "x" and sh[0] == "O" and sh[1] in ("sllv", "dsllv") and len(sh[2]) == 2 and sh[2][0] == K(1):
            return "and(bit,#%d)" % v[2][1][1]     # taskB: a bit-mask switch's (1 << (X - min)) & M keeps its mask
        return "x" if x == "x" else "and(%s,#%d)" % (x, v[2][1][1])
    return "x"


def canon_pred(ck):
    """a <= b is !(b < a) (NaN aside): fle(a,b) -> flt(b,a) with the sense flipped, so MWCC's two spellings of one
    test compare alike; a leading ! (a negated boolean) flips too. Returns (key, flipped)."""
    if ck.startswith("!"):
        k, f = canon_pred(ck[1:])
        return k, not f
    m = re.match(r"^fle\((.*)\)$", ck)
    if m:
        parts = split_ops(m.group(1))
        if len(parts) == 2:
            return "flt(%s,%s)" % (parts[1], parts[0]), True
    m = re.match(r"^lt\((.*)\)$", ck)     # taskB: signed compares against 0 are bltz/blez spellings: slt(x,0) = ltz(x),
    if m:                                 # slt(0,x) = !lez(x), slti(x,1) = lez(x) (ezNetCnfInit, func_00468850)
        parts = split_ops(m.group(1))
        if len(parts) == 2:
            if parts[1] == "#0":
                return "ltz(%s)" % parts[0], False
            if parts[0] == "#0":
                return "lez(%s)" % parts[1], True
            if parts[1] == "#1":
                return "lez(%s)" % parts[0], False
    return ck, False


def taken_truth(op, ck):
    """is the branch taken when its predicate (cond_key, up to negation) is TRUE? (before canon_pred's flip)"""
    ck = ck.lstrip("!")
    base = {"beql": "beq", "bnel": "bne", "bgezl": "bgez", "bltzl": "bltz", "blezl": "blez", "bgtzl": "bgtz",
            "bc1tl": "bc1t", "bc1fl": "bc1f"}.get(op, op)
    if base in ("bc1t", "beq", "bltz", "blez"):
        t = True
    elif base in ("bc1f", "bne", "bgez", "bgtz"):
        t = False
    else:
        return None
    if ck.startswith(("lt(", "ltu(", "nz(")):      # beqz/bnez on an slt result or a value: beqz = taken when 0
        t = not t
    return t


def branch_sigs(rec, bl, succ):
    """per conditional branch: (predicate, effects only on its TRUE side, effects only on its FALSE side). A layout
    flip (bc1t vs bc1f, beqz vs bnez with the arms swapped) keeps the signature; an inverted condition swaps the sides."""
    if not bl:
        return []
    n = len(bl)
    # post-dominators (iterative sets; blocks without successors are exits)
    full = frozenset(range(n))
    pdom = [full] * n
    for k in range(n):
        if not succ[k]:
            pdom[k] = frozenset([k])
    changed = True
    rounds = 0
    while changed and rounds < 200:
        changed, rounds = False, rounds + 1
        for k in range(n - 1, -1, -1):
            if not succ[k]:
                continue
            new = frozenset.intersection(*[pdom[t] for (t, _) in succ[k]]) | {k}
            if new != pdom[k]:
                pdom[k], changed = new, True

    def region(start, k):
        """blocks from start up to the join (a strict post-dominator of k), not passing k again"""
        stop = pdom[k] - {k}
        if start in stop:
            return set()
        seen, st = {start}, [start]
        while st:
            x = st.pop()
            for (t, _) in succ[x]:
                if t not in seen and t not in stop and t != k:
                    seen.add(t)
                    st.append(t)
        return seen
    out = []
    for (ck, tt, k, off) in rec.brs:
        if tt is None or k >= n:
            continue
        tk = [t for (t, kind) in succ[k] if kind == "taken"]
        fl = [t for (t, kind) in succ[k] if kind == "fall"]
        if not tk or not fl or tk[0] == fl[0]:
            continue
        rt, rf = region(tk[0], k), region(fl[0], k)
        et = frozenset(e for b in rt - rf for e in rec.eff.get(b, ()))
        ef = frozenset(e for b in rf - rt for e in rec.eff.get(b, ()))
        if not et and not ef:
            continue
        out.append((ck, et, ef, off) if tt else (ck, ef, et, off))
    return out


def cond_key(st, ins):
    """the branch's predicate up to negation (layout-independent): lt(a,b), le(a,b), eq(a,b), ltz(a), lez(a), nz(a)"""
    op = ins.op
    if op.startswith("bc1"):
        f = st.r.get("FCC", TOP)
        if f[0] != "FCC":
            return "fcc(x)"
        c = f[1].split(".")[1]
        a, b = cc(f[2]), cc(f[3])
        if c in ("eq", "ueq", "seq", "ngl"):
            a, b = sorted([a, b])
        return "f%s(%s,%s)" % (c, a, b)
    regs = [st.get(o[1]) for o in ins.ops if o[0] == "r"]
    base = {"beql": "beq", "bnel": "bne", "bgezl": "bgez", "bltzl": "bltz", "blezl": "blez", "bgtzl": "bgtz"}.get(op, op)
    if base in ("beq", "bne") and len(regs) == 2:
        a, b = regs
        if b == K(0):
            neg = False
            for _ in range(4):        # booleans: xori 1 negates, sltu(0,v) is v != 0, sltiu(v,1) is v == 0
                if a[0] == "O" and a[1] == "xori" and len(a[2]) == 2 and a[2][1] == K(1):
                    a, neg = a[2][0], not neg
                elif a[0] == "O" and a[1] == "sltu" and len(a[2]) == 2 and a[2][0] == K(0):
                    a = a[2][1]
                elif a[0] == "O" and a[1] == "sltiu" and len(a[2]) == 2 and a[2][1] == K(1):
                    a, neg = a[2][0], not neg
                else:
                    break
            pre = "!" if neg else ""
            if a[0] == "O" and a[1] in ("slt", "sltu", "slti", "sltiu") and len(a[2]) == 2:
                return pre + "%s(%s,%s)" % ("ltu" if a[1].startswith("sltu") else "lt", cc(a[2][0]), cc(a[2][1]))
            return pre + "nz(%s)" % cc(a)
        x, y = sorted([cc(a), cc(b)])
        return "eq(%s,%s)" % (x, y)
    if base in ("bltz", "bgez") and regs:
        return "ltz(%s)" % cc(regs[0])
    if base in ("blez", "bgtz") and regs:
        return "lez(%s)" % cc(regs[0])
    return op


def jalr_key(v):
    # vcall through a vtable: L(L(obj, vptroff), slot)
    if v[0] == "L" and v[1][0] == "L":
        return "[+%X][+%X]" % (v[1][2], v[2])
    if v[0] == "L":
        return "(%s)" % val_canon(v)
    return "(%s)" % val_canon(v)[:40]


class Recorder:
    def __init__(self):
        self.calls, self.consts, self.stores, self.loads = [], collections.Counter(), [], []
        self.branches = collections.Counter()
        self.fcmps = []
        self.conds = []
        self.brs = []                                 # (cond key, taken when true?, block, off)
        self.eff = collections.defaultdict(set)       # block -> effects (calls, non-stack stores)
        self.sigs = []
        self.returns = []
        self.cur_block = 0
        self.last_fcmp = None

    def const(self, v, ins, op="li"):
        if v[0] == "K":
            n = v[1]
            self.consts[("K", n if n < 1 << 63 else n - (1 << 64))] += 1
        else:
            self.consts[("F", fbits_str(v[1]))] += 1

    def call(self, st, ins, key):
        args = {}
        for r in ARGI + ARGF:
            args[r] = st.get(r)
        self.calls.append({"off": ins.off, "key": key, "args": args, "block": self.cur_block})
        self.eff[self.cur_block].add("call " + callee_disp(key))

    def store(self, addr, w, v, ins):
        b, off = addr_split(addr)
        self.stores.append((b, off, w, v, ins.off))
        k = store_key(b, off, w)
        if k[0] != "*":
            self.eff[self.cur_block].add("store %s+%X" % (k[0], k[1]))

    def load(self, addr, w, ins):
        pass

    def fcmp(self, op, a, b, ins):
        self.fcmps.append((op, a, b, ins.off))
        self.last_fcmp = op

    def branch(self, st, ins):
        op = ins.op
        if op in ("b", "j"):
            return
        if ins.tgt is not None and ins.tgt == ins.off + 8 and not op.endswith("l"):
            return    # taskB: an empty branch (taken target = the fall-through after the delay slot): no behaviour
                      # (UpdateSkidVoices__22CB3SoundCrashedTraffic's bltz / bc1f 0x28FFA0, 0x28FFB8)
        ck0 = cond_key(st, ins)
        ck, flip = canon_pred(ck0)
        self.conds.append((ck, ins.off))
        tt = taken_truth(op, ck0)
        self.brs.append((ck, (None if tt is None else tt != flip), self.cur_block, ins.off))
        if op.startswith("bc1"):
            fcc = st.r.get("FCC", TOP)
            c = fcc[1] if fcc[0] == "FCC" else "c.?"
            self.branches["%s+%s" % (c.replace(".s", ""), op)] += 1
            return
        regs = [o for o in ins.ops if o[0] == "r"]
        if op in ("beq", "bne", "beql", "bnel") and len(regs) == 2 and regs[1] == ("r", "zero"):
            self.branches[op + "z"] += 1
            v = st.get(regs[0][1])
            return
        if op in ("beq", "bne", "beql", "bnel") and len(regs) == 2:
            self.branches[op] += 1
            for r in regs:
                v = st.get(r[1])
                if v[0] == "K":
                    self.consts[("K", v[1] if v[1] < 1 << 63 else v[1] - (1 << 64))] += 0
            return
        self.branches[op] += 1

    def ret(self, st, ins):
        pass


# ---------------------------------------------------------------- features + comparison

def analyse(insns, ctx):
    PHIS.clear()
    rec = Recorder()
    an = Analyzer(insns, ctx, rec)
    an.run()
    rec.sigs = branch_sigs(rec, getattr(an, "blocks", []), getattr(an, "succ", []))
    rec.minmax = sum(1 for i in insns if i.op in ("min.s", "max.s", "abs.s") or
                     i.op.startswith(("vmax", "vmini")))   # taskB: branchless float selects (FPU and VU0 clamps)
    rec.movsel = sum(1 for i in insns if i.op in ("movz", "movn", "pminw", "pmaxw"))   # taskB: branchless integer selects
    # freeze: PHI values become their canonical text now (PHIS is per function)
    for c in rec.calls:
        c["args"] = {k: freeze(v) for k, v in c["args"].items()}
    rec.stores = [(freeze(b), off, w, freeze(v), o) for (b, off, w, v, o) in rec.stores]
    rec.fcmps = [(op, freeze(a), freeze(b), o) for (op, a, b, o) in rec.fcmps]
    rec.returns = [(freeze(a), freeze(b), o) for (a, b, o) in rec.returns]
    return rec


def freeze(v):
    t = v[0]
    if t == "PHI":
        return ("PHIC", phi_canon(v))
    if t in ("L",):
        return ("L", freeze(v[1]), v[2], v[3])
    if t == "A":
        return ("A", freeze(v[1]), v[2])
    if t == "O":
        return ("O", v[1], tuple(freeze(a) for a in v[2]))
    if t in ("V4", "V2"):
        return (t,) + tuple(freeze(c) for c in v[1:])
    if t == "LANE":
        return ("LANE", freeze(v[1]), v[2])
    return v


Q3 = set()


def lanes(stores):
    """quadword/doubleword stores as 4-byte lanes (lane copies and lq/sq copies compare alike); a quadword's w lane
    is tagged q3 (padding in most CGtV3d copies)"""
    for (b, off, w, v, o) in stores:
        n = _wid(w)
        if n in (8, 16) and w[-1:] not in ("l", "r"):
            for i in range(n // 4):
                yield (b, off + 4 * i, "4" + ("q3" if n == 16 and i == 3 else ""), lane_of(v, i), o)
        else:
            yield (b, off, w, v, o)


def store_key(b, off, w):
    if w.endswith("q3"):
        k = store_key(b, off, w[:-2])
        Q3.add(k)
        return k
    if b == GB:
        bk = "&%X" % off
        return (bk, 0, w)
    bs = strength(b) if b not in (TOP, U) else 0
    bk = val_canon(b) if bs == 2 else "*"
    if b[0] == "S":
        bk = "&" + local_disp(b[1])
    return (bk, off, w)


PURE = re.compile(r"^__(ct|dt|as|pl|mi|ml|dv|apl|ami|amu|adv|eq|ne|lt|gt|le|ge|vc|cl|nm|ad|or|er|co|rs|ls)__|Q29GtMathPs2|^(sqrtf|fabsf)$")


_tiny = {}


def tiny_callee(key):
    """retail's callee is a leaf of <= 6 instructions (a quad copy `sq a1,0(a0); jr ra`, an accessor): an inline in
    ours vs an out-of-line call in retail is no behaviour difference"""
    if key in _tiny:
        return _tiny[key]
    r = False
    if re.match(r"^[0-9A-F]+$", key):
        glabel_addr("")
        n = _byaddr.get(int(key, 16))
        if n and n in _gpath:
            try:
                ins, _ = parse_retail(_gpath[n], n)
                r = 0 < len(ins) <= 6 and not any(i.op in ("jal", "jalr", "tailj") for i in ins)
            except Exception:  # noqa
                r = False
    _tiny[key] = r
    return r


def pure(key):
    """a GtMathPs2 member, constructor or operator, or a tiny leaf: an inlined-vs-called difference, not a behaviour one"""
    return PURE.search(callee_disp(key)) is not None or tiny_callee(key)


def compare(fr, fo, arity, addr=None):
    """-> list of (score, category, retail_off, detail)"""
    out = []
    # ---- calls
    ka = [c["key"] for c in fr.calls]
    kb = [c["key"] for c in fo.calls]
    sm = difflib.SequenceMatcher(None, ka, kb, autojunk=False)
    pairs = []
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == "equal":
            pairs += [(fr.calls[i1 + k], fo.calls[j1 + k]) for k in range(i2 - i1)]
            continue
        miss = collections.Counter(ka[i1:i2]) - collections.Counter(kb)
        extra = collections.Counter(kb[j1:j2]) - collections.Counter(ka)
        for c in fr.calls[i1:i2]:
            if miss.get(c["key"]):
                out.append((1 if pure(c["key"]) else 6, "call-missing", c["off"], "retail calls %s, ours never does" % callee_disp(c["key"])))
                miss[c["key"]] -= 1
        for c in fo.calls[j1:j2]:
            if extra.get(c["key"]):
                out.append((1 if pure(c["key"]) else 6, "call-extra", None, "ours calls %s, retail never does" % callee_disp(c["key"])))
                extra[c["key"]] -= 1
    if collections.Counter(ka) != collections.Counter(kb):
        mc = collections.Counter(ka) - collections.Counter(kb)
        ec = collections.Counter(kb) - collections.Counter(ka)
        for k, n in mc.items():
            if not any(f[1] == "call-missing" and callee_disp(k) in f[3] for f in out):
                out.append((1 if pure(k) else 4, "call-count", None, "%s: retail %d calls, ours %d" % (callee_disp(k), ka.count(k), kb.count(k))))
        for k, n in ec.items():
            if not any(f[1] == "call-extra" and callee_disp(k) in f[3] for f in out):
                out.append((1 if pure(k) else 4, "call-count", None, "%s: retail %d calls, ours %d" % (callee_disp(k), ka.count(k), kb.count(k))))
    elif ka != kb:
        out.append((1, "call-order", None, "same callee multiset, different address order (layout?)"))
    # fix2: a callee name with no retail address that our object does not define either: a prototype whose parameter
    # types / linkage mangle to a symbol retail does not have (placeholder struct types, int for an enum, extern "C" vs
    # C++): the matching build never links it, the port would fail to link (DrawInvisiblePolys, func_00366980, ...)
    loc = getattr(fo, "local_defs", set())
    for k in sorted(set(kb)):
        if re.match(r"^[0-9A-F]+$", k) or k.startswith(("vcall", "@", ".")) or callee_disp(k) in loc or k == "?":
            continue
        out.append((6, "call-unresolved", None, "ours calls %s: no retail symbol of that name (prototype types or "
                    "linkage?)" % callee_disp(k)))
    # pair calls of the same callee by their arguments (block placement reorders sites: the first retail call of a
    # callee can be ours' third), greedily by the number of agreeing argument sources, ties by order
    byk = collections.defaultdict(list)
    for c in fo.calls:
        byk[c["key"]].append(c)
    # global greedy: best-agreeing pairs first, ties by position in each list
    cand = []
    rank = collections.Counter()
    ccache = {}

    def ccv(v):
        if v not in ccache:
            ccache[v] = cc(v)
        return ccache[v]
    for i, c in enumerate(fr.calls):
        ri = rank[c["key"]]
        rank[c["key"]] += 1
        lst = byk.get(c["key"], [])
        if len(lst) > 60:
            lst = lst[max(0, ri - 30):ri + 30]
        for j, o in enumerate(lst):
            sc = sum(1 for r in ARGI + ARGF if c["args"][r] != U and o["args"][r] != U and
                     ccv(c["args"][r]) != "x" and ccv(c["args"][r]) == ccv(o["args"][r]))
            cand.append((-sc, abs(ri - j), i, j, c, o))
    cand.sort(key=lambda t: t[:4])
    pairs, ua, ub = [], set(), set()
    for _, _, i, j, c, o in cand:
        if i in ua or id(o) in ub:
            continue
        ua.add(i)
        ub.add(id(o))
        pairs.append((c, o))
    for a, b in pairs:
        regs = arity.get(a["key"], {})
        diffs = {}
        for r in ARGI + ARGF:
            va, vb = a["args"][r], b["args"][r]
            kind = regs.get(r, "unk")
            if kind == "argx":
                kind = "arg"
            if kind == "no":
                continue
            if va == vb:
                continue
            if a["key"].startswith("vcall") and r not in ("a0", "a1", "f12"):
                continue          # a virtual callee's parameter list is unknown: only the first slots
            if va != U and vb == U:
                if kind == "arg":
                    out.append((6, "arg-missing", a["off"], "%s %s: retail %s, ours leaves it unset" % (
                        callee_disp(a["key"]), r, cc(va))))
                continue
            if va == U:
                continue
            ca, cb = cc(va), cc(vb)
            if ca == cb or "x" in (ca, cb) or loosely_equal_c(ca, cb) or "&stack" in (ca, cb):
                continue          # &stack: a local copy (by-value struct, out-parameter) -- not comparable
            if a["key"].startswith("vcall") and r not in ("a0", "a1", "f12"):
                continue          # a virtual callee's parameter list is unknown: only the first slots
            if (kind == "unk" or a["key"].startswith("vcall")) and (va[0] == "P" and va[1] == r or vb[0] == "P" and vb[1] == r):
                continue          # untouched incoming register on one side: the callee may not take it (fix2: a vcall's
                                  # "arity" from retail sites counts stale registers, e.g. Update__16CB3TrafficSystem)
            diffs[r] = (ca, cb)
        done = set()
        for r1 in diffs:
            for r2 in diffs:
                if r1 < r2 and r1 not in done and r2 not in done and diffs[r1][0] == diffs[r2][1] and diffs[r1][1] == diffs[r2][0]:
                    out.append((7, "arg-swap", a["off"], "%s %s<->%s: retail %s,%s / ours %s,%s" % (
                        callee_disp(a["key"]), r1, r2, diffs[r1][0], diffs[r2][0], diffs[r1][1], diffs[r2][1])))
                    done |= {r1, r2}
        for r, (ca, cb) in diffs.items():
            if r in done:
                continue
            exact = not re.search(r"\bx\b", ca + " " + cb)
            w = 5 if exact else 3
            if wild_eq(ca, cb) or idx_fold_eq(ca, cb):
                w = 1             # fix3: equal up to a value the dataflow lost on one side (see wild_eq)
            elif phi_contains(ca, cb) or phi_contains(cb, ca):
                w = 2             # fix2: one side's value is one input of the other's merge (loop exit / tail-duplicated
                                  # arm / swap): seen as noise in DoFiller, FillLaneSection, func_0030C560
            out.append((w, "arg-source", a["off"], "%s %s: retail %s / ours %s" % (
                callee_disp(a["key"]), r, ca[:70], cb[:70])))
    # swapped args: an arg-source pair whose values are exchanged
    srcs = [f for f in out if f[1] == "arg-source"]
    # ---- branches: an inverted condition = the same predicate with its two sides' effects swapped
    sa = collections.Counter((k, t, f) for (k, t, f, o) in fr.sigs)
    sb = collections.Counter((k, t, f) for (k, t, f, o) in fo.sigs)
    soffs = {(k, t, f): o for (k, t, f, o) in fr.sigs}
    inverted = set()
    for (k, t, f), n in sa.items():
        if re.match(r"^nz\(phi\{[#\d|-]+\}\)$", k):
            continue          # a merged 0/1 flag: which constant means "true" is the earlier branch's business
        if sb.get((k, t, f), 0) < n and sb.get((k, f, t), 0) > sa.get((k, f, t), 0) and t != f:
            inverted.add(k)
            out.append((7, "cond-inverted", soffs.get((k, t, f)), "%s: retail does {%s} when true / {%s} when false; ours "
                        "the other way round" % (k, ", ".join(sorted(t))[:80], ", ".join(sorted(f))[:80])))
    # census: a sense flip with equal totals is usually block placement (info); different totals = a missing branch
    tot_a, tot_b = collections.Counter(), collections.Counter()
    for k, n in fr.branches.items():
        tot_a[census_base(k)] += n
    for k, n in fo.branches.items():
        tot_b[census_base(k)] += n
    for k in sorted(set(fr.branches) | set(fo.branches)):
        x, y = fr.branches.get(k, 0), fo.branches.get(k, 0)
        if x != y:
            b = census_base(k)
            w = 1             # fix3: noise in every fix2 sample (block placement, tail duplication, && chains): info only
            if k.startswith("c.") and tot_a[b] != tot_b[b] and not \
                    (0 < tot_b[b] - tot_a[b] <= 2 * max(0, getattr(fr, "minmax", 0) - getattr(fo, "minmax", 0))):
                w = 2             # ... except a float compare whose sense mix changed (c.lt+bc1f vs c.le+bc1t keeps NaN
                                  # semantics apart; calib DetectNormalNearMiss's inverted tests show only here)
            out.append((w, "branch-census", None, "%s: retail %d, ours %d" % (k, x, y)))
    # flipped float compare sense with equal totals is the classic inverted condition; already above
    fa = collections.Counter(k for k, o in fr.conds)
    fb = collections.Counter(k for k, o in fo.conds)
    first = {}
    for k, o in fr.conds:
        first.setdefault(k, o)
    # fix3: excess retail keys and excess ours keys that agree up to lost values (wild_eq) pair off as noise
    exr = collections.Counter({k: fa[k] - fb[k] for k in fa if fa[k] > fb[k]})
    exo = collections.Counter({k: fb[k] - fa[k] for k in fb if fb[k] > fa[k]})
    wpair = set()
    # taskB: case-value tests on one operand X: eq(#c,X) and range tests (unsigned)(X - a) < n (sltiu: lt((X+-a),#n)).
    # MWCC folds runs of cases into ranges differently per side (CollideWithWorld 1..3, VehicleTrafficResponse 4 + 6..7 vs
    # 4..7, UpdateAttachState): when both sides' excess tests of X cover the same value set, they pair as noise.
    def case_vals(k):
        m = re.match(r"^lt\(\((.*)\+-([0-9A-F]+)\),#(\d+)\)$", k)      # offsets print in hex, constants in decimal
        if m and int(m.group(3)) <= 16:
            return m.group(1), set(range(int(m.group(2), 16), int(m.group(2), 16) + int(m.group(3))))
        m = re.match(r"^eq\((.*)\)$", k)
        if m:
            ops = split_ops(m.group(1))
            if len(ops) == 2:
                c = [o for o in ops if re.match(r"^#\d+$", o)]
                if len(c) == 1:
                    return [o for o in ops if o != c[0]][0], {int(c[0][1:])}
        return None, None
    def case_groups(ex):
        g = collections.defaultdict(list)
        for k in sorted(ex, key=str):
            if ex[k] > 0:
                X, vs = case_vals(k)
                if X is not None:
                    g[X].append((k, vs))
        return g
    gr, go = case_groups(exr), case_groups(exo)
    def same_x(a, b):
        if a == b or wild_eq("eq(#0,%s)" % a, "eq(#0,%s)" % b) or wild_eq("eq(#0,%s)" % b, "eq(#0,%s)" % a):
            return True
        for p, q in ((a, b), (b, a)):         # a merged operand phi{A|B} stands for each of its arms
            m = re.match(r"^phi\{(.*)\}$", p)
            if m and any(alt == q or wild_eq("eq(#0,%s)" % alt, "eq(#0,%s)" % q) for alt in m.group(1).split("|")):
                return True
        return False
    xs = [("r", X) for X in gr] + [("o", X) for X in go]
    cl = list(range(len(xs)))                 # union-find clusters of operands that may be the same value
    def root(i):
        while cl[i] != i:
            i = cl[i]
        return i
    for a in range(len(xs)):
        for b in range(a + 1, len(xs)):
            if same_x(xs[a][1], xs[b][1]):
                cl[root(a)] = root(b)
    for c in set(root(i) for i in range(len(xs))):
        members = [xs[i] for i in range(len(xs)) if root(i) == c]
        lr = [kv for side, X in members if side == "r" for kv in gr[X]]
        lo = [kv for side, X in members if side == "o" for kv in go[X]]
        if not lr or not lo or not any(k.startswith("lt(") for k, _ in lr + lo):
            continue              # only where a range test is involved
        sr, so = set().union(*[v for _, v in lr]), set().union(*[v for _, v in lo])
        def mask_switch(one, ex, S, R):
            # a bit-mask switch: one range test (X - min) < (max - min + 1), then (1 << (X - min)) & M (VehicleTrafficResponse
            # 0xD at 0x1B5CD4, func_0044A8F0 0x61): M's bits from min must be exactly the other side's case values
            if sum(k.startswith("lt(") for k, _ in one) != 1 or not S or not S <= R or min(S) != min(R):
                return None
            for mk in sorted(ex, key=str):
                mm = re.match(r"^!?nz\(and\(.*,#(\d+)\)\)$", mk)
                if ex[mk] > 0 and mm and {min(R) + i for i in range(32) if int(mm.group(1)) >> i & 1} == S:
                    return mk
            return None
        mk = None if sr == so else (mask_switch(lr, exr, so, sr) or mask_switch(lo, exo, sr, so))
        if mk:
            (exr if mk in exr else exo)[mk] = 0
            wpair.add(mk)
        if sr == so or mk:
            for k, _ in lr:
                exr[k] = 0
                wpair.add(k)
            for k, _ in lo:
                exo[k] = 0
                wpair.add(k)
    for kr in sorted(exr, key=str):
        for ko in sorted(exo, key=str):
            if exr[kr] and exo[ko] and kr.split("(")[0] == ko.split("(")[0] and wild_eq(kr, ko):
                n = min(exr[kr], exo[ko])
                exr[kr] -= n
                exo[ko] -= n
                wpair |= {kr, ko}
    # loop keys: the bound constants (outside the merge) each side tests anywhere; a bound only one side has stays a signal
    lb_r = set().union(*[loop_bounds(k) for k in fa]) if fa else set()
    lb_o = set().union(*[loop_bounds(k) for k in fb]) if fb else set()
    # fix3: a test of a merged pointer phi{A|B} on one side, of A and of B on the other (the compiler tail-duplicated
    # the code after the merge per arm: HandleObjectObjectCollisionEffects' lo/hi swap): pair as noise
    def phi_alts(k):
        m = re.search(r"phi\{([^{}]*)\}", k)
        if not m or "x" in split_ops(m.group(1).replace("|", ",")) or "self" in m.group(1):
            return set()
        return {k[:m.start()] + p + k[m.end():] for p in m.group(1).split("|")}
    for src, dst in ((exr, exo), (exo, exr)):
        for kp in sorted(src, key=str):
            alts = phi_alts(kp)
            hit = [ko for ko in dst if dst[ko] and ko in alts]
            if src[kp] and hit:
                src[kp] = 0
                for ko in hit:
                    dst[ko] = 0
                wpair |= {kp} | set(hit)
    mm_left = [2 * max(0, getattr(fr, "minmax", 0) - getattr(fo, "minmax", 0))]
    mv_left = [max(0, getattr(fr, "movsel", 0) - getattr(fo, "movsel", 0))]
    for k in sorted(set(fa) | set(fb), key=str):
        if fa[k] != fb[k] and k in wpair and not exr.get(k) and not exo.get(k):
            out.append((1, "cond", first.get(k), "%s: retail %d, ours %d (pairs up to lost values)" % (k, fa[k], fb[k])))
            continue
        if fa[k] != fb[k]:
            concrete = re.search(r"[#&\[]|arg:|ret\(|\df\b|phi", k) is not None and \
                not re.match(r"^\w+\((#-?\d+|-?[\d.e+-]+f)(,(#-?\d+|-?[\d.e+-]+f))?\)$", k)
            m = re.match(r"^\w+\((.*)\)$", k)
            bare = m is not None and "x" in split_ops(m.group(1))     # an unknown operand: a weaker key
            w = (2 if bare else 3) if concrete else 1
            if ("self" in k or re.search(r"phi\{[^{}]*\}", k) and not re.search(r"(arg:|&|ret\()", k)) and \
                    loop_bounds(k) <= (lb_o if fa[k] > fb[k] else lb_r):
                w = 1             # fix3: a loop counter / merged-constant key (lez((phi{#7|#8|(self+-1)}+-1))): loop
                                  # rotation and exit placement, noise in every fix2 sample
            if w > 1 and k.startswith("flt(") and fb[k] > fa[k] and mm_left[0] >= fb[k] - fa[k]:
                mm_left[0] -= fb[k] - fa[k]
                w = 1             # taskB: retail selects with min.s/max.s/abs.s where ours compares and branches
                                  # (func_0025BBC0's clamps, CB3SoundTrafficPass's abs); budget = retail's extra ops
            if w > 1 and re.match(r"^(nz|eq|lt|ltu)\(", k) and fb[k] > fa[k] and mv_left[0] >= fb[k] - fa[k]:
                mv_left[0] -= fb[k] - fa[k]
                w = 1             # taskB: retail selects with movz/movn/pminw/pmaxw where ours branches (func_0026FAA0's
                                  # timeouts, CalculateEdgePosition's min(limit, 20))
            out.append((w, "cond", first.get(k), "%s: retail %d, ours %d" % (k, fa[k], fb[k])))
    # ---- stores
    Q3.clear()
    sa_ = collections.defaultdict(set)
    sb_ = collections.defaultdict(set)
    soff = {}
    def sv(v, w):
        c = cc(v)
        if c == "x":
            return "*"
        # fix2: a byte/halfword store keeps the low bits only: sb 255 == sb -1, sb -112 == sb 144 (Update__8CB3Score)
        bits = {"1": 8, "2": 16}.get(str(w))
        m = re.match(r"^#(-?\d+)$", c) if bits else None
        if m:
            return "#%d" % (int(m.group(1)) & ((1 << bits) - 1))
        return c
    for (b, off, w, v, o) in lanes(fr.stores):
        k = store_key(b, off, w)
        sa_[k].add(sv(v, w))
        soff.setdefault(k, o)
    for (b, off, w, v, o) in lanes(fo.stores):
        sb_[store_key(b, off, w)].add(sv(v, w))
    ka_, kb_ = set(sa_), set(sb_)
    wa = collections.defaultdict(set)
    for (bk, off, w) in ka_ | kb_:
        pass
    for k in sorted(ka_ - kb_, key=str):
        same_slot = [kk for kk in kb_ - ka_ if kk[0] == k[0] and kk[1] == k[1] and kk[2] != k[2]]
        if same_slot:
            out.append((6, "store-width", soff.get(k), "store %s+%X: retail width %s, ours %s" % (k[0], k[1], k[2], same_slot[0][2])))
        elif k[0] != "*":
            # a quadword's w lane copied by retail only is usually padding: info
            # fix3: ours stores the same offset/width through a base the dataflow lost: weight 1
            out.append((1 if k in Q3 or ("*", k[1], k[2]) in kb_ else 3, "store-missing", soff.get(k), "retail stores %s to %s+%X, ours never" % (k[2], k[0], k[1])))
    for k in sorted(kb_ - ka_, key=str):
        if any(kk[0] == k[0] and kk[1] == k[1] for kk in ka_ - kb_):
            continue
        if k[0] != "*":
            out.append((1 if k in Q3 or ("*", k[1], k[2]) in ka_ else 3, "store-extra", None, "ours stores %s to %s+%X, retail never" % (k[2], k[0], k[1])))
    for k in sorted(ka_ & kb_, key=str):
        A = {x for x in sa_[k] if x != "*"}
        B = {x for x in sb_[k] if x != "*"}
        if A != B and A and B and not (A & B and len(A ^ B) == 0):
            if {_as_float(x) for x in A} == {_as_float(y) for y in B}:
                continue
            if {romfold(x) for x in A} == {romfold(y) for y in B}:
                continue          # fix3: a global's initial data vs the symbolic load of the same word
            if all(any(wild_eq(x, y) for y in B) for x in A) and all(any(wild_eq(x, y) for x in A) for y in B):
                # fix3: equal up to values the dataflow lost on one side (indexed bases, loop-carried merges)
                out.append((1, "store-value", soff.get(k), "%s+%X (%s): retail %s / ours %s (equal up to lost values)" % (
                    k[0], k[1], k[2], ",".join(sorted(A))[:80], ",".join(sorted(B))[:80])))
                continue
            if A < B and "*" in sa_[k] or B < A and "*" in sb_[k]:
                # fix3: the side with fewer values also stores an unknown one (a stack slot a call may have filled):
                # the extra values can be that one (GetRadialBlurParams: retail's lq 0x840(sp) after fabsf)
                out.append((1, "store-value", soff.get(k), "%s+%X (%s): retail %s / ours %s (+unknown on the smaller side)" % (
                    k[0], k[1], k[2], ",".join(sorted(A))[:80], ",".join(sorted(B))[:80])))
                continue
            if expand_phis(A) == expand_phis(B):
                continue          # one store of a merged value vs one store per arm
            if any(loosely_equal_c(x, y) for x in A for y in B) and len(A) == len(B) == 1:
                continue
            lit = re.compile(r"^(#-?\d+|-?[\d.e+-]+f)$")
            if k[0] == "*" and not ({x for x in A if lit.match(x)} ^ {y for y in B if lit.match(y)}):
                # fix3: an unknown store base pools every pointer store at that offset (a quad's lanes stored through
                # &e.field_20 on one side, sq 0(s0) on the other: func_003B90E0); only differing literals stay a signal
                out.append((1, "store-value", soff.get(k), "%s+%X (%s): retail %s / ours %s (unknown base)" % (
                    k[0], k[1], k[2], ",".join(sorted(A))[:80], ",".join(sorted(B))[:80])))
                continue
            out.append((4, "store-value", soff.get(k), "%s+%X (%s): retail %s / ours %s" % (
                k[0], k[1], k[2], ",".join(sorted(A))[:80], ",".join(sorted(B))[:80])))
    # ---- constants
    # fix3: a constant used on one side only is noise in every sample (fix2: folded, hoisted, re-materialised); the useful
    # signal is a NEAR miss -- a float only retail uses with a float only ours uses within 2% (0.0174533f for retail's
    # 0x3C8EFA35, 1/1609.344 off by one ulp, UV 0x3F6F vs 0x3F6E): const-near, weight 4. The rest weight 1 (info).
    def fval(k):
        try:
            return float(k[1])
        except (TypeError, ValueError):
            return None
    onlyr = [k for k in fr.consts if k[0] == "F" and fr.consts[k] and not fo.consts.get(k)]
    onlyo = [k for k in fo.consts if k[0] == "F" and fo.consts[k] and not fr.consts.get(k)]
    near = set()
    for kr in onlyr:
        for ko in onlyo:
            a_, b_ = fval(kr), fval(ko)
            if a_ is not None and b_ is not None and a_ != b_ and a_ * b_ > 0 and abs(a_ - b_) / max(abs(a_), abs(b_)) < 0.02:
                near |= {kr, ko}
                out.append((4, "const-near", None, "float %s (retail, %d uses) vs %s (ours, %d uses): a near-miss literal?" % (
                    kr[1], fr.consts[kr], ko[1], fo.consts[ko])))
    for k in sorted(set(fr.consts) | set(fo.consts), key=str):
        x, y = fr.consts.get(k, 0), fo.consts.get(k, 0)
        if (x == 0) != (y == 0) and k not in near:
            out.append((1, "const", None, "%s %s: retail %d uses, ours %d" % (
                "float" if k[0] == "F" else "int", k[1] if k[0] == "F" else ("%d (0x%X)" % (k[1], k[1] & 0xFFFFFFFF)), x, y)))
    # ---- returns
    # the return register: f0 when retail computes a float into it on some path (not a callee's leftover), else v0
    fl = any(r[1][0] not in ("U", "R", "P", "?") for r in fr.returns)
    if fl and fr.returns and all(r[0][0] == "K" for r in fr.returns):
        fl = False        # fix2: every retail path sets v0 to a constant: an int/bool function (UpdateCamera__22CB3DirectionalBlurBase)
    ra = collections.Counter(ret_key(r, fl) for r in fr.returns)
    rb = collections.Counter(ret_key(r, fl) for r in fo.returns)
    if len(fr.returns) != len(fo.returns):
        out.append((1, "return-paths", None, "paths into jr ra: retail %d, ours %d" % (len(fr.returns), len(fo.returns))))
    ca = {k for k in ra if k[0] != "*"}
    cb = {k for k in rb if k[0] != "*"}
    if ca != cb and ca and cb and not (addr is not None and ret_read(addr, "f0" if fl else "v0") is False):
        out.append((4, "return-value", None, "concrete return values: retail {%s} / ours {%s}" % (
            ",".join(sorted("%s" % (k,) for k in ca))[:100], ",".join(sorted("%s" % (k,) for k in cb))[:100])))
    return out


_jal_index = None
_STORE_OPS = ("sb", "sh", "sw", "sd", "sq", "swc1", "sdc1", "sqc2", "swl", "swr", "sdl", "sdr", "mtc1", "dmtc1", "qmtc2",
              "ctc1", "ctc2", "mtlo", "mthi", "jr", "jalr")


def ret_read(addr, reg):
    """fix2: does any retail caller read the function's return register (v0 or f0) after `jal`? None = no direct call
    site found (unknown); True/False otherwise. Straight-line scan after the delay slot: a read before any write = used;
    a branch/jump reached first counts as used (conservative)."""
    global _jal_index
    if _jal_index is None:
        _jal_index = collections.defaultdict(list)
        for p in glob.glob("assembly/asm/game/*.s") + glob.glob("assembly/asm/b3/**/*.s", recursive=True):
            ins = []
            for l in open(p, errors="replace"):
                m = re.match(r"\s*/\*[^*]*\*/\s+(\S+)\s*(.*)$", l)
                if m:
                    ins.append((m.group(1), m.group(2).split("#")[0].strip()))
                    if m.group(1) == "jal":
                        _jal_index[m.group(2).strip()].append((ins, len(ins) - 1))
    glabel_addr("__fix2_none__")
    names = [n for n, a in _glabels.items() if a == addr] + ["func_%08X" % addr]
    sites = [x for n in set(names) for x in _jal_index.get(n, [])]
    if not sites:
        return None
    rr = "$" + reg
    for ins, i in sites:
        used = True
        for op, ops in ins[i + 2:i + 14]:
            parts = [x.strip() for x in ops.split(",")]
            regs_in = [x for x in parts if rr in re.findall(r"\$\w+", x)]
            if op.startswith("b") or op in ("j", "jr", "jalr"):
                used = True if rr in ops or op != "jal" else used
                break
            if op == "jal":
                used = False
                break
            if not regs_in:
                continue
            dest = parts[0] if op not in _STORE_OPS else None
            if any(x != dest for x in regs_in) or (dest and rr in dest and "(" in dest):
                used = True
                break
            used = False      # written first
            break
        if used:
            return True
    return False


def census_base(k):
    """census kind without its sense: c.lt+bc1t/bc1f -> c.lt; beqz/bnez -> eqz; bgez/bltz -> ltz; blez/bgtz -> lez"""
    if "+bc1" in k:
        return k.split("+")[0]
    return {"beqz": "eqz", "bnez": "eqz", "beqlz": "eqz", "bnelz": "eqz", "beq": "eq", "bne": "eq", "beql": "eq",
            "bnel": "eq", "bgez": "ltz", "bltz": "ltz", "bgezl": "ltz", "bltzl": "ltz", "blez": "lez", "bgtz": "lez",
            "blezl": "lez", "bgtzl": "lez"}.get(k, k)


def loosely_equal(a, b):
    return loosely_equal_c(val_canon(a), val_canon(b))


def expand_phis(vals):
    """{phi{a|b}} -> {a, b}; {[phi{&A|&B}+N].x} -> {[&A+N].x, [&B+N].x} (load of a merge vs a merge of loads)"""
    out = set()
    for v in vals:
        m = re.match(r"^\[phi\{(.*)\}\+([0-9A-F]+)\](.*)$", v)
        if m:
            for p in m.group(1).split("|"):
                ma = re.match(r"^&([0-9A-F]+)$", p)
                if ma:      # fix3: [&A+N] is the absolute [&(A+N)] (func_0039B330)
                    out.add("[&%X]%s" % (int(ma.group(1), 16) + int(m.group(2), 16), m.group(3)))
                    continue
                out.add(("[%s+%s]%s" % (p, m.group(2), m.group(3))).replace("+0]", "]"))
            continue
        m = re.match(r"^phi\{(.*)\}$", v)
        if m:
            out |= set(m.group(1).split("|"))
            continue
        out.add(v.replace("+0]", "]"))
    return out


def _as_float(t):
    # fix2: a stored int 0 is the bits of 0.0f too (sw $zero vs swc1 of a zero register)
    return re.sub(r"#(-?\d+)\b", lambda m: fbits_str(int(m.group(1))) + "f" if abs(int(m.group(1))) > 0xFFFF else (
        "0f" if m.group(1) == "0" else m.group(0)), t)


def loop_bounds(k):
    """fix3: the integer constants of a condition key outside any phi{..} merge (lt((phi{#0|#1|(self+1)}+1),#4) -> {#4})"""
    t = k
    while True:
        u = re.sub(r"phi\{[^{}]*\}", "M", t)
        if u == t:
            break
        t = u
    return set(re.findall(r"#-?\d+", t))


def romfold(t):
    """fix3: `[&X]` (a word load of an absolute global) -> its ELF initial value, as a constant: one side reads a global
    with lwc1 (folded to its data by load()), the other with ld/lq (kept symbolic) -- SetupTable__28CB3OnScreenKeyboard"""
    def rep(m):
        raw = rom_read(int(m.group(1), 16), 4)
        return m.group(0) if raw is None else "#%d" % struct.unpack("<i", raw)[0]
    return _as_float(re.sub(r"\[&([0-9A-F]+)\]", rep, t))


def _wtok(t):
    return re.findall(r"phi\{|[\[\](){},|+]|[^\[\](){},|+]+", t)


def _wterm(toks, i):
    """end index of the balanced term starting at toks[i] (a term ends at , | + or a closing bracket at depth 0)"""
    d = 0
    j = i
    while j < len(toks):
        t = toks[j]
        if t in ("[", "(", "{", "phi{") or t.endswith("("):
            d += 1
        elif t in ("]", ")", "}"):
            if d == 0:
                return j
            d -= 1
        elif t in (",", "|", "+") and d == 0:
            return j
        j += 1
    return j


def wild_eq(a, b):
    """fix3: a and b agree except where one side has `x` / `phi` / a merge phi{..} (a value the dataflow lost: an
    indexed base, a loop-carried register) and the other a concrete term: [x+1B0] ~ [[arg:a0+14]+1B0]. Not equal when
    both are exact or a pair of different concrete atoms remains."""
    if a == b:
        return True
    A, B = _wtok(a), _wtok(b)

    def wild(t):
        return t in ("x", "phi", "self")

    def go(i, j, used):
        while i < len(A) and j < len(B):
            if A[i] == B[j] and A[i] != "phi{":
                i += 1
                j += 1
                continue
            if A[i] == "phi{" and B[j] == "phi{":
                # two merges: their inputs must agree as sets (up to lost values)
                ei, ej = _close(A, i), _close(B, j)
                pa = split_ops("".join(A[i + 1:ei - 1]).replace("|", ","))
                pb = split_ops("".join(B[j + 1:ej - 1]).replace("|", ","))
                if not (all(any(wild_eq(x, y) for y in pb) for x in pa) and all(any(wild_eq(x, y) for x in pa) for y in pb)):
                    return False
                i, j, used = ei, ej, True
                continue
            if A[i] == "phi{" and not _phi_lost(A, i) or B[j] == "phi{" and not _phi_lost(B, j):
                return False      # a merge of known values vs one value: one arm missing, not a lost value
            if wild(A[i]) or A[i] == "phi{":
                ei = _close(A, i) if A[i] == "phi{" else i + 1
                ej = _wterm(B, j)
                i, j, used = ei, ej, True
                continue
            if wild(B[j]) or B[j] == "phi{":
                ej = _close(B, j) if B[j] == "phi{" else j + 1
                ei = _wterm(A, i)
                i, j, used = ei, ej, True
                continue
            return False
        return i == len(A) and j == len(B) and used
    return go(0, 0, False)


def _phi_lost(T, i):
    """the merge at T[i] has an input the dataflow lost (x, a nested merge, a loop-carried self)"""
    return any(t in ("x", "phi", "self", "phi{") for t in T[i + 1:_close(T, i) - 1])


def _close(T, i):
    """index after the `}` closing the phi{ at T[i]"""
    d = 0
    for j in range(i, len(T)):
        if T[j] in ("[", "(", "{", "phi{") or T[j].endswith("("):
            d += 1
        elif T[j] in ("]", ")", "}"):
            d -= 1
            if d == 0:
                return j + 1
    return len(T)


def idx_fold_eq(a, b):
    """fix3: an indexed global whose constant part of the index the compiler folded into the base on one side:
    retail [x+1EA4470] (x = (i + 0x76) * 4) vs ours [x+1EA4648] (D_01EA4470[i + 0x76], 0x76 * 4 folded). Absolute
    addresses (>= 0x100000) on an index term x (or a known #0 index), within 0x400 of each other."""
    pat = r"(?<![\w+])(x|#0)\+([0-9A-F]{6,8})\b"
    fa_, fb_ = re.findall(pat, a), re.findall(pat, b)
    if not fa_ or len(fa_) != len(fb_):
        return False
    for (_, ha), (_, hb) in zip(fa_, fb_):
        na, nb = int(ha, 16), int(hb, 16)
        if na < 0x100000 or nb < 0x100000 or abs(na - nb) > 0x400:
            return False
    return re.sub(pat, "x+G", a) == re.sub(pat, "x+G", b)


def phi_contains(p, q):
    """fix2: q (a single source) is one input of the merge p, or q is itself a merge sharing an input with p"""
    m = re.match(r"^phi\{(.*)\}$", p)
    if not m:
        return False
    parts = set(split_ops(m.group(1).replace("|", ",")))
    mq = re.match(r"^phi\{(.*)\}$", q)
    if mq:
        return bool(parts & set(split_ops(mq.group(1).replace("|", ","))))
    return q in parts


def loosely_equal_c(x, y):
    if x != y and _as_float(x) == _as_float(y):
        return True               # an int store/argument of a float's bits (lui/ori) vs the float itself
    for p, q in ((x, y), (y, x)):
        # a loop-carried merge whose other inputs only re-read through the merge itself: phi{V|[phi+N]} ~ V
        m = re.match(r"^phi\{(.*)\}$", p)
        if m:
            parts = split_ops(m.group(1).replace("|", ","))
            if q in parts and all(pp == q or "phi" in pp or "self" in pp for pp in parts):
                return True
    # an unresolved local of ours (LOCAL) matches any retail absolute address
    if "LOCAL" in x or "LOCAL" in y:
        pat = r"&LOCAL(\+[0-9A-F]+)?|&[0-9A-F]+"
        return re.sub(pat, "&G", x) == re.sub(pat, "&G", y)
    # stack loads after a callee filled them: both "stack"
    return False


def fcmp_key(c):
    op, a, b, o = c
    ca = val_canon(a) if strength(a) == 2 and a[0] in ("K", "F") else "x"
    cb = val_canon(b) if strength(b) == 2 and b[0] in ("K", "F") else "x"
    return "%s(%s,%s)" % (op.replace(".s", ""), ca, cb)


CALLEE_SAVED = {"s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7", "fp", "f20", "f21", "f22", "f23", "f24", "f25", "f26",
                "f27", "f28", "f29", "f30", "f31"}


def ret_key(r, fl=False):
    v0, f0, off = r
    v = f0 if fl else v0
    if v[0] == "P" and v[1] in CALLEE_SAVED:
        return ("*",)
    if v[0] in ("K", "F", "P"):
        return (val_canon(v),)
    return ("*",)


# ---------------------------------------------------------------- arity from retail call sites

def _cw_type(s, i):
    """one CodeWarrior-mangled parameter type at s[i] -> (kind, next index); kind 'i' (GPR), 'f' (FPR), 'e'
    (ellipsis), None when unsure"""
    ptr = False
    while i < len(s) and s[i] in "CVUS":
        i += 1
    while i < len(s) and s[i] in "PR":
        ptr = True
        i += 1
        while i < len(s) and s[i] in "CVUS":
            i += 1
    if i >= len(s):
        return None, i
    c = s[i]
    if c.isdigit():
        m = re.match(r"\d+", s[i:])
        return "i", i + len(m.group(0)) + int(m.group(0))
    if c == "Q":
        if i + 1 >= len(s) or not s[i + 1].isdigit():
            return None, i
        n, i = int(s[i + 1]), i + 2
        for _ in range(n):
            m = re.match(r"\d+", s[i:])
            if not m:
                return None, i
            i += len(m.group(0)) + int(m.group(0))
        return "i", i
    if c == "F":          # function pointer PF<params>_<ret>
        if not ptr:
            return None, i
        i += 1
        while i < len(s) and s[i] != "_":
            k, i = _cw_type(s, i)
            if k is None:
                return None, i
        k, i = _cw_type(s, i + 1)
        return ("i" if k is not None else None), i
    if c == "A":
        m = re.match(r"A\d+_", s[i:])
        if not m:
            return None, i
        k, i = _cw_type(s, i + len(m.group(0)))
        return "i", i
    if c == "e":
        return "e", i + 1
    if c in "fd":
        return ("i" if ptr else "f"), i + 1
    if c in "vbcsilxw":
        return "i", i + 1
    return None, i


def mangled_regs(name):
    """argument registers a CodeWarrior-mangled function can take (`this` assumed for members: an upper bound), or None"""
    p = None
    for mm in re.finditer(r"__(?=[\dQF])", name):
        if mm.start() == 0:
            continue
        i = mm.end()
        member = name[i] != "F"
        if member:
            k, i = _cw_type(name, i)          # the class: <len><name> or Q<n>...
            if k != "i":
                continue
        if name[i:i + 1] == "C":
            i += 1
        if name[i:i + 1] == "F":
            p = name[i + 1:]
            break
    if p is None:
        return None
    types, i = [], 0
    while i < len(p):
        if p[i] == "_":
            break
        if p[i] in "TN":
            mm = re.match(r"T(\d)|N(\d)(\d)", p[i:])
            if not mm:
                return None
            cnt = 1 if mm.group(1) else int(mm.group(2))
            idx = int(mm.group(1) or mm.group(3)) - 1
            if idx >= len(types):
                return None
            types += [types[idx]] * cnt
            i += len(mm.group(0))
            continue
        k, j = _cw_type(p, i)
        if k is None or k == "e":
            return None
        types.append(k)
        i = j
    if p.startswith("v") and len(types) == 1:
        types = []
    ni = (1 if member else 0) + sum(1 for k in types if k == "i")
    nf = sum(1 for k in types if k == "f")
    return set(ARGI[:ni]) | set(ARGF[:nf])


def arity_from(recs):
    """callee key -> set of argument registers set at EVERY retail call site seen (≥1 site)."""
    cnt = collections.defaultdict(lambda: collections.defaultdict(lambda: [0, 0]))
    for rec in recs:
        for c in rec.calls:
            for r in ARGI + ARGF:
                v = c["args"][r]
                if v == U:
                    cnt[c["key"]][r][1] += 1
                elif not (v[0] == "P" and v[1] == r):
                    cnt[c["key"]][r][0] += 1      # written before the call (an untouched incoming reg is no evidence)
    out = {}
    for k, regs in cnt.items():
        if k in ("11E328", "11E340", "11E370"):
            # fix2: retail's acosf/asinf/logf wrappers (`j __ieee754_<f>`) take f12 only (a stale a0 is not an argument)
            out[k] = {r: ("arg" if r == "f12" else "no") for r in ARGI + ARGF}
            continue
        d = {r: ("no" if u else ("arg" if w else "unk")) for r, (w, u) in regs.items()}
        mr = None
        if re.match(r"^[0-9A-F]+$", k):
            mr = live_in(int(k, 16))       # the callee's own retail code: what it reads before writing
            mm = mangled_regs(callee_disp(k))
            if mr is not None and mm is not None:
                mr = mr & mm                 # the mangled list bounds it (forwarding into library code over-reads)
                out[k] = {r: ("arg" if r in mr else "no") for r in ARGI + ARGF}
                continue
        if mr is None and not k.startswith("vcall"):
            mr = mangled_regs(callee_disp(k))
        if mr is not None:
            for r in d:
                if r not in mr:
                    d[r] = "no"
        out[k] = d
    return out


# ---------------------------------------------------------------- driver

OUT = "build/vt/audit1"
FLAG = 4          # a function is reported when its findings (weight >= 2) add up to this


def compile_src(src, obj):
    subprocess.run(["timeout", "180", "bash", "tools/tiny_compile.sh", src, obj], capture_output=True)
    return os.path.exists(obj)


def func_syms(objpath):
    o = Obj(objpath)
    out = []
    for name, (shn, val, size) in o.syms.items():
        if o.secname[shn].startswith(".text") and size:
            out.append(name)
    return out


def alias_local_statics(ri, oi):
    """taskB: a proven unit's function-local statics (`lnRotate$5`, retargeted onto retail's .sbss/.sdata labels at
    link time by tools/sdata_retarget.py) take the retail symbol the same instruction names (byte-identical code, so the
    instruction lists align; PresentDrawBuffer's lnRotate = D_004E294C)"""
    for a, b in zip(ri, oi):
        if a.op != b.op or len(a.ops) != len(b.ops):
            continue
        for k, (x, y) in enumerate(zip(a.ops, b.ops)):
            if x[0] != y[0] or x[0] not in ("m", "i"):
                continue
            j = 3 if x[0] == "m" else 2
            if len(x) <= j or len(y) <= j or not x[j] or not y[j]:
                continue
            if "$" in y[j][1] and x[j][0] == y[j][0] and sym_addr(x[j][1]) is not None:
                b.ops[k] = y[:j] + ((y[j][0], x[j][1], y[j][2]),) + y[j + 1:]


def audit_one(job):
    """job = (tag, src, [(sym, retail .s path)]) -> (tag, results) where results = [(sym, base, findings, err)]"""
    tag, src, funcs, outdir = job
    obj = os.path.join(outdir, "obj", "%s.o" % re.sub(r"[^\w]", "_", tag)[:120])
    if os.path.exists(obj):
        os.remove(obj)
    if not compile_src(src, obj):
        return tag, [(f[0], None, None, "compile failed") for f in funcs], {}, {}
    res = []
    recs = {}
    try:
        ob = Obj(obj)
        if funcs and funcs[0][0] == "*ALL*":
            # a matched unit: every function of our object against retail's bytes at the same offset
            _, spath, vr = funcs[0]
            texts = [i for i, n in enumerate(ob.secname) if n.startswith(".text")]
            funcs = []
            for name, (shn, val, size) in sorted(ob.syms.items(), key=lambda kv: kv[1][1]):
                if size and shn in texts and len(texts) == 1:
                    funcs.append((name, spath, (vr + val, vr + val + size)))
        for f in funcs:
            sym, spath = f[0], f[1]
            rng = f[2] if len(f) > 2 else None
            set_randomiser_alias(spath)
            ri, base = parse_retail(spath, sym, rng)
            oi, _ = parse_ours(obj, sym)
            if ri and not oi:          # draftAO: defined under another symbol (N104 renames): the object's one function
                _one = func_syms(obj)
                if len(_one) == 1:
                    oi, _ = parse_ours(obj, _one[0])
            if not ri or not oi:
                res.append((sym, base, None, "no code (retail %d / ours %d)" % (len(ri), len(oi))))
                continue
            if rng is not None and len(ri) == len(oi):
                alias_local_statics(ri, oi)
            fr = analyse(ri, Ctx("retail"))
            fo = analyse(oi, Ctx("ours", ob))
            fo.local_defs = set(ob.syms)      # fix2: symbols our object defines (static helpers, out-of-line inlines)
            recs[sym] = (fr, fo)
            res.append((sym, base, None, None))
    except Exception as e:  # noqa
        import traceback
        res.append(("?", None, None, "analysis error: %s" % traceback.format_exc()[-300:]))
    try:
        os.remove(obj)
    except OSError:
        pass
    for fr, fo in recs.values():
        fr.names = fo.names = None
    return tag, res, recs, dict(_names)


TRACK = {}


def archive_jobs(only, outdir, pattern="src/nonmatching/*.cpp"):
    jobs = []
    for path in sorted(glob.glob(pattern)):
        h = open(path, errors="replace").readline()
        m = re.match(r"// NONMATCHING: (\S+) -- ", h)
        if not m:
            continue
        name = m.group(1)
        if only and not any(o in path or o in name for o in only):
            continue
        unit = tiny_batch.where(name)
        if not unit:
            # gaps1: the .init static initialisers sit in dict-form yaml units tiny_batch.where() does not list
            glabel_addr("")
            gp = _gpath.get(name, "")
            if gp.startswith("assembly/asm/game/") and os.path.exists(gp):
                unit = gp[len("assembly/asm/"):-2]
        if not unit:
            continue
        jobs.append((name, path, [(name, "assembly/asm/%s.s" % unit)], outdir))
        TRACK[path] = (re.search(r"^// TRACK: (\w+)", open(path, errors="replace").read(), re.M) or [0, "?"])[1]
    return jobs


def matched_jobs(n, outdir, only):
    import random
    rows = []
    for l in open("config/proven_units.txt"):
        if l.startswith("#"):
            continue
        p = l.strip().split(",")
        if len(p) >= 5 and p[4].startswith("src/b3/") and os.path.exists(p[4]):
            s = "assembly/asm/" + p[4][len("src/"):-4] + ".s"
            if os.path.exists(s):
                rows.append((p[3], p[4], s))
    rows = sorted(set(rows))
    if only:
        rows = [r for r in rows if any(o in r[1] for o in only)]
    random.Random(1).shuffle(rows)
    jobs = []
    vram = {}
    for l in open("config/proven_units.txt"):
        p = l.strip().split(",")
        if len(p) >= 5 and not l.startswith("#"):
            vram[p[4]] = int(p[0], 16)
    for unit, src, s in rows[:n]:
        jobs.append((unit, src, [("*ALL*", s, vram[src])], outdir))
    return jobs


VERIFIED_FP = os.path.join(os.path.dirname(os.path.abspath(__file__)), "behaviour_audit_fp.tsv")
_vfp = None


def apply_verified_fp(sym, fs):
    """fix3: findings checked by hand against retail and found equal (tools/behaviour_audit_fp.tsv: symbol, category,
    detail regex, note) drop to weight 0 with the note. Only for the real archives (never --matched / --glob calib)."""
    global _vfp
    if _vfp is None:
        _vfp = collections.defaultdict(list)
        if os.path.exists(VERIFIED_FP):
            for ln in open(VERIFIED_FP):
                if ln.startswith("#") or not ln.strip():
                    continue
                p = ln.rstrip("\n").split("\t")
                if len(p) >= 4:
                    _vfp[p[0]].append((p[1], re.compile(p[2]), p[3]))
    rules = _vfp.get(sym)
    if not rules:
        return fs
    out = []
    for sc, cat, off, det in fs:
        for c, rx, note in rules:
            if sc >= 2 and c == cat and rx.search(det):
                sc, det = 0, det + " [verified FP: %s]" % note
                break
        out.append((sc, cat, off, det))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=12)
    ap.add_argument("--only", nargs="*")
    ap.add_argument("--matched", type=int)
    ap.add_argument("--out", default=OUT)
    ap.add_argument("--file")
    ap.add_argument("--glob", default="src/nonmatching/*.cpp", help="archive sources (e.g. a calibration copy)")
    ap.add_argument("--sym")
    ap.add_argument("--tag", default="", help="suffix for the report files")
    ap.add_argument("--show", action="store_true", help="print every finding")
    a = ap.parse_args()
    outdir = a.out
    os.makedirs(os.path.join(outdir, "obj"), exist_ok=True)
    if a.file:
        unit = tiny_batch.where(a.sym)
        jobs = [(a.sym, a.file, [(a.sym, "assembly/asm/%s.s" % unit)], outdir)]
    elif a.matched:
        jobs = matched_jobs(a.matched, outdir, a.only)
    else:
        jobs = archive_jobs(a.only, outdir, a.glob)
    print("auditing %d sources (%d functions), %d jobs" % (len(jobs), sum(len(j[2]) for j in jobs), a.jobs), flush=True)
    glabel_addr("")         # build the glabel index once, before the workers fork
    with cf.ProcessPoolExecutor(a.jobs) as ex:
        results = list(ex.map(audit_one, jobs, chunksize=1))
    # arity: retail call sites of every analysed function (retail side only)
    for r in results:
        _names.update(r[3])
    results = [r[:3] for r in results]
    arity = arity_from([fr for _, _, recs in results for (fr, fo) in recs.values()])
    rows, errs = [], []
    per = {}
    for (tag, res, recs), job in zip(results, jobs):
        for sym, base, _, err in res:
            if err:
                errs.append((job[1], sym, err))
                continue
            fr, fo = recs[sym]
            fs = compare(fr, fo, arity, base)
            if not a.matched and a.glob == "src/nonmatching/*.cpp":
                fs = apply_verified_fp(sym, fs)
            per[(job[1], sym)] = (base, fs)
            for sc, cat, off, det in fs:
                rows.append((os.path.basename(job[1]), sym, "%08X" % (base + off) if (base is not None and off is not None) else (
                    "%08X" % base if base is not None else "?"), sc, cat, det))
    suffix = "_matched" if a.matched else ("_" + a.tag if a.tag else "")
    tsv = os.path.join(outdir, "report%s.tsv" % suffix)
    with open(tsv, "w") as f:
        f.write("archive\tsymbol\tretail_addr\tscore\tcategory\tdetail\ttrack\n")
        for r in sorted(rows, key=lambda r: (-sum(x[3] for x in rows if x[1] == r[1]) if False else 0, r[1], -r[3])):
            f.write("%s\t%s\t%s\t%d\t%s\t%s\t%s\n" % (r + (TRACK.get("src/nonmatching/" + r[0], ""),)))
    tot = {k: sum(f[0] for f in v[1] if f[0] >= 2) for k, v in per.items()}     # weight 1 = info only
    tot = {k: (t if t >= FLAG else 0) for k, t in tot.items()}                   # below FLAG: noise level
    ranked = sorted(tot.items(), key=lambda kv: -kv[1])
    cats = collections.Counter(r[4] for r in rows)
    lines = ["behaviour_audit: %d functions analysed, %d with findings, %d errors" % (
        len(per), sum(1 for v in tot.values() if v), len(errs)),
        "categories: " + ", ".join("%s %d" % kv for kv in cats.most_common())]
    for (src, sym), t in ranked:
        if t == 0:
            continue
        base, fs = per[(src, sym)]
        lines.append("%4d  %s  @%08X  [%s]" % (t, sym[:90], base or 0, TRACK.get(src, "?")))
        for sc, cat, off, det in sorted(fs, key=lambda f: -f[0])[: (99 if a.show else 6)]:
            lines.append("        %d %-14s %s %s" % (sc, cat, ("@%08X" % (base + off)) if off is not None else "         ", det[:150]))
    for e in errs:
        lines.append("ERROR %s %s: %s" % e)
    sumf = os.path.join(outdir, "summary%s.txt" % suffix)
    open(sumf, "w").write("\n".join(lines) + "\n")
    print("\n".join(lines[:60]))
    print("... full: %s, %s" % (tsv, sumf))



def dump(src, sym):
    """debug: print both sides' features for one function"""
    os.makedirs(OUT + "/obj", exist_ok=True)
    obj = OUT + "/obj/dump.o"
    compile_src(src, obj)
    unit = tiny_batch.where(sym)
    spath = "assembly/asm/%s.s" % unit if unit else src.replace("src/", "assembly/asm/")[:-4] + ".s"
    set_randomiser_alias(spath)
    ri, base = parse_retail(spath, sym)
    oi, _ = parse_ours(obj, sym)
    for side, ins, ctx in (("RETAIL", ri, Ctx("retail")), ("OURS", oi, Ctx("ours", Obj(obj)))):
        r = analyse(ins, ctx)
        print("==", side, len(ins))
        for c in r.calls:
            print("  call %x %s  %s" % (c["off"], callee_disp(c["key"]), " ".join(
                "%s=%s" % (k, val_canon(v)[:50]) for k, v in c["args"].items() if v != U and not (v[0] == "P" and v[1] == k))))
        for s in r.stores:
            print("  store %x %s" % (s[4], (store_key(s[0], s[1], s[2]), val_canon(s[3])[:80])))
        print("  branches", dict(r.branches))
        print("  fcmps", [fcmp_key(c) for c in r.fcmps])
        print("  consts", dict(r.consts))
        print("  returns", [(val_canon(a), val_canon(b), "%x" % o) for a, b, o in r.returns])


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--dump":
        dump(sys.argv[2], sys.argv[3])
    else:
        main()
