# Strict tiering: exact masked body, callee+caller name agreement, uniqueness of the body.
import csv,sys,collections,hashlib
exec(open('tools/name_verify/verify.py').read().split('def tok(w)')[0])   # loaders and tables
def mask(ws,base,names):
    out=[]; luireg=set()
    for w in ws:
        op=w>>26; rs=(w>>21)&31; rt=(w>>16)&31
        if op==3: t=(base&0xf0000000)|((w&0x3ffffff)<<2); out.append(('jal',names.get(t,'?')))
        elif op==2: out.append(('j',))
        elif op==0xf: luireg.add(rt); out.append(('lui',rt))
        elif op in (4,5,6,7,0x14,0x15,0x16,0x17,1): out.append(w)       # branches: relative, keep
        elif op not in (0,0x1c,0x10,0x11,0x12,0x13,0x12) and (rs==28 or rs in luireg):
            out.append((op,rs,rt,'imm'))                                   # address lo / gp-relative
        else: out.append(w)
    return tuple(out)
rname={a:r['name'] for a,r in ours.items()}
def body(elf,a,sz,names):
    ws=elf.words(a,sz) if sz else None
    return mask(ws,a,names) if ws else None
def callgraph(elf,fs):
    cr=collections.defaultdict(list)
    for a,sz in fs.items():
        ws=elf.words(a,sz)
        if not ws: continue
        for w in ws:
            if w>>26==3: cr[(a&0xf0000000)|((w&0x3ffffff)<<2)].append(a)
    return cr
Rcallers=callgraph(R,fr); Ecallers=callgraph(E,fe)
# body hashes for uniqueness (raw masked, names of callees replaced by '?')
def h(b): return hashlib.md5(repr(b).encode()).hexdigest() if b else None
Eh=collections.Counter(h(body(E,a,s,{})) for a,s in fe.items()); Rh=collections.Counter(h(body(R,a,s,{})) for a,s in fr.items())
v={r['addr']:r for r in csv.DictReader(open(sys.argv[1]+'/verify.csv',encoding='utf-8'))}
out=[]
for a,r in sorted(ours.items()):
    x=v[f'{a:08x}']; e=int(x['e_addr'],16)
    rb=body(R,a,fr.get(a),rname); eb=body(E,e,fe.get(e),ename)
    exact= rb is not None and rb==eb
    ru=Rh[h(body(R,a,fr.get(a),{}))]==1 if fr.get(a) else False
    eu=Eh[h(body(E,e,fe.get(e),{}))]==1 if fe.get(e) else False
    rc=collections.Counter(rname.get(c) for c in Rcallers.get(a,[])); ec=collections.Counter(ename.get(c) for c in Ecallers.get(e,[]))
    rc.pop(None,None); ec.pop(None,None)
    cs=sum((rc&ec).values()); cd=sum((rc-ec).values())+sum((ec-rc).values())
    sz=fr.get(a) or 0
    starts= x['start_resD']=='True' and x['start_ghidra']=='True'
    sim=float(x['sim'] or 0)
    callees_ok=int(x['calls_diff'])==0
    if exact and starts and (ru and eu or cs>0) and (cd==0 or cs>0):   tier='T1-proven'
    elif starts and sim>=0.9 and callees_ok and (cs>0 or (ru and eu) or int(x['calls_same'])>0): tier='T2-strong'
    elif starts and sim>=0.75 and callees_ok: tier='T3-likely'
    else: tier='T4-review'
    x.update(exact=exact,unique_r=ru,unique_e=eu,callers_same=cs,callers_diff=cd,tier=tier)
    out.append(x)
w=csv.DictWriter(open(sys.argv[1]+'/verify2.csv','w',newline='',encoding='utf-8'),fieldnames=list(out[0])); w.writeheader(); w.writerows(out)
C=collections.Counter
print(C(x['tier'] for x in out))
print(C((x['tier'],x['conf']) for x in out))
