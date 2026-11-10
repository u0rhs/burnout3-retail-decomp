// CB3OnScreenKeyboardComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONSCREENKEYBOARDCOMPONENT_H
#define B3_CLASSES_CB3ONSCREENKEYBOARDCOMPONENT_H

#include "b3/GtMath.h"

#include "b3/classes/EGlobalStrings.h"

class CB3OnScreenKeyboardComponent;

class CB3OnScreenKeyboardComponent {
public:
    void RegisterKeyboardCallbacks();
    void SetAllowableCharacters(EGlobalStrings);
    void Show(bool, bool);
    void UnRegisterKeyboardCallbacks();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
