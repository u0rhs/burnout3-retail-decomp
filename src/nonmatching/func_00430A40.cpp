// NONMATCHING: func_00430A40 -- retail 115 / ours 115 instructions, 1 in changed runs
// pass3b: literal 4005 call arg fixes the li but v0 then takes s0 and g/a s1 (retail v0=s1, g/a=s0): all 5 b/v0/a declaration permutations keep it; v0 defined only per-branch, all-4005 switch/if on g->field_8 (field not in struct) not viable. Retail's call arg is a separate constant vreg from the compared s1 -- source shape unknown.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// s321: 115/115, 1 off (was 112/115, 42): sibling func_00430000 shape (int b; int v0 = 4005; int a; v0 re-assigned 4005 in the switch branch keeps the 'v0 < 4005' test unfolded in s1; float FLT_MAX default in f20). Left: retail's first call passes literal 4005 (li a1) where ours passes s1; a literal arg or per-branch defs shift regs (14) or sink the li (4). Tried 8 pragmas, inline const& forms, all decl orders

// s321: rewritten after the proven sibling func_00430000 (same page-text setup: id locals tested < 4005).
// func_00430A40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00430A40;
struct UnkStruct_00430A40_2;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0064D370;
struct UnkStruct_D_0064EA70;
struct UnkStruct_D_01EA7810;

struct UnkStruct_D_0064D370 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00430A40_2 {
    unsigned char pad_0[0x88];
    float field_88;
};

struct UnkStruct_D_0064EA70 {
    unsigned char pad_0[0x3C];
    float field_3C;
    unsigned char pad_40[0x30];
    int field_70;
};

struct UnkStruct_D_01EA7810 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00430A40 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0x4E];
    unsigned char field_72;
    unsigned char field_73;
    unsigned char pad_74[0x50];
    int field_C4;
    unsigned char pad_C8[0x8];
    unsigned char field_D0;
};

extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_01EA7810 D_01EA7810;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" UnkStruct_00430A40_2 * GetTrackRecords__10CB3RecordsFUl(void *, unsigned long);
extern "C" int func_00271A00(void *, int);

// 0x00430A40
extern "C" void func_00430A40(UnkStruct_00430A40 * self)
{
    UnkStruct_D_0064EA70 * const g = &D_0064EA70;
    self->field_1C = 13;
    self->field_20 = 1;
    self->field_72 = 0;
    self->field_73 = 0;
    int b;
    int v0 = 4005;
    int a;
    if (self->field_D0 == 0) {
        self->field_14 = 2502;
        float v2 = 3.4028235e+38f;
        UnkStruct_00430A40_2 * r0 = GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, D_0064D370.field_0);
        if (r0 != 0) {
            v2 = r0->field_88;
        }
        if (g->field_3C < v2) {
            b = 859;
            a = 861;
            self->field_C = 1;
        } else {
            b = 860;
            a = 862;
            self->field_C = 4;
        }
    } else {
        v0 = 4005;
        self->field_14 = 2503;
        switch (g->field_70) {
        case 2:
            b = 853;
            a = 810;
            self->field_C = 1;
            self->field_C4 = 0;
            break;
        case 1:
            b = 854;
            a = 811;
            self->field_C = 2;
            self->field_C4 = 1;
            break;
        case 0:
            b = 855;
            a = 812;
            self->field_C = 3;
            self->field_C4 = 2;
            break;
        default:
            b = 856;
            a = 813;
            self->field_C = 4;
            break;
        }
    }
    if (v0 < 4005) {
        self->field_0 = func_00271A00(&D_0051BA44, v0);
    }
    if (b < 4005) {
        self->field_4 = func_00271A00(&D_0051BA44, b);
    }
    if (a < 4005) {
        self->field_8 = func_00271A00(&D_0051BA44, a);
    }
}
