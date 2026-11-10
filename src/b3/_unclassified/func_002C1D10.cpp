// func_002C1D10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_002C1D10;
struct UnkStruct_002C1D10_4;

struct UnkStruct_002C1D10_4 {
    unsigned char pad_0[0x14];
    // vptr at +0x14: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(int, int);
};

struct UnkStruct_002C1D10 {
    unsigned char field_0;
    unsigned char pad_1[0x3];
    UnkStruct_002C1D10_4 * field_4;
    int field_8;
    unsigned char pad_C[0x810];
    int field_81C;
    int field_820;
    int field_824;
    unsigned char field_828;
    unsigned char field_829;
    unsigned char pad_82A[0x78F2];
    int field_811C;
    unsigned char pad_8120[0x4];
    int field_8124;
    unsigned char field_8128[1];  // [G] element count unknown
    unsigned char pad_8129[0x3B];
    int field_8164;
    unsigned char pad_8168[0x2];
    unsigned char field_816A;
    unsigned char pad_816B[0x1];
    int field_816C;
    unsigned char pad_8170[0x8];
    int field_8178;
    float field_817C;
    int field_8180;
    int field_8184;
    int field_8188;
    int field_818C[1];  // [G] element count unknown
    unsigned char pad_8190[0x1C];
    int field_81AC;
    int field_81B0[1];  // [G] element count unknown
    unsigned char pad_81B4[0x1C];
    int field_81D0;
    int field_81D4;
    unsigned char pad_81D8[0x4];
    int field_81DC[1];  // [G] element count unknown
    unsigned char pad_81E0[0x10];
    int field_81F0[1];  // [G] element count unknown
    unsigned char pad_81F4[0x10];
    unsigned char field_8204;
};

// 0x002C1D10
extern "C" void func_002C1D10(UnkStruct_002C1D10 * self)
{
    for (int i = 0; (i < 60); i++) {
        self->field_8128[i] = 0;
    }
    self->field_8164 = -1;
    self->field_811C = 0;
    self->field_8124 = 0;
    self->field_81C = 0;
    self->field_820 = 0;
    self->field_816A = 1;
    self->field_824 = 65535;
    self->field_829 = 0;
    self->field_8164 = -1;
    self->field_828 = 1;
    self->field_81D4 = -1;
    self->field_8188 = -1;
    self->field_8178 = 0;
    self->field_817C = 20.0f;
    self->field_8180 = 0;
    for (int i1 = 0; (i1 < 5); i1++) {
        self->field_81DC[i1] = 0;
        self->field_81F0[i1] = -1;
    }
    self->field_4->vfunc_10(self->field_816C, -1);
    self->field_8 = 0;
    self->field_8184 = 0;
    for (int i2 = 0; (i2 < 8); i2++) {
        self->field_818C[i2] = -1;
        self->field_81B0[i2] = -1;
    }
    self->field_81AC = 0;
    self->field_81D0 = 0;
    self->field_8204 = 1;
    self->field_0 = 0;
}
