// NONMATCHING: GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df -- retail 84 / ours 85 instructions, 55 in changed runs
// a210: logic believed complete (85 vs 84 instrs, 55 in changed runs): seg ushort pair equal -> 0.5f; d = P0-P1 SetY(0), GetLength, w = 0+len-2f (adda.s zero/msub.s); n = Normalise(P1-P0); (dot(pos-P0,n) - f)/w with vsubx.x. Left: VU numbering (retail vf1..vf4 w/ vsub dest=vf1, normalise in vf4), adda.s zero,len scheduling (ours add.s extra), GetLength spill order, loads of D_0064D354 pts re-done as lqc2 at 0x145F84/94.
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
static inline u_long128 a210_xsubf(u_long128 a, float f)
{
    asm("qmtc2.ni %1, $vf2" "\n\t" "vsubx.x %0, %0, $vf2x" : "+j"(a) : "r"(f));
    return a;
}
static inline u_long128 a210_len(u_long128 a)
{
    u_long128 l = a210_sqlen(a);
    u_long128 one, r;
    asm("qmtc2.i %2, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(r), "=&r"(one) : "r"(l));
    return r;
}
struct UnkStruct_glf_seg { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_glf_arr { UnkStruct_glf_seg *field_0; };
struct UnkStruct_glf_pt { CGtV3d field_0; };
struct UnkStruct_D_0064D354 { UnkStruct_glf_pt *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
class CB3AILane {
public:
    float GetLeftFrac(unsigned short p0, CGtV3d p1, float p2) const;
    unsigned char pad_0[4];
    UnkStruct_glf_arr *field_4;
};
float CB3AILane::GetLeftFrac(unsigned short p0, CGtV3d p1, float p2) const
{
    UnkStruct_glf_seg *s = &field_4->field_0[p0];
    if (s->field_2 == s->field_0) {
        return 0.5f;
    }
    u_long128 a = D_0064D354.field_0[s->field_2].field_0.mData;
    u_long128 b = D_0064D354.field_0[s->field_0].field_0.mData;
    u_long128 d = a210_sub(b, a);
    a210_sety(d, 0.0f);
    float zero = 0.0f;
    float w = zero + a210_f(a210_len(d)) - 2.0f * p2;
    u_long128 n = a210_sub(D_0064D354.field_0[s->field_2].field_0.mData, D_0064D354.field_0[s->field_0].field_0.mData);
    n = a210_norm(n);
    u_long128 q = a210_sub(p1.mData, D_0064D354.field_0[s->field_0].field_0.mData);
    return a210_f(a210_xsubf(a210_dot(q, n), p2)) / w;
}
