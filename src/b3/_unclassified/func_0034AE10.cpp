// func_0034AE10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (4 state compares merged with || into one block ending in break; inlined swap reads D_01EA2980 after the D_01EA2974 store).

// lifter variant 0
// func_0034AE10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0034AE10_5;
struct UnkStruct_0034AE10_7;
struct UnkStruct_0034AE10_8;
struct UnkStruct_0034AE10_9;
struct UnkStruct_D_0051BA90;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3C620;
struct UnkStruct_D_01E6548B;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_0051BA90 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E6548B {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

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
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0034AE10_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034AE10_5 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034AE10_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034AE10_8 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0034AE10_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E3C620 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA90 D_0051BA90;
extern UnkStruct_D_01E6548B D_01E6548B;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E3C620 D_01E3C620;
extern UnkStruct_D_01E32AE0 D_01E32AE0;

extern "C" int func_0022D2D0(void *);
extern "C" void func_00270D00(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x0034AE10
extern "C" void func_0034AE10(void *n0_, int p0)
{
    int n0 = (int)n0_;
    switch (p0) {
    case 1:
        if (func_0022D2D0(&D_01E3C620) == 4 || func_0022D2D0(&D_01E3C620) == 6 || func_0022D2D0(&D_01E3C620) == 3 || func_0022D2D0(&D_01E3C620) == 5) {
            func_00270D00(&D_01E32AE0);
            D_0051BA90.field_0 = 1;
            D_01E6548B.field_0 = 1;
            break;
        }
        func_00270D00(&D_01E32AE0);
        UnkStruct_0034AE10_7 * r9 = (UnkStruct_0034AE10_7 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F847A2EA);
        if (D_01EA2974.field_0 == r9) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r9, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r9;
        UnkStruct_0034AE10_5 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r9 != 0) {
                r9->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        break;
    case 3:
        func_00270D00(&D_01E32AE0);
        UnkStruct_0034AE10_9 * r13 = (UnkStruct_0034AE10_9 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F847A2EA);
        if (D_01EA2974.field_0 == r13) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r13, 0);
        void * t2 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r13;
        UnkStruct_0034AE10_5 * t3 = D_01EA2980.field_0;
        if (t3 != 0) {
            D_01EA2984.field_0 = t3->field_20;
            if (r13 != 0) {
                r13->field_8 = t3->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
        break;
    default:
        break;
    }
}
