// func_00430000 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (const ptr to D_0064EA70 hoisted; v2 init before call; id locals assigned before field stores in each arm; b declared before a).

// func_00430000 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00430000;
struct UnkStruct_00430000_3;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0064D370;
struct UnkStruct_D_0064EA70;
struct UnkStruct_D_01EA7810;

struct UnkStruct_D_0064EA70 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x5C];
    int field_68;
    unsigned char pad_6C[0x8];
    int field_74;
};

struct UnkStruct_D_0064D370 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00430000_3 {
    unsigned char pad_0[0x114];
    int field_114;
};

struct UnkStruct_D_01EA7810 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00430000 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0x4F];
    unsigned char field_73;
    unsigned char field_74;
    unsigned char field_75;
    unsigned char pad_76[0x4E];
    int field_C4;
    unsigned char pad_C8[0x8];
    unsigned char field_D0;
};

extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_01EA7810 D_01EA7810;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" UnkStruct_00430000_3 * GetTrackRecords__10CB3RecordsFUl(void *, unsigned long);
extern "C" int func_00271A00(void *, int);

// 0x00430000
extern "C" void func_00430000(UnkStruct_00430000 * self)
{
    UnkStruct_D_0064EA70 * const g = &D_0064EA70;
    self->field_1C = 2;
    self->field_20 = 9;
    self->field_14 = 2504;
    self->field_73 = 0;
    self->field_74 = 0;
    self->field_75 = 0;
    int v0;
    switch (g->field_8) {
    case 4:
    case 5:
        v0 = 837;
        break;
    case 1:
        v0 = 824;
        break;
    default:
        v0 = 838;
        break;
    }
    int b;
    int a;
    if (self->field_D0 == 0) {
        int v2 = 0x7FFFFFFF;
        UnkStruct_00430000_3 * r0 = GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, D_0064D370.field_0);
        if (r0 != 0) {
            v2 = r0->field_114;
        }
        if (v2 < g->field_68) {
            b = 844;
            a = 846;
            self->field_C = 1;
        } else {
            b = 845;
            a = 847;
            self->field_C = 4;
        }
    } else {
        switch (g->field_74) {
        case 2:
            b = 839;
            a = 810;
            self->field_C = 1;
            self->field_C4 = 0;
            break;
        case 1:
            b = 840;
            a = 811;
            self->field_C = 2;
            self->field_C4 = 1;
            break;
        case 0:
            b = 841;
            a = 812;
            self->field_C = 3;
            self->field_C4 = 2;
            break;
        default:
            b = 842;
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
