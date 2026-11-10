// OnEndOfChallenge__12CB3ChallengeFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (load D_01EA2980 into its local after the D_01EA2974 store (declaration order sets registers)).

// lifter variant 0
// OnEndOfChallenge__12CB3ChallengeFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003BA780_3;
struct UnkStruct_003BA780_5;
struct UnkStruct_003BA780_6;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051A6A8;
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
    virtual void vfunc_18(UnkStruct_003BA780_5 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003BA780_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003BA780_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003BA780_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003BA780_6 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_0051A6A8 D_0051A6A8;

extern "C" void func_00131F10(void *, void *);
extern "C" UnkStruct_003BA780_5 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003BA780
extern "C" void OnEndOfChallenge__12CB3ChallengeFv()
{
    func_00131F10(&D_004EE040, &D_0051A6A8);
    UnkStruct_003BA780_5 * r1 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
    if (D_01EA2974.field_0 == r1) return;
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r1, 0);
    void * t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r1;
    UnkStruct_003BA780_3 * t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r1 != 0) {
            r1->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
}
