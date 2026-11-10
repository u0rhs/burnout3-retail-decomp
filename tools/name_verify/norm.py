import re
TY={'uint':'unsigned int','ulong':'unsigned long','ushort':'unsigned short','uchar':'unsigned char'}
def split_args(s):
    out=[];d=0;cur=''
    for ch in s:
        if ch in '(<': d+=1
        if ch in ')>': d-=1
        if ch==',' and d==0: out.append(cur);cur=''
        else: cur+=ch
    out.append(cur); return out
def ntype(t):
    t=t.strip()
    for k,v in TY.items(): t=re.sub(r'\b%s\b'%k,v,t)
    # move trailing const before base: "X const *" -> "const X*"
    m=re.match(r'^(.*?)\s+const\s*([*&]+.*)$',t)
    if m and not m.group(1).startswith('const '): t='const '+m.group(1)+m.group(2)
    m=re.match(r'^(.*?)\s+const$',t)
    if m and not m.group(1).startswith('const '): t='const '+m.group(1)
    return re.sub(r'\s+(?=[*&])','',t).replace(' ','')
def norm(n, drop_const=True):
    n=n.strip()
    i=n.find('(')
    if i<0: return n
    # match closing paren of arg list at depth
    d=0
    for j in range(i,len(n)):
        if n[j]=='(':d+=1
        elif n[j]==')':
            d-=1
            if d==0: break
    else:
        return n.replace(' ','')  # truncated
    head,args,tail=n[:i],n[i+1:j],n[j+1:]
    a=[] if args.strip() in ('','void') else [ntype(x) for x in split_args(args)]
    tail=tail.strip()
    if drop_const: tail=''
    return head.replace(' ','')+'('+','.join(a)+')'+tail
def truncated(n): 
    d=0
    for ch in n:
        if ch=='(':d+=1
        elif ch==')':d-=1
    return d!=0
