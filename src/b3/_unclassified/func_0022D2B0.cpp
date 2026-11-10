// func_0022D2B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022D2B0;

struct UnkStruct_0022D2B0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
};

extern "C" void func_002514B0(void *, UnkStruct_0022D2B0 *, int);

// 0x0022D2B0
extern "C" void func_0022D2B0(UnkStruct_0022D2B0 * self, void *p0_, int p1, int p2)
{
    int p0 = (int)p0_;
    self->field_4 = p0;
    self->field_8 = p1;
    self->field_C = p2;
    func_002514B0(((char *)self + 0x41), self, self->field_C);
}
