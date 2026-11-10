// NONMATCHING: _Render__23CB3SelectionBar2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 196 / ours 190 instructions, 217 in changed runs
// draftAN fork B C-first: SetTexture(D_01EA46B0[0]), colours = object colour x5 (+ [4]/[5] alpha 0), kSelectionBarEndUVs/LineUVs into 6 UVs, two 6-vertex RenderTriStripGouraudTex strips (left part to x + data.+8 * s, right part from data.+0xC * s further to the right edge); 190/196, calls identical, non-stack stores identical (39/39, base-relative)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every batch-buffer store (6 colours, 6 UVs, 2 x 6 vertices) traced to its source lane, both call argument lists

// CB3SelectionBar2dObject::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAN fork B (C-first draft). 0x3720F0,
// 0x310. [C] name: the mangled symbol in retail's tables; kSelectionBarEndSize / LineUVs / EndUVs: DNAT rows
// (B3SelectionBar2dObject.cpp, 8 / 0x10 / 0x10 bytes). Data block as the archived Prepare func_00372400 (+0 1/size, +8 / +0xC floats).
// What it draws [L]: two 6-vertex RenderTriStripGouraudTex strips with texture D_01EA46B0[0] (the menu texture table): colours =
// the object colour x5, the last two with alpha 0 (a fade); the first strip ends at x + data.+8 * scale, the second starts
// data.+0xC * scale further right and runs to the object's right edge. Types and field meanings [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003720F0_data {            // the object's data block (func_00372400 = Prepare: 1 / size, then two floats)
    CGtV2d field_0;
    float field_8;                          // [G] gap start (x scale units)
    float field_C;                          // [G] gap width
};
extern CGtTexture * D_01EA46B0[];           // the menu texture table (B3HeadingComponent sources: [0x38])
extern const CGtV2d kSelectionBarEndSize;   // [C] DNAT; retail lui/%lo
extern const CGtV2d kSelectionBarLineUVs[2];
extern const CGtV2d kSelectionBarEndUVs[2];

class CB3SelectionBar2dObject : public CGt2dObject {
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace &, const void *);
};

// 0x003720F0
void CB3SelectionBar2dObject::_Render(const CGt2dObject::CGt2dObjectSpace & space, const void * lpData)
{
    const UnkStruct_003720F0_data * data = (const UnkStruct_003720F0_data *)lpData;
    CGtV2d lOffset(0.0f, 0.0f);
    CGtV2d s = data->field_0 * space.mSize;
    CGtV2d e = s * kSelectionBarEndSize;
    float a = data->field_8 * s.X();
    float b = data->field_C * s.X();
    Gt2dRenderer::SetTexture(D_01EA46B0[0]);

    CGtV4d * col = (CGtV4d *)CGt2dObject::mgu8RenderBatchData;
    for (int i = 0; i < 5; i++)
        col[i] = space.mColour;
    col[4].SetA(0.0f);
    col[5] = col[4];
    CGtV2d * v = (CGtV2d *)(col + 6);
    CGtV2d * uv = v + 6;
    uv[0].Set(kSelectionBarEndUVs[0].X(), kSelectionBarEndUVs[0].Y());
    uv[1].Set(kSelectionBarEndUVs[0].X(), kSelectionBarEndUVs[1].Y());
    uv[2].Set(kSelectionBarEndUVs[1].X(), kSelectionBarEndUVs[0].Y());
    uv[3].Set(kSelectionBarEndUVs[1].X(), kSelectionBarEndUVs[1].Y());
    uv[4].Set(kSelectionBarLineUVs[1].X(), kSelectionBarLineUVs[0].Y());
    uv[5].Set(kSelectionBarLineUVs[1].X(), kSelectionBarLineUVs[1].Y());

    // first strip: from the left edge to x + a
    CGtV2d p(space.mTopLeftPos.X() + a, space.mTopLeftPos.Y() + space.mSize.Y());
    CGtV2d q = p - e;
    v[0].Set(p.X(), space.mTopLeftPos.Y());
    v[1].Set(p.X(), p.Y());
    v[2].Set(q.X(), q.Y());
    v[3].Set(q.X(), p.Y());
    v[4].Set(space.mTopLeftPos.X(), space.mTopLeftPos.Y());
    v[5].Set(space.mTopLeftPos.X(), p.Y());
    Gt2dRenderer::RenderTriStripGouraudTex(lOffset, 6, v, uv, col);

    // second strip: b further right, to the right edge
    CGtV2d d(b, 0.0f);
    v[0] = v[0] + d;
    v[1] = v[1] + d;
    CGtV2d r = v[0] + e;
    v[2].Set(r.X(), v[0].Y());
    v[3].Set(r.X(), r.Y());
    CGtV2d t = space.mTopLeftPos + space.mSize;
    v[4].Set(t.X(), v[0].Y());
    v[5].Set(t.X(), t.Y());
    Gt2dRenderer::RenderTriStripGouraudTex(lOffset, 6, v, uv, col);
}
