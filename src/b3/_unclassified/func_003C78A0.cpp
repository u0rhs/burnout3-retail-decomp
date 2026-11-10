// func_003C78A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (default arm as if/else-if chain (DAC1==0 || DAC2==0 shares one swap block), returns in vcall arms, swap block reads D_01EA2980 after the D_01EA2974 store).

// lifter variant 0
// func_003C78A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C78A0;
struct UnkStruct_003C78A0_11;
struct UnkStruct_003C78A0_12;
struct UnkStruct_003C78A0_14;
struct UnkStruct_003C78A0_3;
struct UnkStruct_003C78A0_4;
struct UnkStruct_003C78A0_9;
struct UnkStruct_D_004E2ED8;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051B928;
struct UnkStruct_D_0051BA88;
struct UnkStruct_D_01E95968;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECDAC1;
struct UnkStruct_D_01ECDAC2;
struct UnkStruct_D_01ECDAC7;

struct UnkStruct_D_01ECDAC7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA88 {
    UnkStruct_003C78A0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C78A0_3 {
    unsigned char pad_0[0x1B8];
    UnkStruct_003C78A0_4 * field_1B8;
};

struct UnkStruct_003C78A0_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
};

struct UnkStruct_D_01ECDAC1 {
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
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003C78A0_9 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C78A0_9 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C78A0_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C78A0_12 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_01ECDAC2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C78A0_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_0051B928 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E95968 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E2ED8 {
    unsigned char pad_0[0x4];  // [G] size: gp-relative addressing needs <= 8 bytes
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C78A0 {
    unsigned char pad_0[0x14];
    unsigned char field_14;
};

extern UnkStruct_D_01ECDAC7 D_01ECDAC7;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01ECDAC1 D_01ECDAC1;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01ECDAC2 D_01ECDAC2;
extern UnkStruct_D_0051B928 D_0051B928;
extern UnkStruct_D_01E95968 D_01E95968;
extern UnkStruct_D_004E2ED8 D_004E2ED8;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int func_003C5750(void *, int, void *);
extern "C" int func_003C57C0(void *, int, void *);
extern "C" int func_003C5690(void *, int, void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00130C20(void *, unsigned long);
extern "C" void func_00131F10(void *, void *);

// 0x003C78A0
extern "C" void func_003C78A0(UnkStruct_003C78A0 * self, int p0, int p1)
{
    self->field_14 = 0;
    switch (((signed char)p0)) {
    case 0:
        func_003C5750(&D_01E95968, p1, &D_004E2ED8);
        break;
    case 1:
        func_003C57C0(&D_01E95968, p1, &D_004E2ED8);
        break;
    case 2:
        func_003C5690(&D_01E95968, p1, &D_004E2ED8);
        break;
    default:
        if (D_01ECDAC7.field_0 != 0) {
            D_0051BA88.field_0->field_1B8->vfunc_1C();
            return;
        } else if (D_01ECDAC1.field_0 == 0 || D_01ECDAC2.field_0 == 0) {
            UnkStruct_003C78A0_11 * r4 = (UnkStruct_003C78A0_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FA737AAA797);
            if (D_01EA2974.field_0 != r4) {
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r4, 0);
                void * t0 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r4;
                UnkStruct_003C78A0_9 * t1 = D_01EA2980.field_0;
                if (t1 != 0) {
                    D_01EA2984.field_0 = t1->field_20;
                    if (r4 != 0) {
                        r4->field_8 = t1->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            }
            func_00130C20(&D_0051A6A8, 0x94413E09C8514CA1);
            func_00131F10(&D_004EE040, &D_0051A6A8);
        } else {
            ((UnkStruct_D_0051B928 *)&D_0051B928)->vfunc_1C();
            return;
        }
        break;
    }
}
