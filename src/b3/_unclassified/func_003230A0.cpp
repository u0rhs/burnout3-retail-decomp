// func_003230A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (s313: archive + scoped opt_dead_assignments off (sibling func_00322EA0) + return in cases 0x4C/0x4D/0x40).

// func_003230A0 -- hand-matched by s313 from the a148 archive: scoped `opt_dead_assignments off` as the proven sibling
// func_00322EA0 (N182, [G]) fixed the saved registers/frame; the 0x4C/0x4D/0x40 cases end in `return` (not break) so
// only the shared break block gets the epilogue ld ra. Unnamed in every table: placeholder with C linkage; types [G].

enum EB3ScoreFinishState {};
struct UnkStruct_4P { unsigned char pad_0[0x10]; };
struct UnkStruct_B { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_UB { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_arr { signed char b[0x2C]; };
struct UnkStruct_D_004F5040 { UnkStruct_arr field_0; unsigned char pad_2C[0x14]; };
struct UnkStruct_Sc {
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
    virtual void vfunc_38();
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
    virtual int vfunc_98();
};
struct UnkStruct_Pg { unsigned char pad_0[0x1B4]; UnkStruct_Sc * field_1B4; };
struct UnkStruct_FSM {
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
struct UnkStruct_3230A0 {
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
    int field_50;
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
extern UnkStruct_4P D_004F50C0;
extern UnkStruct_4P D_01E77540;
extern UnkStruct_B D_0064ED5D;
extern UnkStruct_4P D_0064D3B0;
extern UnkStruct_FSM D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_B D_01EA2F0E;
extern UnkStruct_4P D_01ECD9F0;
extern UnkStruct_4P D_004EE040;
extern UnkStruct_4P D_0051A6A8;
extern UnkStruct_4P D_01E964A4;
extern UnkStruct_4P D_01E96F20;
struct UnkStruct_Gp { UnkStruct_Pg * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_Gp D_0051BA88;
extern "C" void SetPause__15CB3InputManagerFb(void *, bool);
extern "C" void func_00288F50(void *);
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_0042F790(void *);
extern "C" void func_00130C20(void *, unsigned long);
extern "C" void func_00131F10(void *, void *);
extern "C" int func_003F2FE0(void *, int);
extern "C" int func_003F3670(void *, int);
extern "C" void func_00393360(void *);

static inline void SetScene(unsigned long h)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_FSM *)&D_01EA2970)->vfunc_18(r, 0);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_FSM *)&D_01EA2970)->vfunc_1C(t, 0);
}

// N182: scoped `opt_dead_assignments off` as the proven sibling func_00322EA0 ([G] scoped to this function).
#pragma push
#pragma opt_dead_assignments off
// 0x003230A0
extern "C" void func_003230A0(UnkStruct_3230A0 * self, int p1, int p2, int p3)
{
    switch (p3) {
    case 6:
        SetPause__15CB3InputManagerFb(&D_004F50C0, false);
        D_0064ED5D.field_0 = 1;
        func_00288F50(&D_01E77540);
        break;
    case 9:
        SetFinished__10CB3RaceCarF19EB3ScoreFinishState(&D_0064D3B0, (EB3ScoreFinishState)3);
        SetScene(0x943D84EEB02101E9UL);
        break;
    case 0xB:
        D_01EA2F0E.field_0 = 0;
        func_0042F790(&D_01ECD9F0);
        SetScene(0x94413FA737AAA797UL);
        func_00130C20(&D_0051A6A8, 0x94413E09C8514CA1UL);
        func_00131F10(&D_004EE040, &D_0051A6A8);
        break;
    case 0x4C: {
        self->field_50 = 1;
        self->field_10 = D_004F5040.field_0;
        unsigned char b0 = D_004F506C.field_0;
        unsigned char b1 = D_004F506D.field_0;
        unsigned char b2 = D_004F506E.field_0;
        unsigned char b3 = D_004F506F.field_0;
        self->field_3C = b0;
        self->field_3D = b1;
        self->field_3E = b2;
        self->field_3F = b3;
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
        unsigned char e0 = D_004F507D.field_0;
        unsigned char e1 = D_004F507E.field_0;
        self->field_4D = e0;
        self->field_4E = e1;
        self->field_4F = D_004F507F.field_0;
        func_003F2FE0(&D_01E964A4, 1);
        return; }
    case 0x4D: {
        self->field_50 = 1;
        self->field_10 = D_004F5040.field_0;
        unsigned char c0 = D_004F506C.field_0;
        unsigned char c1 = D_004F506D.field_0;
        unsigned char c2 = D_004F506E.field_0;
        unsigned char c3 = D_004F506F.field_0;
        self->field_3C = c0;
        self->field_3D = c1;
        self->field_3E = c2;
        self->field_3F = c3;
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
        unsigned char e0 = D_004F507D.field_0;
        unsigned char e1 = D_004F507E.field_0;
        self->field_4D = e0;
        self->field_4E = e1;
        self->field_4F = D_004F507F.field_0;
        func_003F3670(&D_01E96F20, 1);
        return; }
    case 0x40:
        if (D_0051BA88.field_0 != 0) {
            if (D_0051BA88.field_0->field_1B4 != 0) {
                if (D_0051BA88.field_0->field_1B4->vfunc_98() == 6) {
                    func_00393360(D_0051BA88.field_0->field_1B4);
                }
            }
        }
        return;
    }
}

#pragma pop
