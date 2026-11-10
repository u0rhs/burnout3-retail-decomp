// func_00430720 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch (case 1 / default) instead of if/else; &D_0064EA70 pointer local hoisted; per-case field_C stores after the a/b/c ids).

// func_00430720 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00430720;
struct UnkStruct_00430720_2;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0064EA70;

struct UnkStruct_D_0051BA88 {
    UnkStruct_00430720_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00430720_2 {
    unsigned char pad_0[0x78];
    int field_78;
};

struct UnkStruct_D_0064EA70 {
    short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00430720 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0xA0];
    int field_C4;
    unsigned char pad_C8[0x18];
    unsigned char field_E0;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" int func_00271A00(void *, int);

// 0x00430720
extern "C" void func_00430720(UnkStruct_00430720 * self)
{
    UnkStruct_D_0064EA70 * p = &D_0064EA70;
    int a;
    int b;
    int c;
    self->field_1C = 13;
    self->field_20 = 9;
    self->field_14 = 2862;
    UnkStruct_00430720_2 * t0 = D_0051BA88.field_0;
    if (t0 != 0) {
        self->field_E0 = t0->field_78;
    }
    switch (p->field_0) {
    case 1:
        a = 831;
        b = 833;
        c = 835;
        self->field_C = 1;
        self->field_C4 = 0;
        break;
    default:
        a = 832;
        b = 834;
        c = 836;
        self->field_C = 4;
        break;
    }
    if (a < 4005) {
        self->field_0 = func_00271A00(&D_0051BA44, a);
    }
    if (b < 4005) {
        self->field_4 = func_00271A00(&D_0051BA44, b);
    }
    if (c < 4005) {
        self->field_8 = func_00271A00(&D_0051BA44, c);
    }
}
