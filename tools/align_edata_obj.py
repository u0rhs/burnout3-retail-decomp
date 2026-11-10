"""Align E map data symbols to the E ELF per OBJECT CONTRIBUTION.
The linker places each object's section contribution contiguously, so one shift (map - elf) holds for a whole
(section, source) block. Per block: candidate shifts from code references of named functions of the SAME source;
score = 2 per reference on a symbol start + 1 per reference inside a symbol of the block; alignment preserved
(8/16-byte objects aligned in the map stay aligned). Blocks without same-source references take the shift of the
nearest scored block in the same section (fallback = pass-1 run shift). Vtables keep the verified 0xd380.
Output research/E_data_aligned.csv (+ 'method' column: scored / inherited / vtable)."""
import sys, csv, bisect, collections
sys.path.insert(0, 'tools'); sys.path.insert(0, 'matching/namecheck')
from common import load, E_ELF
from datarefs import refs, gp_of
F = load('research/features_e_v2.jsonl')
fsrc = {int(l.split('\t')[0], 16): l.split('\t')[3] for l in open('research/E_aligned_apply.tsv', encoding='utf-8')}
bysrc = collections.defaultdict(list)
for f, i, t, k in refs(F, gp_of(E_ELF)):
    if f in fsrc: bysrc[fsrc[f]].append(t)
for s in bysrc: bysrc[s].sort()
_all = sorted((t, s) for s, v in bysrc.items() for t in v); ALLT = [t for t, _ in _all]; ALLS = [s for _, s in _all]
FOREIGN_W = float(__import__('os').environ.get('B3_FOREIGN_W', '0.5'))
SECS = ('.data', '.rodata', '.sdata', '.sbss', '.bss', '.vtables', '.vudata')
syms = sorted((r for r in csv.DictReader(open('research/E_dnat_symbols.csv', encoding='utf-8'))
               if r['section'] in SECS and not r['name'].startswith('.') and int(r['size'], 16) > 0), key=lambda r: int(r['addr'], 16))
p1 = {r['map_addr']: int(r['shift'], 16) for r in csv.DictReader(open('research/E_data_aligned_pass1.csv', encoding='utf-8'))}
# blocks: consecutive symbols with the same (section, source)
blocks = []
for r in syms:
    key = (r['section'], r['source'])
    if blocks and blocks[-1][0] == key: blocks[-1][1].append(r)
    else: blocks.append([key, [r]])
SECR = {}   # ELF range per section from pass 1 (blocks must stay inside their own section)
for r in csv.DictReader(open('research/E_data_aligned_pass1.csv', encoding='utf-8')):
    e = int(r['elf_addr'], 16); lo_, hi_ = SECR.get(r['section'], (e, e)); SECR[r['section']] = (min(lo_, e), max(hi_, e + int(r['size'])))
def score(block, s):
    A = [int(r['addr'], 16) for r in block]; N = [int(r['size'], 16) for r in block]
    slo, shi = SECR.get(block[0]['section'], (0, 1 << 32))
    if A[0] - s < slo - 0x40 or A[-1] + N[-1] - s > shi + 0x40: return -1
    for a, n in zip(A, N):
        for al in (16, 8):
            if n >= al and a % al == 0 and (a - s) % al: return -1
    T = bysrc.get(block[0]['source'], [])
    lo, hi = A[0] - s, A[-1] + N[-1] - s
    i0, i1 = bisect.bisect_left(T, lo), bisect.bisect_left(T, hi)
    starts = {a - s for a in A}; sc = 0
    for t in T[i0:i1]:
        if t in starts: sc += 2
        else:
            j = bisect.bisect_right(A, t + s) - 1
            if j >= 0 and t + s < A[j] + N[j]: sc += 1
    # references from OTHER source files inside the block: evidence for a foreign object at this place
    # (only for small objects: big globals such as gWorld are legitimately referenced from many files)
    k0, k1 = bisect.bisect_left(ALLT, lo), bisect.bisect_left(ALLT, hi); foreign = 0
    for k in range(k0, k1):
        if ALLS[k] == block[0]['source']: continue
        j = bisect.bisect_right(A, ALLT[k] + s) - 1
        if j >= 0 and ALLT[k] + s < A[j] + N[j] and N[j] <= 0x40: foreign += 1
    return sc - FOREIGN_W * foreign
res = []
for key, block in blocks:
    sec, src = key
    if sec == '.vtables': res.append((0xd380, 'vtable', 0)); continue
    if sec == '.bss':   # mostly globals referenced across files: same-source scoring is too weak, keep the pass-1 run shift
        res.append((p1.get(block[0]['addr'].lower().zfill(8), 0xd380), 'pass1', 0)); continue
    T = bysrc.get(src, [])
    cand = collections.Counter()
    for r in block:
        a = int(r['addr'], 16)
        for t in T[bisect.bisect_left(T, a - 0x30000):bisect.bisect_right(T, a + 0x4000)]: cand[a - t] += 1
    best, bs = None, 0
    base = p1.get(block[0]['addr'].lower().zfill(8))
    for s, _ in cand.most_common(60):
        v = score(block, s)
        if v > bs or (v == bs and v > 0 and base is not None and abs(s - base) < abs(best - base)): best, bs = s, v
    res.append((best, 'scored', bs) if best is not None and bs >= 2 else (None, 'inherited', 0))
# fill inherited blocks from the nearest scored block of the same section (prefer the previous one)
for i, (s, m, v) in enumerate(res):
    if s is not None: continue
    sec = blocks[i][0][0]; cand = None
    for d in range(1, len(res)):
        for j in (i - d, i + d):
            if 0 <= j < len(res) and blocks[j][0][0] == sec and res[j][1] == 'scored': cand = res[j][0]; break
        if cand is not None: break
    if cand is None: cand = p1.get(blocks[i][1][0]['addr'].lower().zfill(8), 0xd380)
    res[i] = (cand, 'inherited', 0)
w = csv.writer(open('research/E_data_aligned.csv', 'w', newline='', encoding='utf-8'))
w.writerow(['elf_addr', 'map_addr', 'size', 'section', 'name', 'source', 'shift', 'referenced', 'method'])
allT = set(t for v in bysrc.values() for t in v)
stat = collections.Counter()
for (key, block), (s, m, v) in zip(blocks, res):
    for r in block:
        a = int(r['addr'], 16); e = a - s
        w.writerow([f'{e:08x}', f'{a:08x}', int(r['size'], 16), r['section'], r['name'], r['source'], hex(s), e in allT, m])
        stat[(key[0], m)] += 1
for k in sorted(stat): print(k, stat[k])
print('blocks', len(blocks))
