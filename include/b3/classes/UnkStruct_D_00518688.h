// UnkStruct_D_00518688 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_00518688_H
#define B3_CLASSES_UNKSTRUCT_D_00518688_H

struct UnkStruct_002FAD90_3;
struct UnkStruct_002FAD90_e0;
struct UnkStruct_D_00518688;

struct UnkStruct_002FAD90_3 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_002FAD90_e0 * field_C;
};

struct UnkStruct_002FAD90_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_D_00518688 {
    UnkStruct_002FAD90_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
