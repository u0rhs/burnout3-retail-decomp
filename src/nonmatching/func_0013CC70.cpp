// NONMATCHING: func_0013CC70 -- retail 88 / ours 82 instructions, 18 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x13CC70..0x13CDCC). Unnamed; file B3TwoPlayerSplitScreenStage.cpp
// per research/retail_names.csv (medium). [L] the split-screen stage's Prepare: func_00135280's shape for two players
// (memory layout 2, both CB3Players D_00516DF0 / D_00516E14, the HUD and func_00289AF0 for 2, single- or split
// viewports by crash mode); returns 0 on failure, else 1.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for; GetMenuFlowType's result is unused [C]

struct UnkStruct_0013CC70_gm { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual int vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8(); virtual int vfunc_AC(); };
struct UnkStruct_0013CC70 { unsigned char pad_0[0x1B0]; virtual void vfunc_8(); UnkStruct_0013CC70_gm * field_1B4; };

extern unsigned char D_01E65499;
extern unsigned char D_00516E10;
extern unsigned char D_00516E34;
extern unsigned char D_0051BAA5;              // [C] gGame + 0x2DA65
extern int D_0051BAA8;                        // [C] gGame + 0x2DA68 (frame-rate mode)
extern int D_0066A544;
extern unsigned char theMemMgr[];
extern unsigned char D_00516DF0[];            // [C] CB3Players (Prepare__9CB3PlayerFv a0)
extern unsigned char D_00516E14[];
extern unsigned char D_004EE040[];
extern unsigned char D_00665EC0[];
extern unsigned char D_0066A3D0[];
extern unsigned char D_01E77540[];
extern unsigned char D_01EA2970[];
extern unsigned char D_0051A6A8[];

extern "C" int AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(void *, int);
extern "C" int func_001346C0(void *);
extern "C" int Prepare__9CB3PlayerFv(void *);
extern "C" void func_00135A90(void *);
extern "C" int func_00131E40(void *);         // [L] E map: CB3Game::IsCrashMode() (upstream note in symbol_addrs)
extern "C" void func_0019E990(void *);
extern "C" void func_0019E760(void *);
extern "C" void func_001A0660(void *, int);
extern "C" void func_00289AF0(void *, int);
extern "C" int GetMenuFlowType__14CB3MenuFlowFSMFv(void *);
extern "C" void func_00130C20(void *, unsigned long);   // [C] proven: stores p0 (64-bit) at +0x300

// 0x0013CC70
extern "C" int func_0013CC70(UnkStruct_0013CC70 * self)
{
    D_01E65499 = 0;
    if (AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(theMemMgr, 2) == 0) {
        return 0;
    }
    if (func_001346C0(self) == 0) {
        return 0;
    }
    Prepare__9CB3PlayerFv(D_00516DF0);
    Prepare__9CB3PlayerFv(D_00516E14);
    D_00516E10 = 1;
    func_00135A90(D_00516DF0);
    D_00516E34 = 1;
    func_00135A90(D_00516E14);
    if (func_00131E40(D_004EE040) != 0) {
        func_0019E990(D_00665EC0);
    } else {
        func_0019E760(D_00665EC0);
    }
    D_0066A544 = self->field_1B4->vfunc_30();
    func_001A0660(D_0066A3D0, 2);
    func_00289AF0(D_01E77540, 2);
    GetMenuFlowType__14CB3MenuFlowFSMFv(D_01EA2970);
    func_00130C20(D_0051A6A8, 0x94413FC035B0F871UL);   // [C] the same 64-bit id func_00135280 passes
    D_0051BAA5 = 1;
    D_0051BAA8 = 0;
    return 1;
}
