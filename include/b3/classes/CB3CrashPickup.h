// CB3CrashPickup -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CRASHPICKUP_H
#define B3_CLASSES_CB3CRASHPICKUP_H

#include "b3/GtMath.h"

class CB3CrashPickup;

class CB3CrashPickup {
public:
    void Construct();

    int field_0;
    unsigned char pad_4[0x4];
    unsigned char field_8;
    unsigned char field_9;
    signed char field_A;
};

#endif
