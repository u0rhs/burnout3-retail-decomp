// func_0022D920 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022D920;

struct UnkStruct_0022D920 {
    unsigned char field_0;
};

extern "C" void func_0022D970(UnkStruct_0022D920 *, int);

// 0x0022D920
// pass1: a1 (the byte count; caller func_00235F80 passes a virtual call's result) goes to func_0022D970 untouched
extern "C" int func_0022D920(UnkStruct_0022D920 * self, int n)
{
    unsigned char t0 = self->field_0;
    func_0022D970(self, n);
    if (self->field_0 == (t0 & 255)) {
        return 1;
    }
    self->field_0 = t0;
    return 0;
}
