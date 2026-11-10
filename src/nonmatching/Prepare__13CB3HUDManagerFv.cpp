// NONMATCHING: Prepare__13CB3HUDManagerFv -- retail 409 / ours 409 instructions, 14 in changed runs
// near36: 409/409, 14 changed (was 373/409, 78). Split-screen rects as struct { CGtV2d s; CGtV2d p; } filled with in-place CGtV2d::Set (retail keeps them on the stack; = CGtV2d(...) adds temps), frame copy through an inline taking the frame pointer by reference (UnkStruct_HM_fr *&f: retail reloads self->field_64 between the pos and size copies). Left: s3/s5 swap in the final per-player loop (retail p=s3, m=s5; ours reversed) -- m/p declaration placement, while form, i reuse all inert or worse.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

// a159: CB3HUDManager::Prepare
struct UnkStruct_HM_m {
    virtual void vfunc_8();
    virtual void vfunc_C(bool, int, int, float);
    unsigned char pad_4[0x8];
    UnkStruct_HM_m * field_C;
    unsigned char pad_10[0x4];
    int field_14;
};
struct UnkStruct_HM_e0 { unsigned char pad_0[0xC]; int field_C; };
struct UnkStruct_HM_fr { CGtV2d field_0; CGtV2d field_8; };
struct UnkStruct_HM_hud {
    float field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x1C];
    void * field_28;
    unsigned char pad_2C[0x14];
    UnkStruct_HM_e0 * field_40;
    unsigned char pad_44[0x20];
    UnkStruct_HM_fr * field_64;
    UnkStruct_HM_m * field_68;
    unsigned char pad_6C[4];
};
struct UnkStruct_HM_self {
    UnkStruct_HM_hud field_0[2];
    unsigned char pad_E0[0x90];
    int field_170;
    int field_174;
    int field_178;
};
struct UnkStruct_HM_rc { CGtV2d s; CGtV2d p; };
static inline void func_001A12B0_inl1(UnkStruct_HM_fr *& f, const UnkStruct_HM_rc & r) { f->field_0 = r.p; f->field_8 = r.s; }
struct UnkStruct_D_00665ECF_hm { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_HM_big { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00665ECF_hm D_00665ECF;
extern UnkStruct_HM_big D_0066C100;
extern UnkStruct_HM_big D_0066B5B0;
extern UnkStruct_HM_big D_0066C2B0;
extern UnkStruct_HM_big _gPrimaryMessageComponentP1;
extern UnkStruct_HM_big _gCrashTimerComponentP1;
extern UnkStruct_HM_big _gScoreComponentP1;
extern UnkStruct_HM_big _gScoreComponentP2;
extern int _kxHUDModeFlags[];
extern "C" void func_001A0560(void *);
extern "C" void Destruct__10CGt2dFrameFv(void *);
extern "C" void * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);
extern "C" void PrepareNormalComponents__13CB3HUDManagerFv(void *);
extern "C" void PrepareCrashComponents__13CB3HUDManagerFv(void *);
enum EHUDAlign {};
extern "C" int Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore(void *, int, EHUDAlign, int, void *);
extern "C" int func_003B8450(void *, int, int, int, int);
extern "C" int func_004360B0(void *, int, int, int);

extern "C" int Prepare__13CB3HUDManagerFv(UnkStruct_HM_self * self)
{
    int i;
    switch (self->field_178) {
    case 1:
    case 0x18:
        break;
    case 0x17:
        for (i = 0; i < 2; i++) {
            UnkStruct_HM_m * c = self->field_0[i].field_68;
            while (c != 0) {
                UnkStruct_HM_m * n = c->field_C;
                c->field_C = 0;
                c = n;
            }
            self->field_0[i].field_68 = 0;
        }
        break;
    }
    for (i = 0; i < self->field_170; i++) func_001A0560(&self->field_0[i]);
    if (self->field_170 == 2) {
        if (D_00665ECF.field_0 != 0) {
            UnkStruct_HM_rc a; UnkStruct_HM_rc b;
            a.s.Set(320.0f, 480.0f); a.p.Set(0.0f, 0.0f);
            for (i = 0; i < 18; i++) self->field_0[0].field_40[i].field_C = 0;
            if (self->field_0[0].field_64 != 0) { Destruct__10CGt2dFrameFv(self->field_0[0].field_64); self->field_0[0].field_64 = 0; }
            self->field_0[0].field_64 = (UnkStruct_HM_fr *)ConstructChild__10CGt2dFrameFv(self->field_0[0].field_28);
            SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(self->field_0[0].field_64);
            b.s.Set(320.0f, 480.0f); b.p.Set(320.0f, 0.0f);
            func_001A12B0_inl1(self->field_0[0].field_64, a);
            for (i = 0; i < 18; i++) self->field_0[1].field_40[i].field_C = 0;
            if (self->field_0[1].field_64 != 0) { Destruct__10CGt2dFrameFv(self->field_0[1].field_64); self->field_0[1].field_64 = 0; }
            self->field_0[1].field_64 = (UnkStruct_HM_fr *)ConstructChild__10CGt2dFrameFv(self->field_0[1].field_28);
            SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(self->field_0[1].field_64);
            func_001A12B0_inl1(self->field_0[1].field_64, b);
        } else {
            UnkStruct_HM_rc a; UnkStruct_HM_rc b;
            a.s.Set(640.0f, 240.0f); a.p.Set(0.0f, 0.0f);
            for (i = 0; i < 18; i++) self->field_0[0].field_40[i].field_C = 0;
            if (self->field_0[0].field_64 != 0) { Destruct__10CGt2dFrameFv(self->field_0[0].field_64); self->field_0[0].field_64 = 0; }
            self->field_0[0].field_64 = (UnkStruct_HM_fr *)ConstructChild__10CGt2dFrameFv(self->field_0[0].field_28);
            SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(self->field_0[0].field_64);
            b.s.Set(640.0f, 240.0f); b.p.Set(0.0f, 240.0f);
            func_001A12B0_inl1(self->field_0[0].field_64, a);
            for (i = 0; i < 18; i++) self->field_0[1].field_40[i].field_C = 0;
            if (self->field_0[1].field_64 != 0) { Destruct__10CGt2dFrameFv(self->field_0[1].field_64); self->field_0[1].field_64 = 0; }
            self->field_0[1].field_64 = (UnkStruct_HM_fr *)ConstructChild__10CGt2dFrameFv(self->field_0[1].field_28);
            SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(self->field_0[1].field_64);
            func_001A12B0_inl1(self->field_0[1].field_64, b);
        }
    } else {
        for (i = 0; i < 18; i++) self->field_0[0].field_40[i].field_C = 0;
        if (self->field_0[0].field_64 != 0) { Destruct__10CGt2dFrameFv(self->field_0[0].field_64); self->field_0[0].field_64 = 0; }
        for (i = 0; i < 18; i++) self->field_0[1].field_40[i].field_C = 0;
        if (self->field_0[1].field_64 != 0) { Destruct__10CGt2dFrameFv(self->field_0[1].field_64); self->field_0[1].field_64 = 0; }
    }
    *((unsigned char *)self + 0xE0) = 0;
    PrepareNormalComponents__13CB3HUDManagerFv(self);
    PrepareCrashComponents__13CB3HUDManagerFv(self);
    switch (self->field_174) {
    case 2:
    case 8:
        Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore(&_gPrimaryMessageComponentP1, 0, (EHUDAlign)8, 7, 0);
        Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore(&D_0066C100, 1, (EHUDAlign)8, 7, 0);
        break;
    case 10: case 11: case 12: case 13: case 15:
        func_003B8450(&_gCrashTimerComponentP1, 0, 0, 3, 0);
        Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore(&_gPrimaryMessageComponentP1, 0, (EHUDAlign)8, 3, &_gScoreComponentP1);
        break;
    case 14:
        func_003B8450(&_gCrashTimerComponentP1, 0, 0, 3, 1);
        Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore(&_gPrimaryMessageComponentP1, 0, (EHUDAlign)8, 3, &_gScoreComponentP1);
        Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore(&D_0066C100, 1, (EHUDAlign)8, 3, &_gScoreComponentP2);
        break;
    case 1: case 3: case 4: case 5: case 6: case 7: case 9:
        Prepare__20CB3HUDPrimaryMessageFi9EHUDAligniP11CB3HUDScore(&_gPrimaryMessageComponentP1, 0, (EHUDAlign)8, 7, &_gScoreComponentP1);
        break;
    }
    if (self->field_174 == 8 || self->field_174 == 2) {
        func_004360B0(&D_0066B5B0, 0, 5, 8);
        func_004360B0(&D_0066C2B0, 1, 5, 8);
    }
    for (int p = 0; p < self->field_170; p++) {
        UnkStruct_HM_hud * h = &self->field_0[p];
        int * pf4 = &h->field_4;
        h->field_4 = 0;
        h->field_8 = 5;
        int * pf8 = &h->field_8;
        int fa = _kxHUDModeFlags[h->field_4];
        int fb = _kxHUDModeFlags[h->field_8];
        for (UnkStruct_HM_m * m = h->field_68; m != 0; m = m->field_C) {
            bool in = (m->field_14 & fa) != 0;
            bool out = (m->field_14 & fb) != 0;
            if (in != out) {
                m->vfunc_C(in, h->field_4, h->field_8, 1.0f);
            } else if (in) {
                m->vfunc_C(in, h->field_4, h->field_8, 1.0f);
            }
        }
        *pf8 = 0;
        *pf4 = 0;
    }
    self->field_178 = 0x17;
    return 1;
}

