# Position check: a name between two proven anchors (T1a) whose E gap holds the same function sequence.
import csv,sys,collections,re,bisect
S=sys.argv[1]
def feats(p):
    return {int(m.group(1),16):int(m.group(2)) for m in re.finditer(r'\{"entry":"([0-9a-f]+)","size":(\d+)',open(p,'rb').read().decode('latin1'))}
fe=sorted(feats('research/features_e_v2.jsonl')); fr=sorted(feats('research/features_retail_v4.jsonl'))
rows=list(csv.DictReader(open(S+'/verify3.csv',encoding='utf-8')))
by={int(x['addr'],16):x for x in rows}
proven={a:int(x['e_addr'],16) for a,x in by.items() if x['tier2']=='T1a-proven-unique'}
pa=sorted(proven)
C=collections.Counter()
for a,x in by.items():
    x['sandwich']=''
    if x['tier2'].startswith('T1'): continue
    i=bisect.bisect_left(pa,a)
    if i==0 or i>=len(pa) : C['no anchors']+=1; continue
    lo,hi=pa[i-1],pa[i]
    elo,ehi=proven[lo],proven[hi]
    if not elo<int(x['e_addr'],16)<ehi: x['sandwich']='outside-E-gap'; C['outside']+=1; continue
    rseq=fr[bisect.bisect_right(fr,lo):bisect.bisect_left(fr,hi)]
    eseq=fe[bisect.bisect_right(fe,elo):bisect.bisect_left(fe,ehi)]
    # all named functions in the retail gap must map in order into the E gap
    named=[(r,int(by[r]['e_addr'],16)) for r in rseq if r in by]
    es=[e for _,e in named]
    inorder= es==sorted(es) and all(elo<e<ehi for e in es)
    if len(rseq)==len(eseq) and inorder and [e for e in eseq]==es: x['sandwich']='exact-gap'; C['exact-gap']+=1
    elif inorder: x['sandwich']='in-order'; C['in-order']+=1
    else: x['sandwich']='order-broken'; C['order-broken']+=1
print(C)
T=collections.Counter()
for x in rows:
    t=x['tier2']
    if not t.startswith('T1') and x['sandwich']=='exact-gap' and x['e_anchor_ok']=='True' and x['start_resD']=='True' and x['start_ghidra']=='True': t='T1c-proven-position'
    x['final']=t; T[t]+=1
print(T)
w=csv.DictWriter(open(S+'/verify4.csv','w',newline='',encoding='utf-8'),fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)
