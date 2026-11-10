// func_0042C240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042C240;

struct UnkStruct_0042C240 {
    unsigned char pad_0[0x238];
    int field_238;
    unsigned char pad_23C[0x8];
    int field_244;
};

// 0x0042C240
extern "C" bool func_0042C240(UnkStruct_0042C240 * self)
{
    bool v0;
    if (self->field_238 == 0) {
        v0 = (0 < self->field_244);
    } else {
        v0 = 0;
    }
    return v0;
}
