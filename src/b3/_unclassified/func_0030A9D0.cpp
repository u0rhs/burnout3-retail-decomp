// func_0030A9D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (draftAM: GetRadialBlurParams called with retail's five arguments (viewport, car, camera manager in t0); exact).

// from build/vt\try_func_0030A9D0_best.cpp
// func_0030A9D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3RadialBlurParams;
class CB3PlayerCar;
class CB3PlayerCameraManager;

class CB3BoostEffectParams;
struct UnkStruct_0030A9D0;
struct UnkStruct_0030A9D0_a2;
struct UnkStruct_0030A9D0_e0;
struct UnkStruct_D_004E1020;
struct UnkStruct_D_004E1028;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0064C9A0;
struct UnkStruct_D_0064C9A4;

class CB3BoostEffectParams {
public:
};
// draftAM [C]: retail passes five arguments (a0 this, a1 the params, a2 this function's p0 -- a viewport, Revenge's lpViewport --,
// a3 the car, t0 the camera manager &D_004EE040.field_28E00[car->field_27C0]); the mangled name lists three (defined so in
// src/nonmatching/GetRadialBlurParams__20CB3BoostEffectParams...cpp), so it is called through its link name
extern "C" void GetRadialBlurParams__20CB3BoostEffectParamsCFP19CB3RadialBlurParamsP12CB3PlayerCarP22CB3PlayerCameraManager(
    const CB3BoostEffectParams *, CB3RadialBlurParams *, void *, CB3PlayerCar *, CB3PlayerCameraManager *);

struct UnkStruct_D_0064C9A0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064C9A4 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E1028 {
    float field_0;
};

struct UnkStruct_0030A9D0_a2 {
    unsigned char pad_0[0x118C];
    CB3BoostEffectParams field_118C;
    unsigned char pad_118D[0x7];
    float field_1194;
    unsigned char pad_1198[0x1628];
    int field_27C0;
};

struct UnkStruct_0030A9D0_e0 {
    unsigned char pad_0[0xB00];
    unsigned long field_B00;
    unsigned char pad_B08[0xA8];
};

struct UnkStruct_0030A9D0_e1 { unsigned char pad_0[0xB80]; unsigned long field_B80; unsigned char pad_B88[0x28]; };
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x28E00];
    UnkStruct_0030A9D0_e1 field_28E00[1];  // [G] element count unknown
};

struct UnkStruct_D_004E1020 {
    float field_0;
};

struct UnkStruct_0030A9D0 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    int field_1C;
    unsigned char pad_20[0x30];
    float field_50;
    float field_54;
    float field_58;
    unsigned char pad_5C[0x38];
    int field_94;
};

extern UnkStruct_D_0064C9A0 D_0064C9A0;
extern UnkStruct_D_0064C9A4 D_0064C9A4;
extern UnkStruct_D_004E1028 D_004E1028;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_004E1020 D_004E1020;

// 0x0030A9D0
extern "C" void func_0030A9D0(UnkStruct_0030A9D0 * self, int p0, UnkStruct_0030A9D0_a2 * p1)
{
    self->field_50 = D_0064C9A0.field_0;
    self->field_54 = D_0064C9A4.field_0;
    if (p1 != 0) {
        UnkStruct_0030A9D0_e1 * cam = (UnkStruct_0030A9D0_e1*)((int)&D_004EE040.field_28E00[p1->field_27C0]);
        unsigned long t2 = cam->field_B80;
        if ((t2 & 4) || (t2 & 8) || (t2 & 16) || (t2 & 32)) {
            self->field_58 = (0.5f + (p1->field_1194 * D_004E1020.field_0));
            GetRadialBlurParams__20CB3BoostEffectParamsCFP19CB3RadialBlurParamsP12CB3PlayerCarP22CB3PlayerCameraManager(
                &p1->field_118C, (CB3RadialBlurParams*)self, (void*)p0, (CB3PlayerCar*)p1, (CB3PlayerCameraManager*)cam);
            self->field_94 = 0;
            return;
        }
    }
    self->field_58 = 0.5f;
    float t0 = D_004E1028.field_0;
    self->field_0 = 0.5f;
    self->field_4 = 0.5f;
    self->field_8 = 1.0f;
    self->field_C = 1.0f;
    self->field_10 = t0;
    self->field_14 = t0;
    self->field_18 = 1.0f;
    self->field_1C = 0;
    self->field_94 = 0;
}
