// CB3OnlineLobbyPage::BuildGameOptionsText() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (goto form; cls=0 after the id test + scoped opt_rebuildconditionals off (pass3a sweep)).

// CB3OnlineLobbyPage::BuildGameOptionsText() -- hand-written (fresh7); the lifter refused it.
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

struct UnkStruct_D_01E3CD44 { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual int vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual int vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(void *); virtual void vfunc_B4(void *); virtual void vfunc_B8(void *); virtual void vfunc_BC(void *); unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E3D578 { unsigned long field_0; unsigned long pad_8; };
struct UnkStruct_00311890_player { unsigned char pad_0[0x4D8]; unsigned long field_4D8; };

// [G] the game settings vfunc_BC fills (0x40 bytes)
struct UnkStruct_00311890_params {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned int field_18;
    unsigned int field_1C;
    int field_20;
    int field_24;
    int field_28;
    unsigned char pad_2C[0x14];
};

struct UnkStruct_00311890 {
    unsigned char pad_0[0x1384];
    unsigned short *field_1384;
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_P D_01E32AE0, D_0051BA44, D_004EE040, D_005196A0, D_01E89788;
extern UnkStruct_D_byte D_01E3D58A, D_01E65499;
extern UnkStruct_D_01E3D578 D_01E3D578;
extern char maOffsetTable__14CB3MenuFlowFSM[];
extern int D_004C4F70[];
extern int D_004C4F78[];

extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" unsigned short *AppendN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, const unsigned short *);
extern "C" unsigned short *PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
extern "C" void func_003180A0(unsigned short *, const unsigned short *, void *);
extern "C" int FindCrashStage__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" int func_003E9490(int, int);
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int GetTrackString__21CB3HardCodedTrackListFib(int, bool);
extern "C" bool IsTrackPointToPoint__12CB3TrackListFUl(void *, unsigned long);
extern "C" bool AmIHost__17CB3NetworkManagerFv(void *);
extern "C" int GetHostPlayerID__23CGtNetworkPlayerManagerFv(void *);
extern "C" UnkStruct_00311890_player *GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetCarClass__18CB3OnlineLobbyPageFUl(UnkStruct_00311890 *, unsigned long);
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short *, bool, bool, float);

union UnkUnion_00311890_id {
    struct { int lo; int hi; } s;
    unsigned long l;
};

static inline int func_00311890_inl2()
{
    if (D_01E65499.field_0 != 0)
        return GetHostPlayerID__23CGtNetworkPlayerManagerFv(&D_01E32AE0);
    return ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_80();
}

// N182: `#pragma opt_repositioncode off` ([G] scoped to this function): retail's rare arms (track names, the
// mode-specific suffixes, the car-class line) sit after the return in the goto order below.
// N182: `#pragma opt_rebuildconditionals off` ([G] same scope): keeps `cls = 0` after the `id != 0` test as
// retail's fall-through (bnez to the out-of-line GetCarClass call, empty delay slot); pass3a pragma sweep.
#pragma push
#pragma opt_repositioncode off
#pragma opt_rebuildconditionals off
// 0x00311890
extern "C" void BuildGameOptionsText__18CB3OnlineLobbyPageFv(UnkStruct_00311890 *self)
{
    const unsigned short *argc;
    const unsigned short *argv;
    short sep[4] = {0x20, 0, 0, 0};
    UnkUnion_00311890_id idTrack;
    UnkUnion_00311890_id idStage;
    UnkUnion_00311890_id idP2P;
    unsigned short buf[128];
    UnkStruct_00311890_params p;
    unsigned short *s;
    unsigned short *t;
    unsigned short *t1;
    int v;
    int cls;
    unsigned long id;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&p);
    self->field_1384[0] = 0;
    int &type0 = p.field_14;
    if (type0 == 1) {
        unsigned int off;
        if (D_01E3D58A.field_0 != 0) {
            off = 0x2DA04;
            t1 = AppendN__10CGtUnicodeFPUsiPCUs(self->field_1384, 0x100, func_00271A00(&D_0051BA44, 0x3C6));
        } else {
            off = 0x2DA04;
            t1 = AppendN__10CGtUnicodeFPUsiPCUs(self->field_1384, 0x100, func_00271A00(&D_0051BA44, 0x3C5));
        }
        AppendN__10CGtUnicodeFPUsiPCUs(t1, 0x100, func_00271A00((void *)((unsigned int)&D_004EE040 + off), 0x3BC));
    }
    s = AppendN__10CGtUnicodeFPUsiPCUs(self->field_1384, 0x100, func_00271A00(&D_0051BA44, ((int *)(maOffsetTable__14CB3MenuFlowFSM + 0x460))[type0]));
    s = AppendN__10CGtUnicodeFPUsiPCUs(s, 0x100, func_00271A00(&D_0051BA44, 0x3BC));
    if (type0 == 0 || type0 == 1)
        goto track;
    s = AppendN__10CGtUnicodeFPUsiPCUs(s, 0x100, func_00271A00(&D_0051BA44, func_003E9490((idStage.s.lo = p.field_24, idStage.s.hi = p.field_28, FindCrashStage__26CB3HardCodedCrashStageListFUl(idStage.l)), 0)));
named:
    s = AppendN__10CGtUnicodeFPUsiPCUs(s, 0x100, func_00271A00(&D_0051BA44, 0x3BC));
    if ((idP2P.s.lo = p.field_C, idP2P.s.hi = p.field_20, IsTrackPointToPoint__12CB3TrackListFUl(&D_005196A0, idP2P.l)) && (type0 == 0 || type0 == 1))
        goto laps;
    if (type0 == 2)
        goto laps;
    {
        unsigned int *n = &p.field_1C;
        t = AppendN__10CGtUnicodeFPUsiPCUs(PrintInt__10CGtUnicodeFPUsii(s, (*n >> 24) & 0xFF, 1, 0), 0x100, (const unsigned short *)sep);
        if (type0 == 0 || type0 == 1)
            goto lapword;
        if (((*n >> 24) & 0xFF) == 1)
            s = AppendN__10CGtUnicodeFPUsiPCUs(t, 0x100, func_00271A00(&D_0051BA44, 0x3C0));
        else
            s = AppendN__10CGtUnicodeFPUsiPCUs(t, 0x100, func_00271A00(&D_0051BA44, 0x3C1));
    lapsep:
        s = AppendN__10CGtUnicodeFPUsiPCUs(s, 0x100, func_00271A00(&D_0051BA44, 0x3BC));
    }
laps:
    if (type0 == 1 && D_01E3D58A.field_0 != 0)
        v = (p.field_18 >> 8) & 0xFF;
    else
        v = (p.field_1C >> 8) & 0xFF;
    if (v == 1)
        goto carclass;
    if (v <= 0)
        goto plain;
    argv = func_00271A00(&D_0051BA44, D_004C4F70[v]);
    func_003180A0(buf, func_00271A00(&D_0051BA44, 0x3C4), &argv);
    AppendN__10CGtUnicodeFPUsiPCUs(s, 0x100, buf);
done:
    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, self->field_1384, false, false, 80.0f);
    return;
track:
    s = AppendN__10CGtUnicodeFPUsiPCUs(s, 0x100, func_00271A00(&D_0051BA44, GetTrackString__21CB3HardCodedTrackListFib((idTrack.s.lo = p.field_C, idTrack.s.hi = p.field_20, FindTrack__21CB3HardCodedTrackListFUl(idTrack.l)), false)));
    goto named;
lapword:
    if (((*(unsigned int *)&p.field_1C >> 24) & 0xFF) == 1)
        s = AppendN__10CGtUnicodeFPUsiPCUs(t, 0x100, func_00271A00(&D_0051BA44, 0x3BE));
    else
        s = AppendN__10CGtUnicodeFPUsiPCUs(t, 0x100, func_00271A00(&D_0051BA44, 0x3BF));
    goto lapsep;
carclass:
    if (!AmIHost__17CB3NetworkManagerFv(&D_01E32AE0))
        goto client;
    id = D_01E3D578.field_0;
idtest:
    if (id != 0)
        goto getclass;
    cls = 0;
haveclass:
    argc = func_00271A00(&D_0051BA44, D_004C4F78[cls]);
    func_003180A0(buf, func_00271A00(&D_0051BA44, 0x3C4), &argc);
    AppendN__10CGtUnicodeFPUsiPCUs(s, 0x100, buf);
    goto done;
client:
    if (func_00311890_inl2() < 0) {
        id = D_01E3D578.field_0;
        goto idtest;
    }
    id = GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, func_00311890_inl2())->field_4D8;
    goto idtest;
getclass:
    cls = GetCarClass__18CB3OnlineLobbyPageFUl(self, id);
    goto haveclass;
plain:
    AppendN__10CGtUnicodeFPUsiPCUs(s, 0x100, func_00271A00(&D_0051BA44, D_004C4F70[v]));
    goto done;
}
#pragma pop
