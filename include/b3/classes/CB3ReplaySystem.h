// CB3ReplaySystem -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3REPLAYSYSTEM_H
#define B3_CLASSES_CB3REPLAYSYSTEM_H

#include "b3/GtMath.h"

#include "b3/classes/CGtByteStream.h"

class CB3ReplaySystem;

class CB3ReplaySystem {
public:
    void Construct();
    void Destruct();
    int Prepare(bool p0);
    int UnpackHeader();

    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x54];
    CGtByteStream field_60;
    unsigned char pad_61[0x3];
    int field_64;
    unsigned char pad_68[0x4];
    int field_6C;
    unsigned char pad_70[0x8];
    int field_78;
    int field_7C;
    int field_80;
    bool field_84;
};

#endif
