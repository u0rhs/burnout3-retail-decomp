// func_003FBA10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FBA10;

struct UnkStruct_003FBA10 {
    unsigned char pad_0[0xE8];
    unsigned char field_E8;
};

// 0x003FBA10
extern "C" void func_003FBA10(UnkStruct_003FBA10 * self, int p0)
{
    if (p0 != 0) {
        self->field_E8 = (self->field_E8 | 4);
    } else {
        self->field_E8 = (self->field_E8 & 251);
    }
}
