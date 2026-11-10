// func_00392400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00392400;
struct UnkStruct_00392400_e0;

struct UnkStruct_00392400_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00392400 {
    unsigned char pad_0[0x70];
    UnkStruct_00392400_e0 * field_70;
};

// 0x00392400
extern "C" void func_00392400(UnkStruct_00392400 * self, int p0)
{
    self->field_70 = (UnkStruct_00392400_e0 *)&self->field_70[p0];
}
