// func_0042FBC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042FBC0;

struct UnkStruct_0042FBC0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    unsigned char pad_28[0x4A];
    unsigned char field_72[1];  // [G] element count unknown
    unsigned char pad_73[0x51];
    int field_C4;
    int field_C8;
    int field_CC;
    unsigned char field_D0;
    unsigned char field_D1;
    unsigned char field_D2;
    unsigned char field_D3;
    unsigned char field_D4;
    unsigned char field_D5;
    unsigned char field_D6;
    unsigned char field_D7;
    unsigned char field_D8;
    unsigned char field_D9;
    unsigned char field_DA;
    unsigned char field_DB;
    unsigned char field_DC;
    unsigned char field_DD;
    unsigned char field_DE;
    unsigned char field_DF;
    unsigned char field_E0;
    unsigned char field_E1[1];  // [G] element count unknown
    unsigned char pad_E2[0x2B6];
    int field_398;
    unsigned char field_39C;
};

// 0x0042FBC0
extern "C" void func_0042FBC0(UnkStruct_0042FBC0 * self)
{
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_8 = 0;
    self->field_C = 4;
    self->field_10 = 901;
    self->field_14 = 900;
    self->field_18 = 873;
    self->field_1C = 0;
    self->field_20 = 0;
    self->field_24 = 0;
    self->field_C4 = 3;
    self->field_C8 = 3;
    self->field_CC = 3;
    self->field_D0 = 0;
    self->field_D1 = 0;
    self->field_D2 = 0;
    self->field_D3 = 0;
    self->field_D4 = 0;
    self->field_D5 = 0;
    self->field_D6 = 0;
    self->field_D7 = 0;
    self->field_D8 = 0;
    self->field_D9 = 0;
    self->field_DA = 0;
    self->field_DB = 1;
    self->field_DC = 1;
    self->field_DD = 0;
    self->field_DE = 0;
    self->field_DF = 5;
    self->field_E0 = 0;
    for (int i = 0; (i < 2); i++) {
        self->field_E1[i] = 0;
    }
    for (int i1 = 0; (i1 < 4); i1++) {
        self->field_72[i1] = 1;
    }
    self->field_398 = -1;
    self->field_39C = 0;
}
