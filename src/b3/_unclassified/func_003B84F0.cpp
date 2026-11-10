// func_003B84F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003B84F0;

struct UnkStruct_003B84F0 {
    unsigned char pad_0[0x1800];
    int field_1800;
};

extern "C" void func_003B8840(void *, int);
extern "C" int Length__10CGtUnicodeFPCUs(int);

// 0x003B84F0
// pass1: a1 (the number, callers func_00450EF0 / func_00452ED0) goes to func_003B8840 (-> ustrFromInt) untouched
extern "C" int func_003B84F0(UnkStruct_003B84F0 * self, int n)
{
    int t0 = self->field_1800;
    func_003B8840((void *)(t0), n);
    int r1 = Length__10CGtUnicodeFPCUs(t0);
    self->field_1800 = (self->field_1800 + ((r1 + 1) << 1));
    return t0;
}
