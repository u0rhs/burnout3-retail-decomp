// GetEntryCount__20CB3CarouselComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042B660;

struct UnkStruct_0042B660 {
    unsigned char pad_0[0x234];
    int field_234;
    int field_238;
    unsigned char pad_23C[0xC];
    int field_248;
    int field_24C;
};

// 0x0042B660
extern "C" int GetEntryCount__20CB3CarouselComponentFv(UnkStruct_0042B660 * self)
{
    if ((self->field_234 != 4) || ((unsigned int)(self->field_238 + -3) >= (unsigned int)2)) {
        return self->field_248;
    }
    return self->field_24C;
}
