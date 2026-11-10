// UnkStruct_D_004CE2E2 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_004CE2E2_H
#define B3_CLASSES_UNKSTRUCT_D_004CE2E2_H

struct UnkStruct_003F5940_e2;
struct UnkStruct_D_004CE2E2;

struct UnkStruct_003F5940_e2 {
    short field_0;
    unsigned char pad_2[0x4];
};

struct UnkStruct_D_004CE2E2 {
    UnkStruct_003F5940_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_6[0xA];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
