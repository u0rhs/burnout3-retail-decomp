// func_003F8870 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003F8870;

struct UnkStruct_003F8870 {
    unsigned char pad_0[0x1AC];
    unsigned char field_1AC;
};

extern "C" void func_003FBA40(UnkStruct_003F8870 *, int);

// 0x003F8870
extern "C" void func_003F8870(UnkStruct_003F8870 * self, int p0)
{
    self->field_1AC = ((p0 != 0) ^ 1);
    func_003FBA40(self, (((p0 != 0) ^ 1) & 255));
}
