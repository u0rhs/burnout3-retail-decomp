// func_00389E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (merged || guard, default first, ternaries, slti-at compares written > 1).

// func_00389E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00389E00_1;
struct UnkStruct_00389E00_2;
struct UnkStruct_00389E00_5;
struct UnkStruct_D_0051B930;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0064D3A0;
struct UnkStruct_D_0064D3A4;

struct UnkStruct_D_0051BA88 {
    UnkStruct_00389E00_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00389E00_1 {
    unsigned char pad_0[0x1B8];
    UnkStruct_00389E00_2 * field_1B8;
};

struct UnkStruct_00389E00_2 {
    unsigned char pad_0[0x4];
    int field_4;
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B930 {
    UnkStruct_00389E00_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00389E00_5 {
    unsigned char pad_0[0x38];
    int field_38;
};

struct UnkStruct_D_0064D3A4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_0051B930 D_0051B930;
extern UnkStruct_D_0064D3A4 D_0064D3A4;

// 0x00389E00
extern "C" int func_00389E00()
{
    if (D_0051BA88.field_0->field_1B8 == 0 || D_0051BA88.field_0->field_1B8->field_4 == 2) {
        return 7;
    }
    switch (D_0051BA88.field_0->field_1B8->field_4) {
    default:
        return 7;
    case 0:
        return D_0064D3A0.field_0 > 1 ? 11 : 7;
    case 1:
        if (D_0051B930.field_0->field_38 > 1) {
            return 5;
        }
        return D_0064D3A4.field_0 == 1 ? 3 : 0;
    }
}
