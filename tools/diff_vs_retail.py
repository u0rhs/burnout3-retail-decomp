#!/usr/bin/env python3
"""Side-by-side compare of a compiled object's function against its retail .s disassembly.

Usage: diff_vs_retail.py <object.o> <retail.s> <glabel>[=<our symbol>]

Compares mnemonic + operands with relocation targets masked: retail's %hi/%lo/%gp_rel/symbol
operands and our unrelocated zeros both become '<r>', so only real instruction/register/offset
differences are flagged. A quick triage aid only -- the wire-in-and-relink SHA-1 is the proof.
"""
import re
import subprocess
import sys


def norm(ins):
    ins = re.sub(r"\s*/\*.*?\*/", "", ins).strip()   # spimdisasm's `/* handwritten instruction */` on ei/di (a77)
    # R5900 cvt.w.s (0x46000024 form): spimdisasm emits it as `.word ... # cvt.w.s $fD, $fS`, objdump in R5900
    # mode names the same encoding trunc.w.s
    m = re.match(r"\.word\s+0x[0-9A-Fa-f]+\s+#\s*cvt\.w\.s\s+(\S+),\s*(\S+)", ins)
    if m:
        ins = "trunc.w.s %s, %s" % (m.group(1), m.group(2))
    # COP2 instructions spimdisasm can't name (`.word 0x4A0103BD # vsqrt ...`) vs objdump's `c2 0x...` (the low 25 bits)
    m = re.match(r"\.word\s+(0x[0-9A-Fa-f]+|\d+)\s+#", ins)
    if m and (int(m.group(1), 0) >> 25) == 0x25:
        ins = "cop2word %d" % int(m.group(1), 0)
    m = re.match(r"c2\s+(0x[0-9A-Fa-f]+|\d+)$", ins.strip())
    if m:
        ins = "cop2word %d" % (0x4A000000 | int(m.group(1), 0))
    # sqrt.s: spimdisasm prints retail's word as `c1 <low 25 bits>`, objdump names it (near10: GetIKAngles, 0x46000544)
    m = re.match(r"c1\s+(0x[0-9A-Fa-f]+|\d+)$", ins.strip())
    if m:
        ins = "cop1word %d" % (0x46000000 | int(m.group(1), 0))
    m = re.match(r"sqrt\.s\s+\$?f(\d+),\s*\$?f(\d+)$", ins.strip())
    if m:
        ins = "cop1word %d" % (0x46000004 | (int(m.group(2)) << 11) | (int(m.group(1)) << 6))
    ins = re.sub(r"\s+", " ", ins)
    # keep the base register of a relocated operand (only $gp's is dropped, as ours strips `(gp)`): masking it hid
    # a v0/v1 base swap, 0 changed but 6 bytes off in the link (parkfix: DamageRaceCar__13CB3StageLogic)
    ins = re.sub(r"%(hi|lo|gp_rel)\([^)]*\)(\(\$?gp\))?", "<r>", ins)
    ins = ins.replace("$", "")
    # VU0 macro-mode syntax: spimdisasm writes qmtc2.ni / vf1, objdump qmtc2 / vf1w (same encodings)
    ins = re.sub(r"\b(qmtc2|qmfc2|ctc2|cfc2)\.ni\b", r"\1", ins)   # ctc2/cfc2 too (near6: same encoding)
    ins = re.sub(r"\b(vf\d+)[xyzw]{1,4}\b(?=,|$)", r"\1", ins) if re.match(r"v[a-z]+\d*\.[xyzw]+ ", ins) else ins   # \d*: vftoi0/vitof12 (v242)
    ins = re.sub(r"\bACC[xyzw]{1,4}\b", "ACC", ins)   # objdump's ACCx, spimdisasm's ACC (same accumulator)
    ins = re.sub(r"\bdaddu (\w+), ?(\w+), ?zero\b", r"move \1,\2", ins)
    # aliases spimdisasm and objdump spell differently (same encodings)
    ins = re.sub(r"(?<![a-z0-9_])s8(?![a-z0-9_])", "fp", ins)    # register 30: spimdisasm $fp, objdump s8
    ins = re.sub(r"^not (\w+), ?(\w+)$", r"nor \1,\2,zero", ins)
    # COP0 registers: objdump names them (c0_count), spimdisasm numbers them (9) -- same encoding (a166, GetTime)
    ins = re.sub(r"\bc0_(index|random|entrylo0|entrylo1|context|pagemask|wired|badvaddr|count|entryhi|compare|status|"
                 r"cause|epc|prid|config)\b", lambda m: str({"index": 0, "random": 1, "entrylo0": 2, "entrylo1": 3,
                 "context": 4, "pagemask": 5, "wired": 6, "badvaddr": 8, "count": 9, "entryhi": 10, "compare": 11,
                 "status": 12, "cause": 13, "epc": 14, "prid": 15, "config": 16}[m.group(1)]), ins)
    ins = re.sub(r"^ori (\w+), ?zero, ?(-?0x[0-9a-fA-F]+|-?\d+)$", lambda m: "li %s,%d" % (m.group(1), int(m.group(2), 0)), ins)
    ins = re.sub(r"\baddiu (\w+), ?zero, ?(-?0x[0-9a-fA-F]+|-?\d+)", lambda m: "li %s,%d" % (m.group(1), int(m.group(2), 0)), ins)
    # tidy1: the branch-likely zero compares too (bgtzl in func_002FC530's hand asm); targets still compared by --targets
    ins = re.sub(r"\b(jal|j|b|beqz|bnez|beq|bne|bc1t|bc1f|bc0t|bc0f|bc1tl|bc1fl|bc0tl|bc0fl|bgtz|bltz|blez|bgez|beql|bnel|bgtzl|bltzl|blezl|bgezl|bgezal|bltzal|bgezall|bltzall)\b (.*)", lambda m: m.group(1) + " " + re.sub(r"[^,]+$", "<t>", m.group(2)), ins)
    ins = re.sub(r"\blui (\w+), ?<r>", r"lui \1,<r>", ins)
    ins = re.sub(r"\blui (\w+), ?\(0x([0-9A-Fa-f]+) >> 16\)", lambda m: "lui %s,0x%x" % (m.group(1), int(m.group(2), 16) >> 16), ins)
    ins = re.sub(r"0x([0-9a-fA-F]+)", lambda m: str(int(m.group(1), 16)), ins)
    ins = re.sub(r"\((\d+) ?& ?(\d+)\)", lambda m: str(int(m.group(1)) & int(m.group(2))), ins)  # ori (K & 0xFFFF)
    ins = ins.replace(", ", ",")
    return ins


# %hi/%lo values of the D_XXXXXXXX symbols the retail function references: splat names some plain constants
# (an offset into a large object, e.g. D_0012AD28 in `D_00522660.field_12AD28[i]`) as symbols, so retail shows a
# relocation where our object has the same value as a literal -- identical bytes once linked (func_0038BE40)
ABS = {"hi": set(), "lo": set()}


def retail(path, label):
    out, on = [], False
    ABS["hi"].clear()
    ABS["lo"].clear()
    for line in open(path):
        if line.split()[:2] == ["glabel", label]:   # exact: a prefix matched ezNetCnfGetCombinationList (a99)
            on = True
            continue
        if on and line.split()[:2] == ["endlabel", label]:
            break
        m = re.match(r"\s*/\* \w+ \w+ \w+ \*/\s+(.*)", line)
        if on and m:
            # any symbol with a known address (not only D_XXXXXXXX): splat sometimes names a plain constant after a
            # nearby symbol, e.g. 0x12C6FC as %hi(__moddi3+0x4C) (Prepare__16CB3SoundListenerFUi
            for k, sym, off in re.findall(r"%(hi|lo)\(\s*([A-Za-z_.$][\w.$]*)\s*(?:\+\s*(0x[0-9A-Fa-f]+|\d+))?\s*\)", m.group(1)):
                base = sym_addr(sym)
                if base is None:
                    continue
                addr = base + (int(off, 0) if off else 0)
                if k == "hi":
                    ABS["hi"].add(((addr + 0x8000) >> 16) & 0xFFFF)
                else:
                    lo = addr & 0xFFFF
                    ABS["lo"].add(lo - 0x10000 if lo >= 0x8000 else lo)
            out.append(norm(m.group(1)))
    return out


_SYMS = None


def sym_addr(name):
    """A symbol's link address (config/symbol_addrs*.txt, the undefined-symbol files, D_XXXXXXXX), or None."""
    global _SYMS
    if _SYMS is None:
        _SYMS = {}
        for p in ("config/symbol_addrs_b3names.txt", "config/symbol_addrs.txt", "build/undefined_syms_auto.txt",
                  "config/undefined_syms_manual.txt", "build/lit4_retarget_defs.txt", "build/glabel_addrs.txt"):
            try:
                for l in open(p, errors="replace"):
                    m = re.match(r"\s*([A-Za-z_.$@][\w.$@]*)\s*=\s*(0x[0-9A-Fa-f]+|\d+)\s*;", l)
                    if m:
                        _SYMS.setdefault(m.group(1), int(m.group(2), 0))
            except OSError:
                pass
    if name in _SYMS:
        return _SYMS[name]
    m = re.match(r"D_([0-9A-Fa-f]{8})$", name)
    return int(m.group(1), 16) if m else None


# our relocated instructions resolved to the immediates retail prints when splat left a %hi/%lo pair as raw numbers
# (spilled pairs: `lui a0,0x67` / `lw a0,0x54D8(a0)`, MoveScreen__15CGtScreenCentreFff: index -> text
RESOLVED = {}


def ours(obj, label=None):
    """Our object's instructions; with `label`, only that function's (objects can hold several)."""
    txt = subprocess.run(["mips-linux-gnu-objdump", "-dr", "-z", "--no-show-raw-insn", obj],
                         capture_output=True, text=True).stdout
    out = []
    RESOLVED.clear()
    on = label is None
    for line in txt.splitlines():
        h = re.match(r"^[0-9a-f]+ <([^>]+)>:", line)
        if h and label is not None:
            on = h.group(1).strip() == label  # MWCC pads some local names (__sinit_*) with spaces
            continue
        r = re.match(r"\s*[0-9a-f]+: (R_MIPS_\w+)\s+(\S+)", line)
        if r:
            if on and out and r.group(1) in ("R_MIPS_HI16", "R_MIPS_LO16"):
                a = sym_addr(re.sub(r"[+-]0x[0-9a-f]+$", "", r.group(2)))
                mm = re.match(r"^(lui \w+,|.*?,)(-?\d+)(\(\w+\))?$", out[-1])
                if a is not None and mm:
                    imm = int(mm.group(2))
                    if r.group(1) == "R_MIPS_HI16":
                        v = (((a + (imm << 16)) + 0x8000) >> 16) & 0xFFFF
                    else:
                        lo = (a + imm) & 0xFFFF
                        v = lo - 0x10000 if lo >= 0x8000 else lo
                    RESOLVED[len(out) - 1] = "%s%d%s" % (mm.group(1), v, mm.group(3) or "")
            # a relocated immediate holds its REL addend (e.g. 36 for sym+0x24): mask it like retail's %lo(sym+K)
            if on and out and r.group(1) in ("R_MIPS_HI16", "R_MIPS_LO16", "R_MIPS_GPREL16"):
                out[-1] = re.sub(r",-?\d+(\(\w+\))$", r",0\1", out[-1])
                out[-1] = re.sub(r"^(lui \w+|addiu \w+,\w+),-?\d+$", r"\1,0", out[-1])
                out[-1] = re.sub(r"^((?:lwc1|swc1|lw|sw|lh|sh|lb|lbu|sb|lhu|ld|sd|lq|sq) \w+),-?\d+$", r"\1,0", out[-1])
            continue
        m = re.match(r"\s*[0-9a-f]+:\s+(\S.*)", line)
        if m and on:
            s = re.sub(r"\s*<[^>]*>$", "", m.group(1))
            s = re.sub(r"\(gp\)", "", s) if "gp" in s else s
            s = re.sub(r"(lwc1|lw|lbu|lb|sw) (\S+?),0(\(\w+\))?$", lambda mm: "%s %s,<r>%s" % (mm.group(1), mm.group(2), ""), s) if False else s
            out.append(norm(s))
    return out


BRANCH = re.compile(r"^\s*(jal|j|b|beqz|bnez|beq|bne|bc1t|bc1f|bgtz|bltz|blez|bgez|beql|bnel|bc1tl|bc1fl|bc0t|bc0f|bc0tl|bc0fl|bgezal|bltzal|bgtzl|bltzl|blezl|bgezl|bgezall|bltzall)\s+(.*)$")


def retail_targets(path, label):
    """Per instruction: a branch's target as a function-relative offset, a jal's callee name, else None."""
    out, on, base = [], False, None
    for line in open(path):
        if line.split()[:2] == ["glabel", label]:   # exact: a prefix matched ezNetCnfGetCombinationList (a99)
            on = True
            continue
        if on and line.split()[:2] == ["endlabel", label]:
            break
        m = re.match(r"\s*/\* \w+ (\w+) \w+ \*/\s+(.*)", line)
        if on and m:
            if base is None:
                base = int(m.group(1), 16)
            t = None
            b = BRANCH.match(m.group(2).replace("$", ""))
            if b:
                op = b.group(2).split(",")[-1].strip()
                if b.group(1) == "jal":
                    t = "s:" + op
                elif re.match(r"\.L[0-9A-F]{8}$", op):
                    t = "o:%x" % (int(op[2:], 16) - base)
            out.append(t)
    return out


def ours_targets(obj, label):
    txt = subprocess.run(["mips-linux-gnu-objdump", "-dr", "-z", "--no-show-raw-insn", obj],
                         capture_output=True, text=True).stdout
    out, on, base = [], False, 0
    for line in txt.splitlines():
        h = re.match(r"^([0-9a-f]+) <([^>]+)>:", line)
        if h:
            on = h.group(2).strip() == label
            base = int(h.group(1), 16)
            continue
        if not on:
            continue
        r = re.match(r"\s*[0-9a-f]+: (R_MIPS_\w+)\s+(\S+)", line)
        if r:
            if r.group(1) == "R_MIPS_26" and out and out[-1] == "s:?":
                out[-1] = "s:" + r.group(2)
            continue
        m = re.match(r"\s*[0-9a-f]+:\s+(\S.*)", line)
        if m:
            t = None
            b = BRANCH.match(re.sub(r"\s+", " ", m.group(1)))
            if b:
                if b.group(1) == "jal":
                    t = "s:?"
                else:
                    op = re.sub(r"\s*<[^>]*>$", "", b.group(2)).split(",")[-1].strip()
                    if re.match(r"^[0-9a-f]+$", op):
                        t = "o:%x" % (int(op, 16) - base)
            out.append(t)
    return out


def canon_ours(rb):
    # a literal equal to a retail D_ symbol's %hi / %lo (ABS above; a %lo only when large, so a real small field
    # offset is never masked)
    rb = re.sub(r"^lui (\w+),(\d+)$", lambda m: "lui %s,%s" % (
        m.group(1), "<r>" if int(m.group(2)) and int(m.group(2)) in ABS["hi"] else m.group(2)), rb)
    rb = re.sub(r",(-?\d+)(\(\w+\))", lambda m: ",%s%s" % (
        "<r>" if abs(int(m.group(1))) >= 0x800 and int(m.group(1)) in ABS["lo"] else m.group(1), m.group(2)), rb)
    # our relocation fields are zero; treat "x,0(reg)" vs "x,<r>(reg)" and "lui r,0" vs "lui r,<r>" as equal
    rb = re.sub(r",0(\(\w+\))", r",<r>\1", rb)
    rb = re.sub(r"^((?:lwc1|swc1|lw|sw|lh|sh|lb|lbu|sb|lhu|ld|sd|lq|sq) \w+),0$", r"\1,<r>", rb)  # $gp-relative, gp stripped
    rb = re.sub(r"^lui (\w+),0$", r"lui \1,<r>", rb)
    rb = re.sub(r"^(addiu \w+,(?!sp\b)\w+),0$", r"\1,<r>", rb)   # not sp: `addiu rX,sp,0` is a real 0 (a73)
    return rb      # parkfix: the base register stays (was dropped: `<r>(v0)` == `<r>(v1)`)


def lo_pair(ca, rb):
    """An aligned pair that differs only by a small displacement: ours `x,-695(v1)` where retail's line has the
    relocation `%lo(D_0012FD49)` (canonical `<r>`) and -695 is a retail symbol's %lo. canon_ours masks a %lo only
    when it is large, so a real small field offset is never hidden in general; here the aligned retail line itself
    says the field is relocated (func_0042AFC0."""
    rb2 = re.sub(r",(-?\d+)(\(\w+\))", lambda m: ",%s%s" % (
        "<r>" if int(m.group(1)) in ABS["lo"] else m.group(1), m.group(2)), rb)
    return rb2 != rb and "<r>" in ca and canon_ours(rb2) == ca


def canon_retail(ra):
    # the same %hi mask canon_ours applies: a literal `lui r,K` equal to a D_ symbol's %hi the function references
    # (retail spelling `lui at,(0x13B2D0 >> 16)` -> 19 vs ours masked; func_00199EB0/func_0019B380
    ra = re.sub(r"^lui (\w+),(\d+)$", lambda m: "lui %s,%s" % (
        m.group(1), "<r>" if int(m.group(2)) and int(m.group(2)) in ABS["hi"] else m.group(2)), ra)
    ra = re.sub(r",0(\(\w+\))", r",<r>\1", ra)  # a real zero offset looks like our unrelocated one
    return ra      # parkfix: the base register stays


def main():
    obj, s_path, label = sys.argv[1:4]
    # <retail glabel>=<our symbol>: compare under two names (e.g. a func_ placeholder we now name properly)
    rlabel, olabel = label.split("=", 1) if "=" in label else (label, label)
    a, b = retail(s_path, rlabel), ours(obj, olabel)
    if "--seq" in sys.argv:
        # alignment-aware: difflib over the canonical forms, so one inserted/missing instruction
        # doesn't make every later line "differ"
        import difflib
        ca, cb = [canon_retail(x) for x in a], [canon_ours(x) for x in b]
        changed = 0
        for op, i1, i2, j1, j2 in difflib.SequenceMatcher(None, ca, cb, autojunk=False).get_opcodes():
            if op == "equal":
                continue
            if op == "replace" and i2 - i1 == j2 - j1 and all(
                    lo_pair(ca[i1 + k], b[j1 + k]) or RESOLVED.get(j1 + k) == a[i1 + k]
                    or ca[i1 + k] == b[j1 + k]        # our raw line equals retail's: canon_ours masked a real 0 (a208)
                    for k in range(i2 - i1)):
                continue      # small %lo offsets where retail has the relocation (lo_pair), or retail's raw
                              # %hi/%lo numbers equal to our resolved relocation (RESOLVED)
            changed += max(i2 - i1, j2 - j1)
            print("%s retail %03x-%03x / ours %03x-%03x" % (op, i1 * 4, i2 * 4, j1 * 4, j2 * 4))
            for x in a[i1:i2]:
                print("   - " + x)
            for x in b[j1:j2]:
                print("   + " + x)
        if changed == 0 and "--targets" in sys.argv:
            # same instructions: also compare branch targets and jal callees (masked above)
            ta, tb = retail_targets(s_path, rlabel), ours_targets(obj, olabel)
            for k, (x, y) in enumerate(zip(ta, tb)):
                if x and y and y != "s:?" and x != y:
                    changed += 1
                    print("target at %03x: retail %s / ours %s" % (k * 4, x, y))
        print("retail %d instrs, ours %d instrs, %d instrs in changed runs" % (len(a), len(b), changed))
        return
    diffs = 0
    for i in range(max(len(a), len(b))):
        ra = a[i] if i < len(a) else ""
        rb = b[i] if i < len(b) else ""
        mark = "  " if canon_retail(ra) == canon_ours(rb) else "<>"
        if mark == "<>":
            diffs += 1
        print("%03x %s %-34s %s" % (i * 4, mark, ra, rb))
    print("retail %d instrs, ours %d instrs, %d differing lines" % (len(a), len(b), diffs))


if __name__ == "__main__":
    main()
