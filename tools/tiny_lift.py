#!/usr/bin/env python3
"""Straight-line lifter for tools/tiny_batch.py: a label-free function's instructions -> C/C++ (kind "lift").

The function is executed symbolically: registers hold expressions over the incoming parameters, constants, globals,
loads and call results; stores and calls become statements in program order (a load still needed after a later
store or call is bound to a local first). Prologue/epilogue saves of ra/s-registers are ignored; any other stack
access, branch, VU/128-bit operation or unknown instruction skips the function. Objects reached through a pointer
(a0 = `self`, other pointer parameters, globals, loaded pointers, call results) get placeholder structs whose
fields come from the access offsets and widths (all types [G]). Callees are declared as in tools/tiny_gen.py:
func_XXXXXXXX extern "C" with the arguments passed; a named method of a header-less class as a local class member;
anything else through its link name. Globals keep their asm symbol; an absolutely-addressed one is declared at
least 0x10 bytes so MWCC does not pick gp-relative addressing for it (N50).

generate(c, has_header) -> ((text, unit), None) or (None, reason)
"""
import ast
import os, re, sys
DIAG = bool(os.environ.get("LIFT_DIAG"))
NPATHS_MAX = 64
NPATHS_MAX_UNROT = 64    # lift2: tried 256 -- the extra functions came out 3-6x retail size (shared regions duplicated): kept at 64
# vlift (2026-10-26): VU0 values the lifter models. VVAL: whole-vector expressions emitted as GtMathPs2 calls
# (field reads, operator-/+/unary -, scale by a float, CrossProduct, TransformPoint); VANY: anything a VU register or a
# GPR round trip can hold.
VVAL = ("vmem", "vneg", "vsubv", "vaddv", "vscale", "vcross", "vxform", "v4scale", "v4mul", "v4sub", "vloc",
        "vlerp4", "vlerp3")   # lift3: Interpolate(CGtV4d/CGtV3d)
V4OPS = ("v4scale", "v4mul", "v4sub", "vlerp4")    # CGtV4d operator*(float) / operator*(CGtV4d) / operator-(CGtV4d) / Interpolate
VANY = VVAL + ("vset", "vone", "vsq", "vprod", "vdot", "vgpr", "vnorm", "vzero", "vlen")   # lift3: vlen


def hdr_has(api):
    """lift3: include/b3/GtMathPs2.h declares `api` (a member the lifter may only emit once the header has it). The
    environment variable LIFT3_HDR (comma list) adds APIs for header experiments (build/vt/lift3/inc)."""
    global _HDR_TEXT
    if _HDR_TEXT is None:
        try:
            _HDR_TEXT = open(os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "include", "b3",
                                          "GtMathPs2.h"), errors="replace").read()
        except OSError:
            _HDR_TEXT = ""
    return api in os.environ.get("LIFT3_HDR", "").split(",") or re.search(r"\b%s\s*\(" % re.escape(api), _HDR_TEXT) is not None


_HDR_TEXT = None
# NPATHS_MAX: conditional branches walked (shared regions count again): a guard against duplication blow-up

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from cwdemangle import demangle  # noqa: E402
import tiny_gen  # noqa: E402
import callee_sig  # noqa: E402
from tiny_gen import Skip, ptype as _ptype, parse_method, split_params  # noqa: E402


def ptype(t):
    """tiny_gen.ptype, plus pointers to a type qualified by one scope (`DirtySock::LobbyApiRefT*`), which are
    declared `namespace NS { class T; }` -- [G]: the mangling (Q2..) is the same for a class scope."""
    core = t.replace("const", "").replace("*", "").replace("&", "").strip()
    if core == SPACE and (t.endswith("&") or t.count("*") == 1):
        return core, True, t.endswith("&"), False      # lift3: Gt2dObject.h's type, by reference / pointer
    m = re.fullmatch(r"([A-Za-z_]\w*)::([A-Za-z_]\w*)", core)
    if m and "*" in t and not t.endswith("&") and m.group(1) != "GtMathPs2":
        return core, True, False, False
    if core in VECT and "*" not in t and "&" not in t:
        return core, False, False, False
    return _ptype(t)


# lift3: CGt2dObject::CGt2dObjectSpace (E map; include/b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h declares it with
# Revenge member names [L]): a parameter of that type is used through the header -- its fields by member name, no local
# struct. Offsets [C] from the header's layout (CGtV2d mTopLeftPos +0, CGtV2d mSize +8, CGtV4d mColour +0x10).
SPACE = "CGt2dObject::CGt2dObjectSpace"
G2D_HDR = "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
SPACE_MEMBERS = {0: "mTopLeftPos.marValues[0]", 4: "mTopLeftPos.marValues[1]", 8: "mSize.marValues[0]",
                 0xC: "mSize.marValues[1]", 0x14: "mColour.f[1]", 0x18: "mColour.f[2]", 0x1C: "mColour.f[3]"}
# types Gt2dObject.h defines: a draft that includes it must not define them itself (Gt2dRenderer is a namespace there)
G2D_DEFINED = ("CGt2dObject", "CGt2dObjectBox", "CGt2dObjectImage", "UnkStruct_Gt2dObject_20")

# GtMathPs2 vector classes passed by value: the caller copies the 128-bit value into a stack temporary and passes
# its address; `CGtV3d t; t.mData = src; f(t)` gives retail's lq/sq + addiu (func_00284D00) [C]
VECT = ("GtMathPs2::CGtV3d", "GtMathPs2::CGtV4d")
# types include/b3/GtMathPs2.h defines (usable through pointers / references)
GTMATH_TYPES = ("GtMathPs2::CGtV2d", "GtMathPs2::CGtV3d", "GtMathPs2::CGtV4d", "GtMathPs2::CGtMatrix2x3",
                "GtMathPs2::CGtMatrix3x4")

GPR = ["a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3"]
STK = ["st%d" % _k for _k in range(8)]   # integer parameters 9.. (the caller's argument area, 8 bytes each)
GPRX = GPR + STK
FPR = ["f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19"]
CALLER_SAVED = {"v0", "v1", "at", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9"} | \
    {"f%d" % i for i in range(20)}
LOADT = {"lw": "int", "lh": "short", "lhu": "unsigned short", "lb": "signed char", "lbu": "unsigned char", "lwc1": "float",
         "ld": "unsigned long", "lq": "u_long128"}
STORET = {"sw": "int", "sh": "short", "sb": "unsigned char", "swc1": "float", "sd": "unsigned long", "sq": "u_long128"}
PUNS = {"int", "float", "short", "unsigned short", "signed char", "unsigned char"}
SIZE = {"int": 4, "short": 2, "unsigned short": 2, "signed char": 1, "unsigned char": 1, "float": 4, "unsigned long": 8,
        "bool": 1, "void *": 4, "u_long128": 16}
NUM = r"(-?0x[0-9A-Fa-f]+|-?\d+)"
BINOPS = {"addu": "+", "daddu": "+", "subu": "-", "dsubu": "-", "and": "&", "or": "|", "xor": "^",
          "slt": "<", "sltu": "<u", "sllv": "<<", "srlv": ">>u", "srav": ">>"}
IMMOPS = {"addiu": "+", "daddiu": "+", "andi": "&", "ori": "|", "xori": "^", "slti": "<", "sltiu": "<u",
          "sll": "<<", "srl": ">>u", "sra": ">>"}
FOPS = {"add.s": "+", "sub.s": "-", "mul.s": "*", "div.s": "/"}
# conditional branches (not the likely forms: their delay slot runs only when taken)
REGTOK = re.compile(r"\b(v[01]|a[0-3]|t[0-9]|s[0-7]|fp|ra|at|f[0-9]+)\b")
STOREM = {"sw", "sh", "sb", "sd", "swc1", "sq"}


LIT4_LO, LIT4_HI = 0x4E0680, 0x4E1400       # retail's .lit4 pool (config/b3_retail.yaml: [0x3E0680, sdata, lit4])
_ROM = None


def lit4_bits(root, off):
    """The 32-bit value of a .lit4 pool entry read as `D_XXXXXXXX` + off, or None (patch_lit4.py)."""
    global _ROM
    if root[0] != "g" or off != 0 or not re.fullmatch(r"D_[0-9A-F]{8}", root[1]):
        return None
    a = int(root[1][2:], 16)
    if not LIT4_LO <= a < LIT4_HI:
        return None
    if _ROM is None:
        p = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "orig", "SLUS_210.50.rom")
        if not os.path.exists(p):
            p = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(
                os.path.abspath(__file__))))), "orig", "SLUS_210.50.rom")
        try:
            _ROM = open(p, "rb").read()
        except OSError as e:
            raise Skip("retail ROM not readable (%s)" % e)      # skip this function, not the whole batch
    o = a - 0x100000
    return int.from_bytes(_ROM[o:o + 4], "little")


def rw(m, a):
    """Static (reads, writes) register sets of one instruction (loop analysis)."""
    toks = REGTOK.findall(a)
    if m in STOREM:
        return set(toks), set()
    if m in ("jal", "jalr"):
        return set(), set(CALLER_SAVED)
    if m in ("j", "b", "jr", "nop", "label"):
        return set(toks), set()
    if m == "mtc1":
        return set(toks[:1]), set(toks[1:2])
    if m.startswith("c.") and m.endswith(".s"):
        return set(toks), {"fcc"}
    if m in ("bc1t", "bc1f"):
        return {"fcc"}, set()
    if m in CONDBR or m.startswith("b"):
        return set(toks), set()
    if not toks:
        return set(), set()
    return set(toks[1:]), {toks[0]}


MIRROR = {"<": ">", ">": "<", "<=": ">=", ">=": "<=", "<u": ">u", ">=u": "<=u", "==": "==", "!=": "!=",
          "f<": "f>", "f<=": "f>="}
CONDBR = {"beqz", "bnez", "beq", "bne", "blez", "bgtz", "bltz", "bgez", "bc1t", "bc1f"}
NEG = {"==": "!=", "!=": "==", "<": ">=", ">=": "<", "<=": ">", ">": "<=", "<u": ">=u", ">=u": "<u"}
FCMP = {"c.eq.s": "f==", "c.lt.s": "f<", "c.le.s": "f<="}
# C library callees: their standard prototypes (C linkage; size_t is 32-bit here)
LIBC = {"memset": ("void *", ["void *", "int", "unsigned int"]),
        "memcpy": ("void *", ["void *", "const void *", "unsigned int"]),
        "memmove": ("void *", ["void *", "const void *", "unsigned int"]),
        "memcmp": ("int", ["const void *", "const void *", "unsigned int"]),
        "strcpy": ("char *", ["char *", "const char *"]),
        "strncpy": ("char *", ["char *", "const char *", "unsigned int"]),
        "strcat": ("char *", ["char *", "const char *"]),
        "strlen": ("unsigned int", ["const char *"]),
        "strcmp": ("int", ["const char *", "const char *"]),
        "strncmp": ("int", ["const char *", "const char *", "unsigned int"])}


class CDict(dict):
    """A dict keyed by repr strings, canonicalized through the owner's load aliases (typed: also through its
    re-load aliases, for keys standing for a type)."""
    def __init__(self, owner, typed=False):
        super().__init__()
        self.o = owner
        self.c = owner.ckt if typed else owner.ck

    def __getitem__(self, k):
        return super().__getitem__(self.c(k))

    def __setitem__(self, k, v):
        super().__setitem__(self.c(k), v)

    def __contains__(self, k):
        return super().__contains__(self.c(k))

    def get(self, k, d=None):
        return super().get(self.c(k), d)

    def setdefault(self, k, d=None):
        return super().setdefault(self.c(k), d)


class CSet(set):
    def __init__(self, owner):
        super().__init__()
        self.o = owner

    def add(self, k):
        super().add(self.o.ck(k))

    def __contains__(self, k):
        return super().__contains__(self.o.ck(k))


def num(s):
    return int(s, 0)


def sofs(n):
    """A signed byte offset for `base + off` text: `+ 0x60` / `- 0x60` (Python's %X of a negative gives `0x-60`)."""
    return "- 0x%X" % -n if n < 0 else "+ 0x%X" % n


class Lift:
    def __init__(self, c, has_header):
        self.c, self.has_header = c, has_header
        self.named = not c["name"].startswith("func_")
        self.addr = c["addr"]
        self.R = {}
        for r in GPR + FPR:
            self.R[r] = ("p", r)
        self.R["zero"] = ("k", 0)
        self.stmts = []           # strings or ("load", key) placeholders resolved at the end
        self.epoch = 0
        self.loads = {}           # key -> {"slot", "epoch", "temp", "type", "expr"}
        self.alias = {}           # repr(("l", k)) -> repr(("l", first load of the same field))
        self.talias = {}          # repr(("l", k)) -> repr(("l", first load)) for a re-load: the same type only
        self.objs = CDict(self, typed=True)   # root key -> {"fields": {off: type}, "kind", "name", "mode"}
        self.calls = []           # [{"target", "args", "ret": None|"int"|"float"|ptr, "slot", "temp"}]
        self.used_params = set()
        self.ptr_roots = CSet(self)
        self.ret = None
        self.globals_mode = {}
        self.smembers = {}         # mangled static data member -> (class, member)
        self.frame, self.locbase, self.locsize = None, None, 0
        self.scopes = set()        # namespaces declared for qualified parameter types
        self.decls = []           # extra declarations (callees)
        self.fwd = []
        self.classes = {}         # local class declarations from named callees: name -> [method sigs]
        self.class_order = []
        self.tmpn = 0
        self.param_types = {}     # reg -> type (func_ callers)
        self.const_param = False
        self.typing = False
        self.static = False
        self.used_tail_if = False  # an early-return form was chosen (variant bit 0 writes the block form instead)
        self.used_dret = False     # a final value-returning if/else was written in a variant form
        self.used_loop = False     # a for loop was written (variant (v // 6) % 2: a do-while)
        self.used_pvar = False     # path mode grouped ifs into a switch / an || (variant (v // 12) % 3)
        self.used_fuse = False     # a float product feeds an add/sub (variant (v // 192) % 2: product as a local)
        self.used_extra = False    # a call passes registers past its signature (variant (v // 384) % 2: dropped)
        self.qparams = set()       # parameter registers stored with sq (128-bit values)
        self.dparams = set()       # parameter registers stored with sd (64-bit values)
        self.nparams = {}          # parameter registers passed unconverted to a narrow parameter -> that type
        self.used_mvorder = False  # two or more loop variables declared (variant (v // 768) % 2: reversed)
        self.used_liveout = False  # v0/f0 live out of a loop made a loop variable (variant (v // 1536) % 2: not)
        self.used_phiorder = False # two or more merged variables set in a branch (variant (v // 3072) % 2: reversed)
        self.used_ucbool = False   # an extern "C" callee with a bool parameter (variant (v // 6144) % 2: unsigned char)
        self.used_voidret = False  # the return value was also stored/passed (variant (v // 12288) % 2: void)
        self.used_mirror = False   # a comparison of two values (variant (v // 24576) % 2: written mirrored)
        self.used_offby1 = False   # a comparison with a constant (variant (v // 49152) % 2: the bound one off)
        self.used_reload = False   # a field re-loaded after a store/call (variant (v // 98304) % 2: one variable)
        self.vtemps = set()        # stack offsets of by-value vector argument copies
        self.v4tmp = {}            # stack offset -> lane values of a CGtV4d(x, y, z, w) being built
        self.vt_ctor = {}          # vector temporary offset -> the constructor arguments it was copied from
        self.outargs = set()       # stack offsets of the outgoing argument area (arguments 9+)
        self.used_pun = False      # a field accessed as two scalar types
        self.preg_types = {}       # argument register -> declared parameter type (set by run for named functions)
        self.used_static = False   # a callee taken as static because `this` would be an integer
        self.used_wide = False     # a narrow argument to a placeholder callee (variant 1572864: an int parameter)
        self.used_elptr = False    # a read-modify-write of a[i].f (variant 3145728: through an element pointer)
        self.n_elptr = 0
        self.used_ifswap = False   # an if/else (variant 805306368: negated, branches swapped)
        self.used_pullin = False   # an if ending in a return before a returning rest (variant 1610612736)
        self.used_eaddr = False    # an element address &a[i] as a value (variant 402653184: an element pointer local)
        self.eaddr = {}
        self.used_bphi = False     # a merged 0 / 1 argument (variant 6291456: a bool)
        self.boolphis = set()
        self.used_swret = False    # a switch whose every path returns (variant 12582912: one return after it)
        self.used_kret = False     # a constant v0 beside a float f0 (variant 25165824: the constant returned)
        self.used_keepb = False    # a register compare tested by beqz/bnez (variant 50331648: `(c) == false`)
        self.used_intadd = False   # int + pointer (variant 100663296: `x + (int)p`, the int first in the addu)
        self.used_notb = False     # bool ^ 1 (variant 201326592: `!b`, a bool)
        self.used_reljoin = False  # an if's paths loading one field: read after the if (variant 786432: merged)
        self.used_swj = False      # path mode met a compare chain: a switch (variant (v // 196608) % 2: ifs)
        self.int_idx = set()       # index expressions of array roots (a sum there is integer arithmetic)
        self.hioff = {}            # register -> D_ "symbol" whose %hi was added to a pointer (an offset)
        self.stackargs = {}        # ... values stored there for the next call
        self.refparams = set()     # named callers: parameter registers declared as references
        self.vt_types = {}         # vector temporary offset -> its class (from the callee's parameter)
        self.need_gtmath = False   # include b3/GtMathPs2.h
        self.need_dot = False      # a file-local DotProduct(CGtV3d, CGtV3d) stand-in (vlift; not in the header yet)
        self.need_gtmath1 = False  # include b3/GtMath.h (GtMath::Max / Min)
        self.need_abs = False      # lift3: a file-local GtMath::Abs(float) stand-in (B3O0PCH map; not in GtMath.h yet)
        self.need_lerp3 = False    # lift3: a file-local Interpolate(CGtV3d, CGtV3d, float) stand-in (B3O0PCH map)
        self.need_g2d = False      # lift3: include Gt2dObject.h (a CGt2dObject::CGt2dObjectSpace parameter / argument)
        self.fbinds = []           # float locals bound before a GtMath call: `float fN = x;`
        self.used_blkcopy = False
        self.used_l4live = False
        self.used_l4cnt = False
        self.used_l4pd = False     # lift4: a `while (n--)` loop
        self.used_l4latch = False  # lift4: an if in a do-while body joined at the latch
        self.used_l5ret = False
        self.used_l5dsll = False   # lift5: dsll of a value
        self.used_l5brk = False    # lift5: a register only break paths set made a loop variable    # lift5: paths' return kinds unified
        self.used_l4goto = False   # lift4: several gotos to one label    # lift4: a do-while's back branch tests the counter register itself   # lift4: a register written in a loop and read after it made a loop variable
        self.used_qorder = False
        self.zext128 = set()
        self.used_pinc = False
        self.used_loopcall = False
        self.frame_gap = 0
        self.vfields = set()
        self.vlanes = {}           # lift3: (root, off) -> lanes set on that vector field (w: vmulx.w, W: SetW form)
        self.psize = {}            # pointee type -> size, from a `p++` of its pointer (padded to it)
        self.qbinds = []           # 128-bit values built by pcpyld: `u_long128 qN; asm("pcpyld ...")`
        self.aggs = {}             # aggregate copy types: name -> (members [(off, type)], size, align)
        self.aggof = {}            # repr(source root) -> (size, align) of a whole-object copy
        self.pend = []             # hoisted product declarations waiting for the statement being rendered
        self.hoisted = {}
        self.no_hoist = False
        self.phis = []             # merged register values at if joins: {"a", "b", "init", "used", "ea", "eb"}
        self.lvars = []            # loop induction variables: {"init", "reg"}
        self.mvars = []            # loop-carried variables: {"init", "reg", "isf"}
        self.phi_alias = {}        # merge id -> loop variable it is written as (in-place updates)
        self.pathmode = bool(c.get("pathmode"))  # every branch: the taken path lifted to its own return
        self.path_rvs = []         # path mode: the return values of the taken paths
        self.path_alts = []        # ... per path: (a call result left in v0, its ("ret") statement)
        self.path_raw = []         # lift5: ... per path: the (v0, f0) values at its `jr ra`
        self.npaths = 0
        self.loopctx = []          # region mode: enclosing loops {"C": continue point, "X": exit}
        self.gpend = {}            # lift2: goto target position -> [(state, goto stmt, epoch)] awaiting its label
        self.loops = {}            # region mode: header -> (cond start | None, back branch position, body blocks)
        self.bend = {}             # region mode: block start -> next block start
        self.nsteps = 0
        self.poverride = {}
        self.used_csig = False     # call arguments from the callee's asm changed something (csig_args)
        self.used_cptr = False     # a call result tested against zero (patch_cptr.py)
        self.used_dfirst = False   # a switch with a default block (patch_dfirst.py)
        self.used_lit4 = False     # a .lit4 pool load made a float literal (patch_lit4.py)
        self.used_fptr = False     # an int field load tested against zero (patch_fptr.py)
        self.consumed = set()      # values already stored / passed (a final v0/f0 holding one is likely a temp)
        self.recent = set()        # ... since the last call
        self.ptr_elem = CDict(self)  # repr(pointer base) -> repr(element root), for p[i] indexing
        self.unk_sig = {}         # func_ callee -> (arg types, return type), merged over its calls
        self.unk_vptr = set()     # ... whose calls' results are different pointer types: `void *`, cast per call
        self.a0_value = False     # a0 used as a plain value (arithmetic / an index)
        self.etypes = {}          # (repr(base), K0, stride) -> element struct name

    # -- values --------------------------------------------------------------------------------------------------
    def ck(self, key):
        for a, b in self.alias.items():
            if a in key:
                key = key.replace(a, b)
        return key

    def ckt(self, key):
        key = self.ck(key)
        for a, b in self.talias.items():
            if a in key:
                key = key.replace(a, b)
        return key

    def same(self, x, y):
        return self.ck(repr(x)) == self.ck(repr(y))

    def same_t(self, x, y):
        """The same object for typing: also through a pointer's re-loads (talias)."""
        return self.ckt(repr(x)) == self.ckt(repr(y))

    def rd(self, r):
        v = self.R.get(r)
        if v is None or v[0] == "x":
            raise Skip("reads clobbered/unknown register %s" % r + (" [%s %s; %s]" % (
                getattr(self, "_cur", ("?", ""))[0], getattr(self, "_cur", ("?", ""))[1] + " @%r" % (getattr(self, "_pos", None),),
                "never set" if v is None else "clobbered" + (" by a loop (%s)" % self._loopx[r] if r in getattr(self, "_loopx", {}) else "")) if DIAG else ""))
        return v

    @staticmethod
    def kfold(v):
        """The integer value of an all-constant expression (k, + - << * & |), else None."""
        if v[0] == "k":
            return v[1]
        if v[0] == "b" and len(v) >= 4 and v[1] in ("+", "-", "<<", "*", "&", "|"):
            x, y = Lift.kfold(v[2]), Lift.kfold(v[3])
            if x is None or y is None:
                return None
            r = {"+": x + y, "-": x - y, "<<": x << y if 0 <= y < 32 else None, "*": x * y, "&": x & y,
                 "|": x | y}[v[1]]
            if r is None:
                return None
            r &= 0xFFFFFFFF
            return r - 0x100000000 if r & 0x80000000 else r
        return None

    def split(self, v, extra=0):
        """-> (root, off) for an address value (+ a displacement: array elements are cut with it included)."""
        off = extra
        while v[0] == "b" and v[1] == "+" and v[3][0] != "k" and self.kfold(v[3]) is not None:
            v = (v[0], v[1], v[2], ("k", self.kfold(v[3]))) + tuple(v[4:])
        if v[0] == "b" and v[1] == "+" and v[2][0] != "k" and self.kfold(v[2]) is not None:
            v = (v[0], v[1], ("k", self.kfold(v[2])), v[3]) + tuple(v[4:])
        while v[0] == "b" and v[1] == "+" and v[3][0] == "k":
            off += v[3][1]
            v = v[2]
        if v[0] == "b" and v[1] == "+" and v[2][0] == "k":
            off += v[2][1]
            v = v[3]
        if v[0] == "gofs":
            return ("g", v[1]), off + v[2]
        if v[0] in ("p", "g", "l", "c", "phi", "loc", "lv", "mv"):
            if v[0] == "p" and v[1] not in GPR:
                raise Skip("float register used as a pointer")
            return v, off
        if v[0] == "b" and v[1] == "+":
            ix = self.split_idx(v, off)
            if ix:
                return ix
        raise Skip("address from %s" % (v[0],) + (" %r" % (v,) if DIAG else ""))

    def lin(self, v, opaque=False):
        """v as coef * var for a single non-constant var, or None. opaque (an array index): a sum of different
        terms (`i + j`, `i + K`) is one index expression."""
        if v[0] == "b" and v[1] == "i*" and v[3][0] == "k":
            r = self.lin(v[2], opaque)
            return (r[0], r[1] * v[3][1]) if r else None
        if v[0] == "b" and v[1] == "<<" and v[3][0] == "k":
            r = self.lin(v[2], opaque)
            return (r[0], r[1] << v[3][1]) if r else None
        if v[0] == "b" and v[1] in ("+", "-"):
            a, b = self.lin(v[2], opaque), self.lin(v[3], opaque)
            if a and b and a[0] == b[0]:
                return (a[0], a[1] + b[1] if v[1] == "+" else a[1] - b[1])
            if opaque and (a or b) and not self.is_ptr(v[2]) and not self.is_ptr(v[3]):
                return (v, 1)
            return None
        if v[0] == "b" and v[1] in ("i%", "i/", "i%u", "i/u", "&", ">>", ">>u"):
            return (v, 1)                    # an opaque index expression (x % n, x & mask, ...)
        if v[0] in ("p", "l", "c", "lv", "mv", "phi") or (v[0] == "u" and v[1].startswith("(")):
            if v[0] == "p" and v[1] not in GPR:
                return None
            return (v, 1)
        return None

    def flat(self, v, terms, k):
        if v[0] == "b" and v[1] == "+":
            k = self.flat(v[2], terms, k)
            return self.flat(v[3], terms, k)
        if v[0] == "k":
            return k + v[1]
        if v[0] == "gofs":
            terms.append(("g", v[1]))
            return k + v[2]
        terms.append(v)
        return k

    def scaled(self, i, S):
        return i if S == 1 else ("b", "i*", i, ("k", S))

    def split_idx(self, v, off):
        """base + stride*index + K -> an array-element root and the offset inside the element."""
        terms = []
        k = self.flat(v, terms, off)
        if len(terms) == 3:
            # base + S1*i + S2*j (S1 > S2, S2 | S1): `base[i].field_K[j]`, an array inside an array element [G]
            bases = [t for t in terms if t[0] in ("p", "g", "l", "c") and not (t[0] == "p" and t[1] not in GPR)
                     and (repr(t) in self.ptr_roots or t[0] == "g" or t == ("p", "a0"))]
            if not bases:
                # `l[i].f[j]` off a fresh load: the one load / declared-pointer parameter among the terms
                # (DoesNeighbourExist__14CB3TrafficLaneFi22ESegmentNeighbourTypes: a2 + (l + a1*18)) [G]
                bases = [t for t in terms if t[0] in ("l", "c") or (
                    t[0] == "p" and self.preg_types.get(t[1], "").endswith("*"))]
                if len(bases) != 1:
                    bases = []
            for b0 in bases:
                rest = [t for t in terms if t is not b0]
                ls = [self.lin(t, True) for t in rest]
                if None in ls or any(l[1] < 1 for l in ls):
                    continue
                if ls[0][1] == ls[1][1] and len(bases) == 1 and k >= 0 and \
                        not any(self.is_ptr(t) for t in rest):
                    # base + S*i + S*j: one index `base[i + j]` (MWCC adds base + i first for S == 1: func_003F57A0)
                    S = ls[0][1]
                    idx = ("b", "+", ls[1][0], ls[0][0])    # source `base[a + b]` flattens as b, base, a
                    self.int_idx.add(repr(idx))
                    root = ("ix", b0, k - k % S, S, idx)
                    o = self.obj(root)
                    o["stride"] = S
                    if k - k % S == 0 and (b0[0] in ("l", "c") or (b0[0] == "p" and b0[1] != "a0")):
                        self.ptr_elem[repr(b0)] = repr(root)
                        self.ptr_roots.add(repr(b0))
                    else:
                        self.field(b0, k - k % S, "ARR|" + repr(root))
                    return root, k % S
                (i, S1), (j, S2) = sorted(ls, key=lambda l: -l[1])
                if S1 == S2 or S1 % S2 or k < 0:
                    continue
                inner = self.split_idx(("b", "+", ("b", "+", b0, self.scaled(i, S1)), ("k", k - k % S1)), 0)
                if not inner or inner[1] != 0:
                    continue
                r1 = inner[0]
                eo = k % S1
                K1 = eo - eo % S2
                root = ("ix", r1, K1, S2, j)
                self.int_idx.add(repr(j))
                o = self.obj(root)
                o["stride"] = S2
                self.field(r1, K1, "ARR|" + repr(root))
                return root, eo % S2
            return None
        if len(terms) != 2:
            return None
        cand = []
        for a, b in ((terms[0], terms[1]), (terms[1], terms[0])):
            if a[0] not in ("p", "g", "l", "c", "loc") or (a[0] == "p" and a[1] not in GPR):
                continue
            li = self.lin(b, True)
            if not li or li[1] < 1 or li[0] == a:
                continue
            score = (li[1] > 1) * 4 + (repr(a) in self.ptr_roots) * 2 + (a == ("p", "a0") or a[0] in ("g", "l"))
            cand.append((score, a, li))
        if not cand:
            return None
        cand.sort(key=lambda x: -x[0])
        if len(cand) > 1 and cand[0][0] == cand[1][0]:
            raise Skip("ambiguous array base")
        _, base, (idx, S) = cand[0]
        if k < 0:
            # `p[i - n].f`: MWCC folds the -n*S into the load displacement (GetSegmentLengthFast__9CB3AILaneCFUs)
            if not (base[0] in ("l", "c") or (base[0] == "p" and base[1] in GPR)) or self.is_ptr(idx):
                return None
            n = -(k // S)
            idx = ("b", "+", idx, ("k", -n))
            k += n * S
        eoff = k % S
        K0 = k - eoff
        if K0 > 0 and self.same_elem(base, 0, S):
            # base already indexed as an element pointer of this stride: `p[i + n]`, not a field array
            # (GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType) [G]
            idx = ("b", "+", idx, ("k", K0 // S))
            K0 = 0
        self.int_idx.add(repr(idx))
        root = ("ix", base, K0, S, idx)
        o = self.obj(root)
        o["stride"] = S
        if K0 == 0 and (base[0] in ("l", "c") or (base[0] == "p" and base[1] != "a0")):
            self.ptr_elem[repr(base)] = repr(root)
            self.ptr_roots.add(repr(base))
        else:
            self.field(base, K0, "ARR|" + repr(root))
        return root, eoff

    def obj(self, root):
        key = repr(root)
        if key not in self.objs:
            self.objs[key] = {"root": root, "fields": {}, "n": len(self.objs)}
            if self.typing:
                self.name_one(self.objs[key])
        self.ptr_roots.add(key)
        return self.objs[key]

    def field(self, root, off, t, zero=False, soft=False, pun=False):
        """Record field +off of root as type t. soft: a sb/sh store of a register (either signedness fits a
        field of that size). pun: a scalar access of another scalar type is allowed and returned (the access
        is then rendered through a pointer cast, `*(T *)&p->field_XX`) [G] source form."""
        o = self.obj(root)
        if o.get("vptr") == off:
            return
        # a 64-bit access over two 4-byte scalars (a CGtV2d copied whole with ld/sd): the 4-byte fields stay the
        # layout and the 64-bit access is a pun, `*(unsigned long *)&p->field_X` [G] source form
        WIDE = {"unsigned long": 8, "u_long128": 16}
        if pun and t in WIDE:
            cover = range(off, off + WIDE[t], 4)
            small = [o["fields"][k] for k in cover if o["fields"].get(k) in PUNS and SIZE.get(o["fields"][k]) == 4]
            if small:
                if off not in o["fields"]:
                    o["fields"][off] = small[0]
                self.used_pun = True
                return t
            if off not in o["fields"]:
                o.setdefault("wideprov", set()).add(off)
        if pun and t in PUNS and SIZE.get(t) == 4:
            for wt, wn in WIDE.items():
                for wo in range(off - wn + 4, off + 1, 4):
                    if o["fields"].get(wo) == wt and wo in o.get("wideprov", ()):
                        # the provisional wide field was a run of these: its accesses so far become puns
                        o["wideprov"].discard(wo)
                        o["fields"][wo] = t
                        self.repun(root, wo, wt)
                        if wo == off:
                            return
        if zero and t == "int":
            # a store of 0 fits a field of any type (0.0f is stored with `sw zero` too)
            if off in o["fields"]:
                return
            o.setdefault("zint", set()).add(off)
            o["fields"][off] = "int"
            return
        if off in o["fields"] and o["fields"][off] == "int" and off in o.get("zint", ()) and t != "int":
            o["zint"].discard(off)
            o["fields"][off] = t
            return
        if t == "int" and off in o.get("zint", ()):
            o["zint"].discard(off)              # really an int: read or stored as one
        if off in o["fields"] and o["fields"][off] != t and o["fields"][off] in PUNS and t in PUNS and \
                SIZE[o["fields"][off]] == SIZE[t]:
            if soft:
                return                          # a sb/sh store of a register: the field's own type fits
            if off in o.get("soft", ()):
                o["soft"].discard(off)          # the type so far came from such a store only
                o["fields"][off] = t
                return
        if soft and off not in o["fields"]:
            o.setdefault("soft", set()).add(off)
        elif not soft and off in o.get("soft", ()) and o["fields"].get(off) == t:
            o["soft"].discard(off)
        if off in o["fields"] and o["fields"][off] in ("V3D", "V4D", "V3P", "SPH") and t == "u_long128":   # lift3: V3P/SPH
            return None                          # an lq/sq of a vector field: the same 128 bits
        if t == "u_long128" and any(o["fields"].get(off - k_) == "M34" for k_ in (0, 0x10, 0x20, 0x30)):
            return None                          # a matrix row (vlift)
        if off in o["fields"] and o["fields"][off] != t:
            if {o["fields"][off], t} <= {"int", "void *"} or (o["fields"][off].endswith("*") and t == "int"):
                return
            if o["fields"][off].startswith("ARR|") and t.startswith("ARR|"):
                # one array indexed by two expressions (`a[i]`, `a[j]`): the same element type (name_one keys
                # it by base, offset and stride; the layouts merge per type)
                r1, r2 = self.objs[o["fields"][off][4:]]["root"], self.objs[t[4:]]["root"]
                if (self.ck(repr(r1[1])), r1[2], r1[3]) == (self.ck(repr(r2[1])), r2[2], r2[3]):
                    return
            if pun and o["fields"][off] in PUNS and t in PUNS:
                self.used_pun = True
                return t
            if o["fields"][off].endswith("*") and t.endswith("*"):
                raise Skip("field +0x%X used as two pointer types" % off)
            raise Skip("field +0x%X used as %s and %s" % (off, o["fields"][off], t))
        if t == "int" and o["fields"].get(off, "").endswith("*"):
            return
        o["fields"][off] = t

    def repun(self, root, off, wt):
        """The wide (64/128-bit) loads and stores of root+off recorded so far become puns (their field turned out
        4 bytes)."""
        lm, sm = {"unsigned long": ("ld", "sd"), "u_long128": ("lq", "sq")}[wt]
        for L in self.loads.values():
            if L["off"] == off and L["mn"] == lm and self.same(L["root"], root):
                L["pun"] = wt
        for k, s in enumerate(self.stmts):
            if s[0] == "store" and s[2] == off and s[4] == sm and self.same(s[1], root):
                self.stmts[k] = s[:5] + (wt,)
        self.used_pun = True

    def use(self, v):
        """Mark a value as used at the current point (binds stale loads/calls to temporaries)."""
        if v[0] == "l":
            L = self.loads[v[1]]
            L["used"] = True
            if L["epoch"] != self.epoch:
                L["temp"] = True
            self.use(L["root"])
        elif v[0] == "c":
            if self.calls[v[1]].get("fused"):
                raise Skip("call result used as int and float")
            self.calls[v[1]]["used"] = True
        elif v[0] == "cf":
            if self.calls[v[1]]["used"]:
                raise Skip("call result used as int and float")
            self.calls[v[1]]["fused"] = True
        elif v[0] in ("b",):
            if ("p", "a0") in (v[2], v[3]):
                self.a0_value = True
            self.use(v[2]); self.use(v[3])
        elif v[0] == "u":
            self.use(v[2])
        elif v[0] == "sl32" and self.c.get("lift5"):
            self.use(v[1])                           # lift5
        elif v[0] == "fcall":
            self.use(v[2])
            if v[3] is not None:                 # lift3: one-argument GtMath::Abs
                self.use(v[3])
        elif v[0] == "p":
            self.used_params.add(v[1])
        elif v[0] == "phi":
            ph = self.phis[v[1]]
            if not ph["used"]:
                ph["used"] = True
                save = self.epoch
                self.epoch = ph["ea"]
                self.use(ph["a"])
                self.epoch = ph["eb"]
                if ph["b"] is not None:
                    self.use(ph["b"])
                for k in ph.get("more", ()):
                    self.epoch = ph["e" + k]
                    self.use(ph[k])
                self.epoch = save
        elif v[0] == "ix":
            if v[4] == ("p", "a0"):
                self.a0_value = True
            self.use(v[1]); self.use(v[4])

    # -- interpretation ------------------------------------------------------------------------------------------
    def mem(self, a):
        m = re.fullmatch(r"(\w+),(.+)\((\w+)\)", a)
        if not m:
            raise Skip("operand %s" % a)
        rt, offs, base = m.groups()
        g = re.fullmatch(r"%gp_rel\(([A-Za-z_]\w*)(?:\+(0x[0-9A-Fa-f]+|\d+))?\)", offs)
        if g and base == "gp":
            self.gmode(g.group(1), "gp")
            return rt, ("g", g.group(1)), num(g.group(2)) if g.group(2) else 0
        g = re.fullmatch(r"%lo\(([A-Za-z_]\w*)(?:\+(0x[0-9A-Fa-f]+|\d+))?\)", offs)
        if g:
            hv = self.rd(base)
            if hv[0] != "hi" and self.hioff.get(base) == g.group(1):
                # the low half of such an offset (sign-extended)
                lo = (int(g.group(1)[2:], 16) + (num(g.group(2)) if g.group(2) else 0)) & 0xFFFF
                root, off = self.split(hv, lo - 0x10000 if lo >= 0x8000 else lo)
                return rt, root, off
            if hv != ("hi", g.group(1), num(g.group(2)) if g.group(2) else 0):
                raise Skip("%lo without its %hi")
            self.gmode(g.group(1), "abs")
            return rt, ("g", g.group(1)), num(g.group(2)) if g.group(2) else 0
        if base == "sp" and self.locbase is not None and re.fullmatch(NUM, offs):
            return rt, ("loc",), num(offs) - self.locbase
        if base in ("sp", "gp"):
            raise Skip("stack/gp access")
        g = re.fullmatch(r"\((0x[0-9A-Fa-f]+)&0xFFFF\)", offs)
        if g:
            # a field past 0x7FFF: `lui r,(K>>16); addu r,base,r` then the sign-extended low half
            lo = num(g.group(1)) & 0xFFFF
            root, off = self.split(self.rd(base), lo - 0x10000 if lo >= 0x8000 else lo)
            return rt, root, off
        if not re.fullmatch(NUM, offs):
            raise Skip("offset %s" % offs)
        root, off = self.split(self.rd(base), num(offs))
        return rt, root, off

    def gmode(self, sym, mode):
        if "__" in sym:
            m = re.fullmatch(r"([A-Za-z_]\w*?)__(\d+)([A-Za-z_]\w*)", sym)
            if not m or int(m.group(2)) != len(m.group(3)):
                raise Skip("mangled global %s" % sym)
            if self.has_header(m.group(3)):
                raise Skip("static member's class %s has a header" % m.group(3))
            self.smembers[sym] = (m.group(3), m.group(1))
        if self.globals_mode.setdefault(sym, mode) != mode:
            raise Skip("global %s addressed two ways" % sym)

    def scan_stack(self, ins):
        """A function with a frame may have one local (an out-parameter's target, a value written and read
        back): the bytes from the lowest sp offset that is not a register save up to the frame's top."""
        self.frame, self.locbase = None, None
        self.saveslots = None     # None: every callee-saved register access counts as a save (no frame scan)
        for m, a in ins:
            if m in ("addiu", "daddiu") and a.startswith("sp,sp,-"):
                self.frame = num(a.split(",")[2][1:])
                break
        if self.frame is None:
            return
        top = 0
        for m_, a_ in ins:
            o_ = a_.split(",") if a_ else []
            g_ = re.search(r"(-?0x[0-9A-Fa-f]+|\d+)\(sp\)$", a_)
            if g_:
                top = max(top, num(g_.group(1)) + {"sq": 16, "lq": 16, "sd": 8, "ld": 8}.get(m_, 4))
            elif m_ in ("addiu", "daddiu") and len(o_) == 3 and o_[1] == "sp" and o_[0] != "sp":
                top = self.frame                # an address taken: the extent is unknown
            elif m_ in ("daddu", "addu", "or") and "sp" in o_[1:] and o_[0] != "sp":
                top = self.frame
        self.frame_gap = self.frame - (top + 15) // 16 * 16
        saves, offs = [], []
        # vector temporaries: offsets only ever written whole by one `sq` and taken by address
        acc = {}
        for m, a in ins:
            ops = a.split(",") if a else []
            g_ = re.search(r"(%s)\(sp\)$" % NUM, a)
            if g_ and num(g_.group(1)) >= self.frame:
                continue                          # an incoming stack argument (STK), not a local
            if m in ("addiu", "daddiu") and len(ops) == 3 and ops[1] == "sp" and ops[0] != "sp" \
                    and re.fullmatch(NUM, ops[2]):
                acc.setdefault(num(ops[2]), []).append("addr")
            elif a.endswith("(sp)") and len(ops) == 2 and re.fullmatch(r"%s\(sp\)" % NUM, ops[1]):
                if not (m in ("sd", "sq", "ld", "lq", "swc1", "lwc1") and
                        (ops[0] == "ra" or re.fullmatch(r"s[0-7]|fp|f2[0-9]|f3[01]", ops[0]))):
                    acc.setdefault(num(ops[1][:-4]), []).append(m)
        # a CGtV4d(x, y, z, w) built in a temporary: four 4-byte stores and one lq of it, nothing else (unless a
        # first attempt found the copy used otherwise: generate() retries with nov4)
        for X in ([] if self.c.get("nov4") else sorted(acc)):
            if sorted(acc.get(X, [])) in (["lq", "sw"], ["lq", "swc1"]) and \
                    all(len(acc.get(X + d, [])) == 1 and acc[X + d][0] in ("sw", "swc1") for d in (4, 8, 12)):
                self.v4tmp[X] = [None] * 4
        if self.v4tmp:
            for X in self.v4tmp:
                for d in (0, 4, 8, 12):
                    acc.pop(X + d, None)
        if acc and all(sorted(v) == ["addr", "sq"] for v in acc.values()):
            self.vtemps = set(acc)
            return
        self.v4tmp = {}
        # register save slots: a callee-saved register (or ra) stored before the function first writes it -- a
        # store of it after that (`swc1 f20,0xCC(sp)` of a computed f20) is a local, and so is a load from any other
        # offset (`lwc1 f20,0x3C(sp)`) [C] func_001D0D00, func_001D6C40
        self.saveslots, written = set(), set()
        for m, a in ins:
            ops = a.split(",") if a else []
            if m in ("sd", "sq", "swc1") and len(ops) == 2 and ops[1].endswith("(sp)") and \
                    (ops[0] == "ra" or re.fullmatch(r"s[0-7]|fp|f2[0-9]|f3[01]", ops[0])) and ops[0] not in written:
                g = re.fullmatch(r"(%s)\(sp\)" % NUM, ops[1])
                if g:
                    self.saveslots.add(num(g.group(1)))
                continue
            if ops and m not in ("sb", "sh", "sw", "sd", "sq", "swc1", "sqc2") and not m.startswith("b") and \
                    m not in ("j", "jr", "nop"):
                written.add(ops[1] if m in ("mtc1", "dmtc1", "ctc1", "qmtc2") and len(ops) > 1 else ops[0])
            if m in ("jal", "jalr"):
                written.add("ra")
        for m, a in ins:
            ops = a.split(",") if a else []
            if m in ("addiu", "daddiu") and len(ops) == 3 and ops[1] == "sp" and ops[0] != "sp":
                if not re.fullmatch(NUM, ops[2]):
                    raise Skip("stack address %s" % a)
                offs.append(num(ops[2]))
            elif m in ("daddu", "addu", "or") and len(ops) == 3 and "sp" in ops[1:] and ops[0] != "sp":
                if "zero" not in ops[1:]:
                    continue                     # sp + index: the element offsets come with the accesses
                offs.append(0)
            elif a.endswith("(sp)") and len(ops) == 2:
                r = ops[0]
                g = re.fullmatch(r"(%s)\(sp\)" % NUM, ops[1])
                if not g:
                    raise Skip("stack operand %s" % a)
                k = num(g.group(1))
                if k >= self.frame:
                    continue                      # an incoming stack argument (STK)
                if m in ("sd", "sq", "ld", "lq", "swc1", "lwc1") and k in self.saveslots and \
                        (r == "ra" or re.fullmatch(r"s[0-7]|fp|f2[0-9]|f3[01]", r)):
                    saves.append((k, k + {"sd": 8, "ld": 8, "sq": 16, "lq": 16}.get(m, 4)))
                else:
                    offs.append(k)
        # the outgoing argument area: offsets below every register save, only ever stored with sd/sw (the
        # arguments past a0..t3 of the next call)
        kinds, sstart = {}, []
        for m, a in ins:
            ops = a.split(",") if a else []
            if m in ("addiu", "daddiu") and len(ops) == 3 and ops[1] == "sp" and ops[0] != "sp" and \
                    re.fullmatch(NUM, ops[2]):
                kinds.setdefault(num(ops[2]), set()).add("addr")
            elif a.endswith("(sp)") and len(ops) == 2 and re.fullmatch(r"%s\(sp\)" % NUM, ops[1]):
                k = num(ops[1][:-4])
                if m in ("sd", "sq", "ld", "lq", "swc1", "lwc1") and k in self.saveslots and \
                        (ops[0] == "ra" or re.fullmatch(r"s[0-7]|fp|f2[0-9]|f3[01]", ops[0])):
                    sstart.append(k)
                else:
                    kinds.setdefault(k, set()).add(m)
        if sstart:
            self.outargs = {k for k, ks in kinds.items() if k < min(sstart) and ks <= {"sd", "sw"} and k % 8 == 0}
            offs = [k for k in offs if k not in self.outargs]
        if not offs:
            return
        base = min(offs)
        if base >= self.frame:
            raise Skip("stack offset beyond the frame")
        # the local runs from its lowest offset up to the next register save above it (or the frame's top): MWCC
        # puts locals either below the saves (func_002174A0: local at 0, ra at 0x10) or above them
        if any(s < base < e for s, e in saves):
            raise Skip("stack local inside a register save")
        above = [s for s, e in saves if s >= base]
        end = min(above) if above else self.frame
        if any(k >= end for k in offs):
            raise Skip("stack locals on both sides of a register save")
        self.locbase = base
        self.locsize = end - base

    def blkcopy_pass(self, ins):
        """MWCC's aggregate copy loops (known.md N132) -> ("cpyloop", "S,D,C,step,temps"), when only their own
        bgtz targets the label."""
        R_ = r"([a-z]\w*)"
        pats = [
            (16, [("lq", R_ + r",0x0\(" + R_ + r"\)"), ("addiu", R_ + r"," + R_ + r",-0x1"),
                  ("sq", R_ + r",0x0\(" + R_ + r"\)"), ("addiu", R_ + r"," + R_ + r",0x10"),
                  ("addiu", R_ + r"," + R_ + r",0x10"), ("bgtz", R_ + r",(\.L\w+)"), ("nop", "")]),
            (32, [("lq", R_ + r",0x0\(" + R_ + r"\)"), ("addiu", R_ + r"," + R_ + r",-0x1"),
                  ("lq", R_ + r",0x10\(" + R_ + r"\)"), ("sq", R_ + r",0x0\(" + R_ + r"\)"),
                  ("sq", R_ + r",0x10\(" + R_ + r"\)"), ("addiu", R_ + r"," + R_ + r",0x20"),
                  ("bgtz", R_ + r",(\.L\w+)"), ("addiu", R_ + r"," + R_ + r",0x20")]),
            (8, [("lw", R_ + r",0x0\(" + R_ + r"\)"), ("addiu", R_ + r"," + R_ + r",-0x1"),
                 ("lw", R_ + r",0x4\(" + R_ + r"\)"), ("sw", R_ + r",0x0\(" + R_ + r"\)"),
                 ("sw", R_ + r",0x4\(" + R_ + r"\)"), ("addiu", R_ + r"," + R_ + r",0x8"),
                 ("bgtz", R_ + r",(\.L\w+)"), ("addiu", R_ + r"," + R_ + r",0x8")]),
        ]
        out, k = [], 0
        while k < len(ins):
            m, a = ins[k]
            hit = None
            if m == "label":
                for step, pat in pats:
                    body = ins[k + 1:k + 1 + len(pat)]
                    if len(body) != len(pat):
                        continue
                    gs = []
                    for (pm, pa), (bm, ba) in zip(pat, body):
                        g = re.fullmatch(pa, ba) if pm == bm else None
                        if g is None:
                            break
                        gs.append(g.groups())
                    else:
                        if step == 16:
                            (x, S), (C, C2), (x2, D), (S2, S3), (D2, D3), (C3, L), _ = gs
                            ok = x == x2 and C == C2 == C3 and S == S2 == S3 and D == D2 == D3
                            temps = [x]
                        else:
                            (x, S), (C, C2), (y, S1), (x2, D), (y2, D1), (S2, S3), (C3, L), (D2, D3) = gs
                            ok = x == x2 and y == y2 and S == S1 == S2 == S3 and D == D1 == D2 == D3 and \
                                C == C2 == C3 and x != y
                            temps = [x, y]
                        tg = sum(1 for (mm, aa) in ins if mm != "label" and aa.split(",")[-1] == a)
                        if ok and L == a and tg == 1 and len({S, D, C} | set(temps)) == 3 + len(temps):
                            hit = (len(pat), "%s,%s,%s,%d,%s" % (S, D, C, step, "/".join(temps)))
                            break
            if hit:
                out.append(("cpyloop", hit[1]))
                k += 1 + hit[0]
                self.used_blkcopy = True
                continue
            out.append((m, a))
            k += 1
        return out

    def unrotate_pass(self, ins):
        """lift2 (2026-10-26): MWCC fills an unconditional jump's delay slot with the target's first instruction and
        jumps past it (`b .L+4; <insn at .L>`). That edge enters a block in its middle ("loop entered in the middle",
        "continue to a do-while's test"). Rewrite it as `b .L; nop`, .L a label just before that instruction (reused
        when one is there). Only when the instruction falls into the target and is not itself a delay slot."""
        lab = {a: k for k, (m, a) in enumerate(ins) if m == "label"}
        JUMPS = CONDBR | {"b", "j", "jal", "jalr", "jr"}
        retarget, newlab, nfix = {}, {}, 0
        for k, (m, a) in enumerate(ins):
            if m != "b" or a not in lab or k + 1 >= len(ins):
                continue
            d = ins[k + 1]
            if d == ("nop", "") or d[0] == "label" or d[0] in JUMPS:
                continue
            p = lab[a] - 1
            while p >= 0 and ins[p][0] == "label":
                p -= 1
            if p < 1 or ins[p] != d or ins[p - 1][0] in JUMPS or ins[p - 1][0] == "cpyloop" or \
                    (ins[p - 1][0].startswith("b") and ins[p - 1][0].endswith("l") and ins[p - 1][0] != "bal"):
                continue
            if p == k + 1:
                continue
            if ins[p - 1][0] == "label":
                tl = ins[p - 1][1]
            else:
                tl = newlab.setdefault(p, a + "_u")
            retarget[k] = tl
            nfix += 1
        if not nfix:
            return ins
        out = []
        for k, (m, a) in enumerate(ins):
            if k in newlab:
                out.append(("label", newlab[k]))
            if k in retarget:
                out.append(("b", retarget[k]))
                continue
            if k - 1 in retarget:
                out.append(("nop", ""))
                continue
            out.append((m, a))
        # labels no longer targeted by anything are dropped (they would only split blocks)
        used = set()
        for m, a in out:
            if m != "label" and a:
                used.add(a.split(",")[-1])
        old = {ins[k][1] for k in retarget}
        out = [x for x in out if x[0] != "label" or x[1] in used or x[1] not in old]
        self.used_unrot = nfix
        return out

    def unthread_pass(self, ins):
        """lift2 (2026-10-26): MWCC threads a branch to an entry-jump loop's `b C` straight to the loop's condition
        block C (`if (c) { while (t) {...} }` -> `bc1t C`), or there is no `b C` at all when nothing falls into the
        loop header. Rebuild the canonical entry: a label J before `b C; nop` right ahead of the header (the old
        `b C`'s delay instruction hoisted above J), and the outside branches to C retargeted to J. "loop entered in
        the middle" (GetParamFromDist__14CB3TrafficLaneFf, func_003827B0)."""
        lab = {a: k for k, (m, a) in enumerate(ins) if m == "label"}
        UNC = ("b", "j", "jr")
        before, replace, retarget, nfix = {}, {}, {}, 0
        for kb, (m, a) in enumerate(ins):
            if m not in CONDBR:
                continue
            H = lab.get(a.split(",")[-1])
            if H is None or H >= kb:
                continue
            # the condition block: the last label before kb with no branch/jump between it and kb
            p, Lc = kb - 1, None
            while p > H:
                mp = ins[p][0]
                if mp == "label":
                    Lc = ins[p][1]
                    break
                if mp in CONDBR or mp in UNC or (mp.startswith("b") and mp.endswith("l") and mp != "bal"):
                    break
                p -= 1
            if Lc is None:
                continue
            outside = [k for k, (mk, ak) in enumerate(ins[:H]) if (mk in CONDBR or mk == "b") and
                       ak.split(",")[-1] == Lc]
            if not outside:
                continue
            q = H - 1
            while q >= 0 and ins[q][0] == "label":
                q -= 1
            if q < 1:
                continue
            canon = q - 1 if ins[q - 1] == ("b", Lc) else None
            others = [k for k in outside if k != canon]
            if not others or any(k in replace or k in retarget for k in others):
                continue
            J = Lc + "_e%d" % H
            if canon is not None:
                d = ins[canon + 1]
                if d[0] == "label" or d[0] in CONDBR or d[0] in UNC or d[0] in ("jal", "jalr") or canon in replace:
                    continue
                replace[canon] = ([] if d == ("nop", "") else [d]) + [("label", J), ("b", Lc), ("nop", "")]
                replace[canon + 1] = []
            else:
                if ins[q - 1][0] not in UNC or (q + 1) in before:
                    continue
                before[q + 1] = [("label", J), ("b", Lc), ("nop", "")]
            for k in others:
                retarget[k] = J
            nfix += 1
        # a break threaded past the loop's exit jump: the loop's back branch is followed by `b T; nop` and a branch
        # inside the loop goes straight to T -> retarget it to (a label on) that exit jump (GetParamFromDist)
        for kb, (m, a) in enumerate(ins):
            if m not in CONDBR:
                continue
            H = lab.get(a.split(",")[-1])
            if H is None or H >= kb or kb + 3 >= len(ins):
                continue
            p = kb + 2
            xl = None
            while p < len(ins) and ins[p][0] == "label":
                xl = ins[p][1]
                p += 1
            if p + 1 >= len(ins) or ins[p][0] != "b" or ins[p + 1] != ("nop", ""):
                continue
            T = ins[p][1]
            brk = [k for k in range(H + 1, kb) if (ins[k][0] in CONDBR or ins[k][0] == "b") and
                   ins[k][1].split(",")[-1] == T and k not in retarget and k not in replace]
            if not brk:
                continue
            if xl is None:
                if (kb + 2) in before or p in replace:
                    continue
                xl = T + "_x%d" % kb
                before[kb + 2] = before.get(kb + 2, []) + [("label", xl)]
            for k in brk:
                retarget[k] = xl
            nfix += 1
        if not nfix:
            return ins
        out = []
        for k, (m, a) in enumerate(ins):
            out += before.get(k, [])
            if k in replace:
                out += replace[k]
                continue
            if k in retarget:
                ops = a.split(",")
                out.append((m, ",".join(ops[:-1] + [retarget[k]])))
                continue
            out.append((m, a))
        self.used_unthread = nfix
        return out

    def run(self, ins):
        ins = self.blkcopy_pass(ins)
        if self.c.get("unrot"):
            ins = self.unrotate_pass(ins)        # lift2
            ins = self.unthread_pass(ins)        # lift2
        self.labels = None
        self.scan_stack([x for x in ins if x[0] != "label"])
        if any(m == "label" for m, a in ins):
            self.labels = {a: k for k, (m, a) in enumerate(ins) if m == "label"}
            self.targets = {}
            for k, (m, a) in enumerate(ins):
                if m in CONDBR or m == "b" or (m.startswith("b") and m.endswith("l") and m != "bal"):
                    self.targets.setdefault(a.split(",")[-1], []).append(k)
            if ins[-2] != ("jr", "ra") and ins[-2][0] != "j":
                raise Skip("does not end in a return")
            plain = [x for x in ins if x[0] != "label"]
            self.a0_relevant = any("a0" in a.replace("(", ",").replace(")", ",").split(",")[1:] for m, a in plain
                                   if m not in ("jal", "j"))
            self.caller_gprs, self.caller_fprs = [], []
            if self.named:
                pm = parse_method(self.c["demangled"])
                if pm:
                    gi, fi = 1, 0
                    for t in pm[2]:
                        if ptype(t)[3]:
                            self.caller_fprs.append(FPR[fi]); fi += 1
                        else:
                            if gi < len(GPR):
                                self.preg_types[GPR[gi]] = t
                            self.caller_gprs.append(GPRX[gi]); gi += 1
            self.ins = ins
            self.exec_range(0, len(ins))
            return
        n = len(ins)
        if n < 2:
            raise Skip("too short")
        # reorder delay slots: a branch/jump's delay instruction runs first
        seq = []
        i = 0
        while i < n:
            m, a = ins[i]
            if m in ("jal", "j", "jr", "jalr") and i + 1 < n:
                seq.append(ins[i + 1])
                seq.append((m, a))
                i += 2
            else:
                seq.append((m, a))
                i += 1
        if seq[-1][0] not in ("jr", "j") or (seq[-1][0] == "jr" and seq[-1][1] not in ("ra", "t9")):
            raise Skip("does not end in a return/tail call")
        self.a0_relevant = any("a0" in a.replace("(", ",").replace(")", ",").split(",")[1:] for m, a in ins
                               if m not in ("jal", "j"))
        self.caller_gprs, self.caller_fprs = [], []
        self.preg_types = {}       # argument register -> its declared parameter type (named functions)
        if self.named:
            pm = parse_method(self.c["demangled"])
            if pm:
                gi, fi = 1, 0
                for t in pm[2]:
                    if ptype(t)[3]:
                        self.caller_fprs.append(FPR[fi]); fi += 1
                    else:
                        if gi < len(GPR):
                            self.preg_types[GPR[gi]] = t
                        self.caller_gprs.append(GPRX[gi]); gi += 1
        if self.labels is not None:
            self.ins = ins
            self.exec_range(0, len(ins))
            return
        for k, (m, a) in enumerate(seq):
            last = k == len(seq) - 1
            self.step(m, a, last)

    def phvals(self, ph):
        """The merged values of a phi: an if's two sides, a switch's every side."""
        return [y for y in [ph["a"], ph["b"]] + [ph[k] for k in ph.get("more", ())] if y is not None]

    def all_stmts(self, stmts=None):
        for st in (self.stmts if stmts is None else stmts):
            if st[0] == "if":
                yield from self.all_stmts(st[2])
                if st[3] is not None:
                    yield from self.all_stmts(st[3])
            elif st[0] == "swj":
                for _, b, _ in st[2]:
                    yield from self.all_stmts(b)
                if st[3] is not None:
                    yield from self.all_stmts(st[3])
            elif st[0] == "for":
                yield from self.all_stmts(st[4])
            else:
                yield st

    def neg(self, v):
        if v[0] == "b" and v[1] in NEG:
            return ("b", NEG[v[1]], v[2], v[3]) + tuple(v[4:])
        if v[0] == "u" and v[1] == "!":
            return v[2]
        return ("u", "!", v)

    def cond(self, m, a):
        """The condition under which a conditional branch is taken."""
        ops = a.split(",")
        if m in ("bc1t", "bc1f"):
            f = self.R.get("fcc")
            if f is None:
                raise Skip("bc1 without a compare")
            return f if m == "bc1t" else ("u", "!", f)
        x = self.rd(ops[0])
        self.consume(repr(x))     # tested by the branch (v0 then is a temp when f0 is also set)
        if m in ("beqz", "bnez") and x[0] == "l" and self.loads[x[1]]["mn"] == "lw" and \
                self.loads[x[1]]["type"] == "int" and self.loads[x[1]]["root"][0] in ("p", "l", "g", "lv", "mv"):
            self.used_fptr = True
            if ((self.c.get("variant") or 0) // 412316860416) % 2:
                L1 = self.loads[x[1]]
                L1["type"] = "void *"
                o = self.obj(L1["root"])
                if o["fields"].get(L1["off"]) == "int":
                    o["fields"][L1["off"]] = "void *"
        if m in ("beqz", "bnez") and x[0] == "c" and self.calls[x[1]]["kind"] in ("unk", "method", "free", "static"):
            self.calls[x[1]]["ztest"] = True
            self.used_cptr = True
        if m in ("beqz", "bnez"):
            iscmp = x[0] == "b" and x[1] in NEG
            if iscmp:
                self.used_keepb = True
                if ((self.c.get("variant") or 0) // 50331648) % 2:
                    return ("b", "!=" if m == "bnez" else "==", x, ("k", 0), "keepb")
            if m == "bnez":
                return x if iscmp else ("b", "!=", x, ("k", 0))
            return self.neg(x) if iscmp else ("b", "==", x, ("k", 0))
        self.consume(repr(x))
        if m in ("beq", "bne"):
            y = self.rd(ops[1])
            self.consume(repr(y))
            return ("b", "==" if m == "beq" else "!=", x, y)
        return ("b", {"blez": "<=", "bgtz": ">", "bltz": "<", "bgez": ">="}[m], x, ("k", 0))

    def loop_branch(self, lbody, jc, hi):
        """Position of the conditional branch back to lbody that ends the condition block starting at jc."""
        for k in range(jc + 1, hi):
            mk, ak = self.ins[k]
            if mk == "label":
                return None
            if mk in CONDBR:
                return k if ak.split(",")[-1] == lbody else None
            if mk in ("b", "j", "jal", "jr", "jalr"):
                return None
        return None

    def aliasable(self, v, j):
        """v is loop variable j, or a merge with a side that is (a merge chain ending in) j."""
        if v == ("mv", j):
            return True
        if v[0] != "phi" or self.phi_alias.get(v[1], j) != j:
            return False
        ph = self.phis[v[1]]
        return any(x is not None and self.aliasable(x, j) for x in self.phvals(ph))

    def alias_merges(self, v, j):
        """Mark the merges of chain v as loop variable j itself; False if v is not such a chain."""
        if v[0] != "phi" or not self.aliasable(v, j):
            return False
        work = [v]
        while work:
            x = work.pop()
            if x[0] == "phi" and x[1] not in self.phi_alias and self.aliasable(x, j):
                self.phi_alias[x[1]] = j
                ph = self.phis[x[1]]
                work += [y for y in self.phvals(ph) if y is not None]
        return True

    def live_after(self, k, r):
        """r is read (or returned) before it is written on the straight-line path from position k."""
        ins = self.ins
        while k < len(ins):
            mk, ak = ins[k]
            if mk == "label" or (mk, ak) == ("nop", ""):
                k += 1
                continue
            if mk in CONDBR or mk in ("b", "j", "jal", "jalr"):
                return False
            if mk == "jr":
                return True
            rr_, ww_ = rw(mk, ak)
            if r in rr_:
                return True
            if r in ww_:
                return False
            k += 1
        return False

    def live_out(self, k, r):
        """lift4: r is read before written on SOME path from position k (a DFS over branches; a call reads nothing:
        tried a0-a3 as its arguments -- that only added phantom arguments; nor does `jr`)."""
        ins, seen, work = self.ins, set(), [k]
        while work:
            k = work.pop()
            while k < len(ins) and k not in seen:
                seen.add(k)
                mk, ak = ins[k]
                if mk == "label" or (mk, ak) == ("nop", ""):
                    k += 1
                    continue
                if mk == "jr":
                    break                        # a return value is the v0 / f0 live-out rule's business
                rr_, ww_ = rw(mk, ak)
                if r in rr_ and mk not in ("jal", "jalr"):
                    return True
                if mk in CONDBR or mk == "b":
                    d = ins[k + 1] if k + 1 < len(ins) else ("nop", "")
                    if r in rw(*d)[0] and d[0] not in ("jal", "jalr"):
                        return True
                    t = self.labels.get(ak.split(",")[-1]) if self.labels else None
                    if t is None:
                        return True              # unknown target: assume live
                    if r not in rw(*d)[1]:
                        work.append(t)
                        if mk == "b":
                            break
                        k += 2
                        continue
                    break
                if r in ww_:
                    break
                k += 1
        return False

    def postdec_shape(self, clo, jb, d):
        """lift4: `while (n--)` -- the condition block is `daddu T,X,zero` (+ `addiu V,X,-1`), the back branch
        `bnez T`, its delay slot the decrement `addiu X,X,-1` / `andi X,V,0xFF|0xFFFF` [C] LaneIsDriveable x3,
        Render__10CGt2dScene. Returns (X, T) or None."""
        ins = self.ins
        blk = [x for x in ins[clo:jb] if x[0] != "label" and x != ("nop", "")]
        mb, ab = ins[jb]
        if mb != "bnez" or not blk or blk[0][0] != "daddu" or len(blk) > 2:
            return None
        t = [q.strip() for q in blk[0][1].split(",")]
        if t[2] != "zero" or ab.split(",")[0] != t[0]:
            return None
        T, X = t[0], t[1]
        dm, da = d
        dt = [q.strip() for q in da.split(",")]
        if len(blk) == 1:
            ok = dm == "addiu" and dt[0] == X and dt[1] == X and dt[2] in ("-0x1", "-1")
        else:
            v = [q.strip() for q in blk[1][1].split(",")]
            ok = blk[1][0] == "addiu" and v[1] == X and v[2] in ("-0x1", "-1") and v[0] not in (X, T) and \
                dm == "andi" and dt[0] == X and dt[1] == v[0] and dt[2] in ("0xFF", "0xFFFF")
        return (X, T) if ok else None

    def loop(self, blo, bhi, clo, jb, check_first, body=None, inf=None):
        """A counted loop: body [blo, bhi), condition [clo, jb), the branch back at jb (a delay slot ends the body).
        One integer induction register: read before written in the loop, and the body ends with it advanced by a
        constant; every other register the loop writes is unknown at the top of the body."""
        ins = self.ins
        d = ins[jb + 1]
        pd = self.postdec_shape(clo, jb, d) if self.c.get("lift4") and check_first and inf is None else None
        if pd:
            d = None                     # lift4: `while (n--)`: the delay slot's decrement is the condition's
        if d == ("nop", "") or d is None:
            d = None
        else:
            # the back branch's delay slot runs after the test on every iteration and on the exit; when it
            # commutes with the test it is the body's last statement [G]
            if d[0] == "label" or d[0] in CONDBR or d[0] in ("b", "j", "jr", "jal", "jalr"):
                raise Skip("loop branch delay slot")
            rd_, wd_ = rw(*d)
            for mk, ak in ins[clo:jb + 1]:
                if mk == "label":
                    continue
                rc_, wc_ = rw(mk, ak)
                mem = (d[0] in STOREM and mk[0] == "l") or (mk in STOREM and d[0][0] == "l")
                if (wd_ & rc_) or (wc_ & (rd_ | wd_)) or mem:
                    raise Skip("loop branch delay slot")
        if not self.pathmode:
            self.closed(blo, bhi)
            if clo < jb:
                self.closed(clo, jb)
        seq = self.loop_seq(body) if body is not None else [x for x in ins[blo:bhi] + ins[clo:jb + 1]
                                                            if x[0] != "label"]
        if d is not None and body is None:
            seq = seq + [d]
        if check_first:
            # entered at the test: registers in execution order (test, then body)
            if body is not None:
                # test blocks, then the body, then blocks laid out after the loop's back branch (an out-of-line
                # if-body MWCC moved past the exit, which jumps back in: func_0042DF40) -- in execution order
                seq = self.loop_seq([b for b in body if clo - 1 <= b <= jb]) +                     self.loop_seq([b for b in body if b < clo - 1]) + self.loop_seq([b for b in body if b > jb])
            else:
                seq = [x for x in ins[clo:jb + 1] + ins[blo:bhi] if x[0] != "label"] + ([d] if d else [])
            if pd and body is None:
                seq = seq + [ins[jb + 1]]          # lift4: the decrement (taken out of d above)
        written, livein = set(), set()
        for mk, ak in seq:
            r, w = rw(mk, ak)
            livein |= (r - written)
            written |= w
        carried = [r for r in written & livein if r not in ("fcc",)]
        # two carried registers, each written once by `addiu r,r,K`: the smaller step is the counter, the other
        # a derived induction (start + counter * ratio), as from `p[i]` strength-reduced [G]
        derived = None
        if len(carried) == 2:
            steps = {}
            for cr in carried:
                ws = [(mk, ak) for mk, ak in seq if cr in rw(mk, ak)[1]]
                if len(ws) == 1 and ws[0][0] == "addiu":
                    t = [x.strip() for x in ws[0][1].split(",")]
                    if t[0] == cr and t[1] == cr and re.fullmatch(NUM, t[2]):
                        steps[cr] = num(t[2])
            if len(steps) == 2:
                a_, b_ = sorted(carried, key=lambda q: abs(steps[q]))
                if steps[a_] and abs(steps[a_]) != abs(steps[b_]) and steps[b_] % steps[a_] == 0:
                    derived = (b_, steps[b_] // steps[a_], steps[b_])
                    carried = [a_]
        # the counter: a carried register written once by `addiu r,r,K`; every other carried register is a loop
        # variable, a local declared before the loop and assigned its end-of-body value (no counter: a while) [G]
        def single_step(cr):
            ws = [(mk, ak) for mk, ak in seq if cr in rw(mk, ak)[1]]
            if len(ws) == 1 and ws[0][0] == "addiu":
                t = [x.strip() for x in ws[0][1].split(",")]
                return t[0] == cr and t[1] == cr and re.fullmatch(NUM, t[2]) is not None
            if len(ws) == 2 and ws[0][0] == "dsll32" and ws[1][0] == "dsra32":
                a1_, a2_ = ws[0][1].split(","), ws[1][1].split(",")
                if a1_[0] == cr and a2_[:2] == [cr, cr] and a1_[2] == a2_[2] and a1_[2] in ("24", "16"):
                    k_ = seq.index(ws[0])
                    tw = [(mk, ak) for mk, ak in seq[:k_] if a1_[1] in rw(mk, ak)[1]][-1:]
                    if len(tw) == 1 and tw[0][0] == "addiu":
                        t = tw[0][1].split(",")
                        return t[0] == a1_[1] and t[1] == cr and re.fullmatch(NUM, t[2]) is not None
            return False
        # ... and read by the loop test (the branch, or the compare feeding it)
        treg = set(rw(*ins[jb])[0])
        for mk, ak in reversed(seq):
            rr_, ww_ = rw(mk, ak)
            if ww_ & treg and mk in ("slt", "slti", "sltu", "sltiu", "xor", "xori", "subu", "andi", "dsll32",
                                     "dsra32"):
                treg |= rr_
        ind = [cr for cr in carried if single_step(cr) and cr in treg and cr not in FPR and not cr.startswith("f")]
        r = ind[0] if ind else None
        mvregs = sorted(cr for cr in carried if cr != r)
        # v0/f0 set before the loop, written in it and still live at the return: a loop variable too (no calls
        # in the loop; variant (v // 1536) % 2 leaves it out) [G]
        for cr in ("v0", "f0"):
            pre = self.R.get(cr)
            if cr in written and cr not in carried and pre is not None and pre[0] not in ("x", "p", "c", "cf") \
                    and not any(mk in ("jal", "jalr") for mk, ak in seq) and self.live_after(jb + 2, cr):
                self.used_liveout = True
                if not ((self.c.get("variant") or 0) // 1536) % 2:
                    mvregs.append(cr)
        if self.c.get("lift4"):
            # lift4: a register the loop writes (not carried, not the counter) and some path after the loop reads:
            # a variable declared before the loop and assigned in it (`int best = -1; for (..) if (c) best = x;`)
            # [G]; caller-saved registers only in a loop without calls
            hascall = any(mk in ("jal", "jalr") for mk, ak in seq)
            for cr in sorted(written - set(carried) - set(mvregs)):
                if cr in ("fcc", "at", "hi", "lo", "ra", "sp") or cr == r or (derived and cr == derived[0]):
                    continue
                if hascall and cr in CALLER_SAVED:
                    continue
                pre = self.R.get(cr)
                if pre is None or pre[0] == "x" or not self.live_out(jb + 2, cr):
                    continue
                mvregs.append(cr)
                self.used_l4live = True
        l5b = []
        if self.c.get("lift5"):
            # lift5: a register only a break path sets (`found = 1; break;`, hinted by the guard after the loop on an
            # earlier run): a loop variable declared before the loop, assigned before each break [G]
            for cr in (self.c.get("l5brk") or {}).get(blo, []):
                pre = self.R.get(cr)
                if cr not in mvregs and cr != r and cr not in written and pre is not None and pre[0] != "x":
                    mvregs.append(cr)
                    l5b.append(cr)
        if len(mvregs) > (5 if self.c.get("lift4") else 3):      # lift4: up to 5 loop variables
            raise Skip("loop with %d carried registers" % len(carried))
        if r is not None:
            init = self.rd(r)
            lid = len(self.lvars)
            lv = ("lv", lid)
            self.lvars.append({"init": init, "reg": r})
            self.use(init)
        else:
            init, lid, lv = None, None, None
        mvs = []
        for cr in mvregs:
            iv = self.rd(cr)
            self.use(iv)
            self.consume(repr(iv))
            mvs.append(len(self.mvars))
            self.mvars.append({"init": iv, "reg": cr, "isf": cr in FPR or cr.startswith("f")})
            if cr in l5b:
                self.mvars[-1]["brk"] = True        # lift5
                self.used_l5brk = True
        S0 = dict(self.R)
        for x in written:
            self.R[x] = ("x",)
        if lv is not None:
            self.R[r] = lv
        for j in mvs:
            self.R[self.mvars[j]["reg"]] = ("mv", j)
        if derived:
            r2, ratio, K2 = derived
            if init is None or init[0] != "k" or r2 in FPR:
                raise Skip("derived induction with a non-constant start")
            init2 = S0.get(r2)
            if init2 is None or init2[0] == "x":
                raise Skip("reads clobbered/unknown register %s" % r2)
            self.use(init2)
            DV = ("b", "+", init2, lv if ratio == 1 else ("b", "i*", lv, ("k", ratio)))
            if init[1]:
                DV = ("b", "+", DV, ("k", -init[1] * ratio))
            self.R[r2] = DV
        outer = self.stmts
        self.stmts = []
        self.epoch += 1
        if check_first and clo < jb and any(ins[k][0] in ("jal", "jalr") for k in range(clo, jb)):
            pass        # a call in the test (`i < f(x)`): no test values carried into the body; it runs in the test
        elif pd:
            pass        # lift4: `while (n--)`: the test's copy / decrement are the condition's own
        elif check_first and clo < jb:
            # the test's values reach the body (MWCC keeps `*p` from the test for the body's use) [G]
            nl = len(self.loads)
            for k in range(clo, jb):
                mk, ak = ins[k]
                if mk == "label" or (mk, ak) == ("nop", ""):
                    continue
                if mk in CONDBR or mk in ("b", "j", "jr", "jal", "jalr") or mk in STOREM:
                    raise Skip("statements in a loop condition")
                self.step(mk, ak, False)
            for k in range(nl, len(self.loads)):
                self.loads[k]["nodata"] = True      # a re-read of the test's load, not code of its own
        if self.pathmode:
            # continue point: the condition block (entry-jump loops); exit: after the branch back
            self.loopctx.append({"C": jb if inf is not None else clo if check_first else None,
                                 "X": inf if inf is not None else jb + 2, "K": jb, "body": body,   # lift2: body (goto_exit)
                                 "mvbrk": [j for j in mvs if self.mvars[j].get("brk")]})          # lift5
            rr = self.exec_region(blo, bhi)
            LCd = self.loopctx.pop()
            brk_states = LCd.get("brkR", [])          # lift4
            if inf is not None:
                # an infinite loop's end of body: every path that reaches the latch (`b H`)
                cs = LCd.get("contR", []) + ([dict(self.R)] if rr is None else [])
                keep = [q for q in carried + ([derived[0]] if derived else []) if q]
                if not cs or any(x.get(q) != cs[0].get(q) for x in cs[1:] for q in keep):
                    raise Skip("infinite loop latch states differ")
                self.R = dict(cs[0])
            elif rr in ("break", "ret", "goto"):     # lift2: "goto" (goto_exit) leaves like a break
                # every path leaves except through `continue`: the end-of-body state is the continuing paths'
                cs = LCd.get("contR", [])
                keep = [q for q in carried + ([derived[0]] if derived else []) if q]
                # lift4: loop variables every continuing path leaves unchanged need no assignment (`while (n--)`)
                mvs_ = [j for j in mvs if any(x.get(self.mvars[j]["reg"]) != ("mv", j) for x in cs)] \
                    if self.c.get("lift4") else mvs
                if not cs or mvs_ or any(x.get(q) != cs[0].get(q) for x in cs[1:] for q in keep):
                    raise Skip("loop body always leaves" + (" [blo=%d bhi=%d cs=%d mvs=%s]" % (blo, bhi, len(cs), mvs) if DIAG else ""))
                self.R = dict(cs[0])
        else:
            self.exec_range(blo, bhi)
            brk_states = []                             # lift4: region mode (exec_range) has no breaks
        if d is not None:
            self.step(d[0], d[1], False)

        def has(v, t):
            return v == t or (isinstance(v, tuple) and any(has(x, t) for x in v))
        step_k = 0
        narrow = None
        if lv is not None:
            end = self.R.get(r)
            if end and end[0] == "u" and end[1] in ("(signed char)", "(short)"):
                narrow, end = end[1][1:-1], end[2]       # a signed char / short counter (sign-extended step)
                self.lvars[lid]["type"] = narrow
            if not (end and end[0] == "b" and end[1] == "+" and end[2] == lv and end[3][0] == "k"):
                raise Skip("induction step")
            step_k = end[3][1]
        if derived and self.R.get(r2) != ("b", "+", DV, ("k", K2)):
            raise Skip("derived induction step")
        ends = {}
        for j in mvs:
            E = self.R.get(self.mvars[j]["reg"])
            if E is None or E[0] == "x":
                raise Skip("loop variable clobbered")
            ends[j] = E
        if pd:
            js = [j for j in mvs if self.mvars[j]["reg"] == pd[0]]
            if len(js) != 1 or ends[js[0]] != ("mv", js[0]):
                raise Skip("loop branch delay slot (n-- variable written in the body)")
            self.mvars[js[0]]["postdec"] = True
            self.used_l4pd = True
            if self.mvars[js[0]]["init"] == ("p", pd[0]):
                # the parameter itself counts down (BRIEF: advance the parameter, not a copy) [G]
                self.mvars[js[0]]["asparam"] = True
        assigned = []
        for j in mvs:
            if ends[j] == ("mv", j):
                continue
            if self.alias_merges(ends[j], j):
                # `if (c) m = x;` written in place (the merge temporaries' form lays retail's blocks out
                # differently: func_00136380) [G]
                self.use(ends[j])
                self.consume(repr(ends[j]))
                self.mvars[j]["end"] = ends[j]
                continue
            if any(has(ends[j], ("mv", q)) for q in assigned):
                raise Skip("loop variables depend on each other")
            if self.c.get("lift4") and assigned:
                # lift4: a later loop variable's value loaded through an earlier one (`m1 = a[m0].f` after
                # `m0 = ..`) would re-read through the new value: a new epoch binds its loads to temporaries,
                # declared where the body loaded them
                self.epoch += 1
            self.use(ends[j])
            self.consume(repr(ends[j]))
            self.stmts.append(("mvset", j, ends[j]))
            self.mvars[j]["end"] = ends[j]
            assigned.append(j)
        if lv is not None:
            self.R[r] = lv                   # C: the condition reads the variable after its increment
        for j in mvs:
            self.R[self.mvars[j]["reg"]] = ("mv", j)
        if derived:
            self.R[r2] = DV
        n_body = len(self.stmts)
        if clo < jb:
            if self.pathmode:
                skip_ = set()
                for k in range(clo, jb):
                    mk, ak = ins[k]
                    if k in skip_ or mk == "label" or (mk, ak) == ("nop", ""):
                        continue
                    if mk == "jal" and k + 1 < jb and ins[k + 1][0] != "label":
                        # a call in the test (`i < f(x)`): its delay slot first [G]
                        if ins[k + 1] != ("nop", ""):
                            self.step(ins[k + 1][0], ins[k + 1][1], False)
                        self.step(mk, ak, False)
                        skip_.add(k + 1)
                        continue
                    if mk in CONDBR or mk in ("b", "j", "jr", "jal", "jalr"):
                        raise Skip("control flow in a loop condition")
                    self.step(mk, ak, False)
            else:
                self.exec_range(clo, jb)
        if self.c.get("lift4") and inf is None and lv is not None and not check_first and clo == jb and \
                r in rw(*ins[jb])[0]:
            # lift4: the back branch tests the counter register itself (`addiu n,n,-1; ..; bgtz n,L`): it reads the
            # stepped value, `for (n = 5; n > 0; n--)` (the reset to the variable above is for a compare computed
            # in the body) [G]
            R_r = self.R[r]
            self.R[r] = ("b", "+", lv, ("k", step_k))
            c = self.cond(*ins[jb])
            self.R[r] = R_r
            self.used_l4cnt = True
        else:
            c = self.cond(*ins[jb]) if inf is None else ("k", 1)
        extra = [x for x in self.stmts[n_body:] if x[0] != "load"]
        if extra:
            # a call whose result only the test reads is written inside the condition (`i < f(x)`) [G]
            if all(x[0] == "call" and not self.calls[x[1]]["tail"] and repr(("c", x[1])) in repr(c) for x in extra):
                for x in extra:
                    self.calls[x[1]]["inline"] = True
                    self.stmts.remove(x)
                self.used_loopcall = True
            else:
                raise Skip("statements in a loop condition")    # (a load is not a statement: rendered on use)

        def subst(v, a, b):
            if v == a:
                return b
            if isinstance(v, tuple):
                return tuple(subst(x, a, b) for x in v)
            return v
        for j in assigned:
            c = subst(c, ends[j], ("mv", j))     # the test reads the variable just assigned
        if not check_first and (assigned or lv is not None):     # lift5: ungated (audit: base lifter never reaches it; 0 diffs)
            # lift4: a do-while test reading a load the body made through a variable the body then steps
            # (`do { t = *s; ..; s++; } while (t != 0)`) would re-read through the stepped variable: refused
            stepped = [repr(("mv", j)) for j in assigned] + ([repr(lv)] if lv is not None else [])

            def loads_in(v, out):
                if isinstance(v, tuple):
                    if v and v[0] == "l":
                        out.append(v)
                    for x in v[1:]:
                        loads_in(x, out)
                return out
            for Lk in loads_in(c, []):
                L_ = self.loads[Lk[1]]
                if L_.get("nodata"):
                    continue
                D_ = self.deps(L_["root"])
                if any(t in D_ for t in stepped) and n_body > 0 and \
                        any(isinstance(x, tuple) and x[0] == "load" and x[1] == Lk[1] for x in self.stmts[:n_body]):
                    raise Skip("do-while test reads a body load through a stepped variable")
        post = ("b", "+", lv, ("k", step_k))

        def sub(v):
            if v == post:
                return ("lvpost",)
            if isinstance(v, tuple):
                return tuple(sub(x) for x in v)
            return v
        c = sub(c)
        if lv is not None and not check_first and has(c, lv):
            raise Skip("do-while condition reads the pre-increment value" + (" [c=%r lv=%r step=%r blo=%d jb=%d]" % (
                c, lv, step_k, blo, jb) if DIAG else ""))     # lift4: census detail

        def back(v):
            if v == ("lvpost",):
                return lv
            if isinstance(v, tuple):
                return tuple(back(x) for x in v)
            return v
        c = back(c)
        if narrow:
            c = subst(c, ("u", "(%s)" % narrow, lv), lv)      # the test's re-extension of the counter
        if check_first and init is not None and init[0] == "k" and c[0] == "b" and (c[2][0] == "k" or c[3][0] == "k") \
                and not narrow:
            check_first = "goto"
        self.use(c)
        body = self.stmts
        self.stmts = outer
        if lv is not None and (repr(lv) in self.objs or repr(lv) in self.ptr_roots):
            # a pointer stepped by its element size: `T * q = init; ...; q++` [G] element layout
            o = self.objs.get(repr(lv))
            if o is None or step_k <= 0 or any(off < 0 or off >= step_k for off in o["fields"]):
                raise Skip("pointer induction")
            o["stride"] = step_k
            self.lvars[lid]["ptr"] = True
        if not body:
            raise Skip("empty loop body")
        self.stmts.append(("for", lid, c, step_k, body, check_first, mvs))
        self.epoch += 1
        self.R = dict(S0)
        # lift5: a break path that ran code outside the body (an out-of-line `s2 = 1; b exit`) leaves registers the
        # body never writes changed: unknown after the loop (was: their value before it -- wrong code) [C bug fix]
        for st_ in brk_states:
            for x, v_ in st_.items():
                if x not in written and v_ != S0.get(x):
                    self.R[x] = ("x",)
                    if self.c.get("lift5") and re.fullmatch(r"(v[01]|a[0-3]|t[0-9]|s[0-8]|fp)", x):
                        L5_HINT.setdefault(blo, set()).add(x)
        for x in written:
            self.R[x] = ("x",)
            if DIAG:                         # lift2: census detail (rd's "clobbered by a loop")
                if not hasattr(self, "_loopx"):
                    self._loopx = {}
                self._loopx[x] = "counter" if x == r else "derived" if derived and x == derived[0] else "written"
        for j in mvs:
            self.R[self.mvars[j]["reg"]] = ("mv", j)    # after the loop: the variable's last value
        if self.c.get("lift4") and lv is not None and r not in FPR and self.live_out(jb + 2, r) and \
                all(x.get(r) == lv for x in brk_states):
            # lift4: the counter read after the loop (`for (i = 0; ..; i++) if (c) break; use(i)`): declared before
            # the loop, its value after it is the variable's (every break leaves it unchanged) [G]
            self.R[r] = lv
            self.lvars[lid]["out"] = True

    def ool_shape(self, i, j, hi):
        """-> (.Lback position, .Lend position) when the branch at i targets an out-of-line then-body at j."""
        ins = self.ins
        if i + 2 >= j or ins[i + 2][0] != "label" or j - 2 <= i + 2:
            return None
        back = ins[i + 2][1]
        if ins[j - 2][0] != "b" or ins[j - 1][0] == "label":
            return None
        je = self.labels.get(ins[j - 2][1])
        if je is None or je <= j + 2 or je > hi:
            return None
        if ins[je - 2] != ("b", back) or ins[je - 1][0] == "label":
            return None
        # .Lback is reached from the body's jump only; the body and REST are closed regions
        if sorted(self.targets.get(back, [])) != [je - 2]:
            return None
        if sorted(self.targets.get(ins[j][1], [])) != [i]:
            return None
        self.closed(j + 1, je - 2)
        self.closed(i + 3, j - 2)
        return i + 2, je

    def join(self, c, tst, tR, te, est, eR, ee, ool=False):
        """Merge the two paths of an if (est None: no else, eR = the state before) and append the statement."""
        newR, phis, rel = {}, [], []
        for r in sorted(set(tR) | set(eR)):     # sorted: the same source on every run
            x, y = tR.get(r), eR.get(r)
            if x == y:
                newR[r] = x
            elif x is None or y is None or x[0] == "x" or y[0] == "x" or r in ("fcc", "sp", "ra"):
                newR[r] = ("x",)
            elif x[0] == "l" and y[0] == "l" and self.reljoin_ok(x[1], y[1]):
                rel.append((r, x[1]))
                self.loads[x[1]]["relj"] = self.loads[y[1]]["relj"] = True     # not dead: read again below
            else:
                pid = len(self.phis)
                self.phis.append({"a": x, "b": y, "init": est is None, "used": False, "ea": te, "eb": ee})
                tst.append(("assign", pid))
                if est is not None:
                    est.append(("assign", pid))
                newR[r] = ("phi", pid)
                phis.append(pid)
        self.R = newR
        if not tst and not phis:
            raise Skip("empty if body")
        if est is not None and not [y for y in est if y[0] != "load"] and rel and not phis:
            est = None                          # the else path only loaded the field read after the if
        self.stmts.append(("if", c, tst, est, phis, ool))   # ool: retail laid the then-body out of line (block form)
        self.epoch += 1
        for r, k in rel:
            L = self.loads[k]
            key = len(self.loads)
            self.loads[key] = dict(L, epoch=self.epoch, temp=False, slot=len(self.stmts), used=False)
            self.stmts.append(("load", key))
            self.R[r] = ("l", key)

    def reljoin_ok(self, a, b):
        A, B = self.loads[a], self.loads[b]
        if a == b or A["off"] != B["off"] or A["mn"] != B["mn"] or not self.same(A["root"], B["root"]):
            return False
        self.used_reljoin = True
        return not ((self.c.get("variant") or 0) // 786432) % 2

    def sw_chain(self, i):
        """MWCC's lowering of a small switch: compares `li r,K; beq x,r,.Lcase` / `beqz
        x,.Lcase` one after another (cases in reverse source order), the default inline after them, the case bodies
        after that. -> (x register, [(K, case position, li position or None)], default position) or None."""
        ins = self.ins
        out, xr, q = [], None, i
        while q + 1 < len(ins):
            m, a = ins[q]
            ops = a.split(",") if a else []
            li = None
            if m == "addiu" and q != i and len(ops) == 3 and ops[1] == "zero" and re.fullmatch(NUM, ops[2]) and \
                    ins[q + 1][0] == "beq":
                li, K, r = q, num(ops[2]), ops[0]
                q += 1
                m, a = ins[q]
                ops = a.split(",")
            if m == "beq" and len(ops) == 3:
                if li is None:
                    if q != i:
                        break
                    # the first compare's constant is already in its register (its li may be scheduled earlier)
                    kr = [z for z in ops[:2] if self.R.get(z, ("x",))[0] == "k"]
                    if len(kr) != 1:
                        break
                    K, r = self.R[kr[0]][1], kr[0]
                if r not in ops[:2] or ops[0] == ops[1]:
                    break
                x = ops[1] if ops[0] == r else ops[0]
            elif m == "beqz" and len(ops) == 2 and li is None:
                K, x = 0, ops[0]
            else:
                if li is not None:
                    q = li
                break
            if xr is not None and x != xr:
                q = li if li is not None else q
                break
            t = self.labels.get(ops[-1])
            d = ins[q + 1]
            # a scheduled delay slot runs before the compare's branch in C order (func_00285770)
            dok = d == ("nop", "") or (d[0] != "label" and d[0] not in CONDBR and
                                       d[0] not in ("b", "j", "jal", "jr", "jalr") and d[1].split(",")[0] != x)
            if t is None or t <= q or not dok:
                q = li if li is not None else q
                break
            xr = x
            out.append((K, t, li, None if d == ("nop", "") else q + 1))
            q += 2
        if len(out) < 2:
            return None
        chain = set(range(i, q))
        for K, t, li, dl in out:
            if t < q or any(z not in chain and z < q for z in self.targets.get(self.ins[t][1], [])):
                return None
            if li is not None and ins[li][1].split(",")[0] == xr:
                return None
        return xr, out, q

    def join_switch(self, x, sides, dflt, dnone):
        """Merge a switch's paths. sides: [(case values, stmts, R, epoch, result)] in body order; dflt the same
        for the default path (case values None). Appends ("swj", x, [(Ks, stmts, side)], default stmts or None,
        phis); a default that runs nothing is left out (the merged variables start as its values)."""
        live = [S for S in sides + [dflt] if S[4] != "ret"]
        dst, dR = dflt[1], dflt[2]
        if dnone and [x for x in dst if x[0] != "load"] == [("ret", None)] and not \
                [x for x in dst if x[0] == "load" and self.loads[x[1]]["temp"]]:
            # `b <epilogue>; nop` in a void function: no default at all (a `default: return;` puts the epilogue's
            # `ld ra` in that jump's delay slot: func_003CBB60)
            dst[:] = []
        dempty = dnone and not dst
        keys, ki = {}, 0
        for S in sides:
            if id(S) == id(sides[0]):
                keys[id(S)] = "a"
            else:
                keys[id(S)] = "m%d" % ki
                ki += 1
        keys[id(dflt)] = "b"
        newR, phis = {}, []
        if live:
            regs = sorted(set().union(*[set(S[2]) for S in live]))
            for r in regs:
                vals = [S[2].get(r) for S in live]
                # an empty default leaves a variable the cases set uninitialized (`T v;`): its value is unknown
                undef = dempty and dflt[4] != "ret" and (dR.get(r) is None or dR[r][0] == "x") and \
                    all(S[2].get(r) is not None and S[2][r][0] != "x" for S in live if S is not dflt)
                if undef:
                    vals = [S[2].get(r) for S in live if S is not dflt]
                if all(y == vals[0] for y in vals) and not undef:
                    newR[r] = vals[0]
                elif any(y is None or y[0] == "x" for y in vals) or r in ("fcc", "sp", "ra"):
                    newR[r] = ("x",)
                else:
                    pid = len(self.phis)
                    ph = {"init": dempty, "used": False, "more": []}
                    for S in sides + [dflt]:
                        k = keys[id(S)]
                        y = S[2].get(r) if S[4] != "ret" else None
                        if k in ("a", "b"):
                            ph[k] = y
                            ph["e" + k] = S[3]
                        else:
                            ph[k] = y
                            ph["e" + k] = S[3]
                            ph["more"].append(k)
                    if undef:
                        ph["b"], ph["init"] = None, False
                    if any(ph[k] is None for k in ["a"] + ([] if undef else ["b"]) + ph["more"]):
                        raise Skip("switch merge with a returning case")
                    self.phis.append(ph)
                    for S in sides:
                        S[1].append(("assign", pid))
                    if not dempty:
                        dst.append(("assign", pid))
                    newR[r] = ("phi", pid)
                    phis.append(pid)
        self.R = newR
        cl = [(S[0], S[1], keys[id(S)]) for S in sides]
        if dflt[0] is not None:
            if not sides:
                raise Skip("switch with one body")
            cl.insert(dflt[6], (dflt[0], dst, "b"))
            dst = None
        self.stmts.append(("swj", x, cl, None if dempty else dst, phis))
        self.epoch += 1

    def closed(self, lo, hi):
        """Labels strictly inside [lo, hi) are reached only from inside; no return inside."""
        for k in range(lo, hi):
            mk, ak = self.ins[k]
            if mk == "jr":
                raise Skip("return inside an if body")
            if mk == "label":
                if any(not (lo <= q < hi) for q in self.targets.get(ak, [])):
                    raise Skip("label in an if body reached from outside")

    def cfg(self):
        """Basic blocks (start positions), successors and immediate post-dominators (EXIT = -1). No loops."""
        ins = self.ins
        n = len(ins)
        starts = {0}
        for k, (m, a) in enumerate(ins):
            if m == "label":
                starts.add(k)
            if m in CONDBR or m in ("b", "j", "jr"):
                if k + 2 < n:
                    starts.add(k + 2)
        starts = sorted(starts)
        succ, term = {}, {}
        for bi, b in enumerate(starts):
            nxt = starts[bi + 1] if bi + 1 < len(starts) else n
            ss = None
            for k in range(b, nxt):
                m, a = ins[k]
                if m in CONDBR or m in ("b", "j", "jr"):
                    term[k] = b
                    if m == "jr" or m == "j":
                        ss = [-1]
                    else:
                        t = self.labels.get(a.split(",")[-1])
                        if t is None:
                            raise Skip("branch to an unknown label")
                        ss = [t] if m == "b" else [t, k + 2]
                    break
            if ss is None:
                ss = [nxt] if nxt < n else [-1]
            succ[b] = ss
            self.bend[b] = nxt
        # back edges: conditional branches to an earlier label (a loop's test jumping back to its header); with them
        # removed the graph must be acyclic (an ool then-body's jump back is a forward edge in CFG terms)
        def reaches(x0, goal):
            seen, work = {x0}, [x0]
            while work:
                x = work.pop()
                if x == goal:
                    return True
                for t in succ[x]:
                    if t != -1 and t not in seen:
                        seen.add(t)
                        work.append(t)
            return False
        # a back edge goes to a block that dominates its source (an out-of-line then-body jumping back into
        # its loop is earlier by position but not a back edge: func_00136380)
        dom = {x: set(starts) for x in starts}
        dom[0] = {0}
        pr0 = {}
        for x in starts:
            for t in succ[x]:
                if t != -1:
                    pr0.setdefault(t, []).append(x)
        changed = True
        while changed:
            changed = False
            for x in starts:
                if x == 0:
                    continue
                ps = [dom[q] for q in pr0.get(x, []) if q in dom]
                nd = (set.intersection(*ps) if ps else set()) | {x}
                if nd != dom[x]:
                    dom[x], changed = nd, True
        backs, infs = [], set()
        for k, b in term.items():
            m, a = ins[k]
            if m == "b":
                t = self.labels.get(a)
                tk = [x for x in term if term[x] == t]
                to_test = tk and ins[tk[0]][0] in CONDBR and \
                    (self.labels.get(ins[tk[0]][1].split(",")[-1]) or k + 1) <= tk[0]
                if t is not None and t <= k and t in dom.get(b, ()) and not to_test:
                    backs.append((b, t))
                    infs.add((b, t))
            if m in CONDBR:
                t = self.labels.get(a.split(",")[-1])
                if t is not None and t <= k and reaches(t, b) and t in dom.get(b, ()):
                    backs.append((b, t))
                elif t is not None and t <= k and reaches(t, b) and t >= 2 and ins[t - 2][0] == "b":
                    backs.append((b, t))     # an entry-jump loop (`b C` before the header): entered at its test
        preds = {}
        for x in starts:
            for t in succ[x]:
                preds.setdefault(t, []).append(x)
        succ0 = {x: list(t) for x, t in succ.items()}     # before inner loops drop their back edges
        for u, H in backs:
            k = max(x for x in term if term[x] == u)
            if H in self.loops:
                raise Skip("two back edges to one header")
            # the loop: blocks reachable from H (without back edges) that reach u (H need not dominate u: an
            # entry-jump loop is entered at its condition block)
            # an inner loop's back edge (header after H, latch before u) stays in: its body is part of this loop
            bset = set(e for e in backs if not (e[1] > H and e[0] < u))
            if self.c.get("lift5"):
                # lift5: an inner loop laid out after this loop's latch (an out-of-line inner loop: its header and
                # latch past u) is still inner when H, or the entry jump's target, dominates its header [G]
                cj0 = self.labels.get(ins[H - 2][1]) if H >= 2 and ins[H - 2][0] == "b" else None
                bset = set(e for e in bset if not (e[1] != H and (H in dom.get(e[1], ()) or
                                                                  (cj0 is not None and cj0 in dom.get(e[1], ())))))
            fwd, work = {H}, [H]
            while work:
                x = work.pop()
                for t in succ0[x]:
                    if t != -1 and (x, t) not in bset and t not in fwd:
                        fwd.add(t)
                        work.append(t)
            body, work = {u}, [u]
            while work:
                x = work.pop()
                if x == H:
                    continue
                for pr in preds.get(x, []):
                    if pr not in body and pr in fwd and (pr, x) not in bset:
                        body.add(pr)
                        work.append(pr)
            body.add(H)
            # entry-jump loop: `b C` right before the header label, C a block of the loop
            cpos = None
            if H >= 2 and ins[H - 2][0] == "b" and (u, H) not in infs:
                cj = self.labels.get(ins[H - 2][1])
                if cj is not None and cj in body and cj != H:
                    cpos = cj
            for x in body:
                for pr in preds.get(x, []):
                    if pr in body:
                        continue
                    if x == H or (cpos is not None and x == cpos and term.get(H - 2) == pr):
                        continue
                    raise Skip("loop entered in the middle" + (" [H=%d x=%d pr=%d cpos=%s u=%d]" % (H, x, pr, cpos, u) if DIAG else ""))
            if (u, H) in infs:
                # the latch falls to the loop's one exit (as a do-while's back branch does)
                exits = {t for x in body for t in succ[x] if t not in body and t != -1}
                # an exit into the shared return block is a `return` of its own; one other exit is the break
                # (so is an exit whose code runs on to the return without meeting the break's: the last exit is
                # taken as the break [G])
                nonret = sorted(t for t in exits if not self.is_ret_block(t))
                if not exits:
                    raise Skip("infinite loop without an exit")
                X = nonret[-1] if nonret else min(exits)
                for e in nonret[:-1]:
                    if reaches(e, X):
                        raise Skip("infinite loop with %d exits" % len(nonret))
                self.loops[H] = ("inf", k, body, X)
                succ[u] = [X]
                continue
            self.loops[H] = (cpos, k, body)
            succ[u] = [t for t in succ[u] if t != H]
        state = {}

        def acyclic(x):
            state[x] = 1
            for t in succ[x]:
                if t == -1:
                    continue
                if state.get(t) == 1:
                    raise Skip("loop closed by an unconditional jump")
                if t not in state:
                    acyclic(t)
            state[x] = 2
        acyclic(0)
        nodes = starts + [-1]
        pdom = {x: set(nodes) for x in nodes}
        pdom[-1] = {-1}
        changed = True
        while changed:
            changed = False
            for x in reversed(starts):
                new = set.intersection(*[pdom[t] for t in succ[x]]) | {x}
                if new != pdom[x]:
                    pdom[x], changed = new, True
        ipdom = {}
        for x in starts:
            strict = pdom[x] - {x}
            for d in strict:
                if pdom[d] >= strict:
                    ipdom[x] = d
                    break
        self.term, self.ipdom = term, ipdom
        self.succ_fwd = succ                     # lift2: forward successors (back edges dropped), for goto_exit

    def is_ret_block(self, p):
        """The block at p is only the epilogue and `jr ra` (+ delay)."""
        for k in range(p, len(self.ins)):
            m, a = self.ins[k]
            if m == "label" or (m, a) == ("nop", ""):
                continue
            if m == "jr":
                d = self.ins[k + 1]
                return d == ("nop", "") or (d[0] in ("addiu", "daddiu") and d[1].startswith("sp,sp,"))
            if m in ("ld", "lq", "lwc1") and a.endswith("(sp)"):
                continue
            if m in ("addiu", "daddiu") and a.startswith("sp,sp,"):
                continue
            return False
        return False

    def loop_seq(self, body):
        """The instructions of a loop's blocks (labels dropped)."""
        out = []
        for b in sorted(body):
            out += [x for x in self.ins[b:self.bend[b]] if x[0] != "label"]
        return out

    def goto_exit(self, i):
        """lift2 (2026-10-26): a path inside a loop reaching a block outside it that is neither the loop's exit nor
        its continue point, but one the exit runs on into (`for (...) { if (c) goto found; } t = 0; found: ...`, the
        hand pattern for find loops: BRIEF a88/a89/a171) -> a ("goto", label) statement; the state is merged at the
        label (goto_merge). Only blocks reachable from the loop's exit (a block that only returns is not one)."""
        LC = self.loopctx[-1]
        B = LC.get("body")
        if B is None or i == -1 or i not in self.bend or i in B or i == LC["X"] or i == LC["C"]:
            return False
        if any(i == L2["X"] or i == L2["C"] for L2 in self.loopctx[:-1]) or self.is_ret_block(i):
            return False
        if not hasattr(self, "_reach"):
            self._reach = {}
        X = LC["X"]
        if X not in self._reach:
            seen, work = {X}, [X]
            while work:
                x = work.pop()
                for t in self.succ_fwd.get(x, []):
                    if t != -1 and t not in seen:
                        seen.add(t)
                        work.append(t)
            self._reach[X] = seen
        if i not in self._reach[X]:
            return False
        walked = i in getattr(self, "glabels", ()) and not (self.gpend.get(i))
        if walked and self.c.get("lift4"):
            # lift4: path mode walked this region before (a region reached from two ifs is walked once per path):
            # a fresh label name for this walk's copy
            self.glabels.discard(i)
            self.gwalk = getattr(self, "gwalk", {})
            self.gwalk[i] = self.gwalk.get(i, 0) + 1
            self.used_l4goto = True
        elif i in getattr(self, "glabels", ()) or (i in self.gpend and self.gpend[i] and not self.c.get("lift4")):
            raise Skip("two gotos to one label" + (" [label walked]" if DIAG and i in getattr(self, "glabels", ()) else ""))
            # lift4: several gotos to one label (goto_merge merges them all)
        if i in self.gpend and self.gpend[i]:
            self.used_l4goto = True
        st = ("goto", "g%d" % i if not getattr(self, "gwalk", {}).get(i) else "g%d_%d" % (i, self.gwalk[i]))   # lift4: _N
        self.stmts.append(st)
        self.gpend.setdefault(i, []).append((dict(self.R), st, self.epoch))
        self.used_goto = True
        return True

    def goto_merge(self, T):
        """lift2: at a goto's target: merge the goto's state with the fall-through one (differing registers become
        merged variables declared ahead of the statement holding the goto, assigned before the goto and here), then
        the label. The fall-through statements since that statement are braced (no declaration crosses the jump)."""
        G_ = self.gpend.pop(T)
        if len(G_) > 1:
            return self.goto_merge_n(T, G_)          # lift4
        (Rg, gst, ep), = G_
        if not hasattr(self, "glabels"):
            self.glabels = set()
        if T in self.glabels:
            raise Skip("goto label walked twice")
        self.glabels.add(T)

        def holds(st):
            if st is gst:
                return True
            if st[0] == "if":
                return any(holds(y) for y in st[2]) or (st[3] is not None and any(holds(y) for y in st[3]))
            if st[0] == "swj":
                return any(holds(y) for _, b, _ in st[2] for y in b) or (st[3] is not None and any(holds(y) for y in st[3]))
            if st[0] == "for":
                return any(holds(y) for y in st[4])
            return False
        idx = [q for q, st in enumerate(self.stmts) if holds(st)]
        if len(idx) != 1:
            raise Skip("goto target in another block")
        idx = idx[0]
        cur, newR, pids = dict(self.R), {}, []
        for r in sorted(set(cur) | set(Rg)):
            x, y = Rg.get(r), cur.get(r)
            if x == y:
                newR[r] = x
            elif x is None or y is None or x[0] == "x" or y[0] == "x" or r in ("fcc", "sp", "ra"):
                newR[r] = ("x",)
            else:
                pid = len(self.phis)
                self.phis.append({"a": x, "b": y, "init": False, "used": False, "ea": ep, "eb": self.epoch})
                newR[r] = ("phi", pid)
                pids.append(pid)

        def put(lst):
            for q, st in enumerate(lst):
                if st is gst:
                    lst[q:q] = [("gset", pid, "a") for pid in pids]
                    return True
                if st[0] == "if" and (put(st[2]) or (st[3] is not None and put(st[3]))):
                    return True
                if st[0] == "swj" and (any(put(b) for _, b, _ in st[2]) or (st[3] is not None and put(st[3]))):
                    return True
                if st[0] == "for" and put(st[4]):
                    return True
            return False
        put(self.stmts)
        tail = self.stmts[idx + 1:]
        del self.stmts[idx + 1:]
        if [y for y in tail if y[0] != "load"]:
            self.stmts.append(("bopen",))
            self.stmts.extend(tail + [("gset", pid, "b") for pid in pids])
            self.stmts.append(("bclose",))
        else:
            self.stmts.extend(tail + [("gset", pid, "b") for pid in pids])
        self.stmts[idx:idx] = [("gdecl", pids)]
        self.stmts.append(("label", gst[1]))         # lift4: the goto's own name ("g%d" % T, or a later walk's)
        self.R = newR
        self.epoch += 1

    def goto_merge_n(self, T, G_):
        """lift4: goto_merge for several gotos to one label: the merged variables take one value per goto ("a",
        then "c", "d", ...: a phi's "more" keys) and the fall-through's ("b"); declared ahead of the first
        statement holding a goto, the fall-through statements from there on braced."""
        if not hasattr(self, "glabels"):
            self.glabels = set()
        if T in self.glabels:
            raise Skip("goto label walked twice")
        self.glabels.add(T)
        gsts = [g[1] for g in G_]

        def holds(st, gst):
            if st is gst:
                return True
            if st[0] == "if":
                return any(holds(y, gst) for y in st[2]) or (st[3] is not None and any(holds(y, gst) for y in st[3]))
            if st[0] == "swj":
                return any(holds(y, gst) for _, b, _ in st[2] for y in b) or \
                    (st[3] is not None and any(holds(y, gst) for y in st[3]))
            if st[0] == "for":
                return any(holds(y, gst) for y in st[4])
            return False
        idxs = []
        for gst in gsts:
            ix = [q for q, st in enumerate(self.stmts) if holds(st, gst)]
            if len(ix) != 1:
                raise Skip("goto target in another block")
            idxs.append(ix[0])
        idx = min(idxs)
        keys = ["a"] + [chr(ord("c") + k) for k in range(len(G_) - 1)]
        cur, newR, pids = dict(self.R), {}, []
        for r in sorted(set(cur).union(*[set(g[0]) for g in G_])):
            vals = [g[0].get(r) for g in G_] + [cur.get(r)]
            if all(v == vals[0] for v in vals):
                newR[r] = vals[0]
            elif any(v is None or v[0] == "x" for v in vals) or r in ("fcc", "sp", "ra"):
                newR[r] = ("x",)
            else:
                pid = len(self.phis)
                ph = {"init": False, "used": False, "b": cur.get(r), "eb": self.epoch, "more": []}
                for k, (Rg, gst, ep) in zip(keys, G_):
                    ph[k] = Rg.get(r)
                    ph["e" + k] = ep
                    if k != "a":
                        ph["more"].append(k)
                self.phis.append(ph)
                newR[r] = ("phi", pid)
                pids.append(pid)

        def put(lst, gst, k):
            for q, st in enumerate(lst):
                if st is gst:
                    lst[q:q] = [("gset", pid, k) for pid in pids]
                    return True
                if st[0] == "if" and (put(st[2], gst, k) or (st[3] is not None and put(st[3], gst, k))):
                    return True
                if st[0] == "swj" and (any(put(b, gst, k) for _, b, _ in st[2]) or (st[3] is not None and put(st[3], gst, k))):
                    return True
                if st[0] == "for" and put(st[4], gst, k):
                    return True
            return False
        for k, gst in zip(keys, gsts):
            put(self.stmts, gst, k)
        idx = min(q for q, st in enumerate(self.stmts) if any(holds(st, g) for g in gsts))
        tail = self.stmts[idx + 1:]
        del self.stmts[idx + 1:]
        if [y for y in tail if y[0] != "load"]:
            self.stmts.append(("bopen",))
            self.stmts.extend(tail + [("gset", pid, "b") for pid in pids])
            self.stmts.append(("bclose",))
        else:
            self.stmts.extend(tail + [("gset", pid, "b") for pid in pids])
        self.stmts[idx:idx] = [("gdecl", pids)]
        self.stmts.append(("label", gsts[0][1]))
        self.R = newR
        self.epoch += 1

    def l5_brkset(self, LC):
        """lift5: before a break, the loop variables only break paths set take this path's value."""
        for j in LC.get("mvbrk", ()):
            reg = self.mvars[j]["reg"]
            v = self.R.get(reg)
            if v == ("mv", j):
                continue
            if v is None or v[0] == "x":
                raise Skip("break-path variable clobbered")
            self.use(v)
            self.consume(repr(v))
            self.stmts.append(("mvset", j, v))
            self.R[reg] = ("mv", j)

    def exec_region(self, pos, stop):
        """Region mode: run from pos until the block at `stop` (EXIT -1: the function's return). Returns "ret" when
        the path returned (a ("ret", value) statement is appended), else None."""
        ins = self.ins
        i = pos
        while True:
            if self.c.get("unrot") and self.loopctx and self.goto_exit(i):
                return "goto"
            if i == stop and self.loopctx and i == self.loopctx[-1]["X"] and i != -1 and self.c.get("unrot"):
                # lift2: a side that reaches the loop's exit at an if's join is a break (the join of `if (c) break;`
                # at the end of an entry-jump loop's body is the exit itself: GetParamFromDist__14CB3TrafficLaneFf)
                self.l5_brkset(self.loopctx[-1])          # lift5
                self.stmts.append(("break",))
                self.loopctx[-1].setdefault("brkR", []).append(dict(self.R))     # lift4
                return "break"
            if i == stop and not (self.retjoin and self.is_ret_block(stop)):
                return None
            if i == stop:
                stop = -1                    # a join at the shared return block: this path returns on its own
            if i in self.gpend:
                self.goto_merge(i)           # lift2: the label of a goto out of a loop
            if self.loopctx:
                LC = self.loopctx[-1]
                if LC["C"] is not None and i == LC["C"]:
                    LC.setdefault("contR", []).append(dict(self.R))
                    return "cont"
                if i == LC["X"]:
                    self.l5_brkset(LC)                    # lift5
                    self.stmts.append(("break",))
                    LC.setdefault("brkR", []).append(dict(self.R))     # lift4
                    return "break"
            self.nsteps += 1
            self._pos = (i, len(self.loopctx))
            if self.nsteps > 6000:
                raise Skip("region walk too long")
            if self.loopctx and m_is_latch(self, i):
                raise Skip("continue to a do-while's test")
            if i >= len(ins):
                raise Skip("region ran off the end")
            m, a = ins[i]
            if m == "label":
                if i in self.loops and self.loops[i][0] == "inf":
                    _, k, body, X = self.loops[i]
                    self.loop(i + 1, k, k, k, check_first=False, body=body, inf=X)
                    i = X
                    continue
                if i in self.loops and self.loops[i][0] is None:
                    cpos, k, body = self.loops[i]
                    self.loop(i + 1, k, k, k, check_first=False, body=body)
                    i = k + 2
                    continue
                i += 1
                continue
            if m == "b" and i + 2 in self.loops and self.loops[i + 2][0] == self.labels.get(a):
                cpos, k, body = self.loops[i + 2]
                d = ins[i + 1]
                if d != ("nop", ""):
                    self.step(d[0], d[1], False)
                self.loop(i + 3, cpos, cpos + 1, k, check_first=True, body=body)
                i = k + 2
                continue
            if m in ("jal", "jalr", "jr", "j"):
                d = ins[i + 1]
                if d[0] == "label":
                    raise Skip("delay slot across a label")
                self.step(d[0], d[1], False)
                self.step(m, a, m in ("jr", "j"))
                if m in ("jr", "j"):
                    rv = None if self.ret == "tail" else self.ret_value(self.ret)
                    if rv:
                        self.use(rv[0])
                    # a call's result left in v0: the value this path returns if another path returns an int
                    alt = None
                    if rv is None and self.ret not in (None, "tail") and self.ret[0] and self.ret[0][0] == "c":
                        alt = (self.ret[0], False)
                    rs = ("ret", rv)
                    self.path_alts.append((alt, rs))
                    self.path_rvs.append(rv)
                    self.path_raw.append(self.ret if isinstance(self.ret, tuple) else None)   # lift5
                    self.stmts.append(rs)
                    self.ret = None
                    return "ret"
                i += 2
                continue
            if m == "b":
                d = ins[i + 1]
                if d != ("nop", ""):
                    self.step(d[0], d[1], False)
                i = self.labels[a]
                continue
            sw = self.sw_chain(i) if m in ("beq", "beqz") else None
            if sw:
                self.used_swj = True
            if sw and ((self.c.get("variant") or 0) // 196608) % 2:
                sw = None                    # variant: the chain as ifs (`x == A || x == B`: func_00468D10)
            if sw:
                xr, cases, dpos = sw
                join = self.ipdom.get(self.term[i], -1)
                self.npaths += len(cases)
                if self.npaths > (NPATHS_MAX_UNROT if self.c.get("unrot") else NPATHS_MAX):
                    raise Skip("too many branches")
                xv = self.rd(xr)
                self.use(xv)
                Rs = []
                for K, t, li, dl in cases:
                    if li is not None:
                        self.step(ins[li][0], ins[li][1], False)
                    if dl is not None:
                        self.step(ins[dl][0], ins[dl][1], False)
                    Rs.append(dict(self.R))
                R0, outer = dict(self.R), self.stmts
                # source order: the compares run in reverse; a body several cases share
                # takes its labels in that order, and the default when it falls into a case body (func_00450E10)
                bodies, order = {}, []
                for (K, t, li, dl), Rk in reversed(list(zip(cases, Rs))):
                    if t not in bodies:
                        bodies[t] = [Rk, []]
                        order.append(t)
                    bodies[t][1].append(K)
                if dpos in bodies:
                    bodies[dpos][1].append("default")
                sides, dflt = [], None
                for t in order:
                    self.R, self.stmts = dict(bodies[t][0]), []
                    self.epoch += 1
                    r = self.exec_region(t, join)
                    if r in ("break", "cont", "goto"):      # lift2: + goto
                        raise Skip("switch case leaves the loop")
                    sides.append((bodies[t][1], self.stmts, dict(self.R), self.epoch, r))
                    if t == dpos:
                        dflt = sides.pop()
                        dflt = dflt + ("share", len(sides))
                if dflt is None:
                    self.R, self.stmts = dict(R0), []
                    self.epoch += 1
                    r = self.exec_region(dpos, join)
                    if r in ("break", "cont", "goto"):      # lift2: + goto
                        raise Skip("switch case leaves the loop")
                    dflt = (None, self.stmts, dict(self.R), self.epoch, r)
                self.stmts = outer
                dnone = dflt[0] is None and (dpos == join or (ins[dpos][0] == "b" and
                                             self.labels.get(ins[dpos][1]) == join and ins[dpos + 1] == ("nop", "")))
                self.join_switch(xv, sides, dflt, dnone)
                if all(S[4] == "ret" for S in sides + [dflt]):
                    return "ret"
                i = join
                if i == -1:
                    raise Skip("region join at the exit without a return")
                continue
            if m in CONDBR:
                self.npaths += 1
                if self.npaths > (NPATHS_MAX_UNROT if self.c.get("unrot") else NPATHS_MAX):
                    raise Skip("too many branches")
                j = self.labels.get(a.split(",")[-1])
                join = self.ipdom.get(self.term[i], -1)
                if self.c.get("lift4") and self.loopctx and self.loopctx[-1]["C"] is None and \
                        self.loopctx[-1].get("K") is not None and stop == self.loopctx[-1]["K"]:
                    # lift4: inside a do-while body, an if whose join lies outside the loop (one side leaves it:
                    # `if (--n == 0) { *d = 0; break; }`) joins at the latch instead -- the staying side runs on to
                    # the test (else "continue to a do-while's test") [G] ds_strnzcpy-like copies (func_004655C0)
                    LCb = self.loopctx[-1].get("body")
                    K_ = self.loopctx[-1]["K"]
                    if join == -1 or (join > K_ and not (LCb and join in LCb)) or join < pos:
                        join = K_
                        self.used_l4latch = True
                c = self.cond(m, a)
                d = ins[i + 1]
                if d[0] == "label":
                    raise Skip("delay slot across a label")
                if d != ("nop", ""):
                    self.step(d[0], d[1], False)
                self.use(c)
                R0, e0, outer = dict(self.R), self.epoch, self.stmts
                sides = []
                for start in (j, i + 2):
                    self.R = dict(R0)
                    self.stmts = []
                    if sides and sides[0][3] == "ret" and all(x[0] in ("ret", "load") for x in sides[0][0]):
                        self.epoch = e0          # after a guard that only returns, nothing has changed
                    else:
                        self.epoch += 1
                    r = self.exec_region(start, join)
                    sides.append((self.stmts, dict(self.R), self.epoch, r))
                self.stmts = outer
                (tst, tR, te, tr), (fst, fR, fe, fr) = sides
                if ((self.c.get("variant") or 0) // 48) % 2:
                    # variant: the fall-through side is the then-branch
                    c, (tst, tR, te, tr), (fst, fR, fe, fr) = self.neg(c), (fst, fR, fe, fr), (tst, tR, te, tr)
                END = ("ret", "break", "cont", "goto")     # lift2: + goto (goto_exit)
                if tr == "cont" and fr == "cont":
                    # both sides reach the loop's continue point: an ordinary if/else merged there
                    if not tst and tR == R0:
                        c, (tst, tR, te), (fst, fR, fe) = self.neg(c), (fst, fR, fe), (tst, tR, te)
                    plain = not fst and fR == R0
                    self.join(c, tst, tR, te, None if plain else fst, R0 if plain else fR, e0 if plain else fe,
                              ool=True)
                    return "cont"
                if tr == "cont" and fr != "cont":
                    tst = tst + [("continue",)]
                if tr in END and fr in END:
                    self.stmts.append(("if", c, tst, None, [], True))
                    self.stmts.extend(fst)
                    return fr
                if tr in END or fr in END:
                    if fr in END:
                        if fr == "cont":
                            fst = fst + [("continue",)]
                        c, (tst, tR, te, tr), (fst, fR, fe, fr) = self.neg(c), (fst, fR, fe, fr), (tst, tR, te, tr)
                    self.stmts.append(("if", c, tst, None, [], True))
                    self.stmts.extend(fst)
                    self.R = fR
                    if not all(x[0] in ("ret", "load", "assign", "break", "continue") for x in tst):
                        self.epoch += 1          # (a guard that only leaves changes nothing the rest reads)
                else:
                    if not tst and tR == R0:
                        c, (tst, tR, te), (fst, fR, fe) = self.neg(c), (fst, fR, fe), (tst, tR, te)
                    plain = not fst and fR == R0
                    self.join(c, tst, tR, te, None if plain else fst, R0 if plain else fR, e0 if plain else fe,
                              ool=True)
                i = join
                if i == -1:
                    raise Skip("region join at the exit without a return")
                continue
            if m.startswith("b") and m.endswith("l") and m != "bal":
                raise Skip("%s (likely branch)" % m)
            self.step(m, a, False)
            i += 1

    def exec_range(self, lo, hi):
        if self.pathmode:
            if lo != 0:
                raise Skip("region mode inside a block")
            self.cfg()
            # variant (v // 96) % 2: paths joining at the shared return block merge into one variable
            self.retjoin = not ((self.c.get("variant") or 0) // 96) % 2
            r = self.exec_region(0, -1)
            if r != "ret":
                raise Skip("region mode: no return")
            if any(self.gpend.values()):
                raise Skip("goto target not reached")     # lift2
            self.ret = "done"
            return
        ins = self.ins
        i = lo
        while i < hi:
            m, a = ins[i]
            if m == "label":
                back = [q for q in self.targets.get(a, []) if q > i]
                if back:
                    # do-while: .Lbody: BODY+COND; bcond .Lbody; nop
                    jb = back[0]
                    if len(back) != 1 or jb >= hi or ins[jb][0] not in CONDBR or self.targets.get(a) != back:
                        raise Skip("loop shape")
                    self.loop(i + 1, jb, jb, jb, check_first=False)
                    i = jb + 2
                    continue
                i += 1
                continue
            if m in ("jal", "j", "jr", "jalr"):
                if i + 1 >= hi or ins[i + 1][0] == "label":
                    raise Skip("delay slot across a label")
                d = ins[i + 1]
                self.step(d[0], d[1], False)
                self.step(m, a, i + 2 >= len(ins))
                i += 2
                continue
            if m in CONDBR:
                tgt = a.split(",")[-1]
                j = self.labels.get(tgt)
                if j is None or j <= i + 1 or j > hi:
                    raise Skip("branch shape (backward / out of the block)")
                ool = self.ool_shape(i, j, hi)
                if ool:
                    back, je = ool
                    c = self.cond(m, a)
                    d = ins[i + 1]
                    if d != ("nop", ""):
                        self.step(d[0], d[1], False)   # the delay slot runs before the if in C order
                    self.use(c)
                    before = dict(self.R)
                    e0 = self.epoch
                    outer = self.stmts
                    self.stmts = []
                    self.epoch += 1
                    self.exec_range(j + 1, je - 2)
                    dd = ins[je - 1]
                    if dd != ("nop", ""):
                        self.step(dd[0], dd[1], False)
                    tst = self.stmts
                    self.stmts = outer
                    self.join(c, tst, dict(self.R), self.epoch, None, before, e0, ool=True)
                    # REST, then on at .Lend
                    self.exec_range(i + 3, j - 2)
                    dd = ins[j - 1]
                    if dd != ("nop", ""):
                        self.step(dd[0], dd[1], False)
                    i = je
                    continue
                self.closed(i + 2, j)
                c = self.cond(m, a)
                d = ins[i + 1]
                if d[0] == "label":
                    raise Skip("delay slot across a label")
                if d != ("nop", ""):
                    self.step(d[0], d[1], False)       # the delay slot runs before the if in C order
                self.use(c)
                # if/else: the then-part ends `b JOIN; delay` just before the else label
                j2 = None
                if j - 2 > i + 1 and ins[j - 2][0] == "b" and ins[j - 1][0] != "label":
                    j2 = self.labels.get(ins[j - 2][1])
                    if j2 is None or j2 <= j or j2 > hi:
                        raise Skip("else branch shape")
                    self.closed(j + 1, j2)
                before = dict(self.R)
                e0 = self.epoch
                outer = self.stmts
                self.stmts = []
                self.epoch += 1
                if j2 is None:
                    self.exec_range(i + 2, j)
                else:
                    self.exec_range(i + 2, j - 2)
                    dd = ins[j - 1]
                    if dd != ("nop", ""):
                        self.step(dd[0], dd[1], False)
                tst, tR, te = self.stmts, dict(self.R), self.epoch
                est, eR, ee = None, before, e0
                if j2 is not None:
                    self.R = dict(before)
                    self.stmts = []
                    self.epoch += 1
                    self.exec_range(j, j2)
                    est, eR, ee = self.stmts, dict(self.R), self.epoch
                self.stmts = outer
                self.join(self.neg(c), tst, tR, te, est, eR, ee)
                i = (j2 if j2 is not None else j)
                continue
            if m == "b":
                jc = self.labels.get(a)
                if jc is not None and jc > i + 2 and ins[i + 2][0] == "label" and ins[i + 1][0] != "label":
                    jb = self.loop_branch(ins[i + 2][1], jc, hi)
                    if jb is not None:
                        d = ins[i + 1]
                        if d != ("nop", ""):
                            self.step(d[0], d[1], False)
                        if sorted(self.targets.get(a, [])) != [i]:
                            raise Skip("loop condition reached from elsewhere")
                        self.loop(i + 3, jc, jc + 1, jb, check_first=True)
                        i = jb + 2
                        continue
                        i = jb + 2
                        continue
                raise Skip("b (else / unstructured)")
            if m.startswith("b") and m.endswith("l") and m != "bal":
                raise Skip("%s (likely branch)" % m)
            self.step(m, a, False)
            i += 1

    def step(self, m, a, last):
        R = self.R
        self._cur = (m, a)
        ops = a.split(",") if a else []
        g_ = re.fullmatch(r"(\w+),(%s)\(sp\)" % NUM, a) if a.endswith("(sp)") else None
        if g_ and getattr(self, "frame", None) and num(g_.group(2)) >= self.frame:
            k_, rem = divmod(num(g_.group(2)) - self.frame, 8)
            NARROW = {"lb": "signed char", "lbu": "unsigned char", "lh": "short", "lhu": "unsigned short"}
            if m not in ("lw", "ld") and m not in NARROW or rem or k_ >= len(STK):
                raise Skip("stack argument access %s %s" % (m, a))
            if m in NARROW:
                if self.nparams.get(STK[k_], NARROW[m]) != NARROW[m]:
                    raise Skip("stack argument read as two widths")
                self.nparams[STK[k_]] = NARROW[m]     # a narrow parameter in its 8-byte slot [G]
            R[g_.group(1)] = ("p", STK[k_])
            return
        if (m, a) == ("nop", ""):
            return
        if self.v4tmp and a.endswith("(sp)") and len(ops) == 2 and re.fullmatch(r"%s\(sp\)" % NUM, ops[1]):
            k_ = num(ops[1][:-4])
            for X, lanes in self.v4tmp.items():
                if m in ("sw", "swc1") and X <= k_ < X + 16:
                    v = self.rd(ops[0])
                    if m == "sw":
                        v = ("fk", v[1] & 0xFFFFFFFF) if v[0] == "k" else v[1] if v[0] == "fbits" else None
                    if v is None:
                        raise Skip("vector constructor lane from an integer")
                    lanes[(k_ - X) // 4] = v
                    return
                if m == "lq" and k_ == X:
                    if None in lanes:
                        raise Skip("vector constructor read before its four lanes")
                    R[ops[0]] = ("v4ctor", tuple(lanes))
                    return
        # prologue / epilogue
        if m in ("addiu", "daddiu") and len(ops) == 3 and ops[0] == "sp" and ops[1] == "sp":
            return
        if m == "sw" and a.endswith("(sp)") and re.fullmatch(r"%s\(sp\)" % NUM, ops[1]) and \
                num(ops[1][:-4]) in self.outargs:
            # a 32-bit outgoing argument (9th or later); the store guard below only admits 64/128-bit and FPU forms
            v = self.rd(ops[0])
            self.use(v)
            self.consume(repr(v))
            self.stackargs[num(ops[1][:-4])] = v
            return
        if m in ("sd", "sq", "ld", "lq", "swc1", "lwc1") and a.endswith("(sp)"):
            r = ops[0]
            ss = getattr(self, "saveslots", None)
            k_sp = re.fullmatch(r"(%s)\(sp\)" % NUM, ops[1])
            is_slot = ss is None or (k_sp is not None and num(k_sp.group(1)) in ss)
            if (r == "ra" or re.fullmatch(r"s[0-7]|fp|f2[0-9]|f3[01]", r)) and is_slot:
                if m in ("ld", "lq", "lwc1"):
                    R[r] = ("x",)
                return
            if m in ("sd", "sw") and num(ops[1][:-4]) in self.outargs:
                v = self.rd(r)
                self.use(v)
                self.consume(repr(v))
                self.stackargs[num(ops[1][:-4])] = v
                return
            if m == "sq" and self.vtemps and num(ops[1][:-4]) in self.vtemps:
                v = self.rd(r)
                if v[0] == "v4ctor":
                    for x in v[1]:
                        self.use(x)
                    self.vt_ctor[num(ops[1][:-4])] = v[1]     # passed as `CGtV4d(a, b, c, d)` itself
                    return
                self.use(v)
                self.consume(repr(v))
                self.stmts.append(("vcopy", num(ops[1][:-4]), v))
                return
            if self.locbase is None:
                raise Skip("stack local (no local: %s %s)" % (m, "callee-saved" if re.fullmatch(r"s[0-7]|fp|f2[0-9]|f3[01]|ra", r) else "other"))
            # 64/128-bit accesses to the local (a vector built word by word and copied whole, `sq` spills): handled
            # as field accesses below (unsigned long / u_long128 fields, puns where they overlap smaller ones)
        if self.vtemps and m in ("addiu", "daddiu") and len(ops) == 3 and ops[1] == "sp" and ops[0] != "sp":
            if num(ops[2]) not in self.vtemps:
                raise Skip("stack address outside the vector temporaries")
            R[ops[0]] = ("vt", num(ops[2]))
            return
        if self.locbase is not None and m in ("addiu", "daddiu") and len(ops) == 3 and ops[1] == "sp" and                 ops[0] != "sp":
            k = num(ops[2]) - self.locbase
            self.obj(("loc",))
            R[ops[0]] = ("loc",) if k == 0 else ("b", "+", ("loc",), ("k", k))
            return
        if self.locbase is not None and m in ("addu", "daddu") and len(ops) == 3 and "sp" in ops[1:] and                 "zero" not in ops[1:] and ops[0] != "sp":
            # an index into the frame's local (an array): local + index, the displacement added by the access
            x = self.rd(ops[2] if ops[1] == "sp" else ops[1])
            self.obj(("loc",))
            R[ops[0]] = ("b", "+", ("b", "+", ("loc",), ("k", -self.locbase)), x)
            return
        if self.locbase is not None and m in ("daddu", "addu", "or") and len(ops) == 3 and ops[1] == "sp" and                 ops[2] == "zero":
            if self.locbase != 0:
                raise Skip("stack address below the local")
            self.obj(("loc",))
            R[ops[0]] = ("loc",)
            return
        if m in ("jalr", "jr") and a == "t9":
            self.vcall(tail=(m == "jr"))
            return
        if m == "jr":
            if a != "ra":
                raise Skip("jr %s" % a)
            v0 = R.get("v0")
            f0 = R.get("f0")
            self.ret = (v0, f0)
            return
        if m == "jal" or m == "j":
            for k_ in [k_ for k_ in R if k_.startswith("vf")]:
                del R[k_]
            if not re.fullmatch(r"[A-Za-z_]\w*", a):
                raise Skip("jump target %s" % a)
            self.call(a, tail=(m == "j"))
            return
        if m == "jalr" and re.fullmatch(r"(v[01]|a[0-3]|t[0-8]|s[0-7])", a):
            # a call through a function pointer held in data (not t9: MWCC's virtual dispatch register,
            # whose slot methods would need names): `((rt (*)(...))value)(args)` [G] types
            fv = self.rd(a)
            self.use(fv)
            self.call(("fptr", fv), tail=False)
            return
        if m in ("jalr", "bal") or m.startswith("b") and m not in ("bnel",):
            raise Skip("branch/indirect call %s" % m)
        if m in LOADT or (m == "lwu" and self.c.get("lift5")):
            # lift5: lwu -- a 32-bit unsigned field loaded zero-extended (read as 64 bits) [G] unsigned int
            rt, root, off = self.mem(a)
            t = LOADT.get(m, "unsigned int")
            key = len(self.loads)
            for k1, L1 in self.loads.items():
                if L1["off"] == off and L1["mn"] == m and self.same(L1["root"], root):
                    if L1["epoch"] != self.epoch:
                        # a re-load after a store/call: the source read it again (MWCC cannot keep it across one:
                        # func_00385EC0); variant (v // 98304) % 2: one variable as before [G]
                        self.used_reload = True
                        if not ((self.c.get("variant") or 0) // 98304) % 2:
                            self.talias.setdefault(repr(("l", key)), self.ckt(repr(("l", k1))))
                            continue
                    self.alias[repr(("l", key))] = self.ck(repr(("l", k1)))
                    break
            lb = lit4_bits(root, off) if m == "lwc1" else None
            if lb is not None:
                self.used_lit4 = True
                if not ((self.c.get("variant") or 0) // 206158430208) % 2:
                    R[rt] = ("fk", lb)                 # a float literal (patch_lit4.py)
                    return
            pn = self.field(root, off, t, pun=True)
            self.use(root)
            self.loads[key] = {"root": root, "off": off, "type": t, "epoch": self.epoch, "temp": False,
                               "slot": len(self.stmts), "mn": m, "pun": pn}
            self.stmts.append(("load", key))
            R[rt] = ("l", key)
            return
        if m in ("sq", "sqc2") and R.get(ops[0], ("x",))[0] in ("vnorm",):
            rt, root, off = self.mem(a)
            v = R[rt]
            if v[0] == "vnorm" and v[1][0] == "vmem" and self.same(v[1][1], root) and v[1][2] == off:
                self.vfield(root, off)
                self.stmts.append(("vcall", root, off, "Normalise"))
                self.epoch += 1
                return
            if v[0] == "vnorm" and v[1][0] in VVAL:
                # another vector normalised into this field: `f = v; f.Normalise();` [G] (vlift)
                self.vuse(v[1])
                self.vfield(root, off)
                self.stmts.append(("vassign", root, off, v[1]))
                self.stmts.append(("vcall", root, off, "Normalise"))
                self.epoch += 1
                return
            raise Skip("vector stored elsewhere")
        if m == "sq" and len(ops) == 2 and R.get(ops[0], ("x",))[0] in ("vneg", "vsubv", "vaddv", "vscale", "vcross", "vxform", "vlerp3") + V4OPS:
            vs, root, off = self.mem(a)             # a computed vector out through a GPR (qmfc2 + sq) (vlift)
            self.vuse(R[vs])
            self.vfield(root, off, "V4D" if R[vs][0] in V4OPS else "V3D")
            self.stmts.append(("vassign", root, off, R[vs]))
            self.epoch += 1
            return
        if m in STORET:
            rt, root, off = self.mem(a)
            v = self.rd(rt)
            t = STORET[m]
            if m == "sw" and self.is_ptr(v):
                t = "PTR"
            if m == "sq" and v[0] == "p":
                self.qparams.add(v[1])           # a parameter stored whole as 128 bits: a u_long128 [G]
            if m == "sd" and v[0] == "p":
                self.dparams.add(v[1])           # stored whole as 64 bits: an unsigned long (no sign extension) [G]
            if m == "sd" and v[0] == "c":
                self.calls[v[1]]["dword"] = True
            if v[0] == "k":
                # the constant's sign/width picks the field type (MWCC re-materializes -1 vs 255 vs 0xFFFF)
                if m == "sb" and v[1] < 0:
                    t = "signed char"
                if m == "sh":
                    t = "unsigned short" if v[1] > 0x7FFF else "short"
            if m == "swc1" and not (v[0] in ("p", "fk", "fb", "l", "cf") or v[0] == "fb"):
                pass
            self.use(v)
            self.use(root)
            pn = self.field(root, off, t if t != "PTR" else "void *", zero=(m == "sw" and v == ("k", 0)),
                            soft=(m in ("sb", "sh") and (v[0] != "k" or 0 <= v[1] <= (0x7F if m == "sb" else 0x7FFF))),
                            pun=(t != "PTR"))
            self.consume(repr(v))
            self.stmts.append(("store", root, off, v, m, pn))
            self.epoch += 1
            return
        if m == "lui":
            g = re.fullmatch(r"(\w+),%hi\(([A-Za-z_]\w*)(?:\+(0x[0-9A-Fa-f]+|\d+))?\)", a)
            if g:
                R[g.group(1)] = ("hi", g.group(2), num(g.group(3)) if g.group(3) else 0)
                return
            g = re.fullmatch(r"(\w+),%s" % NUM, a)
            if g:
                R[g.group(1)] = ("k", (num(g.group(2)) << 16) & 0xFFFFFFFF)
                return
            g = re.fullmatch(r"(\w+),\((0x[0-9A-Fa-f]+)>>16\)", a)
            if g:
                R[g.group(1)] = ("k", num(g.group(2)) & 0xFFFF0000)
                return
            raise Skip("lui %s" % a)
        if m in ("addiu", "daddiu") and len(ops) == 3 and ops[2].startswith("%lo("):
            g = re.fullmatch(r"%lo\(([A-Za-z_]\w*)(?:\+(0x[0-9A-Fa-f]+|\d+))?\)", ops[2])
            hv = self.rd(ops[1])
            if not g or hv != ("hi", g.group(1), num(g.group(2)) if g.group(2) else 0):
                raise Skip("%lo pair")
            if not g.group(2) and "__" in g.group(1) and "(" in (demangle(g.group(1)) or ""):
                R[ops[0]] = ("fn", g.group(1))   # a mangled function's address (a callback)
                return
            self.gmode(g.group(1), "abs")
            R[ops[0]] = ("gofs", g.group(1), num(g.group(2)) if g.group(2) else 0) if g.group(2) else ("g", g.group(1))
            return
        if m in ("addiu", "daddiu") and len(ops) == 3 and ops[1] == "gp" and ops[2].startswith("%gp_rel("):
            g = re.fullmatch(r"%gp_rel\(([A-Za-z_]\w*)(?:\+(0x[0-9A-Fa-f]+|\d+))?\)", ops[2])
            if not g:
                raise Skip("gp_rel")
            self.gmode(g.group(1), "gp")
            R[ops[0]] = ("gofs", g.group(1), num(g.group(2)) if g.group(2) else 0) if g.group(2) else ("g", g.group(1))
            return
        if m in IMMOPS and len(ops) == 3 and re.fullmatch(NUM, ops[2]):
            x = self.rd(ops[1])
            k = num(ops[2])
            op = IMMOPS[m]
            if op == "+" and x == ("k", 0):
                R[ops[0]] = ("k", k)
            elif op == "|" and x[0] == "k":
                R[ops[0]] = ("k", x[1] | k)
            elif op == "+" and k == 0:
                R[ops[0]] = x
            elif op == "&" and x[0] == "p" and (self.preg_types.get(x[1], "").replace("const ", ""), k) in (
                    ("unsigned short", 0xFFFF), ("unsigned char", 0xFF), ("bool", 0xFF)):
                R[ops[0]] = x      # MWCC's zero-extension of a narrow unsigned parameter: no source
                                   # (GetSegmentLengthFast__9CB3AILaneCFUs: `(p0 & 65535)` costs the match)
            else:
                if op in ("&", "|", "^"):
                    k &= 0xFFFF
                R[ops[0]] = ("b", op, x, ("k", k))
            return
        if m in BINOPS and len(ops) == 3:
            x, y = self.rd(ops[1]), self.rd(ops[2])
            op = BINOPS[m]
            if op == "+" and (x[0] == "hi") != (y[0] == "hi"):
                # `lui r,%hi(D_00XXXXXX); addu r,base,r`: the disassembler named a large offset as a symbol
                h = x if x[0] == "hi" else y
                if not re.fullmatch(r"D_[0-9A-F]{8}", h[1]):
                    raise Skip("%hi added to a register")
                val = int(h[1][2:], 16) + h[2]
                hk = ("k", ((val + 0x8000) >> 16) << 16)
                x, y = (hk, y) if x[0] == "hi" else (x, hk)
                R[ops[0]] = ("b", "+", x, y) if x[0] != "k" else ("b", "+", y, x)
                self.hioff[ops[0]] = h[1]
                return
            if x[0] == "k" and y[0] == "k" and op in ("|", "&", "^"):
                # two constant halves joined (a 64-bit constant, built piecewise)
                R[ops[0]] = ("k", {"|": x[1] | y[1], "&": x[1] & y[1], "^": x[1] ^ y[1]}[op] & 0xFFFFFFFFFFFFFFFF)
                return
            if op in ("+", "|") and y == ("k", 0):
                R[ops[0]] = x
            elif op == "+" and x == ("k", 0):
                R[ops[0]] = y
            elif op == "-" and x == ("k", 0):
                R[ops[0]] = ("u", "-", y)
            elif op == "<u" and x == ("k", 0):
                R[ops[0]] = ("b", "!=", y, ("k", 0))
            else:
                R[ops[0]] = ("b", op, x, y)
            return
        if m == "dsll32" and len(ops) == 3 and re.fullmatch(r"\d+", ops[2]) and R.get(ops[1], ("x",))[0] != "k":
            R[ops[0]] = ("sl32", self.rd(ops[1]), int(ops[2]))
            return
        if m in ("dsra32", "dsrl32") and len(ops) == 3 and re.fullmatch(r"\d+", ops[2]):
            x = self.rd(ops[1])
            n = int(ops[2])
            if x[0] != "sl32" or x[2] != n or n not in (0, 16, 24):
                raise Skip("64-bit shift pair")
            cast = {("dsra32", 24): "(signed char)", ("dsra32", 16): "(short)", ("dsrl32", 24): "(unsigned char)",
                    ("dsrl32", 16): "(unsigned short)", ("dsrl32", 0): "(unsigned int)", ("dsra32", 0): "(int)"}[(m, n)]
            R[ops[0]] = ("u", cast, x[1])
            return
        # 64-bit constants (an unsigned long is 64 bits on the EE): lui/ori halves joined by dsll32/dsll/or, and
        # pcpyld rd,zero,rs (the value in a 128-bit register's low half)
        if m in ("dsll32", "dsll") and len(ops) == 3 and re.fullmatch(NUM, ops[2]):
            x = self.rd(ops[1])
            if x[0] != "k" and m == "dsll" and self.c.get("lift5"):
                # lift5: a 64-bit shift of a value (GS packet fields: `(u_long)x << K`; an unsigned long is 64 bits
                # on the EE) [G] -- the dsll32 form's rendering
                R[ops[0]] = ("b", "<<", ("u", "(unsigned long)", x), ("k", num(ops[2])))
                self.used_l5dsll = True
                return
            if x[0] != "k":
                raise Skip("instruction %s" % m)
            R[ops[0]] = ("k", ((x[1] & 0xFFFFFFFFFFFFFFFF) << (num(ops[2]) + (32 if m == "dsll32" else 0)))
                         & 0xFFFFFFFFFFFFFFFF)
            return
        if m == "or" and len(ops) == 3 and ops[2] != "zero":
            x, y = self.rd(ops[1]), self.rd(ops[2])
            if x[0] == "k" and y[0] == "k" and max(x[1], y[1]) > 0xFFFFFFFF:
                R[ops[0]] = ("k", (x[1] | y[1]) & 0xFFFFFFFFFFFFFFFF)
                return
        if m == "pcpyld" and len(ops) == 3 and ops[1] == "zero":
            x = self.rd(ops[2])
            if x[0] != "k" or x[1] <= 0xFFFFFFFF:
                raise Skip("instruction pcpyld")
            R[ops[0]] = x
            self.zext128.add(repr(x))        # a later pcpyld's low half: written `(u_long128)K` [C] pc14
            return
        if m == "nor" and len(ops) == 3 and ops[2] == "zero":
            R[ops[0]] = ("u", "~", self.rd(ops[1]))
            return
        if m == "not" and len(ops) == 2:
            R[ops[0]] = ("u", "~", self.rd(ops[1]))
            return
        if m == "mult" and len(ops) == 3 and not ops[0].startswith("f") and ops[0] != "zero":
            # R5900 three-operand mult: rd = rs * rt (HI/LO clobbered; a later mflo/mfhi is refused below)
            R[ops[0]] = ("b", "i*", self.rd(ops[1]), self.rd(ops[2]))
            R["lo"] = ("x",)
            return
        if m in ("div", "divu") and len(ops) == 3 and ops[0] == "zero":
            # LO = quotient, HI = remainder (MWCC divides by a constant with div too, no reciprocal multiply)
            x, y = self.rd(ops[1]), self.rd(ops[2])
            u = "u" if m == "divu" else ""
            R["lo"] = ("b", "i/" + u, x, y)
            R["hi"] = ("b", "i%" + u, x, y)
            return
        if m in ("mflo", "mfhi") and len(ops) == 1:
            R[ops[0]] = self.rd(m[2:])
            return
        if m == "cvt.s.w" and len(ops) == 2:
            x = self.rd(ops[1])
            if x[0] == "l":
                # an int field loaded straight into an FPR (lwc1) and converted: the field is an int
                LD = self.loads[x[1]]
                o = self.obj(LD["root"])
                if o["fields"].get(LD["off"]) != "float":
                    raise Skip("cvt.s.w of a non-float load")
                o["fields"][LD["off"]] = "int"
                R[ops[0]] = ("u", "(float)", x)
                return
            if x[0] == "wbits":
                R[ops[0]] = ("u", "(float)", ("u", "(int)", x[1]))     # truncation: (float)(int)f
                return
            if x[0] == "fk":
                # an int constant moved in and converted: `(float)K` (MWCC does not fold the conversion)
                k = x[1] - (1 << 32) if x[1] & 0x80000000 else x[1]
                R[ops[0]] = ("u", "(float)", ("k", k))
                return
            if x[0] != "ibits":
                raise Skip("cvt.s.w of a float value")
            R[ops[0]] = ("u", "(float)", x[1])
            return
        if m == ".word" and re.search(r"#vsqrtQ,(vf\d+)x#", a):
            # lift3: vsqrt Q, vfN.x (spimdisasm can't name it) of a squared length: CGtV3d::GetLength() (B3O0PCH map,
            # 140 bytes) -- `sq; vsqrt; 1.0 * Q` (GetWidth__9CB3AILaneCFUs, UpdateLastPositions__10CB3RaceCar ...)
            v = R.get(re.search(r"#vsqrtQ,(vf\d+)x#", a).group(1))
            if v is None or v[0] != "vdot" or v[1][0] != "vsq":
                raise Skip("sqrt of an unknown value")
            if not hdr_has("GetLength"):
                raise Skip("header lacks CGtV3d::GetLength (B3O0PCH map)")
            R["vQ"] = ("sqrt", v)
            return
        if m == ".word":
            g = re.search(r"#cvt\.w\.s(f\d+),(f\d+)#", a)
            if not g:
                raise Skip("instruction .word" + (" [%s]" % a if DIAG else ""))   # lift3: operands under DIAG
            R[g.group(1)] = ("wbits", self.rd(g.group(2)))
            return
        if m == "mfc1" and len(ops) == 2:
            x = self.rd(ops[1])
            if x[0] == "wbits":
                R[ops[0]] = ("u", "(int)", x[1])
            elif x[0] == "ibits":
                R[ops[0]] = x[1]
            else:
                R[ops[0]] = ("fbits", x)          # a float's bits in a GPR: only a qmtc2 takes them
            return
        if m == "ori" and len(ops) == 3 and re.fullmatch(r"\((0x[0-9A-Fa-f]+)&0xFFFF\)", ops[2]):
            x = self.rd(ops[1])
            if x[0] != "k":
                raise Skip("ori of a non-constant")
            R[ops[0]] = ("k", x[1] | (num(ops[2][1:].split("&")[0]) & 0xFFFF))
            return
        if m == "mtc1":
            x = self.rd(ops[0])
            if x[0] == "vlen":                         # lift3: v.GetLength()
                self.vuse(x[1])
                R[ops[1]] = ("glen", x[1])
                return
            if x[0] == "vdot":
                if x[1][0] == "vprod":
                    self.vuse(x[1][1])
                    self.vuse(x[1][2])
                    self.need_dot = True
                    R[ops[1]] = ("dotp", x[1][1], x[1][2])
                    return
                sv = x[1][1]
                self.vuse(sv)
                R[ops[1]] = ("gsl", sv)
                return
            if x[0] != "k":
                # integer bits for a cvt.s.w (an int -> float conversion); any other use is refused
                R[ops[1]] = ("ibits", x)
                return
            R[ops[1]] = ("fk", x[1] & 0xFFFFFFFF)
            return
        if m == "mov.s":
            R[ops[0]] = self.rd(ops[1])
            return
        if m in FCMP and len(ops) == 2:
            R["fcc"] = ("b", FCMP[m], self.rd(ops[0]), self.rd(ops[1]))
            self.consume(repr(R["fcc"][2]))
            self.consume(repr(R["fcc"][3]))
            return
        if m == "abs.s" and len(ops) == 2:
            # lift3: GtMath::Abs(float) (B3O0PCH map, 12 bytes: abs.s, jr ra, nop) -- the N170/N176 one-instruction asm
            # helper; the argument passed directly (proven fabsf users: func_0012FDA0, func_00461D60)
            R[ops[0]] = ("fcall", "GtMath::Abs", self.rd(ops[1]), None)
            return
        if m == "neg.s":
            R[ops[0]] = ("u", "-", self.rd(ops[1]))
            return
        if m == "lqc2" and len(ops) == 2:
            vd, root, off = self.mem(a)
            self.use(root)
            R[vd] = ("vmem", root, off)
            return
        if m in ("qmtc2", "qmtc2.ni") and len(ops) == 2:
            x = self.rd(ops[0])
            if x[0] == "l" and self.loads[x[1]]["mn"] == "lq":
                L_ = self.loads[x[1]]
                L_["nodata"] = True                      # read by the VU operation, not a C value
                x = ("vmem", L_["root"], L_["off"])      # a field read through a GPR (the asm's "r" operand)
            R[ops[1]] = x if x[0] in VANY else ("vgpr", x)
            return
        if m in ("qmfc2", "qmfc2.ni") and len(ops) == 2:
            v = R.get(ops[1])
            if v is None or v[0] not in VANY:
                raise Skip("qmfc2 of an unknown vector")
            R[ops[0]] = v
            return
        if m == "vrsqrt" and len(ops) == 3 and ops[0] == "Q" and ops[1] == "vf0w" and ops[2].endswith("x"):
            v = R.get(ops[2][:-1])
            if v is None or v[0] != "vdot":
                raise Skip("rsqrt of an unknown value")
            R["vQ"] = ("rsqrt", v)
            return
        if m == "vwaitq" and not ops:
            return
        if m == "vadd.xyz" and len(ops) == 3 and "vf0" not in ops[1:]:
            x, y = R.get(ops[1]), R.get(ops[2])
            if x is None or y is None or x[0] not in VVAL or y[0] not in VVAL:
                raise Skip("sum of unknown vectors")
            R[ops[0]] = ("vaddv", x, y)
            return
        if m == "vmulx.xyz" and len(ops) == 3 and ops[2].endswith("x") and ops[1] != ops[2][:-1]:
            x, sc = R.get(ops[1]), R.get(ops[2][:-1])
            if x is None or x[0] not in VVAL or sc is None or sc[0] != "vgpr":
                raise Skip("scale of an unknown vector")
            v_ = self.fscalar(sc[1])
            R[ops[0]] = ("vscale", x, v_)
            return
        if m == "vsub.xyz" and len(ops) == 3 and ops[1] != ops[2]:
            if ops[1] == "vf0":
                x = R.get(ops[2])
                if x is None or x[0] != "vmem":
                    raise Skip("negation of an unknown vector")
                R[ops[0]] = ("vneg", x)
            else:
                x, y = R.get(ops[1]), R.get(ops[2])
                if x is None or y is None or x[0] not in VVAL or y[0] not in VVAL:
                    raise Skip("difference of unknown vectors")
                R[ops[0]] = ("vsubv", x, y)
            return
        if m in ("vadd.xyz", "vsub.xyzw") and a == "%s,vf0,vf0" % ops[0]:
            R[ops[0]] = ("vzero", 3 if m == "vadd.xyz" else 4, len(self.stmts), id(self.stmts))
            return
        if m == "vmulq.xyz" and len(ops) == 3 and ops[2] == "Q":
            q, v = R.get("vQ"), R.get(ops[1])
            if q is None or v is None or q[1] != ("vdot", ("vsq", v)):
                raise Skip("scale by Q of another vector")
            R[ops[0]] = ("vnorm", v)
            return
        if m == "vaddw.x" and a == "vf%s,vf0,vf0w" % ops[0][2:]:
            R[ops[0]] = ("vone",)
            return
        if m == "vmulq.x" and len(ops) == 3 and ops[2] == "Q" and R.get(ops[1]) == ("vone",) and \
                R.get("vQ", ("x",))[0] == "sqrt":
            R[ops[0]] = ("vlen", R["vQ"][1][1][1])        # lift3: 1.0 * sqrt(|v|^2): GetLength()
            return
        if m in ("vmul.xyz", "vopmula.xyz", "vsub.xyz", "vadd.xyz", "vmulx.xyz") and len(ops) == 3:
            for r_ in set(ops[1:]):
                r_ = r_.rstrip("xyzw") if r_.startswith("vf") and r_[-1] in "xyzw" and not r_[2:].isdigit() else r_
                if R.get(r_, ("x",))[0] == "vset":
                    R[r_] = self.vmat(R[r_])
        if m == "vmul.xyz" and len(ops) == 3 and ops[1] == ops[2]:
            v = R.get(ops[1])
            if v is None or v[0] not in VVAL:
                raise Skip("square of an unknown vector")
            R[ops[0]] = ("vsq", v)
            return
        if m == "vmul.xyz" and len(ops) == 3 and ops[1] != ops[2]:
            x, y = R.get(ops[1]), R.get(ops[2])
            if x is not None and y is not None and x[0] in VVAL and y[0] in VVAL:
                R[ops[0]] = ("vprod", x, y)         # DotProduct(x, y)'s product (vlift) [L]
                return
        if m == "vmulx.xyzw" and len(ops) == 3 and ops[2].endswith("x") and ops[1] != ops[2][:-1]:
            x, sc = R.get(ops[1]), R.get(ops[2][:-1])
            if x is None or x[0] not in ("vmem",) + V4OPS or sc is None or sc[0] != "vgpr":
                raise Skip("4-lane scale of an unknown vector")
            R[ops[0]] = ("v4scale", x, self.fscalar(sc[1]))      # CGtV4d * float (vlift)
            return
        if m in ("vmul.xyzw", "vsub.xyzw") and len(ops) == 3 and "vf0" not in ops[1:]:
            x, y = R.get(ops[1]), R.get(ops[2])
            if x is None or y is None or x[0] not in ("vmem",) + V4OPS or y[0] not in ("vmem",) + V4OPS:
                raise Skip("4-lane operation on unknown vectors")
            R[ops[0]] = ("v4mul" if m == "vmul.xyzw" else "v4sub", x, y)   # this op o: `vXXX.xyzw d, this, o` (vlift)
            return
        if m == "vopmula.xyz" and len(ops) == 3 and ops[0] == "ACC":
            x, y = R.get(ops[1]), R.get(ops[2])
            if x is None or y is None or x[0] not in VVAL or y[0] not in VVAL:
                raise Skip("cross product of unknown vectors")
            R["vACC"] = ("vopm", ops[1], ops[2], x, y)
            return
        if m == "vopmsub.xyz" and len(ops) == 3:
            acc = R.get("vACC")
            if acc is None or acc[0] != "vopm" or (ops[1], ops[2]) != (acc[2], acc[1]) or \
                    R.get(ops[1]) is not acc[4] or R.get(ops[2]) is not acc[3]:
                raise Skip("cross product tail shape")
            R[ops[0]] = ("vcross", acc[3], acc[4])     # CrossProduct(a, b): vopmula ACC,a,b; vopmsub d,b,a (vlift)
            R["vACC"] = None
            return
        g3 = re.fullmatch(r"v(mula|madda)([xyz])\.xyz", m)
        if g3 and len(ops) == 3 and ops[0] == "ACC" and ops[2].endswith(g3.group(2)):
            # TransformPoint(CGtMatrix3x4, v): rows 0-2 times v's x/y/z lanes into ACC (vlift) [L]
            k = "xyz".index(g3.group(2))
            row, v = R.get(ops[1]), R.get(ops[2][:-1])
            acc = R.get("vACC")
            if row is None or row[0] != "vmem" or v is None or v[0] not in VVAL or \
                    (g3.group(1) == "mula") != (k == 0) or \
                    (k and (acc is None or acc[0] != "vxf" or acc[4] != k or acc[3] is not v or
                            not self.same(acc[1], row[1]) or acc[2] + 0x10 * k != row[2])):
                raise Skip("matrix-point product shape")
            R["vACC"] = ("vxf", row[1], row[2] - 0x10 * k, v, k + 1)
            return
        if m == "vmaddw.xyz" and len(ops) == 3 and ops[2] == "vf0w":
            row, acc = R.get(ops[1]), R.get("vACC")
            if row is None or row[0] != "vmem" or acc is None or acc[0] != "vxf" or acc[4] != 3 or \
                    not self.same(acc[1], row[1]) or acc[2] + 0x30 != row[2]:
                raise Skip("matrix-point product tail shape")
            R[ops[0]] = ("vxform", acc[1], acc[2], acc[3])
            R["vACC"] = None
            return
        if m == "vadday.x" and len(ops) == 3 and ops[0] == "ACC" and ops[2] == ops[1] + "y":
            v = R.get(ops[1])
            if v is None or v[0] not in ("vsq", "vprod"):
                raise Skip("dot product of an unknown vector")
            R["vACC"] = ("vacc", v)
            return
        if m == "vmaddz.x" and len(ops) == 3 and ops[2].endswith("z"):   # any destination (the header's "=j" tail) (vlift)
            one, acc = R.get(ops[1]), R.get("vACC")
            if one != ("vone",) or acc is None or acc[1] != R.get(ops[2][:-1]):
                raise Skip("dot product tail shape")
            R[ops[0]] = ("vdot", acc[1])
            return
        g2 = re.fullmatch(r"vadd([xyz])\.([xyz])", m)
        if g2 and len(ops) == 3 and ops[1] == "vf0" and ops[2].endswith(g2.group(1)):
            sv, dv = R.get(ops[2][:-1]), R.get(ops[0])
            if sv is not None and sv[0] == "vmem" and dv is not None and dv[0] in ("vmem", "vset"):
                # a lane of another vector: dst.SetY(src.Y()) [L]
                R[ops[0]] = ("vset", dv, g2.group(2), ("lane", sv, g2.group(1)))
                return
        if m == "vadd.xyz" and len(ops) == 3 and ops[1] == "vf0" and ops[0] != ops[2]:
            # lift3: keep-w xyz assign -- `vadd.xyz D, $vf0, S` with D loaded from the destination: the header's
            # CGtV3dPlus::SetGtV3d / CGtSphere::SetPosition / CGtPlane::SetNormal body (N185, B3O0PCH map)
            sv, dv = R.get(ops[2]), R.get(ops[0])
            if dv is not None and dv[0] == "vmem" and sv is not None and sv[0] in VVAL:
                R[ops[0]] = ("vkeepw", dv, sv)
                return
        if m == "vmove.xyzw" and len(ops) == 2 and R.get(ops[1], ("x",))[0] in VANY:
            R[ops[0]] = R[ops[1]]                # lift3: a VU register copy (a folded qmfc2/qmtc2 round trip, N188)
            return
        g3_ = re.fullmatch(r"(vaddax|vmsubax|vmaddx)\.(xyzw|xyz)", m)
        if g3_ and len(ops) == 3:
            # lift3: Interpolate(a, b, t) = a + (b - a) * t through ACC: `vaddax ACC,A,vf0x; vmsubax ACC,A,Tx;
            # vmaddx D,B,Tx` -- the header's Interpolate(CGtV4d, CGtV4d, float) (xyzw) / a file-local
            # Interpolate(CGtV3d, CGtV3d, float) stand-in (xyz; B3O0PCH map, 116 bytes) [L]
            op_, w_ = g3_.groups()
            acc = R.get("vACC")
            if op_ == "vaddax" and ops[0] == "ACC" and ops[2] == "vf0x":
                a_ = R.get(ops[1])
                if a_ is None or a_[0] not in VVAL:
                    raise Skip("interpolation of an unknown vector")
                R["vACC"] = ("ilerp0", a_, w_)
                return
            if op_ == "vmsubax" and ops[0] == "ACC" and ops[2].endswith("x") and acc is not None and \
                    acc[0] == "ilerp0" and acc[2] == w_ and R.get(ops[1]) == acc[1]:
                sc = R.get(ops[2][:-1])
                if sc is None or sc[0] != "vgpr":
                    raise Skip("interpolation by an unknown scalar")
                R["vACC"] = ("ilerp1", acc[1], w_, ops[2][:-1], sc)
                return
            if op_ == "vmaddx" and ops[2].endswith("x") and acc is not None and acc[0] == "ilerp1" and \
                    acc[2] == w_ and R.get(ops[2][:-1]) == acc[4]:
                b_ = R.get(ops[1])
                if b_ is None or b_[0] not in VVAL:
                    raise Skip("interpolation to an unknown vector")
                R[ops[0]] = ("vlerp4" if w_ == "xyzw" else "vlerp3", acc[1], b_, self.fscalar(acc[4][1]))
                R["vACC"] = None
                return
            raise Skip("interpolation shape")
        if m == "vsubw.w" and len(ops) == 3 and ops[1:] == ["vf0", "vf0w"]:
            dv = R.get(ops[0])                 # CGtV4d::SetW(f)'s head: w = 0 (vlift)
            if dv is None or dv[0] not in ("vmem", "vset", "vkeepw"):
                raise Skip("vector lane clear shape")
            R[ops[0]] = ("vwz", dv)
            return
        if m == "vaddx.w" and len(ops) == 3 and ops[1] == ops[0] and ops[2].endswith("x") and \
                R.get(ops[0], ("x",))[0] == "vwz":
            sv = R.get(ops[2][:-1])            # ... w = 0 + f: SetW(f) (vlift)
            if sv is None or sv[0] != "vgpr":
                raise Skip("vector lane set shape (SetW)")
            R[ops[0]] = ("vset", R[ops[0]][1], "W", sv[1])
            return
        g = re.fullmatch(r"vaddx\.([xyz])", m) or re.fullmatch(r"vmulx\.(w)", m)
        if g and len(ops) == 3 and ops[1] == "vf0" and ops[2].endswith("x"):
            sv, dv = R.get(ops[2][:-1]), R.get(ops[0])
            if sv is None or sv[0] != "vgpr" or dv is None or dv[0] not in ("vmem", "vset", "vneg", "vsubv", "vaddv", "vscale", "vcross", "vxform", "vkeepw"):
                raise Skip("vector lane set shape" + (" [src=%s dst=%s]" % (None if sv is None else sv[0], None if dv is None else dv[0]) if DIAG else ""))
            R[ops[0]] = ("vset", dv, g.group(1), sv[1])
            return
        if m in ("sqc2", "sq") and len(ops) == 2 and R.get(ops[0], ("x",))[0] in ("vneg", "vsubv", "vaddv", "vscale", "vcross", "vxform", "vlerp3") + V4OPS:
            vs, root, off = self.mem(a)
            self.vuse(R[vs])
            self.vfield(root, off, "V4D" if R[vs][0] in V4OPS else "V3D")
            self.stmts.append(("vassign", root, off, R[vs]))
            self.epoch += 1
            if m == "sqc2":
                R[vs] = ("vmem", root, off)
            return
        if m == "sqc2" and len(ops) == 2 and R.get(ops[0], ("x",))[0] == "vzero":
            vs, root, off = self.mem(a)
            zv = R[vs]
            self.vfield(root, off, "V3D" if zv[1] == 3 else "V4D")
            pos = len(self.stmts)
            if zv[3] == id(self.stmts) and all(x[0] == "load" for x in self.stmts[zv[2]:]):
                pos = zv[2]                      # the statement where the zero was computed
                for x in self.stmts[pos:]:
                    self.loads[x[1]]["slot"] += 1
            self.stmts.insert(pos, ("vcall", root, off, "Zero"))
            self.epoch += 1
            return
        if m == "sqc2" and len(ops) == 2:
            vs, root, off = self.mem(a)
            v, chain = R.get(vs), []
            while v is not None and v[0] == "vset":
                chain.append((v[2], v[3]))
                v = v[1]
            if chain and v is not None and v[0] == "vmem" and not (self.same(v[1], root) and v[2] == off):
                # another field's value with lanes set, stored here: `b = a; b.SetY(f);` [G]
                self.vfield(v[1], v[2])
                self.vfield(root, off)
                self.use(v[1])
                self.stmts.append(("vassign", root, off, v))
                v = ("vmem", root, off)
            elif chain and v is not None and v[0] in ("vneg", "vsubv", "vaddv", "vscale", "vcross", "vxform"):
                # a computed vector with lanes set, stored here: `b = x - y; b.SetY(f);` [G] (vlift)
                self.vuse(v)
                self.vfield(root, off)
                self.stmts.append(("vassign", root, off, v))
                v = ("vmem", root, off)
            if v is not None and v[0] == "vkeepw" and v[1][0] == "vmem" and self.same(v[1][1], root) and v[1][2] == off:
                # lift3: `f.SetGtV3d(s)` (CGtV3dPlus) / `f.SetPosition(s)` (CGtSphere, when w is set by vmulx.w) [G] type
                lanes_ = {l_ for l_, x_ in chain}
                if lanes_ - {"w", "W"}:
                    raise Skip("keep-w assign with xyz lane sets")
                self.vuse(v[2])
                self.vlanes.setdefault((repr(root), off), set()).update(lanes_)
                self.vfield(root, off, "V3P")
                self.stmts.append(("vkeepw", root, off, v[2]))
                v = ("vmem", root, off)
                if not chain:
                    self.epoch += 1
                    R[vs] = v
                    return
            if not chain or v is None or v[0] != "vmem" or not self.same(v[1], root) or v[2] != off:
                raise Skip("vector store shape" + (" [%s chain=%d base=%s]" % (vs, len(chain), None if v is None else v[0]) if DIAG else ""))
            lanes = {l_.lower() for l_, x_ in chain}
            if "w" in lanes and lanes != {"w"}:
                raise Skip("vector lane set of w and xyz")
            self.vlanes.setdefault((repr(root), off), set()).update(l_ for l_, x_ in chain)   # lift3
            self.vfield(root, off, "V4D" if lanes == {"w"} else "V3D")
            for lane, x in reversed(chain):
                if x[0] == "lane":
                    self.vuse(x[1])
                    self.stmts.append(("vset", root, off, lane, x))
                    continue
                x = self.fscalar(x)
                self.use(x)
                self.consume(repr(x))
                self.stmts.append(("vset", root, off, lane, x))
            self.epoch += 1
            R[vs] = ("vmem", root, off)          # the register now holds the field's value
            return
        if m == "dsll32" and len(ops) == 3:
            v = self.rd(ops[1])
            sh = 32 + num(ops[2])
            R[ops[0]] = ("k", (v[1] << sh) & 0xFFFFFFFFFFFFFFFF) if v[0] == "k" else \
                ("b", "<<", ("u", "(unsigned long)", v), ("k", sh))
            return
        if m == "pcpyld" and len(ops) == 3:
            hi = ("k", 0) if ops[1] == "zero" else self.rd(ops[1])
            lo = ("k", 0) if ops[2] == "zero" else self.rd(ops[2])
            if ops[1] == "zero":
                R[ops[0]] = ("u", "(u_long128)", lo)      # MWCC's own 64 -> 128-bit conversion [C] pc14
                return
            if repr(lo) in self.zext128:
                lo = ("u", "(u_long128)", lo)
            for x in (hi, lo):
                self.use(x)
                self.consume(repr(x))
            qid = len(self.qbinds)
            self.qbinds.append((hi, lo))
            self.stmts.append(("qbind", qid))
            self.used_qorder = True
            R[ops[0]] = ("qb", qid)
            return
        if m == "cpyloop":
            S, D, C, step, temps = a.split(",")
            sv, dv, cv = self.rd(S), self.rd(D), self.rd(C)
            if cv[0] != "k" or cv[1] <= 0:
                raise Skip("aggregate copy with a non-constant count")
            sroot, soff = self.split(sv)
            droot, doff = self.split(dv)
            self.use(sroot)
            self.use(droot)
            self.stmts.append(("blk", droot, doff, sroot, soff, cv[1] * int(step), int(step)))
            for r in [S, D, C] + temps.split("/"):
                R[r] = ("x",)
            self.epoch += 1
            return
        if m in ("max.s", "min.s") and len(ops) == 3:
            # GtMath::Max / Min: an asm max.s / min.s inline; a computed argument goes through a float local first,
            # and so do two loaded ones (in argument order: passed directly they load reversed) [C] probes
            # build/vt/mx/fog7.cpp / fog8.cpp (CB3Fog::CalculateClipPlanes: one load beside a bound product stays),
            # gits.cpp / gits2.cpp (CB3TableComponent::GetImageAndTextSize)
            args = []
            raw = [self.rd(r) for r in ops[1:]]
            keep = ("p", "fk", "fb", "cf", "phi", "mv", "lv", "fcall") + (() if all(x[0] == "l" for x in raw) else ("l",))
            for x in raw:
                if x[0] not in keep:
                    self.use(x)
                    self.consume(repr(x))
                    fid = len(self.fbinds)
                    self.fbinds.append(x)
                    self.stmts.append(("fbind", fid))
                    x = ("fb", fid)
                args.append(x)
            R[ops[0]] = ("fcall", "GtMath::Max" if m == "max.s" else "GtMath::Min", args[0], args[1])
            return
        if m == "negu" and len(ops) == 2:
            v = self.rd(ops[1])
            R[ops[0]] = ("k", -v[1]) if v[0] == "k" else ("u", "-", v)
            return
        if m in FOPS:
            R[ops[0]] = ("b", FOPS[m], self.rd(ops[1]), self.rd(ops[2]))
            return
        # the R5900 FPU accumulator: MWCC's fused `x + y * z` / `x - y * z` (adda.s 0,x seeds it with x)
        if m in ("adda.s", "suba.s", "mula.s") and len(ops) == 2:
            x, y = self.rd(ops[0]), self.rd(ops[1])
            if m == "adda.s":
                R["acc"] = y if x == ("fk", 0) else x if y == ("fk", 0) else ("b", "+", x, y)
            elif m == "suba.s":
                R["acc"] = ("b", "-", x, y)
            else:
                R["acc"] = ("b", "*", x, y)
            return
        if m in ("madd.s", "msub.s") and len(ops) == 3:
            R[ops[0]] = ("b", "+" if m == "madd.s" else "-", self.rd("acc"), ("b", "*", self.rd(ops[1]), self.rd(ops[2])))
            return
        if m in ("madda.s", "msuba.s") and len(ops) == 2:
            R["acc"] = ("b", "+" if m == "madda.s" else "-", self.rd("acc"), ("b", "*", self.rd(ops[0]), self.rd(ops[1])))
            return
        raise Skip("instruction %s" % m + (" [%s]" % a if DIAG else ""))   # lift3: operands under DIAG

    def is_ptr(self, v):
        if v[0] in ("g", "gofs", "loc", "fn"):
            return True
        if v[0] == "p" and self.typing and self.named and self.ptypes.get(v[1], "").endswith("*"):
            return True
        if v[0] in ("p", "l", "c", "lv", "mv"):
            return repr(v) in self.ptr_roots
        if v[0] == "phi":
            ph = self.phis[v[1]]
            return repr(v) in self.ptr_roots or any(self.is_ptr(y) for y in self.phvals(ph))
        if v[0] == "b" and v[1] in ("+", "-") and self.is_ptr(v[2]):
            return True
        return False

    # -- calls ---------------------------------------------------------------------------------------------------
    def consume(self, v):
        self.consumed.add(v)
        self.recent.add(v)

    def vcall(self, tail):
        """A virtual call: t9 = *(*(obj + VP) + SLOT) with a0 = obj. MWCC puts the vptr where the class's first
        virtual function is declared and the first slot at +8 (compile probes), so the object's
        struct declares placeholder virtuals `vfunc_<slot offset>` at VP. The names are placeholders (user
        decision), the signatures [G] from the argument registers."""
        fv = self.R.get("t9")
        if not fv or fv[0] != "l" or self.loads[fv[1]]["root"][0] != "l":
            raise Skip("virtual call shape")
        L2 = self.loads[fv[1]]
        k1 = self.loads[fv[1]]["root"][1]
        L1 = self.loads[k1]
        root, VP, SLOT = L1["root"], L1["off"], L2["off"]
        if L1["mn"] != "lw" or L2["mn"] != "lw" or SLOT < 8 or SLOT % 4 or VP % 4 or VP < 0:
            raise Skip("virtual slot offset")
        sroot, soff = self.split(self.rd("a0"))
        if soff != 0 and soff == VP and self.same(sroot, root):
            # `this` is a member object at +VP with its own vptr at its start: a pseudo-root for it [G]
            o0 = self.obj(root)
            if o0["fields"].get(VP) in ("int", "void *"):
                del o0["fields"][VP]
            root, VP, soff = ("at", root, VP), 0, 0
            sroot = root
        if soff != 0 or not self.same(sroot, root):
            raise Skip("virtual call on another object than its vptr's")
        # the two loads are the dispatch, not data: no fields, no temporaries
        for L in (L1, L2):
            L["used"] = L["temp"] = False
            L["nodata"] = True
        self.objs.pop(repr(("l", k1)), None)
        self.ptr_roots.discard(repr(("l", k1)))
        o = self.obj(root)
        if o.get("vptr", VP) != VP:
            raise Skip("two vptr offsets")
        o["vptr"] = VP
        if o["fields"].get(VP) in ("int", "void *"):
            del o["fields"][VP]
        self.call(("virt", root, VP, SLOT), tail)

    def csig_args(self, target, hi, fhi):
        """The argument registers of an unk callee, from its asm (callee_sig.py; patch_csig.py) -> (hi, fhi)."""
        sig = callee_sig.params(target)
        if not sig:
            return hi, fhi
        g, f, exact = sig

        def live(r):
            return self.R.get(r, ("x",)) != ("x",)

        def leftover(r):
            v = self.R.get(r, ("x",))
            return v[0] == "x" or v == ("p", r) or repr(v) in self.recent

        nhi, nfhi = hi, fhi
        if g - 1 > nhi and all(live(GPR[i]) for i in range(nhi + 1, g)):
            nhi = g - 1
        if f - 1 > nfhi and all(live(FPR[i]) for i in range(nfhi + 1, f)):
            nfhi = f - 1
        if exact:
            while nhi >= g and leftover(GPR[nhi]):
                nhi -= 1
            while nfhi >= f and leftover(FPR[nfhi]):
                nfhi -= 1
        if (nhi, nfhi) == (hi, fhi):
            return hi, fhi
        self.used_csig = True
        if ((self.c.get("variant") or 0) // 25769803776) % 2:
            return hi, fhi
        return nhi, nfhi

    def call(self, target, tail):
        info = {"target": target, "tail": tail, "used": False, "usedf": False, "slot": len(self.stmts)}
        isptr = isinstance(target, tuple)
        if not isptr and target in LIBC:
            rt, plist = LIBC[target]
            info.update(kind="libc", plist=plist, rtype=rt)
            info["args"] = [self.rd(GPR[i]) for i in range(len(plist))]
            info["fargs"] = []
        elif isptr or target.startswith("func_") or ("__" not in target and not demangle(target)):
            # an unnamed function, or a plain C symbol (SDK / RenderWare / DirtySock): `extern "C"`, its
            # parameters inferred from the argument registers [G]
            # arguments: a0..aN up to the highest register written since entry / the last call
            # (a0 too when the function uses it at all; a named caller passes its own parameters on)
            written = [r for r in GPR if self.R[r] not in (("p", r), ("x",))]
            hi = max([GPR.index(r) for r in written] + [-1])
            if self.a0_relevant and self.R["a0"] != ("x",):
                hi = max(hi, 0)
            if self.named and not self.calls:
                hi = max([hi, 0] + [GPR.index(r) for r in self.caller_gprs if self.R[r] != ("x",)])
            fregs = [r for r in FPR if self.R[r] not in (("p", r), ("x",))]
            if self.named and not self.calls:
                fregs += [r for r in self.caller_fprs if self.R[r] != ("x",)]
            fhi = max([FPR.index(r) for r in fregs] + [-1])
            if isptr and target[0] == "virt":
                hi = max(hi, 0)                  # a0: the object
            if self.stackargs:
                hi = len(GPR) - 1                # arguments past t3 are on the stack: all eight registers too
            if not isptr and not self.stackargs:
                hi, fhi = self.csig_args(target, hi, fhi)
            info["args"] = [self.rd(GPR[i]) for i in range(hi + 1)] + [self.stackargs[k] for k in sorted(self.stackargs)]
            info["fargs"] = [self.rd(FPR[i]) for i in range(fhi + 1)]
            info["kind"] = ("virt" if target[0] == "virt" else "fptr") if isptr else "unk"
        else:
            dem = demangle(target)
            if not dem:
                raise Skip("callee %s not demangled" % target)
            pm = parse_method(dem)
            if pm:
                cls2, meth2, plist, const2 = pm
                if meth2.startswith("~") or meth2 == cls2:
                    raise Skip("callee ctor/dtor")
                info.update(kind="method", cls=cls2, meth=meth2, plist=plist, const=const2)
                first = 1
                # a static member (or a namespace function: same mangling [G]): no `this`, its arguments from a0
                # -- when the method layout reads a clobbered register and the static one does not
                ng = sum(1 for t in plist if not ptype(t)[3])

                def unreadable(r):
                    # clobbered, or a named caller's register that is not one of its parameters
                    v = self.R.get(r, ("x",))
                    return v[0] == "x" or (self.named and v == ("p", r) and r != "a0" and r not in self.caller_gprs)
                if not const2 and ng < len(GPR) and any(unreadable(r) for r in GPR[:ng + 1]) and \
                        not any(unreadable(r) for r in GPR[:ng]):
                    info["kind"] = "static"
                    first = 0
                elif not const2 and ng < len(GPR) and self.R.get("a0", ("x",))[0] == "p" and                         self.R["a0"][1] not in ("a0",) and self.R["a0"][1] in GPR and                         not self.is_ptr(self.R["a0"]) and not any(unreadable(r) for r in GPR[:ng]):
                    # `this` would be an integer parameter: a static member taking it as its first argument
                    # (func_003D1000) [G]; variant (v // 393216) % 2: the method reading
                    self.used_static = True
                    if not ((self.c.get("variant") or 0) // 393216) % 2:
                        info["kind"] = "static"
                        first = 0
            else:
                mm = re.fullmatch(r"(\w+)\((.*)\)", dem)
                if not mm:
                    raise Skip("callee shape %s" % dem[:40])
                info.update(kind="free", fname=mm.group(1), plist=split_params(mm.group(2)))
                first = 0
            gi, fi = first, 0
            args, fargs, types = [], [], []
            for t in info["plist"]:
                core, isp, isr, isf = ptype(t)
                if isf and not isr:
                    fargs.append(self.rd(FPR[fi])); fi += 1
                elif gi >= len(GPR):
                    sk = sorted(self.stackargs)
                    if gi - len(GPR) >= len(sk):
                        raise Skip("stack argument not stored")
                    args.append(self.stackargs[sk[gi - len(GPR)]]); gi += 1
                else:
                    a_ = self.rd(GPR[gi])
                    if t in ("unsigned long", "long") and a_[0] == "p" and a_[1] in GPR and not self.named:
                        self.dparams.add(a_[1])  # passed on whole to a 64-bit parameter: one itself (func_003D1000)
                    elif t in ("signed char", "char", "short", "unsigned char", "unsigned short") and a_[0] == "p"                             and a_[1] in GPR and not self.named and self.nparams.get(a_[1], t) == t:
                        self.nparams[a_[1]] = t  # ... to a narrow one unconverted: that type (func_0022CBE0) [G]
                    args.append(a_); gi += 1
                    if core in VECT and not isp:
                        if args[-1][0] != "vt":
                            try:
                                rt_, _ = self.split(args[-1])
                            except Skip:
                                rt_ = ("x",)
                            if rt_[0] not in ("p", "l", "g", "loc"):
                                raise Skip("vector argument not from a temporary")
                            continue              # a field's own address: the field itself (rendered in callstmt)
                        if self.vt_types.get(args[-1][1], core) != core:
                            raise Skip("vector temporary used as two classes")
                        self.vt_types[args[-1][1]] = core
            info["args"] = ([self.rd("a0")] if first else []) + args
            info["fargs"] = fargs
            # argument registers past the mangled signature, written since the last call and read by nothing
            # else: retail passes them, so the call goes through an extern "C" declaration that takes them
            # (variant (v // 384) % 2: dropped) [G]
            xs = [GPR.index(r) for r in GPR[gi:] if self.R[r] not in (("p", r), ("x",))
                  and repr(self.R[r]) not in self.recent]
            fxs = [FPR.index(r) for r in FPR[fi:] if self.R.get(r, ("x",)) not in (("p", r), ("x",))
                   and repr(self.R[r]) not in self.recent]
            # (extra arguments fill the registers after the signature's: a gap means there are none)
            if xs and any(self.R.get(GPR[i], ("x",))[0] == "x" for i in range(gi, max(xs) + 1)):
                xs = []
            if fxs and any(self.R.get(FPR[i], ("x",))[0] == "x" for i in range(fi, max(fxs) + 1)):
                fxs = []
            if xs or fxs:
                self.used_extra = True
                # the callee's asm reads none of them (callee_sig.py, exact): dropped by default (N145) [G]
                sig = callee_sig.params(target)
                drop0 = bool(sig and sig[2] and sig[0] <= gi and sig[1] <= fi)
                if (not ((self.c.get("variant") or 0) // 384) % 2) != drop0:
                    info["extra"] = [self.rd(GPR[i]) for i in range(gi, max(xs) + 1)] if xs else []
                    info["fextra"] = [self.rd(FPR[i]) for i in range(fi, max(fxs) + 1)] if fxs else []
        for v in info["args"] + info["fargs"] + info.get("extra", []) + info.get("fextra", []):
            self.use(v)
            self.consume(repr(v))
        idx = len(self.calls)
        info["idx"] = idx
        self.calls.append(info)
        self.recent = set()
        self.stackargs = {}
        self.stmts.append(("call", idx))
        self.epoch += 1
        for r in CALLER_SAVED:
            self.R[r] = ("x",)
        self.R["v0"] = ("c", idx)
        self.R["f0"] = ("cf", idx)
        if tail:
            self.ret = "tail"

    # -- emission ------------------------------------------------------------------------------------------------
    def path_rtype(self):
        """Region mode: the return type from the returned values, constants aside (a pointer wins)."""
        ts = [self.vtype(v, f) for v, f in self.path_rvs if v[0] not in ("k", "fk")]
        if not ts:
            return self.vtype(self.path_rvs[0][0], self.path_rvs[0][1])
        for t in ts:
            if t.endswith("*"):
                return t
        return ts[0]

    def l5_unify_returns(self, kinds):
        """lift5: paths returning differently (void / int / float) made one kind [G]: every path sets v0 -> an int
        function returning v0 (f0 a leftover: TriggerVoice); else every path sets f0 -> a float function; else a path
        that sets neither is void -> a void function (the values elsewhere are leftovers: func_003B8A50)."""
        if len(self.path_raw) != len(self.path_rvs):
            return kinds

        def ok(v, isf):
            if v is None or v[0] == "x" or v in (("p", "v0"), ("p", "v1"), ("p", "f0")):
                return False
            if v[0] == "p" and (v[1] in FPR) != isf:
                return False
            if v[0] in ("c", "cf") and (v[0] == "cf") != isf:
                return False
            if isf and v[0] in ("k", "fk") and repr(v) in self.consumed:
                return False             # (ret_value's: a constant left over from a compare/store)
            if v[0] not in ("c", "cf") and self.callish(v):
                return False
            return not (v[0] in ("wbits", "ibits") or (not isf and v[0] == "vlen"))
        raw = [r if r else (None, None) for r in self.path_raw]
        if all(ok(r[0], False) for r in raw):
            new, kind = [(r[0], False) for r in raw], False
        elif all(ok(r[1], True) for r in raw) and not all(ok(r[0], False) for r in raw):
            new, kind = [(r[1], True) for r in raw], True
        elif None in kinds and any(not ok(r[0], False) and not ok(r[1], True) for r in raw):
            new, kind = [None for r in raw], None
        else:
            return kinds
        swap = {}
        for k, (nv, (alt, rs)) in enumerate(zip(new, self.path_alts)):
            if nv is not None:
                self.use(nv[0])
            self.path_rvs[k] = nv
            swap[id(rs)] = ("ret", nv)

        def walk(lst):
            for q, x in enumerate(lst):
                if id(x) in swap:
                    lst[q] = swap[id(x)]
                elif x[0] == "if":
                    walk(x[2])
                    if x[3] is not None:
                        walk(x[3])
                elif x[0] == "swj":
                    for _, b, _ in x[2]:
                        walk(b)
                    if x[3] is not None:
                        walk(x[3])
                elif x[0] == "for":
                    walk(x[4])
        walk(self.stmts)
        self.used_l5ret = True
        return {kind}

    def ret_value(self, ret):
        """The value a `jr ra` returns: (value, is_float) or None (void)."""
        if ret is None or ret == "tail":
            return None
        v0, f0 = ret
        cands = []
        for v, isf in ((v0, False), (f0, True)):
            if v is None or v[0] == "x" or v[0] in ("c", "cf", "wbits", "ibits") or self.callish(v):
                continue                 # (wbits/ibits: a conversion's FPR temporary, not a value)
            if v == ("p", "v0") or v == ("p", "f0"):
                continue
            if v[0] == "p" and v[1] in ("v0", "v1", "f0"):
                continue
            if not isf and v[0] == "p" and v[1] in FPR:
                continue
            if isf and v[0] == "p" and v[1] in GPR:
                continue
            if isf and v[0] in ("k", "fk") and repr(v) in self.consumed:
                continue                 # a constant left over from a compare/store, not a return value [G]
            if not isf and v[0] == "vlen":
                continue                 # lift3: GetLength's GPR round trip (its float went on through mtc1)
            cands.append((v, isf))
        if len(cands) == 2 and cands[0][0][0] == "k" and cands[1][0][0] not in ("k", "fk"):
            # a constant v0 beside a float: variant (v // 25165824) % 2 returns the constant (an int function
            # whose f0 is a leftover: func_00391630) [G]
            self.used_kret = True
            if ((self.c.get("variant") or 0) // 25165824) % 2:
                return cands[0]
        if len(cands) == 2:
            fresh = [x for x in cands if repr(x[0]) not in self.consumed]
            if len(fresh) != 1:
                # v0 only feeds f0 (a constant / %hi half / an address under f0's load): the float is returned [G]
                v0v, f0v = cands[0][0], cands[1][0]
                if v0v[0] in ("k", "hi") or repr(v0v) in self.deps(f0v) or (
                        v0v[0] == "b" and v0v[1] in ("+", "<<") and f0v[0] == "l"):
                    fresh = [cands[1]]
                elif v0v[0] == "phi" and self.v0_temp(v0v, f0v):
                    fresh = [cands[1]]   # merged v0: on every path a temp (tested, a call's, feeding f0) [G]
                elif self.c.get("lift4") and self.addr_feeds(v0v, f0v):
                    fresh = [cands[1]]   # lift4: v0 an element address whose terms all feed f0's loads [G]
                    self._l4af = True
                else:
                    raise Skip("both v0 and f0 set" + (" [%r]" % (cands,) if DIAG else ""))   # lift4: census detail
            cands = fresh
        if cands and repr(cands[0][0]) in self.consumed:
            # variant (v // 12288) % 2: a leftover that was stored or passed is not the result (void: MWCC's
            # temporaries then start at v1 like retail's -- func_00135A90, func_00458940) [G]
            self.used_voidret = True
            if ((self.c.get("variant") or 0) // 12288) % 2:
                return None
        return cands[0] if cands else None

    def callish(self, v):
        """A merge of values that are all calls' leftover v0/f0 (or clobbered) on every path."""
        if v[0] in ("x", "c", "cf"):
            return True
        if v[0] != "phi":
            return False
        ph = self.phis[v[1]]
        return all(y is not None and self.callish(y) for y in self.phvals(ph))

    def v0_temp(self, x, f0):
        """x (a value v0 holds at a return, f0 also set) is a leftover on every path, not the result."""
        if x is None or x[0] in ("x", "c", "cf", "k", "hi"):
            return True
        if x[0] == "phi":
            ph = self.phis[x[1]]
            return all(self.v0_temp(y, f0) for y in self.phvals(ph))
        if repr(x) in self.consumed or repr(x) in self.deps(f0):
            return True
        if x[0] == "b" and x[1] in ("+", "<<"):
            # an element address left in v0 whose loads feed f0 (`p[i].f - p[i - 1].f`:
            # GetSegmentLengthFast__9CB3AILaneCFUs): every non-constant leaf of it is under f0 [G]
            d = self.deps(f0)
            leaves = []

            def walk(y):
                if y[0] == "b":
                    walk(y[2])
                    walk(y[3])
                elif y[0] != "k":
                    leaves.append(y)
            walk(x)
            return bool(leaves) and all(repr(y) in d for y in leaves)
        return False

    def addr_feeds(self, a, f):
        """lift4: a is address arithmetic (+, <<, *, constants) whose every non-constant leaf (a load, parameter, merge,
        loop variable) is among what feeds f's loads (`v0 = &p[i]` left over beside the float read from it)."""
        if not (a[0] == "b" and a[1] in ("+", "<<")):
            return False
        D = self.deps(f)
        leaves = []

        def walk(v):
            if v[0] == "b" and v[1] in ("+", "-", "<<", "*", "i*"):
                walk(v[2])
                walk(v[3])
            elif v[0] != "k":
                leaves.append(v)
        walk(a)
        return bool(leaves) and any(x[0] == "l" for x in leaves) and all(repr(x) in D for x in leaves) and \
            f[0] not in ("k", "fk")

    def deps(self, v, seen=None):
        """repr of v with every load expanded to its address root (to see what feeds it); phis expanded."""
        if isinstance(v, tuple) and v and v[0] == "phi":
            seen = seen or set()
            if v[1] in seen:
                return repr(v)
            seen.add(v[1])
            ph = self.phis[v[1]]
            return repr(v) + "".join(self.deps(y, seen) for y in self.phvals(ph))
        if isinstance(v, tuple) and v and v[0] == "l":
            L = self.loads[v[1]]
            return repr(v) + self.deps(L["root"])
        if isinstance(v, tuple):
            return repr(v) + "".join(self.deps(x) for x in v[1:] if isinstance(x, tuple))
        return repr(v)

    def collapse_copies(self):
        """A run of ("blk") pieces and load->store copies at one source/destination delta -> ("acopy", droot,
        doff, sroot, soff, type): MWCC's copy of an aggregate (known.md N132)."""
        st = self.stmts
        MT = {"lw": "int", "lwc1": "float", "lbu": "unsigned char", "lb": "signed char", "lhu": "unsigned short",
              "lh": "short", "lq": "u_long128"}
        MS = {"lw": 4, "lwc1": 4, "lbu": 1, "lb": 1, "lhu": 2, "lh": 2, "lq": 16}
        i = 0
        while i < len(st):
            if st[i][0] != "blk":
                i += 1
                continue
            _, droot, doff, sroot, soff, size, step = st[i]
            delta = doff - soff

            def piece(x):
                """-> member (soff, size, kind, load key or None) when x continues this run."""
                if x[0] == "blk" and self.same(x[1], droot) and self.same(x[3], sroot) and x[2] - x[4] == delta:
                    return (x[4], x[5], "blk%d" % x[6], None)
                if x[0] == "store" and x[3][0] == "l" and self.same(x[1], droot):
                    L = self.loads[x[3][1]]
                    if self.same(L["root"], sroot) and x[2] - L["off"] == delta and L["mn"] in MT and \
                            MS[L["mn"]] == {"sw": 4, "swc1": 4, "sb": 1, "sh": 2, "sq": 16}.get(x[4]):
                        return (L["off"], MS[L["mn"]], L["mn"], x[3][1])
                return None
            lo, hi = i, i + 1
            while lo > 0 and (st[lo - 1][0] == "load" or piece(st[lo - 1])):
                lo -= 1
            while hi < len(st) and (st[hi][0] == "load" or piece(st[hi])):
                hi += 1
            while lo < i and st[lo][0] == "load":
                lo += 1
            while hi > i + 1 and st[hi - 1][0] == "load":
                hi -= 1
            mem = [piece(x) for x in st[lo:hi] if x[0] != "load"]
            keys = {q[3] for q in mem if q[3] is not None}
            if any(x[0] == "load" and x[1] not in keys for x in st[lo:hi]):
                raise Skip("aggregate copy interleaved with other loads")
            mem.sort()
            blks = [q for q in mem if q[2].startswith("blk")]
            memberwise = len(mem) > 1
            if memberwise and not any(q[2] == "lq" for q in mem):
                raise Skip("memberwise aggregate copy without a quadword member")
            fields, al, pos = [], 1, mem[0][0]
            S0 = mem[0][0]
            for off, sz, kind, key in mem:
                if kind.startswith("blk"):
                    t, a_ = ("QARR|%d" % (sz // 16), 16) if kind != "blk8" else ("IARR|%d" % (sz // 4), 4)
                elif kind == "lq":
                    t, a_ = ("V3D" if memberwise else "u_long128"), 16
                else:
                    t = self.objs.get(repr(sroot), {}).get("fields", {}).get(off) or MT[kind]
                    if t.startswith(("ARR|", "AGG")):
                        raise Skip("aggregate copy member of an array type")
                    a_ = 4 if t.endswith("*") else SIZE.get(t, 4)
                if off != (pos + a_ - 1) // a_ * a_:
                    raise Skip("aggregate copy with a gap at +0x%X" % off)
                fields.append((off - S0, t))
                pos = off + sz
                al = max(al, a_)
            total = (pos - S0 + al - 1) // al * al
            if any(t == "V3D" for o_, t in fields):
                self.need_gtmath = True
            so = self.objs.get(repr(sroot)) or self.obj(sroot)
            do = self.objs.get(repr(droot)) or self.obj(droot)
            for o in (so, do):
                pass
            whole = S0 == 0 and sroot[0] == "p" and sroot[1] != "a0" and self.named and \
                not any(f_ >= total or f_ < 0 for f_ in so["fields"] if f_ not in dict(fields))
            for f_ in list(so["fields"]):
                if S0 <= f_ < S0 + total:
                    del so["fields"][f_]
            for f_ in list(do["fields"]):
                if doff - (soff - S0) <= f_ < doff - (soff - S0) + total:
                    del do["fields"][f_]
            D0 = S0 + delta
            if whole:
                for o_, t in fields:
                    so["fields"][o_] = t
                self.aggof[repr(sroot)] = (total, al)
                do["fields"][D0] = "AGGOF|" + repr(sroot)
                tname = None
            else:
                tname = "UnkStruct_%08X_c%d" % (self.addr, len(self.aggs))
                self.aggs[tname] = (fields, total, al)
                so["fields"][S0] = "AGG|" + tname
                do["fields"][D0] = "AGG|" + tname
            st[lo:hi] = [("acopy", droot, D0, sroot, S0, whole)]
            i = lo + 1

    def pinc_ok(self, t, k):
        """t (a placeholder struct this function declares) fits in k bytes, k a multiple of its alignment."""
        if not t.startswith("UnkStruct_") or self.psize.get(t, k) != k:
            return False
        end, al = 0, 1
        for o in self.objs.values():
            if o.get("type") != t:
                continue
            if "stride" in o:
                return False
            for off, ft in o["fields"].items():
                if not isinstance(ft, str) or ft.startswith(("ARR|", "AGG", "QARR|", "IARR|", "V3D")):
                    return False
                sz = 4 if ft.endswith("*") else SIZE.get(ft, 4)
                end, al = max(end, off + sz), max(al, sz)
        return end <= k and k % al == 0

    def vfield(self, root, off, kind="V3D"):
        """Type field +off of root as GtMathPs2::CGtV3d / CGtV4d (a u_long128 view of it is the same member)."""
        o = self.obj(root)
        if kind == "M34":
            # a CGtMatrix3x4 (four CGtV3d rows): the rows' own lq reads are the same memory
            for k_ in (0x10, 0x20, 0x30):
                if o["fields"].get(off + k_) in ("u_long128", "V3D"):
                    del o["fields"][off + k_]
                elif off + k_ in o["fields"]:
                    raise Skip("matrix row +0x%X used as %s" % (off + k_, o["fields"][off + k_]))
            if o["fields"].get(off, "M34") not in ("M34", "u_long128", "V3D"):
                raise Skip("field +0x%X used as %s and a matrix" % (off, o["fields"][off]))
            o["fields"][off] = "M34"
            self.vfields.add((repr(root), off))
            self.need_gtmath = True
            return
        cur = o["fields"].get(off, kind)
        if "V3P" in (cur, kind) or "SPH" in (cur, kind):
            # lift3: a keep-w assigned field: CGtV3dPlus (w by SetPlus, the vsubw.w/vaddx.w "W" form) or CGtSphere
            # (w by SetRadius, the vmulx.w "w" form) [G] -- CGtPlane has the same two bodies
            other = kind if cur in ("V3P", "SPH") else cur
            ln = self.vlanes.get((repr(root), off), set())
            if other not in ("V3P", "SPH", "u_long128", "V4D") or (other == "V4D" and not ln <= {"w", "W"}) \
                    or ln >= {"w", "W"}:
                raise Skip("field +0x%X used as %s and a keep-w vector" % (off, other))
            o["fields"][off] = "SPH" if "w" in ln else "V3P"
            self.vfields.add((repr(root), off))
            self.need_gtmath = True
            return
        if cur == "M34" and kind in ("V3D", "V4D"):
            raise Skip("field +0x%X used as a matrix and a vector" % off)
        if {cur, kind} == {"V3D", "V4D"}:
            kind = "V4D"                         # xyz lanes and w: a CGtV4d (it has the xyz setters too)
        elif cur not in (kind, "u_long128"):
            raise Skip("field +0x%X used as %s and a vector" % (off, o["fields"][off]))
        o["fields"][off] = kind
        self.vfields.add((repr(root), off))
        self.need_gtmath = True

    def fscalar(self, x):
        """A float value that reached a VU0 register through a GPR: float bits, a constant, or an lw of a field."""
        if x[0] == "fbits":
            return x[1]
        if x[0] == "k":
            return ("fk", x[1] & 0xFFFFFFFF)
        if x[0] == "l" and self.loads[x[1]].get("mn") == "lw":
            L = self.loads[x[1]]
            o = self.obj(L["root"])
            if o["fields"].get(L["off"], "int") not in ("int", "float"):
                raise Skip("vector lane from a %s field" % o["fields"][L["off"]])
            o["fields"][L["off"]] = "float"      # read as the float it is [G]
            L["mn"] = "lwc1"
            return x
        raise Skip("vector lane from an integer value")

    def vmat(self, v):
        """A computed vector with lanes set, used as an operand: a CGtV3d local (vlift) [G] --
        `CGtV3d vlN = base; vlN.SetY(f);`. Returns ("vloc", N)."""
        chain = []
        while v[0] == "vset":
            chain.append((v[2], v[3]))
            v = v[1]
        if v[0] not in VVAL or any(l_ in ("w", "W") for l_, x_ in chain):
            raise Skip("lane-set vector operand shape")
        self.vuse(v)
        sets = []
        for lane, x in reversed(chain):
            if x[0] == "lane":
                self.vuse(x[1])
            else:
                x = self.fscalar(x)
                self.use(x)
                self.consume(repr(x))
            sets.append((lane, x))
        k = self.nvloc = getattr(self, "nvloc", -1) + 1
        self.stmts.append(("vlocal", k, v, sets))
        self.need_gtmath = True
        return ("vloc", k)

    def vuse(self, v, kind="V3D"):
        """Type and use the fields a vector expression reads."""
        if v[0] == "vloc":
            return
        if v[0] == "vmem":
            self.vfield(v[1], v[2], kind)
            self.use(v[1])
        elif v[0] == "v4scale":
            self.vuse(v[1], "V4D")
            self.use(v[2])
            self.consume(repr(v[2]))
        elif v[0] in ("v4mul", "v4sub"):
            self.vuse(v[1], "V4D")
            self.vuse(v[2], "V4D")
        elif v[0] in ("vneg", "vsubv", "vaddv"):
            for x in v[1:]:
                self.vuse(x)
        elif v[0] == "vscale":
            self.vuse(v[1])
            self.use(v[2])
            self.consume(repr(v[2]))
        elif v[0] == "vcross":
            self.vuse(v[1])
            self.vuse(v[2])
        elif v[0] == "vxform":
            self.vfield(v[1], v[2], "M34")
            self.use(v[1])
            self.vuse(v[3])
        elif v[0] in ("vlerp4", "vlerp3"):        # lift3
            k_ = "V4D" if v[0] == "vlerp4" else "V3D"
            self.vuse(v[1], k_)
            self.vuse(v[2], k_)
            self.use(v[3])
            self.consume(repr(v[3]))
            if v[0] == "vlerp3":
                self.need_lerp3 = True
        else:
            raise Skip("vector expression %s" % v[0])

    def vexpr(self, v, operand=False):
        if v[0] == "vmem":
            return self.fexpr(v[1], v[2])
        if v[0] == "vloc":
            return "vl%d" % v[1]
        if v[0] == "vneg":
            e = "-%s" % self.vexpr(v[1], True)
        elif v[0] == "vsubv":
            e = "%s - %s" % (self.vexpr(v[1], True), self.vexpr(v[2], True))
        elif v[0] == "vaddv":
            e = "%s + %s" % (self.vexpr(v[1], True), self.vexpr(v[2], True))
        elif v[0] == "vscale":
            e = "%s * %s" % (self.vexpr(v[1], True), self.expr(v[2]))
        elif v[0] == "vcross":
            return "GtMathPs2::CrossProduct(%s, %s)" % (self.vexpr(v[1]), self.vexpr(v[2]))
        elif v[0] == "v4scale":
            e = "%s * %s" % (self.vexpr(v[1], True), self.expr(v[2]))
        elif v[0] in ("v4mul", "v4sub"):
            e = "%s %s %s" % (self.vexpr(v[1], True), "*" if v[0] == "v4mul" else "-", self.vexpr(v[2], True))
        elif v[0] == "vxform":
            return "GtMathPs2::TransformPoint(%s, %s)" % (self.fexpr(v[1], v[2]), self.vexpr(v[3]))
        elif v[0] in ("vlerp4", "vlerp3"):        # lift3
            return "GtMathPs2::Interpolate(%s, %s, %s)" % (self.vexpr(v[1]), self.vexpr(v[2]), self.expr(v[3]))
        else:
            raise Skip("vector expression %s" % v[0])
        return "(%s)" % e if operand else e

    def wholeexpr(self, root):
        if root[0] == "p":
            if root[1] == "a0":
                return "*this" if self.named else "*self"
            return self.pname(root[1]) if root[1] in self.refparams else "*" + self.pname(root[1])
        if root[0] == "g":
            return root[1]
        if root[0] == "loc":
            return "local"
        raise Skip("aggregate copy from a %s root" % root[0])

    def finish(self):
        c = self.c
        if self.used_blkcopy:
            self.collapse_copies()
            if any(x[0] == "blk" for x in self.stmts):
                raise Skip("aggregate copy loop not collapsed")
        # return value
        rv = None
        rtype = "void"
        if self.ret not in ("tail", "done"):
            rv = self.ret_value(self.ret)
            if rv:
                self.use(rv[0])
        if self.ret != "tail" and False:
            v0, f0 = self.ret
            cands = []
            for v, isf in ((v0, False), (f0, True)):
                if v is None or v[0] == "x" or v[0] in ("c", "cf"):
                    continue
                if v == ("p", "v0") or v == ("p", "f0"):
                    continue
                if v[0] == "p" and v[1] in ("v0", "v1", "f0"):
                    continue
                if not isf and v[0] == "p" and v[1] in FPR:
                    continue
                if isf and v[0] == "p" and v[1] in GPR:
                    continue
                if isf and v[0] in ("k", "fk") and repr(v) in self.consumed:
                    continue                 # a constant left over from a compare/store, not a return value [G]
                if not isf and v[0] == "vlen":
                    continue                 # lift3: GetLength's GPR round trip (its float went on through mtc1)
                cands.append((v, isf))
            if len(cands) == 2:
                fresh = [x for x in cands if repr(x[0]) not in self.consumed]
                if len(fresh) != 1:
                    raise Skip("both v0 and f0 set")
                cands = fresh
            rv = cands[0] if cands else None
            if rv:
                self.use(rv[0])
        # caller identity
        if self.named:
            pm = parse_method(c["demangled"])
            if not pm:
                raise Skip("unsupported name shape")
            self.ccls, self.meth, plist, self.cconst = pm
            if self.meth.startswith("~") or self.meth == self.ccls:
                raise Skip("ctor/dtor")
            if self.has_header(self.ccls):
                # lift3: the class has a hand header in include/ whose layout is pads + the few proven fields; declare
                # it locally with only what this function touches, as the hand-matched units of such classes do
                # (B3AITarget_00149140.cpp: CB3AITarget, a163) -- was: refused ("class already has a header")
                self.own_hdr = True
            # a0 used only as a plain value and the last integer parameter register unused: a static member
            # ([G]: the mangling does not mark static; the byte match is what is verified)
            ngpr = len([t for t in plist if not ptype(t)[3]])
            a0_obj = repr(("p", "a0")) in self.objs or repr(("p", "a0")) in self.ptr_elem
            self.static = (self.a0_value and not a0_obj and not self.cconst and 1 <= ngpr < len(GPRX)
                           and GPRX[ngpr] not in self.used_params and ("p", "a0") not in
                           [C["args"][0] for C in self.calls if C["kind"] == "method" and C["args"]])
            self.pnames = {} if self.static else {"a0": "this"}
            self.ptypes = {} if self.static else {"a0": self.ccls + " *"}
            gi, fi = (0 if self.static else 1), 0
            self.plist = []
            for k, t in enumerate(plist):
                core, isp, isr, isf = ptype(t)
                pn = "p%d" % k
                self.need_type(t)
                self.plist.append((t, pn))
                if isf and fi >= len(FPR):
                    raise Skip("float parameter past f19")
                reg = FPR[fi] if isf else GPRX[gi]
                if isf:
                    fi += 1
                else:
                    gi += 1
                self.pnames[reg] = pn
                # a reference parameter is typed as the pointer it is in the register; rendered `p.` / `&p`
                self.ptypes[reg] = t.replace("&", "*") if isr else t
                if isr:
                    self.refparams.add(reg)
                    isf = False
            for r in self.used_params:
                if r not in self.pnames:
                    raise Skip("uses register %s that is not a parameter" % r)
        for key, L in self.loads.items():
            if not L.get("used") and not L.get("nodata") and not L.get("relj"):
                raise Skip("dead load")
        for st in self.all_stmts():
            if st[0] != "store":
                continue
            o = self.objs[repr(st[1])]
            if st[4] == "sb" and st[3][0] == "p" and self.named and self.ptypes.get(st[3][1]) == "bool" and                     o["fields"].get(st[2]) in ("unsigned char", "signed char"):
                # a bool parameter stored: a bool field (else MWCC tests the truncated copy, `andi 255`:
                # Gt2dRenderer::EnableZTest) [G]
                o["fields"][st[2]] = "bool"
            if (st[4] == "sw" and st[3][0] == "p" and self.named and self.ptypes.get(st[3][1], "").endswith("*")
                    and o["fields"].get(st[2]) in ("int", "void *")):
                pt = self.ptypes[st[3][1]]
                o["fields"][st[2]] = pt.rstrip("*").strip() + " " + "*" * (len(pt) - len(pt.rstrip("*")))
            elif st[4] == "sw" and self.is_ptr(st[3]) and o["fields"].get(st[2]) == "int":
                o["fields"][st[2]] = "void *"
            if st[4] == "sw" and st[3][0] == "k" and float_like(st[3][1]) and o["fields"].get(st[2]) == "int":
                if not any(self.same(L["root"], st[1]) and L["off"] == st[2] for L in self.loads.values()):
                    o["fields"][st[2]] = "float"
        self.typing = True
        for key, o in list(self.objs.items()):
            self.name_one(o)
        if self.pathmode:
            kinds = {None if r is None else r[1] for r in self.path_rvs}
            if kinds == {None, False} and all(r is not None or a[0] is not None
                                              for r, a in zip(self.path_rvs, self.path_alts)):
                # the void-looking paths return their call's result (`return f(x);` before the epilogue) [G]
                swap = {}
                for k, (r, (alt, rs)) in enumerate(zip(self.path_rvs, self.path_alts)):
                    if r is None:
                        self.use(alt[0])
                        self.path_rvs[k] = alt
                        swap[id(rs)] = ("ret", alt)

                def walk(lst):
                    for q, x in enumerate(lst):
                        if id(x) in swap:
                            lst[q] = swap[id(x)]
                        elif x[0] == "if":
                            walk(x[2])
                            if x[3] is not None:
                                walk(x[3])
                        elif x[0] == "swj":
                            for _, b, _ in x[2]:
                                walk(b)
                            if x[3] is not None:
                                walk(x[3])
                        elif x[0] == "for":
                            walk(x[4])
                walk(self.stmts)
                kinds = {False}
            if len(kinds) > 1 and None in kinds and all(r is None or repr(r[0]) in self.consumed for r in self.path_rvs):
                # every value-returning path only leaves a stored/passed value behind: a void function [G]
                gone = {}

                def unret(lst):
                    for q, x in enumerate(lst):
                        if x[0] == "ret" and x[1] is not None:
                            lst[q] = ("ret", None)
                        elif x[0] == "if":
                            unret(x[2])
                            if x[3] is not None:
                                unret(x[3])
                        elif x[0] == "swj":
                            for _, b, _ in x[2]:
                                unret(b)
                            if x[3] is not None:
                                unret(x[3])
                        elif x[0] == "for":
                            unret(x[4])
                unret(self.stmts)
                self.path_rvs = [None for r in self.path_rvs]
                kinds = {None}
            if len(kinds) > 1 and self.c.get("lift5"):
                kinds = self.l5_unify_returns(kinds)
            self.path_rvs = [r for r in self.path_rvs if r]
            if len(kinds) != 1:
                raise Skip("paths return differently (void / int / float)" + (" [%r]" % (self.path_rvs,) if DIAG else ""))
        self.rtype = "void"
        if rv:
            self.rtype = self.vtype(rv[0], rv[1])
        elif self.pathmode and self.path_rvs:
            self.rtype = self.path_rtype()
        self.render(rv)                  # first pass settles object/field types
        if not self.named:
            for st in self.all_stmts():
                if st[0] == "store" and st[3][0] == "p" and repr(st[3]) not in self.objs and st[3][1] in GPR:
                    ft = self.ftype(st[1], st[2])
                    if ft.endswith("*"):
                        self.poverride[st[3][1]] = ft
        if not self.named:
            # a parameter compared (==, !=) with a 64-bit value is 64-bit itself: an int would be sign-extended
            # first (dsll32/dsra32; func_003F5E40 against an `ld` element) [G]
            def walkv(t):
                if isinstance(t, (list, tuple)):
                    if len(t) >= 4 and t[0] == "b" and t[1] in ("==", "!=") and isinstance(t[2], tuple)                             and isinstance(t[3], tuple):
                        for a_, b_ in ((t[2], t[3]), (t[3], t[2])):
                            if a_[:1] == ("p",) and a_[1] in GPR and repr(a_) not in self.objs                                     and a_[1] not in self.dparams:
                                try:
                                    bt = self.vtype(b_)
                                except Exception:
                                    bt = None
                                if bt in ("long", "unsigned long"):
                                    self.dparams.add(a_[1])
                    for z in t:
                        walkv(z)
            walkv(self.stmts)
        if self.pathmode and self.path_rvs and not rv:
            self.rtype = self.path_rtype()
        if rv or self.pathmode:
            if rv:
                self.rtype = self.vtype(rv[0], rv[1])
            for r in self.path_rvs:
                t = self.vtype(r[0], r[1])
                if t.endswith("*") and not self.rtype.endswith("*"):
                    self.rtype = t
        return self.render(rv)

    def name_one(self, o):
        if "type" in o:
            return
        if True:
            r = o["root"]
            if r[0] == "p":
                if r[1] == "a0":
                    o["type"] = self.ccls if self.named else "UnkStruct_%08X" % self.addr
                elif self.named:
                    t = self.ptypes.get(r[1], "")
                    core = t.replace("const", "").replace("*", "").strip()
                    if t.endswith("*") and t.count("*") == 1 and core in tiny_gen.BUILTIN and core != "void":
                        o["type"], o["deref"] = core, True      # `*pN`: a pointer to a builtin
                        return
                    if t.endswith("*") and t.count("*") == 1 and core in VECT:
                        o["type"], o["deref"] = core, True      # `*pN`: a GtMathPs2 vector out-parameter (vlift)
                        return
                    if core in VECT and "*" not in t:
                        # a GtMathPs2 vector passed by value: its address arrives in the register (vlift) [C] N128
                        o["type"], o["deref"] = core, True
                        self.refparams.add(r[1])
                        return
                    if not t.endswith("*") or core in tiny_gen.BUILTIN or not re.fullmatch(r"\w+(::\w+)?", core):
                        raise Skip("parameter %s (%s) used as a pointer" % (r[1], t))
                    if self.has_header(core):
                        raise Skip("parameter class %s has a header" % core)
                    o["type"] = core
                else:
                    o["type"] = "UnkStruct_%08X_%s" % (self.addr, r[1])
            elif r[0] == "g":
                o["type"] = "UnkStruct_%s" % r[1]
            elif r[0] == "ix":
                key = (self.ckt(repr(r[1])), r[2], r[3])
                if key not in self.etypes:
                    self.etypes[key] = "UnkStruct_%08X_e%d" % (self.addr, len(self.etypes))
                o["type"] = self.etypes[key]
            else:
                o["type"] = "UnkStruct_%08X_%d" % (self.addr, o["n"])

    def vtype(self, v, isf=False):
        if isf or v[0] in ("fcall", "fb", "gsl", "dotp", "glen"):
            return "float"
        if v[0] == "qb" or (v[0] == "u" and v[1] == "(u_long128)"):
            return "u_long128"
        if v[0] == "u" and v[1] == "(unsigned long)":
            return "unsigned long"
        if self.c.get("lift5") and (v[0] == "sl32" or (v[0] == "b" and v[1] in ("<<", "|", "&", ">>u", "+") and
                                                       "unsigned long" in (self.vtype(v[2]), self.vtype(v[3])))):
            return "unsigned long"               # lift5: 64-bit GS packet expressions
        if v[0] == "k" and v[1] > 0xFFFFFFFF:
            return "unsigned long"
        if v[0] == "lv":
            o = self.objs.get(repr(v))
            return (o["type"] + " *") if self.lvars[v[1]].get("ptr") and o and "type" in o else \
                self.lvars[v[1]].get("type", "int")
        if v[0] == "mv":
            o = self.objs.get(repr(v))
            if o and "type" in o:
                return o["type"] + " *"
            M = self.mvars[v[1]]
            if M["isf"]:
                return "float"
            t = self.vtype(M["init"])
            if not M.get("typing") and M.get("end") is not None:
                M["typing"] = True                       # a pointer assigned in the loop makes it a pointer
                try:
                    te = self.vtype(M["end"])
                finally:
                    M["typing"] = False
                if te.endswith("*") and not t.endswith("*"):
                    t = te
            return "int" if t == "bool" else t
        if v[0] == "l":
            L = self.loads[v[1]]
            if L.get("tempname") and not L.get("pun"):
                cs = self.lcast(v[1])
                if cs:
                    return cs[1:-1]
            return L.get("pun") or self.ftype(L["root"], L["off"])
        if v[0] == "p" and repr(v) in self.objs:
            return self.objs[repr(v)]["type"] + " *"
        if v[0] == "p" and self.typing and repr(v) in self.ptr_elem and not self.named:
            return self.elem_type(self.ptr_elem[repr(v)]) + " *"
        if v[0] == "p":
            if self.named and v[1] in self.ptypes:
                return self.ptypes[v[1]]
            if v[1] in self.poverride:
                return self.poverride[v[1]]
            return "float" if v[1] in FPR else "int"
        if v[0] in ("g", "gofs", "fn"):
            return "void *"
        if v[0] == "loc":
            o = self.objs.get(repr(v))
            return (o["type"] + " *") if o and "type" in o else "void *"
        if v[0] == "b" and v[1] in ("<", "<u", "!=", "==", ">=", "<=", ">", ">=u", "f==", "f<", "f<="):
            return "bool"
        if v[0] == "b" and v[1] == "^" and v[3] == ("k", 1) and self.vtype(v[2]) == "bool":
            self.used_notb = True
            if ((self.c.get("variant") or 0) // 201326592) % 2:
                return "bool"                            # `!b` (an int `b ^ 1` adds andi 255) [C] probe hif1
        if v[0] == "b" and v[1] == "+" and (self.is_ptr(v[2]) or self.is_ptr(v[3])):
            return "void *"
        if v[0] == "fk":
            return "float"
        if v[0] == "b" and v[1] in ("*", "/") or (v[0] == "b" and "float" in (self.vtype(v[2]), self.vtype(v[3]))):
            return "float"
        if v[0] == "u" and (v[1] == "(float)" or self.vtype(v[2]) == "float" and v[1] != "(int)"):
            return "float"
        if v[0] == "c":
            o = self.objs.get(repr(v))
            if self.calls[v[1]]["used"] and o is not None and "type" in o:
                return o["type"] + " *"           # a result used as an object pointer (the callee's crt)
            if self.cptr(self.calls[v[1]]):
                return "void *"
            return "int"
        if v[0] == "cf":
            return "float"
        if v[0] == "phi":
            ph = self.phis[v[1]]
            if v[1] in self.boolphis:
                return "bool"
            o = self.objs.get(repr(v))
            if self.typing and o is not None and "type" in o:
                return o["type"] + " *"            # a merged pointer used as an object (`v0->f`)
            if "more" in ph:
                ts = [self.vtype(y) for y in self.phvals(ph) if y[0] != "k"] or ["int"]
                return next((t for t in ts if t.endswith("*")), ts[0])
            ta, tb = self.vtype(ph["a"]), self.vtype(ph["b"])
            if ph["a"][0] == "k":
                return tb
            if tb.endswith("*") and not ta.endswith("*"):
                return tb
            return ta
        return "int"

    def elem_type(self, ixkey):
        o = self.objs[ixkey]
        if self.scalar_elem(o["root"]):
            return self.ftype(o["root"], 0)      # a loaded element used as an object is that object's pointer
        return o["type"]

    def ltype(self, key):
        """The pointer type a load's own value is used as (its object / array element), or None."""
        k = repr(("l", key))
        if k in self.ptr_elem:
            return self.elem_type(self.ptr_elem[k]) + " *"
        if k in self.objs and "type" in self.objs[k]:
            return self.objs[k]["type"] + " *"
        return None

    def lcast(self, key):
        """The cast a load needs to be used as its own type, when the field is declared as another ("" if none)."""
        L = self.loads[key]
        if L.get("pun"):
            return ""
        t = self.ltype(key)
        if t is None or not self.typing:
            return ""
        try:
            ft = self.ftype(L["root"], L["off"])
        except (KeyError, Skip):
            return ""
        return "" if ft == t else "(%s)" % t

    def ftype(self, root, off):
        o = self.objs[repr(root)]
        t = o["fields"][off]
        # every root of this type (as the struct emitter): the first load of the field with an object gives its type
        troots = [root] + [x["root"] for x in self.objs.values() if "type" in o and x.get("type") == o["type"]
                           and not self.same(x["root"], root)]
        # a loaded pointer used as a root (or indexed as an array)
        for key, L in self.loads.items():
            if any(self.same_t(L["root"], r) for r in troots) and L["off"] == off:
                k = repr(("l", key))
                if k in self.ptr_elem:
                    return self.elem_type(self.ptr_elem[k]) + " *"
                if k in self.objs:
                    return self.objs[k]["type"] + " *"
        if t.startswith("ARR|"):
            return self.elem_type(t[4:]) + " *"
        return {"V3D": "GtMathPs2::CGtV3d", "V4D": "GtMathPs2::CGtV4d", "M34": "GtMathPs2::CGtMatrix3x4",
                "V3P": "GtMathPs2::CGtV3dPlus", "SPH": "GtMathPs2::CGtSphere"}.get(t, t)   # lift3: V3P / SPH

    def scalar_elem(self, root):
        o = self.objs.get(repr(root))
        if not o or list(o["fields"]) != [0]:
            return False
        t = o["fields"][0]
        return (4 if t.endswith("*") else SIZE.get(t, 0)) == root[3]

    def garray(self, base):
        """A global used only as a scalar array from offset 0: declared `extern T SYM[];`."""
        if base[0] != "g":
            return None
        o = self.objs.get(repr(base))
        if not o or list(o["fields"]) != [0] or not o["fields"][0].startswith("ARR|"):
            return None
        ek = o["fields"][0][4:]
        if not self.scalar_elem(self.objs[ek]["root"]):
            return None
        return self.elem_type(ek)

    def ixexpr(self, root):
        _, base, K0, S, idx = root
        if self.garray(base):
            return "%s[%s]" % (base[1], self.expr(idx))
        if self.ck(self.ptr_elem.get(repr(base)) or "") == self.ck(repr(root)) or self.same_elem(base, K0, S):
            b = self.expr(base)
            if base[0] == "l" and not self.loads[base[1]].get("tempname"):
                cs = self.lcast(base[1])          # a re-load indexed as another element type (no code) [G]
                if cs:
                    b = "(%s%s)" % (cs, b)
            return "%s[%s]" % (b, self.iexpr(idx))
        return "%s[%s]" % (self.fexpr(base, K0), self.iexpr(idx))

    def same_elem(self, base, K0, S):
        """base is an element pointer (ptr_elem) of stride S indexed by another index (`p[i]` and `p[i - 1]`)."""
        st = self.ptr_elem.get(repr(base))
        if not st or K0 != 0:
            return False
        try:
            sr = ast.literal_eval(st)
        except (ValueError, SyntaxError):
            return False
        return sr[0] == "ix" and sr[2] == 0 and sr[3] == S and self.ck(repr(sr[1])) == self.ck(repr(base))

    def iexpr(self, idx):
        e = self.expr(idx)
        if self.typing and self.vtype(idx).endswith("*"):
            return "(int)" + e
        return e

    def pexpr(self, root, off, pun):
        """A field access, through a pointer cast when it is a pun of the declared type."""
        e = self.fexpr(root, off)
        if pun and pun != self.ftype(root, off):
            return "*(%s *)&%s" % (pun, e)
        return e

    def fexpr(self, root, off):
        if root[0] == "ix" and self.scalar_elem(root):
            return self.ixexpr(root)
        if root[0] == "p" and self.objs.get(repr(root), {}).get("deref"):
            if off:
                raise Skip("builtin pointer parameter used with an offset")
            o_ = self.objs[repr(root)]
            if o_.get("type") in VECT and o_["fields"].get(0) not in ("V3D", "V4D"):
                # a GtMathPs2 vector parameter read / written as its 128 bits (lq/sq) (vlift)
                return ("%s.mData" if root[1] in self.refparams else "%s->mData") % self.pname(root[1])
            return ("%s" if root[1] in self.refparams else "*%s") % self.pname(root[1])
        if root[0] == "g" and root[1] in self.smembers:
            if off:
                raise Skip("static member used as a struct")
            return "%s::%s" % self.smembers[root[1]]
        o_ = self.objs.get(repr(root))
        if o_ is not None and o_.get("type") == "GtMathPs2::CGtV2d":   # lift3: the header's CGtV2d (marValues[2])
            if off not in (0, 4) or o_["fields"].get(off) != "float":
                raise Skip("CGtV2d field +0x%X as %s" % (off, o_["fields"].get(off)))
            self.need_gtmath = True
            return "%smarValues[%d]" % (self.objexpr(root), off // 4)
        if o_ is not None and o_.get("type") == SPACE:      # lift3: Gt2dObject.h's member names
            ft_ = o_["fields"].get(off)
            if off == 0x10:
                mem = {"float": "mColour.f[0]", "V4D": "mColour", "u_long128": "mColour.mData"}.get(ft_)
            else:
                mem = SPACE_MEMBERS.get(off) if ft_ == "float" else None
            if mem is None:
                raise Skip("CGt2dObjectSpace field +0x%X as %s" % (off, ft_))
            self.need_g2d = True
            return "%s%s" % (self.objexpr(root), mem)
        return "%sfield_%X" % (self.objexpr(root), off)

    def objexpr(self, root):
        """Expression for the object a root points to, as `X->` / `X.` prefix."""
        if root[0] == "loc":
            return "local."
        if root[0] == "ix":
            return self.ixexpr(root) + "."
        if root[0] == "p":
            if root[1] == "a0":
                return "" if self.named else "self->"
            if root[1] in self.refparams:
                return "%s." % self.pname(root[1])
            return "%s->" % self.pname(root[1])
        if root[0] == "g":
            return "%s." % root[1]
        if root[0] == "l":
            cs = "" if self.loads[root[1]].get("tempname") else self.lcast(root[1])
            if cs:
                return "(%s%s)->" % (cs, self.expr(root))
            return "%s->" % self.expr(root)
        if root[0] == "c":
            return "%s->" % self.callexpr(root[1])
        if root[0] == "phi":
            return "v%d->" % root[1]
        if (root[0] == "lv" and self.lvars[root[1]].get("ptr")) or root[0] == "mv":
            return "%s->" % self.expr(root)
        if root[0] == "at":
            # an object inside another at a byte offset (a member with its own vptr)
            o = self.obj(root)
            return "((%s *)((char *)%s %s))->" % (o["type"], self.expr(root[1]), sofs(root[2]))
        raise Skip("object root %s" % (root[0],))

    def pname(self, r):
        if self.named:
            return self.pnames[r]
        if r == "a0":
            if repr(("p", "a0")) in self.objs or repr(("p", "a0")) in self.ptr_elem or self.self_cls:
                return "self"
            return "n0"
        if r in FPR:
            return "f%d" % FPR.index(r)
        return "p%d" % (GPRX.index(r) - 1)

    def callexpr(self, idx):
        C = self.calls[idx]
        if C.get("inline"):
            return self.callstmt(C)
        if not C.get("temp"):
            raise Skip("call result used as an object before binding")
        return C["temp"]

    def expr(self, v, top=True):
        k = v[0]
        if k == "k":
            return str(v[1]) if v[1] < 0x10000 or v[1] < 0 else "0x%X" % v[1]
        if k == "fk":
            return flit(v[1])
        if k == "p":
            if v[1] in self.refparams:
                return "&%s" % self.pname(v[1])
            return self.pname(v[1])
        if k == "loc":
            self.obj(v)
            return "&local"
        if k == "g":
            if v[1] in self.smembers:
                raise Skip("address of a static member")
            self.obj(v)
            return "&%s" % v[1]
        if k == "fn":
            # through an extern "C" declaration of the mangled name (same symbol for a static member or a
            # namespace function) [G] its return type
            dem = demangle(v[1])
            pl = re.search(r"\((.*)\)", dem).group(1)
            types = []
            for t in (split_params(pl) if pl and pl != "void" else []):
                core, isp, isr, isf = ptype(t)
                types.append(("const void *" if "const" in t else "void *") if (isp or isr) and core is not None else t)
            d = 'extern "C" void %s(%s);  // %s, its address taken' % (v[1], ", ".join(types), dem)
            if d not in self.decls:
                self.decls.append(d)
            return "(void *)&%s" % v[1]
        if k == "gofs":
            if v[1] in self.smembers:
                raise Skip("address of a static member")
            self.obj(("g", v[1]))
            return "((char *)&%s %s)" % (v[1], sofs(v[2]))
        if k == "sl32" and self.c.get("lift5"):
            # lift5: a dsll32 not undone by dsra32/dsrl32: a 64-bit shift `(unsigned long)x << 32+n` [G]
            return self.expr(("b", "<<", ("u", "(unsigned long)", v[1]), ("k", 32 + v[2])), top)
        if k == "l":
            L = self.loads[v[1]]
            if L.get("tempname"):
                return L["tempname"]
            return self.pexpr(L["root"], L["off"], L.get("pun"))
        if k == "c":
            C = self.calls[v[1]]
            if C.get("inline"):
                return self.callstmt(C)          # a call moved into the test that reads its result
            return C["temp"]
        if k == "cf":
            C = self.calls[v[1]]
            if not C.get("temp"):
                raise Skip("float call result used before binding")
            return C["temp"]
        if k == "phi":
            if v[1] in self.phi_alias:
                return "m%d" % self.phi_alias[v[1]]
            return "v%d" % v[1]
        if k == "mv":
            if self.mvars[v[1]].get("asparam"):
                return self.expr(self.mvars[v[1]]["init"], top)      # lift4: `while (p2--)`
            return "m%d" % v[1]
        if k == "lv":
            if self.lvars[v[1]].get("ptr"):
                return "q" if v[1] == 0 else "q%d" % v[1]
            return "i" if v[1] == 0 else "i%d" % v[1]
        if k == "fcall" and v[3] is None:       # lift3: GtMath::Abs(float), a file-local stand-in
            self.need_abs = True
            return "%s(%s)" % (v[1], self.expr(v[2], False))
        if k == "fcall":
            self.need_gtmath1 = True
            return "%s(%s, %s)" % (v[1], self.expr(v[2], False), self.expr(v[3], False))
        if k == "fb":
            return "mm%d" % v[1]
        if k == "qb":
            return "q%d" % v[1]
        if k in ("gsl", "glen"):
            e_ = self.vexpr(v[1], True)
            if e_.startswith("*"):
                e_ = "(%s)" % e_                       # lift3: `(*pN).X()` -- was `*pN.X()` (a compile error)
            return "%s.%s()" % (e_, "GetSquaredLength" if k == "gsl" else "GetLength")
        if k == "dotp":
            return "GtMathPs2::DotProduct(%s, %s)" % (self.vexpr(v[1]), self.vexpr(v[2]))
        if k in ("fbits", "vmem", "vgpr", "vset", "vone", "vsq", "vdot"):
            raise Skip("a float's bits / a vector used as a value")
        if k == "u":
            if v[2][0] == "lv" and v[1] == "(%s)" % self.vtype(v[2]):
                return self.expr(v[2], False)      # a narrow counter's re-extension: already that type
            if v[1] in ("-", "~") and self.typing and self.vtype(v[2]).endswith("*"):
                return "(%s(int)%s)" % (v[1], self.expr(v[2], False))     # a pointer negated (no code)
            return "(%s%s)" % (v[1], self.expr(v[2], False))
        if k == "b":
            op = v[1]
            x, y = v[2], v[3]
            if op == "^" and y == ("k", 1) and self.vtype(x) == "bool" and                     ((self.c.get("variant") or 0) // 201326592) % 2:
                return "(!%s)" % self.expr(x, False)
            if op in ("!=", "==") and v[4:] == ("keepb",):
                return "(%s %s false)" % (self.expr(x, False), op)
            if op == "!=" and y == ("k", 0) and x[0] == "b" and x[1] in ("<", "<u", "!=", "==", ">=", "<=", ">", ">=u"):
                # a compare re-tested (`sltu v0,zero,v0` twice): `(c) != false` keeps both [C] probe sltu4 (IsPlaying)
                return "(%s != false)" % self.expr(x, False)
            if op in ("!=", "==") and y == ("k", 0) and self.vtype(x) == "bool":
                # a bool tested bare: `p != 0` masks it first (`andi 255`), `if (p)` does not [C] probe b1/b2
                return ("%s" if op == "!=" else "(!%s)") % self.expr(x, False)
            if op == "+" and not self.is_ptr(y) and y[0] != "k" and (self.is_ptr(x) or x[0] in ("p", "l")) and \
                    not (repr(v) in self.int_idx and not self.is_ptr(x)):
                try:
                    ix = self.split_idx(v, 0)
                except Skip:
                    ix = None
                if ix and ix[1] == 0:
                    if not self.typing:
                        pass
                    self.name_one(self.objs[repr(ix[0])]) if self.typing else None
                    ea = "&%s" % self.ixexpr(ix[0])
                    self.used_eaddr = True
                    et = self.objs.get(repr(ix[0]), {}).get("type")
                    ie = self.iexpr(ix[0][4])
                    if self.typing and et and re.fullmatch(r"[A-Za-z_]\w*", ie) and                             ((self.c.get("variant") or 0) // 402653184) % 2:
                        # variant: the element address through a pointer local declared after the index (`E *ea0 =
                        # &a[i];`, the base first in the addu) [C] probe p_atv2 (AddTrafficVehicle__17CB3PhysicsManager)
                        return self.eaddr.setdefault(ea, ("ea%d" % len(self.eaddr), et, ie))[0]
                    return ea
            if op in ("+", "-") and not self.is_ptr(x) and not self.is_ptr(y) and has_shift(v):
                # MWCC's shift-and-add expansion of a multiply by a constant: `x * K` [G]
                li = self.lin(v)
                if li and li[1] not in (0, 1) and li[0][0] != "k" and self.vtype(li[0]) != "float":
                    return "(%s * %d)" % (self.expr(li[0], False), li[1])
            if op == "+" and self.is_ptr(y) and not self.is_ptr(x) and x[0] != "k":
                # variant (v // 100663296) % 2: an integer plus a pointer written as integers (`f + (int)self`):
                # MWCC keeps the operand order (func_0021AAF0) [G]
                self.used_intadd = True
                if ((self.c.get("variant") or 0) // 100663296) % 2:
                    return "((char *)(%s + (int)%s))" % (self.expr(x, False), self.expr(y, False))
            if op == "+" and self.is_ptr(y) and not self.is_ptr(x):
                x, y = y, x
            if op in ("+", "-") and self.is_ptr(x):
                if y[0] == "k":
                    return "((char *)%s %s 0x%X)" % (self.expr(x, False), op, y[1])
                ys = self.expr(y, False)
                if self.is_ptr(y) or (self.typing and self.vtype(y).endswith("*")):
                    ys = "(int)" + ys
                return "((char *)%s %s %s)" % (self.expr(x, False), op, ys)
            if op == "<u" and y == ("k", 1):
                if x[0] == "b" and x[1] == "^" and x[3][0] == "k":
                    return "(%s == %s)" % (self.expr(x[2], False), self.expr(x[3], False))
                return "(%s == 0)" % self.expr(x, False)
            if op == "!=" and y == ("k", 0):
                return "(%s != 0)" % self.expr(x, False)
            if op in ("+", "-") and self.typing and self.vtype(v) == "float":
                fm = [z for z in (x, y) if z[0] == "b" and z[1] == "*" and self.vtype(z) == "float"]
                if fm:
                    self.used_fuse = True
                    if ((self.c.get("variant") or 0) // 192) % 2 and not self.no_hoist:
                        # variant: the product as its own local (MWCC then keeps mul.s and add/sub.s apart)
                        nm = {}
                        for z in fm:
                            key = repr(z)
                            if key not in self.hoisted:
                                # `float m = A; m = m * B;` (m * m for a square): MWCC fuses a product into
                                # madd/msub when it is a fresh value, not when the variable is reassigned
                                #
                                m = self.hoisted[key] = "m%d" % len(self.hoisted)
                                self.pend.append("float %s = %s;" % (m, self.expr(z[2])))
                                if self.expr(z[2]) == self.expr(z[3]):
                                    self.pend.append("%s = %s * %s;" % (m, m, m))
                                else:
                                    self.pend.append("%s = %s * %s;" % (m, m, self.expr(z[3], False)))
                            nm[key] = self.hoisted[key]
                        xs = nm.get(repr(x)) or self.expr(x, False)
                        ys = nm.get(repr(y)) or self.expr(y, False)
                        return "(%s %s %s)" % (xs, op, ys)
            xs, ys = self.expr(x, False), self.expr(y, False)
            if op in ("<", ">=", ">", "<=") and y[0] == "k" and x[0] != "k":
                # variant (v // 49152) % 2: the bound written one off (`n > -1` for `n >= 0`): MWCC then keeps
                # retail's slti (func_003EAAE0) [G]
                self.used_offby1 = True
                if ((self.c.get("variant") or 0) // 49152) % 2:
                    nop_, k_ = {"<": ("<=", -1), ">=": (">", -1), ">": (">=", 1), "<=": ("<", 1)}[op]
                    return "(%s %s %s)" % (xs, nop_, self.expr(("k", y[1] + k_), False))
            if op in ("==", "!=", "^") and self.typing:
                tx, ty = self.vtype(x), self.vtype(y)
                px, py = tx.endswith("*"), ty.endswith("*")
                if op != "^" and px and py and tx != ty and "void *" not in (tx, ty):
                    ys = "(void *)" + ys
                elif px and not py and (op == "^" or y != ("k", 0)):
                    xs = "(int)" + xs
                elif py and not px and (op == "^" or x != ("k", 0)):
                    ys = "(int)" + ys
            if op in MIRROR and y[0] != "k":
                # variant (v // 24576) % 2: the comparison written mirrored (`b > a` for `a < b`): MWCC then
                # compares into $at and lays the then-body out of line like retail (SetPosition) [G]
                self.used_mirror = True
                if ((self.c.get("variant") or 0) // 24576) % 2:
                    op, xs, ys = MIRROR[op], ys, xs
                    if op.endswith("u"):
                        return "((unsigned int)%s %s (unsigned int)%s)" % (xs, op[:-1], ys)
            if op in ("f==", "f<", "f<=", "f>", "f>="):
                return "(%s %s %s)" % (xs, op[1:], ys)
            if op in ("+", "-") and self.typing and self.vtype(x).endswith("*"):
                xs = "(char *)" + xs
                if self.vtype(y).endswith("*"):
                    ys = "(int)" + ys
            elif op == "+" and self.typing and self.vtype(y).endswith("*"):
                ys = "(char *)" + ys
            if op == "i*":
                return "(%s * %s)" % (xs, ys)
            if op == ">=u":
                return "((unsigned int)%s >= (unsigned int)%s)" % (xs, ys)
            if op == "<u":
                s = "((unsigned int)%s < (unsigned int)%s)" % (xs, ys)
            elif op == ">>u":
                s = "((unsigned int)%s >> %s)" % (xs, ys)
            elif op in ("i/u", "i%u"):
                s = "((unsigned int)%s %s (unsigned int)%s)" % (xs, op[1], ys)
            elif op in ("i/", "i%"):
                s = "(%s %s %s)" % (xs, op[1], ys)
            else:
                s = "(%s %s %s)" % (xs, op, ys)
            return s
        raise Skip("expression %s" % (k,))

    def render(self, rv):
        c = self.c
        # temporaries for loads used across a store/call
        out = []
        for k, L in self.loads.items():
            if L["temp"]:
                L["tempname"] = None
        self.tcount = 0
        self.decls = []
        self.unk_sig = {}
        self.vsig = {}
        self.hoisted = {}
        self.pend = []
        var = self.c.get("variant") or 0
        st = self.stmts
        # a final value-returning if: variant (var // 2) % 3 = 1 early returns, 2 a ternary
        mode = (var // 2) % 3
        last = st[-1] if st else None
        if (rv and last and last[0] == "if" and rv[0][0] == "phi" and rv[0][1] in last[4]
                and not any(self.phis[q]["used"] for q in last[4] if q != rv[0][1])):
            self.used_dret = True
            self.no_hoist = True
            pid = rv[0][1]
            ph = self.phis[pid]
            pure = not [x for x in last[2] + (last[3] or []) if x[0] != "assign"]
            if mode == 1 or (mode == 2 and pure):
                body = self.rend(st[:-1], "    ")
                ce = self.expr(last[1])
                if not (ce.startswith("(") and ce.endswith(")")):
                    ce = "(%s)" % ce
                rt = self.vtype(rv[0])
                if mode == 2:
                    body.append("    return %s ? %s : %s;" % (ce, self.retexpr(ph["a"], rt), self.retexpr(ph["b"], rt)))
                else:
                    body.append("    if %s {" % ce)
                    body += self.rend([x for x in last[2] if x[0] != "assign"], "        ")
                    body.append("        return %s;" % self.retexpr(ph["a"], rt))
                    body.append("    }")
                    body += self.rend([x for x in (last[3] or []) if x[0] != "assign"], "    ")
                    body.append("    return %s;" % self.retexpr(ph["b"], rt))
                for t, (types, rtt) in self.unk_sig.items():
                    self.decls.append('extern "C" %s %s(%s);' % (rtt, t, ", ".join(types)))
                self.no_hoist = False
                return self.place_eaddr(body)
            self.no_hoist = False
        if self.pathmode and st and st[-1] == ("ret", None):
            st = st[:-1]
        body = self.rend(st, "    ", not rv and not (var & 1))
        if rv:
            e = self.expr(rv[0])
            body += ["    " + x for x in self.pend]
            self.pend = []
            body.append("    return %s;" % e)
        for t, (types, rt) in self.unk_sig.items():
            self.decls.append('extern "C" %s %s(%s);' % (rt, t, ", ".join(types)))
        return self.place_eaddr(body)

    def place_eaddr(self, body):
        """Declare variant 402653184's element pointers after their index's top-level declaration (at the top for a
        parameter); one that can't be placed goes back inline."""
        params = {n for _, n in getattr(self, "plist_names", [])}
        for ea, (nm, et, ie) in sorted(self.eaddr.items(), key=lambda t: -int(t[1][0][2:])):
            at = None
            if ie in params or re.fullmatch(r"p\d+", ie):
                at = 0
            else:
                for q, l in enumerate(body):
                    if re.match(r"^    [\w :<>*]+[ *]%s = " % re.escape(ie), l):
                        at = q + 1
                        break
            if at is None:
                body = [re.sub(r"\b%s\b" % nm, ea.replace("\\", "\\\\"), l) for l in body]
            else:
                body.insert(at, "    %s *%s = %s;" % (et, nm, ea))
        return body

    def rend_branch(self, stmts, ind, side):
        """A branch body: its trailing ("assign", pid) entries set the merged variables from this side's value."""
        plain = [x for x in stmts if x[0] != "assign"]
        out = self.rend(plain, ind)
        asg = [x for x in stmts if x[0] == "assign" and self.phis[x[1]]["used"]]
        if len(asg) > 1:
            # variant (v // 3072) % 2: the merged variables assigned in reverse (MWCC keeps their order:
            # GetMostInterestingCluster)
            self.used_phiorder = True
            if ((self.c.get("variant") or 0) // 3072) % 2:
                asg.reverse()
        for x in asg:
            if x[1] in self.phi_alias:
                ph = self.phis[x[1]]
                e = self.retexpr(ph[side], self.vtype(("phi", x[1])))
                if e != "m%d" % self.phi_alias[x[1]]:
                    out.append("%sm%d = %s;" % (ind, self.phi_alias[x[1]], e))
                continue
            if True:
                ph = self.phis[x[1]]
                t = self.vtype(("phi", x[1]))
                out.append("%sv%d = %s;" % (ind, x[1], self.retexpr(ph[side], t)))
        return out

    def retexpr(self, v, rt):
        e = self.expr(v)
        vt = self.vtype(v)
        if rt.endswith("*") and vt != rt and v != ("k", 0):
            e = "(%s)%s" % (rt, e)
        return e

    def pgroup(self, stmts, ind):
        """Path-mode variants (v // 12) % 4: 1 = a run of `if (x == K) {...; return}` on one x is a switch, cases in
        ascending order (MWCC then emits retail's compare order: an earlier pass, func_0013B6A0); 3 = the same in branch
        order; 2 = consecutive ifs with the same returning body are one `if (a || b)`."""
        mode = ((self.c.get("variant") or 0) // 12) % 4
        if not self.pathmode or not mode:
            return stmts

        def retif(st):
            return st[0] == "if" and st[3] is None and st[2] and st[2][-1][0] == "ret"
        out, k = [], 0
        while k < len(stmts):
            st = stmts[k]
            if mode in (1, 3) and retif(st) and st[1][0] == "b" and st[1][1] == "==" and st[1][3][0] == "k":
                x = st[1][2]
                run = [st]
                while k + len(run) < len(stmts):
                    nx = stmts[k + len(run)]
                    if retif(nx) and nx[1][0] == "b" and nx[1][1] == "==" and nx[1][3][0] == "k" and \
                            self.expr(nx[1][2]) == self.expr(x):
                        run.append(nx)
                    else:
                        break
                if len(run) >= 2:
                    self.used_pvar = True
                    cases = [(r[1][3][1], r[2]) for r in run]
                    if mode == 1:
                        cases.sort(key=lambda kb: kb[0])
                    out.append(("switch", x, cases))
                    k += len(run)
                    continue
            if mode == 2 and retif(st):
                # a chain of returning ifs with one body: `if (a || b || c)`; loads between them are not
                # statements, and a call whose result only the next test reads moves into that test (the || keeps
                # it conditional, as retail's branches do: func_00385EC0)
                cur, j, merged = st, k + 1, False
                while True:
                    m2, inl = j, None

                    def skip_loads(q):
                        while q < len(stmts) and stmts[q][0] == "load" and not self.loads[stmts[q][1]]["temp"]:
                            q += 1
                        return q
                    m2 = skip_loads(m2)
                    if m2 + 1 < len(stmts) and stmts[m2][0] == "call" and not self.calls[stmts[m2][1]]["tail"]:
                        idx = stmts[m2][1]
                        key = repr(("c", idx))
                        q2 = skip_loads(m2 + 1)
                        if q2 < len(stmts) and retif(stmts[q2]) and key in repr(stmts[q2][1]) and \
                                not any(key in repr(x) for x in stmts[q2][2]) and \
                                not any(key in repr(x) for x in stmts[q2 + 1:]):
                            inl, m2 = idx, q2
                    if m2 < len(stmts) and retif(stmts[m2]):
                        save = self.tcount
                        a = self.rend(cur[2], ind)
                        self.tcount = save
                        b = self.rend(stmts[m2][2], ind)
                        self.tcount = save
                        if a == b:
                            if inl is not None:
                                self.calls[inl]["inline"] = True
                            cur = ("if", ("b", "||", cur[1], stmts[m2][1]), cur[2], None, [], True)
                            j, merged = m2 + 1, True
                            continue
                    break
                if merged:
                    self.used_pvar = True
                    out.append(cur)
                    k = j
                    continue
            out.append(st)
            k += 1
        return out

    def rend(self, stmts, ind, tail=False):
        """tail: nothing follows these statements before a void return. A final `if` there is written as an early
        return (`if (!c) return; body`): MWCC moves a block-form then-body out of line."""
        body = []
        stmts = self.pgroup(stmts, ind)

        def rets(b):
            nb = [y for y in b if y[0] != "assign"]
            return bool(nb) and nb[-1][0] == "ret"
        for k, s in enumerate(stmts):
            if getattr(self, "pending_label", None):
                body.append("%s:" % self.pending_label)      # a label loop's break target
                self.pending_label = None
            mark = len(body)
            if s[0] == "if" and s[3] is None and not any(self.phis[q]["used"] for q in s[4]) and rets(s[2]) and \
                    k + 1 < len(stmts) and rets(stmts[k + 1:]):
                # variant (v // 1610612736) % 2: `if (c) { A; return; } B; return;` written `if (!c) { B } A`
                # (MWCC falls through into the then-body) [C] probe pd1 (func_003E9AD0)
                self.used_pullin = True
                if ((self.c.get("variant") or 0) // 1610612736) % 2:
                    ce = self.expr(self.neg(s[1]))
                    if not (ce.startswith("(") and ce.endswith(")")):
                        ce = "(%s)" % ce
                    head = ["%sif %s {" % (ind, ce)]
                    if self.pend:
                        head[0:0] = [ind + x for x in self.pend]
                        self.pend = []
                    body += head
                    body += self.rend(stmts[k + 1:], ind + "    ", tail)
                    body.append("%s}" % ind)
                    body += self.rend(s[2], ind, tail)
                    break
            self.rend1(body, k, s, stmts, ind, tail)
            if self.pend:
                body[mark:mark] = [ind + x for x in self.pend]
                self.pend = []
        if getattr(self, "pending_label", None):
            body.append("%s:;" % self.pending_label)
            self.pending_label = None
        return body

    def rend1(self, body, k, s, stmts, ind, tail):
        """One statement of rend() (lines appended to body)."""
        if True:
            if s[0] == "assign":
                return
            if s[0] in ("break", "continue"):
                body.append("%s%s;" % (ind, s[0]))
                return
            if s[0] == "goto":
                body.append("%sgoto %s;" % (ind, s[1]))
                return
            if s[0] == "label":                       # lift2: a goto's target
                body.append("%s:;" % s[1])
                return
            if s[0] in ("bopen", "bclose"):
                body.append("%s%s" % (ind, "{" if s[0] == "bopen" else "}"))
                return
            if s[0] == "gdecl":
                for q in s[1]:
                    if self.phis[q]["used"]:
                        body.append("%s%s v%d;" % (ind, self.vtype(("phi", q)), q))
                return
            if s[0] == "gset":
                ph = self.phis[s[1]]
                if ph["used"]:
                    body.append("%sv%d = %s;" % (ind, s[1], self.retexpr(ph[s[2]], self.vtype(("phi", s[1])))))
                return
            if s[0] == "swj":
                _, x, cases, dst, phs = s
                for q in phs:
                    ph = self.phis[q]
                    if ph["used"] and q in self.phi_alias:
                        if ph["init"] and self.expr(ph["b"]) != "m%d" % self.phi_alias[q]:
                            body.append("%sm%d = %s;" % (ind, self.phi_alias[q], self.retexpr(ph["b"], self.vtype(("phi", q)))))
                        continue
                    if ph["used"]:
                        t = self.vtype(("phi", q))
                        if ph["init"]:
                            body.append("%s%s v%d = %s;" % (ind, t, q, self.retexpr(ph["b"], t)))
                        else:
                            body.append("%s%s v%d;" % (ind, t, q))
                body.append("%sswitch (%s) {" % (ind, self.iexpr(x)))
                # the function's last statement: a case's void `return;` is a `break;` (a return there puts the
                # epilogue's `ld ra` in the jump's delay slot: func_003CBB60)
                endsw = tail and k == len(stmts) - 1 and self.rtype == "void"

                def unret(b):
                    nb = [y for y in b if y[0] != "assign"]
                    if endsw and nb and nb[-1] == ("ret", None):
                        return [y for y in b if y is not nb[-1]]
                    return b
                cases = [(Ks, unret(b), side) for Ks, b, side in cases]

                def rets(b):
                    nb = [y for y in b if y[0] != "assign"]
                    return bool(nb) and nb[-1][0] == "ret"
                after = None
                if dst is not None and rets(dst) and cases and all(rets(b) for _, b, _ in cases):
                    # every path returns: variant (v // 12582912) % 2 makes the last case returning by itself a
                    # `break` to one return after the switch (no jump to the epilogue) [C] probe sw2 = func_00468E20
                    pure = [q for q, (_, b, _) in enumerate(cases) if [y[0] for y in b] == ["ret"]]
                    if pure:
                        self.used_swret = True
                        if ((self.c.get("variant") or 0) // 12582912) % 2:
                            q = pure[-1]
                            after = cases[q][1][0]
                            cases[q] = (cases[q][0], [], cases[q][2])
                dfirst = False
                if dst is not None:
                    self.used_dfirst = True
                    dfirst = bool(((self.c.get("variant") or 0) // 103079215104) % 2)
                if dfirst:
                    dst = unret(dst)
                    body.append("%sdefault:" % ind)
                    body += self.rend_branch(dst, ind + "    ", "b")
                    if not ([y for y in dst if y[0] != "assign"] and
                            [y for y in dst if y[0] != "assign"][-1][0] == "ret"):
                        body.append("%s    break;" % ind)
                    dst = None
                for Ks, b, side in cases:
                    for K in Ks:
                        body.append("%sdefault:" % ind if K == "default" else "%scase %d:" % (ind, K))
                    lines = self.rend_branch(b, ind + "    ", side)
                    body += lines
                    if not (b and [y for y in b if y[0] != "assign"] and
                            [y for y in b if y[0] != "assign"][-1][0] == "ret") and                             not (lines and lines[-1].strip().startswith("return")):
                        body.append("%s    break;" % ind)
                if dst is not None:
                    dst = unret(dst)
                    body.append("%sdefault:" % ind)
                    body += self.rend_branch(dst, ind + "    ", "b")
                    if not ([y for y in dst if y[0] != "assign"] and
                            [y for y in dst if y[0] != "assign"][-1][0] == "ret"):
                        body.append("%s    break;" % ind)
                body.append("%s}" % ind)
                if after is not None:
                    self.rend1(body, len(stmts), after, stmts, ind, False)
                return
            if s[0] == "switch":
                body.append("%sswitch (%s) {" % (ind, self.iexpr(s[1])))
                for K, b in s[2]:
                    body.append("%scase %d:" % (ind, K))
                    body += self.rend(b, ind + "    ")
                body.append("%s}" % ind)
                return
            if s[0] == "ret":
                if s[1]:
                    body.append("%sreturn %s;" % (ind, self.retexpr(s[1][0], self.rtype)))
                else:
                    body.append("%sreturn;" % ind)
                return
            if s[0] == "mvset":
                _, j, E = s
                t, e = self.vtype(("mv", j)), self.expr(E)
                if t.endswith("*") and self.vtype(E) != t and E != ("k", 0):
                    e = "(%s)%s" % (t, e)
                body.append("%sm%d = %s;" % (ind, j, e))
                return
            if s[0] == "for":
                _, lid, c, stepk, fb, first, mvs = s
                if self.c.get("lift4"):
                    # lift4: a loop variable of a loop nested in this body that this loop's condition reads
                    # (`do { done = 1; for (..) if (c) done = 0; } while (!done);`): declared before this loop
                    nested = set()

                    def nest(b):
                        for y in b:
                            if y[0] == "for":
                                nested.update(y[6])
                                nest(y[4])
                            elif y[0] == "if":
                                nest(y[2])
                                if y[3] is not None:
                                    nest(y[3])
                    nest(fb)
                    rc = repr(c)
                    for j in sorted(nested):
                        if repr(("mv", j)) in rc:          # (rendered more than once: the flag persists)
                            self.mvars[j]["predecl"] = True
                            body.append("%s%s m%d;" % (ind, self.vtype(("mv", j)), j))
                if len(mvs) > 1:
                    # variant (v // 768) % 2: the loop variables declared in reverse (MWCC's register order
                    # follows the declarations: func_00386970)
                    self.used_mvorder = True
                    if ((self.c.get("variant") or 0) // 768) % 2:
                        mvs = list(reversed(mvs))
                for j in mvs:
                    t, iv = self.vtype(("mv", j)), self.mvars[j]["init"]
                    e = self.expr(iv)
                    if t.endswith("*") and self.vtype(iv) != t and iv != ("k", 0):
                        e = "(%s)%s" % (t, e)
                    if self.mvars[j].get("predecl"):
                        body.append("%sm%d = %s;" % (ind, j, e))     # lift4: declared before the outer loop
                        continue
                    if self.mvars[j].get("asparam"):
                        continue                                       # lift4: the parameter itself

                    body.append("%s%s m%d = %s;" % (ind, t, j, e))
                if lid is None:
                    self.no_hoist = True
                    ce = self.expr(c)
                    self.no_hoist = False
                    ce = ce if ce.startswith("(") else "(%s)" % ce
                    self.used_loop = True
                    if c == ("k", 1):
                        body.append("%sfor (;;) {" % ind)
                        body += self.rend(fb, ind + "    ")
                        body.append("%s}" % ind)
                    elif first and c[0] == "b" and c[1] == "!=" and c[3] == ("k", 0) and c[2][0] == "mv" and \
                            self.mvars[c[2][1]].get("postdec"):
                        body.append("%swhile (%s--) {" % (ind, self.expr(c[2])))     # lift4
                        body += self.rend(fb, ind + "    ")
                        body.append("%s}" % ind)
                    elif first:
                        body.append("%swhile %s {" % (ind, ce))
                        body += self.rend(fb, ind + "    ")
                        body.append("%s}" % ind)
                    else:
                        body.append("%sdo {" % ind)
                        body += self.rend(fb, ind + "    ")
                        body.append("%s} while %s;" % (ind, ce))
                    return
                name = self.expr(("lv", lid))
                init = self.expr(self.lvars[lid]["init"])
                lt = self.vtype(("lv", lid))
                if lt.endswith("*") and self.vtype(self.lvars[lid]["init"]) != lt and self.lvars[lid]["init"] != ("k", 0):
                    init = "(%s)%s" % (lt, init)
                self.no_hoist = True             # the test runs every pass: nothing hoisted out of it
                ce = self.expr(c)
                self.no_hoist = False
                inc = "%s++" % name if stepk == 1 else "%s--" % name if stepk == -1 else (
                    "%s += %d" % (name, stepk) if stepk > 0 else "%s -= %d" % (name, -stepk))
                if lt.endswith("*"):
                    inc = "%s++" % name
                self.used_loop = True
                if first == "goto":
                    # known.md N24: the label loop keeps retail's entry jump (the block keeps the body's own
                    # declarations out of the jumps' way)
                    def leaves(b):
                        for y in b:
                            if y[0] in ("break", "continue"):
                                return True
                            if y[0] == "if" and (leaves(y[2]) or (y[3] is not None and leaves(y[3]))):
                                return True
                        return False
                    L = "loop%d" % lid
                    used = set()

                    def regoto(b):
                        out_ = []
                        for y in b:
                            if y[0] == "break":
                                used.add("end")
                                out_.append(("goto", L + "_end"))
                            elif y[0] == "continue":
                                used.add("next")
                                out_.append(("goto", L + "_next"))
                            elif y[0] == "if":
                                out_.append(("if", y[1], regoto(y[2]), None if y[3] is None else regoto(y[3])) +
                                            tuple(y[4:]))
                            else:
                                out_.append(y)
                        return out_
                    if leaves(fb):
                        fb = regoto(fb)
                    body.append("%s%s %s = %s;" % (ind, lt, name, init))
                    body.append("%sgoto %s_test;" % (ind, L))
                    body.append("%s_body:" % L)
                    body.append("%s{" % ind)
                    body += self.rend(fb, ind + "    ")
                    body.append("%s}" % ind)
                    if "next" in used:
                        body.append("%s_next:" % L)
                    body.append("%s%s;" % (ind, inc))
                    body.append("%s_test:" % L)
                    def one_group(e):
                        d = 0
                        for q, ch in enumerate(e):
                            d += (ch == "(") - (ch == ")")
                            if d == 0 and q < len(e) - 1:
                                return False
                        return e.startswith("(")
                    body.append("%sif %s goto %s_body;" % (ind, ce if one_group(ce) else "(%s)" % ce, L))
                    if "end" in used:
                        self.pending_label = L + "_end"     # placed before the loop's next statement
                    return
                # a bottom-tested loop: a for (MWCC drops the entry test when the first pass is provable);
                # variant (v // 6) % 2 writes the do-while
                if not ((self.c.get("variant") or 0) // 6) % 2:
                    first = True
                if first and self.lvars[lid].get("out"):
                    # lift4: the counter is read after the loop: declared before it
                    body.append("%s%s %s;" % (ind, lt, name))
                    body.append("%sfor (%s = %s; %s; %s) {" % (ind, name, init, ce, inc))
                    body += self.rend(fb, ind + "    ")
                    body.append("%s}" % ind)
                elif first:
                    body.append("%sfor (%s %s = %s; %s; %s) {" % (ind, lt, name, init, ce, inc))
                    body += self.rend(fb, ind + "    ")
                    body.append("%s}" % ind)
                else:
                    body.append("%s%s %s = %s;" % (ind, lt, name, init))
                    body.append("%sdo {" % ind)
                    body += self.rend(fb, ind + "    ")
                    body.append("%s    %s;" % (ind, inc))
                    body.append("%s} while %s;" % (ind, ce if ce.startswith("(") else "(%s)" % ce))
                return
            if s[0] == "if" and s[3] is None and len([q for q in s[4] if self.phis[q]["used"]]) == 1 and \
                    not [y for y in s[2] if y[0] != "assign"]:
                # `v = x >> K; if (x < 0) v = (x + (2^K - 1)) >> K;`: MWCC's signed division, `v = x / 2^K` [C] probe
                # pa2 (IsControlPressed__25CGtInputDevicePS2Keyboard)
                q = [q for q in s[4] if self.phis[q]["used"]][0]
                ph = self.phis[q]
                A, B, c = ph["b"], ph["a"], s[1]
                if ph["init"] and q not in self.phi_alias and A and B and A[0] == "b" and A[1] == ">>" and \
                        A[3][0] == "k" and 0 < A[3][1] < 31 and B[0] == "b" and B[1] == ">>" and B[3] == A[3] and \
                        B[2] == ("b", "+", A[2], ("k", (1 << A[3][1]) - 1)) and \
                        tuple(c[:4]) in (("b", "<", A[2], ("k", 0)), ("b", "<=", A[2], ("k", -1))):
                    t = self.vtype(("phi", q))
                    body.append("%s%s v%d = (%s / %d);" % (ind, t, q, self.expr(A[2], False), 1 << A[3][1]))
                    return
            if s[0] == "if" and s[3] is None and len([q for q in s[4] if self.phis[q]["used"]]) == 1 and \
                    not [y for y in s[2] if y[0] != "assign" and not (y[0] == "load" and not self.loads[y[1]]["temp"])]:
                # `v = A; if (A) v = B;` with comparison values: MWCC's lowering of `v = A && B` (`if (!A)`:
                # `A || B`) [C] probe x1 vs func_003BE640
                q = [q for q in s[4] if self.phis[q]["used"]][0]
                ph = self.phis[q]

                def isbool(v):
                    return v is not None and ((v[0] == "b" and (v[1] in NEG or v[1] in ("&&", "||"))) or
                                              (v[0] == "u" and v[1] == "!"))
                A, B, c = ph["b"], ph["a"], s[1]
                op = None
                if ph["init"] and q not in self.phi_alias and isbool(A) and isbool(B):
                    if c == A or c == ("b", "!=", A, ("k", 0)):
                        op = "&&"
                    elif c == self.neg(A) or c == ("b", "==", A, ("k", 0)) or c == ("u", "!", A):
                        op = "||"
                if op:
                    t = self.vtype(("phi", q))
                    body.append("%s%s v%d = (%s %s %s);" % (ind, t, q, self.expr(A), op, self.expr(B)))
                    return
            if s[0] == "if" and (s[3] is not None or any(self.phis[q]["used"] for q in s[4])):
                for q in s[4]:
                    ph = self.phis[q]
                    if ph["used"] and q in self.phi_alias:
                        # written as the loop variable: only a fall-back value that is not already it
                        if ph["init"] and self.expr(ph["b"]) != "m%d" % self.phi_alias[q]:
                            body.append("%sm%d = %s;" % (ind, self.phi_alias[q], self.retexpr(ph["b"], self.vtype(("phi", q)))))
                        continue
                    if ph["used"]:
                        t = self.vtype(("phi", q))
                        if ph["init"]:
                            body.append("%s%s v%d = %s;" % (ind, t, q, self.retexpr(ph["b"], t)))
                        else:
                            body.append("%s%s v%d;" % (ind, t, q))
                ce = self.expr(s[1])
                if not (ce.startswith("(") and ce.endswith(")")):
                    ce = "(%s)" % ce
                if s[3] is not None:
                    self.used_ifswap = True
                if s[3] is not None and ((self.c.get("variant") or 0) // 805306368) % 2:
                    # variant: `if (!c) B else A` (MWCC lays the then-body out first) [G]
                    ce = self.expr(self.neg(s[1]))
                    if not (ce.startswith("(") and ce.endswith(")")):
                        ce = "(%s)" % ce
                    body.append("%sif %s {" % (ind, ce))
                    body += self.rend_branch(s[3], ind + "    ", "b")
                    body.append("%s} else {" % ind)
                    body += self.rend_branch(s[2], ind + "    ", "a")
                    body.append("%s}" % ind)
                    return
                body.append("%sif %s {" % (ind, ce))
                body += self.rend_branch(s[2], ind + "    ", "a")
                if s[3] is not None:
                    body.append("%s} else {" % ind)
                    body += self.rend_branch(s[3], ind + "    ", "b")
                body.append("%s}" % ind)
                return
            if s[0] == "if" and tail and k == len(stmts) - 1 and not s[5]:
                ce = self.expr(self.neg(s[1]))
                if not (ce.startswith("(") and ce.endswith(")")):
                    ce = "(%s)" % ce
                body.append("%sif %s return;" % (ind, ce))
                self.used_tail_if = True
                body += self.rend(s[2], ind, True)
                return
            if s[0] == "if":
                ce = self.expr(s[1])
                if not (ce.startswith("(") and ce.endswith(")")):
                    ce = "(%s)" % ce
                body.append("%sif %s {" % (ind, ce))
                body += self.rend(s[2], ind + "    ")
                body.append("%s}" % ind)
                return
            if s[0] == "acopy":
                _, droot, doff, sroot, soff, whole = s
                src = self.wholeexpr(sroot) if whole else self.fexpr(sroot, soff)
                body.append("%s%s = %s;" % (ind, self.fexpr(droot, doff), src))
                return
            if s[0] == "blk":
                raise Skip("aggregate copy loop inside a branch")
            if s[0] == "vassign":
                body.append("%s%s = %s;" % (ind, self.fexpr(s[1], s[2]), self.vexpr(s[3])))
                return
            if s[0] == "vcall":
                body.append("%s%s.%s();" % (ind, self.fexpr(s[1], s[2]), s[3]))
                return
            if s[0] == "vlocal":
                _, k, base, sets = s
                body.append("%sGtMathPs2::CGtV3d vl%d = %s;" % (ind, k, self.vexpr(base)))
                for lane, x in sets:
                    arg = "%s.%s()" % (self.vexpr(x[1], True), x[2].upper()) if x[0] == "lane" else self.expr(x)
                    body.append("%svl%d.Set%s(%s);" % (ind, k, lane.upper(), arg))
                return
            if s[0] == "vkeepw":                 # lift3
                _, root, off, v = s
                sph = self.obj(root)["fields"].get(off) == "SPH"
                body.append("%s%s.%s(%s);" % (ind, self.fexpr(root, off), "SetPosition" if sph else "SetGtV3d", self.vexpr(v)))
                return
            if s[0] == "vset":
                _, root, off, lane, x = s
                meth = "SetA" if lane == "w" else "SetW" if lane == "W" else "Set" + lane.upper()
                ft_ = self.obj(root)["fields"].get(off)
                if ft_ in ("V3P", "SPH"):         # lift3: the keep-w types' w setters
                    meth = "SetRadius" if ft_ == "SPH" else "SetPlus"
                if x[0] == "lane":
                    arg = "%s.%s()" % (self.vexpr(x[1], True), x[2].upper())
                else:
                    arg = self.expr(x)
                body.append("%s%s.%s(%s);" % (ind, self.fexpr(root, off), meth, arg))
                return
            if s[0] == "qbind":
                hi, lo = self.qbinds[s[1]]
                he, le = self.expr(hi), self.expr(lo)
                body.append("%su_long128 q%d;" % (ind, s[1]))
                if ((self.c.get("variant") or 0) // 3221225472) % 2:
                    body.append('%sasm("pcpyld %%0, %%1, %%2" : "=r"(q%d) : "r"(%s), "r"(%s));' % (ind, s[1], he, le))
                else:
                    body.append('%sasm("pcpyld %%0, %%2, %%1" : "=r"(q%d) : "r"(%s), "r"(%s));' % (ind, s[1], le, he))
                return
            if s[0] == "fbind":
                body.append("%sfloat mm%d = %s;" % (ind, s[1], self.expr(self.fbinds[s[1]])))
                return
            if s[0] == "vcopy":
                _, K, v = s
                if K not in self.vt_types:
                    raise Skip("vector temporary not passed to a vector parameter")
                body.append("%s%s vt%X;" % (ind, self.vt_types[K], K))
                body.append("%svt%X.mData = %s;" % (ind, K, self.expr(v)))
                return
            if s[0] == "load":
                L = self.loads[s[1]]
                if L["temp"]:
                    name = "t%d" % self.tcount
                    self.tcount += 1
                    cs = self.lcast(s[1])
                    t = L.get("pun") or (cs[1:-1] if cs else self.ftype(L["root"], L["off"]))
                    body.append("%s%s %s = %s%s;" % (ind, t, name, cs, self.pexpr(L["root"], L["off"], L.get("pun"))))
                    L["tempname"] = name
            elif s[0] == "store":
                _, root, off, v, mn, pn = s
                val = self.expr(v)
                ft = pn or self.ftype(root, off)
                vt = self.vtype(v)
                if ft == "float" and v[0] == "k" and mn == "sw":
                    val = flit(v[1])
                elif ft.endswith("*") and vt != ft:
                    if v == ("k", 0):
                        val = "0"
                    else:
                        val = "(%s)%s" % (ft, val)
                elif vt.endswith("*") and not ft.endswith("*") and ft != "float":
                    val = "(%s)%s" % (ft, val)
                lhs = self.pexpr(root, off, pn)
                fn = ".field_%X" % off
                if mn == "sq":
                    vt_ = self.ftype(self.loads[v[1]]["root"], self.loads[v[1]]["off"]) \
                        if v[0] == "l" and self.loads[v[1]].get("mn") == "lq" else None
                    vecs = ("GtMathPs2::CGtV3d", "GtMathPs2::CGtV4d", "V3D", "V4D")
                    if vt_ in vecs and ft not in vecs:
                        val = val + ".mData"           # a vector field copied into a u_long128 one
                    elif ft in vecs and vt_ not in vecs:
                        lhs = lhs + ".mData"           # ... and the other way

                if ft.endswith(" *") and v[0] == "b" and v[1] == "+" and v[3][0] == "k" and v[3][1] > 0 and \
                        v[2][0] == "l" and self.same(self.loads[v[2][1]]["root"], root) and \
                        self.loads[v[2][1]]["off"] == off and self.pinc_ok(ft[:-2], v[3][1]):
                    # `p++` (the pointee padded to the step) [C] probe build/vt/mx/er9.cpp
                    self.used_pinc = True
                    if not ((self.c.get("variant") or 0) // 6442450944) % 2:
                        self.psize[ft[:-2]] = v[3][1]
                        body.append("%s%s++;" % (ind, lhs))
                        return body
                if root[0] == "ix" and not pn and lhs.endswith("]" + fn) and lhs in val and                         "type" in self.objs.get(repr(root), {}):
                    # a read-modify-write of an indexed element's field: variant (v // 3145728) % 2 goes through
                    # an element pointer (`E *e = &a[i]; e->f = e->f | K;`: the base first in the addu) [C] probe
                    # av4 = AllocVirtualVoice__20CGtSoundVoiceManagerFv
                    self.used_elptr = True
                    if ((self.c.get("variant") or 0) // 3145728) % 2:
                        en = "e%d" % self.n_elptr
                        self.n_elptr += 1
                        body.append("%s%s * %s = &%s;" % (ind, self.objs[repr(root)]["type"], en, lhs[:-len(fn)]))
                        body.append("%s%s->%s = %s;" % (ind, en, fn[1:], val.replace(lhs, "%s->%s" % (en, fn[1:]))))
                        return body
                body.append("%s%s = %s;" % (ind, lhs, val))
            elif s[0] == "call":
                C = self.calls[s[1]]
                ce = self.callstmt(C)
                if (C["used"] or C.get("fused")) and not C["tail"]:
                    name = "r%d" % s[1]
                    C["temp"] = name
                    rt = C["rtype"] if C["kind"] == "libc" else self.crt(C)
                    if C["kind"] == "libc" and C.get("fused") and rt != "float":
                        raise Skip("libc result used as a float")
                    C["rtype"] = rt
                    body.append("%s%s %s = %s;" % (ind, rt, name, ce))
                else:
                    body.append("%s%s;" % (ind, ce))
        return body

    def crt(self, C):
        """A callee's declared return type: from how the result is used (f0: float [G])."""
        if C["tail"]:
            return "void"
        if C.get("fused"):
            return "float"
        if C.get("dword"):
            return "unsigned long"               # stored with sd: a 64-bit result
        o = self.objs.get(repr(("c", C["idx"])))
        if C["used"] and o is not None and "type" in o:
            return o["type"] + " *"           # the result is used as an object pointer
        if C["used"] and self.cptr(C):
            return "void *"
        return "int" if C["used"] else "void"

    def cptr(self, C):
        """A zero-tested call result declared `void *` (patch_cptr.py; variant (v // 51539607552) % 2)."""
        return bool(C.get("ztest")) and bool(((self.c.get("variant") or 0) // 51539607552) % 2)

    def argtype(self, v):
        if v[0] == "phi" and all(y in (("k", 0), ("k", 1)) for y in self.phvals(self.phis[v[1]])):
            # a merged 0 / 1 passed to a placeholder callee: variant (v // 6291456) % 2 makes it a bool and the
            # parameter bool (retail sets it with `daddiu r,zero,1`) [C] probe ba2 = func_003BA4E0
            self.used_bphi = True
            if ((self.c.get("variant") or 0) // 6291456) % 2:
                self.boolphis.add(v[1])
                return "bool"
        t = self.vtype(v)
        if t in ("signed char", "unsigned char", "char", "short", "unsigned short", "bool"):
            # a narrow argument to a placeholder callee: variant (v // 1572864) % 2 declares the parameter int
            # (MWCC schedules the argument loads differently: probe ps4 = PrepareSound__12CB3PlayerCarFv) [C]
            self.used_wide = True
            if ((self.c.get("variant") or 0) // 1572864) % 2:
                return "int"
        return t

    def callstmt(self, C):
        args = C["args"]
        fargs = C["fargs"]
        if C["kind"] == "libc":
            d = 'extern "C" %s %s(%s);' % (C["rtype"], C["target"], ", ".join(C["plist"]))
            if d not in self.decls:
                self.decls.append(d)
            vals = []
            for v, t in zip(args, C["plist"]):
                e = self.expr(v)
                vt = self.vtype(v)
                if t.endswith("*") and vt != t and v != ("k", 0) and not (vt.endswith("*") and "void" in t):
                    e = "(%s)%s" % (t, e)
                vals.append(e)
            return "%s(%s)" % (C["target"], ", ".join(vals))
        if C["kind"] == "virt":
            _, root, VP, SLOT = C["target"]
            types = [self.argtype(v) for v in args[1:]] + ["float"] * len(fargs)
            rt = self.crt(C)
            key = (self.obj(root)["type"], SLOT)
            old = self.vsig.get(key)
            if old:
                if len(old[0]) != len(types):
                    raise Skip("virtual slot called with different argument counts")
                types = [a if a == b else ("void *" if a.endswith("*") and b.endswith("*") else None)
                         for a, b in zip(old[0], types)]
                if None in types:
                    raise Skip("virtual slot argument types conflict")
                if old[1] != "void":
                    if rt not in ("void", old[1]):
                        raise Skip("virtual slot return types conflict")
                    rt = old[1]
            self.vsig[key] = (types, rt)
            ox = self.objexpr(root)
            if ox.endswith("."):
                # an object held by value: MWCC knows its dynamic type and calls the slot directly, so
                # retail's dispatch comes from a pointer (compile probe, func_00421580) [G] form
                ox = "((%s *)&%s)->" % (key[0], ox[:-1])
            return "%svfunc_%X(%s)" % (ox, SLOT,
                                       ", ".join([self.expr(v) for v in args[1:]] + [self.expr(v) for v in fargs]))
        if C["kind"] == "fptr":
            types = [self.argtype(v) for v in args] + ["float"] * len(fargs)
            fv = C["target"][1]
            return "((%s (*)(%s))%s)(%s)" % (self.crt(C), ", ".join(types), self.expr(fv),
                                            ", ".join([self.expr(v) for v in args] + [self.expr(v) for v in fargs]))
        if C["kind"] == "unk":
            types = [self.argtype(v) for v in args] + ["float"] * len(fargs)
            rt = self.crt(C)
            cast = ""
            if C["target"] in self.unk_vptr and rt.endswith("*"):
                cast, rt = ("(%s)" % rt if rt != "void *" else ""), "void *"
            old = self.unk_sig.get(C["target"])
            if old:
                if len(old[0]) != len(types):
                    raise Skip("callee %s called with different argument counts" % C["target"])
                merged = []
                for a, b in zip(old[0], types):
                    if a == b:
                        merged.append(a)
                    elif a.endswith("*") and b.endswith("*"):
                        merged.append("void *")
                    else:
                        raise Skip("callee %s argument types conflict" % C["target"])
                types = merged
                if old[1] != "void":
                    if rt not in ("void", old[1]):
                        if rt.endswith("*") and old[1].endswith("*"):
                            self.unk_vptr.add(C["target"])   # settled by the next render pass
                        else:
                            raise Skip("callee %s return types conflict" % C["target"])
                    rt = old[1]
            self.unk_sig[C["target"]] = (types, rt)
            return "%s%s(%s)" % (cast, C["target"], ", ".join([self.expr(v) for v in args] + [self.expr(v) for v in fargs]))
        rt = self.crt(C)
        vals = []
        plist = C["plist"]
        gi = 1 if C["kind"] == "method" else 0
        ai, fi = (1 if C["kind"] == "method" else 0), 0
        if C["kind"] == "static" and (C.get("extra") or C.get("fextra")):
            raise Skip("static callee with extra arguments")
        for t in plist:
            core, isp, isr, isf = ptype(t)
            v = fargs[fi] if isf else args[ai]
            if isf:
                fi += 1
            else:
                ai += 1
            if isr:
                # a reference: the address is passed (declared as a pointer below) [G]
                e = self.expr(v)
                if not self.vtype(v).endswith("*") and v != ("k", 0):
                    e = "(void *)" + e
                vals.append(e)
                continue
            if core in VECT and not isp:
                if v[0] != "vt":
                    try:
                        root_, off_ = self.split(v)
                    except Skip:
                        raise Skip("vector argument not from a temporary" + (" %r" % (v,) if DIAG else ""))
                    if root_[0] not in ("p", "l", "g", "loc"):
                        raise Skip("vector argument not from a temporary" + (" %r" % (v,) if DIAG else ""))
                    self.vfield(root_, off_, "V3D" if core.endswith("V3d") else "V4D")
                    vals.append(self.fexpr(root_, off_))
                    continue
                if self.vt_types.get(v[1], core) != core:
                    raise Skip("vector temporary used as two classes")
                self.vt_types[v[1]] = core
                self.need_gtmath = True
                if v[1] in self.vt_ctor:
                    if core != "GtMathPs2::CGtV4d":
                        raise Skip("four-float constructor of %s" % core)
                    vals.append("GtMathPs2::CGtV4d(%s)" % ", ".join(self.expr(x) for x in self.vt_ctor[v[1]]))
                    continue
                vals.append("vt%X" % v[1])
                continue
            e = self.expr(v)
            vt = self.vtype(v)
            if core == "FNPTR":
                # a function pointer parameter: declared `const void *` / `void *` in the extern declaration
                vals.append(e if v == ("k", 0) else "(%svoid *)%s" % ("const " if "const" in t else "", e))
                continue
            if vt != t and (isp or vt.endswith("*")):
                e = "(%s)%s" % (t, e) if v != ("k", 0) else "0"
            elif core and core.startswith("E") and not isp and vt != t:
                e = "(%s)%s" % (t, e)
            vals.append(e)
            self.need_type(t)
        if C.get("extra") or C.get("fextra"):
            types = []
            for t in plist:
                core, isp, isr, isf = ptype(t)
                types.append(("const void *" if "const" in t else "void *") if isp and core is not None else t)
            types += [self.argtype(v) for v in C["extra"]] + ["float"] * len(C.get("fextra", []))
            vals += [self.expr(v) for v in C["extra"]] + [self.expr(v) for v in C.get("fextra", [])]
            if C["kind"] == "method":
                ae = self.expr(args[0])
                if not self.vtype(args[0]).endswith("*") and args[0] != ("k", 0):
                    ae = "(void *)" + ae
                types, vals = ["void *"] + types, [ae] + vals
            d = 'extern "C" %s %s(%s);  // %s, passed %d more argument(s) [G]' % (
                rt, C["target"], ", ".join(types), demangle(C["target"]), len(C["extra"]) + len(C.get("fextra", [])))
            if d not in self.decls:
                self.decls.append(d)
            return "%s(%s)" % (C["target"], ", ".join(vals))
        if any(ptype(t)[2] for t in plist):
            # reference parameters: an extern "C" declaration of the mangled name with pointers (same calling
            # convention, same symbol) [G]
            types = ["void *"] if C["kind"] == "method" else []
            for t in plist:
                core, isp, isr, isf = ptype(t)
                types.append(("const void *" if "const" in t else "void *") if isr or (isp and core is not None) else t)
            vs = list(vals)
            if C["kind"] == "method":
                ae = self.expr(args[0])
                if not self.vtype(args[0]).endswith("*") and args[0] != ("k", 0):
                    ae = "(void *)" + ae
                vs = [ae] + vs
            d = 'extern "C" %s %s(%s);  // %s' % (rt, C["target"], ", ".join(types), demangle(C["target"]))
            if d not in self.decls:
                self.decls.append(d)
            return "%s(%s)" % (C["target"], ", ".join(vs))
        if C["kind"] == "static":
            cls2 = C["cls"]
            if not self.has_header(cls2) and "::" not in cls2:
                sig = "static %s %s(%s)" % (rt, C["meth"], ", ".join(plist))
                if cls2 not in self.classes:
                    self.classes[cls2] = []
                    self.class_order.append(cls2)
                if sig not in self.classes[cls2]:
                    self.classes[cls2].append(sig)
                return "%s::%s(%s)" % (cls2, C["meth"], ", ".join(vals))
            types = []
            for t in plist:
                core, isp, isr, isf = ptype(t)
                types.append(("const void *" if "const" in t else "void *") if isp and core is not None else t)
            d = 'extern "C" %s %s(%s);  // %s' % (rt, C["target"], ", ".join(types), demangle(C["target"]))
            if d not in self.decls:
                self.decls.append(d)
            return "%s(%s)" % (C["target"], ", ".join(vals))
        if C["kind"] == "free":
            d = "%s %s(%s);" % (rt, C["fname"], ", ".join(plist))
            if d not in self.fwd:
                self.fwd.append(d)
            return "%s(%s)" % (C["fname"], ", ".join(vals))
        cls2 = C["cls"]
        simple = not self.has_header(cls2)
        try:
            for t in plist:
                ptype(t)
        except Skip:
            simple = False
        a0 = args[0]
        if simple and a0[0] == "p" and a0[1] == "a0":
            if self.named and cls2 == self.ccls:
                obj = ""
            elif self.named:
                simple = False
            else:
                o = self.objs.get(repr(a0))
                if o and o["type"] != cls2:
                    simple = False
                else:
                    self.self_cls = cls2
                    obj = "self->"
        elif simple and a0[0] == "l":
            L = self.loads[a0[1]]
            sub = self.obj(a0)
            sub["type"] = cls2
            obj = self.expr(a0) + "->"
        elif simple and a0[0] == "b" and a0[1] == "+" and a0[3][0] == "k" and a0[2][0] in ("p", "l", "g"):
            root, off = self.split(a0)
            if root[0] == "p" and root[1] != "a0" and self.named:
                simple = False
            else:
                self.field(root, off, cls2)
                obj = "%sfield_%X." % (self.objexpr(root), off)
        elif simple and a0[0] == "g":
            o = self.obj(a0)
            o["type"] = cls2
            obj = "%s." % a0[1]
        else:
            simple = False
        if simple:
            sig = "%s %s(%s)%s" % (rt, C["meth"], ", ".join(plist), " const" if C["const"] else "")
            if cls2 not in self.classes:
                self.classes[cls2] = []
                self.class_order.append(cls2)
            if sig not in self.classes[cls2]:
                self.classes[cls2].append(sig)
            return "%s%s(%s)" % (obj, C["meth"], ", ".join(vals))
        types = ["void *"]
        for t in plist:
            core, isp, isr, isf = ptype(t)
            types.append(("const void *" if "const" in t else "void *") if isp and core is not None else t)
        if "bool" in types:
            # variant (v // 6144) % 2: a bool parameter declared unsigned char -- retail passes a byte it
            # already masked, without bool normalization (func_00213EB0) [G]
            self.used_ucbool = True
            if ((self.c.get("variant") or 0) // 6144) % 2:
                types = ["unsigned char" if x == "bool" else x for x in types]
                vals = [v[len("(bool)"):] if v.startswith("(bool)") else v for v in vals]
        d = 'extern "C" %s %s(%s);  // %s' % (rt, C["target"], ", ".join(types), demangle(C["target"]))
        if d not in self.decls:
            self.decls.append(d)
        ae = self.expr(a0)
        if not self.vtype(a0).endswith("*") and a0 != ("k", 0):
            ae = "(void *)" + ae
        return "%s(%s)" % (C["target"], ", ".join([ae] + vals))

    def need_type(self, t):
        core, isp, isr, isf = ptype(t)
        if core == SPACE:
            self.need_g2d = True               # lift3: declared by Gt2dObject.h
            return
        if core is None or core.startswith("GtMathPs2::"):
            if core in VECT or core in GTMATH_TYPES:
                self.need_gtmath = True
            elif core:
                raise Skip("GtMathPs2 type in callee")
            return
        if "::" in core:
            ns, nm = core.split("::")
            if self.has_header(ns) or ns in self.classes or (self.named and ns == self.ccls):
                raise Skip("scope %s is a class here" % ns)
            d = "namespace %s { class %s; }" % (ns, nm)
            self.scopes.add(ns)
        else:
            d = ("enum %s {};" % core) if core.startswith("E") else ("class %s;" % core)
        if d not in self.fwd:
            self.fwd.append(d)


LAST_NVAR = 1   # source-form variants the last generate() call has (tools/tiny_batch.py tries each)
LAST_DIMS = []        # (multiplier, radix) of each variant dimension the last generate() call used
LAST_VARIANTS = [0]   # ... the ones worth generating, in order (variant 0 first)


STRUCT_SKIPS = ("label in an if body reached from outside", "else branch shape", "b (else / unstructured)",
                "branch out of an if body", "return inside an if body", "branch shape (backward",
                "b inside an if body", "loop condition reached from elsewhere", "loop shape",
                "loop entry jump with a constant first test", "empty if body")


# vlift: GtMathPs2::DotProduct(CGtV3d, CGtV3d) is in the B3O0PCH map but not yet in include/b3/GtMathPs2.h; a file-local
# stand-in with the body of the proven GtIntersection_002BF2E0.cpp (frame pads dropped) = build/vt/hdr/inc_hdrj_full's (N185/N187)
DOT_HELPER = []  # DotProduct(CGtV3d, CGtV3d) is in GtMathPs2.h now (hdr6, N209); was:
_DOT_HELPER_OLD = [
    "namespace GtMathPs2 {",
    "// [L] N185: stands in for a missing GtMathPs2 inline -- DotProduct(CGtV3d, CGtV3d) (B3O0PCH map, 116 bytes); body as",
    "// GtIntersection_002BF2E0.cpp (proven): product + ACC sum on $vf1, the 1.0 its own late \"=j\" statement (b119p hoists it).",
    "static inline XAxisType DotProduct(CGtV3d a, CGtV3d b)",
    "{",
    "    u_long128 d, m, one;",
    '    asm("vmul.xyz $vf1, %1, %2" "\\n\\t" "vadday.x $ACC, $vf1, $vf1y" : "=j"(m) : "j"(a.mData), "j"(b.mData));',
    '    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));',
    '    asm("vmaddz.x $vf1, %2, $vf1z" "\\n\\t" "qmfc2.i %0, $vf1" : "=r"(d) : "j"(m), "j"(one));',
    "    return XAxisType(d);",
    "}",
    "}",
]


# lift3: GtMathPs2::Interpolate(CGtV3d, CGtV3d, float) is in the B3O0PCH map (116 bytes) but not in include/b3/GtMathPs2.h
# (only the CGtV4d one); a file-local stand-in with the header's CGtV4d body on .xyz (retail: RepositionCarInLane__10CB3RaceCar
# `vaddax.xyz ACC,a,vf0x; qmtc2.ni t; vmsubax.xyz ACC,a,tx; qmtc2.ni b; vmaddx.xyz r,b,tx; qmfc2.ni`).
LERP3_HELPER = []  # Interpolate(CGtV3d,CGtV3d,float) is in GtMathPs2.h now (hdrrd); was:
_LERP3_HELPER_OLD = [
    "namespace GtMathPs2 {",
    "// [L] N185: stands in for a missing GtMathPs2 inline -- Interpolate(CGtV3d, CGtV3d, float) (B3O0PCH map, 116 bytes);",
    "// body: the header's Interpolate(CGtV4d, CGtV4d, float) on the xyz lanes.",
    "static inline CGtV3d Interpolate(CGtV3d a, CGtV3d b, float t)",
    "{",
    "    u_long128 r;",
    '    asm volatile("vaddax.xyz $ACC, %1, $vf0x" "\\n\\t" "qmtc2.ni %3, $vf2" "\\n\\t" "vmsubax.xyz $ACC, %1, $vf2x" "\\n\\t"',
    '        "qmtc2.ni %2, %1" "\\n\\t" "vmaddx.xyz %1, %1, $vf2x" "\\n\\t" "qmfc2.ni %0, %1"',
    '        : "=r"(r), "+j"(a.mData) : "r"(b.mData), "r"(t));',
    "    return CGtV3d(r);",
    "}",
    "}",
]


# lift3: GtMath::Abs(float) is in the B3O0PCH map (0x12EF10, 12 bytes) but not in include/b3/GtMath.h; a file-local
# stand-in with the body of the proven fabsf helpers (N170/N176). If GtMath.h gains Abs these drafts clash: drop it then.
ABS_HELPER = []  # GtMath::Abs(float) is in GtMath.h now (hdrrd); was:
_ABS_HELPER_OLD = [
    "namespace GtMath {",
    "// [L] N185: stands in for a missing GtMath inline -- Abs(float) (B3O0PCH map, 12 bytes); one abs.s (N170/N176).",
    'static inline float Abs(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }',
    "}",
]


L5_HINT = {}      # lift5: loop body start -> registers only break paths set (from the last run)


def generate(c, has_header):
    text, why = generate2(c, has_header)
    if "ir" not in c:              # hand-queued candidates from older queue files carry no IR: no retries (wirefix)
        return text, why
    # lift2 (2026-10-26): retry a refused function with MWCC's delay-slot-filled jumps un-rotated (Lift.unrotate_pass);
    # only on a refusal, so every function lifted today keeps its source
    if text is None and not c.get("unrot") and any(m == "b" for m, a in c["ir"]["ins"]):
        t2, w2 = generate2(dict(c, unrot=True), has_header)
        if t2 is not None:
            return t2, None
        if w2 != why:
            why = "%s; unrot: %s" % (why, w2)
    # lift4 (2026-10-27): a further retry with the lift4 shapes (with the un-rotation when the function has jumps);
    # only on a refusal, as lift2's
    if text is None and not c.get("lift4"):
        c4 = dict(c, lift4=True, unrot=True) if any(m == "b" for m, a in c["ir"]["ins"]) else dict(c, lift4=True)
        t4, w4 = generate2(c4, has_header)
        if t4 is not None:
            return t4, None
        if w4 != why.split("; unrot: ")[-1]:
            why = "%s; lift4: %s" % (why, w4)
        # lift5 (2026-10-27): one more retry with the lift5 shapes (on top of lift4's); only on a refusal
        c5 = dict(c4, lift5=True)
        for _ in range(6):
            L5_HINT.clear()
            t5, w5 = generate2(c5, has_header)
            if t5 is not None:
                return t5, None
            # a register only a break path sets: run again with it as a loop variable (lift5)
            hint = {k: sorted(set(v) | set((c5.get("l5brk") or {}).get(k, ()))) for k, v in L5_HINT.items()}
            if not hint or all(set(v) <= set((c5.get("l5brk") or {}).get(k, ())) for k, v in hint.items()):
                break
            nh = dict(c5.get("l5brk") or {})
            nh.update(hint)
            c5 = dict(c5, l5brk=nh)
        if w5 != w4:
            why = "%s; lift5: %s" % (why, w5)
    return text, why


def generate2(c, has_header):
    text, why = generate0(c, has_header)
    if text is None and not c.get("nov4") and why and "expression vt" in why:
        t2, w2 = generate0(dict(c, nov4=True), has_header)     # the four-float temporary as a plain local
        if t2 is not None:
            return t2, None
    return text, why


def generate0(c, has_header):
    text, why = generate1(c, has_header)
    if text is None and not c.get("pathmode") and why and why.startswith(STRUCT_SKIPS) and \
            any(m == "label" for m, a in c["ir"]["ins"]):
        t2, w2 = generate1(dict(c, pathmode=True), has_header)
        if t2 is not None:
            return t2, None
        return None, "%s; path mode: %s" % (why, w2)
    return text, why


def generate1(c, has_header):
    global LAST_NVAR
    LAST_NVAR = 1
    LAST_VARIANTS[:] = [0]
    L = Lift(c, has_header)
    L.self_cls = None
    try:
        L.run([tuple(x) for x in c["ir"]["ins"]])
        body = L.finish()
        # self retyped to a callee class?
        if L.self_cls:
            o = L.objs.get(repr(("p", "a0")))
            if o:
                o["type"] = L.self_cls
            else:
                L.objs[repr(("p", "a0"))] = {"root": ("p", "a0"), "fields": {}, "n": -1, "type": L.self_cls}
        LAST_NVAR = 1
        if L.used_tail_if or L.used_dret:
            LAST_NVAR = 6
        if L.used_loop:
            LAST_NVAR = 12           # variants are mixed-radix (2, 3, 2, 3); duplicates are skipped by the callers
        if L.pathmode:
            LAST_NVAR = 192
        if L.used_fuse:
            LAST_NVAR = 384
        if L.used_extra:
            LAST_NVAR = 768
        if L.used_mvorder:
            LAST_NVAR = 1536
        if L.used_liveout:
            LAST_NVAR = 3072
        if L.used_phiorder:
            LAST_NVAR = 6144
        if L.used_ucbool:
            LAST_NVAR = 12288
        if L.used_voidret:
            LAST_NVAR = 24576
        if L.used_mirror:
            LAST_NVAR = 49152
        if L.used_offby1:
            LAST_NVAR = 98304
        if L.used_reload:
            LAST_NVAR = 196608
        if L.used_swj:
            LAST_NVAR = 393216
        if L.used_static:
            LAST_NVAR = 786432
        if L.used_reljoin:
            LAST_NVAR = 1572864
        if L.used_wide:
            LAST_NVAR = 3145728
        if L.used_elptr:
            LAST_NVAR = 6291456
        if L.used_bphi:
            LAST_NVAR = 12582912
        if L.used_swret:
            LAST_NVAR = 25165824
        if L.used_kret:
            LAST_NVAR = 50331648
        if L.used_keepb:
            LAST_NVAR = 100663296
        if L.used_intadd:
            LAST_NVAR = 201326592
        if L.used_notb:
            LAST_NVAR = 402653184
        if L.used_eaddr:
            LAST_NVAR = 805306368
        if L.used_ifswap:
            LAST_NVAR = 1610612736
        if L.used_pullin:
            LAST_NVAR = 3221225472
        if L.used_qorder:
            LAST_NVAR = 6442450944
        if L.used_pinc:
            LAST_NVAR = 12884901888
        L.used_pad = L.frame_gap >= 16 and L.frame_gap <= 0x400
        if L.used_pad:
            LAST_NVAR = 25769803776
        if L.used_csig:
            LAST_NVAR = 51539607552
        if L.used_cptr:
            LAST_NVAR = 103079215104
        if L.used_dfirst:
            LAST_NVAR = 206158430208
        if L.used_lit4:
            LAST_NVAR = 412316860416
        if L.used_fptr:
            LAST_NVAR = 824633720832
        # the variant numbers worth generating: digits only along the dimensions this function uses, fewest
        # non-default digits first, at most 4096 (variants_by_weight; the callers skip duplicate sources)
        dims = []
        if L.used_tail_if or L.used_dret:
            dims += [(1, 2), (2, 3)]
        if L.used_loop:
            dims.append((6, 2))
        if L.pathmode:
            dims += [(12, 4), (48, 2), (96, 2)]
        for flag, mul in (("used_fuse", 192), ("used_extra", 384), ("used_mvorder", 768), ("used_liveout", 1536),
                          ("used_phiorder", 3072), ("used_ucbool", 6144), ("used_voidret", 12288),
                          ("used_mirror", 24576), ("used_offby1", 49152), ("used_reload", 98304),
                          ("used_swj", 196608), ("used_static", 393216), ("used_reljoin", 786432),
                          ("used_wide", 1572864), ("used_elptr", 3145728),
                          ("used_bphi", 6291456), ("used_swret", 12582912),
                          ("used_kret", 25165824), ("used_keepb", 50331648),
                          ("used_intadd", 100663296), ("used_notb", 201326592), ("used_eaddr", 402653184),
                          ("used_ifswap", 805306368), ("used_pullin", 1610612736),
                          ("used_qorder", 3221225472), ("used_pinc", 6442450944),
                          ("used_pad", 12884901888), ("used_csig", 25769803776), ("used_cptr", 51539607552), ("used_dfirst", 103079215104), ("used_lit4", 206158430208), ("used_fptr", 412316860416)):
            if getattr(L, flag):
                dims.append((mul, 2))
        LAST_DIMS[:] = list(dims)
        LAST_VARIANTS[:] = variants_by_weight(dims, 4096)
        return emit(L, body), None
    except Skip as e:
        return None, str(e)
    except (KeyError, IndexError, ValueError) as e:
        return None, "lifter: %s %s" % (type(e).__name__, e)


def variants_by_weight(dims, cap):
    """The variant numbers of the mixed-radix digits `dims` [(multiplier, radix)], fewest non-default digits first
    (then by value), at most `cap` -- the same order as sorting the full product, without building it (cloud review
    2026-10-28: ~20 flags made millions of tuples before the cut)."""
    import itertools
    out = []
    for w in range(len(dims) + 1):
        level = []
        for idx in itertools.combinations(range(len(dims)), w):
            for digits in itertools.product(*[range(1, dims[i][1]) for i in idx]):
                level.append(sum(d * dims[i][0] for i, d in zip(idx, digits)))
        # the level that crosses the cap is built whole (exact order); it is at most ~(flags x radix) times the cap
        level.sort()
        out += level[:cap - len(out)]
        if len(out) >= cap:
            break
    return out


def arr_sig(L, ft):
    """An array field's declaration (element type, stride): two elements' `a[i].f[j]` and `a[i + 1].f[j]` declare
    the same member (GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType)."""
    k = ft[4:]
    if k not in L.objs:
        return None
    try:
        return (L.elem_type(k), L.objs[k].get("stride"))
    except (KeyError, Skip):
        return None


def emit(L, body):
    c = L.c
    lines = []
    if L.named:
        lines += ["// %s -- tiny-function batch (tools/tiny_batch.py, lifted)." % c["demangled"],
                  "// [C] name: the mangled symbol in retail's tables (%s); file: research/retail_names.csv -> %s."
                  % (c.get("conf") or "high", c["file"]),
                  "// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only",
                  "// what this function touches; field names are placeholders and every type is [G] (instruction widths)."]
    else:
        lines += ["// %s -- tiny-function batch (tools/tiny_batch.py, lifted)." % c["name"],
                  "// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so",
                  "// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction",
                  "// widths); `self` is whatever a0 points to."]
    if getattr(L, "own_hdr", False):
        lines.append("// %s has a header in include/ (pads and a few proven fields only): declared locally instead, as the"
                     % L.ccls)
        lines.append("// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].")
    lines.append("")
    if L.fwd:
        lines += L.fwd + [""]
    # struct/class definitions: dependency order (pointer fields only need forward declarations)
    defs = []
    fwd_structs = []
    selftype = L.ccls if L.named else (L.self_cls or "UnkStruct_%08X" % c["addr"])
    types_done = set()
    methods = dict((k, list(v)) for k, v in L.classes.items())
    if L.named:
        own = "%s%s %s(%s)%s" % ("static " if L.static else "", L.rtype, L.meth, ", ".join("%s %s" % p for p in L.plist), " const" if L.cconst else "")
        methods.setdefault(L.ccls, []).insert(0, own)
    smem_types = set()
    for key, o in L.objs.items():
        if o["root"][0] == "g" and o["root"][1] in L.smembers:
            cls, mem = L.smembers[o["root"][1]]
            if list(o["fields"]) != [0] or o["fields"][0].startswith("ARR|"):
                raise Skip("static member used as a struct")
            if L.globals_mode.get(o["root"][1]) == "abs":
                raise Skip("absolutely addressed static member (N50 size)")
            ft = o["fields"][0]
            for lk, LD in L.loads.items():
                if L.same(LD["root"], o["root"]) and LD["off"] == 0:
                    kk = repr(("l", lk))
                    if kk in L.ptr_elem:
                        ft = L.elem_type(L.ptr_elem[kk]) + " *"
                    elif kk in L.objs:
                        ft = L.objs[kk]["type"] + " *"
            methods.setdefault(cls, []).append("static %s %s" % (ft, mem))
            smem_types.add(o["type"])
    allobjs = {}
    for key, o in L.objs.items():
        if o["root"][0] == "g" and o["root"][1] in L.smembers:
            continue
        t = o["type"]
        if t in VECT:
            if any(f_ != 0 for f_ in o["fields"]):
                raise Skip("GtMathPs2 vector parameter used with an offset")
            continue                      # `*pN` / `pN`: the header's class (vlift)
        if t in allobjs and allobjs[t] is not o:
            for off, ft in o["fields"].items():
                ot = allobjs[t]["fields"].get(off, ft)
                if ot != ft and not (ot.startswith("ARR|") and ft.startswith("ARR|") and arr_sig(L, ot) and
                                     arr_sig(L, ot) == arr_sig(L, ft)):
                    raise Skip("type %s merged with conflicting fields" % t)
                allobjs[t]["fields"].setdefault(off, ft)
        else:
            allobjs.setdefault(t, {"fields": dict(o["fields"]), "root": o["root"]})
        if o.get("vptr") is not None:
            if allobjs[t].get("vptr", o["vptr"]) != o["vptr"]:
                raise Skip("type %s with two vptr offsets" % t)
            allobjs[t]["vptr"] = o["vptr"]
    names = list(dict.fromkeys(list(L.class_order) + list(allobjs) + ([L.ccls] if L.named else []) +
                               [cm[0] for cm in L.smembers.values()]))
    names = [t for t in names if t not in smem_types or t in methods]
    aggtypes = set(L.aggs) | {L.objs[k]["type"] for k in L.aggof}
    for t, (mem, size, al) in L.aggs.items():
        allobjs[t] = {"fields": dict(mem), "root": None}
    names = [t for t in names if t in aggtypes] + list(L.aggs) + [t for t in names if t not in aggtypes]
    names = list(dict.fromkeys(names))
    if any(o.get("type") == SPACE for o in L.objs.values()) or any(SPACE in p[0] for p in getattr(L, "plist", [])):
        L.need_g2d = True                 # lift3
    if getattr(L, "need_g2d", False):
        for t in names:
            if t in G2D_DEFINED or t.startswith("CGt2dObject::"):
                if t != SPACE:
                    raise Skip("Gt2dObject.h defines %s" % t)
    for t in names:
        if t in tiny_gen.BUILTIN or t in VECT:
            continue                      # a pointer-to-builtin / GtMathPs2 vector parameter (`*pN`): no struct
        if t == SPACE or t == "GtMathPs2::CGtV2d":
            continue                      # lift3: Gt2dObject.h's / GtMathPs2.h's (fields by member name)
        fl = allobjs.get(t, {"fields": {}, "root": None})
        root = fl["root"]
        if root is not None and L.garray(root):
            continue
        kw = "class" if (t in methods or (L.named and t == L.ccls)) else "struct"
        fields = {}
        if root is not None and root[0] == "ix" and L.scalar_elem(root):
            continue                      # a plain scalar array: no element struct
        # every root of this type (one array indexed by two expressions has two)
        troots = [root] + [o["root"] for o in L.objs.values() if o.get("type") == t and o["root"] != root]
        for off, ft in fl["fields"].items():
            # loaded pointers used as roots get their struct type
            for key, LD in L.loads.items():
                if root is not None and any(L.same_t(LD["root"], r) for r in troots) and LD["off"] == off:
                    k = repr(("l", key))
                    if k in L.ptr_elem:
                        ft = L.elem_type(L.ptr_elem[k]) + " *"
                        break
                    elif k in L.objs:
                        ft = L.objs[k]["type"] + " *"
                        break                 # the first load's type, as ftype
            fields[off] = ft
        if fl.get("vptr") is not None:
            fields[fl["vptr"]] = "VPTR"
        lay, pos = [], 0
        for off in sorted(fields):
            ft = fields[off]
            arr = ""
            if ft == "VPTR":
                if off < pos:
                    raise Skip("overlapping fields at +0x%X" % off)
                if off > pos:
                    lay.append("    unsigned char pad_%X[0x%X];" % (pos, off - pos))
                slots = sorted(sl for (vt_, sl) in L.vsig if vt_ == t)
                lay.append("    // vptr at +0x%X: placeholder virtuals by slot offset (names not in any table) [G]" % off)
                for sl in range(8, max(slots) + 4, 4):
                    types, rt = L.vsig.get((t, sl), ([], "void"))
                    lay.append("    virtual %s vfunc_%X(%s);" % (rt, sl, ", ".join(types)))
                pos = off + 4
                continue
            if ft.startswith(("QARR|", "IARR|")):
                n = int(ft[5:])
                ft, arr = ("u_long128", 16) if ft[0] == "Q" else ("int", 4)
                sz, al = arr * n, arr
                arr = "[%d]" % n
            elif ft == "V3D":
                ft, sz, al = "GtMathPs2::CGtV3d", 16, 16
            elif ft == "V4D":
                ft, sz, al = "GtMathPs2::CGtV4d", 16, 16
            elif ft == "M34":
                ft, sz, al = "GtMathPs2::CGtMatrix3x4", 0x40, 16
            elif ft in ("V3P", "SPH"):           # lift3
                ft, sz, al = "GtMathPs2::CGtV3dPlus" if ft == "V3P" else "GtMathPs2::CGtSphere", 16, 16
            elif ft.startswith("AGG|"):
                sz, al = L.aggs[ft[4:]][1], L.aggs[ft[4:]][2]
                ft = ft[4:]
            elif ft.startswith("AGGOF|"):
                sz, al = L.aggof[ft[6:]]
                ft = L.objs[ft[6:]]["type"]
            elif ft.startswith("ARR|"):
                eo = L.objs[ft[4:]]
                et = L.elem_type(ft[4:])
                sz = eo["stride"]
                al = max([4 if x.endswith("*") else min(SIZE.get(x, 4), 8) for x in eo["fields"].values()] + [1])
                ft, arr = et, "[1]  // [G] element count unknown"
            else:
                sz = 4 if ft.endswith("*") else (1 if ft in L.classes else SIZE.get(ft, 4))
                al = sz
            if arr and not arr.startswith("[1]"):
                pass
            if off < 0:
                raise Skip("negative offset")
            if off % al:
                raise Skip("misaligned field +0x%X" % off)
            if off < pos:
                raise Skip("overlapping fields at +0x%X" % off)
            if off > pos and not (t in aggtypes and off == (pos + al - 1) // al * al):
                lay.append("    unsigned char pad_%X[0x%X];" % (pos, off - pos))
            if arr and arr.startswith("[") and not arr.startswith("[1]"):
                lay.append("    %s field_%X%s;" % (ft, off, arr))
            elif arr:
                lay.append("    %s field_%X%s" % (ft, off, arr.replace("[1]", "[1];", 1)))
            else:
                lay.append("    %s field_%X;" % (ft, off))
            pos = off + sz
        if t in L.psize and pos < L.psize[t]:
            lay.append("    unsigned char pad_%X[0x%X];" % (pos, L.psize[t] - pos))
        if root is not None and root[0] == "loc":
            if pos > L.locsize:
                raise Skip("stack local fields beyond the frame")
            if pos < L.locsize:
                lay.append("    unsigned char pad_%X[0x%X];" % (pos, L.locsize - pos))
        if root is not None and (root[0] == "ix" or (root[0] == "lv" and "stride" in L.objs.get(repr(root), {}))):
            S = L.objs[repr(root)]["stride"]
            if pos > S:
                raise Skip("element fields beyond the stride")
            if pos < S:
                lay.append("    unsigned char pad_%X[0x%X];" % (pos, S - pos))
        if root is not None and root[0] == "g" and L.globals_mode.get(root[1]) == "abs" and pos < 0x10:
            lay.append("    unsigned char pad_%X[0x%X];  // [G] size: absolute addressing needs > 8 bytes (N50)" % (pos, 0x10 - pos))
        if root is not None and root[0] == "g" and L.globals_mode.get(root[1]) == "gp" and pos > 8:
            raise Skip("gp-relative global larger than 8 bytes")
        if root is not None and root[0] == "g" and L.globals_mode.get(root[1]) == "gp" and not lay and \
                t not in methods:
            # only its address taken: a complete type of at most 8 bytes, or MWCC addresses an incomplete one
            # absolutely (func_00335DD0)
            lay.append("    unsigned char pad_0[0x4];  // [G] size: gp-relative addressing needs <= 8 bytes")
        if not lay and t not in methods:
            fwd_structs.append("%s %s;" % (kw, t))
            continue
        d = ["%s %s {" % (kw, t)]
        if t in methods:
            d.append("public:")
            d += ["    %s;" % m for m in methods[t]]
            if lay:
                d.append("")
        d += lay
        d += ["};", ""]
        defs.append((t, d))
    fwd_all = [("struct %s;" if d[0].startswith("struct ") else "class %s;") % t for t, d in defs]
    # a qualified type is already declared in its namespace (L.fwd); it cannot be forward-declared again
    fwd_all = [x for x in fwd_all if "::" not in x]
    fwd_structs = [x for x in fwd_structs if "::" not in x]
    if fwd_structs or fwd_all:
        lines += sorted(set(fwd_structs + fwd_all)) + [""]
    # self type last
    defs.sort(key=lambda x: x[0] == selftype)
    # by-value members (embedded objects, array elements) must be complete before the struct that holds them
    byname, done, order = dict(defs), set(), []

    def visit(t, stack):
        if t in done:
            return
        if t in stack:
            raise Skip("structs contain each other by value")
        for ln in byname[t]:
            m = re.match(r"    ([\w:]+) field_[0-9A-F]+(\[1\])?;", ln)
            if m and m.group(1) in byname and m.group(1) != t:
                visit(m.group(1), stack + (t,))
        done.add(t)
        order.append((t, byname[t]))
    for t, d in defs:
        visit(t, ())
    defs = order
    for t, d in defs:
        lines += d
    for key, o in L.objs.items():
        if o["root"][0] == "g" and o["root"][1] not in L.smembers:
            ga = L.garray(o["root"])
            if ga and L.globals_mode.get(o["root"][1]) == "gp":
                # gp-relative: a complete array of at most 8 bytes (an incomplete one is addressed absolutely)
                lines.append("extern %s %s[%d];  // [G] element count: gp-relative, so at most 8 bytes" %
                             (ga, o["root"][1], max(1, 8 // (4 if ga.endswith("*") else SIZE.get(ga, 4)))))
            elif ga:
                lines.append("extern %s %s[];  // [G] element count unknown" % (ga, o["root"][1]))
            else:
                lines.append("extern %s %s;" % (o["type"], o["root"][1]))
    if any(o["root"][0] == "g" for o in L.objs.values()):
        lines.append("")
    if L.decls:
        lines += L.decls + [""]
    lines.append("// 0x%08X" % c["addr"])
    if L.named:
        lines.append("%s %s::%s(%s)%s" % (L.rtype, L.ccls, L.meth, ", ".join("%s %s" % p for p in L.plist),
                                          " const" if L.cconst else ""))
    else:
        ps = []
        used = L.used_params | {o["root"][1] for o in L.objs.values() if o["root"][0] == "p"}
        gh = max([GPRX.index(r) for r in used if r in GPRX] + [-1])
        fh = max([FPR.index(r) for r in used if r in FPR] + [-1])
        for i in range(gh + 1):
            r = GPRX[i]
            o = L.objs.get(repr(("p", r)))
            if repr(("p", r)) in L.ptr_elem:
                t = L.elem_type(L.ptr_elem[repr(("p", r))]) + " *"
            elif o:
                t = o["type"] + " *"
            elif r == "a0" and L.self_cls:
                t = L.self_cls + " *"
            elif r in L.qparams:
                t = "u_long128"
            elif r in L.dparams:
                t = "unsigned long"
            elif r in L.nparams:
                t = L.nparams[r]
            else:
                t = "int"
            ps.append("%s %s" % (t, L.pname(r)))
        for i in range(fh + 1):
            ps.append("float %s" % L.pname(FPR[i]))
        lines.append('extern "C" %s %s(%s)' % (L.rtype, c["name"], ", ".join(ps)))
    lines.append("{")
    lo = L.objs.get(repr(("loc",)))
    if lo is not None:
        lines.append("    %s local;  // [G] the frame's one local (size: up to the frame top)" % lo["type"])
    if getattr(L, "used_pad", False) and ((c.get("variant") or 0) // 12884901888) % 2:
        pt_ = "UnkStruct_%08X_pad" % c["addr"]
        lines.append("    %s pad;  // [G] an unused local object: retail's frame keeps 0x%X unused bytes at its top "
                     "(a scoped object with a constructor/destructor reserves its slot, known.md N140)" % (pt_, L.frame_gap))
        k_ = lines.index("// 0x%08X" % c["addr"]) if ("// 0x%08X" % c["addr"]) in lines else None
        decl = ["struct %s {" % pt_, "    unsigned char field_0[0x%X];" % (L.frame_gap - 15 if L.frame_gap > 16 else 4),
                "    %s() {}" % pt_, "    ~%s() {}" % pt_, "};", ""]
        if k_ is None:
            raise Skip("no function marker for the pad object")
        lines[k_:k_] = decl
    lines += body
    lines.append("}")
    if L.need_gtmath1 or L.need_abs:
        k = lines.index("")
        lines[k:k] = ["", '#include "b3/GtMath.h"'] + (ABS_HELPER if L.need_abs else [])
    if getattr(L, "need_g2d", False):
        # lift3: Gt2dObject.h (it includes GtMathPs2.h); its Gt2dRenderer is a namespace: a lifted static-method class of
        # that name becomes a namespace block (same mangled names [C] N119: static member = namespace function)
        text_ = "\n".join(lines)
        if re.search(r"^class Gt2dRenderer \{", text_, re.M):
            i0 = lines.index("class Gt2dRenderer {")
            i1 = lines.index("};", i0)
            body_ = [x for x in lines[i0 + 1:i1] if x.strip() and x.strip() != "public:"]
            if any(not x.strip().startswith("static ") for x in body_):
                raise Skip("Gt2dRenderer with non-static members")
            lines[i0:i1 + 1] = ["namespace Gt2dRenderer {"] + [x.replace("static ", "", 1) for x in body_] + ["}"]
            lines = [x for x in lines if x != "class Gt2dRenderer;"]
        k = lines.index("")
        lines[k:k] = ["", '#include "%s"' % G2D_HDR]
    if L.need_gtmath or L.need_dot or L.need_lerp3:
        k = lines.index("")
        lines[k:k] = ["", '#include "b3/GtMathPs2.h"'] + (DOT_HELPER if L.need_dot else []) + \
            (LERP3_HELPER if L.need_lerp3 else [])
    elif any("u_long128" in x for x in lines):
        # a 128-bit field (lq/sq copies): the EE quadword type, declared as include/b3/GtMathPs2.h does
        k = lines.index("")
        lines[k:k] = ["", "typedef unsigned int u_long128 __attribute__((mode(TI)));"]
    text = "\n".join(lines) + "\n"
    text = re.sub(r"\n\n\n+", "\n\n", text)
    unit = ("%s_%08X" % (re.sub(r"[^A-Za-z0-9_]", "_", os.path.splitext(c["file"])[0]), c["addr"])) if L.named else c["name"]
    return text, unit


def has_shift(v):
    """v (an expression) contains a constant left shift."""
    if not isinstance(v, tuple) or not v:
        return False
    if v[0] == "b" and v[1] == "<<" and v[3][0] == "k":
        return True
    return v[0] == "b" and any(has_shift(x) for x in v[2:])


def m_is_latch(L, i):
    """i is the back branch of an enclosing loop other than at the region's own stop."""
    return any(LC.get("K") == i for LC in L.loopctx) and L.ins[i][0] in CONDBR


def flit(bits):
    """The shortest float literal that MWCC turns back into exactly these bits."""
    import struct
    f = struct.unpack("<f", struct.pack("<I", bits))[0]
    if f != f or f in (float("inf"), float("-inf")):
        raise Skip("non-finite float constant")
    for prec in range(1, 10):
        t = "%.*g" % (prec, f)
        try:
            if struct.unpack("<f", struct.pack("<f", float(t)))[0] == f:
                break
        except OverflowError:
            continue              # a shorter decimal rounds past FLT_MAX
    if "e" in t and f == int(f) and abs(f) < 1e7:
        t = "%d" % int(f)                 # 1800.0f, not 1.8e+03f (same bits)
    if "e" not in t and "." not in t:
        t += ".0"
    return t + "f"


def float_like(k):
    """A `lui`-only constant that reads as a short float literal (1.0f, 0.5f, -1.0f, 100.0f...)."""
    if k & 0xFFFF or not k:
        return False
    try:
        t = flit(k)
    except Skip:
        return False
    digits = t.rstrip("f").lstrip("-").replace(".", "").lstrip("0")
    return "e" not in t and len(digits.rstrip("0")) <= 3 and 0x30000000 <= (k & 0x7FFFFFFF) <= 0x4E000000
