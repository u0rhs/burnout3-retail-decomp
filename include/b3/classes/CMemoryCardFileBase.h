// CMemoryCardFileBase -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CMEMORYCARDFILEBASE_H
#define B3_CLASSES_CMEMORYCARDFILEBASE_H

class CMemoryCardFileBase;
struct UnkStruct_004216A0_1;

struct UnkStruct_004216A0_1 {
    signed char field_0;
};

class CMemoryCardFileBase {
public:
    static int mgpacDirName;
    void * GetFullFilename();

    UnkStruct_004216A0_1 * field_0;
};

#endif
