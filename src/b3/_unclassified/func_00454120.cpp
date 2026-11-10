// Hand-written; the lifter refused it (near23: const index tables, case 3/8 statement order).

// Hand-finished by near23 from a158's archive: the index tables as const externs (loads schedule past the field_8 stores),
// case 3 constants before the table loads, case 8 as s1 / s0 / s2 with field_8 stored before s7.
// func_00456550's third parameter stays int here: func_004547C0's unsigned long adds a sign extension at this call.

// func_00454120 -- hand-written (a158): stage/trophy page set-up by type (a1), index (a2), flag (a3); jtbl 12 cases.
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051A9A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051A9A0 D_0051A9A0;
extern UnkStruct_P16 D_0051BA44;
extern UnkStruct_P16 D_01E89788;
extern UnkStruct_P16 D_01E90438;
extern UnkStruct_P16 D_01E88A80;
extern UnkStruct_P16 D_0051A6A8;
extern UnkStruct_P16 D_01E89800;
extern UnkStruct_P16 D_01E8F2D8;
extern UnkStruct_P16 D_01E89518;
extern UnkStruct_P16 D_01E894FC;
extern UnkStruct_P16 D_01E8FFF0;
extern const int D_004D31C0[];
extern const int D_004D31E0[];
extern const int D_004D3200[];
extern const int D_004D3230[];
extern const int D_004D3260[];
extern const int D_004D3290[];
extern const int D_004D32E0[];
extern const int D_004D32F0[];
extern const int D_004D3318[];
extern const int D_004D3328[];
extern const int D_004D3338[];
extern unsigned short D_004D3350[];
struct UnkStruct_00454120 {
    unsigned char pad_0[4];
    int field_4;
    float field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
};
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void func_00130C30(void *, int);
extern "C" int func_003F5FD0(int);
extern "C" int func_003F5F50(int);
extern "C" int func_003F5E90(int);
extern "C" int func_003F5E00(int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void AwardPrepare__19CB3HelpBarComponentFPCUs(void *, const unsigned short *);
extern "C" int GetTrophySpecialCondition__22CB3HardCodedTrophyListFi(int);
extern "C" int GetHeadlineCrashDamage__24CB3HardCodedHeadlineListFi(int);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" unsigned short *Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" void *AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void *func_001A3AA0(void *, const unsigned short *, int *);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00456550(void *, int, int);
extern "C" int func_00461DF0(void *, int);
extern "C" void Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);

static inline bool func_00454120_inl1()
{
    bool r;
    if (D_0051A9A0.field_0 == 0x18 || D_0051A9A0.field_0 == 1) r = true; else r = false;
    return r;
}

// 0x00454120
extern "C" int func_00454120(UnkStruct_00454120 *self, int p0, int p1, int p2)
{
    int s2;
    int s1 = 0x55C;
    int s0 = 5;
    bool s7 = true;
    int loc;
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_F = 0;
    if (!func_00454120_inl1()) {
        func_00130C70(&D_0051A6A8);
        func_00130D00(&D_0051A6A8);
    }
    self->field_8 = 10.01001072f;
    loc = p1;
    switch (p0) {
    case 6:
        s2 = D_004D31C0[p1];
        s1 = D_004D31E0[p1];
        s7 = false;
        self->field_8 = 17.01701736f;
        break;
    case 1:
        s1 = 0x6E9;
        s0 = 9;
        AwardPrepare__19CB3HelpBarComponentFPCUs(&D_01E89788, func_00271A00(&D_0051BA44, func_003F5FD0(p1)));
        s2 = D_004D32E0[p1];
        break;
    case 2:
        s1 = 0x6EE;
        s0 = 9;
        AwardPrepare__19CB3HelpBarComponentFPCUs(&D_01E89788, func_00271A00(&D_0051BA44, func_003F5F50(p1)));
        s2 = D_004D3290[p1];
        self->field_8 = 12.01201248f;
        break;
    case 3:
        s1 = 0x9BD;
        s0 = 6;
        s2 = D_004D3230[p1];
        loc = D_004D3200[p1];
        self->field_8 = 8.475142479f;
        break;
    case 4:
        s1 = 0x6ED;
        s0 = 6;
        AwardPrepare__19CB3HelpBarComponentFPCUs(&D_01E89788, func_00271A00(&D_0051BA44, func_003F5E90(p1)));
        s2 = D_004D3260[p1];
        break;
    case 5: {
        const unsigned short *fp = func_00271A00(&D_0051BA44, GetTrophySpecialCondition__22CB3HardCodedTrophyListFi(p1));
        s1 = 0x6EC;
        s0 = 7;
        const unsigned short *a = func_00271A00(&D_0051BA44, func_003F5E00(p1));
        int cd = GetHeadlineCrashDamage__24CB3HardCodedHeadlineListFi(p1);
        s2 = Length__10CGtUnicodeFPCUs(fp) + 0x42;
        unsigned short *buf = (unsigned short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, s2 + Length__10CGtUnicodeFPCUs(D_004D3350));
        func_001A3AA0(buf, a, &cd);
        Append__10CGtUnicodeFPUsPCUs(buf, D_004D3350);
        Append__10CGtUnicodeFPUsPCUs(buf, fp);
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, buf, false, 80.0f);
        s2 = D_004D32F0[p1];
        break;
    }
    case 11:
        s1 = 0xCB8;
        s0 = 7;
        s2 = 0x24;
        break;
    case 10:
        s1 = 0xCB8;
        s0 = 7;
        if (p1 < 2) p1 = 1 - p1;
        s2 = p1 + 0x23;
        break;
    case 9:
        s1 = 0xCB9;
        s0 = 5;
        if (p1 < 2) p1 = 1 - p1;
        s2 = p1 + 0x23;
        break;
    case 8:
        s1 = D_004D3328[p1];
        s0 = 5;
        s2 = D_004D3318[p1];
        if (p1 == 2) {
            self->field_F = 1;
            self->field_8 = -1.0f;
            s7 = false;
        } else if (p2 == 0) {
            Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, func_00271A00(&D_0051BA44, D_004D3338[p1]), false, 80.0f);
        }
        break;
    default:
        break;
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 4);
    func_00130C30(&D_0051A6A8, s2);
    if (p2 != 0) {
        func_0031ECD0(&D_01E89800, 0x10, 3);
        self->field_E = 1;
    } else {
        func_0031ECD0(&D_01E89800, 0, 3);
        self->field_E = 0;
        if (s7) func_00456550(&D_01E8F2D8, p0, loc);
    }
    if (self->field_F != 0) func_00461DF0(&D_01E8FFF0, p2);
    if (s1 == 0x55C || s1 == 0xFA5) {
        Prepare__19CB3HeadingComponentFQ219CB3HeadingComponent12EHeadingType(&D_01E89518, s0);
    } else {
        func_00319C80(&D_01E89518, s1, s0);
    }
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    self->field_4 = 0;
    self->field_C = 0;
    self->field_D = 0;
    return 1;
}
