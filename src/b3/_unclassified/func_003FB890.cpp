// func_003FB890 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FB890;

struct UnkStruct_003FB890 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0x2D];
    unsigned char field_EA;
};

// 0x003FB890
extern "C" unsigned char func_003FB890(UnkStruct_003FB890 * self)
{
    unsigned char v0;
    if (self->field_BC != 0) {
        v0 = self->field_EA;
    } else {
        v0 = 1;
    }
    return v0;
}
