// NONMATCHING: _RenderCurveSection__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4df -- retail 212 / ours 212 instructions, 119 in changed runs
// sdra: const pointee on a read-only param [G] (const loads are not ordered after stores, sdra rule 1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: _RenderCurveSection__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4df -- retail 212 / ours 212 instructions, 130 in changed runs
// a156: 212/212 instrs, 130 in changed runs; logic and block layout (tex block first, untex out of line via if(tex==0){untex}else{tex}), frame 0x1B0 exact. Left: pure scheduling/FPR numbering: retail loads scale2.y into f11 / a0.y f8 first and issues the 8 products in a different interleave (ours f0/f10/f8); retail hoists the colour lq to the very first slot and puts c.lt.s f5,f4 right before bc1f; the dir0/dir1 temp slots (retail 0x130/0x128, ours differ).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// Hand-written (a156): CGt2dBezierCurve::_RenderCurveSection -- one bezier section drawn as a textured/flat wide-line strip.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01EBE380 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01EBE380 D_01EBE380;

struct CGtBezierSection {
    CGtV2d pt[4];
    float field_20;
    float field_24;
};
struct UnkStruct_RCS_data {
    CGtV2d field_0;
    unsigned char pad_8[8];
    float field_10;
};
struct UnkStruct_CGtWideLinePoint {
    CGtV2d field_0;
    CGtV2d field_8;
    unsigned char pad_10[0x10];
    float field_20;
    unsigned char pad_24[0xC];
};

extern "C" void ConvertPointListToWideLine__11CGtWideLineFP16CGtWideLinePointifPQ29GtMathPs26CGtV2dPQ29GtMathPs26CGtV2d(UnkStruct_CGtWideLinePoint *, int, float, CGtV2d *, CGtV2d *);
extern "C" void SetTextureAddressMode__12Gt2dRendererFQ212Gt2dRenderer23EGt2dRendererTexAddress(int);

extern "C" void _RenderCurveSection__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4df(
    const CGt2dObject::CGt2dObjectSpace & space, const void * data, CGtBezierSection * sec, CGtTexture * tex, const CGtV4d colour, float width)
{
    CGtV4d col = colour;
    const UnkStruct_RCS_data * d = (const UnkStruct_RCS_data *)data;
    CGtV2d scale2 = space.mSize * d->field_0;
    UnkStruct_CGtWideLinePoint pts[2];
    CGtV2d a[4];
    CGtV2d b[4];
    float scale = d->field_10;
    pts[0].field_0 = sec->pt[0];
    pts[1].field_0 = sec->pt[3];
    pts[0].field_8 = sec->pt[1] - sec->pt[0];
    pts[1].field_8 = sec->pt[3] - sec->pt[2];
    if (scale < 0.0f) {
        float t = scale * D_01EBE380.field_0;
        float k = 1.0f;
        float fr = 0.0f + t - k * (float)(int)(t / k);
        pts[0].field_20 = fr + sec->field_20;
        pts[1].field_20 = fr + sec->field_24;
    } else {
        float t = scale * D_01EBE380.field_0;
        float k = 1.0f;
        float fr = 0.0f + t - k * (float)(int)(t / k);
        pts[0].field_20 = 2.0f - (fr + sec->field_20);
        pts[1].field_20 = 2.0f - (fr + sec->field_24);
    }
    ConvertPointListToWideLine__11CGtWideLineFP16CGtWideLinePointifPQ29GtMathPs26CGtV2dPQ29GtMathPs26CGtV2d(pts, 2, width, a, b);
    CGtV2d t0 = a[0] * scale2;
    a[0] = t0 + space.mTopLeftPos;
    CGtV2d t1 = a[1] * scale2;
    CGtV2d u1 = t1 + space.mTopLeftPos;
    a[1] = u1;
    CGtV2d t2 = a[2] * scale2;
    CGtV2d u2 = t2 + space.mTopLeftPos;
    a[2] = u2;
    CGtV2d t3 = a[3] * scale2;
    CGtV2d u3 = t3 + space.mTopLeftPos;
    a[3] = u3;
    if (tex == 0) {
        Gt2dRenderer::RenderTriStripFlatUntex(col, CGtV2d(0.0f, 0.0f), 4, a);
    } else {
        SetTextureAddressMode__12Gt2dRendererFQ212Gt2dRenderer23EGt2dRendererTexAddress(1);
        Gt2dRenderer::SetTexture(tex);
        Gt2dRenderer::RenderTriStripFlatTex(col, CGtV2d(0.0f, 0.0f), 4, a, b);
    }
}
