// func_0041E3C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (break vs return exits per retail blocks, case-3 else-if chain, field_10 test flipped, == -2 arm first, D_01EA2974 store before D_01EA2980 read).

// lifter variant 0
// func_0041E3C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EGlobalStrings {};
enum EB3MessageBoxType {};

class CB3ErrorPage;
struct UnkStruct_0041E3C0;
struct UnkStruct_0041E3C0_11;
struct UnkStruct_0041E3C0_12;
struct UnkStruct_0041E3C0_13;
struct UnkStruct_0041E3C0_14;
struct UnkStruct_0041E3C0_15;
struct UnkStruct_0041E3C0_5;
struct UnkStruct_0041E3C0_9;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E3CD48;
struct UnkStruct_D_01E3D38F;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01EA2F0C;
struct UnkStruct_D_01EA2F0E;

class CB3ErrorPage {
public:
    void Prepare(EGlobalStrings, EGlobalStrings, EB3MessageBoxType);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2F0C {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2F0E {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D38F {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual int vfunc_58();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041E3C0_5 {
    unsigned char pad_0[0x58];
    int field_58;
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
    UnkStruct_0041E3C0_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041E3C0_9 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041E3C0_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0041E3C0_12 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0041E3C0_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0041E3C0_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0041E3C0_15 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E3CD48 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041E3C0 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
};

extern UnkStruct_D_01EA2F0C D_01EA2F0C;
extern UnkStruct_D_01EA2F0E D_01EA2F0E;
extern UnkStruct_D_01E3D38F D_01E3D38F;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern CB3ErrorPage D_01E95B4C;
extern UnkStruct_D_01E3CD48 D_01E3CD48;
extern UnkStruct_D_01E32AE0 D_01E32AE0;

extern "C" int func_00352130(void *, int, void *, int);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00270D00(void *);

// 0x0041E3C0
extern "C" void func_0041E3C0(UnkStruct_0041E3C0 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        self->field_10 = 0;
        D_01EA2F0C.field_0 = 0;
        D_01EA2F0E.field_0 = 0;
        if (D_01E3D38F.field_0 == 0) {
            self->field_10 = 1;
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
            D_01E95B4C.Prepare((EGlobalStrings)2869, (EGlobalStrings)110, (EB3MessageBoxType)2);
        } else if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58() == -2) {
            func_00352130(&D_01E95B4C, 2869, &D_01E3CD48, 2);
        } else if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58() == -56) {
            D_01E95B4C.Prepare((EGlobalStrings)2869, (EGlobalStrings)2870, (EB3MessageBoxType)7);
        } else if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58() != -12) {
            D_01E95B4C.Prepare((EGlobalStrings)2869, (EGlobalStrings)110, (EB3MessageBoxType)2);
            self->field_10 = 1;
        } else {
            D_01E95B4C.Prepare((EGlobalStrings)2869, (EGlobalStrings)2868, (EB3MessageBoxType)7);
        }
        break;
    case 5:
        switch (p2) {
        case 1:
            if (self->field_10 != 0) {
                func_00270D00(&D_01E32AE0);
                UnkStruct_0041E3C0_14 * r18 = (UnkStruct_0041E3C0_14 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E0BA2B41647);
                if (D_01EA2974.field_0 != r18) {
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r18, 0);
                    void * t4 = D_01EA2974.field_0;
                    D_01EA2974.field_0 = (void *)r18;
                    UnkStruct_0041E3C0_9 * t5 = D_01EA2980.field_0;
                    if (t5 != 0) {
                        D_01EA2984.field_0 = t5->field_20;
                        if (r18 != 0) {
                            r18->field_8 = t5->field_20;
                        }
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t4, 0);
                }
                self->field_10 = 0;
                return;
            }
            if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58() == -2) {
                func_00270D00(&D_01E32AE0);
                UnkStruct_0041E3C0_13 * r14 = (UnkStruct_0041E3C0_13 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E0BA2B41647);
                if (D_01EA2974.field_0 == r14) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r14, 0);
                void * t2 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r14;
                UnkStruct_0041E3C0_9 * t3 = D_01EA2980.field_0;
                if (t3 != 0) {
                    D_01EA2984.field_0 = t3->field_20;
                    if (r14 != 0) {
                        r14->field_8 = t3->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
            } else {
                UnkStruct_0041E3C0_11 * r10 = (UnkStruct_0041E3C0_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8506BD2);
                if (D_01EA2974.field_0 == r10) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r10, 0);
                void * t0 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r10;
                UnkStruct_0041E3C0_9 * t1 = D_01EA2980.field_0;
                if (t1 != 0) {
                    D_01EA2984.field_0 = t1->field_20;
                    if (r10 != 0) {
                        r10->field_8 = t1->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            }
            break;
        case 3:
            func_00270D00(&D_01E32AE0);
            UnkStruct_0041E3C0_15 * r22 = (UnkStruct_0041E3C0_15 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E0BA2B41647);
            if (D_01EA2974.field_0 == r22) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r22, 0);
            void * t6 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r22;
            UnkStruct_0041E3C0_9 * t7 = D_01EA2980.field_0;
            if (t7 != 0) {
                D_01EA2984.field_0 = t7->field_20;
                if (r22 != 0) {
                    r22->field_8 = t7->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t6, 0);
            break;
        }
        break;
    case 2:
        return;
    }
}
