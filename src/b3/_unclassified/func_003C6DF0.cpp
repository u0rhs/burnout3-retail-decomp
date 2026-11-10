// func_003C6DF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (static inline swap helper (x3); one-case switch on p2; || merge for parked branch).

// lifter variant 0
// func_003C6DF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C6DF0_11;
struct UnkStruct_003C6DF0_12;
struct UnkStruct_003C6DF0_4;
struct UnkStruct_003C6DF0_6;
struct UnkStruct_003C6DF0_7;
struct UnkStruct_003C6DF0_9;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_01E900B0;
struct UnkStruct_D_01E91C3D;
struct UnkStruct_D_01E95950;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECDAC4;

struct UnkStruct_D_01E900B0 {
    int field_0;
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
    UnkStruct_003C6DF0_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C6DF0_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C6DF0_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C6DF0_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_01ECDAC4 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C6DF0_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E91C3D {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C6DF0_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C6DF0_12 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E95950 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E900B0 D_01E900B0;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01ECDAC4 D_01ECDAC4;
extern UnkStruct_D_01E91C3D D_01E91C3D;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E95950 D_01E95950;

extern "C" int func_00131E40(void *);
extern "C" int func_003C4900(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

static inline void func_003C6DF0_inl1(unsigned long id)  // [G] inlined swap helper (name unknown)
{
    UnkStruct_003C6DF0_6 * r = (UnkStruct_003C6DF0_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, id);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003C6DF0_4 * t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r != 0) {
            r->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
}

// 0x003C6DF0
extern "C" void func_003C6DF0(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    case 0:
        break;
    case 3:
        if (func_00131E40(&D_004EE040) == 0) {
            func_003C4900(&D_01E95950);
            break;
        }
        D_01E900B0.field_0 = 3;
        func_003C6DF0_inl1(0x94413FA737AAA797);
        break;
    case 5:
        switch (p2) {
        case 2:
            if (D_01ECDAC4.field_0 == 0 || D_01E91C3D.field_0 == 0) {
                func_003C6DF0_inl1(0x944140403E74F2B0);
            } else {
                D_01E900B0.field_0 = 3;
                func_003C6DF0_inl1(0x94413FA737AAA797);
            }
            break;
        }
        break;
    default:
        break;
    }
}
