// CB3SkyDomeRenderer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SKYDOMERENDERER_H
#define B3_CLASSES_CB3SKYDOMERENDERER_H

#include "b3/GtMath.h"

class CB3SkyDomeRenderer;

class CB3SkyDomeRenderer {
public:
    static int mePrepareState;
    static unsigned char mbTexturesUploaded;
    static unsigned long mu64OldFrame_1;
    void Destruct();
    void Release();
    void RestoreRenderTarget();

    unsigned char pad_0[0x1];
};

#endif
