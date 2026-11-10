// func_00431F90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (swap blocks store-then-load; returns become break; outer default first).

// lifter variant 0
// func_00431F90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00431F90_3;
struct UnkStruct_00431F90_5;
struct UnkStruct_00431F90_6;
struct UnkStruct_00431F90_7;
struct UnkStruct_D_01E96550;
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
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00431F90_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00431F90_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00431F90_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00431F90_6 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_00431F90_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E96550 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E96550 D_01E96550;

extern "C" void func_00431F70(void *);
extern "C" int func_00431D80(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00431F90
extern "C" void func_00431F90(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    default:
        break;
    case 3:
        func_00431F70(&D_01E96550);
        func_00431D80(&D_01E96550);
        break;
    case 5:
        switch (p2) {
        case 1:
            UnkStruct_00431F90_5 * r2 = (UnkStruct_00431F90_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC165859B62);
            if (D_01EA2974.field_0 == r2) {
                break;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r2;
            UnkStruct_00431F90_3 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r2 != 0) {
                    r2->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            break;
        case 3:
            UnkStruct_00431F90_7 * r5 = (UnkStruct_00431F90_7 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC165859B62);
            if (D_01EA2974.field_0 == r5) {
                break;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
            void * t2 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r5;
            UnkStruct_00431F90_3 * t3 = D_01EA2980.field_0;
            if (t3 != 0) {
                D_01EA2984.field_0 = t3->field_20;
                if (r5 != 0) {
                    r5->field_8 = t3->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
            break;
        }
        break;
    }
}
