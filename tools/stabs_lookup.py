#!/usr/bin/env python3
"""Look up a B3 function's Burnout Revenge counterpart in the STABS dump.

    python3 tools/stabs_lookup.py <B3 mangled symbol> [--all] [--brief]

Source: research/stabs/revenge_jul14_functions.cpp (stdump of Revenge Jul 14 2005, GCC/SN;
docs/provenance.md "Revenge STABS dumps"). Each block there gives the address range, the
parameters and the locals in declaration order (stack offset or register), inlined bodies'
locals flattened in.

Mapping: the B3 name is MWCC-mangled (`Name__<n>ClassF<params>`, `__ct__`, `__dt__`), Revenge's
is GCC 2.x (`Name__<n>Class<params>`, const = `__C<n>Class`, ctor `__<n>Class`, dtor `_$_<n>Class`).
Both are split into (qualified class, method, params); the class matches after CB3 -> CB4 (also
in the params, length prefixes fixed). Candidates are ranked: exact params, then same parameter
count, then the rest. With one exact/count match it prints that block, otherwise the candidate
list (--all prints every candidate block). Blocks without an address are inline/out-of-line
copies stdump saw without code. The B3 size comes from build/vt/sizes or the retail map when
available (else omitted). Names from Revenge are [L] evidence for B3 only (docs/conventions.md).
"""
import re
import sys
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DUMP = os.path.join(ROOT, 'research', 'stabs', 'revenge_jul14_functions.cpp')

HDR = re.compile(r'^(?:/\* ([0-9a-f]{8}) ([0-9a-f]{8}) \*/ )?(?:static )?(.*?)\b([A-Za-z_$][A-Za-z0-9_$]*)\((.*)$')


def read_class(s, i):
    """Read one <n>Name or Q<k><n>Name... starting at s[i]; return (name, end)."""
    if i < len(s) and s[i] == 'Q':
        if s[i + 1] == '_':          # Q_<k>_
            j = s.index('_', i + 2)
            k = int(s[i + 2:j]); i = j + 1
        else:
            k = int(s[i + 1]); i += 2
        parts = []
        for _ in range(k):
            n, i = read_class(s, i)
            parts.append(n)
            if i < len(s) and s[i] == '_' and k > 1 and s[i + 1:i + 2].isdigit():
                i += 1
        return '::'.join(parts), i
    m = re.match(r'(\d+)', s[i:])
    if not m:
        return None, i
    n = int(m.group(1)); i += len(m.group(1))
    return s[i:i + n], i + n


def split_mangled(sym, gcc):
    """-> (class, method, params) or None. Free functions: class ''."""
    if not gcc:
        m = re.match(r'^(__ct|__dt)__(.*)$', sym)
        if m:
            meth, rest = ('ctor' if m.group(1) == '__ct' else 'dtor'), m.group(2)
        else:
            k = sym.find('__', 1)
            if k < 0:
                return ('', sym, None)
            meth, rest = sym[:k], sym[k + 2:]
        if rest.startswith('F'):
            return ('', meth, rest[1:])
        cls, i = read_class(rest, 0)
        if cls is None:
            return None
        if rest[i:i + 2] == 'CF':
            i += 2
        elif rest[i:i + 1] == 'F':
            i += 1
        return (cls, meth, rest[i:])
    if sym.startswith('_$_'):
        cls, i = read_class(sym, 3)
        return (cls, 'dtor', sym[i:])
    m = re.match(r'^__(\d|Q)', sym)
    if m:
        cls, i = read_class(sym, 2)
        return (cls, 'ctor', sym[i:])
    k = sym.find('__', 1)
    if k < 0:
        return ('', sym, None)
    meth, rest = sym[:k], sym[k + 2:]
    if rest.startswith('F'):
        return ('', meth, rest[1:])
    if rest.startswith('C') and rest[1:2].isdigit() or rest.startswith('CQ'):
        rest = rest[1:]
    cls, i = read_class(rest, 0)
    if cls is None:
        return None
    return (cls, meth, rest[i:])


def b3_to_b4(s):
    """CB3X -> CB4X in a class name or a mangled param string."""
    return re.sub(r'CB3', 'CB4', s or '')


def norm_params(p, gcc):
    if p is None:
        return None
    if not gcc and p == 'v':
        p = ''
    return p


def nparams_text(hdr_rest):
    """Count the params in the dump's C-like parameter list (minus `this`)."""
    inner = hdr_rest.rsplit(')', 1)[0]
    if not inner.strip():
        return 0
    n = inner.count('/*')
    return n - (1 if '*this' in inner else 0)


def count_mangled(p):
    """Rough parameter count of a mangled param string (enough to rank overloads)."""
    if p is None:
        return -1
    i = n = 0
    while i < len(p):
        c = p[i]
        if c in 'PRCVU':            # qualifiers / pointer / ref / unsigned
            i += 1; continue
        if c in 'TN':               # GCC back-references
            i += 2 if c == 'T' else 3; n += 1; continue
        if c.isdigit() or c == 'Q':
            _, i = read_class(p, i); n += 1; continue
        if c == 'A':                # array
            j = p.find('_', i); i = j + 1 if j > 0 else i + 1; continue
        n += 1; i += 1
    return n


def load_blocks():
    lines = open(DUMP, encoding='utf-8', errors='replace').read().split('\n')
    blocks, i = [], 0
    curfile = ''
    while i < len(lines):
        ln = lines[i]
        if ln.startswith('// FILE -- '):
            curfile = ln[11:]
        m = HDR.match(ln) if ln and not ln.startswith(('\t', '//', ' ')) else None
        if m and m.group(4):
            j = i
            if not ln.rstrip().endswith('{}'):
                while j + 1 < len(lines) and lines[j + 1] != '}':
                    j += 1
                j += 1
            blocks.append(dict(start=m.group(1), end=m.group(2), sym=m.group(4),
                               rest=m.group(5), text='\n'.join(lines[i:j + 1]), file=curfile))
            i = j + 1
            continue
        i += 1
    return blocks


def b3_size(sym):
    p = os.path.join(ROOT, 'config', 'symbol_addrs_b3names.txt')
    try:
        for ln in open(p, encoding='utf-8', errors='replace'):
            if ln.startswith(sym + ' ='):
                m = re.search(r'size:(0x[0-9A-Fa-f]+)', ln)
                a = re.search(r'= (0x[0-9A-Fa-f]+)', ln)
                return (a.group(1) if a else None), (int(m.group(1), 16) if m else None)
    except OSError:
        pass
    return None, None


def main(argv):
    args = [a for a in argv if not a.startswith('--')]
    if not args:
        print(__doc__); return 2
    sym = args[0]
    want = split_mangled(sym, gcc=False)
    if not want:
        print('cannot parse', sym); return 1
    cls, meth, par = want
    cls4, par4 = b3_to_b4(cls), norm_params(b3_to_b4(par), False)
    cands = []
    for b in load_blocks():
        try:
            g = split_mangled(b['sym'], gcc=True)
        except (ValueError, IndexError, TypeError):
            g = None
        if not g or g[1] != meth or g[0] != cls4:
            continue
        gp = g[2]
        rank = 0 if gp == par4 else (1 if count_mangled(gp) == count_mangled(par4) else 2)
        cands.append((rank, 0 if b['start'] else 1, b))
    addr, size = b3_size(sym)
    print('// B3 %s  (%s::%s%s)' % (sym, cls, meth, ' @ ' + addr if addr else ''))
    if not cands:
        print('// no Revenge counterpart for %s::%s' % (cls4, meth)); return 1
    cands.sort(key=lambda t: (t[0], t[1]))
    best = [c for c in cands if c[0] == cands[0][0]]
    with_code = [c for c in best if c[2]['start']]
    show = cands if '--all' in argv else (with_code[:1] or best[:1])
    if len(cands) > 1:
        print('// %d candidates (rank 0 exact params, 1 same count, 2 other):' % len(cands))
        for r, _, b in cands:
            sz = int(b['end'], 16) - int(b['start'], 16) if b['start'] else None
            print('//   [%d] %s  %s' % (r, b['sym'], ('0x%x bytes (%d instrs)' % (sz, sz // 4)) if sz else 'no code'))
    for r, _, b in show:
        sz = int(b['end'], 16) - int(b['start'], 16) if b['start'] else None
        print('// Revenge %s  %s  file %s' % (b['sym'], ('0x%x bytes = %d instrs' % (sz, sz // 4)) if sz else 'no code',
                                            b['file']))
        if '--brief' not in argv:
            print(b['text'])
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
