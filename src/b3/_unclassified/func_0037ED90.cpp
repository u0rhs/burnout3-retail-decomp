// Hand-written; the lifter refused it (CB3CreateAccountSaveMenuPage::Update: switch on state, one-case switch for field_C0==6, vfunc via pun cast, FEVerticalMove extra arg).

// Hand-written (a170): CB3CreateAccountSaveMenuPage::Update. [L] DNAT: CB3CreateAccountSaveMenuPage::Update() (research/proto/new_names.csv, medium)
struct UnkStruct_F_info {
    unsigned char pad_0[0xC];
    char field_C[0x20];
    char field_2C[0x20];
    char field_4C[0x80];
    char field_CC[0x6];
    unsigned char field_D2;
    unsigned char field_D3;
    unsigned char field_D4;
    unsigned char field_D5;
    unsigned char pad_D6[0xA];
};
struct UnkStruct_F_tmp {
    char * field_0;
    char * field_4;
    char * field_8;
    unsigned char pad_C[0x14];
    unsigned char field_20;
    unsigned char field_21;
};
struct UnkStruct_0037ED90 {
    unsigned char pad_0[0x4];
    char field_4[0x20];
    unsigned char pad_24[0x86];
    unsigned char field_AA;
    unsigned char pad_AB[0x15];
    unsigned short field_C0;
    short field_C2;
    UnkStruct_F_info * field_C4;
    unsigned char field_C8;
    unsigned char field_C9;
};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Int16 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_Ulong16 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_vt58 {
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
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_Int16 D_01E90424, D_01E8CBCC;
extern UnkStruct_D_Byte16 D_01E8954E, D_01E899DC;
extern UnkStruct_D_vt D_01E898E8, D_01E89544, D_01E89800;
extern UnkStruct_D_vt58 D_01E3CD44;
extern UnkStruct_D_Pad16 D_004F50C0, D_01E7A800, D_01E899C0, D_01E90240, D_01E32AE0, D_01E8961C;
extern UnkStruct_D_Ulong16 D_01E89810;

extern "C" int func_0032B2C0(void *, int, int);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_003BC540(void *, int, int);
extern "C" void func_003BC360(void *, int, int);
extern "C" int func_0037E440(void *);
extern "C" void func_00350CF0(void *);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardShift__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardCapsLock__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(void *, int);
extern "C" void SetDisplayText__28CB3OnScreenKeyboardComponentFPcb(void *, char *, bool);
extern "C" void SelectNextLeft__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextRight__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextUp__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextDown__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void Select__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectShift__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectCapsLock__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectSymbols__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" void RegisterAccount__20CGtLobbyPS2DirtySockFP31CGtDirtySockAccountCreateParams(void *, void *);

// 0x0037ED90
extern "C" void func_0037ED90(UnkStruct_0037ED90 * self)
{
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_C8) {
    case 2:
        if (!func_0032B2C0(&D_01E898E8, 0, 1)) {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            self->field_C8 = 0;
        }
        break;
    case 0:
        if ((GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319360(&self->field_C0))
            || (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319330(&self->field_C0))) {
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            if (self->field_C0 == 6 && self->field_AA == 0) {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 4, 3);
            } else {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~4UL, 3);
            }
            return;
        }
        if (GetMenuLeft__15CB3InputManagerFSc(&D_004F50C0, 0) || GetMenuRight__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            switch (self->field_C0) {
            case 0:
                if (self->field_C9) return;
                self->field_C8 = 1;
                if (D_01E8954E.field_0) ((UnkStruct_D_vt *)&D_01E89544)->vfunc_C();
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 1, 0);
                SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0x295);
                SetDisplayText__28CB3OnScreenKeyboardComponentFPcb(&D_01E899C0, self->field_C4->field_C, 0);
                D_01E8CBCC.field_0 = 0x11;
                break;
            case 1:
                self->field_C8 = 1;
                if (D_01E8954E.field_0) ((UnkStruct_D_vt *)&D_01E89544)->vfunc_C();
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 1, 0);
                SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0xC58);
                D_01E899DC.field_0 = 1;
                SetDisplayText__28CB3OnScreenKeyboardComponentFPcb(&D_01E899C0, self->field_C4->field_2C, 0);
                D_01E8CBCC.field_0 = 0x11;
                break;
            case 2:
                self->field_C8 = 1;
                if (D_01E8954E.field_0) ((UnkStruct_D_vt *)&D_01E89544)->vfunc_C();
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 1, 0);
                SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0xC58);
                D_01E899DC.field_0 = 1;
                SetDisplayText__28CB3OnScreenKeyboardComponentFPcb(&D_01E899C0, self->field_4, 0);
                D_01E8CBCC.field_0 = 0x11;
                break;
            case 3:
                self->field_C8 = 1;
                if (D_01E8954E.field_0) ((UnkStruct_D_vt *)&D_01E89544)->vfunc_C();
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 1, 0);
                SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0x296);
                SetDisplayText__28CB3OnScreenKeyboardComponentFPcb(&D_01E899C0, self->field_C4->field_4C, 0);
                break;
            case 4:
                self->field_C4->field_D2 = !self->field_C4->field_D2;
                func_003BC540(&D_01E8961C, 4, self->field_C4->field_D2);
                break;
            case 5:
                self->field_C4->field_D3 = !self->field_C4->field_D3;
                func_003BC540(&D_01E8961C, 5, self->field_C4->field_D3);
                break;
            }
            return;
        }
        if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            switch (self->field_C0) { case 6:
                if (self->field_AA) return;
                if (self->field_C9 == 0) {
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 1, 0);
                } else {
                    UnkStruct_F_tmp tmp;
                    tmp.field_0 = self->field_C4->field_C;
                    tmp.field_4 = self->field_C4->field_2C;
                    tmp.field_8 = self->field_C4->field_4C;
                    tmp.field_20 = self->field_C4->field_D2;
                    tmp.field_21 = self->field_C4->field_D3;
                    RegisterAccount__20CGtLobbyPS2DirtySockFP31CGtDirtySockAccountCreateParams(&D_01E3CD44, &tmp);
                    self->field_C8 = 3;
                    func_0032D080(&D_01E898E8, 0, 0x82, 0xF, 0);
                    ((UnkStruct_D_vt *)&D_01E89800)->vfunc_C();
                }
            }
        } else if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            return;
        }
        break;
    case 1:
        if (GetMenuLeft__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextLeft__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuRight__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextRight__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextUp__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectNextDown__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            Select__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuKeyboardShift__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectShift__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuKeyboardCapsLock__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xE, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xF, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_00350CF0(&D_01E899C0);
        } else if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            FEKeyboardDel__18CB3HUDSoundManagerFv(&D_01E7A800);
            if (self->field_C8 == 1) {
                self->field_C8 = 0;
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 0, 0);
                D_01E899DC.field_0 = 0;
                func_003BC360(&D_01E8961C, 6, func_0037E440(self));
            }
        }
        break;
    case 3:
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 0:
            return;
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 1, 0);
            break;
        case 1: {
            int err = ((UnkStruct_D_vt58 *)&D_01E3CD44)->vfunc_58();
            self->field_C8 = 2;
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, err), 0, 0);
            break;
        }
        default:
            break;
        }
        break;
    default:
        break;
    }
}
