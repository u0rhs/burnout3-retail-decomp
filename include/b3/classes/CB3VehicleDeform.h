// CB3VehicleDeform -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3VEHICLEDEFORM_H
#define B3_CLASSES_CB3VEHICLEDEFORM_H

#include "b3/GtMathPs2.h"

class CB3VehicleDeform;
struct UnkStruct_00461440_e0;

struct UnkStruct_00461440_e0 {
    GtMathPs2::CGtV4d field_0;
    unsigned char pad_10[0x20];
};

class CB3VehicleDeform {
public:
    void Construct();
    GtMathPs2::CGtV3d GetWindscreenPos(bool, bool);

    int field_0;
    int field_4;
    unsigned char pad_8[0xC];
    int field_14;
    int field_18;
    unsigned char pad_1C[0x28];
    unsigned char field_44;
    unsigned char pad_45[0x4B];
    UnkStruct_00461440_e0 field_90[1];  // [G] element count unknown
};

#endif
