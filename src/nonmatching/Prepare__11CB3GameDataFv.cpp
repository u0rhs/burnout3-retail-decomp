// NONMATCHING: Prepare__11CB3GameDataFv -- retail 967 / ours 969 instructions, 109 in changed runs
// retail 967 / ours 969: 18-state loader FSM complete, frame matches; left: s-register choice for the two option bools / options object in the 0x17 pickup block, lane-pointer loop (case 0xD) scheduling
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm + Ghidra draft: every state of the 25-entry jump table, each read/seek size and offset, global stores and the 0x17 prepare block accounted for

// CB3GameData::Prepare -- hand-written (draft2) from the retail asm + Ghidra draft; never attempted before.
// [C] name: the mangled symbol. A streaming-load state machine (field_584 = state, falls through case to case);
// classes declared here with only what this function touches; field names are placeholders, types [G].
struct UnkStruct_0014F050_file {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(void *, int);   // [G] read(dst, size)
    virtual void vfunc_14();
    virtual void vfunc_18(long, int);     // [G] seek(offset, whence)
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();               // [G] async status: 1 = done
};
struct UnkStruct_0014F050_hdr {           // 0x800-byte directory read first
    unsigned char pad_0[0x8];
    unsigned long field_8[(0x198 - 0x8) / 8];
    int field_198[(0x260 - 0x198) / 4];
    int field_260;
};
struct UnkStruct_0014F050_trk {           // track data header (field_564)
    unsigned char pad_0[0x3B4];
    int field_3B4;
    unsigned char pad_3B8[0x4];
    int field_3BC;
    int field_3C0;
    int field_3C4;
    int field_3C8;
    int field_3CC;
    int field_3D0;
    int field_3D4;
    int field_3D8;
};
struct UnkStruct_0014F050_trig { unsigned char pad_0[0x20]; };
struct UnkStruct_0014F050_pick { unsigned char pad_0[0x11]; unsigned char field_11; unsigned char pad_12[0xE]; };
struct UnkStruct_0014F050_dat {           // field_56C
    UnkStruct_0014F050_trig field_0[1];
    unsigned char pad_20[0x3C0];
    UnkStruct_0014F050_pick * field_3E0;
    char * field_3E4;
    unsigned char pad_3E8[0x4];
    int field_3EC;
    int field_3F0;
    int field_3F4;
    int field_3F8;
    int field_3FC;
};
struct UnkStruct_0014F050_lanes { int field_0; unsigned char pad_4[0x4]; int field_8; };
struct UnkStruct_0014F050_ai { unsigned char pad_0[0x4]; int field_4; int field_8; int field_C; unsigned char pad_10[0x4];
    int field_14; int field_18; int field_1C; int field_20; };
struct UnkStruct_0014F050_te { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_0014F050_td { unsigned char pad_0[0x8]; int field_8; UnkStruct_0014F050_te * field_C; };
struct UnkStruct_0014F050_blk { unsigned char pad_0[0x18]; char field_18[8]; };
struct UnkStruct_0014F050_opt {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18();
    virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C();
    virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40();
    virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68();
    virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C();
    virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90();
    virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual bool vfunc_A4();
    virtual bool vfunc_A8();
};
struct UnkStruct_0014F050_game { unsigned char pad_0[0x1B4]; UnkStruct_0014F050_opt * field_1B4; };

struct UnkStruct_D_00522660_l { int field_0; unsigned char pad_4[0x48]; };
struct UnkStruct_D_00522660_a { int field_0; int field_4; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x30];
    UnkStruct_D_00522660_a field_30[63];
    unsigned char pad_228[0x4];
    UnkStruct_D_00522660_l field_22C[1];  // [G] element count unknown
};
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing needs > 8 bytes (N50)
struct UnkStruct_P { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_P D_00527440;   // [G] first word: traffic data pointer
extern UnkStruct_I D_0064D340, D_0064D344, D_0064D348, D_0064D34C, D_0064D350, D_0064D354, D_0064D358, D_0064D35C,
    D_0064D360, D_0064D364, D_0064D368;
extern UnkStruct_P D_004F60C0, D_00518688, D_0051BA88;
extern char * D_00488080[9];
extern char D_004B60F0[];
extern char theMemMgr[];
extern char D_004EE040[];
extern "C" void * AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" UnkStruct_0014F050_file * Open__13CGTFileSystemFPCcUi(void *, char *, unsigned int);
extern "C" void Fixup__18CB3TrackDataStructFUi(void *, unsigned int);
extern "C" void Fixup__20CB3TrafficDataStructFUi(void *, unsigned int);
extern "C" void Fixup__21CB3TrafficLanesStructFUi(void *, unsigned int);
extern "C" void Fixup__20CB3AILanesDataStructFv(void *);
extern "C" void Prepare__13CB3StartPointFP22CB3StartPositionStruct(void *, void *);
extern "C" void Prepare__18CB3StartFinishLineFP22CB3PlanarTriggerStructb(void *, void *, bool);
extern "C" void Prepare__22CB3SplitTimeCheckpointFP22CB3PlanarTriggerStruct(void *, void *);
extern "C" int Prepare__14CB3CrashPickupFP24CB3CrashModePickupStructPP10CGtTexture(void *, void *, void *);
extern "C" void Prepare__12CB3CrashRampFP22CB3CrashModeRampStruct(void *, void *);
extern "C" int func_00131E40(void *);   // [L] E map: CB3Game::IsCrashMode() (upstream note in symbol_addrs)
extern "C" int strcasecmp(const char *, const void *);

class CB3GameData {
public:
    int Prepare();

    unsigned char pad_0[0x370];
    int field_370[6];
    unsigned char field_388[2][0x10];
    unsigned char field_3A8[2][0x10];
    unsigned char field_3C8[12][0x8];
    int field_428[2];
    int field_430[9];
    int field_454;
    char field_458[0x100];
    unsigned long field_558;
    void * field_560;
    UnkStruct_0014F050_trk * field_564;
    char * field_568;
    UnkStruct_0014F050_dat * field_56C;
    UnkStruct_0014F050_lanes * field_570;
    UnkStruct_0014F050_ai * field_574;
    UnkStruct_0014F050_file * field_578;
    int field_57C;
    int field_580;
    int field_584;
    unsigned char field_588;
    unsigned char field_589;
    unsigned char field_58A;
    unsigned char field_58B;
    unsigned char field_58C;
};

// file status check (inlined at every state; returns the status==1 bool)
static inline bool func_0014F050_inl1(UnkStruct_0014F050_file * f)
{
    switch (f->vfunc_24()) {
    case 1:
        return true;
    case 3:
    case 2:
    case 0:
        return false;
    }
    return false;
}

static inline int func_0014F050_inl2(void * name)
{
    int t;
    UnkStruct_0014F050_td * d = (UnkStruct_0014F050_td *)D_00518688.field_0;
    int i;
    for (i = 0; i < d->field_8; i++) {
        t = d->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0014F050_blk *)(t + 0x90))->field_18, name) == 0) {
            goto found;
        }
    }
    t = 0;
found:
    return t;
}

int CB3GameData::Prepare()
{
    int i;
    if (field_589 == 0 || field_58A == 0) return 1;
    switch (field_584) {
    case 1:
    case 0x18:
        field_588 = 0;
        field_560 = 0;
        field_560 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(theMemMgr, 9, 0);
        if (field_560 == 0) return 0;
        field_584 = 2;
    case 2:
        field_578 = Open__13CGTFileSystemFPCcUi(D_004F60C0.field_0, field_458, 0x11);
        if (field_578 == 0) return 0;
        field_584 = 3;
    case 3:
        if (!func_0014F050_inl1(field_578)) return 0;
        field_578->vfunc_10(field_560, 0x800);
        field_584 = 4;
    case 4:
        if (!func_0014F050_inl1(field_578)) return 0;
        field_568 = (char *)field_560 + 0x800;
        field_578->vfunc_10(field_568, 0x2800);
        field_584 = 5;
    case 5: {
        if (!func_0014F050_inl1(field_578)) return 0;
        UnkStruct_0014F050_hdr * h = (UnkStruct_0014F050_hdr *)field_560;
        int off = 0;
        for (i = 0; i < h->field_260; i++) {
            if (h->field_8[i] == field_558) {
                off = h->field_198[i];
                break;
            }
        }
        field_564 = (UnkStruct_0014F050_trk *)(field_568 + 0x2800);
        field_578->vfunc_18(off, 0);
        field_584 = 6;
    }
    case 6:
        if (!func_0014F050_inl1(field_578)) return 0;
        field_578->vfunc_10(field_564, 0x800);
        field_584 = 7;
    case 7:
        if (!func_0014F050_inl1(field_578)) return 0;
        if (field_58B != 0) {
            D_0064D350.field_0 = (int)(field_568 + field_57C * 0x390);
            D_0064D360.field_0 = ((int *)(field_568 + 0x2010))[field_57C];
        } else {
            D_0064D350.field_0 = (int)field_564;
            D_0064D360.field_0 = field_564->field_3B4;
        }
        field_56C = (UnkStruct_0014F050_dat *)((char *)field_564 + 0x800);
        field_578->vfunc_18(field_564->field_3C0, 0);
        field_584 = 8;
    case 8:
        if (!func_0014F050_inl1(field_578)) return 0;
        field_578->vfunc_10(field_56C, field_564->field_3BC);
        field_584 = 9;
    case 9:
        if (!func_0014F050_inl1(field_578)) return 0;
        Fixup__18CB3TrackDataStructFUi(field_56C, (unsigned int)field_56C);
        D_00527440.field_0 = (char *)field_56C + field_564->field_3BC;
        if (field_58B != 0) {
            field_578->vfunc_18(((int *)(field_568 + 0x2040))[field_580], 0);
        } else {
            field_578->vfunc_18(field_564->field_3C8, 0);
        }
        field_584 = 10;
    case 10:
        if (!func_0014F050_inl1(field_578)) return 0;
        if (field_58B != 0) {
            field_578->vfunc_10(D_00527440.field_0, ((int *)(field_568 + 0x2034))[field_580]);
        } else {
            field_578->vfunc_10(D_00527440.field_0, field_564->field_3C4);
        }
        field_584 = 0xB;
    case 0xB: {
        if (!func_0014F050_inl1(field_578)) return 0;
        Fixup__20CB3TrafficDataStructFUi(D_00527440.field_0, (unsigned int)D_00527440.field_0);
        char * base = (char *)D_00527440.field_0;
        int n;
        if (field_58B != 0) {
            n = ((int *)(field_568 + 0x2034))[field_580];
        } else {
            n = field_564->field_3C4;
        }
        field_570 = (UnkStruct_0014F050_lanes *)(base + n);
        field_578->vfunc_18(field_564->field_3D0, 0);
        field_584 = 0xC;
    }
    case 0xC:
        if (!func_0014F050_inl1(field_578)) return 0;
        field_578->vfunc_10(field_570, field_564->field_3CC);
        field_584 = 0xD;
    case 0xD:
        if (!func_0014F050_inl1(field_578)) return 0;
        Fixup__21CB3TrafficLanesStructFUi(field_570, (unsigned int)field_570);
        for (i = 0; i < (D_0064D340.field_0 = field_570->field_8); i++) {
            D_00522660.field_22C[i].field_0 = field_570->field_0 + i * 0x14;
        }
        field_574 = (UnkStruct_0014F050_ai *)((char *)field_570 + field_564->field_3CC);
        field_578->vfunc_18(field_564->field_3D8, 0);
        field_584 = 0xE;
    case 0xE:
        if (!func_0014F050_inl1(field_578)) return 0;
        field_578->vfunc_10(field_574, field_564->field_3D4);
        field_584 = 0xF;
    case 0xF:
        if (!func_0014F050_inl1(field_578)) return 0;
        field_578->vfunc_C();
        field_578 = 0;
        Fixup__20CB3AILanesDataStructFv(field_574);
        D_0064D344.field_0 = (int)field_574;
        D_0064D354.field_0 = field_574->field_20;
        D_0064D348.field_0 = field_574->field_14;
        D_0064D34C.field_0 = field_574->field_1C;
        D_0064D364.field_0 = field_574->field_18;
        D_0064D358.field_0 = field_574->field_4;
        D_0064D35C.field_0 = field_574->field_C;
        D_0064D368.field_0 = field_574->field_8;
        for (i = 0; i < field_574->field_4; i++) {
            D_00522660.field_30[i].field_0 = D_0064D348.field_0 + i * 0x10;
        }
        field_584 = 0x17;
        return 0;
    case 0x17: {
        for (i = 0; i < 6; i++) {
            Prepare__13CB3StartPointFP22CB3StartPositionStruct(&field_370[i], (char *)field_56C + i * 0x50);
        }
        for (i = 0; i < 2; i++) {
            int n = 0;
            if (field_560 != 0) n = field_56C->field_3EC;
            if (i < n) {
                Prepare__18CB3StartFinishLineFP22CB3PlanarTriggerStructb(field_388[i], (char *)field_56C + i * 0x20 + 0x1E0, false);
            }
        }
        for (i = 0; i < 2; i++) {
            int n = 0;
            if (field_560 != 0) n = field_56C->field_3F0;
            if (i < n) {
                Prepare__18CB3StartFinishLineFP22CB3PlanarTriggerStructb(field_3A8[i], (char *)field_56C + i * 0x20 + 0x220, true);
            }
        }
        for (i = 0; i < 12; i++) {
            int n = 0;
            if (field_560 != 0) n = field_56C->field_3F4;
            if (i < n) {
                Prepare__22CB3SplitTimeCheckpointFP22CB3PlanarTriggerStruct(field_3C8[i], (char *)field_56C + i * 0x20 + 0x260);
            }
        }
        field_58C = 0;
        if (func_00131E40(D_004EE040)) {
            UnkStruct_0014F050_opt * o = ((UnkStruct_0014F050_game *)D_0051BA88.field_0)->field_1B4;
            bool a = o->vfunc_A8();
            bool b = o->vfunc_A4();
            bool n = !(a || b);
            for (i = 0; i < 9; i++) {
                field_430[i] = func_0014F050_inl2(D_00488080[i]);
            }
            for (i = 0; i < field_56C->field_3F8; i++) {
                UnkStruct_0014F050_pick * p = &field_56C->field_3E0[i];
                if (n && (p->field_11 & 1)) {
                    Prepare__14CB3CrashPickupFP24CB3CrashModePickupStructPP10CGtTexture((char *)this + field_58C * 0x10, p, field_430);
                    field_58C++;
                } else if (a != 0 && (p->field_11 & 4)) {
                    Prepare__14CB3CrashPickupFP24CB3CrashModePickupStructPP10CGtTexture((char *)this + field_58C * 0x10, p, field_430);
                    field_58C++;
                } else if (b != 0 && (p->field_11 & 2)) {
                    Prepare__14CB3CrashPickupFP24CB3CrashModePickupStructPP10CGtTexture((char *)this + field_58C * 0x10, p, field_430);
                    field_58C++;
                }
            }
            field_454 = func_0014F050_inl2(D_004B60F0);
            for (i = 0; i < field_56C->field_3FC; i++) {
                Prepare__12CB3CrashRampFP22CB3CrashModeRampStruct((char *)this + i * 0x70 + 0x140, field_56C->field_3E4 + i * 0x50);
            }
            for (i = 0; i < 2; i++) {
                field_428[i] = 4;
            }
        }
    }
    default:
        return 1;
    }
}
