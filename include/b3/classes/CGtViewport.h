// CGtViewport -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTVIEWPORT_H
#define B3_CLASSES_CGTVIEWPORT_H

class CGtCamera;
class CGtViewport;
struct UnkStruct_00211DD0_1;

struct UnkStruct_00211DD0_1 {
    unsigned char pad_0[0x60];
    int field_60;
    int field_64;
};

class CGtViewport {
public:
    void Construct(int p0, int p1, int p2);
    int Prepare();
    void SetAspectRatio(float p0);
    void SetCamera(CGtCamera* p0);

    unsigned char pad_0[0x40];
    int field_40;
    int field_44;
    unsigned char pad_48[0x10];
    UnkStruct_00211DD0_1 * field_58;
    int field_5C;
    int field_60;
    int field_64;
    void * field_68;
    float field_6C;
    float field_70;
    float field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
};

#endif
