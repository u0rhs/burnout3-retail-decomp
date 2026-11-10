// func_0041FAD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else-if chain over the flag bytes, swap block as a static inline helper taking the event argument).

// func_0041FAD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0041FAD0_11;
struct UnkStruct_0041FAD0_13;
struct UnkStruct_0041FAD0_15;
struct UnkStruct_0041FAD0_16;
struct UnkStruct_0041FAD0_4;
struct UnkStruct_0041FAD0_6;
struct UnkStruct_0041FAD0_7;
struct UnkStruct_0041FAD0_9;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECDAC0;
struct UnkStruct_D_01ECDAC5;
struct UnkStruct_D_01ECDAC6;
struct UnkStruct_D_01ECDAC7;
struct UnkStruct_D_01ECDAC9;

struct UnkStruct_D_01ECDAC0 {
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
    virtual void vfunc_18(UnkStruct_0041FAD0_6 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0041FAD0_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041FAD0_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041FAD0_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0041FAD0_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_01ECDAC6 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041FAD0_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01ECDAC5 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041FAD0_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01ECDAC9 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041FAD0_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01ECDAC7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0041FAD0_15 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0041FAD0_16 {
    unsigned char pad_0[0x8];
    float field_8;
};

extern UnkStruct_D_01ECDAC0 D_01ECDAC0;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01ECDAC6 D_01ECDAC6;
extern UnkStruct_D_01ECDAC5 D_01ECDAC5;
extern UnkStruct_D_01ECDAC9 D_01ECDAC9;
extern UnkStruct_D_01ECDAC7 D_01ECDAC7;

extern "C" UnkStruct_0041FAD0_6 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// [G] the inlined swap block (as in CB3MyBurnoutRewardsState::Action, 0x3EC240), with the event argument
static inline void func_0041FAD0_inl1(unsigned long id, int k)
{
    UnkStruct_0041FAD0_6 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, k);
    void * t1 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_0041FAD0_4 * t2 = D_01EA2980.field_0;
    if (t2 != 0) {
        D_01EA2984.field_0 = t2->field_20;
        if (r != 0) {
            r->field_8 = t2->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, k);
}

// 0x0041FAD0
extern "C" void func_0041FAD0()
{
    if (D_01ECDAC0.field_0 != 0) {
        func_0041FAD0_inl1(0x94413E0BA2B41647, 0);
    } else if (D_01ECDAC6.field_0 != 0) {
        func_0041FAD0_inl1(0x94414018F8506BD2, 0);
    } else if (D_01ECDAC5.field_0 != 0 || D_01ECDAC9.field_0 != 0 || D_01ECDAC7.field_0 != 0) {
        func_0041FAD0_inl1(0x94413CD3ABD53F29, 0x3D);
    } else {
        func_0041FAD0_inl1(0x94413E0BA2B41647, 0);
    }
}
