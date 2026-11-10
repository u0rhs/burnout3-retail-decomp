// func_00423DC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a80: byte-offset int read of D_00522660+idx*0x27D0+0x12C494, int array field_168, '>' operand order).

struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_00423DC0 {
    unsigned char pad_0[0x168];
    int field_168[1];  // [G] element count unknown
};
extern UnkStruct_D_00522660 D_00522660;

// 0x00423DC0
extern "C" void func_00423DC0(UnkStruct_00423DC0 * self, int p0, int p1)
{
    self->field_168[p0] += p1;
    int t0 = *(int *)((char *)&D_00522660 + p0 * 0x27D0 + 0x12C494);
    if (self->field_168[p0] > t0) {
        self->field_168[p0] = t0;
    }
}
