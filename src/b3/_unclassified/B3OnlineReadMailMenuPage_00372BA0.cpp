// CB3OnlineReadMailMenuPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineReadMailMenuPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (else-if keyboard dispatch).

class CB3InputManager {
public:
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    int GetMenuConfirm(signed char);
    int GetMenuKeyboardShift(signed char);
    int GetMenuKeyboardCapsLock(signed char);
    int GetMenuBack(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_0x10 { unsigned char pad_0[0x10]; };
struct UnkStruct_25CB3OnlineReadMailMenuPage { unsigned char pad_0[0x28]; int field_28; };
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_0x10 D_01E899C0, D_01E7A800;
extern "C" int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void SelectNextLeft__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextRight__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextUp__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextDown__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void Select__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectShift__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectCapsLock__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectSymbols__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void Update__25CB3OnlineReadMailMenuPageFv(UnkStruct_25CB3OnlineReadMailMenuPage * self)
{
    if (D_004F50C0.GetMenuLeft(0) != 0) {
        SelectNextLeft__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuRight(0) != 0) {
        SelectNextRight__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuUp(0) != 0) {
        SelectNextUp__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuDown(0) != 0) {
        SelectNextDown__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        FEKeyboardMove__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuConfirm(0) != 0) {
        Select__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuKeyboardShift(0) != 0) {
        SelectShift__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (D_004F50C0.GetMenuKeyboardCapsLock(0) != 0) {
        SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xE, 0) != 0) {
        SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xF, 0) != 0) {
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        func_00350CF0(&D_01E899C0);
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        self->field_28 = 0;
        Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
    }
}
