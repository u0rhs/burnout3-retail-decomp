// CB3SoundDSPDataBlock -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDDSPDATABLOCK_H
#define B3_CLASSES_CB3SOUNDDSPDATABLOCK_H

class CB3SoundDSPDataBlock;

class CB3SoundDSPDataBlock {
public:
    void CalculateHighShelfCoefficients(float, float, float);
    void Construct();
    void Reset();

    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x30];
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    unsigned char pad_4C[0x1C];
    short field_68;
    short field_6A;
    short field_6C;
    short field_6E;
    int field_70;
};

#endif
