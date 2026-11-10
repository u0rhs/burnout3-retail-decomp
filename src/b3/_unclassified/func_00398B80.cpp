// Hand-written; the lifter refused it (a84: CB3OnlineGameCreateOptionsPage::UpdateKeyboard [L] DNAT; sibling UpdateChat__22CB3OnlineOpenLobbyPageFv else-if chain with Confirm last).

// UpdateKeyboard__30CB3OnlineGameCreateOptionsPageFv -- CB3OnlineGameCreateOptionsPage::UpdateKeyboard() [L] DNAT
struct CB3MenuInput {
    enum EMenuControls { EMenuControls_Unk0 };
};
enum EB3MenuFlowFSMEvents {};
enum EB3ChatDisplayOrientation {};
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
    void UnRegisterKeyboardCallbacks();
    unsigned char pad_0[0x10];
};
class CB3ChatDisplayComponent {
public:
    void SetOrientation(EB3ChatDisplayOrientation);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_00397C90 {
    unsigned char pad_0[0xE0];
    int field_E0;
    unsigned char pad_E4[0x378];
    unsigned char field_45C;
    unsigned char field_45D;
    unsigned char pad_45E[2];
};
extern CB3InputManager D_004F50C0;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CB3ChatDisplayComponent D_01E8CBE0;
extern UnkStruct_P D_01E90240;
extern UnkStruct_P D_01E7A800;
struct UnkStruct_D_01E89544 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E8954E {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8954E D_01E8954E;
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void func_00396D30(UnkStruct_00397C90 *);
extern "C" void func_00396E50(UnkStruct_00397C90 *);
extern "C" void func_00396A90(UnkStruct_00397C90 *);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" int func_0022CBE0(void *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);

// [L] DNAT: CB3OnlineGameCreateOptionsPage::UpdateKeyboard() (research/proto/new_names.csv, high)
// 0x00398B80
extern "C" void UpdateKeyboard__30CB3OnlineGameCreateOptionsPageFv(UnkStruct_00397C90 * self)
{
    if (D_004F50C0.GetMenuBack(0)) {
        D_01E899C0.UnRegisterKeyboardCallbacks();
        D_01E899C0.Show(0, 0);
        self->field_E0 = 0;
    } else if (D_004F50C0.GetMenuLeft(0)) {
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
    } else if (D_004F50C0.GetMenuKeyboardShift(0)) {
        D_01E899C0.SelectShift();
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuKeyboardCapsLock(0)) {
        D_01E899C0.SelectCapsLock();
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuButton((CB3MenuInput::EMenuControls)14, 0)) {
        D_01E899C0.SelectSymbols();
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuButton((CB3MenuInput::EMenuControls)15, 0)) {
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        func_00350CF0(&D_01E899C0);
    } else if (D_004F50C0.GetMenuConfirm(0)) {
        D_01E899C0.Select();
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    }
}
