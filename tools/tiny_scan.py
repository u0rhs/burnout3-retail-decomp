#!/usr/bin/env python3
"""Scan the game's asm chunks for tiny (<= 0x40 byte) functions that a mechanical template can express.

Prints a JSON list of candidates for tools/tiny_batch.py. Only chunks the yaml currently links are scanned (a renamed
or split chunk's old .s file can stay on disk). A candidate is label-free and its body, read in order with the delay
slot executed before the jump, is a list of effects then a terminator:
  effects     stores to off(a0) of zero / an argument register / a constant loaded with `li v0|v1,K`
  jr ra       returning nothing, a constant, a0 itself, a0+K, a field of a0, or (field == K)
  j target    a tail call; the delay slot (or the effects) may set up arguments: `li aN,K`, a0 = a0+K or a0 = *(a0+K)
Kinds (for reporting): empty, const, get, stores, setk (constant stores), this, addr, eq, tail.
Named candidates need a high- (or with --medium, medium-) confidence research/retail_names.csv row naming a .cpp;
--func adds the unnamed func_ placeholders.
--lift adds every other label-free function as kind "lift" (tools/tiny_lift.py: straight-line code with calls,
globals and arithmetic); --lift-only drops the template kinds.
Usage: tiny_scan.py [--max 0x40] [--medium] [--func] [--lift|--lift-only] > candidates.json
"""
import csv, glob, json, os, re, sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from cwdemangle import demangle  # noqa: E402

MAX = int(sys.argv[sys.argv.index("--max") + 1], 16) if "--max" in sys.argv else 0x40

INS = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$")
NUM = r"(-?0x[0-9A-Fa-f]+|-?\d+)"
STORES = ("sw", "sh", "sb", "sd", "swc1")
LOADS = ("lw", "lh", "lhu", "lb", "lbu", "lwc1")
ARGREGS = ("a1", "a2", "a3", "t0", "t1", "f12", "f13", "f14", "f15")
SETREGS = ("a1", "a2", "a3", "t0", "t1")


def functions(path):
    cur = None
    for line in open(path):
        if line.startswith("glabel "):
            cur = {"name": line.split()[1], "ins": [], "lins": [], "unit": path}
            continue
        if cur is not None and line.startswith("endlabel " + cur["name"]):
            yield cur
            cur = None
            continue
        if cur is not None:
            m = INS.match(line)
            if m:
                if not cur["ins"]:
                    cur["addr"] = int(m.group(1), 16)
                cur["ins"].append((m.group(2), m.group(3).replace("$", "").replace(" ", "")))
                cur["lins"].append(cur["ins"][-1])
            elif line.strip().startswith(".L") or "jlabel" in line:
                cur["labels"] = True
                if "jlabel" in line:
                    cur["jtab"] = True
                else:
                    cur["lins"].append(("label", line.strip().rstrip(":")))


def classify(ins):
    """-> (kind, ir) or None. ir = {"stores": [[mn, src, off]], "ret": spec|None, "tail": {"target", "args"}|None};
    src is a register, "zero" or "#K"; ret spec: ["k",K] ["self"] ["addr",off] ["get",mn,off] ["eq",mn,off,K];
    tail args: {reg: ["k",K] | ["addr",off] | ["load",off]}."""
    if len(ins) < 2:
        return None
    term = ins[-2]
    if term == ("jr", "ra"):
        tail = None
    elif term[0] == "j" and re.fullmatch(r"[A-Za-z_]\w*", term[1]):
        tail = term[1]
    else:
        return None
    body = ins[:-2] + [ins[-1]]          # the delay slot executes before the jump
    regs, args, stores = {}, {}, []
    a0mod = False
    for m, a in body:
        if (m, a) == ("nop", ""):
            continue
        s = re.fullmatch(r"(\w+),%s\(a0\)" % NUM, a)
        if m in STORES and s:
            r, off = s.group(1), int(s.group(2), 0)
            if a0mod:
                return None
            if r == "zero":
                src = "zero"
            elif r in args and args[r][0] == "k":
                src = "#%d" % args[r][1]
            elif r in ARGREGS and r not in args:
                src = r
            elif r in ("v0", "v1") and regs.get(r, [None])[0] == "k":
                src = "#%d" % regs[r][1]
            else:
                return None
            if src.startswith("#") and m == "swc1":
                return None
            stores.append([m, src, off])
            continue
        k = re.fullmatch(r"(\w+),zero,%s" % NUM, a) if m == "addiu" else None
        if m == "daddu" and re.fullmatch(r"\w+,zero,zero", a):
            k = re.fullmatch(r"(\w+),zero,(zero)", a)
        if k:
            r = k.group(1)
            val = 0 if k.group(2) == "zero" else int(k.group(2), 0)
            if r in ("v0", "v1"):
                regs[r] = ["k", val]
            elif tail and r in SETREGS:
                args[r] = ["k", val]
            else:
                return None
            continue
        if not tail and (m, a) == ("daddu", "v0,a0,zero"):
            regs["v0"] = ["self"]
            continue
        g = re.fullmatch(r"(\w+),a0,%s" % NUM, a) if m == "addiu" else None
        if g and not a0mod:
            if not tail and g.group(1) == "v0":
                regs["v0"] = ["addr", int(g.group(2), 0)]
                continue
            if tail and g.group(1) == "a0":
                args["a0"] = ["addr", int(g.group(2), 0)]
                a0mod = True
                continue
            return None
        g = re.fullmatch(r"(\w+),%s\(a0\)" % NUM, a)
        if m in LOADS and g and not a0mod:
            r, off = g.group(1), int(g.group(2), 0)
            if not tail and ((r == "v0" and m != "lwc1") or (r == "f0" and m == "lwc1")):
                regs[r] = ["get", m, off]
                continue
            if tail and r == "a0" and m == "lw":
                args["a0"] = ["load", off]
                a0mod = True
                continue
            return None
        g = re.fullmatch(r"v0,v0,%s" % NUM, a)
        if m == "xori" and g and regs.get("v0", [None])[0] == "get":
            regs["v0"] = ["xor"] + regs["v0"][1:] + [int(g.group(1), 0)]
            continue
        if (m, a) == ("sltiu", "v0,v0,1") and regs.get("v0", [None])[0] == "xor":
            regs["v0"] = ["eq"] + regs["v0"][1:]
            continue
        return None
    ir = {"stores": stores, "ret": None, "tail": None}
    if tail:
        if regs:
            return None
        ir["tail"] = {"target": tail, "args": args}
        return "tail", ir
    ret = regs.get("v0") or regs.get("f0")
    if ("v0" in regs and "f0" in regs) or (ret and ret[0] == "xor"):
        return None
    if regs.get("v1") and not any(s[1] == "#%d" % regs["v1"][1] for s in stores):
        return None                          # a constant in v1 that nothing stores
    ir["ret"] = ret
    if ret is None:
        return ("setk" if any(s[1].startswith("#") for s in stores) else "stores" if stores else "empty"), ir
    kind = {"k": "const", "self": "this", "addr": "addr", "get": "get", "eq": "eq"}[ret[0]]
    if stores:
        kind = "setk" if any(s[1].startswith("#") for s in stores) else "stores"
    return kind, ir


def live_chunks():
    y = open("config/b3_retail.yaml").read()
    return set(re.findall(r"asm, (game/unit_[0-9A-F]+)\]", y))


def main():
    names = {}
    with open("research/retail_names.csv", newline="") as f:
        for row in csv.reader(f):
            if len(row) >= 4 and re.fullmatch(r"[0-9a-f]{8}", row[0]):
                names[int(row[0], 16)] = (row[1], row[2], row[3])
    live = live_chunks()
    out = []
    for path in sorted(glob.glob("assembly/asm/game/unit_*.s")):
        if path.replace("\\", "/")[len("assembly/asm/"):-2] not in live:
            continue
        for fn in functions(path):
            n = fn["name"]
            if "addr" not in fn or fn.get("jtab"):
                continue
            if fn.get("labels") and "--branch" not in sys.argv:
                continue
            size = 4 * len(fn["ins"])
            if size > MAX:
                continue
            kind = None if fn.get("labels") else classify(fn["ins"])
            if kind is None:
                if "--lift" not in sys.argv and "--lift-only" not in sys.argv:
                    continue
                kind = ("lift", {"ins": fn["lins"]})   # tools/tiny_lift.py (labels kept for --branch)
            elif "--lift-only" in sys.argv:
                continue
            rec = {"name": n, "addr": fn["addr"], "size": size, "unit": path.replace("\\", "/"), "kind": kind[0], "ir": kind[1]}
            if n.startswith("func_"):
                if "--func" not in sys.argv:
                    continue
                rec.update(file=None, demangled=None, conf=None)
            else:
                info = names.get(fn["addr"])
                ok = ("high", "medium") if "--medium" in sys.argv else ("high",)
                if not info or info[2] not in ok or not info[1].endswith(".cpp"):
                    continue
                d = demangle(n)
                if not d or "::" not in d.split("(")[0]:
                    continue
                rec.update(file=info[1], demangled=d, conf=info[2])
            out.append(rec)
    json.dump(out, sys.stdout, indent=1)


if __name__ == "__main__":
    main()
