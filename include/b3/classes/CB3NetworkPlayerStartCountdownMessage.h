// CB3NetworkPlayerStartCountdownMessage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3NETWORKPLAYERSTARTCOUNTDOWNMESSAGE_H
#define B3_CLASSES_CB3NETWORKPLAYERSTARTCOUNTDOWNMESSAGE_H

class CB3NetworkPlayerStartCountdownMessage;

class CB3NetworkPlayerStartCountdownMessage {
public:
    int Retrieve(int* p0, float* p1, int* p2);

    unsigned char field_0;
    unsigned char pad_1[0xF];
    int field_10;
    float field_14;
    int field_18[1];  // [G] element count unknown
};

#endif
