// UnkStruct_D_004CBF04 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_004CBF04_H
#define B3_CLASSES_UNKSTRUCT_D_004CBF04_H

struct UnkStruct_003E9690_e1;
struct UnkStruct_D_004CBF04;

struct UnkStruct_003E9690_e1 {
    int field_0;
    unsigned char pad_4[0x8];
};

struct UnkStruct_D_004CBF04 {
    UnkStruct_003E9690_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_C[0x4];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
