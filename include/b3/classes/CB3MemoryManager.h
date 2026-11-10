// CB3MemoryManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MEMORYMANAGER_H
#define B3_CLASSES_CB3MEMORYMANAGER_H

#include "b3/classes/EB3MemoryLayout.h"

class CB3MemoryManager;

class CB3MemoryManager {
public:
    int AcquireMemoryLayout(EB3MemoryLayout p0);

    unsigned char pad_0[0x984];
    int field_984;
    int field_988;
};

#endif
