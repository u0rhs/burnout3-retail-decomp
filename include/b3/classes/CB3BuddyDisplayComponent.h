// CB3BuddyDisplayComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BUDDYDISPLAYCOMPONENT_H
#define B3_CLASSES_CB3BUDDYDISPLAYCOMPONENT_H

#include "b3/GtMath.h"

class CB3BuddyDisplayComponent;

class CB3BuddyDisplayComponent {
public:
    void Construct();
    bool GetSelectedBuddyName(char* p0);
    void MailSent(int);

    unsigned char pad_0[0xE6C];
    int field_E6C;
    int field_E70;
    unsigned char pad_E74[0x4];
    unsigned short field_E78;
    unsigned char pad_E7A[0x6];
    int field_E80;
};

#endif
