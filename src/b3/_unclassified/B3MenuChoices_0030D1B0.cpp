// CB3MenuChoices::RequestNewGameMode() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuChoices.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (nested switch(field_C) default-first; const ptr to D_0051A9E0 in case 4).

// lifter variant 0
// CB3MenuChoices::RequestNewGameMode() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuChoices.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3MenuChoices;
struct UnkStruct_0030D1B0_10;
struct UnkStruct_0030D1B0_7;
struct UnkStruct_0030D1B0_9;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051A9BF;
struct UnkStruct_D_0051A9E0;
struct UnkStruct_D_006481A0;
struct UnkStruct_D_00665E52;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECD9F0;

struct UnkStruct_D_0051A9BF {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A9E0 {
    unsigned long field_0;
    unsigned long field_8;
    unsigned char pad_10[0x60];
    int field_70;
    unsigned char pad_74[0x2C];
    int field_A0;
};

struct UnkStruct_D_00665E52 {
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
    virtual void vfunc_18(UnkStruct_0030D1B0_9 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0030D1B0_7 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030D1B0_7 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0030D1B0_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0030D1B0_10 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_006481A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD9F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3MenuChoices {
public:
    void RequestNewGameMode();
    int RequestOnePlayerGameMode(int);
    int RequestCrashPartyGameMode();
    int RequestTwoPlayerGameMode(int);
    int RequestOnlineGameMode();

    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned char pad_18[0x68];
    unsigned long field_80;
};

extern UnkStruct_D_0051A9BF D_0051A9BF;
extern UnkStruct_D_0051A9E0 D_0051A9E0;
extern UnkStruct_D_00665E52 D_00665E52;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_006481A0 D_006481A0;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" void * memset(void *, int, unsigned int);
extern "C" void func_0014EC10(void *);
extern "C" int func_0030C560(CB3MenuChoices *, signed char);
extern "C" void func_0030CF90(CB3MenuChoices *, void *);
extern "C" UnkStruct_0030D1B0_9 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_0042FBC0(void *);
extern "C" void func_00131F10(void *, void *);

// 0x0030D1B0
void CB3MenuChoices::RequestNewGameMode()
{
    func_0014EC10(&D_006481A0);
    void * v4;
    switch (field_4) {
    case 0:
        v4 = (void *)func_0030C560(this, D_0051A9BF.field_0);
        break;
    case 1:
        v4 = (void *)RequestOnePlayerGameMode(0);
        break;
    case 2:
        switch (field_C) {
        default:
            v4 = (void *)RequestTwoPlayerGameMode(0);
            break;
        case 4:
            v4 = (void *)RequestCrashPartyGameMode();
            break;
        }
        break;
    case 3:
        v4 = (void *)RequestOnlineGameMode();
        break;
    case 4: {
        v4 = &D_0051A9E0;
        memset(v4, 0, 432);
        field_14 = 1;
        ((UnkStruct_D_0051A9E0 *)v4)->field_A0 = field_14;
        ((UnkStruct_D_0051A9E0 *)v4)->field_8 = field_80;
        ((UnkStruct_D_0051A9E0 *)v4)->field_70 = 0;
        ((UnkStruct_D_0051A9E0 *)v4)->field_0 = 0;
        break;
    }
    default:
        v4 = 0;
        break;
    }
    func_0030CF90(this, v4);
    D_00665E52.field_0 = 0;
    field_0 = 2;
    UnkStruct_0030D1B0_9 * r8 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
    if (D_01EA2974.field_0 != r8) {
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r8, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r8;
        UnkStruct_0030D1B0_7 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r8 != 0) {
                r8->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
    }
    func_0042FBC0(&D_01ECD9F0);
    func_00131F10(&D_004EE040, v4);
}
