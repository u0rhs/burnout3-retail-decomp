// CB3SoundRaceCarManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDRACECARMANAGER_H
#define B3_CLASSES_CB3SOUNDRACECARMANAGER_H

#include "b3/GtMath.h"

#include "b3/classes/EB3RaceCarType.h"

class CB3SoundRaceCar;
class CB3SoundRaceCarManager;

class CB3SoundRaceCarManager {
public:
    void Destruct();
    int Prepare();
    void Release();
    void RelinquishRaceCar(CB3SoundRaceCar* p0);
    int RequestRaceCar(EB3RaceCarType);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
