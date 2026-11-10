// CB3StageLogic -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3STAGELOGIC_H
#define B3_CLASSES_CB3STAGELOGIC_H

#include "b3/GtMath.h"

class CB3RaceCarPhysics;
class CB3StageLogic;

class CB3StageLogic {
public:
    int AllResultsAreIn();
    int AssignStartPositionIndex(int p0);
    int GetNumRoundsPlayed();
    int IsCrashType();
    void OnPostCrashReset(CB3RaceCarPhysics*);
    void OnWorldPrepared();

    unsigned char pad_0[0x1];
};

#endif
