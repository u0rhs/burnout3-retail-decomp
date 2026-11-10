// NONMATCHING: func_00381AB0 -- retail 465 / ours 444 instructions, 560 in changed runs
// fix2 (2026-11-01): GtMathPs2Quat.h included: CGtV4d::SetW(WAxisType) is defined there (without it the call linked a missing out-of-line symbol) | Before: son7 first archive: text _Render callback, sibling of func_00382200. flags 2/1/8/4 + outline table loop. retail 465 vs ours ~466 instrs but ~565 in changed runs; frame 0x2F0 vs 0x3F0 (gradient quad temporaries; lerp via component math differs from retail's vaddabc/vmsubabc/vmaddbc); gradient axis and vertex order are [G]
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// func_00381AB0 -- hand-written (son7). _Render callback (space, data) of a text object: func_00382200 fills the batch
// (positions at mgu8RenderBatchData, UVs at +0xFE0) and returns the sprite count; then optional drop shadow (flag 2),
// 4-way outline (flag 1), plain or gradient fill (flag 8 / flag 4), and a thick outline (byte +0x17). Sibling of
// func_00382200 [L]. Field names are placeholders and every type is [G]; the gradient axis choice is [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GtMathPs2Quat.h"   // fix2: CGtV4d::SetW(WAxisType) is defined there (without it the call links a missing out-of-line symbol)

using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
extern float D_004E06D4;
extern float D_004E06CC;
extern float D_004E0868;
extern float D_004E068C;
extern float D_004E086C;
extern float D_004E0870;
extern const CGtV2d D_004C9460[8];

struct UnkStruct_00381AB0_data {
    unsigned char pad_0[4];
    float field_4;
    float field_8;
    float field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
};

extern "C" int func_00382200(const CGt2dObject::CGt2dObjectSpace &, const UnkStruct_00381AB0_data *);
extern "C" void func_00217E70(int);
extern "C" void RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d(const CGtV2d &, int, const CGtV2d *, const CGtV2d *, const CGtV4d *);
namespace Gt2dRenderer {
void RenderSpritesTex(CGtV4d, const CGtV2d &, int, const CGtV2d *, const CGtV2d *);
}

static inline CGtV4d func_00381AB0_lerp(const CGtV4d &a, const CGtV4d &b, float t)
{
    CGtV4d dd = (b - a) * t;
    return CGtV4d(a.X() + dd.X(), a.Y() + dd.Y(), a.Z() + dd.Z(), a.W() + dd.W());
}

// 0x00381AB0
extern "C" void func_00381AB0(const CGt2dObject::CGt2dObjectSpace &space, const UnkStruct_00381AB0_data *d)
{
    CGt2dFont *font = D_00665ED0.pFont;
    CGtV2d size(d->field_8 * space.mSize.X(), d->field_C * space.mSize.Y());
    CGtV4d c = space.mColour;
    c.SetW(c.W() * c.W());
    float alpha = c.W();
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    CGtV2d zero(0.0f, 0.0f);
    int n = func_00382200(space, d);
    Gt2dRenderer::SetTexture(font->field_4);
    if (d->field_13 & 2) {
        CGtV4d s(0.0f, 0.0f, 0.0f, alpha * 0.75f);
        Gt2dRenderer::RenderSpritesTex(s, size * 2.5f, n, pos, uv);
    }
    if (d->field_13 & 1) {
        CGtV4d s(0.0f, 0.0f, 0.0f, alpha);
        CGtV2d off(size.X() * D_004E06CC, size.Y() * D_004E06CC);
        for (int i = 0; i < 2; i++) {
            Gt2dRenderer::RenderSpritesTex(s, off, n, pos, uv);
            Gt2dRenderer::RenderSpritesTex(s, CGtV2d(-off.X(), -off.Y()), n, pos, uv);
            off.Set(-off.X(), off.Y());
        }
    }
    if (!(d->field_13 & 8)) {
        CGtV4d k = space.mColour * D_004E06D4;
        CGtV4d ca = CGtV4d((float)d->field_10, (float)d->field_11, (float)d->field_12, 255.0f) * k;
        CGtV4d cb = CGtV4d((float)d->field_14, (float)d->field_15, (float)d->field_16, 255.0f) * k;
        bool horizontal = (d->field_13 & 4) != 0;
        float lo, inv;
        if (horizontal) {
            float w = pos[2 * n - 1].X() - pos[0].X();
            inv = D_004E0868 / w;
            lo = (pos[0].X() + 0.0f) - D_004E068C * w;
        } else {
            inv = D_004E0868 / space.mSize.Y();
            lo = (space.mTopLeftPos.Y() + 0.0f) - D_004E068C * space.mSize.Y();
        }
        for (int i = n - 1; i >= 0; i--) {
            const CGtV2d &p0 = pos[2 * i];
            const CGtV2d &p1 = pos[2 * i + 1];
            const CGtV2d &u0 = uv[2 * i];
            const CGtV2d &u1 = uv[2 * i + 1];
            CGtV2d qp[4], qu[4];
            CGtV4d qc[4];
            qp[0] = p0;
            qp[1] = CGtV2d(p0.X(), p1.Y());
            qp[2] = CGtV2d(p1.X(), p0.Y());
            qp[3] = p1;
            qu[0] = u0;
            qu[1] = CGtV2d(u0.X(), u1.Y());
            qu[2] = CGtV2d(u1.X(), u0.Y());
            qu[3] = u1;
            for (int j = 0; j < 4; j++) {
                float v = horizontal ? qp[j].X() : qp[j].Y();
                qc[j] = func_00381AB0_lerp(ca, cb, inv * (v - lo));
            }
            RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d(zero, 4, qp, qu, qc);
        }
    } else {
        Gt2dRenderer::RenderSpritesTex(space.mColour, zero, n, pos, uv);
    }
    if (d->field_17 != 0) {
        CGtV4d oc = space.mColour * (D_004E086C * (float)d->field_17);
        CGtV2d sz(size.X() * D_004E0870, size.Y() * D_004E0870);
        float sx = d->field_4 * sz.X();
        func_00217E70(1);
        for (int i = 0; i < 8; i++) {
            Gt2dRenderer::RenderSpritesTex(oc, CGtV2d(D_004C9460[i].X() * sx, D_004C9460[i].Y() * sz.Y()), n, pos, uv);
        }
        func_00217E70(0);
    }
}
