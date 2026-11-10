def tok(w):
    op=w>>26
    if op==0: return (0,w&63)
    if op==0x1c: return (0x1c,w&63)
    if op==1: return (1,(w>>16)&31)
    if op in (0x10,0x11,0x12): return (op,(w>>21)&31,w&63)
    return (op,)
