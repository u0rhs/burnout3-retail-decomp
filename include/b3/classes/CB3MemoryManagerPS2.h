// CB3MemoryManagerPS2 -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MEMORYMANAGERPS2_H
#define B3_CLASSES_CB3MEMORYMANAGERPS2_H

#include "b3/classes/CB3ManagedMemoryBlock.h"
#include "b3/classes/EB3MemoryBlock.h"

class CB3MemoryManagerPS2;

class CB3MemoryManagerPS2 {
public:
    void ReleaseBlock(EB3MemoryBlock p0, int p1);

    unsigned char pad_0[0x174];
    CB3ManagedMemoryBlock field_174;
    unsigned char pad_184[0x310];
    CB3ManagedMemoryBlock field_494;
    unsigned char pad_4A4[0x490];
    CB3ManagedMemoryBlock field_934;
    unsigned char pad_944[0x40];
    int field_984;
    unsigned char pad_988[0x4];
    CB3ManagedMemoryBlock field_98C;
    CB3ManagedMemoryBlock field_99C;
    CB3ManagedMemoryBlock field_9AC;
    CB3ManagedMemoryBlock field_9BC;
};

#endif
