// NONMATCHING: func_00329330 -- retail 1186 / ours 1186 instructions, 41 in changed runs
// draftM: 1186/1186, 41 changed = 7 spill instructions only: retail spills &field_1870[i].field_30 and .field_45 with sq (slots 0xE0/0xD0) and .field_40 with sw (0xF0); ours spills all three with sw and swaps the 0xD0/0xF0 slots. Everything else identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] same instruction count and every instruction outside the 3 spill slots identical to retail
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// func_00329330 -- hand-written (draftM) from the retail asm and the Ghidra draft.
// Unnamed in every table, so a placeholder with C linkage. [L] CB3OnlineJoinGamePage's game-list refresh: called from
// CB3OnlineJoinGamePage::Update (0x327F10) with the page, calls SetMode__21CB3OnlineJoinGamePageFi20EB3MenuChoicesOnline,
// and is the JoinGame counterpart of the matched func_0037B770 (Optimatch page; same table/scroll-bar Prepare calls).
// Shape [C asm]: every 0x3D frames re-requests the game list (lobby vfunc_44 with callback func_0032A5C0); when a new
// list arrived (field_1B14), copies it to the shown list, fills the 9 table rows, clamps the selection and recolours.
// Field names placeholders, types [G].
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using namespace GtMathPs2;

enum EB3MenuChoicesOnline { };            // [C] type name: SetMode's mangled name; enumerators unknown

struct UnkStruct_00329330_game {          // [G] one 0x48-byte game row (field_15E8 = received, field_1870 = shown)
    unsigned long field_0;
    unsigned long field_8;
    char field_10[0x20];                  // game name
    int field_30;                         // mode (SetMode's EB3MenuChoicesOnline)
    int field_34;                         // players [G]
    int field_38;                         // max players [G]
    int field_3C;
    int field_40;                         // index into D_004C5580 (-1 = none)
    unsigned char field_44;               // flags: 1, 2 (password), 4, 0x10, 0x20 [G]
    unsigned char field_45;
    bool IsFlag1() { return field_44 & 1; }
    bool IsFlag4() { return field_44 & 4; }
    bool IsFlag20() { return field_44 & 0x20; }
    bool IsNotFlag1() { return !IsFlag1(); }
    bool IsNotFlag4() { return !IsFlag4(); }
};
struct UnkStruct_00329330_cell { CGtV4d field_0; unsigned char pad_10[0x18]; unsigned short *field_28; unsigned char pad_2C[0x24]; };
struct UnkStruct_00329330_row { UnkStruct_00329330_cell field_0[5]; };
struct UnkStruct_00329330_rowc { CGtV4d field_0; unsigned char pad_10[0x30]; };
struct UnkStruct_00329330_sel {           // [L] CB3MenuComponentSelectionData
    unsigned short field_0;               // selected row
    unsigned short field_2;               // row count
    short field_4;
    short field_6;
    int field_8;                          // refresh counter
    int field_C;                          // scroll offset [G]
    int field_10;                         // games received
    int field_14;
    int field_18;
};

class CB3OnlineJoinGamePage {
public:
    void SetMode(int, EB3MenuChoicesOnline);
    unsigned char pad_0[0x1F0];
    UnkStruct_00329330_row field_1F0[8];
    unsigned char pad_E70[0xFE0 - 0xE70];
    UnkStruct_00329330_rowc field_FE0[9];
    unsigned char pad_1220[0x4];
    unsigned short *field_1224[10];
    unsigned short *field_124C[10];
    unsigned char pad_1274[0x4];
    unsigned char field_1278[0x15E8 - 0x1278];  // CGt2dObjectTableData [L] (Prepare's argument); rows of 0x3C at +0x110
    UnkStruct_00329330_game field_15E8[9];
    UnkStruct_00329330_game field_1870[9];
    UnkStruct_00329330_sel field_1AF8;
    unsigned char field_1B14;
    signed char field_1B15;
};
#define SEL(s) ((s)->field_1AF8)
#define ROW(i) ((char *)self + (i) * 60)

struct UnkStruct_D_00665ECE { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00329330_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00329330_flag { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00329330_P { unsigned char pad_0[0x10]; };
struct UnkStruct_00329330_vc {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_00329330_lobby {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44(int, int, int, void *, void *);
    unsigned char pad_4[0xC];
};

extern CB3MenuPageManager D_01E90240;
extern UnkStruct_D_00665ECE D_00665ECE;
extern UnkStruct_00329330_P D_01E3CD44;
extern UnkStruct_00329330_P D_01E89788;
extern UnkStruct_00329330_P D_01E89800;
extern UnkStruct_00329330_P D_0051BA44;
extern UnkStruct_00329330_P D_01E8D450;
extern UnkStruct_00329330_flag D_01E8D45A;
extern UnkStruct_00329330_int D_01E8D45C;
extern UnkStruct_00329330_P D_01E8D490;
extern UnkStruct_00329330_flag D_01E8D49A;
extern UnkStruct_00329330_P D_01E8D4B0;
extern UnkStruct_00329330_flag D_01E8D4BA;
extern UnkStruct_00329330_P D_01E8EAF8;
extern UnkStruct_00329330_flag D_01E8EB02;
extern UnkStruct_00329330_P krTextPosition;
extern UnkStruct_00329330_P krTextHandle;
extern UnkStruct_00329330_P krTextBackgroundPosition;
extern UnkStruct_00329330_P krTextBackgroundHandle;
extern UnkStruct_00329330_P krTextBackgroundSize;
extern UnkStruct_00329330_P D_004C5568;
extern UnkStruct_00329330_P D_004C5570;
extern int D_004C5580[];
extern char D_004C55C8[];
extern char D_004C5608[];
extern char D_004C5610[];
#define LOBBY ((UnkStruct_00329330_lobby *)&D_01E3CD44)

extern "C" int GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(void *);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" void Prepare__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatabb(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, void *, bool, bool);
extern "C" void Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(void *, int, void *, void *);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, const void *, const void *, float, const void *);
extern "C" int func_0032A5C0(char *, int, int, int, int, int, int, int, signed char, int, int, int, int, void *, void *);

// the same nested predicates as CB3OnlineJoinGamePage::Update (draftJ, matched): joinable game row
static inline bool func_00327F10_inl1(CB3OnlineJoinGamePage *p, int i)
{
    bool r = false;
    if (p->field_1870[i].field_34 < p->field_1870[i].field_38 && p->field_1870[i].IsNotFlag1()) r = true;
    return r;
}
static inline bool func_00327F10_inl2(CB3OnlineJoinGamePage *p, int i)
{
    bool r = false;
    if (func_00327F10_inl1(p, i) && p->field_1870[i].IsNotFlag4()) r = true;
    return r;
}
static inline bool func_00327F10_inl3(CB3OnlineJoinGamePage *p, int i)
{
    bool r = false;
    if (func_00327F10_inl2(p, i) && p->field_1870[i].field_45) r = true;
    return r;
}
static inline bool func_00327F10_inl5(CB3OnlineJoinGamePage *p, int i)
{
    return p->field_1870[i].IsFlag20() && !D_00665ECE.field_0;
}
static inline bool func_00327F10_inl6(CB3OnlineJoinGamePage *p, int i)
{
    bool ok = true;
    bool x = false;
    if ((p->field_1870[i].field_44 & 0x10) && D_00665ECE.field_0) x = true;
    if (!x && !func_00327F10_inl5(p, i)) ok = false;
    return ok;
}
static inline bool func_00327F10_inl4(CB3OnlineJoinGamePage *p, int i)
{
    bool r = false;
    if (func_00327F10_inl3(p, i) && func_00327F10_inl6(p, i)) r = true;
    return r;
}
static inline void func_00327F10_inl7(UnkStruct_00329330_sel *s, int a, int b)
{
    s->field_4 = a;
    s->field_6 = b;
}

// 0x00329330
extern "C" int func_00329330(CB3OnlineJoinGamePage *self)
{
    CB3MenuPageManager * const mgr = &D_01E90240;
    int i;
    SEL(self).field_8++;
    if (SEL(self).field_8 >= 0x3D) {
        if (SEL(self).field_10 == 0) {
            self->field_1B15 = 2;
            if (D_01E8D4BA.field_0 != 0) ((UnkStruct_00329330_vc *)&D_01E8D4B0)->vfunc_C();
            if (D_01E8D45A.field_0 != 0) ((UnkStruct_00329330_vc *)&D_01E8D450)->vfunc_C();
            if (D_01E8D49A.field_0 != 0) ((UnkStruct_00329330_vc *)&D_01E8D490)->vfunc_C();
            if (D_01E8EB02.field_0 != 0) ((UnkStruct_00329330_vc *)&D_01E8EAF8)->vfunc_C();
            func_00351F00(&D_01E8D4B0, &krTextPosition, &krTextHandle, &krTextBackgroundPosition, &krTextBackgroundHandle, &krTextBackgroundSize, 0x64, 3, 0, 1, 0, 32.0f, 400.0f);
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x41, 0);
        }
        for (i = 0; i < 9; i++) {
            self->field_15E8[i].field_3C = 0;
            sprintf(self->field_15E8[i].field_10, D_004C5608);
            self->field_15E8[i].field_0 = 0;
            self->field_15E8[i].field_8 = 0;
            self->field_15E8[i].field_34 = 0;
            self->field_15E8[i].field_38 = 0;
            self->field_15E8[i].field_44 = 0;
            self->field_15E8[i].field_30 = 5;
            self->field_15E8[i].field_40 = -1;
        }
        SEL(self).field_8 = 0;
        SEL(self).field_10 = 0;
        self->field_1B14 = 1;
        LOBBY->vfunc_44(SEL(self).field_C, 9, 0x3C, (void *)func_0032A5C0, self);
        return 0;
    }
    if (SEL(self).field_10 == 0) return 0;
    if (!self->field_1B14) return 0;
    self->field_1B15 = 0;
    self->field_1B14 = 0;
    if (D_01E8D4BA.field_0 != 0) {
        ((UnkStruct_00329330_vc *)&D_01E8D4B0)->vfunc_C();
        CGtV2d va, vb, vc;
        Prepare__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatabb(&D_01E8D450, (va.Set(48.0f, 112.0f), va), (vb.Set(0.0f, 0.0f), vb), (vc.Set(544.0f, 256.0f), vc), self->field_1278, true, false);
        Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(&D_01E8D490, 1, (void *)(D_01E8D45C.field_0), &SEL(self));
        RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
        Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C5568, &D_004C5570, 256.0f, &SEL(self).field_4);
    }
    SEL(self).field_14 = SEL(self).field_10;
    i = 0;
    if (i < SEL(self).field_10) {
    CB3MenuPageManager * const m = &D_01E90240;
    for (; i < SEL(self).field_10; i++) {
        self->field_1870[i] = self->field_15E8[i];
        if ((self->field_1870[i].field_44 & 2) == 2) {
            *(void **)(ROW(i) + 0x138C) = (void *)&GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            *(void **)(ROW(i) + 0x1388) = (void *)&RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        } else {
            *(void **)(ROW(i) + 0x1388) = 0;
            *(void **)(ROW(i) + 0x138C) = 0;
        }
        if (func_00327F10_inl4(self, i)) {
            self->field_FE0[i].field_0 = m->field_0[0];
        } else {
            self->field_FE0[i].field_0 = m->field_0[2];
        }
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(self->field_1870[i].field_10, self->field_124C[i], 0x20);
        if (func_00327F10_inl4(self, i)) {
            self->field_1F0[i].field_0[1].field_0 = m->field_0[0];
        } else {
            self->field_1F0[i].field_0[1].field_0 = m->field_0[2];
        }
        self->SetMode(i, (EB3MenuChoicesOnline)self->field_1870[i].field_30);
        if (self->field_1870[i].field_40 == -1) {
            *(void **)(ROW(i) + 0x13B0) = 0;
            *(void **)(ROW(i) + 0x13AC) = 0;
        } else {
            self->field_1F0[i].field_0[3].field_28 = func_00271A00(&D_0051BA44, D_004C5580[self->field_1870[i].field_40]);
            *(void **)(ROW(i) + 0x13B0) = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            *(void **)(ROW(i) + 0x13AC) = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            if (func_00327F10_inl4(self, i)) {
                self->field_1F0[i].field_0[3].field_0 = m->field_0[0];
            } else {
                self->field_1F0[i].field_0[3].field_0 = m->field_0[2];
            }
        }
        int a3v = self->field_1870[i].field_34;
        int t0v = self->field_1870[i].field_38;
        if (a3v == -1) {
            *(void **)(ROW(i) + 0x13BC) = 0;
            *(void **)(ROW(i) + 0x13B8) = 0;
        } else {
            char buf[6];
            snprintf(buf, 6, D_004C55C8, a3v, t0v);
            ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_1224[i], 6);
            *(void **)(ROW(i) + 0x13BC) = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            *(void **)(ROW(i) + 0x13B8) = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            if (func_00327F10_inl4(self, i)) {
                self->field_1F0[i].field_0[4].field_0 = m->field_0[0];
            } else {
                self->field_1F0[i].field_0[4].field_0 = m->field_0[2];
            }
        }
    }
    }
    if (i < 9) {
    CB3MenuPageManager * const m = &D_01E90240;
    for (; i < 9; i++) {
        *(void **)(ROW(i) + 0x1388) = 0;
        *(void **)(ROW(i) + 0x138C) = 0;
        if (func_00327F10_inl4(self, i)) {
            self->field_FE0[i].field_0 = m->field_0[0];
        } else {
            self->field_FE0[i].field_0 = m->field_0[2];
        }
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(D_004C5610, self->field_124C[i], 0x20);
        if (func_00327F10_inl4(self, i)) {
            self->field_1F0[i].field_0[1].field_0 = m->field_0[0];
        } else {
            self->field_1F0[i].field_0[1].field_0 = m->field_0[2];
        }
        self->SetMode(i, (EB3MenuChoicesOnline)5);
        *(void **)(ROW(i) + 0x13B0) = 0;
        *(void **)(ROW(i) + 0x13AC) = 0;
        *(void **)(ROW(i) + 0x13BC) = 0;
        *(void **)(ROW(i) + 0x13B8) = 0;
    }
    }
    RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
    int cur = SEL(self).field_0;
    {
        int n = SEL(self).field_10;
        if (cur < n) {
            SEL(self).field_0 = cur;
            SEL(self).field_2 = n;
        } else {
            SEL(self).field_0 = n - 1;
            SEL(self).field_2 = n;
        }
    }
    if (SEL(self).field_C + SEL(self).field_0 >= GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44)) {
        func_00327F10_inl7(&SEL(self), GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44) - 1, GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44));
    } else {
        func_00327F10_inl7(&SEL(self), SEL(self).field_C + SEL(self).field_0, GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44));
    }
    if (cur != -1) {
        for (int j = 0; j < 5; j++) {
            if (func_00327F10_inl4(self, cur)) {
                self->field_1F0[cur].field_0[j].field_0 = mgr->field_0[0];
            } else {
                self->field_1F0[cur].field_0[j].field_0 = mgr->field_0[2];
            }
        }
        if (func_00327F10_inl4(self, cur)) {
            self->field_FE0[cur].field_0 = mgr->field_0[0];
        } else {
            self->field_FE0[cur].field_0 = mgr->field_0[2];
        }
    }
    if (func_00327F10_inl4(self, SEL(self).field_0)) {
        for (int j = 0; j < 5; j++) {
            self->field_1F0[SEL(self).field_0].field_0[j].field_0 = mgr->field_0[1];
        }
        self->field_FE0[SEL(self).field_0].field_0 = mgr->field_0[1];
    }
    if (func_00327F10_inl4(self, SEL(self).field_0)) {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x145, 3);
    } else {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x141, 3);
    }
    {
        unsigned char f = self->field_1870[SEL(self).field_0].field_44;
        if (((f & 0x10) && D_00665ECE.field_0) || ((f & 0x20) && !D_00665ECE.field_0)) {
            SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, func_00271A00(&D_0051BA44, 0x5F), 0, 1, 80.0f);
        } else {
            SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, func_00271A00(&D_0051BA44, 0xF9E), 0, 1, 80.0f);
        }
    }
    return 1;
}
