// func_003FBA40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FBA40;

struct UnkStruct_003FBA40 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0x2B];
    unsigned char field_E8;
};

extern "C" void func_0042B4F0(void *);

// 0x003FBA40
extern "C" void func_003FBA40(UnkStruct_003FBA40 * self, int p0)
{
    if (self->field_BC != 0) {
        if (p0 != 0) {
            self->field_E8 = (self->field_E8 | 2);
        } else {
            self->field_E8 = (self->field_E8 & 253);
        }
    } else {
        func_0042B4F0(((char *)self + 0x8));
    }
}
