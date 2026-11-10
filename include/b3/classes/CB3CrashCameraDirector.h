// CB3CrashCameraDirector -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CRASHCAMERADIRECTOR_H
#define B3_CLASSES_CB3CRASHCAMERADIRECTOR_H

#include "b3/GtMath.h"

class CB3CrashCameraDirector;

class CB3CrashCameraDirector {
public:
    void Destruct();
    int Prepare(bool p0);

    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
    int field_20;
    unsigned char pad_24[0x8];
    int field_2C;
    unsigned char field_30;
    bool field_31;
    unsigned char pad_32[0x1];
    unsigned char field_33;
};

#endif
