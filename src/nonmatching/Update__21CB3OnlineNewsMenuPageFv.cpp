// NONMATCHING: Update__21CB3OnlineNewsMenuPageFv -- retail 500 / ours 502 instructions, 115 in changed runs
// audit1 (2026-11-01): missing arguments: func_00335DB0 frees its 2nd argument (the news buffer field_20, never passed: leak / garbage free) and func_0043FF50 takes field_1C [C] retail 0x379AF0, 0x379B74, 0x37A158 (behaviour_audit) | Before: a169: logic complete (4-state FSM), 500/500 instrs, 114 in changed runs. Left: layout of state-0 Up/Down arms: retail keeps the Up body inline but puts the 'Prepare+zero 256-byte buf+func_0033A6A0+pick buf/D_004C9110' block out of line (after case 3), rejoining at the func_00336150 call; also 'vfunc_C(); lw a1,0x20(s0) in jalr delay slot; beqz a1' (retail tests a1 after the call, ours reloads) and a dead 'addiu s1,sp,buf' stub. goto-form (variant e6) fixes Up arm start but breaks the Down arm (192 changed). vfunc_C takes no argument.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.


// Hand-written (a169): CB3OnlineNewsMenuPage::Update -- lifter refused; written from cfgmap + asm.
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_vt {
    virtual void vfunc_8();
    virtual void vfunc_C(void *);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_Pad16 D_004F50C0, D_01E89800, D_01E3CD44, D_01E7A800, D_01E89544, D_01E90240, D_0051BA44, D_004C90E0, D_004C90E8, D_004C9110;
extern UnkStruct_D_vt D_01E8D4F0;
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int func_0022CBE0(void *, signed char);
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" int func_00379380(void *);
extern "C" int func_00379450(void *);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void func_00335DB0(void *, void *);   // audit1: (heap, block) -- frees block when non-null [C] retail 0x335DB0 reads a1 only
extern "C" void func_00336150(void *, void *, int);
extern "C" int func_0033A6A0(void *, char *, int);
extern "C" int func_0033A730(void *, char *, int);
extern "C" int GetNumLines__20CB3PageTextComponentFv(void *);
extern "C" void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(void *, void *, void *, int, unsigned int);
extern "C" void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsUi(void *, void *, void *, void *, unsigned int);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void ShowSelectionBar__20CB3PageTextComponentFv(void *);
extern "C" void HideSelectionBar__20CB3PageTextComponentFv(void *);
extern "C" void SetItemEnabled__19CB3VSelectComponentFib(void *, int, bool);
extern "C" void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, bool);
extern "C" int func_00335FD0(void *);
extern "C" char *func_00335FC0(void *);
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" unsigned short *func_00335DD0(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const void *, void *, int);
extern "C" void *func_0043FF50(char *);   // audit1 [C] retail 0x37A158 passes field_1C in a0 (forwarded to func_00127BF8)
extern "C" void func_00335F60(void *);
struct UnkStruct_a169 {
    unsigned char pad_0[0x14];
    unsigned char field_14[4];
    unsigned short field_18;
    unsigned short field_1A;
    char *field_1C;
    unsigned short *field_20;
    unsigned char pad_24[4];
    int field_28;
};
extern "C" void Update__21CB3OnlineNewsMenuPageFv(UnkStruct_a169 *self)
{
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_28) {
    case 0:
        if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            ShowSelectionBar__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_28 = 1;
            SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, 0, false);
            SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, 1, false);
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x141, 3);
            return;
        }
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
            return;
        }
        if (func_0022CBE0(&D_004F50C0, 0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 0x24, false);
            break;
        }
        if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319360(&self->field_14)) {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 1, 3);
            unsigned short *p = self->field_20;
            ((UnkStruct_D_vt *)&D_01E8D4F0)->vfunc_C(p);
            if (p) {
                func_00335DB0(&D_01E3CD44, self->field_20);   // audit1 [C] retail 0x379AF0: a1 = field_20
                self->field_20 = 0;
            }
            Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(&D_01E8D4F0, &D_004C90E0, &D_004C90E8, 0x3DF, 0x65);
            int n = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_18 = 0;
            self->field_1A = n;
            char buf[0x100] = {0};
            func_0033A6A0(&D_01E3CD44, buf, 0x100);
            void *s = &D_004C9110;
            if (buf[0] != 0) s = buf;
            func_00336150(&D_01E3CD44, s, 0x708);
            self->field_28 = 2;
            return;
        }
        if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319330(&self->field_14)) {
            unsigned short *p = self->field_20;
            ((UnkStruct_D_vt *)&D_01E8D4F0)->vfunc_C(p);
            if (p) {
                func_00335DB0(&D_01E3CD44, self->field_20);   // audit1 [C] retail 0x379B74: a1 = field_20
                self->field_20 = 0;
            }
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 1, 3);
            Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(&D_01E8D4F0, &D_004C90E0, &D_004C90E8, 0xC0C, 0x65);
            int n = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_18 = 0;
            self->field_1A = n;
            char buf[0x100] = {0};
            func_0033A730(&D_01E3CD44, buf, 0x100);
            void *s = &D_004C9110;
            if (buf[0] != 0) s = buf;
            func_00336150(&D_01E3CD44, s, 0x708);
            self->field_28 = 3;
            return;
        }
        return;
    case 1:
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            HideSelectionBar__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_28 = 0;
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x145, 3);
            SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, 0, true);
            SetItemEnabled__19CB3VSelectComponentFib(&D_01E89544, 1, true);
            return;
        }
        if (func_0022CBE0(&D_004F50C0, 0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 0x24, false);
            break;
        }
        if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00379380(&D_01E8D4F0)) {
            int n = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_18 = self->field_18 - 1;
            self->field_1A = n;
            return;
        }
        if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00379450(&D_01E8D4F0)) {
            int n = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_18 = self->field_18 + 1;
            self->field_1A = n;
            return;
        }
        return;
    case 2: {
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
            func_00335F60(&D_01E3CD44);
            return;
        }
        int n = func_00335FD0(&D_01E3CD44);
        if (n == 0) return;
        unsigned short *s;
        if (n < 0) {
            s = func_00271A00(&D_0051BA44, 0x3E0);
        } else {
            self->field_1C = func_00335FC0(&D_01E3CD44);
            self->field_1C[n - 1] = 0;
            if (self->field_1C[0] != 0) {
                n = (n + 1) * 2;
                self->field_20 = func_00335DD0(&D_01E3CD44, n);
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(self->field_1C, self->field_20, n);
                s = self->field_20;
            } else {
                s = func_00271A00(&D_0051BA44, 0x3E0);
            }
        }
        self->field_28 = 0;
        ((UnkStruct_D_vt *)&D_01E8D4F0)->vfunc_C(0);
        Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsUi(&D_01E8D4F0, &D_004C90E0, &D_004C90E8, s, 0x65);
        int m = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
        self->field_18 = 0;
        self->field_1A = m;
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x145, 3);
        func_00335F60(&D_01E3CD44);
        break;
    }
    case 3: {
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(&D_01E90240, 3, false);
            func_00335F60(&D_01E3CD44);
            return;
        }
        int n = func_00335FD0(&D_01E3CD44);
        if (n == 0) return;
        unsigned short *s;
        if (n < 0) {
            s = func_00271A00(&D_0051BA44, 0x3E0);
        } else {
            self->field_1C = func_00335FC0(&D_01E3CD44);
            self->field_1C[n - 1] = 0;
            if (self->field_1C[0] != 0) {
                void *d = func_0043FF50(self->field_1C);   // audit1 [C] retail 0x37A158
                n = (n + 1) * 2;
                self->field_20 = func_00335DD0(&D_01E3CD44, n);
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(d, self->field_20, n);
                s = self->field_20;
            } else {
                s = func_00271A00(&D_0051BA44, 0x3E0);
            }
        }
        self->field_28 = 0;
        ((UnkStruct_D_vt *)&D_01E8D4F0)->vfunc_C(0);
        Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsUi(&D_01E8D4F0, &D_004C90E0, &D_004C90E8, s, 0x65);
        int m = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
        self->field_18 = 0;
        self->field_1A = m;
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x145, 3);
        func_00335F60(&D_01E3CD44);
        break;
    }
    }
}
