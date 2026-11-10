// CB3ErrorPage -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3ERRORPAGE_H
#define B3_CLASSES_CB3ERRORPAGE_H

#include "b3/GtMath.h"

#include "b3/classes/EB3MessageBoxType.h"
#include "b3/classes/EGlobalStrings.h"

class CB3ErrorPage;

class CB3ErrorPage {
public:
    int Prepare(EGlobalStrings p0, EGlobalStrings p1, EB3MessageBoxType p2);
    void Release();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
