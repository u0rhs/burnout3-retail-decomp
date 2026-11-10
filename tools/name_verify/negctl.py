# Negative control: pair each retail function with a WRONG E function of the same size; how often does the exact test pass?
import sys,collections,random
exec(open('tools/name_verify/verify2.py').read().split('rname={a:r')[0])
bysize=collections.defaultdict(list)
for a,s in fe.items(): bysize[s].append(a)
random.seed(1); tests=passes=0; passu=0
eh={}
for a,r in ours.items():
    e=eaddr[r['name']][0]; s=fr.get(a)
    if not s: continue
    others=[b for b in bysize.get(s,[]) if b!=e]
    if not others: continue
    b=random.choice(others); tests+=1
    rb=mask(R.words(a,s),a,{}); eb=mask(E.words(b,s),b,{})
    if rb==eb: passes+=1
print('wrong same-size pairs tested',tests,'exact-body passes (callees ignored)',passes)
