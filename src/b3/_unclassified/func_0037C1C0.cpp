// func_0037C1C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0037C1C0_a1;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_func_0037B6C0;
struct UnkStruct_func_0037BCF0;

struct UnkStruct_0037C1C0_a1 {
    unsigned char pad_0[0x1920];
    int field_1920;
    unsigned char pad_1924[0x1C];
    unsigned char field_1940;
};

struct UnkStruct_D_01E3CD44 {
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
    virtual void vfunc_C4(void *, UnkStruct_0037C1C0_a1 *);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_0037BCF0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_0037B6C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_func_0037BCF0 func_0037BCF0;
extern UnkStruct_func_0037B6C0 func_0037B6C0;

extern "C" void qsort(void *, int, int, void *);

// 0x0037C1C0
extern "C" int func_0037C1C0(int n0, UnkStruct_0037C1C0_a1 * p0)
{
    if (n0 > 0) {
        int t0 = p0->field_1920;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_C4(&func_0037BCF0, p0);
        int t1 = p0->field_1920;
        if (t0 >= t1) {
        } else {
            qsort(((char *)p0 + 0x60), t1, 80, &func_0037B6C0);
        }
    } else {
    }
    p0->field_1940 = 1;
    return 1;
}
