"""Final retail names = merged v2 + v1 names at addresses v2 leaves unnamed (if the name is not used elsewhere in v2)
+ overrides (research/retail_name_overrides.csv). usage: finalize_retail_names.py <v2.csv> <v1.csv> <out.csv>"""
import csv, sys
v2 = {r['elf_addr']: r for r in csv.DictReader(open(sys.argv[1], encoding='utf-8'))}
v1 = {r['elf_addr']: r for r in csv.DictReader(open(sys.argv[2], encoding='utf-8'))}
used = {r['name'] for r in v2.values()}
carried = 0
for a, r in v1.items():
    if a not in v2 and r['name'] not in used and r['confidence'] != 'conflict':
        r = dict(r); r['method'] += ' (v1 carry-over)'; v2[a] = r; carried += 1
ov = 0
for r in csv.DictReader(open('research/retail_name_overrides.csv', encoding='utf-8')):
    src = v2.get(r['elf_addr'], {}).get('source', '')
    v2[r['elf_addr']] = dict(elf_addr=r['elf_addr'], name=r['name'], source=src, confidence=r['confidence'], method=r['method']); ov += 1
w = csv.DictWriter(open(sys.argv[3], 'w', newline='', encoding='utf-8'), fieldnames=['elf_addr', 'name', 'source', 'confidence', 'method'])
w.writeheader()
for a in sorted(v2): w.writerow({k: v2[a][k] for k in w.fieldnames})
print('final', len(v2), 'carried from v1', carried, 'overrides', ov)
