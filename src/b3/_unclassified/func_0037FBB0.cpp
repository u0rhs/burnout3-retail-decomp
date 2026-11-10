// Hand-written; the lifter refused it (exact; switch jump table retargeted at retail's (tools/jtbl_retarget.py)).

// func_0037FBB0 -- CB3OnlineCreateAccountState::Action(EGtStateAction,void*,void*,void*)
// [L] DNAT: CB3OnlineCreateAccountState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

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
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };

class CB3OnlineCreateAccountState {
public:
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    int field_18;
    unsigned char field_1C[0x20];
    unsigned char field_3C[0x20];
    unsigned char field_5C;
    unsigned char pad_5D[0x7F];
    char field_DC[3];
    char field_DF[3];
    unsigned char field_E2;
    unsigned char field_E3;
    unsigned char field_E4;
    unsigned char field_E5;
    unsigned char pad_E6[0x2];
    unsigned char field_E8;
    unsigned char pad_E9[0x3];
    int field_EC;
};

struct UnkStruct_D_004E2918 { int field_0; };
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_P D_004C92D0;
extern UnkStruct_P D_004C92D8;
extern UnkStruct_P D_004C92E0;
extern UnkStruct_P D_004C92E8;
extern UnkStruct_P D_004C92F0;
extern UnkStruct_P D_004C92F8;
extern UnkStruct_P D_004C9300;
extern UnkStruct_P D_004C9308;
extern UnkStruct_P D_004C9310;
extern UnkStruct_P D_004C9318;
extern UnkStruct_P D_004C9320;
extern UnkStruct_P D_004C9328;
extern UnkStruct_P D_01E9F9F4;
extern UnkStruct_P D_01E9FAC0;
extern UnkStruct_P D_01E9FBA8;
extern UnkStruct_P D_01E9B698;
extern UnkStruct_P D_01EA2E70;
extern UnkStruct_P D_01EA2EA2;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;

extern "C" char * strcpy(char *, const char *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_0037F640(void *, int);
extern "C" int func_0045F630(void *);
extern "C" bool func_0037E270(void *, int);
extern "C" int func_0037CF00(void *, int, int);
extern "C" void func_0037E680(void *);
extern "C" void func_0045CB70(void *);
extern "C" void func_0037C570(void *);
extern "C" void func_0037E5F0(void *);
extern "C" void func_0045CA40(void *);
extern "C" void func_0037C510(void *);
extern "C" void func_0037E600(void *);
extern "C" void func_0045CA50(void *);
extern "C" void OnKeyboardCancel__26CB3OnlineOptimatchMenuPageFv(void *);

static inline void SetScene(unsigned long h)
{
    UnkStruct_r * r = (UnkStruct_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r, 0);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t, 0);
}

// 0x0037FBB0
extern "C" void func_0037FBB0(CB3OnlineCreateAccountState * self, EGtStateAction p0, void * p1, long p2, void * p3)
{
    switch (p0) {
    case 3:
        self->field_EC = 0;
        self->field_E8 = 0;
        self->field_1C[0] = 0;
        self->field_3C[0] = 0;
        self->field_5C = 0;
        switch (D_004E2918.field_0) {
        case 0:
            strcpy(self->field_DC, (const char *)&D_004C92D0);
            strcpy(self->field_DF, (const char *)&D_004C92D8);
            break;
        case 1:
        default:
            strcpy(self->field_DC, (const char *)&D_004C92E0);
            strcpy(self->field_DF, (const char *)&D_004C92D8);
            break;
        case 2:
            strcpy(self->field_DC, (const char *)&D_004C92E8);
            strcpy(self->field_DF, (const char *)&D_004C92E8);
            break;
        case 3:
            strcpy(self->field_DC, (const char *)&D_004C92F0);
            strcpy(self->field_DF, (const char *)&D_004C92F0);
            break;
        case 4:
            strcpy(self->field_DC, (const char *)&D_004C92F8);
            strcpy(self->field_DF, (const char *)&D_004C92F8);
            break;
        case 5:
            strcpy(self->field_DC, (const char *)&D_004C9300);
            strcpy(self->field_DF, (const char *)&D_004C9300);
            break;
        case 6:
            strcpy(self->field_DC, (const char *)&D_004C9308);
            strcpy(self->field_DF, (const char *)&D_004C9308);
            break;
        case 7:
            strcpy(self->field_DC, (const char *)&D_004C9310);
            strcpy(self->field_DF, (const char *)&D_004C9310);
            break;
        case 8:
            strcpy(self->field_DC, (const char *)&D_004C92E0);
            strcpy(self->field_DF, (const char *)&D_004C92D8);
            break;
        case 9:
            strcpy(self->field_DC, (const char *)&D_004C9318);
            strcpy(self->field_DF, (const char *)&D_004C9318);
            break;
        case 10:
            strcpy(self->field_DC, (const char *)&D_004C9320);
            strcpy(self->field_DF, (const char *)&D_004C9320);
            break;
        case 11:
            strcpy(self->field_DC, (const char *)&D_004C9328);
            strcpy(self->field_DF, (const char *)&D_004C9328);
            break;
        }
        self->field_10 = 1;
        self->field_14 = 1;
        self->field_18 = 0x7C8;
        self->field_E2 = 0;
        self->field_E3 = 0;
        self->field_E4 = 1;
        self->field_E5 = 0;
        func_0037F640(&D_01E9F9F4, 0);
        break;
    case 5:
        switch (p2) {
        case 1:
            switch (self->field_EC) {
            case 0:
                self->field_EC = 1;
                func_0045F630(&D_01E9FAC0);
                break;
            case 1:
                self->field_EC = 3;
                func_0037E270(&D_01E9B698, 0);
                break;
            case 2:
                self->field_EC = 3;
                func_0037E270(&D_01E9B698, 0);
                break;
            case 3:
                self->field_E8 = 1;
                strcpy((char *)&D_01EA2E70, (const char *)self->field_1C);
                strcpy((char *)&D_01EA2EA2, (const char *)self->field_3C);
                SetScene(0x94414018F8506BD2UL);
                break;
            }
            break;
        case 3:
            switch (self->field_EC) {
            case 0:
                SetScene(0x94414018F8506BD2UL);
                break;
            case 1:
                self->field_EC = 0;
                func_0037F640(&D_01E9F9F4, 0);
                break;
            case 2:
                self->field_EC = 0;
                func_0037F640(&D_01E9F9F4, 0);
                break;
            }
            break;
        case 0x22:
            self->field_EC = 2;
            func_0037CF00(&D_01E9FBA8, 1, 0);
            break;
        case 0x1B:
            switch (self->field_EC) {
            case 0:
                func_0037E680(&D_01E9F9F4);
                break;
            case 1:
                func_0045CB70(&D_01E9FAC0);
                break;
            case 2:
                func_0037C570(&D_01E9FBA8);
                break;
            }
            break;
        case 0x19:
            switch (self->field_EC) {
            case 0:
                func_0037E5F0(&D_01E9F9F4);
                break;
            case 1:
                func_0045CA40(&D_01E9FAC0);
                break;
            case 2:
                func_0037C510(&D_01E9FBA8);
                break;
            }
            break;
        case 0x1A:
            switch (self->field_EC) {
            case 0:
                func_0037E600(&D_01E9F9F4);
                break;
            case 1:
                func_0045CA50(&D_01E9FAC0);
                break;
            case 2:
                OnKeyboardCancel__26CB3OnlineOptimatchMenuPageFv(&D_01E9FBA8);
                break;
            }
            break;
        }
        break;
    }
}
