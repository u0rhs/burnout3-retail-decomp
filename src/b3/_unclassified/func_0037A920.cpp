// Hand-written; the lifter refused it (draftM: CB3OnlineOptimatchMenuPage update FSM [L], exact; func_0037B400 takes the index in a1).

// func_0037A920 -- hand-written (draftM) from the retail asm and the Ghidra draft.
// Unnamed in every table, so a placeholder with C linkage. [L] CB3OnlineOptimatchMenuPage's per-frame update: it sits
// between SetupTable__26CB3OnlineOptimatchMenuPageFv and CacheGameParams__26CB3OnlineOptimatchMenuPageFi, calls
// func_0037B400 (which calls CacheGameParams on the same object) and reads the same 0x50-byte game entries at +0x60.
// [C asm] func_0037B400 takes the entry index in a1 (it reaches CacheGameParams(int) untouched; its matched lifted
// source declares only self).
// Shape [C asm]: a 9-state FSM on field_1942 (jump table jtbl_004C91F0). Field names placeholders, types [G].
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using namespace GtMathPs2;

struct UnkStruct_0037A920_e {             // [G] one 0x48+8-byte game entry (same as CacheGameParams' entries at +0x60)
    char field_0[0x20];
    unsigned char pad_20[0x1C];
    int field_3C;                         // players [G]
    int field_40;                         // max players [G]
    unsigned char pad_44[0xC];
};
struct UnkStruct_0037A920_cell { CGtV4d field_0; unsigned char pad_10[0x40]; };
struct UnkStruct_0037A920_row { UnkStruct_0037A920_cell field_0[5]; };
struct UnkStruct_0037A920_rowc { CGtV4d field_0; unsigned char pad_10[0x30]; };
struct UnkStruct_0037A920_sel {           // [L] CB3MenuComponentSelectionData (func_00319330/60 take its address)
    unsigned short field_0;
    unsigned char pad_2[0x1E];
};

struct UnkStruct_0037A920 {
    unsigned char pad_0[0x38];
    unsigned char field_38[0x28];         // join parameters (CacheGameParams fills them) [L]
    UnkStruct_0037A920_e field_60[9];
    UnkStruct_0037A920_sel field_330;
    unsigned char pad_350[0x4F0 - 0x350];
    UnkStruct_0037A920_row field_4F0[8];
    unsigned char pad_1170[0x12E0 - 0x1170];
    UnkStruct_0037A920_rowc field_12E0[9];
    unsigned char pad_1520[0x18C4 - 0x1520];
    int field_18C4;
    int field_18C8;
    int field_18CC[0x14];
    int field_191C;
    int field_1920;
    unsigned char pad_1924[0x1C];
    unsigned char field_1940;
    unsigned char field_1941;
    signed char field_1942;
};

struct UnkStruct_0037A920_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0037A920_flag { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0037A920_P { unsigned char pad_0[0x10]; };
struct UnkStruct_0037A920_vc {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_0037A920_lobby {
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
    virtual void vfunc_38(void *);
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual int vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C(void *, void *);
    virtual void vfunc_A0(int);
    unsigned char pad_4[0xC];
};

extern CB3MenuPageManager D_01E90240;
extern UnkStruct_0037A920_int D_01E90424;
extern UnkStruct_0037A920_int D_01EA2F08;
extern UnkStruct_0037A920_P D_01E32AE0;
extern UnkStruct_0037A920_P D_01E3CD44;
extern UnkStruct_0037A920_P D_004F50C0;
extern UnkStruct_0037A920_P D_01E7A800;
extern UnkStruct_0037A920_P D_01E89788;
extern UnkStruct_0037A920_P D_01E89800;
extern UnkStruct_0037A920_P D_0051BA44;
extern UnkStruct_0037A920_P D_01E8D450;
extern UnkStruct_0037A920_flag D_01E8D45A;
extern UnkStruct_0037A920_P D_01E8D490;
extern UnkStruct_0037A920_flag D_01E8D49A;
extern UnkStruct_0037A920_P D_01E8D4B0;
extern UnkStruct_0037A920_flag D_01E8D4BA;
extern UnkStruct_0037A920_P D_01E898E8;
extern UnkStruct_0037A920_flag D_01E898F2;
extern UnkStruct_0037A920_P D_004C9148;
extern UnkStruct_0037A920_P D_004C9150;
extern UnkStruct_0037A920_P D_004C9158;
extern UnkStruct_0037A920_P D_004C9160;
extern UnkStruct_0037A920_P D_004C9168;
#define LOBBY ((UnkStruct_0037A920_lobby *)&D_01E3CD44)

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // passed 1 more argument [G] (N112)
extern "C" int GetLobbyStatus__17CB3NetworkManagerFv(void *);
extern "C" int GetErrorString__17CB3NetworkManagerFi(void *, int);
extern "C" int func_002351C0(void *);
extern "C" int GetMyPlayerIndex__23CGtNetworkPlayerManagerCFv(void *);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" int GetMenuConfirm__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuBack__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuUp__15CB3InputManagerFSc(void *, signed char);
extern "C" int GetMenuDown__15CB3InputManagerFSc(void *, signed char);
extern "C" int func_0022CBE0(void *, signed char);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void func_00284E90(void *);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);
extern "C" int func_00271A00(void *, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" int func_00319330(void *);
extern "C" int func_00319360(void *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_00235D90(void *);
extern "C" void func_0022D3F0();
extern "C" int func_0037B400(UnkStruct_0037A920 *, int);
extern "C" int func_0037B770(UnkStruct_0037A920 *);
extern "C" int func_0037C170(int, int, int, int, int, void *);

// [G] inlined "show the network error box": hides the three menu panels and the message box, then shows the
// lobby's error string (cf. func_0032A930 in B3OnlineJoinGamePage, which is the out-of-line equivalent).
static inline void func_0037A920_inl1(UnkStruct_0037A920 *p, int err)
{
    p->field_1942 = 3;
    if (D_01E8D45A.field_0 != 0) ((UnkStruct_0037A920_vc *)&D_01E8D450)->vfunc_C();
    if (D_01E8D49A.field_0 != 0) ((UnkStruct_0037A920_vc *)&D_01E8D490)->vfunc_C();
    if (D_01E8D4BA.field_0 != 0) ((UnkStruct_0037A920_vc *)&D_01E8D4B0)->vfunc_C();
    if (D_01E898F2.field_0 != 0) ((UnkStruct_0037A920_vc *)&D_01E898E8)->vfunc_C();
    func_0032D080(&D_01E898E8, 2, GetErrorString__17CB3NetworkManagerFi(&D_01E32AE0, err), 0, 0);
}

// 0x0037A920
extern "C" void func_0037A920(UnkStruct_0037A920 *self)
{
    CB3MenuPageManager *mgr = &D_01E90240;
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_1942) {
    case 0: {
        int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (st) {
            case 2:
                break;
            case 0:
                break;
            case 1:
                func_0037A920_inl1(self, LOBBY->vfunc_58());
                break;
        }
        if (self->field_1940) func_0037B770(self);
        break;
    }
    case 1: {
        int old = self->field_330.field_0;
        if (self->field_1920 > 0 && GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            int s = self->field_330.field_0;
            if (self->field_60[s].field_3C < self->field_60[s].field_40) {
                func_0037B400(self, s);
            }
            break;
        }
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            D_01E90240.StartLeadOutFore((EB3MenuFlowFSMEvents)3, 0);
            return;
        }
        if (func_0022CBE0(&D_004F50C0, 0)) {
            D_01E90240.StartLeadOutFore((EB3MenuFlowFSMEvents)0x24, 0);
            break;
        }
        if ((GetMenuUp__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319360(&self->field_330)) ||
            (GetMenuDown__15CB3InputManagerFSc(&D_004F50C0, 0) && func_00319330(&self->field_330))) {
            if (self->field_60[self->field_330.field_0].field_3C < self->field_60[self->field_330.field_0].field_40) {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x145, 3);
            } else {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x141, 3);
            }
            for (int i = 0; i < 5; i++) {
                self->field_4F0[old].field_0[i].field_0 = mgr->field_0[0];
                self->field_4F0[self->field_330.field_0].field_0[i].field_0 = mgr->field_0[1];
            }
            self->field_12E0[old].field_0 = mgr->field_0[0];
            self->field_12E0[self->field_330.field_0].field_0 = mgr->field_0[1];
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        }
        return;
    }
    case 2: {
        int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (st) {
            case 2:
                break;
            case 0:
                break;
            case 1:
                func_0037A920_inl1(self, LOBBY->vfunc_58());
                break;
        }
        if (GetMenuBack__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x18, 0);
            return;
        }
        if (func_0022CBE0(&D_004F50C0, 0)) {
            D_01E90240.StartLeadOutFore((EB3MenuFlowFSMEvents)0x24, 0);
        } else if (GetMenuConfirm__15CB3InputManagerFSc(&D_004F50C0, 0)) {
            self->field_1941 = 0;
            self->field_18C8 = 0;
            LOBBY->vfunc_9C((void *)func_0037C170, self);
            self->field_1942 = 8;
        }
        break;
    }
    case 8:
        if (self->field_1941) {
            self->field_191C = 0;
            self->field_18C4 = self->field_18CC[self->field_191C];
            LOBBY->vfunc_A0(self->field_18C4);
            D_01EA2F08.field_0 = self->field_18C4;
            self->field_1942 = 6;
        }
        break;
    case 3:
        if (!func_0032B2C0(&D_01E898E8, 0, 1)) {
        self->field_1942 = 1;
        ((UnkStruct_0037A920_vc *)&D_01E898E8)->vfunc_C();
        SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0x5F), 0, 0, 80.0f);
        func_00351F00(&D_01E8D4B0, &D_004C9148, &D_004C9150, &D_004C9158, &D_004C9160, &D_004C9168, 0x5F, 3, 1, 103, 0, 32.0f, 496.0f);
        return;
        }
        break;
    case 7:
        if (GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0) == 2) {
            LOBBY->vfunc_A0(self->field_18C4);
            D_01EA2F08.field_0 = self->field_18C4;
            self->field_1942 = 4;
        }
        break;
    case 5: {
        int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (st) {
            case 2:
                if (func_002351C0(&D_01E32AE0) && GetMyPlayerIndex__23CGtNetworkPlayerManagerCFv(&D_01E32AE0) > -1) {
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(mgr, (EB3MenuFlowFSMEvents)1, 0);
                    func_00284E90(&D_01E7A800);
                }
                break;
            case 0:
                return;
            case 1:
                func_0037A920_inl1(self, LOBBY->vfunc_58());
                break;
        }
        break;
    }
    case 4:
    case 6: {
        int st = GetLobbyStatus__17CB3NetworkManagerFv(&D_01E32AE0);
        switch (st) {
            case 2:
                if (self->field_1942 == 6) {
                    StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(mgr, (EB3MenuFlowFSMEvents)0x2D, 0);
                } else {
                    ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
                    func_00235D90(&D_01E32AE0);
                    func_0022D3F0();
                    LOBBY->vfunc_38(self->field_38);
                    self->field_1942 = 5;
                }
                break;
            case 0:
                return;
            case 1:
                self->field_191C++;
                if (self->field_1942 == 6 && self->field_191C < self->field_18C8) {
                    self->field_18C4 = self->field_18CC[self->field_191C];
                    LOBBY->vfunc_A0(self->field_18C4);
                    D_01EA2F08.field_0 = self->field_18C4;
                } else {
                    func_0037A920_inl1(self, LOBBY->vfunc_58());
                }
                break;
        }
        break;
    }
    }
}
