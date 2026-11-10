// CB3SunRenderer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SUNRENDERER_H
#define B3_CLASSES_CB3SUNRENDERER_H

#include "b3/GtMath.h"

class CB3SunRenderer;

class CB3SunRenderer {
public:
    static int mpCoronaTexture;
    static int mpEnvmapCoronaTexture;
    void Construct();
    void Release();
    void RenderEnvmap();
    void RenderEnvmapCorona();
    static void Destruct();
    static void RenderEnvmapBlob();

    unsigned char pad_0[0x1];
};

#endif
