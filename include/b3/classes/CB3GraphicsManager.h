// CB3GraphicsManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3GRAPHICSMANAGER_H
#define B3_CLASSES_CB3GRAPHICSMANAGER_H

#include "b3/GtMath.h"

class CB3GraphicsManager;
class RwSkyVideoMode;

class CB3GraphicsManager {
public:
    void OpenRenderWare();
    void SetVideoModeParams(RwSkyVideoMode*);

    unsigned char pad_0[0x420];
    int field_420;
    unsigned char pad_424[0x8];
    int field_42C;
};

#endif
