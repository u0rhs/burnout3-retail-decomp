// NONMATCHING: func_001AA680 -- retail 274 / ours 274 instructions, 79 in changed runs
// 79 off: logic/op sequence exact; frame 0x30 vs retail 0x2D0 (dead slots); SinCosFast2 head numbering (retail b->vf1 first, a->vf2, v=vf3; header hard-codes vf1); trig I-constant GPRs t3/t4/t5 rotated; matrix-lane stand-ins number s/t/rows vf5/vf4/vf2-3 vs retail vf4/vf3/vf5
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001AA680 -- hand-written (ghvu16) from the Ghidra draft and retail. Unnamed in every table, so the asm label with
// C linkage. A rotation matrix from three byte angles (angle = n * 2pi/255 - pi; retail .lit4 values): SinCosFast2 for
// two of them, SinCosFast for the third (GtMathPs2Trig.h), then the three rows' lanes in place. Every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV4d;
using GtMathPs2::CGtMatrix3x4;

// [L] N185: stand-ins for missing GtMathPs2 lane-type operators (retail's single VU ops, compiler-chosen registers).

// [L] N185: GtMathPs2::SinCosFast2 (GtMathPs2Trig.h) with the two scalar moves on compiler-chosen registers (retail moves
// b into $vf1 ahead of a into $vf2); the rest as the header.
static inline CGtV4d func_001AA680_inl1(float a, float b)
{
    CGtV4d v;
    u_long128 w;
    u_long128 qa, qb;
    asm("qmtc2.ni %1, %0" : "=j"(qa) : "r"(a));
    asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(qa));
    asm("qmtc2.ni %1, %0" : "=j"(qb) : "r"(b));
    asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(qb));
    asm("vaddx.y %0, $vf0, %0x" : "+j"(v.mData));
    asm("vmulz.w %0, $vf0, %0z" : "+j"(v.mData));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3FC90FDB));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xz %0, %1, $I" : "=j"(w) : "j"(v.mData));
    asm(".set reorder");
    u_long128 x, one, f, y, t, t2, t4, t8, c1, c3, ca, cb, cc, r;
    asm(".set noreorder");
    asm("vabs.xyzw %0, %1" : "=j"(x) : "j"(w));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmaxw.xyzw %0, $vf0, $vf0w" : "=j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xBE22F983));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmulai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x4B400000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I\n\tvmaddai.xyzw $ACC, %0, $I" : : "j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0xBE22F983));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x3F000000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubi.xyzw %0, %1, $I" : "=j"(f) : "j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vabs.xyzw %0, %1" : "=j"(y) : "j"(f));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3E800000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xyzw %0, %1, $I" : "=j"(t) : "j"(y));
    asm(".set reorder");
    asm("vmul.xyzw %0, %1, %1" : "=j"(t2) : "j"(t));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t4) : "j"(t2));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t8) : "j"(t4));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2992661));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(c1) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmul.xyzw %0, %1, %2" : "=j"(c3) : "j"(c1), "j"(t2));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2255DE0));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(ca) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x42A33457));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cb) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x421ED7B7));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cc) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmula.xyzw $ACC, %0, %1" : : "j"(ca), "j"(t2));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(c3), "j"(t4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21" : : "r"(0x40C90FDA));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(cb), "j"(t4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmaddai.xyzw $ACC, %0, $I" : : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadd.xyzw %0, %1, %2" : "=j"(r) : "j"(cc), "j"(t8));
    asm(".set reorder");
    return CGtV4d(r);
}

// 0x001AA680
extern "C" void func_001AA680(CGtMatrix3x4 *m, unsigned int a, unsigned int b, unsigned int c)
{
    float fa = (float)a;
    fa *= 0.02463994175f;
    fa -= 3.141592741f;
    float fb = (float)b;
    fb *= 0.02463994175f;
    fb -= 3.141592741f;
    float fc = (float)c;
    fc *= 0.02463994175f;
    fc -= 3.141592741f;
    CGtV4d t = func_001AA680_inl1(fc, fb);
    CGtV4d s = GtMathPs2::SinCosFast(fa);
    u_long128 A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S;
    asm("vmuly.y %0, %1, %2y" : "=j"(A) : "j"(s.mData), "j"(t.mData));
    asm("vmuly.x %0, %1, %2y" : "=j"(B) : "j"(s.mData), "j"(t.mData));
    asm("vaddy.x %0, $vf0, %1y" : "+j"(m->mRight.mData) : "j"(A));
    asm("vaddx.y %0, $vf0, %1x" : "+j"(m->mRight.mData) : "j"(B));
    asm("vsub.x %0, $vf0, %1" : "=j"(C) : "j"(t.mData));
    asm("vaddx.z %0, $vf0, %1x" : "+j"(m->mRight.mData) : "j"(C));
    asm("vmulw.x %0, %1, %2w" : "=j"(D) : "j"(s.mData), "j"(t.mData));
    asm("vsub.x %0, $vf0, %1" : "=j"(E) : "j"(D));
    asm("vmulx.y %0, %1, %2x" : "=j"(F) : "j"(s.mData), "j"(t.mData));
    asm("vmulz.y %0, %0, %1z" : "+j"(F) : "j"(t.mData));
    asm("vaddy.x %0, %1, %2y" : "=j"(G) : "j"(E), "j"(F));
    asm("vaddx.x %0, $vf0, %1x" : "+j"(m->mUp.mData) : "j"(G));
    asm("vmulw.y %0, %1, %2w" : "=j"(H) : "j"(s.mData), "j"(t.mData));
    asm("vmulx.x %0, %1, %2x" : "=j"(I) : "j"(s.mData), "j"(t.mData));
    asm("vmulz.x %0, %0, %1z" : "+j"(I) : "j"(t.mData));
    asm("vaddx.y %0, %1, %2x" : "=j"(J) : "j"(H), "j"(I));
    asm("vaddy.y %0, $vf0, %1y" : "+j"(m->mUp.mData) : "j"(J));
    asm("vmulz.y %0, %1, %1z" : "=j"(K) : "j"(t.mData));
    asm("vaddy.z %0, $vf0, %1y" : "+j"(m->mUp.mData) : "j"(K));
    asm("vmulx.y %0, %1, %2x" : "=j"(L) : "j"(s.mData), "j"(t.mData));
    asm("vmulz.x %0, %1, %2z" : "=j"(M) : "j"(s.mData), "j"(t.mData));
    asm("vmulw.y %0, %0, %1w" : "+j"(L) : "j"(t.mData));
    asm("vaddy.x %0, %1, %2y" : "=j"(N) : "j"(M), "j"(L));
    asm("vaddx.x %0, $vf0, %1x" : "+j"(m->mAt.mData) : "j"(N));
    asm("vmulz.y %0, %1, %2z" : "=j"(O) : "j"(s.mData), "j"(t.mData));
    asm("vsub.y %0, $vf0, %1" : "=j"(P) : "j"(O));
    asm("vmulx.x %0, %1, %2x" : "=j"(Q) : "j"(s.mData), "j"(t.mData));
    asm("vmulw.x %0, %0, %1w" : "+j"(Q) : "j"(t.mData));
    asm("vaddx.y %0, %1, %2x" : "=j"(R) : "j"(P), "j"(Q));
    asm("vaddy.y %0, $vf0, %1y" : "+j"(m->mAt.mData) : "j"(R));
    asm("vmulw.y %0, %1, %1w" : "=j"(S) : "j"(t.mData));
    asm("vaddy.z %0, $vf0, %1y" : "+j"(m->mAt.mData) : "j"(S));
}
