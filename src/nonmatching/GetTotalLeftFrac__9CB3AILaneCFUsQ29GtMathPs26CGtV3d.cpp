// NONMATCHING: GetTotalLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3d -- retail 66 / ours 65 instructions, 15 in changed runs
// a210: logic complete, frame 0x80 matches, 65 vs 66 instrs, 15 in changed runs, all VU numbering/GPR temps. Retail: cross result v0->qmtc2 v0,vf3 (ours v1); final dot has one=vf3 (vaddw.x vf3; qmfc2 v0,vf3 placed BEFORE qmtc2.ni s2,vf4), pos=vf2, side=vf1 (sub dest), right=vf4, vmul vf2,vf1,vf4; ours: one vf1, right vf1, sub vf2. Local N185 stand-ins a210_* (u_long128 helpers; by-value CGtV3d helper params add dead frame slots, so pass mData).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [L] N185: file-local stand-ins (retail's non-hoisted forms: 1.0 parked in a GPR, compiler-chosen VU registers)
static inline float a210_abs(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline u_long128 a210_one() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
static inline u_long128 a210_dot(u_long128 a, u_long128 b)
{
    u_long128 one = a210_one();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %2" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a), "j"(b));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return d;
}
static inline u_long128 a210_sqlen(u_long128 a)
{
    u_long128 one = a210_one();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %1" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return d;
}
static inline void a210_sety(u_long128 &v, float y)
{
    asm("qmtc2.ni %1, $vf1" "\n\t" "vaddx.y %0, $vf0, $vf1x" : "+j"(v) : "r"(y));
}
static inline u_long128 a210_sub(u_long128 a, u_long128 b)
{
    asm("vsub.xyz %0, %1, %0" : "+j"(b) : "j"(a));
    return b;
}
static inline u_long128 a210_neg(u_long128 a)
{
    u_long128 t;
    asm("qmtc2.i %1, $vf1" "\n\t" "vsub.x $vf1, $vf0, $vf1" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "r"(a));
    return t;
}
static inline u_long128 a210_norm(u_long128 a)
{
    u_long128 l = a210_sqlen(a);
    u_long128 t, v = a;
    asm volatile("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t"
        "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v) : "r"(l));
    return t;
}
static inline float a210_f(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }
static inline u_long128 a210_cross(u_long128 a, u_long128 b)
{
    u_long128 t;
    asm volatile("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b) : "j"(a));
    return t;
}
extern u_long128 kYAxis;
class CB3AILane {
public:
    float GetTotalLeftFrac(unsigned short p0, CGtV3d p1) const;
    void GetAvgForwardsVector(unsigned short, CGtV3d *) const;
    void GetSidePosition(unsigned short, int, CGtV3d *) const;
    float GetTotalWidth(unsigned short, unsigned short) const;
};
float CB3AILane::GetTotalLeftFrac(unsigned short p0, CGtV3d p1) const
{
    CGtV3d pos = p1;
    CGtV3d side;
    CGtV3d fwd;
    float w = GetTotalWidth(p0, p0);
    GetAvgForwardsVector(p0, &fwd);
    u_long128 r = a210_cross(fwd.mData, kYAxis);
    a210_sety(r, 0.0f);
    r = a210_norm(r);
    GetSidePosition(p0, 1, &side);
    u_long128 d = a210_sub(pos.mData, side.mData);
    return a210_f(a210_dot(d, r)) / w;
}
