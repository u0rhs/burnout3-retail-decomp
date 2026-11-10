# Independent check of every retail function name: body vs the E function of the same name, call targets, starts.
import csv,json,struct,sys,collections,difflib
sys.path.insert(0,sys.argv[1]); from norm import norm
OUT=sys.argv[1]
class Elf:
    def __init__(s,p):
        d=open(p,'rb').read(); s.d=d; s.seg=[]
        phoff,=struct.unpack_from('<I',d,28); phes,phn=struct.unpack_from('<HH',d,42)
        for i in range(phn):
            t,o,va,pa,fs,ms,fl,al=struct.unpack_from('<8I',d,phoff+i*phes)
            if t==1: s.seg.append((va,o,fs))
    def words(s,a,n):
        for va,o,fs in s.seg:
            if va<=a and a+n<=va+fs: return struct.unpack_from('<%dI'%(n//4),s.d,o+a-va)
        return None
E=Elf('research/E_jun8/DNAT_200.45'); R=Elf('research/C_retail/SLUS_210.50')
def feats(p):
    import re
    m={}
    for mo in re.finditer(r'\{"entry":"([0-9a-f]+)","size":(\d+)', open(p,'rb').read().decode('latin1')):
        m[int(mo.group(1),16)]=int(mo.group(2))
    return m
fe=feats('research/features_e_v2.jsonl'); fr=feats('research/features_retail_v4.jsonl')
# E names at aligned E ELF addresses
ename={}; eaddr=collections.defaultdict(list)
for r in csv.DictReader(open('research/names_E_jun8.csv',encoding='utf-8')):
    a=int(r['elf_addr'],16); ename[a]=r['name']; eaddr[r['name']].append(a)
ours={int(r['elf_addr'],16):r for r in csv.DictReader(open('research/retail_names.csv',encoding='utf-8'))}
# transfer pairs (v3 = current), dst->src
x3={}
for r in csv.DictReader(open('research/xfer_E_retail_v3.csv',encoding='utf-8')):
    x3[int(r['dst_entry'],16)]=int(r['src_entry'],16)
dlist=set(int(r['address'],16) for r in csv.DictReader(open('ext/refs/dgv_<local archive>/games/burnout3/config/functions.csv',encoding='utf-8')))
def tok(w):
    op=w>>26
    if op==0: return (0,w&63)
    if op==0x1c: return (0x1c,w&63)
    if op==1: return (1,(w>>16)&31)
    if op in (0x10,0x11,0x12): return (op,(w>>21)&31,w&63)
    return (op,)
def calls(ws,base):
    out=[]
    for i,w in enumerate(ws):
        if w>>26==3: out.append(((base&0xf0000000)|((w&0x3ffffff)<<2)))
    return out
rname={a:r['name'] for a,r in ours.items()}
rows=[]; stat=collections.Counter()
for a,r in sorted(ours.items()):
    n=r['name']; cand=eaddr.get(n,[])
    src=x3.get(a)
    e=None; how=''
    if len(cand)==1: e=cand[0]; how='by-name'
    elif src in cand: e=src; how='by-name+xfer'
    elif cand: how='ambiguous-name'
    else: how='no-E-name'
    rsz=fr.get(a); esz=fe.get(e) if e else None
    sim=''; cal=''; csame=cdiff=0
    if e and rsz and esz:
        rw=R.words(a,rsz); ew=E.words(e,esz)
        if rw and ew:
            rt=[tok(w) for w in rw]; et=[tok(w) for w in ew]
            sim=round(difflib.SequenceMatcher(None,rt,et,autojunk=False).ratio(),3) if len(rt)*len(et)<4e6 else ''
            rc=collections.Counter(rname.get(t) for t in calls(rw,a)); ec=collections.Counter(ename.get(t) for t in calls(ew,e))
            rc.pop(None,None); ec.pop(None,None)
            csame=sum((rc&ec).values()); cdiff=sum((rc-ec).values())
    st_d=a in dlist; st_g=a in fr
    rows.append(dict(addr=f'{a:08x}',name=n,conf=r['confidence'],method=r['method'],e_addr=f'{e:08x}' if e else '',e_how=how,
        xfer_agrees=('yes' if src==e else 'no' if src is not None and e else ''),r_size=rsz or '',e_size=esz or '',
        size_ratio=round(rsz/esz,3) if rsz and esz else '',sim=sim,calls_same=csame,calls_diff=cdiff,start_resD=st_d,start_ghidra=st_g))
w=csv.DictWriter(open(OUT+'/verify.csv','w',newline='',encoding='utf-8'),fieldnames=list(rows[0]))
w.writeheader(); w.writerows(rows)
print(len(rows))
