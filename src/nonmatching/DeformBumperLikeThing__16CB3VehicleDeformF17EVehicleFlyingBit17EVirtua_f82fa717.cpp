// NONMATCHING: DeformBumperLikeThing__16CB3VehicleDeformF17EVehicleFlyingBit17EVirtualBoneIndex17EVirtualBoneIndex17EVirtualBoneIndexf -- retail 570 / ours 579 instructions, 586 in changed runs
// draftAG: logic complete; retail 570 / ours 579; calls identical; every VU arithmetic op count identical (header CreateRotationMatrix3x4 + SinCosFast via the DeformBonnet draft's RotateBoneByAxisAngle inline; one extra vmove); left: lq/sq vs lqc2/sqc2 split of the copies, frame 0x6A0 vs 0x470; the default-position switch is a [G] placeholder inline
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; layout + inlined RotateBoneByAxisAngle / RotateBoneAboutACentrePoint / GetFlyingObjectIndex [C names] from the archived DeformBonnet draft; every branch, call, store and VU op accounted for; call sequence identical (calls.sh)

// CB3VehicleDeform::DeformBumperLikeThing(EVehicleFlyingBit, EVirtualBoneIndex, EVirtualBoneIndex, EVirtualBoneIndex, float) --
// draftAG (C-first draft; no Revenge counterpart). [C] name: research/retail_names.csv 0x3E30C0 (high; E_B3O0PCH 0x443800).
// [L] reading: a two-segment flying bit (bumper / boot / spoiler: DeformFrontBumper etc. pass their bone) bends about +Y.
// The bit's damage grows by a quarter of the impact; each segment's yaw angle moves by 100 * D_0052267C (towards -100 when the
// struck bone is the first of the pair), clamped to +-20 degrees, and the segment is rebuilt from its default matrix rotated
// about its own position; the second segment's position then follows the deformed length ratio of the two virtual bones;
// the final matrices are rebuilt and the bit is flagged as changed.
// Layout and the inlined RotateBoneByAxisAngle / RotateBoneAboutACentrePoint / GetFlyingObjectIndex [C names, B3O0PCH map]
// from the archived DeformBonnet__16CB3VehicleDeformFffb draft.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
using namespace GtMath;

enum EVehicleFlyingBit { };                       // [C] name: GetFlyingObjectIndex's mangled parameter type
enum EVirtualBoneIndex { };                       // [C] name: the mangled parameter type

class CB3VehicleData {                            // [C] name: GetFlyingObjectIndex's mangled parameter type
public:
    unsigned char pad_0[0xC];
    signed char field_C;                          // flying-bit count
    unsigned char pad_D[0x63];
    CGtMatrix3x4 field_70[8];                     // [C] default bone matrices (+0xA0 = [0].mPos)
    CGtMatrix3x4 field_270[8][2];                 // [G] default segment matrices per flying bit
    unsigned char pad_670[0x100];
    CGtMatrix3x4 field_770[6][2];                 // [G] bind (offset) matrices per flying bit
    unsigned char pad_A70[0x54];
    int field_AC4[1];                             // flying-bit type per slot
};
struct UnkStruct_003E30C0_14 {
    unsigned char pad_0[0x4B2];
    signed char field_4B2[6];                     // [C] per-bit state: 3 = no more deformation [G]
    unsigned char pad_4B8[0x448];
    CGtMatrix3x4 field_900[6][2];                 // [G] final segment matrices
    CGtMatrix3x4 field_C00[6][2];                 // [G] deformed segment matrices
    float field_F00[6][2];                        // [C] per-segment yaw angle, degrees
    unsigned char pad_F30[0x60];
    float field_F90[32];                          // [G] per-bit damage
    unsigned char pad_1010[0xC];
    unsigned char field_101C[1];                  // [G] per-bit "changed" flag
};

extern int kaeVirtualToNormalBone[7];
extern float D_0052267C;                          // [C] lw from .data: the deformation rate scale [G]
extern "C" CGtMatrix3x4 func_003E7390(void *self, int bone);   // [L] GetVirtualBoneMatrix (E map name, not applied)

class CB3VehicleDeform {
public:
    void DeformBumperLikeThing(EVehicleFlyingBit, EVirtualBoneIndex, EVirtualBoneIndex, EVirtualBoneIndex, float);
    // [C] name/signature (E dnat 0x3979E0, proven 0x3E7600); inlined here
    static int GetFlyingObjectIndex(CB3VehicleData *d, EVehicleFlyingBit b)
    {
        int i;
        for (i = 0; i < d->field_C; i++) {
            if (b == d->field_AC4[i]) return i;
        }
        return -1;
    }
    // [C] names/signatures: B3O0PCH map 0x442130 / 0x4421E0; [L] bodies as the DeformBonnet draft
    CGtMatrix3x4 RotateBoneAboutACentrePoint(const CGtMatrix3x4 &bone, const CGtMatrix3x4 &rot, CGtV3d centre)
    {
        CGtMatrix3x4 lBone = bone;
        lBone.mPos.Zero();
        CGtMatrix3x4 r = lBone * rot;
        r.mPos = centre;
        return r;
    }
    CGtMatrix3x4 RotateBoneByAxisAngle(const CGtMatrix3x4 &bone, CGtV3d axis, float angle, float offset)
    {
        CGtMatrix3x4 lRot = CreateRotationMatrix3x4(axis, angle);
        CGtV3d lCentre = bone.mPos + bone.mAt * offset;
        CGtMatrix3x4 r = RotateBoneAboutACentrePoint(bone, lRot, lCentre);
        r.mPos -= r.mAt * offset;
        return r;
    }
    // [G] inlined: a virtual bone's default position (bones 2 and 3 are the stored field_50 / field_60, as func_003E7390's
    // cases; the rest the default bone matrix of kaeVirtualToNormalBone[bone]); name unknown, placeholder
    static CGtV3d func_003E30C0_inl1(CB3VehicleDeform *self, int bone)
    {
        CGtV3d p;
        switch (bone) {
        case 2:
            p = self->field_50;
            break;
        case 3:
            p = self->field_60;
            break;
        default:
            p = self->field_18->field_70[kaeVirtualToNormalBone[bone]].mPos;
            break;
        }
        return p;
    }

    unsigned char pad_0[0x14];
    UnkStruct_003E30C0_14 *field_14;
    CB3VehicleData *field_18;
    unsigned char pad_1C[0x34];
    CGtV3d field_50;                              // [C] virtual bone 2's position (func_003E7390 archive)
    CGtV3d field_60;                              // [C] virtual bone 3's position
};

// 0x003E30C0
void CB3VehicleDeform::DeformBumperLikeThing(EVehicleFlyingBit lBit, EVirtualBoneIndex lnStruck, EVirtualBoneIndex lnBoneA,
    EVirtualBoneIndex lnBoneB, float lrAmount)
{
    CGtV3d lAxis(0.0f, 1.0f, 0.0f);
    int k = GetFlyingObjectIndex(field_18, lBit);
    if (k < 0)
        return;
    if (field_14->field_4B2[k] == 3)
        return;
    field_14->field_F90[k] = 0.0f + field_14->field_F90[k] + 0.25f * lrAmount;
    CGtV3d lPosA = func_003E7390(this, lnBoneA).mPos;
    CGtV3d lDelta = func_003E7390(this, lnBoneB).mPos - lPosA;
    ((float *)&lDelta)[3] = ((const float *)&lPosA)[3]; // [C] 0x3E31D0 lqc2 vf1, 0x690(sp) (lPosA); 0x3E31D8 vsub.xyz vf1, vf2, vf1
    // keeps lPosA's w; 0x3E31E4 sqc2 vf1, 0x680(sp) -- `a - b` took the bone position's w
    CGtV3d lDefA = func_003E30C0_inl1(this, lnBoneA);
    CGtV3d lDefB = func_003E30C0_inl1(this, lnBoneB);
    float lrCur = lDelta.GetLength();
    float lrRatio = Min(Max(lrCur / (float)(lDefB - lDefA).GetLength(), 0.0f), 1.0f);
    for (int j = 0; j < 2; j++) {
        float lrAngle;
        if (lnStruck == lnBoneA)
            lrAngle = 0.0f + field_14->field_F00[k][j] + -100.0f * D_0052267C;
        else
            lrAngle = 0.0f + field_14->field_F00[k][j] + 100.0f * D_0052267C;
        lrAngle = Min(Max(lrAngle, -20.0f), 20.0f);
        field_14->field_C00[k][j] = RotateBoneByAxisAngle(field_18->field_270[k][j], lAxis, 0.01745329238f * lrAngle, 0.0f);
        field_14->field_F00[k][j] = lrAngle;
    }
    field_14->field_C00[k][1].mPos = field_14->field_C00[k][0].mPos + (field_14->field_C00[k][1].mPos - field_14->field_C00[k][0].mPos) * lrRatio;
    // [C] w = field_C00[k][0].mPos.w: 0x3E3840 lqc2 vf1, 0xC30(a1); 0x3E384C vadd.xyz vf1, vf1, vf2; 0x3E3850 sqc2 vf1, 0xC70(a1)
    // -- `a + b` took the difference's w ([1].mPos.w); a lane write, since `x = a; x += b` would overwrite [1].mPos before it is read
    ((float *)&field_14->field_C00[k][1].mPos)[3] = ((const float *)&field_14->field_C00[k][0].mPos)[3];
    for (int j = 0; j < 2; j++) {
        // [G] inlined final-matrix rebuild (as SetFinalMatrix): bind * deformed
        field_14->field_900[k][j] = field_18->field_770[k][j] * field_14->field_C00[k][j];
    }
    int k2 = GetFlyingObjectIndex(field_18, lBit);
    if (k2 >= 0)
        field_14->field_101C[k2] = 1;
}
