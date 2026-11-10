# Tighten T1b (a T1a caller must call it in both builds) and T1c (body similarity >= 0.6); write the final tiers.
import csv,sys,collections
exec(open('tools/name_verify/verify2.py').read().split('rname={a:r')[0])
rname={a:r['name'] for a,r in ours.items()}
Rc=collections.defaultdict(set); Ec=collections.defaultdict(set)
for fs,elf,cr in ((fr,R,Rc),(fe,E,Ec)):
    for a,sz in fs.items():
        ws=elf.words(a,sz)
        if ws:
            for w in ws:
                if w>>26==3: cr[(a&0xf0000000)|((w&0x3ffffff)<<2)].add(a)
rows=list(csv.DictReader(open(sys.argv[1]+'/verify4.csv',encoding='utf-8')))
by={int(x['addr'],16):x for x in rows}
t1a={a:int(x['e_addr'],16) for a,x in by.items() if x['final']=='T1a-proven-unique'}
C=collections.Counter()
for a,x in by.items():
    f=x['final']; e=int(x['e_addr'],16)
    if f=='T1b-proven-callers':
        if not any(c in t1a and t1a[c] in Ec.get(e,()) for c in Rc.get(a,())): f='T2-strong'
    if f=='T1c-proven-position' and float(x['sim'] or 0)<0.6: f='T3-likely'
    x['final']=f; C[f]+=1
print(C, sum(v for k,v in C.items() if k.startswith('T1')))
w=csv.DictWriter(open(sys.argv[1]+'/verify_final.csv','w',newline='',encoding='utf-8'),fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)
