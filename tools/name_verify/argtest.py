# Which argument registers does a function read before writing them? (EE EABI: GPR args r4-r11, FPR args f12-f19.)
import csv,sys,collections
exec(open('tools/name_verify/verify2.py').read().split('rname={a:r')[0])
from norm import norm,split_args
def uses(ws):
    """Linear scan until the first branch/jump (straight-line prologue region + delay slot)."""
    rd=set(); wr=set(); frd=set(); fwr=set()
    for i,w in enumerate(ws):
        op=w>>26; rs=(w>>21)&31; rt=(w>>16)&31; rd_=(w>>11)&31
        srcs=[];dst=None;fs=[];fd=None
        if op==0:
            f=w&63
            if f in (8,9): srcs=[rs]
            elif f in (0,2,3): srcs=[rt]; dst=rd_
            else: srcs=[rs,rt]; dst=rd_
        elif op in (0x1c,0x1e,0x1f,0x1a,0x1b): srcs=[rs,rt]; dst=rd_     # MMI/lq/sq approx
        elif op in (4,5): srcs=[rs,rt]
        elif op in (6,7,1): srcs=[rs]
        elif op in (2,3): pass
        elif op==0xf: dst=rt
        elif op in (0x20,0x21,0x23,0x24,0x25,0x27,0x37,0x1e): srcs=[rs]; dst=rt
        elif op in (0x28,0x29,0x2b,0x3f,0x1f): srcs=[rs,rt]
        elif op==0x31: srcs=[rs]; fd=rt                   # lwc1
        elif op==0x39: srcs=[rs]; fs=[rt]                 # swc1
        elif op==0x11:
            fmt=rs; f=w&63
            if fmt==4: srcs=[rt]; fd=rd_                  # mtc1
            elif fmt==0: fs=[rd_]; dst=rt                 # mfc1
            elif fmt==16:
                ft=rt; fss=rd_; fdd=(w>>6)&31
                fs=[fss,ft]; fd=fdd
        elif op in (8,9,10,11,12,13,14,0x18,0x19): srcs=[rs]; dst=rt
        for s in srcs:
            if s not in wr: rd.add(s)
        for s in fs:
            if s not in fwr: frd.add(s)
        if dst: wr.add(dst)
        if fd is not None: fwr.add(fd)
        if op in (2,3,4,5,6,7,1) or (op==0 and (w&63) in (8,9)):
            # include delay slot then stop
            if i+1<len(ws):
                pass
            break
    g=sorted(r-4 for r in rd if 4<=r<=11); f=sorted(r-12 for r in frd if 12<=r<=19)
    return g,f
def nparams(n):
    i=n.find('(')
    if i<0: return None
    j=n.rfind(')')
    a=n[i+1:j].strip()
    return [] if a in ('','void') else split_args(a)
rows=list(csv.DictReader(open(sys.argv[1]+'/wiki_test.csv',encoding='utf-8')))
for x in rows:
    if x['agree']!='False' or not x['wiki_E_addr']: continue
    a=int(x['addr'],16); ea=int(x['wiki_E_addr'],16)
    rw=R.words(a,fr.get(a,0)); ew=E.words(ea,fe.get(ea,0))
    if not rw or not ew: continue
    print(f"{x['addr']} retail reads a{uses(rw)[0]} f{uses(rw)[1]} | E reads a{uses(ew)[0]} f{uses(ew)[1]} | ours:{len(nparams(x['our_name']) or [])} params '{x['our_name'][:55]}' | wiki:{len(nparams(x['wiki_name']) or [])} '{x['wiki_name'][:55]}'")
