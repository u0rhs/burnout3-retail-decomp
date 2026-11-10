// NONMATCHING: func_003CE290 -- retail 682 / ours 707 instructions, 861 in changed runs
// draftAI: logic complete; retail 682 / ours 707; call identical; every FP and VU op count identical (header Interpolate x10, CGtV4d*CGtV4d x4, CGtV2d +,-,*float, GtMath::Min/Max); real parameter list from the registers (style in t3, as _RenderNormal leaves it); two retail quirks kept: the first band's 6-vertex cut is dead (re-tests 0.48) and the second band's 6-vertex cut leaves laRGBAs[4..5] unwritten; left: nops (+12), colour copies through lqc2/lq (+4), addiu +5, frame 0x410 vs 0x5E0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm op for op: axis from the 2x2 inverse, 4 whiteness-lightened stops per style, the 3x3 band cases with 4/6/8-vertex cuts, the common corner copies and one gouraud strip per glyph

// func_003CE290 -- draftAI (C-first draft, 0x3CE290, 0xAA8). [L] DNAT CB3StylisedText2dObject::_DispatchMetallic(CGtV4d,
// const CGtV2d&, const CGtV2d*, const CGtV2d*, ...) (research/proto/new_names.csv, high; the map's signature is truncated).
// Retail's label is still the placeholder, so C linkage. Parameter list from the registers [C]: colour (a0, by value), the
// offset (a1), the glyph strip's positions and UVs (a2, a3), its vertex count (t0), the object's x and y axes (t1, t2), the
// style 1..3 (t3: _RenderNormal leaves field_10 there) and the whiteness (f12).
// What it draws [L]: each glyph quad (6 strip vertices apart) with a vertical chrome gradient: four colour stops (by style:
// D_004CA500.., D_004CA540.., D_004CA580..) at 0, 0.48, 0.51 and 1 of the height, each lightened towards D_004CA5C0 by the
// whiteness; a quad crossing a stop is cut there (4, 6 or 8 vertices) and drawn as one gouraud strip.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

namespace Gt2dRenderer {
void RenderTriStripGouraudTex(const CGtV2d &, int, const CGtV2d *, const CGtV2d *, const CGtV4d *);   // [C] mangled name (queued)
}
extern const CGtV4d D_004CA500, D_004CA510, D_004CA520, D_004CA530;   // [C] style 1's stops (rodata)
extern const CGtV4d D_004CA540, D_004CA550, D_004CA560, D_004CA570;   // [C] style 2's stops
extern const CGtV4d D_004CA580, D_004CA590, D_004CA5A0, D_004CA5B0;   // [C] style 3's stops
extern const CGtV4d D_004CA5C0;                                         // [C] the colour the whiteness blends towards

// [L] the quad cut at fraction s of its height: a pair of new strip vertices (left, right) and their UVs
static inline void func_003CE290_inl1(CGtV2d *xy, CGtV2d *uv, const CGtV2d *p, const CGtV2d *q, float s)
{
    xy[0] = p[0] + (p[2] - p[0]) * s;
    xy[1] = p[1] + (p[3] - p[1]) * s;
    uv[0] = q[0] + (q[2] - q[0]) * s;
    uv[1] = q[1] + (q[3] - q[1]) * s;
}

// 0x003CE290
extern "C" void func_003CE290(CGtV4d lColour, const CGtV2d &lPos, const CGtV2d *lpXYs, const CGtV2d *lpUVs, int n,
                              const CGtV2d &a, const CGtV2d &b, int style, float lrWhiteness)
{
    float inv = 1.0f / (b.marValues[1] * a.marValues[0] - b.marValues[0] * a.marValues[1]);
    CGtV2d lAxis(-a.marValues[1] * inv, a.marValues[0] * inv);   // the height direction, scaled to 0..1 over the object
    CGtV4d c0;
    CGtV4d c1;
    CGtV4d c2;
    CGtV4d c3;
    switch (style) {
    case 1:
        c0 = D_004CA500;
        c1 = D_004CA510;
        c2 = D_004CA520;
        c3 = D_004CA530;
        break;
    case 2:
        c0 = D_004CA540;
        c1 = D_004CA550;
        c2 = D_004CA560;
        c3 = D_004CA570;
        break;
    case 3:
        c0 = D_004CA580;
        c1 = D_004CA590;
        c2 = D_004CA5A0;
        c3 = D_004CA5B0;
        break;
    }
    c0 = Interpolate(c0, D_004CA5C0, lrWhiteness) * lColour;
    c1 = Interpolate(c1, D_004CA5C0, lrWhiteness) * lColour;
    c2 = Interpolate(c2, D_004CA5C0, lrWhiteness) * lColour;
    c3 = Interpolate(c3, D_004CA5C0, lrWhiteness) * lColour;
    CGtV2d laUVs[8];
    CGtV2d laXYs[8];
    CGtV4d laRGBAs[8];
    while (n >= 4) {
        float u0 = GtMath::Max(lpXYs[0].marValues[1] * lAxis.marValues[1] + lpXYs[0].marValues[0] * lAxis.marValues[0], 0.0f);
        float u1 = GtMath::Min(lpXYs[2].marValues[1] * lAxis.marValues[1] + lpXYs[2].marValues[0] * lAxis.marValues[0], 1.0f);
        int lnCount;
        if (u0 < 0.48f) {
            laRGBAs[0] = laRGBAs[1] = Interpolate(c0, c1, 2.0833335f * u0);
            if (u1 < 0.48f) {
                laRGBAs[2] = laRGBAs[3] = Interpolate(c0, c1, 2.0833335f * u1);
                lnCount = 4;
            } else {
                laRGBAs[2] = laRGBAs[3] = c1;
                func_003CE290_inl1(&laXYs[2], &laUVs[2], lpXYs, lpUVs, (0.48f - u0) / (u1 - u0));
                // [C] retail tests the first stop again here (c.lt.s against 0.48, already false), so the 6-vertex cut is
                // never taken and a quad ending before 0.51 still gets the second cut (s > 1, extrapolated): kept as retail
                if (u1 < 0.48f) {
                    laRGBAs[4] = laRGBAs[5] = Interpolate(c1, c2, 33.333332f * (u1 - 0.48f));
                    lnCount = 6;
                } else {
                    laRGBAs[4] = laRGBAs[5] = c2;
                    func_003CE290_inl1(&laXYs[4], &laUVs[4], lpXYs, lpUVs, (0.51f - u0) / (u1 - u0));
                    laRGBAs[6] = laRGBAs[7] = Interpolate(c2, c3, 2.0408163f * (u1 - 0.51f));
                    lnCount = 8;
                }
            }
        } else if (u0 < 0.51f) {
            laRGBAs[0] = laRGBAs[1] = Interpolate(c1, c2, 33.333332f * (u0 - 0.48f));
            if (u1 < 0.51f) {
                laRGBAs[2] = laRGBAs[3] = Interpolate(c1, c2, 33.333332f * (u1 - 0.48f));
                lnCount = 4;
            } else {
                laRGBAs[2] = laRGBAs[3] = c2;
                lnCount = 6;
                func_003CE290_inl1(&laXYs[2], &laUVs[2], lpXYs, lpUVs, (0.51f - u0) / (u1 - u0));
                // [C] laRGBAs[4] and [5] are not written on this path (retail: no store; they keep the last glyph's values)
            }
        } else {
            laRGBAs[0] = laRGBAs[1] = Interpolate(c2, c3, 2.0408163f * (u0 - 0.51f));
            laRGBAs[2] = laRGBAs[3] = Interpolate(c2, c3, 2.0408163f * (u1 - 0.51f));
            lnCount = 4;
        }
        laXYs[0] = lpXYs[0];
        laXYs[1] = lpXYs[1];
        laUVs[0] = lpUVs[0];
        laUVs[1] = lpUVs[1];
        laUVs[lnCount - 2] = lpUVs[2];
        laXYs[lnCount - 2] = lpXYs[2];
        laXYs[lnCount - 1] = lpXYs[3];
        laUVs[lnCount - 1] = lpUVs[3];
        Gt2dRenderer::RenderTriStripGouraudTex(lPos, lnCount, laXYs, laUVs, laRGBAs);
        lpXYs += 6;
        lpUVs += 6;
        n -= 6;
    }
}
