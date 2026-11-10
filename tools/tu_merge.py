"""tu_merge.py [--jobs N] [--only STEM ...] [--dry]: regroup proven per-function units into their original translation
units (one source file per retail .cpp), in their Area folder when one is evidenced; re-runs fold new units into the
existing merged files and move a merged file out of _unclassified/ when new folder evidence turns up.

Membership (tools/tu_map.py): research/retail_names.csv names the function's file [C]; a medium-confidence name
confirmed by its neighbour [L]; or the function sits between two functions of the file in address order [L] (N2).

Folder, first evidence that applies (docs/layout.md table, tools/layout_tu_table.py):
  1. a hand-placed file of the same unit already in an Area folder (its own docs/layout.md row);
  2. [L] Revenge (SLUS_212.42 functions.csv) has a file of the same name (B3X <-> B4X, GtX <-> GtX) in one folder;
  3. [L] Revenge has the unit's class (CB3X <-> CB4X, CGtX) with every method in one folder;
  4. [G] a domain word in the file name that Revenge's own file names tie to one folder: >= 85% of its >= 5 Revenge
     files with that word are in that folder (e.g. HUD -> GameSource/Hud, 37 of 38), no other such word disagreeing;
  otherwise _unclassified/.

Per translation unit, the existing merged file's functions (if any) are the base and new units are added one at a
time in address order: compiled, split back into one object per function (tools/split_tu_obj.py), every piece
identical to that unit's current object (tools/obj_same.py), else the unit just added is dropped again and logged
PARKED and the merge goes on. Then the full retail link with all its pieces must match (tools/relink_check.sh), or the
translation unit is left as it was. Accepted ones are installed: merged source written (moved if its folder changed),
per-function sources removed, config/proven_units.txt and config/tu_units.txt updated.

Only lifted single-function units that declare no shared type locally (tools/hdr_consolidate.py adopted them, or they
need none) are merged; the others are logged SKIP. Log: build/tu/merge.log."""
import collections
import csv
import json
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import split_tu_obj  # noqa: E402
# run bash directly on Linux (repo on WSL's filesystem), through wsl.exe from Windows
BASH = ["bash"] if os.name != "nt" else ["wsl.exe", "bash"]

UNC = ROOT / "src" / "b3" / "_unclassified"
WORK = ROOT / "build" / "tu"
REV = ROOT / "research" / "burnout3-symbols" / "data" / "burnout-revenge-prototype" / "SLUS_212.42" / "functions.csv"
WSL_REPO = "${B3_ROOT}"
LOG = []


def log(s):
    LOG.append(s)
    print(s, flush=True)


def wsl(cmd, timeout=3600):
    r = subprocess.run(BASH + ["-c", "cd %s && %s" % (WSL_REPO, cmd)], capture_output=True, text=True,
                       timeout=timeout)
    return r.returncode, r.stdout + r.stderr


def rel(p):
    return str(Path(p).relative_to(ROOT)).replace("\\", "/")


# --- folder evidence ---------------------------------------------------------------------------------------------------
def words(s):
    s = re.sub(r"^(B4|B3|Gt)", "", s)
    return re.findall(r"HUD|PS2|[A-Z][a-z]+|[A-Z]+(?![a-z])|\d+", s)


class Evidence:
    def __init__(self):
        self.by_base = collections.defaultdict(set)              # Revenge file name -> folders
        self.cls = collections.defaultdict(collections.Counter)  # Revenge class -> folders
        files = set()
        for r in csv.DictReader(open(REV, encoding="utf-8")):
            sf = r["source_file"]
            if not sf.startswith(("GameSource/", "GameShared/", "SharedClasses/")):
                continue
            folder, base = sf.rsplit("/", 1)
            self.by_base[base].add(folder)
            files.add(sf)
            m = re.match(r"(\w+)::", r["demangled"] or "")
            if m:
                self.cls[m.group(1)][folder] += 1
        tok = collections.defaultdict(collections.Counter)
        for sf in files:
            folder, base = sf.rsplit("/", 1)
            for w in set(words(base[:-4])):
                tok[w][folder] += 1
        self.domain = {}
        for w, c in tok.items():
            n = sum(c.values())
            f, k = c.most_common(1)[0]
            if n >= 5 and k >= 0.85 * n:
                self.domain[w] = (f, k, n)
        # hand-placed units: a file in an Area folder named after the stem (stem.cpp or stem_XXXXXXXX.cpp) that
        # tools/tu_merge.py did not write
        merged = {l.split()[0] for l in open(ROOT / "config" / "tu_units.txt") if l.strip() and not l.startswith("#")} \
            if (ROOT / "config" / "tu_units.txt").exists() else set()
        self.hand = {}
        for root, _, fs in os.walk(ROOT / "src" / "b3"):
            if "_unclassified" in root:
                continue
            for f in fs:
                p = rel(Path(root) / f)
                if f.endswith(".cpp") and p not in merged:
                    stem = re.sub(r"_[0-9A-F]{8}$", "", f[:-4])
                    self.hand.setdefault(stem, rel(Path(root)))
        # each retail file's dominant class (retail_names.csv, high + medium)
        self.stem_cls = collections.defaultdict(collections.Counter)
        for r in csv.DictReader(open(ROOT / "research" / "retail_names.csv", encoding="utf-8")):
            if r["source"].endswith(".cpp") and r["confidence"] in ("high", "medium"):
                m = re.match(r"(\w+)::", r["name"])
                if m:
                    self.stem_cls[r["source"][:-4]][m.group(1)] += 1

    @staticmethod
    def repo(folder):
        parts = folder.split("/")
        if parts[0] == "GameSource":
            return ("src/b3/gamesource/" + "/".join(parts[1:])).rstrip("/")
        return "src/b3/" + folder

    def area(self, stem):
        """(repo folder or None, evidence text)."""
        if stem in self.hand:
            return self.hand[stem], "Area: %s, same unit as the hand-placed file there (its docs/layout.md row)" % \
                self.hand[stem]
        cands = (["B4" + stem[2:] + ".cpp", stem + ".cpp"] if stem.startswith("B3") else [stem + ".cpp"])
        hits = set()
        for c in cands:
            hits |= self.by_base.get(c, set())
        if len(hits) == 1:
            f = hits.pop()
            used = next(c for c in cands if c in self.by_base)
            return self.repo(f), "Area: %s, [L] Revenge (SLUS_212.42) %s/%s" % (self.repo(f), f, used)
        why = "Revenge has %d folders for its file name" % len(hits) if hits else "no Revenge file of that name"
        cl = self.stem_cls.get(stem)
        if cl:
            c = cl.most_common(1)[0][0]
            rc = "CB4" + c[3:] if c.startswith("CB3") else c
            fo = self.cls.get(rc) or self.cls.get(c)
            if fo and len(fo) == 1:
                f = list(fo)[0]
                return self.repo(f), "Area: %s, [L] Revenge (SLUS_212.42) keeps class %s (as %s) with all %d of its " \
                    "methods in %s/" % (self.repo(f), c, rc if self.cls.get(rc) else c, sum(fo.values()), f)
            if fo:
                why += "; class %s in %d Revenge folders" % (c, len(fo))
        ds = {w: self.domain[w] for w in set(words(stem)) if w in self.domain}
        folders = {v[0] for v in ds.values()}
        if len(folders) == 1:
            f = folders.pop()
            w = sorted(ds)[0]
            return self.repo(f), "Area: %s, [G] domain word `%s` in the name: %d of Revenge's %d files with it are " \
                "in %s/" % (self.repo(f), w, ds[w][1], ds[w][2], f)
        if len(folders) > 1:
            why += "; domain words disagree (%s)" % ", ".join(sorted(ds))
        return None, "Area not evidenced (%s), so _unclassified/ (docs/conventions.md)" % why


# --- unit sources ------------------------------------------------------------------------------------------------------
def parse_parts(text, name, need_body=True):
    """Unit text -> parts: head comment lines, prelude, fwd, local type blocks, enums, externs, decls, body."""
    lines = text.split("\n")
    U = {"head": [], "prelude": [], "fwd": [], "types": [], "enums": [], "externs": [], "decls": [], "body": None}
    i = 0
    while i < len(lines) and lines[i].startswith("//") and not re.match(r"// 0x[0-9A-F]{8}$", lines[i]):
        U["head"].append(lines[i])
        i += 1
    while i < len(lines):
        ln = lines[i]
        if re.match(r"// 0x[0-9A-F]{8}$", ln):
            U["body"] = "\n".join(lines[i:]).rstrip("\n")
            break
        if not ln.strip() or ln.startswith("//"):
            i += 1
        elif re.match(r"^(class|struct) \w+;$", ln):
            U["fwd"].append(ln)
            i += 1
        elif re.match(r"^enum \w+ \{\};$", ln):
            U["enums"].append(ln)
            i += 1
        elif ln.startswith("#include") or ln.startswith("typedef ") or ln.startswith("namespace "):
            U["prelude"].append(ln)
            i += 1
        elif re.match(r"^(class|struct) \w+.* \{$", ln):
            j = i
            while lines[j] != "};":
                j += 1
            U["types"].append((re.match(r"^(?:class|struct) (\w+)", ln).group(1), "\n".join(lines[i:j + 1])))
            i = j + 1
        elif ln.startswith('extern "C" '):        # a declaration (definitions only follow a `// 0x` marker)
            U["decls"].append(ln)
            i += 1
        elif ln.startswith("extern "):
            U["externs"].append(ln)
            i += 1
        else:
            raise ValueError("%s: unexpected line %r" % (name, ln))
    if U["body"] is None and need_body:
        raise ValueError("%s: no body" % name)
    return U


def parse_unit(path):
    return parse_parts(open(path, encoding="utf-8").read(), path.name)


def parse_tu(path, vram_unit):
    """An existing merged file -> [(addr, unit, U)]: its preamble goes with the first function."""
    text = open(path, encoding="utf-8").read()
    lines = text.split("\n")
    starts = [k for k, l in enumerate(lines) if re.match(r"// 0x[0-9A-F]{8}$", l)]
    if not starts:
        raise ValueError("%s: no functions" % path)
    heads = []
    for s in starts:
        h = s
        while h > 0 and lines[h - 1].startswith("//") and s - h < 2:
            h -= 1
        heads.append(h)
    pre = parse_parts("\n".join(lines[:heads[0]]), path.name, need_body=False)
    out = []
    for n, (h, s) in enumerate(zip(heads, starts)):
        end = heads[n + 1] if n + 1 < len(heads) else len(lines)
        body = "\n".join(lines[s:end]).rstrip("\n")
        addr = int(lines[s][5:], 16)
        if addr not in vram_unit:
            raise ValueError("%s: function at 0x%X is not a proven unit" % (path, addr))
        U = {"head": lines[h:s], "prelude": [], "fwd": [], "types": [], "enums": [], "externs": [], "decls": [],
             "body": body}
        if n == 0:
            for k in ("prelude", "fwd", "types", "enums", "externs", "decls"):
                U[k] = pre[k]
        out.append((addr, vram_unit[addr], U))
    return out


def shared_local(U):
    """Shared types (tools/hdr_consolidate.is_shared) this unit still declares itself."""
    return [n for n, _ in U["types"] if not re.fullmatch(r"UnkStruct_([0-9A-F]{8}(_\w+)?|func_\w+)", n)] + U["enums"]


def decl_symbol(d):
    m = re.match(r'^extern "C" .*?\b(\w+)\((.*)\);', d)
    return m.group(1) if m else None


def split_top(s):
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch == "," and depth == 0:
            out.append(cur.strip())
            cur = ""
            continue
        depth += (ch in "(<") - (ch in ")>")
        cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def unify_decls(a, b):
    """Two C-linkage declarations of one function as one, or None: parameters that are pointers in both become
    `void *` (a pointer argument converts to it; the call compiles the same), and a `void` return yields to a value
    return (a caller that ignores the result compiles the same). The per-function compile check decides the rest."""
    pa = re.match(r'^extern "C" (.*?)\b(\w+)\((.*)\);(.*)$', a)
    pb = re.match(r'^extern "C" (.*?)\b(\w+)\((.*)\);(.*)$', b)
    if not pa or not pb:
        return None
    ra, rb = pa.group(1).strip(), pb.group(1).strip()
    if ra != rb and "void" not in (ra, rb):
        return None
    rt = rb if ra == "void" else ra
    xa, xb = split_top(pa.group(3)), split_top(pb.group(3))
    if len(xa) != len(xb):
        return None
    ps = []
    for x, y in zip(xa, xb):
        if x == y:
            ps.append(x)
        elif "*" in x and "*" in y:
            ps.append("const void *" if "const" in x or "const" in y else "void *")
        else:
            return None
    return 'extern "C" %s %s(%s);%s' % (rt, pa.group(2), ", ".join(ps), pa.group(4))


def extern_symbol(d):
    m = re.match(r"^extern .*?\b(\w+)(\[[^\]]*\])?;", d)
    return m.group(1) if m else None


def compose(stem, units, area_ev, name_ev):
    """The merged translation unit's text from its units (address order)."""
    pre, inc, fwd, types, externs, decls = [], [], [], [], [], []
    seen_ext, seen_decl = {}, {}
    for addr, unit, U in units:
        for p in U["prelude"]:
            if p not in pre + inc:
                (inc if p.startswith("#include") else pre).append(p)
        for f in U["fwd"]:
            if f not in fwd:
                fwd.append(f)
        types += [t for _, t in U["types"]]
        for e in U["externs"]:
            s = extern_symbol(e)
            if s in seen_ext and seen_ext[s] != e:
                raise ValueError("extern %s declared two ways" % s)
            if s not in seen_ext:
                seen_ext[s] = e
                externs.append(e)
        for d in U["decls"]:
            s = decl_symbol(d)
            if s in seen_decl and seen_decl[s] != d:
                u = unify_decls(seen_decl[s], d)
                if u is None:
                    raise ValueError("function %s declared two ways" % s)
                decls[decls.index(seen_decl[s])] = u
                seen_decl[s] = u
                continue
            if s not in seen_decl:
                seen_decl[s] = d
                decls.append(d)
    for addr, unit, U in units:
        m = re.match(r'// 0x[0-9A-F]{8}\nextern "C" (.*?)\b(\w+)\((.*)\)\n\{', U["body"])
        if m and m.group(2) in seen_decl:
            d = seen_decl[m.group(2)]
            want = 'extern "C" %s%s(%s);' % (m.group(1), m.group(2), m.group(3))
            norm = lambda x: re.sub(r"\s*\b[pnf]\d+\b", "", x.replace(" ", ""))
            if norm(want) != norm(d):
                raise ValueError("%s defined and declared two ways" % m.group(2))
            decls.remove(d)
    out = ["// %s.cpp -- translation unit regrouped by tools/tu_merge.py from %d proven function(s) (tools/tiny_batch.py)."
           % (stem, len(units)),
           "// [C]/[L] membership: %s." % name_ev,
           "// %s." % area_ev,
           "// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are",
           "// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.",
           ""]
    for blk in (sorted(pre, key=lambda p: (not p.startswith("typedef"), p)), sorted(inc), fwd, types, externs, decls):
        if blk:
            out += blk + [""]
    for addr, unit, U in units:
        out += [h for h in U["head"][:2]]
        out.append(U["body"])
        out.append("")
    return re.sub(r"\n\n\n+", "\n\n", "\n".join(out))


_symcache = {}


def unit_symbol(u):
    if u not in _symcache:
        e, flags, secs = split_tu_obj.read_elf(ROOT / "build" / "mw" / (u + ".o"))
        fs = [s for s in split_tu_obj.symbols(secs) if s["type"] == 2 and s["shndx"] not in (0, 0xFFF1)]
        if len(fs) != 1:
            raise ValueError("%s: %d functions in its object" % (u, len(fs)))
        _symcache[u] = fs[0]["name"]
    return _symcache[u]


def try_build(stem, units, area_ev, name_ev, tag):
    d = WORK / stem
    d.mkdir(parents=True, exist_ok=True)
    try:
        text = compose(stem, units, area_ev, name_ev)
        args = " ".join("%s=%s" % (unit_symbol(u), u) for _, u, _ in units)
    except ValueError as e:
        return False, "compose: %s" % e
    src = d / (stem + ".cpp")
    open(src, "w", encoding="utf-8", newline="\n").write(text)
    pieces = d / ("pieces_" + tag)
    if pieces.exists():
        for f in pieces.iterdir():
            os.remove(f)
    pieces.mkdir(exist_ok=True)
    obj = d / (stem + ".o")
    if obj.exists():
        os.remove(obj)
    cmd = ("bash tools/tiny_compile.sh %s %s; python3 -I tools/split_tu_obj.py %s %s %s && "
           "for u in %s; do python3 -I tools/obj_same.py %s/$u.o build/mw/$u.o || echo \"PIECE $u\"; done"
           % (rel(src), rel(obj), rel(obj), rel(pieces), args, " ".join(u for _, u, _ in units), rel(pieces)))
    rc, out = wsl(cmd)
    if not obj.exists():
        return False, "compile: " + " ".join(out.split())[:300]
    if "REFUSED" in out:
        return False, out.strip().split("\n")[-1][:300]
    if "PIECE" in out or "differs" in out:
        return False, "changed: " + " ".join(out.split())[:300]
    return True, text


def merge_tu(stem, base, cands, area_ev, name_ev, moves=False):
    """base: the existing file's functions (accepted as they are); cands: new units; moves: the file's folder changes
    (installed even when no new unit merges). -> (accepted, text, parked, status)."""
    acc, parked = list(base), []
    if base:
        ok, msg = try_build(stem, acc, area_ev, name_ev, "t")
        if not ok:
            return [], None, [], "existing file no longer builds identically: " + msg[:200]
    for c in cands:
        trial = sorted(acc + [c], key=lambda x: x[0])
        ok, msg = try_build(stem, trial, area_ev, name_ev, "t")
        if ok:
            acc = trial
        else:
            parked.append((c[1], msg))
    if len(acc) == len(base) and not moves:
        return [], None, parked, "nothing new merged"
    ok, msg = try_build(stem, acc, area_ev, name_ev, "final")
    if not ok:
        return [], None, parked + [(u, "final build: " + msg[:200]) for a, u, U in acc if (a, u, U) not in base], \
            "final build failed"
    text = msg
    pieces = WORK / stem / "pieces_final"
    subs = " ".join("%s=%s/%s.o" % (u, rel(pieces), u) for _, u, _ in acc)
    rc, out = wsl("bash tools/relink_check.sh %s %s" % (rel(WORK / stem / "link"), subs))
    if rc != 0 or "MATCHES RETAIL" not in out:
        return [], None, parked + [(c[1], "relink: " + out.strip()[:200]) for c in cands], "relink failed"
    return acc, text, parked, "MATCHES RETAIL"


def main():
    jobs = int(sys.argv[sys.argv.index("--jobs") + 1]) if "--jobs" in sys.argv else 12
    only = set(sys.argv[sys.argv.index("--only") + 1:]) if "--only" in sys.argv else None
    dry = "--dry" in sys.argv
    WORK.mkdir(parents=True, exist_ok=True)
    subprocess.run([sys.executable, str(ROOT / "tools" / "tu_map.py")], capture_output=True)
    tm = json.load(open(ROOT / "build" / "tu_map.json"))
    func_file = {f["addr"]: (f["file"], f["file_ev"]) for f in tm["funcs"]}
    proven, vram_unit = [], {}
    for line in open(ROOT / "config" / "proven_units.txt"):
        if line.startswith("#") or not line.strip():
            continue
        f = line.strip().split(",")
        proven.append((int(f[0], 16), int(f[1], 16), int(f[2]), f[3], f[4]))
        vram_unit[int(f[0], 16)] = f[3]
    ev = Evidence()
    tu_file = {}
    tu_path = ROOT / "config" / "tu_units.txt"
    if tu_path.exists():
        for l in open(tu_path):
            if l.strip() and not l.startswith("#"):
                p = l.split()[0]
                tu_file[Path(p).stem] = p
    # units with their own compile script (post-processing a merged compile would skip: lit4/jtbl retargets)
    scripted = set()
    for sp in (ROOT / "tools").glob("compile_*.sh"):
        scripted |= set(re.findall(r"\\(\w+)\.cpp\"", sp.read_text(errors="replace")))
    groups = collections.defaultdict(list)
    for vram, size, nf, unit, src in proven:
        p = ROOT / src
        if not src.startswith("src/b3/_unclassified/") or p.stem != unit:
            continue                                # already in a merged file, or hand-placed
        ff, fev = func_file.get(vram, (None, None))
        if not ff:
            continue
        stem = ff[:-4]
        if only and stem not in only:
            continue
        if nf != 1:
            log("SKIP %s %s: %d functions in one unit" % (stem, unit, nf))
            continue
        if unit in scripted:
            log("SKIP %s %s: built by its own tools/compile_*.sh (lit4/jtbl retarget)" % (stem, unit))
            continue
        try:
            U = parse_unit(p)
        except ValueError as e:
            log("SKIP %s %s: %s" % (stem, unit, e))
            continue
        sl = shared_local(U)
        if sl:
            log("SKIP %s %s: declares shared types locally (%s)" % (stem, unit, ", ".join(sl[:3])))
            continue
        groups[stem].append((vram, unit, U, fev))
    # merged files that may move (new folder evidence) even without new units
    for stem, p in tu_file.items():
        if (only is None or stem in only) and "/_unclassified/" in p and stem not in groups:
            if ev.area(stem)[0]:
                groups[stem] = []
    todo = []
    for stem, us in sorted(groups.items()):
        us.sort(key=lambda x: x[0])
        base = []
        if stem in tu_file:
            try:
                base = parse_tu(ROOT / tu_file[stem], vram_unit)
            except ValueError as e:
                log("SKIP %s: existing file: %s" % (stem, e))
                continue
        area, area_ev = ev.area(stem)
        if area is None:
            area = "src/b3/_unclassified"
        allf = [func_file.get(a, (None, None))[1] for a, _, _ in base] + [x[3] for x in us]
        name_ev = "%d function(s) named in research/retail_names.csv -> %s.cpp" % (allf.count("C"), stem)
        if allf.count("Lm"):
            name_ev += ", %d by a medium-confidence name confirmed by a neighbour" % allf.count("Lm")
        if allf.count("L"):
            name_ev += ", %d placed between two of them by address contiguity (N2)" % allf.count("L")
        todo.append((stem, base, [(a, u, U) for a, u, U, _ in us], area, area_ev, name_ev))
    log("translation units: %d (%d existing files, %d new units)" % (
        len(todo), sum(1 for t in todo if t[1]), sum(len(t[2]) for t in todo)))
    results = []
    with ThreadPoolExecutor(max_workers=jobs) as ex:
        futs = [ex.submit(merge_tu, stem, base, cands, aev, nev,
                          bool(base) and tu_file.get(stem, "").rsplit("/", 1)[0] != area)
                for stem, base, cands, area, aev, nev in todo]
        for f, t in zip(futs, todo):
            acc, text, parked, status = f.result()
            for u, why in parked:
                log("PARKED %s %s: %s" % (t[0], u, why))
            log("TU %s: %d existing + %d/%d new units -> %s, %s" % (
                t[0], len(t[1]), len(acc) - len(t[1]) if acc else 0, len(t[2]), t[3], status))
            results.append((t, acc, text))
    open(WORK / "merge.log", "a").write("\n".join(LOG) + "\n")
    if dry:
        return
    pu = open(ROOT / "config" / "proven_units.txt").read().split("\n")
    tu_lines = {l.split()[0]: l for l in (open(tu_path).read().split("\n") if tu_path.exists() else [])
                if l.strip() and not l.startswith("#")}
    n_tu = n_u = 0
    for (stem, base, cands, area, aev, nev), acc, text in results:
        if not acc:
            continue
        dst = ROOT / area / (stem + ".cpp")
        old = tu_file.get(stem)
        if dst.exists() and (old is None or rel(dst) != old):
            log("NOT INSTALLED %s: %s exists" % (stem, rel(dst)))
            continue
        dst.parent.mkdir(parents=True, exist_ok=True)
        open(dst, "w", encoding="utf-8", newline="\n").write(text)
        if old and old != rel(dst):
            os.remove(ROOT / old)
            tu_lines.pop(old, None)
        newp = rel(dst)
        units = [u for _, u, _ in acc]
        base_units = {u for _, u, _ in base}
        for u in units:
            if u not in base_units:
                os.remove(UNC / (u + ".cpp"))
            pu = [re.sub(r",src/[^,]*\.cpp$", "," + newp, l) if (",%s," % u) in l else l for l in pu]
            os.replace(WORK / stem / "pieces_final" / (u + ".o"), ROOT / "build" / "mw" / (u + ".o"))
        tu_lines[newp] = "%s %s" % (newp, " ".join("%s=%s" % (unit_symbol(u), u) for u in units))
        n_tu += 1
        n_u += len(units) - len(base_units)
    open(ROOT / "config" / "proven_units.txt", "w", newline="\n").write("\n".join(pu))
    hdr = ["# Translation units regrouped by tools/tu_merge.py: <source> <function symbol>=<unit> ...",
           "# tools/build_c_units.sh compiles <source> once and splits its object into build/mw/<unit>.o per function",
           "# (tools/split_tu_obj.py); the link script still places each function's object at its retail address."]
    open(tu_path, "w", newline="\n").write("\n".join(hdr + sorted(tu_lines.values())) + "\n")
    log("installed %d translation units (%d new units)" % (n_tu, n_u))
    open(WORK / "merge.log", "a").write("\n".join(LOG[-1:]) + "\n")


if __name__ == "__main__":
    main()
