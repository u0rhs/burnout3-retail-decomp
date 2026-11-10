// CB3GraphicsManagerBase -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3GRAPHICSMANAGERBASE_H
#define B3_CLASSES_CB3GRAPHICSMANAGERBASE_H

#include "b3/classes/EB3ViewportSelection.h"

class CB3GraphicsManagerBase;
class CGtCamera;

class CB3GraphicsManagerBase {
public:
    void AttachCameraToViewport(EB3ViewportSelection p0, CGtCamera* p1);

    unsigned char pad_0[0x1];
};

#endif
