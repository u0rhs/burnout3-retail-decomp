// CB3SoundScrape -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDSCRAPE_H
#define B3_CLASSES_CB3SOUNDSCRAPE_H

#include "b3/GtMath.h"

class CB3SoundScrape;
class CGtSoundVirtualVoice;

class CB3SoundScrape {
public:
    void Release();

    unsigned char pad_0[0x10];
    CGtSoundVirtualVoice * field_10;
    CGtSoundVirtualVoice * field_14;
    unsigned char pad_18[0x8];
    int field_20;
    int field_24;
};

#endif
