// CB3EffectsManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3EFFECTSMANAGER_H
#define B3_CLASSES_CB3EFFECTSMANAGER_H

#include "b3/classes/CB3TrailSystem.h"

class CB3EffectsManager;
struct UnkStruct_00262660_e0;

struct UnkStruct_00262660_e0 {
    unsigned char pad_0[0x30];
};

class CB3EffectsManager {
public:
    void Release();

    UnkStruct_00262660_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_30[0x25D0];
    CB3TrailSystem field_2600;
};

#endif
