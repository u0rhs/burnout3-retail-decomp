// func_004389B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (swap block as static inline helper (D_01EA2974 store before D_01EA2980 read), called per branch).

// lifter variant 0
// func_004389B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004389B0;
struct UnkStruct_004389B0_10;
struct UnkStruct_004389B0_11;
struct UnkStruct_004389B0_6;
struct UnkStruct_004389B0_8;
struct UnkStruct_004389B0_9;
struct UnkStruct_D_004F50A0;
struct UnkStruct_D_01E90230;
struct UnkStruct_D_01E97E1C;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_004F50A0 {
    float field_0;
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
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_004389B0_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004389B0_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004389B0_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_004389B0_9 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_004389B0_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_004389B0_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E97E1C {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004389B0 {
    unsigned char pad_0[0x10];
    float field_10;
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_01E90230 D_01E90230;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E97E1C D_01E97E1C;

extern "C" int func_00438910(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

static inline void a51_set(unsigned long h)
{
    UnkStruct_004389B0_8 * r = (UnkStruct_004389B0_8 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t1 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_004389B0_6 * t2 = D_01EA2980.field_0;
    if (t2 != 0) {
        D_01EA2984.field_0 = t2->field_20;
        if (r != 0) {
            r->field_8 = t2->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, 0);
}

// 0x004389B0
extern "C" void func_004389B0(UnkStruct_004389B0 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        self->field_10 = D_004F50A0.field_0;
        func_00438910(&D_01E97E1C);
        break;
    case 5:
        switch (p2) {
        case 1:
            if (D_01E90230.field_0 != 0x60D6B07214065F27) {
                a51_set(D_01E90230.field_0);
            } else {
                a51_set(0x94413FC035B0F871);
            }
            break;
        case 5:
            a51_set(0x944140D320FEDE85);
            break;
        }
        break;
    }
}
