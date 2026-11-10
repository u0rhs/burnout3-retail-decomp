// CGtInputDevicePS2DualShock -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTINPUTDEVICEPS2DUALSHOCK_H
#define B3_CLASSES_CGTINPUTDEVICEPS2DUALSHOCK_H

#include "b3/GtMath.h"

class CGtInputDevicePS2DualShock;

class CGtInputDevicePS2DualShock {
public:
    int GetPort();
    unsigned char IsConnected();
    int Prepare();
    void UnbindFromPort();

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
    unsigned char pad_9[0x1];
    unsigned char field_A[1];  // [G] element count unknown
    unsigned char pad_B[0x1B];
    unsigned char field_26[1];  // [G] element count unknown
    unsigned char pad_27[0x1B];
    unsigned char field_42;
    unsigned char field_43;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x1];
    int field_48[1];  // [G] element count unknown
    unsigned char pad_4C[0x98];
    int field_E4;
    int field_E8;
};

#endif
