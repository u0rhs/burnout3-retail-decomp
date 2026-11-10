// NONMATCHING: func_00135620 -- retail 70 / ours 62 instructions, 17 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x135620..0x135734). Unnamed; file B3OnlineStage.cpp per
// research/retail_names.csv (high). [L] the online stage's Update: func_00135180's shape, with func_00131F10(gGame,
// D_0051A6A8) when the game mode's slot 0x28 fires, the HUD update inside the D_004EB1E0 test, and the half-rate
// request skipped for the two embedded game modes (D_0051B714 / D_0051B788 = gGame + 0x2D6D4 / + 0x2D748).
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

struct UnkStruct_00135620_gm { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual int vfunc_28(); };
struct UnkStruct_00135620 {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8();                   // [C] the stage's vtable pointer sits at +0x1B0
    UnkStruct_00135620_gm * field_1B4;
};

extern unsigned char D_004EB1E0;              // [C] the CB3DebugManager object's first byte, read as a flag
extern unsigned char D_004EB1E1;
extern unsigned char D_0064EC9A;
extern unsigned char D_0051BAA5;              // [C] gGame + 0x2DA65 / + 0x2DA66
extern unsigned char D_0051BAA6;
extern float D_004F509C;
extern unsigned char D_004EE040[];            // [C] gGame
extern unsigned char D_0051A6A8[];
extern unsigned char D_0066A3D0[];            // [C] the CB3HUDManager
extern unsigned char D_0051B714[];            // [C] gGame + 0x2D6D4 / + 0x2D748: the embedded game modes (func_001322B0)
extern unsigned char D_0051B788[];

extern "C" void func_00134660(void *);        // [C] reads a0: this+0x1B4 / +0x1B8
extern "C" void func_00131F10(void *, void *);
extern "C" void Update__13CB3HUDManagerFf(void *, float);

// 0x00135620
extern "C" void func_00135620(UnkStruct_00135620 * self)
{
    if (D_004EB1E0 != 0) {
        func_00134660(self);
        if (self->field_1B4->vfunc_28() != 0) {
            func_00131F10(D_004EE040, D_0051A6A8);
        }
        Update__13CB3HUDManagerFf(D_0066A3D0, D_004F509C);
        void * gm = self->field_1B4;
        if (gm != D_0051B714 && gm != D_0051B788) {
            if (D_0064EC9A != 0) {
                if (D_0051BAA6 == 0) {
                    D_0051BAA5 = 1;
                }
            } else if (D_0051BAA6 != 0) {
                D_0051BAA5 = 0;
            }
        }
    }
    if (D_004EB1E1 != 0) {
        self->field_1B4->vfunc_14();
    }
}
