// NONMATCHING: func_001C8120 -- retail 90 / ours 84 instructions, 51 in changed runs
// ghvu3: logic right (lane lerp + TransformPoint/Vector + Impact with 12 args as passed); left: retail keeps lo/hi GPR copies stored to sp+0x90/0xA0 (dead by-value copies, frame 0xD0 vs 0x60), switch tests 4,5,1,2,3 but bodies default,4/5,1/2/3 (no case order gives both)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (ghvu3, Ghidra draft); the lifter refused it. A point lerped between two local corners by t (lane-wise),
// moved to world space with the body matrix, a direction rotated with it, then CB3VehicleDeform::Impact with the
// vehicle id of the right kind (by field_215) and this function's own float passed through (f12 untouched).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_001C8120_1 { unsigned char pad_0[0x1960]; unsigned long field_1960; };
struct UnkStruct_001C8120 {
    unsigned char pad_0[0x1D0];
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    unsigned char pad_1F0[0x14];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0xD];
    signed char field_215;
    unsigned char pad_216[0xAAA];
    void *field_CC0;
    unsigned char *field_CC4;
    unsigned char pad_CC8[0x72C];
    UnkStruct_001C8120_1 *field_13F4;
    unsigned char pad_13F8[0x1032];
    unsigned char field_242A;
};
extern unsigned long D_0055B7D0[];
// CB3VehicleDeform::Impact: retail's callers pass more than the mangled name lists (t3 and a third stack word, both 1 at
// every call of this family; checked in the callers' asm), so it is declared with C linkage and the arguments as passed [G]
extern "C" void Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
    void *, void *, void *, void *, unsigned long, int, int, int, const CGtV3d &, const CGtV3d &, int, float);
// [L] N185: stands in for CGtV3d::operator*(CGtV3d) (B3O0PCH map, 68 bytes): lane-wise vmul.xyz, compiler-chosen
static inline CGtV3d func_001C8120_inl1(const CGtV3d &a, CGtV3d b) { u_long128 r; asm("vmul.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: stands in for a compiler-chosen CGtV3d add (retail `vadd.xyz $vf1, $vf2, $vf1` with the sum on the product's register)
static inline CGtV3d func_001C8120_inl2(const CGtV3d &a, const CGtV3d &o) {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vadd.xyz $vf1, $vf2, $vf1" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "r"(o.mData), "r"(a.mData));
    return CGtV3d(t);
}
// [G] the id lookup as a static inline returning the value (retail's join: `b join; ld t0` from each arm, t0 = 0 inline)
static inline unsigned long func_001C8120_inl3(UnkStruct_001C8120 *self)
{
    switch (self->field_215) {
    case 3:
    case 2:
    case 1:
        return self->field_13F4->field_1960;
    case 5:
    case 4:
        return D_0055B7D0[self->field_242A];
    }
    return 0;
}
// 0x001C8120
extern "C" void func_001C8120(UnkStruct_001C8120 *self, const CGtV3d &t, const CGtV3d &dir, float f)
{
    CGtV3d lo = self->field_1E0;
    CGtV3d d = self->field_1D0;
    d -= lo;
    CGtV3d p = func_001C8120_inl2(lo, func_001C8120_inl1(t, d));
    CGtV3d pos = TransformPoint(*self->field_204, p);
    CGtV3d v = TransformVector(*self->field_204, dir);
    unsigned long id = func_001C8120_inl3(self);
    if (id != 0) {
        Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
            self->field_CC4 + 0x300, self, self->field_CC0, self->field_CC4, id, 12, 2, 1, pos, v, 1, f);
    }
}
