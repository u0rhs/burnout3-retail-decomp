// func_00436140 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (unsigned seconds param; per-field divide then p0 -= field * constant (strength-reduced by MWCC), +2000 after the subtract).

// lifter variant 0
// func_00436140 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00436140;

struct UnkStruct_00436140 {
    unsigned short field_0;
    unsigned short field_2;
    unsigned short field_4;
    unsigned short field_6;
    unsigned short field_8;
    short field_A;
};

// 0x00436140
extern "C" void func_00436140(UnkStruct_00436140 * self, unsigned int p0)
{
    self->field_0 = p0 / 32140800;
    p0 -= self->field_0 * 32140800;
    self->field_0 += 2000;
    self->field_2 = p0 / 2678400;
    p0 -= self->field_2 * 2678400;
    self->field_4 = p0 / 86400;
    p0 -= self->field_4 * 86400;
    self->field_6 = p0 / 3600;
    p0 -= self->field_6 * 3600;
    self->field_8 = p0 / 60;
    p0 -= self->field_8 * 60;
    self->field_A = p0;
    self->field_4++;
    self->field_2++;
}
