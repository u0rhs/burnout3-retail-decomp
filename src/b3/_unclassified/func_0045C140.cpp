// Hand-written; the lifter refused it (L255: Action-style handler; SetScene inline + D_004F5040 save/restore as func_00322EA0, scoped opt_dead_assignments off [G] N182).

// func_0045C140 -- FSM state Action handler [G] (a1 = action; SetScene inline as B3OnlineMenuState_00323E30.cpp;
// D_004F5040 header save/restore as func_00322EA0.cpp).

struct UnkStruct_D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_D_01EA2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2980 { UnkStruct_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA2984 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_UB { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_arr { signed char b[0x2C]; };
struct UnkStruct_D_004F5040 { UnkStruct_arr field_0; unsigned char pad_2C[0x14]; };
struct UnkStruct_0045C140 {
    unsigned char pad_0[0x10];
    UnkStruct_arr field_10;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    unsigned char field_3F;
    signed char field_40;
    signed char field_41;
    signed char field_42;
    signed char field_43;
    signed char field_44;
    signed char field_45;
    signed char field_46;
    signed char field_47;
    signed char field_48;
    signed char field_49;
    signed char field_4A;
    signed char field_4B;
    signed char field_4C;
    unsigned char field_4D;
    unsigned char field_4E;
    signed char field_4F;
    bool field_50;
};
extern UnkStruct_D_004F5040 D_004F5040;
extern UnkStruct_UB D_004F506C;
extern UnkStruct_UB D_004F506D;
extern UnkStruct_UB D_004F506E;
extern UnkStruct_UB D_004F506F;
extern UnkStruct_B D_004F5070;
extern UnkStruct_B D_004F5071;
extern UnkStruct_B D_004F5072;
extern UnkStruct_B D_004F5073;
extern UnkStruct_B D_004F5074;
extern UnkStruct_B D_004F5075;
extern UnkStruct_B D_004F5076;
extern UnkStruct_B D_004F5077;
extern UnkStruct_B D_004F5078;
extern UnkStruct_B D_004F5079;
extern UnkStruct_B D_004F507A;
extern UnkStruct_B D_004F507B;
extern UnkStruct_B D_004F507C;
extern UnkStruct_UB D_004F507D;
extern UnkStruct_UB D_004F507E;
extern UnkStruct_B D_004F507F;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_P D_01EA29F0;
extern UnkStruct_UB D_01E91C3E;
extern UnkStruct_I D_0051BA94;
extern UnkStruct_I D_0051BA9C;
extern UnkStruct_P D_01E96514;
extern UnkStruct_P D_01E9842C;
extern UnkStruct_P D_01E964A4;
extern UnkStruct_P D_01E96F20;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_0045BB10(void *);
extern "C" int func_003F3E60(void *);
extern "C" int func_003F2FE0(void *, bool);
extern "C" int func_003F3670(void *, bool);
extern "C" void func_0021B4F0(void *);
extern "C" void func_0021B5E0(void *);

static inline void SetScene(unsigned long h, int k)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, k);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t, k);
}

// N182: [G] scoped to this function, as func_00322EA0.cpp
#pragma push
#pragma opt_dead_assignments off
// 0x0045C140
extern "C" void func_0045C140(UnkStruct_0045C140 * self, int action, void * p1, void * p2, int p3)
{
    switch (action) {
    case 3:
        self->field_50 = p2 == &D_01EA29F0;
        if (self->field_50) {
            D_01E91C3E.field_0 = 1;
        }
        self->field_10 = D_004F5040.field_0;
        {
            unsigned char b0 = D_004F506C.field_0;
            unsigned char b1 = D_004F506D.field_0;
            unsigned char b2 = D_004F506E.field_0;
            unsigned char b3 = D_004F506F.field_0;
            self->field_3C = b0;
            self->field_3D = b1;
            self->field_3E = b2;
            self->field_3F = b3;
        }
        self->field_40 = D_004F5070.field_0;
        self->field_41 = D_004F5071.field_0;
        self->field_42 = D_004F5072.field_0;
        self->field_43 = D_004F5073.field_0;
        self->field_44 = D_004F5074.field_0;
        self->field_45 = D_004F5075.field_0;
        self->field_46 = D_004F5076.field_0;
        self->field_47 = D_004F5077.field_0;
        self->field_48 = D_004F5078.field_0;
        self->field_49 = D_004F5079.field_0;
        self->field_4A = D_004F507A.field_0;
        self->field_4B = D_004F507B.field_0;
        self->field_4C = D_004F507C.field_0;
        {
            unsigned char b4 = D_004F507D.field_0;
            unsigned char b5 = D_004F507E.field_0;
            self->field_4D = b4;
            self->field_4E = b5;
        }
        self->field_4F = D_004F507F.field_0;
        switch (p3) {
        case 0:
            func_0045BB10(&D_01E96514);
            break;
        case 2:
            func_003F3E60(&D_01E9842C);
            break;
        case 1:
            func_003F2FE0(&D_01E964A4, self->field_50);
            break;
        case 3:
            func_003F3670(&D_01E96F20, self->field_50);
            break;
        }
        break;
    case 5:
        switch ((int)p2) {
        case 1:
            if (self->field_50) {
                SetScene(0x94413EE6EE66CE78UL, 0);
            } else {
                SetScene(0x94413FC165859B62UL, 0);
            }
            break;
        case 6:
            SetScene(0x94413EDB6B01A028UL, 0);
            {
                int v = D_0051BA94.field_0;
                if (v < 0) return;
                D_0051BA9C.field_0 = v;
            }
            break;
        case 3:
            if (self->field_50) {
                SetScene(0x94413EE6EE66CE78UL, 0);
            } else {
                SetScene(0x94413FC165859B62UL, 0);
            }
        case 0x4A:
            D_004F5040.field_0 = self->field_10;
            {
                unsigned char b0 = self->field_3C;
                unsigned char b1 = self->field_3D;
                unsigned char b2 = self->field_3E;
                unsigned char b3 = self->field_3F;
                D_004F506C.field_0 = b0;
                D_004F506D.field_0 = b1;
                D_004F506E.field_0 = b2;
                D_004F506F.field_0 = b3;
            }
            D_004F5070.field_0 = self->field_40;
            D_004F5071.field_0 = self->field_41;
            D_004F5072.field_0 = self->field_42;
            D_004F5073.field_0 = self->field_43;
            D_004F5074.field_0 = self->field_44;
            D_004F5075.field_0 = self->field_45;
            D_004F5076.field_0 = self->field_46;
            D_004F5077.field_0 = self->field_47;
            D_004F5078.field_0 = self->field_48;
            D_004F5079.field_0 = self->field_49;
            D_004F507A.field_0 = self->field_4A;
            D_004F507B.field_0 = self->field_4B;
            D_004F507C.field_0 = self->field_4C;
            {
                unsigned char b4 = self->field_4D;
                unsigned char b5 = self->field_4E;
                D_004F507D.field_0 = b4;
                D_004F507E.field_0 = b5;
            }
            D_004F507F.field_0 = self->field_4F;
        case 0x4B:
            if (self->field_50) {
                func_0021B4F0(&D_004F5040);
            } else {
                func_0021B5E0(&D_004F5040);
            }
            break;
        }
        break;
    }
}


#pragma pop
