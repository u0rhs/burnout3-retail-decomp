"""Content-based name transfer between two builds using Ghidra feature exports (ExportFeatures.java).
usage: match_builds.py <src_features.jsonl> <src_names.csv: entry,name,class> <dst_features.jsonl> <out.csv> [--seed dst_seed.csv]
Methods (confidence): exact (high) -> callgraph (high if sim>=.8 else medium) -> string (high) -> order+sim (medium) -> order-only (low).
Only source names with class verified/boundary are transferred."""
import csv, json, sys, struct, difflib, collections, bisect
def load(p):
    F = {}
    raw = open(p, "rb").read().decode("utf-8", "replace")
    for l in raw.split("]}" + chr(13) + chr(10)):
        l = l.strip()
        if not l: continue
        if not l.endswith("]}"): l += "]}"
        j = json.loads(l, strict=False); a = int(j["entry"], 16); b = bytes.fromhex(j["bytes"])
        W = struct.unpack("<%dI" % (len(b)//4), b[:len(b)//4*4])
        F[a] = dict(size=j["size"], W=W, calls=[int(c, 16) for c in j["calls"]], strings=tuple(sorted(set(j["strings"]))), name=j["name"])
    return F
def norm(x):
    op = x >> 26
    if op in (2, 3): return x & 0xFC000000
    if op == 0xF: return x & 0xFFFF0000
    if op in (0x9, 0xC, 0xD) and (x >> 21 & 31) != 29 and (x >> 16 & 31) != 29: return x & 0xFFFF0000
    if (x >> 21 & 31) == 28 and op >= 0x20: return x & 0xFFFF0000
    return x
def shape(W): return [(x >> 26) * 64 + ((x & 63) if x >> 26 in (0, 0x1C, 0x11, 0x12) else 0) for x in W]
def sim(fa, fb):
    if not fa["W"] or not fb["W"]: return 0.0
    r = min(fa["size"], fb["size"]) / max(fa["size"], fb["size"])
    if r < 0.5: return 0.0
    sa, sb = fa.setdefault("_s", shape(fa["W"])), fb.setdefault("_s", shape(fb["W"]))
    m = difflib.SequenceMatcher(None, sa, sb, autojunk=False)
    return m.quick_ratio() and m.ratio()
def main():
    A = load(sys.argv[1]); B = load(sys.argv[3]); out = sys.argv[4]
    names = {}
    for r in csv.DictReader(open(sys.argv[2], encoding="utf-8")):
        if r["class"] in ("verified", "boundary"): names[int(r["entry"], 16)] = r["name"]
    match = {}; rev = {}; how = {}
    def add(a, b, m, c, s=1.0):
        if a in match or b in rev: return False
        match[a] = b; rev[b] = a; how[a] = (m, c, s); return True
    # 1 exact
    ha = collections.defaultdict(list); hb = collections.defaultdict(list)
    for a, f in A.items(): ha[tuple(norm(x) for x in f["W"])].append(a)
    for b, f in B.items(): hb[tuple(norm(x) for x in f["W"])].append(b)
    for h, la in ha.items():
        lb = hb.get(h)
        if lb and len(la) == 1 and len(lb) == 1 and len(h) >= 4: add(la[0], lb[0], "exact", "high")
    n_exact = len(match)
    # callers index
    callers_a = collections.defaultdict(set); callers_b = collections.defaultdict(set)
    for a, f in A.items():
        for c in f["calls"]: callers_a[c].add(a)
    for b, f in B.items():
        for c in f["calls"]: callers_b[c].add(b)
    # 2 call-graph propagation (iterate)
    changed = True
    while changed:
        changed = False
        for a, b in list(match.items()):
            ca, cb = A[a]["calls"], B[b]["calls"]
            if len(ca) == len(cb):
                for x, y in zip(ca, cb):
                    if x in A and y in B and x not in match and y not in rev:
                        s = sim(A[x], B[y])
                        if s >= 0.6 and add(x, y, "callgraph", "high" if s >= 0.8 else "medium", s): changed = True
            ua = [x for x in callers_a.get(a, ()) if x not in match and x in A]; ub = [y for y in callers_b.get(b, ()) if y not in rev and y in B]
            if len(ua) == 1 and len(ub) == 1:
                s = sim(A[ua[0]], B[ub[0]])
                if s >= 0.6 and add(ua[0], ub[0], "caller", "high" if s >= 0.8 else "medium", s): changed = True
    n_cg = len(match) - n_exact
    # 3 string anchors
    sa = collections.defaultdict(list); sb = collections.defaultdict(list)
    for a, f in A.items():
        if f["strings"] and a not in match: sa[f["strings"]].append(a)
    for b, f in B.items():
        if f["strings"] and b not in rev: sb[f["strings"]].append(b)
    n0 = len(match)
    for k, la in sa.items():
        lb = sb.get(k)
        if lb and len(la) == 1 and len(lb) == 1:
            s = sim(A[la[0]], B[lb[0]])
            if s >= 0.4: add(la[0], lb[0], "string", "high" if s >= 0.6 else "medium", s)
    n_str = len(match) - n0
    # 4 link-order gap alignment between anchors (monotone pairs only)
    n0 = len(match)
    As = sorted(A); Bs = sorted(B)
    anchors = sorted((a, b) for a, b in match.items())
    mono = []; best_b = -1
    for a, b in anchors:
        if b > best_b: mono.append((a, b)); best_b = b
    for (a1, b1), (a2, b2) in zip(mono, mono[1:]):
        ga = [x for x in As[bisect.bisect_right(As, a1):bisect.bisect_left(As, a2)] if x not in match]
        gb = [y for y in Bs[bisect.bisect_right(Bs, b1):bisect.bisect_left(Bs, b2)] if y not in rev]
        if not ga or not gb or len(ga) > 60 or len(gb) > 60: continue
        # simple DP alignment on similarity
        n, m = len(ga), len(gb); S = [[sim(A[x], B[y]) for y in gb] for x in ga]
        D = [[0.0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                D[i][j] = max(D[i-1][j], D[i][j-1], D[i-1][j-1] + (S[i-1][j-1] if S[i-1][j-1] >= 0.5 else -1))
        i, j = n, m
        while i > 0 and j > 0:
            if D[i][j] == D[i-1][j-1] + (S[i-1][j-1] if S[i-1][j-1] >= 0.5 else -1) and S[i-1][j-1] >= 0.5:
                s = S[i-1][j-1]; add(ga[i-1], gb[j-1], "order+sim", "medium" if s >= 0.7 else "low", s); i -= 1; j -= 1
            elif D[i][j] == D[i-1][j]: i -= 1
            else: j -= 1
        if n == m == 1 and ga[0] not in match: add(ga[0], gb[0], "order-only", "low", S[0][0])
    n_ord = len(match) - n0
    w = csv.writer(open(out, "w", newline="", encoding="utf-8")); w.writerow(["dst_entry", "src_entry", "name", "method", "confidence", "similarity"])
    named = collections.Counter()
    for a, b in sorted(match.items(), key=lambda t: t[1]):
        nm = names.get(a, "")
        w.writerow([f"{b:08x}", f"{a:08x}", nm, how[a][0], how[a][1], f"{how[a][2]:.2f}"])
        if nm: named[how[a][1]] += 1
    print(f"src funcs {len(A)}, dst funcs {len(B)}; matched {len(match)} (exact {n_exact}, callgraph {n_cg}, string {n_str}, order {n_ord}); named transfers by confidence: {dict(named)}")
main()
