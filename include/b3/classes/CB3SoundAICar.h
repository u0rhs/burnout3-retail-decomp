// CB3SoundAICar -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDAICAR_H
#define B3_CLASSES_CB3SOUNDAICAR_H

#include "b3/GtMath.h"

class CB3SoundAICar;
class CGtSoundVirtualVoice;

class CB3SoundAICar {
public:
    void Construct();
    void Destruct();
    void Release();
    void Unregister();

    unsigned char pad_0[0x68];
    int field_68;
    unsigned char pad_6C[0x53];
    unsigned char field_BF;
    unsigned char pad_C0[0x80];
    int field_140;
    int field_144;
    unsigned char pad_148[0x8];
    CGtSoundVirtualVoice * field_150;
    CGtSoundVirtualVoice * field_154;
    int field_158;
    int field_15C;
};

#endif
