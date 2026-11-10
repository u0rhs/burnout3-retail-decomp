// NONMATCHING: SetVirtualBoneMatrix__16CB3VehicleDeformF17EVirtualBoneIndexPQ29GtMathPs212CGtMatrix3x4 -- retail 496 / ours 498 instructions, 411 in changed runs
// draftAO (2026-11-01): rewritten from the asm with header APIs (Normalise, CGtV3d*float, CGtMatrix3x4::operator* = rest * bone) and N185 X-lane stand-ins; behaviour fix: for index 3 the x distance is other - m (retail swaps the vsubx.x operands, 0x3E655C), the old draft used m - other for both; outputs in retail order 3,0,7,6 | Before: psweep: scoped #pragma inline_depth(3) [G] improves 1111 -> 692
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x3E6460..0x3E6C1C): calls identical, VU/FPU op counts equal, non-stack stores as retail; behaviour_audit quiet

// CB3VehicleDeform::SetVirtualBoneMatrix(EVirtualBoneIndex, CGtMatrix3x4 *) -- 0x3E6460. draftAO (2026-11-01): written from the
// asm with the header APIs (CGtV3d::Normalise, CGtV3d::operator*(float), CGtMatrix3x4::operator*), replacing the stand-ins.
// [C] jump table jtbl_004CAE10: indices 0, 1, 4, 5 copy the matrix into the normal bone (kaeVirtualToNormalBone); 2 and 3
// re-solve the axle; >= 6 nothing (sltiu 6).
// [C] axle case (0x3E64E0..0x3E6C04): the width f20 = field_50.x - field_60.x; the opposite virtual bone (2 -> 3, 3 -> 2) from
// func_003E7390 (GetVirtualBoneMatrix by E order, [G]); the signed x distance is m - other for 2 but other - m for 3 (retail
// swaps the vsubx.x operands per branch, 0x3E6524 / 0x3E655C); ratio = dx / width; the mid x (m.x + other.x) * 0.5 goes into
// the position rows of normal bones 3, 0, 7, 6 (+0x7F0, +0x730, +0x8F0, +0x8B0); their right rows are normalised and scaled
// by the ratio (w kept), then the four matrices +0x500[k] = rest[k] * bone[k] for k = 3, 0, 7, 6 (rest = field_18 +0x570 + k*0x40).
// Field names are placeholders, every type [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EVirtualBoneIndex { EVirtualBoneIndex_dummy };   // [C] type name: the mangled symbol; enumerators unknown

struct UnkStruct_003E6460_bones {
    unsigned char pad_0[0x500];
    CGtMatrix3x4 field_500[8];      // [G] skinning matrices (bone * rest), written here for bones 0, 3, 6, 7
    CGtMatrix3x4 field_700[8];      // [G] normal bone matrices (func_003E7390 reads [3] and [kaeVirtualToNormalBone[i]])
};
struct UnkStruct_003E6460_rest {
    unsigned char pad_0[0x570];
    CGtMatrix3x4 field_570[8];      // [G] per-bone rest matrices (read for bones 0, 3, 6, 7)
};
class CB3VehicleDeform {
public:
    void SetVirtualBoneMatrix(EVirtualBoneIndex idx, CGtMatrix3x4 *m);
    unsigned char pad_0[0x14];
    UnkStruct_003E6460_bones *field_14;
    UnkStruct_003E6460_rest *field_18;
    unsigned char pad_1C[0x34];
    CGtV3d field_50;                // [G] axle end positions (x read)
    CGtV3d field_60;
};
extern int kaeVirtualToNormalBone[];
// [L] N185 stand-ins (as the proven func_003E7390): GtMathPs2::operator-(XAxisType, XAxisType) / operator+(XAxisType, XAxisType)
// (B3O0PCH map names, not in the header yet) and XAxisType * float (vmulx.x by a qmtc2'd scalar, retail 0x3E6598)
static inline XAxisType func_003E6460_inl1(XAxisType a, XAxisType b) { u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
static inline XAxisType func_003E6460_inl2(XAxisType a, XAxisType b) { u_long128 r; asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
static inline XAxisType func_003E6460_inl3(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }
extern "C" CGtMatrix3x4 func_003E7390(CB3VehicleDeform *self, int idx);   // [G] GetVirtualBoneMatrix (proven unit's return type)

// 0x003E6460
void CB3VehicleDeform::SetVirtualBoneMatrix(EVirtualBoneIndex idx, CGtMatrix3x4 *m)
{
    switch ((unsigned int)idx) {
    case 0:
    case 1:
    case 4:
    case 5:
        field_14->field_700[kaeVirtualToNormalBone[idx]] = *m;
        break;
    case 2:
    case 3: {
        float width = func_003E6460_inl1(field_50.X(), field_60.X());
        CGtV3d other;
        float dx;
        if (idx == 2) {
            CGtMatrix3x4 b = func_003E7390(this, 3);
            other = b.mPos;
            dx = func_003E6460_inl1(m->mPos.X(), other.X());
        } else {
            CGtMatrix3x4 b = func_003E7390(this, 2);
            other = b.mPos;
            dx = func_003E6460_inl1(other.X(), m->mPos.X());
        }
        float ratio = dx / width;
        XAxisType mid = func_003E6460_inl3(func_003E6460_inl2(m->mPos.X(), other.X()), 0.5f);
        field_14->field_700[3].mPos.SetX(mid);
        field_14->field_700[0].mPos.SetX(mid);
        field_14->field_700[7].mPos.SetX(mid);
        field_14->field_700[6].mPos.SetX(mid);
        CGtV3d *r;
        r = &field_14->field_700[3].mRight; r->Normalise(); *r = *r * ratio;
        r = &field_14->field_700[0].mRight; r->Normalise(); *r = *r * ratio;
        r = &field_14->field_700[7].mRight; r->Normalise(); *r = *r * ratio;
        r = &field_14->field_700[6].mRight; r->Normalise(); *r = *r * ratio;
        field_14->field_500[3] = field_18->field_570[3] * field_14->field_700[3];
        field_14->field_500[0] = field_18->field_570[0] * field_14->field_700[0];
        field_14->field_500[7] = field_18->field_570[7] * field_14->field_700[7];
        field_14->field_500[6] = field_18->field_570[6] * field_14->field_700[6];
        break;
    }
    }
}
