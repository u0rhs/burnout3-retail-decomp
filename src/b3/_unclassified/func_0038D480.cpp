// func_0038D480 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0038D480;

struct UnkStruct_0038D480 {
    unsigned char pad_0[0x4C];
    unsigned char field_4C;
    unsigned char field_4D;
};

extern "C" int func_0038A380(UnkStruct_0038D480 *);

// 0x0038D480
extern "C" int func_0038D480(UnkStruct_0038D480 * self)
{
    self->field_4C = 1;
    self->field_4D = 1;
    return func_0038A380(self);
}
