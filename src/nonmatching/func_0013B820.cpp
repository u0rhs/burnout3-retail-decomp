// NONMATCHING: func_0013B820 -- retail 593 / ours 593 instructions, 416 in changed runs
// a100: 593/593 instrs, 416 changed, all inside the memberwise save of gCalculatedData 0x0..0x113 to +0x3F0 (0x270-0x6E8). Same root cause as func_00138D60: retail gives field_4's load the third byte copy's register (t2), so it waits for that store; ours picks a free register and hoists it. Tried inline pointer copy, non-POD struct, temp copy.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

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
struct UnkStruct_gCalculatedData_hd {
    int field_0;
    int field_4;
    float field_8;
    int field_C;
    float field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    int field_50;
    float field_54;
    float field_58;
    float field_5C;
    float field_60;
    int field_64;
    float field_68;
    float field_6C;
    float field_70;
    float field_74;
    int field_78;
    float field_7C;
    float field_80;
    float field_84;
    float field_88;
    int field_8C;
    int field_90;
    int field_94;
    float field_98;
    float field_9C;
    float field_A0;
    float field_A4;
    int field_A8;
    float field_AC;
    float field_B0;
    float field_B4;
    float field_B8;
    int field_BC;
    float field_C0;
    float field_C4;
    float field_C8;
    float field_CC;
    int field_D0;
    float field_D4;
    float field_D8;
    float field_DC;
    float field_E0;
    int field_E4;
    float field_E8;
    float field_EC;
    float field_F0;
    float field_F4;
    int field_F8;
    float field_FC;
    float field_100;
    float field_104;
    float field_108;
    int field_10C;
    int field_110;
};
struct UnkStruct_gCalculatedData_0051BFA0 {
    UnkStruct_gCalculatedData_hd field_0;
    unsigned char pad_114[0x8];
    UnkStruct_0051BFA0_ud field_11C;
    unsigned char pad_27E[0xE];
    UnkStruct_0051BFA0_ud field_28C;
    unsigned char pad_3EE[0x2];
    UnkStruct_gCalculatedData_hd field_3F0;
};
class CB3Profile {
public:
    void Evaluate();
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
    signed char field_3CF[100];
    unsigned char field_433[20];
    unsigned char field_447[10];
    unsigned char field_451[67];
    signed char field_494;
    signed char field_495;
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

extern "C" int func_0013C620(CB3Profile *);
extern "C" int func_0013C400(UnkStruct_0051BFA0_ud *);
extern "C" int func_0013C4B0(UnkStruct_0051BFA0_ud *);
extern unsigned char D_0051C610[];
extern int D_004E26A4;

// 0x0013B820
// Resets the profile (func_0013C620) and unlock state, saves the unlock state and gCalculatedData 0x0..0x113 to the
// copies at gCalculatedData+0x28C / +0x3F0, evaluates the profile, then func_00139F20's body inlined [C: identical code].
extern "C" int func_0013B820(CB3Profile * self)
{
    func_0013C620(self);
    for (int i = 0; i < 20; i++) {
        D_0051C610[i] = 0;
    }
    func_0013C400(&D_0051BFA0);
    func_0013C4B0(&gCalculatedData.field_11C);
    __memcpy(gCalculatedData.field_28C.field_0, D_0051BFA0.field_0, 67);
    gCalculatedData.field_28C.field_43 = D_0051BFA0.field_43;
    gCalculatedData.field_28C.field_57 = D_0051BFA0.field_57;
    gCalculatedData.field_28C.field_A0 = D_0051BFA0.field_A0;
    gCalculatedData.field_28C.field_104 = D_0051BFA0.field_104;
    gCalculatedData.field_28C.field_128 = D_0051BFA0.field_128;
    gCalculatedData.field_28C.field_132 = D_0051BFA0.field_132;
    gCalculatedData.field_28C.field_13C = D_0051BFA0.field_13C;
    gCalculatedData.field_28C.field_150 = D_0051BFA0.field_150;
    gCalculatedData.field_28C.field_15A = D_0051BFA0.field_15A;
    gCalculatedData.field_28C.field_15F = D_0051BFA0.field_15F;
    gCalculatedData.field_3F0 = gCalculatedData.field_0;
    self->Evaluate();
    func_00139F20_inl1();
    D_004E26A4++;
    return 1;
}
