// func_003BB0D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BB0D0;
struct UnkStruct_003BB0D0_e0;
struct UnkStruct_003BB0D0_e1;

struct UnkStruct_003BB0D0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_003BB0D0_e1 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_003BB0D0 {
    unsigned char pad_0[0x50];
    UnkStruct_003BB0D0_e0 * field_50;
    UnkStruct_003BB0D0_e1 * field_54;
};

// 0x003BB0D0
extern "C" void func_003BB0D0(UnkStruct_003BB0D0 * self, int p0, int p1)
{
    self->field_50 = (UnkStruct_003BB0D0_e0 *)&self->field_50[p0];
    self->field_54 = (UnkStruct_003BB0D0_e1 *)&self->field_54[p1];
}
