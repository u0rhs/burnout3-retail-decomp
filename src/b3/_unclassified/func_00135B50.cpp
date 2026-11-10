// func_00135B50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00135B50;

struct UnkStruct_00135B50 {
    unsigned char pad_0[0x49A];
    unsigned char field_49A;
};

extern "C" int func_00135DA0(UnkStruct_00135B50 *, int, int);

// 0x00135B50
extern "C" int func_00135B50(UnkStruct_00135B50 * self, int p0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (i != p0) {
            int r0 = func_00135DA0(self, i, ((self->field_49A != 0) ^ 1));
            if (r0 == 0) {
                goto loop0_next;
            }
            return 1;
        }
    }
loop0_next:
    i++;
loop0_test:
    if (i < 3) goto loop0_body;
    return 0;
}
