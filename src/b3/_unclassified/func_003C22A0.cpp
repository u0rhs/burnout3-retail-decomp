// func_003C22A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (p0 unsigned int widened into an unsigned long local; func_0031ECD0 takes it as unsigned long).

// func_003C22A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C22A0;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E8980A;
struct UnkStruct_D_01E90438;

struct UnkStruct_D_01E8980A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90438 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C22A0 {
    unsigned char pad_0[0x20];
    unsigned char field_20;
    unsigned char field_21;
    unsigned char pad_22[0x2];
    int field_24;
    int field_28;
    unsigned char pad_2C[0x4];
    int field_30;
    unsigned char pad_34[0x4];
    unsigned long field_38;
};

extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E90438 D_01E90438;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

extern "C" void func_003C22A0(UnkStruct_003C22A0 * self, unsigned int p0)
{
    self->field_28 = 0;
    self->field_24 = 0;
    self->field_30 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 128);
    self->field_38 = 0xFFFFFFFF;
    unsigned long v = p0;
    if (v != self->field_38) {
        self->field_38 = v;
        if (D_01E8980A.field_0 != 0) {
            ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
        }
        self->field_20 = (v & 0x419E9003) != 0;
        self->field_21 = (v & 0x1C00020681C) != 0;
        func_0031ECD0(&D_01E89800, v, 3);
    }
    Prepare__15CB3MenuPageBaseFb(self, 0);
}
