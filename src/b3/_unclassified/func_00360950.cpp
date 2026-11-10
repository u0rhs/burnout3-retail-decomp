// func_00360950 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00360950;

struct UnkStruct_00360950 {
    unsigned char pad_0[0x118];
    int field_118;
    unsigned char pad_11C[0x5];
    unsigned char field_121;
};

extern "C" void HLBApiUpdate(int);
extern "C" void func_00419D18(int);

// 0x00360950
extern "C" void func_00360950(UnkStruct_00360950 * self)
{
    if (self->field_121 != 0) {
        int t0 = self->field_118;
        if (t0 != 0) {
            HLBApiUpdate(t0);
            func_00419D18(self->field_118);
        }
    }
}
