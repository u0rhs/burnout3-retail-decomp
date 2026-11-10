// UnkStruct_D_0051A86C -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_0051A86C_H
#define B3_CLASSES_UNKSTRUCT_D_0051A86C_H

struct UnkStruct_0030CE20_1;
struct UnkStruct_D_0051A86C;

struct UnkStruct_0030CE20_1 {
    unsigned char pad_0[0x260];
    int field_260;
    unsigned char pad_264[0x17C];
    unsigned char field_3E0[1];  // [G] element count unknown
};

struct UnkStruct_D_0051A86C {
    UnkStruct_0030CE20_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
