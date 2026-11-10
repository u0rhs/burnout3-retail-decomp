// CB3SoundDistortion -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDDISTORTION_H
#define B3_CLASSES_CB3SOUNDDISTORTION_H

class CB3SoundDistortion;
struct UnkStruct_002FCF00_1;
struct UnkStruct_002FCF00_2;

struct UnkStruct_002FCF00_1 {
    int field_0;
};

struct UnkStruct_002FCF00_2 {
    int field_0;
};

class CB3SoundDistortion {
public:
    void SetChannels(int p0);
    void StartDistortion();
    void StopDistortion();

    unsigned char pad_0[0x184C];
    unsigned char field_184C;
    unsigned char pad_184D[0x83];
    int field_18D0;
    unsigned char pad_18D4[0x42C];
    UnkStruct_002FCF00_2 * field_1D00;
    UnkStruct_002FCF00_1 * field_1D04;
    unsigned char pad_1D08[0x8];
    unsigned char field_1D10[0x28];
};

#endif
