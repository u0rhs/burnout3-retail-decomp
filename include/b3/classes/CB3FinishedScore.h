// CB3FinishedScore -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3FINISHEDSCORE_H
#define B3_CLASSES_CB3FINISHEDSCORE_H

#include "b3/GtMath.h"

class CB3FinishedScore;

class CB3FinishedScore {
public:
    int Prepare(int p0);

    short field_0;
    short field_2;
    unsigned char pad_4[0x4];
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    float field_1C[1];  // [G] element count unknown
    unsigned char pad_20[0x1C];
    float field_3C;
    int field_40;
    int field_44;
    float field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    unsigned char field_94;
    unsigned char field_95;
    unsigned char pad_96[0x2];
    int field_98;
    int field_9C;
    unsigned char field_A0;
    unsigned char field_A1;
    unsigned char field_A2;
    unsigned char pad_A3[0x9];
    int field_AC[1];  // [G] element count unknown
    unsigned char pad_B0[0xC];
    int field_BC[1];  // [G] element count unknown
};

#endif
