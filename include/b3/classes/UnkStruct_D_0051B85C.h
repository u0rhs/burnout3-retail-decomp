// UnkStruct_D_0051B85C -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_0051B85C_H
#define B3_CLASSES_UNKSTRUCT_D_0051B85C_H

struct UnkStruct_0023B6A0_2;
struct UnkStruct_D_0051B85C;

struct UnkStruct_0023B6A0_2 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_0051B85C {
    UnkStruct_0023B6A0_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
