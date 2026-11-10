// CB3CoronaDynamicArray -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CORONADYNAMICARRAY_H
#define B3_CLASSES_CB3CORONADYNAMICARRAY_H

class CB3CoronaDynamicArray;
struct UnkStruct_00307500_e1;
struct UnkStruct_00307500_e3;

struct UnkStruct_00307500_e1 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

struct UnkStruct_00307500_e3 {
    unsigned char pad_0[0x20];
};

class CB3CoronaDynamicArray {
public:
    void BeginUpdate(int p0);
    void Construct(int p0);
    void ConstructDMAData(int, int, int);
    void Destruct();

    unsigned char pad_0[0x10];
    UnkStruct_00307500_e1 field_10[1];  // [G] element count unknown
    unsigned char pad_18[0x8];
    UnkStruct_00307500_e3 * field_20;
    int field_24;
    short field_28;
    short field_2A[1];  // [G] element count unknown
    unsigned char pad_2C[0x2];
    signed char field_2E[1];  // [G] element count unknown
    unsigned char pad_2F[0x1];
    signed char field_30;
};

#endif
