// CB3NetworkRaceReadyMessage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3NETWORKRACEREADYMESSAGE_H
#define B3_CLASSES_CB3NETWORKRACEREADYMESSAGE_H

#include "b3/GtMath.h"

#include "b3/classes/CB3NetworkMessage.h"

class CB3NetworkRaceReadyMessage;

class CB3NetworkRaceReadyMessage : public CB3NetworkMessage {
public:
    void Prepare();

    unsigned char pad_0[0x1];
};

#endif
