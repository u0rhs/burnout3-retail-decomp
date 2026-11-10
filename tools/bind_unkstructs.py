#!/usr/bin/env python3
"""Bind the lifter's anonymous per-function `UnkStruct_*` views to real classes.

    python3 tools/bind_unkstructs.py [--quiet] [--rounds N]

Inputs : src/b3/**/*.cpp, src/nonmatching/*.cpp   (function bodies, local struct views)
         include/b3/**/*.h                        (class definitions: members `field_<hexoff>` / `pad_<hexoff>[n]`)
         research/names/revenge_member_map.tsv    (B3 class + offset -> Revenge member + type; tools/revenge_member_map.py)
         research/names/revenge_class_pairs.tsv   (CB4Xxx -> CB3Xxx pairing, to turn Revenge member types into B3 classes)
Outputs: research/names/unkstruct_bindings.tsv    one row per (file, function, view): bound class, base offset, evidence
         research/names/class_layouts.tsv         union of all bound views per class: offset, width, kind, #functions, name
         research/names/unkstruct_bindings.md     summary (counts by evidence/tier, contradictions, coverage)

Method (names are never invented; a binding says "this view IS that class at that base", not what a field is called):
 1. Parse every struct/class definition (headers + each .cpp's local ones): member offsets come from the lifter's
    `field_<hex>` / `pad_<hex>` names (real-named members are laid out sequentially), widths/kinds from the declared
    type (f32, ptr, i8..i64, obj).  A view = a struct whose name starts with `UnkStruct_`; anything else is a class.
 2. Roots.  A function whose name is a mangled E-map symbol (`Name__17CB3TrafficVehicleFv`) yields its parameter
    classes from the mangled parameter list.  C parameter k is matched to mangled parameter k-1 when the C function has
    one more parameter than the mangled list (extern "C" method: parameter 0 is `this`), or to k when the counts are
    equal.  `this` of a method binds to the mangled class and a `PNN<Class>` / `RNN<Class>` parameter to that class
    ([C]: the symbol is the retail name).  `void Class::Method()` bodies bind the implicit `this` to Class ([C]).
    A bare class-typed parameter/variable is itself the class.
 3. Propagation, evaluated per function body with a small postfix-expression typer (`v->field_X`, `.field_X`, `[i]`,
    `&x->field_X`, casts `(T *)expr`, `(T *)((char *)x + K)`):
      member-type : a view reached through a member of a bound class takes the class that member points to.  The member
                    type comes from (a) callee evidence: that member is passed as `this`/parameter to a method whose
                    mangled name names the class (`&self->field_40` = embedded sub-object; `self->field_44` = pointer),
                    (b) the Revenge member map (`CB4AICar*` -> CB3AICar via the class pairs), (c) a header member typed
                    with a real class. All [L] (or the row's tier for (b)).
      sub-view    : `self->field_40.field_8` with `field_40` an embedded struct, no known class: the view binds to the
                    same class at base + 0x40 (same memory, [C] given the parent binding).
      cast/shift  : `(T *)((char *)x + K)` binds T at base + K.
      local/assign: `T * v = expr;`, `v = expr;` and call-argument passing into a mangled class parameter ([L]).
    Tier of a derived binding = the weaker of its parent's tier and the edge's tier.  Several rounds run because callee
    evidence learned late binds views early.
 3b. Weak evidence.  Passing a view to a method of X only shows "X or a subclass" (call-arg, member-type:callee); such
    bindings and anything derived from them carry `~w` in the evidence column, and are rejected when their accesses reach
    beyond the class extent that exact bindings know (derived-class pollution).  A view bound to two different places with
    equal tier in one function is ambiguous and REJECTED.  `caller-arg` = the same function is called elsewhere with an
    argument whose class is known (name `func_XXXXXX` or any callee): parameter k of the callee is that class.
 4. Consistency.  The union of all bound views is each class's layout. A view access conflicts when it overlaps a
    different-extent access that other functions support at least twice as often, when it reads an f32 where others read a
    pointer (or vice versa), or when it contradicts the Revenge member type's width/kind. A binding with >= 3 conflicts that
    are >= 30% of its accessed offsets is flagged REJECTED and left out of the layouts and the coverage numbers.
 5. Coverage is measured on `field_<hex>` tokens in src/b3 + src/nonmatching: uses resolved through a bound view / a real
    class, plus member-declaration tokens inside bound view definitions; "named" = the (class, offset) has a Revenge row.
Everything is deterministic; rerun after source/header or member-map changes.
"""
import glob, os, re, sys, csv
from collections import defaultdict, Counter

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, 'research', 'names')
QUIET = '--quiet' in sys.argv
ROUNDS = 6
if '--rounds' in sys.argv:
    ROUNDS = int(sys.argv[sys.argv.index('--rounds') + 1])

TIER_RANK = {'[C]': 0, '[L]': 1, '[G]': 2}
def weaker(a, b):
    return a if TIER_RANK[a] >= TIER_RANK[b] else b

# ------------------------------------------------------------------ text helpers
COMMENT = re.compile(r'//[^\n]*|/\*.*?\*/', re.S)
STRLIT = re.compile(r'"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])+\'')

def clean(text):
    # keep newlines out of consideration; comments/strings blanked to a space / "0"
    text = COMMENT.sub(' ', text)
    text = re.sub(r'extern\s+"C"', 'extern CLINK', text)
    text = STRLIT.sub('0', text)
    return text

def match_brace(t, i):
    """t[i] == '{' -> index just past the matching '}'."""
    d = 0
    n = len(t)
    while i < n:
        c = t[i]
        if c == '{':
            d += 1
        elif c == '}':
            d -= 1
            if d == 0:
                return i + 1
        i += 1
    return n

# ------------------------------------------------------------------ types
BUILTIN = {
    'char': (1, 'i8'), 'signed char': (1, 'i8'), 'unsigned char': (1, 'i8'), 'bool': (1, 'i8'),
    'short': (2, 'i16'), 'unsigned short': (2, 'i16'), 'signed short': (2, 'i16'), 'short int': (2, 'i16'),
    'unsigned short int': (2, 'i16'),
    'int': (4, 'i32'), 'unsigned int': (4, 'i32'), 'unsigned': (4, 'i32'), 'signed int': (4, 'i32'),
    'long': (4, 'i32'), 'unsigned long': (4, 'i32'), 'signed long': (4, 'i32'),
    'float': (4, 'f32'), 'double': (8, 'f64'),
    'long long': (8, 'i64'), 'unsigned long long': (8, 'i64'), 'long long int': (8, 'i64'),
    'u_long128': (16, 'i128'), 'u_long': (8, 'i64'), 'u_int': (4, 'i32'), 'u_char': (1, 'i8'), 'u_short': (2, 'i16'),
    'RwReal': (4, 'f32'), 'RwInt32': (4, 'i32'), 'RwUInt32': (4, 'i32'), 'RwInt16': (2, 'i16'),
    'RwUInt16': (2, 'i16'), 'RwInt8': (1, 'i8'), 'RwUInt8': (1, 'i8'),
}
# `long` is 8 bytes on the EE (mips64 ABI is n32/o32: GCC `long` = 4, CodeWarrior PS2 `long` = 8)
BUILTIN['long'] = (8, 'i64'); BUILTIN['unsigned long'] = (8, 'i64'); BUILTIN['signed long'] = (8, 'i64')

class Member:
    __slots__ = ('off', 'size', 'kind', 'typ', 'ptr', 'arr', 'name', 'pad')
    def __init__(self, off, size, kind, typ, ptr, arr, name, pad):
        self.off, self.size, self.kind, self.typ, self.ptr, self.arr, self.name, self.pad = \
            off, size, kind, typ, ptr, arr, name, pad

class SDef:
    def __init__(self, name, base, members, size):
        self.name, self.base, self.members, self.size = name, base, members, size
        self.by_off = {}
        for m in members:
            if not m.pad:
                self.by_off.setdefault(m.off, m)
        self.by_name = {m.name: m for m in members}

STRUCT_HDR = re.compile(r'\b(struct|class)\s+(?:alignas\(\d+\)\s+)?(\w+)\s*(?::\s*(?:public\s+|virtual\s+)*([\w:]+)\s*)?\{')
MEMBER_RE = re.compile(r'^(?:mutable\s+)?(?P<ty>[\w:<>, ]+?)\s*(?P<ptr>[\*&]+)?\s*(?P<name>\w+)\s*(?:\[(?P<n>[^\]]*)\])?(?:\s*:\s*\d+)?$')
HEXOFF = re.compile(r'^(?:field|pad)_([0-9A-Fa-f]+)$')

def parse_int(s):
    s = s.strip().rstrip('uUlL')
    try:
        return int(s, 0)
    except ValueError:
        return None

def type_size(tname, ptr, defs):
    if ptr:
        return 4, 'ptr'
    t = tname.replace('const ', '').strip()
    t = re.sub(r'\bstruct\s+', '', t)
    t = t.split('::')[-1]
    if t in BUILTIN:
        return BUILTIN[t]
    d = defs.get(t)
    if d is not None:
        return d.size, 'obj'
    if re.match(r'^E[A-Z]\w+$', t):
        return 4, 'i32'          # enum by naming convention
    return None, 'unk'

def parse_structs(text, outer_defs):
    """-> {name: SDef} for every struct/class in cleaned text (inline method bodies skipped)."""
    res = {}
    pos = 0
    while True:
        m = STRUCT_HDR.search(text, pos)
        if not m:
            break
        end = match_brace(text, m.end() - 1)
        body = text[m.end():end - 1]
        pos = end
        # drop nested braces (inline methods / nested types)
        flat, d = [], 0
        for c in body:
            if c == '{':
                d += 1
                if d == 1:
                    flat.append(';')
            elif c == '}':
                d -= 1
            elif d == 0:
                flat.append(c)
        body = ''.join(flat)
        members, cur = [], 0
        for stmt in body.split(';'):
            s = ' '.join(stmt.replace('public:', ' ').replace('private:', ' ').replace('protected:', ' ').split())
            if not s or '(' in s or s.startswith(('typedef', 'enum', 'static', 'friend', 'using', 'virtual', 'template', 'struct ', 'class ', 'union')):
                if s.startswith(('struct ', 'class ')) and '(' not in s:
                    s = re.sub(r'^(struct|class)\s+', '', s)
                else:
                    continue
            mm = MEMBER_RE.match(s)
            if not mm:
                continue
            ty, ptr, name, n = mm.group('ty').strip(), mm.group('ptr'), mm.group('name'), mm.group('n')
            if ty in ('return', 'public', 'private'):
                continue
            ho = HEXOFF.match(name)
            arr = None
            if n is not None:
                arr = parse_int(n) if n.strip() else 0
            ptrn = len(ptr) if ptr else 0
            sz, kind = type_size(ty, ptrn, {**outer_defs, **res})
            elem = sz
            tot = (sz or 0) * (arr if arr else 1)
            if ho:
                cur = int(ho.group(1), 16)
            else:
                al = min(sz or 4, 16)
                if al and cur % al:
                    cur += al - cur % al
            members.append(Member(cur, elem, kind, ty.split('::')[-1], ptrn, arr, name, name.startswith('pad_')))
            cur += tot
        res[m.group(2)] = SDef(m.group(2), m.group(3), members, cur)
    return res

# ------------------------------------------------------------------ mangled names
def parse_class_spec(s, i):
    """digits+name, or Q<n> of them -> (list of components, new i) | None"""
    if i >= len(s):
        return None
    if s[i] == 'Q' and i + 1 < len(s) and s[i + 1].isdigit():
        n = int(s[i + 1]); i += 2
        comps = []
        for _ in range(n):
            r = parse_class_spec(s, i)
            if r is None:
                return None
            comps.append(r[0][-1]); i = r[1]
        return comps, i
    j = i
    while j < len(s) and s[j].isdigit():
        j += 1
    if j == i:
        return None
    ln = int(s[i:j])
    if j + ln > len(s):
        return None
    return [s[j:j + ln]], j + ln

def parse_param(s, i, params):
    """-> (type tuple, new i) | None.  type = ('cls', name, ptrlevel) | ('prim', code, ptrlevel) | ('other', '', 0)"""
    ptr = 0
    while i < len(s):
        c = s[i]
        if c in 'PR':
            ptr += 1; i += 1
        elif c in 'CUSV':
            i += 1
        elif c == 'A' and i + 1 < len(s) and s[i + 1].isdigit():   # array A<n>_
            j = s.find('_', i)
            if j < 0:
                return None
            ptr += 1; i = j + 1
        else:
            break
    if i >= len(s):
        return None
    c = s[i]
    if c.isdigit() or c == 'Q':
        r = parse_class_spec(s, i)
        if r is None:
            return None
        return ('cls', r[0][-1], ptr), r[1]
    if c == 'T' and i + 1 < len(s) and s[i + 1].isdigit():
        j = i + 1
        while j < len(s) and s[j].isdigit():
            j += 1
        k = int(s[i + 1:j])
        t = params[k] if k < len(params) else ('other', '', 0)
        return (t[0], t[1], t[2] + ptr), j
    if c == 'F':          # function type  F<params>_<ret>
        depth = 0
        j = i
        # skip to the matching '_' (return type follows)
        sub = []
        j = i + 1
        while j < len(s) and s[j] != '_':
            r = parse_param(s, j, sub)
            if r is None:
                return None
            sub.append(r[0]); j = r[1]
        j += 1
        r = parse_param(s, j, sub)
        if r is None:
            return None
        return ('other', 'fn', ptr), r[1]
    if c in 'vcsilfdbxwr':
        return ('prim', c, ptr), i + 1
    return None

def parse_params(s):
    if s == 'v':
        return []
    params, i = [], 0
    while i < len(s):
        if s[i] == 'N' and i + 2 < len(s) and s[i + 1].isdigit() and s[i + 2].isdigit():
            cnt, idx = int(s[i + 1]), int(s[i + 2])
            t = params[idx] if idx < len(params) else ('other', '', 0)
            params.extend([t] * cnt); i += 3
            continue
        r = parse_param(s, i, params)
        if r is None:
            return params if params else None
        params.append(r[0]); i = r[1]
    return params

_MANGLE_CACHE = {}
def parse_mangled(name):
    """-> (func, class|None, params|None, const) or None"""
    if name in _MANGLE_CACHE:
        return _MANGLE_CACHE[name]
    out = None
    for m in re.finditer(r'__(?=[0-9QCF])', name):
        i = m.end()
        func = name[:m.start()]
        if not func:
            continue
        cls = None
        const = False
        if name[i] == 'C':
            const = True; i += 1
        if i < len(name) and name[i] != 'F':
            r = parse_class_spec(name, i)
            if r is None:
                continue
            cls, i = r[0][-1], r[1]
            if i < len(name) and name[i] == 'C':
                const = True; i += 1
        if i < len(name) and name[i] == 'F':
            params = parse_params(name[i + 1:])
            out = (func, cls, params, const)
            break
        if i == len(name) and cls:
            out = (func, cls, None, const)
            break
    _MANGLE_CACHE[name] = out
    return out

# ------------------------------------------------------------------ function extraction
def split_top(s, sep=','):
    out, d, cur = [], 0, []
    for c in s:
        if c in '(<[':
            d += 1
        elif c in ')>]':
            d -= 1
        if c == sep and d == 0:
            out.append(''.join(cur)); cur = []
        else:
            cur.append(c)
    out.append(''.join(cur))
    return out

class Func:
    def __init__(self, name, cls, params, body, line):
        self.name, self.cls, self.params, self.body, self.line = name, cls, params, body, line

def extract_functions(text):
    """top-level function definitions of cleaned text -> [Func]"""
    funcs = []
    i, n = 0, len(text)
    start = 0
    while i < n:
        c = text[i]
        if c == ';':
            start = i + 1; i += 1
        elif c == '}':
            start = i + 1; i += 1
        elif c == '{':
            head = ' '.join(text[start:i].split())
            end = match_brace(text, i)
            if re.match(r'^(extern CLINK\s*)?(typedef\s+)?(struct|class|union|enum|namespace)\b', head) or head in ('', 'extern CLINK'):
                # type definitions are skipped here (namespace bodies are re-scanned)
                if re.match(r'^(extern CLINK\s*)?namespace\b', head) or head == 'extern CLINK':
                    start = i + 1; i += 1
                    continue
                i = end; start = end
                continue
            body = text[i:end]
            lp = head.find('(')
            if lp > 0:
                pre = head[:lp].strip()
                m = re.search(r'([\w:~]+)$', pre)
                # parameter list up to matching paren
                d, j = 0, lp
                while j < len(head):
                    if head[j] == '(':
                        d += 1
                    elif head[j] == ')':
                        d -= 1
                        if d == 0:
                            break
                    j += 1
                plist = head[lp + 1:j]
                params = []
                for p in split_top(plist):
                    p = p.strip()
                    if not p or p == 'void':
                        continue
                    mm = re.match(r'^(.*?)(\w+)\s*(?:\[[^\]]*\])?$', p)
                    if mm and mm.group(1).strip():
                        ty = mm.group(1).strip(); nm = mm.group(2)
                    else:
                        ty, nm = p, ''
                    params.append((ty, nm))
                if m:
                    full = m.group(1)
                    cls = None
                    if '::' in full:
                        cls, nm = full.rsplit('::', 1)
                        cls = cls.split('::')[-1]
                    else:
                        nm = full
                    line = text.count('\n', 0, i) + 1
                    funcs.append(Func(full if not cls else cls + '::' + nm, cls, params, body, line))
            i = end; start = end
        else:
            i += 1
    return funcs

# ------------------------------------------------------------------ tokenizer for bodies
TOK = re.compile(r'0[xX][0-9A-Fa-f]+[uUlL]*|\d+\.?\d*[fFuUlL]*|[A-Za-z_]\w*|->|\+\+|--|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%&|^~!<>=?:.,;(){}\[\]]')

def tokenize(body):
    return TOK.findall(body)

# ------------------------------------------------------------------ global state
class Ctx:
    pass

C_ = Ctx()
C_.hdr_defs = {}
C_.memmap = {}          # (cls, off) -> dict(name, rtype, tier, ...)
C_.rev2b3 = {}
C_.learned = defaultdict(Counter)   # (cls, abs) -> Counter[(target cls, embedded)]
C_.learned_new = defaultdict(Counter)
C_.pl = defaultdict(Counter)       # (callee name, param idx) -> Counter[(class, tier)] from callers' arguments
C_.pl_new = defaultdict(Counter)
C_.hdr_member_type = {}  # (cls, abs) -> target class from header members typed with a real class

def wv(ev):
    """weak evidence: the class is only known as 'X or a subclass of X' (argument of an X method), or derived from such"""
    return '~w' in ev or 'callee' in ev or 'call-arg' in ev

def inh(ev, parent):
    return ev + '~w' if (parent is not None and wv(parent.ev) and not wv(ev)) else ev

def is_view(n):
    return n.startswith('UnkStruct_')

def kind_conflict(a, b):
    """a, b = (size, kind) of the same offset"""
    if a == b:
        return False
    if a[0] != b[0] and a[0] and b[0]:
        return True
    ka, kb = a[1], b[1]
    return (ka == 'f32' and kb == 'ptr') or (ka == 'ptr' and kb == 'f32')

# ------------------------------------------------------------------ loading
def load_headers():
    defs = {}
    for p in sorted(glob.glob(os.path.join(ROOT, 'include', 'b3', '**', '*.h'), recursive=True)):
        t = clean(open(p, encoding='utf-8', errors='replace').read())
        defs.update(parse_structs(t, defs))
    return defs

def load_memmap():
    mm = {}
    p = os.path.join(OUT, 'revenge_member_map.tsv')
    if not os.path.exists(p):
        return mm
    for r in csv.DictReader(open(p, encoding='utf-8'), delimiter='\t'):
        off = int(r['b3_offset'], 16)
        mm[(r['b3_class'], off)] = dict(name=r['revenge_member'], rtype=r['revenge_type'], tier=r['tier'],
                                        rclass=r['revenge_class'])
    rv = {}
    p = os.path.join(OUT, 'revenge_class_pairs.tsv')
    for r in csv.DictReader(open(p, encoding='utf-8'), delimiter='\t'):
        rv[r['revenge_class']] = r['b3_class']
    return mm, rv

# ------------------------------------------------------------------ per-function analysis
class Pos:
    """(class, base offset) with provenance"""
    __slots__ = ('cls', 'base', 'tier', 'ev')
    def __init__(self, cls, base, tier, ev):
        self.cls, self.base, self.tier, self.ev = cls, base, tier, ev

class Val:
    __slots__ = ('S', 'ptr', 'pos', 'src', 'amp')
    def __init__(self, S=None, ptr=False, pos=None, src=None, amp=False):
        self.S, self.ptr, self.pos, self.src, self.amp = S, ptr, pos, src, amp

NOVAL = Val()

def member_type(cls, abs_off):
    """class a member of `cls` at abs_off points to / embeds -> (class, embedded, tier, ev) | None"""
    cnt = C_.learned.get((cls, abs_off))
    if cnt:
        (t, emb), _ = cnt.most_common(1)[0]
        return t, emb, '[L]', 'member-type:callee'
    row = C_.memmap.get((cls, abs_off))
    if row:
        rt = row['rtype'].replace('const ', '').strip()
        emb = '*' not in rt and '&' not in rt
        base = rt.rstrip('*& ').strip()
        t = C_.rev2b3.get(base)
        if t is None and base in C_.hdr_defs and not is_view(base):
            t = base
        if t is None and base.startswith('CB4'):
            t = 'CB3' + base[3:]
            if t not in C_.hdr_defs:
                t = None
        if t:
            return t, emb, row['tier'], 'member-type:revenge'
    return C_.hdr_member_type.get((cls, abs_off))

class FuncAnalysis:
    """one body, scanned several times so that bindings flow in both directions"""
    def __init__(self, fn, local_defs, file_funcs, collect):
        self.fn = fn
        self.defs = local_defs
        self.params_vars = {}
        self.void_params = {}
        self.file_funcs = file_funcs
        self.bound = {}           # view name -> Pos
        self.conflicts = defaultdict(list)   # view -> [text]
        self.ambig = set()
        self.vars = {}            # variable -> (struct name, is_ptr)
        self.this_cls = None
        self.collect = collect
        self.accesses = []        # (struct, Member, ctx)  at final pass
        self.calls = []
        self.bare = 0

    def getdef(self, name):
        return self.defs.get(name) or C_.hdr_defs.get(name)

    def isclass(self, n):
        return n is not None and not is_view(n) and self.getdef(n) is not None

    # ---- binding
    def bind(self, S, pos):
        if pos is None or S is None or not is_view(S):
            return
        cur = self.bound.get(S)
        if cur is None:
            self.bound[S] = pos
        elif (cur.cls, cur.base) != (pos.cls, pos.base):
            msg = 'bound %s+0x%X (%s) vs %s+0x%X (%s)' % (cur.cls, cur.base, cur.ev, pos.cls, pos.base, pos.ev)
            if msg not in self.conflicts[S] and (pos.cls, pos.base, cur.cls, cur.base) != (cur.cls, cur.base, pos.cls, pos.base):
                # keep the stronger tier binding
                if TIER_RANK[pos.tier] < TIER_RANK[cur.tier]:
                    self.bound[S] = pos
                elif TIER_RANK[pos.tier] == TIER_RANK[cur.tier] and not (cur.ev in ('this-param', 'param-type') or pos.ev in ('this-param', 'param-type')):
                    self.ambig.add(S)
                self.conflicts[S].append(msg)

    def pos_of_struct(self, S):
        if S is None:
            return None
        if self.isclass(S):
            return Pos(S, 0, '[C]', 'class-typed')
        return self.bound.get(S)

    # ---- expression typer over tokens
    def parse_expr(self, T, i, stop=(';', ',', ')', ']', '}', ':', '?')):
        """additive/ternary-free expression -> (Val, j)"""
        v, j = self.parse_unary(T, i)
        while j < len(T):
            t = T[j]
            if t in ('+', '-') and j + 1 < len(T) and re.match(r'^(0[xX][0-9A-Fa-f]+|\d+)[uUlL]*$', T[j + 1]):
                k = parse_int(T[j + 1])
                if v.pos is not None and k is not None:
                    v = Val(v.S, v.ptr, Pos(v.pos.cls, v.pos.base + (k if t == '+' else -k), v.pos.tier, inh('cast-shift', v.pos)), None)
                else:
                    v = Val()
                j += 2
            elif t in ('+', '-', '*', '/', '&', '|', '^', '<<', '>>', '==', '!=', '<', '>', '<=', '>=', '&&', '||', '%', '=', '?', ':') and t not in stop:
                if t in ('=',):
                    # assignment: bind lhs variable's view to rhs
                    rhs, k = self.parse_expr(T, j + 1, stop)
                    self.assign(v, rhs, T, i)
                    return rhs, k
                # opaque binary operator: parse right operand, result unknown
                _, k = self.parse_unary(T, j + 1)
                v = Val()
                j = k
            else:
                break
        return v, j

    def assign(self, lhs, rhs, T, i):
        # plain `ident = expr`: lhs variable carries a view type
        if i < len(T) and T[i] in self.vars and (i + 1 < len(T) and T[i + 1] == '='):
            S, isptr = self.vars[T[i]]
            if rhs.pos is not None and is_view(S):
                self.bind(S, rhs.pos if rhs.pos.ev.startswith(('local', 'cast-shift')) else Pos(rhs.pos.cls, rhs.pos.base, rhs.pos.tier, rhs.pos.ev))

    def parse_unary(self, T, i):
        if i >= len(T):
            return NOVAL, i
        t = T[i]
        if t == '&':
            v, j = self.parse_unary(T, i + 1)
            if v.S is not None or v.src is not None:
                return Val(v.S, True, v.pos, v.src, True), j
            return Val(), j
        if t == '*':
            v, j = self.parse_unary(T, i + 1)
            return Val(v.S, False, v.pos, None), j
        if t in ('-', '!', '~', '+', '++', '--'):
            v, j = self.parse_unary(T, i + 1)
            return Val(), j
        if t == '(':
            # cast?  ( [const] [struct] name {* } )
            k = i + 1
            while k < len(T) and T[k] in ('const', 'struct', 'unsigned', 'signed', 'volatile'):
                k += 1
            if k < len(T) and re.match(r'^[A-Za-z_]\w*$', T[k]) and T[k] not in self.vars and (
                    T[k] in BUILTIN or T[k] in ('void', 'int', 'unsigned', 'char', 'short', 'long', 'float') or self.getdef(T[k]) is not None):
                k2 = k + 1
                while k2 < len(T) and T[k2] in ('*', '&', 'long', 'int', 'char', 'short'):
                    k2 += 1
                if k2 < len(T) and T[k2] == ')' and k2 > k:
                    nxt = k2 + 1
                    if nxt < len(T) and (re.match(r'^[A-Za-z_(&*]', T[nxt]) or T[nxt] in ('(', '&', '*')) and T[nxt] not in (')',):
                        name = T[k]
                        isptr = '*' in T[k + 1:k2] or '&' in T[k + 1:k2]
                        inner, j = self.parse_unary(T, nxt)
                        return self.apply_cast(name, isptr, inner), j
            # parenthesised expression
            v, j = self.parse_expr(T, i + 1)
            if j < len(T) and T[j] == ')':
                j += 1
            v, j = self.postfix(T, j, v)
            return v, j
        if re.match(r'^[A-Za-z_]\w*$', t):
            # call?
            if i + 1 < len(T) and T[i + 1] == '(' and t not in self.vars and t not in ('sizeof', 'if', 'while', 'for', 'switch', 'return'):
                return self.parse_call(T, i)
            if t == 'sizeof':
                return Val(), i + 1
            v = self.primary_ident(t)
            return self.postfix(T, i + 1, v)
        if re.match(r'^(0[xX][0-9A-Fa-f]+|\d)', t):
            return Val(), i + 1
        return Val(), i + 1

    def apply_cast(self, name, isptr, inner):
        if name in ('char', 'void', 'unsigned', 'int', 'float', 'short', 'long') or (self.getdef(name) is None):
            return Val(None, isptr, inner.pos, None) if isptr else Val()
        # cast to a known struct: that struct views whatever `inner` pointed to
        v = Val(name, isptr, inner.pos, inner.src, inner.amp)
        if inner.pos is not None and is_view(name):
            ev = inner.pos.ev if inner.pos.ev in ('cast-shift',) else 'cast'
            self.bind(name, Pos(inner.pos.cls, inner.pos.base, inner.pos.tier, 'cast:' + inner.pos.ev if not inner.pos.ev.startswith('cast-shift') else inner.pos.ev))
        return v

    def primary_ident(self, t):
        if t == 'this':
            if self.this_cls:
                return Val(self.this_cls, True, Pos(self.this_cls, 0, '[C]', 'this'))
            return Val()
        if t in self.vars:
            S, isptr = self.vars[t]
            return Val(S, isptr, self.pos_of_struct(S))
        if t.startswith('field_') and self.this_cls and HEXOFF.match(t):
            # bare member inside a method body
            v = self.member(Val(self.this_cls, True, Pos(self.this_cls, 0, '[C]', 'this')), t)
            return v
        return Val()

    def member(self, v, name):
        S = v.S
        d = self.getdef(S) if S else None
        if d is None:
            return Val()
        m = d.by_name.get(name)
        if m is None:
            ho = HEXOFF.match(name)
            if ho:
                m = d.by_off.get(int(ho.group(1), 16))
        if m is None:
            return Val()
        pos = v.pos if v.pos is not None else self.pos_of_struct(S)
        absoff = None
        src = None
        npos = None
        T = m.typ
        tdef = self.getdef(T) if T else None
        target_S = T if tdef is not None else None
        if pos is not None:
            absoff = pos.base + m.off
            src = (pos.cls, absoff)
            if target_S is not None:
                mt = member_type(pos.cls, absoff)
                if m.ptr > 0 or (m.arr is not None):
                    if m.ptr > 0 and mt is not None:
                        npos = Pos(mt[0], 0, weaker(pos.tier, mt[2]), inh(mt[3], pos))
                    elif m.ptr == 0 and m.arr is not None:
                        npos = Pos(pos.cls, absoff, pos.tier, inh('subview', pos))
                else:
                    if mt is not None and mt[1]:
                        npos = Pos(mt[0], 0, weaker(pos.tier, mt[2]), inh('subobject:' + mt[3], pos))
                    else:
                        npos = Pos(pos.cls, absoff, pos.tier, inh('subview', pos))
        if target_S is not None and not is_view(target_S) and npos is None:
            npos = Pos(target_S, 0, '[L]', 'member-class-typed')
        if self.collect is not None:
            objcls = None
            if m.kind == 'obj' and m.ptr == 0 and pos is not None:
                mt2 = member_type(pos.cls, pos.base + m.off)
                if mt2 is not None and mt2[1]:
                    objcls = mt2[0]
            self.collect.append((S, m, objcls))
        res = Val(target_S, m.ptr > 0, npos, src, False)
        if target_S is not None and npos is not None and is_view(target_S):
            self.bind(target_S, npos)
        return res

    def postfix(self, T, j, v):
        while j < len(T):
            t = T[j]
            if t in ('->', '.') and j + 1 < len(T):
                v = self.member(v, T[j + 1])
                j += 2
            elif t == '[':
                # skip index expression
                d, k = 1, j + 1
                while k < len(T) and d:
                    if T[k] == '[':
                        d += 1
                    elif T[k] == ']':
                        d -= 1
                    k += 1
                v = Val(v.S, False, v.pos, v.src, False)
                j = k
            elif t == '(' and v.S is None and False:
                break
            else:
                break
        return v, j

    def parse_call(self, T, i):
        name = T[i]
        j = i + 2
        args = []
        if j < len(T) and T[j] == ')':
            j += 1
        else:
            while j < len(T):
                a, k = self.parse_expr(T, j)
                args.append(a)
                if k < len(T) and T[k] == ',':
                    j = k + 1
                    continue
                j = k + 1 if k < len(T) and T[k] == ')' else k
                break
        info = parse_mangled(name)
        if info and info[1] is not None or (info and info[2] is not None):
            self.use_call(info, args)
        if self.collect is not None and not name.startswith(('Rw', 'sce', 'mem', 'str')):
            for k, a in enumerate(args):
                if a.pos is not None and a.pos.base == 0 and a.ptr and not a.amp and a.pos.ev != 'class-typed-default':
                    C_.pl_new[(name, k)][(a.pos.cls, a.pos.tier if a.pos.tier != '[C]' else '[L]', wv(a.pos.ev))] += 1
        return Val(), j

    def use_call(self, info, args):
        func, cls, params, const = info
        plist = params if params is not None else []
        if cls is not None and params is not None and len(args) == len(plist) + 1:
            slots = [('cls', cls, 1)] + plist
        elif cls is None and params is not None and len(args) == len(plist):
            slots = plist
        elif cls is not None and params is None and len(args) >= 1:
            slots = [('cls', cls, 1)] + [('other', '', 0)] * (len(args) - 1)
        else:
            return
        for a, s in zip(args, slots):
            if s[0] != 'cls' or s[2] < 1 or a is None:
                continue
            X = s[1]
            if self.getdef(X) is None and not X.startswith(('C', 'E')):
                continue
            if a.src is not None and self.collect is not None:
                C_.learned_new[(a.src[0], a.src[1])][(X, bool(a.amp))] += 1
            if a.S is not None and is_view(a.S) and a.S not in self.bound:
                self.bind(a.S, Pos(X, 0, '[L]', 'call-arg'))

    # ---- scanning
    def run(self, T, final):
        i, n = 0, len(T)
        self.vars_reset()
        while i < n:
            t = T[i]
            # declaration:  Type [*] name [= ...] | Type name[...]
            if re.match(r'^[A-Za-z_]\w*$', t) and (self.getdef(t) is not None) and t not in self.vars:
                k = i + 1
                isptr = False
                while k < n and T[k] in ('*', '&'):
                    isptr = True; k += 1
                if k < n and re.match(r'^[A-Za-z_]\w*$', T[k]) and k + 1 < n and T[k + 1] in ('=', ';', ',', '[', ')'):
                    nm = T[k]
                    if nm not in ('const',):
                        self.vars[nm] = (t, isptr)
                        if T[k + 1] == '=':
                            v, j = self.parse_expr(T, k + 2)
                            if v.pos is not None and is_view(t):
                                p = v.pos
                                self.bind(t, Pos(p.cls, p.base, p.tier, 'local:' + p.ev if not p.ev.startswith('local') else p.ev))
                            i = j
                            continue
                        i = k + 1
                        continue
            if t in self.vars and i + 1 < n and T[i + 1] == '=':
                v, j = self.parse_expr(T, i)
                i = max(j, i + 1)
                continue
            if re.match(r'^[A-Za-z_]\w*$', t) or t in ('(', '&', '*'):
                v, j = self.parse_expr(T, i, stop=(';', ',', ')', ']', '}', ':', '?'))
                i = max(j, i + 1)
                continue
            i += 1

    def vars_reset(self):
        self.vars = dict(self.params_vars)

    def setup(self):
        fn = self.fn
        info = parse_mangled(fn.name) if '::' not in fn.name else None
        slots = None
        mp = None
        cls = None
        if fn.cls:
            self.this_cls = fn.cls
        n = len(fn.params)
        has_this = False
        if info:
            func, cls, mp, const = info
            if mp is not None:
                if cls is not None and n == len(mp) + 1:
                    slots = [('cls', cls, 1)] + mp
                    has_this = True
                elif n == len(mp):
                    slots = mp
        for idx, (ty, nm) in enumerate(fn.params):
            base = re.sub(r'\b(const|struct|unsigned|volatile)\b', '', ty)
            ptr = '*' in base or '&' in base
            tn = re.sub(r'[\*&\s]', '', base)
            if not nm:
                continue
            S = tn if self.getdef(tn) is not None else None
            if S is not None:
                self.params_vars[nm] = (S, ptr)
            elif ptr:
                self.params_vars[nm] = (None, True)
            if slots is not None and idx < len(slots) and slots[idx][0] == 'cls' and slots[idx][2] >= 1:
                X = slots[idx][1]
                ev = 'this-param' if (idx == 0 and has_this) else 'param-type'
                if S is not None and is_view(S):
                    self.bind(S, Pos(X, 0, '[C]', ev))
                elif S is None and ptr:
                    self.void_params[nm] = Pos(X, 0, '[C]', ev)
        for idx, (ty, nm) in enumerate(fn.params):
            if not nm or (slots is not None and idx < len(slots) and slots[idx][0] == 'cls'):
                continue
            cnt = C_.pl.get((fn.name, idx))
            if not cnt:
                continue
            (X, tier, wk), n = cnt.most_common(1)[0]
            if len(cnt) > 1 and cnt.most_common(2)[1][1] == n:
                continue
            S = self.params_vars.get(nm, (None, False))[0]
            if S is not None and is_view(S):
                self.bind(S, Pos(X, 0, tier, 'caller-arg~w' if wk else 'caller-arg'))
            elif S is None and self.params_vars.get(nm, (None, False))[1]:
                self.void_params[nm] = Pos(X, 0, tier, 'caller-arg~w' if wk else 'caller-arg')
        if has_this:
            self.this_cls = None   # extern "C" form: `this` is the explicit first parameter

    def run_pass(self, T):
        vp = self.void_params
        orig = FuncAnalysis.primary_ident.__get__(self)
        def pi(t):
            if t in vp:
                return Val(None, True, vp[t])
            return orig(t)
        self.primary_ident = pi
        try:
            self.run(T, False)
        finally:
            del self.primary_ident

# ------------------------------------------------------------------ driver
def rtype_kind(rt):
    rt = rt.replace('const ', '').strip()
    if '*' in rt or '&' in rt:
        return 4, 'ptr'
    if rt in BUILTIN:
        return BUILTIN[rt]
    return None, 'unk'

def main():
    mm, rv = load_memmap()
    C_.memmap, C_.rev2b3 = mm, rv
    C_.hdr_defs = load_headers()
    for d in C_.hdr_defs.values():
        if is_view(d.name):
            continue
        for m in d.members:
            if m.pad or not m.typ:
                continue
            if m.typ in C_.hdr_defs and not is_view(m.typ) and m.typ != d.name and m.kind in ('ptr', 'obj'):
                C_.hdr_member_type[(d.name, m.off)] = (m.typ, m.ptr == 0, '[L]', 'member-type:header')

    files = sorted(glob.glob(os.path.join(ROOT, 'src', 'b3', '**', '*.cpp'), recursive=True)) + \
        sorted(glob.glob(os.path.join(ROOT, 'src', 'nonmatching', '*.cpp')))
    parsed = []
    total_tokens = 0
    for p in files:
        t = clean(open(p, encoding='utf-8', errors='replace').read())
        total_tokens += len(re.findall(r'\bfield_[0-9A-Fa-f]+\b', t))
        defs = parse_structs(t, C_.hdr_defs)
        funcs = [f for f in extract_functions(t) if 'field_' in f.body]
        parsed.append((os.path.relpath(p, ROOT), t, defs, funcs))
    if not QUIET:
        print('files %d, field_ tokens %d, header structs %d' % (len(files), total_tokens, len(C_.hdr_defs)), file=sys.stderr)

    results = []
    for rnd in range(ROUNDS):
        C_.learned_new = defaultdict(Counter)
        C_.pl_new = defaultdict(Counter)
        results = []
        for rel, t, defs, funcs in parsed:
            for fn in funcs:
                fa = FuncAnalysis(fn, defs, funcs, None)
                fa.setup()
                T = tokenize(fn.body)
                for k in range(3):
                    fa.collect = [] if k == 2 else None
                    fa.run_pass(T)
                results.append((rel, fn, fa))
        C_.learned = C_.learned_new
        C_.pl = C_.pl_new
        if not QUIET:
            nb = sum(len(fa.bound) for _, _, fa in results)
            print('round %d: %d functions, %d views bound, %d learned member types' % (rnd, len(results), nb, len(C_.learned)), file=sys.stderr)
    return parsed, results, total_tokens

def finish(parsed, results, total_tokens):
    bindings = []
    for rel, fn, fa in results:
        per = defaultdict(Counter)
        for S, m, oc in (fa.collect or []):
            per[S][(m.off, 0 if oc else m.size, ('obj:' + oc) if oc else m.kind)] += 1
        for S, cnt in per.items():
            if is_view(S):
                pos = fa.bound.get(S)
                if pos is None:
                    continue
                row = dict(file=rel, fn=fn.name, view=S, cls=pos.cls, base=pos.base, ev=pos.ev, tier=pos.tier,
                           acc=Counter(), conflicts=list(fa.conflicts.get(S, [])), ambig=S in fa.ambig)
                for (off, sz, kind), n in cnt.items():
                    row['acc'][(pos.base + off, sz, kind)] += n
            else:
                row = dict(file=rel, fn=fn.name, view=S, cls=S, base=0, ev='class-typed', tier='[C]', acc=Counter(),
                           conflicts=[], real=True)
                for (off, sz, kind), n in cnt.items():
                    row['acc'][(off, sz, kind)] += n
            row['n'] = sum(cnt.values())
            bindings.append(row)

    def build_layout(rows):
        lay = defaultdict(lambda: defaultdict(Counter))
        use = defaultdict(lambda: defaultdict(Counter))
        for r in rows:
            for (a, sz, kind), n in r['acc'].items():
                if sz is None or kind == 'obj':
                    continue
                lay[r['cls']][a][(sz, kind)] += 1
                use[r['cls']][a][(sz, kind)] += n
        return lay, use

    def is_weak(r):
        return not r.get('real') and wv(r['ev'])

    def strong_extent(rows):
        ext = defaultdict(int)
        for r in rows:
            if r.get('real') or not is_weak(r):
                for (a, sz, kind) in r['acc']:
                    if sz and kind != 'obj':
                        ext[r['cls']] = max(ext[r['cls']], a + sz)
        for (cls, off), row in C_.memmap.items():
            pass
        return ext

    def contains(a, sa, b, sb):
        return (a <= b and b + sb <= a + sa) or (b <= a and a + sa <= b + sb)

    def check(rows, lay, sext=None):
        for r in rows:
            r['bad'] = []
            r['soft'] = 0
            cl = lay[r['cls']]
            for (a, sz, kind), n in r['acc'].items():
                if sz is None or kind == 'obj':
                    continue
                own = cl[a][(sz, kind)]
                bad = None
                for k2, c2 in cl[a].items():
                    if k2 != (sz, kind) and c2 >= 2 and c2 >= 2 * own:
                        if k2[0] == sz and kind_conflict((sz, kind), k2):
                            bad = '0x%X: %d%s vs %d%s (n=%d)' % (a, sz, kind, k2[0], k2[1], c2)
                            break
                        r['soft'] += 1
                if bad is None:
                    for a2 in range(max(0, a - 15), a + sz):
                        if a2 == a or a2 not in cl:
                            continue
                        for k2, c2 in cl[a2].items():
                            if k2[0] and a2 + k2[0] > a and a2 < a + sz and c2 >= 2 and c2 >= 2 * own:
                                if contains(a, sz, a2, k2[0]):
                                    r['soft'] += 1
                                else:
                                    bad = '0x%X: %d%s partially overlaps 0x%X: %d%s (n=%d)' % (a, sz, kind, a2, k2[0], k2[1], c2)
                                    break
                        if bad:
                            break
                if bad is None:
                    row = C_.memmap.get((r['cls'], a))
                    if row and row['tier'] == '[L]':
                        rs, rk = rtype_kind(row['rtype'])
                        if rs and rs == sz and kind_conflict((sz, kind), (rs, rk)):
                            bad = '0x%X: %d%s vs Revenge %s %s' % (a, sz, kind, row['name'], row['rtype'])
                        elif rs and rs != sz:
                            r['soft'] += 1
                if bad:
                    r['bad'].append(bad)
            r['rejected'] = len(r['bad']) >= 3 and len(r['bad']) >= 0.3 * max(1, len(r['acc'])) and not r.get('real')
            if r.get('ambig'):
                r['rejected'] = True
                r['bad'].insert(0, 'ambiguous: the view is bound to different places in the same function')
            if sext is not None and is_weak(r) and not r['rejected']:
                e = sext.get(r['cls'])
                top = max([a + sz for (a, sz, kind) in r['acc'] if sz and kind != 'obj'] or [0])
                if e and top > e + 0x10:
                    r['bad'].append('is-a: accesses reach 0x%X, beyond the class extent 0x%X known from exact bindings (derived class?)' % (top, e))
                    r['rejected'] = True
    sext = strong_extent(bindings)
    lay, use = build_layout(bindings)
    check(bindings, lay, sext)
    for _ in range(2):
        keep = [r for r in bindings if not r['rejected']]
        lay, use = build_layout(keep)
        check(keep, lay)
        for r in bindings:
            if r['rejected'] and 'is-a' in ' '.join(r['bad']):
                continue
    keep = [r for r in bindings if not r['rejected']]
    for r in bindings:
        if r['rejected']:
            pass
    n_rej = sum(1 for r in bindings if r['rejected'])

    view_rows = [r for r in bindings if not r.get('real')]
    view_rows.sort(key=lambda r: (r['file'], r['fn'], r['view']))
    with open(os.path.join(OUT, 'unkstruct_bindings.tsv'), 'w', encoding='utf-8') as f:
        f.write('file\tfunction\tunkstruct\tbound_class\tbase_offset\tevidence\ttier\tn_field_uses\tcontradictions\n')
        for r in view_rows:
            con = list(r['conflicts']) + r['bad']
            if r['rejected']:
                con.insert(0, 'REJECTED(%d conflicts)' % len(r['bad']))
            f.write('\t'.join([r['file'], r['fn'], r['view'], r['cls'], '0x%X' % r['base'], r['ev'], r['tier'],
                              str(r['n']), '; '.join(con[:6]) + (' ...(%d)' % len(con) if len(con) > 6 else '')]) + '\n')

    with open(os.path.join(OUT, 'class_layouts.tsv'), 'w', encoding='utf-8') as f:
        f.write('class\toffset\twidth\tkind\tobserved_in_N_functions\tn_uses\trevenge_name\tname_tier\trevenge_type\tstatus\n')
        for cls in sorted(lay):
            cl = lay[cls]
            for a in sorted(cl):
                keys = cl[a].most_common()
                for idx, ((sz, kind), n) in enumerate(keys):
                    row = C_.memmap.get((cls, a))
                    status = 'ok' if len(keys) == 1 else ('primary' if idx == 0 else 'alt')
                    f.write('\t'.join([cls, '0x%X' % a, str(sz), kind, str(n), str(use[cls][a][(sz, kind)]),
                                      row['name'] if row else '', row['tier'] if row else '', row['rtype'] if row else '', status]) + '\n')

    attributed = named_uses = base_attr = base_named = 0
    cls_new_named = Counter()
    for r in keep:
        for (a, sz, kind), n in r['acc'].items():
            attributed += n
            nm = (r['cls'], a) in C_.memmap
            if nm:
                named_uses += n
            if r.get('real'):
                base_attr += n
                base_named += n if nm else 0
            elif nm:
                cls_new_named[r['cls']] += n
    decl_attr = decl_named = 0
    bound_views = defaultdict(Counter)
    for r in keep:
        if not r.get('real'):
            bound_views[(r['file'], r['view'])][(r['cls'], r['base'])] += 1
    for rel, t, defs, funcs in parsed:
        for name, d in defs.items():
            nfield = [m for m in d.members if m.name.startswith('field_')]
            if is_view(name):
                bv = bound_views.get((rel, name))
                if not bv:
                    continue
                (cls, base), _ = bv.most_common(1)[0]
            else:
                cls, base = name, 0
            for m in nfield:
                decl_attr += 1
                if (cls, base + m.off) in C_.memmap:
                    decl_named += 1
    paired = set(C_.rev2b3.values())
    paired_uses = sum(n for r in keep for n in r['acc'].values() if r['cls'] in paired)
    root_ev = Counter()
    ev_stat = defaultdict(lambda: [0, 0, 0])     # first evidence word -> [views, flagged hard, rejected]
    for r in view_rows:
        if not r['rejected']:
            root_ev[(r['ev'], r['tier'])] += 1
        k = r['ev'].split(':')[0] if not r['ev'].startswith(('member-type', 'subobject', 'cast')) else r['ev'].split(':')[0] + ':' + r['ev'].split(':')[-1].split(':')[0]
        e = ev_stat[k]
        e[0] += 1
        e[1] += 1 if r['bad'] else 0
        e[2] += 1 if r['rejected'] else 0
    contr = [r for r in view_rows if r['conflicts'] or r['bad']]
    cstats = []
    for cls, cl in lay.items():
        ext = cov = 0
        for a, ks in cl.items():
            sz = ks.most_common(1)[0][0][0]
            ext = max(ext, a + sz)
            cov += sz
        multi = sum(1 for a, ks in cl.items() if sum(ks.values()) >= 2)
        cstats.append((cls, len(cl), ext, cov, multi))
    md = []
    w = md.append
    w('# unkstruct bindings -- summary (generated by tools/bind_unkstructs.py)\n')
    w('- functions analysed (with `field_` in the body): %d; views bound: %d; REJECTED (layout contradictions): %d; flagged: %d' % (
        len(results), len(view_rows), n_rej, len(contr)))
    w('- `field_` tokens in src/b3 + src/nonmatching: %d' % total_tokens)
    w('- uses resolved to a class: %d via views + %d via real classes = %d (%.1f%% of all tokens); named (Revenge member via the binding): %d (%.1f%%)' % (
        attributed - base_attr, base_attr, attributed, 100.0 * attributed / total_tokens, named_uses, 100.0 * named_uses / total_tokens))
    w('- plus %d member-declaration tokens in bound view / local class definitions (%d named): total attributable %d (%.1f%%), named %d (%.1f%%)' % (
        decl_attr, decl_named, attributed + decl_attr, 100.0 * (attributed + decl_attr) / total_tokens,
        named_uses + decl_named, 100.0 * (named_uses + decl_named) / total_tokens))
    w('- of the %d attributed uses, %d (%.0f%%) sit in classes that have a Revenge pairing (only those can ever be named by the member map); %.0f%% of those are named' % (
        attributed, paired_uses, 100.0 * paired_uses / max(1, attributed), 100.0 * named_uses / max(1, paired_uses)))
    w('- without view bindings (real classes only): %d uses attributed, %d named' % (base_attr, base_named))
    w('')
    w('| evidence | tier | views |')
    w('|---|---|---|')
    for (e, t), n in sorted(root_ev.items(), key=lambda x: -x[1])[:40]:
        w('| %s | %s | %d |' % (e, t, n))
    w('')
    w('| evidence (first word) | views | with hard contradictions | rejected |')
    w('|---|---|---|---|')
    for k, (a, b, c) in sorted(ev_stat.items(), key=lambda x: -x[1][0]):
        w('| %s | %d | %d (%.0f%%) | %d |' % (k, a, b, 100.0 * b / a, c))
    w('')
    w('## Contradictions: %d views flagged (%d rejected)' % (len(contr), n_rej))
    for r in sorted(contr, key=lambda r: -len(r['bad']) - len(r['conflicts']))[:25]:
        w('- %s `%s` %s -> %s+0x%X: %s' % (r['file'].split('/')[-1], r['fn'][:50], r['view'], r['cls'], r['base'], '; '.join((r['conflicts'] + r['bad'])[:3])))
    w('')
    w('## Top classes by newly named uses (through views)')
    for cls, n in cls_new_named.most_common(25):
        w('- %s: %d' % (cls, n))
    w('')
    w('## Most complete reconstructed layouts')
    w('| class | offsets | seen in >=2 fn | extent | covered bytes | density |')
    w('|---|---|---|---|---|---|')
    for cls, noff, ext, cov, multi in sorted(cstats, key=lambda x: -x[4])[:40]:
        w('| %s | %d | %d | 0x%X | %d | %.0f%% |' % (cls, noff, multi, ext, cov, 100.0 * cov / max(1, ext)))
    open(os.path.join(OUT, 'unkstruct_bindings.md'), 'w', encoding='utf-8').write('\n'.join(md) + '\n')
    if not QUIET:
        print('\n'.join(md[:8]))

if __name__ == '__main__':
    finish(*main())
