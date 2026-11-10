// func_00425330 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (nested switches (p0 / p2 / D_01E95B58) with break; swap block in sibling order (2974 store before 2980 read)).

// func_00425330 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00425330_11;
struct UnkStruct_00425330_12;
struct UnkStruct_00425330_13;
struct UnkStruct_00425330_3;
struct UnkStruct_00425330_5;
struct UnkStruct_00425330_6;
struct UnkStruct_D_01E95B54;
struct UnkStruct_D_01E95B58;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECDA10;
struct UnkStruct_D_01ECDA5D;
struct UnkStruct_D_01ECDAC8;

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
    UnkStruct_00425330_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00425330_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00425330_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00425330_6 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_01E95B58 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDAC8 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDA5D {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDA10 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00425330_11 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00425330_12 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00425330_13 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01E95B54 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E95B58 D_01E95B58;
extern UnkStruct_D_01ECDAC8 D_01ECDAC8;
extern UnkStruct_D_01ECDA5D D_01ECDA5D;
extern UnkStruct_D_01ECDA10 D_01ECDA10;
extern UnkStruct_D_01E95B54 D_01E95B54;

extern "C" void func_00425320(void *);
extern "C" int func_004251E0(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x00425330
extern "C" void func_00425330(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        func_00425320(&D_01E95B54);
        func_004251E0(&D_01E95B54);
        break;
    case 5:
        switch (p2) {
        case 2:
            switch (D_01E95B58.field_0) {
            case 2:
                D_01ECDAC8.field_0 = 0;
                D_01ECDA5D.field_0 = 1;
                D_01ECDA10.field_0 = 9;
                {
                    UnkStruct_00425330_12 * r = (UnkStruct_00425330_12 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E0BA2B41647);
                    if (D_01EA2974.field_0 != r) {
                        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
                        void * t0 = D_01EA2974.field_0;
                        D_01EA2974.field_0 = (void *)r;
                        UnkStruct_00425330_3 * t1 = D_01EA2980.field_0;
                        if (t1 != 0) {
                            D_01EA2984.field_0 = t1->field_20;
                            if (r != 0) {
                                r->field_8 = t1->field_20;
                            }
                        }
                        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
                    }
                }
                break;
            case 3:
                D_01ECDAC8.field_0 = 1;
                D_01ECDA5D.field_0 = 1;
                D_01ECDA10.field_0 = 0;
                {
                    UnkStruct_00425330_11 * r = (UnkStruct_00425330_11 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E0BA2B41647);
                    if (D_01EA2974.field_0 != r) {
                        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
                        void * t0 = D_01EA2974.field_0;
                        D_01EA2974.field_0 = (void *)r;
                        UnkStruct_00425330_3 * t1 = D_01EA2980.field_0;
                        if (t1 != 0) {
                            D_01EA2984.field_0 = t1->field_20;
                            if (r != 0) {
                                r->field_8 = t1->field_20;
                            }
                        }
                        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
                    }
                }
                break;
            default:
                {
                    UnkStruct_00425330_13 * r = (UnkStruct_00425330_13 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FD6EF6E02D9);
                    if (D_01EA2974.field_0 != r) {
                        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
                        void * t0 = D_01EA2974.field_0;
                        D_01EA2974.field_0 = (void *)r;
                        UnkStruct_00425330_3 * t1 = D_01EA2980.field_0;
                        if (t1 != 0) {
                            D_01EA2984.field_0 = t1->field_20;
                            if (r != 0) {
                                r->field_8 = t1->field_20;
                            }
                        }
                        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
                    }
                }
                break;
            }
            break;
        case 0:
            break;
        case 3:
            {
                UnkStruct_00425330_5 * r = (UnkStruct_00425330_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FD6EF6E02D9);
                if (D_01EA2974.field_0 != r) {
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
                    void * t0 = D_01EA2974.field_0;
                    D_01EA2974.field_0 = (void *)r;
                    UnkStruct_00425330_3 * t1 = D_01EA2980.field_0;
                    if (t1 != 0) {
                        D_01EA2984.field_0 = t1->field_20;
                        if (r != 0) {
                            r->field_8 = t1->field_20;
                        }
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
                }
            }
            break;
        }
        break;
    }
}
