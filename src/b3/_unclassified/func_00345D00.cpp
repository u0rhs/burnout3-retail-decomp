// Hand-written; the lifter refused it (a82: Action FSM from sibling HandleRetrieveConfigEvents shapes; SetScene blocks inline, early return when scene equal, case 3/4 return).

// func_00345D00 -- [L] DNAT: CB3EndOfRaceState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)
enum EGtStateAction {};
enum EB3MenuFlowFSMEvents {};
enum EGlobalStrings {};
enum EB3MessageBoxType {};

class CB3ErrorPage {
public:
    void Prepare(EGlobalStrings, EGlobalStrings, EB3MessageBoxType);
    unsigned char pad_0[0x10];
};
class CB3OnlineRetrieveConfigsPage {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
class CB3OnlineSelNetConfigPage {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};

struct UnkStruct_00345D00_3 {
    unsigned char pad_0[0x20];
    float field_20;
};
struct UnkStruct_00345D00_5 {
    unsigned char pad_0[0x8];
    float field_8;
};
struct UnkStruct_D_01EA2974 {
    void * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01EA2970 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01EA2980 {
    UnkStruct_00345D00_3 * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E3C620 {
    virtual void vfunc_8();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0051BA90 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_01E6548B {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_01E3C660 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_01E654C8 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E9B6B8 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];
};

class CB3EndOfRaceState {
public:
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E3C620 D_01E3C620;
extern UnkStruct_D_0051BA90 D_0051BA90;
extern UnkStruct_D_01E6548B D_01E6548B;
extern UnkStruct_D_01E3C660 D_01E3C660;
extern UnkStruct_D_01E654C8 D_01E654C8;
extern UnkStruct_D_01E9B6B8 D_01E9B6B8;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3ErrorPage D_01E95B4C;
extern CB3OnlineRetrieveConfigsPage D_01E9B690;
extern CB3OnlineSelNetConfigPage D_01E9B6B4;

extern "C" int GetAdapterErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_0022D2D0(void *);
extern "C" void HandleRetrieveConfigEvents__28CB3OnlineOpenConnectionStateF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents);

// 0x00345D00
extern "C" void func_00345D00(CB3EndOfRaceState * self, EGtStateAction p0, void * p1, void * p2, void * p3)
{
    switch (p0) {
    default:
        break;
    case 3:
        if (D_01E3C660.field_0 != 0 && D_01E654C8.field_0 == 9) {
            D_01E9B6B8.field_0 = -1;
            UnkStruct_00345D00_5 * r0 = (UnkStruct_00345D00_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94414018F8506BD2);
            if (D_01EA2974.field_0 == r0) {
                return;
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r0, 0);
            void * t0 = D_01EA2974.field_0;
            D_01EA2974.field_0 = (void *)r0;
            UnkStruct_00345D00_3 * t1 = D_01EA2980.field_0;
            if (t1 != 0) {
                D_01EA2984.field_0 = t1->field_20;
                if (r0 != 0) {
                    r0->field_8 = t1->field_20;
                }
            }
            ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t0, 0);
        } else {
            self->field_10 = 0;
            D_01E9B690.Prepare();
        }
        break;
    case 5:
        switch (self->field_10) {
        case 0:
            switch ((int)p2) {
            case 1:
                self->field_10 = 1;
                D_01E9B6B4.Prepare();
                break;
            case 20: {
                self->field_10 = 2;
                int r7 = func_0022D2D0(&D_01E3C620);
                if ((unsigned int)(r7 - 3) < 3) {
                    D_01E95B4C.Prepare((EGlobalStrings)85, (EGlobalStrings)GetAdapterErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r7), (EB3MessageBoxType)7);
                } else {
                    D_01E95B4C.Prepare((EGlobalStrings)85, (EGlobalStrings)GetAdapterErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r7), (EB3MessageBoxType)2);
                }
                break;
            }
            case 3: {
                UnkStruct_00345D00_5 * r4 = (UnkStruct_00345D00_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC035B0F871);
                if (D_01EA2974.field_0 == r4) {
                    return;
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r4, 0);
                void * t2 = D_01EA2974.field_0;
                D_01EA2974.field_0 = (void *)r4;
                UnkStruct_00345D00_3 * t3 = D_01EA2980.field_0;
                if (t3 != 0) {
                    D_01EA2984.field_0 = t3->field_20;
                    if (r4 != 0) {
                        r4->field_8 = t3->field_20;
                    }
                }
                ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t2, 0);
                break;
            }
            }
            break;
        case 1:
            HandleRetrieveConfigEvents__28CB3OnlineOpenConnectionStateF20EB3MenuFlowFSMEvents(self, (EB3MenuFlowFSMEvents)(int)p2);
            break;
        case 2:
            switch ((int)p2) {
            case 1: {
                UnkStruct_00345D00_5 * r5 = (UnkStruct_00345D00_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC035B0F871);
                if (D_01EA2974.field_0 != r5) {
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
                    void * t4 = D_01EA2974.field_0;
                    D_01EA2974.field_0 = (void *)r5;
                    UnkStruct_00345D00_3 * t5 = D_01EA2980.field_0;
                    if (t5 != 0) {
                        D_01EA2984.field_0 = t5->field_20;
                        if (r5 != 0) {
                            r5->field_8 = t5->field_20;
                        }
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t4, 0);
                }
                if (func_0022D2D0(&D_01E3C620) == 4 || func_0022D2D0(&D_01E3C620) == 3 || func_0022D2D0(&D_01E3C620) == 5) {
                    D_0051BA90.field_0 = 1;
                    D_01E6548B.field_0 = 1;
                }
                ((UnkStruct_D_01E3C620 *)&D_01E3C620)->vfunc_8();
                break;
            }
            case 3: {
                UnkStruct_00345D00_5 * r6 = (UnkStruct_00345D00_5 *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FC035B0F871);
                if (D_01EA2974.field_0 != r6) {
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r6, 0);
                    void * t6 = D_01EA2974.field_0;
                    D_01EA2974.field_0 = (void *)r6;
                    UnkStruct_00345D00_3 * t7 = D_01EA2980.field_0;
                    if (t7 != 0) {
                        D_01EA2984.field_0 = t7->field_20;
                        if (r6 != 0) {
                            r6->field_8 = t7->field_20;
                        }
                    }
                    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t6, 0);
                }
                ((UnkStruct_D_01E3C620 *)&D_01E3C620)->vfunc_8();
                break;
            }
            }
            break;
        case 3:
        case 4:
            return;
        }
        break;
    }
}
