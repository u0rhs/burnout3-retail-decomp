// CB3TrafficLight -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICLIGHT_H
#define B3_CLASSES_CB3TRAFFICLIGHT_H

class CB3TrafficLight;
class CB3TrafficLightPositionStruct;
struct UnkStruct_00265C60_1;

struct UnkStruct_00265C60_1 {
    float field_0;
};

class CB3TrafficLight {
public:
    int Prepare(CB3TrafficLightPositionStruct* p0);
    void UseNewTimingsData(float p0);

    CB3TrafficLightPositionStruct * field_0;
    UnkStruct_00265C60_1 * field_4;
    float field_8;
    float field_C;
    unsigned char field_10[1];  // [G] element count unknown
    unsigned char pad_11[0x3];
    unsigned char field_14;
};

#endif
