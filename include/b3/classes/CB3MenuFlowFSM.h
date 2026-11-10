// CB3MenuFlowFSM -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MENUFLOWFSM_H
#define B3_CLASSES_CB3MENUFLOWFSM_H

#include "b3/GtMath.h"

#include "b3/classes/CGtFSM.h"

class CB3MenuFlowFSM;

class CB3MenuFlowFSM : public CGtFSM {
public:
    void ApplyEvent(unsigned int p0, void* p1);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
