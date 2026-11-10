// Hand-written; the lifter refused it (sibling func_0036A3A0 shape + jtbl switch).

struct UnkStruct_0036A3A0;
struct UnkStruct_0036A3A0_3;
struct UnkStruct_0036A3A0_5;
struct UnkStruct_0036A3A0_6;
struct UnkStruct_D_01E9B940;
struct UnkStruct_D_01E9B928;
struct UnkStruct_D_01EA14C0;
struct UnkStruct_D_01EA14C8;
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
    virtual void vfunc_18(UnkStruct_0036A3A0_5 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_0036A3A0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036A3A0_3 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036A3A0_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_0036A3A0_6 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01EA14C8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B928 {
    unsigned short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E9B940 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA14C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036A3A0 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
struct UnkStruct_D_US { unsigned short field_0; unsigned char pad_2[0xE]; };
extern UnkStruct_D_US D_01E9B8C4;
extern UnkStruct_D_01E9B940 D_01E9B940;
extern UnkStruct_D_01EA14C0 D_01EA14C0;

extern "C" int func_00378C00(void *, int, unsigned long);
extern "C" int func_004556D0(void *);
extern "C" UnkStruct_0036A3A0_5 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

// 0x0036A680
extern "C" int func_0036A680(UnkStruct_0036A3A0 * self, void *p0_)
{
    int p0 = (int)p0_;
    UnkStruct_0036A3A0_5 * r0;
    switch (p0) {
    case 1:
    case 2:
    case 0:
    default:
        switch (D_01E9B8C4.field_0) {
        case 0: func_00378C00(&D_01E9B940, 0, 0); self->field_10 = 4; break;
        case 1: func_00378C00(&D_01E9B940, 1, 0); self->field_10 = 4; break;
        case 2: func_00378C00(&D_01E9B940, 2, 0); self->field_10 = 4; break;
        case 3: func_00378C00(&D_01E9B940, 3, 0); self->field_10 = 4; break;
        case 4: func_00378C00(&D_01E9B940, 4, 0); self->field_10 = 4; break;
        case 5: func_004556D0(&D_01EA14C0); self->field_10 = 1; break;
        }
        break;
    case 3:
        r0 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8512871);
        if (D_01EA2974.field_0 != r0) {
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
            void * t1 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r0;
            UnkStruct_0036A3A0_3 * t2 = D_01EA2980.field_0;
            if (t2 != 0) {
                D_01EA2984.field_0 = t2->field_20;
                if (r0 != 0) {
                    r0->field_8 = t2->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, 0);
        }
        break;
    case 36:
        r0 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413E2F8A91F137);
        if (D_01EA2974.field_0 != r0) {
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 1);
            void * t1 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r0;
            UnkStruct_0036A3A0_3 * t2 = D_01EA2980.field_0;
            if (t2 != 0) {
                D_01EA2984.field_0 = t2->field_20;
                if (r0 != 0) {
                    r0->field_8 = t2->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, 1);
        }
        break;
    }
    return 1;
}
