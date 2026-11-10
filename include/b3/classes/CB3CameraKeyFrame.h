// CB3CameraKeyFrame -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CAMERAKEYFRAME_H
#define B3_CLASSES_CB3CAMERAKEYFRAME_H

#include "b3/GtMath.h"

class CB3CameraKeyFrame;

class CB3CameraKeyFrame {
public:
    int GetEventPause();
    int GetEventRecord();
    bool GetIsSetup();
    unsigned char GetRaceCarIndex();
    int GetTypeBehaviour();
    int GetTypeTransition();

    unsigned char pad_0[0x14];
    int field_14;
    unsigned char field_18;
};

#endif
