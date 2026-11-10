// CB3OnlineLoginToLobbyState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (low); file: research/retail_names.csv -> B3OnlineLoginToLobbyState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (LoginToLobby state Action: SetScene template, 12-entry jump table in block order (0-7,10,11,8,9) without default, else-if chain for the non-login id, block-form redundant field_B4==3 test).

// func_0034A4E0 -- hand-written (L254) from the asm after the proven siblings in this file
// (B3OnlineLoginToLobbyState Handle*Events) and the SetScene template (B3OnlineJoinGameState_0032ADF0.cpp).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction widths).
// [L] DNAT: CB3OnlineLoginToLobbyState::Action(EGtStateAction,void*,void*,void*) (research/proto/new_names.csv, medium)

struct UnkStruct_0034A4E0_FSM {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(void *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];
};
struct UnkStruct_0034A4E0_Lobby {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
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
    virtual int vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual int vfunc_70();
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
    virtual int vfunc_D8();
    unsigned char pad_4[0xC];
};
struct UnkStruct_0034A4E0_P { unsigned char pad_0[0x10]; };
struct UnkStruct_0034A4E0_r { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_0034A4E0_s { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_0034A4E0_2974 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0034A4E0_2980 { UnkStruct_0034A4E0_s * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0034A4E0_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0034A4E0_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0034A4E0_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0034A4E0_Id { unsigned long field_0; };
struct UnkStruct_0034A4E0 {
    unsigned char pad_0[0xA8];
    int field_A8;
    unsigned char field_AC;
    unsigned char field_AD;
    unsigned char field_AE;
    unsigned char pad_AF[0x5];
    int field_B4;
};
extern UnkStruct_0034A4E0_B D_01E9B534;
extern UnkStruct_0034A4E0_B D_01EA3150;
extern UnkStruct_0034A4E0_B D_01E3C660;
extern UnkStruct_0034A4E0_I D_01E32AE0;
extern UnkStruct_0034A4E0_I D_01E654C8;
extern UnkStruct_0034A4E0_I D_01E9B6B8;
extern UnkStruct_0034A4E0_P D_01E9B740;
extern char D_01EA3084[];
extern char D_01EA30A4[];
extern UnkStruct_0034A4E0_P D_01E9B4CC;
extern UnkStruct_0034A4E0_P D_01E9B4C0;
extern UnkStruct_0034A4E0_P D_01EA2960;
extern UnkStruct_0034A4E0_P D_01EA2870;
extern UnkStruct_0034A4E0_P D_01E9FBA8;
extern UnkStruct_0034A4E0_P D_01E9F9F4;
extern UnkStruct_0034A4E0_P D_01E9B698;
extern UnkStruct_0034A4E0_P D_01E9C870;
extern UnkStruct_0034A4E0_Lobby D_01E3CD44;
extern UnkStruct_0034A4E0_FSM D_01EA2970;
extern UnkStruct_0034A4E0_2974 D_01EA2974;
extern UnkStruct_0034A4E0_2980 D_01EA2980;
extern UnkStruct_0034A4E0_F D_01EA2984;
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" void Prepare__25CB3OnlineLoginToLobbyPageFPcPcb(void *, char *, char *, bool);
extern "C" void Prepare__24CB3OnlineSelectLoginPageFv(void *);
extern "C" void Prepare__11CB3DNASPageFv(void *);
extern "C" void Prepare__23CB3OnlineConnectingPageFi(void *, int);
extern "C" void PrepareLobbyConnect__23CB3OnlineConnectingPageFv(void *);
extern "C" void Prepare__26CB3OnlineSelectPersonaPageFPc(void *, char *);
extern "C" void HandleConnectingEvents__26CB3OnlineLoginToLobbyStateF20EB3MenuFlowFSMEvents(UnkStruct_0034A4E0 *, int);
extern "C" void HandleSelectLoginEvents__26CB3OnlineLoginToLobbyStateF20EB3MenuFlowFSMEvents(UnkStruct_0034A4E0 *, int);
extern "C" void HandleLoggingIntoServerEvents__26CB3OnlineLoginToLobbyStateF20EB3MenuFlowFSMEvents(UnkStruct_0034A4E0 *, int);
extern "C" void func_0034B050(UnkStruct_0034A4E0 *, int);
extern "C" void func_0034AE10(UnkStruct_0034A4E0 *, int);
extern "C" int func_0037CF00(void *, int, int);
extern "C" void func_0037C570(void *);
extern "C" void func_0037C510(void *);
extern "C" void OnKeyboardCancel__26CB3OnlineOptimatchMenuPageFv(void *);
extern "C" bool func_0037E270(void *, int);
extern "C" void func_0037E680(void *);
extern "C" void func_0037E5F0(void *);
extern "C" void func_0037E600(void *);
extern "C" int func_00383830(void *, int, int);

static inline void SetScene(unsigned long h, int k)
{
    UnkStruct_0034A4E0_r * r = (UnkStruct_0034A4E0_r *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, h);
    if (D_01EA2974.field_0 == r) {
        return;
    }
    ((UnkStruct_0034A4E0_FSM *)&D_01EA2970)->vfunc_18(r, k);
    void * t = D_01EA2974.field_0;
    D_01EA2974.field_0 = (void *)r;
    UnkStruct_0034A4E0_s * s = D_01EA2980.field_0;
    if (s != 0) {
        D_01EA2984.field_0 = s->field_20;
        if (r != 0) {
            r->field_8 = s->field_20;
        }
    }
    ((UnkStruct_0034A4E0_FSM *)&D_01EA2970)->vfunc_1C(t, k);
}

#define LOBBY ((UnkStruct_0034A4E0_Lobby *)&D_01E3CD44)

// 0x0034A4E0
extern "C" void func_0034A4E0(UnkStruct_0034A4E0 * self, int p0, void * p1, int p2)
{
    switch (p0) {
    case 0:
        self->field_AE = 0;
        self->field_AC = 0;
        self->field_AD = 0;
        D_01E9B534.field_0 = 0;
        break;
    case 3:
        if (((UnkStruct_0034A4E0_Id *)p2)->field_0 == 0x94413E52D9756028UL) {
            if (D_01EA3150.field_0 != 0) {
                self->field_B4 = 2;
                Prepare__25CB3OnlineLoginToLobbyPageFPcPcb(&D_01E9B740, D_01EA3084, D_01EA30A4, false);
            } else {
                self->field_B4 = 1;
                Prepare__24CB3OnlineSelectLoginPageFv(&D_01E9B4CC);
            }
        } else if (LOBBY->vfunc_64() != 0) {
            SetScene(0x94414018F8512871UL, 0);
        } else if (D_01E32AE0.field_0 == 0x17) {
            self->field_B4 = 0;
            PrepareLobbyConnect__23CB3OnlineConnectingPageFv(&D_01E9B4C0);
        } else if (D_01E654C8.field_0 == 9) {
            self->field_B4 = 0;
            Prepare__23CB3OnlineConnectingPageFi(&D_01E9B4C0, D_01E9B6B8.field_0);
        } else if (D_01E3C660.field_0 != 0) {
            self->field_B4 = 0;
            Prepare__11CB3DNASPageFv(&D_01EA2960);
        } else {
            self->field_B4 = 0;
            Prepare__23CB3OnlineConnectingPageFi(&D_01E9B4C0, D_01E9B6B8.field_0);
        }
        break;
    case 5:
        switch (self->field_B4) {
        case 0:
            HandleConnectingEvents__26CB3OnlineLoginToLobbyStateF20EB3MenuFlowFSMEvents(self, p2);
            break;
        case 1:
            HandleSelectLoginEvents__26CB3OnlineLoginToLobbyStateF20EB3MenuFlowFSMEvents(self, p2);
            break;
        case 2:
            HandleLoggingIntoServerEvents__26CB3OnlineLoginToLobbyStateF20EB3MenuFlowFSMEvents(self, p2);
            break;
        case 3:
            switch (p2) {
            case 3:
                self->field_B4 = 1;
                Prepare__24CB3OnlineSelectLoginPageFv(&D_01E9B4CC);
                break;
            case 1:
                if (self->field_B4 == 3) {
                    self->field_B4 = 1;
                    Prepare__24CB3OnlineSelectLoginPageFv(&D_01E9B4CC);
                }
                break;
            }
            break;
        case 4:
            func_0034B050(self, p2);
            break;
        case 5:
            switch (p2) {
            case 3:
            case 1:
                self->field_B4 = 4;
                Prepare__26CB3OnlineSelectPersonaPageFPc(&D_01EA2870, 0);
                break;
            case 0x22:
                func_0037CF00(&D_01E9FBA8, 0, 0);
                break;
            case 0x1B:
                func_0037C570(&D_01E9FBA8);
                break;
            case 0x19:
                func_0037C510(&D_01E9FBA8);
                break;
            case 0x1A:
                OnKeyboardCancel__26CB3OnlineOptimatchMenuPageFv(&D_01E9FBA8);
                break;
            }
            break;
        case 6:
            switch (p2) {
            case 1:
                self->field_B4 = 7;
                func_0037E270(&D_01E9B698, 1);
                break;
            case 3:
                self->field_B4 = 4;
                Prepare__26CB3OnlineSelectPersonaPageFPc(&D_01EA2870, 0);
                break;
            case 0x1B:
                func_0037E680(&D_01E9F9F4);
                break;
            case 0x19:
                func_0037E5F0(&D_01E9F9F4);
                break;
            case 0x1A:
                func_0037E600(&D_01E9F9F4);
                break;
            }
            break;
        case 7:
            switch (p2) {
            case 1:
            case 3:
                self->field_B4 = 4;
                Prepare__26CB3OnlineSelectPersonaPageFPc(&D_01EA2870, 0);
                break;
            }
            break;
        case 10:
            func_0034AE10(self, p2);
            break;
        case 11:
            switch (p2) {
            case 1:
                SetScene(0x94413FC035B0F871UL, 0);
                break;
            case 3:
                SetScene(0x94413FC035B0F871UL, 0);
                break;
            }
            break;
        case 8:
            switch (p2) {
            case 1:
                if (LOBBY->vfunc_D8() != 0 && self->field_AE != 0 && LOBBY->vfunc_70() == 0) {
                    self->field_AE = 0;
                    SetScene(0x94414018F8506AFEUL, 1);
                } else {
                    self->field_B4 = 9;
                    func_00383830(&D_01E9C870, self->field_A8, 0);
                }
                break;
            }
            break;
        case 9:
            switch (p2) {
            case 1:
                SetScene(0x94414018F8535FC2UL, 0);
                break;
            case 3:
                SetScene(0x94414018F8512871UL, 0);
                break;
            }
            break;
        }
        break;
    }
}
