// CGtFilePS2DVD -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTFILEPS2DVD_H
#define B3_CLASSES_CGTFILEPS2DVD_H

class CGtFilePS2DVD;

class CGtFilePS2DVD {
public:
    int GetStatus();
    int Sync(int p0);
    int Write(const void* p0, unsigned int p1);

    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
    unsigned char pad_20[0xC];
    int field_2C;
};

#endif
