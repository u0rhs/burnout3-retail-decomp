// UnkStruct_D_004C9680 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_004C9680_H
#define B3_CLASSES_UNKSTRUCT_D_004C9680_H

struct UnkStruct_00382CF0_e3;
struct UnkStruct_D_004C9680;

struct UnkStruct_00382CF0_e3 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_004C9680 {
    UnkStruct_00382CF0_e3 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
