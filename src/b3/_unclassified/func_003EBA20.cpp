// func_003EBA20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (swap block as static inline helper, cases break, D_01EA2974 store before D_01EA2980 read, case 7 test flipped to != 0).

// lifter variant 0
// func_003EBA20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003EBA20_10;
struct UnkStruct_003EBA20_11;
struct UnkStruct_003EBA20_12;
struct UnkStruct_003EBA20_13;
struct UnkStruct_003EBA20_4;
struct UnkStruct_003EBA20_6;
struct UnkStruct_003EBA20_7;
struct UnkStruct_003EBA20_8;
struct UnkStruct_D_004F507F;
struct UnkStruct_D_01E96410;
struct UnkStruct_D_01E96414;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_01E96414 {
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
    UnkStruct_003EBA20_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EBA20_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EBA20_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EBA20_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_003EBA20_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_004F507F {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EBA20_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EBA20_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EBA20_12 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EBA20_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E96410 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E96414 D_01E96414;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_004F507F D_004F507F;
extern UnkStruct_D_01E96410 D_01E96410;

extern "C" int func_003ED950(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// inlined swap helper (placeholder name) [G]
static inline void func_003EBA20_inl1(UnkStruct_003EBA20_6 * r, int flag)
{
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, flag);
    void * t0 = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_003EBA20_4 * t1 = D_01EA2980.field_0;
    if (t1 != 0) {
        D_01EA2984.field_0 = t1->field_20;
        if (r != 0) {
            r->field_8 = t1->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, flag);
}

// 0x003EBA20
extern "C" void func_003EBA20(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        func_003ED950(&D_01E96410);
        break;
    case 5:
        switch (p2) {
        case 0:
            switch (D_01E96414.field_0) {
            case 4:
                func_003EBA20_inl1((UnkStruct_003EBA20_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC155240E48), 0);
                break;
            case 6:
                func_003EBA20_inl1((UnkStruct_003EBA20_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC1552437EA), 0);
                break;
            case 7:
                if (D_004F507F.field_0 != 0) {
                    func_003EBA20_inl1((UnkStruct_003EBA20_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E09C8DC7ACA), 0);
                } else {
                    func_003EBA20_inl1((UnkStruct_003EBA20_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC1552437EA), 1);
                }
                break;
            case 8:
                func_003EBA20_inl1((UnkStruct_003EBA20_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC15523D68A), 0);
                break;
            }
            break;
        case 3:
            func_003EBA20_inl1((UnkStruct_003EBA20_6 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FD6EF6E02D9), 0);
            break;
        }
        break;
    }
}
