// UnkStruct_D_01EA5470 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_01EA5470_H
#define B3_CLASSES_UNKSTRUCT_D_01EA5470_H

#include "b3/GtMath.h"

struct UnkStruct_003BA5E0_e0;
struct UnkStruct_D_01EA5470;

struct UnkStruct_003BA5E0_e0 {
    unsigned char field_0;
    unsigned char pad_1[0x33];
    int field_34;
};

struct UnkStruct_D_01EA5470 {
    UnkStruct_003BA5E0_e0 field_0[1];  // [G] element count unknown
};

#endif
