// func_0022D850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022D850;

struct UnkStruct_0022D850 {
    unsigned char field_0;
};

extern "C" void DecryptData__17CGtNetworkMessageFii(UnkStruct_0022D850 *, int, int);

// 0x0022D850
extern "C" void func_0022D850(UnkStruct_0022D850 * self)
{
    DecryptData__17CGtNetworkMessageFii(self, 3, 13);
    self->field_0 = (self->field_0 & -3);
}
