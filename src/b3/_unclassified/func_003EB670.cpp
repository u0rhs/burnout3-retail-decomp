// func_003EB670 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (inner switch returns->break (break vs return exits), D_01EA2974 store before D_01EA2980 read, phantom args dropped).

// lifter variant 0
// func_003EB670 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003EB670_5;
struct UnkStruct_003EB670_7;
struct UnkStruct_003EB670_8;
struct UnkStruct_D_0051A999;
struct UnkStruct_D_01E96424;
struct UnkStruct_D_01E96428;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECD520;

struct UnkStruct_D_01E96428 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A999 {
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
    virtual void vfunc_18(UnkStruct_003EB670_7 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003EB670_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EB670_5 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EB670_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EB670_8 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E96424 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E96428 D_01E96428;
extern UnkStruct_D_0051A999 D_0051A999;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E96424 D_01E96424;
extern UnkStruct_D_01ECD520 D_01ECD520;

extern "C" int func_003EF7F0(void *);
extern "C" void Update__24CB3MemCardControllerBaseFv(void *);
extern "C" void func_0041FAD0();
extern "C" UnkStruct_003EB670_7 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_003EDFD0(void *, int);
extern "C" void func_003EDEE0(void *);
extern "C" void func_003EDE60(void *);  // [G] callee ignores a0, but retail passes it
extern "C" void OnKeyboardCancel__27CB3MyBurnoutProfileSavePageFv(void *);

// 0x003EB670
extern "C" void func_003EB670(int n0, int p0, int p1, int p2, int p3)
{
    switch (p0) {
    case 3:
        D_01E96428.field_0 = (p3 != 0);
        func_003EF7F0(&D_01E96424);
        break;
    case 4:
        Update__24CB3MemCardControllerBaseFv(&D_01ECD520);
        break;
    case 5:
        switch (p2) {
        case 0:
            return;
        case 3:
            if (D_0051A999.field_0 != 0) {
                D_0051A999.field_0 = 0;
                func_0041FAD0();
                break;
            }
            UnkStruct_003EB670_7 * r3 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC1552CB1E0);
            if (D_01EA2974.field_0 == r3) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r3, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r3;
            UnkStruct_003EB670_5 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r3 != 0) {
                    r3->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            break;
        case 49:
            func_003EDFD0(&D_01E96424, 49);
            break;
        case 48:
            func_003EDFD0(&D_01E96424, 48);
            break;
        case 46:
            func_003EDFD0(&D_01E96424, 46);
            break;
        case 50:
            func_003EDFD0(&D_01E96424, 50);
            break;
        case 53:
            func_003EDFD0(&D_01E96424, 53);
            break;
        case 52:
            func_003EDFD0(&D_01E96424, 52);
            break;
        case 54:
            func_003EDFD0(&D_01E96424, 54);
            break;
        case 55:
            func_003EDFD0(&D_01E96424, 55);
            break;
        case 56:
            func_003EDFD0(&D_01E96424, 56);
            break;
        case 57:
            func_003EDFD0(&D_01E96424, 57);
            break;
        case 60:
            func_003EDFD0(&D_01E96424, 60);
            break;
        case 59:
            func_003EDFD0(&D_01E96424, 59);
            break;
        case 47:
            func_003EDFD0(&D_01E96424, 47);
            break;
        case 58:
            func_003EDFD0(&D_01E96424, 58);
            break;
        case 27:
            func_003EDEE0(&D_01E96424);
            break;
        case 25:
            func_003EDE60(&D_01E96424);
            break;
        case 26:
            OnKeyboardCancel__27CB3MyBurnoutProfileSavePageFv(&D_01E96424);
            break;
        case 51:
            func_003EDFD0(&D_01E96424, 51);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
