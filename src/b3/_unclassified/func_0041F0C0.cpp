// Hand-written; the lifter refused it (L255: autosave Action; SetScene + func_0041FAD0 dispatch inline; func_00420A50 arm via goto [G]).

// func_0041F0C0 -- autosave FSM state Action handler [G]; SetScene inline as B3OnlineMenuState_00323E30.cpp,
// the memory-card result dispatch as the matched neighbour func_0041FAD0.cpp.
// [G] DNAT hint (research/proto/new_names.csv, low): CB3AutoSaveState::Action(EGtStateAction,void*,void*,void*).

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
struct UnkStruct_UB { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_UB D_01ECDA5D;
extern UnkStruct_UB D_01ECDA5E;
extern UnkStruct_UB D_01ECDAC0;
extern UnkStruct_UB D_01ECDAC5;
extern UnkStruct_UB D_01ECDAC6;
extern UnkStruct_UB D_01ECDAC7;
extern UnkStruct_UB D_01ECDAC9;
extern UnkStruct_UB D_0051A999;
extern UnkStruct_I D_01E900B4;
extern UnkStruct_P D_01E97DAC;
extern UnkStruct_P D_01ECD520;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void Update__24CB3MemCardControllerBaseFv(void *);
extern "C" void func_004201F0(void *, int);
extern "C" int func_00420A50(void *);

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

// inlined result dispatch, as func_0041FAD0 (placeholder name) [G]
static inline void func_0041F0C0_inl1()
{
    if (D_01ECDAC0.field_0 != 0) {
        SetScene(0x94413E0BA2B41647UL, 0);
    } else if (D_01ECDAC6.field_0 != 0) {
        SetScene(0x94414018F8506BD2UL, 0);
    } else if (D_01ECDAC5.field_0 != 0 || D_01ECDAC9.field_0 != 0 || D_01ECDAC7.field_0 != 0) {
        SetScene(0x94413CD3ABD53F29UL, 0x3D);
    } else {
        SetScene(0x94413E0BA2B41647UL, 0);
    }
}

// 0x0041F0C0
extern "C" void func_0041F0C0(void * self, int action, void * p1, int p2)
{
    switch (action) {
    case 0:
        break;
    case 3:
        if (D_01ECDA5D.field_0 != 0 || D_01ECDA5E.field_0 != 0) {
            if (D_01E900B4.field_0 != 4) goto other;
            SetScene(0x94413FC035B0F871UL, 0);
        } else {
            func_0041F0C0_inl1();
        }
        break;
    other:  // [G] goto: retail lays this arm out of line after the dispatch arms
        func_00420A50(&D_01E97DAC);
        break;
    case 4:
        Update__24CB3MemCardControllerBaseFv(&D_01ECD520);
        break;
    case 5:
        switch (p2) {
        case 2:
            if (D_0051A999.field_0 != 0) {
                SetScene(0x94413FC1552437EAUL, 0);
            } else {
                func_0041F0C0_inl1();
            }
            break;
        case 0x31:
            func_004201F0(&D_01E97DAC, 0x31);
            break;
        case 0x30:
            func_004201F0(&D_01E97DAC, 0x30);
            break;
        case 0x2E:
            func_004201F0(&D_01E97DAC, 0x2E);
            break;
        case 0x32:
            func_004201F0(&D_01E97DAC, 0x32);
            break;
        case 0x35:
            func_004201F0(&D_01E97DAC, 0x35);
            break;
        case 0x34:
            func_004201F0(&D_01E97DAC, 0x34);
            break;
        case 0x36:
            func_004201F0(&D_01E97DAC, 0x36);
            break;
        case 0x37:
            func_004201F0(&D_01E97DAC, 0x37);
            break;
        case 0x38:
            func_004201F0(&D_01E97DAC, 0x38);
            break;
        case 0x39:
            func_004201F0(&D_01E97DAC, 0x39);
            break;
        case 0x3C:
            func_004201F0(&D_01E97DAC, 0x3C);
            break;
        case 0x3B:
            func_004201F0(&D_01E97DAC, 0x3B);
            break;
        case 0x2F:
            func_004201F0(&D_01E97DAC, 0x2F);
            break;
        case 0x3A:
            func_004201F0(&D_01E97DAC, 0x3A);
            break;
        }
        break;
    }
}
