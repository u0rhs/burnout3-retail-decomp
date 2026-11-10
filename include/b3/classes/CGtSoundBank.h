// CGtSoundBank -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDBANK_H
#define B3_CLASSES_CGTSOUNDBANK_H

#include "b3/GtMath.h"

class CGtSoundBank;
struct UnkStruct_00383C10_e0;

struct UnkStruct_00383C10_e0 {
    unsigned char pad_0[0x10];
};

class CGtSoundBank {
public:
    void Destruct();
    unsigned char GetReferenceCount();
    unsigned char IsGlobal();
    void SetReferenceCount(int p0);
    void Unload();

    UnkStruct_00383C10_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0x388];
    int field_398;
    int field_39C;
    unsigned char pad_3A0[0x4];
    int field_3A4;
    unsigned char field_3A8;
    signed char field_3A9;
    unsigned char field_3AA;
};

#endif
