// Hand-written; the lifter refused it (a100: UnlockAll body; 15 explicit 1000 stores; tail = func_00139F20 inlined (memcpy intrinsic head)).

// D_0051BFA0 is one unlock-state object [L]: func_0013C4B0 clears exactly these arrays (67, 20, 73, 100, 36, 10, 10,
// 20, 10, 5, 3 bytes) and func_0013C400(&D_0051BFA0) reaches gCalculatedData at +0x164 [C: 0x51BFA0 + 0x164 = 0x51C104].
// gCalculatedData+0x11C (= D_0051BFA0+0x280) holds a copy of it. Each array is copied as a char-array struct (a90),
// the 67-byte head with the memcpy intrinsic (a100: the lq loop + lh/lbu tail through the advanced pointers).
struct UnkStruct_0051BFA0_43 { signed char b[20]; };
struct UnkStruct_0051BFA0_57 { signed char b[73]; };
struct UnkStruct_0051BFA0_A0 { signed char b[100]; };
struct UnkStruct_0051BFA0_104 { signed char b[36]; };
struct UnkStruct_0051BFA0_a10 { signed char b[10]; };
struct UnkStruct_0051BFA0_13C { signed char b[20]; };
struct UnkStruct_0051BFA0_15A { signed char b[5]; };
struct UnkStruct_0051BFA0_15F { unsigned char b[3]; };
struct UnkStruct_0051BFA0_ud {
    unsigned char field_0[67];
    UnkStruct_0051BFA0_43 field_43;
    UnkStruct_0051BFA0_57 field_57;
    UnkStruct_0051BFA0_A0 field_A0;
    UnkStruct_0051BFA0_104 field_104;
    UnkStruct_0051BFA0_a10 field_128;
    UnkStruct_0051BFA0_a10 field_132;
    UnkStruct_0051BFA0_13C field_13C;
    UnkStruct_0051BFA0_a10 field_150;
    UnkStruct_0051BFA0_15A field_15A;
    UnkStruct_0051BFA0_15F field_15F;
};
struct UnkStruct_gCalculatedData_0051BFA0 {
    unsigned char pad_0[0x1C];
    int field_1C;
    unsigned char pad_20[0x8];
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    unsigned char pad_38[0xD8];
    int field_110;
    unsigned char pad_114[0x8];
    UnkStruct_0051BFA0_ud field_11C;
};
class CB3Profile {
public:
    unsigned char pad_0[0x154];
    int field_154[7];
    int field_170[36];
    int field_200;
    unsigned char pad_204[0x8];
    float field_20C[36];
    int field_29C;
    float field_2A0[36];
    int field_330;
    unsigned char pad_334[0x10];
    int field_344[15];
    unsigned char pad_380[0x6];
    signed char field_386[73];
    unsigned char field_3CF[100];
    unsigned char field_433[20];
    unsigned char field_447[10];
    unsigned char field_451[67];
    unsigned char field_494;
    unsigned char field_495;
};
extern UnkStruct_0051BFA0_ud D_0051BFA0;
extern UnkStruct_gCalculatedData_0051BFA0 gCalculatedData;

// func_00139F20's body (placeholder inline, [G] that the source inlined that function).
static inline void func_00139F20_inl1()
{
    __memcpy(gCalculatedData.field_11C.field_0, D_0051BFA0.field_0, 67);
    gCalculatedData.field_11C.field_43 = D_0051BFA0.field_43;
    gCalculatedData.field_11C.field_57 = D_0051BFA0.field_57;
    gCalculatedData.field_11C.field_A0 = D_0051BFA0.field_A0;
    gCalculatedData.field_11C.field_104 = D_0051BFA0.field_104;
    gCalculatedData.field_11C.field_128 = D_0051BFA0.field_128;
    gCalculatedData.field_11C.field_132 = D_0051BFA0.field_132;
    gCalculatedData.field_11C.field_13C = D_0051BFA0.field_13C;
    gCalculatedData.field_11C.field_150 = D_0051BFA0.field_150;
    gCalculatedData.field_11C.field_15A = D_0051BFA0.field_15A;
    gCalculatedData.field_11C.field_15F = D_0051BFA0.field_15F;
}

// 0x00139790
// Called by CB3ProfileManager::UnlockAll() with its profile [C: B3Profile_00136490]: unlocks everything, then the
// tail is func_00139F20's body inlined [C: identical code]. CB3Profile offsets as in EvaluateTrackUnlocking (field_386).
// The int-to-float 10000 is converted at run time (mtc1/cvt.s.w), so it is an int constant in the source.
extern "C" void func_00139790(CB3Profile * self)
{
    int i;
    for (i = 0; i < 73; i++) {
        D_0051BFA0.field_57.b[i] = 1;
        self->field_386[i] = 3;
    }
    gCalculatedData.field_30 = 73;
    self->field_494 = 72;
    for (i = 0; i < 100; i++) {
        D_0051BFA0.field_A0.b[i] = 1;
        self->field_3CF[i] = 3;
    }
    gCalculatedData.field_34 = 100;
    self->field_495 = 99;
    for (i = 0; i < 67; i++) {
        D_0051BFA0.field_0[i] = 1;
        self->field_451[i] = 1;
    }
    gCalculatedData.field_28 = 67;
    for (i = 0; i < 10; i++) {
        self->field_447[i] = 1;
    }
    gCalculatedData.field_110 = 10;
    for (i = 0; i < 20; i++) {
        D_0051BFA0.field_43.b[i] = 1;
    }
    gCalculatedData.field_2C = 20;
    for (i = 0; i < 20; i++) {
        self->field_433[i] = 1;
    }
    gCalculatedData.field_1C = 20;
    for (i = 0; i < 20; i++) {
        D_0051BFA0.field_43.b[i] = 1;
    }
    for (i = 0; i < 36; i++) {
        self->field_170[i] = 1000;
        self->field_20C[i] = 10000;
        self->field_2A0[i] = 10000;
    }
    for (i = 0; i < 7; i++) {
        self->field_154[i] = 1000;
    }
    self->field_200 = 1000;
    self->field_344[0] = 1000;
    self->field_344[1] = 1000;
    self->field_344[2] = 1000;
    self->field_344[3] = 1000;
    self->field_344[4] = 1000;
    self->field_344[5] = 1000;
    self->field_344[6] = 1000;
    self->field_344[7] = 1000;
    self->field_344[8] = 1000;
    self->field_344[9] = 1000;
    self->field_344[10] = 1000;
    self->field_344[11] = 1000;
    self->field_344[12] = 1000;
    self->field_344[13] = 1000;
    self->field_344[14] = 1000;
    self->field_29C = 0;
    self->field_330 = 0;
    func_00139F20_inl1();
}
