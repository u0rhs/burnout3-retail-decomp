// func_003926C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003926C0;

struct UnkStruct_003926C0 {
    unsigned char pad_0[0x11F];
    unsigned char field_11F;
};

extern "C" void func_00390610(UnkStruct_003926C0 *, int, int);

// 0x003926C0
extern "C" void func_003926C0(UnkStruct_003926C0 * self, int p0, int p1)
{
    func_00390610(self, p0, p1);
    if ((((signed char)p1) & 8) != 0) {
        self->field_11F = 1;
    }
}
