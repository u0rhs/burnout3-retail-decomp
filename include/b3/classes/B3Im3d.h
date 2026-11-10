// B3Im3d -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_B3IM3D_H
#define B3_CLASSES_B3IM3D_H

#include "b3/GtMath.h"

class B3Im3d;

class B3Im3d {
public:
    static unsigned char _gbBFC;
    static unsigned char _gbConstructed;
    int Construct();
    void SetBackfaceCull(bool p0);
    static void EndRendering();
    static void SetZWrite(bool);

    unsigned char pad_0[0x1];
};

#endif
