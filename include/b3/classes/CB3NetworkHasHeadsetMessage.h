// CB3NetworkHasHeadsetMessage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3NETWORKHASHEADSETMESSAGE_H
#define B3_CLASSES_CB3NETWORKHASHEADSETMESSAGE_H

#include "b3/GtMath.h"

class CB3NetworkHasHeadsetMessage;

class CB3NetworkHasHeadsetMessage {
public:
    void Prepare(unsigned char p0);
    int Retrieve(unsigned char* p0);

    unsigned char field_0;
    unsigned char pad_1[0xF];
    unsigned char field_10;
};

#endif
