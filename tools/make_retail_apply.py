"""Build Ghidra apply inputs for the retail project.
out1: research/retail_apply.tsv  (addr, name, source, layer, confidence, method)
out2: research/retail_missing_entries.tsv (addr, reason): vtable/jal targets Ghidra did not create."""
import csv, sys, struct, bisect
sys.path.insert(0, 'matching/namecheck')
from common import load, Elf, R_ELF
src2layer = {}
for r in csv.DictReader(open('research/E_classified.csv', encoding='utf-8')): src2layer.setdefault(r['source'], r['layer'])
with open('research/retail_apply.tsv', 'w', encoding='utf-8', newline='') as o:
    for r in csv.DictReader(open('research/retail_names.csv', encoding='utf-8')):
        f = [r['elf_addr'], r['name'], r['source'], src2layer.get(r['source'], 'UNKNOWN'), r['confidence'], r['method']]
        o.write('\t'.join(x.replace('\t', ' ') for x in f) + '\n')
FR = load('research/features_retail.jsonl'); R = Elf(R_ELF)
lo, hi = min(FR), max(FR) + FR[max(FR)]['size']; starts = sorted(FR)
def inside(t):
    i = bisect.bisect_right(starts, t) - 1
    return i >= 0 and t < starts[i] + FR[starts[i]]['size']
miss = {}
for a, f in FR.items():
    for c in f['calls']:
        if lo <= c < hi and c not in FR and not inside(c): miss[c] = 'jal-target'
for va, off, fs, ms in R.segs:
    n = fs // 4; W = struct.unpack_from('<%dI' % n, R.d, off); i = 0
    while i < n - 2:
        if W[i] == 0 and W[i+1] == 0 and lo <= W[i+2] < hi and W[i+2] % 4 == 0 and va + 4 * i > hi:
            j = i + 2
            while j < n and lo <= W[j] < hi and W[j] % 4 == 0:
                t = W[j]
                if t not in FR and not inside(t): miss.setdefault(t, 'vtable-slot %08x' % (va + 4 * i))
                j += 1
            i = j
        else: i += 1
with open('research/retail_missing_entries.tsv', 'w', encoding='utf-8', newline='') as o:
    for t in sorted(miss): o.write('%08x\t%s\n' % (t, miss[t]))
print('names', sum(1 for _ in open('research/retail_apply.tsv', encoding='utf-8')), 'missing entries', len(miss))
