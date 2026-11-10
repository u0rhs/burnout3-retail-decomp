// CB3VehicleRenderer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3VEHICLERENDERER_H
#define B3_CLASSES_CB3VEHICLERENDERER_H

class CB3VehicleRenderer;

class CB3VehicleRenderer {
public:
    void Construct();
    void Destruct();
    int Prepare();

    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    unsigned char field_18;
    unsigned char pad_19[0xE7];
    int field_100;
};

#endif
