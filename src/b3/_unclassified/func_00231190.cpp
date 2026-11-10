// func_00231190 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00231190;
struct UnkStruct_00231190_e0;

struct UnkStruct_00231190_e0 {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x78];
};

struct UnkStruct_00231190 {
    UnkStruct_00231190_e0 field_0[1];  // [G] element count unknown
};

// 0x00231190
extern "C" void * func_00231190(UnkStruct_00231190 * self, int p0)
{
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (p0 == self->field_0[i].field_14) {
            return &self->field_0[i];
        }
    }
    i++;
loop0_test:
    if (i < 8) goto loop0_body;
    return 0;
}
