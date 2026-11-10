// NONMATCHING: func_00432AB0 -- retail 477 / ours 477 instructions, 20 in changed runs
// near28: 20 off (was 37). r-loop as goto loop (rtop) keeps the three j-loop pointers per pass (no pragma); int r declared before prof, int k before p2. Left: ids/cnt pointer registers swapped (s6/s7; all 6 definition orders same), default-case field_26=3 CSE'd with the case-3 compare constant (li a1,3)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

class CB3Profile {
public:
    unsigned char IsTrackUnlocked(unsigned long);
};
class CB3TrackList {
public:
    int GetTrackRegion(unsigned long);
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_0051BF9C {
    CB3Profile * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_005196A4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8961C { unsigned char pad_0[0x10]; };

// option entry at +0x28, stride 0x14 [G]
struct UnkStruct_00432AB0_opt {
    const unsigned short * field_0;
    int field_4;
    void * field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    int field_10;
};

struct UnkStruct_00432AB0 {
    unsigned char pad_0[0x20];
    int field_20;
    unsigned short field_24;
    unsigned short field_26;
    UnkStruct_00432AB0_opt field_28[3];
    unsigned char pad_64[0x64];
    unsigned short field_C8;
    unsigned short field_CA;
    int field_CC[4];
    int field_DC[4];
    int field_EC;
    unsigned long field_F0[1];
    unsigned char pad_F8[0x98];
    int field_190[1];
    unsigned char pad_194[0x4C];
    int field_1E0;
    unsigned char pad_1E4[0x4];
    unsigned long field_1E8[1];
    unsigned char pad_1F0[0x328];
    int field_518[1];
    unsigned char pad_51C[0x194];
    int field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    int field_6C4;
};

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_005196A4 D_005196A4;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E8961C D_01E8961C;
extern CB3TrackList D_005196A0;
extern unsigned long D_00519AA8[];
extern unsigned char D_0051BA44[];
extern unsigned char D_01E89518[];
extern unsigned char D_01E88A80[];
extern unsigned char D_01E89800[];
extern unsigned char D_01E894FC[];

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" unsigned long func_00432160(UnkStruct_00432AB0 *);
extern "C" unsigned long func_00432280(UnkStruct_00432AB0 *, int);
extern "C" unsigned long func_00432410(UnkStruct_00432AB0 *);
extern "C" int func_0013AD70(CB3Profile *, int, int);
extern "C" unsigned long GetCrashStageGtID__26CB3HardCodedCrashStageListFi(int);
extern "C" int func_003E9490(int, int);
extern "C" int GetTrackRegionString__27CB3HardCodedTrackRegionListF14EB3TrackRegionb(int, bool);
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int GetTrackString__21CB3HardCodedTrackListFib(int, bool);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);

// 0x00432AB0
extern "C" int func_00432AB0(UnkStruct_00432AB0 * self, int mode)
{
    int r;
    CB3Profile * prof = D_0051BF9C.field_0;
    self->field_20 = mode;
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_C8 = 0;
    self->field_CA = 5;
    self->field_518[0] = 0x2E0;
    self->field_1E8[0] = func_00432160(self);
    self->field_6B0 = 1;
    for (int i = 0; i < 100; i++) {
        if (func_0013AD70(prof, i, 0) != 0) continue;
        self->field_1E8[self->field_6B0] = GetCrashStageGtID__26CB3HardCodedCrashStageListFi(i);
        self->field_518[self->field_6B0] = func_003E9490(i, 0);
        self->field_6B0++;
    }
    if (self->field_6BC >= self->field_6B0) self->field_6BC = 0;
    self->field_CC[0] = 3;
    self->field_DC[0] = 0x2E0;
    self->field_EC = 1;
    r = 0;
rtop: {
        unsigned long * ids = D_00519AA8;
        CB3TrackList * tl = &D_005196A0;
        UnkStruct_D_005196A4 * cnt = &D_005196A4;
        for (int j = 0; j < cnt->field_0; j++) {
            unsigned long id = ids[j];
            if (!prof->IsTrackUnlocked(id)) continue;
            if (r != tl->GetTrackRegion(id)) continue;
            self->field_CC[self->field_EC] = r;
            self->field_DC[self->field_EC] = GetTrackRegionString__27CB3HardCodedTrackRegionListF14EB3TrackRegionb(r, false);
            self->field_EC++;
            break;
        }
    }
    r++;
    if (r < 3) goto rtop;
    if (self->field_6B4 >= self->field_EC) self->field_6B4 = 0;
    self->field_190[0] = 0x2E0;
    if (self->field_6B4 == 0) {
        self->field_F0[0] = func_00432410(self);
        self->field_1E0 = 1;
    } else {
        int k;
        CB3Profile * p2 = D_0051BF9C.field_0;
        int region = self->field_CC[self->field_6B4];
        self->field_F0[0] = func_00432280(self, region);
        self->field_1E0 = 1;
        for (k = 0; k < D_005196A4.field_0; k++) {
            unsigned long id = *(unsigned long *)((char *)&D_004EE040 + k * 8 + 0x2BA68);
            if (!p2->IsTrackUnlocked(id)) continue;
            if (region != D_005196A0.GetTrackRegion(id)) continue;
            self->field_F0[self->field_1E0] = id;
            self->field_190[self->field_1E0] = GetTrackString__21CB3HardCodedTrackListFib(FindTrack__21CB3HardCodedTrackListFUl(id), false);
            self->field_1E0++;
        }
    }
    if (self->field_6B8 >= self->field_1E0) self->field_6B8 = 0;
    func_00319C80(D_01E89518, 0x196, 0xE);
    unsigned char n;
    int m;
    switch (self->field_20) {
    default:
        self->field_24 = 0;
        self->field_26 = 3;
        n = self->field_EC;
        self->field_28[0].field_0 = func_00271A00(D_0051BA44, 0x2C2);
        self->field_28[0].field_8 = self->field_DC;
        self->field_28[0].field_C = n;
        self->field_28[0].field_D = 4;
        self->field_28[0].field_E = 0;
        self->field_28[0].field_10 = 0;
        self->field_28[0].field_4 = 0;
        m = self->field_1E0;
        if (m > 1) {
            self->field_28[1].field_0 = func_00271A00(D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 0;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        } else {
            self->field_28[1].field_0 = func_00271A00(D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 1;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        }
        self->field_28[2].field_0 = func_00271A00(D_0051BA44, 0x2C8);
        self->field_28[2].field_8 = &self->field_C8;
        self->field_28[2].field_C = self->field_CA - self->field_C8;
        self->field_28[2].field_D = 5;
        self->field_28[2].field_E = 0;
        self->field_28[2].field_10 = 0;
        self->field_28[2].field_4 = 0;
        func_003BE5A0(&D_01E8961C, &self->field_24, self->field_28);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6B4);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_6B8);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_6C0);
        break;
    case 1:
        self->field_24 = 0;
        self->field_26 = 2;
        n = self->field_EC;
        self->field_28[0].field_0 = func_00271A00(D_0051BA44, 0x2C2);
        self->field_28[0].field_8 = self->field_DC;
        self->field_28[0].field_C = n;
        self->field_28[0].field_D = 4;
        self->field_28[0].field_E = 0;
        self->field_28[0].field_10 = 0;
        self->field_28[0].field_4 = 0;
        m = self->field_1E0;
        if (m > 1) {
            self->field_28[1].field_0 = func_00271A00(D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 0;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        } else {
            self->field_28[1].field_0 = func_00271A00(D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 1;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        }
        func_003BE5A0(&D_01E8961C, &self->field_24, self->field_28);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6B4);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_6B8);
        break;
    case 2:
        self->field_24 = 0;
        self->field_26 = 2;
        n = self->field_EC;
        self->field_28[0].field_0 = func_00271A00(D_0051BA44, 0x2C2);
        self->field_28[0].field_8 = self->field_DC;
        self->field_28[0].field_C = n;
        self->field_28[0].field_D = 4;
        self->field_28[0].field_E = 0;
        self->field_28[0].field_10 = 0;
        self->field_28[0].field_4 = 0;
        m = self->field_1E0;
        if (m > 1) {
            self->field_28[1].field_0 = func_00271A00(D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 0;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        } else {
            self->field_28[1].field_0 = func_00271A00(D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 1;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        }
        func_003BE5A0(&D_01E8961C, &self->field_24, self->field_28);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6B4);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_6B8);
        break;
    case 3:
        self->field_24 = 0;
        self->field_26 = 1;
        n = self->field_6B0;
        self->field_28[0].field_0 = func_00271A00(D_0051BA44, 0x2D0);
        self->field_28[0].field_8 = self->field_518;
        self->field_28[0].field_C = n;
        self->field_28[0].field_D = 4;
        self->field_28[0].field_E = 0;
        self->field_28[0].field_10 = 0;
        self->field_28[0].field_4 = 0;
        func_003BE5A0(&D_01E8961C, &self->field_24, self->field_28);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6BC);
        break;
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(D_01E88A80, 0);
    func_0031ECD0(D_01E89800, 0x111, 3);
    Prepare__21CB3PromptBarComponentFv(D_01E894FC);
    self->field_6C4 = 0;
    return 1;
}


