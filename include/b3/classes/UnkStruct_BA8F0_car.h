// UnkStruct_BA8F0_car -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_BA8F0_CAR_H
#define B3_CLASSES_UNKSTRUCT_BA8F0_CAR_H

#include "b3/GtMath.h"

struct UnkStruct_BA8F0_car;

struct UnkStruct_BA8F0_car {
    unsigned char pad_0[0x16C0];
    short field_16C0;
    unsigned char pad_16C2[0x252];
    int field_1914;
};

#endif
