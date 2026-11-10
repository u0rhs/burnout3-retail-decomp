// CGtSoundManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDMANAGER_H
#define B3_CLASSES_CGTSOUNDMANAGER_H

#include "b3/GtMath.h"

#include "b3/classes/CGtSoundBankManager.h"
#include "b3/classes/CGtSoundListenerManager.h"
#include "b3/classes/CGtSoundStreamManager.h"
#include "b3/classes/CGtSoundVoiceManager.h"

class CGtSoundManager;

class CGtSoundManager {
public:
    void Destruct();
    void Pause();
    void StopAll();
    void Unpause();

    unsigned char pad_0[0x8];
    CGtSoundBankManager field_8;
    unsigned char pad_44[0x4];
    CGtSoundListenerManager field_48;
    unsigned char pad_4C[0x10];
    CGtSoundVoiceManager field_5C;
    unsigned char pad_1E98[0x8];
    CGtSoundStreamManager field_1EA0;
    unsigned char pad_1EBC[0x25];
    unsigned char field_1EE1;
};

#endif
