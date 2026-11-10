#!/usr/bin/env python3
"""Non-matching track coverage: unmatched game functions/bytes, and how many have a src/nonmatching file.
Usage: python3 -I tools/nonmatching_coverage.py .   (docs/conventions.md "Non-matching track")"""
import re, os, glob, sys
os.chdir(sys.argv[1])
proven=[]
for l in open('config/proven_units.txt'):
    l=l.strip()
    if not l or l.startswith('#'): continue
    v,s,_,_,_=l.split(',',4); v=int(v,16); proven.append((v,v+int(s,16)))
def is_proven(a): return any(lo<=a<hi for lo,hi in proven)
funcs={}
nm_re=re.compile(r'^nonmatching (\S+), 0x([0-9A-Fa-f]+)'); ins=re.compile(r'^\s*/\* [0-9A-F]+ ([0-9A-F]{8}) ')
for top in ('game','b3'):
    for f in glob.glob('assembly/asm/%s/**/*.s'%top, recursive=True):
        cur=None
        for line in open(f,errors='ignore'):
            m=nm_re.match(line)
            if m: cur=[m.group(1),int(m.group(2),16),None]; continue
            if cur and cur[2] is None:
                m=ins.match(line)
                if m: cur[2]=int(m.group(1),16); funcs[cur[0]]=(cur[2],cur[1]); cur=None
un={n:v for n,v in funcs.items() if not is_proven(v[0])}
arch={os.path.splitext(f)[0] for f in os.listdir('src/nonmatching') if f.endswith(('.cpp','.c'))}
for f in os.listdir('src/nonmatching'):  # long names are hashed in the file name: take the header line's name too
    if f.endswith(('.cpp','.c')):
        m=re.match(r'// NONMATCHING: (\S+)', open(os.path.join('src/nonmatching',f),errors='replace').readline())
        if m: arch.add(m.group(1))
def key(n,a): return n in arch or ('func_%08X'%a) in arch
tb=sum(s for a,s in un.values()); ab=sum(s for n,(a,s) in un.items() if key(n,a))
ac=sum(1 for n,(a,s) in un.items() if key(n,a))
print('unmatched game funcs',len(un),'bytes',tb); print('with archive',ac,'bytes',ab, '%.1f%%'%(100*ab/tb))
big=sorted(((s,n) for n,(a,s) in un.items() if not key(n,a)),reverse=True)
print('no archive: funcs',len(big),'bytes',sum(s for s,n in big)); print('  >=0x400:',sum(1 for s,n in big if s>=0x400),sum(s for s,n in big if s>=0x400))
