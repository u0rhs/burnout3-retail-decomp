// func_003EC7E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (nested switch in source order with literal case values passed, swap block as a static inline helper (sibling of func_003EB0F0)).

// func_003EC7E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003EC7E0_4;
struct UnkStruct_003EC7E0_6;
struct UnkStruct_003EC7E0_7;
struct UnkStruct_003EC7E0_8;
struct UnkStruct_003EC7E0_9;
struct UnkStruct_D_0051A998;
struct UnkStruct_D_01E96450;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECD520;

struct UnkStruct_D_0051A998 {
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
    virtual void vfunc_18(UnkStruct_003EC7E0_6 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003EC7E0_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC7E0_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC7E0_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EC7E0_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_003EC7E0_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EC7E0_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E96450 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051A998 D_0051A998;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E96450 D_01E96450;
extern UnkStruct_D_01ECD520 D_01ECD520;

extern "C" int func_003F55E0(void *);
extern "C" void Update__24CB3MemCardControllerBaseFv(void *);
extern "C" void OnKeyboardCancel__32CB3MyBurnoutProfileCreateNewPageFv(void *);
extern "C" void func_003F40D0(void *);
extern "C" void func_003F4160(void *);
extern "C" void func_003F4200(void *, int);
extern "C" UnkStruct_003EC7E0_6 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// [G] the inlined swap block (as in CB3MyBurnoutRewardsState::Action, 0x3EC240)
static inline void func_003EC7E0_inl1(unsigned long id)
{
    UnkStruct_003EC7E0_6 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t1 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003EC7E0_4 * t2 = D_01EA2980.field_0;
    if (t2 != 0) {
        D_01EA2984.field_0 = t2->field_20;
        if (r != 0) {
            r->field_8 = t2->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, 0);
}

// 0x003EC7E0
extern "C" void func_003EC7E0(void * self, int p0, void * p1, int p2)
{
    switch (p0) {
    case 3:
        func_003F55E0(&D_01E96450);
        break;
    case 4:
        Update__24CB3MemCardControllerBaseFv(&D_01ECD520);
        break;
    case 5:
        switch (p2) {
        case 0:
            break;
        case 3:
            if (D_0051A998.field_0 == 0) {
                func_003EC7E0_inl1(0x94413FC1552CB1E0);
            } else {
                func_003EC7E0_inl1(0x94413E2ECD875C80);
            }
            break;
        case 4:
            D_0051A998.field_0 = 0;
            func_003EC7E0_inl1(0x94413FC035B0F871);
            break;
        case 0x31:
            func_003F4200(&D_01E96450, 0x31);
            break;
        case 0x30:
            func_003F4200(&D_01E96450, 0x30);
            break;
        case 0x2E:
            func_003F4200(&D_01E96450, 0x2E);
            break;
        case 0x32:
            func_003F4200(&D_01E96450, 0x32);
            break;
        case 0x35:
            func_003F4200(&D_01E96450, 0x35);
            break;
        case 0x34:
            func_003F4200(&D_01E96450, 0x34);
            break;
        case 0x36:
            func_003F4200(&D_01E96450, 0x36);
            break;
        case 0x37:
            func_003F4200(&D_01E96450, 0x37);
            break;
        case 0x38:
            func_003F4200(&D_01E96450, 0x38);
            break;
        case 0x39:
            func_003F4200(&D_01E96450, 0x39);
            break;
        case 0x3C:
            func_003F4200(&D_01E96450, 0x3C);
            break;
        case 0x3B:
            func_003F4200(&D_01E96450, 0x3B);
            break;
        case 0x2F:
            func_003F4200(&D_01E96450, 0x2F);
            break;
        case 0x3A:
            func_003F4200(&D_01E96450, 0x3A);
            break;
        case 0x33:
            func_003F4200(&D_01E96450, 0x33);
            break;
        case 0x1B:
            func_003F4160(&D_01E96450);
            break;
        case 0x19:
            func_003F40D0(&D_01E96450);
            break;
        case 0x1A:
            OnKeyboardCancel__32CB3MyBurnoutProfileCreateNewPageFv(&D_01E96450);
            break;
        }
        break;
    }
}
