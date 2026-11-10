// NONMATCHING: Reset__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams -- retail 346 / ours 339 instructions, 96 in changed runs
// v311: logic complete, 96 changed. Left: (1) header SetIdentity in the two matrix loops numbers the hoisted zero rows vf5..vf2 and the per-row scratch vf1, retail rows vf4..vf1 + scratch vf5; (2) tail 0.0f: retail materialises mtc1 zero,f0 and uses swc1 f0 for field_178/17C/180 and four separate mfc1 for the Set(x,y,z)/SetPlus scalars (a function-top float z used in loop 1 reproduces the four mfc1 + vf5..vf2, but not the swc1s); (3) CGtV3d(0,0,0) temp stores stay inside the last loop in retail (frame 0x30), b119 hoists them (frame 0x10)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3VehicleDeform::Reset(CB3VehicleEssentialParams*, CB3VehicleParams*) -- hand-written (v311) from the asm.
// [C] name: the mangled symbol in retail's tables. Field names are placeholders; every type is [G].
// The random step is the CB3CrashActionDirector::StartTrafficCrashing shape (B3CrashActionDirector_001AE500.cpp).

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_003DAEE0_data {
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[0x63];
    CGtMatrix3x4 field_70[8];
    CGtMatrix3x4 field_270[16][2];
    unsigned char pad_A70[0x20];
    float field_A90[30][2];
    CGtMatrix3x4 field_B80[6];
    CGtMatrix3x4 field_D00[1];
};
class CB3VehicleEssentialParams {
public:
    unsigned char pad_0[0x40];
    UnkStruct_003DAEE0_data * field_40;
};
class CB3VehicleParams {
public:
    CGtMatrix3x4 field_0[6];
    CGtMatrix3x4 field_180[12];
    unsigned char pad_480[0x2C];
    unsigned char field_4AC[6];
    unsigned char field_4B2[6];
    int field_4B8[6];
    unsigned char pad_4D0[0x30];
    CGtMatrix3x4 field_500[8];
    CGtMatrix3x4 field_700[8];
    CGtMatrix3x4 field_900[6][2];
    CGtMatrix3x4 field_C00[6][2];
    int field_F00[6][2];
    float field_F30[6][2];
    unsigned char pad_F60[0x18];
    int field_F78[6];
    int field_F90[6];
    float field_FA8[6];
    float field_FC0[6];
    float field_FD8[6];
    unsigned char pad_FF0[0x20];
    int field_1010;
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char field_1016;
    unsigned char pad_1017[4];
    unsigned char field_101B;
    unsigned char field_101C[6];
};
struct UnkStruct_003DAEE0_hull {
    CGtV3d field_0;
    CGtV3dPlus field_10;
    unsigned char pad_20[0x10];
};
class CB3VehicleDeform {
public:
    void Reset(CB3VehicleEssentialParams * p0, CB3VehicleParams * p1);
    int field_0;
    int field_4;
    unsigned long field_8;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    unsigned char pad_20[4];
    float field_24;
    unsigned char pad_28[0x10];
    int field_38;
    int field_3C;
    int field_40;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x29];
    int field_70;
    unsigned char pad_74[0xC];
    UnkStruct_003DAEE0_hull field_80[4];
    CGtV3d field_140;
    CGtV3d field_150;
    int field_160[6];
    float field_178;
    float field_17C;
    float field_180;
    unsigned char field_184;
    unsigned char field_185;
    unsigned char pad_186[6];
    int field_18C;
};

static inline float func_003DAEE0_inl1(CB3VehicleDeform * self)
{
    self->field_0 = (self->field_0 << 16) + (self->field_0 >> 16);
    self->field_0 += self->field_4;
    self->field_4 += self->field_0;
    return 2.3283064e-10f * (float)(unsigned int)self->field_0;
}

// [L] N185: stands in for CGtV3d::Zero() with a compiler-chosen register (the A211_ZERO form of
// B3BodyPartPhysics_00334680.cpp)
static inline void func_003DAEE0_inl2(CGtV3d & v)
{
    u_long128 r;
    asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r));
    v.mData = r;
}

// 0x003DAEE0
void CB3VehicleDeform::Reset(CB3VehicleEssentialParams * p0, CB3VehicleParams * p1)
{
    int i;
    int j;
    field_45 = 0;
    field_46 = 0;
    field_24 = 1.0f;
    field_18C = 0;
    for (i = 0; i < p0->field_40->field_C; i++) {
        float z = 0.0f;
        p1->field_FA8[i] = 0.1f * (z + 0.5f + 0.5f * func_003DAEE0_inl1(this));
        p1->field_FC0[i] = 0.17f * (z + 0.5f + 0.5f * func_003DAEE0_inl1(this));
        p1->field_FD8[i] = 0.2f * (z + 0.7f + 0.3f * func_003DAEE0_inl1(this));
    }
    for (i = 0; i < 8; i++) {
        p1->field_500[i].SetIdentity();
        if (p0->field_40 != 0) {
            p1->field_700[i] = p0->field_40->field_70[i];
        }
    }
    for (i = 0; i < p0->field_40->field_C; i++) {
        if (p0->field_40 != 0) {
            p1->field_180[i] = p0->field_40->field_D00[i];
        }
        for (j = 0; j < 2; j++) {
            p1->field_F00[i][j] = 0;
            p1->field_900[i][j].SetIdentity();
            if (p0->field_40 != 0) {
                p1->field_C00[i][j] = p0->field_40->field_270[i][j];
                p1->field_F30[i][j] = p0->field_40->field_A90[i][j];
            }
        }
    }
    for (i = 0; i < 6; i++) {
        if (p0->field_40 != 0) {
            p1->field_0[i] = p0->field_40->field_B80[i];
        }
    }
    p1->field_101B = 0;
    for (i = 0; i < p0->field_40->field_C; i++) {
        p1->field_101C[i] = 0;
    }
    p1->field_1014 = 0;
    p1->field_1010 = 0;
    p1->field_1015 = 0;
    p1->field_1016 = 0;
    for (i = 0; i < 6; i++) {
        p1->field_4AC[i] = 0;
        p1->field_F78[i] = 0;
        p1->field_4B8[i] = 0;
    }
    for (i = 0; i < p0->field_40->field_C; i++) {
        p1->field_4B2[i] = 0;
        p1->field_F90[i] = 0;
    }
    field_1C = 0;
    field_8 = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_44 = 0;
    field_70 = 0;
    field_38 = 0;
    field_3C = 8;
    field_40 = 4;
    field_45 = 0;
    for (i = 0; i < 6; i++) {
        field_160[i] = 0;
    }
    func_003DAEE0_inl2(field_140);
    func_003DAEE0_inl2(field_150);
    field_178 = 0.0f;
    field_17C = 0.0f;
    field_180 = 0.0f;
    field_184 = 4;
    field_185 = 4;
    for (i = 0; i < 4; i++) {
        field_80[i].field_10.SetGtV3d(CGtV3d(0.0f, 0.0f, 0.0f));
        field_80[i].field_10.SetPlus(0.0f);
        field_80[i].field_0.Set(0.0f, 0.0f, 0.0f);
    }
}
