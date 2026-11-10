// NONMATCHING: func_00439620 -- retail 433 / ours 412 instructions, 449 in changed runs
// fix2 (2026-11-01): texture coordinates 0.93359375 (0x3F6F) and 0.671875 (0x3F2C) as retail 0x439934/0x439978; the draft had 0x3F6E / 0x3F2E | Before: first archive: logic/control flow/constants/calls right; prologue + first sprite block match; left: float scheduling in blocks 2-4 (D_004E11BC load order), final fade colour (vmulx.w/vmulw.w VU0 on colour w lane written scalar), V2d temp-copy register allocation; 412 vs 433
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

struct UnkStruct_00439620_d {
    CGtTexture *field_0;
    const unsigned short *field_4;
    const unsigned short *field_8;
    const unsigned short *field_C;
    float field_10;
};
struct UnkStruct_D_00665ED0 { CGt2dFont *field_0; };
extern UnkStruct_D_00665ED0 D_00665ED0;
extern "C" void func_004392D0(const CGtV4d colour, const CGtV2d &origin, const CGtV2d &size, const unsigned short *s, const CGt2dFont *font, float maxW);

extern float D_004E0F5C, D_004E1194, D_004E1198, D_004E119C, D_004E11A0, D_004E11A4, D_004E11A8, D_004E11AC, D_004E11B0, D_004E11B4, D_004E11B8, D_004E11BC, D_004E11C0, D_004E11C4, D_004E11C8, D_004E11CC, D_004E11D0;
// 0x00439620
extern "C" void func_00439620(const CGt2dObject::CGt2dObjectSpace &space, const UnkStruct_00439620_d *d)
{
    float t = d->field_10;
    CGtV2d *base0 = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *base1 = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    if (t <= 0.0f) {
        return;
    }
    CGtV2d *c = base0;
    CGtV2d *uv = base1;
    float A = 1.0f;
    float B = 1.0f;
    float C = 1.0f;
    float D = 1.0f;
    if (t < 1.25f) {
        if (t > 1.0f) {
            A = 4.0f * (t - 1.0f);
        } else {
            A = 0.0f;
            if (t > 0.75f) {
                float u = 4.0f * (t - 0.75f);
                C = 0.0f + D_004E1198 * u + D_004E1194 * (u * u);
            } else {
                C = 0.0f;
                if (t < 0.375f) {
                    if (t < D_004E0F5C) {
                        float u = D_004E119C * t;
                        D = 0.0f + D_004E11A0 * u + D_004E11A4 * (u * u);
                    }
                    B = D_004E11A8 * t;
                }
            }
        }
    }
    CGtV2d P;
    P = CGtV2d(space.mSize.X() * D_004E11AC, space.mSize.Y() * 0.5f);
    // fix3 (port mac5, 2026-11-08): retail keeps the start point (sp+0x198/0x19C) for the logo, its text and the tab's
    // offset, and advances only a copy ($f8) along the bar -- the draft centred the logo on the advanced point, so in
    // races the EA TRAX panel drew the logo at the bar's right end [C retail 0x4398EC, 0x439984, 0x439A84; the
    // original's panel: Burn3 capture fri1-perf1 poll 7500, and EXPLORE_RETAIL=439620 in the port]
    const CGtV2d P0 = P;
    float w1 = D_004E11B0 * C * space.mSize.X();
    if (w1 > 0.0f) {
        float lim = D_004E11B4 * space.mSize.X();
        if (lim < w1) {
            uv[0].Set(0.6796875f, 0.015625f);
            uv[1].Set(0.78125f, 0.984375f);
            c[0].Set(P.X(), 0.0f);
            c[1].Set(P.X() + (w1 - lim), space.mSize.Y());
            P.Set(P.X() + (w1 - lim), P.Y());
            c += 2;
            uv += 2;
        } else {
            lim = w1;
        }
        c[0].Set(P.X(), 0.0f);
        uv[0].Set(0.78125f, 0.015625f);
        c[1].Set(P.X() + lim, space.mSize.Y());
        P.Set(P.X() + lim, P.Y());   // fix3: [C] retail 0x4397C4 add.s $f8, $f8, $f6
        uv[1].Set(0.83203125f, 0.984375f);
        c += 2;
        uv += 2;
    }
    if (B > 0.5f) {
        float x0 = GtMath::Max(P.X(), P0.X() + D_004E11B8 * ((B * B - 0.125f) * space.mSize.X()));   // fix3: [C] 0x4398EC
        c[0].Set(x0, 0.0f);
        uv[0].Set(0.83203125f, 0.015625f);
        c[1].Set(x0 + D_004E11BC * space.mSize.X(), space.mSize.Y());
        uv[1].Set(0.93359375f, 0.984375f);   // fix2: [C] retail 0x439934 lui 0x3F6F (the draft had 0x3F6E)
        c += 2;
        uv += 2;
    }
    if (B > 0.0f) {
        CGtV2d h;
        h = CGtV2d(space.mSize.X() * D_004E11AC, space.mSize.Y() * 0.5f);
        CGtV2d hs;
        hs = h * B;
        CGtV2d lo(P0.X() - hs.X(), P0.Y() - hs.Y());   // fix3
        CGtV2d hi(P0.X() + hs.X(), P0.Y() + hs.Y());
        c[0] = lo;
        uv[0].Set(0.4296875f, 0.015625f);
        c[1].Set(P0.X(), hi.Y());
        uv[1].Set(0.671875f, 0.984375f);     // fix2: [C] retail 0x439978 lui 0x3F2C (the draft had 0x3F2E)
        c[2].Set(P0.X(), lo.Y());
        uv[2].Set(0.671875f, 0.984375f);
        c[3] = hi;
        uv[3].Set(0.4296875f, 0.015625f);
        c += 4;
        uv += 4;
    }
    if (D > 0.0f) {
        CGtV2d h;
        h = CGtV2d(space.mSize.X() * D_004E11C0, space.mSize.Y() * D_004E11C4);
        CGtV2d hs;
        hs = h * D;
        CGtV2d lo(P0.X() - hs.X(), P0.Y() - hs.Y());   // fix3
        CGtV2d hi(P0.X() + hs.X(), P0.Y() + hs.Y());
        c[0] = lo;
        uv[0].Set(0.0078125f, 0.109375f);
        c[1] = hi;
        uv[1].Set(0.3984375f, 0.890625f);
        c += 2;
        uv += 2;
    }
    Gt2dRenderer::SetTexture(d->field_0);
    Gt2dRenderer::RenderSpritesTex(space.mColour, space.mTopLeftPos, (c - base0) / 2, base0, base1);
    if (A > 0.0f) {
        CGtV4d col = space.mColour;
        float aw = col.f[3] * A;
        CGtV4d dark(0.0f, 0.0f, 0.0f, aw);
        CGt2dFont *font = D_00665ED0.field_0;
        float fx = D_004E11C8 * space.mSize.X();
        float maxW = D_004E11CC * space.mSize.X();
        float fy = space.mSize.Y();
        Gt2dRenderer::SetTexture(font->field_4);
        CGtV2d sz(fx * 0.34375f, fy * 0.34375f);
        CGtV2d off(space.mSize.X() * D_004E11D0, space.mSize.Y() * 0.078125f);
        CGtV2d pos(space.mTopLeftPos.X() + off.X(), space.mTopLeftPos.Y() + off.Y());
        func_004392D0(dark, pos, sz, d->field_4, font, maxW);
        sz = CGtV2d(fx * 0.28125f, fy * 0.28125f);
        pos.Set(pos.X(), pos.Y() + 0.296875f * space.mSize.Y());
        func_004392D0(dark, pos, sz, d->field_8, font, maxW);
        pos.Set(pos.X(), pos.Y() + 0.234375f * space.mSize.Y());
        func_004392D0(dark, pos, sz, d->field_C, font, maxW);
    }
}
