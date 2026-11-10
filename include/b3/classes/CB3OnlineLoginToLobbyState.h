// CB3OnlineLoginToLobbyState -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ONLINELOGINTOLOBBYSTATE_H
#define B3_CLASSES_CB3ONLINELOGINTOLOBBYSTATE_H

#include "b3/GtMath.h"

#include "b3/classes/EB3MenuFlowFSMEvents.h"

class CB3OnlineLoginToLobbyState;

class CB3OnlineLoginToLobbyState {
public:
    void HandleLoggingIntoServerEvents(EB3MenuFlowFSMEvents p0);

    unsigned char pad_0[0xAC];
    unsigned char field_AC;
    unsigned char pad_AD[0x3];
    int field_B0;
    int field_B4;
};

#endif
