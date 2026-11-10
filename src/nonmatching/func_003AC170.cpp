// NONMATCHING: func_003AC170 -- retail 1177 / ours 1182 instructions, 1061 in changed runs
// draftAJ C-first: [L] CB3SatNavComponent stage-marker update: race branch (stage change -> rebuild start marker, route re-prepare via func_0041E260, 5 markers grown by D_004E2EA8), crash branch (junction marker/label timeline on the function statics, junction sound restart via D_0051A6A8, label pop-in keys); 1182/1177, call multiset identical (order differs by block layout); left: block layout, CGtV2d temp copies (sd 52 vs 56), frame 0x4F0 vs 0x480
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every branch sense, timeline constant (folded sums 0.65000004/0.75000006/0.100000024 from the ELF), store and call argument traced; keeps retail's two reads of unset values (race-path marker position p, crash-path elapsed time e when the sound state is not 0x17) and its dead clamp
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// func_003AC170 -- draftAJ (C-first draft; the lifter refused it). 0x3AC170, 0x1264. Unnamed in every table, so the asm
// label with C linkage. [L] a CB3SatNavComponent method (B3SatNavComponent.cpp unit, between func_003AB850 and
// func_003AD3E0, whose layout this file reuses). Written from the retail asm (Ghidra's draft as a reading aid).
// What it does [L]: per-frame update of the stage markers on the sat-nav map.
//  - race stages (field_8E6 == 0): when the selected stage (field_B0[D_01E88D40]) changes, rebuild the start marker
//    (field_1F0[0]) for the new track and flag the route for re-preparing (field_290); a flagged route is prepared
//    (func_0041E260 on field_22C); then the five markers field_1F0[i] are sized and coloured, growing in while the shared
//    timer D_004E2EA8 is below 0.5;
//  - crash stages: the crash-junction marker D_004E2E94 and its label D_004E2E9C are driven by a small timeline on the
//    static D_004E2EB0 / D_004E2EA0 / D_004E2EA4 state: a new junction (or sound state change) starts a fade-out
//    (0.75 s) that ends with the junction sound restarted (D_0051A6A8) and the label re-anchored; otherwise the label
//    pops in (0.5 .. 0.75 s) and the marker is re-prepared and scaled.
// Two reads are of values retail never sets on their path (kept as they are): the race branch's marker position `p`
// (only the crash branch fills it) and the crash branch's elapsed time `e` when the junction sound is not in state 0x17.
// Types and field meanings [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGt2dFrame;
class CGt2dObject;
class CGtTexture;

struct UnkStruct_003AC170_obj {             // a 2D object (fields as func_003AD3E0's)
    CGtV2d field_0;                         // position
    CGtV2d field_8;                         // size
    CGtV4d field_10;                        // colour
    int field_20;
    int field_24;
    float field_28;
    float field_2C;
    float field_30;                         // angle
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
};
struct UnkStruct_003AC170_rd {              // field_294: the route render data passed to func_0041E260
    int field_0;
    int field_4;
    float field_8;
    float field_C;
};
struct UnkStruct_003AC170_e { int field_0; unsigned char pad_4[0xC]; };   // stage list entries (stage id)
struct UnkStruct_003AC170_info {            // crash stage map info (func_003E8E00)
    short field_0;                          // junction x
    short field_2;                          // junction y
    int field_4;
    int field_8;                            // sound id
    int field_C;
    int field_10;
};
struct UnkStruct_003AC170_f { CGtV2d field_0; };

struct UnkStruct_003AC170 {
    unsigned char pad_0[0x8];
    short field_8;                          // scene layer
    unsigned char pad_A[0xE];
    CGtV2d field_18;                        // map zoom
    unsigned char pad_20[0x90];
    UnkStruct_003AC170_e field_B0[1];
    unsigned char pad_C0[0x130];
    UnkStruct_003AC170_obj *field_1F0[5];
    unsigned char pad_204[0x24];
    CGt2dFrame *field_228;
    UnkStruct_003AC170_obj *field_22C;      // the route object
    unsigned char pad_230[0x24];
    int field_254;                          // region
    unsigned char pad_258[0xC];
    int field_264;
    unsigned char pad_268[0x14];
    int field_27C;
    unsigned char pad_280[0x10];
    bool field_290;                         // route needs preparing
    unsigned char pad_291[0x3];
    UnkStruct_003AC170_rd field_294;
    unsigned char pad_2A4[0x34];
    CGtV2d field_2D8[5];                    // marker positions
    int field_300;                          // current stage id
    unsigned char pad_304[0x278];
    int field_57C[1];                       // [region * 28 + i]
    unsigned char pad_580[0x188];
    int field_708;
    unsigned char pad_70C[0x1DA];
    bool field_8E6;                         // crash stages
};

class CGt2dScene {
public:
    UnkStruct_003AC170_obj *ConstructObject(int, CGt2dFrame *);
    void DestructObject(int, CGt2dObject *);
};
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x110]; CGtV4d field_110; };   // the menu page manager
extern UnkStruct_D_01E90240 D_01E90240;
extern CGt2dScene D_01E903E0;
struct UnkStruct_D_01E88D40 { unsigned short field_0; unsigned char pad_2[0xE]; };
extern UnkStruct_D_01E88D40 D_01E88D40;     // selected stage list entry
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
struct UnkStruct_D_01EA4630 { CGtTexture *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01EA4630 D_01EA4630;
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F50A0 D_004F50A0;     // [G] the front-end clock
struct UnkStruct_D_0051A9A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051A9A0 D_0051A9A0;     // [G] junction sound state (0x17 = idle)
extern UnkStruct_D_0051A9A0 D_0051A9A4;     // [G] junction sound id (0x1A = none)
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_Pad16 D_0051A6A8;        // the junction sound player
extern UnkStruct_D_Pad16 D_0051A870;
extern UnkStruct_D_Pad16 D_004C9F68;
extern const CGtV2d D_004C9FA8;             // marker size
extern const CGtV2d D_004C9F38, D_004C9F40, D_004C9F58, D_004C9F60;   // label scale keys
extern float D_004E1E84;                    // zoom limit (0.5)
// statics of this function [G] (.sbss)
extern UnkStruct_003AC170_obj *D_004E2E94;  // crash-junction marker
extern UnkStruct_003AC170_obj *D_004E2E9C;  // its label
extern float D_004E2EA0;                    // label start time
extern float D_004E2EA4;                    // fade-out start time
extern float D_004E2EA8;                    // marker grow timer
extern bool D_004E2EB0;                     // fading out
extern CGtV2d D_004E2EB8;                   // label position
extern CGtV2d D_004E2EC0;                   // junction position the label belongs to

extern "C" void func_003B0160(void *, void *);        // the marker render callback
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(
    UnkStruct_003AC170_obj *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
#define CGt2dObject_Prepare Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi
extern "C" unsigned long GetCrashStageGtID__26CB3HardCodedCrashStageListFi(int);
extern "C" unsigned long GetStageGtID__25CB3HardCodedRaceStageListFii(int, int);
extern "C" unsigned long GetStageTrackID__25CB3HardCodedRaceStageListFUl(unsigned long);
extern "C" void func_00130C30(void *, int);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void func_00130D50(void *);
extern "C" int func_0013AD70(void *, int, int);
extern "C" void func_00324EC0(void *);
extern "C" void func_00326CF0(UnkStruct_003AC170_obj *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const void *, const void *, const void *);
extern "C" void func_003A8A90(UnkStruct_003AC170 *);   // [L] DNAT CB3SatNavComponent::ReleasePopups (func_003ADD80's note)
extern "C" UnkStruct_003AC170_f *func_003E8DD0(void);
extern "C" UnkStruct_003AC170_f *func_003E8DE0(int);
extern "C" UnkStruct_003AC170_info *func_003E8E00(unsigned long);
extern "C" void func_003EA4C0(int, int, int *, int *);
extern "C" float func_003EA880(unsigned long);
extern "C" float func_003EA8E0(unsigned long);
extern "C" void func_003EA940(unsigned long, CGtV2d *);
extern "C" CGtV2d func_003F5A20(int, int);
extern "C" void func_0041E260(UnkStruct_003AC170_obj *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, CGtTexture *, float);

// [G] size, colour and placement of race marker i
static inline void func_003AC170_inl1(UnkStruct_003AC170 *self, int i, float alpha, float scale, const CGtV2d &clamp)
{
    UnkStruct_003AC170_obj *o = self->field_1F0[i];
    if (o != 0) {
        CGtV2d a = D_004C9FA8 * 0.6f;
        CGtV4d col;
        col = D_01E90240.field_110;
        col.SetA(alpha);
        o->field_10 = col;
        CGtV2d size = a / clamp * scale;
        CGtV2d pos = self->field_2D8[i] - size * 0.5f;
        o->field_0 = pos;
        o->field_8 = size;
        self->field_1F0[i]->field_24 = 0;
        self->field_1F0[i]->field_28 = 1.0f;
    }
}

// 0x003AC170
extern "C" void func_003AC170(UnkStruct_003AC170 *self)
{
    CGt2dScene *const scene = &D_01E903E0;
    UnkStruct_D_01E90240 *const mgr = &D_01E90240;
    int layer = self->field_8 + 8;
    CGtV2d inv = D_004C9FA8 / self->field_18;
    int fp = self->field_57C[self->field_254 * 28 + self->field_27C];
    CGtTexture *tex = D_01EA4630.field_0;
    int x = D_0051BF9C.field_0;
    CGtV2d p;                               // [C] set only on the crash path; the race path passes it as it is
    float e;                                // [C] unset on one crash path (see the head comment)
    if (!self->field_8E6) {
        CGtV2d clamp = self->field_18;
        if (!(clamp.marValues[0] <= D_004E1E84)) clamp.marValues[0] = D_004E1E84;
        if (!(clamp.marValues[1] <= D_004E1E84)) clamp.marValues[1] = D_004E1E84;
        func_00324EC0(&D_0051A870);
        if (self->field_300 != self->field_B0[D_01E88D40.field_0].field_0) {
            unsigned long oldTrack = GetStageTrackID__25CB3HardCodedRaceStageListFUl(GetStageGtID__25CB3HardCodedRaceStageListFii(self->field_300, 0));
            self->field_300 = self->field_B0[D_01E88D40.field_0].field_0;
            unsigned long track = GetStageTrackID__25CB3HardCodedRaceStageListFUl(GetStageGtID__25CB3HardCodedRaceStageListFii(self->field_300, 0));
            self->field_708 = 0;
            func_003A8A90(self);
            if (track != oldTrack) {
                CGtV2d old = self->field_2D8[0];
                func_003EA940(track, &self->field_2D8[0]);
                bool same = old.marValues[0] == self->field_2D8[0].marValues[0];
                if (same) same = old.marValues[1] == self->field_2D8[0].marValues[1];
                if (!same) {
                    if (!(self->field_2D8[0].marValues[0] < 0.0f)) {
                        if (self->field_1F0[0] == 0) self->field_1F0[0] = scene->ConstructObject(layer, self->field_228);
                        float ang = 90.0f + func_003EA8E0(track);
                        CGtV2d z(0.0f, 0.0f);
                        CGtV4d v;
                        v = mgr->field_110;
                        UnkStruct_003AC170_obj *o = self->field_1F0[0];
                        o->field_34 = 0x37;
                        o->field_35 = 0x90;
                        o->field_30 = ang;
                        o->field_28 = 0.0f;
                        o->field_24 = 0;
                        o->field_36 = 0xFF;
                        o->field_20 = fp;
                        CGtV2d tp = p - z * 0.5f;
                        CGt2dObject_Prepare(o, tp, z, v, (const void *)&func_003B0160, 0x40, 0x18);
                        o->field_2C = 1.0f;
                        self->field_1F0[0]->field_24 = 0;
                        self->field_1F0[0]->field_28 = 0.0f;
                    } else if (self->field_1F0[0] != 0) {
                        scene->DestructObject(layer, (CGt2dObject *)self->field_1F0[0]);
                        self->field_1F0[0] = 0;
                    }
                }
                self->field_290 = true;
            }
        }
        if (self->field_290) {
            unsigned long track = GetStageTrackID__25CB3HardCodedRaceStageListFUl(GetStageGtID__25CB3HardCodedRaceStageListFii(self->field_300, 0));
            func_003EA4C0(self->field_254, self->field_264, &self->field_294.field_0, &self->field_294.field_4);
            self->field_294.field_C = 1.0f;
            self->field_294.field_8 = 10.0f;
            CGtV4d white(1.0f, 1.0f, 1.0f, 1.0f);
            CGtV2d z0(0.0f, 0.0f);
            CGtV2d z1(0.0f, 0.0f);
            float s = func_003EA880(track);
            func_0041E260(self->field_22C, z1, z0, white, &self->field_294, D_01EA4630.field_0, 0.2f * s);
            self->field_290 = false;
        }
        if (D_004E2EA8 <= 0.5f) {
            for (int i = 0; i < 5; i++) {
                float f = D_004E2EA8 / 0.5f;
                func_003AC170_inl1(self, i, f, 0.2f + f * 0.8f, clamp);
            }
        } else {
            float one = 1.0f;
            for (int i = 0; i < 5; i++) {
                func_003AC170_inl1(self, i, one, one, clamp);
            }
        }
        return;
    }

    UnkStruct_003AC170_info *info = func_003E8E00(GetCrashStageGtID__26CB3HardCodedCrashStageListFi(self->field_B0[D_01E88D40.field_0].field_0));
    p = CGtV2d((float)info->field_0, (float)info->field_2);
    p += func_003F5A20(self->field_254, self->field_27C);
    int snd;
    if (func_0013AD70((void *)(x), self->field_B0[D_01E88D40.field_0].field_0, 0) != 0) {
        snd = 0x80;
    } else {
        snd = info->field_8;
    }
    UnkStruct_003AC170_obj *marker = D_004E2E94;
    if (marker == 0) return;
    bool keep = false;
    if (D_0051A9A4.field_0 == 0x1A || snd == D_0051A9A4.field_0) {
        bool same = D_004E2EC0.marValues[0] == (float)info->field_0;
        if (same) same = D_004E2EC0.marValues[1] == (float)info->field_2;
        keep = same;
    }
    if (!keep && !D_004E2EB0) {
        D_004E2EB0 = true;
        self->field_290 = true;
        D_004E2EA4 = D_004F50A0.field_0;
        return;
    }
    if (D_004E2EB0) {
        // fading out: the route, the marker and the label shrink away over 0.75 s
        e = D_004F50A0.field_0 - D_004E2EA4;
        bool done = false;
        if (self->field_22C != 0) {
            float a = 1.0f - GtMath::Min(e / 0.75000006f, 1.0f);
            self->field_22C->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, a);
        }
        float k = GtMath::Min(GtMath::Max(D_004E2EA8 - 0.5f, 0.0f), 0.3f);   // [C] unused (retail computes it, nothing reads it)
        (void)k;
        float a = 1.0f - e / 0.75000006f;
        float scale = 0.2f + a * 0.8f;
        CGtV2d size = inv * scale;
        CGtV4d col;
        col = mgr->field_110;
        col.SetA(a);
        marker->field_10 = col;
        CGtV2d pos = D_004E2EC0 - size * 0.5f;
        marker->field_0 = pos;
        marker->field_8 = size;
        CGtV2d s;
        if (e < 0.5f) {
            s = CGtV2d(1.0f, 1.0f);
        } else if (!(e < 0.5f) && e < 0.6f) {
            s = D_004C9F60 + (D_004C9F58 - D_004C9F60) * ((e - 0.5f) / 0.100000024f);
        } else if (!(e < 0.5f) && e < 0.65000004f) {
            s = D_004C9F58;
        } else if (!(e < 0.5f) && e < 0.75000006f) {
            s = D_004C9F40 + (D_004C9F38 - D_004C9F40) * ((e - 0.65000004f) / 0.100000024f);
        } else {
            s = CGtV2d(0.0f, 0.0f);
            done = true;
        }
        if (done) {
            // restart the junction sound for the new junction and re-anchor the label
            if (D_0051A9A0.field_0 == 0x17) {
                func_00130C70(&D_0051A6A8);
                func_00130D00(&D_0051A6A8);
                func_00130C30(&D_0051A6A8, snd);
            }
            while (D_0051A9A0.field_0 != 0x17) func_00130D50(&D_0051A6A8);
            D_004E2E94->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, 0.0f);
            D_004E2EA8 = 0.0f;
            D_004E2EB0 = false;
            D_004E2EA0 = D_004F50A0.field_0;
            CGtV2d q = func_003F5A20(self->field_254, self->field_27C);
            q = q + func_003E8DE0(info->field_4)->field_0 / self->field_18;
            D_004E2EB8 = q;
            D_004E2EC0 = CGtV2d((float)info->field_0, (float)info->field_2);
        }
        CGtV2d ls = func_003E8DD0()->field_0 * s / self->field_18;
        func_00326CF0(D_004E2E9C, D_004E2EB8, CGtV2d(0.5f, 0.5f), ls, &D_004C9F68, &mgr->field_110, &D_0051A870);
        return;
    }
    if (D_0051A9A0.field_0 == 0x17) {
        // the label pops in between 0.5 and 0.75 s
        CGtV2d q = func_003F5A20(self->field_254, self->field_27C);
        UnkStruct_003AC170_f *f = func_003E8DE0(info->field_4);
        e = D_004F50A0.field_0 - D_004E2EA0;
        q = q + f->field_0 / self->field_18;
        CGtV2d s;
        if (e < 0.5f) {
            s = CGtV2d(0.0f, 0.0f);
        } else if (!(e < 0.5f) && e < 0.6f) {
            s = D_004C9F38 + (D_004C9F40 - D_004C9F38) * ((e - 0.5f) / 0.100000024f);
        } else if (!(e < 0.5f) && e < 0.65000004f) {
            s = D_004C9F40;
        } else if (!(e < 0.5f) && e < 0.75000006f) {
            s = D_004C9F58 + (D_004C9F60 - D_004C9F58) * ((e - 0.65000004f) / 0.100000024f);
        } else {
            s = CGtV2d(1.0f, 1.0f);
        }
        CGtV2d ls = func_003E8DD0()->field_0 * s / self->field_18;
        func_00326CF0(D_004E2E9C, q, CGtV2d(0.5f, 0.5f), ls, &D_004C9F68, &mgr->field_110, &D_0051A870);
    } else if (D_004E2E9C != 0) {
        scene->DestructObject(layer, (CGt2dObject *)D_004E2E9C);
        D_004E2E9C = 0;
    }
    if (e < 0.5f) return;
    // re-prepare the marker and grow it with D_004E2EA8 (0.5 .. 0.8)
    CGtV4d v;
    v = mgr->field_110;
    CGtV2d msize = D_004C9FA8 * 0.2f;
    UnkStruct_003AC170_obj *o = D_004E2E94;
    o->field_34 = 0x40;
    o->field_35 = 0x40;
    o->field_30 = 0.0f;
    o->field_28 = 0.0f;
    o->field_24 = 0;
    o->field_36 = 0xFF;
    o->field_20 = fp;
    CGtV2d tp = p - msize * 0.5f;
    CGt2dObject_Prepare(o, tp, msize, v, (const void *)&func_003B0160, 0x40, 0x18);
    o->field_2C = 1.0f;
    float k = GtMath::Min(GtMath::Max(D_004E2EA8 - 0.5f, 0.0f), 0.3f);
    float a = 3.3333333f * (k - 0.0f);
    float scale = 0.2f + a * 0.8f;
    CGtV2d size = inv * scale;
    CGtV4d col;
    col = mgr->field_110;
    col.SetA(a);
    D_004E2E94->field_10 = col;
    CGtV2d pos = CGtV2d((float)info->field_0, (float)info->field_2) - size * 0.5f;
    D_004E2E94->field_0 = pos;
    D_004E2E94->field_8 = size;
    if (self->field_290) {
        self->field_294.field_0 = info->field_C;
        self->field_294.field_4 = info->field_10;
        self->field_294.field_C = 1.0f;
        self->field_294.field_8 = 10.0f;
        CGtV2d z0(0.0f, 0.0f);
        CGtV2d z1(0.0f, 0.0f);
        func_0041E260(self->field_22C, z0, z1, CGtV4d(1.0f, 1.0f, 1.0f, a), &self->field_294, tex, -0.2f);
        self->field_290 = false;
    }
    if (self->field_22C != 0) self->field_22C->field_10 = CGtV4d(1.0f, 1.0f, 1.0f, a);
}
