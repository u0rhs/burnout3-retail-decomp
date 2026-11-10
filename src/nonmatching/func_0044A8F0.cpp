// NONMATCHING: func_0044A8F0 -- retail 1088 / ours 1051 instructions, 682 in changed runs
// draftAG: logic complete; retail 1088 / ours 1051; op counts agree except retail keeps the stage cursor 'base' in a stack slot (0x22C, +17 lwc1 / +11 swc1 reloads; an inline by-reference helper did not reproduce it), frame 0x230 vs 0x250, block placement (the func_00284020 / kind-switch blocks out of line)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm and Ghidra draft, every branch, store, call and VU op accounted for (Interpolate x6, SetA x3); call multiset identical (calls.sh order differs only by out-of-line block placement); row layout shared with the archived sibling func_0044B9F0

// func_0044A8F0 -- draftAG (C-first draft): a menu table component's Update(float dt) [L: a0 = self, f12 = dt; same
// row layout as func_0044B9F0 -- 8 rows of 0x24 bytes from +0xC; per-row kind bytes at +0x1C8]. Field names are
// placeholders, types [G]. Every row of kind 5/10/11 slides in from the side; other rows reveal their value one by one.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/GtMath.h"
extern "C" float cosf(float);
using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0x100]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E903E0;   // [C] the menu's CGt2dScene (D_01E90240 + 0x1A0)
extern UnkStruct_D_16 D_01E7A800;   // [C] the HUD sound manager
extern CGtV4d D_01E90350;           // [C] page manager colour (D_01E90240 + 0x110)
extern CGtV4d D_01E903C0;           // [C] page manager colour (D_01E90240 + 0x180)
extern float D_01E90420[];          // [C] menu transition progress
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90424 D_01E90424;  // [C] menu transition state
struct UnkStruct_D_004D3130 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004D3134 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004D3130 D_004D3130;
extern UnkStruct_D_004D3134 D_004D3134;
extern const CGtV4d D_004D3140;     // [C] 16-byte colours (lq / lqc2)
extern const CGtV4d D_004D3150;
extern const CGtV4d D_004D3170;
// [C] two (float, float) parameter blocks in .sbss ($gp), handed to an italic text's data block (+0x2C) by address;
// field_0 = a reveal fraction or -1, field_4 = a pulse 0..1 or -1 [L].
struct UnkStruct_D_004E2FA8 { float field_0; float field_4; };
extern UnkStruct_D_004E2FA8 D_004E2FA8;
extern UnkStruct_D_004E2FA8 D_004E2FB0;

extern "C" void func_00283B30(void *sound, int row);   // [C] reads a1; HUD sounds, unnamed
extern "C" void func_00283CA0(void *sound);
extern "C" void func_00283EF0(void *sound, int a);
extern "C" void func_00283F30(void *sound);
extern "C" void func_00283FA0(void *sound);
extern "C" void func_00284020(void *sound);
extern "C" void func_002841B0(void *sound);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void func_00453980(const CGt2dObject::CGt2dObjectSpace &, const void *);  // the italic text's render callback
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *,
    void (*)(const CGt2dObject::CGt2dObjectSpace &, const void *));

struct UnkStruct_0044A8F0;
extern "C" void func_0044CF90(UnkStruct_0044A8F0 *self, int idx, float frac);

// italic text block (+0x20): +0x2C the parameter block pointer (0 = none), +0x30 the font scale
struct UnkStruct_0044A8F0_data { unsigned char pad_0[0xC]; UnkStruct_D_004E2FA8 *field_C; CGtV2d field_10; };
// the highlighted row's field_1C object block: +0x2C a float [C sw/swc1]
struct UnkStruct_0044A8F0_data2 { unsigned char pad_0[0xC]; float field_C; };
struct UnkStruct_0044A8F0_row {
    CGt2dObject *field_0;    // [C] background (colour pulses)
    CGt2dObject *field_4;    // [C] shadow: placed at field_0's position + 6 * pulse
    CGt2dFrame *field_8;     // [C] the row frame (its x slides in)
    CGt2dFrame *field_C;     // [C] scaled 1.0 .. 1.08 by the pulse; the highlight's scale and alpha
    CGt2dObject *field_10;
    CGt2dObject *field_14;   // [C] value text (italic, field_140[row]); colour pulses
    CGt2dObject *field_18;
    CGt2dObject *field_1C;
    CGt2dObject *field_20;
};
struct UnkStruct_0044A8F0 {
    unsigned char pad_0[8];
    short field_8;                         // [C] scene layer
    unsigned char pad_A[2];
    UnkStruct_0044A8F0_row field_C[8];
    CGt2dObject *field_12C;                // [C] faded with the menu transition
    unsigned char pad_130[4];
    int field_134;                         // [C] 6: another sound set
    int field_138;                         // [C] row count
    float field_13C;                       // [C] animation timer
    const unsigned short *field_140[8];
    unsigned char pad_160[0x68];
    signed char field_1C8[8];              // [C] per-row kind: 5/10/11 slide in, 9/10 pulse, 8 no value text
    unsigned char pad_1D0[0x2E];
    signed char field_1FE;                 // [C] highlighted row, <= 0 none (>= 0 keeps the idle pulse)
    unsigned char pad_1FF;
    int field_200;                         // [C] 1: a per-row sound
    unsigned char field_204;               // [C] the intro is over: only the idle pulse runs
};

// [L] inline (repeated in retail at each use, as func_0044B9F0_inl1): give an italic text a new string, or destroy it
// when there is none.
static inline void func_0044A8F0_inl1(UnkStruct_0044A8F0 *self, CGt2dObject **slot, const unsigned short *text, float ax)
{
    CGt2dObject *o = *slot;
    if (o != 0) {
        if (text == 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, self->field_8 + 2, o);
            *slot = 0;
        } else {
            CGtV2d size = o->mObjectSpace.mSize;
            CGtV2d anchor(ax, 0.5f);
            CGtV2d pos(0.0f + o->mObjectSpace.mTopLeftPos.marValues[0] + ax * size.marValues[0], 0.0f);
            PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(
                o, pos, anchor, size.marValues[1], o->mObjectSpace.mColour, D_00665ED0.pFont, text, func_00453980);
            UnkStruct_0044A8F0_data *d = (UnkStruct_0044A8F0_data *)o->mauDataBlock;
            d->field_10 = CGtV2d(D_004D3130.field_0, D_004D3134.field_0) / o->mObjectSpace.mSize;
            d->field_C = 0;
        }
    }
}

// [L] inline: pulse every row of one kind at f (0..1): frame scale 1 .. 1.08, shadow offset 6 * f, colours.
static inline void func_0044A8F0_inl2(UnkStruct_0044A8F0 *self, int kind, float f)
{
    for (int i = 0; i < self->field_138; i++) {
        if (self->field_1C8[i] == kind) {
            UnkStruct_0044A8F0_row *r = &self->field_C[i];
            if (r->field_C != 0) {
                float s = 0.0f + 1.0f + 0.08f * f;
                CGtV2d sc(s, s);
                r->field_C->field_0.field_8 = sc;
            }
            if (r->field_4 != 0 && r->field_0 != 0) {
                r->field_4->mObjectSpace.mTopLeftPos = r->field_0->mObjectSpace.mTopLeftPos + CGtV2d(6.0f * f, 6.0f * f);
                r->field_0->mObjectSpace.mColour = Interpolate(D_004D3150, D_01E90350, f);
            }
            r->field_14->mObjectSpace.mColour = Interpolate(D_01E903C0, D_004D3170, f);
        }
    }
}

// [L] inline: a stage's clamped elapsed time (max.s / min.s pair at every stage).
static inline float func_0044A8F0_inl3(float v, float lim) { return GtMath::Min(GtMath::Max(v, 0.0f), lim); }

static inline float func_0044A8F0_inl4(float a, float b) { return 0.0f + a - b * (float)(int)(a / b); }  // fmod [L]

// 0x0044A8F0
extern "C" void func_0044A8F0(UnkStruct_0044A8F0 *self, float dt)
{
    int state = D_01E90424.field_0;
    switch (state) {
    case 5: {
        if (self->field_204) {
            if (self->field_1FE >= 0) {
                self->field_13C = func_0044A8F0_inl4(self->field_13C + dt, 1.0f);
                float f = (1.0f - cosf(0.017453292f * (360.0f * self->field_13C))) * 0.5f;
                func_0044A8F0_inl2(self, 11, f);
            }
            return;
        }
        float base = 0.0f;
        self->field_13C += dt;
        float cur = 2.5f * func_0044A8F0_inl3(self->field_13C - base, 0.4f);
        base += 0.4f;
        // the side rows slide in over the first 0.4 s (kind 5 from the right)
        for (int i = 0; i < self->field_138; i++) {
            signed char k = self->field_1C8[i];
            if (k == 5 || k == 10 || k == 11) {
                CGt2dFrame *fr = self->field_C[i].field_8;
                CGtV2d p = fr->field_0.field_0;
                if (k == 5)
                    p.marValues[0] = 0.0f + 640.0f + cur * -640.0f;
                else
                    p.marValues[0] = 0.0f + -640.0f + cur * 640.0f;
                fr->field_0.field_0 = p;
            }
        }
        // the other rows, one 0.4 s stage each; a run of them ends at a side row, whose stage then pulses the
        // previous row's value (1.2 s)
        UnkStruct_0044A8F0_row *prev = 0;
        signed char prevKind;
        float last;
        for (int i = 0; i < self->field_138; i++) {
            UnkStruct_0044A8F0_row *row = &self->field_C[i];
            signed char *kp = &self->field_1C8[i];
            bool own = true;
            switch (*kp) {
            case 5:
            case 10:
            case 11:
                own = false;
                break;
            }
            if (own || prev != 0) {
                float d = self->field_13C - base;
                float a = func_0044A8F0_inl3(d, 0.4f);
                float b = func_0044A8F0_inl3(d - dt, 0.4f);
                cur = 2.5f * a;
                base += 0.4f;
                last = 2.5f * b;
                if (own && 0.0f == b && !(a <= 0.0f))
                    func_00284020(&D_01E7A800);
            }
            if (own) {
                CGt2dFrame *fr = row->field_8;
                CGtV2d p(0.0f + 640.0f + cur * -640.0f, fr->field_0.field_0.marValues[1]);
                fr->field_0.field_0 = p;
            }
            if (prev != 0) {
                UnkStruct_D_004E2FA8 *pp = 0;
                if (!(cur <= 0.0f) && 0.0f == last) {
                    if (self->field_134 == 6) {
                        switch (prevKind) {
                        case 11:
                        case 10:
                        case 9:
                        case 7:
                            func_00283F30(&D_01E7A800);
                            break;
                        case 8:
                            func_00283EF0(&D_01E7A800, 0);
                            break;
                        default:
                            func_002841B0(&D_01E7A800);
                            break;
                        }
                    } else if (self->field_200 == 1) {
                        func_00283B30(&D_01E7A800, i);
                    } else {
                        func_002841B0(&D_01E7A800);
                    }
                }
                if (!(cur <= 0.0f) && cur < 1.0f) {
                    pp = &D_004E2FA8;
                    D_004E2FA8.field_0 = cur;
                    D_004E2FA8.field_4 = -1.0f;
                }
                if (!own) {
                    cur = 1.25f * func_0044A8F0_inl3(self->field_13C - (base - 0.4f), 1.6f);
                    if (!(cur <= 0.0f) && cur < 2.0f) {
                        if (pp == 0) {
                            pp = &D_004E2FA8;
                            D_004E2FA8.field_0 = -1.0f;
                        }
                        pp->field_4 = (1.0f - cosf(0.017453292f * (360.0f * cur))) * 0.5f;
                    }
                    base += 1.2f;
                }
                ((UnkStruct_0044A8F0_data *)prev->field_14->mauDataBlock)->field_C = pp;
            }
            if (own) {
                if (*kp != 8) {
                    cur = 2.5f * func_0044A8F0_inl3(self->field_13C - base, 0.4f);
                    func_0044CF90(self, i, cur);
                    func_0044A8F0_inl1(self, &self->field_C[i].field_14, self->field_140[i], 1.0f);
                    base += 0.4f;
                }
                prevKind = *kp;
                prev = row;
            } else {
                prev = 0;
            }
        }
        // kinds 9 and 10 pulse in opposite phase over the next stage
        float g = 2.5f * func_0044A8F0_inl3(self->field_13C - base, 0.4f);
        base += 0.4f;
        func_0044A8F0_inl2(self, 9, 1.0f - g);
        func_0044A8F0_inl2(self, 10, g);
        // then the kind-10 rows reveal their values
        for (int i = 0; i < self->field_138; i++) {
            if (self->field_1C8[i] == 10) {
                UnkStruct_D_004E2FA8 *pp = 0;
                UnkStruct_0044A8F0_row *row = &self->field_C[i];
                float c = 2.5f * func_0044A8F0_inl3(self->field_13C - base, 0.4f);
                base += 0.4f;
                func_0044CF90(self, i, c);
                func_0044A8F0_inl1(self, &self->field_C[i].field_14, self->field_140[i], 1.0f);
                if (!(c <= 0.0f)) {
                    D_004E2FA8.field_4 = -1.0f;
                    pp = &D_004E2FA8;
                    float d = self->field_13C - base;
                    float a = func_0044A8F0_inl3(d, 0.4f);
                    float b = func_0044A8F0_inl3(d - dt, 0.4f);
                    c = 2.5f * a;
                    base += 0.4f;
                    if (!(c <= 0.0f) && c < 1.0f)
                        D_004E2FA8.field_0 = c;
                    else
                        pp->field_0 = -1.0f;
                    if (!(c <= 0.0f) && 0.0f == b) {
                        if (self->field_134 == 6)
                            func_00283F30(&D_01E7A800);
                        else
                            func_002841B0(&D_01E7A800);
                    }
                }
                ((UnkStruct_0044A8F0_data *)row->field_14->mauDataBlock)->field_C = pp;
            }
        }
        // the highlighted row: flash, value reveal + pulse, then its highlight settles
        if (self->field_1FE > 0) {
            UnkStruct_D_004E2FA8 *pp = 0;
            base -= 0.2f;
            CGtV4d col(D_01E90350);
            float d = self->field_13C - base;
            float x = 0.0f + 1.0f - 4.0f * func_0044A8F0_inl3(d, 0.25f);
            float y = 0.0f + 1.0f - 4.0f * func_0044A8F0_inl3(d - 0.02f, 0.25f);
            if (0.0f == x && !(y <= 0.0f))
                func_00283FA0(&D_01E7A800);
            UnkStruct_0044A8F0_row *r = &self->field_C[self->field_1FE];
            col.SetA(5.0f * func_0044A8F0_inl3(d, 0.2f));
            ((UnkStruct_0044A8F0_data2 *)r->field_1C->mauDataBlock)->field_C = 3.76991153f * x;
            r->field_1C->mObjectSpace.mColour = col;
            base += 0.25f;
            float c = 2.5f * func_0044A8F0_inl3(self->field_13C - base, 0.4f);
            base += 0.4f;
            if (!(c <= 0.0f) && c < 1.0f) {
                pp = &D_004E2FB0;
                D_004E2FB0.field_0 = c;
                D_004E2FB0.field_4 = -1.0f;
            }
            float e = func_0044A8F0_inl3(self->field_13C - (base - 0.4f), 1.6f);
            if (!(e <= 0.0f) && e <= 0.03f)
                func_00283FA0(&D_01E7A800);
            e = 1.25f * e;
            base += 1.6f;
            if (!(e <= 0.0f) && e < 2.0f) {
                pp = &D_004E2FB0;
                D_004E2FB0.field_0 = -1.0f;
                D_004E2FB0.field_4 = (1.0f - cosf(0.017453292f * (360.0f * e))) * 0.5f;
            }
            ((UnkStruct_0044A8F0_data *)r->field_14->mauDataBlock)->field_C = pp;
            d = self->field_13C - base;
            float a = func_0044A8F0_inl3(d, 0.25f);
            float b = func_0044A8F0_inl3(d - dt, 0.25f);
            if (!(a <= 0.0f) && 0.0f == b)
                func_00283CA0(&D_01E7A800);
            float s = 4.0f * a;
            base += 0.25f;
            float v;
            if (base < self->field_13C) {
                v = GtMath::Max(0.05f, 4.0f * func_0044A8F0_inl3(self->field_13C - base, 0.25f));
                r->field_10->mObjectSpace.mColour = D_004D3140;
                r->field_1C->mObjectSpace.mColour = D_004D3140;
                r->field_20->mObjectSpace.mColour = D_01E90350;
            } else {
                v = GtMath::Max(0.05f, 1.0f - s);
            }
            CGtV2d sc(v, v);
            r->field_C->field_0.field_8 = sc;
            r->field_C->field_0.field_10.SetA(v);
            base += 0.25f;
        }
        self->field_204 = base < self->field_13C;
        if (self->field_204)
            self->field_13C = 0.0f;
    } break;
    case 2:
    case 3:
    case 4: {
        CGtV4d c(D_01E90350);
        c.SetA(D_01E90420[0]);
        self->field_12C->mObjectSpace.mColour = c;
    } break;
    }
}

