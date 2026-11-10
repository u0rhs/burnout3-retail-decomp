// UnkStruct_D_004E2FCC -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_004E2FCC_H
#define B3_CLASSES_UNKSTRUCT_D_004E2FCC_H

struct UnkStruct_00467580_3;
struct UnkStruct_D_004E2FCC;

struct UnkStruct_00467580_3 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    unsigned char pad_20[0x18];
    int field_38;
};

struct UnkStruct_D_004E2FCC {
    UnkStruct_00467580_3 * field_0;
};

#endif
