// Hand-written; the lifter refused it (hull record struct copy (aligned(4) byte array) + row-pointer Zero() stand-ins hoisted by b119p).

// func_001CBA30 -- hand-matched (ghvu8). Placeholder name, C linkage (asm label); `self` is a0.
// [G] nahelam_check.csv row (rejected): CB3VehiclePhysics::StopCrashing -- not used as evidence.
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

// [G] 0x600-byte record copied whole from the params object (+0x1060) to self+0x220.
struct UnkStruct_001CBA30_hull {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    signed char field_1C[0x78] __attribute__((aligned(4)));  // [G] array starts 4-aligned (0x1B not copied)
    u_long128 field_A0[0x28];
    u_long128 field_320[0x16];
    signed char field_480[0x78];
    int field_4F8[0x42];
};

struct UnkStruct_001CBA30_40 {
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[0x1053];
    UnkStruct_001CBA30_hull field_1060;
};

struct UnkStruct_001CBA30_cc0 {
    unsigned char pad_0[0x40];
    UnkStruct_001CBA30_40 * field_40;
};

struct UnkStruct_001CBA30_cc4 {
    unsigned char pad_0[0x300];
    unsigned char field_300[0x10];
};

struct UnkStruct_001CBA30_w {
    unsigned char pad_0[0x54];
    float field_54;
    unsigned char pad_58[0x68];
};

struct UnkStruct_001CBA30_r {
    unsigned char pad_0[0x60];
    CGtV3d field_60;
    CGtV3d field_70;
    CGtV3d field_80;
    CGtV3d field_90;
    CGtV3d field_A0;
    unsigned char pad_B0[0x10];
};

struct UnkStruct_001CBA30 {
    unsigned char pad_0[0x220];
    UnkStruct_001CBA30_hull field_220;
    unsigned char pad_820[0x20];
    UnkStruct_001CBA30_w field_840[5];
    unsigned char pad_C00[0xA0];
    float field_CA0;
    unsigned char pad_CA4[0xC];
    float field_CB0;
    unsigned char pad_CB4[0xC];
    UnkStruct_001CBA30_cc0 * field_CC0;
    UnkStruct_001CBA30_cc4 * field_CC4;
    unsigned char pad_CC8[0x18];
    UnkStruct_001CBA30_r field_CE0[4];
    unsigned char pad_FE0[0x189];
    signed char field_1169;
    unsigned char pad_116A[0x2];
    float field_116C;
};

extern "C" void StopCrashing__16CB3CollidingBodyFv(void *);
extern "C" void Reset__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(void *, void *, void *);
extern "C" void Initialise__20CB3ConvexHullVehicleFv(void *);

// [L] N185: stands in for the header's Zero() (which hard-codes $vf1)
static inline void func_001CBA30_inl1(CGtV3d &v) { u_long128 t; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(t)); v.mData = t; }

// 0x001CBA30
extern "C" void func_001CBA30(UnkStruct_001CBA30 * self)
{
    int i;
    StopCrashing__16CB3CollidingBodyFv(self);
    for (i = 0; i < self->field_1169; i++) {
        if (i < 2) {
            self->field_840[i].field_54 = self->field_CA0;
        } else {
            self->field_840[i].field_54 = self->field_CB0;
        }
    }
    Reset__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(self->field_CC4->field_300, self->field_CC0, self->field_CC4);
    self->field_220 = self->field_CC0->field_40->field_1060;
    UnkStruct_001CBA30_r *r = self->field_CE0;
    for (i = 0; i < self->field_CC0->field_40->field_C; i++, r++) {
        func_001CBA30_inl1(r->field_90);
        func_001CBA30_inl1(r->field_60);
        func_001CBA30_inl1(r->field_70);
        func_001CBA30_inl1(r->field_80);
        func_001CBA30_inl1(r->field_90);
        func_001CBA30_inl1(r->field_A0);
    }
    Initialise__20CB3ConvexHullVehicleFv(&self->field_220);
    self->field_116C = 9999;
}
