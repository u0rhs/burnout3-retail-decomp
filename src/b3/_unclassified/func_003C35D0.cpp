// Hand-written; the lifter refused it (CB3CrashNavPage::Update [L]: page FSM; case 1/2-4 exits return, (x!=0)^1 loop test, wrap via n=i+1 if/else, goto out for the last 0x49 test).

// func_003C35D0 -- hand-written from retail (lifter refused). [L] DNAT: CB3CrashNavPage::Update()
// (research/proto/new_names.csv, medium). Sibling: func_003C4150 ([L] CB3CrashNavPage::Prepare), func_003C43E0.
// Exits: case 0's inner switch breaks to a shared stub; cases 1 and 2/4 return straight to the epilogue.
// States (field_4): 0 = region select (globe), 1 = sat-nav map, 2/4 = zoomed map.

struct UnkStruct_003C35D0_e { int field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[0x2]; };
struct UnkStruct_003C35D0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char pad_13[0x1];
    short field_14;
    short field_16;
    UnkStruct_003C35D0_e field_18[3];
};
struct UnkStruct_003C35D0_st { unsigned long field_0; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_SByte16 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Int16 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_Ptr16 { UnkStruct_003C35D0_st * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E2ED4 { unsigned char field_0; };
struct UnkStruct_D_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_Int16 D_01E90424, D_0051BF9C, D_01E8E834, D_01E8E838;
extern UnkStruct_D_Byte16 D_01E8954E;
extern UnkStruct_D_SByte16 D_01E893D4;
extern UnkStruct_D_Ptr16 D_01EA2974;
extern UnkStruct_D_004E2ED4 D_004E2ED4;
extern UnkStruct_D_Pad16 D_01E89544, D_01E88A80, D_01E8E7E0, D_01E88AF0;
extern UnkStruct_D_Pad16 D_004F50C0, D_01E7A800, D_01E7A888, D_01E89800, D_01E90240, D_0051A870, D_0051A6A8;

extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void func_003F8C00(void *, int);
extern "C" void Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, bool, float, float, float, float, const void *, void *, int, float);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void func_003C43E0(UnkStruct_003C35D0 *, int, int);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int func_0022CBE0(void *, signed char);
extern "C" int func_003F5800(int, int);
extern "C" void Prepare__18CB3SatNavComponentF12ESatMapLevel14EB3TrackRegion21ESatMapEnterDirection(void *, int, int, int);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" void func_00285220(void *);
extern "C" void func_00285260(void *);
extern "C" void func_00284FB0(void *);
extern "C" void func_00284FF0(void *);
extern "C" void func_003B6200(void *);
extern "C" void func_003B6210(void *, int);
extern "C" int func_003B78D0(void *, int);
extern "C" void ForceLead__19CB3VSelectComponentFbb(void *, bool, bool);
extern "C" int func_003A7000(void *);
extern "C" int func_003A6FD0(void *);
extern "C" void func_00324EB0(void *);
extern "C" void ZoomIn__18CB3SatNavComponentFv(void *);
extern "C" int func_003A72E0(void *);
extern "C" int func_003A70D0(void *);
extern "C" int func_003A86C0(void *);
extern "C" int func_003A8570(void *);
extern "C" void func_003A87F0(void *);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);

static inline unsigned long func_003C35D0_inl1(UnkStruct_003C35D0_st * s)
{
    return s != 0 ? s->field_0 : 0x6D6123044330FCCF;
}


// 0x003C35D0
extern "C" void func_003C35D0(UnkStruct_003C35D0 * self)
{
    int t0 = D_0051BF9C.field_0;
    if (D_01E90424.field_0 != 5) return;
    self->field_8 = D_01E8E838.field_0;
    switch (self->field_4) {
    case 0:
        if (D_004E2ED4.field_0 != 0 && Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0) != 0) {
            D_004E2ED4.field_0 = 0;
        }
        func_003F8C00(&D_01E7A888, 1);
        switch (D_01E8E834.field_0) {
        case 1:
            if (D_01E8954E.field_0 != 0) {
                ((UnkStruct_D_vt *)&D_01E89544)->vfunc_C();
            }
            Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, true, 440.0f, 150.0f, 30.0f, 40.0f, &self->field_14, self->field_18, 0, 136.0f);
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000105, 0xF);
            self->field_11 = 1;
            break;
        case 2:
            if (self->field_12 != 0) {
                func_003C43E0(self, 0, 1);
            }
            if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
                FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
                return;
            } else if (func_0022CBE0(&D_004F50C0, 0)) {
                FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
                StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 0x49, false);
                return;
            } else if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
                func_00285220(&D_01E7A800);
                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
                func_003B6200(&D_01E8E7E0);
                ForceLead__19CB3VSelectComponentFbb(&D_01E89544, true, true);
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000105, 0);
                ((UnkStruct_D_vt *)&D_01E88A80)->vfunc_C();
                D_004E2ED4.field_0 = 1;
                func_003C43E0(self, 1, 1);
                return;
            } else if (GetMenuLeft__15CB3InputManagerFSc(&D_004F50C0, 0) || GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0)) {
                int i = self->field_8;
                do {
                    i--;
                    if (i < 0) i = 2;
                } while ((func_003F5800(i, t0) != 0) ^ 1);
                if (i != self->field_8) {
                    self->field_8 = i;
                    self->field_14 = self->field_8;
                    func_00285260(&D_01E7A800);
                    func_003B6210(&D_01E8E7E0, self->field_8);
                }
                return;
            } else if (GetMenuRight__15CB3InputManagerFSc(&D_004F50C0, 0) || GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0)) {
                int i = self->field_8;
                do {
                    int n = i + 1;
                    if (n < 3) i = n; else i = 0;
                } while ((func_003F5800(i, t0) != 0) ^ 1);
                if (i != self->field_8) {
                    self->field_8 = i;
                    self->field_14 = self->field_8;
                    func_00285260(&D_01E7A800);
                    func_003B6210(&D_01E8E7E0, self->field_8);
                }
                return;
            }
            break;
        case 6:
            if (self->field_10 == 0) {
                Prepare__18CB3SatNavComponentF12ESatMapLevel14EB3TrackRegion21ESatMapEnterDirection(&D_01E88AF0, 0, self->field_8, 0);
                self->field_10 = 1;
            }
            break;
        case 7:
            self->field_4 = 1;
            func_003C43E0(self, 1, 1);
            ((UnkStruct_D_vt *)&D_01E8E7E0)->vfunc_C();
            break;
        }
        break;
    case 1: {
        if (D_004E2ED4.field_0 != 0 && Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 4) != 0) {
            D_004E2ED4.field_0 = 0;
        }
        func_003F8C00(&D_01E7A888, 2);
        int s = D_01E893D4.field_0;
        if (s == 2 && self->field_C != 2 && self->field_C != 1) {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000105, 0xC);
        }
        self->field_C = s;
        if (s != 2) return;
        if (self->field_12 != 0) {
            func_003C43E0(self, 0, 1);
        }
        if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            UnkStruct_003C35D0_st * st = D_01EA2974.field_0;
            if ((func_003C35D0_inl1(st) == 0x94413FC15F5A6380 || func_003C35D0_inl1(st) == 0x9441407F0FDC9797) && !func_003A7000(&D_01E88AF0)) {
                func_00324EB0(&D_0051A870);
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0, 0);
                return;
            }
            ZoomIn__18CB3SatNavComponentFv(&D_01E88AF0);
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000105, 0);
            if (func_003A7000(&D_01E88AF0)) {
                self->field_4 = 2;
                func_003C43E0(self, 1, 1);
            } else {
                self->field_4 = 4;
                func_003C43E0(self, 1, 1);
            }
        } else if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (self->field_10 != 0) {
                ((UnkStruct_D_vt *)&D_01E88AF0)->vfunc_C();
            }
            if (self->field_11 == 0) {
                if (D_01E8954E.field_0 != 0) {
                    ((UnkStruct_D_vt *)&D_01E89544)->vfunc_C();
                }
                Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, true, 440.0f, 150.0f, 30.0f, 40.0f, &self->field_14, self->field_18, 0, 136.0f);
                self->field_11 = 1;
            } else {
                ForceLead__19CB3VSelectComponentFbb(&D_01E89544, false, true);
            }
            self->field_10 = 0;
            func_003B78D0(&D_01E8E7E0, self->field_8);
            self->field_4 = 0;
            func_003C43E0(self, 1, 1);
            ((UnkStruct_D_vt *)&D_01E88A80)->vfunc_C();
            func_00130C70(&D_0051A6A8);
            func_00130D00(&D_0051A6A8);
            D_004E2ED4.field_0 = 1;
            func_00284FB0(&D_01E7A800);
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            return;
        } else if (GetMenuLeft__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (func_003A72E0(&D_01E88AF0)) {
                func_00284FF0(&D_01E7A800);
            }
            return;
        } else if (GetMenuRight__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (func_003A70D0(&D_01E88AF0)) {
                func_00284FF0(&D_01E7A800);
            }
            return;
        } else if (func_0022CBE0(&D_004F50C0, 0)) {
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 0x49, false);
            return;
        }
        return;
    }
    case 2:
    case 4: {
        int s = D_01E893D4.field_0;
        if (s == 3 && self->field_C != 3) {
            if (func_003A6FD0(&D_01E88AF0)) {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000101, 3);
            } else {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000105, 3);
            }
        }
        self->field_C = s;
        func_003F8C00(&D_01E7A888, 3);
        if (D_01E893D4.field_0 != 3) return;
        if (self->field_12 != 0) {
            func_003C43E0(self, 0, 1);
        }
        if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0) && !func_003A6FD0(&D_01E88AF0)) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0, 0);
            return;
        }
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_003A87F0(&D_01E88AF0);
            self->field_4 = 1;
            func_003C43E0(self, 1, 1);
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000105, 0);
            return;
        } else if ((GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0) && func_003A86C0(&D_01E88AF0))
                   || (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0) && func_003A8570(&D_01E88AF0))) {
            func_003C43E0(self, 0, 0);
            if (func_003A6FD0(&D_01E88AF0)) {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000101, 3);
            } else {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x800000105, 3);
            }
            return;
        }
        if (!func_0022CBE0(&D_004F50C0, 0)) goto out;  // [G] goto: retail's direct beqz to the epilogue (a169 page-FSM exits)
        FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
        StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 0x49, false);
        return;
    }
    }
out:
    return;
}
