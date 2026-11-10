// func_00458880 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00458880;
struct UnkStruct_00458880_e5;
struct UnkStruct_00458880_e6;

struct UnkStruct_00458880_e5 {
    int field_0;
    int field_4;
};

struct UnkStruct_00458880_e6 {
    int field_0;
    int field_4;
};

struct UnkStruct_00458880 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x4];
    int field_18[1];  // [G] element count unknown
    unsigned char pad_1C[0x4];
    UnkStruct_00458880_e5 field_20[1];  // [G] element count unknown
    unsigned char pad_28[0x8];
    UnkStruct_00458880_e6 field_30[1];  // [G] element count unknown
    unsigned char pad_38[0x14];
    float field_4C;
    unsigned char field_50[1];  // [G] element count unknown
    unsigned char pad_51[0x1];
    unsigned char field_52[1];  // [G] element count unknown
    unsigned char pad_53[0x1];
    unsigned char field_54[1];  // [G] element count unknown
    unsigned char pad_55[0x1];
    unsigned char field_56;
    unsigned char field_57;
    unsigned char field_58;
};

// 0x00458880
extern "C" void func_00458880(UnkStruct_00458880 * self, void *p0_, int p1, int p2)
{
    int p0 = (int)p0_;
    self->field_C = 0;
    for (int i = 0; (i < 2); i++) {
        self->field_10[i] = 0;
        self->field_18[i] = 0;
        self->field_50[i] = 0;
        self->field_52[i] = 0;
        self->field_54[i] = 0;
    }
    self->field_0 = p0;
    self->field_4 = p1;
    self->field_8 = p2;
    for (int i1 = 0; (i1 < 2); i1++) {
        self->field_20[i1].field_0 = 0;
        self->field_20[i1].field_4 = 0;
        self->field_30[i1].field_0 = 0;
        self->field_30[i1].field_4 = 0;
    }
    self->field_4C = -1.0f;
    self->field_56 = 0;
    self->field_57 = 0;
    self->field_58 = 0;
}
