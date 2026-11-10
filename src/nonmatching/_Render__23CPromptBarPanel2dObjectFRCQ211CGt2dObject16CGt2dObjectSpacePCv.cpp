// NONMATCHING: _Render__23CPromptBarPanel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 219 / ours 219 instructions, 65 in changed runs
// v291: frame 0x1C0 and every slot right; 219/219; everything from the first RenderSpritesTex on is exact. Left (65): prologue scheduling before SetTexture -- retail materialises 32.0 (v0) before 1.0 (v1) and loads the space/data inputs + colour lqc2s earlier, mgr base in a2 (ours v1). Keys found: colour decls fill/middle/outer order (VU regs), colour stores after pos[5].Set, pos[0].Set(X(),Y()-d.Y()) (drops a d.y reload), a+(b-a)*0.5f midpoint inline gives retail's depth-ordered temp slots. Tried: c/d/br/offset order, CGtV2d(0,1) forms, named 32.0, colour block positions, const-ref data.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

struct UnkStruct_D_01EA46C0 {
    CGtTexture * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing (N51)
};
extern UnkStruct_D_01EA46C0 D_01EA46C0;
extern const CGtV2d D_004CA940[2];  // [G] the first sprite's UV pair
struct UnkStruct_D_01EA4790 {
    CGtV2d uv[2];               // [G] the second sprite's UV pair
};
extern UnkStruct_D_01EA4790 D_01EA4790;

class CPromptBarPanel2dObject : public CGt2dObject {
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace &, const void *);
};

// [G] inlined helper (placeholder name): the point half way from a to b
static inline CGtV2d func_003D7B40_inl1(const CGtV2d &a, const CGtV2d &b)
{
    return a + (b - a) * 0.5f;
}

// 0x003D7B40
void CPromptBarPanel2dObject::_Render(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    CB3MenuPageManager *const mgr = &D_01E90240;
    CGtV4d *colours = (CGtV4d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *pos = (CGtV2d *)(colours + 6);
    CGtV2d *quad = pos + 6;

    CGtV2d scale = *(const CGtV2d *)data * space.mSize;
    CGtV2d c = scale * CGtV2d(0.0f, 1.0f);
    CGtV2d d = scale * 32.0f;
    CGtV2d offset(0.0f, 0.0f);
    CGtV2d e = space.mTopLeftPos + c;
    CGtV2d br = space.mTopLeftPos + space.mSize;
    quad[0] = e;
    quad[1] = br;
    CGtV4d fill = mgr->field_100 * space.mColour;
    CGtV4d middle = mgr->field_120 * space.mColour;
    CGtV4d outer = mgr->field_130 * space.mColour;
    Gt2dRenderer::SetTexture(D_01EA46C0.field_0);
    Gt2dRenderer::RenderSpritesTex(fill, offset, 1, quad, D_004CA940);

    pos[0] = space.mTopLeftPos - c;
    pos[1] = space.mTopLeftPos + c;
    pos[4].Set(quad[1].marValues[0] - d.marValues[0], pos[0].marValues[1]);
    pos[5].Set(quad[1].marValues[0] - d.marValues[0], pos[1].marValues[1]);
    colours[0] = outer;
    colours[1] = outer;
    colours[2] = middle;
    colours[3] = middle;
    colours[4] = outer;
    colours[5] = outer;
    pos[2] = func_003D7B40_inl1(pos[0], pos[4]);
    pos[3] = func_003D7B40_inl1(pos[1], pos[5]);
    Gt2dRenderer::RenderTriStripGouraudUntex(offset, 6, pos, colours);

    pos[0].Set(pos[5].X(), pos[1].Y() - d.Y());
    pos[1] = pos[0] + d;
    Gt2dRenderer::RenderSpritesTex(outer, offset, 1, pos, D_01EA4790.uv);
}
