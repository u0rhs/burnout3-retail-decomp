import csv,sys,collections,re,random
S=sys.argv[1]
def feats(p):
    return {int(m.group(1),16):int(m.group(2)) for m in re.finditer(r'\{"entry":"([0-9a-f]+)","size":(\d+)',open(p,'rb').read().decode('latin1'))}
fe=feats('research/features_e_v2.jsonl')
mp=collections.defaultdict(set)
for r in csv.DictReader(open('research/E_dnat_symbols.csv',encoding='utf-8')):
    if r['section']=='.text': mp[r['name']].add(int(r['size'],16))
ecount=collections.Counter(r['name'] for r in csv.DictReader(open('research/names_E_jun8.csv',encoding='utf-8')))
rows=list(csv.DictReader(open(S+'/verify2.csv',encoding='utf-8')))
for x in rows:
    e=int(x['e_addr'],16); n=x['name']
    anchor = fe.get(e) in mp.get(n,set()) and ecount[n]==1
    x['e_anchor_ok']=anchor
    t=x['tier']
    if t=='T1-proven':
        t='T1a-proven-unique' if x['unique_r']=='True' and x['unique_e']=='True' else 'T1b-proven-callers'
    if not anchor and t.startswith('T1'): t='T2-strong'
    if not anchor and t=='T2-strong' and x['sim'] and float(x['sim'])<0.95: t='T3-likely'
    x['tier2']=t
C=collections.Counter
print(C(x['tier2'] for x in rows)); print('anchor',C(x['e_anchor_ok'] for x in rows))
w=csv.DictWriter(open(S+'/verify3.csv','w',newline='',encoding='utf-8'),fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)
