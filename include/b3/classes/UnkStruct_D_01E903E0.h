// UnkStruct_D_01E903E0 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_01E903E0_H
#define B3_CLASSES_UNKSTRUCT_D_01E903E0_H

struct UnkStruct_00332240_e0;
struct UnkStruct_D_01E903E0;

struct UnkStruct_00332240_e0 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x2C];
    UnkStruct_00332240_e0 * field_2C;
};

#endif
