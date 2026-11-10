// func_00237030 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00237030;

struct UnkStruct_00237030 {
    unsigned char field_0;
};

// 0x00237030
extern "C" void func_00237030(UnkStruct_00237030 * self)
{
    if (self == 0) return;
    self->field_0 = (self->field_0 & -2);
}
