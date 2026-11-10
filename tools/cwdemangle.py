"""Minimal Metrowerks/cfront-style C++ demangler for the subset used in this project.
demangle("Fixup__18CB3TrackDataStructFUi") -> "CB3TrackDataStruct::Fixup(unsigned int)"; returns None if unsupported."""
import re
BASIC = {"v": "void", "i": "int", "f": "float", "d": "double", "c": "char", "b": "bool", "s": "short", "l": "long", "x": "long long", "w": "wchar_t", "e": "..."}
OPS = {"ml": "operator *", "pl": "operator +", "mi": "operator -", "dv": "operator /", "as": "operator =", "eq": "operator ==", "ne": "operator !=",
       "ct": None, "dt": None, "vc": "operator []", "apl": "operator +=", "ami": "operator -=", "amu": "operator *=", "lt": "operator <", "gt": "operator >"}
def _name(s, i):
    if s[i] == "Q":
        n = int(s[i+1]); i += 2; parts = []
        for _ in range(n):
            m = re.match(r"\d+", s[i:]); l = int(m.group()); i += len(m.group()); parts.append(s[i:i+l]); i += l
        return "::".join(parts), i
    m = re.match(r"\d+", s[i:]); l = int(m.group()); i += len(m.group()); return s[i:i+l], i + l
def _type(s, i):
    pre = ""; post = ""
    while True:
        c = s[i]
        if c == "C": pre = "const " + pre if not post else pre; post = (" const" + post) if post else post; i += 1; cst = True; continue
        if c == "P" and s[i+1] == "F":            # a function pointer: PF<params>_<return>
            i += 2; ps = []
            while s[i] != "_":
                t, i = _type(s, i); ps.append(t)
            r, i = _type(s, i + 1)
            if ps == ["void"]: ps = []
            return pre + r + " (*)(" + ",".join(ps) + ")", i
        if c == "P": t, i = _type(s, i+1); return t + "*", i
        if c == "R": t, i = _type(s, i+1); return t + "&", i
        if c == "U": i += 1; t = {"c": "unsigned char", "i": "unsigned int", "s": "unsigned short", "l": "unsigned long", "x": "unsigned long long"}[s[i]]; return pre + t, i + 1
        if c == "S" and s[i+1] == "c": return pre + "signed char", i + 2
        if c in BASIC: return pre + BASIC[c], i + 1
        if c.isdigit() or c == "Q": n, i = _name(s, i); return pre + n, i
        raise ValueError(s[i:])
def demangle(sym):
    m = re.match(r"^(\w+?)__(Q\d|\d)", sym)
    if not m: return None
    fn = m.group(1); rest = sym[len(fn) + 2:]
    try:
        cls, i = _name(rest, 0)
        const = False
        if rest[i] == "C": const = True; i += 1
        if rest[i] != "F": return None
        i += 1; args = []
        while i < len(rest):
            t, i = _type(rest, i); args.append(t)
        if args == ["void"]: args = []
        last = cls.split("::")[-1]
        if fn == "__ct": fn = last
        elif fn == "__dt": fn = "~" + last
        elif fn.startswith("__") and fn[2:] in OPS: fn = OPS[fn[2:]]
        return f"{cls}::{fn}({','.join(args)})" + (" const" if const else "")
    except Exception:
        return None
if __name__ == "__main__":
    import sys
    for s in sys.argv[1:]: print(s, "->", demangle(s))
