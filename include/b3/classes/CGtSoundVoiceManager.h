// CGtSoundVoiceManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDVOICEMANAGER_H
#define B3_CLASSES_CGTSOUNDVOICEMANAGER_H

#include "b3/GtMath.h"

class CGtSoundRealVoice;
class CGtSoundVirtualVoice;
class CGtSoundVoiceManager;
struct UnkStruct_00388F20_e1;

struct UnkStruct_00388F20_e1 {
    unsigned char pad_0[0x33];
    unsigned char field_33;
};

class CGtSoundVoiceManager {
public:
    void * AllocVirtualVoice();
    void Destruct();
    void FreeRealVoice(CGtSoundRealVoice* p0);
    void FreeVirtualVoice(CGtSoundVirtualVoice* p0);

    UnkStruct_00388F20_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_34[0x1D10];
    unsigned char field_1D44[1];  // [G] element count unknown
    unsigned char pad_1D45[0xF3];
    int field_1E38;
};

#endif
