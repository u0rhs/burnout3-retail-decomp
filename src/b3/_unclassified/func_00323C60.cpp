// func_00323C60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (inlined setter: D_01EA2980 read after the store; nested if instead of an early return inside the switch).

// func_00323C60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00323C60;
struct UnkStruct_00323C60_4;
struct UnkStruct_00323C60_6;
struct UnkStruct_00323C60_7;
struct UnkStruct_D_01E99840;
struct UnkStruct_D_01E9B634;
struct UnkStruct_D_01EA08A0;
struct UnkStruct_D_01EA1B20;
struct UnkStruct_D_01EA1B24;
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
    virtual void vfunc_18(UnkStruct_00323C60_6 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_00323C60_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00323C60_4 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00323C60_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_00323C60_7 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E99840 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B634 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA1B24 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA08A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA1B20 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00323C60 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E99840 D_01E99840;
extern UnkStruct_D_01E9B634 D_01E9B634;
extern UnkStruct_D_01EA1B24 D_01EA1B24;
extern UnkStruct_D_01EA08A0 D_01EA08A0;
extern UnkStruct_D_01EA1B20 D_01EA1B20;

extern "C" int func_00323A10(void *);
extern "C" UnkStruct_00323C60_6 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_00438520(void *, void *, int);
extern "C" int func_0043B4A0(void *, void *);
extern "C" void func_004597C0(void *);
extern "C" void func_00459760(void *);
extern "C" void func_00459770(void *);

// 0x00323C60
extern "C" void func_00323C60(UnkStruct_00323C60 * self, int p0)
{
    switch (p0) {
    case 1:
    case 3:
        self->field_10 = 0;
        func_00323A10(&D_01E99840);
        break;
    case 36:
        UnkStruct_00323C60_6 * r1 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E2F8A91F137);
        if (D_01EA2974.field_0 != r1) {
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r1, 1);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r1;
            UnkStruct_00323C60_4 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r1 != 0) {
                    r1->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 1);
        }
        break;
    case 42:
        self->field_10 = 3;
        func_00438520(&D_01E9B634, &D_01EA1B24, 0);
        break;
    case 44:
        self->field_10 = 4;
        func_0043B4A0(&D_01EA08A0, &D_01EA1B24);
        break;
    case 27:
        func_004597C0(&D_01EA1B20);
        break;
    case 25:
        func_00459760(&D_01EA1B20);
        break;
    case 26:
        func_00459770(&D_01EA1B20);
        break;
    default:
        break;
    }
}
