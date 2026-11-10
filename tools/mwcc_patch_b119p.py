# mwcc_patch_b119p.py <b119 mwccps2.exe> <dst mwccps2.exe>: b119p = b119 + N184 (54 bytes) + N216 (3 bytes) + N223 (6 bytes)
# + N251 (1 byte) + N285 (1 byte)
# b119 -> "b103 partial-mask rule": a partial-lane write by a '&'-format VU op is a def+use (RMW)
# only for vmove (opcode 0x2ae), as in b103 (0x497b59..0x497b8b); b119 makes every '&' op RMW.
# Re-encodes b119 0x4910db..0x49111e (same length, no cave) and retargets the assert-continue jmp at 0x491521.
import sys, struct
FOFF = lambda va: va - 0x401000 + 0x400          # .text: va 0x401000 <-> file 0x400
src, dst = sys.argv[1], sys.argv[2]
d = bytearray(open(src, 'rb').read())
orig = bytes.fromhex(
 'c744241800000000'  # 4910db movl $0,0x18(%esp)
 '803f02' '89fb' '7422'  # cmpb $2,(%edi); mov %edi,%ebx; je 0x49110c
 '8d8000000000'      # 4910ea lea 0(%eax),%eax (pad)
 '8344241801' '837c241805' '0f8d10040000'  # 4910f0 addl; cmpl $5; jge 0x491510
 '83eb18' '803b02' '0f85e4ffffff'  # 491100 sub $0x18,%ebx; cmpb $2,(%ebx); jne 0x4910f0
 '837b040f' '740c'   # 49110c cmpl $0xf,0x4(%ebx); je 0x49111e
 '8165 0cefbfffff'.replace(' ', '') +  # 491112 andl $0xffffbfef,0xc(%ebp)
 '66834f0203')       # 491119 orw $3,0x2(%edi)
A = 0x4910db
assert d[FOFF(A):FOFF(A)+len(orig)] == orig, 'unexpected bytes (not b119?)'
new = bytes.fromhex(
 'c744241800000000'  # 4910db movl $0,0x18(%esp)
 '803f02' '89fb' '7418'  # 4910e3 cmpb; 4910e6 mov; 4910e8 je 0x491102
 '8344241801'        # 4910ea addl $1,0x18(%esp)        (loop head L1)
 '837c241805'        # 4910ef cmpl $5,0x18(%esp)
 '0f8d16040000'      # 4910f4 jge 0x491510
 '83eb18'            # 4910fa sub $0x18,%ebx            (assert-continue target)
 '803b02' '75e8'     # 4910fd cmpb $2,(%ebx); 491100 jne 0x4910ea
 '837b040f' '7416'   # 491102 cmpl $0xf,0x4(%ebx); 491106 je 0x49111e
 '81650cefbfffff'    # 491108 andl $0xffffbfef,0xc(%ebp)   (unchanged rule)
 '66817d28ae02' '7507'  # 49110f cmpw $0x2ae,0x28(%ebp); 491115 jne 0x49111e   (b103: vmove only)
 '66834f0203'        # 491117 orw $3,0x2(%edi)
 '6690')             # 49111c 2-byte nop
assert len(new) == len(orig), (len(new), len(orig))
d[FOFF(A):FOFF(A)+len(new)] = new
J = 0x491521
assert d[FOFF(J):FOFF(J)+5] == bytes.fromhex('e9dafbffff')
d[FOFF(J):FOFF(J)+5] = b'\xe9' + struct.pack('<i', 0x4910fa - (J + 5))
# N216: b119's array-construction loop builder (0x477810; b103 0x47e2c0) ends a member-array
# ctor loop with ST_IFGOTO(p < end) (kind 6, ELESS 0x13 -> `sltu`); b103 and retail use ST_IFNGOTO(p == end) (kind 7,
# EEQU 0x17 -> `bne`). 3 same-length bytes (cmpdiff2, build/vt/cmpdiff2/mkpatch_ctor.py); 3425/3425 proven identical.
for va, o, n in ((0x477b5e, 'c6450406', 'c6450407'),   # movb $6,4(%ebp) -> $7   (ST_IFGOTO -> ST_IFNGOTO)
                 (0x477db4, 'c6450406', 'c6450407'),   # same, out-of-line path back to 0x477b7e
                 (0x477b7e, '6a13', '6a17')):           # push $0x13 (ELESS) -> $0x17 (EEQU)
    assert d[FOFF(va):FOFF(va) + len(o) // 2] == bytes.fromhex(o), hex(va)
    d[FOFF(va):FOFF(va) + len(n) // 2] = bytes.fromhex(n)
# N223: b119's opcode table registers vmaddai / vmaddaq with the typo format strings
# '&+2A,2S,2IA;K' / '&+2A,2S,2QA;K' (stray 'A': 'illegal operand' for every form); restore b103's strings in place
# (= b119's own vmsubai form), 6 bytes (cmpdiff3, build/vt/cmpdiff3/mkpatch_vmaddai.py).
for off, o, n in ((0x1dfe77, b'&+2A,2S,2IA;K\0', b'&+2A,2S,2I;K\0\0'), (0x1dfe8d, b'&+2A,2S,2QA;K\0', b'&+2A,2S,2Q;K\0\0')):
    assert bytes(d[off:off + len(o)]) == o, hex(off)
    d[off:off + len(n)] = n
# N251: b119's opt_classresults (named-return-value) pass (0x477210) gives up on any
# function containing an inline-asm statement (statement kind 0x10): `cmp $0x10,%cl` at 0x4772a4. Retail elides the
# named-return copy in asm-bodied inlines (CGtMatrix3x4::operator*, N246/N250); immediate 0x10 -> 0x7f (no such
# kind), 1 byte (cc1, build/vt/cc1/mkpatch_nrvo.py). The pass only runs under `#pragma opt_classresults on`.
va = 0x4772a4
assert d[FOFF(va):FOFF(va) + 3] == bytes.fromhex('80f910'), hex(va)
d[FOFF(va) + 2] = 0x7f
# N285 (proposed 2026-10-31, cpatch2): an inline-asm `.set noreorder` region gives its blocks flags 0x4088 (b119 0x4906cc
# `orw $0x4088,0x631794`); bit 0x80 makes the peephole driver (0x4ba314 `test ecx,0x180`) skip them, so VU move folds and
# redundant qmtc2/qmfc2 round trips stay inside noreorder regions. Retail folds there (IntersectLineSegment__14CB3TrafficAxle
# 0x15F530 / UpdateHingedPart 0x1C89D4: `vopmsub.xyz $vf1,...` written straight to $vf1, no round trip). vcallms blocks keep
# their own 0x80 mark (0x4906f6; retail func_00272EA0 0x272F6C keeps lq+qmtc2 there). 0x4088 -> 0x4008, 1 byte.
va = 0x4906cc
assert d[FOFF(va):FOFF(va) + 9] == bytes.fromhex('66810d941763008840'), hex(va)
d[FOFF(va) + 7] = 0x08
open(dst, 'wb').write(d)
print('patched', dst)
