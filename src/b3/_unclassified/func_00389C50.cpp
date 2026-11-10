// func_00389C50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (swap block: store D_01EA2974 before loading D_01EA2980; if (vfunc_C0()!=0) 16-arm first; else-if tail).

// lifter variant 0
// func_00389C50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00389C50;
struct UnkStruct_00389C50_10;
struct UnkStruct_00389C50_11;
struct UnkStruct_00389C50_3;
struct UnkStruct_00389C50_5;
struct UnkStruct_00389C50_6;
struct UnkStruct_D_00516E40;
struct UnkStruct_D_005179F0;
struct UnkStruct_D_00522660;
struct UnkStruct_D_00665E50;
struct UnkStruct_D_00665E51;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_01EA2974 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2970 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_00389C50_5 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00389C50_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00389C50_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00389C50_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00389C50_6 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_00516E40 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_005179F0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00389C50_10 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_00389C50_11 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_00665E50 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E51 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00389C50 {
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
    unsigned char pad_4[0x3C];
    int field_40;
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_005179F0 D_005179F0;
extern UnkStruct_D_00665E50 D_00665E50;
extern UnkStruct_D_00665E51 D_00665E51;
extern UnkStruct_D_00522660 D_00522660;

extern "C" UnkStruct_00389C50_5 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void Stop__8CGtTimerFv(void *);
extern "C" void Start__8CGtTimerFv(void *);

extern "C" void func_00389C50(UnkStruct_00389C50 * self)
{
    UnkStruct_00389C50_5 * r0 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413EDB6B01A028);
    if (D_01EA2974.field_0 != r0) {
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r0;
        UnkStruct_00389C50_3 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r0 != 0) {
                r0->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
    }
    if (self->vfunc_C0() != 0) {
        ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(16, 0);
        ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(16, 0);
    } else {
        ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(17, 0);
        ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(17, 0);
        self->field_40 = 2;
    }
    D_00665E50.field_0 = 0;
    if (D_00665E50.field_0 != 0) {
        Stop__8CGtTimerFv(&D_00522660);
    } else if (D_00665E51.field_0 == 0) {
        Start__8CGtTimerFv(&D_00522660);
    }
}
