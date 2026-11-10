// CB3HullWorldTriCollideParams -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HULLWORLDTRICOLLIDEPARAMS_H
#define B3_CLASSES_CB3HULLWORLDTRICOLLIDEPARAMS_H

#include "b3/GtMathPs2.h"

struct CB3HullWorldTriCollideParams;
struct UnkStruct_002B9470_2;

struct UnkStruct_002B9470_2 {
    u_long128 field_0;
    u_long128 field_10;
    GtMathPs2::CGtV3d field_20;
    u_long128 field_30;
};

struct CB3HullWorldTriCollideParams {
    unsigned char pad_0[0x70];
    u_long128 field_70;
    u_long128 field_80;
    u_long128 field_90;
    u_long128 field_A0;
    unsigned char pad_B0[0x90];
    u_long128 field_140;
    unsigned char pad_150[0xB0];
    int field_200;
    UnkStruct_002B9470_2 * field_204;
    int field_208;
    unsigned char pad_20C[0x8];
    unsigned char field_214;
};

#endif
