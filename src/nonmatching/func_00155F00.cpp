// NONMATCHING: func_00155F00 -- retail 96 / ours 97 instructions, 3 in changed runs
// 6->3: UnkEnum_00155F00 local with if(==0) v=1 else v=0 gives retail's index diamond; left: retail hoists lui/lw D_0051BA88 above bnez p0 (ours tests first). Moving the load into an inner block fixes that but changes the return-0 block layout (6)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_00155F00 -- retail 96 / ours 97 instructions, 6 in changed runs
// 6 instrs: (1) index 0/1 from p1->field_19AC: retail branches bnez->v=0 / fallthrough b+li 1; every if/else/ternary form is if-converted (sltiu), a one-case switch keeps branches but inverts them. (2) retail hoists lui/lw D_0051BA88 above the bnez p0 test; ours tests p0 first. Tail/layout and swaps match.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// lifter variant 0
// func_00155F00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00155F00;
struct UnkStruct_00155F00_10;
struct UnkStruct_00155F00_11;
struct UnkStruct_00155F00_12;
struct UnkStruct_00155F00_13;
struct UnkStruct_00155F00_14;
struct UnkStruct_00155F00_15;
struct UnkStruct_00155F00_1;
struct UnkStruct_00155F00_2;
struct UnkStruct_00155F00_6;
struct UnkStruct_00155F00_7;
struct UnkStruct_00155F00_9;
struct UnkStruct_00155F00_a2;
struct UnkStruct_D_0051BA88;

struct UnkStruct_D_0051BA88 {
    UnkStruct_00155F00_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00155F00_1 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00155F00_2 * field_1B4;
};

struct UnkStruct_00155F00_2 {
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
    virtual int vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual int vfunc_A8();
    unsigned char pad_4[0x2];
    unsigned char field_6;
    unsigned char pad_7[0x6C];
    unsigned char field_73;
};

struct UnkStruct_00155F00_a2 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_00155F00_6 {
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
    virtual int vfunc_9C();
};

struct UnkStruct_00155F00 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x78];
    int field_84;
    unsigned char pad_88[0x4];
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char field_95;
    unsigned char pad_96[0x2];
    int field_98;
};

struct UnkStruct_00155F00_7 {
    unsigned char pad_0[0x16C0];
    UnkStruct_00155F00 field_16C0;
};
struct UnkStruct_00155F00_7_old {
    unsigned char pad_0[0x16C8];
    int field_16C8;
    unsigned char pad_16CC[0x78];
    int field_1744;
    unsigned char pad_1748[0x4];
    int field_174C;
    int field_1750;
    unsigned char field_1754;
    unsigned char field_1755;
    unsigned char pad_1756[0x2];
    int field_1758;
};

struct UnkStruct_00155F00_9 {
    unsigned char pad_0[0x6];
    unsigned char field_6;
};

struct UnkStruct_00155F00_10 {
    unsigned char pad_0[0x6];
    unsigned char field_6;
};

struct UnkStruct_00155F00_11 {
    unsigned char pad_0[0x6];
    unsigned char field_6;
};

struct UnkStruct_00155F00_12 {
    unsigned char pad_0[0x6];
    unsigned char field_6;
};

struct UnkStruct_00155F00_13 {
    unsigned char pad_0[0x73];
    unsigned char field_73;
};

struct UnkStruct_00155F00_14 {
    unsigned char pad_0[0x6];
    unsigned char field_6;
};

struct UnkStruct_00155F00_15 {
    unsigned char pad_0[0x6];
    unsigned char field_6;
};


extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_00155F00_7 * D_0064D388[];  // [G] element count unknown

enum UnkEnum_00155F00 { UnkEnum_00155F00_0 = 0, UnkEnum_00155F00_1 = 1 };
// 0x00155F00
extern "C" int func_00155F00(UnkStruct_00155F00 * self, int p0, UnkStruct_00155F00_a2 * p1)
{
    if (D_0051BA88.field_0->field_1B4->vfunc_A8() == 0) return 0;
    UnkEnum_00155F00 v;
    if (p1->field_19AC == 0) v = UnkEnum_00155F00_1; else v = UnkEnum_00155F00_0;
    UnkStruct_00155F00 *o = &D_0064D388[v]->field_16C0;
    if (D_0051BA88.field_0->field_1B4->vfunc_9C() == 4 && p0 == 0 && D_0051BA88.field_0->field_1B4->field_73 == 0) return 0;
    if (o->field_8 != 0 && (self->field_95 != 0 || o->field_95 != 0)) {
    { int t = self->field_84; self->field_84 = o->field_84; o->field_84 = t; } { int t = self->field_90; self->field_90 = o->field_90; o->field_90 = t; } { unsigned char t = self->field_94; self->field_94 = o->field_94; o->field_94 = t; } { int t = self->field_8C; self->field_8C = o->field_8C; o->field_8C = t; } { int t = self->field_98; self->field_98 = o->field_98; o->field_98 = t; } { unsigned char t = self->field_95; self->field_95 = o->field_95; o->field_95 = t; }
        D_0051BA88.field_0->field_1B4->field_6 = 1;
        return 1;
    }
    return 0;
}
