// NONMATCHING: SetRealisticMomentsOfInertia__16CB3CollidingBodyFv -- retail 236 / ours 263 instructions, 324 in changed runs
// draftAN fork C C-first: box half-extents max(field_1D0, -field_1E0) per axis, solid-box inertia 0.5*mass*(sum of the other squared extents), inverted lane by lane into the diagonal local inverse tensor field_10 (rows lane by lane, w kept), world tensor field_40 = transpose(R) * field_10 * R (Update__16CB3CollidingBodyFf's stand-ins; transpose from row copies, each product row keeps its left row's w); 263/236, no calls, non-stack store multiset same apart from our extra field_10.mUp re-store and byte-loop row copies straight into field_40 (same final values)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: max.s operands, the three sums and their pairing with each axis, 0.5 * (mass * sum), the 1/x div.s per lane, every tensor lane and both row-product chains (vmulax/vmadday/vmaddz.xyz, w sources) traced

// SetRealisticMomentsOfInertia__16CB3CollidingBodyFv -- draftAN fork C (C-first draft). 0x1AC0A0, 0x3B0.
// [C] name: the mangled symbol in retail's tables. Revenge SetRealisticMomentsOfInertia__16CB4CollidingBody (0x148,
// B4CollidingBody.cpp; stabs locals lInertia, lrXPlaneSquared / lrYPlaneSquared / lrZPlaneSquared) [L]. What it does [L]: the
// half-extents of the body's box (max of field_1D0 and -field_1E0 per axis), a solid-box inertia 0.5 * mass * (sum of the other two
// squared extents) per axis, inverted lane by lane into the diagonal local inverse-inertia tensor field_10 (CB3Tensor, rows set
// lane by lane, w kept), then the world tensor field_40 = transpose(R) * field_10 * R with R the rotation rows of *field_204 --
// the same tail as Update__16CB3CollidingBodyFf's archive (its CGtMatrix3x3 / CB3Tensor stand-ins, reused here) [L].
// w lanes [C]: retail's transpose starts from a copy of each rotation row (only the off-diagonal lanes written), and each row
// product's madd destination is the left row (first product: the transposed row; second: field_40's row), so every result row
// keeps that row's w. lInertia starts uninitialised (retail lqc2 of its unset stack home; its w is never read).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

// [L] GtMathPs2::CGtMatrix3x3 with the map's copy ctor (as Update__16CB3CollidingBodyFf's archive) [G body]
struct UnkStruct_001AC0A0_m33 {
    CGtV3d mRight, mUp, mAt;
    UnkStruct_001AC0A0_m33() {}
    UnkStruct_001AC0A0_m33(const UnkStruct_001AC0A0_m33& m) { UnkStruct_001AC0A0_m33& r = (*this = m); }
};
// [G] the row product inside CGtMatrix3x3::operator* (B3O0PCH 0x1A50B0), result w = w's w (Update's inl12)
static inline CGtV3d func_001AC0A0_inl1(const UnkStruct_001AC0A0_m33& m, CGtV3d v, u_long128 w) {
    u_long128 t = w;
    asm("vmulax.xyz $ACC, %0, %1x" : : "j"(m.mRight.mData), "j"(v.mData));
    asm("vmadday.xyz $ACC, %0, %1y" : : "j"(m.mUp.mData), "j"(v.mData));
    asm("vmaddz.xyz %0, %1, %2z" : "+j"(t) : "j"(m.mAt.mData), "j"(v.mData));
    return CGtV3d(t);
}
// [G] stand-in for CGtMatrix3x3::operator*(const CGtMatrix3x3&): each row of a through b, keeping a's row w
static inline UnkStruct_001AC0A0_m33 func_001AC0A0_inl2(const UnkStruct_001AC0A0_m33& a, const UnkStruct_001AC0A0_m33& b) {
    UnkStruct_001AC0A0_m33 r;
    r.mRight = func_001AC0A0_inl1(b, a.mRight, a.mRight.mData);
    r.mUp = func_001AC0A0_inl1(b, a.mUp, a.mUp.mData);
    r.mAt = func_001AC0A0_inl1(b, a.mAt, a.mAt.mData);
    return r;
}
// [G] stand-in for CB3Tensor::GetTranspose() (B3O0PCH 0x1A5230): a copy with the off-diagonal lanes swapped (retail
// 0x1AC290..0x1AC2A4: vaddx.y/z, vaddy.x/z, vaddz.x/y on copies of the rows)
static inline UnkStruct_001AC0A0_m33 func_001AC0A0_inl3(const UnkStruct_001AC0A0_m33& m) {
    UnkStruct_001AC0A0_m33 t = m;
    asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(t.mRight.mData) : "j"(m.mUp.mData), "j"(m.mAt.mData));
    asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(t.mUp.mData) : "j"(m.mRight.mData), "j"(m.mAt.mData));
    asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(t.mAt.mData) : "j"(m.mRight.mData), "j"(m.mUp.mData));
    return t;
}

class CB3CollidingBody {
public:
    void SetRealisticMomentsOfInertia();
    unsigned char pad_0[0x10];
    UnkStruct_001AC0A0_m33 field_10;     // [L] CB3Tensor (local inverse inertia)
    UnkStruct_001AC0A0_m33 field_40;     // [L] CB3Tensor (world inverse inertia)
    unsigned char pad_70[0x1D0 - 0x70];
    CGtV3d field_1D0;                    // [G] box max
    CGtV3d field_1E0;                    // [G] box min
    float field_1F0;                     // [L] mass
    unsigned char pad_1F4[0x204 - 0x1F4];
    CGtMatrix3x4 *field_204;             // the body's matrix
};

// 0x001AC0A0
void CB3CollidingBody::SetRealisticMomentsOfInertia()
{
    CGtV3d lInertia;                     // [C] unset before the lane writes (retail reads its stack home)
    float x = GtMath::Max(field_1D0.X(), -field_1E0.X());
    float y = GtMath::Max(field_1D0.Y(), -field_1E0.Y());
    float z = GtMath::Max(field_1D0.Z(), -field_1E0.Z());
    float lrXPlaneSquared = x * x;
    float lrYPlaneSquared = y * y;
    float lrZPlaneSquared = z * z;
    lInertia.SetX(0.5f * (field_1F0 * (lrYPlaneSquared + lrZPlaneSquared)));
    lInertia.SetY(0.5f * (field_1F0 * (lrXPlaneSquared + lrZPlaneSquared)));
    lInertia.SetZ(0.5f * (field_1F0 * (lrXPlaneSquared + lrYPlaneSquared)));
    lInertia.SetX(1.0f / (float)lInertia.X());  // [C] retail FPU form, not a VU lane op: 0x1AC18C / 0x1AC1B8 / 0x1AC1D8 div.s (the cast keeps the port's PS2 float model)
    lInertia.SetY(1.0f / (float)lInertia.Y());  // [C] retail FPU form, not a VU lane op: 0x1AC18C / 0x1AC1B8 / 0x1AC1D8 div.s (the cast keeps the port's PS2 float model)
    lInertia.SetZ(1.0f / (float)lInertia.Z());  // [C] retail FPU form, not a VU lane op: 0x1AC18C / 0x1AC1B8 / 0x1AC1D8 div.s (the cast keeps the port's PS2 float model)
    field_10.mRight.SetX(lInertia.X());
    field_10.mRight.SetY(0.0f);
    field_10.mRight.SetZ(0.0f);
    field_10.mUp.SetX(0.0f);
    field_10.mUp.SetY((float)lInertia.Y());
    field_10.mUp.SetZ(0.0f);
    field_10.mAt.SetX(0.0f);
    field_10.mAt.SetY(0.0f);
    field_10.mAt.SetZ((float)lInertia.Z());
    UnkStruct_001AC0A0_m33 lRot;
    lRot.mRight = field_204->mRight;
    lRot.mUp = field_204->mUp;
    lRot.mAt = field_204->mAt;
    field_40 = func_001AC0A0_inl2(func_001AC0A0_inl3(lRot), field_10);
    field_40 = func_001AC0A0_inl2(field_40, lRot);
}
