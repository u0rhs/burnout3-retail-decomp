import struct,collections,re,csv,sys
d=open('research/R_jul14/SLUS_212.42','rb').read()
shoff,=struct.unpack_from('<I',d,32); shes,shn,shstr=struct.unpack_from('<HHH',d,46)
secs=[struct.unpack_from('<10I',d,shoff+i*shes) for i in range(shn)]
st=secs[87]; strs=secs[88][4]
out=[]
for k in range(st[5]//16):
    nm,val,sz,info,oth,shx=struct.unpack_from('<IIIBBH',d,st[4]+k*16)
    e=d.index(b'\0',strs+nm); n=d[strs+nm:e].decode('latin1')
    out.append((val,sz,info&15,info>>4,shx,n))
C=collections.Counter((t,b) for _,_,t,b,_,_ in out); print(C)
funcs=[o for o in out if o[2]==2]; objs=[o for o in out if o[2]==1]
print('funcs',len(funcs),'objects',len(objs))
for o in funcs[:8]+funcs[5000:5008]: print(hex(o[0]),o[1],o[5])
csv.writer(open('research/R_jul14/symtab.csv','w',newline='',encoding='utf-8')).writerows([('addr','size','type','bind','shndx','name')]+[(f'{a:08x}',s,t,b,x,n) for a,s,t,b,x,n in out])
