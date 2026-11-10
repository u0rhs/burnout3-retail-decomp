// NONMATCHING: func_00433C80 -- retail 462 / ours 462 instructions, 4 in changed runs
// fix2 (2026-11-01): GetTrackRegionString takes EB3TrackRegion (retail symbol ...F14EB3TrackRegionb; int mangled to a missing symbol) | Before: near10: 4 off (was 5). 'int j = 0;' declared between tl and ids (cnt, tl, j, ids) fixed the j=0 slot partly; left: ids/cnt base registers swap (retail ids=s6, cnt=s7) and retail's 'move s1,zero' sits right after the three luis. const/const-pointer forms, D_004EE040+0x2BA68 view, 24 decl permutations incl. j, sreg all tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.


// NONMATCHING: func_00433C80 -- retail 462 / ours 462 instructions, 5 in changed runs
// L274: 462/462, 5 changed: only the region-scan inline's hoisted base registers swap (retail ids=s6, count ptr=s7; ours reversed) plus the j=0 slot. Explicit pointer locals in the inline give retail's per-pass hoist and frame; the mode dispatch is the nested if form (!=3 && !=2, then !=1). Tried all 6 decl orders, goto-form loop, opt_loop_invariants.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_00433C80 -- [G] DNAT low row: CB3MultiplayerGameOptionsPage::Prepare(EB3MenuChoicesTwoPlayer)
// (research/proto/new_names.csv, low; not applied). Hand-written (L274) from the asm after the proven siblings
// func_00433250 / func_00433370 / func_00433560 (track-list scans) and func_00399130 (option-item rows).
// Field names are placeholders; every type is [G].

class CB3Profile {
public:
    unsigned char IsTrackUnlocked(unsigned long);
    unsigned char pad_0[0x1];
};
class CB3TrackList {
public:
    bool IsTrackMarathon(unsigned long);
    bool IsTrackPointToPoint(unsigned long);
    int GetTrackRegion(unsigned long);
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x400];
    unsigned long field_408[1];
};
class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageGtID(int);
};
class CB3HardCodedTrackList {
public:
    static void *FindTrack(unsigned long);
    static unsigned short *GetTrackString(int, bool);
};
enum EB3TrackRegion { };   // [C] name: the mangled GetTrackRegionString symbol
class CB3HardCodedTrackRegionList {
public:
    static unsigned short *GetTrackRegionString(EB3TrackRegion, bool);   // [C] retail symbol ...F14EB3TrackRegionb
};
struct UnkStruct_D_0051BF9C {
    CB3Profile * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_00433C80_P { unsigned char pad_0[0x10]; };
struct UnkStruct_00433C80_item {
    unsigned short *field_0;
    int field_4;
    void *field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    int field_10;
};
struct UnkStruct_00433C80 {
    unsigned char pad_0[0x20];
    int field_20;
    short field_24;
    short field_26;
    UnkStruct_00433C80_item field_28[3];
    unsigned char pad_64[0x64];
    unsigned short field_C8;
    unsigned short field_CA;
    int field_CC[4];
    unsigned short *field_DC[4];
    int field_EC;
    unsigned long field_F0[20];
    unsigned short *field_190[20];
    int field_1E0;
    unsigned char pad_1E4[4];
    unsigned long field_1E8[102];
    int field_518[101];
    unsigned char pad_6AC[4];
    int field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    int field_6C4;
};
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern CB3TrackList D_005196A0;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_00433C80_P D_01E89518, D_0051BA44, D_01E8961C, D_01E88A80, D_01E89800, D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" unsigned long func_00433250(UnkStruct_00433C80 *);
extern "C" unsigned long func_00433370(UnkStruct_00433C80 *, int);
extern "C" unsigned long func_00433560(UnkStruct_00433C80 *);
extern "C" int func_0013AD70(CB3Profile *, int, int);
extern "C" int func_003E9490(int, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);

// [G] inlined region scan: adds region r once if any unlocked circuit track lies in it
static inline void func_00433C80_inl1(UnkStruct_00433C80 *self, CB3Profile *profile, int r)
{
    int *cnt = &D_005196A0.field_4;
    CB3TrackList *tl = &D_005196A0;
    int j = 0;
    unsigned long *ids = D_005196A0.field_408;
    for (; j < *cnt; j++) {
        unsigned long id = ids[j];
        if (!tl->IsTrackMarathon(id) && !tl->IsTrackPointToPoint(id) && profile->IsTrackUnlocked(id)
            && r == tl->GetTrackRegion(id)) {
            self->field_CC[self->field_EC] = r;
            self->field_DC[self->field_EC] = CB3HardCodedTrackRegionList::GetTrackRegionString((EB3TrackRegion)r, 0);
            self->field_EC++;
            return;
        }
    }
}

// 0x00433C80
extern "C" bool func_00433C80(UnkStruct_00433C80 *self, int mode)
{
    int i;
    int r;
    CB3Profile *profile = D_0051BF9C.field_0;
    self->field_20 = mode;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_C8 = 0;
    self->field_CA = 4;
    if (self->field_6C0 > 4) self->field_6C0 = 4;
    self->field_518[0] = 0x2E0;
    self->field_1E8[0] = func_00433250(self);
    self->field_6B0 = 1;
    for (i = 0; i < 100; i++) {
        if (func_0013AD70(profile, i, 0) == 0) {
            self->field_1E8[self->field_6B0] = CB3HardCodedCrashStageList::GetCrashStageGtID(i);
            self->field_518[self->field_6B0] = func_003E9490(i, 0);
            self->field_6B0++;
        }
    }
    if (self->field_6BC >= self->field_6B0) self->field_6BC = 0;
    self->field_CC[0] = 3;
    self->field_DC[0] = (unsigned short *)0x2E0;
    self->field_EC = 1;
    r = 0;
rtop:
    func_00433C80_inl1(self, profile, r);
    r++;
    if (r < 3) goto rtop;
    if (self->field_6B4 >= self->field_EC) self->field_6B4 = 0;
    self->field_190[0] = (unsigned short *)0x2E0;
    if (self->field_6B4 == 0) {
        self->field_F0[0] = func_00433560(self);
        self->field_1E0 = 1;
    } else {
        int k;
        CB3Profile *p2 = D_0051BF9C.field_0;
        int reg = self->field_CC[self->field_6B4];
        self->field_F0[0] = func_00433370(self, reg);
        self->field_1E0 = 1;
        for (k = 0; k < D_005196A0.field_4; k++) {
            unsigned long id = *(unsigned long *)((char *)&D_004EE040 + k * 8 + 0x2BA68);
            if (!D_005196A0.IsTrackMarathon(id) && !D_005196A0.IsTrackPointToPoint(id) && p2->IsTrackUnlocked(id)
                && reg == D_005196A0.GetTrackRegion(id)) {
                self->field_F0[self->field_1E0] = id;
                self->field_190[self->field_1E0] = CB3HardCodedTrackList::GetTrackString((int)CB3HardCodedTrackList::FindTrack(id), 0);
                self->field_1E0++;
            }
        }
    }
    if (self->field_6B8 >= self->field_1E0) self->field_6B8 = 0;
    if (self->field_20 != 3 && self->field_20 != 2) {
        if (self->field_20 != 1) {
        func_00319C80(&D_01E89518, 0x15F, 0xE);
        self->field_24 = 0;
        self->field_26 = 3;
        unsigned char n = self->field_EC;
        self->field_28[0].field_0 = func_00271A00(&D_0051BA44, 0x2C2);
        self->field_28[0].field_8 = &self->field_DC;
        self->field_28[0].field_C = n;
        self->field_28[0].field_D = 4;
        self->field_28[0].field_E = 0;
        self->field_28[0].field_10 = 0;
        self->field_28[0].field_4 = 0;
        int m = self->field_1E0;
        if (m > 1) {
            self->field_28[1].field_0 = func_00271A00(&D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = &self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 0;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        } else {
            self->field_28[1].field_0 = func_00271A00(&D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = &self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 1;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        }
        self->field_28[2].field_0 = func_00271A00(&D_0051BA44, 0x2C8);
        self->field_28[2].field_8 = &self->field_C8;
        self->field_28[2].field_C = self->field_CA - self->field_C8;
        self->field_28[2].field_D = 5;
        self->field_28[2].field_E = 0;
        self->field_28[2].field_10 = 0;
        self->field_28[2].field_4 = 0;
        func_003BE5A0(&D_01E8961C, &self->field_24, &self->field_28);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6B4);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_6B8);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_6C0);
        } else {
        func_00319C80(&D_01E89518, 0x160, 0xE);
        self->field_24 = 0;
        self->field_26 = 2;
        unsigned char n = self->field_EC;
        self->field_28[0].field_0 = func_00271A00(&D_0051BA44, 0x2C2);
        self->field_28[0].field_8 = &self->field_DC;
        self->field_28[0].field_C = n;
        self->field_28[0].field_D = 4;
        self->field_28[0].field_E = 0;
        self->field_28[0].field_10 = 0;
        self->field_28[0].field_4 = 0;
        int m = self->field_1E0;
        if (m > 1) {
            self->field_28[1].field_0 = func_00271A00(&D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = &self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 0;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        } else {
            self->field_28[1].field_0 = func_00271A00(&D_0051BA44, 0x2CF);
            self->field_28[1].field_8 = &self->field_190;
            self->field_28[1].field_C = m;
            self->field_28[1].field_D = 4;
            self->field_28[1].field_E = 1;
            self->field_28[1].field_10 = 0;
            self->field_28[1].field_4 = 0;
        }
        func_003BE5A0(&D_01E8961C, &self->field_24, &self->field_28);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6B4);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_6B8);
        }
    } else {
        switch (self->field_20) {
        case 2:
        default:
            func_00319C80(&D_01E89518, 0x162, 0xE);
            break;
        case 3:
            func_00319C80(&D_01E89518, 0x163, 0xE);
            break;
        }
        self->field_24 = 0;
        self->field_26 = 1;
        unsigned char n = self->field_6B0;
        self->field_28[0].field_0 = func_00271A00(&D_0051BA44, 0x2D0);
        self->field_28[0].field_8 = &self->field_518;
        self->field_28[0].field_C = n;
        self->field_28[0].field_D = 4;
        self->field_28[0].field_E = 0;
        self->field_28[0].field_10 = 0;
        self->field_28[0].field_4 = 0;
        func_003BE5A0(&D_01E8961C, &self->field_24, &self->field_28);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6BC);
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    func_0031ECD0(&D_01E89800, 0x111, 3);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    self->field_6C4 = 0;
    return true;
}




