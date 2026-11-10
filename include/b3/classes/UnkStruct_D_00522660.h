// UnkStruct_D_00522660 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_D_00522660_H
#define B3_CLASSES_UNKSTRUCT_D_00522660_H

#include "b3/GtMath.h"

struct UnkStruct_00267520_e3;
struct UnkStruct_0038BE40_4;
struct UnkStruct_D_00522660;

struct UnkStruct_00267520_e3 {
    unsigned char pad_0[0x4C];
};

struct UnkStruct_0038BE40_4 {
    unsigned char pad_0[0x1384];
    int field_1384;
    unsigned char pad_1388[0x8];
    float field_1390;
};

struct UnkStruct_D_00522660 {
    UnkStruct_00267520_e3 field_0[1];  // [G] element count unknown
    unsigned char pad_4C[0x12ACDC];
    UnkStruct_0038BE40_4 * field_12AD28[1];  // [G] element count unknown
};

#endif
