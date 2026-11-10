// CB3TrafficParam -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICPARAM_H
#define B3_CLASSES_CB3TRAFFICPARAM_H

#include "b3/GtMath.h"

class CB3TrafficParam;

class CB3TrafficParam {
public:
    void Remove();
    void RemoveFromTrafficLights();
    void ResetMemberVariables();

    int field_0;
    int field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    unsigned short field_3C;
    unsigned short field_3E;
    unsigned char field_40;
    unsigned char field_41;
    unsigned char field_42;
    unsigned char field_43;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char field_47;
    unsigned char field_48;
    unsigned char pad_49[0x1];
    unsigned char field_4A;
    unsigned char field_4B;
    unsigned char field_4C;
    unsigned char field_4D;
};

#endif
