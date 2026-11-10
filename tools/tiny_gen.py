#!/usr/bin/env python3
"""Source generation for tools/tiny_batch.py: one tools/tiny_scan.py candidate -> a C/C++ file.

generate(c, has_header) -> ((text, unit), None) or (None, reason).
Named functions become a method of their class, declared locally with only what the function touches; unnamed ones
(func_XXXXXXXX) become extern "C" functions whose a0 is `self`, a placeholder struct (or, when a0 is passed straight
on as `this` to a named method of a header-less class, that class). Field names are placeholders (field_XX) and every
field/parameter type is [G], read off the instruction widths. A tail call's callee is declared as follows:
  func_XXXXXXXX           extern "C", parameters = what this function passes it
  Cls::Method(params)     a local class declaration, when Cls has no header and every parameter type is simple;
                          the call is this->Method(), self->Method(), field.Method() or field->Method(), or
                          Base::Method() when a named method tail-calls the same-named method of another class
                          (then a base class, [L]); otherwise called through its link name (extern "C", as N112)
  free function(params)   declared with its demangled parameter types
"""
import os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from cwdemangle import demangle  # noqa: E402

GPR = ["a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3"]
FPR = ["f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19"]
BUILTIN = {"void", "int", "unsigned int", "short", "unsigned short", "char", "signed char", "unsigned char", "bool", "float",
           "long", "unsigned long", "long long", "unsigned long long"}
LOADT = {"lw": "int", "lh": "short", "lhu": "unsigned short", "lb": "signed char", "lbu": "unsigned char", "lwc1": "float"}
STORET = {"sw": "int", "sh": "short", "sb": "unsigned char", "sd": "unsigned long", "swc1": "float"}
SIZE = {"int": 4, "short": 2, "unsigned short": 2, "signed char": 1, "unsigned char": 1, "unsigned long": 8, "float": 4,
        "bool": 1, "char": 1, "unsigned int": 4, "long": 8}


class Skip(Exception):
    pass


def split_params(p):
    p = p.strip()
    if p in ("", "void"):
        return []
    if "<" in p:
        raise Skip("param list %s" % p[:40])
    out, d, cur = [], 0, ""
    for ch in p:                      # commas inside a function pointer's own parameter list stay in it
        d += (ch == "(") - (ch == ")")
        if ch == "," and d == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += ch
    out.append(cur.strip())
    return out


def ptype(t):
    """-> (core identifier or None for builtins, is_ptr, is_ref, is_float). Raises Skip for unsupported types."""
    if "(*)" in t:
        return "FNPTR", True, False, False      # a function pointer: an address in a GPR (declared void *)
    core = t.replace("const", "").replace("*", "").replace("&", "").strip()
    is_ref = t.endswith("&")
    is_ptr = "*" in t or is_ref
    if core in BUILTIN:
        return None, is_ptr, is_ref, (core == "float" and not is_ptr)
    if core.startswith("GtMathPs2::") and is_ptr and re.fullmatch(r"GtMathPs2::\w+", core):
        return core, is_ptr, is_ref, False
    if not re.fullmatch(r"[A-Za-z_]\w*", core):
        raise Skip("param type %s" % t)
    if not is_ptr and not core.startswith("E"):
        raise Skip("class %s by value" % t)
    return core, is_ptr, is_ref, False


def parse_method(dem):
    m = re.fullmatch(r"(\w+)::(~?\w+)\((.*)\)( const)?", dem)
    if not m:
        return None
    return m.group(1), m.group(2), split_params(m.group(3)), bool(m.group(4))


def is_ptr_type(t):
    return "*" in t or t.endswith("&")


class Unit:
    def __init__(self, c, has_header):
        self.c, self.has_header = c, has_header
        self.ir = c["ir"]
        self.classes = {}        # name -> {"methods": [], "fields": {off: type}, "base": None, "kw": "class"}
        self.order = []          # declaration order of full class definitions
        self.fwd = []            # forward declarations / enums
        self.externs = []        # extern "C" declarations
        self.include_gt = False
        self.body = []
        self.ret = "void"
        self.named = not c["name"].startswith("func_")
        self.params = {}         # reg -> (name, type)
        self.self_needed = False

    # -- declarations --------------------------------------------------------------------------------------------
    def cls(self, name, kw="class"):
        if name not in self.classes:
            self.classes[name] = {"methods": [], "fields": {}, "base": None, "kw": kw}
            self.order.append(name)
        return self.classes[name]

    def need_type(self, t):
        core, isp, isr, isf = ptype(t)
        if core is None:
            return
        if core.startswith("GtMathPs2::"):
            self.include_gt = True
            return
        d = ("enum %s {};" % core) if core.startswith("E") else ("class %s;" % core)
        if core not in self.classes and d not in self.fwd:
            self.fwd.append(d)

    # -- the function's own signature ---------------------------------------------------------------------------
    def setup_caller(self):
        c = self.c
        if self.named:
            pm = parse_method(c["demangled"])
            if not pm:
                raise Skip("unsupported name shape")
            self.ccls, self.meth, plist, self.const = pm
            if self.meth.startswith("~"):
                raise Skip("dtor")
            self.ctor = self.meth == self.ccls
            if self.has_header(self.ccls):
                raise Skip("class already has a header")
            self.self_type = self.ccls
            self.cls(self.ccls)
            self.self_expr, self.fpre = "this", ""
            gi, fi = 1, 0
            self.plist = []
            for k, t in enumerate(plist):
                core, isp, isr, isf = ptype(t)
                self.need_type(t)
                pn = "p%d" % k
                self.plist.append("%s %s" % (t, pn))
                if isf:
                    self.params[FPR[fi]] = (pn, t); fi += 1
                else:
                    self.params[GPR[gi]] = (pn, t); gi += 1
        else:
            self.ctor, self.const = False, False
            self.self_type = "UnkStruct_%08X" % c["addr"]
            self.self_expr, self.fpre = "self", "self->"

    def param(self, reg, want):
        """The caller's parameter held in `reg`; unnamed functions grow one of type `want`."""
        if reg == "a0":
            self.self_needed = True
            return self.self_expr, self.self_type + " *"
        if reg in self.params:
            return self.params[reg]
        if self.named:
            raise Skip("needs register %s, not a parameter" % reg)
        if reg in FPR:
            for r in FPR[:FPR.index(reg)]:
                self.params.setdefault(r, ("f%d" % FPR.index(r), "float"))
            self.params[reg] = ("f%d" % FPR.index(reg), want)
        else:
            for r in GPR[1:GPR.index(reg)]:
                self.params.setdefault(r, ("p%d" % (GPR.index(r) - 1), "int"))
            self.params[reg] = ("p%d" % (GPR.index(reg) - 1), want)
            self.self_needed = True       # a1.. implies a0 is a parameter too
        return self.params[reg]

    # -- fields ---------------------------------------------------------------------------------------------------
    def field(self, off, t):
        f = self.cls(self.self_type, "class" if self.named else "struct")["fields"]
        if off in f and f[off] != t:
            raise Skip("conflicting field types at +0x%X" % off)
        f[off] = t
        self.self_needed = True
        return "%sfield_%X" % (self.fpre, off)

    # -- body -----------------------------------------------------------------------------------------------------
    def stores(self):
        for mn, src, off in self.ir["stores"]:
            ft = STORET[mn]
            if src == "zero":
                val = "0"
            elif src.startswith("#"):
                k = int(src[1:])
                if mn == "sb" and k < 0:
                    ft = "signed char"
                if mn == "sh" and k > 0x7FFF:
                    ft = "unsigned short"
                val = str(k)
            else:
                if (mn == "swc1") != (src in FPR):
                    raise Skip("%s from %s" % (mn, src))
                want = "float" if src in FPR else ("unsigned long" if mn == "sd" else "int")
                pn, pt = self.param(src, want)
                core = pt.replace("&", "").strip()
                if pt.endswith("&"):
                    if mn != "sw":
                        raise Skip("reference stored with %s" % mn)
                    ft, val = core + " *", "&" + pn
                elif "*" in pt and mn == "sw":
                    ft, val = pt, pn
                elif pt == "bool" and mn == "sb":
                    ft, val = "bool", pn
                elif pt.startswith("E") and mn == "sw":
                    ft, val = pt, pn
                else:
                    psz = SIZE.get(pt.replace("const", "").strip(), 4)
                    val = pn if SIZE.get(ft) == psz else "(%s)%s" % (ft, pn)
            self.body.append("    %s = %s;" % (self.field(off, ft), val))

    def returns(self):
        r = self.ir["ret"]
        if r is None:
            return
        if self.ctor:
            if r[0] != "self":
                raise Skip("constructor not returning this")
            return
        k = r[0]
        if k == "k":
            self.ret = "int"
            self.body.append("    return %d;" % r[1])
        elif k == "self":
            self.self_needed = True
            self.ret = self.self_type + " *"
            self.body.append("    return %s;" % self.self_expr)
        elif k == "addr":
            self.self_needed = True
            self.ret = "void *"
            self.body.append("    return (char *)%s + 0x%X;" % (self.self_expr, r[1]))
        elif k == "get":
            self.ret = LOADT[r[1]]
            self.body.append("    return %s;" % self.field(r[2], LOADT[r[1]]))
        elif k == "eq":
            self.ret = "bool"
            self.body.append("    return %s == %d;" % (self.field(r[2], LOADT[r[1]]), r[3]))
        else:
            raise Skip("ret %s" % k)

    def tail(self):
        t = self.ir["tail"]
        if not t:
            return
        target, args = t["target"], t["args"]
        if target == self.c["name"]:
            raise Skip("self tail call")
        if target.startswith("func_"):
            self.tail_unknown(target, args)
            return
        dem = demangle(target)
        if not dem:
            raise Skip("callee %s not demangled (C library?)" % target)
        pm = parse_method(dem)
        if pm:
            self.tail_method(target, pm, args)
            return
        m = re.fullmatch(r"(\w+)\((.*)\)", dem)
        if not m:
            raise Skip("callee shape %s" % dem[:40])
        self.tail_free(target, m.group(1), split_params(m.group(2)), args)

    def arg_value(self, reg, spec, objtype=None):
        """An argument expression for a register the delay slot / effects set up."""
        if spec[0] == "k":
            return str(spec[1]), "int"
        if spec[0] == "addr":
            if objtype:
                return "&" + self.field(spec[1], objtype), objtype + " *"
            return "(char *)%s + 0x%X" % (self.self_expr, spec[1]), "void *"
        if spec[0] == "load":
            ft = (objtype + " *") if objtype else "void *"
            return self.field(spec[1], ft), ft
        raise Skip("arg %s" % spec)

    def tail_unknown(self, target, args):
        regs = [r for r in GPR if r in args]
        top = max([GPR.index(r) for r in regs] + [-1])
        if self.named:
            top = max(top, max([GPR.index(r) for r in self.params if r in GPR] + [0]))
        elif self.ir["stores"] and top < 0:
            top = 0                       # pass self on, as the stores already use it
        vals, types = [], []
        for i in range(top + 1):
            r = GPR[i]
            if r in args:
                v, ty = self.arg_value(r, args[r])
            else:
                v, ty = self.param(r, "int")
            vals.append(v); types.append(ty)
        if self.named:
            for r in FPR:
                if r in self.params:
                    vals.append(self.params[r][0]); types.append(self.params[r][1])
        self.externs.append('extern "C" void %s(%s);' % (target, ", ".join(types)))
        self.body.append("    %s(%s);" % (target, ", ".join(vals)))

    def callee_args(self, plist, args, first):
        """Values for a known callee's parameters (GPR from `first`)."""
        vals = []
        gi, fi = first, 0
        for t in plist:
            core, isp, isr, isf = ptype(t)
            self.need_type(t)
            reg = FPR[fi] if isf else GPR[gi]
            if isf:
                fi += 1
            else:
                gi += 1
            if reg in args:
                if args[reg][0] != "k" or isp:
                    raise Skip("argument %s set up as %s" % (reg, args[reg]))
                vals.append(str(args[reg][1]))
                continue
            pn, pt = self.param(reg, t)
            if pt == t:
                vals.append(pn)
            elif is_ptr_type(pt) and is_ptr_type(t) and not t.endswith("&"):
                vals.append("(%s)%s" % (t, pn))
            else:
                raise Skip("passes %s as %s" % (pt, t))
        for r in args:
            if r != "a0" and r in GPR and GPR.index(r) >= gi:
                raise Skip("sets %s beyond the callee's parameters" % r)
        return vals

    def tail_method(self, target, pm, args):
        ccls2, meth2, plist2, const2 = pm
        if meth2.startswith("~") or meth2 == ccls2:
            raise Skip("callee ctor/dtor")
        simple = not self.has_header(ccls2)
        try:
            for t in plist2:
                ptype(t)
        except Skip:
            simple = False
        if self.named and ccls2 == self.ccls:
            simple = True                  # our own class: declared here anyway
        a0 = args.get("a0")
        sig = "void %s(%s)%s" % (meth2, ", ".join(plist2), " const" if const2 else "")
        if simple:
            if a0 is None:
                if self.named:
                    if ccls2 == self.ccls:
                        obj = None
                    elif meth2 == self.meth and not self.classes[self.ccls]["fields"] and not self.ir["stores"]:
                        self.cls(ccls2)
                        self.classes[self.ccls]["base"] = ccls2
                        obj = ccls2 + "::"
                    else:
                        simple = False
                else:
                    # a0 goes straight on as `this`: self is a ccls2 (its fields move over)
                    old = self.classes.pop(self.self_type, None)
                    if self.self_type in self.order:
                        self.order.remove(self.self_type)
                    self.self_type = ccls2
                    if old:
                        self.cls(ccls2)["fields"].update(old["fields"])
                    self.self_needed = True
                    obj = "self->"
            else:
                obj = None
        if not simple:
            vals = [self.arg_value("a0", a0)[0] if a0 else self.param("a0", "void *")[0]] + self.callee_args(plist2, args, 1)
            types = ["void *" if a0 else self.self_type + " *"]
            for t in plist2:
                core, isp, isr, isf = ptype(t)
                types.append("void *" if isp else t)
            self.externs.append('extern "C" void %s(%s);  // %s' % (target, ", ".join(types), demangle(target)))
            self.body.append("    %s(%s);" % (target, ", ".join(vals)))
            return
        k = self.cls(ccls2)
        if sig not in k["methods"]:
            k["methods"].append(sig)
        if a0 is not None:
            if a0[0] == "k":
                raise Skip("constant object")
            if self.classes.get(ccls2, {}).get("fields"):
                raise Skip("embedded class with fields")
            expr, _ = self.arg_value("a0", a0, ccls2)
            obj = (expr[1:] + ".") if a0[0] == "addr" else (expr + "->")
        vals = self.callee_args(plist2, args, 1)
        if obj is None:
            self.body.append("    %s(%s);" % (meth2, ", ".join(vals)))
        else:
            self.body.append("    %s%s(%s);" % (obj, meth2, ", ".join(vals)))

    def tail_free(self, target, fname, plist, args):
        if "a0" in args and args["a0"][0] != "k":
            raise Skip("free callee with a computed a0")
        vals = self.callee_args(plist, args, 0)
        d = "void %s(%s);" % (fname, ", ".join(plist))
        if d not in self.fwd:
            self.fwd.append(d)
        self.body.append("    %s(%s);" % (fname, ", ".join(vals)))

    # -- output ---------------------------------------------------------------------------------------------------
    def layout(self, name):
        k = self.classes[name]
        lay, pos = [], 0
        for off in sorted(k["fields"]):
            ft = k["fields"][off]
            if "*" in ft or ft.startswith("E"):
                sz = 4
            elif ft in self.classes:
                sz = 1
            else:
                sz = SIZE.get(ft, 4)
            if off % sz:
                raise Skip("misaligned field +0x%X" % off)
            if off < pos:
                raise Skip("overlapping fields at +0x%X" % off)
            if off > pos:
                lay.append("    unsigned char pad_%X[0x%X];" % (pos, off - pos))
            lay.append("    %s field_%X;" % (ft, off))
            pos = off + sz
        return lay

    def emit(self):
        c = self.c
        if self.named:
            k = self.cls(self.ccls)
            if self.ctor:
                own = "%s(%s);" % (self.ccls, ", ".join(self.plist))
            else:
                own = "%s %s(%s)%s;" % (self.ret, self.meth, ", ".join(self.plist), " const" if self.const else "")
            k["methods"].insert(0, own)
        lines = []
        if self.named:
            lines += ["// %s -- tiny-function batch (tools/tiny_batch.py)." % c["demangled"],
                      "// [C] name: the mangled symbol in retail's tables (%s); file: research/retail_names.csv -> %s."
                      % (c.get("conf") or "high", c["file"]),
                      "// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes are declared here with only what this",
                      "// function needs; field names are placeholders and their types are [G] from the instruction widths."]
        else:
            lines += ["// %s -- tiny-function batch (tools/tiny_batch.py)." % c["name"],
                      "// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so",
                      "// _unclassified/. Parameter and field types are [G] from the registers and instruction widths; `self` is",
                      "// whatever object a0 points to."]
        if self.ir.get("tail"):
            t = self.ir["tail"]["target"]
            lines.append("// Tail call: %s%s." % (t, (" = " + demangle(t)) if demangle(t) else ""))
            if any(cl["base"] for cl in self.classes.values()):
                lines.append("// [L] base class: a method that tail-calls the same-named method of another class on `this`.")
        if self.include_gt:
            lines.append('#include "b3/GtMathPs2.h"')
        lines.append("")
        if self.fwd:
            lines += self.fwd + [""]
        order = [n for n in self.order if n != self.self_type] + [n for n in self.order if n == self.self_type]
        if not self.named and self.self_needed:
            k = self.classes.get(self.self_type)
            if not k or (not k["methods"] and not k["fields"]):
                lines += ["struct %s;" % self.self_type, ""]
        for name in order:
            k = self.classes[name]
            if not k["methods"] and not k["fields"] and not self.named and name == self.self_type:
                continue
            head = "%s %s%s {" % (k["kw"], name, (" : public %s" % k["base"]) if k["base"] else "")
            lines.append(head)
            if k["methods"]:
                lines.append("public:")
                lines += ["    %s" % m if m.endswith(";") else "    %s;" % m for m in k["methods"]]
            lay = self.layout(name)
            if lay:
                if k["methods"]:
                    lines.append("")
                lines += lay
            lines += ["};", ""]
        if self.externs:
            lines += self.externs + [""]
        lines.append("// 0x%08X" % c["addr"])
        if self.named:
            q = "%s::" % self.ccls
            if self.ctor:
                lines.append("%s%s(%s)" % (q, self.ccls, ", ".join(self.plist)))
            else:
                lines.append("%s %s%s(%s)%s" % (self.ret, q, self.meth, ", ".join(self.plist), " const" if self.const else ""))
        else:
            ps = []
            if self.self_needed:
                ps.append("%s *self" % self.self_type)
            for bank in (GPR[1:], FPR):
                for r in bank:
                    if r in self.params:
                        ps.append("%s %s" % (self.params[r][1], self.params[r][0]))
            lines.append('extern "C" %s %s(%s)' % (self.ret, c["name"], ", ".join(ps)))
        lines.append("{")
        lines += self.body
        lines.append("}")
        text = "\n".join(lines) + "\n"
        text = re.sub(r"\n\n\n+", "\n\n", text)
        if self.named:
            unit = "%s_%08X" % (os.path.splitext(c["file"])[0], c["addr"])
        else:
            unit = c["name"]
        return text, unit


def generate(c, has_header):
    u = Unit(c, has_header)
    try:
        u.setup_caller()
        u.stores()
        u.returns()
        u.tail()
        if u.ctor and (u.ir["tail"] or u.ir["ret"] is None):
            raise Skip("constructor shape")
        return u.emit(), None
    except Skip as e:
        return None, str(e)
