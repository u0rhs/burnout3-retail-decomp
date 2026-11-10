// CB3AILaneStruct -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3AILANESTRUCT_H
#define B3_CLASSES_CB3AILANESTRUCT_H

struct CB3AILaneStruct;
struct UnkStruct_00148C20_seg;

struct UnkStruct_00148C20_seg {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

struct CB3AILaneStruct {
    unsigned char pad_0[0x8];
    UnkStruct_00148C20_seg * field_8;
    unsigned short field_C;
    unsigned char field_E;
};

#endif
