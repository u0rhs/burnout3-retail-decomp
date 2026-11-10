// UnkStruct_D_004E2FC4 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_004E2FC4_H
#define B3_CLASSES_UNKSTRUCT_D_004E2FC4_H

struct UnkStruct_00465910_1;
struct UnkStruct_D_004E2FC4;

struct UnkStruct_00465910_1 {
    unsigned char pad_0[0xD0];
    int field_D0;
    unsigned char pad_D4[0x8];
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    unsigned char pad_EC[0x4];
    int field_F0;
    int field_F4[1];  // [G] element count unknown
    unsigned char pad_F8[0x8];
    void * field_100;
    void * field_104;
    unsigned char pad_108[0x3C];
    int field_144;
    int field_148;
    int field_14C;
};

struct UnkStruct_D_004E2FC4 {
    UnkStruct_00465910_1 * field_0;
};

#endif
