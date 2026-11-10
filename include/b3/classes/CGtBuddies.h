// CGtBuddies -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTBUDDIES_H
#define B3_CLASSES_CGTBUDDIES_H

#include "b3/GtMath.h"

class CGtBuddies;

class CGtBuddies {
public:
    int Prepare();
    void SetPresenceDetail(char* p0, char* p1, char* p2);

    unsigned char pad_0[0xCB];
    unsigned char field_CB;
    unsigned char field_CC;
    unsigned char pad_CD[0x3];
    int field_D0;
    int field_D4;
    unsigned char pad_D8[0x8];
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    unsigned char pad_F8[0x8];
    int field_100;
    int field_104;
    unsigned char pad_108[0x8];
    int field_110;
    int field_114;
};

#endif
