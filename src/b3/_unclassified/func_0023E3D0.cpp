// func_0023E3D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_0023E3D0;

struct UnkStruct_0023E3D0 {
    u_long128 field_0;
};

// 0x0023E3D0
extern "C" UnkStruct_0023E3D0 * func_0023E3D0(UnkStruct_0023E3D0 * self, u_long128 p0)
{
    self->field_0 = p0;
    return self;
}
