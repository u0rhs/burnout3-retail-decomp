// func_00462160 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00462160;

struct UnkStruct_00462160 {
    int field_0;
};

extern "C" int func_004697C0();

// 0x00462160
extern "C" void func_00462160(UnkStruct_00462160 * self)
{
    int r0 = func_004697C0();
    if (self == 0) return;
    self->field_0 = r0;
}
