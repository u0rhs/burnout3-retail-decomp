// CGtNetworkHeadset -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTNETWORKHEADSET_H
#define B3_CLASSES_CGTNETWORKHEADSET_H

class CGtNetworkHeadset;

class CGtNetworkHeadset {
public:
    int GetIDOfTalkingNetworkPlayer(int*);
    float GetMaximumTalkTime();
    bool IsRequestingTalk();
    bool IsTalking();

    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x816C];
    float field_8178;
};

#endif
