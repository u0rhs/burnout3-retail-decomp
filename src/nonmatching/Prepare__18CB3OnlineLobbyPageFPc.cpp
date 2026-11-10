// NONMATCHING: Prepare__18CB3OnlineLobbyPageFPc -- retail 222 / ours 222 instructions, 7 in changed runs
// a147: 222/222 instrs, 7 in changed runs, all one register swap: retail keeps ctrl pointer e (D_004F50C0+0xD48 record, used for the final sh zero,0x76) in s1 and the alloc-loop index / k-ref (addiu s0,sp,0x74) in s0; ours has e in s0, i/k in s1. Declaration order of i/e, do-while, const e, short* e76 do not flip it. Frame needs a 0x40 N140-style pad class (UnkStruct_00317D20_pad, ctor/dtor, field_0[0x40]) declared first; sibling UpdateLaunchGame (B3OnlineLobbyPage_00314A30) supplies the id/ref inline; vfunc_CC/BC through a cast pun.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a147).
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74();
    virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84();
    virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94();
    virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4(); virtual void vfunc_B8();
    virtual void vfunc_BC(void *);
    virtual void vfunc_C0(); virtual void vfunc_C4(); virtual void vfunc_C8();
    virtual void vfunc_CC(void *, void *);
    unsigned char pad_4[0xC];
};
class CB3TrackList { public: int IsTrackPointToPoint(unsigned long); unsigned char pad_0[0x10]; };
struct UnkStruct_D_004F6061 { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00314A30_e0 { unsigned char pad_0[0xE4]; short field_E4; unsigned char pad_E6[0x46]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_long { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_gen { unsigned char pad_0[0x10]; };
struct UnkStruct_00316840_ctrl { unsigned char pad_0[0x76]; short field_76; unsigned char pad_78[0xB4]; };
struct UnkStruct_00316840_D { unsigned char pad_0[0xD48]; UnkStruct_00316840_ctrl field_D48[1]; };
extern UnkStruct_00316840_D D_004F50C0;
struct UnkStruct_a2 { void * field_0; };
struct UnkStruct_buf { unsigned short field_0[0x1E]; UnkStruct_a2 field_3C; };
struct UnkStruct_Prepare_9 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    unsigned char pad_2C[0x14];
};
struct UnkStruct_00314A30_id { int field_0; int field_4; };
struct UnkStruct_00317D20_pad {
    unsigned char field_0[0x40];
    UnkStruct_00317D20_pad() {}
    ~UnkStruct_00317D20_pad() {}
};
struct CB3MenuNode { short field_0; short field_2; };
class CB3OnlineLobbyPage {
public:
    bool Prepare(char *);
    unsigned char pad_0[4];
    short field_4;
    short field_6;
    unsigned char field_8;
    unsigned char pad_9[3];
    int field_C;
    unsigned char pad_10[0x1270];
    short field_1280;
    short field_1282;
    unsigned char pad_1284[0xC0];
    int field_1344[6];
    int field_135C[6];
    int field_1374;
    int field_1378;
    UnkStruct_a2 field_137C;
    int field_1380;
    int field_1384;
    unsigned char pad_1388[8];
    int field_1390;
    unsigned char pad_1394[8];
    float field_139C;
    unsigned char pad_13A0[5];
    unsigned char field_13A5;
    unsigned char field_13A6;
    unsigned char field_13A7;
    unsigned char pad_13A8[4];
    signed char field_13AC;
};
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_gen D_01E90438;
extern UnkStruct_D_gen D_01E88A80;
extern UnkStruct_D_gen D_01E894FC;
extern UnkStruct_D_gen D_01E89788;
extern UnkStruct_D_gen D_01E32AE0;
extern UnkStruct_D_gen D_01E8CBE0;
extern UnkStruct_D_gen D_01E899C0;
extern UnkStruct_D_gen D_01E89518;
extern UnkStruct_D_gen D_0051BA44;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CB3TrackList D_005196A0;
extern UnkStruct_D_int D_01E900C0;
extern UnkStruct_D_byte D_01E90225;
extern UnkStruct_D_long D_01E901F0;
extern UnkStruct_D_long D_01E90198;
extern UnkStruct_D_int D_0051B24C;
extern char D_004C4FE8[];
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void Prepare__19CB3HelpBarComponentFv(void *);
extern "C" void SetupTableData__18CB3OnlineLobbyPageFv(void *);
extern "C" int AmIHost__17CB3NetworkManagerFv(void *);
extern "C" void Prepare__23CB3ChatDisplayComponentF25EB3ChatDisplayOrientation(void *, int);
extern "C" int func_003517F0(void *);
extern "C" void RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" void ChatMessageCallback__18CB3OnlineLobbyPageFPcPcPv(char *, char *, void *);
extern "C" void BuildGameOptionsText__18CB3OnlineLobbyPageFv(void *);
extern "C" void func_00312420(void *);
extern "C" void func_00316640(void *);
extern "C" void func_00312A60(void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, int, int);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003180A0(void *, void *, const UnkStruct_a2 &);
extern "C" void AddNewMessage__23CB3ChatDisplayComponentFPcPCUs(void *, char *, void *);

static inline unsigned long func_00317D20_inl1(const int & a, const int & b)
{
    UnkStruct_00314A30_id t;
    t.field_0 = a;
    t.field_4 = b;
    return *(unsigned long *)&t;
}

// 0x00317D20
bool CB3OnlineLobbyPage::Prepare(char * p0)
{
    UnkStruct_00317D20_pad pad;  // [G] N140 frame slot (retail frame is 0x40 larger)
    UnkStruct_buf buf;
    UnkStruct_Prepare_9 local;
    UnkStruct_00316840_ctrl * e = &D_004F50C0.field_D48[D_004F6061.field_0];
    Prepare__15CB3MenuPageBaseFb(this, false);
    field_C = 0;
    for (int i = 0; i < 6; i++) {
        int a = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
        char * q = (char *)this + i * 4;
        *(int *)(q + 0x1344) = a;
        *(int *)(q + 0x135C) = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
    }
    field_1374 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
    field_1378 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 3);
    field_137C.field_0 = (void *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    field_1380 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 256);
    field_1384 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 2);
    field_13A5 = 0;
    field_13A6 = 0;
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    Prepare__19CB3HelpBarComponentFv(&D_01E89788);
    SetupTableData__18CB3OnlineLobbyPageFv(this);
    if (AmIHost__17CB3NetworkManagerFv(&D_01E32AE0) != 0) {
        Prepare__23CB3ChatDisplayComponentF25EB3ChatDisplayOrientation(&D_01E8CBE0, 2);
    } else {
        Prepare__23CB3ChatDisplayComponentF25EB3ChatDisplayOrientation(&D_01E8CBE0, 3);
    }
    func_003517F0(&D_01E899C0);
    RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_CC((void *)&ChatMessageCallback__18CB3OnlineLobbyPageFPcPcPv, this);
    field_1280 = 0;
    field_1282 = 1;
    field_4 = 0;
    field_6 = 6;
    field_13AC = 1;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_BC(&local);
    int & c = local.field_C;
    int & k = local.field_14;
    int & d = local.field_20;
    D_01E900C0.field_0 = k;
    D_01E90198.field_0 = func_00317D20_inl1(c, d);
    D_01E901F0.field_0 = func_00317D20_inl1(local.field_24, local.field_28);
    D_01E90225.field_0 = ((((unsigned int)local.field_18 >> 16) & 255) == 1);
    if (D_005196A0.IsTrackPointToPoint(func_00317D20_inl1(c, d)) == 0 || (k != 0 && k != 1)) {
        D_0051B24C.field_0 = (((unsigned int)local.field_1C >> 24) & 255);
    } else {
        D_0051B24C.field_0 = 1;
    }
    BuildGameOptionsText__18CB3OnlineLobbyPageFv(this);
    func_00312420(this);
    field_8 = 0;
    func_00316640(this);
    func_00312A60(this);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p0, (int)field_137C.field_0, 32);
    Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)((int)field_137C.field_0), 14);
    field_139C = -1.0f;
    field_13A7 = AmIHost__17CB3NetworkManagerFv(&D_01E32AE0);
    field_1390 = 0;
    buf.field_0[0] = 0;
    func_003180A0(&buf, (void *)(func_00271A00(&D_0051BA44, 0x3BD)), field_137C);
    AddNewMessage__23CB3ChatDisplayComponentFPcPCUs(&D_01E8CBE0, D_004C4FE8, &buf);
    e->field_76 = 0;
    return true;
}
