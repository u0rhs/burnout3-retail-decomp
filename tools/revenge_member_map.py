#!/usr/bin/env python3
"""Build a B3 -> Revenge member-name map from the Revenge STABS type dump.

    python3 tools/revenge_member_map.py [--quiet]

Inputs : include/b3/classes/*.h   (B3 class headers; members `field_<hexoff>` / `pad_<hexoff>[n]`,
                                   a few real names; only the *touched* members exist, the rest is pad)
         research/stabs/revenge_jul14_types.h  (stdump of Revenge Jul 14 2005: full layouts, GCC/SN)
         src/b3, src/nonmatching  (only to count `field_` uses per class)
Outputs: research/names/revenge_member_map.tsv   one row per mapped member
         research/names/revenge_class_pairs.tsv  one row per paired class (alignment evidence)
         research/names/revenge_member_map.md    summary (counts, coverage)  [regenerated too]

Method (docs/provenance.md "Revenge STABS dumps"; names are Revenge's, so [L]/[G] evidence for B3 only):
 1. Pair CB3Xxx -> CB4Xxx (tools/stabs_lookup.py mapping), else the same name (CGt*, GtMath...), when the
    Revenge struct exists. Method-name overlap between the B3 header's declared methods and Revenge's is
    recorded as supporting pairing evidence.
 2. Flatten Revenge's layout (bases at their offsets, embedded structs/arrays expanded to scalar leaves,
    typedefs resolved) and reduce both sides' types to a width-kind (f32, ptr, i8, i16, i32, i64, i128,
    CGtV3d ...). B3 header types are instruction widths [G], so equal kind is the only type test.
 3. Alignment: every (B3 field, Revenge leaf) pair of equal kind votes for delta = b3_off - rev_off.
    A delta is *significant* when its votes exceed the empirical null (3b). Kinds: identical (delta 0 only, size equal), prefix (delta 0, sizes differ),
    shifted (one or several non-zero significant deltas), none.
 3b. Significance is empirical: each class's field kinds are shuffled among its offsets 40x; a delta needs
    more votes than the shuffles' 95th-percentile best delta (min 3). A field matching two significant deltas
    with votes within 20% (periodic/array structure) is dropped as ambiguous; one B3 offset per Revenge leaf
    (better-supported delta wins); one offset with several candidates is demoted to [G] and flagged CONFLICT.
    `--control` runs the same code on the shuffled layouts as a false-positive estimate (prints row counts only).
 4. A field is mapped under the significant delta with most votes that it matches. [L] when that
    delta is also confirmed by >= 2 *other* matched fields within 0x100 bytes of it, or, for delta 0,
    by >= 3 other fields in the class; otherwise [G]. Rows whose delta is not significant are dropped.
Everything is deterministic; rerun after header changes.
"""
import glob, math, os, random, re, sys, zlib
from collections import defaultdict, Counter

NULL_TRIALS = 40
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TYPES = os.path.join(ROOT, 'research', 'stabs', 'revenge_jul14_types.h')
OUT = os.path.join(ROOT, 'research', 'names')

# ---------------------------------------------------------------- Revenge parse
HDR = re.compile(r'^(struct|union|class)\s+([^\s{:]+(?:<[^{]*?>)?)\s*(?::\s*(.*?))?\s*\{\s*//\s*0x([0-9a-f]+)')
BASE = re.compile(r'/\*\s*0x([0-9a-f]+)\s*\*/\s*(?:public\s+|virtual\s+)*([^\s,]+(?:<[^,]*?>)?)')
MEM = re.compile(r'^\s*/\*\s*0x([0-9a-f]+)\s*\*/\s*(.+?)\s*;\s*$')
TDEF = re.compile(r'^typedef\s+(.+?)\s+(\w+)\s*;\s*$')
ENUM = re.compile(r'^enum\s+(\w+)')


class RStruct:
    def __init__(self, name, size, bases):
        self.name, self.size, self.bases, self.members = name, size, bases, []


def parse_revenge():
    structs, typedefs, enums = {}, {}, set()
    cur, depth = None, 0
    for ln in open(TYPES, encoding='utf-8', errors='replace'):
        ln = ln.rstrip('\n')
        if cur is None:
            m = ENUM.match(ln)
            if m:
                enums.add(m.group(1))
            m = TDEF.match(ln)
            if m and '{' not in ln:
                typedefs[m.group(2)] = m.group(1)
            m = HDR.match(ln)
            if m and m.group(1) != 'union':
                bases = []
                if m.group(3):
                    for bm in BASE.finditer(m.group(3)):
                        bases.append((int(bm.group(1), 16), bm.group(2)))
                cur = RStruct(m.group(2), int(m.group(4), 16), bases)
                depth = 1
            elif m and ln.endswith('{') is False:
                pass
            continue
        s = ln.strip()
        if s.endswith('{') or re.search(r'\{\s*//', s):
            depth += 1
            continue
        if s.startswith('}'):
            depth -= 1
            if depth == 0:
                structs.setdefault(cur.name, cur)
                cur = None
            continue
        if depth != 1:
            continue
        m = MEM.match(ln)
        if m and '(' not in m.group(2).split('[')[0].replace('(*', '') or (m and '(*' in m.group(2)):
            off = int(m.group(1), 16)
            decl = m.group(2)
            if ':' in decl and re.search(r':\s*\d+$', decl):
                continue                      # bitfield
            if '(*' in decl:
                nm = re.search(r'\(\*(\w+)', decl)
                if nm:
                    cur.members.append((off, 'void(*)()', nm.group(1), None))
                continue
            am = re.match(r'^(.*?)\s*(\**)\s*(\w+)((?:\[\d+\])*)$', decl)
            if not am:
                continue
            ty = (am.group(1) + ' ' + am.group(2)).strip() if am.group(2) else am.group(1)
            ty = ty.replace(' *', '*')
            dims = [int(x) for x in re.findall(r'\[(\d+)\]', am.group(4))]
            cur.members.append((off, ty + ('*' * 0), am.group(3), dims or None))
            if am.group(2):
                cur.members[-1] = (off, am.group(1).strip() + am.group(2), am.group(3), dims or None)
    return structs, typedefs, enums


SCALAR = {
    'float': ('f32', 4), 'double': ('f64', 8), 'int': ('i32', 4), 'unsigned int': ('i32', 4),
    'short int': ('i16', 2), 'short unsigned int': ('i16', 2), 'char': ('i8', 1), 'signed char': ('i8', 1),
    'unsigned char': ('i8', 1), 'bool': ('i8', 1), 'long int': ('i64', 8), 'long unsigned int': ('i64', 8),
    'long long int': ('i64', 8), 'long long unsigned int': ('i64', 8), '__int128_t': ('i128', 16),
    '__uint128_t': ('i128', 16), 'u_long128': ('i128', 16),
}
VEC = {'CGtV3d': 'v3d', 'CGtV4d': 'v4d'}


class Rev:
    def __init__(self):
        self.structs, self.typedefs, self.enums = parse_revenge()
        self._leaf = {}

    def resolve(self, ty):
        """-> (kind, size) with kind in width-kinds, 'ptr', 'S:<name>' or None."""
        ty = ty.strip()
        for _ in range(8):
            if ty.endswith('*') or ty.endswith(')'):
                return ('ptr', 4)
            if ty in SCALAR:
                return SCALAR[ty]
            if ty in self.enums:
                return ('i32', 4)
            if ty in self.typedefs:
                ty = self.typedefs[ty].strip()
                continue
            if ty.startswith(('struct ', 'class ', 'enum ', 'union ')):
                ty = ty.split(None, 1)[1]
                continue
            break
        if ty in VEC or ty.split('::')[-1] in VEC:
            k = VEC[ty.split('::')[-1]]
            return (k, 16)
        if ty in self.structs:
            return ('S:' + ty, self.structs[ty].size)
        return (None, 0)

    def layout(self, name, base_off=0, seen=()):
        """Direct members of `name` incl. inherited ones: [(abs_off, type, member, dims, owner)]."""
        st = self.structs.get(name)
        if not st or name in seen:
            return []
        out = []
        for boff, bname in st.bases:
            out += self.layout(bname, base_off + boff, seen + (name,))
        for off, ty, nm, dims in st.members:
            out.append((base_off + off, ty, nm, dims, name))
        return out

    def leaves(self, name):
        """Scalar leaves of struct `name`: list of (off, kind, size, path, top_member, top_type, owner, top_off)."""
        if name in self._leaf:
            return self._leaf[name]
        res = []
        for off, ty, nm, dims, owner in self.layout(name):
            kind, size = self.resolve(ty)
            if nm == '__vtable':
                continue
            self._expand(res, off, kind, size, dims, nm, nm, ty, owner, off, 0)
        self._leaf[name] = res
        return res

    def _expand(self, res, off, kind, size, dims, path, top, topty, owner, topoff, depth):
        if kind is None:
            return
        if dims:
            n = 1
            for d in dims:
                n *= d
            if n > 256:
                n = 256
            if size == 0:
                return
            for i in range(n):
                idx = '[%d]' % i if len(dims) == 1 else '[%d]' % i      # flat index for multi-dim
                self._expand(res, off + i * size, kind, size, None, path + idx, top, topty, owner, topoff, depth)
            return
        res.append((off, kind, size, path, top, topty, owner, topoff, depth))
        if kind.startswith('S:') and depth < 3:
            for o2, t2, n2, d2, ow2 in self.layout(kind[2:]):
                if n2 == '__vtable':
                    continue
                k2, s2 = self.resolve(t2)
                self._expand(res, off + o2, k2, s2, d2, path + '.' + n2, top, topty, owner, topoff, depth + 1)
        if kind in ('v3d', 'v4d'):
            pass


# ---------------------------------------------------------------- B3 parse
B3_SIZES = {'char': 1, 'signed char': 1, 'unsigned char': 1, 'bool': 1, 'short': 2, 'unsigned short': 2,
            'int': 4, 'unsigned int': 4, 'float': 4, 'long': 8, 'unsigned long': 8, 'u_long128': 16}


def b3_kind(ty):
    t = ty.strip()
    if t.endswith('*'):
        return ('ptr', 4)
    t = re.sub(r'^(GtMathPs2::|struct |class )', '', t)
    if t == 'float':
        return ('f32', 4)
    if t in ('char', 'signed char', 'unsigned char', 'bool'):
        return ('i8', 1)
    if t in ('short', 'unsigned short'):
        return ('i16', 2)
    if t in ('int', 'unsigned int'):
        return ('i32', 4)
    if t in ('long', 'unsigned long'):
        return ('i64', 8)
    if t == 'u_long128':
        return ('i128', 16)
    if t == 'CGtV3d':
        return ('v3d', 16)
    if t == 'CGtV4d':
        return ('v4d', 16)
    if re.match(r'^E[A-Z]\w+$', t):
        return ('i32', 4)
    if re.match(r'^\w+$', t):
        return ('S:' + t, 0)
    return (None, 0)


CLS = re.compile(r'^(class|struct)\s+(\w+)\s*(?::\s*(?:public\s+)?([\w:]+))?\s*\{')
FLD = re.compile(r'^\s+([\w:\s\*<>]+?)\s*(\w+)((?:\[(?:0x)?[0-9A-Fa-f]+\])?)\s*;')


class B3Class:
    def __init__(self, name, base, path):
        self.name, self.base, self.path = name, base, path
        self.fields = []     # (off, type, name, count)
        self.methods = set()
        self.extent = 0
        self.virtual = False


def parse_b3_header(path):
    out = {}
    cur = None
    cursor = 0
    for ln in open(path, encoding='utf-8', errors='replace'):
        ln = ln.rstrip('\n')
        if cur is None:
            m = CLS.match(ln)
            if m and not ln.rstrip().endswith('};'):
                cur = B3Class(m.group(2), m.group(3), path)
                cursor = 0
            continue
        if ln.startswith('}'):
            out[cur.name] = cur
            cur = None
            continue
        if '(' in ln:
            mm = re.search(r'(\w+)\s*\(', ln)
            if mm:
                cur.methods.add(mm.group(1))
            if 'virtual' in ln:
                cur.virtual = True
            continue
        if ln.lstrip().startswith(('static ', 'typedef ', 'friend ')):
            continue
        m = FLD.match(ln)
        if not m:
            continue
        ty, nm, arr = m.group(1).strip(), m.group(2), m.group(3)
        if ty in ('public', 'private', 'protected', 'return', 'typedef'):
            continue
        n = int(arr.strip('[]'), 0) if arr else 1
        if arr and not arr.strip('[]').lower().startswith('0x'):
            n = int(arr.strip('[]'), 16) if re.search('[A-Fa-f]', arr) else int(arr.strip('[]'))
        if re.match(r'^(?:field|pad)_', nm) and not re.match(r'^(?:field|pad)_[0-9A-F]+$', nm):
            continue
        om = re.match(r'^(?:field|pad)_([0-9A-F]+)$', nm)
        off = int(om.group(1), 16) if om else cursor
        if nm.startswith('pad_'):
            cursor = off + n
            continue
        kind, size = b3_kind(ty)
        if size == 0:
            size = 4
        cursor = off + size * n
        cur.extent = max(cur.extent, cursor)
        cur.fields.append((off, ty, nm, n))
    return out


# ---------------------------------------------------------------- B3 AST names (independent B3 evidence)
def ast_names():
    """Identifiers in B3's own assert expressions (build E .AST files, wiki clone, git-ignored); a Revenge
    member name that also occurs there is used by Criterion's B3 code too."""
    out = set()
    d = os.path.join(ROOT, 'research', 'burnout3-symbols', 'data', 'burnout3-prototype', 'maps')
    for fn in ('B3DEBUG.AST.txt', 'B3INTERN.AST.txt'):
        try:
            for ln in open(os.path.join(d, fn), encoding='utf-8', errors='replace'):
                out.update(re.findall(r'\b[a-z]{1,3}[A-Z]\w*', ln))
        except OSError:
            pass
    return out


# ---------------------------------------------------------------- usage counts
def usage_counts(classes):
    """Attribute every `field_<OFF>` token in src/b3 + src/nonmatching to the classes whose definition is in
    scope of its file: classes/structs defined in the file itself plus those of #included b3 headers. A token
    whose name is defined by k in-scope types counts 1/k for each (so struct-local fields are not credited to
    an unrelated class). Returns (total tokens, {class: Counter(name -> weighted uses)})."""
    hdr_defs = {}          # header basename -> {type: set(field names)}
    for p in glob.glob(os.path.join(ROOT, 'include', 'b3', '**', '*.h'), recursive=True):
        hdr_defs[os.path.basename(p)] = {k: {f[2] for f in v.fields} for k, v in parse_b3_header(p).items()}
    total = 0
    per_class = defaultdict(Counter)
    pat = re.compile(r'\bfield_([0-9A-F]+)\b')
    inc = re.compile(r'#include\s+"[^"]*?([\w.]+\.h)"')
    for d in ('src/b3', 'src/nonmatching'):
        for dp, _, fs in os.walk(os.path.join(ROOT, d)):
            for f in fs:
                if not f.endswith(('.cpp', '.c', '.h')):
                    continue
                p = os.path.join(dp, f)
                try:
                    txt = open(p, encoding='utf-8', errors='replace').read()
                except OSError:
                    continue
                uses = Counter(pat.findall(txt))
                if not uses:
                    continue
                total += sum(uses.values())
                scope = {}
                for h in inc.findall(txt):
                    for k, names in hdr_defs.get(h, {}).items():
                        scope.setdefault(k, set()).update(names)
                for k, v in parse_b3_header(p).items():
                    scope.setdefault(k, set()).update(x[2] for x in v.fields)
                for off, n in uses.items():
                    nm = 'field_' + off
                    owners = [k for k, names in scope.items() if nm in names]
                    for k in owners:
                        if k in classes:
                            per_class[k][nm] += n / len(owners)
    return total, per_class


# ---------------------------------------------------------------- align
def poisson_tail(lam, v):
    """P(X >= v) for X ~ Poisson(lam)."""
    if lam <= 0:
        return 0.0
    term = math.exp(-lam)
    cdf = 0.0
    for k in range(v):
        cdf += term
        term *= lam / (k + 1)
    return max(0.0, 1.0 - cdf)


def significant(votes, thr):
    """Deltas with >= thr votes (thr = empirical family-wise null threshold, see main)."""
    sig = {d: v for d, v in votes.items() if v >= thr}
    # shadow votes: byte/short fields also match 1-3 bytes away from a stronger delta; drop those
    for d in sorted(sig, key=lambda x: (-sig[x], abs(x))):
        if d in sig:
            for e in list(sig):
                if e != d and abs(e - d) <= 3 and sig[e] <= sig[d]:
                    del sig[e]
    return sig


def compat(bk, rk):
    if bk is None or rk is None:
        return False
    if bk == rk:
        return True
    if bk.startswith('S:') and rk.startswith('S:'):
        return re.sub('CB3', 'CB4', bk) == rk
    return False


def hx(n):
    return '0x%X' % n if n >= 0 else '-0x%X' % -n


def main(argv):
    quiet = '--quiet' in argv
    control = '--control' in argv      # negative control: shuffle each class's field types among its offsets
    rev = Rev()
    b3 = {}
    srcfiles = sorted(glob.glob(os.path.join(ROOT, 'include', 'b3', '**', '*.h'), recursive=True)) + \
        sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.cpp'), recursive=True)) + \
        sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.h'), recursive=True))
    for p in srcfiles:
        try:
            got = parse_b3_header(p)
        except OSError:
            continue
        for k, v in got.items():
            if not (re.sub('CB3', 'CB4', k) in rev.structs or k in rev.structs):
                continue
            if k not in b3:
                b3[k] = v
                v.srcs = {os.path.relpath(p, ROOT)}
            else:
                have = {(o, b3_kind(t)[0]) for o, t, n, c in b3[k].fields}
                for fl in v.fields:
                    if (fl[0], b3_kind(fl[1])[0]) not in have:
                        b3[k].fields.append(fl)
                        have.add((fl[0], b3_kind(fl[1])[0]))
                b3[k].extent = max(b3[k].extent, v.extent)
                b3[k].methods |= v.methods
                b3[k].srcs.add(os.path.relpath(p, ROOT))
    total_uses, per_class = usage_counts(set(b3))
    astn = ast_names()
    rows, pairs = [], []
    unpaired = []
    rng = random.Random(12345)
    for name in sorted(b3):
        c = b3[name]
        if control:
            tys = [(t, n) for o, t, nm, n in c.fields]
            rng.shuffle(tys)
            c.fields = [(f[0], t, f[2], n) for f, (t, n) in zip(c.fields, tys)]
        cands = [re.sub('CB3', 'CB4', name), name]
        rname = next((x for x in cands if x in rev.structs and rev.structs[x].size), None)
        if not rname:
            unpaired.append(name)
            continue
        rst = rev.structs[rname]
        leaves = rev.leaves(rname)
        fields = []
        for off, ty, nm, n in c.fields:
            kind, size = b3_kind(ty)
            if kind is None:
                continue
            fields.append((off, ty, nm, n, kind, size))
        by_kind = defaultdict(list)
        for lf in leaves:
            by_kind[lf[1]].append(lf)

        def lkey(k):
            return re.sub('CB3', 'CB4', k) if k.startswith('S:') else k

        koffs = {k: [l[0] for l in v] for k, v in by_kind.items()}

        def tally(kinds_offs):
            v = Counter()
            for off, kind in kinds_offs:
                ds = set()
                for lo in koffs.get(lkey(kind), ()):
                    d = off - lo
                    if -0x2000 <= d <= 0x2000:
                        ds.add(d)
                v.update(ds)
            return v
        votes = tally([(f[0], f[4]) for f in fields])
        # empirical null: shuffle the kinds among the same offsets; threshold = max votes at any delta
        # in >5% of shuffles (family-wise), at least 3
        nulls = []
        nrng = random.Random(zlib.crc32(name.encode()))
        ks = [f[4] for f in fields]
        for _ in range(NULL_TRIALS if len(fields) >= 2 else 0):
            nrng.shuffle(ks)
            tv = tally([(f[0], k) for f, k in zip(fields, ks)])
            nulls.append(max(tv.values()) if tv else 0)
        nulls.sort()
        thr = max(3, (nulls[int(0.95 * len(nulls)) - 1] + 1) if nulls else 3)
        sig = significant(votes, thr)
        ncheck = len(fields)
        meth_b3 = {m for m in c.methods}
        meth_r = {re.sub(r'\W', '', x) for x in []}
        # --- map fields
        mapped = []
        matched_at = defaultdict(list)       # delta -> offsets matched
        cand = {}
        ambiguous = 0
        for off, ty, nm, n, kind, size in fields:
            best = None
            ds_hit = set()
            for lf in leaves:
                if not compat(kind, lf[1]):
                    continue
                d = off - lf[0]
                if d in sig:
                    ds_hit.add(d)
                if d in sig and (best is None or (sig[d], -abs(d), -lf[8]) > (sig[best[0]], -abs(best[0]), -best[1][8])):
                    best = (d, lf)
            if best and any(dd != best[0] and sig[dd] >= 0.8 * sig[best[0]] for dd in ds_hit):
                ambiguous += 1                # periodic / repeated structure: two deltas explain it equally well
                best = None
            if best:
                cand[(off, nm, ty)] = best
        # one B3 offset per Revenge leaf: the better-supported delta wins (ties: smaller |delta|)
        owner = {}
        for key, (d, lf) in sorted(cand.items(), key=lambda kv: (-sig[kv[1][0]], abs(kv[1][0]), kv[0][0])):
            lk = (lf[6], lf[3])
            if lk in owner and owner[lk] != key[0]:
                cand[key] = None
            else:
                owner[lk] = key[0]
        cand = {k: v for k, v in cand.items() if v}
        for key, (d, lf) in cand.items():
            matched_at[d].append(key[0])
        # prefer, for equal offset, shallowest leaf (top-level member) -- done via depth tie-break above
        nL = nG = 0
        for off, ty, nm, n, kind, size in fields:
            b = cand.get((off, nm, ty))
            if not b:
                continue
            d, lf = b
            near = [o for o in matched_at[d] if o != off and abs(o - off) <= 0x100]
            allm = [o for o in matched_at[d] if o != off]
            if (d == 0 and len(allm) >= 3) or len(near) >= 2:
                tier = '[L]'
            else:
                tier = '[G]'
            leafname = lf[3]
            evid = 'delta %s votes %d/%d fields; %s' % (hx(d), sig[d], ncheck,
                    'leaf of %s.%s@%s' % (lf[6], lf[4], hx(lf[7])) if lf[8] or '.' in leafname or '[' in leafname else
                    'direct member of %s' % lf[6])
            if lf[8] and not leafname.startswith(lf[4]):
                pass
            base_nm = re.split(r'[.\[]', leafname)[-1] if False else re.sub(r'\[\d+\]$', '', leafname.split('.')[-1])
            if base_nm in astn:
                evid += '; name also an identifier in B3 AST asserts (not discriminating: base rate similar)'
            rows.append((name, hx(off), nm, ty + ('[%d]' % n if n > 1 else ''), rname, leafname, lf[5], tier, evid,
                         round(per_class[name].get(nm, 0), 1) if nm.startswith('field_') else 0))
            if tier == '[L]':
                nL += 1
            else:
                nG += 1
        # --- alignment kind
        if not fields:
            kindname = 'none'
        elif not sig:
            kindname = 'none'
        elif set(sig) == {0}:
            kindname = 'identical' if (c.extent and abs(c.extent - rst.size) < 0x10 and sig[0] >= 0.5 * ncheck) else 'prefix-identical'
        elif 0 in sig and len(sig) == 1:
            kindname = 'prefix-identical'
        else:
            kindname = 'shifted'
        dtxt = ','.join('%s:%d' % (hx(d), v) for d, v in sorted(sig.items(), key=lambda x: -x[1])[:4])
        note = 'fields %d, extent %s; deltas {%s}; ambiguous-dropped %d' % (ncheck, hx(c.extent), dtxt, ambiguous)
        if rname != re.sub('CB3', 'CB4', name) and rname == name:
            note += '; same-name pairing'
        pairs.append((name, rname, hx(c.extent) + '+', hx(rst.size), kindname, nL + nG, note,
                      round(sum(per_class[name].values()), 1)))
    merged = {}
    for r in rows:
        k = (r[0], r[1], r[5])
        if k in merged:
            if r[3] not in merged[k][3].split(' | '):
                merged[k] = merged[k][:3] + (merged[k][3] + ' | ' + r[3],) + merged[k][4:]
        else:
            merged[k] = r
    rows = list(merged.values())
    byoff = defaultdict(list)
    for i, r in enumerate(rows):
        byoff[(r[0], r[1])].append(i)
    for idxs in byoff.values():
        if len(idxs) > 1:           # one offset, several Revenge candidates (type variants in different units)
            for i in idxs:
                r = list(rows[i])
                r[7] = '[G]'
                r[8] += '; CONFLICT: %d candidates at this offset' % len(idxs)
                rows[i] = tuple(r)
    if control:
        print('CONTROL rows', len(rows), Counter(r[7] for r in rows), Counter(p[4] for p in pairs))
        return 0
    os.makedirs(OUT, exist_ok=True)
    with open(os.path.join(OUT, 'revenge_member_map.tsv'), 'w') as f:
        f.write('\t'.join(['b3_class', 'b3_offset', 'b3_current_name', 'b3_type', 'revenge_class', 'revenge_member',
                           'revenge_type', 'tier', 'evidence', 'field_uses_in_class_sources']) + '\n')
        for r in rows:
            f.write('\t'.join(str(x) for x in r) + '\n')
    with open(os.path.join(OUT, 'revenge_class_pairs.tsv'), 'w') as f:
        f.write('\t'.join(['b3_class', 'revenge_class', 'b3_size(min extent)', 'revenge_size', 'alignment',
                           'members_mapped', 'notes', 'field_uses']) + '\n')
        for r in sorted(pairs, key=lambda x: -x[7]):
            f.write('\t'.join(str(x) for x in r) + '\n')
    # ---- summary
    mapped_uses = sum(r[9] for r in rows)
    class_uses = sum(sum(per_class[n].values()) for n in b3 if n in per_class)
    byc = defaultdict(lambda: [0, 0, 0])
    for r in rows:
        byc[r[0]][0] += 1
        byc[r[0]][1] += r[9]
        byc[r[0]][2] += (r[7] == '[L]')
    with open(os.path.join(OUT, 'revenge_member_map.md'), 'w') as f:
        f.write('# Revenge member map -- summary (generated by tools/revenge_member_map.py)\n\n')
        f.write('- classes paired: %d; alignment kinds: %s\n' % (len(pairs), dict(Counter(p[4] for p in pairs))))
        f.write('- members mapped: %d ([L] %d, [G] %d)\n' % (len(rows), sum(r[7] == '[L]' for r in rows), sum(r[7] == '[G]' for r in rows)))
        f.write('- `field_` token uses in src/b3 + src/nonmatching: %d total; %.0f attributed to a paired class '
                '(attributed to a paired class by in-scope definitions, weighted 1/k); mapped rows cover %d uses (%.1f%% of all, %.1f%% of class-attributable)\n'
                % (total_uses, class_uses, mapped_uses, 100.0 * mapped_uses / max(1, total_uses),
                   100.0 * mapped_uses / max(1, class_uses)))
        f.write('- negative control (kinds shuffled among offsets, same code): see `--control`\n\n')
        f.write('| class | mapped | uses covered | [L] |\n|---|---|---|---|\n')
        for k, v in sorted(byc.items(), key=lambda x: -x[1][1])[:30]:
            f.write('| %s | %d | %d | %d |\n' % (k, v[0], v[1], v[2]))
    if not quiet:
        print('classes in B3 headers', len(b3), 'paired', len(pairs), 'unpaired', len(unpaired))
        print('rows', len(rows), Counter(r[7] for r in rows))
        print(Counter(p[4] for p in pairs))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
