// CB3OnlineJoinGamePage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINEJOINGAMEPAGE_H
#define B3_CLASSES_CB3ONLINEJOINGAMEPAGE_H

#include "b3/GtMath.h"

class CB3OnlineJoinGamePage;

class CB3OnlineJoinGamePage {
public:
    void OnKeyboardCancel();
    void OnKeyboardDone();
    void OnKeyboardShow();
    void Release();

    unsigned char pad_0[0x1274];
    int field_1274;
    unsigned char pad_1278[0x880];
    unsigned short field_1AF8;
    unsigned char pad_1AFA[0x1B];
    signed char field_1B15;
};

#endif
