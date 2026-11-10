// NONMATCHING: func_003B0160 -- retail 450 / ours 464 instructions, 467 in changed runs
// fix2 (2026-11-01): texture coordinates in retail's order (0,0) (1,0) (0,1) (1,1) (the draft had (0,1) (0,0) (1,1) (1,0): both layers drawn rotated) [C] retail 0x3B01C8..0x3B0200; GtMathPs2Quat.h included (CGtV4d::SetW(WAxisType) is defined there; the call linked a missing out-of-line symbol) | Before: psweep: scoped #pragma inline_depth(4) [G] improves 715 -> 482
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



// func_003B0160 -- hand-written (son7). A 2D object _Render callback (space, data) drawing a rotated 4-vertex strip
// twice (a glow layer, then the icon) and an optional 1-2 digit number on top. Sibling of the rotating image's
// _Render (B3HeadingComponent_0031A300.cpp) [L]. Field names are placeholders and every type is [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GtMathPs2Quat.h"   // fix2: CGtV4d::SetW(WAxisType) is defined there (without it the call links a missing out-of-line symbol)
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(4)

using namespace GtMathPs2;

extern CGtTexture *D_01EA4470[];
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
extern float D_004E06F0;
extern float D_004E06AC;
extern float D_004E07F8;
extern float D_004E07FC;
extern float D_004E0800;
extern float D_004E06DC;

struct UnkStruct_003B0160_data {
    unsigned char pad_0[4];
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    signed char field_14;
    signed char field_15;
    signed char field_16;
};

extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" void func_001D6AD0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *, const CGtV2d *, int);

// [G] one rotated layer: scale s, fade (1 - field_8) on the colour's w
static inline void func_003B0160_inl1(const CGt2dObject::CGt2dObjectSpace &space, const UnkStruct_003B0160_data *d,
                                      const CGtMatrix2x3 &m, float s, int tex)
{
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = pos + 4;
    CGtV2d half = space.mSize * 0.5f;
    CGtV2d centre = space.mTopLeftPos + half;
    CGtV2d e = half * (s * d->field_C);
    CGtV4d colour = space.mColour;
    colour.SetW(colour.W() * (1.0f - d->field_8));
    pos[0].Set(-e.X(), -e.Y());
    pos[1].Set(e.X(), -e.Y());
    pos[2].Set(-e.X(), e.Y());
    pos[3].Set(e.X(), e.Y());
    uv[0].Set(0.0f, 0.0f);                  // [C] retail 0x3B01C8..0x3B0200: batch +0x20..+0x3C = (0,0) (1,0) (0,1) (1,1)
    uv[1].Set(1.0f, 0.0f);
    uv[2].Set(0.0f, 1.0f);
    uv[3].Set(1.0f, 1.0f);
    GtMathPs2::TransformPoints(m, pos, pos, 4);
    Gt2dRenderer::SetTexture(D_01EA4470[tex]);
    Gt2dRenderer::RenderTriStripFlatTex(colour, centre, 4, pos, uv);
}

// 0x003B0160
extern "C" void func_003B0160(const CGt2dObject::CGt2dObjectSpace &space, const UnkStruct_003B0160_data *d)
{
    CGtMatrix2x3 m;
    m = GtMathPs2::CreateRotationMatrix2x3(D_004E06F0 * -d->field_10);
    m.mPos = CGtV2d(0.0f, 0.0f);
    float s;
    if (d->field_15 != -0x70 && d->field_14 != '1' && d->field_14 != '4') {
        if (d->field_4 >= 0.0f) s = d->field_8 * D_004E07F8 + D_004E06AC + 0.0f;
        else s = 0.5f;
        func_003B0160_inl1(space, d, m, s, d->field_15);
    }
    if (d->field_4 >= 0.0f) s = d->field_4 * D_004E0800 + D_004E07FC + 0.0f;
    else s = D_004E06DC;
    func_003B0160_inl1(space, d, m, s, d->field_14);
    if (d->field_16 != -1 && d->field_14 != '5') {
        unsigned short text[4];
        if (d->field_16 < 10) PrintInt__10CGtUnicodeFPUsii(text, d->field_16, 1, 0);
        else PrintInt__10CGtUnicodeFPUsii(text, d->field_16, 2, 0);
        D_00665ED0.pFont->GetStringWidth(text);
        float a = (d->field_C - 0.5f) * 2.0f;
        a = a > 0.0f ? a : 0.0f;
        a = a < 1.0f ? a : 1.0f;
        CGtV4d colour = space.mColour * a;
        colour.SetW(colour.W() * a);
        CGtV2d anchor(0.5f, 0.5f);
        CGtV2d shadow(D_004E06DC, D_004E06DC);
        CGt2dObject o;
        func_001D6AD0(&o, space.mTopLeftPos, anchor, 17.0f, colour, D_00665ED0.pFont, text, &shadow, 2);
        CGtV2d half = space.mSize * 0.5f;
        CGtV2d sz = o.mObjectSpace.mSize * s;
        CGtV2d c = space.mTopLeftPos + half;
        CGt2dObject::CGt2dObjectSpace sp = o.mObjectSpace;
        sp.mTopLeftPos = c - sz * 0.5f;
        sp.mSize = sz;
        o.Render(sp);
    }
}

#pragma pop
