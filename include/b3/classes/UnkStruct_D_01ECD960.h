// UnkStruct_D_01ECD960 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_01ECD960_H
#define B3_CLASSES_UNKSTRUCT_D_01ECD960_H

struct UnkStruct_003FF1D0_3;
struct UnkStruct_D_01ECD960;

struct UnkStruct_003FF1D0_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01ECD960 {
    UnkStruct_003FF1D0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
