// func_003FC260 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FC260;

struct UnkStruct_003FC260 {
    unsigned char pad_0[0xBC];
    unsigned char field_BC;
    unsigned char pad_BD[0xB];
    int field_C8;
    unsigned char pad_CC[0xC];
    int field_D8;
    unsigned char pad_DC[0xC];
    unsigned char field_E8;
};

extern "C" void func_0042B560(void *, int);

// 0x003FC260
extern "C" void func_003FC260(UnkStruct_003FC260 * self)
{
    int t0 = self->field_D8;
    if (t0 == -1) {
        return;
    }
    self->field_E8 = (self->field_E8 | 1);
    if (self->field_BC == 0) {
        func_0042B560(((char *)self + 0x8), t0);
    } else {
        if (self->field_C8 == 4) {
            self->field_C8 = 5;
        }
        self->field_E8 = (self->field_E8 | 1);
    }
}
