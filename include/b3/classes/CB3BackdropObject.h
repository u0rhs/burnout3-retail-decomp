// CB3BackdropObject -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BACKDROPOBJECT_H
#define B3_CLASSES_CB3BACKDROPOBJECT_H

#include "b3/GtMath.h"

struct CB3BackdropObject;
struct UnkStruct_00332D00_e0;

struct UnkStruct_00332D00_e0 {
    unsigned char pad_0[0x50];
};

struct CB3BackdropObject {
    short field_0;
    unsigned char pad_2[0x2];
    UnkStruct_00332D00_e0 * field_4;
};

#endif
