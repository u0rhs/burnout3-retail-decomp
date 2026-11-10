"""Merge the direct (E->retail) and chained (E->F->retail) name transfers into retail_names.csv format.
usage: merge_retail_names.py <xfer_E_retail.csv> <xfer_F_retail.csv> <xfer_E_F.csv> <out.csv> [conflicts.csv]
Rules (docs/retail-names.md): both routes same name -> high 'direct+chain agree';
different -> conflict;
one route only -> that route's confidence (chain: the lower of E->F and F->retail)."""
import csv, sys, collections
RANK = {'high': 3, 'medium': 2, 'low': 1}
def rows(p): return {r['dst_entry']: r for r in csv.DictReader(open(p, encoding='utf-8')) if r['name']}
d, c = rows(sys.argv[1]), rows(sys.argv[2])
ef = {r['dst_entry']: r for r in csv.DictReader(open(sys.argv[3], encoding='utf-8'))}
srcE = {int(l.split('\t')[0], 16): l.split('\t')[3] for l in open('research/E_aligned_apply.tsv', encoding='utf-8')}
def esrc(a):  # source file of the E function behind a retail address (direct route, else via F)
    D, C = d.get(a), c.get(a)
    if D: return srcE.get(int(D['src_entry'], 16), '')
    e = ef.get(C['src_entry']) if C else None
    return srcE.get(int(e['src_entry'], 16), '') if e else ''
out = []; conf = []
for a in sorted(set(d) | set(c)):
    D, C = d.get(a), c.get(a)
    if D and C:
        if D['name'] == C['name']: out.append((a, D['name'], 'high', 'direct+chain agree'))
        else: out.append((a, D['name'], 'conflict', 'direct/chain disagree')); conf.append((a, D['name'], C['name']))
    elif D: out.append((a, D['name'], D['confidence'], 'direct:' + D['method']))
    else:
        e = ef.get(C['src_entry']); m1 = e['method'] if e else '?'; c1 = e['confidence'] if e else 'low'
        k = min(c1, C['confidence'], key=lambda x: RANK.get(x, 0))
        out.append((a, C['name'], k, 'chain:%s>%s' % (m1, C['method'])))
w = csv.writer(open(sys.argv[4], 'w', newline='', encoding='utf-8')); w.writerow(['elf_addr', 'name', 'source', 'confidence', 'method'])
for a, n, k, m in out: w.writerow([a, n, esrc(a), k, m])
if len(sys.argv) > 5:
    w2 = csv.writer(open(sys.argv[5], 'w', newline='', encoding='utf-8')); w2.writerow(['elf_addr', 'direct', 'chain']); w2.writerows(conf)
print('named', len(out), collections.Counter(k for _, _, k, _ in out), 'conflicts', len(conf))
