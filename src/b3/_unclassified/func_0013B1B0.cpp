// func_0013B1B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013B1B0;

struct UnkStruct_0013B1B0 {
    unsigned char pad_0[0x204];
    int field_204;
    int field_208;
};

// 0x0013B1B0
extern "C" int func_0013B1B0(UnkStruct_0013B1B0 * self, int p0)
{
    int v0;
    if (p0 != 0) {
        v0 = self->field_208;
    } else {
        v0 = self->field_204;
    }
    return v0;
}
