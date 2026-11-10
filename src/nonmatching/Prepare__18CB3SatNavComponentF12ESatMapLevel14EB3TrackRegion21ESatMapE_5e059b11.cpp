// NONMATCHING: Prepare__18CB3SatNavComponentF12ESatMapLevel14EB3TrackRegion21ESatMapEnterDirection -- retail 839 / ours 839 instructions, 5 in changed runs
// big2: 839/839, frame equal, 5 changed. Left: two 8-byte stack temporaries swapped -- the field_10 = (0.4167, 0.40625) copy temp (retail 0x1B8, ours 0x1B0) and the zoom block's (656, 0) backdrop temp (retail 0x1B0, ours 0x1B8); the 0x298 copy and every other slot match. Tried: helper returning CGtV2d (named r / ctor / member stores / V struct), x*1.0f, operator+, named sc local, backdrop store in an inline (with/without named local), whole zoom block as an inline -- no change; robust.py: 5 at every pad (not a layout flip). Found: bool return (retail's li v0,1 is the return value reused for field_290 = 1); int i declared after the scene pointer; separate counter k for the cross-hair loop; 'float x = (s = -s) * func_003F5A20(..).X()' for retail's in-place neg + early mul; race = true after the field_57C store; *(const EB3TrackRegion *)&field_254 [G] pun for retail's reload in the race arm of the stage-state loop; the zoomed branch is ZoomIn's work written out (not ZoomIn inlined: different neg/mul schedule); find-index loop as a static inline; switches written case 2, 0, 1.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// CB3SatNavComponent::Prepare(ESatMapLevel, EB3TrackRegion, ESatMapEnterDirection) -- hand-written from retail
// (lifter refused). [C] name: the mangled symbol. Sibling sources: B3SatNavComponent_003AAE30.cpp
// (PrepareCustomLeadIn), func_003A89A0.cpp (ZoomIn, whose body is inlined here), func_003AE120/func_003AB850.
// Numbers the region's stages (race stages first, crash stages after), picks the current stage (last one played
// in this region, else the first unlocked one), then builds the map: frame, background box, 2x3 map tiles,
// border images, cursor, cross-hair boxes; then either the custom lead-in (level 0) or the zoomed panel.

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGt2dFrame;
enum ESatMapLevel {};
enum EB3TrackRegion {};
enum ESatMapEnterDirection {};

class CB3HardCodedTrackRegionList {
public:
    static int GetSatMapImage(EB3TrackRegion, int);
};
class CB3HardCodedRaceStageList {
public:
    static int IsCorrectRegion(EB3TrackRegion, int);
    static int IsChallengeOnThisCircuit(EB3TrackRegion, int, int);
};
class CB3HardCodedCrashStageList {
public:
    static int IsCorrectRegion(EB3TrackRegion, int);
    static int IsChallengeOnThisCircuit(EB3TrackRegion, int, int);
};

struct UnkStruct_Prepare_SN_e2 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    CGt2dFrame * field_14;
    unsigned char pad_18[0x14];
    UnkStruct_Prepare_SN_e2 * field_2C;
};
struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0xF0];
    CGtV4d field_F0;
    CGtV4d field_100;
    CGtV4d field_110;
};
struct UnkStruct_D_01EA4070 {
    unsigned char pad_0[0x400];
    int field_400[1];  // [G] element count unknown
};
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_Ptr16 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E2EA8 { int field_0; };
struct UnkStruct_D_004E2E98 { unsigned char field_0; };
struct UnkStruct_Prepare_SN_prof { unsigned char pad_0[0x49A]; unsigned char field_49A; };
struct UnkStruct_D_0051BF9C { UnkStruct_Prepare_SN_prof * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Prepare_SN_V { float field_0[2]; UnkStruct_Prepare_SN_V() {} float X() const { return field_0[0]; } float Y() const { return field_0[1]; } UnkStruct_Prepare_SN_V(float x, float y) { field_0[0] = x; field_0[1] = y; } };
struct UnkStruct_Prepare_SN_3 { float field_0; float field_4; };

class CB3SatNavComponent {
public:
    bool Prepare(ESatMapLevel, EB3TrackRegion, ESatMapEnterDirection);
    void PrepareCustomLeadIn();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    CGtV2d field_10;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    struct { void * field_0; void * field_4; } field_30[2];
    unsigned char pad_40[0x124];
    void * field_164[6];
    void * field_17C[2];
    unsigned char pad_184[0x4];
    void * field_188;
    unsigned char pad_18C[0x88];
    void * field_214;
    unsigned char pad_218[0x10];
    CGt2dFrame * field_228;
    void * field_22C;
    unsigned char pad_230[0x1C];
    UnkStruct_Prepare_SN_3 * field_24C;
    unsigned char pad_250[0x4];
    EB3TrackRegion field_254;
    unsigned char pad_258[0x4];
    int field_25C;
    int field_260;
    int field_264;
    int field_268[3];
    unsigned char field_274[4];
    int field_278;
    int field_27C;
    unsigned char pad_280[0xC];
    int field_28C;
    unsigned char field_290;
    unsigned char pad_291[0x3];
    float field_294;
    float field_298;
    float field_29C;
    float field_2A0;
    int field_2A4[0xA8];
    unsigned char field_544[0x38];
    int field_57C[3][28];
    unsigned char field_6CC[0x30];
    unsigned char field_6FC;
    unsigned char pad_6FD[0x3];
    int field_700;
    int field_704;
    int field_708;
    unsigned char pad_70C[0x4];
    int field_710;
    int field_714;
    int field_718;
    unsigned char pad_71C[0x1C4];
    int field_8E0;
    unsigned char field_8E4;
    unsigned char pad_8E5;
    unsigned char field_8E6;
    unsigned char field_8E7;
    unsigned char field_8E8;
    unsigned char field_8E9;
    unsigned char pad_8EA[0x2];
    int field_8EC;
    unsigned char pad_8F0[0xC0];
    int field_9B0;
    int field_9B4;
    int field_9B8;
    int field_9BC;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01EA4070 D_01EA4070;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_004E2EA8 D_004E2EA8;
extern UnkStruct_D_004E2E98 D_004E2E98;
extern UnkStruct_Pad16 D_01EA4790, D_01EA4798, D_01EA31A0, D_01EA31A8, D_01EA31B0, D_01EA31B8, D_0051A870, D_01E7A800;
extern UnkStruct_D_Ptr16 D_01EA46B4, D_01EA46BC, D_01EA4630;
extern CGtV4d kSatNavXHairColour;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void * memset(void *, int, unsigned int);
extern "C" int func_003F5D10(int);
extern "C" int func_003EA530(int);
extern "C" int func_003F5C00(int, int);
extern "C" int func_003AFCE0(CB3SatNavComponent *, int, int);
extern "C" int func_003E9750(int, int, void *);
extern "C" int func_003E8EA0(int, int, void *);
extern "C" int func_00136400(void *);
extern "C" int func_00136380(void *);
extern "C" int func_00136110(void *, int, int);
extern "C" int func_00135F30(void *, int, int);
extern "C" int func_003E9CB0(int, int);
extern "C" int func_003E9030(int, int);
extern "C" CGt2dFrame * ConstructChild__10CGt2dFrameFv(CGt2dFrame *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(CGt2dFrame *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const void *, const void *, unsigned int);
extern "C" void func_003A6E80(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, float, float, const void *, const void *, int);
extern "C" void func_003EA4C0(int, int, float *, float *);
extern "C" void func_0041E260(void *, const CGtV2d &, const CGtV2d &, const CGtV4d, void *, float, const void *);
extern "C" void func_003AE120(CB3SatNavComponent *);
extern "C" void func_00324EB0(void *);
extern "C" void func_003A7F20(CB3SatNavComponent *, int, float);
extern "C" void func_003AD3E0(CB3SatNavComponent *);
extern "C" float func_003F58D0(int, int);
extern "C" UnkStruct_Prepare_SN_V func_003F5A20(int, int);
extern "C" void func_003AB850(CB3SatNavComponent *);
extern "C" void func_00284F50(void *);
extern "C" void func_003ADD80(CB3SatNavComponent *, float);
extern "C" void func_003A7CB0(CB3SatNavComponent *, float);

// [G] stage index of stage id `id` in the current region's panel (-1 if absent)
static inline int func_003AEFC0_inl1(CB3SatNavComponent * self, int id)
{
    int n = func_003F5D10(self->field_254);
    func_003EA530(self->field_254);
    int i;
    for (i = 0; i < n; i++) {
        if (self->field_57C[self->field_254][i] == id) return i;
    }
    return -1;
}

// [G] a CGtV2d built and returned by value (retail copies it through two 8-byte stack slots)
static inline CGtV2d func_003AEFC0_inl2(float x, float y)
{
    CGtV2d r(x, y);
    return r;
}

// 0x003AEFC0
bool CB3SatNavComponent::Prepare(ESatMapLevel level, EB3TrackRegion region, ESatMapEnterDirection dir)
{
    Prepare__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int i;
    int base = field_8;
    UnkStruct_Prepare_SN_prof * prof = D_0051BF9C.field_0;
    CGt2dFrame * root = scene->field_14;
    bool crash = false;
    bool race = false;
    D_004E2E98.field_0 = 0;
    field_8E8 = 1;
    field_8E9 = 0;
    field_9B0 = 0;
    field_28C = 0;
    field_290 = 0;
    field_6FC = 0;
    field_254 = region;
    field_700 = 0;
    int l5 = base + 5;
    field_8E7 = 0;
    field_8E0 = 0;
    int l14 = base + 14;
    field_718 = 0;
    field_25C = 0;
    int l6 = base + 6;
    field_260 = 0;
    field_8EC = 0;
    int l4 = base + 4;
    field_9B4 = 0;
    field_9B8 = 0;
    int l7 = base + 7;
    field_9BC = 0;
    if (dir != 2) {
        field_8E6 = 0;
    }
    memset(field_544, 0, 0x38);
    {
        int n = func_003F5D10(field_254);
        int nr = 0;
        int nc = func_003EA530(field_254);
        for (i = 0; i < n; i++) {
            if (func_003F5C00(field_254, i) == 0x2F) {
                field_57C[field_254][i] = nr;
                race = true;
                nr++;
            } else {
                crash = true;
                field_57C[field_254][i] = nc;
                nc++;
            }
            func_003AFCE0(this, field_254, i);
        }
    }
    {
        UnkStruct_Prepare_SN_prof * p = D_0051BF9C.field_0;
        int n = func_003F5D10(field_254);
        int m = func_003EA530(field_254);
        for (i = 0; i < n; i++) {
            int id = field_57C[field_254][i];
            if (id < m) {
                field_2A4[i] = func_003E9750(*(const EB3TrackRegion *)&field_254, id, p);
            } else {
                field_2A4[i] = func_003E8EA0(field_254, id, p);
            }
        }
    }
    if (dir != 2) {
        field_278 = -1;
        field_27C = -1;
        if ((prof->field_49A != 0 || !crash) && race) {
            int r = func_00136400(prof);
            for (i = 0; i < 0x49; i++) {
                if (CB3HardCodedRaceStageList::IsCorrectRegion(field_254, i) && func_00136110(prof, i, r)) {
                    field_264 = func_003E9CB0(field_254, i);
                    field_27C = func_003AEFC0_inl1(this, field_264);
                    field_25C = i;
                    field_8E6 = 0;
                    break;
                }
            }
        } else if (crash) {
            int r = func_00136380(prof);
            for (i = 0; i < 100; i++) {
                if (CB3HardCodedCrashStageList::IsCorrectRegion(field_254, i) && func_00135F30(prof, i, r)) {
                    field_264 = func_003E9030(field_254, i);
                    field_27C = func_003AEFC0_inl1(this, field_264);
                    field_25C = i;
                    field_8E6 = 1;
                    break;
                }
            }
        }
        if (field_27C == -1) {
            field_264 = field_268[field_254];
            if (field_264 != -1) {
                field_27C = func_003AEFC0_inl1(this, field_264);
                field_8E6 = field_274[field_254];
            } else {
                int n = func_003F5D10(field_254);
                for (field_27C = 0; field_27C < n; field_27C++) {
                    if (field_2A4[field_27C] != 0) {
                        field_264 = field_57C[field_254][field_27C];
                        field_8E6 = func_003F5C00(field_254, field_27C) != 0x2F;
                        break;
                    }
                }
            }
            field_25C = -1;
            if (field_8E6 != 0) {
                for (i = 0; i < 100; i++) {
                    if (CB3HardCodedCrashStageList::IsChallengeOnThisCircuit(field_254, i, field_264)) {
                        field_25C = i;
                        break;
                    }
                }
            } else {
                for (i = 0; i < 0x49; i++) {
                    if (CB3HardCodedRaceStageList::IsChallengeOnThisCircuit(field_254, i, field_264)) {
                        field_25C = i;
                        break;
                    }
                }
            }
        }
        field_268[field_254] = field_264;
        field_274[field_254] = field_8E6;
    } else {
        field_264 = field_57C[field_254][field_27C];
    }
    field_704 = 0;
    field_708 = 0;
    field_710 = 0;
    D_004E2EA8.field_0 = 0;
    scene->field_2C[l6].field_0 = 0x10;
    scene->field_2C[l14].field_0 = 8;
    field_228 = ConstructChild__10CGt2dFrameFv(root);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(field_228);
    field_214 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l7, field_228);
    field_10 = func_003AEFC0_inl2(0.41666666f, 0.40625f);
    i = 0;
    do {
        field_164[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l4, field_228);
        i++;
    } while (i < 6);
    i = 0;
    do {
        field_17C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l14, root);
        i++;
    } while (i < 2);
    Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(field_214, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 480.0f), CGtV4d(0.0f, 0.0f, 0.0f, 0.0f));
    i = 0;
    do {
        int row = i * 3;
        int j = 0;
        float y = 512.0f * (float)i;
        do {
            int k = j + row;
            int img = CB3HardCodedTrackRegionList::GetSatMapImage(field_254, k);
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(field_164[k], CGtV2d(512.0f * (float)j, y), CGtV2d(0.0f, 0.0f), CGtV2d(512.0f, 512.0f), mgr->field_110, (void *)D_01EA4070.field_400[img], &D_01EA4790, &D_01EA4798, 0);
            j++;
        } while (j < 3);
        i++;
    } while (i < 2);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(field_17C[1], CGtV2d(0.0f, 416.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 64.0f), mgr->field_110, D_01EA46B4.field_0, &D_01EA31A0, &D_01EA31A8, 0);
    func_003A6E80(field_17C[0], CGtV2d(0.0f, 384.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 32.0f), 0.0f, 1.0f, &D_01EA31B0, &D_01EA31B8, 0);
    field_188 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l6, root);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(field_188, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(656.0f, 496.0f), mgr->field_F0, D_01EA46BC.field_0, &CGtV2d(0.0625f, 0.0625f), &CGtV2d(40.9375f, 30.9375f), 0);
    func_003EA4C0(field_254, field_264, &field_294, &field_298);
    field_2A0 = 1.0f;
    field_29C = 10.0f;
    field_22C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l5, field_228);
    func_0041E260(field_22C, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), &field_294, -0.2f, D_01EA4630.field_0);
    int k = 0;
    do {
        field_30[k].field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l7, field_228);
        field_30[k].field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l7, field_228);
        Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(field_30[k].field_0, CGtV2d(-12.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(12.0f, 1024.0f), kSatNavXHairColour);
        Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(field_30[k].field_4, CGtV2d(0.0f, -6.0f), CGtV2d(0.0f, 0.0f), CGtV2d(1536.0f, 6.0f), kSatNavXHairColour);
        k++;
    } while (k < 2);
    if (level == 0) {
        func_003AE120(this);
        field_8E4 = 0;
        field_18 = 1.0f;
        field_1C = 1.0f;
        field_20 = 0.0f;
        field_24 = 0.0f;
        PrepareCustomLeadIn();
        field_28 = -12.0f;
        field_2C = -6.0f;
        func_00324EB0(&D_0051A870);
        switch (dir) {
        case 2:
            func_003A7F20(this, 1, 0.0f);
            break;
        case 0:
            func_003A7F20(this, 1, 0.0f);
            break;
        case 1:
            func_003A7F20(this, 0, 2.1f);
            break;
        }
    } else {
        func_003AD3E0(this);
        float s = 416.0f / func_003F58D0(field_254, field_27C);
        field_18 = s;
        field_1C = s;
        field_8E7 = 0;
        float x = (s = -s) * func_003F5A20(field_254, field_27C).X();
        float b = func_003F5A20(field_254, field_27C).Y();
        field_20 = x;
        field_24 = s * b;
        field_8E4 = 5;
        field_704 = 0;
        D_004E2EA8.field_0 = 0;
        field_9B4 = 0;
        field_9B8 = 0;
        func_003AB850(this);
        UnkStruct_Prepare_SN_3 * t2 = field_24C;
        if (t2 != 0) {
            *(UnkStruct_Prepare_SN_V *)t2 = UnkStruct_Prepare_SN_V(656.0f, 0.0f);
        }
        func_00284F50(&D_01E7A800);
        field_8E4 = 3;
        switch (dir) {
        case 2:
            func_003A7F20(this, 0, 2.1f);
            break;
        case 0:
            func_003A7F20(this, 1, 0.0f);
            break;
        case 1:
            func_003A7F20(this, 0, 2.1f);
            break;
        }
    }
    field_714 = 0;
    func_003ADD80(this, 0.0f);
    func_003A7CB0(this, 0.0f);
    field_290 = 1;
    return true;
}
