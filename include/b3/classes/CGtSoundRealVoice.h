// CGtSoundRealVoice -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDREALVOICE_H
#define B3_CLASSES_CGTSOUNDREALVOICE_H

#include "b3/GtMath.h"

class CGtSoundRealVoice;
struct UnkStruct_00385680_1;
struct UnkStruct_00385680_2;

struct UnkStruct_00385680_1 {
    unsigned char pad_0[0x30];
    UnkStruct_00385680_2 * field_30;
};

struct UnkStruct_00385680_2 {
    int field_0;
};

class CGtSoundRealVoice {
public:
    void IgnoreGlobalPitch();
    void MuteDryVoice(int p0, bool p1);
    void Stop();

    unsigned char pad_0[0x14];
    UnkStruct_00385680_1 * field_14;
    unsigned char field_18;
    unsigned char pad_19[0x2];
    unsigned char field_1B;
};

#endif
