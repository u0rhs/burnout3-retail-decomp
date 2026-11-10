// Hand-written; the lifter refused it (a133: keyboard rename page Update; ReadMail sibling shape + leading D_01E90424==5 guard; caps/symbols call order).

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
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_0x10 D_01E90240;
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
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
// [L] DNAT: CB3MyBurnoutProfileRenamePage::Update() (research/proto/new_names.csv, high)
// 0x003EDAD0
extern "C" void func_003EDAD0(void *self)
{
    if (D_01E90424.field_0 != 5) return;
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
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xE, 0) != 0) {
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xF, 0) != 0) {
        FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        func_00350CF0(&D_01E899C0);
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        FEKeyboardDel__18CB3HUDSoundManagerFv(&D_01E7A800);
        FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
        Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 3, 0);
    }
}
