// GtMathPs2Trig: the GtMathPs2 fast trig inlines, kept apart from b3/GtMathPs2.h.
// [C] names: GtMathPs2::CosFast4(CGtV4d) (520 bytes), SinCosFast2(float, float) (632) and SinCosFast(float) (588) in
//     research/E_B3O0PCH_symbols.csv. [G] this file's name and the split: no file evidence. The bodies sit outside
//     GtMathPs2.h because merely defining CosFast4 there perturbs register allocation in unrelated proven units
//     (B3HUDScore_001A1CD0.cpp s0/s1, func_003BD760; hdr14 N232: the effect flips with the count of noreorder statements,
//     heap-layout noise): include this header only where they are used.
// [L] bodies (hdr13, N231): compiler-chosen VU registers; one-op statements, each but the power chain in its own
//     noreorder region (N209 parking); I-register constants as int literals through ctc2 $vi21.
// [L] hdr14: SinCosFast/SinCosFast2 carry their own copy of the polynomial (no CosFast4 call): the map emits CosFast4 first at
//     0x432090, long after SinCosFast (0x132B10) and SinCosFast2 (0x1A0D00), so neither calls it out of line; -O0 sizes
//     584 / 652 (map 588 / 632; were 176 / 244); CosFast4 472 (map 520, open). Reroutes: func_002BB420 68, PrepareRotate 192.
#ifndef B3_GTMATHPS2TRIG_H
#define B3_GTMATHPS2TRIG_H

#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"

namespace GtMathPs2 {

#if defined(__MWERKS__)
inline CGtV4d CosFast4(CGtV4d v)
{
    u_long128 a, one, f, b, t, t2, t4, t8, c1, c3, ca, cb, cc, r;
    asm(".set noreorder");
    asm("vabs.xyzw %0, %1" : "=j"(a) : "j"(v.mData));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmaxw.xyzw %0, $vf0, $vf0w" : "=j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xBE22F983));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmulai.xyzw $ACC, %0, $I" : : "j"(a));
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
    asm("vmsubai.xyzw $ACC, %0, $I" : : "j"(a));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x3F000000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubi.xyzw %0, %1, $I" : "=j"(f) : "j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vabs.xyzw %0, %1" : "=j"(b) : "j"(f));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3E800000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xyzw %0, %1, $I" : "=j"(t) : "j"(b));
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
inline CGtV4d SinCosFast2(float a, float b)
{
    CGtV4d v;
    u_long128 w;
    asm("qmtc2.ni %1, $vf1\n\tvaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(a));
    asm("qmtc2.ni %1, $vf1\n\tvaddx.z %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(b));
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
inline CGtV4d SinCosFast(float a)
{
    CGtV4d v;
    u_long128 w;
    asm("qmtc2.ni %1, $vf1\n\tvaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(a));
    asm("vaddx.y %0, $vf0, %0x" : "+j"(v.mData));
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
#endif

#if defined(__MWERKS__)
// ---- gapE (2026-10-30): CreateRotationMatrix3x4 ----
// [C] API: B3O0PCH map (GtMathPs2::CreateRotationMatrix3x4(CGtV3d,float), 1372 bytes). [C] order: the helpers the map emits after it
// (0x132430..0x132D80), read backwards, are this body's first uses in this order (build/vt/gapE/notes.txt). [L] body: retail's inlined
// copies (98 in 35 functions, build/vt/gapE/census.txt; func_00429BE0 0x429E40..0x429EE8 op for op): a rotation by `angle` radians
// about the normalised axis, k = 1 - cos kept in the sin/cos vector's z, rows from (1 - a*a) k, the cross terms (yz, zx, xy) k and
// a sin; mPos zero. Local names after Revenge's inlined copy (`lRotateMatrix`, STABS) [L], the others [G].
// -O0 -inline off 1244 (map 1372, open: the map also emits CGtV3d::IsEffectivelyZero and XAxisType() next to it [G]).
inline CGtMatrix3x4 CreateRotationMatrix3x4(CGtV3d axis, float angle)
{
    CGtMatrix3x4 lRotateMatrix;
    CGtV3d lOne;
    lOne.SetX(1.0f);
    axis.Normalise();
    CGtV3d lSinCos(SinCosFast(angle).GetRawData());
    lSinCos.SetZ(lOne.X() - lSinCos.Y());
    CGtV3d lOneMinusSq = -(axis * axis);
    lOneMinusSq += lOne.X();
    lOneMinusSq *= lSinCos.Z();
    CGtV3d lCross;
    lCross.SetX(axis.Y() * axis.Z());
    lCross.SetY(axis.Z() * axis.X());
    lCross.SetZ(axis.X() * axis.Y());
    CGtV3d lAxisSin = axis * lSinCos.X();
    lCross *= lSinCos.Z();
    lRotateMatrix.mRight.SetX(lOne.X() - lOneMinusSq.X());
    lRotateMatrix.mRight.SetY(lCross.Z() + lAxisSin.Z());
    lRotateMatrix.mRight.SetZ(lCross.Y() - lAxisSin.Y());
    lRotateMatrix.mUp.SetX(lCross.Z() - lAxisSin.Z());
    lRotateMatrix.mUp.SetY(lOne.X() - lOneMinusSq.Y());
    lRotateMatrix.mUp.SetZ(lCross.X() + lAxisSin.X());
    lRotateMatrix.mAt.SetX(lCross.Y() + lAxisSin.Y());
    lRotateMatrix.mAt.SetY(lCross.X() - lAxisSin.X());
    lRotateMatrix.mPos.Zero();
    lRotateMatrix.mAt.SetZ(lOne.X() - lOneMinusSq.Z());
    return lRotateMatrix;
}
#endif

} // namespace GtMathPs2
#endif
