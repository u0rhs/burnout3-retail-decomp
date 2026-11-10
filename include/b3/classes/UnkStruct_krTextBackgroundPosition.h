// UnkStruct_krTextBackgroundPosition -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_UNKSTRUCT_KRTEXTBACKGROUNDPOSITION_H
#define B3_CLASSES_UNKSTRUCT_KRTEXTBACKGROUNDPOSITION_H

#include "b3/GtMath.h"

struct UnkStruct_krTextBackgroundPosition;

struct UnkStruct_krTextBackgroundPosition {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

#endif
