// NONMATCHING: func_0042F0F0 -- retail 344 / ours 344 instructions, 24 in changed runs
// a157: layout+logic exact (344 instrs); only profile/l3 saved regs swapped (retail profile=s4,l3=s3; ours s3/s4): 24 changed instrs all move a0/a2. 24 declaration orders, int-reuse of s4, none flipped it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a157): single-event "race finished" page setup/dispatch; the first half is func_0042F790's body.
struct UnkStruct_0042F0F0_1 {
    unsigned char pad_0[0x1B4];
    struct UnkStruct_0042F0F0_3 * field_1B4;
    void * field_1B8;
};
struct UnkStruct_D_0051BA88 {
    UnkStruct_0042F0F0_1 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_0042F0F0_3 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual int vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual int vfunc_A4();
    virtual int vfunc_A8();
};
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064EA70 {
    unsigned char pad_0[0x4C];
    int field_4C;
    unsigned char pad_50[0xC];
    float field_5C;
    unsigned char pad_60[4];
    float field_64;
    int field_68;
    unsigned char pad_6C[0x2C];
    int field_98;
    unsigned char pad_9C[8];
    int field_A4;
};
struct UnkStruct_D_0051B930_t { unsigned char pad_0[0x30]; int field_30; };
struct UnkStruct_D_0051B930 { UnkStruct_D_0051B930_t * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064ED10 { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0042F0F0 {
    unsigned char pad_0[0x1C];
    int field_1C;
    unsigned char pad_20[4];
    int field_24;
    unsigned char pad_28[0x44];
    unsigned char field_6C;
    unsigned char field_6D;
    unsigned char field_6E;
    unsigned char field_6F;
    unsigned char pad_70[0x54];
    int field_C4;
    int field_C8;
    int field_CC;
    unsigned char field_D0;
    unsigned char field_D1;
    unsigned char field_D2;
    unsigned char field_D3;
    unsigned char pad_D4;
    unsigned char field_D5;
    unsigned char field_D6;
    unsigned char field_D7;
    unsigned char field_D8;
    unsigned char field_D9;
    unsigned char pad_DA[4];
    unsigned char field_DE;
    unsigned char pad_DF[0x27D];
    signed char field_35C[12];
    int field_368[12];
    unsigned char pad_398[4];
    unsigned char field_39C;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_D_0064EA70 D_0064EA70;
extern UnkStruct_D_0051B930 D_0051B930;
extern UnkStruct_D_0064ED10 D_0064ED10;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_Pad16 D_0051B928;
extern UnkStruct_Pad16 D_004EE040;
extern UnkStruct_Pad16 D_0051BB00;
extern UnkStruct_Pad16 D_01EA7810;
extern int D_004E2EE0;
extern "C" void func_0042FBC0(void *);
extern "C" int func_00131CA0(void *);
extern "C" int func_00131D90(void *);
extern "C" int func_00131D20(void *);
extern "C" void func_00430ED0(void *);
extern "C" void func_00430C10(void *);
extern "C" void func_00430E30(void *);
extern "C" void func_00430A40(void *);
extern "C" void func_0042FDC0(void *);
extern "C" void func_00430570(void *);
extern "C" void func_00430720(void *);
extern "C" void func_00430840(void *);
extern "C" void func_00430210(void *);
extern "C" void func_0042FCE0(void *);
extern "C" void func_00430000(void *);
extern "C" void func_0042FE90(void *);
extern "C" bool func_003D1090(void *, unsigned long, unsigned long);
extern "C" void UpdateProfile__17CB3ProfileManagerF15EChallengeMedali(int, int);
extern "C" int func_00136F30(int);
extern "C" void func_00139F20(void *);
extern "C" int GetChallengeUnlockedCount__10CB3ProfileFv(int);
extern "C" void Evaluate__10CB3ProfileFv(void *);
extern "C" void func_0013ADF0(void *, int);
extern "C" void func_0013B580(void *, unsigned int, unsigned long);
extern "C" void IncrementVehicleUsage__10CB3ProfileFUl(void *, unsigned long);
extern "C" void IncreaseSlamTotal__10CB3ProfileFUib(void *, unsigned int, unsigned char);
extern "C" void func_0013AF40(void *, unsigned long, unsigned long, float);
extern "C" void func_0013AE40(void *, int);
extern "C" void func_0013B260(void *, int, unsigned long, unsigned long, int);
extern "C" void func_0013B0E0(void *, unsigned long, unsigned long, float);
extern "C" void func_0013B670(int, int);
extern "C" void func_0013A830(void *, void *);
extern "C" void func_003BB0D0(void *, int, int);
extern "C" void func_0042F8D0(void *, int);
extern "C" void func_0042EE20(void *);

// 0x0042F0F0
extern "C" void func_0042F0F0(UnkStruct_0042F0F0 * self)
{
    UnkStruct_0042F0F0_1 * s2 = D_0051BA88.field_0;
    UnkStruct_0042F0F0_3 * s4 = s2->field_1B4;
    UnkStruct_D_0064EA70 * const g = &D_0064EA70;
    int a1;
    int v;
    func_0042FBC0(self);
    UnkStruct_0042F0F0_1 * t0 = D_0051BA88.field_0;
    UnkStruct_0042F0F0_3 * t1 = t0->field_1B4;
    self->field_D0 = t0->field_1B8 == &D_0051B928;
    self->field_D5 = func_00131CA0(&D_004EE040) || t1->vfunc_A4() || t1->vfunc_A8();
    self->field_D6 = D_01E65499.field_0;
    self->field_D3 = self->field_D6;
    self->field_D7 = func_00131D90(&D_004EE040);
    self->field_D9 = func_00131D20(&D_004EE040);
    self->field_6F = 0;
    v = s4->vfunc_38();
    if (self->field_D6 != 0) {
        self->field_24 = 9;
    } else {
        self->field_24 = 3;
    }
    switch (v) {
    case 0:
        self->field_D8 = 1;
        if (self->field_D7 != 0) {
            func_00430ED0(self);
        } else if (self->field_D5 != 0) {
            func_00430C10(self);
        } else {
            func_00430E30(self);
        }
        break;
    case 2:
        func_00430A40(self);
        break;
    case 1:
        if (self->field_D0 != 0) {
            switch (D_0051B930.field_0->field_30) {
            case 2:
                self->field_D1 = 1;
                func_00430840(self);
                break;
            case 8:
                func_00430720(self);
                break;
            case 1:
                func_00430570(self);
                break;
            }
        } else if (self->field_D5 != 0) {
            func_0042FDC0(self);
        } else {
            func_00430570(self);
        }
        break;
    case 3:
        if (self->field_D6 != 0) {
            func_00430210(self);
        } else if (self->field_D5 != 0) {
            func_0042FCE0(self);
        } else {
            func_00430000(self);
        }
        break;
    case 4:
        func_0042FE90(self);
        break;
    default:
        break;
    }
    self->field_6E = func_003D1090(&D_01EA7810, self->field_1C, self->field_D5) || self->field_6E;
    self->field_CC = D_004E2EE0;
    if (self->field_D0 != 0) {
        int m = self->field_D1 ? self->field_C8 : self->field_C4;
        switch (m) {
        case 0:
            a1 = 3;
            break;
        case 1:
            a1 = 2;
            break;
        case 2:
            a1 = 1;
            break;
        default:
            a1 = 0;
            break;
        }
        UpdateProfile__17CB3ProfileManagerF15EChallengeMedali((int)(&D_0051BB00), a1);
    }
    unsigned long l3;
    int s4p = D_0051BF9C.field_0;
    int cnt;
    int sum;
    int i;
    self->field_6D = func_00136F30(s4p);
    if (self->field_6D == 0) goto z6d;
    l3 = *(unsigned long *)s2;
    cnt = GetChallengeUnlockedCount__10CB3ProfileFv(s4p);
    if (self->field_D8 == 0) goto d8z;
    if (self->field_D6 == 0) goto other;
    if (self->field_D5 == 0) goto other;
    self->field_39C = 1;
    a1 = self->field_D6;
merge:
    func_0013ADF0((void *)(s4p), a1);
eval:
    Evaluate__10CB3ProfileFv((void *)(s4p));
    self->field_DE = GetChallengeUnlockedCount__10CB3ProfileFv(s4p) - cnt;
    func_0042F8D0(self, self->field_D8);
join2:
    for (i = 0; i < 12; i++) {
        self->field_368[i] = self->field_35C[i];
    }
    func_0042EE20(self);
    sum = 0;
    for (i = 0; i < 12; i++) {
        sum += self->field_35C[i];
        if (i < 9) sum = sum - 1;
    }
    if (self->field_D1 == 0) goto tail;
    if (self->field_D2 == 0) goto tail;
ret:
    return;
other:
    func_0013B580((void *)(s4p), g->field_98, l3);
    a1 = self->field_D6;
    goto merge;
d8z:
    {
        unsigned long s5 = D_0064ED10.field_0;
        IncrementVehicleUsage__10CB3ProfileFUl((void *)(s4p), s5);
        IncreaseSlamTotal__10CB3ProfileFUib((void *)(s4p), g->field_A4, self->field_D6);
        func_0013AF40((void *)(s4p), s5, l3, g->field_64);
        func_0013AE40((void *)(s4p), self->field_D6);
        func_0013B260((void *)(s4p), g->field_68, s5, l3, self->field_D6);
        func_0013B0E0((void *)(s4p), s5, l3, g->field_5C);
        func_0013B670(s4p, g->field_4C);
        func_0013A830((void *)(s4p), g);
        if (self->field_D1 != 0) {
            func_003BB0D0(&D_0051B928, g->field_4C, g->field_68);
        }
        goto eval;
    }
z6d:
    func_00139F20((void *)(s4p));
    goto join2;
tail:
    if (sum <= 0) return;
    self->field_24 = self->field_24 & -7;
    goto ret;
}
