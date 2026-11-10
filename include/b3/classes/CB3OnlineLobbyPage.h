// CB3OnlineLobbyPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINELOBBYPAGE_H
#define B3_CLASSES_CB3ONLINELOBBYPAGE_H

#include "b3/GtMath.h"

class CB3OnlineLobbyPage;

class CB3OnlineLobbyPage {
public:
    int ChatMessageCallback(char* p0, char* p1, void* p2);
    void HandleError(int p0);
    void OnKeyboardCancel();
    void OnKeyboardShow();
    void Release();

    unsigned char pad_0[0x13AC];
    signed char field_13AC;
};

#endif
