// func_00390380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if (field_5D != 0) {...return 1;} return 0; store to D_01EA2974 before loading D_01EA2980).

// func_00390380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3ScoreFinishState {};

class CB3RaceCar;
struct UnkStruct_00390380;
struct UnkStruct_00390380_10;
struct UnkStruct_00390380_7;
struct UnkStruct_00390380_9;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0064EA78;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90430;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01EA2F0E;
struct UnkStruct_D_01ECD9F0;

class CB3RaceCar {
public:
    void SetFinished(EB3ScoreFinishState);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064EA78 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90430 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2F0E {
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
    virtual void vfunc_18(UnkStruct_00390380_9 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00390380_7 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00390380_7 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00390380_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00390380_10 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01ECD9F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00390380 {
    unsigned char pad_0[0x5D];
    unsigned char field_5D;
};

extern UnkStruct_D_0064EA78 D_0064EA78;
extern UnkStruct_D_01E90430 D_01E90430;
extern UnkStruct_D_01EA2F0E D_01EA2F0E;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern CB3RaceCar D_0064D3B0;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0051A6A8 D_0051A6A8;

extern "C" void ReleaseCurrentMenu__18CB3MenuPageManagerFv(void *);  // CB3MenuPageManager::ReleaseCurrentMenu()
extern "C" void func_0042F0F0(void *);
extern "C" void func_00131F10(void *, void *);
extern "C" UnkStruct_00390380_9 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00390380
extern "C" int func_00390380(UnkStruct_00390380 * self)
{
    if (self->field_5D != 0) {
    if (D_0064EA78.field_0 == 0) {
        D_0064D3B0.SetFinished((EB3ScoreFinishState)2);
        func_0042F0F0(&D_01ECD9F0);
    }
    if (D_01E90430.field_0 != 0) {
        ReleaseCurrentMenu__18CB3MenuPageManagerFv(&D_01E90240);
    }
    D_01EA2F0E.field_0 = 1;
    func_00131F10(&D_004EE040, &D_0051A6A8);
    UnkStruct_00390380_9 * r4 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
    if (D_01EA2974.field_0 != r4) {
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r4, 0);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r4;
        UnkStruct_00390380_7 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r4 != 0) {
                r4->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
    }
    return 1;
    }
    return 0;
}
