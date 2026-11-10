// func_003FBBB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FBBB0;

struct UnkStruct_003FBBB0 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0xB];
    int field_C8;
};

// 0x003FBBB0
extern "C" bool func_003FBBB0(UnkStruct_003FBBB0 * self)
{
    bool v0;
    if (self->field_BC != 0) {
        v0 = (self->field_C8 == 2);
    } else {
        v0 = 1;
    }
    return v0;
}
