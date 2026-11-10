// NONMATCHING: func_00131AC0 -- retail 27 / ours 26 instructions, 2 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x131AC0..0x131B28). Unnamed (no retail_names.csv row; in B3Game.cpp's range). One menu-only
// frame: the menu-flow FSM (slot 0x10) and the page manager update, then open, render, close and present -- the
// tail of func_00132600 without the stage.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_00131AC0_fsm { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); };

extern UnkStruct_00131AC0_fsm D_01EA2970;     // [C] the menu-flow CGtFSM
extern unsigned char D_01E90240[];            // [C] the CB3MenuPageManager
extern unsigned char D_00665EC0[];            // [C] the CB3GraphicsManager

extern "C" void Update__18CB3MenuPageManagerFv(void *);
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void Render__18CB3MenuPageManagerFv(void *);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void PresentDrawBuffer__18CB3GraphicsManagerFv(void *);

// 0x00131AC0
extern "C" void func_00131AC0()
{
    ((UnkStruct_00131AC0_fsm *)&D_01EA2970)->vfunc_10();   // through the pointer: a virtual call, as retail
    Update__18CB3MenuPageManagerFv(D_01E90240);
    OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(D_00665EC0, 0);
    Render__18CB3MenuPageManagerFv(D_01E90240);
    CloseViewport__22CB3GraphicsManagerBaseFv(D_00665EC0);
    PresentDrawBuffer__18CB3GraphicsManagerFv(D_00665EC0);
}
