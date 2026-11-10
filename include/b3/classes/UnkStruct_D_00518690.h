// UnkStruct_D_00518690 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_00518690_H
#define B3_CLASSES_UNKSTRUCT_D_00518690_H

struct UnkStruct_003EA580_1;
struct UnkStruct_003EA580_2;
struct UnkStruct_003EA580_5;
struct UnkStruct_003EA580_e0;
struct UnkStruct_003EA580_e1;
struct UnkStruct_D_00518690;

struct UnkStruct_003EA580_1 {
    unsigned char pad_0[0x4];
    UnkStruct_003EA580_2 * field_4;
};

struct UnkStruct_003EA580_2 {
    UnkStruct_003EA580_e0 * field_0;
    int field_4;
};

struct UnkStruct_003EA580_5 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
};

struct UnkStruct_003EA580_e0 {
    unsigned char pad_0[0x10];
    UnkStruct_003EA580_e1 * field_10;
    int field_14;
};

struct UnkStruct_003EA580_e1 {
    unsigned char pad_0[0x34];
    UnkStruct_003EA580_5 * field_34;
    int field_38;
    unsigned char pad_3C[0x4];
};

struct UnkStruct_D_00518690 {
    UnkStruct_003EA580_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
