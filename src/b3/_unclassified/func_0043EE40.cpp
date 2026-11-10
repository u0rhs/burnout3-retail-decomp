// func_0043EE40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch default:return first; global store moved before the next global load).

// lifter variant 0
// func_0043EE40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0043EE40;
struct UnkStruct_0043EE40_10;
struct UnkStruct_0043EE40_11;
struct UnkStruct_0043EE40_8;
struct UnkStruct_0043EE40_a3;
struct UnkStruct_D_01E7A888;
struct UnkStruct_D_01E90208;
struct UnkStruct_D_01E9020C;
struct UnkStruct_D_01E90210;
struct UnkStruct_D_01E98478;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_0043EE40_a3 {
    unsigned long field_0;
};

struct UnkStruct_D_01E90208 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9020C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90210 {
    float field_0;
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
    virtual void vfunc_18(UnkStruct_0043EE40_10 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0043EE40_8 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043EE40_8 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043EE40_10 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0043EE40_11 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E7A888 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E98478 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0043EE40 {
    unsigned char pad_0[0x18];
    unsigned long field_18;
};

extern UnkStruct_D_01E90208 D_01E90208;
extern UnkStruct_D_01E9020C D_01E9020C;
extern UnkStruct_D_01E90210 D_01E90210;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E7A888 D_01E7A888;
extern UnkStruct_D_01E98478 D_01E98478;

extern "C" void func_003FA600(void *, int);
extern "C" int func_00424750(void *, int, int, int, float);
extern "C" UnkStruct_0043EE40_10 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x0043EE40
extern "C" void func_0043EE40(UnkStruct_0043EE40 * self, int p0, int p1, UnkStruct_0043EE40_a3 * p2)
{
    switch (p0) {
    default:
        return;
    case 3:
        self->field_18 = p2->field_0;
        func_003FA600(&D_01E7A888, 3);
        func_00424750(&D_01E98478, D_01E90208.field_0, 1, D_01E9020C.field_0, D_01E90210.field_0);
        break;
    case 5:
        if ((int)p2 == 1) {
            return;
        }
        switch ((int)p2) {
        case 0:
        case 2:
            UnkStruct_0043EE40_10 * r2 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, self->field_18);
            if (D_01EA2974.field_0 == r2) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r2, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r2;
            UnkStruct_0043EE40_8 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r2 != 0) {
                    r2->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
            return;
        }
        break;
    case 2:
        func_003FA600(&D_01E7A888, 1);
        break;
    }
}
