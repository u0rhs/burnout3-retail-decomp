// NONMATCHING: func_003D76C0 -- retail 285 / ours 286 instructions, 3 in changed runs
// v301: 3 off (285/286): only the header Interpolate(CGtV4d)'s t mfc1 v1,f22 is scheduled after vaddax (+nop) where retail hoists it before the cursor/extra mul/add; t = pop is a variable (f22) here, not the HelpBar constant; every placement of float t = pop tried. Logic, frame (2 N140 pads), VU numbering exact.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003D76C0 -- [G] the crash-combo text's render callback (CGt2dObjectComboText::_Render shape: its unit holds DNAT's
// CGt2dObjectComboText::_BuildBatchData = func_003D7340, called here). Hand-written (lifter refused).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
using GtMathPs2::WAxisType;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

struct UnkStruct_D_0066A4C0 {
    unsigned char pad0[0x10];
    CGtV4d field_10;
    unsigned char pad20[0x20];
    CGtV4d field_40;
    unsigned char pad50[0x100];
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;

// [L] .rodata CGtV2d filled by the file's static initializer (as kHelpBarRecipSize).
extern const CGtV2d D_004CA920;
extern unsigned short D_004CA928[];
extern unsigned short D_004CA930[];

struct UnkStruct_003D76C0_combo {
    unsigned char pad_0[0x100];
    int field_100;
};
struct UnkStruct_003D76C0_data {
    float field_0;
    UnkStruct_003D76C0_combo *field_4;
};

extern "C" unsigned short *Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short *Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" void *GetFirstItem__13CB3CrashComboFb(UnkStruct_003D76C0_combo *, bool);
extern "C" void *GetNextItem__13CB3CrashComboFv(UnkStruct_003D76C0_combo *);
extern "C" void func_00364300(void *item, unsigned short *s, int n);
extern "C" int func_003D7340(const CGtV2d &scale, CGtV2d *cursor, const unsigned short *s,
                             const CGt2dObject::CGt2dObjectSpace &space, const void *data);

// [G] probably GtMath::Interpolate(float,float,float) (B3O0PCH map, 0x48): no header body yet.
static inline float func_003D76C0_inl1(float a, float b, float t) { float z = 0.0f; float d = b - a; return z + a + d * t; }
// [L] N185: stand-in: zero vector with w taken from another vector's w lane.
static inline CGtV4d func_003D76C0_inl2(const WAxisType &w)
{
    u_long128 r;
    asm("vsub.xyzw %0, $vf0, $vf0" : "=j"(r));
    asm("vmulw.w %0, $vf0, %1w" : "+j"(r) : "j"(w.lVector));
    return CGtV4d(r);
}

static inline float func_003D76C0_inl3(float sx, const unsigned short *s) { float w = 25.0f * D_00665ED0.pFont->GetStringWidthIncludingLRKern(s); return w * sx; }

struct UnkStruct_003D76C0_pad { int x[4]; UnkStruct_003D76C0_pad() {} ~UnkStruct_003D76C0_pad() {} };

// 0x003D76C0
extern "C" void func_003D76C0(const CGt2dObject::CGt2dObjectSpace &space, const void *p)
{
    const UnkStruct_003D76C0_data *data = (const UnkStruct_003D76C0_data *)p;
    UnkStruct_D_0066A4C0 *const colours = &D_0066A4C0;
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    CGtV2d scale = D_004CA920 * space.mSize;
    CGtV2d zero(0.0f, 0.0f);
    CGtV4d shadow;
    CGtV2d offs[4];
    CGtV4d colour;
    unsigned short buf[64];
    UnkStruct_003D76C0_pad pad;
    UnkStruct_003D76C0_pad pad2;
    float pop = 1.0f;
    float fade = 1.0f;
    float tm = data->field_0;
    if (tm > 0.0f) {
        if (tm > 0.5f) {
            float u = (tm - 0.5f) / 19.2f;
            fade = 1.0f - GtMath::Min(GtMath::Max(u, 0.0f), 1.0f);
            pop = 0.0f;
        } else {
            float u = tm / 0.5f;
            float v = 1.0f - GtMath::Min(GtMath::Max(u, 0.0f), 1.0f);
            pop = v * v;
        }
    }
    CGtV2d cursor(space.mTopLeftPos.marValues[0] + space.mSize.marValues[0], space.mTopLeftPos.marValues[1]);
    float extra = 46.0f * scale.X();
    float t = pop;
    CGtV4d blend = GtMathPs2::Interpolate(colours->field_10, colours->field_40, t);
    offs[0] = scale * 0.017453292f;
    colour = blend * space.mColour;
    shadow = func_003D76C0_inl2(space.mColour.W());
    offs[2].SetX(offs[0].X());
    offs[1] = -offs[0];
    offs[2].SetY(offs[1].Y());
    offs[3] = -offs[2];
    Gt2dRenderer::SetTexture(D_00665ED0.pFont->field_4);
    void *item = GetFirstItem__13CB3CrashComboFb(data->field_4, false);
    int k = data->field_4->field_100 - 1;
    while (item != 0) {
        unsigned short *s = buf;
        if (k != 0)
            s = Copy__10CGtUnicodeFPUsPCUs(buf, D_004CA930);
        func_00364300(item, s, 0x40);
        Append__10CGtUnicodeFPUsPCUs(s, D_004CA928);
        float w = func_003D76C0_inl3(scale.marValues[0], buf);
        cursor.marValues[0] = cursor.marValues[0] - (extra + w * fade);
        fade = 1.0f;
        extra = 0.0f;
        int n = func_003D7340(scale, &cursor, buf, space, data);
        if (n > 0) {
            if (pop < 1.0f) {
                float s2 = func_003D76C0_inl1(1.5f, 1.0f, pop);
                float r = 1.0f - s2;
                float cx = 0.5f * (pos[0].marValues[0] + pos[n - 1].marValues[0]);
                float cy = space.mTopLeftPos.marValues[1] + 0.5f * space.mSize.marValues[1];
                CGtV2d cr(cx * r, r * cy);
                for (int i = 0; i < n; i++)
                    pos[i] = cr + pos[i] * s2;
                pop = 1.0f;
            }
            for (int j = 0; j < 4; j++)
                Gt2dRenderer::RenderTriStripFlatTex(shadow, offs[j], n, pos, uv);
            Gt2dRenderer::RenderTriStripFlatTex(colour, zero, n, pos, uv);
        }
        if (cursor.marValues[0] < 0.0f)
            return;
        colour = colours->field_40 * space.mColour;
        k--;
        item = GetNextItem__13CB3CrashComboFv(data->field_4);
    }
}






