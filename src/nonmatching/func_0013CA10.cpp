// NONMATCHING: func_0013CA10 -- retail 101 / ours 99 instructions, 24 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x13CA10..0x13CBA0). Unnamed; file B3TwoPlayerSplitScreenStage.cpp
// per research/retail_names.csv (medium). [L] the split-screen stage's Render by its calls: both viewports, the world
// (func_002768F0 in crash mode when the game mode's slot 0xAC agrees, else RenderTwoPlayer__8CB3WorldFv), then the HUD
// unless D_01E90430 is set and the menu-flow state's id is not 0x94413EA3518C496C (no state: id 0x6D6123044330FCCF).
// TRACK: clean
// EQUIV: [L] written from the asm: every branch and call accounted for; the id compare is 64-bit (bne after pcpyld)

struct UnkStruct_0013CA10_gm { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual int vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8(); virtual int vfunc_AC(); };
struct UnkStruct_0013CA10_st { unsigned char pad_0[0x1B0]; virtual void vfunc_8(); UnkStruct_0013CA10_gm * field_1B4; };
struct UnkStruct_0013CA10_fs { unsigned long field_0; };   // [C] ld 0x0: the FSM state's 64-bit id

extern unsigned char D_00665EC0[];            // [C] the CB3GraphicsManager
extern unsigned char D_00666090[];
extern unsigned char D_00666130[];
extern unsigned char D_0064D3B0[];
extern unsigned char D_0064FB80[];
extern unsigned char D_004EE040[];            // [C] gGame
extern unsigned char D_00522660[];            // [C] the CB3World
extern unsigned char D_0066A3D0[];            // [C] the CB3HUDManager
extern UnkStruct_0013CA10_st * D_0051BA88;    // [C] gGame + 0x2DA48: the current stage
extern int D_01E90430;
extern UnkStruct_0013CA10_fs * D_01EA2974;    // [C] the menu-flow FSM's current state

extern "C" void UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(void *, int);
extern "C" void * func_0019E9E0(void *, int);
extern "C" void func_0030A9D0(void *, void *, void *);
extern "C" int func_00131E40(void *);         // [L] E map: CB3Game::IsCrashMode() (upstream note in symbol_addrs)
extern "C" void func_002768F0(void *);
extern "C" void RenderTwoPlayer__8CB3WorldFv(void *);
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void Render__13CB3HUDManagerFv(void *);
extern "C" void Begin__12Gt2dRendererFv();
extern "C" void func_00217E70(int);
extern "C" void func_00134DF0(void *);
extern "C" void End__12Gt2dRendererFv();
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);

// 0x0013CA10
extern "C" void func_0013CA10()
{
    UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(D_00665EC0, 1);
    UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(D_00665EC0, 2);
    func_0030A9D0(D_00666090, func_0019E9E0(D_00665EC0, 1), D_0064D3B0);
    func_0030A9D0(D_00666130, func_0019E9E0(D_00665EC0, 2), D_0064FB80);
    if (func_00131E40(D_004EE040) != 0 && D_0051BA88->field_1B4->vfunc_AC() != 0) {
        func_002768F0(D_00522660);
    } else {
        RenderTwoPlayer__8CB3WorldFv(D_00522660);
    }
    OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(D_00665EC0, 0);
    bool hud = true;
    if (D_01E90430 != 0) {
        unsigned long id = D_01EA2974 != 0 ? D_01EA2974->field_0 : 0x6D6123044330FCCFUL;
        if (id != 0x94413EA3518C496CUL) {
            hud = false;
        }
    }
    if (hud) {
        Render__13CB3HUDManagerFv(D_0066A3D0);
        Begin__12Gt2dRendererFv();
        func_00217E70(0);
        func_00134DF0(D_0064D3B0);
        End__12Gt2dRendererFv();
    }
    CloseViewport__22CB3GraphicsManagerBaseFv(D_00665EC0);
}
