// func_00430ED0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else arms swapped to test != 0 first (field_D2, field_D9); final test merged as if (field_D2 != 0 || field_DA == 0) field_24 = 0).

struct UnkStruct_00430ED0;
struct UnkStruct_00430ED0_2;
struct UnkStruct_00430ED0_3;
struct UnkStruct_D_0051B988;
struct UnkStruct_D_0051BA38;
struct UnkStruct_D_0051BA39;
struct UnkStruct_D_0051BA3A;
struct UnkStruct_D_0051BA88;

struct UnkStruct_D_0051BA88 {
    UnkStruct_00430ED0_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00430ED0_2 {
    unsigned char pad_0[0x1B0];
    // vptr at +0x1B0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual int vfunc_20();
    UnkStruct_00430ED0_3 * field_1B4;
};

struct UnkStruct_00430ED0_3 {
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
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void vfunc_FC();
    virtual int vfunc_100();
};

struct UnkStruct_D_0051BA38 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA3A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA39 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051B988 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00430ED0 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    unsigned char pad_18[0x8];
    int field_20;
    int field_24;
    unsigned char pad_28[0xAA];
    unsigned char field_D2;
    unsigned char pad_D3[0x1];
    unsigned char field_D4;
    unsigned char pad_D5[0x1];
    unsigned char field_D6;
    unsigned char pad_D7[0x2];
    unsigned char field_D9;
    unsigned char field_DA;
    signed char field_DB;
    signed char field_DC;
    signed char field_DD;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051BA38 D_0051BA38;
extern UnkStruct_D_0051BA3A D_0051BA3A;
extern UnkStruct_D_0051BA39 D_0051BA39;
extern UnkStruct_D_0051B988 D_0051B988;

extern "C" int func_003C28E0(void *);
extern "C" int func_003C2940(void *);

// 0x00430ED0
extern "C" void func_00430ED0(UnkStruct_00430ED0 * self)
{
    self->field_D4 = 1;
    if (self->field_D6 != 0) {
        int r0 = D_0051BA88.field_0->field_1B4->vfunc_100();
        self->field_DB = r0;
        int r1 = D_0051BA88.field_0->vfunc_20();
        self->field_DC = r1;
        self->field_DA = 1;
        self->field_D2 = (self->field_DB < self->field_DC);
    } else {
        int r2 = func_003C28E0(&D_0051B988);
        if (r2 != 0) {
            self->field_DA = 1;
            int r3 = func_003C2940(&D_0051B988);
            self->field_D2 = ((r3 != 0) ^ 1);
        } else {
            self->field_D2 = 1;
        }
        self->field_DB = (D_0051BA38.field_0 + 1);
        self->field_DC = D_0051BA3A.field_0;
        self->field_DD = D_0051BA39.field_0;
    }
    self->field_14 = 2510;
    if (self->field_D2 != 0) {
        self->field_10 = 2511;
    } else {
        self->field_10 = 902;
    }
    self->field_20 = 112;
    if (self->field_D9 != 0) {
        self->field_20 |= 256;
        self->field_DD <<= 1;
    } else {
        self->field_20 |= 128;
    }
    if (self->field_D2 != 0 || self->field_DA == 0) {
        self->field_24 = 0;
    }
}
