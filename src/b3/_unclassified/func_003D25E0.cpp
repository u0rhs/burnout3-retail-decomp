// func_003D25E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003D25E0;
struct UnkStruct_003D25E0_e0;

struct UnkStruct_003D25E0_e0 {
    unsigned char pad_0[0x14];
    signed char field_14;
    unsigned char pad_15[0x7];
};

struct UnkStruct_003D25E0 {
    UnkStruct_003D25E0_e0 field_0[1];  // [G] element count unknown
};

// 0x003D25E0
extern "C" int func_003D25E0(UnkStruct_003D25E0 * self, int p0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (p0 == self->field_0[i].field_14) {
            return 1;
        }
    }
    i++;
loop0_test:
    if (i < 5) goto loop0_body;
    return 0;
}
