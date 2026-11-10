// CB3DebrisArray -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3DEBRISARRAY_H
#define B3_CLASSES_CB3DEBRISARRAY_H

class CB3DebrisArray;
struct UnkStruct_002F4940_e0;

struct UnkStruct_002F4940_e0 {
    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0xC];
};

class CB3DebrisArray {
public:
    void Destruct();
    int Prepare();
    void Release();

    unsigned char pad_0[0x14];
    UnkStruct_002F4940_e0 * field_14;
    int field_18;
    int field_1C;
};

#endif
