// CB3AICar -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3AICAR_H
#define B3_CLASSES_CB3AICAR_H

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

#include "b3/classes/CB3AIDriver.h"

class CB3AICar;
struct UnkStruct_00142350_2;

struct UnkStruct_00142350_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual int vfunc_8(unsigned long, int);
};

class CB3AICar {
public:
    float IncreaseAggression(float p0);
    int PrepareSound();
    void Release();
    void StopCrashing();

    unsigned char pad_0[0x1918];
    UnkStruct_00142350_2 * field_1918;
    unsigned char pad_191C[0x44];
    unsigned long field_1960;
    unsigned char pad_1968[0x44];
    signed char field_19AC;
    unsigned char pad_19AD[0x3];
    GtMathPs2::CGtV3d field_19B0;
    GtMathPs2::CGtV3d field_19C0;
    unsigned char pad_19D0[0x20];
    CB3AIDriver field_19F0;
    unsigned char pad_19F1[0x9DF];
    float field_23D0;
    unsigned char pad_23D4[0xC];
    float field_23E0;
    float field_23E4;
    unsigned char pad_23E8[0x6C];
    int field_2454;
};

#endif
