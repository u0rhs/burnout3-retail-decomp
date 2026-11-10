// func_003960A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (D_01EA2970..2984 one object (vptr, field_4, field_10, field_14); calls through a cast pointer stay virtual; no early return).

// func_003960A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003960A0_10;
struct UnkStruct_003960A0_2;
struct UnkStruct_003960A0_3;
struct UnkStruct_003960A0_7;
struct UnkStruct_003960A0_9;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_00665E53;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECD9F0;

struct UnkStruct_D_00665E53 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003960A0_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003960A0_2 {
    unsigned char pad_0[0x1B8];
    UnkStruct_003960A0_3 * field_1B8;
};

struct UnkStruct_003960A0_3 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
};

struct UnkStruct_003960A0_7 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2970 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_003960A0_9 *, int);
    virtual void vfunc_1C(UnkStruct_003960A0_9 *, int);
    UnkStruct_003960A0_9 * field_4;
    unsigned char pad_8[0x8];
    UnkStruct_003960A0_7 * field_10;
    float field_14;
};

struct UnkStruct_003960A0_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003960A0_10 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01ECD9F0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_00665E53 D_00665E53;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;

extern "C" void func_0042F0F0(void *);
extern "C" UnkStruct_003960A0_9 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003960A0
extern "C" void func_003960A0()
{
    if (D_00665E53.field_0 == 0) {
        D_0051BA88.field_0->field_1B8->vfunc_24();
        func_0042F0F0(&D_01ECD9F0);
        UnkStruct_003960A0_9 * r2 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413EA3518C496C);
        if (D_01EA2970.field_4 != r2) {
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
            UnkStruct_003960A0_9 * old = D_01EA2970.field_4;
            D_01EA2970.field_4 = r2;
            if (D_01EA2970.field_10 != 0) {
                D_01EA2970.field_14 = D_01EA2970.field_10->field_20;
                if (r2 != 0) {
                    r2->field_8 = D_01EA2970.field_10->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(old, 0);
        }
    }
}
