// NONMATCHING: DeformDoor__16CB3VehicleDeformF17EVehicleFlyingBitff -- retail 800 / ours 801 instructions, 886 in changed runs
// draftAD C-first: door angle about the hinge (NormaliseFast x2, clamped cos, acos, cross-product sign), +-20 deg step, two RotateBoneByAxisAngle (header CreateRotationMatrix3x4 inlined) + 770*C00 products, flag + sound; all arithmetic/VU op counts equal; residue = lq/sq vs lqc2/sqc2 matrix copies and frame 0x600 vs 0xA90 (copy slots, as DeformBonnet)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded; calls identical (acosf = header name of func_0011E328); per-mnemonic counts equal for every FPU/VU arithmetic op (only lq/lqc2/sq/sqc2/lui/addiu/mfc1 differ)

// CB3VehicleDeform::DeformDoor(EVehicleFlyingBit, float, float) -- hand-written C-first draft (draftAD, 2026-10-31); the lifter refused it.
// [C] name: retail symbol table; no Revenge counterpart. Types and the inlined RotateBoneByAxisAngle / RotateBoneAboutACentrePoint /
// GetFlyingObjectIndex from the DeformBonnet archive (draftY; [C] map names). [L] reading: flying bit 0 / 1 = the two doors; p1 = impact
// amount (adds 0.25*p1 to the bit's damage and sets the target opening, +-20 deg * 2*p1), p2 = sound strength. The door's current
// angle about the hinge (D_004CAD80 reference, D_004CAD90 axis) is moved toward the target by at most 20 degrees: both segments
// rotated from the default pose (the second the other way), positions kept, final matrices rebuilt, the bit flagged, the sound played.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
using namespace GtMath;


enum EVehicleFlyingBit { };                       // [C] name: GetFlyingObjectIndex's mangled parameter type
struct UnkStruct_003E39B0_pair { CGtMatrix3x4 field_0; CGtMatrix3x4 field_40; };   // [G] lower / upper bonnet segment

class CB3VehicleData {                            // [C] name: GetFlyingObjectIndex's mangled parameter type
public:
    unsigned char pad_0[0xC];
    signed char field_C;                          // flying-bit count
    unsigned char pad_D[0x270 - 0xD];
    UnkStruct_003E39B0_pair field_270[8];         // [G] default segment matrices per flying bit
    unsigned char pad_670[0x100];
    UnkStruct_003E39B0_pair field_770[6];         // [G] bind (offset) matrices per flying bit
    unsigned char pad_A70[0x54];
    int field_AC4[1];                             // flying-bit type per slot
};
struct UnkStruct_003E39B0_14 {
    unsigned char pad_0[0x900];
    UnkStruct_003E39B0_pair field_900[6];         // [G] final segment matrices
    UnkStruct_003E39B0_pair field_C00[6];         // [G] deformed segment matrices
    unsigned char pad_F00[0x30];
    float field_F30[6][2];                        // [L] segment lengths (GetIKAngles' first two arguments)
    unsigned char pad_F60[0x30];
    float field_F90[32];                          // [G] per-bit damage
    unsigned char pad_1010[0xC];
    unsigned char field_101C[1];                  // [G] per-bit "changed" flag
};
struct UnkStruct_003E39B0_10 { unsigned char pad_0[0x30]; CGtV3d field_30; };

class CB3SoundCrashManager {
public:
    void DeformDoor(CGtV3d, float);               // [C] mangled name
    unsigned char pad_0[0x8E0];
};
extern CB3SoundCrashManager D_01E78510;
// [G] stand-in: retail passes the CGtV3d argument's address with no copy (b119p copies a by-value class argument)
extern "C" void DeformDoor__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(CB3SoundCrashManager *, const CGtV3d &, float);
extern CGtV3d D_004CAD80;   // [G] the door hinge reference direction
extern CGtV3d D_004CAD90;   // [G] the door hinge axis
extern float D_004E0D3C;    // 0.017453292 (degrees -> radians)

class CB3VehicleDeform {
public:
    void DeformDoor(EVehicleFlyingBit, float, float);
    // [C] name/signature (E dnat 0x3979E0, proven 0x3E7600); inlined here
    static int GetFlyingObjectIndex(CB3VehicleData *d, EVehicleFlyingBit b)
    {
        int i;
        for (i = 0; i < d->field_C; i++) {
            if (b == d->field_AC4[i]) return i;
        }
        return -1;
    }
    // [C] names/signatures: B3O0PCH map 0x442130 (0xB0) / 0x4421E0 (0x14C); [L] bodies from the inlined copies; return type [G]
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
        CGtMatrix3x4 lRot = CreateRotationMatrix3x4(axis, angle);   // [C] built before the centre (retail order)
        CGtV3d lCentre = bone.mPos + bone.mAt * offset;
        CGtMatrix3x4 r = RotateBoneAboutACentrePoint(bone, lRot, lCentre);
        r.mPos -= r.mAt * offset;
        return r;
    }

    unsigned char pad_0[0x10];
    UnkStruct_003E39B0_10 *field_10;
    UnkStruct_003E39B0_14 *field_14;
    CB3VehicleData *field_18;
};

// 0x003E5040
void CB3VehicleDeform::DeformDoor(EVehicleFlyingBit p0, float p1, float p2)
{
    float lLimit;
    if (p0 == 0) lLimit = -20.0f;
    else if (p0 == 1) lLimit = 20.0f;
    else return;
    float lTarget = lLimit * (2.0f * p1);
    int k = GetFlyingObjectIndex(field_18, p0);
    if (k == -1) return;
    field_14->field_F90[k] = 0.0f + field_14->field_F90[k] + 0.25f * p1;   // [L] retail adda.s zero / madd.s
    // the door's current opening angle about the hinge, signed by the hinge axis, in (-180, 180]
    CGtV3d lRef = D_004CAD80;
    CGtV3d lAt = field_14->field_C00[k].field_0.mAt;
    lRef.NormaliseFast();
    lAt.NormaliseFast();
    float lAngle = ACosDeg(CosAngleBetweenNormalisedVectors(lRef, lAt));
    if (DotProduct(CrossProduct(lRef, lAt), D_004CAD90) < 0.0f) lAngle = 360.0f - lAngle;
    if (lAngle > 180.0f) lAngle -= 360.0f;
    float lDelta = Min(Max(lTarget - lAngle, -20.0f), 20.0f);
    // both door segments rotated about the hinge axis from their default pose, keeping their positions
    CGtV3d lOldPos0 = field_14->field_C00[k].field_0.mPos;
    field_14->field_C00[k].field_0 = RotateBoneByAxisAngle(field_18->field_270[k].field_0, D_004CAD90, D_004E0D3C * -lDelta, 0.0f);
    field_14->field_C00[k].field_0.mPos = lOldPos0;
    CGtV3d lOldPos1 = field_14->field_C00[k].field_40.mPos;
    field_14->field_C00[k].field_40 = RotateBoneByAxisAngle(field_18->field_270[k].field_40, D_004CAD90, D_004E0D3C * lDelta, 0.0f);
    field_14->field_C00[k].field_40.mPos = lOldPos1;
    field_14->field_900[k].field_0 = field_18->field_770[k].field_0 * field_14->field_C00[k].field_0;
    field_14->field_900[k].field_40 = field_18->field_770[k].field_40 * field_14->field_C00[k].field_40;
    int j = GetFlyingObjectIndex(field_18, p0);
    if (j >= 0) field_14->field_101C[j] = 1;
    if (p2 > 0.0f) DeformDoor__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, field_10->field_30, p2);
}
