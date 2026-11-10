// CB3BoostEffectParams -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3BOOSTEFFECTPARAMS_H
#define B3_CLASSES_CB3BOOSTEFFECTPARAMS_H

#include "b3/GtMath.h"

class CB3BoostEffectParams;
class CB3Burn;

class CB3BoostEffectParams {
public:
    int Prepare(CB3Burn* p0);
    void Stop();

    CB3Burn * field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    unsigned char pad_18[0x8];
    int field_20;
};

#endif
