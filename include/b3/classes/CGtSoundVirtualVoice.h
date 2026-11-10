// CGtSoundVirtualVoice -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDVIRTUALVOICE_H
#define B3_CLASSES_CGTSOUNDVIRTUALVOICE_H

#include "b3/GtMath.h"

class CGtSoundVirtualVoice;
class CGtSoundVoiceParams;
struct UnkStruct_00387980_1;

struct UnkStruct_00387980_1 {
    unsigned char pad_0[0x8A];
    unsigned char field_8A;
};

class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
    void IgnoreGlobalPitch();
    bool IsPlaying();
    void Start(const CGtSoundVoiceParams*);
    void Stop();

    unsigned char field_0;
    unsigned char pad_1[0x3];
    UnkStruct_00387980_1 * field_4;
    unsigned char pad_8[0x14];
    float field_1C;
    float field_20;
    unsigned char pad_24[0x8];
    unsigned char field_2C;
    unsigned char pad_2D[0x2];
    unsigned char field_2F;
};

#endif
