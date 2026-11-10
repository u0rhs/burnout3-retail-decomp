// func_0013AEF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HardCodedTrackList;
struct UnkStruct_0013AEF0;
struct UnkStruct_gCalculatedData;

class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x10];
    float field_10;
};

struct UnkStruct_0013AEF0 {
    unsigned char pad_0[0x2A0];
    float field_2A0[1];  // [G] element count unknown
};

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013AEF0
extern "C" float func_0013AEF0(UnkStruct_0013AEF0 * self, unsigned long p0)
{
    if (p0 == 0) {
        return gCalculatedData.field_10;
    }
    int r0 = CB3HardCodedTrackList::FindTrack(p0);
    return self->field_2A0[r0];
}
