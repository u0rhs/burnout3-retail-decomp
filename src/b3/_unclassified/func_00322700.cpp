// Hand-written; the lifter refused it (L255: Action handler, SetScene inline, jtbl cases 0-6 + default).

// func_00322700 -- FSM state Action handler [G] (a1 = action; SetScene inline as B3OnlineMenuState_00323E30.cpp).
// [G] DNAT hint (research/proto/new_names.csv, low): CB3MyBurnoutState::Action(EGtStateAction,void*,void*,void*).

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
struct UnkStruct_00322700 {
    unsigned char pad_0[0x10];
    int field_10;
};
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_P D_01E94F30;
extern UnkStruct_I D_01E94F34;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void Construct__16CB3MyBurnoutPageFv(void *);
extern "C" int func_00322450(void *);

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

// 0x00322700
extern "C" void func_00322700(UnkStruct_00322700 * self, int action, void * p1, void * p2, void * p3)
{
    switch (action) {
    case 0:
        Construct__16CB3MyBurnoutPageFv(&D_01E94F30);
        break;
    case 3:
        func_00322450(&D_01E94F30);
        if (p3 != 0) {
            self->field_10 = (int)p3;
        }
        break;
    case 5:
        switch ((int)p2) {
        case 1:
            switch (D_01E94F34.field_0) {
            case 0:
                SetScene(0x94413FC1552CB98FUL, 0);
                break;
            case 1:
                SetScene(0x94413FC15F6D9400UL, 0);
                break;
            case 2:
                SetScene(0x94413FC15F5A6380UL, 0);
                break;
            case 3:
                SetScene(0x94413FC1552CB1E0UL, 0);
                break;
            case 4:
                SetScene(0x94413FC165859B62UL, 0);
                break;
            case 5:
                SetScene(0x94413FC16D891965UL, 0);
                break;
            case 6:
                SetScene(0x94413FC112F8BDA7UL, 0);
                break;
            default:
                SetScene(0x94413FC035B0F871UL, 0);
                break;
            }
            break;
        case 3:
            if (self->field_10 == 1) {
                SetScene(0x94413E52C3BF9CAAUL, 1);
            } else {
                SetScene(0x94413FC035B0F871UL, 0);
            }
            break;
        }
        break;
    }
}
