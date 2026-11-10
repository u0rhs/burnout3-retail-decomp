// func_00393740 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (D_01EA2980 read after the D_01EA2974 store (same inline as StartFormat__24CB3MemCardControllerBaseFv)).

// func_00393740 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00393740;
struct UnkStruct_00393740_3;
struct UnkStruct_00393740_5;
struct UnkStruct_00393740_6;
struct UnkStruct_D_00516E40;
struct UnkStruct_D_005179F0;
struct UnkStruct_D_00522660;
struct UnkStruct_D_00665E50;
struct UnkStruct_D_00665E51;
struct UnkStruct_D_01E78E50;
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
    virtual void vfunc_18(UnkStruct_00393740_5 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00393740_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00393740_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00393740_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00393740_6 {
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

struct UnkStruct_D_01E78E50 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00393740 {
    unsigned char pad_0[0x40];
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
extern UnkStruct_D_01E78E50 D_01E78E50;

extern "C" UnkStruct_00393740_5 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void Stop__8CGtTimerFv(void *);
extern "C" void Start__8CGtTimerFv(void *);
extern "C" void func_00276A10(void *);

// 0x00393740
extern "C" void func_00393740(UnkStruct_00393740 * self)
{
    UnkStruct_00393740_5 * r0 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413EDB6B01A028);
    if (D_01EA2974.field_0 != r0) {
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r0;
        UnkStruct_00393740_3 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r0 != 0) {
                r0->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
    }
    self->field_40 = 3;
    ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(17, 0);
    ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(17, 0);
    D_00665E50.field_0 = 0;
    if (D_00665E50.field_0 != 0) {
        Stop__8CGtTimerFv(&D_00522660);
    } else {
        if (D_00665E51.field_0 == 0) {
            Start__8CGtTimerFv(&D_00522660);
        }
    }
    func_00276A10(&D_01E78E50);
}
