// CB3OnlineJoinGamePage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (low); file: research/retail_names.csv -> B3OnlineJoinGamePage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (draftJ: hand-written from asm+Ghidra; 6-state FSM, cases in source order 0,1,3,2,4,5; lobby status as switch (case 2,0,1); join predicate = nested bool inlines taking (page, index); StartLeadOut via extern C (N112)).

// Update__21CB3OnlineJoinGamePageFv -- hand-written (draftJ) from the retail asm and the Ghidra draft.
// [C] name: retail tables (DNAT high). Shape [C asm]: a 6-state FSM on field_1B15 (jump table), state 0 = game list
// (confirm joins / opens the password keyboard, up/down scroll, re-colours the old and new rows), 1 = waiting for the
// lobby join, 2 = list idle, 3 = join by id, 4 = error box, 5 = password keyboard. Field names placeholders, types [G].
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using namespace GtMathPs2;

struct UnkStruct_00327F10_game {          // [G] one 0x48-byte game row (same type as func_00329210's rows at +0x1870)
    unsigned char pad_0[0x34];
    int field_34;                         // players [G]
    int field_38;                         // max players [G]
    unsigned char pad_3C[0x8];
    unsigned char field_44;               // flags: 1, 2 (password), 4, 0x10, 0x20 [G]
    unsigned char field_45;
    unsigned char pad_46[0x2];
    bool IsFlag1() { return field_44 & 1; }
    bool IsFlag4() { return field_44 & 4; }
    bool IsFlag20() { return field_44 & 0x20; }
    bool IsNotFlag1() { return !IsFlag1(); }
    bool IsNotFlag4() { return !IsFlag4(); }
};
struct UnkStruct_00327F10_cell { CGtV4d field_0; unsigned char pad_10[0x40]; };
struct UnkStruct_00327F10_row { UnkStruct_00327F10_cell field_0[5]; };
struct UnkStruct_00327F10_rowc { CGtV4d field_0; unsigned char pad_10[0x30]; };
struct UnkStruct_00327F10_sel {           // [L] CB3MenuComponentSelectionData (SelectNext/SelectPrev take its address)
    unsigned short field_0;               // selected row
    unsigned char pad_2[0x2];
    short field_4;
    short field_6;
    int field_8;
    int field_C;                          // scroll offset [G]
    int field_10;
    int field_14;
    int field_18;                         // game id [G]
};
struct UnkStruct_00327F10_3 {
    int field_0;
    char * field_4;
    void * field_8;
    int field_C;
    int field_10;
    int field_14;
    void * field_18;
    void * field_1C;
    void * field_20;
    void * field_24;
    unsigned char pad_28[0x8];
};
struct UnkStruct_00327F10_10 {
    unsigned char pad_0[0x4C];
    void * field_4C;
};

class CB3OnlineJoinGamePage {
public:
    void Update();
    unsigned char pad_0[0x10];
    unsigned char field_10[0x1E0];
    UnkStruct_00327F10_row field_1F0[8];
    unsigned char pad_E70[0xFE0 - 0xE70];
    UnkStruct_00327F10_rowc field_FE0[9];
    unsigned char pad_1220[0x54];
    int field_1274;
    unsigned char pad_1278[0x15A4 - 0x1278];
    char field_15A4[0x20];
    signed char field_15C4;
    unsigned char pad_15C5[0x23];
    UnkStruct_00327F10_game field_15E8[9];
    UnkStruct_00327F10_game field_1870[9];
    UnkStruct_00327F10_sel field_1AF8;
    unsigned char pad_1B14;
    signed char field_1B15;
};
#define SEL(s) ((s)->field_1AF8)
#define STATE(s) ((s)->field_1B15)

struct UnkStruct_D_00665ECE { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00327F10_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00327F10_flag { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00327F10_P { unsigned char pad_0[0x10]; };
struct UnkStruct_00327F10_vc {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_00327F10_lobby {
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
    virtual void vfunc_38(UnkStruct_00327F10_3 *);
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual int vfunc_58();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E90130 { int field_0; int field_4; unsigned char pad_8[0x8]; };

extern CB3MenuPageManager D_01E90240;
extern UnkStruct_00327F10_int D_01E90424;
extern UnkStruct_00327F10_int D_01E8CBCC;
extern UnkStruct_D_00665ECE D_00665ECE;
extern UnkStruct_00327F10_P D_01E32AE0;
extern UnkStruct_00327F10_P D_01E3CD44;
#define LOBBY ((UnkStruct_00327F10_lobby *)&D_01E3CD44)
extern UnkStruct_00327F10_P D_004F50C0;
extern UnkStruct_00327F10_P D_01E7A800;
extern UnkStruct_00327F10_P D_01E899C0;
extern UnkStruct_00327F10_P D_01E89788;
extern UnkStruct_00327F10_P D_01E89800;
extern UnkStruct_00327F10_P D_0051BA44;
extern UnkStruct_D_01E90130 D_01E90130;
extern UnkStruct_00327F10_P D_01E8D450;
extern UnkStruct_00327F10_flag D_01E8D45A;
extern UnkStruct_00327F10_P D_01E8D490;
extern UnkStruct_00327F10_flag D_01E8D49A;
extern UnkStruct_00327F10_P D_01E8D4B0;
extern UnkStruct_00327F10_flag D_01E8D4BA;
extern UnkStruct_00327F10_P D_01E8EAF8;
extern UnkStruct_00327F10_flag D_01E8EB02;
extern UnkStruct_00327F10_P D_01E898E8;
extern UnkStruct_00327F10_flag D_01E898F2;
extern UnkStruct_00327F10_P krTextPosition;
extern UnkStruct_00327F10_P krTextHandle;
extern UnkStruct_00327F10_P krTextBackgroundPosition;
extern UnkStruct_00327F10_P krTextBackgroundHandle;
extern UnkStruct_00327F10_P krTextBackgroundSize;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument [G] (N112)
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int func_002351C0(void *);
extern "C" int GetMyPlayerIndex__23CGtNetworkPlayerManagerCFv(void *);
extern "C" void SetGameID__23CGtNetworkPlayerManagerFi(void *, int);
extern "C" int GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(void *);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuLeft__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuRight__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardShift__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuKeyboardCapsLock__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(void *, int, signed char);
extern "C" int func_0022CBE0(void *, signed char);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void FEKeyboardMove__18CB3HUDSoundManagerFv(void *);
extern "C" void FEKeyboardSel__18CB3HUDSoundManagerFv(void *);
extern "C" void func_00284E90(void *);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(void *, int);
extern "C" void SetDisplayText__28CB3OnScreenKeyboardComponentFPUsb(void *, void *, bool);
extern "C" void SelectNextLeft__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextRight__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextUp__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectNextDown__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectShift__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectCapsLock__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void SelectSymbols__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void Select__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void func_00350CF0(void *);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003180A0(void *, void *, void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, UnkStruct_00327F10_10 *, int);
extern "C" bool func_00351E40(void *, void *, void *, void *, void *, void *, void *, int, int, int, int, float, float);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" int func_00329330(CB3OnlineJoinGamePage *);
extern "C" int func_00329210(CB3OnlineJoinGamePage *, int);
extern "C" void func_0032A930(CB3OnlineJoinGamePage *, int);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_00235D90(void *);
extern "C" void func_0022D3F0();
extern "C" bool PlayerListChangedCallback__17CB3NetworkManagerFiPv(int, void*);
extern "C" int PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv(int, void*);

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
static inline void func_00327F10_inl7(UnkStruct_00327F10_sel *s, int a, int b)
{
    s->field_4 = a;
    s->field_6 = b;
}

// 0x00327F10
void CB3OnlineJoinGamePage::Update()
{
    CB3MenuPageManager *mgr = &D_01E90240;
    bool moved = false;
    if (D_01E90424.field_0 != 5) return;
    switch (STATE(this)) {
    case 0: {
        func_00329330(this);
        int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (st) {
            case 2: {
                if (SEL(this).field_14 > 0 && GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
                    if (func_00327F10_inl4(this, SEL(this).field_0)) {
                        field_15A4[0] = 0;
                        if (field_1870[SEL(this).field_0].field_44 & 2) {
                            STATE(this) = 5;
                            Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 1, 0);
                            SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0xC58);
                            D_01E8CBCC.field_0 = 0x11;
                            SetDisplayText__28CB3OnScreenKeyboardComponentFPUsb(&D_01E899C0, (void *)(func_00271A00(&D_0051BA44, 0x9BF)), 1);
                        } else {
                            if (func_00329210(this, SEL(this).field_0)) {
                                STATE(this) = 1;
                                FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
                                if (D_01E8D45A.field_0 != 0) ((UnkStruct_00327F10_vc *)&D_01E8D450)->vfunc_C();
                                if (D_01E8D49A.field_0 != 0) ((UnkStruct_00327F10_vc *)&D_01E8D490)->vfunc_C();
                                if (D_01E8D4BA.field_0 != 0) ((UnkStruct_00327F10_vc *)&D_01E8D4B0)->vfunc_C();
                                if (D_01E8EB02.field_0 != 0) ((UnkStruct_00327F10_vc *)&D_01E8EAF8)->vfunc_C();
                                unsigned short buf[38];
                                unsigned short *p;
                                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(field_10, (UnkStruct_00327F10_10 *)buf, 32);
                                p = buf;
                                func_003180A0((void *)(field_1274), (void *)(func_00271A00(&D_0051BA44, 98)), &p);
                                SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)field_1274, 0, 0, 80.0f);
                                func_00351E40(&D_01E8D4B0, &krTextPosition, &krTextHandle, &krTextBackgroundPosition, &krTextBackgroundHandle, &krTextBackgroundSize, (void *)(field_1274), 3, 1, 103, 0, 32.0f, 496.0f);
                            }
                        }
                    }
                }
                break;
            }
            case 0:
                return;
            case 1:
            func_0032A930(this, LOBBY->vfunc_58());
                break;
        }
        int sel = SEL(this).field_0;
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            D_01E90240.StartLeadOutFore((EB3MenuFlowFSMEvents)3, 0);
            return;
        }
        if (func_0022CBE0(&D_004F50C0, 0)) {
            D_01E90240.StartLeadOutFore((EB3MenuFlowFSMEvents)0x24, 0);
        } else if (GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (func_00319360(&SEL(this))) {
                moved = true;
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            } else if (SEL(this).field_C > 0) {
                SEL(this).field_C--;
                SEL(this).field_8 = 0x3D;
                func_00329330(this);
            }
        } else if (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            if (func_00319330(&SEL(this))) {
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
                moved = true;
            } else if (SEL(this).field_0 < GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44) - SEL(this).field_C - 1) {
                SEL(this).field_C++;
                SEL(this).field_8 = 0x3D;
                func_00329330(this);
            }
        }
        if (!moved) return;
        {
            unsigned char f = field_15E8[SEL(this).field_0].field_44;
            if (((f & 0x10) && D_00665ECE.field_0) || ((f & 0x20) && !D_00665ECE.field_0)) {
                SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0x5F), 0, 1, 80.0f);
            } else if (D_00665ECE.field_0) {
                SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0xB3C), 0, 1, 80.0f);
            } else {
                SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0xB3D), 0, 1, 80.0f);
            }
        }
        if (SEL(this).field_C + SEL(this).field_0 >= GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44)) {
            func_00327F10_inl7(&SEL(this), GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44) - 1, GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44));
        } else {
            func_00327F10_inl7(&SEL(this), SEL(this).field_C + SEL(this).field_0, GetNumGamesInCurrentLobby__20CGtLobbyPS2DirtySockFv(&D_01E3CD44));
        }
        if (func_00327F10_inl4(this, SEL(this).field_0)) {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x145, 3);
        } else {
            SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x141, 3);
        }
        for (int i = 0; i < 5; i++) {
            if (func_00327F10_inl4(this, sel)) {
                field_1F0[sel].field_0[i].field_0 = mgr->field_0[0];
            } else {
                field_1F0[sel].field_0[i].field_0 = mgr->field_0[2];
            }
            int c = SEL(this).field_0;
            if (func_00327F10_inl4(this, c)) {
                field_1F0[c].field_0[i].field_0 = mgr->field_0[1];
            }
        }
        if (func_00327F10_inl4(this, sel)) {
            field_FE0[sel].field_0 = mgr->field_0[0];
        } else {
            field_FE0[sel].field_0 = mgr->field_0[2];
        }
        int c = SEL(this).field_0;
        if (func_00327F10_inl4(this, c)) {
            UnkStruct_00327F10_rowc *rc = &field_FE0[c];
            rc->field_0 = mgr->field_0[1];
        }
        return;
    }
    case 1: {
        int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (st) {
            case 2: {
                if (func_002351C0(&D_01E32AE0) && GetMyPlayerIndex__23CGtNetworkPlayerManagerCFv(&D_01E32AE0) > -1) {
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(mgr, (EB3MenuFlowFSMEvents)1, 0);
                func_00284E90(&D_01E7A800);
                }
                break;
            }
            case 0:
                return;
            case 1:
            func_0032A930(this, LOBBY->vfunc_58());
                break;
        }
        break;
    }
    case 3: {
        int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (st) {
            case 2: {
                UnkStruct_00327F10_3 local;
                local.field_0 = SEL(this).field_18;
                SetGameID__23CGtNetworkPlayerManagerFi(&D_01E32AE0, SEL(this).field_18);
                local.field_C = D_01E90130.field_0;
                local.field_10 = D_01E90130.field_4;
                local.field_4 = (char *)&field_15C4;
                local.field_8 = field_15A4;
                local.field_14 = 0;
                local.field_18 = (void *)&PlayerListChangedCallback__17CB3NetworkManagerFiPv;
                local.field_1C = &D_01E32AE0;
                local.field_20 = (void *)&PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv;
                local.field_24 = &D_01E32AE0;
                func_00235D90(&D_01E32AE0);
                func_0022D3F0();
                LOBBY->vfunc_38(&local);
                STATE(this) = 1;
                break;
            }
            case 0:
                return;
            case 1:
            func_0032A930(this, LOBBY->vfunc_58());
                break;
        }
        break;
    }
    case 2:
        func_00329330(this);
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(mgr, (EB3MenuFlowFSMEvents)0x18, 0);
            return;
        }
        if (func_0022CBE0(&D_004F50C0, 0)) {
            mgr->StartLeadOutFore((EB3MenuFlowFSMEvents)0x24, 0);
        }
        break;
    case 4:
        if (func_0032B2C0(&D_01E898E8, 0, 1)) return;
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_00327F10_vc *)&D_01E898E8)->vfunc_C();
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
        if (field_15C4 == 0) {
            STATE(this) = 0;
            if (D_01E8D4BA.field_0 != 0) ((UnkStruct_00327F10_vc *)&D_01E8D4B0)->vfunc_C();
            SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0x5F), 0, 0, 80.0f);
            func_00351F00(&D_01E8D4B0, &krTextPosition, &krTextHandle, &krTextBackgroundPosition, &krTextBackgroundHandle, &krTextBackgroundSize, 0x5F, 3, 1, 103, 0, 32.0f, 496.0f);
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x18, 0);
        }
        return;
    case 5:
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
            if (STATE(this) == 5) Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, 0, 0);
            STATE(this) = 0;
            return;
        }
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
        } else if (GetMenuKeyboardShift__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectShift__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuKeyboardCapsLock__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            SelectCapsLock__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 14, 0)) {
            SelectSymbols__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        } else if (GetMenuButton__15CB3InputManagerFQ212CB3MenuInput13EMenuControlsSc(&D_004F50C0, 15, 0)) {
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
            func_00350CF0(&D_01E899C0);
        } else if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            Select__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
            FEKeyboardSel__18CB3HUDSoundManagerFv(&D_01E7A800);
        }
        break;
    }
}
