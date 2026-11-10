// Hand-written; the lifter refused it (exact; switch jump table retargeted at retail's (tools/jtbl_retarget.py)).

// func_003F68E0 -- CB3OnlineEndOfRaceState::DealWithSecondResultsPageEvent(EGtStateAction,void*,void*,void*)
// [L] DNAT: CB3OnlineEndOfRaceState::DealWithSecondResultsPageEvent(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

enum EGtStateAction {};

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
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

struct UnkStruct_Obj {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0x94];
};
struct UnkStruct_Obj2 {
    unsigned char pad_0[0x4];
};

class CB3OnlineEndOfRaceState {
public:
    unsigned char pad_0[0x10];
    int field_10;
};

struct UnkStruct_Game;
struct UnkStruct_Game {
    unsigned char pad_0[0x1B4];
    struct UnkStruct_Menu * field_1B4;
};
struct UnkStruct_Menu {
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
    virtual void vfunc_98();
    virtual int vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
};
struct UnkStruct_D_0051BA88 { UnkStruct_Game * field_0; unsigned char pad_4[0xC]; };

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_B D_01EA2F0E;
extern UnkStruct_P D_01E95968;
extern UnkStruct_P D_01E9595C;
extern UnkStruct_P D_004EE040;
extern UnkStruct_P D_0051A6A8;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void func_00131F10(void *, void *);
extern "C" int func_003C5630(void *);
extern "C" int func_003C5510(void *);
extern "C" int func_003C5750(void *, int, void *);
extern "C" int func_003C55D0(void *);
extern "C" void func_003F7350(void *);
extern "C" void Prepare__13CB3ReplayPageFb(void *, bool);

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

// 0x003F68E0
extern "C" void func_003F68E0(CB3OnlineEndOfRaceState * self, EGtStateAction p0, void * p1, int p2)
{
    UnkStruct_Game * g = D_0051BA88.field_0;
    switch (p2) {
    case 0x43:
        func_003C5630(&D_01E95968);
        break;
    case 0x44:
        func_003C5510(&D_01E95968);
        break;
    case 0x47:
    case 0x45:
        func_003C5750(&D_01E95968, 0, (void *)(0));
        break;
    case 0x46:
        func_003C55D0(&D_01E95968);
        break;
    case 0x48:
        return;
    case 1:
    case 2:
    case 0:
        {
            UnkStruct_Menu * m = g->field_1B4;
            int r = m->vfunc_9C();
            switch (r) {
            case 2:
            case 0:
                func_00131F10(&D_004EE040, &D_0051A6A8);
                SetScene(0x94413FA737AAA797UL, 0);
                break;
            default:
                m->vfunc_E4();
                break;
            }
        }
        break;
    case 3:
        switch (g->field_1B4->vfunc_9C()) {
        case 0:
        case 2:
            D_01EA2F0E.field_0 = 0;
            func_00131F10(&D_004EE040, &D_0051A6A8);
            SetScene(0x94413FA737AAA797UL, 0);
            break;
        case 4:
            func_003F7350(self);
            break;
        case 3:
            if (self->field_10 == 0) {
                Prepare__13CB3ReplayPageFb(&D_01E9595C, 1);
                self->field_10 = 2;
            } else {
                Prepare__13CB3ReplayPageFb(&D_01E9595C, 1);
                self->field_10 = 3;
            }
            break;
        case 5:
            func_00131F10(&D_004EE040, &D_0051A6A8);
            SetScene(0x94413FA737AAA797UL, 0);
            break;
        case 1:
            break;
        }
        break;
    case 0x41:
        D_01EA2F0E.field_0 = 1;
        func_00131F10(&D_004EE040, &D_0051A6A8);
        SetScene(0x94413FA737AAA797UL, 0);
        break;
    case 0x42:
        D_01EA2F0E.field_0 = 0;
        func_00131F10(&D_004EE040, &D_0051A6A8);
        SetScene(0x94413FA737AAA797UL, 0);
        break;
    }
}
