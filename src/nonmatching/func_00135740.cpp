// NONMATCHING: func_00135740 -- retail 199 / ours 187 instructions, 51 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x135740..0x135A58) with the Ghidra aid. Unnamed; file
// B3OnlineStage.cpp per research/retail_names.csv (high). [L] the online stage's Prepare by shape: the same tail as
// func_00135280 ([L] CB3OnePlayerStage::Prepare), with a resumable start (+0x1C8: 1/0x18, 2..6, then 7; 0x17 = done)
// that binds each network player to a world slot (D_00522660 + 0x13B2D0 + slot * 0x1AA0, slot one lower after a
// missing player).
// TRACK: clean
// EQUIV: [L] written from the asm: the if-chain dispatch (6, 5, 4, 3, 2, 0x18, 1; others skip to the tail), the
// fall-throughs, both player loops, the 64-bit id passed through pcpyld

struct UnkStruct_00135740_gm {
    // [C] the game mode: slots 0x30 and 0x9C called with a0 = it
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual int vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual int vfunc_9C();
};
struct UnkStruct_00135740 {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8();           // [C] a stage: its vtable pointer sits at +0x1B0 (func_00132600's calls)
    UnkStruct_00135740_gm * field_1B4;
    unsigned char pad_1B8[0x8];
    int field_1C0;
    unsigned char pad_1C4[0x4];
    int field_1C8;                    // [C] the start-up state
};
struct UnkStruct_00135740_pl {
    unsigned char pad_0[0x5C0];
    unsigned char field_5C0;
    unsigned char pad_5C1[0x6DC - 0x5C1];
    unsigned char * field_6DC;        // [C] the world slot bound to this player
};

extern unsigned char D_01EA2F0D;
extern unsigned char D_01EA2F0E;
extern unsigned char D_01E65499;
extern unsigned char D_01E6549A;
extern unsigned char D_01E32AE4;
extern int D_01E32B08;                // [C] the network player count (loop bound)
extern int D_01E65458;
extern unsigned char D_00516E10;
extern unsigned char D_00516E34;
extern int D_0066A544;
extern UnkStruct_00135740 * D_0051BA88;   // [C] gGame (D_004EE040) + 0x2DA48: the current stage
extern unsigned char theMemMgr[];
extern unsigned char D_0051A6A8[];
extern unsigned char D_01E32AE0[];    // [C] the CB3NetworkManager
extern unsigned char D_00522660[];    // [C] the CB3World
extern unsigned char D_00516DF0[];    // [C] a CB3Player (Prepare__9CB3PlayerFv a0)
extern unsigned char D_00665EC0[];
extern unsigned char D_0066A3D0[];
extern unsigned char D_01E77540[];

extern "C" int AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(void *, int);
extern "C" int func_001346C0(void *);
extern "C" void func_00130C20(void *, unsigned long);   // [C] proven: stores p0 (64-bit) at +0x300
extern "C" UnkStruct_00135740_pl * func_002366D0(void *, int);
extern "C" void HostMigrationEnterGame__17CB3NetworkManagerFv(void *);
extern "C" void func_00270AC0(void *);
extern "C" int Prepare__9CB3PlayerFv(void *);
extern "C" void func_00135A90(void *);
extern "C" void func_0019E990(void *);
extern "C" void func_001A0660(void *, int);
extern "C" void func_00289AF0(void *, int);

// 0x00135740
extern "C" int func_00135740(UnkStruct_00135740 * self)
{
    if (AcquireMemoryLayout__16CB3MemoryManagerF15EB3MemoryLayout(theMemMgr, 1) == 0) {
        return 0;
    }
    if (func_001346C0(self) == 0) {
        return 0;
    }
    switch (self->field_1C8) {
    case 1:
    case 0x18: {
        D_01EA2F0D = 1;
        D_01EA2F0E = 1;
        // [C] a 64-bit id (a GtID hash, N293's class) built with dsll / or and passed through pcpyld
        func_00130C20(D_0051A6A8, 0x94413E09C8514CA1UL);
        D_01E65499 = 1;
        bool missing = false;
        D_01E6549A = 0;
        for (int i = 0; i < D_01E32B08; i++) {
            UnkStruct_00135740_pl * pl = func_002366D0(D_01E32AE0, i);
            if (pl == 0) {
                D_01E32AE4 = 1;
                missing = true;
                continue;
            }
            unsigned char * slot = missing ? D_00522660 + 0x13B2D0 + (i - 1) * 0x1AA0
                                           : D_00522660 + 0x13B2D0 + i * 0x1AA0;
            if (D_0051BA88->field_1B4->vfunc_9C() != 3) {
                pl->field_6DC = slot;
                *(UnkStruct_00135740_pl **)(slot + 0x1A88) = pl;
            }
        }
        HostMigrationEnterGame__17CB3NetworkManagerFv(D_01E32AE0);
        self->field_1C8 = 2;
    }
        // fall through
    case 2:
        self->field_1C0 = 0;
        self->field_1C8 = 3;
        // fall through
    case 3:
        self->field_1C8 = 4;
        // fall through
    case 4:
        self->field_1C8 = 5;
        // fall through
    case 5:
        self->field_1C8 = 6;
        // fall through
    case 6:
        for (int i = 0; i < D_01E32B08; i++) {
            UnkStruct_00135740_pl * pl = func_002366D0(D_01E32AE0, i);
            if (pl != 0) {
                pl->field_5C0 = 1;
            }
        }
        self->field_1C8 = 7;
        D_01E65458 = 0;
        break;
    default:
        break;
    }
    func_00270AC0(D_01E32AE0);
    Prepare__9CB3PlayerFv(D_00516DF0);
    D_00516E10 = 1;
    func_00135A90(D_00516DF0);
    D_00516E34 = 0;
    func_0019E990(D_00665EC0);
    D_0066A544 = self->field_1B4->vfunc_30();
    func_001A0660(D_0066A3D0, 1);
    func_00289AF0(D_01E77540, 1);
    self->field_1C8 = 0x17;
    return 1;
}
