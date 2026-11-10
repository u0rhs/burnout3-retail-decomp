// NONMATCHING: _Render__20CB3FlashText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 266 / ours 270 instructions, 144 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: v298: first full draft (lifter refused), 266/270, 144 in changed runs; logic decoded from retail: shadow(0,0,0,a*a*0.75) at size*3, two outline passes (0,0,0,a) at +/-off with x flipped, base pass, then flash: t<0 return; t<2: colour*(1,1,1,D_004E06DC*(1-t)) at +/-(t,0)*size; else 4 steps of colour 
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

// [L] N185: stands in for a missing GtMathPs2 inline -- operator *(WAxisType, WAxisType) ([C] API: B3O0PCH map, 0x50 bytes).
static inline WAxisType MulWW(WAxisType a, WAxisType b) { u_long128 r; asm("vmulw.w %0, %1, %2w" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV4d::operator+=(CGtV4d).
static inline void AddV4(CGtV4d &a, const CGtV4d b) { asm("vadd.xyzw %0, %0, %1" : "+j"(a.mData) : "j"(b.mData)); }

struct UnkStruct_00371BE0_font {
    unsigned char pad_0[4];
    CGtTexture *field_4;
};
struct UnkStruct_00371BE0_data {
    UnkStruct_00371BE0_font *field_0;
    unsigned char pad_4[0x8];
    float field_C;
    CGtV2d field_10;
};

extern "C" int _BuildBatchData__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);
extern const CGtV4d kVFlashColourScale;

#define RB (const CGtV2d *)CGt2dObject::mgu8RenderBatchData, (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0)

// 0x00371BE0
extern "C" void _Render__20CB3FlashText2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_00371BE0_data *d = (const UnkStruct_00371BE0_data *)data;
    int n = _BuildBatchData__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(space, data);
    if (n <= 0)
        return;
    {
        WAxisType a = space.mColour.W();
        CGtV4d shadow(0.0f, 0.0f, 0.0f, MulWW(a, a) * 0.75f);
        CGtV4d outline(0.0f, 0.0f, 0.0f, space.mColour.W());
        CGtV2d size = d->field_10 * space.mSize;
        CGtV2d soff = size * 3.0f;
        CGtV2d off = size * 1.0f;
        Gt2dRenderer::SetTexture(d->field_0->field_4);
        Gt2dRenderer::RenderTriStripFlatTex(shadow, soff, n, RB);
        for (int i = 0; i < 2; i++) {
            Gt2dRenderer::RenderTriStripFlatTex(outline, off, n, RB);
            Gt2dRenderer::RenderTriStripFlatTex(outline, -off, n, RB);
            off.marValues[0] = -off.marValues[0];
        }
        Gt2dRenderer::RenderTriStripFlatTex(space.mColour, CGtV2d(0.0f, 0.0f), n, RB);
        float t = d->field_C;
        if (t < 0.0f) {
            return;
        }
        if (t < 2.0f) {
            CGtV4d col = space.mColour * CGtV4d(1.0f, 1.0f, 1.0f, 0.8f * (1.0f - t));
            CGtV2d o = CGtV2d(t, 0.0f) * space.mSize;
            Gt2dRenderer::RenderTriStripFlatTex(col, o, n, RB);
            Gt2dRenderer::RenderTriStripFlatTex(col, -o, n, RB);
        } else {
            CGtV4d step = space.mColour * kVFlashColourScale;
            CGtV4d col = step;
            CGtV2d dstep = CGtV2d(0.0f, 0.25f * (t - 2.0f)) * space.mSize;
            CGtV2d base = CGtV2d(0.0f, 0.0f) * space.mSize;
            CGtV2d pos = dstep;
            for (int j = 0; j < 4; j++) {
                Gt2dRenderer::RenderTriStripFlatTex(col, base + pos, n, RB);
                Gt2dRenderer::RenderTriStripFlatTex(col, base - pos, n, RB);
                pos += dstep;
                AddV4(col, step);
            }
        }
    }
}
