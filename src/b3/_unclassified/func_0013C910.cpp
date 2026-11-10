// func_0013C910 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013C910;
struct UnkStruct_0013C910_e1;

struct UnkStruct_0013C910_e1 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_0013C910 {
    unsigned char pad_0[0x1C0];
    UnkStruct_0013C910_e1 * field_1C0[1];  // [G] element count unknown
};

// 0x0013C910
extern "C" void func_0013C910(UnkStruct_0013C910 * self, int p0, int p1)
{
    self->field_1C0[p0] = (UnkStruct_0013C910_e1 *)&self->field_1C0[p0][p1];
}
