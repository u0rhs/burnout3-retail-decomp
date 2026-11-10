// CB3CrashScore -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CRASHSCORE_H
#define B3_CLASSES_CB3CRASHSCORE_H

#include "b3/classes/ECrashModePickupType.h"

class CB3CrashScore;
struct UnkStruct_003CCE90_e1;

struct UnkStruct_003CCE90_e1 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x10];
};

class CB3CrashScore {
public:
    void AddCrashScore(ECrashModePickupType p0, int p1);

    unsigned char pad_0[0x438];
    UnkStruct_003CCE90_e1 field_438[1];  // [G] element count unknown
    unsigned char pad_44C[0xA6];
    unsigned char field_4F2[1];  // [G] element count unknown
};

#endif
