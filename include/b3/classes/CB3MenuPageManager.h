// CB3MenuPageManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MENUPAGEMANAGER_H
#define B3_CLASSES_CB3MENUPAGEMANAGER_H

#include "b3/classes/EB3MenuFlowFSMEvents.h"

class CB3MenuPageManager;

class CB3MenuPageManager {
public:
    void StartLeadOutFore(EB3MenuFlowFSMEvents p0, bool p1);

    unsigned char pad_0[0x1DC];
    float field_1DC;
    unsigned char pad_1E0[0x4];
    int field_1E4;
    int field_1E8;
    int field_1EC;
    unsigned char pad_1F0[0x180F];
    bool field_19FF;
};

#endif
