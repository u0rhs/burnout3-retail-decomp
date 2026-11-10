// Hand-written; the lifter refused it (a100: unlock-state copy; 67-byte head via the memcpy intrinsic (__memcpy), 3 trailing bytes as one unsigned char[3] struct).

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
    unsigned char pad_0[0x11C];
    UnkStruct_0051BFA0_ud field_11C;
};
class CB3Profile;
extern UnkStruct_0051BFA0_ud D_0051BFA0;
extern UnkStruct_gCalculatedData_0051BFA0 gCalculatedData;

// 0x00139F20
// [G] the parameter is unused here; callers (func_003F4A80, B3MyBurnoutPage) pass the profile pointer.
// __memcpy: MWCC's memcpy intrinsic (inlined at -O4), [G] that the source called memcpy for this array.
extern "C" void func_00139F20(CB3Profile * self)
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
