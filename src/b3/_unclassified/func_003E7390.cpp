// Hand-written; the lifter refused it (v272: header SetIdentity/GetSquaredLength + [L] N185 stand-ins (X-X, X+X, float-X, SetX(float) compiler-chosen, GetLength tail in .set noreorder); both case matrices at function scope fix the frame).

// [G] DNAT/E order: follows CB3VehicleDeform::GetVirtualBones in B3VehicleDeform.cpp; E has GetVirtualBoneMatrix(EVirtualBoneIndex) next (name not applied)
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003E7390_bones {
    unsigned char pad_0[0x700];
    CGtMatrix3x4 field_700[7];   // [G] count
};
struct UnkStruct_003E7390_2 {
    unsigned char pad_0[0x160];
    CGtV3d field_160;
};
struct UnkStruct_003E7390_self {
    unsigned char pad_0[0x14];
    UnkStruct_003E7390_bones * field_14;
    UnkStruct_003E7390_2 * field_18;
    unsigned char pad_1C[0x50 - 0x1C];
    CGtV3d field_50;
    CGtV3d field_60;
};
extern int kaeVirtualToNormalBone[7];

// [L] N185: GtMathPs2::operator-(XAxisType, XAxisType) (B3O0PCH map, 0x50) stand-in
static inline XAxisType v272_subxx(XAxisType a, XAxisType b) { u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
// [L] N185: GtMathPs2::operator+(XAxisType, XAxisType) (B3O0PCH map, 0x50) stand-in
static inline XAxisType v272_addxx(XAxisType a, XAxisType b) { u_long128 r; asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
// [L] N185: GtMathPs2::operator-(float, XAxisType) (B3O0PCH map, 0x50) stand-in
static inline XAxisType v272_subfx(float f, XAxisType b) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(s), "j"(b.lVector)); return XAxisType(r); }
// [L] N185: CGtV3d::SetX(float) on compiler-chosen registers stand-in
static inline void v272_setx(CGtV3d &v, float x) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(x)); asm("vaddx.x %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
// [L] N185: CGtV3d::GetLength() with its sqrt tail inside a `.set noreorder` region (as proven func_00353FA0)
static inline XAxisType v272_len(const CGtV3d &v)
{ return v.GetLength(); }

// 0x003E7390
extern "C" CGtMatrix3x4 func_003E7390(UnkStruct_003E7390_self * self, int idx)
{
    // [G] both matrices at function scope: retail's frame has them adjacent at the top (sp+0xC0, sp+0x80)
    CGtMatrix3x4 m2;
    CGtMatrix3x4 m3;
    switch (idx) {
    case 2: {
        m2.SetIdentity();
        CGtV3d pos = self->field_50;
        float d = v272_subxx(self->field_18->field_160.X(), pos.X());
        float x = v272_addxx(pos.X(), self->field_14->field_700[3].mPos.X());
        float k = v272_subfx(1.0f, v272_len(self->field_14->field_700[3].mRight)) * d;
        v272_setx(pos, x + k);
        m2.mPos = pos;
        return m2;
    }
    case 3: {
        m3.SetIdentity();
        CGtV3d pos = self->field_60;
        float d = v272_subxx(self->field_18->field_160.X(), pos.X());
        float x = v272_addxx(pos.X(), self->field_14->field_700[3].mPos.X());
        float k = v272_subfx(1.0f, v272_len(self->field_14->field_700[3].mRight)) * d;
        v272_setx(pos, x + k);
        m3.mPos = pos;
        return m3;
    }
    default:
        return self->field_14->field_700[kaeVirtualToNormalBone[idx]];
    }
}
