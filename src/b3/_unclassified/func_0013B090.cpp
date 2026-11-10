// func_0013B090 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HardCodedTrackList;
struct UnkStruct_0013B090;
struct UnkStruct_gCalculatedData;

class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
};

struct UnkStruct_gCalculatedData {
    unsigned char pad_0[0x8];
    float field_8;
    unsigned char pad_C[0x4];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0013B090 {
    unsigned char pad_0[0x20C];
    float field_20C[1];  // [G] element count unknown
};

extern UnkStruct_gCalculatedData gCalculatedData;

// 0x0013B090
extern "C" float func_0013B090(UnkStruct_0013B090 * self, unsigned long p0)
{
    if (p0 == 0) {
        return gCalculatedData.field_8;
    }
    int r0 = CB3HardCodedTrackList::FindTrack(p0);
    return self->field_20C[r0];
}
