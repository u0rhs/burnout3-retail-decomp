// CB3SoundManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDMANAGER_H
#define B3_CLASSES_CB3SOUNDMANAGER_H

#include "b3/GtMath.h"

class CB3SoundManager;

class CB3SoundManager {
public:
    void CloseRenderWare();
    int GetSpeakerConfig();
    void OpenRenderWare();
    void SetMasterPitchScalar(float p0);

    unsigned char pad_0[0x1ED8];
    int field_1ED8;
    unsigned char pad_1EDC[0x4];
    unsigned char field_1EE0;
    unsigned char pad_1EE1[0x532B];
    int field_720C;
};

#endif
