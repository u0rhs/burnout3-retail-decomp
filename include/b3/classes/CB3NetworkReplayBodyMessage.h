// CB3NetworkReplayBodyMessage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3NETWORKREPLAYBODYMESSAGE_H
#define B3_CLASSES_CB3NETWORKREPLAYBODYMESSAGE_H

#include "b3/GtMath.h"

class CB3NetworkReplayBodyMessage;

class CB3NetworkReplayBodyMessage {
public:
    void Prepare(const unsigned char* p0, int p1, int p2);
    int Retrieve(unsigned char* p0);

    unsigned char field_0;
    unsigned char pad_1[0xF];
    int field_10;
    int field_14;
};

#endif
