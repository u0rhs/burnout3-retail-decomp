// CB3OnlineSelectLoginPage::UpdateExistingAccount() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (if/else keyboard vs menu, inlined OnKeyboardCancel, trailing return).

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
    void SelectNextLeft();
    void SelectNextRight();
    void SelectNextUp();
    void SelectNextDown();
    void Select();
    void SelectShift();
    void SelectCapsLock();
    void SelectSymbols();
    void SetDisplayText(char *, bool);
    void SetAllowableCharacters(EGlobalStrings);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8CBCC { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E89626 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8D4FA { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E899DC { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8961C { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D4F0 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E3CD44 { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(char *); unsigned char pad_4[0xC]; };
extern CB3InputManager D_004F50C0;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E7A800;
extern UnkStruct_P D_01ECD520;
extern UnkStruct_P D_01E898E8;
extern UnkStruct_P D_004C6EA0, D_004C6EA8;
extern UnkStruct_D_01E8CBCC D_01E8CBCC;
extern UnkStruct_D_01E89626 D_01E89626;
extern UnkStruct_D_01E8D4FA D_01E8D4FA;
extern UnkStruct_D_01E899DC D_01E899DC;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E8D4F0 D_01E8D4F0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" void func_00420B60(void *);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void func_003496C0(void *);
extern "C" bool func_00319360(void *);
extern "C" bool func_00319330(void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(void *, const void *, const void *, EGlobalStrings, unsigned int);

class CB3OnlineSelectLoginPage {
public:
    void OnKeyboardCancel();
    void UpdateExistingAccount();
    unsigned char pad_0[0x4];
    char field_4[0x32];
    char field_36[0x32];
    unsigned char field_68;
    unsigned char pad_69[0x7];
    unsigned char field_70;
    unsigned char field_71;
    unsigned char field_72;
    unsigned char pad_73[0x7D];
    short field_F0;
    short field_F2;
    int field_F4;
    unsigned char pad_F8[0x36];
    unsigned char field_12E;
    unsigned char pad_12F[0x27];
    unsigned char field_156;
};
inline void CB3OnlineSelectLoginPage::OnKeyboardCancel()
{
    if (field_72 != 0) {
        if (D_01E89626.field_0 != 0) {
            ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
        }
        func_003BE5A0(&D_01E8961C, ((char *)this + 0xF0), ((char *)this + 0xF8));
        if (field_72 == 2) {
            D_01E899DC.field_0 = 0;
        }
        field_72 = 0;
        D_01E899C0.Show(0, 0);
    }
}

// 0x003486B0
void CB3OnlineSelectLoginPage::UpdateExistingAccount()
{
    if (field_72 != 0) {
        if (D_004F50C0.GetMenuLeft(0)) {
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectNextLeft();
        } else if (D_004F50C0.GetMenuRight(0)) {
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectNextRight();
        } else if (D_004F50C0.GetMenuUp(0)) {
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectNextUp();
        } else if (D_004F50C0.GetMenuDown(0)) {
            FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectNextDown();
        } else if (D_004F50C0.GetMenuConfirm(0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.Select();
        } else if (D_004F50C0.GetMenuKeyboardShift(0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            D_01E899C0.SelectShift();
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
            OnKeyboardCancel();
            if (D_01E8D4FA.field_0 != 0) {
                ((UnkStruct_D_01E8D4F0 *)&D_01E8D4F0)->vfunc_C();
            }
        }
    } else {
    if ((D_004F50C0.GetMenuUp(0) && func_00319360((char *)this + 0xF0)) ||
        (D_004F50C0.GetMenuDown(0) && func_00319330((char *)this + 0xF0))) {
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        return;
    }
    if (D_004F50C0.GetMenuConfirm(0)) {
        unsigned short sel = field_F0;
        if (sel == 0) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            if (field_72 == 0) {
                D_01E899C0.Show(1, 1);
                field_72 = 1;
                if (D_01E89626.field_0 != 0) {
                    ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
                }
            }
            D_01E899C0.SetDisplayText(field_4, 0);
            D_01E899C0.SetAllowableCharacters((EGlobalStrings)0x295);
            D_01E8CBCC.field_0 = 0x11;
        } else if (sel == 1) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            if (field_72 == 0) {
                D_01E899C0.Show(1, 1);
                field_72 = 2;
                if (D_01E89626.field_0 != 0) {
                    ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
                }
            }
            D_01E899DC.field_0 = 1;
            D_01E899C0.SetDisplayText(field_36, 0);
            D_01E899C0.SetAllowableCharacters((EGlobalStrings)0xC58);
            D_01E8CBCC.field_0 = 0x11;
        } else if (sel == 2 && field_12E == 0) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_8C(field_4);
            field_70 = 3;
            func_0032D080(&D_01E898E8, 0, 0x4F, 0xF, 0);
        } else if (sel == 3) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(&D_01E8D4F0, &D_004C6EA0, &D_004C6EA8, (EGlobalStrings)0x4C, 0x67);
            if (field_72 == 0) {
                D_01E899C0.Show(1, 1);
                field_72 = 3;
                if (D_01E89626.field_0 != 0) {
                    ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
                }
            }
            D_01E899C0.SetAllowableCharacters((EGlobalStrings)0x296);
            D_01E8CBCC.field_0 = 0x40;
        } else if (sel == 4 && field_156 == 0) {
            field_68 = 1;
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
    }
    if (D_004F50C0.GetMenuBack(0)) {
        func_00420B60(&D_01ECD520);
        FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
        func_003496C0(this);
    }
    }
    return;
}
