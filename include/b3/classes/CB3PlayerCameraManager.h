// CB3PlayerCameraManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3PLAYERCAMERAMANAGER_H
#define B3_CLASSES_CB3PLAYERCAMERAMANAGER_H

#include "b3/GtMath.h"

#include "b3/classes/CGtFSM.h"

class CB3PlayerCameraManager;
class CGtStateOffset;
class CGtTimer;

class CB3PlayerCameraManager : public CGtFSM {
public:
    static int meLoadState;
    static int mgpCameraBuffer;
    void ActivateBehaviour(int);
    void Construct(void* p0, const CGtStateOffset* p1, CGtTimer* p2);
    bool HasIntroFinished();
    void ReleaseBuffer();
    void Update();

    unsigned char pad_0[0x1];
};

#endif
