#!/usr/bin/env python3
"""pnach_map.py <file.pnach> [--md out.md]: map a PCSX2 .pnach patch onto the retail executable -- evidence for
decompilation (what code/data a community patch touches, so the function or global's purpose is known).

For every `patch=1,EE,<addr>,<type>,<value> // comment` line:
  - the address (cheat-type nibble stripped from `extended` codes: 0 = 8-bit, 1 = 16-bit, 2 = 32-bit write);
  - where it lands: inside a retail function (name, offset, matched or not, its source file if evidenced), on a
    known global (symbol tables), or outside both (a code cave the patch adds);
  - for code: retail's instruction there and the patched instruction (both disassembled);
  - for data: retail's value there and the patched value (as int and as float);
  - the patch's own comment (the community's description of what it changes).
Patches change the game; this tool only reads them. Their labels are evidence for comments ([L]), never symbol
names (docs/conventions.md naming rules).
Usage (repo root):  python tools/pnach_map.py ../<local archive>/pnach/SLUS-21050_BEBF8793.pnach --md research/pnach_widescreen.md"""
import bisect
import json
import os
import re
import struct
import subprocess
import sys
# run bash directly on Linux (repo on WSL's filesystem), through wsl.exe from Windows
BASH = ["bash"] if os.name != "nt" else ["wsl.exe", "bash"]

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ROM = os.path.join(ROOT, "orig", "SLUS_210.50.rom")
ROM_BASE = 0x100000


def load_funcs():
    tm = json.load(open(os.path.join(ROOT, "build", "tu_map.json")))
    pr = []
    for l in open(os.path.join(ROOT, "config", "proven_units.txt")):
        if l.startswith("#") or not l.strip():
            continue
        f = l.split(",")
        pr.append((int(f[0], 16), int(f[0], 16) + int(f[1], 16)))
    pr.sort()
    files = {f["name"]: f.get("file") for f in tm["funcs"]}
    # every function in the split assembly: glabel name -> first..last instruction address
    ins = re.compile(r"^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ")
    span = {}
    for dp, _, fns in os.walk(os.path.join(ROOT, "assembly", "asm")):
        for fn in fns:
            if not fn.endswith(".s"):
                continue
            cur = None
            for l in open(os.path.join(dp, fn), errors="replace"):
                if l.startswith("glabel "):
                    cur = l.split()[1]
                    continue
                m = ins.match(l)
                if m and cur:
                    a = int(m.group(1), 16)
                    lo, hi = span.get(cur, (a, a))
                    span[cur] = (min(lo, a), max(hi, a))
    fs = sorted((lo, hi + 4 - lo, n, files.get(n)) for n, (lo, hi) in span.items())

    def proven(a):
        i = bisect.bisect_right(pr, (a, 1 << 40)) - 1
        return i >= 0 and pr[i][0] <= a < pr[i][1]
    return fs, proven


def load_syms():
    syms = []
    for p in ("config/symbol_addrs_b3names.txt", "config/symbol_addrs.txt"):
        fp = os.path.join(ROOT, p)
        if not os.path.exists(fp):
            continue
        for l in open(fp, errors="replace"):
            m = re.match(r"\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+)\s*;(.*)$", l)
            if m:
                sz = re.search(r"size:0x([0-9A-Fa-f]+)", m.group(3))
                syms.append((int(m.group(2), 16), m.group(1), int(sz.group(1), 16) if sz else 0))
    return sorted(set(syms))


def load_xrefs():
    """{D_ label address: set of functions referencing it}, from the split assembly and the matched source."""
    refs = {}
    glab = re.compile(r"^glabel (\S+)")
    dref = re.compile(r"\bD_([0-9A-F]{8})\b")
    for base, ext in (("assembly/asm", ".s"), ("src", ".cpp"), ("src", ".c")):
        for dp, _, fns in os.walk(os.path.join(ROOT, base)):
            for fn in fns:
                if not fn.endswith(ext) or "nonmatching" in dp:
                    continue
                cur = os.path.splitext(fn)[0]
                for l in open(os.path.join(dp, fn), errors="replace"):
                    m = glab.match(l)
                    if m:
                        cur = m.group(1)
                        continue
                    if ext == ".s" and not l.lstrip().startswith("/*"):
                        continue          # only instruction lines, not data tables
                    for a in dref.findall(l):
                        refs.setdefault(int(a, 16), set()).add(cur)
    return refs


def disasm(words):
    """{addr: text} for little-endian 32-bit words, via objdump (R5900)."""
    if not words:
        return {}
    blob = b"".join(struct.pack("<I", w) for _, w in words)
    tmp = os.path.join(ROOT, "build", "vt", "pnach_tmp.bin")
    open(tmp, "wb").write(blob)
    wtmp = "/mnt/" + tmp[0].lower() + tmp[2:].replace("\\", "/")
    r = subprocess.run(BASH + ["-c", "mips-linux-gnu-objdump -D -b binary -m mips:5900 -EL %s" % wtmp],
                       capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV="1"))
    out = {}
    for l in r.stdout.splitlines():
        m = re.match(r"\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+(.*)$", l)
        if m:
            k = int(m.group(1), 16) // 4
            if k < len(words):
                t = m.group(2).split(";")[0].strip()
                b = re.match(r"(b\w*\s+(?:[^,]+,)*)0x([0-9a-f]+)$", t)
                if b:                     # PC-relative: rebase from the blob onto the real address
                    t = "%s0x%X" % (b.group(1), words[k][0] + int(b.group(2), 16) - 4 * k)
                out[words[k][0]] = t
    return out


def main():
    src = sys.argv[1]
    md = sys.argv[sys.argv.index("--md") + 1] if "--md" in sys.argv else None
    rom = open(ROM, "rb").read()
    fs, proven = load_funcs()
    starts = [f[0] for f in fs]
    syms = load_syms()
    saddr = [s[0] for s in syms]
    xrefs = load_xrefs()
    xaddr = sorted(xrefs)
    rows, section, cont, skipped = [], "", None, []
    for line in open(src, errors="replace"):
        line = line.rstrip("\n")
        if line.startswith("["):
            section = line.strip("[]")
            cont = None
            continue
        m = re.match(r"\s*patch=\d+,EE,([0-9A-Fa-f]{8}),(\w+),([0-9A-Fa-f]+)\s*(?://\s*(.*))?$", line)
        if not m:
            continue
        raw, typ, val, note = int(m.group(1), 16), m.group(2).lower(), int(m.group(3), 16), (m.group(4) or "").strip()
        if cont:                          # second line of a two-line code (exports split it into its own patch=)
            kind, first = cont
            cont = None
            if kind == "serial":
                a0, n, step = first
                for k in range(min(n, 64)):
                    rows.append(dict(section=section, addr=a0 + 4 * k * step, width=4, val=raw, note=note,
                                     how="serial write %d/%d" % (k + 1, n)))
            elif kind == "inc":
                rows.append(dict(section=section, addr=first, width=4, val=raw, note=note, how="32-bit add/sub"))
            continue
        if typ == "extended":
            kind = raw >> 28
            addr = raw & 0x0FFFFFFF
            if kind in (0, 1, 2):
                rows.append(dict(section=section, addr=addr, width={0: 1, 1: 2, 2: 4}[kind], val=val, note=note,
                                 how="write"))
            elif kind == 3:               # 300000nn/3010..(8-bit), 3020/3030 (16-bit): address in the value field
                sub = (raw >> 20) & 0xF
                if sub in (4, 5):
                    cont = ("inc", val & 0x0FFFFFFF)
                else:
                    rows.append(dict(section=section, addr=val & 0x0FFFFFFF, width=1 if sub < 2 else 2,
                                     val=raw & 0xFFFF, note=note, how="add/sub"))
            elif kind == 4:               # 4aaaaaaa nnnnssss + (value, increment): serial write
                cont = ("serial", (addr, val >> 16, max(val & 0xFFFF, 1)))
            elif kind in (0xD, 0xE):      # conditionals: the address is read, not written
                a = addr if kind == 0xD else val & 0x0FFFFFFF
                rows.append(dict(section=section, addr=a, width=2, val=(raw if kind == 0xE else val) & 0xFFFF,
                                 note=note, how="condition (read)"))
            else:                         # 5/6/7/C codes and encrypted leftovers (8, 9, A, B, F)
                skipped.append((section, line.strip()))
        else:
            addr = raw & 0x1FFFFFFF       # 0x20000000.. is EE's uncached mirror of the same RAM
            width = {"byte": 1, "short": 2, "word": 4}.get(typ, 4)
            rows.append(dict(section=section, addr=addr, width=width, val=val, note=note, how="write"))
    rows = [r for r in rows if 0x100000 <= r["addr"] < 0x2000000]
    # classify
    code_words_old, code_words_new = [], []
    for r in rows:
        a = r["addr"]
        i = bisect.bisect_right(starts, a) - 1
        r["func"] = None
        if i >= 0 and fs[i][0] <= a < fs[i][0] + fs[i][1]:
            f = fs[i]
            r["func"] = "%s+0x%X" % (f[2], a - f[0])
            r["matched"] = proven(f[0])
            r["file"] = f[3]
        j = bisect.bisect_right(saddr, a) - 1
        r["sym"] = None
        if j >= 0 and (saddr[j] == a or saddr[j] <= a < saddr[j] + max(syms[j][2], 1)):
            r["sym"] = syms[j][1] + ("" if saddr[j] == a else "+0x%X" % (a - saddr[j]))
        o = a - ROM_BASE
        if 0 <= o and o + 4 <= len(rom):
            old = rom[o:o + r["width"]]
            r["old"] = int.from_bytes(old, "little")
        else:
            r["old"] = None
        if r["func"] and r["width"] == 4:
            code_words_old.append((a, r["old"] or 0))
            code_words_new.append((a, r["val"]))
    dold, dnew = disasm(code_words_old), disasm(code_words_new)

    def f32(x):
        return struct.unpack("<f", struct.pack("<I", x & 0xFFFFFFFF))[0]
    out = ["# pnach map: %s" % os.path.basename(src), "",
           "Generated by `tools/pnach_map.py`. Labels are the patch authors' descriptions: evidence for comments ([L]), "
           "never symbol names. A data address with many users is usually a pooled literal (`.lit4`): the patch changes "
           "every user, and only one of them is its intent.", "",
           "| Section | Address | Where | Retail | Patched | Patch comment |", "|---|---|---|---|---|---|"]
    for r in rows:
        if r["how"] == "condition (read)":
            r["val_text"] = "if == 0x%X (read)" % r["val"]
        if r["func"]:
            where = "`%s` (%s%s)" % (r["func"], "matched" if r.get("matched") else "unmatched",
                                    (", " + r["file"]) if r.get("file") else "")
            if r["width"] == 4:
                ret, new = dold.get(r["addr"], "?"), dnew.get(r["addr"], "?")
            else:
                ret, new = "0x%X" % (r["old"] or 0), "0x%X (%d-bit write)" % (r["val"], 8 * r["width"])
        elif r["sym"]:
            where = "`%s` (data)" % r["sym"]
            ret = "0x%X" % r["old"] if r["old"] is not None else "-"
            new = "0x%X" % r["val"]
            if r["width"] == 4 and r["old"] is not None:
                ret += " (%.6gf)" % f32(r["old"])
                new += " (%.6gf)" % f32(r["val"])
        else:
            where = "data" if r["old"] is not None else "BSS (not in the ELF file; runtime patch only)"
            ret = "0x%X" % r["old"] if r["old"] is not None else "-"
            new = "0x%X" % r["val"]
            if r["width"] == 4 and r["old"] is not None:
                ret += " (%.6gf)" % f32(r["old"])
                new += " (%.6gf)" % f32(r["val"])
        if not r["func"]:
            # readers: functions referencing the nearest D_ label at or below the address (within 0x40)
            k = bisect.bisect_right(xaddr, r["addr"]) - 1
            if k >= 0 and r["addr"] - xaddr[k] < 0x40:
                lab, us = xaddr[k], sorted(xrefs[xaddr[k]])
                where += "; `D_%08X`%s used by %s" % (lab, "" if lab == r["addr"] else "+0x%X" % (r["addr"] - lab),
                                                       ", ".join("`%s`" % u for u in us[:4]) +
                                                       (" +%d more" % (len(us) - 4) if len(us) > 4 else ""))
        if r["how"] != "write":
            new = r.get("val_text") or "%s (%s)" % (new, r["how"])
        r["where"] = where
        out.append("| %s | 0x%08X | %s | %s | %s | %s |" % (r["section"].replace("|", "/"), r["addr"], where, ret, new,
                                                            r["note"].replace("|", "/")))
    # by address: every datum the codes touch, with all the code names that touch it (the evidence for its meaning)
    by = {}
    for r in rows:
        if not r["func"]:
            by.setdefault(r["addr"], []).append(r)
    out += ["", "## Data addresses (%d), with every code that touches each" % len(by), "",
            "| Address | Where / readers | Codes |", "|---|---|---|"]
    for a in sorted(by):
        names = sorted(set(("%s%s" % (x["section"], " (read)" if x["how"].startswith("condition") else ""))
                           .replace("|", "/") for x in by[a]))
        out.append("| 0x%08X | %s | %s |" % (a, by[a][0]["where"],
                                              "; ".join(names[:6]) + (" +%d more" % (len(names) - 6)
                                                                      if len(names) > 6 else "")))
    if skipped:
        out += ["", "Skipped (%d lines: copy/pointer/bitwise codes or encrypted leftovers): %s" %
                (len(skipped), ", ".join(sorted(set(s for s, _ in skipped)))[:2000])]
    text = "\n".join(out) + "\n"
    if md:
        open(md, "w", encoding="utf-8", newline="\n").write(text)
        print("wrote", md, "(%d patch lines)" % len(rows))
    else:
        print(text)


if __name__ == "__main__":
    main()
