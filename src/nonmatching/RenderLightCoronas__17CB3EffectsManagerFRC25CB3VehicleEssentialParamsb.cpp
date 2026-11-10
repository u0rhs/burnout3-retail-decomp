// NONMATCHING: RenderLightCoronas__17CB3EffectsManagerFRC25CB3VehicleEssentialParamsb -- retail 591 / ours 609 instructions, 514 in changed runs
// draftAL C-first: camera position into object space (Invert + TransformPoint), NormaliseGetLength -> size 1 + 0.02 d; seven light-group corona loops (one inline: TransformPoint, facing DotProduct > 0, AddTrafficCorona's slot write), groups chosen by the flags at +0x58, bits 0x20/0x40 through func_00257080 when lbRearIndicatorsAreRed; 609/591, calls identical; left: MWCC's loop guard + out-of-line arm choice (goto / inverted-if forms compile identically), 400.0f via sw (AddTrafficCorona's open item), matrix rows lq vs lqc2
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); each group's flag bit, light index k (arrays +0x1664[k] / counts +0x16AC[k]), colour global and size factor (1.25, 1, 0.75, 0.5) traced; func_00257080's argument list (k 5/6, D_004BC020, D_004BC010, view dir, 0.5 size)

// CB3EffectsManager::RenderLightCoronas(const CB3VehicleEssentialParams&, bool) -- draftAL (C-first draft). 0x256690, 0x93C.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm (Ghidra's draft as a reading aid); parameter and
// local names from the Revenge STABS of CB4EffectsManager::RenderLightCoronas (lVehicle, lbRearIndicatorsAreRed,
// lInverseObjectMatrix, lrSize; Revenge adds a 3rd parameter). The corona slot write is the body of the archived sibling
// AddTrafficCorona (0x256FD0, defined right after this function): [L] inlined here.
// What it does [L]: the camera position (manager +0x1F810) taken into the vehicle's object space gives the view direction and
// distance; corona size = 1 + 0.02 * distance. Per light group of the vehicle model (light arrays at model +0x1664[k], counts at
// +0x16AC[k], 0x30 bytes per light: position, facing) the vehicle flags (+0x58) choose which groups light up and with which
// colour (static CGtV4d globals D_004BBFE0..D_004BC030); each light facing the camera (dot > 0) adds a corona (position, w 400;
// colour * dot * 64, w = size) to the manager's slot list (+0x2C cursor, +0x30 end). Bits 0x20 / 0x40 with
// lbRearIndicatorsAreRed go through func_00257080 instead (two colours by the light's side).
// Types and field meanings [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00256690_slot { float x, y, z, w; float vx, vy, vz, vw; };   // position (w 400), colour (w size); as AddTrafficCorona's
struct UnkStruct_00256690_light { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x10]; };   // position, facing
struct UnkStruct_00256690_model {
    unsigned char pad_0[0x1664];
    UnkStruct_00256690_light * field_1664[7];
    unsigned char pad_1680[0x2C];
    unsigned char field_16AC[7];
};
class CB3VehicleEssentialParams {
public:
    CGtMatrix3x4 field_0;                   // object matrix
    UnkStruct_00256690_model * field_40;
    unsigned char pad_44[0x14];
    unsigned char field_58;                 // light flags
};
class CB3EffectsManager {
public:
    void RenderLightCoronas(const CB3VehicleEssentialParams &, bool);
    unsigned char pad_0[0x2C];
    UnkStruct_00256690_slot * field_2C;     // corona slot cursor
    UnkStruct_00256690_slot * field_30;     // corona slot end
    unsigned char pad_34[0x1F7DC];
    CGtV3d field_1F810;                     // camera position
};
extern CGtV3d D_004BBFE0;
extern CGtV3d D_004BBFF0;
extern CGtV3d D_004BC000;
extern CGtV3d D_004BC010;
extern CGtV3d D_004BC020;
extern CGtV3d D_004BC030;
extern "C" void func_00257080(CB3EffectsManager *, const CB3VehicleEssentialParams *, int, CGtV3d, CGtV3d, CGtV3d, float);

// [L] the slot write of AddTrafficCorona (0x256FD0): colour * 64 only once a slot is free
static inline void func_00256690_inl1(CB3EffectsManager * self, const CGtV3d & pos, const CGtV3d & colour, float size)
{
    UnkStruct_00256690_slot * s = self->field_2C;
    if (s != self->field_30) {
        CGtV3d c = colour * 64.0f;
        *(CGtV3d *)&s->x = pos;
        s->w = 400.0f;
        *(CGtV3d *)&s->vx = c;
        s->vw = size;
        self->field_2C++;
    }
}
// [G] one light group's coronas
static inline void func_00256690_inl2(CB3EffectsManager * self, const CB3VehicleEssentialParams & lVehicle, int k, CGtV3d colour,
                                      CGtV3d dir, float size)
{
    UnkStruct_00256690_model * m = lVehicle.field_40;
    int n = m->field_16AC[k];
    UnkStruct_00256690_light * e = m->field_1664[k];
    for (int i = 0; i < n; i++, e++) {
        CGtV3d p = TransformPoint(lVehicle.field_0, e->field_0);
        float d = DotProduct(e->field_10, dir);
        if (d > 0.0f)
            func_00256690_inl1(self, p, colour * d, size);
    }
}

// 0x00256690
void CB3EffectsManager::RenderLightCoronas(const CB3VehicleEssentialParams & lVehicle, bool lbRearIndicatorsAreRed)
{
    CGtMatrix3x4 lInverseObjectMatrix = lVehicle.field_0;
    lInverseObjectMatrix.Invert();
    CGtV3d dir = TransformPoint(lInverseObjectMatrix, field_1F810);
    float len = dir.NormaliseGetLength();
    float lrSize = 1.0f + 0.02f * len;
    if (lVehicle.field_58 & 2)
        func_00256690_inl2(this, lVehicle, 0, D_004BBFE0, dir, 1.25f * lrSize);
    else if (lVehicle.field_58 & 4)
        func_00256690_inl2(this, lVehicle, 0, D_004BBFF0, dir, lrSize);
    if (lVehicle.field_58 & 0x10)
        func_00256690_inl2(this, lVehicle, 2, D_004BC000, dir, 0.75f * lrSize);
    else if (lVehicle.field_58 & 8)
        func_00256690_inl2(this, lVehicle, 1, D_004BC010, dir, 0.5f * lrSize);
    if (lVehicle.field_58 & 0x20) {
        if (lbRearIndicatorsAreRed)
            func_00257080(this, &lVehicle, 5, D_004BC020, D_004BC010, dir, 0.5f * lrSize);
        else
            func_00256690_inl2(this, lVehicle, 5, D_004BC020, dir, 0.5f * lrSize);
    }
    if (lVehicle.field_58 & 0x40) {
        if (lbRearIndicatorsAreRed)
            func_00257080(this, &lVehicle, 6, D_004BC020, D_004BC010, dir, 0.5f * lrSize);
        else
            func_00256690_inl2(this, lVehicle, 6, D_004BC020, dir, 0.5f * lrSize);
    }
    if (lVehicle.field_58 & 0x80)
        func_00256690_inl2(this, lVehicle, 4, D_004BC030, dir, 0.5f * lrSize);
}
