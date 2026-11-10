# Test each wiki name against the retail code: find the E function of that name, compare bodies.
import csv,sys,collections,difflib
exec(open('tools/name_verify/verify2.py').read().split('rname={a:r')[0])
from norm import norm
rname={a:r['name'] for a,r in ours.items()}
fin={int(x['addr'],16):x for x in csv.DictReader(open(sys.argv[1]+'/verify_final.csv',encoding='utf-8'))}
en=collections.defaultdict(list)
for a,n in ename.items(): en[norm(n)].append(a)
enhead=collections.defaultdict(list)
for a,n in ename.items(): enhead[norm(n).split('(')[0]].append(a)
Eh=collections.Counter(repr(mask(E.words(a,s),a,{})) for a,s in fe.items() if E.words(a,s))
Rh=collections.Counter(repr(mask(R.words(a,s),a,{})) for a,s in fr.items() if R.words(a,s))
def test(ra,ea):
    rs=fr.get(ra); es=fe.get(ea)
    if not rs or not es: return ('nosize',0)
    rb=mask(R.words(ra,rs),ra,{}); eb=mask(E.words(ea,es),ea,{})
    if rb==eb: return ('exact-unique' if Eh[repr(eb)]==1 and Rh[repr(rb)]==1 else 'exact-dup',1.0)
    from verify_tok import tok
    return ('sim',round(difflib.SequenceMatcher(None,[tok(w) for w in R.words(ra,rs)],[tok(w) for w in E.words(ea,es)],autojunk=False).ratio(),3))
out=[]
for w in csv.DictReader(open('ext/refs/burnout3-symbols/data/burnout3-retail/function-names.csv',encoding='utf-8')):
    if not w['us_address']: continue
    a=int(w['us_address'],16); n=norm(w['name'])
    cand=en.get(n) or enhead.get(n.split('(')[0],[])
    how='exact-name' if en.get(n) else ('same-func-name' if cand else 'no-E-name')
    best=None
    for ea in cand:
        t=test(a,ea)
        if best is None or t[1]>best[1][1]: best=(ea,t)
    o=ours.get(a); f=fin.get(a)
    out.append(dict(addr=w['us_address'],wiki_check=w['check'],wiki_name=w['name'],our_name=o['name'] if o else '',our_tier=f['final'] if f else '',
        agree=(norm(o['name'])==n) if o else '', wiki_E_lookup=how,wiki_E_addr=f'{best[0]:08x}' if best else '',wiki_test=best[1][0] if best else '',wiki_sim=best[1][1] if best else '',
        is_func_start=a in fr))
wr=csv.DictWriter(open(sys.argv[1]+'/wiki_test.csv','w',newline='',encoding='utf-8'),fieldnames=list(out[0])); wr.writeheader(); wr.writerows(out)
C=collections.Counter
print('agree',C((x['our_tier'][:3]) for x in out if x['agree'] is True))
dis=[x for x in out if x['agree'] is False]; only=[x for x in out if x['our_name']=='']
print('disagree',len(dis),C((x['our_tier'][:3],x['wiki_test']) for x in dis))
print('wiki-only',len(only),C((x['wiki_test'], 'start' if x['is_func_start'] else 'nostart') for x in only))
