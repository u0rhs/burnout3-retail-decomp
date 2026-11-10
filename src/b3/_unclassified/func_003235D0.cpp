// func_003235D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (GetStateFromID__6CGtFSMFUl takes unsigned long hash; swap block reads D_01EA2980 after D_01EA2974 store).

// from build/vt\try_func_003235D0_best.cpp
// func_003235D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003235D0;
struct UnkStruct_003235D0_6;
struct UnkStruct_003235D0_8;
struct UnkStruct_003235D0_9;
struct UnkStruct_D_0051BA94;
struct UnkStruct_D_0051BA9C;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_0051BA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA9C {
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
    virtual void vfunc_18(UnkStruct_003235D0_8 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003235D0_6 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003235D0_6 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003235D0_8 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003235D0_9 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_003235D0 {
    unsigned char pad_0[0xC];
    // vptr at +0xC: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C(int, int, int, int, int);
    unsigned char pad_10[0x40];
    int field_50;
};

extern UnkStruct_D_0051BA94 D_0051BA94;
extern UnkStruct_D_0051BA9C D_0051BA9C;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;

extern "C" UnkStruct_003235D0_8 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_003230A0(UnkStruct_003235D0 *, int, int, int);

// 0x003235D0
extern "C" void func_003235D0(UnkStruct_003235D0 * self, int p0, int p1, int p2, int p3)
{
    switch (p0) {
    case 3:
        self->field_50 = 0;
        break;
    case 4:
        if (D_0051BA94.field_0 != -1) {
            if (D_0051BA9C.field_0 == -1) {
                UnkStruct_003235D0_8 * r0 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413EE6EE66CE78);
                if (D_01EA2974.field_0 != r0) {
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
                    void * t0 = D_01EA2974.field_0;
                    D_01EA2974.field_0 = (void *)r0;
                    UnkStruct_003235D0_6 * t1 = D_01EA2980.field_0;
                    if (t1 != 0) {
                        D_01EA2984.field_0 = t1->field_20;
                        if (r0 != 0) {
                            r0->field_8 = t1->field_20;
                        }
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
                }
            }
        }
        break;
    case 5:
        int t2 = self->field_50;
        switch (t2) {
        case 0:
            func_003230A0(self, p0, p1, p2);
            break;
        case 1:
            self->vfunc_C(p0, p1, p2, p3, t2);
            break;
        }
        break;
    default:
        break;
    }
}
