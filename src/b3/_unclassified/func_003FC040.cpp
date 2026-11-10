// func_003FC040 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003FC040;
struct UnkStruct_003FC040_a1;
struct UnkStruct_003FC040_a2;

struct UnkStruct_003FC040_a1 {
    void * field_0;
};

struct UnkStruct_003FC040_a2 {
    int field_0;
};

struct UnkStruct_003FC040 {
    unsigned char pad_0[0xD8];
    int field_D8;
};

// 0x003FC040
extern "C" void func_003FC040(UnkStruct_003FC040 * self, UnkStruct_003FC040_a1 * p0, UnkStruct_003FC040_a2 * p1)
{
    p0->field_0 = ((char *)self + 0x68);
    p1->field_0 = self->field_D8;
}
