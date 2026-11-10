"""hdr_consolidate.py [--exclude FILE] [--apply]: merge the per-file class/struct/enum declarations of the lifted units
(src/b3/_unclassified/*.cpp, tools/tiny_lift.py's output) into one shared header per type, include/b3/classes/<Type>.h.

Shared ("global-keyed") types: named classes/structs/enums, and `UnkStruct_D_XXXXXXXX` (a global's type, keyed by its
address). A file-local placeholder (`UnkStruct_<addr>_<n>`) that sits in a shared type's field (pointee or array
element) is unified with every other file's placeholder in that same field and moves into the header of the first
shared type that reaches it; the lowest-named placeholder names the merged type. Field offsets come from the names
(`field_X` / `pad_X`, docs/conventions.md placeholders), so merged layouts keep every offset; a merged type is as large as its
largest view.

Files are merged one at a time in address order. A file whose view clashes structurally (overlapping fields, a field
of another size at the same offset, two named classes in one slot, a method or virtual slot with another return type)
is left out whole: it keeps its own declarations. Same-size type disagreements (int / unsigned int / float / void *,
pointer vs int) keep the first view; build/hc/verify.sh then recompiles every adopting file and compares it with
build/mw/<unit>.o, and --exclude lists the files that changed for the next round.

Output: build/hc/src/<file>.cpp (rewritten units), build/hc/include/b3/classes/*.h, build/hc/adopted.txt,
build/hc/report.txt. --apply copies them into src/ and include/."""
import copy
import os
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "src" / "b3" / "_unclassified"
OUT = ROOT / "build" / "hc"
HDIR = "b3/classes"

SIZES = {"int": 4, "unsigned int": 4, "short": 2, "unsigned short": 2, "signed short": 2, "char": 1,
         "signed char": 1, "unsigned char": 1, "bool": 1, "float": 4, "long": 8, "unsigned long": 8,
         "long long": 8, "unsigned long long": 8, "u_long128": 16, "void": 1,
         # external types from include/b3/GtMathPs2.h (tiny_lift's aggregate copies and VU0 layer): not ours to merge
         "GtMathPs2::CGtV3d": 16, "GtMathPs2::CGtV4d": 16}
WORD4 = {"int", "unsigned int", "float", "void *"}


class Clash(Exception):
    pass


class Unparsed(Exception):
    pass


def is_shared(name):
    """Named types and global-keyed placeholders (`UnkStruct_D_<addr>`, `UnkStruct_<global name>`) are shared; a
    placeholder keyed by the function that declares it (`UnkStruct_<addr>`, `UnkStruct_<addr>_<n>`,
    `UnkStruct_func_<addr>`) is file-local."""
    return not re.fullmatch(r"UnkStruct_([0-9A-F]{8}(_\w+)?|func_\w+)", name)


def is_builtin(base):
    return base in SIZES or base.startswith("E") and False


def split_type(t):
    """'Foo * *' -> ('Foo', 2)."""
    t = t.strip()
    stars = t.count("*")
    base = t.replace("*", " ").split()
    base = " ".join(base)
    return base, stars


def norm_params(pl):
    """A method's parameter list without parameter names (p0, n1, ...)."""
    if not pl.strip():
        return ""
    out = []
    depth, cur = 0, ""
    for ch in pl:
        if ch == "," and depth == 0:
            out.append(cur)
            cur = ""
            continue
        depth += (ch in "(<") - (ch in ")>")
        cur += ch
    out.append(cur)
    res = []
    for p in out:
        p = p.strip()
        p = re.sub(r"\s*\b[pnf]\d+$", "", p)
        res.append(re.sub(r"\s+", " ", p))
    return ", ".join(res)


METH = re.compile(r"^(?P<pre>(?:static |virtual )*)(?P<rt>.*?)\b(?P<name>~?[A-Za-z_]\w*)\((?P<pl>.*)\)(?P<post>( const)?)$")


def meth_key(decl):
    m = METH.match(decl.strip())
    if not m:
        raise Unparsed("method %r" % decl)
    return (m.group("pre").strip(), m.group("name"), norm_params(m.group("pl")), m.group("post").strip()), \
        m.group("rt").strip()


FIELD = re.compile(r"^    (?P<type>[\w:][\w: ]*?(?: ?\*)*) ?(?P<name>(?:field|pad)_(?P<off>[0-9A-F]+))(?P<arr>\[[^\]]*\])?;"
                   r"(?P<cmt>\s*//.*)?$")


class TypeDef:
    def __init__(self, name, kw):
        self.name, self.kw = name, kw
        self.fields = {}      # off -> [type, arr, cmt]
        self.size = 0
        self.methods = {}     # key -> decl text
        self.mret = {}        # key -> return type
        self.vptr = None      # offset
        self.vslots = {}      # slot -> decl
        self.complete = False
        self.padcmt = None    # comment of a trailing pad (size requirement)
        self.base = None      # `class X : public Base`
        self.defines = set()  # method keys whose definition is a unit's function

    def __repr__(self):
        return "<%s %s>" % (self.kw, self.name)


_hcache = {}


def header_view(name, seen=()):
    """A merged header's declarations (and those of the merged headers it includes), parsed as a unit's would be."""
    if name in _hcache:
        return _hcache[name]
    p = ROOT / "include" / HDIR / (name + ".h")
    if not p.exists() or name in seen:
        return None
    H = parse_file(p, header=True, seen=seen + (name,))
    _hcache[name] = H
    return H


def parse_file(path, header=False, seen=()):
    text = open(path, encoding="utf-8").read()
    lines = text.split("\n")
    F = {"path": path, "src": text, "head": [], "prelude": [], "fwd": [], "defs": {}, "order": [], "enums": [],
         "externs": [], "body": None, "hincl": [], "hdefs": set()}
    i = 0
    while i < len(lines) and lines[i].startswith("//") and not re.match(r"// 0x[0-9A-F]{8}$", lines[i]):
        F["head"].append(lines[i])
        i += 1
    while i < len(lines):
        ln = lines[i]
        if re.match(r"// 0x[0-9A-F]{8}$", ln):
            F["body"] = "\n".join(lines[i:])
            break
        if ln.startswith("//") and not header:
            # comment lines at the top level: a merged file's notes for its first function (kept with the body when
            # the function's marker follows them), otherwise dropped
            j = i
            while j < len(lines) and lines[j].startswith("//") and not re.match(r"// 0x[0-9A-F]{8}$", lines[j]):
                j += 1
            if j < len(lines) and re.match(r"// 0x[0-9A-F]{8}$", lines[j]):
                F["body"] = "\n".join(lines[i:])
                break
            i = j
            continue
        if not ln.strip() or header and (ln.startswith("//") or re.match(r"#(ifndef|define|endif)\b", ln)):
            i += 1
            continue
        m = re.match(r'^#include "%s/(\w+)\.h"$' % HDIR, ln)
        if m:
            F["hincl"].append(m.group(1))     # a merged header (an earlier run): its declarations are this view
            i += 1
            continue
        m = re.match(r"^(class|struct) ([\w]+);$", ln)
        if m:
            F["fwd"].append((m.group(1), m.group(2)))
            i += 1
            continue
        m = re.match(r"^enum (\w+) \{\};$", ln)
        if m:
            F["enums"].append(m.group(1))
            i += 1
            continue
        if ln.startswith("#include") or ln.startswith("typedef ") or ln.startswith("namespace "):
            F["prelude"].append(ln)
            i += 1
            continue
        m = re.match(r"^(class|struct) (\w+)(?: : public (\w+))? \{$", ln)
        if m:
            T = TypeDef(m.group(2), m.group(1))
            T.base = m.group(3)
            T.complete = True
            i += 1
            pos = 0
            while lines[i] != "};":
                b = lines[i]
                i += 1
                if b in ("public:", "") or b.startswith("    // vptr at"):
                    if b.startswith("    // vptr at"):
                        T.vptr = int(re.search(r"\+0x([0-9A-F]+)", b).group(1), 16)
                        pos = T.vptr + 4
                    continue
                mv = re.match(r"^    virtual (.*) vfunc_([0-9A-F]+)\((.*)\);$", b)
                if mv:
                    T.vslots[int(mv.group(2), 16)] = b.strip()[:-1]
                    continue
                mf = FIELD.match(b)
                if mf:
                    off = int(mf.group("off"), 16)
                    ty = mf.group("type").strip()
                    if mf.group("name").startswith("pad_"):
                        ma = re.match(r"\[(0x[0-9A-Fa-f]+|\d+)\]", mf.group("arr") or "")
                        if not ma:      # pad with a multi-dimension / expression size: skip this file's type (rare)
                            raise Unparsed("unparsed pad size %r" % mf.group("arr"))
                        n = int(ma.group(1), 0)
                        pos = off + n
                        T.padcmt = (mf.group("cmt") or "").strip() or None
                        continue
                    T.fields[off] = [ty, mf.group("arr") or "", (mf.group("cmt") or "").strip()]
                    T.padcmt = None
                    pos = off + 1     # real size is resolved after parsing (the size table)
                    T.fields[off].append(None)
                    continue
                if b.startswith("    ") and b.endswith(";") and "(" in b:
                    k, rt = meth_key(b.strip()[:-1])
                    T.methods[k] = b.strip()[:-1]
                    T.mret[k] = rt
                    continue
                if re.match(r"^    static [^()]+ \**\w+;$", b):
                    k = ("static-member", b.strip())
                    T.methods[k] = b.strip()[:-1]
                    T.mret[k] = ""
                    continue
                raise Unparsed("line %r in %s" % (b, T.name))
            T.size = pos      # provisional (fields sized later)
            T._pos_raw = pos
            F["defs"][T.name] = T
            F["order"].append(T.name)
            i += 1
            continue
        if ln.startswith('extern "C" ') or ln.startswith("extern "):
            F["externs"].append(ln)
            i += 1
            continue
        raise Unparsed("top-level line %r" % ln)
    F["hprelude"] = []
    for h in F["hincl"]:
        H = header_view(h, seen)
        if H is None:
            raise Unparsed("missing merged header %s" % h)
        for n, T in H["defs"].items():
            if n not in F["defs"]:
                F["defs"][n] = copy.deepcopy(T)
                F["hdefs"].add(n)
        F["enums"] += [e for e in H["enums"] if e not in F["enums"]]
        F["fwd"] += [x for x in H["fwd"] if x not in F["fwd"]]
        F["hprelude"] += [x for x in H["prelude"] + H["hprelude"] if x not in F["hprelude"]]
    if header:
        return F
    if F["body"] is None:
        raise Unparsed("no function body")
    for m in re.finditer(r"^// 0x[0-9A-F]{8}\n(.*?)\n\{", F["body"], re.S | re.M):   # every function (merged files)
        mm = re.match(r"^.*?\b(\w+)::(~?\w+)\((.*)\)( const)?$", m.group(1))
        if mm and mm.group(1) in F["defs"]:
            T = F["defs"][mm.group(1)]
            for k in T.methods:
                if k[0] != "static-member" and \
                        k[1:] == (mm.group(2), norm_params(mm.group(3)), (mm.group(4) or "").strip()):
                    T.defines.add(k)
    return F


def tsize(t, arr, defs, stack=()):
    base, stars = split_type(t)
    if stars:
        n = 4
    elif base in SIZES:
        n = SIZES[base]
    elif base in defs:
        n = struct_size(defs[base], defs, stack)
    elif base.startswith("E"):
        n = 4                  # an enum
    else:
        n = 1                  # an empty / incomplete class by value (tiny_lift's convention)
    m = re.match(r"\[(\d+)\]", arr or "")
    return n * (int(m.group(1)) if m else 1)


def talign(t, defs):
    base, stars = split_type(t)
    if stars:
        return 4
    if base in SIZES:
        return min(SIZES[base], 16)
    if base in defs:
        return max([talign(f[0], defs) for f in defs[base].fields.values()] + [4 if defs[base].vptr is not None else 1])
    return 4 if base.startswith("E") else 1


def struct_size(T, defs, stack=()):
    if T.name in stack:
        raise Clash("type contains itself")
    end = T._pos_raw if hasattr(T, "_pos_raw") else 0
    for off, f in T.fields.items():
        end = max(end, off + tsize(f[0], f[1], defs, stack + (T.name,)))
    if T.vptr is not None:
        end = max(end, T.vptr + 4)
    return max(end, T.size if T.complete else 0, 1 if not T.fields and T.vptr is None else 0)


# ---------------------------------------------------------------------------------------------------------------------
class Model:
    def __init__(self):
        self.parent = {}
        self.defs = {}         # root -> merged TypeDef
        self.enums = set()
        self.files = []

    def find(self, t):
        while self.parent.get(t, t) != t:
            t = self.parent[t]
        return t

    def ensure(self, name, kw="struct"):
        r = self.find(name)
        if r not in self.defs:
            T = TypeDef(r, kw)
            self.defs[r] = T
            self.parent[r] = r
        return self.find(name)

    def union(self, a, b, fdefs):
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return ra
        sa, sb = is_shared(ra), is_shared(rb)
        if sa and sb:
            raise Clash("two named types in one slot: %s / %s" % (ra, rb))
        if sb or (not sa and rb < ra):
            ra, rb = rb, ra          # ra is the surviving name
        Tb = self.defs.pop(rb)
        self.parent[rb] = ra
        self.merge_def(ra, Tb, fdefs)
        return ra

    def unify_field(self, cur, new, fdefs):
        """cur, new: [type, arr, cmt, by-value size]; returns the merged field (may raise Clash). The 4th entry is the
        size a by-value struct field had in the unit it came from: every view must agree and keep it."""
        vs = cur[3] if cur[3] is not None else new[3]
        if cur[3] is not None and new[3] is not None and cur[3] != new[3]:
            if cur[1] or new[1]:
                raise Clash("array element sizes 0x%X / 0x%X" % (cur[3], new[3]))
            vs = max(cur[3], new[3])
        if cur[0] == new[0] and cur[1] == new[1]:
            return [cur[0], cur[1], cur[2], vs]
        bc, sc = split_type(cur[0])
        bn, sn = split_type(new[0])
        if (cur[1] or "") != (new[1] or ""):
            raise Clash("array vs scalar")
        if sc == sn and sc > 0 and not (bc in SIZES or bn in SIZES):
            r = self.union(bc, bn, fdefs)
            return [r + " " + "*" * sc, cur[1], cur[2], vs]
        if sc == sn and sc == 0 and bc not in SIZES and bn not in SIZES and not bc.startswith("E") and \
                not bn.startswith("E"):
            r = self.union(bc, bn, fdefs)            # by value (array elements, embedded)
            return [r, cur[1], cur[2], vs]
        if sc > 0 and sn == 0 and bn in ("int", "unsigned int") or sc > 0 and new[0] == "void *":
            return cur
        if sn > 0 and sc == 0 and bc in ("int", "unsigned int") or sn > 0 and cur[0] == "void *":
            if sn > 0 and bn not in SIZES:
                self.ensure(bn)
            return [new[0], new[1], new[2], vs]
        if sc == sn and sc > 0:
            return cur                               # builtin pointers of another type: keep the first view
        if cur[0] in WORD4 and new[0] in WORD4:
            return cur
        if sc == sn == 0 and bc in SIZES and bn in SIZES and SIZES[bc] == SIZES[bn]:
            return cur
        raise Clash("field types %s / %s" % (cur[0], new[0]))

    def merge_def(self, root, T, fdefs):
        M = self.defs[self.find(root)]
        if T.kw == "class":
            M.kw = "class"
        if T.base:
            if M.base and M.base != T.base:
                raise Clash("base classes %s / %s" % (M.base, T.base))
            M.base = T.base
            if T.base not in self.parent:
                self.ensure(T.base, "class")
        if T.vptr is not None:
            if M.vptr is not None and M.vptr != T.vptr:
                raise Clash("vptr offsets")
            M.vptr = T.vptr
        for sl, d in T.vslots.items():
            if sl in M.vslots and M.vslots[sl] != d:
                rt1 = re.match(r"virtual (.*) vfunc_", M.vslots[sl]).group(1)
                rt2 = re.match(r"virtual (.*) vfunc_", d).group(1)
                if rt1 != rt2 and rt1 == "void":
                    M.vslots[sl] = d
                elif rt1 != rt2 and rt2 != "void":
                    raise Clash("virtual slot %X return types" % sl)
                continue
            M.vslots[sl] = d
        for k, d in T.methods.items():
            if k in M.methods:
                if M.mret[k] != T.mret[k]:
                    # the defining unit's return type wins; a caller's guess of `void` (result unused) yields
                    if k in T.defines and k not in M.defines or (k not in M.defines and M.mret[k] == "void"):
                        M.methods[k], M.mret[k] = d, T.mret[k]
                    elif not (k in M.defines or T.mret[k] == "void"):
                        raise Clash("method %s return types %s / %s" % (k[1], M.mret[k], T.mret[k]))
                if k in T.defines:
                    M.defines.add(k)
                continue
            M.methods[k] = d
            M.mret[k] = T.mret[k]
            if k in T.defines:
                M.defines.add(k)
        if T.complete:
            M.complete = True
            M.size = max(M.size, T.size, getattr(T, "_size", 0))
            if T.padcmt and not M.padcmt:
                M.padcmt = T.padcmt
        for off, f in sorted(T.fields.items()):
            f = [self.canon_type(f[0]), f[1], f[2], f[3] if len(f) > 3 else None]
            bn, sn = split_type(f[0])
            if bn not in SIZES and not bn.startswith("E") and bn not in self.parent:
                self.ensure(bn)
            M = self.defs[self.find(root)]
            if off in M.fields:
                M.fields[off] = self.unify_field(M.fields[off], f, fdefs)
            else:
                M.fields[off] = f

    def canon_type(self, t):
        b, s = split_type(t)
        if b in SIZES or b.startswith("E") and b in self.enums:
            return t
        if b in self.parent:
            b = self.find(b)
        return b + (" " + "*" * s if s else "")

    def check_layout(self, root):
        M = self.defs[root]
        end = 0
        for off in sorted(M.fields):
            f = M.fields[off]
            if M.vptr is not None and off < M.vptr + 4 and off + 1 > M.vptr:
                raise Clash("field over the vptr")
            if off < end:
                raise Clash("overlapping fields at +0x%X in %s" % (off, root))
            sz = tsize(self.canon_type(f[0]), f[1], self.defs)
            # an array's element size is its stride (exact); an embedded object may grow if nothing overlaps it
            if f[3] is not None and sz != f[3] and (f[1] or sz < f[3]):
                raise Clash("by-value field +0x%X of %s grew 0x%X -> 0x%X" % (off, root, f[3], sz))
            end = off + sz
            if off % min(talign(f[0], self.defs), 8):
                raise Clash("misaligned +0x%X" % off)

    def check_all(self):
        for r in list(self.defs):
            if self.find(r) == r:
                self.check_layout(r)

    def add_file(self, F):
        """Merge one parsed file's shared-type views (and the placeholders they reach)."""
        fdefs = F["defs"]
        for t in F["enums"]:
            self.enums.add(t)
        # the placeholders this file reaches from a shared type through fields
        reach, work = set(), [n for n in fdefs if is_shared(n)]
        reach.update(work)
        while work:
            n = work.pop()
            for f in fdefs[n].fields.values():
                b, s = split_type(f[0])
                if b in fdefs and b not in reach:
                    reach.add(b)
                    work.append(b)
        F["reach"] = reach
        for n in reach:
            for f in fdefs[n].fields.values():
                b, s = split_type(f[0])
                byval = not s and b not in SIZES and not b.startswith("E")
                f[3] = tsize(f[0], f[1], fdefs) if byval else None
        for n in sorted(reach, key=lambda x: not is_shared(x)):
            T = fdefs[n]
            T._size = struct_size(T, fdefs)
            if n not in self.parent:
                self.parent[n] = n
                self.defs[n] = TypeDef(n, T.kw)
            self.merge_def(n, T, fdefs)
        for kw, n in F["fwd"]:
            if is_shared(n) and n not in self.parent:
                self.parent[n] = n
                self.defs[n] = TypeDef(n, kw)
            elif is_shared(n) and not self.defs[self.find(n)].complete:
                self.defs[self.find(n)].kw = kw
        self.check_all()        # a type that grew may no longer fit where another type holds it by value


# ---------------------------------------------------------------------------------------------------------------------
def emit_headers(M):
    """root type -> header text; also the owner header of every placeholder root."""
    owner = {}
    shared = sorted(r for r in M.defs if is_shared(r))
    for r in shared:
        owner[r] = r
    # placeholders: BFS from shared types in name order
    for r in shared:
        work = [r]
        while work:
            n = work.pop(0)
            for f in M.defs[n].fields.values():
                b, s = split_type(M.canon_type(f[0]))
                b = M.find(b) if b in M.parent else b
                if b in M.defs and b not in owner:
                    owner[b] = r
                    work.append(b)
    hdrs = {}
    for r in shared:
        mine = [n for n in owner if owner[n] == r]
        hdrs[r] = (mine, owner)
    return hdrs, owner


def canon_text(M, d):
    """A declaration with every merged placeholder's name replaced by the surviving one."""
    return re.sub(r"\bUnkStruct_\w+", lambda m: M.find(m.group(0)) if m.group(0) in M.parent else m.group(0), d)


def type_text(M, n):
    T = M.defs[n]
    out = []
    lay, pos = [], 0
    items = sorted(T.fields.items())
    if T.vptr is not None:
        items = sorted(items + [(T.vptr, None)], key=lambda x: x[0])
    for off, f in items:
        if f is None:
            if off > pos:
                lay.append("    unsigned char pad_%X[0x%X];" % (pos, off - pos))
            lay.append("    // vptr at +0x%X: placeholder virtuals by slot offset (names not in any table) [G]" % off)
            for sl in sorted(T.vslots):
                lay.append("    %s;" % canon_text(M, T.vslots[sl]))
            pos = off + 4
            continue
        ty = M.canon_type(f[0])
        if off > pos:
            lay.append("    unsigned char pad_%X[0x%X];" % (pos, off - pos))
        sep = "" if ty.endswith("*") else " "
        lay.append("    %s%sfield_%X%s;%s" % (ty, sep if not ty.endswith("*") else " ", off, f[1],
                                               ("  " + f[2]) if f[2] else ""))
        pos = off + tsize(ty, f[1], M.defs)
    size = max(T.size, pos)
    if size > pos:
        lay.append("    unsigned char pad_%X[0x%X];%s" % (pos, size - pos, ("  " + T.padcmt) if T.padcmt else ""))
    if not lay and not T.methods and not T.complete:
        return None
    out.append("%s %s%s {" % (T.kw, n, " : public %s" % T.base if T.base else ""))
    if T.methods:
        out.append("public:")
        for k in sorted(T.methods, key=lambda k: (k[0] != "static-member", repr(k))):
            out.append("    %s;" % canon_text(M, T.methods[k]))
        if lay:
            out.append("")
    out += lay
    out.append("};")
    return out


def deps(M, n):
    """(by-value dependencies, pointer / mentioned type names) of type n's text."""
    T = M.defs[n]
    byval, ptr = set(), set()
    if T.base:
        byval.add(T.base)
    for f in T.fields.values():
        b, s = split_type(M.canon_type(f[0]))
        if b in SIZES:
            continue
        (ptr if s else byval).add(b)
    for d in [canon_text(M, x) for x in list(T.methods.values()) + list(T.vslots.values())]:
        for w in re.findall(r"\b([A-Z]\w+)\b", d):
            ptr.add(w)
    return byval, ptr


def guard(n):
    return "B3_CLASSES_%s_H" % re.sub(r"\W", "_", n).upper()


def write_headers(M, hdrs, owner, prelude_for):
    os.makedirs(OUT / "include" / HDIR, exist_ok=True)
    texts = {}
    for r, (mine, _) in hdrs.items():
        lines = ["// %s -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py)." % r,
                 "// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets",
                 "// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.",
                 "#ifndef %s" % guard(r), "#define %s" % guard(r), ""]
        incl, fwd, loose = set(), set(), set()
        bodies = []
        order, done = [], set()

        def visit(n, stack=()):
            if n in done or n in stack:
                return
            bv, _ = deps(M, n)
            for b in sorted(bv):
                b = M.find(b) if b in M.parent else b
                if b in mine and b != n:
                    visit(b, stack + (n,))
            done.add(n)
            order.append(n)
        for n in sorted(mine, key=lambda x: (x == r, x)):
            visit(n)
        for n in order:
            bv, pt = deps(M, n)
            for b in bv | pt:
                b = M.find(b) if b in M.parent else b
                if b in mine:
                    continue
                if b in owner:
                    if b in bv:
                        incl.add(owner[b])
                    else:
                        fwd.add(b)
                elif b in M.enums:
                    incl.add(b)
                elif b.startswith("UnkStruct_") and b not in M.defs:
                    loose.add(b)      # a unit's own placeholder named in a method signature: declared, not defined
            t = type_text(M, n)
            if t:
                bodies += t + [""]
            else:
                fwd.add(n)
        pre = set()
        for n in order:
            for p in prelude_for.get(n, ()):
                pre.add(p)
        all_text = "\n".join(bodies)
        pre_lines = sorted(p for p in pre if (("GtMathPs2" in p and "GtMathPs2::" in all_text) or
                                               ("u_long128" in p and "u_long128" in all_text) or
                                               ("namespace" in p and p.split()[1] + "::" in all_text) or
                                               (p.startswith("#include") and "GtMathPs2" not in p)))
        if "u_long128" in all_text and not any("u_long128" in p or "GtMathPs2" in p for p in pre_lines):
            pre_lines.append("typedef unsigned int u_long128 __attribute__((mode(TI)));")
        lines += pre_lines + ([""] if pre_lines else [])
        lines += ['#include "%s/%s.h"' % (HDIR, h) for h in sorted(incl) if h != r]
        if incl - {r}:
            lines.append("")
        fw = []
        for b in sorted(fwd | set(mine)):
            if b in M.defs:
                fw.append("%s %s;" % (M.defs[b].kw, b))
        fw += ["struct %s;" % b for b in sorted(loose)]
        lines += fw + ([""] if fw else [])
        lines += bodies
        lines += ["#endif", ""]
        texts[r] = "\n".join(lines)
    for e in sorted(M.enums):
        texts[e] = "\n".join(["// %s -- an enum named in a retail mangled symbol; values unknown (tools/hdr_consolidate.py)." % e,
                              "#ifndef %s" % guard(e), "#define %s" % guard(e), "", "enum %s {};" % e, "", "#endif", ""])
    return texts


def rewrite_file(F, M, owner):
    """The unit with its shared declarations replaced by includes; placeholder names canonical."""
    ren = {}
    for n in F["reach"]:
        r = M.find(n)
        if r != n:
            ren[n] = r
    drop = set(F["reach"]) | {n for _, n in F["fwd"] if is_shared(n) or M.find(n) in owner}
    hdr_needed = set()
    keep_defs = [n for n in F["order"] if n not in drop]
    body_parts = []
    for n in keep_defs:
        T = F["defs"][n]
        body_parts.append(n)
    text_after = []
    # keep-local type definitions, verbatim from the source
    src = F["src"]
    blocks = re.findall(r"^(?:class|struct) (\w+) \{\n.*?^\};\n", src, re.M | re.S)
    blocktext = {m.group(1): m.group(0) for m in re.finditer(r"^(?:class|struct) (\w+) \{\n.*?^\};\n", src,
                                                             re.M | re.S)}
    H = F["head"]
    shared_note = ["// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are",
                   "// placeholders and every type is [G] (instruction widths)."]
    if len(H) > 1 and H[1].startswith("// [C] name"):
        head = H[:2] + ["// Area not evidenced, so _unclassified/ (docs/conventions.md)."] + shared_note
    elif H and any("Unnamed in every table" in h for h in H):
        head = H[:1] + ["// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so",
                        "// _unclassified/. `self` is whatever a0 points to."] + shared_note
    else:
        head = list(H)
    out = head + [""]
    pre = [p for p in F["prelude"]]
    local_fwd = ["%s %s;" % (kw, n) for kw, n in F["fwd"] if n not in drop and M.find(n) not in owner]
    used_text = "\n".join([blocktext[n] for n in keep_defs] + F["externs"] + [F["body"]])

    def rn(s):
        for a, b in sorted(ren.items(), key=lambda x: -len(x[0])):
            s = re.sub(r"\b%s\b" % re.escape(a), b, s)
        return s
    used_text = rn(used_text)
    for w in set(re.findall(r"\b(\w+)\b", used_text)):
        if w in owner:
            hdr_needed.add(owner[w])
        elif w in M.enums:
            hdr_needed.add(w)
    for e in F["enums"]:
        hdr_needed.add(e)
    out += pre + ([""] if pre else [])
    out += ['#include "%s/%s.h"' % (HDIR, h) for h in sorted(hdr_needed)] + ([""] if hdr_needed else [])
    out += local_fwd + ([""] if local_fwd else [])
    for n in keep_defs:
        out.append(rn(blocktext[n]))
    out += [rn(x) for x in F["externs"]] + ([""] if F["externs"] else [])
    out.append(rn(F["body"]))
    t = "\n".join(out)
    t = re.sub(r"\n\n\n+", "\n\n", t)
    return t


def main():
    excl = set()
    if "--exclude" in sys.argv:
        p = sys.argv[sys.argv.index("--exclude") + 1]
        excl = {l.strip() for l in open(p) if l.strip()}
    files = set(SRC.glob("*.cpp"))
    tu = ROOT / "config" / "tu_units.txt"
    if tu.exists():      # regrouped translation units (tools/tu_merge.py), wherever their folder is
        files |= {ROOT / l.split()[0] for l in open(tu) if l.strip() and not l.startswith("#")}

    def first_addr(p):
        m = re.search(r"_([0-9A-F]{8})\.cpp$", p.name)
        if m:
            return m.group(1)
        m = re.search(r"^// 0x([0-9A-F]{8})$", open(p, encoding="utf-8").read(), re.M)
        return m.group(1) if m else p.name
    files = sorted(files, key=first_addr)
    parsed, report = [], []
    for p in files:
        try:
            parsed.append(parse_file(p))
        except Unparsed as e:
            report.append("UNPARSED %s: %s" % (p.name, e))
    M = Model()
    adopted, prelude_for = [], {}
    # Seed the model with every header already installed in include/b3/classes (2026-10-27): --apply replaces that
    # directory, and units that include a header but are not adopted this run (UNPARSED / EXCLUDED / CLASH: 136 of 697
    # includers on 2026-10-27) lost their types -- the ~85 units every run broke since cycle 20 (NO_HC). Seeding keeps
    # every installed view, so the new headers are a superset; hc_verify then checks all includers (build/hc/pinned.txt).
    if "--no-seed" not in sys.argv:
        for hp in sorted((ROOT / "include" / HDIR).glob("*.h")):
            try:
                H = header_view(hp.stem)
                if H is not None:
                    M.add_file(H)
                    for n in H.get("reach", ()):
                        prelude_for.setdefault(n, set()).update(H["prelude"] + H["hprelude"])
            except (Clash, Unparsed) as e:
                report.append("SEEDFAIL %s: %s" % (hp.name, e))
    for F in parsed:
        if F["path"].name in excl:
            report.append("EXCLUDED %s" % F["path"].name)
            continue
        if not any(is_shared(n) for n in F["defs"]) and not F["enums"] and \
                not any(is_shared(n) for _, n in F["fwd"]):
            report.append("NOSHARED %s" % F["path"].name)
            continue
        snap = copy.deepcopy(M)
        try:
            M.add_file(F)
            adopted.append(F)
            for n in F["reach"]:
                prelude_for.setdefault(n, set()).update(F["prelude"] + F["hprelude"])
        except Clash as e:
            M = snap
            report.append("CLASH %s: %s" % (F["path"].name, e))
    for n in list(prelude_for):
        r = M.find(n)
        prelude_for.setdefault(r, set()).update(prelude_for[n])
    hdrs, owner = emit_headers(M)
    texts = write_headers(M, hdrs, owner, prelude_for)
    if (OUT / "include").exists():
        shutil.rmtree(OUT / "include")
    if (OUT / "src").exists():
        shutil.rmtree(OUT / "src")
    os.makedirs(OUT / "include" / HDIR, exist_ok=True)
    os.makedirs(OUT / "src", exist_ok=True)
    frozen = 0
    for n, t in texts.items():
        # Freeze installed headers (2026-10-27): a header that already exists in include/b3/classes is kept byte-for-byte,
        # so the 100+ units that include it without being adopted this run (UNPARSED/EXCLUDED/CLASH) cannot change;
        # adopted units whose view disagrees with a frozen header fail hc_verify and hc_iterate excludes them.
        old_h = ROOT / "include" / HDIR / (n + ".h")
        if old_h.exists() and "--no-freeze" not in sys.argv:
            t = open(old_h, encoding="utf-8").read()
            frozen += 1
        open(OUT / "include" / HDIR / (n + ".h"), "w", encoding="utf-8", newline="\n").write(t)
    # keep installed headers the model no longer emits (their includers are not adopted this run)
    for old_h in (ROOT / "include" / HDIR).glob("*.h"):
        if not (OUT / "include" / HDIR / old_h.name).exists():
            shutil.copy(old_h, OUT / "include" / HDIR / old_h.name)
            frozen += 1
    with open(OUT / "adopted.txt", "w", newline="\n") as af:
        for F in adopted:
            t = rewrite_file(F, M, owner)
            open(OUT / "src" / F["path"].name, "w", encoding="utf-8", newline="\n").write(t)
            af.write(F["path"].name + "\n")
    open(OUT / "report.txt", "w").write("\n".join(report) + "\n")
    names = {F["path"].name for F in adopted}
    with open(OUT / "pinned.txt", "w", newline="\n") as pf:
        for p in sorted(files):
            if p.name not in names and '#include "b3/classes/' in open(p, encoding="utf-8", errors="replace").read():
                shutil.copy(p, OUT / "src" / p.name)
                pf.write(p.name + "\n")
    kinds = {}
    for r in report:
        kinds[r.split()[0]] = kinds.get(r.split()[0], 0) + 1
    print("files:", len(files), "parsed:", len(parsed), "adopted:", len(adopted), kinds)
    print("headers:", len(texts), "(shared types %d, enums %d), %d frozen as installed" % (len(hdrs), len(M.enums), frozen))
    if "--apply" in sys.argv:
        dst = ROOT / "include" / HDIR
        if dst.exists():
            shutil.rmtree(dst)
        shutil.copytree(OUT / "include" / HDIR, dst)
        for F in adopted:
            shutil.copy(OUT / "src" / F["path"].name, F["path"])
        print("applied")


if __name__ == "__main__":
    main()
