// NONMATCHING: func_00381030 -- retail 428 / ours 453 instructions, 430 in changed runs
// fix2 (2026-11-01): shadow pass: func_00217E70 (Gt2dRenderer blend, matched definition takes an int) called with 1 before the 8 offset draws and 0 after, as retail 0x3815C0/0x3816A0 (the draft called it once with no argument: a0 = stale d+0x17) | Before: psweep: scoped #pragma inline_depth(3) [G] improves 581 -> 520
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)

using namespace GtMathPs2;

namespace Gt2dRenderer {
void RenderTriStripGouraudTex(const CGtV2d &, int, const CGtV2d *, const CGtV2d *, const CGtV4d *);
}
struct UnkStruct_00381030_d {   // [G] the object's data block
    const unsigned short *field_0;
    float field_4;
    CGtV2d field_8;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char field_13;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
};
struct UnkStruct_D_00665ED0 { CGt2dFont *field_0; };
extern UnkStruct_D_00665ED0 D_00665ED0;
extern float D_004E06D4, D_004E0868, D_004E068C, D_004E06CC, D_004E086C, D_004E0870;
extern CGtV2d D_004C9460[8];
extern "C" int func_003816E0(const CGt2dObject::CGt2dObjectSpace &, const UnkStruct_00381030_d *);
extern "C" void func_00217E70(int);   // [C] the matched definition (src/b3/_unclassified/func_00217E70.cpp): a Gt2dRenderer blend mode

// 0x00381030
extern "C" void func_00381030(const CGt2dObject::CGt2dObjectSpace &space, const UnkStruct_00381030_d *d)
{
    CGtV2d *base0 = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *base1 = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    CGtV2d scale;
    scale = CGtV2d(d->field_8.X() * space.mSize.X(), d->field_8.Y() * space.mSize.Y());
    CGtV4d sq;
    sq = space.mColour;
    float alpha = sq.f[3] * sq.f[3];
    CGt2dFont *font = D_00665ED0.field_0;
    CGtV4d col(0.0f, 0.0f, 0.0f, 0.0f);
    CGtV2d zero(0.0f, 0.0f);
    int n = func_003816E0(space, d);
    Gt2dRenderer::SetTexture(font->field_4);
    if (d->field_13 & 2) {
        col = CGtV4d(0.0f, 0.0f, 0.0f, 0.75f * alpha);
        CGtV2d off;
        off = CGtV2d(scale.X() * 2.5f, scale.Y() * 2.5f);
        Gt2dRenderer::RenderTriStripFlatTex(col, off, n, base0, base1);
    }
    if (d->field_13 & 1) {
        col = CGtV4d(col.f[0], col.f[1], col.f[2], alpha);
        CGtV2d off;
        off = CGtV2d(scale.X() * D_004E06CC, scale.Y() * D_004E06CC);
        for (int i = 0; i < 2; i++) {
            Gt2dRenderer::RenderTriStripFlatTex(col, off, n, base0, base1);
            CGtV2d neg;
            neg = CGtV2d(-off.X(), -off.Y());
            Gt2dRenderer::RenderTriStripFlatTex(col, neg, n, base0, base1);
            off.Set(-off.X(), off.Y());
        }
    }
    if (d->field_13 & 8) {
        Gt2dRenderer::RenderTriStripFlatTex(space.mColour, zero, n, base0, base1);
    } else {
        CGtV4d tint = space.mColour * D_004E06D4;
        CGtV4d cA(CGtV4d((float)d->field_10, (float)d->field_11, (float)d->field_12, 255.0f));
        CGtV4d cB(CGtV4d((float)d->field_14, (float)d->field_15, (float)d->field_16, 255.0f));
        CGtV4d a = cA * tint;
        CGtV4d b = cB * tint;
        CGtV4d cols[4];
        if (d->field_13 & 4) {
            float x0 = base0[2].X();
            float range = base0[n - 3].X() - x0;
            float k = D_004E0868 / range;
            float o = x0 - D_004E068C * range;
            CGtV2d *p = base0 + n + 2;
            CGtV2d *q = base1 + n + 2;
            do {
                p -= 6;
                q -= 6;
                for (int j = 0; j < 4; j++) {
                    float t = k * (p[j].X() - o);
                    cols[j] = a - (a - b) * t;
                }
                Gt2dRenderer::RenderTriStripGouraudTex(zero, 4, p, q, cols);
            } while (base0 < p);
        } else {
            float k = D_004E0868 / space.mSize.Y();
            float o = space.mTopLeftPos.Y() - D_004E068C * space.mSize.Y();
            CGtV2d *p = base0 + n + 2;
            CGtV2d *q = base1 + n + 2;
            do {
                p -= 6;
                q -= 6;
                float t0 = k * (p[0].Y() - o);
                float t1 = k * (p[2].Y() - o);
                cols[0] = a - (a - b) * t0;
                cols[1] = cols[0];
                cols[2] = a - (a - b) * t1;
                cols[3] = cols[2];
                Gt2dRenderer::RenderTriStripGouraudTex(zero, 4, p, q, cols);
            } while (base0 < p);
        }
    }
    if (d->field_17 != 0) {
        float w = D_004E086C * (float)d->field_17;
        CGtV4d sh(0.0f, 0.0f, 0.0f, space.mColour.f[3] * w);
        CGtV2d rs;
        rs = CGtV2d(d->field_8.X() * space.mSize.X() * D_004E0870, d->field_8.Y() * space.mSize.Y() * D_004E0870);
        float fx = d->field_4 * rs.X();
        float fy = rs.Y();
        func_00217E70(1);                       // [C] retail 0x3815C0 (a0 = 1) / 0x3816A0 (a0 = 0)
        for (int i = 0; i < 8; i++) {
            CGtV2d off;
            off = CGtV2d(D_004C9460[i].X() * fx, D_004C9460[i].Y() * fy);
            Gt2dRenderer::RenderTriStripFlatTex(sh, off, n, base0, base1);
        }
        func_00217E70(0);
    }
}

#pragma pop
