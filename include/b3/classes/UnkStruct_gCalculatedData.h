// UnkStruct_gCalculatedData -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_GCALCULATEDDATA_H
#define B3_CLASSES_UNKSTRUCT_GCALCULATEDDATA_H

#include "b3/GtMath.h"

struct UnkStruct_gCalculatedData;

struct UnkStruct_gCalculatedData {
    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
    int field_C;
    unsigned char pad_10[0xC];
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    unsigned char pad_38[0x4];
    int field_3C;
    unsigned char pad_40[0x4C];
    int field_8C;
    int field_90;
    int field_94;
    unsigned char pad_98[0x78];
    int field_110;
};

#endif
