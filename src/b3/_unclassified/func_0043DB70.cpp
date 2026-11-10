// func_0043DB70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0043DB70;
struct UnkStruct_0043DB70_e0;
struct UnkStruct_0043DB70_e1;

struct UnkStruct_0043DB70_e1 {
    unsigned char pad_0[0x4];
};

struct UnkStruct_0043DB70_e0 {
    UnkStruct_0043DB70_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x10];
};

struct UnkStruct_0043DB70 {
    UnkStruct_0043DB70_e0 field_0[1];  // [G] element count unknown
};

extern "C" void func_004572B0(void *, float);
extern "C" int func_00458960(void *);
extern "C" void func_00458940(void *, float);

// 0x0043DB70
extern "C" void func_0043DB70(UnkStruct_0043DB70 * self, float f0)
{
    func_004572B0(((char *)self + 0x10), f0);
    for (int i = 0; (i < 2); i++) {
        int m0 = 0;
        do {
            int r1 = func_00458960(((char *)&self->field_0[i].field_0[m0] + 0x7C));
            if (r1 != 0) {
                func_00458940(((char *)&self->field_0[i].field_0[m0] + 0x7C), f0);
            } else {
            }
            m0 = (m0 + 1);
        } while (m0 < 5);
    }
}
