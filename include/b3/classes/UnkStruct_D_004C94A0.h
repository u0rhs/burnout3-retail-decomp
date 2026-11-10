// UnkStruct_D_004C94A0 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_004C94A0_H
#define B3_CLASSES_UNKSTRUCT_D_004C94A0_H

struct UnkStruct_00382BE0_e0;
struct UnkStruct_D_004C94A0;

struct UnkStruct_00382BE0_e0 {
    float field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_D_004C94A0 {
    UnkStruct_00382BE0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
