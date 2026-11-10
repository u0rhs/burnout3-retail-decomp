// func_0038E1C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038E1C0;
struct UnkStruct_0038E1C0_e0;

struct UnkStruct_0038E1C0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_0038E1C0 {
    unsigned char pad_0[0x68];
    UnkStruct_0038E1C0_e0 * field_68;
};

// 0x0038E1C0
extern "C" void func_0038E1C0(UnkStruct_0038E1C0 * self, int p0)
{
    self->field_68 = (UnkStruct_0038E1C0_e0 *)&self->field_68[p0];
}
