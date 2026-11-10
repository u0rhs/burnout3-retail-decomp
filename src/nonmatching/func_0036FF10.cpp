// NONMATCHING: func_0036FF10 -- retail 1031 / ours 1025 instructions, 332 in changed runs
// retail 1031 / ours 1025: logic complete; retail places the then-blocks of case 4/8/0x13 (vfunc_C + page-open inline) and parts of the inline itself out of line at the end; ours keeps them inline
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm + Ghidra draft; every case of the 20-entry jump table, call, argument and store accounted for (call sequence diffed vs retail: same calls, order differs only by out-of-line layout)

// func_0036FF10 -- hand-written (draft2), never attempted before; written from the Ghidra draft + retail asm.
// Unnamed in every table, so a placeholder with C linkage. [L] same page class as
// UpdateRemove__24CB3OnlineBuddiesMenuPageFv / UpdateSearch__24CB3OnlineBuddiesMenuPageFv (it dispatches to both
// on state 0xB / 9-10, and touches the same self fields 0x5C/0xCC/0x124/0x128), likely its Update(); not named here.
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual int vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual int vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4();
    virtual void vfunc_B8(); virtual void vfunc_BC(); virtual void vfunc_C0(); virtual void vfunc_C4();
    virtual void vfunc_C8(); virtual void vfunc_CC(); virtual void vfunc_D0(); virtual void vfunc_D4();
    virtual int vfunc_D8();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Int16 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_Ushort16 { unsigned short field_0; unsigned char pad_2[0xE]; };
extern UnkStruct_D_vt D_01E898E8, D_01E8970C;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_Byte16 D_01E8D67A, D_01E89716, D_01E8EB02, D_01E898F2, D_01E3D4B0, D_01E3D45C;
extern UnkStruct_D_Int16 D_01E3D460, D_01E90424, D_01E3D464, D_01E8E4F0;
extern UnkStruct_D_Ushort16 D_01E8E4E8;
extern UnkStruct_Pad16 D_01E7A800, D_01E3D390, D_01E8D670, D_01E89800, D_01E8EAF8, D_004C8158, D_004C8160,
    D_004C8168, D_004F50C0, D_01E32AE0, D_01E90240, D_01E899C0;
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_0033A600(void *, char *, int, int *);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void func_00350CF0(void *);
extern "C" int Connect__22CGtBuddiesPS2DirtySockFPcPc(void *, char *, void *, void *, void *);
extern "C" int GetNumBuddies__22CGtBuddiesPS2DirtySockFv(void *);
extern "C" int GetBuddyErrorString__17CB3NetworkManagerF18EGtBuddyErrorCodes(void *, int);
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardShift__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardCapsLock__15CB3InputManagerFSc(void *, signed char);
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
extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);
extern "C" void SetFocus__24CB3BuddyDisplayComponentFb(void *, bool);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);
struct UnkStruct_0036FF10;
extern "C" void func_0036F170(UnkStruct_0036FF10 *);
extern "C" void func_0036ECC0(UnkStruct_0036FF10 *);
extern "C" void func_0036E820(UnkStruct_0036FF10 *);
extern "C" void func_0036D620(UnkStruct_0036FF10 *);
extern "C" void func_0036D360(UnkStruct_0036FF10 *);
extern "C" void func_0036D0A0(UnkStruct_0036FF10 *);
extern "C" void func_0036CDE0(UnkStruct_0036FF10 *);
extern "C" void func_0036CB20(UnkStruct_0036FF10 *);
extern "C" void func_0036C860(UnkStruct_0036FF10 *);
extern "C" void UpdateSearch__24CB3OnlineBuddiesMenuPageFv(UnkStruct_0036FF10 *);
extern "C" void UpdateRemove__24CB3OnlineBuddiesMenuPageFv(UnkStruct_0036FF10 *);
struct UnkStruct_0036FF10_68 { unsigned char field_0; unsigned char pad_1[7]; };
struct UnkStruct_0036FF10 {
    unsigned char pad_0[0x5C];
    unsigned short field_5C;   // [G] selection data: current
    unsigned short field_5E;   // [G] count
    unsigned short field_60;   // [G] second selection data (SelectNext/SelectPrev on &field_60)
    unsigned char pad_62[6];
    UnkStruct_0036FF10_68 field_68[0xC];
    unsigned char pad_C8[4];
    int field_CC;              // page state
    unsigned char pad_D0[0x54];
    int field_124;
    int field_128;
};
static inline void func_0036FF10_inl1(UnkStruct_0036FF10 *self)
{
    self->field_CC = 2;
    if (D_01E8D67A.field_0 == 0) {
        Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
    }
    SetFocus__24CB3BuddyDisplayComponentFb(&D_01E8D670, true);
    if (D_01E89716.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8970C)->vfunc_C();
    }
    if (D_01E8EB02.field_0 == 0) {
        Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, &self->field_5C, 272.0f);
    }
    unsigned long v = 0x105 | ((unsigned long)4 << 32);
    if (D_01E3D460.field_0 == 6) {
        v |= (unsigned long)2 << 32;
    } else {
        v |= (unsigned long)1 << 32;
    }
    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v, 3);
}
extern "C" void func_0036FF10(UnkStruct_0036FF10 *self)
{
    if (D_01E90424.field_0 != 5) return;
    if (((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_D8() && ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_70()) {
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
        return;
    }
    if (self->field_CC != 0 && self->field_CC != 1 && D_01E3D4B0.field_0 == 0) {
        char buf[0x10C];
        int len;
        self->field_CC = 0;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 3, 0x50, 1, 0);
        func_0033A600(&D_01E3CD44, buf, 0x100, &len);
        Connect__22CGtBuddiesPS2DirtySockFPcPc(&D_01E3D390, buf, (void *)(len), (void *)(((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_94()), &D_004C8168);
    }
    if (D_01E3D4B0.field_0 != 0) {
        int n = GetNumBuddies__22CGtBuddiesPS2DirtySockFv(&D_01E3D390);
        if (n == 0) n = 1;
        int t = D_01E8E4F0.field_0 + D_01E8E4E8.field_0;
        if (n == t) {
            self->field_5C = t - 1;
            self->field_5E = n;
        } else {
            self->field_5C = t;
            self->field_5E = n;
        }
    }
    switch (self->field_CC) {
    case 0:
        if (D_01E3D4B0.field_0 != 0) {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0036FF10_inl1(self);
        } else if (D_01E3D45C.field_0 != 0) {
            if (func_0032B2C0(&D_01E898E8, 0, 1) == 1) {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            }
        } else {
            self->field_CC = 1;
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, GetBuddyErrorString__17CB3NetworkManagerF18EGtBuddyErrorCodes(&D_01E32AE0, D_01E3D464.field_0), 0, 0);
        }
        break;
    case 1:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
        }
        break;
    case 5: {
        switch (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0)) {
        case 1:
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0x20, 0);
            break;
        }
        break;
    }
    case 6:
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
            SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xE, 0)) {
            SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 0xF, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_00350CF0(&D_01E899C0);
        } else if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            switch (self->field_CC) {
            case 7:
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 0, 0);
                func_0036FF10_inl1(self);
                break;
            case 9:
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 0, 0);
                func_0036FF10_inl1(self);
                break;
            }
            FEKeyboardDel__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
        break;
    case 2:
        func_0036F170(self);
        return;
    case 3:
        if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0) && self->field_68[self->field_60].field_0 == 0) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_0036ECC0(self);
        } else if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            func_0036FF10_inl1(self);
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if ((GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319360(&self->field_60))
                   || (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319330(&self->field_60))) {
        }
        break;
    case 4:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0036FF10_inl1(self);
        }
        break;
    case 7:
        func_0036E820(self);
        return;
    case 8:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0036FF10_inl1(self);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
        break;
    case 9:
    case 10:
        UpdateSearch__24CB3OnlineBuddiesMenuPageFv(self);
        return;
    case 0x13:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0036FF10_inl1(self);
        }
        break;
    case 0xB:
        UpdateRemove__24CB3OnlineBuddiesMenuPageFv(self);
        return;
    case 0xC:
        func_0036D620(self);
        return;
    case 0xD:
        func_0036D360(self);
        return;
    case 0xE:
        func_0036D0A0(self);
        return;
    case 0xF:
        func_0036CDE0(self);
        return;
    case 0x10:
        func_0036CB20(self);
        return;
    case 0x11:
        func_0036C860(self);
        return;
    case 0x12:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_0036FF10_inl1(self);
        }
        break;
    }
}
