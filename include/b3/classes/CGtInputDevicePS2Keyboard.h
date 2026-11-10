// CGtInputDevicePS2Keyboard -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTINPUTDEVICEPS2KEYBOARD_H
#define B3_CLASSES_CGTINPUTDEVICEPS2KEYBOARD_H

#include "b3/classes/EGtVirtualKeyCodes.h"

class CGtInputDevicePS2Keyboard;

class CGtInputDevicePS2Keyboard {
public:
    bool IsControlPressed(EGtVirtualKeyCodes p0);

    unsigned char pad_0[0x1A];
    unsigned char field_1A[1];  // [G] element count unknown
};

#endif
