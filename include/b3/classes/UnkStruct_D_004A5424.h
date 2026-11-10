// UnkStruct_D_004A5424 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_004A5424_H
#define B3_CLASSES_UNKSTRUCT_D_004A5424_H

struct UnkStruct_003EA4C0_e1;
struct UnkStruct_D_004A5424;

struct UnkStruct_003EA4C0_e1 {
    int field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_D_004A5424 {
    UnkStruct_003EA4C0_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
