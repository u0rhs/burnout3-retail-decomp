// CB3OnlineLobbyPage::UpdateKeyboard() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a125: chain mirrors func_00397C90; Del-branch ends with explicit return).

struct CB3MenuInput { enum EMenuControls { EMenuControls_Unk0 }; };
class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
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
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00316BE0_sub { unsigned char pad_0[0x14]; short field_14; unsigned char pad_16[0xA]; short field_20; unsigned char pad_22[0xA]; short field_2C; unsigned char pad_2E[0xA]; short field_38; unsigned char pad_3A[0x22]; short field_5C; unsigned char pad_5E[0x46]; short field_A4; unsigned char pad_A6[0xA]; short field_B0; unsigned char pad_B2[0x7A]; };
struct UnkStruct_00316BE0_D { unsigned char pad_0[0xD48]; UnkStruct_00316BE0_sub field_D48[1]; };
class CB3OnlineLobbyPage {
public:
    void UpdateKeyboard();
    unsigned char pad_0[0x13AC];
    signed char field_13AC;
};
extern UnkStruct_00316BE0_D D_004F50C0;
extern UnkStruct_D_004F6061 D_004F6061;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_P D_01E7A800;
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" void func_00316640(CB3OnlineLobbyPage *);
// 0x00316BE0
void CB3OnlineLobbyPage::UpdateKeyboard()
{
    UnkStruct_00316BE0_sub *e = &D_004F50C0.field_D48[D_004F6061.field_0];
    if (e->field_5C) {
        FEKeyboardDel__18CB3HUDSoundManagerFv(&D_01E7A800);
        signed char t = field_13AC;
        if (t == 2) {
            D_01E899C0.Show(0, 1);
            func_00316640(this);
        } else if (t == 5) {
            field_13AC = 3;
            D_01E899C0.Show(0, 1);
        }
        return;
    }
    if (e->field_14) {
        D_01E899C0.SelectNextLeft();
        FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (e->field_20) {
        D_01E899C0.SelectNextRight();
        FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (e->field_2C) {
        D_01E899C0.SelectNextUp();
        FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (e->field_38) {
        D_01E899C0.SelectNextDown();
        FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (((CB3InputManager *)&D_004F50C0)->GetMenuConfirm(0)) {
        D_01E899C0.Select();
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (e->field_A4) {
        D_01E899C0.SelectShift();
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (e->field_B0) {
        D_01E899C0.SelectCapsLock();
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (((CB3InputManager *)&D_004F50C0)->GetMenuButton((CB3MenuInput::EMenuControls)15, 0)) {
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        func_00350CF0(&D_01E899C0);
    }
}
