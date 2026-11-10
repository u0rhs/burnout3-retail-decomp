// func_003EC0C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (inlined swap: D_01EA2980 local loaded after the D_01EA2974 store; case returns -> break).

// lifter variant 0
// func_003EC0C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003EC0C0;
struct UnkStruct_003EC0C0_6;
struct UnkStruct_003EC0C0_8;
struct UnkStruct_003EC0C0_9;
struct UnkStruct_D_01E95C38;
struct UnkStruct_D_01E97EC8;
struct UnkStruct_D_01E97ECC;
struct UnkStruct_D_01E97ED0;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_01E97ECC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E97ED0 {
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
    virtual void vfunc_18(UnkStruct_003EC0C0_8 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003EC0C0_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC0C0_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC0C0_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EC0C0_9 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E97EC8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E95C38 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC0C0 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01E97ECC D_01E97ECC;
extern UnkStruct_D_01E97ED0 D_01E97ED0;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E97EC8 D_01E97EC8;
extern UnkStruct_D_01E95C38 D_01E95C38;

extern "C" int func_0043FA90(void *, int);
extern "C" int func_003F01B0(void *, int, int);
extern "C" UnkStruct_003EC0C0_8 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003EC0C0
extern "C" void func_003EC0C0(UnkStruct_003EC0C0 * self, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        func_0043FA90(&D_01E97EC8, 0);
        self->field_10 = 0;
        break;
    case 5:
        switch (p2) {
        case 0:
            func_003F01B0(&D_01E95C38, D_01E97ECC.field_0, D_01E97ED0.field_0);
            self->field_10 = 1;
            break;
        case 3:
            switch (self->field_10) {
            case 0:
                UnkStruct_003EC0C0_8 * r2 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FD6EF6E02D9);
                if (D_01EA2974.field_0 != r2) {
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
                    void * t0 = D_01EA2974.field_0;
                    D_01EA2974.field_0 = (void *)r2;
                    UnkStruct_003EC0C0_6 * t1 = D_01EA2980.field_0;
                    if (t1 != 0) {
                        D_01EA2984.field_0 = t1->field_20;
                        if (r2 != 0) {
                            r2->field_8 = t1->field_20;
                        }
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
                }
                self->field_10 = 0;
                break;
            case 1:
                func_0043FA90(&D_01E97EC8, 1);
                self->field_10 = 0;
                break;
            }
            break;
        }
        break;
    }
}
