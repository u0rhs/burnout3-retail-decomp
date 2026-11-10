// NONMATCHING: Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df -- retail 658 / ours 673 instructions, 231 in changed runs
// draftAG: logic complete; retail 658 / ours 673; calls identical; branch and VU op counts identical (category test as a 6..10 switch; IsRoofImpact inline copied from the ImpactBody draft; one stand-in operator*(XAxisType,float), queued); retail has 4 register args + a bool at sp+0x10 the E-map name lacks (64-bit vehicle id t0, impact type t3): defined through the link name; left: addiu/lwc1/sq counts (copy temporaries), frame 0x7D0 vs 0x6A0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every branch, call, store, constant and VU op decoded from retail asm; header Invert / TransformPoint / TransformVector / DotProduct / Normalise / GetLength / IsEffectivelyZero / CGtRandom::Random; call sequence identical (calls.sh)

// CB3VehicleDeform::Impact(...) -- draftAG (C-first draft). [C] name: research/retail_names.csv 0x3DB450 (high).
// [C] retail's argument list is longer than the E-map mangled name's (as ImpactRoadRage's `sd` of its id): a0 this, a1 the
// vehicle physics, a2 the essential params (+0x0 world matrix, +0x40 bone data), a3 the vehicle params (damage arrays),
// t0 a 64-bit vehicle id (compared with six 64-bit hashes, stored by sd), t1 the traffic category (6..10 = the big
// vehicles), t2 the active body type, t3 the impact type (2 = [L] scrape: skipped while the IK flag is set), the impact
// position and direction by address (caller sp+0 / sp+8), f12 the impact size, and a bool at caller sp+0x10 (true: no
// residual split). Defined through the link name with that list [G types]. Revenge's Impact (CB4VehicleDeformInput) differs.
// [L] reading: clamps tiny side impacts of small magnitude to the horizontal, picks a stiffness class (field_38) from the
// vehicle height / id / category, scales the size by it, moves position and direction into the vehicle frame, adds paint
// damage to the struck panels (bits facing the impact) and random damage to the lower panels when hit below mid height,
// then either treats it as a roof impact or scales and normalises the local direction, finds the struck virtual bones,
// clamps the size to 0..1 and hands any excess over the cap to AddResidual before ImpactBody.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

struct UnkStruct_003DB450_40 {             // the bone data (essential params +0x40) [G]
    unsigned char pad_0[0xC];
    signed char field_C;                    // [C] count of the panels at field_14->field_180 / field_F90
    signed char field_D;                    // [C] count of the lower panels at field_14->field_0 / field_F78
    unsigned char pad_E[0xE72];
    CGtV3d field_E80;                       // [C] bounding box max (E80.z - E90.z = height; mid y)
    CGtV3d field_E90;                       // [C] bounding box min
};
struct UnkStruct_003DB450_10 {             // CB3VehicleEssentialParams [L]
    CGtMatrix3x4 field_0;                   // [C] the vehicle's world matrix (inverted here)
    UnkStruct_003DB450_40 *field_40;
};
struct UnkStruct_003DB450_14 {             // CB3VehicleParams [L]: per-panel matrices and damage
    CGtMatrix3x4 field_0[6];                // [C] mPos (+0x30 + i*0x40) = the lower panels' normals [G]
    CGtMatrix3x4 field_180[14];             // [C] mPos (+0x1B0 + i*0x40) = the panels' normals [G]
    CGtMatrix3x4 field_500[8];
    CGtMatrix3x4 field_700[8];
    unsigned char pad_900[0x678];
    float field_F78[6];                     // [C] lower panel damage
    float field_F90[32];                    // [C] panel damage
};
struct UnkStruct_003DB450_18 {             // ImpactBody draft's field_18
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70[20];
    unsigned char pad_570[0x550];
    int field_AC0;                          // [C] has bones
};
struct UnkStruct_003DB450_box { CGtV3d field_0; CGtV3d field_10; };   // func_003E6C20's clamp box (max, min)
enum EVirtualBoneIndex { EVirtualBoneIndex_0 };   // placeholder enumerators [G]

class CB3VehicleDeform {
public:
    void ImpactBody();
    void AddResidual(CGtV3d, CGtV3d, float);
    void CheckForDeformationRepairing(EVirtualBoneIndex);

    CGtRandom field_0;
    unsigned long field_8;                  // [C] sd: the 64-bit vehicle id
    UnkStruct_003DB450_10 *field_10;
    UnkStruct_003DB450_14 *field_14;
    UnkStruct_003DB450_18 *field_18;
    void *field_1C;                         // CB3VehiclePhysics*
    unsigned char pad_20[4];
    float field_24;                         // [C] stiffness divisor (reset to 3 when <= 1)
    unsigned char pad_28[0x10];
    int field_38;                           // [C] stiffness class 0..3
    int field_3C;                           // [C] active body type
    int field_40;                           // [C] impact type
    unsigned char pad_44[2];
    unsigned char field_46;                 // [C] flag: IK pass (ImpactBody draft)
    unsigned char pad_47[0xF9];
    CGtV3d field_140;                       // [C] impact position (vehicle frame)
    CGtV3d field_150;                       // [C] impact direction (vehicle frame)
    float field_160[6];                     // [C] panel damage before this impact
    float field_178;
    float field_17C;                        // [C] impact size
    float field_180;
    signed char field_184;
    signed char field_185;
    unsigned char pad_186[2];
    int field_188;
};

extern float D_0052267C;                    // [C] lw from .data: the residual cap scale [G]
extern const CGtV3d D_004CAD50;             // [C] direction scales (16-byte constants, zero in the ELF: static-initialised)
extern const CGtV3d D_004CAD60;             // [C] ... with the IK flag set
extern "C" void func_003E6C20(CB3VehicleDeform *self, int bone, UnkStruct_003DB450_box *box);   // [L] GetClampBox
extern "C" CGtMatrix3x4 func_003E7390(CB3VehicleDeform *self, int bone);   // [L] GetVirtualBoneMatrix
// [G] stand-in: retail passes &field_140 itself for the by-value CGtV3d (as the ImpactBody draft)
extern "C" void GetVirtualBones__16CB3VehicleDeformFQ29GtMathPs26CGtV3dPScPScPf(CB3VehicleDeform *, const void *, signed char *, signed char *, float *);

// [G] inlined CB3VehicleDeform::IsRoofImpact() (copied from the ImpactBody draft's func_003DC730_inl12)
static inline bool func_003DB450_inl1(CB3VehicleDeform *self)
{
    UnkStruct_003DB450_box box;
    func_003E6C20(self, 6, &box);
    CGtV3d pos = func_003E7390(self, 6).mPos;
    CGtV3d top = box.field_10;
    bool below = !(pos.Y() > top.Y());
    if (below) return false;
    CGtV3d dir = self->field_150;
    if (!(dir.Y() < -0.5f)) return false;
    float zf = self->field_18->field_70[4].mPos.Z() * 0.75f + self->field_18->field_70[1].mPos.Z() * 0.25f;
    float zr = self->field_18->field_70[4].mPos.Z() * 0.25f + self->field_18->field_70[1].mPos.Z() * 0.75f;
    if (self->field_140.Z() > zf) return false;
    if (self->field_140.Z() < zr) return false;
    return true;
}

// 0x003DB450
extern "C" void Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
    CB3VehicleDeform *self, void *phys, UnkStruct_003DB450_10 *ess, UnkStruct_003DB450_14 *params, unsigned long id,
    int category, int bodyType, int impactType, CGtV3d pos, CGtV3d dir, float size, bool noResidual)
{
    self->field_14 = params;
    if (self->field_14 == 0)
        return;
    self->field_10 = ess;
    if (self->field_10 == 0)
        return;
    self->field_18 = (UnkStruct_003DB450_18 *)self->field_10->field_40;
    if (self->field_18 == 0)
        return;
    if (size <= 0.0f)
        return;
    if (self->field_46 && impactType == 2)
        return;
    CGtV3d lDir = dir;
    lDir.Normalise();
    if (size < 1500) {
        if (!(lDir.Y() <= 0.9f)) {
            // a small hit from below: keep only its horizontal part
            CGtV3d v = lDir * size;
            v.SetY(0.0f);
            size = v.GetLength();
            if (GtMath::IsEffectivelyZero(size))
                return;
            v.Normalise();
            lDir = v;
        }
    }
    float height = self->field_10->field_40->field_E80.Z() - self->field_10->field_40->field_E90.Z();
    switch (category) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        self->field_38 = 3;
        break;
    default:
        if (height > 5.5f)
            self->field_38 = 1;
        else
            self->field_38 = 0;
        if (id == 0x7704283867D5A000UL || id == 0x7704283867FCB000UL || id == 0x770428386823C000UL ||
            id == 0x7704283866EE2E00UL || id == 0x790798FBA1422A00UL)
            self->field_38 = 1;
        else if (id == 0x77042838671E0800UL)
            self->field_38 = 2;
        break;
    }
    self->field_3C = bodyType;
    self->field_40 = impactType;
    self->field_17C = size;
    self->field_1C = phys;
    self->field_8 = id;
    self->field_188 = 0;
    switch (self->field_38) {
    case 0:
        self->field_17C *= 0.0003125f;
        break;
    case 1:
        self->field_17C *= 0.00015625f;
        break;
    case 2:
        self->field_17C *= 0.00020833333f;
        break;
    default:
        self->field_17C *= 0.00015625f;
        break;
    }
    if (self->field_46)
        self->field_17C *= 1.5f;
    CGtMatrix3x4 lInv = self->field_10->field_0;
    lInv.Invert();
    self->field_140 = TransformPoint(lInv, pos);
    self->field_150 = TransformVector(lInv, lDir);
    for (int i = 0; i < self->field_10->field_40->field_C; i++)
        self->field_160[i] = self->field_14->field_F90[i];
    if (self->field_17C > 5.0f) {
        // paint damage on every panel facing the impact
        for (int i = 0; i < self->field_10->field_40->field_C; i++) {
            if (DotProduct(self->field_150, self->field_14->field_180[i].mPos) < 0.0f)
                self->field_14->field_F90[i] += GtMath::Min(0.002f * self->field_17C, 0.1f);
        }
        UnkStruct_003DB450_40 *b = self->field_10->field_40;
        if (self->field_140.Y() < (b->field_E80.Y() + b->field_E90.Y()) * 0.5f) {
            // hit below mid height: random damage on the lower panels facing it
            for (int i = 0; i < self->field_10->field_40->field_D; i++) {
                if (DotProduct(self->field_150, self->field_14->field_0[i].mPos) < 0.0f) {
                    float r = 0.0f + 0.5f + 0.5f * (2.3283064e-10f * (float)self->field_0.Random());
                    self->field_14->field_F78[i] += GtMath::Min(0.02f * self->field_17C * r, 0.5f);
                }
            }
        }
    }
    if (func_003DB450_inl1(self)) {
        self->field_17C *= self->field_24;
    } else {
        self->field_150 = self->field_150 * self->field_17C;
        if (self->field_46)
            self->field_150 = self->field_150 * D_004CAD60;
        else
            self->field_150 = self->field_150 * D_004CAD50;
        if (impactType != 2) {
            self->field_17C = (self->field_150.GetLength() * self->field_24);
            self->field_150.SetY((float)self->field_150.Y() / self->field_24);
        }
        if (self->field_17C < 1.5258789e-05f)
            return;
        if (self->field_150.GetSquaredLength() < 2.3283064e-10f)
            return;
        self->field_150.Normalise();
        if (self->field_18->field_AC0 != 0) {
            GetVirtualBones__16CB3VehicleDeformFQ29GtMathPs26CGtV3dPScPScPf(self, &self->field_140, &self->field_184, &self->field_185, &self->field_178);
            self->CheckForDeformationRepairing((EVirtualBoneIndex)self->field_184);
            self->CheckForDeformationRepairing((EVirtualBoneIndex)self->field_185);
        }
    }
    if (self->field_24 <= 1.0f)
        self->field_24 = 3.0f;
    self->field_17C = GtMath::Min(GtMath::Max(self->field_17C * 0.0125f, 0.0f), 1.0f);
    self->field_180 = self->field_17C;
    if (!noResidual) {
        float lrCap = 20.0f * D_0052267C;
        if (self->field_17C > lrCap) {
            self->AddResidual(self->field_140, self->field_150, self->field_17C - lrCap);
            self->field_17C = lrCap;
        }
    }
    self->ImpactBody();
}
