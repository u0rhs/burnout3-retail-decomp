// func_004413C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (D_01EA2974 store before the D_01EA2980 load in both FSM blocks; cases break to the shared tail).

// func_004413C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_004413C0_3;
struct UnkStruct_004413C0_5;
struct UnkStruct_004413C0_6;
struct UnkStruct_004413C0_7;
struct UnkStruct_D_01E94CF8;
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
    UnkStruct_004413C0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004413C0_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_004413C0_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_004413C0_6 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_004413C0_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E94CF8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E94CF8 D_01E94CF8;

extern "C" void func_004413B0(void *);
extern "C" int func_00441100(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x004413C0
extern "C" void func_004413C0(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        func_004413B0(&D_01E94CF8);
        func_00441100(&D_01E94CF8);
        break;
    case 5:
        switch (p2) {
        case 1: {
            UnkStruct_004413C0_5 * r2 = (UnkStruct_004413C0_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413EE6EE66CE78);
            if (D_01EA2974.field_0 != r2) {
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
                void * t0 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r2;
                UnkStruct_004413C0_3 * t1 = D_01EA2980.field_0;
                if (t1 != 0) {
                    D_01EA2984.field_0 = t1->field_20;
                    if (r2 != 0) {
                        r2->field_8 = t1->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            }
            break;
        }
        case 3: {
            UnkStruct_004413C0_7 * r5 = (UnkStruct_004413C0_7 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413EE6EE66CE78);
            if (D_01EA2974.field_0 != r5) {
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
                void * t0 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r5;
                UnkStruct_004413C0_3 * t1 = D_01EA2980.field_0;
                if (t1 != 0) {
                    D_01EA2984.field_0 = t1->field_20;
                    if (r5 != 0) {
                        r5->field_8 = t1->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            }
            break;
        }
        }
        break;
    }
}
