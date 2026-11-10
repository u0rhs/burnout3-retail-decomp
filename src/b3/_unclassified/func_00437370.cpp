// func_00437370 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (fixed the draft's declarations (one ReleaseCurrentMenu, GetStateFromID__6CGtFSMFUl returning the object type); swap blocks read D_01EA2980 after the D_01EA2974 store; func_00436880 gets the case value (retail reuses the compare register a1)).

// lifter variant 0
// func_00437370 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3InputManager;
struct UnkStruct_00437370;
struct UnkStruct_00437370_10;
struct UnkStruct_00437370_11;
struct UnkStruct_00437370_7;
struct UnkStruct_00437370_9;
struct UnkStruct_D_004F50A0;
struct UnkStruct_D_01E90230;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90430;
struct UnkStruct_D_01E98460;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECD520;

class CB3InputManager {
public:
    float GetDeadInputTime(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F50A0 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90430 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90230 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual void vfunc_18(UnkStruct_00437370_9 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00437370_7 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00437370_7 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00437370_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00437370_10 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_00437370_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E98460 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00437370 {
    unsigned char pad_0[0x10];
    float field_10;
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01E90230 D_01E90230;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E98460 D_01E98460;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);  // CB3MenuPageManager::ReleaseCurrentMenu()
extern "C" int func_00436C20(void *);
extern "C" void Update__24CB3MemCardControllerBaseFv(void *);
extern "C" UnkStruct_00437370_9 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00436880(void *, int, int);

// 0x00437370
extern "C" void func_00437370(UnkStruct_00437370 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        self->field_10 = D_004F50A0.field_0;
        func_00436C20(&D_01E98460);
        break;
    case 4: {
        Update__24CB3MemCardControllerBaseFv(&D_01ECD520);
        if (D_004F50C0.GetDeadInputTime(-1) <= 30.0f) {
            break;
        }
        if (D_01E90430.field_0 != 0) {
            ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
        }
        D_01E90230.field_0 = 0x94413E2ECD875AF7;
        UnkStruct_00437370_9 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x944140D320FEDE85);
        if (D_01EA2974.field_0 == r) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r;
        UnkStruct_00437370_7 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r != 0) {
                r->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        break;
    }
    case 5:
        switch (p2) {
        case 1: {
            if (D_01E90430.field_0 != 0) {
                ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
            }
            D_01E90230.field_0 = 0x60D6B07214065F27;
            UnkStruct_00437370_9 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA75E03E9D1);
            if (D_01EA2974.field_0 == r) {
                break;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r;
            UnkStruct_00437370_7 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r != 0) {
                    r->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            break;
        }
        case 49:
            func_00436880(&D_01E98460, 49, p1);
            break;
        case 46:
            func_00436880(&D_01E98460, 46, p1);
            break;
        case 47:
            func_00436880(&D_01E98460, 47, p1);
            break;
        case 50:
            func_00436880(&D_01E98460, 50, p1);
            break;
        case 58:
            func_00436880(&D_01E98460, 58, p1);
            break;
        case 56:
            func_00436880(&D_01E98460, 56, p1);
            break;
        case 57:
            func_00436880(&D_01E98460, 57, p1);
            break;
        case 54:
            func_00436880(&D_01E98460, 54, p1);
            break;
        }
        break;
    }
}
