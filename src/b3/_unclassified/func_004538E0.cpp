// func_004538E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (8-element sub-struct array at +0xC reached through an element-pointer local).

struct UnkStruct_004538E0;
struct UnkStruct_004538E0_e0;

struct UnkStruct_004538E0_e0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10[5];
};

struct UnkStruct_004538E0 {
    unsigned char pad_0[0xC];
    UnkStruct_004538E0_e0 field_C[8];
    int field_12C;
    int field_130;
    int field_134;
    unsigned char pad_138[0x90];
    unsigned char field_1C8[8];
    unsigned char field_1D0[8];
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x004538E0
extern "C" void func_004538E0(UnkStruct_004538E0 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 5);
    self->field_12C = 0;
    self->field_130 = 0;
    self->field_134 = 0;
    for (int i = 0; i < 8; i++) {
        UnkStruct_004538E0_e0 * e = &self->field_C[i];
        e->field_0 = 0;
        e->field_4 = 0;
        e->field_8 = 0;
        e->field_C = 0;
        self->field_1C8[i] = 12;
        self->field_1D0[i] = 5;
        for (int j = 0; j < 5; j++) {
            e->field_10[j] = 0;
        }
    }
}
