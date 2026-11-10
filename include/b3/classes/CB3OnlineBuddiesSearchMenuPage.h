// CB3OnlineBuddiesSearchMenuPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINEBUDDIESSEARCHMENUPAGE_H
#define B3_CLASSES_CB3ONLINEBUDDIESSEARCHMENUPAGE_H

#include "b3/GtMath.h"

class CB3OnlineBuddiesSearchMenuPage;

class CB3OnlineBuddiesSearchMenuPage {
public:
    void OnKeyboardCancel();
    void OnKeyboardShow();
    void Release();

    unsigned char pad_0[0x28];
    int field_28;
};

#endif
