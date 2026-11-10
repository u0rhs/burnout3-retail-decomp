// NONMATCHING: Construct__7CB3GameFv -- retail 425 / ours 415 instructions, 30 in changed runs
// gaps1: hand-drafted from the asm (CB3Game::Construct)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x133BB0..0x134250) with the Ghidra aid. [L] CB3Game::Construct
// (retail_names.csv medium, B3Game.cpp); called from func_0012EB30 (boot) with a0 = &D_004EE040 [C 0x12EB64]. Resets
// the game object's flags, seeds the per-frame RNG stir, constructs the hardware, timers (60 Hz NTSC / 50 Hz PAL by
// D_004E2910), framerate manager, memory manager and every subsystem, calls slot 8 of 24 embedded objects (5 with the
// vptr at +0x1B0), and leaves func_00133190's state at 1 and the main loop's at 0.
// TRACK: clean
// EQUIV: [L] written from the asm: every store (offset, width, value), call and argument in retail's order; the 24
// virtual calls in retail's object order (0x2D47C before 0x2D424)

struct UnkStruct_00133BB0_st {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8();   // [C] lw t9, 0x1B0(a0); lw t9, 0x8(t9), a0 = the object
};
struct UnkStruct_00133BB0_ob {
    virtual void vfunc_8();   // [C] lw t9, 0x0(a0); lw t9, 0x8(t9), a0 = the object
};
struct UnkStruct_00133BB0_game {
    unsigned char pad_0[0x7000];
    unsigned char field_7000[0x40];  // [C] a0 of func_0021B770
    unsigned char field_7040[0x40];  // [C] the game CGtTimer (Construct__8CGtTimerFv a0; D_004F5080 by absolute address)
    unsigned char pad_7080[0x1040];
    unsigned char field_80C0[0x794];  // [C] the CAsyncLoadManager (Init a0)
    unsigned char field_8854[0xC];  // [C] a0 of func_0013C890
    unsigned char field_8860[0x10];  // [C] a0 of Construct__Q27GtComms16CGtCommsToolBaseFPCc (the GtComms tool, func_00133190)
    unsigned char pad_8870[0x20540];
    unsigned char field_28DB0[0x24];  // [C] CB3Player 0 (func_00135B40(.., 0))
    unsigned char field_28DD4[0x2C];  // [C] CB3Player 1 (func_00135B40(.., 1))
    unsigned char field_28E00[0xBB0];  // [C] CB3PlayerCameraManager 0
    unsigned char field_299B0[0x10];  // [C] CB3PlayerCameraManager 1
    unsigned char pad_299C0[0xC80];
    int field_2A640;  // [C] RNG stir state seeds (func_00132600)
    int field_2A644;
    void * field_2A648;
    bool field_2A64C;
    unsigned char pad_2A64D[0x7];
    bool field_2A654;
    bool field_2A655;
    unsigned char pad_2A656[0xE];
    int field_2A664;  // [C] sw zero: first word of the pveh/vlist.bin buffer (0x2A660) + 4
    unsigned char pad_2A668[0xFFC];
    int field_2B664;  // [C] sw zero: Tracks/tlist.bin buffer (0x2B660) + 4
    unsigned char pad_2B668[0xFF8];
    bool field_2C660;
    bool field_2C661;
    unsigned char field_2C662;
    unsigned char pad_2C663[0x5];
    unsigned char field_2C668[0x1B4];  // [C] an object with its vptr at +0x1B0 (a stage)
    unsigned char pad_2C81C[0x184];
    unsigned char field_2C9A0[0x1B4];  // [C] an object with its vptr at +0x1B0 (a stage)
    unsigned char pad_2CB54[0x16C];
    unsigned char field_2CCC0[0x1B4];  // [C] an object with its vptr at +0x1B0 (a stage)
    unsigned char pad_2CE74[0xC];
    unsigned char field_2CE80[0x1B4];  // [C] an object with its vptr at +0x1B0 (a stage)
    unsigned char pad_2D034[0x14];
    unsigned char field_2D048[0x1B4];  // [C] an object with its vptr at +0x1B0 (a stage)
    unsigned char pad_2D1FC[0x1C];
    unsigned char field_2D218[0x4];
    unsigned char pad_2D21C[0x48];
    unsigned char field_2D264[0x4];
    unsigned char pad_2D268[0x48];
    unsigned char field_2D2B0[0x4];
    unsigned char pad_2D2B4[0x4C];
    unsigned char field_2D300[0x4];
    unsigned char pad_2D304[0x70];
    unsigned char field_2D374[0x4];
    unsigned char pad_2D378[0x54];
    unsigned char field_2D3CC[0x4];
    unsigned char pad_2D3D0[0x54];
    unsigned char field_2D424[0x4];
    unsigned char pad_2D428[0x54];
    unsigned char field_2D47C[0x4];
    unsigned char pad_2D480[0x54];
    unsigned char field_2D4D4[0x4];
    unsigned char pad_2D4D8[0x54];
    unsigned char field_2D52C[0x4];
    unsigned char pad_2D530[0x48];
    unsigned char field_2D578[0x4];
    unsigned char pad_2D57C[0x70];
    unsigned char field_2D5EC[0x4];
    unsigned char pad_2D5F0[0x60];
    unsigned char field_2D650[0x4];
    unsigned char pad_2D654[0x80];
    unsigned char field_2D6D4[0x4];
    unsigned char pad_2D6D8[0x70];
    unsigned char field_2D748[0x4];
    unsigned char pad_2D74C[0x70];
    unsigned char field_2D7BC[0x4];
    unsigned char pad_2D7C0[0x120];
    unsigned char field_2D8E0[0x4];
    unsigned char pad_2D8E4[0x4];
    unsigned char field_2D8E8[0x4];
    unsigned char pad_2D8EC[0x5C];
    unsigned char field_2D948[0x4];
    unsigned char pad_2D94C[0xB4];
    unsigned char field_2DA00;
    unsigned char pad_2DA01[0x3];
    unsigned char field_2DA04[0x4];  // [C] CB3Strings (func_00271A50 a0)
    unsigned char field_2DA08[0x4];
    unsigned char pad_2DA0C[0x4];
    unsigned char field_2DA10[0x28];  // [C] the CGtFramerateManager
    unsigned char pad_2DA38[0x10];
    void * field_2DA48;
    void * field_2DA4C;
    unsigned char field_2DA50;  // [C] = D_0051BA90, the quit flag func_0012EB30 polls
    unsigned char pad_2DA51[0x3];
    int field_2DA54;
    int field_2DA58;
    int field_2DA5C;
    int field_2DA60;  // [C] func_00133190's state: 1
    unsigned char field_2DA64;
    unsigned char pad_2DA65[0xB];
    int field_2DA70;
    void * field_2DA74;
    void * field_2DA78;
    unsigned char pad_2DA7C[0x4];
    unsigned char field_2DA80;  // [C] power-off flags (B3GamePS2_001D4020: field_2DA80 / 2DA81)
    unsigned char field_2DA81;
    unsigned char field_2DA82;
    unsigned char pad_2DA83[0x9];
    int field_2DA8C;
    int field_2DA90;
    unsigned char field_2DA94;
    unsigned char field_2DA95;
    unsigned char field_2DA96;
};

extern unsigned char theMemMgr[];
extern unsigned char D_00665EC0[];
extern unsigned char D_004EB1E0[];
extern unsigned char D_01E32AE0[];
extern unsigned char D_00522660[];
extern unsigned char D_01E90240[];
extern unsigned char D_01ECDE90[];
extern unsigned char D_01EA2970[];        // [C] the CB3MenuFlowFSM
extern unsigned char D_004F5080[];        // [C] = D_004EE040 + 0x7040, the game timer by absolute address
extern unsigned char D_0051BB00[];
extern unsigned char D_01EA7810[];
extern unsigned char D_01ECD520[];        // [C] the CB3MemCardController
extern unsigned char D_01EA4070[];
extern unsigned char D_01E86560[];        // [C] the CB3CPUMonitors (Construct a0)
extern int D_01E86564, D_01E86568, D_01E8656C, D_01E86570, D_01E86574, D_01E86578, D_01E8657C, D_01E86580,
    D_01E86584, D_01E86588;
extern signed char D_004E2910;            // [C] gp-relative, lb: nonzero = PAL ([L] 50 Hz timer services)
extern float D_004E1118;                  // [C] gp-relative float (frame-rate.md: the 16.667 ms period)

extern "C" void ConstructHardware__7CB3GameFv(void *);
extern "C" void PreparePowerOff__7CB3GameFv(void *);
extern "C" void CheckPowerOff__7CB3GameFv(void *);
extern "C" int func_002372F0(void);       // [C] j GetThreadId
extern "C" void EnableVBlankWait__12CGtThreadMgrFv(void);
extern "C" void Construct__19CB3MemoryManagerPS2Fv(void *);
extern "C" void func_0021B770(void *);
extern "C" void Construct__19CGtHiResSystemTimerFv(void);
extern "C" int PrepareTimerServices__8CGtTimerFi(int);
extern "C" void Construct__19CGtFramerateManagerFff(void *, float, float);
extern "C" void Construct__8CGtTimerFv(void *);
extern "C" int func_002B6C30();
extern "C" void Construct__14CB3CPUMonitorsFv(void *);
extern "C" void func_00371B90(void *);
extern "C" void func_00271A50(void *);
extern "C" void Init__17CAsyncLoadManagerFv(void *);
extern "C" void func_00228160(void *);
extern "C" void Construct__15CB3DebugManagerFv(void *);
extern "C" void Construct__17CB3NetworkManagerFv(void *);
extern "C" void Construct__8CB3WorldFv(void *);
extern "C" void func_0013C890(void *);
extern "C" void Construct__18CB3MenuPageManagerFv(void *);
extern "C" void func_00439280(void *);
extern "C" const void * GetOffsetTable__14CB3MenuFlowFSMFv(void *);
extern "C" void Construct__14CB3MenuFlowFSMFPvPC14CGtStateOffsetP8CGtTimer(void *, void *, const void *, void *);
extern "C" void func_00136E00(void *);
extern "C" void func_003D14F0(void *);
extern "C" void Construct__20CB3MemCardControllerFv(void *);
extern "C" void Construct__Q27GtComms16CGtCommsToolBaseFPCc(void *, int);
extern "C" void func_00135B40(void *, int);
extern "C" void Construct__22CB3PlayerCameraManagerFi(void *, int);

// 0x00133BB0
extern "C" void Construct__7CB3GameFv(UnkStruct_00133BB0_game * self)
{
    self->field_2DA81 = 0;
    self->field_2DA80 = 0;
    self->field_2DA94 = 1;
    self->field_2DA95 = 0;
    self->field_2DA96 = 0;
    self->field_2DA00 = 1;
    self->field_2A64C = false;
    self->field_2A648 = 0;
    self->field_2A654 = false;
    self->field_2A655 = false;
    self->field_2A664 = 0;
    self->field_2C660 = false;
    self->field_2B664 = 0;
    self->field_2C661 = false;
    self->field_2DA82 = 0;
    self->field_2A644 = 0x2B9D6F8;
    self->field_2A640 = (int)0xFD462907;
    ConstructHardware__7CB3GameFv(self);
    PreparePowerOff__7CB3GameFv(self);
    CheckPowerOff__7CB3GameFv(self);
    func_002372F0();
    EnableVBlankWait__12CGtThreadMgrFv();
    Construct__19CB3MemoryManagerPS2Fv(theMemMgr);
    func_0021B770(self->field_7000);
    Construct__19CGtHiResSystemTimerFv();
    if (D_004E2910 != 0) {
        PrepareTimerServices__8CGtTimerFi(50);
        Construct__19CGtFramerateManagerFff(self->field_2DA10, 20.0f, 0.0f);   // [C] 0x41A00000 = 20 ms
    } else {
        PrepareTimerServices__8CGtTimerFi(60);
        Construct__19CGtFramerateManagerFff(self->field_2DA10, D_004E1118, 0.0f);
    }
    Construct__8CGtTimerFv(self->field_7040);
    func_002B6C30();
    Construct__14CB3CPUMonitorsFv(D_01E86560);
    *(int *)D_01E86560 = 0;
    D_01E86570 = 0;
    D_01E86564 = 0;
    D_01E86584 = 0;
    D_01E86568 = 0;
    D_01E8656C = 0;
    D_01E86574 = 0;
    D_01E86578 = 0;
    D_01E8657C = 0;
    D_01E86580 = 0;
    D_01E86588 = 0;
    func_00371B90(D_01EA4070);
    func_00271A50(self->field_2DA04);
    func_00271A50(self->field_2DA08);
    Init__17CAsyncLoadManagerFv(self->field_80C0);
    func_00228160(D_00665EC0);
    Construct__15CB3DebugManagerFv(D_004EB1E0);
    Construct__17CB3NetworkManagerFv(D_01E32AE0);
    Construct__8CB3WorldFv(D_00522660);
    func_0013C890(self->field_8854);
    Construct__18CB3MenuPageManagerFv(D_01E90240);
    func_00439280(D_01ECDE90);
    Construct__14CB3MenuFlowFSMFPvPC14CGtStateOffsetP8CGtTimer(D_01EA2970, self, GetOffsetTable__14CB3MenuFlowFSMFv(D_01EA2970),
                                                                D_004F5080);
    func_00136E00(D_0051BB00);
    func_003D14F0(D_01EA7810);
    Construct__20CB3MemCardControllerFv(D_01ECD520);
    Construct__Q27GtComms16CGtCommsToolBaseFPCc(self->field_8860, 0);
    self->field_2DA50 = 0;
    self->field_2DA48 = 0;
    self->field_2DA4C = 0;
    self->field_2A648 = 0;
    ((UnkStruct_00133BB0_st *)self->field_2C668)->vfunc_8();
    ((UnkStruct_00133BB0_st *)self->field_2C9A0)->vfunc_8();
    ((UnkStruct_00133BB0_st *)self->field_2CCC0)->vfunc_8();
    ((UnkStruct_00133BB0_st *)self->field_2CE80)->vfunc_8();
    ((UnkStruct_00133BB0_st *)self->field_2D048)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D218)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D264)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D2B0)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D300)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D374)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D3CC)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D47C)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D424)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D4D4)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D52C)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D578)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D5EC)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D650)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D6D4)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D748)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D7BC)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D8E0)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D8E8)->vfunc_8();
    ((UnkStruct_00133BB0_ob *)self->field_2D948)->vfunc_8();
    func_00135B40(self->field_28DB0, 0);
    func_00135B40(self->field_28DD4, 1);
    Construct__22CB3PlayerCameraManagerFi(self->field_28E00, 0);
    Construct__22CB3PlayerCameraManagerFi(self->field_299B0, 1);
    self->field_2DA58 = -1;
    self->field_2DA5C = -1;
    self->field_2DA54 = -1;
    self->field_2DA64 = 0;
    self->field_2C662 = 0;
    self->field_2DA60 = 1;
    self->field_2DA70 = 1;
    self->field_2DA74 = 0;
    self->field_2DA78 = 0;
    self->field_2DA90 = 0;
    self->field_2DA8C = 0;
}
