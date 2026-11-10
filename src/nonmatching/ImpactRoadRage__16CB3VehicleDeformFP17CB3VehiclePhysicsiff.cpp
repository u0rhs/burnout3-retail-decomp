// NONMATCHING: ImpactRoadRage__16CB3VehicleDeformFP17CB3VehiclePhysicsiff -- retail 305 / ours 293 instructions, 148 in changed runs
// draftAG: logic complete; retail 305 / ours 293; calls identical; VU ops identical; the 'int' argument is the 64-bit vehicle id (sd, no sign extension; Impact__16CB3VehicleDeform's t0) -> link-name definition; left: retail's extra stack copy of the clamped bone matrix (rows lq/sq 0x210 -> 0x250), frame 0x2F0 vs 0x210
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; layout shared with the archived ImpactBody / SidewaysDeformation / Impact drafts; every branch, call, store and VU op accounted for; header Min/Max/operator*/SetX..Z; call sequence identical (calls.sh)

// CB3VehicleDeform::ImpactRoadRage(CB3VehiclePhysics*, int, float, float) -- draftAG (C-first draft; no Revenge counterpart).
// [C] name: research/retail_names.csv 0x3E2BF0 (E_B3DEBUG / E_B3O0PCH maps). [L] reading: a road-rage (takedown) hit from above:
// caches the vehicle's deform data pointers, deforms the roof (func_003E5CC0, [L] DeformRoof by E dnat order), sets the impact
// point between the two roof virtual bones (4, 5) with a straight-down... (0,0,1) impact direction, pushes both bones along it
// by 1.2% of the impact size inside their clamp boxes, and rebuilds the final matrices of main bones 1 and 2.
// Layout from the archived ImpactBody__16CB3VehicleDeformFv / SidewaysDeformation__16CB3VehicleDeformFv drafts.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EVirtualBoneIndex { EVirtualBoneIndex_0 };   // placeholder enumerators [G]

struct UnkStruct_003E2BF0_40 { unsigned char pad_0[0x10]; };
struct UnkStruct_003E2BF0_10 { unsigned char pad_0[0x40]; UnkStruct_003E2BF0_40 *field_40; };
// [G] field_14: final bone matrices (+0x500), virtual-bone matrices (+0x700), damage state (+0x101B)
struct UnkStruct_003E2BF0_14 {
    unsigned char pad_0[0x500];
    CGtMatrix3x4 field_500[8];
    CGtMatrix3x4 field_700[8];
    unsigned char pad_900[0x71B];
    unsigned char field_101B;
};
// [G] field_18: default bone matrices (+0x70), bind matrices (+0x570)
struct UnkStruct_003E2BF0_18 {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70[20];
    CGtMatrix3x4 field_570[8];
};
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xCC0];
    UnkStruct_003E2BF0_10 *field_CC0;
    UnkStruct_003E2BF0_14 *field_CC4;
};
struct UnkStruct_003E2BF0_box { CGtV3d field_0; CGtV3d field_10; };   // [G] func_003E6C20's clamp box (max, min)

class CB3VehicleDeform {
public:
    void SetVirtualBoneMatrix(EVirtualBoneIndex, CGtMatrix3x4 *);

    int field_0[2];                       // CGtRandom (ImpactBody draft)
    unsigned long field_8;                // [C] sd: the 64-bit vehicle id (as Impact__16CB3VehicleDeform's t0)
    UnkStruct_003E2BF0_10 *field_10;
    UnkStruct_003E2BF0_14 *field_14;
    UnkStruct_003E2BF0_18 *field_18;
    CB3VehiclePhysics *field_1C;
    unsigned char pad_20[0x27];
    unsigned char field_47;               // [G] flag: road-rage impact pending
    unsigned char pad_48[0xF8];
    CGtV3d field_140;                     // [G] impact position
    CGtV3d field_150;                     // [G] impact direction
    unsigned char pad_160[0x1C];
    float field_17C;                      // [G] impact size
};

extern int kaeVirtualToNormalBone[7];
extern "C" void func_003E5CC0(CB3VehicleDeform *self, float, float);   // [L] DeformRoof(float, float) (E dnat file order)
extern "C" void func_003E6C20(CB3VehicleDeform *self, int bone, UnkStruct_003E2BF0_box *box);   // [L] GetClampBox
extern "C" CGtMatrix3x4 func_003E7390(CB3VehicleDeform *self, int bone);   // [L] GetVirtualBoneMatrix

// [G] one roof bone pushed along the impact direction, clamped to its box
static inline void func_003E2BF0_inl1(CB3VehicleDeform *self, int bone)
{
    UnkStruct_003E2BF0_box lBox;
    func_003E6C20(self, bone, &lBox);
    CGtV3d dir = self->field_150;
    CGtMatrix3x4 lMatrix = func_003E7390(self, bone);
    lMatrix.mPos = Min(lBox.field_0, Max(lBox.field_10, lMatrix.mPos + dir * (1.2f * (0.01f * self->field_17C))));
    self->SetVirtualBoneMatrix((EVirtualBoneIndex)bone, &lMatrix);
}

// 0x003E2BF0
// [C] retail stores its second argument with sd and no sign extension: the 64-bit vehicle id that Impact__16CB3VehicleDeform
// also takes (its t0); the E-map name's `int` is an older signature -> defined through the link name [G type].
extern "C" void ImpactRoadRage__16CB3VehicleDeformFP17CB3VehiclePhysicsiff(CB3VehicleDeform *self, CB3VehiclePhysics *phys, unsigned long type, float size, float b)
{
    self->field_1C = phys;
    if (self->field_1C == 0)
        return;
    self->field_14 = self->field_1C->field_CC4;
    if (self->field_14 == 0)
        return;
    self->field_10 = self->field_1C->field_CC0;
    if (self->field_10 == 0)
        return;
    self->field_18 = (UnkStruct_003E2BF0_18 *)self->field_10->field_40;
    if (self->field_18 == 0)
        return;
    if (size <= 0.0f)
        return;
    self->field_8 = type;
    self->field_47 = 1;
    self->field_14->field_101B = 1;
    func_003E5CC0(self, 0.06f * size, 0.06f * b);
    self->field_17C = size;
    self->field_140 = (self->field_18->field_70[kaeVirtualToNormalBone[4]].mPos + self->field_18->field_70[kaeVirtualToNormalBone[5]].mPos) * 0.5f;
    self->field_150.SetX(0.0f);
    self->field_150.SetY(0.0f);
    self->field_150.SetZ(1.0f);
    func_003E2BF0_inl1(self, 4);
    func_003E2BF0_inl1(self, 5);
    // [G] inlined CB3VehicleDeform::SetFinalMatrix(EMainBodyBoneIndex) (E map API), as in the ImpactBody draft
    self->field_14->field_500[1] = self->field_18->field_570[1] * self->field_14->field_700[1];
    self->field_14->field_500[2] = self->field_18->field_570[2] * self->field_14->field_700[2];
}
