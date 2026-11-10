"""Side-by-side E vs retail disassembly of one function, aligned by instruction shape.
usage: sbs_er.py <name substring>   (names from E_names_for_match / retail_names; VU0 ops decoded)"""
import sys, csv, struct, difflib
sys.path.insert(0, 'tools'); sys.path.insert(0, 'matching/namecheck')
from common import load
from mipsdis import md
from vu0dis import decode as vu0
FE = load('research/features_e_v2.jsonl'); FR = load('research/features_retail.jsonl')
en = {r['name']: int(r['entry'], 16) for r in csv.DictReader(open('research/E_names_for_match.csv', encoding='utf-8'))}
rn = {r['name']: int(r['elf_addr'], 16) for r in csv.DictReader(open('research/retail_names.csv', encoding='utf-8'))}
rnames = {v: k for k, v in rn.items()}; enames = {v: k for k, v in en.items()}
def dis(a, W, names):
    out = []
    for i, w in enumerate(W):
        va = a + 4 * i; op = w >> 26
        if op == 0x12: out.append(vu0(w) or 'cop2 %08x' % w); continue
        if op in (0x1E, 0x1F):
            s = (w & 0xFFFF) - (0x10000 if w & 0x8000 else 0); out.append(f"{'lq' if op == 0x1E else 'sq'} r{(w>>16)&31}, {s:#x}(r{(w>>21)&31})"); continue
        g = list(md.disasm(struct.pack('<I', w), va)); t = (f"{g[0].mnemonic} {g[0].op_str}" if g else '.word %08x' % w)
        if op in (2, 3):
            tg = ((va + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2); t = f"{g[0].mnemonic if g else 'j'} {names.get(tg, hex(tg))[:38]}"
        out.append(t)
    return out
q = sys.argv[1]
ks = [k for k in en if q in k]; kr = [k for k in rn if q in k]
for k in ks:
    if k not in rn: print('no retail name for', k); continue
    e, r = en[k], rn[k]; A = dis(e, FE[e]['W'], enames); B = dis(r, FR[r]['W'], rnames)
    print(f'== {k}  E {e:#x} ({len(A)})  retail {r:#x} ({len(B)})')
    sh = lambda W: [(x >> 26) * 64 + ((x & 63) if x >> 26 in (0, 0x1C, 0x11, 0x12) else 0) for x in W]
    sm = difflib.SequenceMatcher(None, sh(FE[e]['W']), sh(FR[r]['W']), autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        for i in range(max(i2 - i1, j2 - j1)):
            a = A[i1 + i] if i1 + i < i2 else ''; b = B[j1 + i] if j1 + i < j2 else ''
            print(f"{'  ' if tag == 'equal' and a == b else ' *'} {a:46s} | {b}")
