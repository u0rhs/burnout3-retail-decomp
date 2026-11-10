// func_0042F790 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool fields; || chain of int calls assigned to bool; pointer compare field_1B8 == &D_0051B928).

// lifter variant 0
// func_0042F790 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0042F790;
struct UnkStruct_0042F790_1;
struct UnkStruct_0042F790_3;
struct UnkStruct_0042F790_4;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051B928;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E65499;

struct UnkStruct_D_0051BA88 {
    UnkStruct_0042F790_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0042F790_1 {
    unsigned char pad_0[0x1B4];
    UnkStruct_0042F790_3 * field_1B4;
     void * field_1B8;
};

struct UnkStruct_0042F790_3 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual int vfunc_A4();
    virtual int vfunc_A8();
};

struct UnkStruct_0042F790_4 {
    unsigned char pad_0[0xA8];
    int field_A8;
};

struct UnkStruct_D_01E65499 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B928 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0042F790 {
    unsigned char pad_0[0x6F];
    unsigned char field_6F;
    unsigned char pad_70[0x60];
     bool field_D0;
    unsigned char pad_D1[0x2];
    unsigned char field_D3;
    unsigned char pad_D4[0x1];
     bool field_D5;
    unsigned char field_D6;
    unsigned char field_D7;
    unsigned char pad_D8[0x1];
    unsigned char field_D9;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_0051B928 D_0051B928;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int func_00131CA0(void *);
extern "C" int func_00131D90(void *);
extern "C" int func_00131D20(void *);

// 0x0042F790
extern "C" void func_0042F790(UnkStruct_0042F790 * self)
{
    UnkStruct_0042F790_1 * t0 = D_0051BA88.field_0;
    UnkStruct_0042F790_3 * t1 = t0->field_1B4;
    self->field_D0 = t0->field_1B8 == &D_0051B928;
    self->field_D5 = func_00131CA0(&D_004EE040) || t1->vfunc_A4() || t1->vfunc_A8();
    self->field_D6 = D_01E65499.field_0;
    self->field_D3 = self->field_D6;
    self->field_D7 = func_00131D90(&D_004EE040);
    self->field_D9 = func_00131D20(&D_004EE040);
    self->field_6F = 1;
}
