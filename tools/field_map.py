"""E -> retail member-offset map per class, from matched function pairs.
Accesses `op rt, off(base)` at aligned instructions (difflib on instruction shapes) with the same opcode and a base
register other than sp/gp/zero vote for (E off -> retail off) under the class of the E function (name prefix).
Only `this`-derived bases are wanted; as an approximation the base must be a0 or an s-register that was copied from a0
(move sX, a0) in the E function. Output research/retail_fieldmap.csv: class,e_off,retail_off,votes,agree,delta.
usage: field_map.py [class_prefix ...]"""
import sys, csv, collections, difflib
sys.path.insert(0, 'tools'); sys.path.insert(0, 'matching/namecheck')
from common import load
FE = load('research/features_e_v2.jsonl'); FR = load('research/features_retail.jsonl')
en = {int(r['entry'], 16): r['name'] for r in csv.DictReader(open('research/E_names_for_match.csv', encoding='utf-8'))}
MEM = {0x20, 0x21, 0x23, 0x24, 0x25, 0x27, 0x28, 0x29, 0x2B, 0x31, 0x35, 0x37, 0x39, 0x3D, 0x3F, 0x1E, 0x1F, 0x36, 0x3E, 0x1A, 0x1B, 0x2C, 0x2D, 0x22, 0x26, 0x2A, 0x2E}
def shape(W): return [(x >> 26) * 64 + ((x & 63) if x >> 26 in (0, 0x1C, 0x11, 0x12) else 0) for x in W]
def this_regs(W):
    regs = {4}
    for w in W[:24]:  # prologue copies: or/addu sX, a0, zero  (move)
        if w >> 26 == 0 and (w & 0x3F) in (0x25, 0x21, 0x2D) and ((w >> 21) & 31) == 4 and ((w >> 16) & 31) == 0: regs.add((w >> 11) & 31)
    return regs
want = sys.argv[1:]
votes = collections.defaultdict(collections.Counter)
for r in csv.DictReader(open('research/xfer_E_retail_v3.csv', encoding='utf-8')):
    if not r['name'] or '::' not in r['name']: continue
    if r['method'] not in ('exact', 'callgraph', 'caller', 'string') and float(r['similarity']) < 0.85: continue
    cls = r['name'].split('(')[0].rsplit('::', 1)[0]
    if want and not any(cls.startswith(p) for p in want): continue
    e, g = int(r['src_entry'], 16), int(r['dst_entry'], 16)
    if e not in FE or g not in FR: continue
    We, Wr = FE[e]['W'], FR[g]['W']; te, tr = this_regs(We), this_regs(Wr)
    sm = difflib.SequenceMatcher(None, shape(We), shape(Wr), autojunk=False)
    for a, b, n in sm.get_matching_blocks():
        for o in range(n):
            x, y = We[a + o], Wr[b + o]; op = x >> 26
            if op not in MEM or y >> 26 != op: continue
            bx, by = (x >> 21) & 31, (y >> 21) & 31
            if bx not in te or by not in tr: continue
            ox = (x & 0xFFFF) - (0x10000 if x & 0x8000 else 0); oy = (y & 0xFFFF) - (0x10000 if y & 0x8000 else 0)
            if ox < 0 or oy < 0: continue
            votes[(cls, ox)][oy] += 1
w = csv.writer(open('research/retail_fieldmap.csv', 'w', newline='', encoding='utf-8')); w.writerow(['class', 'e_off', 'retail_off', 'votes', 'agree', 'delta'])
stat = collections.Counter()
for (cls, ox), c in sorted(votes.items()):
    oy, v = c.most_common(1)[0]; tot = sum(c.values())
    w.writerow([cls, hex(ox), hex(oy), tot, f'{v/tot:.2f}', hex(oy - ox)]); stat[cls] += 1
for k, v in stat.most_common(15): print(k, v)
