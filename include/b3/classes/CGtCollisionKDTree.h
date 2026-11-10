// CGtCollisionKDTree -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTCOLLISIONKDTREE_H
#define B3_CLASSES_CGTCOLLISIONKDTREE_H

class CGtCollisionKDTree;
struct UnkStruct_003BE8D0_e0;
struct UnkStruct_003BE8D0_e1;

struct UnkStruct_003BE8D0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_003BE8D0_e1 {
    unsigned char pad_0[0x10];
};

class CGtCollisionKDTree {
public:
    void FixUp();

    UnkStruct_003BE8D0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_1[0x1F];
    void * field_20;
    UnkStruct_003BE8D0_e1 * field_24;
    unsigned short field_28;
    unsigned char pad_2A[0x2];
    int field_2C;
};

#endif
