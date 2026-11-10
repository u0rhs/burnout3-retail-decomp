// CB3ManagedMemoryBlock -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MANAGEDMEMORYBLOCK_H
#define B3_CLASSES_CB3MANAGEDMEMORYBLOCK_H

class CB3ManagedMemoryBlock;

class CB3ManagedMemoryBlock {
public:
    int GetMemoryBlock(int p0);
    void ReleaseMemoryBlock(int p0);

    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
    int field_C;
};

#endif
