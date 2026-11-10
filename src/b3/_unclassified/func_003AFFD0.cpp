// func_003AFFD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003AFFD0;
struct UnkStruct_003AFFD0_e2;
struct UnkStruct_003AFFD0_e5;
struct UnkStruct_003AFFD0_e6;

struct UnkStruct_003AFFD0_e2 {
    int field_0;
    int field_4;
};

struct UnkStruct_003AFFD0_e5 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_003AFFD0_e6 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_003AFFD0 {
    unsigned char pad_0[0x30];
    UnkStruct_003AFFD0_e2 field_30[1];  // [G] element count unknown
    unsigned char pad_38[0x8];
    UnkStruct_003AFFD0_e5 field_40[1];  // [G] element count unknown
    unsigned char pad_50[0x50];
    UnkStruct_003AFFD0_e6 field_A0[1];  // [G] element count unknown
    unsigned char pad_B0[0xB4];
    int field_164[1];  // [G] element count unknown
    unsigned char pad_168[0x14];
    int field_17C[1];  // [G] element count unknown
    unsigned char pad_180[0x8];
    int field_188;
    int field_18C[1];  // [G] element count unknown
    unsigned char pad_190[0x2C];
    int field_1BC;
    int field_1C0[1];  // [G] element count unknown
    unsigned char pad_1C4[0x2C];
    int field_1F0[1];  // [G] element count unknown
    unsigned char pad_1F4[0x20];
    int field_214;
    int field_218;
    unsigned char pad_21C[0xC];
    int field_228;
    unsigned char pad_22C[0x4];
    int field_230[1];  // [G] element count unknown
    unsigned char pad_234[0x18];
    int field_24C;
    unsigned char pad_250[0x18];
    int field_268;
    int field_26C;
    int field_270;
    unsigned char field_274;
    unsigned char field_275;
    unsigned char field_276;
    unsigned char pad_277[0x89];
    int field_300;
};

extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// 0x003AFFD0
extern "C" void func_003AFFD0(UnkStruct_003AFFD0 * self)
{
    Construct__20CB3MenuComponentBaseFi(self, 21);
    self->field_188 = 0;
    self->field_228 = 0;
    self->field_214 = 0;
    self->field_218 = 0;
    for (int i = 0; (i < 2); i++) {
        self->field_17C[i] = 0;
    }
    for (int i1 = 0; (i1 < 6); i1++) {
        self->field_164[i1] = 0;
    }
    for (int i2 = 0; (i2 < 2); i2++) {
        self->field_30[i2].field_0 = 0;
        self->field_30[i2].field_4 = 0;
    }
    for (int i3 = 0; (i3 < 12); i3++) {
        self->field_18C[i3] = 0;
    }
    self->field_1BC = 0;
    self->field_24C = 0;
    for (int i4 = 0; (i4 < 7); i4++) {
        self->field_230[i4] = 0;
    }
    for (int i5 = 0; (i5 < 4); i5++) {
        self->field_40[i5].field_0 = 0;
        self->field_40[i5].field_4 = 0;
        self->field_40[i5].field_8 = 0;
    }
    for (int i6 = 0; (i6 < 12); i6++) {
        self->field_A0[i6].field_4 = 0;
        self->field_A0[i6].field_8 = 0;
    }
    for (int i7 = 0; (i7 < 12); i7++) {
        self->field_1C0[i7] = 0;
    }
    for (int i8 = 0; (i8 < 5); i8++) {
        self->field_1F0[i8] = 0;
    }
    self->field_268 = -1;
    self->field_26C = -1;
    self->field_270 = -1;
    self->field_274 = 0;
    self->field_275 = 0;
    self->field_276 = 0;
    self->field_300 = -1;
}
