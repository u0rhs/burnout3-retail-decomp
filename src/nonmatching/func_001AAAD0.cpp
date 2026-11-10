// NONMATCHING: func_001AAAD0 -- retail 332 / ours 342 instructions, 266 in changed runs
// v310: logic complete (matrix -> 3 byte angles: asin(-mRight.z) / atan2 lanes, gimbal branch, clamp to [-pi,pi] * 255/2pi). Left (332 vs 342, 266 changed, frame 0x300 vs 0x2F0): retail puts every clamp's set-1.0 arm out of line at the function end (no if/else/!()/pragma form tried reproduces it); lane reads (header Z()/Y() copy) come out as addiu+lwc1 0(reg) when several reads share the function where retail folds lwc1 K(sp); one extra 16-byte slot. Min/max use literals, add/mul the D_004E0D1C/D_004E1388 globals (retail reloads them after each sb).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001AAAD0 -- hand-matched (v310). Unnamed in every table: a placeholder with C linkage (the asm label).
// A rotation matrix to three byte angles: asin of -mRight.z, atan2 of the other lanes (a gimbal-lock branch when
// |asin| == pi/2), each angle clamped to [-pi, pi] and scaled by 255/(2 pi). Types are [G].
// func_0011E340 / func_0011E358 are the libm wrappers that tail-jump to __ieee754_asinf / __ieee754_atan2f [C asm].

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

extern "C" float func_0011E340(float);
extern "C" float func_0011E358(float, float);
extern float D_004E0D1C;
extern float D_004E1388;
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }

// [L] N185: stands in for a missing GtMathPs2 inline (a single-lane negate, `vsub.z D, $vf0, S`)
static inline ZAxisType func_001AAAD0_inl1(const ZAxisType & z)
{
    u_long128 t = z.lVector;
    asm("vsub.z %0, $vf0, %0" : "+j"(t));
    return ZAxisType(t);
}

static inline unsigned char func_001AAAD0_inl2(float x)
{
    return (unsigned char)((GtMath::Min(3.1415927f, GtMath::Max(-3.1415927f, x)) + D_004E0D1C) * D_004E1388);
}

// 0x001AAAD0
extern "C" void func_001AAAD0(const CGtMatrix3x4 * src, unsigned char * a, unsigned char * b, unsigned char * c)
{
    CGtMatrix3x4 m = *src;
    float r, p, y;
    if (m.mRight.Z() > 1.0f) m.mRight.SetZ(1.0f);
    else if (m.mRight.Z() < -1.0f) m.mRight.SetZ(-1.0f);
    r = func_0011E340(func_001AAAD0_inl1(m.mRight.Z()));
    if (fabsf(r) == 1.5707964f) {
        if (m.mUp.X() > 1.0f) m.mUp.SetX(1.0f);
        else if (m.mUp.X() < -1.0f) m.mUp.SetX(-1.0f);
        if (m.mUp.Y() > 1.0f) m.mUp.SetY(1.0f);
        else if (m.mUp.Y() < -1.0f) m.mUp.SetY(-1.0f);
        p = func_0011E358(m.mUp.X(), m.mUp.Y());
        y = 0.0f;
    } else {
        if (m.mUp.Z() > 1.0f) m.mUp.SetZ(1.0f);
        else if (m.mUp.Z() < -1.0f) m.mUp.SetZ(-1.0f);
        if (m.mAt.Z() > 1.0f) m.mAt.SetZ(1.0f);
        else if (m.mAt.Z() < -1.0f) m.mAt.SetZ(-1.0f);
        if (m.mRight.Y() > 1.0f) m.mRight.SetY(1.0f);
        else if (m.mRight.Y() < -1.0f) m.mRight.SetY(-1.0f);
        if (m.mRight.X() > 1.0f) m.mRight.SetX(1.0f);
        else if (m.mRight.X() < -1.0f) m.mRight.SetX(-1.0f);
        p = func_0011E358(m.mUp.Z(), m.mAt.Z());
        y = func_0011E358(m.mRight.Y(), m.mRight.X());
    }
    *a = func_001AAAD0_inl2(y);
    *b = func_001AAAD0_inl2(p);
    *c = func_001AAAD0_inl2(r);
}

