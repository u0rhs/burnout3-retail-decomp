// CB3NetworkReplayHeaderMessage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3NETWORKREPLAYHEADERMESSAGE_H
#define B3_CLASSES_CB3NETWORKREPLAYHEADERMESSAGE_H

#include "b3/GtMath.h"

class CB3NetworkReplayHeaderMessage;
class CB3ReplayFileHeader;

class CB3NetworkReplayHeaderMessage {
public:
    int Retrieve(CB3ReplayFileHeader* p0);

    unsigned char field_0;
};

#endif
