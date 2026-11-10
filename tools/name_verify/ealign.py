# Check 1: the E names sit on the right E ELF functions (map size vs Ghidra size at the aligned address).
import csv,sys,collections,re
def feats(p):
    return {int(m.group(1),16):int(m.group(2)) for m in re.finditer(r'\{"entry":"([0-9a-f]+)","size":(\d+)',open(p,'rb').read().decode('latin1'))}
fe=feats('research/features_e_v2.jsonl')
mp=collections.defaultdict(list)
for r in csv.DictReader(open('research/E_dnat_symbols.csv',encoding='utf-8')):
    if r['section']=='.text' and int(r['size'],16)>0: mp[r['name']].append((int(r['addr'],16),int(r['size'],16)))
C=collections.Counter(); bad=[]
names=list(csv.DictReader(open('research/names_E_jun8.csv',encoding='utf-8')))
for r in names:
    a=int(r['elf_addr'],16); n=r['name']
    raw=[x for x in mp.get(n,[])]
    if not raw: C['no map entry (other map/demangle)']+=1; continue
    sizes={s for _,s in raw}
    g=fe.get(a)
    if g is None: C['no ghidra function at addr']+=1; bad.append((r['elf_addr'],n,'noghidra',sizes)); continue
    if g in sizes: C['size equal']+=1
    else: C['size differs']+=1; bad.append((r['elf_addr'],n,g,sizes))
    d=a-raw[0][0]; C['shift %+#x'%d]+=1
print(len(names)); 
for k,v in sorted(C.items(),key=lambda t:-t[1])[:25]: print(v,k)
for b in bad[:25]: print(b)
