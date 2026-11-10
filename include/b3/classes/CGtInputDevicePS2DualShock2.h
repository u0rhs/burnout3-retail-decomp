// CGtInputDevicePS2DualShock2 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTINPUTDEVICEPS2DUALSHOCK2_H
#define B3_CLASSES_CGTINPUTDEVICEPS2DUALSHOCK2_H

#include "b3/GtMath.h"

class CGtInputDevicePS2DualShock2;

class CGtInputDevicePS2DualShock2 {
public:
    int Prepare();

    unsigned char pad_0[0x4];
    int field_4;
};

#endif
