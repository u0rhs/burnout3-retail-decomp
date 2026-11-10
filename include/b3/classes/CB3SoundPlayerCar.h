// CB3SoundPlayerCar -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDPLAYERCAR_H
#define B3_CLASSES_CB3SOUNDPLAYERCAR_H

#include "b3/GtMath.h"

class CB3SoundPlayerCar;

class CB3SoundPlayerCar {
public:
    void Unregister();

    unsigned char pad_0[0x68];
    int field_68;
    unsigned char pad_6C[0x53];
    unsigned char field_BF;
};

#endif
