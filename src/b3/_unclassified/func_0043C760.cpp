// func_0043C760 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (nested switches for case 5 (p2==2) and case 2 (-1: break, default: store); || for the vfunc_C0 test).

// lifter variant 0
// func_0043C760 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0043C760_2;
struct UnkStruct_0043C760_3;
struct UnkStruct_0043C760_4;
struct UnkStruct_0043C760_5;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_0051BA94;
struct UnkStruct_D_0051BA9C;
struct UnkStruct_D_01E65499;
struct UnkStruct_D_01E9584C;

struct UnkStruct_D_0051BA88 {
    UnkStruct_0043C760_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E65499 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043C760_2 {
    unsigned char pad_0[0x1B4];
    UnkStruct_0043C760_3 * field_1B4;
};

struct UnkStruct_0043C760_3 {
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
    virtual int vfunc_C0();
};

struct UnkStruct_0043C760_4 {
    unsigned char pad_0[0xC0];
    int field_C0;
};

struct UnkStruct_0043C760_5 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
};

struct UnkStruct_D_0051BA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9584C {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_0051BA94 D_0051BA94;
extern UnkStruct_D_0051BA9C D_0051BA9C;
extern UnkStruct_D_01E9584C D_01E9584C;

extern "C" int func_0043C5B0(void *, int, int);

// 0x0043C760
extern "C" void func_0043C760(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    case 0:
        break;
    case 3:
        UnkStruct_0043C760_2 * t0 = D_0051BA88.field_0;
        UnkStruct_0043C760_3 * t1 = t0->field_1B4;
        if (D_01E65499.field_0 != 0 || t1->vfunc_C0() != 0) {
            func_0043C5B0(&D_01E9584C, 0, t1->vfunc_C0());
        } else {
            func_0043C5B0(&D_01E9584C, 1, 0);
        }
        break;
    case 5:
        switch (p2) {
        case 2:
            ((UnkStruct_0043C760_5 *)D_0051BA88.field_0->field_1B4)->vfunc_24();
            break;
        }
        break;
    case 2:
        switch (D_0051BA94.field_0) {
        case -1:
            break;
        default:
            D_0051BA9C.field_0 = 0;
            break;
        }
        break;
    default:
        break;
    }
}
