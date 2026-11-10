// Hand-written; the lifter refused it (buddies menu update; devirt-avoiding vfunc casts, shared prompt call).

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_D_US_F170 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_vt { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01E3D460 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8CBCC { int field_0; unsigned char pad_4[0xC]; };
class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    int GetMenuBack(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_0036F170 {
    unsigned char pad_0[0xCC];
    int field_CC;
    unsigned char pad_D0[0x38];
    char field_108[32];
};
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_vt D_01E8D670;
extern UnkStruct_D_vt D_01E8EAF8;
extern UnkStruct_D_US_F170 D_01E3D390, D_01E7A800, D_01E89800, D_01E899C0, D_01E90240;
extern UnkStruct_D_01E89810 D_01E89810;
extern UnkStruct_D_01E3D460 D_01E3D460;
extern UnkStruct_D_01E8CBCC D_01E8CBCC;
extern "C" int func_003665B0(void *);
extern "C" int GetNumBuddies__22CGtBuddiesPS2DirtySockFv(void *);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void GetSelectedBuddyName__24CB3BuddyDisplayComponentFPc(void *, char *);
extern "C" void func_0036B700(UnkStruct_0036F170 *, int);
extern "C" int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
extern "C" int SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(void *, int, bool);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(void *, int);
extern "C" void IsBuddyIgnored__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, EB3MenuFlowFSMEvents, bool);
// 0x0036F170
extern "C" void func_0036F170(UnkStruct_0036F170 * self)
{
    if (func_003665B0(&D_01E8D670) != 0) {
        bool ignored;
        char name[31];
        GetSelectedBuddyName__24CB3BuddyDisplayComponentFPc(&D_01E8D670, name);
        IsBuddyIgnored__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, name, &ignored);
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 4, 3);
    } else if (D_004F50C0.GetMenuConfirm(0) != 0 && GetNumBuddies__22CGtBuddiesPS2DirtySockFv(&D_01E3D390) > 0) {
        FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        GetSelectedBuddyName__24CB3BuddyDisplayComponentFPc(&D_01E8D670, self->field_108);
        self->field_CC = 3;
        func_0036B700(self, 0);
        ((UnkStruct_D_vt *)&D_01E8D670)->vfunc_C();
        ((UnkStruct_D_vt *)&D_01E8EAF8)->vfunc_C();
    } else if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, (EB3MenuFlowFSMEvents)3, false);
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0x15, 0) != 0) {
        unsigned long s = D_01E89810.field_0 & ~0x300000000UL;
        FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        if (D_01E3D460.field_0 == 6) {
            SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(&D_01E3D390, 1, true);
            s |= 0x100000000UL;
        } else {
            SetPresence__22CGtBuddiesPS2DirtySockF16EGtBuddyPresenceb(&D_01E3D390, 6, true);
            s |= 0x200000000UL;
        }
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, s, 3);
    } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0x16, 0) != 0) {
        self->field_CC = 9;
        Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, true, false);
        SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0x295);
        D_01E8CBCC.field_0 = 16;
    }
}
