// Hand-written; the lifter refused it (a150: ReadMail Update keyboard else-if chain (sibling 00372BA0) + back: switch(field_CC){7,9} same block twice (sibling func_0036CDE0 tail)).

class CB3BuddyDisplayComponent;
class CB3HUDSoundManager;
class CGtBuddiesPS2DirtySock;
struct UnkStruct_0036CDE0;
struct UnkStruct_0036CDE0_2;
struct UnkStruct_0036CDE0_3;
struct UnkStruct_D_004C8158;
struct UnkStruct_D_004C8160;
struct UnkStruct_D_01E3D460;
struct UnkStruct_D_01E8970C;
struct UnkStruct_D_01E89716;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E8D67A;
struct UnkStruct_D_01E8EAF8;
struct UnkStruct_D_01E8EB02;

class CB3HUDSoundManager {
public:
    void FEBack();
    void FESelect();
    void FEKeyboardDel();
    void FEKeyboardMove();
    void FEKeyboardSel();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtBuddiesPS2DirtySock {
public:
    void IsWannaBeMyBuddy(char*, bool*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3BuddyDisplayComponent {
public:
    void SetFocus(bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036CDE0_2 {
    unsigned char field_0;
};

struct UnkStruct_0036CDE0_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E8D67A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89716 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8970C {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EB02 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D460 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EAF8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C8158 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C8160 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0036E820 {
    unsigned char pad_0[0x5C];
    unsigned char field_5C[0x70];
    int field_CC;
    unsigned char pad_D0[0x54];
    int field_124;
    int field_128;
};
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
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_0x10 D_01E899C0;
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

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D67A D_01E8D67A;
extern UnkStruct_D_01E89716 D_01E89716;
extern UnkStruct_D_01E8970C D_01E8970C;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E3D460 D_01E3D460;
extern CB3HUDSoundManager D_01E7A800;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern CB3BuddyDisplayComponent D_01E8D670;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_004C8158 D_004C8158;
extern UnkStruct_D_004C8160 D_004C8160;
extern UnkStruct_D_01E89800 D_01E89800;

extern "C" void _BuddyRejectCallback__24CB3OnlineBuddiesMenuPageFbPv(bool, void*);  // CB3OnlineBuddiesMenuPage::_BuddyRejectCallback(bool,void*), its address taken
extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);  // CB3BuddyDisplayComponent::Prepare(), passed 2 more argument(s) [G]
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);  // CB3PromptsComponent::SetCurrentPrompts(unsigned int,unsigned int)
extern "C" int func_0032B2C0(void *, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int BuddyInviteAccept__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, UnkStruct_0036CDE0 *);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);


// 0x0036E820
extern "C" void func_0036E820(UnkStruct_0036E820 * self)
{
    if (D_004F50C0.GetMenuLeft(0) != 0) {
        SelectNextLeft__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardMove();
    } else if (D_004F50C0.GetMenuRight(0) != 0) {
        SelectNextRight__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardMove();
    } else if (D_004F50C0.GetMenuUp(0) != 0) {
        SelectNextUp__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardMove();
    } else if (D_004F50C0.GetMenuDown(0) != 0) {
        SelectNextDown__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardMove();
    } else if (D_004F50C0.GetMenuConfirm(0) != 0) {
        Select__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardSel();
    } else if (D_004F50C0.GetMenuKeyboardShift(0) != 0) {
        SelectShift__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardSel();
    } else if (D_004F50C0.GetMenuKeyboardCapsLock(0) != 0) {
        SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardSel();
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xE, 0) != 0) {
        SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        D_01E7A800.FEKeyboardSel();
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xF, 0) != 0) {
        D_01E7A800.FEKeyboardSel();
        func_00350CF0(&D_01E899C0);
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        switch (self->field_CC) {
        case 7:
        Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
        self->field_CC = 2;
        if (D_01E8D67A.field_0 == 0) {
            Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
        }
        D_01E8D670.SetFocus(1);
        if (D_01E89716.field_0 != 0) {
            ((UnkStruct_D_01E8970C *)&D_01E8970C)->vfunc_C();
        }
        if (D_01E8EB02.field_0 == 0) {
            Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, self->field_5C, 272.0f);
        }
        {
        unsigned long v = 0x105 | ((unsigned long)4 << 32);
        if (D_01E3D460.field_0 == 6) {
            v |= (unsigned long)2 << 32;
        } else {
            v |= (unsigned long)1 << 32;
        }
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v, 3);
        }
            break;
        case 9:
        Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
        self->field_CC = 2;
        if (D_01E8D67A.field_0 == 0) {
            Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
        }
        D_01E8D670.SetFocus(1);
        if (D_01E89716.field_0 != 0) {
            ((UnkStruct_D_01E8970C *)&D_01E8970C)->vfunc_C();
        }
        if (D_01E8EB02.field_0 == 0) {
            Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, self->field_5C, 272.0f);
        }
        {
        unsigned long v = 0x105 | ((unsigned long)4 << 32);
        if (D_01E3D460.field_0 == 6) {
            v |= (unsigned long)2 << 32;
        } else {
            v |= (unsigned long)1 << 32;
        }
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v, 3);
        }
            break;
        }
        D_01E7A800.FEKeyboardDel();
    }
}
