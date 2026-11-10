// NONMATCHING: DeformBonnet__16CB3VehicleDeformFffb -- retail 1084 / ours 1099 instructions, 1384 in changed runs
// draftY: calls identical, branch layout as retail; [C] map names of the inlined RotateBoneByAxisAngle / RotateBoneAboutACentrePoint / GetFlyingObjectIndex; left: a 0.25*p0 product CSE'd (retail fuses both into madd/msub), first k<0 return as bgez+b (retail bltz), axis kept in a GPR (retail VU reg) through the 3 inlined CreateRotationMatrix3x4, copy slots (frame 0x810 vs 0xF50), sound call through an extern C const& stand-in (b119p copies the by-value CGtV3d)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every call, branch, store and VU op accounted for; the three rotations decoded op for op against the header CreateRotationMatrix3x4 / operator* bodies

// CB3VehicleDeform::DeformBonnet(float, float, bool) -- draftY, written from the retail asm (no Revenge counterpart).
// [L] reading: the bonnet (flying bit 4) is a two-segment IK chain per bit (bone pair field_C00[k] = lower/upper segment).
// p0 = impact amount (adds 0.25*p0 to the bit's damage), p1 = sound strength, p2 passed on to GetNewBonnetLengths.
// When the deformed chain still has length, the IK angles of the old (default) and new lengths are solved, the two
// segments are rotated about -X by the angle changes and the upper one about D_004CAD80 by the new twist angle;
// then both final matrices are rebuilt, the bit is flagged, and the crash sound plays.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
using namespace GtMath;

extern "C" float sqrtf(float);

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
    void DeformBonnet(CGtV3d, float);             // [C] mangled name
    unsigned char pad_0[0x8E0];
};
extern CB3SoundCrashManager D_01E78510;
// [G] stand-in: retail passes the CGtV3d argument's address with no copy (b119p copies a by-value class argument)
extern "C" void DeformBonnet__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(CB3SoundCrashManager *, const CGtV3d &, float);
extern CGtV3d D_004CAD80;

class CB3VehicleDeform {
public:
    void DeformBonnet(float, float, bool);
    bool GetIKAngles(float, float, float, float *, float *, float *, float *);
    float GetNewBonnetLengths(float, bool, float *, float *);
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

void CB3VehicleDeform::DeformBonnet(float p0, float p1, bool p2)
{
    int k = GetFlyingObjectIndex(field_18, (EVehicleFlyingBit)4);
    if (k < 0) return;
    float d = 0.0f;                               // [L] retail adda.s zero / madd.s
    d += field_14->field_F90[k];
    d += 0.25f * p0;
    field_14->field_F90[k] = d;
    float lA = field_14->field_F30[k][0];
    float lB = field_14->field_F30[k][1];
    float lCur = (field_14->field_C00[k].field_40.mPos - field_14->field_C00[k].field_0.mPos).GetLength();
    float lDef = sqrtf((field_18->field_270[k].field_40.mPos - field_18->field_270[k].field_0.mPos).GetSquaredLength());
    if (lCur > 0.0f) {
        float a4C, a48, a44, a40, a3C, a38;
        if (!GetIKAngles(lA, lB, lDef, &a44, &a40, 0, 0)) return;
        float lNew = GetNewBonnetLengths(lDef, p2, &a38, &a3C);
        if (lNew <= 0.0f) {
            float s = 1.0f;
            s -= 0.25f * p0;
            s *= lCur;
            lNew = s;
            float m = 0.8f * lDef;
            if (lNew < m) lNew = m;
            a3C = 0.0f;
        }
        if (a3C > 180.0f) a3C -= 360.0f;
        a3C = Min(Max(a3C, -25.0f), 25.0f);
        float l0 = field_14->field_F30[k][0];
        float l1 = field_14->field_F30[k][1];
        if (!GetIKAngles(l0, l1, lNew, &a4C, &a48, 0, 0)) return;
        field_14->field_F30[k][0] = l0;
        field_14->field_F30[k][1] = l1;
        float c = (lNew * lNew + lDef * lDef - a38 * a38) / (2.0f * lDef * lNew);
        a4C -= a44;
        a48 = a40 - a48;
        float a = ACosDeg(Min(Max(c, -1.0f), 1.0f));
        a4C -= a;
        a48 -= a;
        CGtV3d lAxis;
        lAxis.SetX(-1.0f);
        lAxis.SetY(0.0f);
        lAxis.SetZ(0.0f);
        CGtV3d lOldPos = field_14->field_C00[k].field_0.mPos;
        field_14->field_C00[k].field_0 = RotateBoneByAxisAngle(field_18->field_270[k].field_0, lAxis, 0.01745329238f * a4C, 0.0f);
        field_14->field_C00[k].field_40 = RotateBoneByAxisAngle(field_18->field_270[k].field_40, lAxis, 0.01745329238f * a48, 0.0f);
        field_14->field_C00[k].field_40 = RotateBoneByAxisAngle(field_14->field_C00[k].field_40, D_004CAD80, 0.01745329238f * a3C, 0.0f);
        field_14->field_C00[k].field_0.mPos = lOldPos;
        field_14->field_C00[k].field_40.mPos = lOldPos + field_14->field_C00[k].field_0.mAt * l0 - field_14->field_C00[k].field_40.mAt * l1;
    }
    field_14->field_900[k].field_0 = field_18->field_770[k].field_0 * field_14->field_C00[k].field_0;
    field_14->field_900[k].field_40 = field_18->field_770[k].field_40 * field_14->field_C00[k].field_40;
    int j = GetFlyingObjectIndex(field_18, (EVehicleFlyingBit)4);
    if (j >= 0) field_14->field_101C[j] = 1;
    if (p1 > 0.0f) DeformBonnet__20CB3SoundCrashManagerFQ29GtMathPs26CGtV3df(&D_01E78510, field_10->field_30, p1);
}
