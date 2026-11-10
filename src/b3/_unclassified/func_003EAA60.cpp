// func_003EAA60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch default moved first; kaB3HardCodedTrackList declared const (moves sd ra after the index addu)).

// func_003EAA60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003EAA60_2;

struct UnkStruct_003EAA60_2 {
    signed char field_0;
    unsigned char pad_1[0xF];
};

extern const unsigned long kaB3HardCodedTrackList[];  // [G] element count unknown

extern "C" void func_0021ADF0(unsigned long, UnkStruct_003EAA60_2 *);

// 0x003EAA60
extern "C" int func_003EAA60(void *n0_)
{
    int n0 = (int)n0_;
    UnkStruct_003EAA60_2 local;  // [G] the frame's one local (size: up to the frame top)
    func_0021ADF0(kaB3HardCodedTrackList[n0], &local);
    switch (local.field_0) {
    default:
        return 3;
    case 85:
        return 0;
    case 69:
        return 1;
    case 65:
        return 2;
    }
}
