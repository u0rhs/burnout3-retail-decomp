// CB3HUDComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3HUDCOMPONENT_H
#define B3_CLASSES_CB3HUDCOMPONENT_H

#include "b3/GtMath.h"

#include "b3/classes/EHUDMode.h"

class CB3HUDComponent;
class CB3HUDManager;

class CB3HUDComponent {
public:
    void Construct(CB3HUDManager* p0);
    void StartTransition(bool p0, EHUDMode p1, EHUDMode p2);
    void Update();

    unsigned char pad_0[0x4];
    CB3HUDManager * field_4;
    unsigned char pad_8[0x4];
    int field_C;
};

#endif
