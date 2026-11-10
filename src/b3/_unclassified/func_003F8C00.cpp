// func_003F8C00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003F8C00;

struct UnkStruct_003F8C00 {
    unsigned char pad_0[0x17C];
    int field_17C;
    unsigned char pad_180[0x2D];
    unsigned char field_1AD;
};

// 0x003F8C00
extern "C" void func_003F8C00(UnkStruct_003F8C00 * self, int p0)
{
    if (p0 != self->field_17C) {
        if (p0 < 3) {
            self->field_1AD = 0;
        }
        self->field_17C = p0;
    }
}
