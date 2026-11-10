#!/usr/bin/env python3
"""c_linkage_check.py: extern "C" declarations whose prototype disagrees with the callee's own (decompfix, 2026-11-02).

C linkage carries no parameter types and MWCC accepts a call through any declaration (caller and callee meet only in
registers), so a caller may declare `extern "C" void f();` for a definition `f(T *self, int p0)`, or pass an `int`
where the callee reads a pointer, and the object still matches retail. A host build links the two sides directly and
breaks (port8, the port repo docs/decomp-on-host.md "Calls: port8 changes"; docs/known.md N294).

Truth per C name, in order: (1) a CodeWarrior-mangled link name's parameter list (`Release__14CGtSoundStreamFv`:
`this` + the mangled types), (2) the callee's own definition in src/b3 (proven) or src/nonmatching (archive). A
definition that disagrees with its mangled name is reported too (kind `def-vs-mangled`).

Kinds: P pointer/reference/array, I 32-bit integer (int, short, char, bool, enum), L 64-bit integer (long, long long,
u_long), Q 128-bit (u_long128), F float, S struct/class by value, ? unresolved typedef (never reported), V void return.

Usage (repo root):  python3 -I tools/c_linkage_check.py [--all]
  rows, one per (declaring file, callee), TSV: callee  class  file:line  declared  truth  truth-source
  classes: kind-IP / kind-IL (a pointer or 64-bit argument declared int on one side), fewer / more (the declaration
  passes fewer / more argument registers than the callee takes), ret-callee-void (the caller reads a result the
  definition does not return), ret-caller-void (the caller ignores a result: harmless), def-* (a definition against
  its own mangled name).
  --all also reports return-type differences where neither side is void (e.g. int vs bool), which do not change
  registers; by default only void-vs-value returns and parameter differences are rows.
Exit 0 always; the row count goes to stderr."""
import glob, os, re, sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))

# ---- types ----------------------------------------------------------------------------------------------------------
INT32 = {"int", "short", "char", "bool", "unsigned", "signed", "wchar_t", "u_int", "u_short", "u_char", "size_t"}
INT64 = {"long", "u_long", "u_long64", "long64"}
TYPEDEF = {}     # name -> kind
AGG = set()      # struct/class/union names (by value: S)
ENUMS = set()


def strip(txt):
    """drop comments and string literals (keeping "C" and line structure)"""
    txt = re.sub(r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", " ", m.group(0)), txt, flags=re.S)
    txt = re.sub(r"//[^\n]*", "", txt)
    txt = re.sub(r'"(?:\\.|[^"\\\n])*"', lambda m: '"C"' if m.group(0) == '"C"' else '""', txt)
    txt = re.sub(r"'(?:\\.|[^'\\\n])'", "0", txt)
    return txt


def kind(t):
    t = re.sub(r"\s+", " ", t.strip())
    t = re.sub(r"\b(register|static|inline|extern|virtual|friend|const|volatile|struct|class|union|enum|typename)\b",
               " ", t)
    t = re.sub(r"\s+", " ", t).strip()
    if not t or t == "...":
        return t or "?"
    if "*" in t or "&" in t or "[" in t or "(" in t:
        return "P"
    if t == "void":
        return "V"
    w = t.split()
    if "long" in w and w.count("long") >= 1 and "double" not in w:
        return "L"
    if t in ("float", "double", "ps2f", "long double"):
        return "F"
    if t == "u_long128" or t == "__int128":
        return "Q"
    if all(x in INT32 or x in ("signed", "unsigned", "int") for x in w):
        return "I"
    if t in INT64:
        return "L"
    if "::" in t:
        t = t.split("::")[-1]
    if t in TYPEDEF:
        return TYPEDEF[t]
    if t in ENUMS:
        return "I"
    if t in AGG:
        return "S"
    if re.match(r"^(Unk)?Enum_|^E[A-Z]", t):
        return "I"
    return "?"


def split_top(s):
    out, d, cur = [], 0, ""
    for ch in s:
        if ch in "(<[":
            d += 1
        elif ch in ")>]":
            d -= 1
        if ch == "," and d == 0:
            out.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur)
    return [x.strip() for x in out]


def param_type(p):
    p = p.split("=")[0].strip()
    if p in ("void", "", "..."):
        return p
    if "(" in p:
        return "(*)"   # function pointer
    m = re.match(r"^(.*?[\s\*&])\s*(\w+)\s*((?:\[[^\]]*\])*)$", p)
    if m and m.group(1).strip() and not re.match(r"^(?:const\s+|volatile\s+)*(?:signed|unsigned|long|short)$",
                                                  m.group(1).strip()) \
            and m.group(2) not in ("int", "long", "short", "char", "float", "double", "u_long128", "u_long",
                                   "const", "bool", "unsigned", "signed"):
        return m.group(1).strip() + (" *" if m.group(3) else "")
    return p


def learn_types(txt):
    for m in re.finditer(r"\btypedef\s+([^;{}]*?)\b(\w+)\s*;", txt):
        body, name = m.group(1).strip(), m.group(2)
        if "(" in body:
            TYPEDEF[name] = "P"
            continue
        k = kind(body + (" " if not body.endswith("*") else ""))
        if re.match(r"^(struct|class|union)\s+\w+\s*$", body):
            k = "S"
        if re.match(r"^enum\b", body):
            k = "I"
        if k != "?":
            TYPEDEF.setdefault(name, k)
    for m in re.finditer(r"\btypedef\s+(struct|union|enum)\b[^;{]*\{", txt):
        i, d = m.end(), 1
        while i < len(txt) and d:
            d += {"{": 1, "}": -1}.get(txt[i], 0)
            i += 1
        n = re.match(r"\s*(\w+)\s*;", txt[i:])
        if n:
            TYPEDEF[n.group(1)] = "I" if m.group(1) == "enum" else "S"
    for m in re.finditer(r"\b(struct|class|union)\s+(\w+)\s*(?::[^{;]*)?\{", txt):
        AGG.add(m.group(2))
    for m in re.finditer(r"\benum\s+(\w+)", txt):
        ENUMS.add(m.group(1))


# ---- CodeWarrior mangled names --------------------------------------------------------------------------------------
CODE = {"i": "I", "s": "I", "c": "I", "b": "I", "w": "I", "l": "L", "x": "L", "f": "F", "d": "F", "v": "V"}


def cw_kinds(p):
    out, i = [], 0
    while i < len(p):
        if p[i] == "_":
            break
        if p[i] in "TN":
            m = re.match(r"T(\d)|N(\d)(\d)", p[i:])
            if not m:
                return None
            cnt = 1 if m.group(1) else int(m.group(2))
            idx = int(m.group(1) or m.group(3)) - 1
            if idx >= len(out):
                return None
            out += [out[idx]] * cnt
            i += len(m.group(0))
            continue
        j, ptr = i, False
        while j < len(p) and p[j] in "CVUSPRA":
            if p[j] in "PR":
                ptr = True
            if p[j] == "A":
                ptr = True
                m = re.match(r"A\d+_", p[j:])
                if not m:
                    return None
                j += len(m.group(0))
                continue
            j += 1
        if j >= len(p):
            return None
        c = p[j]
        if c.isdigit():
            m = re.match(r"\d+", p[j:])
            n = int(m.group(0))
            nm = p[j + len(m.group(0)):j + len(m.group(0)) + n]
            j += len(m.group(0)) + n
            out.append("P" if ptr else ("I" if nm in ENUMS or nm in TYPEDEF and TYPEDEF[nm] == "I" else "S?"))
        elif c == "Q":
            n, j = int(p[j + 1]), j + 2
            nm = ""
            for _ in range(n):
                m = re.match(r"\d+", p[j:])
                nm = p[j + len(m.group(0)):j + len(m.group(0)) + int(m.group(0))]
                j += len(m.group(0)) + int(m.group(0))
            out.append("P" if ptr else ("I" if nm in ENUMS else "S?"))
        elif c == "F":
            # function pointer type: F<params>_<ret>
            j += 1
            depth = 0
            while j < len(p) and p[j] != "_":
                j += 1
            j += 2
            out.append("P")
        elif c in CODE:
            j += 1
            out.append("P" if ptr else CODE[c])
        elif c == "e":
            j += 1
            out.append("...")
        else:
            return None
        i = j
    if out == ["V"]:
        out = []
    return out


def demangle(name):
    """link name -> (class, method, is_member, [kinds]) or None"""
    m = re.match(r"^(\w+?)__(\d+)(\w+)$", name)
    if m and not name.startswith("__"):
        n = int(m.group(2))
        rest = m.group(3)
        cls, tail = rest[:n], rest[n:]
        if tail.startswith("C"):
            tail = tail[1:]
        if tail.startswith("F"):
            k = cw_kinds(tail[1:])
            return (cls, m.group(1), True, k) if k is not None else None
    m = re.match(r"^(\w+?)__Q(\d)(\w+)$", name)
    if m:
        k, rest = int(m.group(2)), m.group(3)
        parts = []
        for _ in range(k):
            mm = re.match(r"\d+", rest)
            if not mm:
                return None
            n = int(mm.group(0))
            parts.append(rest[len(mm.group(0)):len(mm.group(0)) + n])
            rest = rest[len(mm.group(0)) + n:]
        if rest.startswith("C"):
            rest = rest[1:]
        if rest.startswith("F"):
            kk = cw_kinds(rest[1:])
            return (parts[-1], m.group(1), True, kk) if kk is not None else None
    m = re.match(r"^(\w+?)__F(\w*)$", name)
    if m:
        k = cw_kinds(m.group(2))
        return ("", m.group(1), False, k) if k is not None else None
    return None


# ---- source parsing -------------------------------------------------------------------------------------------------
PROTO = re.compile(
    r"(?:^|(?<=[;{}\n]))[ \t]*(?P<ext>extern\s+\"C\"\s+)?(?P<spec>(?:(?:static|inline|extern|friend|__inline)\s+)*)"
    r"(?P<ret>(?:const\s+|volatile\s+|unsigned\s+|signed\s+|struct\s+|class\s+|enum\s+)*[A-Za-z_][\w:]*(?:<[^;{}()]*>)?"
    r"(?:\s+(?:long|int|short|char|const))*[\s\*&]+)"
    r"(?P<name>(?:\w+::)*~?\w+)\s*\((?P<params>[^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*)\)\s*(?:const\s*)?"
    r"(?P<end>;|\{)", re.M)
NOTTYPE = {"return", "else", "case", "goto", "new", "delete", "throw", "sizeof", "do", "if", "while", "for", "switch",
           "typedef", "using", "namespace"}


def depth_map(txt):
    """brace depth at each offset, not counting extern "C" { and namespace { blocks; set of C-linkage spans"""
    dep = [0] * (len(txt) + 1)
    stack, cspans, d = [], [], 0
    opens = {m.end() - 1: True for m in re.finditer(r'extern\s+"C"\s*\{', txt)}
    nss = {m.end() - 1 for m in re.finditer(r"\bnamespace\s*\w*\s*\{", txt)}
    for i, ch in enumerate(txt):
        dep[i] = d
        if ch == "{":
            transparent = i in opens or i in nss
            stack.append((i, transparent))
            if not transparent:
                d += 1
        elif ch == "}" and stack:
            j, transparent = stack.pop()
            if transparent:
                if j in opens:
                    cspans.append((j, i))
            else:
                d -= 1
    dep[len(txt)] = d
    return dep, cspans


def parse(path, txt):
    dep, cspans = depth_map(txt)
    out = []
    for m in PROTO.finditer(txt):
        ret = re.sub(r"^(?:(?:public|private|protected)\s*:\s*)+", "", m.group("ret").strip())
        name = m.group("name")
        first = ret.split()[0] if ret.split() else ""
        if first in NOTTYPE or name in NOTTYPE or re.match(r"^(return|case|goto|else)\b", ret):
            continue
        if name.startswith("operator") or "::" in name:
            continue
        pos = m.start("ret")
        incs = any(a < pos < b for a, b in cspans)
        ext = bool(m.group("ext")) or incs
        end = m.group("end")
        if end == "{" and dep[m.end() - 1] != 0:
            continue                       # not a top-level definition
        params = [param_type(p) for p in split_top(m.group("params"))]
        if params == ["void"]:
            params = []
        if any(re.search(r"[+\-/%!?]|^\d|^'|==|\.\w|->|^\"", p) for p in params):
            continue                       # a call, not a prototype
        if end == ";" and any(re.match(r"^\w+$", p) and kind(p) == "?" and not re.match(r"^[A-Z]", p) for p in params):
            continue
        out.append(dict(file=path, line=txt.count("\n", 0, pos) + 1, name=name, ret=ret, params=params,
                        ext=ext, static="static" in m.group("spec") or "inline" in m.group("spec"),
                        defn=end == "{", depth=dep[pos]))
    return out


def kinds(params):
    return [kind(p) for p in params]


def regs(ks):
    """EE (MWCC) argument registers: integers/pointers/aggregates take a0-a3,t0-t3 in order, floats f12-f19,
    each file counted on its own, so (P, I, F) and (P, F, I) load the same registers"""
    return [k for k in ks if k != "F"], [k for k in ks if k == "F"]


def same(a, b):
    """same argument registers with compatible kinds: '?' matches anything; an aggregate by value is a pointer
    to the caller's copy (S = P; proven definitions read it through the register, e.g. func_00399E20)"""
    (ga, fa), (gb, fb) = regs(a), regs(b)
    if len(ga) != len(gb) or len(fa) != len(fb):
        return False
    for x, y in zip(ga, gb):
        if x == y or "?" in (x, y) or {x, y} <= {"S", "S?", "P"} or {x, y} == {"S?", "I"}:
            continue
        return False
    return True


def load():
    """parse src/b3, src/nonmatching and the headers -> (items, defs {name: (rank, item)}, cnames, file-local names)"""
    os.chdir(ROOT)
    files = sorted(glob.glob("src/b3/**/*.cpp", recursive=True)) + sorted(glob.glob("src/nonmatching/*.cpp"))
    headers = sorted(glob.glob("include/**/*.h", recursive=True)) + sorted(glob.glob("src/**/*.h", recursive=True))
    texts = {}
    for f in headers + files:
        texts[f] = strip(open(f, errors="replace").read())
        learn_types(texts[f])
    items = []
    for f, t in texts.items():
        items += parse(f, t)
    cnames = {it["name"] for it in items if it["ext"] and not it["defn"]}
    # definitions of C names: proven first, then archives; static/inline ones are file-local
    defs = {}
    for it in items:
        if it["defn"] and it["name"] in cnames and not it["static"]:
            r = 0 if it["file"].startswith("src/b3/") else 1 if it["file"].startswith("src/nonmatching/") else 2
            if it["name"] not in defs or r < defs[it["name"]][0]:
                defs[it["name"]] = (r, it)
    local = {(it["file"], it["name"]) for it in items if it["defn"] and it["static"]}
    return items, defs, cnames, local


def main():
    show_all = "--all" in sys.argv
    items, defs, cnames, local = load()
    rows = []
    seen = set()

    def truth_of(name, nargs):
        """(kinds, source text, definition item or None)"""
        d = defs.get(name)
        if d:
            return kinds(d[1]["params"]), "%s:%d" % (d[1]["file"], d[1]["line"]), d[1]
        dm = demangle(name)
        if dm:
            mk = list(dm[3])
            if dm[2] and len(regs(nargs)[0]) >= len(regs(mk)[0]) + 1:
                mk = ["P"] + mk          # member: `this` first
            return mk, "mangled", None
        return None, None, None

    for it in items:
        if it["defn"] or not it["ext"]:
            continue
        name = it["name"]
        if (it["file"], name) in local:
            continue
        dk = kinds(it["params"])
        truth, src, d = truth_of(name, dk)
        if truth is None or (d and d["file"] == it["file"]):
            continue
        key = (it["file"], name)
        if key in seen:
            continue
        where = "%s:%d" % (it["file"], it["line"])
        if not same(dk, truth):
            seen.add(key)
            rows.append((name, classify(dk, truth), where, "".join(dk) or "-", "".join(x[0] for x in truth) or "-", src))
            continue
        if d:
            a, b = kind(it["ret"]), kind(d["ret"])
            if (a == "V") != (b == "V"):
                seen.add(key)
                rows.append((name, "ret-caller-void" if a == "V" else "ret-callee-void", where, it["ret"], d["ret"], src))
            elif show_all and a != b and "?" not in (a, b) and {a, b} != {"S", "P"}:
                seen.add(key)
                rows.append((name, "ret-kind", where, it["ret"], d["ret"], src))
    # definitions against their own mangled names
    for name, (r, d) in sorted(defs.items()):
        dm = demangle(name)
        if not dm:
            continue
        mk = list(dm[3])
        dk = kinds(d["params"])
        if dm[2] and len(regs(dk)[0]) >= len(regs(mk)[0]) + 1:
            mk = ["P"] + mk
        if not same(dk, mk):
            rows.append((name, "def-" + classify(dk, mk), "%s:%d" % (d["file"], d["line"]), "".join(dk) or "-",
                         "".join(x[0] for x in mk) or "-", "mangled"))
    for r in sorted(rows, key=lambda r: (r[1], r[0], r[2])):
        print("\t".join(r))
    print("%d rows (%d extern \"C\" names, %d with a definition)" % (len(rows), len(cnames), len(defs)), file=sys.stderr)


def classify(a, b):
    """row class: declared kinds a vs truth b, per register file"""
    (ga, fa), (gb, fb) = regs(a), regs(b)
    if len(ga) < len(gb) or len(fa) < len(fb):
        return "fewer"
    if len(ga) > len(gb) or len(fa) > len(fb):
        return "more"
    d = set()
    for x, y in zip(ga, gb):
        x, y = ("P" if x in ("S", "S?") else x), ("P" if y in ("S", "S?") else y)
        if x != y and "?" not in (x, y):
            d.add("".join(sorted((x, y))))
    return "kind-" + "/".join(sorted(d))


if __name__ == "__main__":
    main()
