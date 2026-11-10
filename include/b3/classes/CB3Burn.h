// CB3Burn -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BURN_H
#define B3_CLASSES_CB3BURN_H

#include "b3/GtMath.h"

class CB3Burn;

class CB3Burn {
public:
    void Construct();
    void Release();
    void RemoveBurn(float p0);
    void RemoveSegment();
    void SetInfiniteBoost(bool);
    void StopBurn();

    unsigned char pad_0[0x38];
    float field_38;
    unsigned char pad_3C[0xC];
    float field_48;
    unsigned char pad_4C[0x4];
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char field_53;
    unsigned char pad_54[0x1];
    unsigned char field_55;
};

#endif
