// Hand-written; the lifter refused it (CB3OnlineGameOptionsPage setup/Prepare-like (flag, settings): goto-laid-out cold arms (found/else/ptp) after flag path; default->goto done, others return 1 (delay-slot li dup); u64 temps declared top u0,u1,u2).

// Hand-written (a170): CB3OnlineGameOptionsPage::Prepare-like setup (flag, settings) [L]
class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageGtID(int);
};
class CB3Profile { public: unsigned char IsTrackUnlocked(unsigned long); unsigned char pad_0[0x1]; };
class CB3TrackList { public: int GetTrackRegion(unsigned long); unsigned char IsTrackPointToPoint(unsigned long); unsigned char pad_0[0x4]; int field_4; unsigned char pad_8[0x400]; };
struct UnkStruct_D_0051BF9C { CB3Profile * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8961C {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_003A03B0_set {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned int field_18;
    unsigned int field_1C;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28;
};
struct UnkStruct_0039D900 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned short field_6;
    void * field_8;
    int field_C;
    void * field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char pad_17;
    unsigned char * field_18;
    void * field_1C;
    int field_20;
    void * field_24;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char field_2A;
    unsigned char pad_2B;
    int field_2C;
    void * field_30;
    int field_34;
    void * field_38;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    unsigned char pad_3F;
    int field_40;
    void * field_44;
    int field_48;
    void * field_4C;
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char pad_53;
    int field_54;
    void * field_58;
    int field_5C;
    void * field_60;
    unsigned char field_64;
    unsigned char field_65;
    unsigned char field_66;
    unsigned char pad_67;
    int field_68;
    void * field_6C;
    int field_70;
    void * field_74;
    unsigned char field_78;
    unsigned char field_79;
    unsigned char field_7A;
    unsigned char pad_7B;
    int field_7C;
    void * field_80;
    int field_84;
    int field_88;
    unsigned char field_8C;
    unsigned char field_8D;
    unsigned char field_8E;
    unsigned char pad_8F;
    int field_90;
    unsigned short field_94;
    unsigned short field_96;
    unsigned char field_98;
    unsigned char field_99;
    unsigned char field_9A;
    unsigned char field_9B;
    unsigned char field_9C;
    unsigned char pad_9D[3];
    int field_A0[0x9];
    int field_C4[0x9];
    int field_E8;
    void * field_EC;
    UnkStruct_003A03B0_set * field_F0;
    unsigned char field_F4;
    unsigned char pad_F5[3];
    int field_F8;
    int field_FC[4];
    void * field_10C[4];
    int field_11C;
    unsigned long field_120[20];
    void * field_1C0[20];
    int field_210;
    unsigned char pad_214[0x4];
    unsigned long field_218[1];
    unsigned char pad_220[0x4C0];
    int field_6E0;
    unsigned int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
    int field_6F8;
    int field_6FC;
    unsigned char pad_700[0x1];
    unsigned char field_701;
    unsigned char field_702;
    unsigned char pad_703[0x1];
    int field_704;
};
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_P D_0051BA44, D_01E89800, D_004C9B30;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_B D_01E89626;
extern UnkStruct_D_01E89810 D_01E89810;
extern int D_004C9B50[];
extern "C" unsigned long func_0039EC90(void *);
extern "C" int func_0013AD70(void *, int, int);
extern "C" int func_0013A6D0(CB3Profile *, int);
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void *AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" unsigned long func_0039EF40(void *);
extern "C" unsigned long func_0039EDB0(void *, int);
extern "C" unsigned long func_0039EC90(void *);
extern "C" void func_0039E5F0(void *);
extern "C" void func_0039DE20(void *);
extern "C" void func_0039D900(void *);
extern "C" void func_0039D5C0(void *, unsigned long);
extern "C" void *FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int func_003EAA60(void *);
extern UnkStruct_P D_01E90438, D_01E89518, D_01E88A80, D_01E894FC;
union UnkStruct_003A03B0_u64 { unsigned long l; struct { int lo; int hi; } s; };
extern "C" void *GetTrackRegionString__27CB3HardCodedTrackRegionListF14EB3TrackRegionb(int, bool);
extern "C" void func_003BC360(void *, int, int);
extern "C" void func_003BC540(void *, int, int);
extern CB3TrackList D_005196A0;
struct UnkStruct_D_I16 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_I16 D_005196A4;
extern unsigned long D_00519AA8[];
extern "C" int func_003E9490(int, int);
extern "C" void *func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);

static inline int func_003A03B0_inl1(UnkStruct_0039D900 * self, int i)
{
    unsigned char *p = self->field_18;
    if (p == 0 || i < 0 || i > self->field_14) return 0;
    return *(unsigned char *)((char *)p + i);
}
static inline void func_003A03B0_inl2(UnkStruct_0039D900 * self, int a, int b)
{
    self->field_A0[self->field_E8] = a;
    self->field_C4[self->field_E8] = b;
    self->field_E8 = self->field_E8 + 1;
}
static inline bool func_003A03B0_inl3(int id, unsigned x)
{
    if (id != 8) return true;
    if (x < 2) return false;
    return true;
}

// 0x003A03B0
extern "C" int func_003A03B0(UnkStruct_0039D900 * self, bool flag, UnkStruct_003A03B0_set * settings)
{
    int s1;
    int s0;
    UnkStruct_003A03B0_u64 u0, u1, u2;
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_EC = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 3);
    if (flag) {
        func_00319C80(&D_01E89518, 0x42C, 0xE);
        self->field_F8 = 0x2D9;
    } else {
        func_00319C80(&D_01E89518, 0xB7, 0xE);
        self->field_F8 = 0x2C1;
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    func_0031ECD0(&D_01E89800, 0x111, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    self->field_F4 = 0;
    self->field_F0 = settings;
    self->field_6E4 = self->field_F0->field_14;
    self->field_6F0 = (unsigned char)(self->field_F0->field_1C >> 24);
    if ((unsigned char)(self->field_F0->field_18 >> 16) == 1) {
        self->field_6FC = 1;
    } else {
        self->field_6FC = 0;
    }
    self->field_6E8 = 0;
    self->field_6EC = 0;
    self->field_1C0[0] = (void *)0x2E0;
    self->field_120[0] = func_0039EF40(self);
    self->field_210 = 1;
    self->field_94 = 1;
    self->field_96 = 6;
    self->field_98 = self->field_F0->field_8 >= 7;
    self->field_99 = self->field_F0->field_8 >= 7;
    self->field_9A = self->field_F0->field_8 != 2;
    self->field_9B = self->field_F0->field_8 != 2;
    self->field_9C = 0;
    if (self->field_F0->field_8 >= 7) {
        self->field_6E4 = 4;
    }
    if (self->field_F0->field_8 != 2 && (unsigned int)(self->field_6E4 - 2) < 2) {
        self->field_6E4 = 0;
    }
    self->field_4 = 0;
    self->field_6 = 5;
    self->field_E8 = 0;
    func_003A03B0_inl2(self, 0x3D4, 0);
    func_003A03B0_inl2(self, 0x3D3, 1);
    s1 = 0;
    goto test2;
body2:
    s0 = s1 + 2;
    if (func_0013A6D0(D_0051BF9C.field_0, s1)) {
        if (func_003A03B0_inl3(s0, self->field_6E4)) {
            func_003A03B0_inl2(self, D_004C9B50[s0], s0);
        }
    }
    s1++;
test2:
    if (s1 < 7) goto body2;
    self->field_6F4 = 0;
    self->field_6F8 = 0;
    {
        int j;
        for (j = 0; j < self->field_E8; j++) {
            int * p = &self->field_C4[j];
            if (self->field_C4[j] == (unsigned char)(self->field_F0->field_1C >> 8)) self->field_6F4 = j;
            if (*p == (unsigned char)(self->field_F0->field_18 >> 8)) self->field_6F8 = j;
        }
    }
    switch (self->field_6E4) {
    case 0:
        func_0039E5F0(self);
        break;
    case 1:
        func_0039DE20(self);
        break;
    case 2:
    case 3:
    case 4:
        func_0039D900(self);
        break;
    default:
        break;
    }
    if (flag) goto flagpath;
    switch (self->field_6E4) {
    case 0:
    case 1:
        if (self->field_701 == 0) goto c7d8;
        if (self->field_702 == 0) goto c7d8;
        self->field_120[0] = func_0039EF40(self);
        goto c868;
    c7d8:
        if (self->field_702 == 0) goto ca24;
        u0.s.lo = self->field_F0->field_C;
        u0.s.hi = self->field_F0->field_20;
        self->field_120[0] = func_0039EDB0(self, func_003EAA60(FindTrack__21CB3HardCodedTrackListFUl(u0.l)));
        s1 = 0;
        goto c848;
    c820:
        if (self->field_FC[s1] == D_005196A0.GetTrackRegion(self->field_120[0])) goto ca08;
        s1++;
    c848:
        if (s1 < 4) goto c820;
    c854:
        func_003BC360(&D_01E8961C, 1, 1);
    c868:
        if (D_005196A0.IsTrackPointToPoint(self->field_120[self->field_6EC])) goto ca4c;
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, self->field_6F0);
        func_003BC360(&D_01E8961C, 3, 1);
        break;
    case 2:
    case 3:
    case 4:
        if (self->field_702) {
            self->field_218[0] = func_0039EC90(self);
        } else {
            u2.s.lo = self->field_F0->field_24;
            u2.s.hi = self->field_F0->field_28;
            func_0039D5C0(self, u2.l);
        }
        break;
    default:
        goto done;
    }
done:
    return 1;
flagpath:
    self->field_6EC = 0;
    switch (self->field_6E4) {
    case 0:
    case 1:
        self->field_120[0] = func_0039EF40(self);
        if (D_005196A0.IsTrackPointToPoint(self->field_120[self->field_6EC])) goto cb9d8;
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, self->field_6F0);
        func_003BC360(&D_01E8961C, 3, 1);
        break;
    case 2:
    case 3:
    case 4:
        self->field_218[0] = func_0039EC90(self);
        break;
    }
    goto done;
cb9d8:
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, 1);
    func_003BC360(&D_01E8961C, 3, 0);
    goto done;
ca08:
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, s1);
    self->field_6E8 = s1;
    goto c854;
ca24:
    u1.s.lo = self->field_F0->field_C;
    u1.s.hi = self->field_F0->field_20;
    func_0039D5C0(self, u1.l);
    goto c868;
ca4c:
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, 1);
    func_003BC360(&D_01E8961C, 3, 0);
    goto done;
}
