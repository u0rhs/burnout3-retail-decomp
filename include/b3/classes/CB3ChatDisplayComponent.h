// CB3ChatDisplayComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CHATDISPLAYCOMPONENT_H
#define B3_CLASSES_CB3CHATDISPLAYCOMPONENT_H

#include "b3/GtMath.h"

#include "b3/classes/EB3ChatDisplayOrientation.h"

class CB3ChatDisplayComponent;
struct UnkStruct_00332570_2;
struct UnkStruct_00332570_4;

struct UnkStruct_00332570_2 {
    short field_0;
};

struct UnkStruct_00332570_4 {
    short field_0;
};

class CB3ChatDisplayComponent {
public:
    void AddNewMessage(char*, const unsigned short*);
    void Construct();
    void Prepare(EB3ChatDisplayOrientation p0);
    void PrepareWithoutStrings(EB3ChatDisplayOrientation);
    void SetOrientation(EB3ChatDisplayOrientation);

    unsigned char pad_0[0x7F0];
    UnkStruct_00332570_2 * field_7F0[1];  // [G] element count unknown
    unsigned char pad_7F4[0x24];
    UnkStruct_00332570_4 * field_818[1];  // [G] element count unknown
    unsigned char pad_81C[0x44];
    int field_860;
    int field_864;
    int field_868;
};

#endif
