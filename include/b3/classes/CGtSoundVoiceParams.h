// CGtSoundVoiceParams -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDVOICEPARAMS_H
#define B3_CLASSES_CGTSOUNDVOICEPARAMS_H

#include "b3/GtMath.h"

class CGtSoundVoiceParams;

class CGtSoundVoiceParams {
public:
    void Construct();

    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    float field_1C;
    float field_20;
    float field_24;
    int field_28;
    unsigned char pad_2C[0x8];
    int field_34;
    float field_38;
    float field_3C;
    int field_40;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
};

#endif
