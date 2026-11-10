// UnkStruct_D_01D9C350 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_01D9C350_H
#define B3_CLASSES_UNKSTRUCT_D_01D9C350_H

#include "b3/GtMath.h"

struct UnkStruct_001B8B70_e8;
struct UnkStruct_D_01D9C350;

struct UnkStruct_001B8B70_e8 {
    unsigned char pad_0[0x1D0];
};

struct UnkStruct_D_01D9C350 {
    UnkStruct_001B8B70_e8 field_0[1];  // [G] element count unknown
    unsigned char pad_1D0[0x910];
    int field_AE0[1];  // [G] element count unknown
    unsigned char pad_AE4[0x14];
    int field_AF8[1];  // [G] element count unknown
};

#endif
