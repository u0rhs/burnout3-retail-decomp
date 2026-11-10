#!/usr/bin/env python3
"""Port inventory: library functions (asm dirs rw/rwa/sce/ea/lg/runtime) called by jal from game code in retail.
Usage: python3 -I tools/port_lib_calls.py . research/port/game_library_calls.tsv   (docs/port-libraries.md)"""
import re, os, glob, struct, sys, collections
os.chdir(sys.argv[1])
LIB=('rw','rwa','sce','ea','lg','runtime')
nm_re=re.compile(r'^nonmatching (\S+), 0x([0-9A-Fa-f]+)'); ins=re.compile(r'^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ')
lib={}  # addr -> (name, lib/file, size)
for d in LIB:
    for f in glob.glob('assembly/asm/%s/**/*.s'%d, recursive=True):
        cur=None
        for line in open(f,errors='ignore'):
            m=nm_re.match(line)
            if m: cur=[m.group(1),int(m.group(2),16)]; continue
            if cur:
                m=ins.match(line)
                if m: lib[int(m.group(1),16)]=(cur[0],d+'/'+os.path.basename(f)[:-2],cur[1]); cur=None
ranges=sorted((a,a+s) for a,(n,g,s) in lib.items())
import bisect
starts=[r[0] for r in ranges]
def in_lib(a):
    i=bisect.bisect_right(starts,a)-1
    return i>=0 and ranges[i][0]<=a<ranges[i][1]
data=open('orig/SLUS_210.50','rb').read()
e_phoff,=struct.unpack_from('<I',data,0x1c); n,=struct.unpack_from('<H',data,0x2c)
calls=collections.Counter(); callers=collections.defaultdict(set)
for i in range(n):
    p_type,off,va,pa,fsz,msz,flg,al=struct.unpack_from('<8I',data,e_phoff+32*i)
    if p_type!=1 or not (flg&1): continue
    for k in range(0,fsz-3,4):
        w,=struct.unpack_from('<I',data,off+k); pc=va+k
        if (w>>26)==3:
            t=((w&0x3ffffff)<<2)|(pc&0xf0000000)
            if t in lib and not in_lib(pc):
                calls[t]+=1; callers[t].add(pc)
bygroup=collections.Counter(); fnbygroup=collections.Counter()
for t,c in calls.items(): g=lib[t][1]; bygroup[g]+=c; fnbygroup[g]+=1
print('library funcs total',len(lib),' called directly from game code:',len(calls))
for g,c in sorted(bygroup.items(),key=lambda x:-x[1]): print('%-22s %4d funcs  %5d call sites'%(g,fnbygroup[g],c))
out=sys.argv[2]
with open(out,'w') as f:
    f.write('addr\tlibrary\tname\tcall_sites\n')
    for t,c in sorted(calls.items(),key=lambda x:(lib[x[0]][1],-x[1])): f.write('%08X\t%s\t%s\t%d\n'%(t,lib[t][1],lib[t][0],c))
