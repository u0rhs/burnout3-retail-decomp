// func_0036A510 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch: default/1/2/0 share one body (== 1 arm first); swap block in the B3OnlineNewsState::Action order (early break on equal)).

// lifter variant 0
// func_0036A510 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0036A510;
struct UnkStruct_0036A510_10;
struct UnkStruct_0036A510_7;
struct UnkStruct_0036A510_9;
struct UnkStruct_D_01E9B8C0;
struct UnkStruct_D_01E9B924;
struct UnkStruct_D_01E9E000;
struct UnkStruct_D_01EA14C4;
struct UnkStruct_D_01EA14C8;
struct UnkStruct_D_01EA14D0;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_01EA14C4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA14D0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA14C8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
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
    virtual void vfunc_18(UnkStruct_0036A510_9 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0036A510_7 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036A510_7 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036A510_9 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0036A510_10 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E9E000 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B924 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B8C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036A510 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
};

extern UnkStruct_D_01EA14C4 D_01EA14C4;
extern UnkStruct_D_01EA14D0 D_01EA14D0;
extern UnkStruct_D_01EA14C8 D_01EA14C8;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E9E000 D_01E9E000;
extern UnkStruct_D_01E9B924 D_01E9B924;
extern UnkStruct_D_01E9B8C0 D_01E9B8C0;

extern "C" int func_00379140(void *, unsigned long);
extern "C" int func_00376470(void *, unsigned long);
extern "C" int func_00371270(void *);
extern "C" UnkStruct_0036A510_9 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x0036A510
extern "C" int func_0036A510(UnkStruct_0036A510 * self, void *p0_)
{
    int p0 = (int)p0_;
    switch (p0) {
    default:
    case 1:
    case 2:
    case 0:
        if (D_01EA14C4.field_0 == 1) {
            self->field_10 = 2;
            func_00376470(&D_01E9B924, D_01EA14C8.field_0);
        } else {
            self->field_10 = 3;
            func_00379140(&D_01E9E000, D_01EA14D0.field_0);
        }
        break;
    case 3:
        self->field_10 = 0;
        func_00371270(&D_01E9B8C0);
        break;
    case 36:
        UnkStruct_0036A510_9 * r3 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E2F8A91F137);
        if (D_01EA2974.field_0 == r3) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r3, 1);
        void * t0 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r3;
        UnkStruct_0036A510_7 * t1 = D_01EA2980.field_0;
        if (t1 != 0) {
            D_01EA2984.field_0 = t1->field_20;
            if (r3 != 0) {
                r3->field_8 = t1->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 1);
        break;
    }
    return 1;
}
