// NONMATCHING: func_00133190 -- retail 648 / ours 628 instructions, 153 in changed runs
// gaps1: hand-drafted from the asm (staged start-up). behaviour_audit total 4 (threshold), checked: MWCC folds the separator switch on the constant 1 that retail compares at run time (0x1338E4..0x133930: always ',' '.'); the ustrSetSeparators arg-source phis and the eq(#1,#k) conds are that fold, not a behaviour difference
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x133190..0x133BAC) with the Ghidra aid. The game's staged start-up:
// func_0012EB30 (boot) calls it once per frame until it returns nonzero [C 0x12ECA4]; each call advances the state
// field_2DA60 through the hardware prepare, the memory device, the async loads (Data/Global.txd, the strings files,
// pveh/vlist.bin, Tracks/tlist.bin, Data/PrgData.bin, Data/EALogin.ico, Data/saveicon.icn) and the subsystems' Prepare
// calls, returning 0 while a load is pending or a Prepare refuses, then sets up timers, players, tuning variables and the
// main loop's first state (field_2DA90 = 1) and returns 1. a0 = &D_004EE040 (the CB3Game). Names: asm labels only.
// TRACK: clean
// EQUIV: [L] written from the asm: the compare-chain dispatch (1 and 0x18 share an entry, unlisted states go to the final
// set-up), every state's fall-through into the next, each early return 0, the separator switch on the value 1 kept

struct UnkStruct_00133190_pdh { unsigned char pad_0[0x4]; int field_4; };
struct UnkStruct_00133190_pd { unsigned char pad_0[0x4]; UnkStruct_00133190_pdh * field_4; };
struct UnkStruct_00133190_dict { unsigned char pad_0[0x8]; int field_8; };   // [C] lw 0x8: the texture count
struct UnkStruct_00133190_game {
    unsigned char field_0[0x3000];  // [C] zeroed, then Data/EALogin.ico is loaded into it (state 11)
    unsigned char field_3000[0x4000];  // [C] zeroed, then Data/saveicon.icn (state 14)
    unsigned char field_7000[0x40];  // [C] a0 of func_0021B5E0 / func_0021B4E0
    unsigned char field_7040[0x40];  // [C] a CGtTimer (Prepare / Start__8CGtTimerFv)
    unsigned char field_7080[0x1000];  // [C] a0 of func_0022B8E0
    void * field_8080;  // [C] the CGTFileSystem passed to CGtCommsToolBase::Prepare
    unsigned char pad_8084[0x3C];
    unsigned char field_80C0[0x7A0];  // [C] the CAsyncLoadManager (Update / QueueLoadRequest a0)
    unsigned char field_8860[0x10];  // [C] a GtComms::CGtCommsToolBase (Prepare a0)
    unsigned char pad_8870[0x20540];
    unsigned char field_28DB0[0x4];  // [C] a CB3Player (Prepare__9CB3PlayerFv a0)
    unsigned short field_28DB4[0x10];  // [C] CopyN__10CGtUnicodeFPUsiPCUs(.., 9, ..) target: the player's name
    unsigned char field_28DD4[0x4];  // [C] the second CB3Player
    unsigned short field_28DD8[0x10];
    unsigned char pad_28DF8[0x1768];
    unsigned char field_2A560[0x10];  // [C] a CMemoryDevicePS2 (Init__16CMemoryDevicePS2Fv a0)
    unsigned char pad_2A570[0xD8];
    void * field_2A648;  // [C] memory block 0xE: Data/Global.txd (a CGtDictionaryBase, FixUp)
    bool field_2A64C;  // [C] load-done flags (QueueLoadRequest's bool *)
    unsigned char pad_2A64D[0x3];
    UnkStruct_00133190_pd * field_2A650;  // [C] the progression data (Fixup__24CB3ProgressionDataStructFUi a0)
    bool field_2A654;
    bool field_2A655;
    bool field_2A656;
    bool field_2A657;
    bool field_2A658;
    unsigned char pad_2A659[0x7];
    unsigned char field_2A660[0x1000];  // [C] pveh/vlist.bin, 0x1000 bytes
    unsigned char field_2B660[0x1000];  // [C] Tracks/tlist.bin, 0x1000 bytes
    bool field_2C660;
    bool field_2C661;
    unsigned char field_2C662;  // [C] set to 1 after the memory device Init
    unsigned char pad_2C663[0x5];
    unsigned char field_2C668[0x10];  // [C] its address becomes the next stage (field_2DA4C)
    unsigned char pad_2C678[0x138C];
    unsigned char field_2DA04[0x4];  // [C] a CB3Strings (Prepare__10CB3StringsFPvPCci a0)
    unsigned char field_2DA08[0x4];  // [C] a second CB3Strings
    unsigned char pad_2DA0C[0x40];
    void * field_2DA4C;  // [C] the next stage (func_00132600 moves it into field_2DA48)
    unsigned char pad_2DA50[0x4];
    int field_2DA54;
    int field_2DA58;
    int field_2DA5C;
    int field_2DA60;  // [C] this function's own state (1 / 0x18 .. 0x10, then 0x17)
    unsigned char field_2DA64;
    unsigned char field_2DA65;
    unsigned char field_2DA66;
    unsigned char pad_2DA67[0x1];
    int field_2DA68;  // [C] frame-rate mode, 1
    int field_2DA6C;  // [C] 3 (func_00132600 then uses field_2DA68)
    unsigned char pad_2DA70[0x4];
    void * field_2DA74;  // [C] memory block 0xA: the global strings file
    void * field_2DA78;  // [C] memory block 0xB: the head strings file
    void * field_2DA7C;  // [C] memory block 0xC: Data/PrgData.bin
    unsigned char pad_2DA80[0x4];
    int field_2DA84;  // [C] N, the first frame's tick count: 1
    unsigned char pad_2DA88[0x4];
    int field_2DA8C;  // [C] the main loop's next state: 1
    int field_2DA90;  // [C] the main loop's state: 1
};

extern unsigned char theMemMgr[];
extern unsigned char D_004F6100[];        // [C] = D_004EE040 + 0x80C0, the game's CAsyncLoadManager by absolute address
extern unsigned char D_00665EC0[];        // [C] the CB3GraphicsManager
extern unsigned char D_004EB1E0[];        // [C] the CB3DebugManager
extern unsigned char D_01E90240[];        // [C] the CB3MenuPageManager
extern unsigned char D_01ECDE90[];
extern unsigned char D_0051BA44[];        // [C] a0 of func_00271A00 ([L] CB3Strings::GetString, DNAT)
extern unsigned char D_0051BB00[];
extern unsigned char D_01EA7810[];
extern unsigned char D_01EA4070[];
extern unsigned char D_01E75640[];
extern unsigned char D_01E754E0[];        // [C] the CB3AIAttribs (Register__12CB3AIAttribsFv a0)
extern unsigned char D_01E3C63C[];
extern int D_01E7751C;
extern signed char D_004E2910;            // [C] gp-relative, lb
extern int D_004E2918;                    // [C] gp-relative, set to 1 before the separator switch
extern const char * D_004B5BA8;           // [C] a pointer to the global strings file name (D_004B5B90)
extern const char * D_004B5C20;           // [C] a pointer to the head strings file name (D_004B5C10)
extern const char D_004B5C70[];           // "Data/Global.txd"
extern const char D_004B5C80[];           // "{696544B6-9CC9-46B6-BA03-7D504B677B28}"
extern const char D_004B5CB0[];           // "{3A4B53B4-7874-4C2F-BCFF-F1747E6B09D4}"
extern const char D_004B5CD8[];           // "pveh/vlist.bin"
extern const char D_004B5CF0[];           // "Data/EALogin.ico"
extern const char D_004B5D10[];           // "Data/saveicon.icn"
extern const char D_004B5D28[];           // "Data/vdb.xml"
extern const char D_004B5D40[];           // "Tracks/tlist.bin"
extern const char D_004B5D60[];           // "Data/PrgData.bin"

extern "C" void CheckPowerOff__7CB3GameFv(void *);
extern "C" void Update__17CAsyncLoadManagerFv(void *);
extern "C" int PrepareHardware__7CB3GameFv(void *);
extern "C" void Init__16CMemoryDevicePS2Fv(void *);
extern "C" void * AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" unsigned int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" int QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(void *, const char *, bool *, void *, unsigned int);
extern "C" void FixUp__17CGtDictionaryBaseFv(void *);
extern "C" void * func_00131AA0(void *, int);
extern "C" void FixUp__10CGtTextureFv(void *);
extern "C" void ustrSetSeparators(int, int);
extern "C" int Prepare__10CB3StringsFPvPCci(void *, void *, const char *, int);
extern "C" void Fixup__24CB3ProgressionDataStructFUi(void *, unsigned int);
extern "C" void func_003EA580(void);
extern "C" void Prepare__26CB3HardCodedCrashStageListFv(void);
extern "C" void func_003EB0A0(void);
extern "C" int Prepare__18CB3GraphicsManagerFv(void *);
extern "C" int func_001364B0(void *);
extern "C" int func_003D11D0(void *);
extern "C" void func_0028B580(void *);
extern "C" int func_0028B380(void *);
extern "C" int func_00371940(void *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int func_00222C90(void *);     // [C] returns guFrameCount; a0 unused
extern "C" int Prepare__19CGtHiResSystemTimerFbi(int, int);
extern "C" void Prepare__8CGtTimerFv(void *);
extern "C" void Start__8CGtTimerFv(void *);
extern "C" void Prepare__15CB3DebugManagerFv(void *);
extern "C" void Prepare__18CB3MenuPageManagerFv(void *);
extern "C" void func_00439110(void *);
extern "C" void Prepare__9CB3PlayerFv(void *);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" unsigned short * CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, const unsigned short *);
extern "C" void func_0022B8E0(void *);
extern "C" int Prepare__Q27GtComms16CGtCommsToolBaseFPCcP13CGTFileSystemPCc(void *, const char *, void *, const char *);
extern "C" void Register__12CB3AIAttribsFv(void *);
extern "C" void RegisterStaticVariables__8CB3ScoreFv(void);
extern "C" void RegisterStaticVariables__7CB3BurnFv(void);
extern "C" void func_00344310(void);
extern "C" void func_0021B5E0(void *);
extern "C" void func_0021B4E0(void *);

// 0x00133190
extern "C" int func_00133190(UnkStruct_00133190_game * self)
{
    CheckPowerOff__7CB3GameFv(self);
    Update__17CAsyncLoadManagerFv(self->field_80C0);
    switch (self->field_2DA60) {
    case 0x18:
    case 1:
        if (PrepareHardware__7CB3GameFv(self) == 0) {
            return 0;
        }
        Init__16CMemoryDevicePS2Fv(self->field_2A560);
        self->field_2C662 = 1;
        self->field_2DA60 = 2;
        // fall through
    case 2:
        self->field_2A648 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0xE, 0);
        if (self->field_2A648 == 0) {
            return 0;
        }
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(D_004F6100, D_004B5C70, &self->field_2A64C, self->field_2A648,
                                                        GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0xE));
        self->field_2DA60 = 3;
        // fall through
    case 3: {
        if (!self->field_2A64C) {
            return 0;
        }
        UnkStruct_00133190_dict * dict = (UnkStruct_00133190_dict *)self->field_2A648;
        FixUp__17CGtDictionaryBaseFv(dict);
        for (int i = 0; i < dict->field_8; i++) {
            FixUp__10CGtTextureFv(func_00131AA0(dict, i));
        }
        self->field_2DA74 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0xA, 0);
        self->field_2DA78 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0xB, 0);
        if (self->field_2DA74 == 0 || self->field_2DA78 == 0) {
            return 0;
        }
        const char * global = D_004B5BA8;
        const char * head = D_004B5C20;
        int n = 1;                            // [C] li v1, 1, stored and then compared (the compiler kept the switch)
        D_004E2918 = n;
        switch (n) {
        case 10:
        case 6:
        case 5:
            ustrSetSeparators('.', ',');
            break;
        case 4:
            ustrSetSeparators(' ', '.');
            break;
        default:
            ustrSetSeparators(',', '.');
            break;
        }
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(self->field_80C0, global, &self->field_2A654, self->field_2DA74,
                                                        GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0xA));
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(self->field_80C0, head, &self->field_2A655, self->field_2DA78,
                                                        GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0xB));
        self->field_2DA60 = 4;
    }
        // fall through
    case 4:
        if (!self->field_2A654 || !self->field_2A655) {
            return 0;
        }
        Prepare__10CB3StringsFPvPCci(self->field_2DA04, self->field_2DA74, D_004B5C80, 0xFA5);
        Prepare__10CB3StringsFPvPCci(self->field_2DA08, self->field_2DA78, D_004B5CB0, 10);
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(self->field_80C0, D_004B5CD8, &self->field_2C660, self->field_2A660,
                                                        0x1000);
        self->field_2DA60 = 5;
        // fall through
    case 5:
        if (!self->field_2C660) {
            return 0;
        }
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(self->field_80C0, D_004B5D40, &self->field_2C661, self->field_2B660,
                                                        0x1000);
        self->field_2DA60 = 6;
        // fall through
    case 6:
        if (!self->field_2C661) {
            return 0;
        }
        self->field_2DA7C = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0xC, 0);
        if (self->field_2DA7C == 0) {
            return 0;
        }
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(self->field_80C0, D_004B5D60, &self->field_2A656, self->field_2DA7C,
                                                        GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0xC));
        self->field_2DA60 = 7;
        // fall through
    case 7: {
        if (!self->field_2A656) {
            return 0;
        }
        self->field_2A650 = (UnkStruct_00133190_pd *)self->field_2DA7C;
        Fixup__24CB3ProgressionDataStructFUi(self->field_2A650, (unsigned int)self->field_2A650);   // [C] a1 = a0
        UnkStruct_00133190_pdh * h = self->field_2A650->field_4;
        if (h->field_4 >= 7) {
            h->field_4 = h->field_4 - 1;
        }
        func_003EA580();
        Prepare__26CB3HardCodedCrashStageListFv();
        func_003EB0A0();
        self->field_2DA60 = 8;
    }
        // fall through
    case 8:
        if (Prepare__18CB3GraphicsManagerFv(D_00665EC0) == 0) {
            return 0;
        }
        if (func_001364B0(D_0051BB00) == 0) {
            return 0;
        }
        if (func_003D11D0(D_01EA7810) == 0) {
            return 0;
        }
        self->field_2DA60 = 9;
        // fall through
    case 9:
        if (D_01E7751C <= 0) {
            func_0028B580(D_01E75640);
        }
        if (func_0028B380(D_01E75640) == 0) {
            return 0;
        }
        self->field_2DA60 = 10;
        // fall through
    case 10:
        self->field_2DA60 = 11;
        // fall through
    case 11:
        self->field_2A657 = false;
        memset(self->field_0, 0, 0x3000);
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(self->field_80C0, D_004B5CF0, &self->field_2A657, self->field_0, 0x3000);
        self->field_2DA60 = 12;
        // fall through
    case 12:
        if (!self->field_2A657) {
            return 0;
        }
        self->field_2DA60 = 13;
        // fall through
    case 13:
        if (func_00371940(D_01EA4070) == 0) {
            return 0;
        }
        self->field_2DA60 = 14;
        // fall through
    case 14:
        self->field_2A658 = false;
        memset(self->field_3000, 0, 0x4000);
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(self->field_80C0, D_004B5D10, &self->field_2A658, self->field_3000,
                                                        0x4000);
        self->field_2DA60 = 15;
        // fall through
    case 15:
        if (!self->field_2A658) {
            return 0;
        }
        self->field_2DA60 = 16;
        // fall through
    default:
        break;
    }
    // final set-up (also reached directly for any state not listed above)
    if (D_004E2910 != 0) {
        Prepare__19CGtHiResSystemTimerFbi(0, func_00222C90(D_00665EC0));
    } else {
        Prepare__19CGtHiResSystemTimerFbi(1, func_00222C90(D_00665EC0));
    }
    Prepare__8CGtTimerFv(self->field_7040);
    Start__8CGtTimerFv(self->field_7040);
    Prepare__15CB3DebugManagerFv(D_004EB1E0);
    Prepare__18CB3MenuPageManagerFv(D_01E90240);
    func_00439110(D_01ECDE90);
    Prepare__9CB3PlayerFv(self->field_28DB0);
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_28DB4, 9, func_00271A00(D_0051BA44, 0x1B9));
    Prepare__9CB3PlayerFv(self->field_28DD4);
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_28DD8, 9, func_00271A00(D_0051BA44, 0x1BA));
    self->field_2DA58 = -1;
    self->field_2DA5C = -1;
    self->field_2DA54 = -1;
    func_0022B8E0(self->field_7080);
    self->field_2DA64 = 0;
    self->field_2DA65 = 0;
    self->field_2DA66 = 0;
    self->field_2DA68 = 1;
    self->field_2DA6C = 3;
    Prepare__Q27GtComms16CGtCommsToolBaseFPCcP13CGTFileSystemPCc(self->field_8860, D_004B5D28, self->field_8080, (const char *)D_01E3C63C);
    Register__12CB3AIAttribsFv(D_01E754E0);
    RegisterStaticVariables__8CB3ScoreFv();
    RegisterStaticVariables__7CB3BurnFv();
    func_00344310();
    self->field_2DA84 = 1;
    func_0021B5E0(self->field_7000);
    func_0021B4E0(self->field_7000);
    self->field_2DA4C = self->field_2C668;
    self->field_2DA60 = 0x17;
    self->field_2DA90 = 1;
    self->field_2DA8C = 1;
    return 1;
}
