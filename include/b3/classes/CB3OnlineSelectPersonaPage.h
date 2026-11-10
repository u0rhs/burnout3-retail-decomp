// CB3OnlineSelectPersonaPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINESELECTPERSONAPAGE_H
#define B3_CLASSES_CB3ONLINESELECTPERSONAPAGE_H

#include "b3/GtMath.h"

class CB3OnlineSelectPersonaPage;

class CB3OnlineSelectPersonaPage {
public:
    void OnKeyboardCancel();
    void OnKeyboardShow();
    void Prepare(char*);
    void Release();

    unsigned char pad_0[0x8C];
    int field_8C;
};

#endif
