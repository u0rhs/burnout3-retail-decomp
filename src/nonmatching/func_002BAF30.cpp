// NONMATCHING: func_002BAF30 -- retail 315 / ours 315 instructions, 26 in changed runs
// ghvu17: clone of the func_002BB420 archive (track region 1): logic exact, frame exact (N140 pads: 6 inside a SinCosFast2 wrapper inline, 1 at top). Left 26: SinCosFast2/CosFast4 constant hoisting in GtMathPs2Trig.h (retail materialises 0xBE22F983/0x3F000000/0x4B400000 before vabs; ours just before each ctc2; unwrapping the vabs/vmaxw regions gains 1), x/one GPR park registers t0/a3 vs a3/a2, polynomial qmfc2 placement, mul.s operand order in the 1450..1600 arm, lane stand-ins vmuly.w/vmulx.w on vf3/vf1 swapped (same as sibling). Pragma sweep: nothing.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_002BAF30 -- hand-written (ghvu17), cloned from the archived sibling func_002BB420 (track region 1 vs 0).
// [L] the inlined GtMathPs2::SinCosFast2(float,float) (B3O0PCH map; include/b3/GtMathPs2Trig.h).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

struct UnkStruct_002BAF30_out {
    CGtV3d field_0;
    unsigned char pad_10[0x1C];
    float field_2C;
};
extern float D_004C1C70[];
extern float D_004C1C74[];
extern float D_004C1C78[];

struct UnkStruct_002BAF30_pad { int x[4]; UnkStruct_002BAF30_pad() {} ~UnkStruct_002BAF30_pad() {} };
// [L] GtMath::Interpolate(float,float,float) (map 0x14CCF0)
static inline float func_002BAF30_inl1(float a, float b, float t) { return a + t * (b - a); }

// [L] N185 stand-ins: operator*(WAxisType,YAxisType), operator*(WAxisType,XAxisType), CGtV3d::SetX(WAxisType),
// CGtV3d::SetY(ZAxisType), CGtV3d::SetZ(WAxisType) on compiler-chosen registers
static inline u_long128 func_002BAF30_inl4(u_long128 a) { u_long128 r; asm("vmuly.w %0, %1, %1y" : "=j"(r) : "j"(a)); return r; }
static inline u_long128 func_002BAF30_inl5(u_long128 a) { u_long128 r; asm("vmulx.w %0, %1, %1x" : "=j"(r) : "j"(a)); return r; }
static inline void func_002BAF30_inl6(CGtV3d &v, u_long128 a) { asm("vaddw.x %0, $vf0, %1w" : "+j"(v.mData) : "j"(a)); }
static inline void func_002BAF30_inl7(CGtV3d &v, u_long128 a) { asm("vaddz.y %0, $vf0, %1z" : "+j"(v.mData) : "j"(a)); }
static inline void func_002BAF30_inl8(CGtV3d &v, u_long128 a) { asm("vaddw.z %0, $vf0, %1w" : "+j"(v.mData) : "j"(a)); }

static inline CGtV4d func_002BAF30_inl9(float a, float b)
{
    UnkStruct_002BAF30_pad pad1, pad2, pad3, pad4, pad5, pad6;  // N140: six dead 16-byte slots below the parameter copy
    return SinCosFast2(a, b);
}
// 0x002BAF30
extern "C" void func_002BAF30(CGtV3d p, UnkStruct_002BAF30_out * out)
{
    UnkStruct_002BAF30_pad pad0;  // N140
    float x = p.X();
    float z = p.Z();
    float t;
    int from;
    int to;
    if (x < -3000) {
        from = 3;
        to = 2;
        if (x < -3750) {
            t = 0.006410256494f * (z - 574);
        } else {
            t = 0.009259259328f * (z - 442.0f);
        }
    } else if (x < -1750) {
        from = 2;
        to = 1;
        if (!(z <= 600.0f)) {
            if (x < -1890) {
                t = 0.0f;
            } else {
                t = -0.007352941204f * (z - 1105);
            }
        } else {
            t = 0.002906976733f * (x - -2121);
        }
    } else {
        from = 1;
        to = 0;
        if (!(z <= 100.0f)) {
            if (x < 1450) {
                t = 0.0f;
            } else if (!(x <= 1600.0f)) {
                t = 1.0f;
            } else {
                t = ((x - 1500) * 33.0f + (z - 796.0f) * -35.0f) * 0.0004321521265f;
            }
        } else {
            t = 0.001000000047f * (x - 1100);
        }
    }
    float c, a, b;
    if (t <= 0.0f) {
        a = D_004C1C70[from * 3];
        b = D_004C1C74[from * 3];
        c = D_004C1C78[from * 3];
    } else if (t < 1.0f) {
        a = func_002BAF30_inl1(D_004C1C70[from * 3], D_004C1C70[to * 3], t);
        b = func_002BAF30_inl1(D_004C1C74[from * 3], D_004C1C74[to * 3], t);
        c = func_002BAF30_inl1(D_004C1C78[from * 3], D_004C1C78[to * 3], t);
    } else {
        a = D_004C1C70[to * 3];
        b = D_004C1C74[to * 3];
        c = D_004C1C78[to * 3];
    }
    float kb = 0.01745329238f * b;
    float ka = 0.01745329238f * a;
    CGtV4d sc = func_002BAF30_inl9(ka, kb);
    func_002BAF30_inl6(out->field_0, func_002BAF30_inl4(sc.mData));
    func_002BAF30_inl7(out->field_0, sc.mData);
    func_002BAF30_inl8(out->field_0, func_002BAF30_inl5(sc.mData));
    out->field_2C = c;
}

