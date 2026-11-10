// CGtSoundBankManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDBANKMANAGER_H
#define B3_CLASSES_CGTSOUNDBANKMANAGER_H

#include "b3/GtMath.h"

class CGtSoundBank;
class CGtSoundBankManager;

class CGtSoundBankManager {
public:
    void Destruct();
    int LoadBank(const char*, bool, bool, int);
    void UnloadBank(CGtSoundBank*);
    void Update();

    int field_0;
    unsigned char pad_4[0x34];
    int field_38;
};

#endif
