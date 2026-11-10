// Hand-written; the lifter refused it (CB3OnlineMenuState::Action: case 0:default: first for delay-slot fill, SetScene(h, D_01EA2F08) for s0/s1, stacked cases).

// func_003242F0 -- CB3OnlineMenuState::Action(EGtStateAction,void*,void*,void*)
// [L] DNAT: CB3OnlineMenuState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

enum EGtStateAction {};
enum EB3MenuFlowFSMEvents {};
enum EGtBuddyPresence {};

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
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004E2918 { int field_0; };

class CGtBuddiesPS2DirtySock {
public:
    void SetPresence(EGtBuddyPresence, bool);
    unsigned char pad_0[0x10];
};
class CGtBuddies {
public:
    void SetPresenceDetail(char *, char *, char *);
    unsigned char pad_0[0x10];
};

class CB3OnlineMenuState {
public:
    void HandleMainMenuEvents(EB3MenuFlowFSMEvents);
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_P D_01E9C870;
extern UnkStruct_I D_01E9C874;
extern UnkStruct_I D_01EA2F08;
extern UnkStruct_P D_0051BA44;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern UnkStruct_D_004E2918 D_004E2918;
extern char * D_004D1B70[];
extern UnkStruct_P D_01E99840;
extern UnkStruct_P D_01EA1B20;
extern UnkStruct_P D_01EA1B24;
extern UnkStruct_P D_01E9B634;
extern UnkStruct_P D_01EA08A0;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;

extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_00383830(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" void SetPresenceDetail__10CGtBuddiesFPcPcPc(void *, char *, char *, char *);
extern "C" int func_00323A10(void *);
extern "C" void HandleMainMenuEvents__18CB3OnlineMenuStateF20EB3MenuFlowFSMEvents(void *, int);
extern "C" void func_00323C60(void *, int);
extern "C" int func_0045B1F0(void *);
extern "C" int func_00438520(void *, void *, int);
extern "C" int func_0043B4A0(void *, void *);

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

static inline void SetSceneK(unsigned long h, int k)
{
    UnkStruct_r * r;
    void * t;
    r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, k);
    t = D_01EA2974.field_0;
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

// 0x003242F0
extern "C" void func_003242F0(CB3OnlineMenuState * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    switch (p0) {
    case 0:
        self->field_10 = 0;
        break;
    case 3:
        {
            unsigned long id = *(unsigned long *)p2;
            if (id == 0x94413E2F8A91F137UL) {
                switch (self->field_10) {
                case 0:
                default:
                    func_00323A10(&D_01E99840);
                    break;
                case 1:
                    func_00383830(&D_01E9C870, -1, 0);
                    break;
                case 2:
                    func_0045B1F0(&D_01EA1B20);
                    break;
                case 3:
                    func_00438520(&D_01E9B634, &D_01EA1B24, 0);
                    break;
                case 4:
                    func_0043B4A0(&D_01EA08A0, &D_01EA1B24);
                    break;
                }
            } else if (id == 0x94414018F8535FC2UL) {
                char name[100];
                char status[100];
                self->field_10 = 1;
                func_00383830(&D_01E9C870, -1, 0);
                ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 5), name, 100);
                ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(func_00271A00(&D_0051BA44, 0xC08), status, 100);
                SetPresenceDetail__10CGtBuddiesFPcPcPc(&D_01E3D390, name, status, D_004D1B70[D_004E2918.field_0]);
                D_01E3D390.SetPresence((EGtBuddyPresence)1, 0);
            } else {
                self->field_10 = 0;
                func_00323A10(&D_01E99840);
            }
        }
        break;
    case 5:
        switch (self->field_10) {
        case 0:
        default:
            self->HandleMainMenuEvents((EB3MenuFlowFSMEvents)(int)p2);
            break;
        case 1:
            switch ((int)p2) {
            case 1:
                {
                    int k = D_01E9C874.field_0;
                    D_01EA2F08.field_0 = k;
                    SetScene(0x94414018F8535FC2UL, D_01EA2F08.field_0);
                }
                break;
            case 3:
                self->field_10 = 0;
                func_00323A10(&D_01E99840);
                break;
            case 0x24:
                SetScene(0x94413E2F8A91F137UL, 1);
                break;
            }
            break;
        case 2:
            func_00323C60(self, (int)p2);
            break;
        case 3:
            switch ((int)p2) {
            case 1:
            case 3:
                self->field_10 = 2;
                func_0045B1F0(&D_01EA1B20);
                break;
            case 0x24:
                SetScene(0x94413E2F8A91F137UL, 1);
                break;
            }
            break;
        case 4:
            switch ((int)p2) {
            case 1:
            case 3:
                self->field_10 = 2;
                func_0045B1F0(&D_01EA1B20);
                break;
            case 0x24:
                SetScene(0x94413E2F8A91F137UL, 1);
                break;
            }
            break;
        }
        break;
    }
}
