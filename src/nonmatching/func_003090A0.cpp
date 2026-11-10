// NONMATCHING: func_003090A0 -- retail 150 / ours 149 instructions, 124 in changed runs
// ghvu9: CreateRotationMatrixOnPrincipalAxis [L DNAT]; logic believed right (150 vs 149). Blockers: header SinCosFast(float) shape differs from retail (retail moves v out and does vsubi.xz into the angle's $vf1, trig constants lui'd early, axis lq'd at entry), and frame 0x210 vs 0x60 (retail: 26 dead 16-byte slots between k@0x1B0 and SinCosFast's v@0x10; m@0x1C0 above k).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003090A0 -- hand-written from the Ghidra draft (ghvu9).
// [L] DNAT: CreateRotationMatrixOnPrincipalAxis(GtMathPs2::CGtV3d,float) (research/proto/new_names.csv, high,
// B3TrafficSystemLoadAndRender.cpp). Returns a CGtMatrix3x4 through the hidden pointer in a0.

#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"

using namespace GtMathPs2;

// [L] N185: lane stand-ins for missing GtMathPs2 inlines (cross-lane copies / single-lane subtracts, compiler-chosen
// registers, as retail 0x309264..0x3092E0)
#define LANE1(op, d, a) asm(op " %0, $vf0, %1" : "+j"(d) : "j"(a))
#define LANE2(op, d, a, b) asm(op : "=j"(d) : "j"(a), "j"(b))

// 0x003090A0
extern "C" CGtMatrix3x4 func_003090A0(CGtV3d axis, float angle)
{
    CGtV3d k;
    k.SetX(1.0f);
    k.SetY(0.0f);
    CGtV4d sc = SinCosFast(angle);
    u_long128 omc, nax, as, t;
    CGtMatrix3x4 m;
    asm("vsuby.x %0, %1, %2y" : "=j"(omc) : "j"(k.mData), "j"(sc.mData));
    asm("vsub.xyz %0, $vf0, %1" : "=j"(nax) : "j"(axis.mData));
    asm("vaddx.z %0, $vf0, %1x" : "+j"(sc.mData) : "j"(omc));
    asm("vaddx.xyz %0, %0, %1x" : "+j"(nax) : "j"(k.mData));
    asm("vmulx.xyz %0, %1, %2x" : "=j"(as) : "j"(axis.mData), "j"(sc.mData));
    asm("vmulz.xyz %0, %0, %1z" : "+j"(nax) : "j"(sc.mData));
    asm("vsubx.x %0, %1, %2x" : "=j"(t) : "j"(k.mData), "j"(nax));
    asm("vaddx.x %0, $vf0, %1x" : "+j"(m.mRight.mData) : "j"(t));
    asm("vaddz.y %0, $vf0, %1z" : "+j"(m.mRight.mData) : "j"(as));
    asm("vsuby.y %0, %1, %2y" : "=j"(t) : "j"(k.mData), "j"(as));
    asm("vaddy.z %0, $vf0, %1y" : "+j"(m.mRight.mData) : "j"(t));
    asm("vsubz.y %0, %1, %2z" : "=j"(omc) : "j"(k.mData), "j"(as));
    asm("vaddy.x %0, $vf0, %1y" : "+j"(m.mUp.mData) : "j"(omc));
    asm("vsuby.x %0, %1, %2y" : "=j"(t) : "j"(k.mData), "j"(nax));
    asm("vaddx.y %0, $vf0, %1x" : "+j"(m.mUp.mData) : "j"(t));
    asm("vaddx.z %0, $vf0, %1x" : "+j"(m.mUp.mData) : "j"(as));
    asm("vsubx.y %0, %1, %2x" : "=j"(omc) : "j"(k.mData), "j"(as));
    asm("vaddy.x %0, $vf0, %1y" : "+j"(m.mAt.mData) : "j"(as));
    asm("vsubz.x %0, %1, %2z" : "=j"(t) : "j"(k.mData), "j"(nax));
    asm("vaddy.y %0, $vf0, %1y" : "+j"(m.mAt.mData) : "j"(omc));
    asm("vaddx.z %0, $vf0, %1x" : "+j"(m.mAt.mData) : "j"(t));
    m.mPos.Zero();
    return m;
}
