import re,csv,collections,sys
sys.path.insert(0,'tools/name_verify'); from norm import norm
rows=[]; obj=None
for l in open('research/R_jul14/B4EXTERN.MAP',encoding='latin1'):
    l=l.rstrip(chr(13)+chr(10))
    if len(l)<41 or not re.match(r'^[0-9a-f]{8} [0-9a-f]{8} ',l): continue
    if l[23:40].strip()=='' and l[40]!=' ': obj=l[40:].split(chr(92))[-1]; continue
    if l[23:48].strip()=='' and len(l)>48: rows.append((int(l[0:8],16),int(l[9:17],16),l[48:].strip(),obj))
csv.writer(open('research/R_jul14/map_symbols.csv','w',newline='',encoding='utf-8')).writerows([('addr','size','name','obj')]+[(f'{a:08x}',s,n,o) for a,s,n,o in rows])
txt=[r for r in rows if 0x100000<=r[0]<0x43be80 and r[1]>0]
print('map symbols',len(rows),'text with size',len(txt),'objs',len({r[3] for r in rows}))
def b3ify(n): return re.sub(r'\bCB4',"CB3",re.sub(r'\bB4',"B3",n))
R=collections.defaultdict(list)
for a,s,n,o in txt: R[norm(b3ify(n))].append((a,n,o))
Rhead=collections.defaultdict(list)
for k,v in R.items(): Rhead[k.split('(')[0]].extend(v)
E=[r for r in csv.DictReader(open('research/names_E_jun8.csv',encoding='utf-8'))]
ours={r['name']:r for r in csv.DictReader(open('research/retail_names.csv',encoding='utf-8'))}
C=collections.Counter(); sig=[]
for r in E:
    n=norm(r['name'])
    if n in R: k='same signature'
    elif n.split('(')[0] in Rhead: k='same function name, other signature'; sig.append((r['name'],Rhead[n.split('(')[0]][0][1]))
    else: k='not in Revenge'
    C[k]+=1
print('E names vs Revenge:',C)
for s in sig[:25]: print('  ',s)
# H10 examples
for q in ['CB3PlayerCarPhysics::DoCrashBreaker','CB3HUDBoostBar::Prepare','CGtLobbyPS2DirtySock::ConnectToServer','CB3World::Prepare','CB3Score::Prepare','CB3Player::Construct','CB3PlayerCar::Prepare','CB3World::RenderOnePlayer','CB3ControllerMapping::GetHorn','CB3ControllerMapping::GetBoost','CGtUnicode::Copy','CB3MenuPageManager::StartLeadOutBack']:
    print(q,'->',[x[1] for x in Rhead.get(norm(q),[])][:3])
