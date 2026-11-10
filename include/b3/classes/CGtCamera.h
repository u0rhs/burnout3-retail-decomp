// CGtCamera -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTCAMERA_H
#define B3_CLASSES_CGTCAMERA_H

class CGtCamera;
class CGtCameraBehaviourDef;

class CGtCamera {
public:
    void Construct();
    void Destruct();
    void SetBehaviours(CGtCameraBehaviourDef* p0, int p1);

    unsigned char pad_0[0x30];
    void * field_30;
    CGtCameraBehaviourDef * field_34;
    int field_38;
    unsigned char field_3C;
};

#endif
