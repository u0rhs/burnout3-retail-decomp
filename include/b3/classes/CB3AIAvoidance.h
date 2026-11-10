// CB3AIAvoidance -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3AIAVOIDANCE_H
#define B3_CLASSES_CB3AIAVOIDANCE_H

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

class CB3AIAvoidance;
struct UnkStruct_001418F0_1;

struct UnkStruct_001418F0_1 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

class CB3AIAvoidance {
public:
    void Construct();
    int Prepare();
    void Release();

    unsigned char pad_0[0x460];
    GtMathPs2::CGtV3d field_460;
    GtMathPs2::CGtV3d field_470;
    int field_480;
    float field_484;
    int field_488;
    int field_48C;
    int field_490;
    int field_494;
    int field_498;
    int field_49C;
    unsigned char pad_4A0[0x4];
    UnkStruct_001418F0_1 * field_4A4;
    unsigned char pad_4A8[0x4];
    unsigned char field_4AC;
    unsigned char field_4AD;
    unsigned char field_4AE;
    unsigned char field_4AF;
};

#endif
