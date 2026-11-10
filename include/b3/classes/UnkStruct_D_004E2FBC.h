// UnkStruct_D_004E2FBC -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_004E2FBC_H
#define B3_CLASSES_UNKSTRUCT_D_004E2FBC_H

struct UnkStruct_00464700_1;
struct UnkStruct_D_004E2FBC;

struct UnkStruct_00464700_1 {
    unsigned char pad_0[0x74];
    int field_74;
    int field_78;
    unsigned char pad_7C[0x18];
    int field_94;
    int field_98;
};

struct UnkStruct_D_004E2FBC {
    UnkStruct_00464700_1 * field_0;
};

#endif
