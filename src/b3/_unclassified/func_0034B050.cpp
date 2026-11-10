// func_0034B050 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (case 1 as if (AC) {AD / AE&&!vfunc_70 / vfunc_D8 else-if chain} else {strcpy...}; swap blocks return on equal, D_01EA2974 store before D_01EA2980 read; case 22 inner switch).

// lifter variant 0
// func_0034B050 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EGlobalStrings {};
enum EB3MessageBoxType {};

class CB3ErrorPage;
class CB3OnlineSelectPersonaPage;
struct UnkStruct_0034B050;
struct UnkStruct_0034B050_10;
struct UnkStruct_0034B050_11;
struct UnkStruct_0034B050_12;
struct UnkStruct_0034B050_13;
struct UnkStruct_0034B050_14;
struct UnkStruct_0034B050_15;
struct UnkStruct_0034B050_16;
struct UnkStruct_0034B050_17;
struct UnkStruct_0034B050_18;
struct UnkStruct_0034B050_19;
struct UnkStruct_0034B050_6;
struct UnkStruct_0034B050_8;
struct UnkStruct_0034B050_9;
struct UnkStruct_0034B050_e0;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E94C40;
struct UnkStruct_D_01E9F9F4;
struct UnkStruct_D_01E9FBA8;
struct UnkStruct_D_01EA07D0;
struct UnkStruct_D_01EA2874;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

class CB3OnlineSelectPersonaPage {
public:
    void OnKeyboardDone();
    void OnKeyboardShow();
    void OnKeyboardCancel();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3ErrorPage {
public:
    void Prepare(EGlobalStrings, EGlobalStrings, EB3MessageBoxType);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2874 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual int vfunc_70();
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
    virtual int vfunc_D8();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    UnkStruct_0034B050_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034B050_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034B050_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_9 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_0034B050_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_11 {
    unsigned char pad_0[0x2C];
    int field_2C;
    unsigned char pad_30[0x40];
    int field_70;
    unsigned char pad_74[0x64];
    int field_D8;
};

struct UnkStruct_0034B050_12 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_15 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_16 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_17 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_18 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_19 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0034B050_e0 {
    unsigned char pad_0[0x20];
};

struct UnkStruct_D_01E94C40 {
    UnkStruct_0034B050_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_01EA07D0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9F9F4 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9FBA8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0034B050 {
    unsigned char pad_0[0xAC];
    unsigned char field_AC;
    unsigned char field_AD;
    unsigned char field_AE;
    unsigned char pad_AF[0x1];
    int field_B0;
    int field_B4;
};

extern UnkStruct_D_01EA2874 D_01EA2874;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E94C40 D_01E94C40;
extern UnkStruct_D_01EA07D0 D_01EA07D0;
extern UnkStruct_D_01E9F9F4 D_01E9F9F4;
extern UnkStruct_D_01E9FBA8 D_01E9FBA8;
extern CB3OnlineSelectPersonaPage D_01EA2870;
extern CB3ErrorPage D_01E95B4C;

extern "C" char * strcpy(char *, const char *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int Prepare__26CB3OnlineUploadResultsPageFv(void *);
extern "C" int func_0037F640(void *, int);
extern "C" int func_0037CF00(void *, int, int);

// 0x0034B050
extern "C" void func_0034B050(UnkStruct_0034B050 * self, int p0)
{
    switch (p0) {
    case 1:
        if (self->field_AC != 0) {
            if (self->field_AD != 0) {
                self->field_B4 = 8;
                Prepare__26CB3OnlineUploadResultsPageFv(&D_01EA07D0);
            } else if (self->field_AE != 0 && ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_70() == 0) {
                self->field_AE = 0;
                UnkStruct_0034B050_8 * r1 = (UnkStruct_0034B050_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8506AFE);
                if (D_01EA2974.field_0 == r1) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r1, 1);
                void * o1 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r1;
                UnkStruct_0034B050_6 * c1 = D_01EA2980.field_0;
                if (c1 != 0) {
                    D_01EA2984.field_0 = c1->field_20;
                    if (r1 != 0) {
                        r1->field_8 = c1->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(o1, 1);
            } else if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() != 0) {
                UnkStruct_0034B050_8 * r2 = (UnkStruct_0034B050_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8512871);
                if (D_01EA2974.field_0 == r2) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 1);
                void * o2 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r2;
                UnkStruct_0034B050_6 * c2 = D_01EA2980.field_0;
                if (c2 != 0) {
                    D_01EA2984.field_0 = c2->field_20;
                    if (r2 != 0) {
                        r2->field_8 = c2->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(o2, 1);
            } else {
                UnkStruct_0034B050_8 * r3 = (UnkStruct_0034B050_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8512871);
                if (D_01EA2974.field_0 == r3) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r3, 0);
                void * o3 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r3;
                UnkStruct_0034B050_6 * c3 = D_01EA2980.field_0;
                if (c3 != 0) {
                    D_01EA2984.field_0 = c3->field_20;
                    if (r3 != 0) {
                        r3->field_8 = c3->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(o3, 0);
            }
        } else {
            strcpy((char *)((char *)self + 0x74), (const char *)((char *)&D_01E94C40.field_0[D_01EA2874.field_0] + 0xDC3C));
            self->field_AC = 1;
            if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() != 0) {
                if (self->field_AE != 0 && ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_70() == 0) {
                    self->field_AE = 0;
                    UnkStruct_0034B050_8 * r4 = (UnkStruct_0034B050_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8506AFE);
                    if (D_01EA2974.field_0 == r4) {
                        return;
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r4, 1);
                    void * o4 = D_01EA2974.field_0;
                    D_01EA2974.field_0 = (void *)r4;
                    UnkStruct_0034B050_6 * c4 = D_01EA2980.field_0;
                    if (c4 != 0) {
                        D_01EA2984.field_0 = c4->field_20;
                        if (r4 != 0) {
                            r4->field_8 = c4->field_20;
                        }
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(o4, 1);
                } else {
                    UnkStruct_0034B050_8 * r5 = (UnkStruct_0034B050_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8512871);
                    if (D_01EA2974.field_0 == r5) {
                        return;
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 1);
                    void * o5 = D_01EA2974.field_0;
                    D_01EA2974.field_0 = (void *)r5;
                    UnkStruct_0034B050_6 * c5 = D_01EA2980.field_0;
                    if (c5 != 0) {
                        D_01EA2984.field_0 = c5->field_20;
                        if (r5 != 0) {
                            r5->field_8 = c5->field_20;
                        }
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(o5, 1);
                }
            } else {
                UnkStruct_0034B050_8 * r6 = (UnkStruct_0034B050_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8512871);
                if (D_01EA2974.field_0 == r6) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r6, 0);
                void * o6 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r6;
                UnkStruct_0034B050_6 * c6 = D_01EA2980.field_0;
                if (c6 != 0) {
                    D_01EA2984.field_0 = c6->field_20;
                    if (r6 != 0) {
                        r6->field_8 = c6->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(o6, 0);
            }
        }
        break;
    case 3:
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_2C();
        UnkStruct_0034B050_8 * r7 = (UnkStruct_0034B050_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC035B0F871);
        if (D_01EA2974.field_0 == r7) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r7, 0);
        void * o7 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r7;
        UnkStruct_0034B050_6 * c7 = D_01EA2980.field_0;
        if (c7 != 0) {
            D_01EA2984.field_0 = c7->field_20;
            if (r7 != 0) {
                r7->field_8 = c7->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(o7, 0);
        break;
    case 43:
        self->field_B4 = 6;
        func_0037F640(&D_01E9F9F4, 1);
        break;
    case 34:
        self->field_B4 = 5;
        func_0037CF00(&D_01E9FBA8, 0, 1);
        break;
    case 27:
        D_01EA2870.OnKeyboardDone();
        break;
    case 25:
        D_01EA2870.OnKeyboardShow();
        break;
    case 26:
        D_01EA2870.OnKeyboardCancel();
        break;
    case 22:
        self->field_B4 = 3;
        switch (self->field_B0) {
        case 0:
            return;
        case -5:
            D_01E95B4C.Prepare((EGlobalStrings)81, (EGlobalStrings)111, (EB3MessageBoxType)2);
            break;
        case -6:
            D_01E95B4C.Prepare((EGlobalStrings)81, (EGlobalStrings)112, (EB3MessageBoxType)2);
            break;
        case -12:
            D_01E95B4C.Prepare((EGlobalStrings)81, (EGlobalStrings)111, (EB3MessageBoxType)2);
            break;
        default:
            D_01E95B4C.Prepare((EGlobalStrings)81, (EGlobalStrings)113, (EB3MessageBoxType)2);
            break;
        }
        break;
    }
}
