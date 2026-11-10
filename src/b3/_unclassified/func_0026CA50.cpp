// func_0026CA50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0026CA50;

struct UnkStruct_0026CA50 {
    unsigned char pad_0[0x32980];
    int field_32980[1];  // [G] element count unknown
};

// 0x0026CA50
extern "C" int func_0026CA50(UnkStruct_0026CA50 * self, int p0, int p1)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (self->field_32980[i] == p1) {
            return 0;
        }
        if (self->field_32980[i] == p0) {
            return 1;
        }
    }
    i++;
loop0_test:
    if (i < 8) goto loop0_body;
    return 1;
}
