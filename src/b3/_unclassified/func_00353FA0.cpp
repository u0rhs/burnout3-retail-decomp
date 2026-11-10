// Hand-written; the lifter refused it (v257: goto-form state test, a210-style parked-1.0 sqlen + GetLength tail in .set noreorder, compiler-chosen vsub, N140 pads (5 top + 1 in the accumulate inline)).

// Hand-written (v257); the lifter refused it. CB3CrashAnalyser family callback [G] (neighbour of func_00353F30, same
// (vector, mode, params, accumulator) shape and the same w*2 lane scale). Types and fields are placeholders [G].
// Body: +10 when the candidate is the current target; with the "only" flag set, only states 1-3 count; weight 1000 for
// states 1-3 (else the object's field_60); a distance factor from |v - acc| (2 / 1.5 / 1 / 0.25 / 0); then
// accumulate 1.2*w*k (mode 2) or k*w*(field_20 / (2*v.w)).
// [L] N185 stand-ins: the squared length with the 1.0 parked in a GPR on compiler-chosen VU registers (a210_sqlen form),
// CGtV3d::GetLength's sqrt tail (the header body) inside a `.set noreorder` region (as v241's Normalise: else b119
// schedules the 10.0f constant's lui into the vwaitq gap and the 1.0 takes v1), and a compiler-chosen vsub.
// [G] N140/N186 frame pads: five 16-byte pads first (retail frame 0xD0) and a 16-byte pad in the accumulate inline (retail
// keeps one 16-byte slot below the W() lane copy at sp+0x10).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00353FA0_3 { unsigned char pad_0[0x215]; signed char field_215; };
struct UnkStruct_00353FA0_2 { unsigned char pad_0[0x40]; UnkStruct_00353FA0_3 * field_40; unsigned char pad_44[0x1C]; float field_60; };
struct UnkStruct_00353FA0_0 { CGtV4d field_0; unsigned char pad_10[0x24]; UnkStruct_00353FA0_2 * field_34; };
struct UnkStruct_00353FA0_a2 { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_00353FA0_a3 { CGtV3d field_0; UnkStruct_00353FA0_3 * field_10; float field_14; unsigned char field_18; };
static inline u_long128 func_00353FA0_inl1() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
static inline u_long128 func_00353FA0_inl2(u_long128 a)
{
    u_long128 one = func_00353FA0_inl1();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %1" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(a));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return d;
}
static inline XAxisType func_00353FA0_inl3(CGtV3d a)
{
    u_long128 l = func_00353FA0_inl2(a.mData);
    u_long128 one, r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(r), "=&r"(one) : "r"(l));
    asm(".set reorder");
    return XAxisType(r);
}
static inline CGtV3d func_00353FA0_inl4(CGtV3d a, CGtV3d b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
// [G] N140 pads (16 bytes each)
struct UnkStruct_00353FA0_pad { int x[4]; UnkStruct_00353FA0_pad() {} ~UnkStruct_00353FA0_pad() {} };
static inline void func_00353FA0_inl5(float &a, float x) { UnkStruct_00353FA0_pad p; a = a + x; }

// 0x00353FA0
extern "C" int func_00353FA0(UnkStruct_00353FA0_0 * v, int mode, UnkStruct_00353FA0_a2 * s, UnkStruct_00353FA0_a3 * acc)
{
    UnkStruct_00353FA0_pad p1, p2, p3, p4, p5;
    UnkStruct_00353FA0_2 * o = v->field_34;
    UnkStruct_00353FA0_3 * c = o->field_40;
    if (c == acc->field_10) {
        acc->field_14 = acc->field_14 + 10.0f;
        return 1;
    }
    unsigned char only = acc->field_18;
    if (only != 0 && !(c->field_215 == 2 || c->field_215 == 3 || c->field_215 == 1))
        return 1;
    float k;
    float w;
    if (only != 0) goto use;
    if (c->field_215 == 2) goto big;
    if (c->field_215 == 3) goto big;
    if (c->field_215 != 1) goto use;
big:
    w = 1000.0f;
    goto done;
use:
    w = o->field_60;
done:
    k = 1.0f;
    if (only == 0) {
        float l = func_00353FA0_inl3(func_00353FA0_inl4(*(CGtV3d *)&v->field_0, acc->field_0));
        if (l < 10.0f) k = 2.0f;
        else if (l < 20.0f) k = 1.5f;
        else if (l < 40.0f) ;
        else if (l < 100.0f) k = 0.25f;
        else k = 0.0f;
    }
    if (mode == 2) {
        acc->field_14 = acc->field_14 + 1.2f * (w * k);
    } else {
        CGtV4d t;
        t = v->field_0;
        asm("qmtc2.ni %1, $vf2\n\tvmulx.w %0, %0, $vf2x" : "+j"(t.mData) : "r"(2.0f));
        float d = s->field_20 / (float)t.W();  // [C] retail FPU form, not a VU lane op: 0x354074 div.s (the cast keeps the port's PS2 float model)
        func_00353FA0_inl5(acc->field_14, k * (w * d));
    }
    return 1;
}
