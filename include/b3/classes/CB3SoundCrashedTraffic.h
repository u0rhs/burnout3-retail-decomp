// CB3SoundCrashedTraffic -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDCRASHEDTRAFFIC_H
#define B3_CLASSES_CB3SOUNDCRASHEDTRAFFIC_H

#include "b3/GtMath.h"

class CB3SoundCrashedTraffic;
class CB3VehiclePhysics;
class CGtSoundVirtualVoice;

class CB3SoundCrashedTraffic {
public:
    void Construct();
    bool Prepare();
    void SetActive();
    void SetOwner(CB3VehiclePhysics* p0);

    CB3VehiclePhysics * field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    CGtSoundVirtualVoice * field_18;
    int field_1C;
    float field_20;
    int field_24;
    unsigned char pad_28[0x8];
    float field_30;
    float field_34;
    int field_38;
    unsigned char pad_3C[0x8];
    int field_44;
    int field_48;
    CGtSoundVirtualVoice * field_4C;
    CGtSoundVirtualVoice * field_50;
    int field_54;
    int field_58;
};

#endif
