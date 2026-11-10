// NONMATCHING: func_0045D0B0 -- retail 2400 / ours 2280 instructions, 1167 in changed runs
// draft1: 2280/2400, 1167 in changed runs, frame 0x160 vs 0x1A0; call sequence identical to retail (243 calls incl. 19 jalr). Fixed on the way: state 1 placed last, lobby-status switch (case 0 return, case 2, case 1), E6 branches swapped, case 8 break, globals > 8 bytes (not $gp), unsigned selection index, 64-bit prompt mask arg. Left: the four inlined day-number->date conversions (retail keeps them in memory: lq/sq struct copies, field pointers in s-regs; ours registerises), scheduling
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the Ghidra draft plus the retail asm for the jump-table option cases and the date conversions; every branch, call (order identical to retail) and store accounted for

// draft1: func_0045D0B0 (0x45D0B0), written from the Ghidra draft and the retail asm (the left/right option jump table
// jtbl_004D3930, which Ghidra could not recover, and the inlined date conversions from the asm).
// [G] an online account-creation page update (state field_DC: 0 the options list, 1 the on-screen keyboard for the
// e-mail, 2 waiting on the lobby, 3 a message box, 4/5 the scrolling terms text, 6 the first options list); placeholder
// name, Area unknown. Types [G] (instruction widths). Profile = {month, day, year, strings, e-mail at 0x8C, codes at
// 0xCC/0xCF, flags at 0xD2..0xD5} [G].
// [L] func_0045C890 = a date constructor (day, month, year) -> day number in field_0 (src/b3/_unclassified/func_0045C890.cpp);
// inl2 = its inverse (day number -> {days, month, day, year}), inlined four times in retail (0x45D35C..0x45D7xx).

struct UnkStruct_0045D0B0_date { int field_0; int field_4; int field_8; int field_C; };
struct UnkStruct_0045D0B0_ymd { int field_0; int field_4; int field_8; int field_C; };   // days, month, day, year
struct UnkStruct_0045D0B0_now { unsigned short field_0; unsigned short field_2; unsigned short field_4; };
struct UnkStruct_0045D0B0_prof {
    unsigned int field_0;       // [G] month 1..12
    unsigned int field_4;       // [G] day
    unsigned int field_8;       // [G] year
    char field_C[0x20];
    char field_2C[0x20];
    char field_4C[0x40];
    char field_8C[0x40];        // [G] e-mail address (checked for '.' and '@')
    char field_CC[3];
    char field_CF[3];
    unsigned char field_D2;
    unsigned char field_D3;
    unsigned char field_D4;
    unsigned char field_D5;
};
struct UnkStruct_0045D0B0_req {     // [G] the request handed to func_0033AE60
    char * field_0; char * field_4; char * field_8; char * field_C;
    char * field_10; char * field_14; char * field_18; char * field_1C;
    unsigned char field_20; unsigned char field_21;
};
struct UnkStruct_0045D0B0_ent {     // [L] CB3VOptionsSelectComponentEntryData (FUN_003be5a0's second argument)
    int field_0; int field_4; void * field_8;
    unsigned char field_C; unsigned char field_D; unsigned char field_E; unsigned char pad_F;
    int field_10;
};
struct UnkStruct_0045D0B0_sel { unsigned short field_0; unsigned short field_2; };   // [L] CB3MenuComponentSelectionData
struct UnkStruct_0045D0B0 {
    unsigned char pad_0[0x4];
    UnkStruct_0045D0B0_ent field_4[9];
    UnkStruct_0045D0B0_sel field_B8;
    UnkStruct_0045D0B0_prof * field_BC;
    unsigned short field_C0;    // [G] day min
    unsigned short field_C2;    // [G] days in the month
    unsigned short field_C4;    // [G] year min
    unsigned short field_C6;    // [G] year max
    UnkStruct_0045D0B0_sel field_C8;
    char * field_CC;
    int field_D0;
    unsigned short * field_D4;
    unsigned char pad_D8[0x4];
    signed char field_DC;
    signed char field_DD;
    unsigned char pad_DE[0x6];
    signed char field_E4;
    signed char field_E5;
    unsigned char field_E6;
};

struct UnkStruct_0045D0B0_vt { unsigned char pad_0[0xC]; void (*vfunc_C)(void *); unsigned char pad_10[0x48]; int (*vfunc_58)(void *); };
struct UnkStruct_0045D0B0_obj { UnkStruct_0045D0B0_vt * vptr; unsigned char pad_4[0xC]; };   // [G] size: only > 8 so it is not small data
struct UnkStruct_0045D0B0_flag { UnkStruct_0045D0B0_vt * vptr; unsigned char pad_4[0x6]; unsigned char field_A; };
struct UnkStruct_0045D0B0_kbd { UnkStruct_0045D0B0_vt * vptr; unsigned char pad_4[0x18]; unsigned char field_1C; };
struct UnkStruct_0045D0B0_pr { UnkStruct_0045D0B0_vt * vptr; unsigned char pad_4[0xC]; unsigned long field_10; };

extern int D_01E90424[];                      // [G] unsized: retail reaches it through lui/lw, not $gp
extern UnkStruct_0045D0B0_obj D_01E3CD44;      // [G] the online/lobby object
extern UnkStruct_0045D0B0_obj D_01E8961C;      // [G] the options-select component
extern UnkStruct_0045D0B0_pr D_01E89800;       // [G] the prompts component
extern UnkStruct_0045D0B0_obj D_01E898E8;      // [G] a message box component
extern UnkStruct_0045D0B0_kbd D_01E899C0;      // [G] the on-screen keyboard
extern UnkStruct_0045D0B0_flag D_01E89544;
extern UnkStruct_0045D0B0_flag D_01E8D4B0;     // [G] a text component
extern UnkStruct_0045D0B0_obj D_01E8D4F0;      // [G] the page text component
extern UnkStruct_0045D0B0_obj D_01E8EAF8;      // [G] the scroll bar component
extern unsigned char D_01E7A800[];             // [G] the HUD sound manager
extern unsigned char D_01E90240[];             // [G] the menu page manager
extern unsigned char D_01E32AE0[];             // [G] the network manager
extern unsigned char D_004F50C0[];             // [G] the input manager
extern unsigned char D_0051BA44[];             // [L] CB3Strings (func_00271A00's this)
extern unsigned int D_004D383C[];              // [G] days per month, 1-based
extern char D_004D37C0[];                      // [G] 3-character codes, 11 of them
extern char D_004D3820[];                      // [G] 3-character codes, 10 of them
extern char D_004D3870[], D_004D38A0[], D_004D3790[], D_004D37F0[];
extern float D_004D3760[2], D_004D3768[2], D_004D3770[2], D_004D3778[2], D_004D3780[2];
extern float D_004D38A8[2], D_004D38B0[2], D_004D38B8[2], D_004D38C0[2];
extern float D_004D38C8;
extern const char D_004D3908[], D_004D3918[], D_004D3920[];

extern "C" {
int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
int GetMenuKeyboardShift__15CB3InputManagerFSc(void *, signed char);
int GetMenuKeyboardCapsLock__15CB3InputManagerFSc(void *, signed char);
int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
void FESelect__18CB3HUDSoundManagerFv(void *);
void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
void FEKeyboardDel__18CB3HUDSoundManagerFv(void *);
void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
void StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(void *, int, int);
int GetLobbyStatus__17CB3NetworkManagerFv(void *);
int GetErrorString__17CB3NetworkManagerFi(void *, int);
void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);   // [G] a1 64-bit: retail passes the ld value untruncated
void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(void *, const float *, const float *, int, unsigned int);
void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsUi(void *, const float *, const float *, void *, unsigned int);
unsigned short GetNumLines__20CB3PageTextComponentFv(void *);
void ShowSelectionBar__20CB3PageTextComponentFv(void *);
void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, const float *, const float *, float, const void *);
void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, unsigned int);
void Show__28CB3OnScreenKeyboardComponentFbb(void *, int, int);
void SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(void *, int);
void SetDisplayText__28CB3OnScreenKeyboardComponentFPcb(void *, char *, int);
void Select__28CB3OnScreenKeyboardComponentFv(void *);
void SelectNextUp__28CB3OnScreenKeyboardComponentFv(void *);
void SelectNextDown__28CB3OnScreenKeyboardComponentFv(void *);
void SelectNextLeft__28CB3OnScreenKeyboardComponentFv(void *);
void SelectNextRight__28CB3OnScreenKeyboardComponentFv(void *);
void SelectShift__28CB3OnScreenKeyboardComponentFv(void *);
void SelectCapsLock__28CB3OnScreenKeyboardComponentFv(void *);
void SelectSymbols__28CB3OnScreenKeyboardComponentFv(void *);
int func_00271A00(void *, int);                    // [L] CB3Strings::GetString(int) (nahelam_check.csv candidate)
int func_00319330(void *);                         // [L] CB3MenuComponentSelectionData::SelectNext() (low)
int func_00319360(void *);                         // [L] CB3MenuComponentSelectionData::SelectPrev() (agree)
int func_0032B2C0(void *, int, int);
void func_0032D080(void *, int, int, int, int);   // [L] CB3MessageBoxComponent::Prepare (rejected there)
int func_00335DD0(void *, int);
void func_00335F60(void *);
char * func_00335FC0(void *);
int func_00335FD0(void *);
void func_0033AE60(void *, UnkStruct_0045D0B0_req *);
void func_00350CF0(void *);
void func_00351F00(void *, const float *, const float *, const float *, const float *, const float *, int, int, float, float);
int func_00379380(void *);
int func_00379450(void *);
void func_003BC360(void *, int, unsigned int);    // [L] CB3HOptionsSelectComponent::SetEnabledState(int, uint)
void func_003BC540(void *, int, int);             // [L] CB3HOptionsSelectComponent::SetYesNoOption(int, bool)
int func_003BE2A0(void *, void *, void *, float);
int func_003BE5A0(void *, void *, void *);       // [L] CB3VOptionsSelectComponent::Prepare (rejected there)
void func_00436460(UnkStruct_0045D0B0_now *);
int func_0043FF50(char *);
void func_0045C890(UnkStruct_0045D0B0_date *, int, int, int);
void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, unsigned short *, int);
int snprintf(char *, unsigned int, const char *, ...);
char * strcpy(char *, const char *);
char * strncpy(char *, const char *, unsigned int);
char * strchr(const char *, int);
unsigned int strlen(const char *);
}

static inline void func_0045D0B0_vc(void * o) { ((UnkStruct_0045D0B0_obj *)o)->vptr->vfunc_C(o); }

// [L] leap year (the same inline as func_0045C890's)
static inline bool func_0045D0B0_inl1(int y)
{
    bool leap;
    if (y % 400 == 0) {
        leap = true;
    } else if (y % 100 == 0) {
        leap = false;
    } else {
        if (y % 4 == 0) {
            leap = true;
        } else {
            leap = false;
        }
    }
    return leap;
}

// day number -> {days, month, day, year}; retail passes the month as func_0045C890's FIRST (day) argument in the month search
static inline void func_0045D0B0_inl2(UnkStruct_0045D0B0_ymd * r, int d)
{
    UnkStruct_0045D0B0_date t;
    r->field_0 = d;
    r->field_C = d / 366;
    func_0045C890(&t, 1, 1, r->field_C);
    while (t.field_0 <= d) {
        r->field_C = r->field_C + 1;
        func_0045C890(&t, 1, 1, r->field_C);
    }
    r->field_C = r->field_C - 1;
    func_0045C890(&t, 1, 1, r->field_C);
    r->field_4 = 1;
    while (t.field_0 <= d) {
        r->field_4 = r->field_4 + 1;
        func_0045C890(&t, r->field_4, 1, r->field_C);
    }
    r->field_4 = r->field_4 - 1;
    func_0045C890(&t, r->field_4, 1, r->field_C);
    r->field_8 = d - t.field_0 + 1;
}

// the day clamp after a month / day / year change (three copies in retail)
static inline void func_0045D0B0_inl3(UnkStruct_0045D0B0 * self)
{
    UnkStruct_0045D0B0_prof * p = self->field_BC;
    if (func_0045D0B0_inl1(p->field_8) && p->field_0 - 1 == 1) {
        if (p->field_4 < self->field_C0)
            p->field_4 = self->field_C2 + 1;
        else if (self->field_C2 + 1 < p->field_4)
            p->field_4 = self->field_C0;
    } else {
        if (p->field_4 < self->field_C0)
            p->field_4 = self->field_C2;
        else if (D_004D383C[p->field_0] < p->field_4)
            p->field_4 = self->field_C0;
    }
}

static inline void func_0045D0B0_inl4(UnkStruct_0045D0B0 * self)
{
    func_003BE5A0(&D_01E8961C, &self->field_B8, self->field_4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_BC->field_0 - 1);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_BC->field_4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_BC->field_8);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, self->field_BC->field_D4 == 0);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 4, self->field_E4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 5, self->field_E5);
    func_003BC540(&D_01E8961C, 7, self->field_BC->field_D5);
}

static inline void func_0045D0B0_ent(UnkStruct_0045D0B0_ent * e, int s, void * p, unsigned char c, unsigned char d, unsigned char f)
{
    e->field_0 = s;
    e->field_8 = p;
    e->field_C = c;
    e->field_D = d;
    e->field_E = f;
    e->field_10 = 0;
    e->field_4 = 0;
}

// the nine-entry details list (states 3 and 6)
static inline void func_0045D0B0_inl5(UnkStruct_0045D0B0 * self)
{
    func_0045D0B0_ent(&self->field_4[0], func_00271A00(D_0051BA44, 0x3F0), D_004D3870, 0xC, 4, 0);
    func_0045D0B0_ent(&self->field_4[1], func_00271A00(D_0051BA44, 0x3F1), &self->field_C0, (char)self->field_C2 - (char)self->field_C0, 5, 0);
    func_0045D0B0_ent(&self->field_4[2], func_00271A00(D_0051BA44, 0x3F2), &self->field_C4, (char)self->field_C6 - (char)self->field_C4, 5, 0);
    func_0045D0B0_ent(&self->field_4[3], func_00271A00(D_0051BA44, 0x3F3), D_004D38A0, 2, 4, 0);
    func_0045D0B0_ent(&self->field_4[4], func_00271A00(D_0051BA44, 0x3F6), D_004D3790, 0xB, 4, 0);
    func_0045D0B0_ent(&self->field_4[5], func_00271A00(D_0051BA44, 0x402), D_004D37F0, 0xA, 4, 0);
    func_0045D0B0_ent(&self->field_4[6], func_00271A00(D_0051BA44, 0x3DE), 0, 0, 0, 0);
    func_0045D0B0_ent(&self->field_4[7], func_00271A00(D_0051BA44, 0x40D), 0, 0, 6, 0);
    unsigned char optin = self->field_BC->field_D5;
    func_0045D0B0_ent(&self->field_4[8], func_00271A00(D_0051BA44, 0x40E), 0, 0, 0, optin == 0);
    self->field_B8.field_0 = 0;
    self->field_B8.field_2 = 9;
}

// the two-entry under-age / message list
static inline void func_0045D0B0_inl6(UnkStruct_0045D0B0 * self)
{
    func_00351F00(&D_01E8D4B0, D_004D3760, D_004D3768, D_004D3770, D_004D3778, D_004D3780, 0xBC, 3, 28.0f, D_004D3780[0]);
    int t = self->field_D0;
    func_0045D0B0_ent(&self->field_4[0], func_00271A00(D_0051BA44, 0x3E6), (void *)t, 1, 2, 0);
    func_0045D0B0_ent(&self->field_4[1], func_00271A00(D_0051BA44, 0x40E), 0, 0, 0, 1);
    self->field_B8.field_0 = 0;
    self->field_B8.field_2 = 2;
    func_003BE2A0(&D_01E8961C, &self->field_B8, self->field_4, 336.0f);
}

// the account request (state 0 option 8 / state 6 option 1); retail: two copies, the first without the e-mail
static inline void func_0045D0B0_inl7(UnkStruct_0045D0B0 * self, char * email)
{
    char date[12];
    char sex[4];
    UnkStruct_0045D0B0_req q;
    UnkStruct_0045D0B0_prof * p = self->field_BC;
    snprintf(date, 9, D_004D3908, p->field_8, p->field_0, p->field_4);
    if (self->field_BC->field_D4 == 0)
        strcpy(sex, D_004D3920);
    else
        strcpy(sex, D_004D3918);
    q.field_0 = self->field_BC->field_C;
    q.field_4 = self->field_BC->field_2C;
    q.field_8 = self->field_BC->field_4C;
    q.field_C = email;
    q.field_10 = date;
    q.field_14 = sex;
    q.field_18 = self->field_BC->field_CC;
    q.field_1C = self->field_BC->field_CF;
    q.field_20 = self->field_BC->field_D2;
    q.field_21 = self->field_BC->field_D3;
    func_0033AE60(&D_01E3CD44, &q);
    self->field_DC = 2;
    self->field_DD = self->field_DC;
    func_0032D080(&D_01E898E8, 0, 0xBE, 0xF, 0);
    func_0045D0B0_vc(&D_01E89800);
}

static inline void func_0045D0B0_inl8(UnkStruct_0045D0B0 * self, const unsigned short * text)
{
    Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsUi(&D_01E8D4F0, D_004D38A8, D_004D38B0, (void *)((int)text), 0x65);
}

// 0x0045D0B0
extern "C" void func_0045D0B0(UnkStruct_0045D0B0 * self)
{
    if (D_01E90424[0] != 5)
        return;
    if (self->field_E6 == 0) {
        int n = func_00335FD0(&D_01E3CD44);
        if (n < 0) {
            func_00271A00(D_0051BA44, 0x3E0);
            self->field_E6 = 1;
        } else if (n > 0) {
            self->field_CC = func_00335FC0(&D_01E3CD44);
            self->field_CC[n - 1] = 0;
            if (*self->field_CC == 0) {
                func_00271A00(D_0051BA44, 0x3E0);
                self->field_E6 = 1;
            } else {
                int u = func_0043FF50(self->field_CC);
                self->field_D4 = (unsigned short *)func_00335DD0(&D_01E3CD44, (n + 1) * 2);
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(u, self->field_D4, n + 1);
                self->field_E6 = 1;
            }
        }
        if (n != 0)
            func_00335F60(&D_01E3CD44);
    }

    switch (self->field_DC) {
    case 0:
        if ((GetMenuUp__15CB3InputManagerFSc(D_004F50C0, 0) && func_00319360(&self->field_B8)) ||
            (GetMenuDown__15CB3InputManagerFSc(D_004F50C0, 0) && func_00319330(&self->field_B8))) {
            FEVerticalMove__18CB3HUDSoundManagerFv(D_01E7A800, 1);
            if ((self->field_B8.field_0 == 8 && self->field_4[8].field_E == 0) || self->field_B8.field_0 == 6)
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89800.field_10 | 4, 3);
            else
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89800.field_10 & ~4, 3);
            break;
        }
        if (GetMenuConfirm__15CB3InputManagerFSc(D_004F50C0, 0)) {
            FESelect__18CB3HUDSoundManagerFv(D_01E7A800);
            switch ((unsigned short)self->field_B8.field_0) {
            case 6:
                func_0045D0B0_vc(&D_01E8961C);
                if (self->field_E6 != 0) {
                    self->field_DC = 5;
                    if (self->field_CC == 0 || *self->field_CC == 0)
                        func_0045D0B0_inl8(self, (const unsigned short *)func_00271A00(D_0051BA44, 0x3E0));
                    else
                        func_0045D0B0_inl8(self, self->field_D4);
                    unsigned short nl = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
                    self->field_C8.field_0 = 0;
                    self->field_C8.field_2 = nl;
                    Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, D_004D38B8, D_004D38C0, D_004D38C8, &self->field_C8);
                    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x109, 3);
                    ShowSelectionBar__20CB3PageTextComponentFv(&D_01E8D4F0);
                } else {
                    self->field_DC = 4;
                    Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(&D_01E8D4F0, D_004D38A8, D_004D38B0, 0xC0C, 0x65);
                    unsigned short nl = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
                    self->field_C8.field_0 = 0;
                    self->field_C8.field_2 = nl;
                    Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, D_004D38B8, D_004D38C0, D_004D38C8, &self->field_C8);
                    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 1, 3);
                }
                break;
            case 8: {
                if (self->field_4[8].field_E != 0)
                    break;
                UnkStruct_0045D0B0_now now;
                func_00436460(&now);
                UnkStruct_0045D0B0_date epoch, today, birth;
                func_0045C890(&epoch, 0, 0, 0);
                func_0045C890(&today, now.field_4, now.field_2, now.field_0);
                UnkStruct_0045D0B0_prof * p = self->field_BC;
                func_0045C890(&birth, p->field_4, p->field_0, p->field_8);
                UnkStruct_0045D0B0_ymd a, b;
                func_0045D0B0_inl2(&a, today.field_0 - birth.field_0);
                UnkStruct_0045D0B0_ymd ta = a;
                func_0045D0B0_inl2(&b, ta.field_0);
                func_0045D0B0_inl2(&b, b.field_0 + epoch.field_0);
                UnkStruct_0045D0B0_ymd tb = b;
                func_0045D0B0_inl2(&b, tb.field_0);
                if (b.field_C < 18) {
                    func_0045D0B0_vc(&D_01E8961C);
                    func_0045D0B0_inl6(self);
                    self->field_DC = 6;
                    self->field_DD = 6;
                } else {
                    func_0045D0B0_inl7(self, 0);
                    self->field_DD = 0;
                }
                break;
            }
            case 0: case 1: case 2: case 3: case 4: case 5: case 7:
                break;
            }
            break;
        }
        if (GetMenuBack__15CB3InputManagerFSc(D_004F50C0, 0)) {
            StartLeadOutFore__18CB3MenuPageManagerF20EB3MenuFlowFSMEventsb(D_01E90240, 3, 0);
            break;
        }
        if (!GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0) && !GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0))
            return;
        switch ((unsigned short)self->field_B8.field_0) {
        case 0:
            if (GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0))
                self->field_BC->field_0--;
            else if (GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0))
                self->field_BC->field_0++;
            if (self->field_BC->field_0 == 0)
                self->field_BC->field_0 = 12;
            if (self->field_BC->field_0 >= 13)
                self->field_BC->field_0 = 1;
            self->field_C2 = D_004D383C[self->field_BC->field_0];
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_BC->field_0 - 1);
            func_0045D0B0_inl3(self);
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_BC->field_4);
            break;
        case 1:
            if (GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0))
                self->field_BC->field_4--;
            else if (GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0))
                self->field_BC->field_4++;
            func_0045D0B0_inl3(self);
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_BC->field_4);
            break;
        case 2:
            if (GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0)) {
                self->field_BC->field_8--;
                if (self->field_BC->field_8 < self->field_C4)
                    self->field_BC->field_8 = self->field_C6;
            } else if (GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0)) {
                self->field_BC->field_8++;
                if (self->field_C6 < self->field_BC->field_8)
                    self->field_BC->field_8 = self->field_C4;
            }
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_BC->field_8);
            func_0045D0B0_inl3(self);
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_BC->field_4);
            break;
        case 3:
            if (GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0) || GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0))
                self->field_BC->field_D4 = !self->field_BC->field_D4;
            if (self->field_BC->field_D4)
                SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, 0);
            else
                SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, 1);
            break;
        case 4:
            if (GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0)) {
                self->field_E4--;
                if (self->field_E4 < 0)
                    self->field_E4 = 10;
            } else if (GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0)) {
                self->field_E4 = (self->field_E4 + 1) % 11;
            }
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 4, self->field_E4);
            strncpy(self->field_BC->field_CC, D_004D37C0 + self->field_E4 * 3, 3);
            break;
        case 5:
            if (GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0)) {
                self->field_E5--;
                if (self->field_E5 < 0)
                    self->field_E5 = 9;
            } else if (GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0)) {
                self->field_E5 = (self->field_E5 + 1) % 10;
            }
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 5, self->field_E5);
            strncpy(self->field_BC->field_CF, D_004D3820 + self->field_E5 * 3, 3);
            break;
        case 6:
            break;
        case 7:
            self->field_BC->field_D5 = !self->field_BC->field_D5;
            func_003BC540(&D_01E8961C, 7, self->field_BC->field_D5);
            func_003BC360(&D_01E8961C, 8, self->field_BC->field_D5);
            break;
        }
        break;
    case 2: {
        int st = GetLobbyStatus__17CB3NetworkManagerFv(D_01E32AE0);
        switch (st) {
        case 0:
            return;
        case 2:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(D_01E90240, 1, 0);
            break;
        case 1: {
            int e = D_01E3CD44.vptr->vfunc_58(&D_01E3CD44);
            if (e == -7) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(D_01E90240, 0x22, 0);
            } else {
                self->field_DC = 3;
                func_0045D0B0_vc(&D_01E898E8);
                func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(D_01E32AE0, e), 0, 0);
            }
            break;
        }
        }
        break;
    }
    case 3:
        if (func_0032B2C0(&D_01E898E8, 0, 1) == 0) {
            func_0045D0B0_vc(&D_01E898E8);
            func_0045D0B0_vc(&D_01E8961C);
            if (self->field_DD == 0) {
                func_0045D0B0_inl5(self);
                func_0045D0B0_inl4(self);
                if (D_01E8D4B0.field_A)
                    func_0045D0B0_vc(&D_01E8D4B0);
                self->field_DC = 0;
            } else {
                if (D_01E8D4B0.field_A)
                    func_0045D0B0_vc(&D_01E8D4B0);
                func_0045D0B0_inl6(self);
                self->field_DC = 6;
            }
        }
        break;
    case 4:
        if (GetMenuBack__15CB3InputManagerFSc(D_004F50C0, 0)) {
            func_0045D0B0_inl4(self);
            self->field_DC = 0;
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x101, 3);
            func_0045D0B0_vc(&D_01E8D4F0);
            func_0045D0B0_vc(&D_01E8EAF8);
        } else if (self->field_E6 != 0) {
            self->field_DC = 5;
            func_0045D0B0_vc(&D_01E8D4F0);
            if (*self->field_CC == 0)
                func_0045D0B0_inl8(self, (const unsigned short *)func_00271A00(D_0051BA44, 0x3E0));
            else
                func_0045D0B0_inl8(self, self->field_D4);
            ShowSelectionBar__20CB3PageTextComponentFv(&D_01E8D4F0);
            unsigned short nl = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_C8.field_0 = 0;
            self->field_C8.field_2 = nl;
            func_0045D0B0_vc(&D_01E8EAF8);
            Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, D_004D38B8, D_004D38C0, D_004D38C8, &self->field_C8);
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x109, 3);
        }
        break;
    case 5:
        if (GetMenuBack__15CB3InputManagerFSc(D_004F50C0, 0) || GetMenuConfirm__15CB3InputManagerFSc(D_004F50C0, 0)) {
            func_00335F60(&D_01E3CD44);
            func_0045D0B0_inl4(self);
            func_0045D0B0_vc(&D_01E8D4F0);
            self->field_DC = 0;
            func_0045D0B0_vc(&D_01E8EAF8);
        } else if (GetMenuUp__15CB3InputManagerFSc(D_004F50C0, 0) && func_00379380(&D_01E8D4F0)) {
            unsigned short nl = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_C8.field_0 = self->field_C8.field_0 - 1;
            self->field_C8.field_2 = nl;
        } else if (GetMenuDown__15CB3InputManagerFSc(D_004F50C0, 0) && func_00379450(&D_01E8D4F0)) {
            unsigned short nl = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
            self->field_C8.field_0 = self->field_C8.field_0 + 1;
            self->field_C8.field_2 = nl;
        }
        break;
    case 6:
        if ((GetMenuUp__15CB3InputManagerFSc(D_004F50C0, 0) && func_00319360(&self->field_B8)) ||
            (GetMenuDown__15CB3InputManagerFSc(D_004F50C0, 0) && func_00319330(&self->field_B8))) {
            FEVerticalMove__18CB3HUDSoundManagerFv(D_01E7A800, 1);
            if (self->field_B8.field_0 == 1 && self->field_4[1].field_E == 0)
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89800.field_10 | 4, 3);
            else
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89800.field_10 & ~4, 3);
            break;
        }
        if (GetMenuConfirm__15CB3InputManagerFSc(D_004F50C0, 0)) {
            FESelect__18CB3HUDSoundManagerFv(D_01E7A800);
            if (self->field_B8.field_0 == 1 && self->field_4[1].field_E == 0)
                func_0045D0B0_inl7(self, self->field_BC->field_8C);
            break;
        }
        if (GetMenuBack__15CB3InputManagerFSc(D_004F50C0, 0)) {
            func_0045D0B0_vc(&D_01E8961C);
            func_0045D0B0_inl5(self);
            func_0045D0B0_inl4(self);
            func_0045D0B0_vc(&D_01E8D4B0);
            self->field_DC = 0;
            break;
        }
        if (!GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0) && !GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0))
            return;
        if (self->field_B8.field_0 == 0) {
            self->field_DC = 1;
            if (D_01E89544.field_A)
                func_0045D0B0_vc(&D_01E89544);
            Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 1, 0);
            SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0x296);
            SetDisplayText__28CB3OnScreenKeyboardComponentFPcb(&D_01E899C0, self->field_BC->field_8C, 0);
        }
        break;
    case 1:
        if (GetMenuLeft__15CB3InputManagerFSc(D_004F50C0, 0)) {
            SelectNextLeft__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(D_01E7A800);
        } else if (GetMenuRight__15CB3InputManagerFSc(D_004F50C0, 0)) {
            SelectNextRight__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(D_01E7A800);
        } else if (GetMenuUp__15CB3InputManagerFSc(D_004F50C0, 0)) {
            SelectNextUp__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(D_01E7A800);
        } else if (GetMenuDown__15CB3InputManagerFSc(D_004F50C0, 0)) {
            SelectNextDown__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardMove__18CB3HUDSoundManagerFv(D_01E7A800);
        } else if (GetMenuConfirm__15CB3InputManagerFSc(D_004F50C0, 0)) {
            Select__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(D_01E7A800);
        } else if (GetMenuKeyboardShift__15CB3InputManagerFSc(D_004F50C0, 0)) {
            SelectShift__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(D_01E7A800);
        } else if (GetMenuKeyboardCapsLock__15CB3InputManagerFSc(D_004F50C0, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(D_01E7A800);
            SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(D_004F50C0, 0xE, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(D_01E7A800);
            SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(D_004F50C0, 0xF, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(D_01E7A800);
            func_00350CF0(&D_01E899C0);
        } else if (GetMenuBack__15CB3InputManagerFSc(D_004F50C0, 0)) {
            FEKeyboardDel__18CB3HUDSoundManagerFv(D_01E7A800);
            if (self->field_DC == 1) {
                self->field_DC = 6;
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 0, 0);
                D_01E899C0.field_1C = 0;
                unsigned int ok;
                if (strlen(self->field_BC->field_8C) < 6) {
                    ok = 0;
                } else if (strchr(self->field_BC->field_8C, '.') == 0 || strchr(self->field_BC->field_8C, '@') == 0) {
                    ok = 0;
                } else {
                    UnkStruct_0045D0B0_prof * p = self->field_BC;
                    if (p->field_8C[strlen(p->field_8C) - 1] == '.' ||
                        self->field_BC->field_8C[strlen(p->field_8C) - 1] == '@')
                        ok = 0;
                    else
                        ok = 1;
                }
                func_003BC360(&D_01E8961C, 1, ok);
            }
        }
        break;
    }
}
