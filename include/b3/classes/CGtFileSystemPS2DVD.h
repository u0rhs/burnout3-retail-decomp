// CGtFileSystemPS2DVD -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTFILESYSTEMPS2DVD_H
#define B3_CLASSES_CGTFILESYSTEMPS2DVD_H

class CGtFileSystemPS2DVD;
struct UnkStruct_001D3830_e0;

struct UnkStruct_001D3830_e0 {
    unsigned char pad_0[0x38];
};

class CGtFileSystemPS2DVD {
public:
    int FileExists(const char* p0);
    void * GetFileObject(unsigned int p0);
    int GetStatus();

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x8];
    UnkStruct_001D3830_e0 * field_10;
};

#endif
