// CB3HUDPrimaryMessage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HUDPRIMARYMESSAGE_H
#define B3_CLASSES_CB3HUDPRIMARYMESSAGE_H

#include "b3/classes/CB3HUDPrimaryMessageHandler.h"
#include "b3/classes/EHUDMode.h"

class CB3HUDPrimaryMessage;

class CB3HUDPrimaryMessage {
public:
    void StartTransition(bool p0, EHUDMode p1, EHUDMode p2);
    void Update(float p0);
    void UpdateCrashText(float);
    void UpdateMessage(float);

    unsigned char pad_0[0x34];
    float field_34;
    int field_38;
    unsigned char pad_3C[0x4];
    CB3HUDPrimaryMessageHandler field_40;
    unsigned char pad_41[0xB];
    int field_4C;
};

#endif
