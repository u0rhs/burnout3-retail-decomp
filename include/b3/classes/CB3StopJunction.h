// CB3StopJunction -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3STOPJUNCTION_H
#define B3_CLASSES_CB3STOPJUNCTION_H

class CB3StopJunction;
struct CB3StopJunctionStruct;

class CB3StopJunction {
public:
    int Prepare(CB3StopJunctionStruct* p0);

    CB3StopJunctionStruct * field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char field_10[1];  // [G] element count unknown
    unsigned char pad_11[0x3];
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char field_1B;
    unsigned char field_1C;
};

#endif
