"""F names for the chained route: E->F transfers, high -> 'verified', medium -> 'boundary' (as in an earlier pass).
usage: make_f_names.py <xfer_E_F.csv> <out.csv>"""
import csv, sys
w = csv.writer(open(sys.argv[2], 'w', newline='', encoding='utf-8')); w.writerow(['entry', 'name', 'class'])
n = 0
for r in csv.DictReader(open(sys.argv[1], encoding='utf-8')):
    if r['name'] and r['confidence'] in ('high', 'medium'):
        w.writerow([r['dst_entry'], r['name'], 'verified' if r['confidence'] == 'high' else 'boundary']); n += 1
print('F names', n)
