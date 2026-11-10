// Hand-written; the lifter refused it (N182 opt_arithtransformation off + x=1; x=f?x:0 (movz)).

// N182: retail compiled this function with `#pragma opt_arithtransformation off` ([G] scoped to this function).
#pragma push
#pragma opt_arithtransformation off

struct UnkStruct_0021B5E0_set {
    unsigned char pad_0[0x2C];
    signed char field_2C[2];
    signed char pad_2E[2];
    signed char field_30;
    signed char field_31;
    signed char pad_32[2];
    signed char field_34;
    signed char field_35;
    signed char pad_36[3];
    signed char field_39;
    signed char pad_3A[3];
    signed char field_3D;
    signed char field_3E;
};
struct UnkStruct_0021B5E0_g {
    unsigned char pad_0[0x8025];
    unsigned char field_8025[2];
};
extern UnkStruct_0021B5E0_g D_004EE040;
struct UnkStruct_D_005179DC { int field_0; int pad_4[3]; };
struct UnkStruct_D_00665EF0 { float field_0; float pad_4[3]; };
extern UnkStruct_D_005179DC D_005179DC;
extern UnkStruct_D_005179DC D_0051858C;
extern UnkStruct_D_00665EF0 D_00665EF0;
extern UnkStruct_D_00665EF0 D_00665EF4;
extern float D_004E0C64;
extern float D_004E0C68;
extern float D_004E0C6C;
extern unsigned char D_01E75640[];
extern unsigned char D_01E7A888[];
extern "C" void func_0028AC80(void *, float);
extern "C" float func_003F8890(void *, float);
extern "C" void func_003F8870(void *, int);

// 0x0021B5E0
extern "C" void func_0021B5E0(UnkStruct_0021B5E0_set *p0)
{
    if (p0->field_3D != 0) {
        D_005179DC.field_0 = 2;
    } else {
        D_005179DC.field_0 = 5;
    }
    if (p0->field_3E != 0) {
        D_0051858C.field_0 = 2;
    } else {
        D_0051858C.field_0 = 5;
    }
    float t1 = D_004E0C68 * (float)p0->field_30;
    float t0 = D_004E0C64 * (float)p0->field_31;
    D_00665EF0.field_0 = t1;
    D_00665EF4.field_0 = t0;
    func_0028AC80(D_01E75640, D_004E0C6C * (float)p0->field_34);
    func_003F8890(D_01E7A888, D_004E0C6C * (float)p0->field_35);
    if (p0->field_39 != 0) {
        func_003F8870(D_01E7A888, 1);
    } else {
        func_003F8870(D_01E7A888, 0);
    }
    for (signed char i = 0; i < 2; i++) {
        int x = 1;
        x = p0->field_2C[i] ? x : 0;
        D_004EE040.field_8025[i] = x == 1;
    }
}

#pragma pop
