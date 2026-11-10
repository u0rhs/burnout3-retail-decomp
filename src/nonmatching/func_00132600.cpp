// NONMATCHING: func_00132600 -- retail 734 / ours 701 instructions, 318 in changed runs
// gaps1: hand-drafted from the asm (main loop)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x132600..0x133174) with the Ghidra aid; every branch, call and
// store of the 734 instructions accounted for. The game's per-frame update, called forever from func_0012EB30 (boot,
// 0x12ECE0) with a0 = &D_004EE040 [C]; port docs/frame-rate.md section 1. State 5 = in game: N (field_2DA84) fixed
// 1/60 s ticks per rendered frame, N decided by func_00376570 ([L] CGtFramerateManager::UpdatePostRenderWait) at the end
// of the previous frame. Names: asm labels only (retail_names.csv has no row for 0x132600).
// TRACK: clean
// EQUIV: [L] written from the asm: the 13-way switch (jtbl_004B5C30; 0, 2, 3 = default), the case 10 -> 11 and 12 -> 4
// fall-throughs, the state-4 entry into the state-5 body, the tick loop's two exits; calls in retail's order

struct UnkStruct_00132600_gm {
    // [C] slots 0x74 / 0x78 called with a0 = the object (0x132CCC, 0x133100)
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78();
};
struct UnkStruct_00132600_st {
    unsigned char pad_0[0x1B0];
    // [C] the vtable pointer sits at +0x1B0 (MWCC places it where the first virtual is declared): slots 0x10, 0x14,
    // 0x18, 0x1C are called with a0 = the stage itself (0x132EA0, 0x132F9C, 0x1328E8, 0x132C50)
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C();
    UnkStruct_00132600_gm * field_1B4;   // [C] lw 0x1B4, null-tested before its virtual calls
    unsigned char pad_1B8[0x4];
    unsigned char field_1BC;             // [C] sb 1 when the stage is released (states 8, 10)
};
struct UnkStruct_00132600_game {
    unsigned char pad_0[0x7040];
    unsigned char field_7040[0x1C];  // [C] a CGtTimer (Update__8CGtTimerFv a0, the game timer)
    float field_705C;  // [C] lwc1, added to D_004E25DC->field_18 every frame
    unsigned char pad_7060[0x20];
    unsigned char field_7080[0x10];  // [C] a0 of func_0022B8E0 / func_00214050 ([L] the input manager, frame-rate.md)
    unsigned char pad_7090[0x1030];
    unsigned char field_80C0[0x10];  // [C] a CAsyncLoadManager (Update__17CAsyncLoadManagerFv a0)
    unsigned char pad_80D0[0x20CE0];
    unsigned char field_28DB0[0x24];  // [C] a0 of func_00135AA0
    unsigned char field_28DD4[0x24];  // [C] a0 of func_00135AA0
    unsigned char pad_28DF8[0xBAE];
    unsigned char field_299A6;  // [C] sb zero after PresentDrawBuffer
    unsigned char pad_299A7[0xBAF];
    unsigned char field_2A556;  // [C] sb zero after PresentDrawBuffer
    unsigned char pad_2A557[0xE9];
    int field_2A640;  // [C] per-frame RNG stir state (frame-rate.md: 0x518680)
    int field_2A644;
    unsigned char pad_2A648[0x33C8];
    unsigned char field_2DA10[0x28];  // [C] a CGtFramerateManager (Prepare__19CGtFramerateManagerFv a0)
    int field_2DA38;  // [C] the tick index the loop stopped at when field_2DA58 was set
    unsigned char pad_2DA3C[0xC];
    UnkStruct_00132600_st * field_2DA48;  // [C] the current stage (vptr at +0x1B0); [L] gGame +0x2DA48 = the current logic
    UnkStruct_00132600_st * field_2DA4C;  // [C] the next stage, moved into field_2DA48
    unsigned char pad_2DA50[0x4];
    int field_2DA54;  // [C] set to -1 on stage switches; -1 = none
    int field_2DA58;
    int field_2DA5C;
    unsigned char pad_2DA60[0x4];
    unsigned char field_2DA64;  // [C] func_0019A950(&D_00522660)'s result; [G] the world is ready
    unsigned char field_2DA65;
    unsigned char field_2DA66;  // [C] half rate: UpdatePostRenderWait(2, 8) instead of (1, 4) (frame-rate.md)
    unsigned char pad_2DA67[0x1];
    int field_2DA68;  // [C] frame-rate mode, used when field_2DA6C == 3
    int field_2DA6C;
    unsigned char pad_2DA70[0x14];
    int field_2DA84;  // [C] N: simulation ticks to run this frame
    unsigned char pad_2DA88[0x4];
    int field_2DA8C;  // [C] the next state
    int field_2DA90;  // [C] the state (switch 0..12, jtbl_004B5C30)
    unsigned char field_2DA94;
    unsigned char field_2DA95;  // [C] request: clear field_2DA94
    unsigned char field_2DA96;  // [C] request: set field_2DA94
};

struct UnkStruct_00132600_fsm {
    // [C] D_01EA2970 is a CGtFSM (GetStateFromID__6CGtFSMFUl's a0 in func_0036B0A0); slot 0x10 called with a0 = it
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10();
};
struct UnkStruct_00132600_d25dc { unsigned char pad_0[0x18]; float field_18; };

extern unsigned char D_004EB1E0;         // [C] the CB3DebugManager object; its first byte is also read as a flag
extern unsigned char D_0051BAD4;
extern unsigned char D_01E65489;
extern unsigned char D_01E91C3D;
extern unsigned char D_00522660[];       // [C] the CB3World (Release__8CB3WorldFv a0) and a CGtTimer (Update__8CGtTimerFv a0)
extern unsigned char D_00665EC0[];       // [C] the CB3GraphicsManager (OpenViewport / PresentDrawBuffer a0)
extern unsigned char D_01E90240[];       // [C] the CB3MenuPageManager
extern unsigned char D_01E32AE0[];       // [C] the CB3NetworkManager
extern unsigned char D_01E75640[];       // [C] a0 of func_0028AEB0 / func_0028B160 (CGtSoundManager in their sources)
extern unsigned char D_01ECDE90[];
extern unsigned char theMemMgr[];
extern UnkStruct_00132600_fsm D_01EA2970;
extern UnkStruct_00132600_d25dc * D_004E25DC;   // [C] gp-relative pointer
extern int D_004E2A14;                   // [C] gp-relative tick counter, +1 per simulation tick

extern "C" void UpdateStartOfFrame__15CB3DebugManagerFv(void *);
extern "C" void Update__15CB3DebugManagerFv(void *);
extern "C" void Update__17CAsyncLoadManagerFv(void *);
extern "C" void Update__19CB3MemoryManagerPS2Fv(void *);
extern "C" int func_00222C90(void *);    // [C] returns guFrameCount (gp); a0 unused
extern "C" void Update__19CGtHiResSystemTimerFi(int);
extern "C" void CheckPowerOff__7CB3GameFv(void *);
extern "C" void func_001D3D20(void);     // [L] CGtTimer::NextFrame (E map, frame-rate.md)
extern "C" void Update__8CGtTimerFv(void *);
extern "C" void Update__18CB3MenuPageManagerFv(void *);
extern "C" void Render__18CB3MenuPageManagerFv(void *);
extern "C" int func_001322B0(void *);    // [C] returns 0 / 1
extern "C" void func_0022B8E0(void *);
extern "C" void func_00214050(void *);
extern "C" void Release__8CB3WorldFv(void *);
extern "C" void func_0028AEB0(void *);
extern "C" void func_0028B160(void *);
extern "C" unsigned char func_0019A950(void *);
extern "C" void func_0019A550(void *);
extern "C" void Update__17CB3NetworkManagerFv(void *);
extern "C" void func_00270E10(void *);
extern "C" void func_00131B90(void *);
extern "C" void Prepare__19CGtFramerateManagerFv(void *);
extern "C" void func_0030EB10(void *);
extern "C" void UpdatePreSimulation__7CB3GameFv(void *);
extern "C" void func_003767B0(void *, int, int);
extern "C" void func_00135AA0(void *);
extern "C" void func_00131F90(void *);   // [L] CB3Game::UpdatePostSimulation (frame-rate.md)
extern "C" void func_001F43B0(void);
extern "C" int func_00376570(void *, int, int);   // [L] CGtFramerateManager::UpdatePostRenderWait(min, max)
extern "C" void Update__22CB3GraphicsManagerBaseFv(void *);
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void func_00438F30(void *);
extern "C" void func_00130970(void *);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void PresentDrawBuffer__18CB3GraphicsManagerFv(void *);

// [G] the four-call simulation-tick prologue every state runs (11 copies in retail: an inline or a macro)
static inline void func_00132600_inl1(UnkStruct_00132600_game * self)
{
    func_001D3D20();
    D_004E2A14++;
    Update__8CGtTimerFv(self->field_7040);
    Update__8CGtTimerFv(D_00522660);
}

// [G] the menu / front-end update that follows the tick in the non-race states
static inline void func_00132600_inl2()
{
    ((UnkStruct_00132600_fsm *)&D_01EA2970)->vfunc_10();   // through the pointer: a virtual call, as retail
    Update__18CB3MenuPageManagerFv(D_01E90240);
}

// states 7, 9, 11: wait for func_001322B0, then go to `next`
static inline void func_00132600_inl3(UnkStruct_00132600_game * self, int next)
{
    func_00132600_inl1(self);
    bool done = false;
    if (func_001322B0(self) != 0) {
        done = true;
    } else {
        D_01E91C3D = 1;
    }
    func_00132600_inl2();
    if (done) {
        self->field_2DA8C = next;
        self->field_2DA90 = next;
    }
}

// 0x00132600
extern "C" void func_00132600(UnkStruct_00132600_game * self)
{
    self->field_2A640 = (self->field_2A640 << 16) + (self->field_2A640 >> 16);   // sll / sra: arithmetic shift
    self->field_2A640 = self->field_2A640 + self->field_2A644;
    self->field_2A644 = self->field_2A644 + self->field_2A640;
    UpdateStartOfFrame__15CB3DebugManagerFv(&D_004EB1E0);
    if (self->field_2DA95 != 0) {
        self->field_2DA94 = 0;
    } else if (self->field_2DA96 != 0) {
        self->field_2DA94 = 1;
    }
    self->field_2DA95 = 0;
    self->field_2DA96 = 0;
    if ((D_0051BAD4 != 0 && D_004EB1E0 != 0) && self->field_2DA90 != self->field_2DA8C) {
        self->field_2DA90 = self->field_2DA8C;
    }
    Update__17CAsyncLoadManagerFv(self->field_80C0);
    Update__19CB3MemoryManagerPS2Fv(theMemMgr);
    Update__19CGtHiResSystemTimerFi(func_00222C90(D_00665EC0));
    CheckPowerOff__7CB3GameFv(self);
    D_004E25DC->field_18 = D_004E25DC->field_18 + self->field_705C;

    switch (self->field_2DA90) {
    case 1:
        func_00132600_inl1(self);
        D_01E91C3D = 1;
        self->field_2DA48 = self->field_2DA4C;
        self->field_2DA4C = 0;
        func_00132600_inl2();
        self->field_2DA8C = 7;
        break;
    case 6:
        func_00132600_inl1(self);
        D_01E91C3D = 1;
        self->field_2DA54 = -1;
        self->field_2DA58 = -1;
        self->field_2DA5C = -1;
        if (D_01E65489 == 0) {
            func_0022B8E0(self->field_7080);
            func_00214050(self->field_7080);
        }
        Release__8CB3WorldFv(D_00522660);
        self->field_2DA64 = 0;
        self->field_2DA48->vfunc_18();
        self->field_2DA48 = self->field_2DA4C;
        self->field_2DA4C = 0;
        self->field_2DA66 = 0;
        self->field_2DA65 = 0;
        func_00132600_inl2();
        self->field_2DA8C = 7;
        break;
    case 7:
        func_00132600_inl3(self, 4);
        break;
    case 8:
        func_00132600_inl1(self);
        D_01E91C3D = 1;
        self->field_2DA54 = -1;
        self->field_2DA58 = -1;
        self->field_2DA5C = -1;
        func_0022B8E0(self->field_7080);
        func_0028AEB0(D_01E75640);
        Release__8CB3WorldFv(D_00522660);
        self->field_2DA64 = 0;
        self->field_2DA48->field_1BC = 1;
        self->field_2DA8C = 9;
        self->field_2DA90 = 9;
        break;
    case 9:
        func_00132600_inl3(self, 4);
        break;
    case 10:
        // no tick here; falls into state 11
        self->field_2DA54 = -1;
        self->field_2DA58 = -1;
        self->field_2DA5C = -1;
        func_0022B8E0(self->field_7080);
        func_0028AEB0(D_01E75640);
        Release__8CB3WorldFv(D_00522660);
        self->field_2DA64 = 0;
        self->field_2DA48->field_1BC = 1;
        self->field_2DA8C = 11;
        self->field_2DA90 = 11;
        // fall through
    case 11:
        func_00132600_inl3(self, 12);
        break;
    case 12:
        self->field_2DA48->vfunc_1C();
        self->field_2DA8C = 4;
        self->field_2DA90 = 4;
        // fall through
    case 4:
        self->field_2DA64 = func_0019A950(D_00522660);
        if (self->field_2DA64 == 0) {
            // not ready yet: one tick of the loading screen
            func_00132600_inl1(self);
            D_01E91C3D = 1;
            func_00132600_inl2();
            if (D_01E65489 == 0) {
                func_0022B8E0(self->field_7080);
                func_00214050(self->field_7080);
            }
            func_0028B160(D_01E75640);
            Update__17CB3NetworkManagerFv(D_01E32AE0);
            if (self->field_2DA48->field_1B4 != 0) {
                self->field_2DA48->field_1B4->vfunc_78();
            }
            func_00270E10(D_01E32AE0);
            func_00131B90(self);
            break;
        }
        if (self->field_2DA48 != 0 && self->field_2DA48->field_1B4 != 0) {
            self->field_2DA48->field_1B4->vfunc_74();
        }
        Prepare__19CGtFramerateManagerFv(self->field_2DA10);
        self->field_2DA8C = 5;
        self->field_2DA90 = 5;
        func_0030EB10(&D_01EA2970);
        // fall through
    case 5: {
        UpdatePreSimulation__7CB3GameFv(self);
        int mode = self->field_2DA6C;
        if (mode == 3) {
            mode = self->field_2DA68;
        }
        if (self->field_2DA54 == -1 && (D_0051BAD4 != 0 && D_004EB1E0 != 0)) {
            func_003767B0(self->field_2DA10, mode, 0);
        } else {
            func_003767B0(self->field_2DA10, mode, 1);
        }
        for (int i = 0; i < self->field_2DA84; i++) {
            if (self->field_2DA58 != -1) {
                self->field_2DA38 = i;
                break;
            }
            func_00132600_inl1(self);
            if (D_01E65489 == 0) {
                func_00214050(self->field_7080);
            }
            func_00135AA0(self->field_28DB0);
            func_00135AA0(self->field_28DD4);
            Update__15CB3DebugManagerFv(&D_004EB1E0);
            if (self->field_2DA54 == -1 && D_004EB1E0 != 0) {
                Update__17CB3NetworkManagerFv(D_01E32AE0);
                if (D_0051BAD4 != 0 && D_004EB1E0 != 0) {
                    func_0019A550(D_00522660);
                }
                self->field_2DA48->vfunc_10();     // [L] the stage's simulation (CB3OnePlayerStage::Update 0x135180 ...)
                func_00270E10(D_01E32AE0);
                func_00131B90(self);
            }
            if (D_004EB1E0 != 0) {
                ((UnkStruct_00132600_fsm *)&D_01EA2970)->vfunc_10();
            }
            Update__18CB3MenuPageManagerFv(D_01E90240);
            if (self->field_2DA8C != 5) {
                break;
            }
        }
        func_00131F90(self);
        func_001F43B0();
        if (self->field_2DA66 != 0) {
            self->field_2DA84 = func_00376570(self->field_2DA10, 2, 8);
        } else {
            self->field_2DA84 = func_00376570(self->field_2DA10, 1, 4);
        }
        Update__22CB3GraphicsManagerBaseFv(D_00665EC0);
        self->field_2DA48->vfunc_14();
        break;
    }
    default:   // 0, 2, 3 and >= 13
        break;
    }
    OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(D_00665EC0, 0);
    Render__18CB3MenuPageManagerFv(D_01E90240);
    func_00438F30(D_01ECDE90);
    func_00130970(&D_004EB1E0);
    CloseViewport__22CB3GraphicsManagerBaseFv(D_00665EC0);
    PresentDrawBuffer__18CB3GraphicsManagerFv(D_00665EC0);
    self->field_299A6 = 0;
    self->field_2A556 = 0;
}
