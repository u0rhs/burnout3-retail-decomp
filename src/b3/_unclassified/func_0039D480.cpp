// func_0039D480 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (20-byte element array at +0xC modelled as a struct, reached through a per-iteration element pointer).

// func_0039D480 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0039D480_e0 {
    int field_0;
    int field_4[2];
    int field_C;
    int field_10;
};

struct UnkStruct_0039D480 {
    unsigned char pad_0[0xC];
    UnkStruct_0039D480_e0 field_C[3];
    int field_48[2];
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x0039D480
extern "C" void func_0039D480(UnkStruct_0039D480 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 3);
    for (int i = 0; i < 3; i++) {
        UnkStruct_0039D480_e0 *e = &self->field_C[i];
        e->field_0 = 0;
        e->field_C = 0;
        for (int j = 0; j < 2; j++) {
            e->field_4[j] = 0;
        }
        e->field_10 = 0;
    }
    for (int i2 = 0; i2 < 2; i2++) {
        self->field_48[i2] = 0;
    }
    self->field_50 = 0;
    self->field_54 = 0;
    self->field_58 = 0;
    self->field_5C = 0;
    self->field_60 = 0;
}
