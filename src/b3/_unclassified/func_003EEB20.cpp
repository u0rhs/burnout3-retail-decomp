// Hand-written; the lifter refused it (CB3MyBurnoutProfileSavePage::Update [L]: keyboard-setup inline, one-case switches, sibling func_003EE470 handler; stores in arms, not before the if).

// [L] DNAT: CB3MyBurnoutProfileSavePage::Update() (research/proto/new_names.csv)
struct UnkStruct_D_vt { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_o { unsigned char pad_0[0x10]; };
struct UnkStruct_D_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_bu { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_sb { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_f { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_p { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_3EEB20 {
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char pad_5[3];
    int field_8;
    int field_C;
    unsigned char pad_10[0x14];
    float field_24;
};
extern UnkStruct_D_i D_01E90424, D_01E8CBCC;
extern UnkStruct_D_vt D_01E8F360, D_01E89800;
extern UnkStruct_D_o D_004F50C0, D_01E7A800, D_01E899C0, D_01E90240, D_01ECD520;
extern UnkStruct_D_bu D_01E8F36A, D_01E8980A, D_0051A999;
extern UnkStruct_D_sb D_004F507F;
extern UnkStruct_D_f D_004F509C;
extern UnkStruct_D_p D_0051BF9C;
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardShift__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardCapsLock__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(void *, int);
extern "C" void SetDisplayText__28CB3OnScreenKeyboardComponentFPUsb(void *, void *, bool);
extern "C" void SelectNextLeft__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextRight__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextUp__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextDown__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void Select__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectShift__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectCapsLock__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectSymbols__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" void * func_0013B730(void *);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void StartSaveProfileFlow__24CB3MemCardControllerBaseFv(void *);
extern "C" void StartFormat__24CB3MemCardControllerBaseFv(void *);
extern "C" signed char * func_00420FE0(void *, int);
extern "C" int func_00449150(void *, int, int);
extern "C" void func_003EE470(void *, int);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
static inline void func_003EEB20_inl1(UnkStruct_3EEB20 * self)
{
    self->field_8 = 0xE;
    if (D_01E8F36A.field_0 != 0) ((UnkStruct_D_vt *)&D_01E8F360)->vfunc_C();
    Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 1, 0);
    SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0x293);
    SetDisplayText__28CB3OnScreenKeyboardComponentFPUsb(&D_01E899C0, func_0013B730(D_0051BF9C.field_0), 1);
    D_01E8CBCC.field_0 = 9;
    FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
    if (D_01E8980A.field_0 != 0) ((UnkStruct_D_vt *)&D_01E89800)->vfunc_C();
    func_0031ECD0(&D_01E89800, 0x105, 0xF);
}
// 0x003EEB20
extern "C" void func_003EEB20(UnkStruct_3EEB20 * self)
{
    if (D_01E90424.field_0 != 5) return;
    if (self->field_8 == 0xE) {
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
            if (self->field_8 == 0xE) {
                self->field_8 = 0;
                func_003EE470(self, 0);
                StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
                FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 0, 0);
            }
        }
        return;
    }
    switch (func_00449150(&D_01E8F360, 0, 1)) {
    case 0xC:
        switch (self->field_8) {
        case 9:
            self->field_8 = 0;
            func_003EE470(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 0xC:
            self->field_8 = 0;
            func_003EE470(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 2:
        case 4:
        case 0xD:
            if (D_0051A999.field_0 != 0) {
                self->field_8 = 0x10;
                func_003EE470(self, 0xE);
            } else {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            }
            break;
        case 0x11:
            self->field_8 = 0x10;
            func_003EE470(self, 0xE);
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 0xF:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            break;
        }
        break;
    case 0:
        switch (self->field_8) {
        case 9:
            self->field_8 = 0xA;
            func_003EE470(self, 8);
            StartFormat__24CB3MemCardControllerBaseFv(&D_01ECD520);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 0xC:
            func_003EEB20_inl1(self);
            break;
        case 2:
        case 1:
            break;
        case 0x10:
            func_003EE470(self, 0);
            self->field_8 = 0;
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 0x11:
            D_004F507F.field_0 = 0;
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            break;
        case 0xF:
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            self->field_8 = 0;
            func_003EE470(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        }
        break;
    case 1:
        switch (self->field_8) {
        case 9:
            self->field_8 = 0;
            func_003EE470(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 0xC:
            self->field_8 = 0;
            func_003EE470(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        case 0x10:
            if (D_004F507F.field_0 != 0) {
                self->field_8 = 0x11;
                func_003EE470(self, 0xF);
            } else {
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            }
            break;
        case 0x11:
            self->field_8 = 0x10;
            func_003EE470(self, 0xE);
            break;
        case 0xF:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            break;
        }
        break;
    case 2:
        switch (self->field_8) {
        case 7:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 3, 0);
            break;
        case 0xB:
            func_003EE470(self, 0);
            self->field_8 = 0;
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 8:
            func_003EE470(self, 0);
            self->field_8 = 0;
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 2:
        case 1:
            if (D_0051A999.field_0 != 0) {
                self->field_8 = 0x10;
                func_003EE470(self, 0xE);
            } else {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 3, 0);
            }
            break;
        case 0xD:
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, 0);
            break;
        }
        break;
    case 3:
        switch (self->field_8) {
        case 0xD:
            self->field_8 = 0;
            func_003EE470(self, 0);
            StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
            break;
        }
        break;
    case 9:
        switch (self->field_8) {
        case 4: {
            signed char * r = func_00420FE0(&D_01ECD520, 0);
            signed char t = r[0x49B];
            if (t == 0) {
                self->field_8 = 0xC;
                self->field_C = 0;
                func_003EE470(self, 0xA);
                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            } else {
                self->field_C = 0;
                func_003EEB20_inl1(self);
            }
            break;
        }
        }
        break;
    case 0xA:
        switch (self->field_8) {
        case 4: {
            signed char * r = func_00420FE0(&D_01ECD520, 1);
            signed char t = r[0x49B];
            if (t == 0) {
                self->field_8 = 0xC;
                self->field_C = 1;
                func_003EE470(self, 0xA);
            } else {
                self->field_C = 1;
                func_003EEB20_inl1(self);
            }
            break;
        }
        }
        break;
    case 0xB:
        switch (self->field_8) {
        case 4: {
            signed char * r = func_00420FE0(&D_01ECD520, 2);
            signed char t = r[0x49B];
            if (t == 0) {
                self->field_8 = 0xC;
                self->field_C = 2;
                func_003EE470(self, 0xA);
            } else {
                self->field_C = 2;
                func_003EEB20_inl1(self);
            }
            break;
        }
        }
        break;
    }
    switch (self->field_8) {
    case 5:
        self->field_24 = self->field_24 + D_004F509C.field_0;
        break;
    case 6:
        self->field_24 = self->field_24 + D_004F509C.field_0;
        if (self->field_24 > 1.0f) {
            self->field_8 = 7;
            self->field_24 = 0.0f;
            if (self->field_4 != 0) D_004F507F.field_0 = 1;
            func_003EE470(self, 5);
        }
        break;
    }
}
