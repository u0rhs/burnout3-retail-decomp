// Hand-written; the lifter refused it (keyboard page input chain; one-case switch + explicit return after back block).

class CB3InputManager { public: unsigned char pad_0[0x10]; };
class CB3HUDSoundManager { public: void FEKeyboardDel(); void FEKeyboardMove(); void FEKeyboardSel(); unsigned char pad_0[0x10]; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_0045AE20 {
    unsigned char pad_0[0xD4D];
    signed char field_D4D;
};
extern CB3InputManager D_004F50C0;
extern signed char D_004F6061[];
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_Pad16 D_01E899C0;
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

// 0x0045AE20
extern "C" void func_0045AE20(UnkStruct_0045AE20 * self)
{
    char * ctrl = (char *)&D_004F50C0 + D_004F6061[0] * 0x12C + 0xD48;
    if (*(short *)(ctrl + 0x5C) != 0) {
        D_01E7A800.FEKeyboardDel();
        switch (self->field_D4D) {
        case 3:
            self->field_D4D = 1;
            Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, true);
            break;
        }
        return;
    } else if (*(short *)(ctrl + 0x14) != 0) {
        SelectNextLeft__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardMove();
    } else if (*(short *)(ctrl + 0x20) != 0) {
        SelectNextRight__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardMove();
    } else if (*(short *)(ctrl + 0x2C) != 0) {
        SelectNextUp__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardMove();
    } else if (*(short *)(ctrl + 0x38) != 0) {
        SelectNextDown__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardMove();
    } else if (*(short *)(ctrl + 0x44) != 0) {
        Select__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardSel();
    } else if (*(short *)(ctrl + 0xA4) != 0) {
        SelectShift__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardSel();
    } else if (*(short *)(ctrl + 0xB0) != 0) {
        SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardSel();
    } else if (*(short *)(ctrl + 0xBC) != 0) {
        SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardSel();
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xF, 0) != 0) {
        D_01E7A800.FEKeyboardSel();
        func_00350CF0(&D_01E899C0);
    }
}
