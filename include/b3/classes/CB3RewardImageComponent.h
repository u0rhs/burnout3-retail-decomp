// CB3RewardImageComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3REWARDIMAGECOMPONENT_H
#define B3_CLASSES_CB3REWARDIMAGECOMPONENT_H

#include "b3/GtMath.h"

class CB3RewardImageComponent;

class CB3RewardImageComponent {
public:
    void Construct();

    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[0x4];
    int field_18;
};

#endif
