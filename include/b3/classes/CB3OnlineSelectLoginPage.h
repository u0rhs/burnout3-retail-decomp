// CB3OnlineSelectLoginPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINESELECTLOGINPAGE_H
#define B3_CLASSES_CB3ONLINESELECTLOGINPAGE_H

#include "b3/GtMath.h"

class CB3OnlineSelectLoginPage;

class CB3OnlineSelectLoginPage {
public:
    void OnKeyboardCancel();
    void OnKeyboardShow();
    int Prepare();
    void PrepareExistingAccountControls();
    void UpdateRequestingAccountPassword();

    unsigned char pad_0[0x68];
    unsigned char field_68;
    unsigned char pad_69[0x7];
    unsigned char field_70;
    unsigned char field_71;
    unsigned char field_72;
    unsigned char pad_73[0x7D];
    short field_F0;
    short field_F2;
    int field_F4;
    unsigned char pad_F8[0x64];
    int field_15C;
    int field_160;
    int field_164;
};

#endif
