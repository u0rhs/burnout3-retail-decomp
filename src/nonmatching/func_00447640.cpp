// NONMATCHING: func_00447640 -- retail 284 / ours 296 instructions, 229 in changed runs
// v303 first draft (lifter refused), logic decoded: dead MulWW(a,a) lane read, func_00447AB0 strip, 4 outline passes (offsets 0.0315*size with -0.0063 shear / -0.005 step, values [C]), 3 gradient passes (D_004D3040..3090 pairs * colour; p0/p1 per pass; func_00217E70(2)/(0)) over 6-vertex glyph strips with Interpolate by y. Left: retail builds the outline offsets through CGtV2d operator temporaries (0x248-0x274 unary-minus/copy slots) -- form not found; frame 0x2A0 vs 0x270; header Interpolate(CGtV4d) puts b on vf1 where this site has b on vf2/t on vf1 (local stand-in used); shadow alpha is vmulw.w from colour.w (SetW(WAxisType)-like, no header API)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00447640 -- the gradient italic-text render callback func_00447E50 installs (cb when the text has width) [L by
// that Prepare]. Hand-written (lifter refused). Builds the strip with func_00447AB0 (archived), draws four outline passes
// in a black shadow colour (alpha = the object's), then three gradient passes (colour pairs D_004D3040..3090 times the
// object colour, interpolated down each glyph quad by its y; offsets p0..p1 across x). Layout [G] from the asm.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

struct UnkStruct_00447E50_data {
    const unsigned short *field_0;
    float field_4;
    float field_8;
};
struct UnkStruct_D_00665ED4 { CGt2dFont *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665ED4 D_00665ED4;
extern const CGtV4d D_004D3040, D_004D3050, D_004D3060, D_004D3070, D_004D3080, D_004D3090;
extern "C" int func_00447AB0(const CGt2dObject::CGt2dObjectSpace &space, const UnkStruct_00447E50_data *d, CGt2dFont *font);
extern "C" void func_00217E70(int);
extern "C" void RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d(
    const CGtV2d &, int, const CGtV2d *, const CGtV2d *, const CGtV4d *);

// [L] N185: stands in for operator *(WAxisType, WAxisType) (as the archived FlashText _Render)
static inline WAxisType func_00447640_inl1(WAxisType a, WAxisType b) { u_long128 r; asm("vmulw.w %0, %1, %2w" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
// [L] N185: stands in for Interpolate(CGtV4d, CGtV4d, float) in this site's register shape (t on vf1, b on vf2)
static inline CGtV4d func_00447640_inl2(const CGtV4d &a, const CGtV4d &b, float t)
{
    u_long128 tv, r;
    asm("vaddax.xyzw $ACC, %1, $vf0x" "\n\t" "qmtc2.ni %2, %0" "\n\t" "vmsubax.xyzw $ACC, %1, %0x" : "=&j"(tv) : "j"(a.mData), "r"(t));
    asm("vmaddx.xyzw %0, %1, %2x" : "=j"(r) : "j"(b.mData), "j"(tv));
    return CGtV4d(r);
}
// [G] colour *= object colour
static inline void func_00447640_inl3(CGtV4d &c, const CGtV4d &o) { asm("vmul.xyzw %0, %0, %1" : "+j"(c.mData) : "j"(o.mData)); }

#define RB (const CGtV2d *)CGt2dObject::mgu8RenderBatchData, (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0)

// 0x00447640
extern "C" void func_00447640(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_00447E50_data *d = (const UnkStruct_00447E50_data *)data;
    CGtV4d shadow;
    CGtV4d top;
    CGtV4d bot;
    CGtV4d cols[4];
    CGtV2d off[4];
    CGt2dFont *font = D_00665ED4.field_0;
    float sx = d->field_4 * space.mSize.marValues[0];
    float sy = space.mSize.marValues[1];
    shadow.Zero();
    WAxisType a = space.mColour.W();
    float aa = func_00447640_inl1(a, a);
    int n = func_00447AB0(space, d, font);
    // [C] values from the asm (0.0315 outline size, -0.0063 italic shear, -0.005 step); the CGtV2d-operator shape that
    // gives retail's temporaries (0x248..0x274) is not yet found.
    CGtV2d o = CGtV2d(sx, sy) * 0.0315f;
    float sh = -0.0063f * sx;
    float st = -0.005f * sx;
    off[0] = CGtV2d(sh + o.marValues[0], o.marValues[1]);
    off[1] = CGtV2d((sh - o.marValues[0]) + st, o.marValues[1]);
    off[2] = CGtV2d(off[1].marValues[0] + st, -o.marValues[1]);
    off[3] = CGtV2d(-(sh - o.marValues[0]), -o.marValues[1]);
    Gt2dRenderer::SetTexture(font->field_4);
    shadow.SetA(space.mColour.W());
    for (int i = 0; i < 4; i++)
        Gt2dRenderer::RenderTriStripFlatTex(shadow, off[i], n, RB);
    const CGtV2d *pb = (const CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    const CGtV2d *ub = (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    float w = pb[n - 4].marValues[0] - pb[0].marValues[0];
    float h = space.mSize.marValues[1];
    float ih = 0.990099f / h;
    float y0 = space.mTopLeftPos.marValues[1] - 0.005f * h;
    float iw = 0.990099f / w;
    float x0 = pb[0].marValues[0] - 0.005f * w;
    const CGtV2d *pe = pb + n + 2;
    const CGtV2d *ue = ub + n + 2;
    for (int pass = 0; pass < 3; pass++) {
        CGtV2d p0;
        CGtV2d p1;
        if (pass == 0) {
            top = D_004D3040;
            bot = D_004D3050;
            p0 = CGtV2d(-0.005f, 0.0f);
            p1 = CGtV2d(-0.05f, 0.0f);
        } else if (pass == 1) {
            top = D_004D3060;
            bot = D_004D3070;
            p0 = CGtV2d(0.0f, 0.0f);
            p1 = CGtV2d(0.0f, 0.0f);
        } else if (pass == 2) {
            top = D_004D3080;
            bot = D_004D3090;
            func_00217E70(2);
            p0 = CGtV2d(0.0224f, 0.0112f);
            p1 = p0;
        }
        p0.marValues[0] *= sx;
        p0.marValues[1] *= sy;
        p1.marValues[0] *= sx;
        p1.marValues[1] *= sy;
        func_00447640_inl3(top, space.mColour);
        func_00447640_inl3(bot, space.mColour);
        CGtV2d dp(p1.marValues[0] - p0.marValues[0], p1.marValues[1] - p0.marValues[1]);
        const CGtV2d *pv = pe;
        const CGtV2d *uv = ue;
        do {
            pv -= 6;
            uv -= 6;
            CGtV2d o = p0 + CGtV2d(dp) * (iw * (pv[0].marValues[0] - x0));
            cols[0] = cols[1] = func_00447640_inl2(top, bot, ih * (pv[0].marValues[1] - y0));
            cols[2] = cols[3] = func_00447640_inl2(top, bot, ih * (pv[2].marValues[1] - y0));
            RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d(o, 4, pv, uv, cols);
        } while (pb < pv);
    }
    func_00217E70(0);
}
