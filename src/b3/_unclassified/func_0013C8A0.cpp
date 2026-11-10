// func_0013C8A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0013C8A0;

struct UnkStruct_0013C8A0 {
    unsigned char pad_0[0x1C0];
    int field_1C0[1];  // [G] element count unknown
};

// 0x0013C8A0
extern "C" int func_0013C8A0(UnkStruct_0013C8A0 * self)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (self->field_1C0[i] > 0) {
            return 1;
        }
    }
    i++;
loop0_test:
    if (i < 2) goto loop0_body;
    return 0;
}
