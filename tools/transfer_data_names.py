"""Transfer E data names to retail via matched function pairs.
For each E<->retail function pair (research/xfer_E_retail_v3.csv, method exact/callgraph/caller/string/order+sim with sim >= 0.9),
pair data references at aligned instructions (difflib on instruction shapes), map the E target to its E data symbol
(research/E_data_aligned.csv) + offset, and vote for retail symbol start = retail target - offset.
Vtables are named separately by slot names (retail slot function names vs E vtable slot names).
Output research/retail_data_names.csv: elf_addr,name,section,source,size,votes,agree,confidence,method"""
import sys, csv, collections, bisect, difflib, json
sys.path.insert(0, 'tools'); sys.path.insert(0, 'matching/namecheck')
from common import load, Elf, E_ELF, R_ELF; from datarefs import refs_of, gp_of
FE = load('research/features_e_v2.jsonl'); FR = load('research/features_retail.jsonl')
gE, gR = gp_of(E_ELF), gp_of(R_ELF)
D = list(csv.DictReader(open('research/E_data_aligned.csv', encoding='utf-8')))
D.sort(key=lambda r: int(r['elf_addr'], 16)); DS = [int(r['elf_addr'], 16) for r in D]
# run quality from the same-source validation: weak runs get lower confidence
WEAK = {('.bss', '0xd380')}  # same-source < 50% (matching/unnamed/edata_validate.py, per-object alignment)
def esym(t):
    j = bisect.bisect_right(DS, t) - 1
    if j < 0: return None
    r = D[j]; n = max(int(r['size']), 1)
    return (r, t - DS[j]) if t < DS[j] + n else None
def shape(W): return [(x >> 26) * 64 + ((x & 63) if x >> 26 in (0, 0x1C, 0x11, 0x12) else 0) for x in W]
pairs = []
for r in csv.DictReader(open('research/xfer_E_retail_v3.csv', encoding='utf-8')):
    if r['method'] in ('exact', 'callgraph', 'caller', 'string') or (r['method'] == 'order+sim' and float(r['similarity']) >= 0.9):
        pairs.append((int(r['src_entry'], 16), int(r['dst_entry'], 16), r['method']))
votes = collections.defaultdict(collections.Counter); meta = {}
for e, g, m in pairs:
    if e not in FE or g not in FR: continue
    We, Wr = FE[e]['W'], FR[g]['W']
    re_ = {i: (t, k) for _, i, t, k in refs_of(e, We, gE)}; rr = {i: (t, k) for _, i, t, k in refs_of(g, Wr, gR)}
    if not re_ or not rr: continue
    sm = difflib.SequenceMatcher(None, shape(We), shape(Wr), autojunk=False)
    for a, b, size in sm.get_matching_blocks():
        for o in range(size):
            if a + o in re_ and b + o in rr:
                (te, ke), (tr, kr) = re_[a + o], rr[b + o]
                s = esym(te)
                if not s or ke != kr: continue
                sym, off = s
                start = tr - off
                votes[start][sym['name']] += 1; meta[(start, sym['name'])] = sym
out = []; stat = collections.Counter()
for start, c in votes.items():
    (name, v), = c.most_common(1); tot = sum(c.values()); sym = meta[(start, name)]
    agree = v / tot; weak = (sym['section'], sym['shift']) in WEAK
    if agree < 0.75: conf = 'conflict'
    elif v >= 2 and not weak: conf = 'high'
    elif v >= 2 or not weak: conf = 'medium'
    else: conf = 'low'
    out.append([f'{start:08x}', name, sym['section'], sym['source'], sym['size'], tot, f'{agree:.2f}', conf, 'coderef'])
    stat[(sym['section'], conf)] += 1
# duplicate names at different retail addresses: keep the best, demote others
byname = collections.defaultdict(list)
for o in out: byname[o[1]].append(o)
RANK = {'high': 3, 'medium': 2, 'low': 1, 'conflict': 0}
for n, l in byname.items():
    if len(l) > 1:
        l.sort(key=lambda o: (RANK[o[7]], o[5]), reverse=True)
        for o in l[1:]: o[7] = 'conflict'; o[8] = 'coderef (name also at %s)' % l[0][0]
# vtables by slot names
R = Elf(R_ELF); E = Elf(E_ELF)
en = {int(r['entry'], 16): r['name'] for r in csv.DictReader(open('research/E_names_for_match.csv', encoding='utf-8'))}
rn = {int(r['elf_addr'], 16): r['name'] for r in csv.DictReader(open('research/retail_names.csv', encoding='utf-8')) if r['confidence'] in ('high', 'medium')}
ev = [(r, [en.get(w, '') for w in E.words(int(r['elf_addr'], 16) + 8, int(r['size']) // 4 - 2)]) for r in D if r['section'] == '.vtables']
import struct
lo, hi = min(FR), max(FR) + FR[max(FR)]['size']
rt = []
for va, off, fs, ms in R.segs:
    n = fs // 4; Wd = struct.unpack_from('<%dI' % n, R.d, off); i = 0
    while i < n - 2:
        if Wd[i] == 0 and Wd[i+1] == 0 and lo <= Wd[i+2] < hi and Wd[i+2] % 4 == 0 and va + 4 * i > hi:
            j = i + 2
            while j < n and lo <= Wd[j] < hi and Wd[j] % 4 == 0: j += 1
            rt.append((va + 4 * i, [rn.get(w, '') for w in Wd[i+2:j]])); i = j
        else: i += 1
vtn = 0
existing = {int(o[0], 16): o for o in out}
for a, slots in rt:
    best = []
    for r, es in ev:
        sc = sum(1 for k in range(min(len(slots), len(es))) if slots[k] and slots[k] == es[k])
        if sc: best.append((sc, len(es) == len(slots), r))
    best.sort(key=lambda t: (t[0], t[1]), reverse=True)
    if not best: continue
    sc, samelen, r = best[0]
    second = best[1][0] if len(best) > 1 else 0
    named = sum(1 for s in slots if s)
    # own-class evidence: the class's own methods in the slots
    cls = r['name'].rsplit('::__vt', 1)[0]; own = sum(1 for s in slots if s.startswith(cls + '::'))
    if sc > second and own >= 1: conf = 'high' if (own >= 2 and samelen) else 'medium'
    elif sc > second: conf = 'low'
    else: conf = 'conflict'
    row = [f'{a:08x}', r['name'], '.vtables', r['source'], (len(slots) + 2) * 4, sc, f'{sc/max(named,1):.2f}', conf, 'vtable-slots own=%d' % own]
    if a in existing: existing[a][:] = row
    else: out.append(row)
    vtn += 1; stat[('.vtables(slots)', conf)] += 1
out.sort()
w = csv.writer(open('research/retail_data_names.csv', 'w', newline='', encoding='utf-8'))
w.writerow(['elf_addr', 'name', 'section', 'source', 'size', 'votes', 'agree', 'confidence', 'method']); w.writerows(out)
print('function pairs used', len(pairs), 'retail data symbols named', len(out))
for k in sorted(stat, key=str): print(' ', k, stat[k])
