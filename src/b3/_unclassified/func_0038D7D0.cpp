// func_0038D7D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038D7D0;

struct UnkStruct_0038D7D0 {
    unsigned char pad_0[0x6F];
    unsigned char field_6F;
    unsigned char field_70;
    unsigned char pad_71[0x1];
    unsigned char field_72;
};

extern "C" void func_00390610(UnkStruct_0038D7D0 *, int, int);

// 0x0038D7D0
extern "C" void func_0038D7D0(UnkStruct_0038D7D0 * self, int p0, int p1)
{
    func_00390610(self, p0, p1);
    if ((((signed char)p1) & 8) != 0) {
        self->field_6F = 1;
    }
    if ((((signed char)p1) & 16) != 0) {
        self->field_70 = 1;
    }
    if ((((signed char)p1) & 32) != 0) {
        self->field_72 = 1;
    }
}
