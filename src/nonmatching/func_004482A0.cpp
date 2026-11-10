// NONMATCHING: func_004482A0 -- retail 420 / ours 420 instructions, 28 in changed runs
// near29: D_004E2F98 / D_004E2FA0 are .sbss CGtV2d statics: 'extern CGtV2d D_x;' + '*(CGtV2d *)&row.field_30 = D_x;' makes the 5-row loop exact (39 -> 28). Left only the two out-of-line title blocks ta/tb: our 'move t0,v0' (ttl) is scheduled first, retail after the pos/anchor setup, which shifts temps (retail t4 = field_88, a0 = 320.0f bits)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_004482A0 -- retail 420 / ours 420 instructions, 39 in changed runs
// a179: 420/420 instrs, 39 changed (all scheduling/float-reg): (1) final 5-iteration loop: retail loads D_004E2F98 into f1 and D_004E2F9C into f0 (first load = f1) before the address arithmetic, ours f0/f1 and address calcs earlier; same for D_004E2FA0/A4 (stores 0x3B0/0x3B4 swapped f1/f0); (2) the two out-of-line title blocks (ta/tb): retail does 'daddu t0,v0' after the pos temp setup and uses t4 for the frame ptr, ours move t0,v0 first. Solved: the A/B/main stack-temp order needs the temps as TOP-DECLARED named CGtV2d locals (pa,aa,pb,ab) declared before the date locals; date/time locals declared d1,d2,d0,hrs,mins,stamp,tm at the top (first declared = highest address); goto ta/tb layout (out-of-line title blocks); col declared before zero.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_004482A0_fr { float field_0; float field_4; };
struct UnkStruct_004482A0_el { int field_0; float field_4; unsigned char field_8; };
struct UnkStruct_004482A0_cb { void * field_0; void * field_4; void * field_8; void * field_C; void * field_10; void * field_14; };
struct UnkStruct_004482A0_row {
    unsigned char pad_0[0x20];
    CGtV4d field_20;
    float field_30;
    float field_34;
    int field_38;
    unsigned char pad_3C[4];
    float field_40;
    int field_44;
    const unsigned short * field_48;
    int field_4C;
};
struct UnkStruct_004482A0_time { unsigned short field_0; unsigned short field_2; unsigned short field_4; unsigned short field_6; unsigned short field_8; short field_A; };
struct UnkStruct_004482A0_prof { unsigned char pad_0[4]; float field_4; unsigned char pad_8[0x493]; signed char field_49B; };
struct UnkStruct_004482A0 {
    unsigned char pad_0[0x70];
    unsigned char field_70[0x18];
    UnkStruct_004482A0_fr * field_88;
    void * field_8C;
    unsigned char pad_90[0x64];
    float field_F4;
    CGtV2d field_F8;
    int field_100;
    int field_104;
    void * field_108;
    void * field_10C;
    void * field_110;
    int field_114;
    UnkStruct_004482A0_el field_118[5];
    UnkStruct_004482A0_el field_154[2];
    UnkStruct_004482A0_cb field_16C[5];
    unsigned char pad_1E4[0xC];
    UnkStruct_004482A0_row field_1F0[5];
    UnkStruct_004482A0_row field_380[5];
    unsigned char pad_510[4];
    const unsigned short * field_514[5];
    const unsigned short * field_528[5];
    unsigned short field_53C[20];
    unsigned short field_564[20];
    unsigned short field_58C[20];
    unsigned short field_5B4[20];
    int field_5DC;
};
struct UnkStruct_D_01E90240 { CGtV4d field_0; CGtV4d field_10; };
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_vt { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_ptr { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_Byte16 D_01E8D45A;
extern UnkStruct_D_vt D_01E8D450;
extern UnkStruct_Pad16 D_01ECD520;
extern UnkStruct_D_ptr D_01E90430;
extern UnkStruct_Pad16 D_01E96418;
extern UnkStruct_Pad16 D_01E96424;
extern UnkStruct_Pad16 D_01E96450;
extern UnkStruct_Pad16 D_0051BA44;
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_float { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_int D_004D30E0;
extern UnkStruct_D_int D_004D30E8;
extern UnkStruct_D_float D_004D30C0;
extern CGtV2d D_004E2F98;
extern CGtV2d D_004E2FA0;
extern int D_00665ED0[4];
extern "C" UnkStruct_004482A0_prof * func_00420FE0(void *, int);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_002F9690(void *, const CGtV2d &, const CGtV2d &, const void *, const unsigned short *, void *, int, int, float);
extern "C" float func_0013A560(unsigned int *, void *);
extern "C" void func_00436140(UnkStruct_004482A0_time *, unsigned int);
extern "C" const unsigned short * func_0013B730(void *);
extern "C" int func_0013ACF0(void *);
extern "C" void func_00449FC0(void *, const unsigned short *, const int *, const int *, const int *);
extern "C" void func_0044A0F0(void *, const unsigned short *, const int *, const int *);
extern "C" void Evaluate__10CB3ProfileFv(void *);
extern "C" int GetChallengeUnlockedCount__10CB3ProfileFv(void *);
extern "C" void ustrFromInt(void *, int, int, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" void Prepare__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatabb(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, void *, bool, bool);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);

// 0x004482A0
extern "C" void func_004482A0(UnkStruct_004482A0 *self, int p1)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    int d1, d2, d0, hrs, mins;
    unsigned int stamp;
    UnkStruct_004482A0_time tm;
    CGtV2d pa, aa, pb, ab;
    const unsigned short *ttl;
    const unsigned short *ttl2;
    CGtV4d col;
    CGtV4d zero(0.0f, 0.0f, 0.0f, 0.0f);
    if (D_01E8D45A.field_0 != 0) ((UnkStruct_D_vt *)&D_01E8D450)->vfunc_C();
    col = mgr->field_10;
    UnkStruct_004482A0_prof *prof = func_00420FE0(&D_01ECD520, p1);
    void *cur = D_01E90430.field_0;
    if (cur == &D_01E96418) goto ta;
    if (cur == &D_01E96424) goto tb;
    if (cur == &D_01E96450) goto tb;
main:
    const unsigned short *title = func_00271A00(&D_0051BA44, 0x8C6);
    func_002F9690(self->field_8C, CGtV2d(320.0f, self->field_F4 / 2.0f + self->field_88->field_4), CGtV2d(0.5f, 0.5f), &zero, title, self->field_70, 3, 0, D_004D30C0.field_0);
    self->field_100 = 5;
    self->field_104 = 2;
    self->field_108 = self->field_118;
    self->field_10C = self->field_154;
    self->field_110 = self->field_16C;
    self->field_114 = self->field_5DC;
    self->field_F8 = CGtV2d(-1.0f, -1.0f);
    func_0013A560(&stamp, prof);
    func_00436140(&tm, stamp);
    int n = D_004D30E0.field_0;
    int i;
    for (i = 0; i < 5; i++) {
        self->field_118[i].field_0 = 0;
        self->field_118[i].field_4 = (float)n;
        self->field_118[i].field_8 = 0;
    }
    int m = D_004D30E8.field_0;
    for (i = 0; i < 2; i++) {
        self->field_154[i].field_0 = 0;
        self->field_154[i].field_4 = (float)m;
        self->field_154[i].field_8 = 0;
    }
    self->field_514[0] = func_00271A00(&D_0051BA44, 0xA21);
    self->field_514[1] = func_00271A00(&D_0051BA44, 0xA22);
    self->field_514[2] = func_00271A00(&D_0051BA44, 0xA23);
    self->field_514[3] = func_00271A00(&D_0051BA44, 0x4D2);
    self->field_514[4] = func_00271A00(&D_0051BA44, 0xA25);
    self->field_528[0] = func_0013B730(prof);
    d1 = tm.field_2;
    d2 = tm.field_4;
    d0 = tm.field_0;
    func_00449FC0(self->field_53C, func_00271A00(&D_0051BA44, 0xA26), &d1, &d2, &d0);
    self->field_528[1] = (const unsigned short *)self->field_53C;
    unsigned int secs = (unsigned int)(int)prof->field_4;
    hrs = secs / 3600;
    mins = (secs % 3600) / 60;
    if (hrs == 1) {
        if (mins == 1) {
            func_0044A0F0(self->field_564, func_00271A00(&D_0051BA44, 0xA27), &hrs, &mins);
        } else {
            func_0044A0F0(self->field_564, func_00271A00(&D_0051BA44, 0xA28), &hrs, &mins);
        }
    } else if (mins == 1) {
        func_0044A0F0(self->field_564, func_00271A00(&D_0051BA44, 0xA29), &hrs, &mins);
    } else {
        func_0044A0F0(self->field_564, func_00271A00(&D_0051BA44, 0xA2A), &hrs, &mins);
    }
    self->field_528[2] = (const unsigned short *)self->field_564;
    Evaluate__10CB3ProfileFv(prof);
    ustrFromInt(self->field_58C, GetChallengeUnlockedCount__10CB3ProfileFv(prof), 1, 0);
    self->field_528[3] = (const unsigned short *)self->field_58C;
    PrintInt__10CGtUnicodeFPUsii(self->field_5B4, func_0013ACF0(prof), 1, 0);
    self->field_528[4] = (const unsigned short *)self->field_5B4;
    for (i = 0; i < 5; i++) {
        *(CGtV2d *)&self->field_1F0[i].field_30 = D_004E2F98;
        self->field_1F0[i].field_20 = col;
        self->field_1F0[i].field_48 = self->field_514[i];
        self->field_1F0[i].field_40 = 24.0f;
        self->field_1F0[i].field_44 = D_00665ED0[0];
        self->field_1F0[i].field_4C = 0;
        *(CGtV2d *)&self->field_380[i].field_30 = D_004E2FA0;
        self->field_380[i].field_20 = col;
        self->field_380[i].field_48 = self->field_528[i];
        self->field_380[i].field_40 = 24.0f;
        self->field_380[i].field_44 = D_00665ED0[0];
        self->field_380[i].field_4C = 0;
        self->field_16C[i].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_16C[i].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_16C[i].field_8 = &self->field_1F0[i];
        self->field_16C[i].field_C = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_16C[i].field_10 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_16C[i].field_14 = &self->field_380[i];
    }
    Prepare__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatabb(&D_01E8D450, CGtV2d(320.0f, self->field_F4 / 2.0f + self->field_88->field_4), CGtV2d(0.5f, 0.5f), CGtV2d(2.0f * (float)m, (float)(n * 5)), &self->field_F8, false, true);
    RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
    return;
ta:
    if (prof->field_49B == 0) goto main;
    ttl = func_00271A00(&D_0051BA44, 0x8C6);
    aa.Set(0.5f, 0.5f);
    pa.Set(320.0f, self->field_F4 / 2.0f + self->field_88->field_4);
    func_002F9690(self->field_8C, pa, aa, mgr, ttl, self->field_70, 3, 0, D_004D30C0.field_0);
    return;
tb:
    if (prof->field_49B == 0) goto main;
    ttl2 = func_00271A00(&D_0051BA44, 0x8C6);
    ab.Set(0.5f, 0.5f);
    pb.Set(320.0f, self->field_F4 / 2.0f + self->field_88->field_4);
    func_002F9690(self->field_8C, pb, ab, mgr, ttl2, self->field_70, 3, 0, D_004D30C0.field_0);
}

