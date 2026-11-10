// CB3HUD -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HUD_H
#define B3_CLASSES_CB3HUD_H

#include "b3/classes/EHUDMode.h"

class CB3HUD;
struct UnkStruct_001A03A0_m;

struct UnkStruct_001A03A0_m {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8(float);
    virtual void vfunc_C(bool, int, int, float);
    unsigned char pad_4[0x8];
    UnkStruct_001A03A0_m * field_C;
    unsigned char pad_10[0x4];
    int field_14;
};

class CB3HUD {
public:
    void SetHUDMode(EHUDMode p0);
    void Update(float p0);

    float field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0x54];
    UnkStruct_001A03A0_m * field_68;
};

#endif
