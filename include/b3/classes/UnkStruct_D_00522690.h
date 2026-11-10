// UnkStruct_D_00522690 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_00522690_H
#define B3_CLASSES_UNKSTRUCT_D_00522690_H

struct UnkStruct_00148CA0_lane;
struct UnkStruct_00148CA0_seg;
struct UnkStruct_D_00522690;

struct UnkStruct_00148CA0_lane {
    unsigned char pad_0[0x8];
    UnkStruct_00148CA0_seg * field_8;
    unsigned short field_C;
    unsigned char field_E;
};

struct UnkStruct_00148CA0_seg {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

struct UnkStruct_D_00522690 {
    UnkStruct_00148CA0_lane * field_0;
    int field_4;
};

#endif
