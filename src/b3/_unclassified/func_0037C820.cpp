// Hand-written; the lifter refused it (CB3CreateAccount2MenuPage::Update: (Up && f) || (Down && f) merged return; func_0032B2C0(...,0,1) third arg shares the switch compare constant (a2)).

// func_0037C820 -- CB3CreateAccount2MenuPage::Update()
// [L] DNAT: CB3CreateAccount2MenuPage::Update() (research/proto/new_names.csv, medium)

struct CB3MenuInput {
    enum EMenuControls { EMenuControls_Unk0 };
};
enum EB3MenuFlowFSMEvents {};
enum EGlobalStrings {};

class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    int GetMenuKeyboardShift(signed char);
    int GetMenuKeyboardCapsLock(signed char);
    int GetMenuButton(CB3MenuInput::EMenuControls, signed char);
    unsigned char pad_0[0x10];
};

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);
    void SetAllowableCharacters(EGlobalStrings);
    void SetDisplayText(unsigned short *, bool);
    void SelectNextLeft();
    void SelectNextRight();
    void SelectNextUp();
    void SelectNextDown();
    void Select();
    void SelectShift();
    void SelectCapsLock();
    void SelectSymbols();
    unsigned char pad_0[0x10];
};

class CGtLobbyPS2DirtySock {
public:
    void CreatePersona(char *);
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
    virtual int vfunc_58();
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
    virtual void vfunc_A4();
    virtual char * vfunc_A8(unsigned short);
    unsigned char pad_4[0xC];
};

struct UnkStruct_D_01E898E8 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};

struct UnkStruct_D_01EA3078 {
    int field_0;
    int field_4;
    int field_8;
    char field_C[0x20];
    char field_2C[0x20];
    char field_4C[0x40];
    char field_8C[0x40];
    char field_CC[0x3];
    char field_CF[0x3];
    unsigned char field_D2;
    unsigned char field_D3;
    unsigned char field_D4;
};
struct UnkStruct_0037C820_1 {
    void * field_0;
    void * field_4;
    void * field_8;
    void * field_C;
    void * field_10;
    void * field_14;
    void * field_18;
    void * field_1C;
    unsigned char field_20;
    unsigned char field_21;
    unsigned char pad_22[0xE];
};
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_0037C570_e0 { unsigned char pad_0[0x20]; };
struct UnkStruct_D_01E94C40 { UnkStruct_0037C570_e0 field_0[1]; };

struct UnkStruct_0037C820 {
    unsigned char pad_0[0x48];
    unsigned short field_48;
    unsigned char pad_4A[0x2];
    unsigned short * field_4C;
    unsigned char field_50;
    unsigned char field_51;
};

extern CB3InputManager D_004F50C0;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CGtLobbyPS2DirtySock D_01E3CD44;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_B D_01E898F2;
extern UnkStruct_I D_01E90424;
extern UnkStruct_I D_01EA2878;
extern UnkStruct_I D_01E8CBCC;
extern UnkStruct_D_01EA3078 D_01EA3078;
extern UnkStruct_D_01E94C40 D_01E94C40;
extern UnkStruct_P D_01E32AE0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E7A800;
extern UnkStruct_P D_004C9248;
extern UnkStruct_P D_004C9258;
extern UnkStruct_P D_004C9260;

extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" char * strcpy(char *, const char *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_0033AE60(void *, UnkStruct_0037C820_1 *);
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);

// 0x0037C820
extern "C" void func_0037C820(UnkStruct_0037C820 * self)
{
    char c[4];
    char b[12];
    UnkStruct_0037C820_1 info;
    if (D_01E90424.field_0 != 5) {
        return;
    }
    switch (self->field_50) {
    case 3:
        if (func_0032B2C0(&D_01E898E8, 0, 1) != 0) {
            return;
        }
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        self->field_50 = 0;
        break;
    case 0:
        if ((D_004F50C0.GetMenuUp(0) && func_00319360(&self->field_48)) || (D_004F50C0.GetMenuDown(0) && func_00319330(&self->field_48))) {
            return;
        }
        if (D_004F50C0.GetMenuConfirm(0)) {
            if (self->field_48 == 5) {
                self->field_50 = 1;
                D_01E899C0.Show(1, 0);
                D_01E899C0.SetAllowableCharacters((EGlobalStrings)661);
                D_01E899C0.SetDisplayText(self->field_4C, 0);
                D_01E8CBCC.field_0 = 17;
            } else {
              if (self->field_51 != 0) {
                UnkStruct_D_01EA3078 * const p = &D_01EA3078;
                snprintf(b, 9, (const char *)&D_004C9248, p->field_8, p->field_0, p->field_4);
                if (p->field_D4 != 0) {
                    strcpy(c, (const char *)&D_004C9258);
                } else {
                    strcpy(c, (const char *)&D_004C9260);
                }
                strncpy(p->field_C, ((CGtLobbyPS2DirtySock *)&D_01E3CD44)->vfunc_A8(self->field_48), 32);
                info.field_0 = p->field_C;
                info.field_4 = p->field_2C;
                info.field_8 = p->field_4C;
                info.field_C = p->field_8C;
                info.field_10 = b;
                info.field_14 = c;
                info.field_18 = p->field_CC;
                info.field_1C = p->field_CF;
                info.field_20 = p->field_D2;
                info.field_21 = p->field_D3;
                func_0033AE60(&D_01E3CD44, &info);
            } else {
                strncpy((char *)&D_01E94C40.field_0[D_01EA2878.field_0] + 0xDC3C, ((CGtLobbyPS2DirtySock *)&D_01E3CD44)->vfunc_A8(self->field_48), 32);
                D_01EA2878.field_0++;
                D_01E3CD44.CreatePersona(((CGtLobbyPS2DirtySock *)&D_01E3CD44)->vfunc_A8(self->field_48));
              }
              self->field_50 = 2;
              func_0032D080(&D_01E898E8, 0, 190, 15, 0);
            }
        } else if (D_004F50C0.GetMenuBack(0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        }
        break;
    case 1:
        if (D_004F50C0.GetMenuLeft(0)) {
            D_01E899C0.SelectNextLeft();
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuRight(0)) {
            D_01E899C0.SelectNextRight();
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuUp(0)) {
            D_01E899C0.SelectNextUp();
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuDown(0)) {
            D_01E899C0.SelectNextDown();
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuConfirm(0)) {
            D_01E899C0.Select();
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuKeyboardShift(0)) {
            D_01E899C0.SelectShift();
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (D_004F50C0.GetMenuKeyboardCapsLock(0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectCapsLock();
        } else if (D_004F50C0.GetMenuButton((CB3MenuInput::EMenuControls)14, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectSymbols();
        } else if (D_004F50C0.GetMenuButton((CB3MenuInput::EMenuControls)15, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_00350CF0(&D_01E899C0);
        } else if (D_004F50C0.GetMenuBack(0)) {
            FEKeyboardDel__18CB3HUDSoundManagerFv(&D_01E7A800);
            if (self->field_50 == 1) {
                self->field_50 = 0;
                D_01E899C0.Show(0, 0);
            }
        }
        break;
    case 2:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 0:
            break;
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        case 1:
            if (self->field_51 == 0) {
                D_01EA2878.field_0--;
            }
            int r = ((CGtLobbyPS2DirtySock *)&D_01E3CD44)->vfunc_58();
            if (r == -7) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)34, 0);
                break;
            }
            self->field_50 = 3;
            if (D_01E898F2.field_0 != 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            }
            func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, r), 0, 0);
            break;
        default:
            break;
        }
        break;
    }
}
