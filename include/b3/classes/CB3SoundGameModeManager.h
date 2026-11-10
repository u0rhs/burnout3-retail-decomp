// CB3SoundGameModeManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDGAMEMODEMANAGER_H
#define B3_CLASSES_CB3SOUNDGAMEMODEMANAGER_H

#include "b3/GtMath.h"

#include "b3/classes/CB3SoundRaceCarManager.h"

class CB3SoundGameModeManager;

class CB3SoundGameModeManager {
public:
    void Destruct();
    void TriggerSpotDucker(float p0);
    void Update();

    unsigned char pad_0[0xC];
    float field_C;
    CB3SoundRaceCarManager field_10;
};

#endif
