// NONMATCHING: func_00135280 -- retail 69 / ours 64 instructions, 20 in changed runs
// gaps1: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x135280..0x135390). [L] CB3OnePlayerStage::Prepare by file
// (research/retail_names.csv: B3OnePlayerStage.cpp, high) -- kept as its asm label. Returns 0 when the memory layout or
// func_001346C0 fails, else 1. D_0051BAA8 = gGame+0x2DA68 (frame-rate mode) [C address arithmetic].
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for; GetMenuFlowType's result is unused [C]

struct UnkStruct_00135280_gm {
    // [C] the game mode at stage+0x1B4: vtable at +0; slots called with a0 = it
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual int vfunc_28(); virtual void vfunc_2C(); virtual int vfunc_30();
};
struct UnkStruct_00135280_st {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8();              // [C] the stage's vtable pointer sits at +0x1B0 (func_00132600's calls)
    UnkStruct_00135280_gm * field_1B4;        // [C] lw 0x1B4($a0)
};

extern unsigned char D_01E65499;
extern unsigned char D_00516E10;
extern unsigned char D_00516E34;
extern int D_0066A544;
extern int D_0051BAA8;
extern unsigned char theMemMgr[];
extern unsigned char D_00516DF0[];       // [C] a CB3Player (Prepare__9CB3PlayerFv a0)
extern unsigned char D_00665EC0[];       // [C] the CB3GraphicsManager
extern unsigned char D_0066A3D0[];       // [C] the CB3HUDManager
extern unsigned char D_01E77540[];
extern unsigned char D_01EA2970[];       // [C] the menu-flow FSM (GetMenuFlowType__14CB3MenuFlowFSMFv a0)
extern unsigned char D_0051A6A8[];

extern "C" int AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(void *, int);
extern "C" int func_001346C0(UnkStruct_00135280_st *);
extern "C" int Prepare__9CB3PlayerFv(void *);
extern "C" void func_00135A90(void *);
extern "C" void func_0019E990(void *);
extern "C" void func_001A0660(void *, int);
extern "C" void func_00289AF0(void *, int);
extern "C" int GetMenuFlowType__14CB3MenuFlowFSMFv(void *);
extern "C" void func_00130C20(void *, unsigned long);   // [C] proven: stores p0 (64-bit) at +0x300

// 0x00135280
extern "C" int func_00135280(UnkStruct_00135280_st * self)
{
    D_01E65499 = 0;
    if (AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(theMemMgr, 1) == 0) {
        return 0;
    }
    if (func_001346C0(self) == 0) {
        return 0;
    }
    Prepare__9CB3PlayerFv(D_00516DF0);
    D_00516E10 = 1;
    func_00135A90(D_00516DF0);
    D_00516E34 = 0;
    func_0019E990(D_00665EC0);
    D_0066A544 = self->field_1B4->vfunc_30();
    func_001A0660(D_0066A3D0, 1);
    func_00289AF0(D_01E77540, 1);
    GetMenuFlowType__14CB3MenuFlowFSMFv(D_01EA2970);
    // [C] a 64-bit id (a GtID hash, N293's class) built with dsll32/or and passed through pcpyld (upper half zero)
    func_00130C20(D_0051A6A8, 0x94413FC035B0F871UL);
    D_0051BAA8 = 0;
    return 1;
}
