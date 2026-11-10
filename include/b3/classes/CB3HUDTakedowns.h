// CB3HUDTakedowns -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HUDTAKEDOWNS_H
#define B3_CLASSES_CB3HUDTAKEDOWNS_H

class CB3HUDTakedowns;
struct UnkStruct_003A2510_1;

struct UnkStruct_003A2510_1 {
    unsigned char pad_0[0x68];
    int field_68;
};

class CB3HUDTakedowns {
public:
    void PrepareTakedownsObjects();
    void Update(float p0);

    unsigned char pad_0[0x34];
    UnkStruct_003A2510_1 * field_34;
    int field_38;
    int field_3C;
    float field_40;
    unsigned char pad_44[0x50];
    unsigned char field_94;
    unsigned char field_95;
    unsigned char pad_96[0x2];
    int field_98;
};

#endif
