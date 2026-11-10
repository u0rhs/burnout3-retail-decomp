// func_003906F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (store D_01EA2974 = r2 before reading D_01EA2980 (statement order)).

// lifter variant 0
// func_003906F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003906F0_1;
struct UnkStruct_003906F0_2;
struct UnkStruct_003906F0_6;
struct UnkStruct_003906F0_8;
struct UnkStruct_003906F0_9;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECD9F0;

struct UnkStruct_D_0051BA88 {
    UnkStruct_003906F0_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003906F0_1 {
    unsigned char pad_0[0x1B4];
    UnkStruct_003906F0_2 * field_1B4;
};

struct UnkStruct_003906F0_2 {
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
    virtual void vfunc_70();
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
    virtual int vfunc_9C();
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
    virtual void vfunc_18(UnkStruct_003906F0_8 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003906F0_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003906F0_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003906F0_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003906F0_9 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01ECD9F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;

extern "C" void func_0042F0F0(void *);
extern "C" UnkStruct_003906F0_8 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003906F0
extern "C" void func_003906F0(void *a0 /* passed by every caller, not read here */)
{
    int r0 = D_0051BA88.field_0->field_1B4->vfunc_9C();
    if (r0 != 0) {
        func_0042F0F0(&D_01ECD9F0);
    }
    UnkStruct_003906F0_8 * r2 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x943D84EEB02101E9);
    if (D_01EA2974.field_0 == r2) return;
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
    void * t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r2;
    UnkStruct_003906F0_6 * t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r2 != 0) {
            r2->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
}
