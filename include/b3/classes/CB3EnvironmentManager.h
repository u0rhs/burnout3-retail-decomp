// CB3EnvironmentManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ENVIRONMENTMANAGER_H
#define B3_CLASSES_CB3ENVIRONMENTMANAGER_H

#include "b3/GtMath.h"

class CB3EnvironmentManager;

class CB3EnvironmentManager {
public:
    void BeginRender(int p0);
    void Destruct();
    void RenderSunCorona();

    unsigned char pad_0[0x130];
    int field_130;
    unsigned char pad_134[0x8];
    unsigned char field_13C;
    unsigned char pad_13D[0x3];
    int field_140;
    unsigned char pad_144[0x8];
    unsigned char field_14C;
};

#endif
