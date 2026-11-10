// func_00461A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00461A30;

struct UnkStruct_00461A30 {
    unsigned char pad_0[0xA0];
    float field_A0;
    unsigned char pad_A4[0x8];
    int field_AC;
};

// 0x00461A30
extern "C" int func_00461A30(UnkStruct_00461A30 * self)
{
    int v1 = (self->field_AC == 3);
    if ((self->field_AC == 3) != false) {
        int v0 = 1;
        if (!(0.0f == self->field_A0)) {
            v0 = 0;
        }
        v1 = v0;
    }
    return v1;
}
