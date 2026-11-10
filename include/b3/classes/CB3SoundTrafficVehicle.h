// CB3SoundTrafficVehicle -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDTRAFFICVEHICLE_H
#define B3_CLASSES_CB3SOUNDTRAFFICVEHICLE_H

#include "b3/GtMath.h"

#include "b3/classes/CB3SoundTrafficPass.h"

class CB3SoundTrafficVehicle;
class CGtSoundVirtualVoice;

class CB3SoundTrafficVehicle {
public:
    void Deactivate();
    int GetID();
    signed char GetPlayerIndex() const;
    bool IsHorning();
    int Prepare();
    void Release();

    int field_0;
    unsigned char pad_4[0xC];
    CB3SoundTrafficPass field_10;
    unsigned char pad_11[0xAF];
    CGtSoundVirtualVoice * field_C0;
    CGtSoundVirtualVoice * field_C4;
    CGtSoundVirtualVoice * field_C8;
    unsigned char pad_CC[0x34];
    float field_100;
    float field_104;
    float field_108;
    float field_10C;
    int field_110;
    unsigned char pad_114[0xC];
    int field_120;
    unsigned char field_124;
    unsigned char pad_125[0x7];
    signed char field_12C;
};

#endif
