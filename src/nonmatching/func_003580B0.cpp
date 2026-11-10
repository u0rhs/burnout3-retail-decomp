// NONMATCHING: func_003580B0 -- retail 124 / ours 129 instructions, 57 in changed runs
// ghvu6: 124/129, 57 off. Critically damped spring step (SmoothCD: x = 2/D_004E1E24 * dt, 1/(1+x+0.48x^2+0.235x^3)) on a CGtV4d built from field_A0.w / C0 / C4 / C8; target from field_180.w / C0+wrapped(1A0-C0) / 1A4 / 1A8 when field_1E1. Lane setters exact as hard-coded $vf1-scalar/$vf2-vector stand-ins (retail's nops come out). Left: frame 0x1D0 vs 0x210 (by-value operator stand-ins give dead slots; 4 more needed), float register numbering in the 180-degree wrap (adda.s zero,d form), VU numbering of the change/target vsub, lane-read address folding (retail lwc1 off sp)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003580B0 -- called from CB3BehaviourCluster::Update (unit_00357B90). A critically damped spring step on a
// 4-lane state built from field_A0.w / field_C0 / field_C4 / field_C8 [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using GtMathPs2::CGtV4d;
using GtMathPs2::XAxisType;

struct UnkStruct_003580B0 {
    unsigned char pad_0[0xA0];
    CGtV4d field_A0;
    unsigned char pad_B0[0x10];
    float field_C0;
    float field_C4;
    float field_C8;
    unsigned char pad_CC[0xB4];
    CGtV4d field_180;
    unsigned char pad_190[0x10];
    float field_1A0;
    float field_1A4;
    float field_1A8;
    unsigned char pad_1AC[0x24];
    CGtV4d field_1D0;
    unsigned char pad_1E0[1];
    unsigned char field_1E1;
};
extern float D_004E1E24;

// [L] N185: lane setters / binary ops on compiler-chosen registers (no CGtV4d header bodies of this shape)
static inline void func_003580B0_inl1(CGtV4d &v, const CGtV4d &a) { u_long128 t; asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vaddw.x $vf2, $vf0, $vf1w" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(a.mData), "r"(v.mData)); v.mData = t; }
static inline void func_003580B0_inl2(CGtV4d &v, const float &f) { u_long128 t; asm("qmtc2 %1, $vf2" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vaddx.y $vf2, $vf0, $vf1x" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(v.mData), "r"(f)); v.mData = t; }
static inline void func_003580B0_inl3(CGtV4d &v, const float &f) { u_long128 t; asm("qmtc2 %1, $vf2" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vaddx.z $vf2, $vf0, $vf1x" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(v.mData), "r"(f)); v.mData = t; }
static inline void func_003580B0_inl4(CGtV4d &v, const float &f) { u_long128 t; asm("qmtc2 %1, $vf2" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vmulx.w $vf2, $vf0, $vf1x" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(v.mData), "r"(f)); v.mData = t; }
static inline CGtV4d func_003580B0_inl6(const CGtV4d &a, CGtV4d b) { u_long128 r; asm("vsub.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV4d(r); }
static inline CGtV4d func_003580B0_inl7(CGtV4d a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(r) : "j"(a.mData), "j"(s)); return CGtV4d(r); }
static inline void func_003580B0_inl8(CGtV4d &v, const CGtV4d &a) { asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(a.mData)); }

extern "C" void func_003580B0(UnkStruct_003580B0 *self, float dt)
{
    CGtV4d cur;
    func_003580B0_inl1(cur, self->field_A0);
    func_003580B0_inl2(cur, self->field_C0);
    func_003580B0_inl3(cur, self->field_C4);
    func_003580B0_inl4(cur, self->field_C8);
    CGtV4d target;
    if (self->field_1E1 != 0) {
        float d = self->field_1A0;
        d -= self->field_C0;
        if (!(GtMath::Abs(d) < 180.0f)) {
            volatile union { float f; unsigned int u; } s;
            s.f = d;
            s.u = (s.u & 0x80000000) | 0x3F800000;
            float z = 0.0f;
            d = z + d + 360.0f * -s.f;
        }
        func_003580B0_inl1(target, self->field_180);
        func_003580B0_inl2(target, self->field_C0 + d);
        func_003580B0_inl3(target, self->field_1A4);
        func_003580B0_inl4(target, self->field_1A8);
    } else {
        target = cur;
    }
    float omega = 2.0f / D_004E1E24;
    float x = omega * dt;
    float e = 1.0f / (1.0f + x + 0.48f * x * x + 0.235f * x * x * x);
    CGtV4d change = func_003580B0_inl6(cur, target);
    CGtV4d temp = func_003580B0_inl7((self->field_1D0 + func_003580B0_inl7(change, omega)), dt);
    self->field_1D0 = func_003580B0_inl7(func_003580B0_inl6(self->field_1D0, func_003580B0_inl7(temp, omega)), e);
    CGtV4d out = (target + func_003580B0_inl7((change + temp), e));
    func_003580B0_inl8(self->field_A0, out);
    self->field_C0 = out.Y();
    self->field_C4 = out.Z();
    self->field_C8 = out.W();
}
