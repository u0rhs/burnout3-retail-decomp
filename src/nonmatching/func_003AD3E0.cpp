// NONMATCHING: func_003AD3E0 -- retail 396 / ours 394 instructions, 207 in changed runs
// a175: logic-complete (394 vs 396 instrs, 207 changed, mostly s-reg numbering + stack slots). Left: retail frame 0x1A0 (ours 0x180; every temp has its own slot), s-reg order (retail s4=self,s3=scene,s5=mgr,s1=b,s6=c,s7=x,fp=fp, ours differs), out-of-line construct-if-null blocks: retail puts the E94/E9C/22C/1F0 blocks and the 'small arm' at function end in order E94,E9C,22C,1F0,arm and the 0x17 test body (D888) + while body (D874) after the crash-branch tail; uninit CGtV2d p read in first branch (hoisted lwc1 f20/f21); GetStageGtID/GetTrackIconPulseImage a2 left unset (declared as 2-arg extern C)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGt2dObject;
class CGt2dFrame;
class CB3HardCodedRaceStageList {
public:
    unsigned long GetStageGtID(int, int);
    static unsigned long GetStageTrackID(unsigned long);
};
struct UnkStruct_003AD3E0_obj { unsigned char pad_0[0x20]; int field_20; int field_24; int field_28; float field_2C; float field_30; unsigned char field_34; unsigned char field_35; unsigned char field_36; };
struct UnkStruct_003AD3E0_e { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003AD3E0_v4 { int field_0; int field_4; float field_8; float field_C; };
struct UnkStruct_003AD3E0_info { short field_0; short field_2; int field_4; int field_8; int field_C; int field_10; };
struct UnkStruct_003AD3E0_f { CGtV2d field_0; };
struct UnkStruct_003AD3E0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0xE];
    float field_18;
    float field_1C;
    unsigned char pad_20[0x90];
    UnkStruct_003AD3E0_e field_B0[1];
    unsigned char pad_C0[0x130];
    UnkStruct_003AD3E0_obj * field_1F0[5];
    unsigned char pad_204[0x24];
    CGt2dFrame * field_228;
    UnkStruct_003AD3E0_obj * field_22C;
    unsigned char pad_230[0x24];
    int field_254;
    unsigned char pad_258[0x24];
    int field_27C;
    unsigned char pad_280[0x14];
    UnkStruct_003AD3E0_v4 field_294;
    unsigned char pad_2A4[0x34];
    CGtV2d field_2D8[5];
    CB3HardCodedRaceStageList * field_300;
};
struct UnkStruct_D_01E88D40 { unsigned short field_0; unsigned char pad_2[0xE]; };
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x110]; CGtV4d field_110; };
extern UnkStruct_D_01E88D40 D_01E88D40;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_003AD3E0_obj * D_004E2E94;
extern UnkStruct_003AD3E0_obj * D_004E2E9C;
extern float D_004E2EA0;
extern int D_004E2EA8;
extern unsigned char D_004E2EB0;
extern CGtV2d D_004E2EB8;
extern CGtV2d D_004E2EC0;
extern float D_004E0828;
struct UnkStruct_D_004F50A0 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004F50A0 D_004F50A0;
struct UnkStruct_D_0051A6A8 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051A6A8 D_0051A6A8;
struct UnkStruct_D_0051A9A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051A9A0 D_0051A9A0;
struct UnkStruct_D_01EA4630 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01EA4630 D_01EA4630;
struct UnkStruct_D_004C9F68 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004C9F68 D_004C9F68;
struct UnkStruct_D_0051A870 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051A870 D_0051A870;
extern int func_003B0160;
extern "C" UnkStruct_003AD3E0_obj * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, UnkStruct_003AD3E0_obj *);
extern "C" unsigned long GetCrashStageGtID__26CB3HardCodedCrashStageListFi(int);
extern "C" int GetTrackIconPulseImage__27CB3HardCodedTrackRegionListF14EB3TrackRegioni(int, int);
extern "C" unsigned long GetStageGtID__25CB3HardCodedRaceStageListFii(int, int);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
extern "C" void func_00130C30(void *, int);
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void func_00130D50(void *);
extern "C" int func_0013AD70(void *, int, int);
extern "C" void func_00326CF0(UnkStruct_003AD3E0_obj *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const void *, const void *, const void *);
extern "C" UnkStruct_003AD3E0_f * func_003E8DE0(int);
extern "C" UnkStruct_003AD3E0_info * func_003E8E00(unsigned long);
extern "C" float func_003EA8E0(unsigned long);
extern "C" void func_003EA940(unsigned long, void *);
extern "C" CGtV2d func_003F5A20(int, int);
extern "C" int func_003F5C00(int, int);
extern "C" void func_0041E260(UnkStruct_003AD3E0_obj *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, void *, float);
static inline CGtV2d inl1(const CGtV2d &a, const CGtV2d &b) { return a - b; }

// 0x003AD3E0
extern "C" void func_003AD3E0(UnkStruct_003AD3E0 * self)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    CGtV2d p;
    int b = self->field_8 + 8;
    int c = self->field_8 + 5;
    int fp = *(int *)((char *)self + self->field_254 * 0x70 + self->field_27C * 4 + 0x57C);
    int t = self->field_254;
    func_003F5C00(t, 0);
    GetTrackIconPulseImage__27CB3HardCodedTrackRegionListF14EB3TrackRegioni(self->field_254, 0);
    unsigned long x = D_0051BF9C.field_0;  // w64: holds a 64-bit track id below (retail s7, 64-bit register)
    if (*((unsigned char *)self + 0x8E6) == 0) {
        self->field_300 = (CB3HardCodedRaceStageList *)self->field_B0[D_01E88D40.field_0].field_0;
        x = CB3HardCodedRaceStageList::GetStageTrackID(GetStageGtID__25CB3HardCodedRaceStageListFii((int)(self->field_300), 0));
        func_003EA940(x, &self->field_2D8[0]);
        for (int i = 0; i < 5; i++) {
            if (!(self->field_2D8[i].marValues[0] < 0.0f)) {
                if (self->field_1F0[i] == 0) self->field_1F0[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, b, self->field_228);
                float ang; int col;
                if (i != 0) { ang = 0.0f; col = 0x41; } else { col = 0x37; ang = 90.0f + func_003EA8E0(x); }
                CGtV2d z(0.0f, 0.0f);
                CGtV4d v; v = mgr->field_110;
                UnkStruct_003AD3E0_obj * o = self->field_1F0[i];
                o->field_34 = col; o->field_35 = -0x70; o->field_30 = ang; o->field_28 = 0; o->field_24 = 0; o->field_36 = -1; o->field_20 = fp;
                CGtV2d h = z * CGtV2d(0.5f, 0.5f);
                CGtV2d tp = p - h;
                Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, tp, z, v, (const void *)&func_003B0160, 64, 24);
                o->field_2C = 1.0f;
                UnkStruct_003AD3E0_obj * f0 = self->field_1F0[0];
                f0->field_24 = 0;
                f0->field_28 = 0;
            } else {
                if (self->field_1F0[i] != 0) { DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b, self->field_1F0[i]); self->field_1F0[i] = 0; }
            }
        }
    } else {
        UnkStruct_003AD3E0_info * info = func_003E8E00(GetCrashStageGtID__26CB3HardCodedCrashStageListFi(self->field_B0[D_01E88D40.field_0].field_0));
        CGtV2d t0((float)info->field_0, (float)info->field_2);
        p = t0;
        p += func_003F5A20(self->field_254, self->field_27C);
        if (D_004E2E94 == 0) D_004E2E94 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, b, self->field_228);
        CGtV2d z(0.0f, 0.0f);
                CGtV4d v; v = mgr->field_110;
        UnkStruct_003AD3E0_obj * o = D_004E2E94;
        o->field_34 = 0x40; o->field_35 = 0x40; o->field_30 = 0.0f; o->field_28 = 0; o->field_24 = 0; o->field_36 = -1; o->field_20 = fp;
        CGtV2d h = z * CGtV2d(0.5f, 0.5f);
                CGtV2d tp = p - h;
        Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, tp, z, v, (const void *)&func_003B0160, 64, 24);
        o->field_2C = 1.0f;
        D_004E2EA8 = 0;
        D_004E2EB0 = 0;
        func_00130C70(&D_0051A6A8);
        func_00130D00(&D_0051A6A8);
        if (func_0013AD70((void *)(x), self->field_B0[D_01E88D40.field_0].field_0, 0) == 0) func_00130C30(&D_0051A6A8, info->field_8);
        else func_00130C30(&D_0051A6A8, 0x80);
        while (D_0051A9A0.field_0 != 0x17) func_00130D50(&D_0051A6A8);
        if (D_0051A9A0.field_0 == 0x17) {
            CGtV2d q;
            q = func_003F5A20(self->field_254, self->field_27C);
            UnkStruct_003AD3E0_f * f = func_003E8DE0(info->field_4);
            q += f->field_0 / *(CGtV2d *)&self->field_18;
            D_004E2EB8 = q;
            D_004E2EC0 = CGtV2d((float)info->field_0, (float)info->field_2);
            if (D_004E2E9C == 0) D_004E2E9C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, b, self->field_228);
            func_00326CF0(D_004E2E9C, q, CGtV2d(0.5f, 0.5f), CGtV2d(0.0f, 0.0f), &D_004C9F68, &mgr->field_110, &D_0051A870);
            D_004E2EA0 = D_004F50A0.field_0;
        }
        self->field_294.field_0 = info->field_C;
        self->field_294.field_4 = info->field_10;
        self->field_294.field_C = 1.0f;
        self->field_294.field_8 = 10.0f;
        if (self->field_22C == 0) self->field_22C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, c, self->field_228);
        func_0041E260(self->field_22C, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV4d(1.0f, 1.0f, 1.0f, 0.0f), (const void *)&self->field_294, (void *)(D_01EA4630.field_0), D_004E0828);
    }
}
