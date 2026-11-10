"""Align E map data symbols to the E ELF (map links differ from the ELF link, so shifts are piecewise).
Candidate shifts s (map - elf) come from code-referenced ELF addresses. Viterbi over map-ordered symbols:
emission (vtables: own-class slot names) = number of code references into [elf, elf+size) from named E functions of the SAME source file
(+0.25 if any reference hits the start), PEN for a shift change, no backwards/overlapping placement.
Output research/E_data_aligned.csv. Held-out checks (not used in scoring):
@STRING@ symbols are printable strings, references landing on symbol starts."""
import sys, csv, collections, bisect
sys.path.insert(0, 'tools'); sys.path.insert(0, 'matching/namecheck')
from common import load, Elf, E_ELF; from datarefs import refs, gp_of
F = load('research/features_e.jsonl'); E = Elf(E_ELF)
fsrc = {int(l.split('\t')[0], 16): l.split('\t')[3] for l in open('research/E_aligned_apply.tsv', encoding='utf-8')}
R = [(t, fsrc[f]) for f, i, t, k in refs(F, gp_of(E_ELF)) if f in fsrc]
R.sort(); RT = [t for t, _ in R]; Tset = set(RT)
SECS = ('.data', '.rodata', '.sdata', '.sbss', '.bss', '.vtables', '.vudata')
syms = [r for r in csv.DictReader(open('research/E_dnat_symbols.csv', encoding='utf-8'))
        if r['section'] in SECS and not r['name'].startswith('.') and int(r['size'], 16) > 0]
syms.sort(key=lambda r: int(r['addr'], 16))
A = [int(r['addr'], 16) for r in syms]; N = [int(r['size'], 16) for r in syms]; SRC = [r['source'] for r in syms]
glob = collections.Counter()
for a in A:
    lo = bisect.bisect_left(RT, a - 0x30000); hi = bisect.bisect_right(RT, a + 0x4000)
    for t in set(RT[lo:hi]): glob[a - t] += 1
K = [s for s, _ in glob.most_common(150)]
if 0xd380 not in K: K.append(0xd380)
en = {int(r['entry'], 16): r['name'] for r in csv.DictReader(open('research/E_names_for_match.csv', encoding='utf-8'))}
def emit(i, s):
    e = A[i] - s
    if syms[i]['section'] == '.vtables':  # constructors referencing vtables are mostly unnamed: score own-class slots
        cls = syms[i]['name'].rsplit('::__vt', 1)[0]; W = E.words(e, N[i] // 4)
        return float(sum(1 for w in W[2:] if w is not None and en.get(w, '').startswith(cls + '::'))) + (1.0 if W[:2] == [0, 0] else 0.0)
    lo = bisect.bisect_left(RT, e); hi = bisect.bisect_left(RT, e + N[i])
    same = sum(1 for j in range(lo, min(hi, lo + 400)) if R[j][1] == SRC[i])
    return min(same, 8) + (0.25 if e in Tset else 0.0)
PEN = 4.0; n = len(syms); m = len(K); back = []
score = [emit(0, s) for s in K]; back.append([None] * m)
for i in range(1, n):
    em = [emit(i, s) for s in K]
    order = sorted(range(m), key=lambda k: -score[k])
    new = []; bp = []
    for k in range(m):
        best_sw, bk = -1e18, None
        for b in order:  # best predecessor that keeps the placement ordered
            if (A[i] - K[k]) >= (A[i-1] - K[b]) + N[i-1]: best_sw, bk = score[b] - PEN, b; break
        if score[k] >= best_sw: new.append(score[k] + em[k]); bp.append(k)
        else: new.append(best_sw + em[k]); bp.append(bk)
    score = new; back.append(bp)
k = max(range(m), key=lambda k: score[k]); path = [0] * n
for i in range(n - 1, -1, -1):
    path[i] = k; k = back[i][k] if back[i][k] is not None else k
w = csv.writer(open('research/E_data_aligned_pass1.csv', 'w', newline='', encoding='utf-8'))
w.writerow(['elf_addr', 'map_addr', 'size', 'section', 'name', 'source', 'shift', 'referenced'])
runs = []
for i, r in enumerate(syms):
    s = K[path[i]]; hit = (A[i] - s) in Tset
    w.writerow([f'{A[i]-s:08x}', f'{A[i]:08x}', N[i], r['section'], r['name'], r['source'], hex(s), hit])
    if not runs or runs[-1][0] != s: runs.append([s, r['section'], A[i], A[i], 0, 0])
    runs[-1][3] = A[i]; runs[-1][4] += 1; runs[-1][5] += hit
print('runs:', len(runs))
for s, sec, a0, a1, cnt, hits in runs:
    if cnt >= 3: print(f'  {sec:9s} map {a0:08x}-{a1:08x} shift {s:#7x} syms {cnt:5d} start-referenced {hits}')
# checks
vt = [(i, r) for i, r in enumerate(syms) if r['section'] == '.vtables']
print('vtables at 0xd380 (scored by slots, expected all):', sum(1 for i, r in vt if K[path[i]] == 0xd380), 'of', len(vt))
st = [(i, r) for i, r in enumerate(syms) if '@STRING@' in r['name']]
def isstr(a, n):
    o = a - 0x100000 + 0x100; b = E.d[o:o+n]
    return len(b) == n and b[-1:] == b'\0' and all(32 <= c < 127 or c in (9, 10) for c in b[:-1])
print('held-out: @STRING@ symbols printable:', sum(1 for i, r in st if isstr(A[i] - K[path[i]], N[i])), 'of', len(st))

# ---- pass 2: local refinement around each symbol's run shift (+-0x80, step 4) --------------------------------
# emission: 2 if the symbol start is referenced, -1 if a reference lands strictly inside but the start is not
# (a sign of a wrong offset), + 0.5 per same-source reference inside (max 4); vtables keep their slot score.
base = [K[path[i]] for i in range(n)]
DL = list(range(-0x80, 0x84, 4))
def emit2(i, s):
    if syms[i]['section'] == '.vtables': return emit(i, s)
    e = A[i] - s
    # alignment is preserved by the linker: an 8/16-byte object aligned in the map stays aligned in the ELF
    for al in (16, 8):
        if N[i] >= al and A[i] % al == 0 and e % al != 0: return -50.0
    lo = bisect.bisect_left(RT, e); hi = bisect.bisect_left(RT, e + N[i])
    inside = hi - lo; start = e in Tset
    same = sum(1 for j in range(lo, min(hi, lo + 400)) if R[j][1] == SRC[i])
    # refs from named functions of OTHER source files that land inside: evidence against this placement in dense
    # small data
    diff = sum(1 for j in range(lo, min(hi, lo + 400)) if R[j][1] != SRC[i])
    return (2.0 if start else (-1.0 if inside else 0.0)) + 0.5 * min(same, 4) - DIFFW * min(diff, 4)
DIFFW = float(__import__("os").environ.get("B3_DIFFW", "0.5"))
PEN2 = 1.5; m2 = len(DL)
sc = [emit2(0, base[0] + d) for d in DL]; bk2 = [[None] * m2]
for i in range(1, n):
    em = [emit2(i, base[i] + d) for d in DL]; order = sorted(range(m2), key=lambda k: -sc[k]); new = []; bp = []
    for k in range(m2):
        cur = base[i] + DL[k]
        # staying = same absolute shift as the previous symbol
        stay_k = DL.index(cur - base[i-1]) if (cur - base[i-1]) in DL else None
        stay = sc[stay_k] if stay_k is not None and (A[i] - cur) >= (A[i-1] - (base[i-1] + DL[stay_k])) + N[i-1] else -1e18
        sw, sb = -1e18, None
        for b in order:
            if (A[i] - cur) >= (A[i-1] - (base[i-1] + DL[b])) + N[i-1]: sw, sb = sc[b] - PEN2, b; break
        if stay >= sw: new.append(stay + em[k]); bp.append(stay_k)
        else: new.append(sw + em[k]); bp.append(sb)
    sc = new; bk2.append(bp)
k = max(range(m2), key=lambda k: sc[k]); p2 = [0] * n
for i in range(n - 1, -1, -1):
    p2[i] = k; k = bk2[i][k] if bk2[i][k] is not None else k
fo = open('research/E_data_aligned.csv', 'w', newline='', encoding='utf-8'); w = csv.writer(fo)
w.writerow(['elf_addr', 'map_addr', 'size', 'section', 'name', 'source', 'shift', 'referenced'])
moved = 0
for i, r in enumerate(syms):
    s = base[i] + DL[p2[i]]; moved += DL[p2[i]] != 0
    w.writerow([f'{A[i]-s:08x}', f'{A[i]:08x}', N[i], r['section'], r['name'], r['source'], hex(base[i]), (A[i] - s) in Tset])
print('pass 2: symbols moved off their run shift:', moved, 'of', n)
print('pass 2: start-referenced:', sum(1 for i in range(n) if (A[i] - base[i] - DL[p2[i]]) in Tset), '(pass 1:', sum(1 for i in range(n) if (A[i] - base[i]) in Tset), ')')
print('pass 2: vtables unchanged:', sum(1 for i, r in enumerate(syms) if r['section'] == '.vtables' and DL[p2[i]] == 0), 'of 312')
print('pass 2: @STRING@ printable:', sum(1 for i, r in enumerate(syms) if '@STRING@' in r['name'] and isstr(A[i] - base[i] - DL[p2[i]], N[i])), 'of', len(st))
fo.close()
