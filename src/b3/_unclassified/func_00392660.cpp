// func_00392660 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00392660;
struct UnkStruct_00392660_e2;

struct UnkStruct_00392660_e2 {
    unsigned char pad_0[0x4];
};

struct UnkStruct_00392660 {
    UnkStruct_00392660_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_4[0xF0];
    int field_F4[1];  // [G] element count unknown
    unsigned char pad_F8[0x1C];
    unsigned char field_114[1];  // [G] element count unknown
};

// 0x00392660
extern "C" void func_00392660(UnkStruct_00392660 * self, int p0, int p1, int p2, int p3)
{
    void * m0 = (void *)p3;
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        if (self->field_F4[i] == p1) {
            return;
        }
        if (self->field_F4[i] == -1) {
            self->field_F4[i] = p1;
            self->field_114[i] = 1;
        }
        m0 = ((char *)&self->field_0[i] + 0xF4);
    }
    i++;
loop0_test:
    if (i < 8) goto loop0_body;
}
