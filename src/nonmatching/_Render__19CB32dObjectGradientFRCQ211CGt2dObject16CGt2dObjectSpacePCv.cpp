// NONMATCHING: _Render__19CB32dObjectGradientFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 294 / ours 281 instructions, 227 in changed runs
// draftAN fork B C-first: byte colours A/B (data +0/+4) / 255 x object colour, centre band w = data.+8 x size.x flat A (RenderTriStripFlatUntex), the two (size.x - w)/2 sides as RenderTriStripGouraudUntex gradients B (outside) -> A (band); 281/294, calls identical, float add count equal
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with the archived Prepare's data block; every vertex/colour stack slot of the three calls traced, the unsigned byte conversions, the 1/255 variable

// CB32dObjectGradient::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAN fork B (C-first draft). 0x352AB0, 0x498.
// [C] name: the mangled symbol in retail's tables (E maps: B32dObjectGradient.cpp). Data block as the archived Prepare (0x352F50):
// +0 / +4 two colours as bytes (lane x 255), +8 a float.
// What it draws [L]: the object as three side-by-side quads: a middle band of width w = data.+8 x size.x in colour A (flat), and the
// two outer parts ((size.x - w) / 2 each) as gradients from colour B at the outside to colour A at the band. Both colours are the
// bytes / 255 times the object colour. Types and field meanings [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00352AB0_data {            // the archived Prepare's data block
    unsigned char field_0[4];               // colour A (centre), lane x 255
    unsigned char field_4[4];               // colour B (outer edges), lane x 255
    float field_8;                          // [G] centre band width / object width
};
extern float D_004E06D4;                    // [C] 1/255 (0x3B808081); a gp-relative variable
class CB32dObjectGradient : public CGt2dObject {
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace &, const void *);
};

// 0x00352AB0
void CB32dObjectGradient::_Render(const CGt2dObject::CGt2dObjectSpace & space, const void * lpData)
{
    const UnkStruct_00352AB0_data * data = (const UnkStruct_00352AB0_data *)lpData;
    CGtV4d cA((float)data->field_0[0], (float)data->field_0[1], (float)data->field_0[2], (float)data->field_0[3]);
    CGtV4d cB((float)data->field_4[0], (float)data->field_4[1], (float)data->field_4[2], (float)data->field_4[3]);
    float w = data->field_8 * space.mSize.X();
    CGtV2d lMid(w, space.mSize.Y());
    CGtV2d lSide((space.mSize.X() - w) / 2.0f, space.mSize.Y());
    cA = cA * (space.mColour * D_004E06D4);
    cB = cB * (space.mColour * D_004E06D4);
    CGtV4d col[4];
    CGtV2d pts[4];

    // left part: B at the outer edge -> A at the band
    col[0] = cB;
    col[1] = cB;
    col[2] = cA;
    col[3] = cA;
    pts[0].Set(space.mTopLeftPos.X(), space.mTopLeftPos.Y());
    CGtV2d t = space.mTopLeftPos + lSide;
    pts[1].Set(pts[0].X(), t.Y());
    pts[3] = t;
    pts[2].Set(t.X(), pts[0].Y());
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, 0.0f), 4, pts, col);

    // centre band, flat A ([C] retail sets all four colours to B first; the flat call does not read them)
    col[0] = cB;
    col[1] = cB;
    col[2] = cB;
    col[3] = cB;
    pts[0] = space.mTopLeftPos + CGtV2d(lSide.X(), 0.0f);
    CGtV2d u = pts[0] + lMid;
    pts[1].Set(pts[0].X(), u.Y());
    pts[3] = u;
    pts[2].Set(u.X(), pts[0].Y());
    Gt2dRenderer::RenderTriStripFlatUntex(cA, CGtV2d(0.0f, 0.0f), 4, pts);

    // right part: A at the band -> B at the outer edge
    col[0] = cA;
    col[1] = cA;
    col[2] = cB;
    col[3] = cB;
    pts[0] = space.mTopLeftPos + CGtV2d(lSide.X() + lMid.X(), 0.0f);
    CGtV2d v = pts[0] + lSide;
    pts[1].Set(pts[0].X(), v.Y());
    pts[3] = v;
    pts[2].Set(v.X(), pts[0].Y());
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, 0.0f), 4, pts, col);
}
