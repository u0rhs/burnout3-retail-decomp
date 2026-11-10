// func_0022D2E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022D2E0;

struct UnkStruct_0022D2E0 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
};

extern "C" void func_00251490(void *, int);

// 0x0022D2E0
extern "C" int func_0022D2E0(UnkStruct_0022D2E0 * self, int p0)
{
    self->field_10 = p0;
    func_00251490(((char *)self + 0x41), self->field_10);
    return self->field_14;
}
