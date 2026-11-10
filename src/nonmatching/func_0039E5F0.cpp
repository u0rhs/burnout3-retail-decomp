// NONMATCHING: func_0039E5F0 -- retail 421 / ours 421 instructions, 12 in changed runs
// s314: L274 form (region scan as a static inline with pointer locals cnt/tl/ids from one CB3TrackList struct D_005196A0 {+4 count, +0x408 ids}, goto-form outer r loop) now materialises the three addresses per outer pass like retail; 12 off = s-register swaps only (profile s3 vs retail s2 / counter s2 vs s3; ids s7 vs s6 / cnt s6 vs s7). Swept 24 inner decl orders x 4 profile decls + sreg run 2 rounds. Twin func_0039DE20 takes the same inline (+ one extra b) but its mwperm archive (9) is still better
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// Hand-written (a170): sibling of func_0039D900 / func_0039D5C0 (CB3OnlineGameOptionsPage setup, region/track variant)
class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageGtID(int);
};
class CB3Profile { public: unsigned char IsTrackUnlocked(unsigned long); unsigned char pad_0[0x1]; };
class CB3TrackList { public: int GetTrackRegion(unsigned long); unsigned char IsTrackPointToPoint(unsigned long); unsigned char pad_0[0x4]; int field_4; unsigned char pad_8[0x400]; unsigned long field_408[1]; };
struct UnkStruct_D_0051BF9C { CB3Profile * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8961C {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[0x8]; };
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
    unsigned char field_98[8];
    int field_A0[0x9];
    int field_C4[0x9];
    int field_E8;
    unsigned char pad_EC[0x10];
    int field_FC[4];
    void * field_10C[4];
    int field_11C;
    unsigned long field_120[20];
    void * field_1C0[20];
    int field_210;
    unsigned char pad_214[0x4];
    unsigned char pad_218[0x4C8];
    int field_6E0;
    unsigned int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
    int field_6F8;
    int field_6FC;
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

static inline int func_0039E5F0_inl1(UnkStruct_0039D900 * self, int i)
{
    unsigned char *p = self->field_18;
    if (p == 0 || i < 0 || i > self->field_14) return 0;
    return *(unsigned char *)((char *)p + i);
}
static inline void func_0039E5F0_inl2(UnkStruct_0039D900 * self, int a, int b)
{
    self->field_A0[self->field_E8] = a;
    self->field_C4[self->field_E8] = b;
    self->field_E8 = self->field_E8 + 1;
}
static inline bool func_0039E5F0_inl3(int id, unsigned x)
{
    if (id != 8) return true;
    if (x < 2) return false;
    return true;
}

// [G] inlined region scan (L274 form: explicit pointer locals in the inline give retail's once-per-pass address loads)
static inline void func_0039E5F0_inl4(UnkStruct_0039D900 * self, CB3Profile * profile, int r)
{
    int s3;
    CB3TrackList *tl = &D_005196A0;
    int *cnt = &D_005196A0.field_4;
    unsigned long *ids = D_005196A0.field_408;
    for (s3 = 0; s3 < *cnt; s3++) {
        unsigned long id = ids[s3];
        if (profile->IsTrackUnlocked(id)) {
            if (r == tl->GetTrackRegion(id)) {
                self->field_FC[self->field_11C] = r;
                self->field_10C[self->field_11C] = GetTrackRegionString__27CB3HardCodedTrackRegionListF14EB3TrackRegionb(r, false);
                self->field_11C = self->field_11C + 1;
                return;
            }
        }
    }
}

// 0x0039DE20
extern "C" void func_0039E5F0(UnkStruct_0039D900 * self)
{
    int i;
    int s1;
    int s0;
    int r;
    CB3Profile * profile = D_0051BF9C.field_0;
    self->field_FC[0] = 3;
    self->field_10C[0] = (void *)0x2E0;
    self->field_11C = 1;
    r = 0;
rtop:
    func_0039E5F0_inl4(self, profile, r);
    r++;
    if (r < 3) goto rtop;
    unsigned short c = self->field_4;
    if (c >= 5) {
        self->field_4 = 4;
        self->field_6 = 5;
    } else {
        self->field_4 = c;
        self->field_6 = 5;
    }
    self->field_8 = func_00271A00(&D_0051BA44, 718);
    self->field_10 = &D_004C9B30;
    self->field_14 = 5;
    self->field_15 = 4;
    self->field_16 = 0;
    self->field_18 = self->field_98;
    self->field_C = 0;
    s1 = func_0039E5F0_inl1(self, self->field_6E4);
    s0 = (unsigned char)self->field_11C;
    self->field_1C = func_00271A00(&D_0051BA44, 706);
    self->field_24 = &self->field_10C[0];
    self->field_28 = s0;
    self->field_29 = 4;
    self->field_2A = s1;
    self->field_2C = 0;
    self->field_20 = 0;
    s0 = self->field_210;
    if (s0 > 1) {
        s1 = func_0039E5F0_inl1(self, self->field_6E4);
        self->field_30 = func_00271A00(&D_0051BA44, 719);
        self->field_38 = &self->field_1C0[0];
        self->field_3C = s0;
        self->field_3D = 4;
        self->field_3E = s1;
        self->field_40 = 0;
        self->field_34 = 0;
    } else {
        self->field_30 = func_00271A00(&D_0051BA44, 719);
        self->field_38 = &self->field_1C0[0];
        self->field_3C = s0;
        self->field_3D = 4;
        self->field_3E = 1;
        self->field_40 = 0;
        self->field_34 = 0;
    }
    s0 = func_0039E5F0_inl1(self, self->field_6E4);
    self->field_44 = func_00271A00(&D_0051BA44, 721);
    self->field_4C = &self->field_94;
    self->field_50 = self->field_96 - self->field_94;
    self->field_51 = 5;
    self->field_52 = s0;
    self->field_54 = 0;
    self->field_48 = 0;
    self->field_E8 = 0;
    func_0039E5F0_inl2(self, 0x3D4, 0);
    func_0039E5F0_inl2(self, 0x3D3, 1);
    s1 = 0;
    goto test2;
body2:
    s0 = s1 + 2;
    if (func_0013A6D0(D_0051BF9C.field_0, s1)) {
        if (func_0039E5F0_inl3(s0, self->field_6E4)) {
            func_0039E5F0_inl2(self, D_004C9B50[s0], s0);
        }
    }
    s1++;
test2:
    if (s1 < 7) goto body2;
    s1 = func_0039E5F0_inl1(self, self->field_6E4);
    s0 = (unsigned char)self->field_E8;
    self->field_58 = func_00271A00(&D_0051BA44, 723);
    self->field_60 = &self->field_A0[0];
    self->field_64 = s0;
    self->field_65 = 4;
    self->field_66 = s1;
    self->field_68 = 0;
    self->field_5C = 0;
    if (D_01E89626.field_0 != 0) {
        ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
    }
    func_003BE5A0(&D_01E8961C, &self->field_4, &self->field_8);
    if (!(self->field_6F4 < self->field_E8)) self->field_6F4 = 0;
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6E4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_6E8);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_6EC);
    if (D_005196A0.IsTrackPointToPoint(self->field_120[self->field_6EC])) {
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, 1);
        func_003BC360(&D_01E8961C, 3, 0);
    } else {
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, self->field_6F0);
        func_003BC360(&D_01E8961C, 3, (func_0039E5F0_inl1(self, self->field_6E4) != 0) ^ 1);
    }
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 4, self->field_6F4);
    if (func_0039E5F0_inl1(self, self->field_6E4)) {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~0x10UL, 3);
    } else {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 0x10, 3);
    }
}
