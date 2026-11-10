// NONMATCHING: func_00131480 -- retail 324 / ours 305 instructions, 87 in changed runs
// gaps1c: hand-drafted from the asm (front-end start-up machine)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x131480..0x13198C) with the Ghidra aid. Unnamed; file
// B3FrontEnd.cpp per research/retail_names.csv (high). A resumable front-end start-up machine on +0x2F4 (states 1/0x18,
// 2..0xC, then 0x17 = done): each state returns 0 until its step completes, so the caller re-enters it every frame.
// TRACK: clean
// EQUIV: [L] written from the asm: the if-chain dispatch (11, 10, ..., 2, 0x18, 1; anything else -> the finish), every
// fall-through into the next state, the two async loads, the FSM state switch (same shape as func_0036B0A0's SetScene)

struct UnkStruct_00131480_dict {
    unsigned char pad_0[0x8];
    int field_8;                      // [C] the texture count FixUp loops over
};
struct UnkStruct_00131480 {
    unsigned char pad_0[0x1C0];
    UnkStruct_00131480_dict * field_1C0;   // [C] AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x10) result, loaded from D_004B5AF0's file
    void * field_1C4;                 // [C] AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x12) result, loaded from D_004B5B10's file
    unsigned char pad_1C8[0x2F4 - 0x1C8];
    int field_2F4;                    // [C] the state
    unsigned char pad_2F8[0x8];
    unsigned long field_300;          // [C] ld: the FSM state id for GetStateFromID__6CGtFSMFUl
    unsigned char pad_308[0x8];
    void * field_310;                 // [C] AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x11) result
    unsigned char pad_314[0x1];
    unsigned char field_315;          // [C] the first load's done flag (QueueLoadRequest's bool *)
    unsigned char field_316;          // [C] the second load's done flag
};
struct UnkStruct_00131480_st { unsigned char pad_0[0x8]; float field_8; };
struct UnkStruct_00131480_cur { unsigned char pad_0[0x20]; float field_20; };
struct UnkStruct_00131480_fsm {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(void *, int); virtual void vfunc_1C(void *, int);
};
struct UnkStruct_00131480_lob {
    // [C] slot 0x24 (a0 = it, buffer, size), slot 0x18 (a0 = it, 0x4D2, callback, &D_01E32AE0, callback,
    // &D_01E32AE0, D_004E2918)
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(int, void *, void *, void *, void *, int); virtual void vfunc_1C(); virtual void vfunc_20();
    virtual void vfunc_24(void *, int);
};

extern unsigned char D_01E91C3C;
extern unsigned char D_01E3C660;
extern unsigned char D_00516E10;
extern unsigned char D_00516E34;
extern unsigned char D_0051BAA5;      // [C] gGame (D_004EE040) + 0x2DA65
extern int D_0051BAA8;                // [C] gGame + 0x2DA68 (frame-rate mode)
extern int D_01E32AE0;                // [C] the CB3NetworkManager; its first word read as a state (0x17)
extern int D_004E2918;                // [C] gp-relative
extern unsigned char theMemMgr[];
extern unsigned char D_004F50C0[];
extern unsigned char D_01E75640[];
extern unsigned char D_004F6100[];    // [C] gGame + 0x80C0: the CAsyncLoadManager, addressed absolutely
extern char D_004B5AF0[];             // [C] file-name strings (QueueLoadRequest a1)
extern char D_004B5B10[];
extern unsigned char D_01EA4070[];    // [C] the CB3MenuImages (CacheFrontendTextures a0)
extern unsigned char D_01E85900[];
extern unsigned char D_0064C990[];    // [C] the CB3StaticTrack
extern unsigned char D_01E7A888[];
extern unsigned char D_01E7A800[];
extern unsigned char D_004EE040[];    // [C] gGame
extern unsigned char D_00665EC0[];
extern UnkStruct_00131480_fsm D_01EA2970;   // [C] the menu-flow CGtFSM
extern UnkStruct_00131480_st * D_01EA2974;  // [C] its current state
extern UnkStruct_00131480_cur * D_01EA2980;
extern float D_01EA2984;
extern UnkStruct_00131480_lob D_01E3CD44;

extern "C" int AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(void *, int);
extern "C" void func_0022BE00(void *);
extern "C" void func_0028AEB0(void *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" void * AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(void *, const char *, unsigned char *, void *, int);
extern "C" void FixUp__17CGtDictionaryBaseFv(void *);
extern "C" void * func_00131AA0(void *, int);
extern "C" void FixUp__10CGtTextureFv(void *);
extern "C" void CacheFrontendTextures__13CB3MenuImagesFv(void *);
extern "C" int func_002BCA20(void *);
extern "C" int Prepare__14CB3StaticTrackFv(void *);
extern "C" void func_003FA600(void *, int);
extern "C" int func_003FB0F0(void *, int);
extern "C" int func_002870D0(void *, int);
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(void *);
extern "C" void * GetStateFromID__6CGtFSMFUl(void *, unsigned long);
extern "C" int func_001346C0(void *);
extern "C" void SetFrontendFrameRate__7CB3GameFb(void *, int);
extern "C" void func_0019E990(void *);
extern "C" void PlayerListChangedCallback__17CB3NetworkManagerFiPv();
extern "C" void PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv();

// 0x00131480
extern "C" int func_00131480(UnkStruct_00131480 * self)
{
    if (D_01E91C3C != 0) {
        return 0;
    }
    switch (self->field_2F4) {
    case 1:
    case 0x18:
        if (AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(theMemMgr, 0) == 0) {
            return 0;
        }
        D_00516E10 = 0;
        D_00516E34 = 0;
        func_0022BE00(D_004F50C0);
        func_0028AEB0(D_01E75640);
        memset(self, 0, 0x1B0);
        self->field_2F4 = 2;
        // fall through
    case 2:
        self->field_310 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x11, 0);
        if (self->field_310 == 0) {
            return 0;
        }
        self->field_2F4 = 3;
        // fall through
    case 3:
        self->field_1C0 = (UnkStruct_00131480_dict *)AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x10, 0);
        if (self->field_1C0 == 0) {
            return 0;
        }
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(D_004F6100, D_004B5AF0, &self->field_315, self->field_1C0,
                                                        GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0x10));
        self->field_2F4 = 4;
        // fall through
    case 4: {
        if (self->field_315 == 0) {
            return 0;
        }
        UnkStruct_00131480_dict * d = self->field_1C0;
        FixUp__17CGtDictionaryBaseFv(d);
        for (int i = 0; i < d->field_8; i++) {
            FixUp__10CGtTextureFv(func_00131AA0(d, i));
        }
        CacheFrontendTextures__13CB3MenuImagesFv(D_01EA4070);
        self->field_2F4 = 5;
    }
        // fall through
    case 5:
        self->field_1C4 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x12, 0);
        if (self->field_1C4 == 0) {
            return 0;
        }
        self->field_316 = 0;
        QueueLoadRequest__17CAsyncLoadManagerFPCcPbPvUi(D_004F6100, D_004B5B10, &self->field_316, self->field_1C4,
                                                        GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0x12));
        self->field_2F4 = 6;
        // fall through
    case 6:
        if (self->field_316 == 0) {
            return 0;
        }
        self->field_2F4 = 7;
        // fall through
    case 7:
        if (func_002BCA20(D_01E85900) == 0) {
            return 0;
        }
        self->field_2F4 = 8;
        // fall through
    case 8:
        if (Prepare__14CB3StaticTrackFv(D_0064C990) == 0) {
            return 0;
        }
        self->field_2F4 = 9;
        // fall through
    case 9:
        func_003FA600(D_01E7A888, 1);
        self->field_2F4 = 10;
        // fall through
    case 10:
        if (func_003FB0F0(D_01E7A888, 1) == 0) {
            return 0;
        }
        self->field_2F4 = 11;
        // fall through
    case 11:
        if (func_002870D0(D_01E7A800, 0) == 0) {
            return 0;
        }
        self->field_2F4 = 12;
        break;
    default:
        break;
    }

    if (D_01E3C660 != 0) {
        void * buf = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x18, 0);
        ((UnkStruct_00131480_lob *)&D_01E3CD44)->vfunc_24(buf, GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(theMemMgr, 0x18));
        ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 0x18, 0);
        ((UnkStruct_00131480_lob *)&D_01E3CD44)->vfunc_18(0x4D2, (void *)PlayerListChangedCallback__17CB3NetworkManagerFiPv,
                                                           &D_01E32AE0,
                                                           (void *)PlayerBootedCallback__17CB3NetworkManagerF16ELobbyKickReasonPv,
                                                           &D_01E32AE0, D_004E2918);
    }
    if (D_01E32AE0 == 0x17) {
        ClearAllPlayers__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
    }
    UnkStruct_00131480_st * s = (UnkStruct_00131480_st *)GetStateFromID__6CGtFSMFUl(&D_01EA2970, self->field_300);
    if (D_01EA2974 != s) {
        ((UnkStruct_00131480_fsm *)&D_01EA2970)->vfunc_18(s, 0);
        UnkStruct_00131480_st * old = D_01EA2974;
        D_01EA2974 = s;
        UnkStruct_00131480_cur * c = D_01EA2980;
        if (c != 0) {
            D_01EA2984 = c->field_20;
            if (s != 0) {
                s->field_8 = c->field_20;
            }
        }
        ((UnkStruct_00131480_fsm *)&D_01EA2970)->vfunc_1C(old, 0);
    }
    func_001346C0(self);
    D_0051BAA8 = 1;
    D_0051BAA5 = 0;
    SetFrontendFrameRate__7CB3GameFb(D_004EE040, 1);
    self->field_2F4 = 0x17;
    func_0019E990(D_00665EC0);
    return 1;
}
