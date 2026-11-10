// NONMATCHING: func_00394280 -- retail 247 / ours 247 instructions, 2 in changed runs
// near2: 2 off (was 6). The call-site t local must be declared BEFORE `float x = ...` here (N224 early-t rule inverted at this site: retail numbers the field_30 pointer a1, t a2). Left: one lui a2,0x3F40 (t) scheduled 3 slots early (retail: after lui 14.0/0.5 and addiu a3). Tried: literal t, const t, split decl/assign, named CGtV2d temps, k14 local, p30 pointer local, x -= 112 split. | near5: k_t placement sweep (top, before t/rec, after x: 6 off, const, split decl/assign: 2) -- no change.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// NONMATCHING: func_00394280 -- retail 247 / ours 247 instructions, 13 in changed runs
// v295: logic complete, 247/247 instrs, frame 0x130 exact, 13 in changed runs: only the first func_003824D0 call's setup -- retail loads Interpolate's b (lq colours+0x30) and 0.75f before the field_30 lwc1s and rotates a1/a0/v1/a2/v0, ours loads b after them (v1 reused). Interpolate stand-in = header N94 body split: vaddax/qmtc2.ni t/vmsubax, then .set noreorder {qmtc2.i b; vmaddx; qmfc2.i} (keeps lq+qmtc2 and qmfc2+sq unfolded; .i cleared by vu0_ni_fixup); found-block reload via byte-offset pun; time text in a static inline (puts buf below the temps). Tried: statement/arg orders, named temps, const& params, operand order.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_00394280 -- hand-written (v295); the lifter refused it.
// [L] DNAT: CB3HUDLapTimer::PrepareMedalObjects() (research/proto/new_names.csv, low -- a hint only). Area not evidenced,
// so _unclassified/. Field names are placeholders and every type is [G] (instruction widths).
// [G] meaning: find the best medal time the current lap beats (times at field_34->field_7C[0..2]), tell the HUD sound
// manager, then print the target time "m:ss.hh" and prepare either the record text or the medal image.
// Shapes from the proven sibling CB3HUDTimer::Prepare (B3HUDTimer_003C26F0.cpp: func_003824D0 call, colours at D_0066A4C0).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00394280_30 { float field_0; unsigned char pad_4[0x4]; float field_8; };
struct UnkStruct_00394280_34 {
    unsigned char pad_0[0x3C];
    float field_3C;
    unsigned char pad_40[0x30];
    int field_70;
    unsigned char pad_74[0x8];
    float * field_7C;
};
struct UnkStruct_00394280_r { unsigned char pad_0[0x18]; float field_18; };
struct UnkStruct_00394280 {
    unsigned char pad_0[0x28];
    void * field_28;
    void * field_2C;
    UnkStruct_00394280_30 * field_30;
    UnkStruct_00394280_34 * field_34;
    float field_38;
    float field_3C;
    unsigned char pad_40[0x40];
    unsigned short field_80[0x20];
    void * field_C0[5];
    float * field_D4;
};
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x30];
    CGtV4d field_30;
    CGtV4d field_40;
    unsigned char pad_50[0x10];
    CGtV4d field_60;
};
struct UnkStruct_D_0064D370 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01EA7810 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_01EA7810 D_01EA7810;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern char D_004C98C0[];

extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" void func_003824D0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int, float, float);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_00284820(void *, float, float);
extern "C" void func_002847A0(void *, int);
extern "C" float func_00155280(float);
extern "C" UnkStruct_00394280_r * GetTrackRecords__10CB3RecordsFUl(void *, unsigned long);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const CGtV2d &, const CGtV2d &, unsigned int);  // plus retail's stack argument (N68)

static inline float func_00394280_inl1(float a, float b) { float r; asm("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

// [L] stand-in for GtMathPs2::Interpolate(CGtV4d, CGtV4d, float) (B3O0PCH map; header body N94): the header's register use
// (t on $vf2, b moved into a's register), with b's move and the result's move written .i so MWCC keeps retail's unfolded
// lq + qmtc2 and qmfc2 + sq (tools/vu0_ni_fixup.py clears the interlock bit, N205).


// [G] the time printed as "m:ss.hh" (a file-local helper: its buffer sits below the caller's temporaries, as in retail's frame)
static inline void func_00394280_inl3(float t, unsigned short * out)
{
    int m, s, h;
    if (t == 3.402823466e+38f) {
        m = 0;
        s = 0;
        h = 0;
    } else {
        m = (int)(0.01666666754f * t);
        float sec = 0.0f + t - 60.0f * (float)(int)(t / 60.0f);
        s = (int)sec;
        h = (int)(100.0f * (sec - (float)s)) % 100;
    }
    char buf[32];
    snprintf(buf, 31, D_004C98C0, m, s, h);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, out, 0x20);
}

// 0x00394280
extern "C" void func_00394280(UnkStruct_00394280 * self)
{
    UnkStruct_D_0066A4C0 * const colours = &D_0066A4C0;
    int medal = 2;
    self->field_D4 = self->field_34->field_7C;
    float * times = self->field_34->field_7C;
    if (times != 0 && self->field_38 != 3.402823466e+38f) {
        float cur = self->field_38;
        medal = self->field_34->field_70;
        int i = 3;
        while (i--) {
            if (cur <= times[i] && (i > medal || medal == 4)) {
                medal = i;
                self->field_3C = ((float *)((char *)times + i * 4))[0];
                func_00284820(&D_01E7A800, 1.0f, self->field_34->field_7C[i] - self->field_38);
                break;
            }
        }
        func_002847A0(&D_01E7A800, medal);
    }
    if (medal == 4)
        medal = 0;
    float t;
    bool rec;
    if (self->field_34->field_7C == 0 || medal == 4 || self->field_34->field_70 == 2) {
        float best = 3.402823466e+38f;
        UnkStruct_00394280_r * r = GetTrackRecords__10CB3RecordsFUl(&D_01EA7810, D_0064D370.field_0);
        if (r)
            best = r->field_18;
        t = func_00394280_inl1(func_00155280(self->field_34->field_3C), best);
        rec = true;
    } else {
        t = self->field_3C;
        rec = false;
    }
    func_00394280_inl3(t, self->field_80);
    float k_t = 0.75f;
    float x = self->field_30->field_0 + self->field_30->field_8 - 112.0f;
    func_003824D0(self->field_2C, CGtV2d(x, 14.0f), CGtV2d(0.0f, 0.5f), 30.0f, colours->field_60,
                  GtMathPs2::Interpolate(colours->field_60, colours->field_30, k_t), self->field_80, 0x61, 1.25f, 3.402823466e+38f);
    if (rec) {
        const unsigned short * text = func_00271A00(&D_0051BA44, 0x7FC);
        func_003824D0(self->field_28, CGtV2d(0.0f, 14.0f), CGtV2d(0.0f, 0.5f), 27.0f, colours->field_40, colours->field_40,
                      text, 0x49, 1.0f, x - 2.0f);
    } else {
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
            self->field_28, CGtV2d(0.0f, 13.5f), CGtV2d(0.0f, 0.5f), CGtV2d(40.0f, 40.0f), CGtV4d(1.0f, 1.0f, 1.0f, 1.0f),
            self->field_C0[medal], CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
    }
}

