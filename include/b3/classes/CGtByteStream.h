// CGtByteStream -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTBYTESTREAM_H
#define B3_CLASSES_CGTBYTESTREAM_H

#include "b3/GtMath.h"

class CGtByteStream;

class CGtByteStream {
public:
    void Create(void*, int, int);
    void SetPosition(int);

    unsigned char pad_0[0x1];
};

#endif
