// func_001508C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a189: else-arm first, goto stubs, D_004E0D6C*CGtV4d::W() lane (N172)).

// func_001508C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

enum EHUDMode {};
class CB3RaceCarPhysics;

struct UnkStruct_001508C0;
struct UnkStruct_001508C0_1;
struct UnkStruct_001508C0_2;
struct UnkStruct_001508C0_4;
struct UnkStruct_001508C0_5;
struct UnkStruct_001508C0_8;
struct UnkStruct_001508C0_e1;
struct UnkStruct_001508C0_e2;
struct UnkStruct_001508C0_e3;
struct UnkStruct_001508C0_e4;
struct UnkStruct_D_004F50C0;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0052267C;
struct UnkStruct_D_0055EF70;
struct UnkStruct_D_00645170;
struct UnkStruct_D_0064D37A;
struct UnkStruct_D_0066A3D0;

struct UnkStruct_001508C0_1 {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
    unsigned char pad_C0[0x1464];
    int field_1524;
    unsigned char pad_1528[0xC];
    float field_1534;
};

struct UnkStruct_001508C0_2 {
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    unsigned char pad_10[0x10];
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_001508C0_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001508C0_4 {
    unsigned char pad_0[0x1B4];
    UnkStruct_001508C0_5 * field_1B4;
};

struct UnkStruct_001508C0_5 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual int vfunc_E8(int);
};

struct UnkStruct_D_0052267C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00645170 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001508C0_8 {
    unsigned char pad_0[0x3524];
    int field_3524;
};

struct UnkStruct_D_0064D37A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001508C0_e1 {
    unsigned char pad_0[0x6C];
    int field_6C;
    unsigned char pad_70[0xBC];
};

struct UnkStruct_001508C0_e4 {
    unsigned char pad_0[0x12C];
};

struct UnkStruct_D_004F50C0 {
    UnkStruct_001508C0_e4 field_0[1];  // [G] element count unknown
    unsigned char pad_12C[0xBB8];
    UnkStruct_001508C0_e1 field_CE4[1];  // [G] element count unknown
};

struct UnkStruct_001508C0_e2 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_D_0066A3D0 {
    UnkStruct_001508C0_e2 field_0[1];  // [G] element count unknown
};

struct UnkStruct_001508C0_e3 {
    unsigned char pad_0[0x4590];
};

struct UnkStruct_D_0055EF70 {
    UnkStruct_001508C0_e3 field_0[1];  // [G] element count unknown
};

struct UnkStruct_001508C0 {
    unsigned char pad_0[0x133C];
    int field_133C;
    unsigned char pad_1340[0x5AA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x11];
    float field_18FC;
    unsigned char pad_1900[0xC0];
    GtMathPs2::CGtV3d field_19C0;
    unsigned char pad_19D0[0xA60];
    UnkStruct_001508C0_1 * field_2430;
    unsigned char pad_2434[0x38C];
    int field_27C0;
    int field_27C4;
    unsigned char field_27C8;
};

extern float D_004E0D6C;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0052267C D_0052267C;
extern UnkStruct_D_00645170 D_00645170;
extern UnkStruct_D_0064D37A D_0064D37A;
extern signed char D_004F6061[];  // [G] element count unknown
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_0066A3D0 D_0066A3D0;
extern UnkStruct_D_0055EF70 D_0055EF70;

extern "C" void Update__10CB3RaceCarFv(void *);  // CB3RaceCar::Update()
extern "C" void UpdateAICheckpoint__8CB3AICarFv(void *);  // CB3AICar::UpdateAICheckpoint()
extern "C" void ResetTarget__11CB3AITargetFv(void *);  // CB3AITarget::ResetTarget()
extern "C" void SetHUDMode__6CB3HUDF8EHUDMode(void *, EHUDMode);  // CB3HUD::SetHUDMode(EHUDMode)
extern "C" void Update__8CB3AICarFv(void *);  // CB3AICar::Update()
extern "C" void StopImmediately__16CB3CollidingBodyFv(void *);  // CB3CollidingBody::StopImmediately()
extern "C" void ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics(void *, bool, void *);  // CB3RaceCarPhysics::ResetOnTrack(bool,CB3RaceCarPhysics*)
extern "C" void func_00364270(void *);
extern "C" void func_00150460(UnkStruct_001508C0 *, unsigned char, int);
extern "C" int func_0012EF20(void *);
extern "C" void func_00442AE0(void *, float, float);
extern "C" void func_00442900(int, signed char, float, float);

// 0x001508C0
extern "C" void func_001508C0(UnkStruct_001508C0 * self)
{
    func_00364270(((char *)self + 0x2470));
    if (self->field_27C8 != 0) {
        Update__8CB3AICarFv(self);
        if (self->field_18EA != 0) goto neg;
        if (!(self->field_18FC < 0.5f)) goto neg;
        {
                UnkStruct_001508C0_1 *pp = self->field_2430;
        if (!((D_004E0D6C * (float)pp->field_B0.W()) < 5.0f)) goto neg;  // [C] retail FPU form, not a VU lane op: 0x150934 lwc1 / 0x150938 mul.s (the cast keeps the port's PS2 float model)
        }
        {
            UnkStruct_001508C0_4 * t1 = D_0051BA88.field_0;
            if (t1 == 0) goto neg;
            UnkStruct_001508C0_5 * t2 = t1->field_1B4;
            if (t2 == 0) goto neg;
            int r6 = t2->vfunc_E8(self->field_27C0);
            if (r6 == 0) goto neg;
        }
        if (-1.0f == *(const float *)&self->field_27C4) goto quarter;
        {
            float t3 = *(float *)&self->field_27C4;
            float t4 = D_0052267C.field_0;
            *(float *)&self->field_27C4 = (t3 - t4);
            if ((t3 - t4) <= 0.0f) {
                *(float *)&self->field_27C4 = -1.0f;
                int t5 = self->field_27C0;
                UnkStruct_001508C0_8 * v5;
                if (D_00645170.field_0 > t5) {
                    v5 = (UnkStruct_001508C0_8 *)((char *)&D_0055EF70.field_0[t5] + 0x1CB80);
                } else {
                    v5 = 0;
                }
                StopImmediately__16CB3CollidingBodyFv(v5);
                func_00150460(self, D_0064D37A.field_0, v5->field_3524);
                ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics(v5, 1, 0);
            }
        }
    after:
        {
            UnkStruct_001508C0_e4 * e = &D_004F50C0.field_0[D_004F6061[*(signed char *)&self->field_27C0]];
            int r10 = func_0012EF20(((char *)e + 0xD48));
            if (r10 != 0) {
            e = &D_004F50C0.field_0[D_004F6061[*(signed char *)&self->field_27C0]];
            func_00442AE0((void *)(*(int *)((char *)e + 0xD50)), 0.0f, 0.0f);
            e = &D_004F50C0.field_0[D_004F6061[*(signed char *)&self->field_27C0]];
            func_00442900(*(int *)((char *)e + 0xD50), *(signed char *)&self->field_27C0, 0.0f, 1.0f);
            }
        }
        goto end;
    quarter:
        self->field_27C4 = 0x3E800000;
        goto after;
    neg:
        self->field_27C4 = 0xBF800000;
        goto after;
    } else {
    Update__10CB3RaceCarFv(self);
    UpdateAICheckpoint__8CB3AICarFv(self);
    if (self->field_133C != 3) {
        return;
    }
    if (self->field_27C8 != 1) {
        self->field_27C8 = 1;
        if (self->field_27C8 != 0) {
            self->field_19C0.Zero();
            ResetTarget__11CB3AITargetFv(((char *)self + 0x19F0));
        } else {
            self->field_2430->field_1534 = 1.0f;
            UnkStruct_001508C0_1 * t0 = self->field_2430;
            int * pf = &t0->field_1524;
            if (t0->field_1524 == 4) {
                *pf = 0;
            }
        }
    }
    SetHUDMode__6CB3HUDF8EHUDMode(&D_0066A3D0.field_0[self->field_27C0], (EHUDMode)4);
    }
end:
    return;
}
