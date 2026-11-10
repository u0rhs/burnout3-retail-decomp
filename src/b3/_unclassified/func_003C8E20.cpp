// func_003C8E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if / else-if chain of D_01EA2970 state switches (each written out, early 'return' only on the already-active check), AC5||AC9||AC7 sharing one block).

// lifter variant 0
// func_003C8E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003C8E20;
struct UnkStruct_003C8E20_12;
struct UnkStruct_003C8E20_14;
struct UnkStruct_003C8E20_16;
struct UnkStruct_003C8E20_18;
struct UnkStruct_003C8E20_19;
struct UnkStruct_003C8E20_4;
struct UnkStruct_003C8E20_6;
struct UnkStruct_003C8E20_7;
struct UnkStruct_003C8E20_9;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;
struct UnkStruct_D_01ECDAC0;
struct UnkStruct_D_01ECDAC3;
struct UnkStruct_D_01ECDAC5;
struct UnkStruct_D_01ECDAC6;
struct UnkStruct_D_01ECDAC7;
struct UnkStruct_D_01ECDAC9;

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
    UnkStruct_003C8E20_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8E20_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8E20_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C8E20_7 {
    unsigned char pad_0[0x18];
    int field_18;
    int field_1C;
};

struct UnkStruct_D_01ECDAC0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8E20_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01ECDAC6 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECDAC3 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8E20_12 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01ECDAC5 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8E20_14 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01ECDAC9 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8E20_16 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_D_01ECDAC7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003C8E20_18 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C8E20_19 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003C8E20 {
    unsigned char pad_0[0x25];
    unsigned char field_25;
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01ECDAC0 D_01ECDAC0;
extern UnkStruct_D_01ECDAC6 D_01ECDAC6;
extern UnkStruct_D_01ECDAC3 D_01ECDAC3;
extern UnkStruct_D_01ECDAC5 D_01ECDAC5;
extern UnkStruct_D_01ECDAC9 D_01ECDAC9;
extern UnkStruct_D_01ECDAC7 D_01ECDAC7;

extern "C" UnkStruct_003C8E20_6 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x003C8E20
extern "C" void func_003C8E20(UnkStruct_003C8E20 * self)
{
    if (self->field_25 != 0) {
        UnkStruct_003C8E20_6 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC035B0F871);
        if (D_01EA2974.field_0 == r) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
        void * old = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r;
        UnkStruct_003C8E20_4 * t = D_01EA2980.field_0;
        if (t != 0) {
            D_01EA2984.field_0 = t->field_20;
            if (r != 0) {
                r->field_8 = t->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(old, 0);
    } else if (D_01ECDAC0.field_0 != 0) {
        UnkStruct_003C8E20_6 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E52C3BF9CAA);
        if (D_01EA2974.field_0 == r) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
        void * old = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r;
        UnkStruct_003C8E20_4 * t = D_01EA2980.field_0;
        if (t != 0) {
            D_01EA2984.field_0 = t->field_20;
            if (r != 0) {
                r->field_8 = t->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(old, 0);
    } else if (D_01ECDAC6.field_0 != 0) {
        D_01ECDAC3.field_0 = 0;
        UnkStruct_003C8E20_6 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8535FC2);
        if (D_01EA2974.field_0 == r) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
        void * old = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r;
        UnkStruct_003C8E20_4 * t = D_01EA2980.field_0;
        if (t != 0) {
            D_01EA2984.field_0 = t->field_20;
            if (r != 0) {
                r->field_8 = t->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(old, 0);
    } else if (D_01ECDAC5.field_0 != 0 || D_01ECDAC9.field_0 != 0 || D_01ECDAC7.field_0 != 0) {
        UnkStruct_003C8E20_6 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413CD3ABD53F29);
        if (D_01EA2974.field_0 == r) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 61);
        void * old = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r;
        UnkStruct_003C8E20_4 * t = D_01EA2980.field_0;
        if (t != 0) {
            D_01EA2984.field_0 = t->field_20;
            if (r != 0) {
                r->field_8 = t->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(old, 61);
    } else {
        UnkStruct_003C8E20_6 * r = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413CAD86353F29);
        if (D_01EA2974.field_0 == r) {
            return;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 61);
        void * old = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r;
        UnkStruct_003C8E20_4 * t = D_01EA2980.field_0;
        if (t != 0) {
            D_01EA2984.field_0 = t->field_20;
            if (r != 0) {
                r->field_8 = t->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(old, 61);
    }
}
