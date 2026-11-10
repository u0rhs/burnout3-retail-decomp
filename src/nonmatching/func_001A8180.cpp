// NONMATCHING: func_001A8180 -- retail 195 / ours 201 instructions, 218 in changed runs
// ghvu11 first draft: logic believed right (two RenderSpritesTex calls; n>1 second quad; alpha col.W()*b via vmulx.w + vmulw.w SetA stand-in; 0.6 midpoint and 5-4b scale of the second quad); left: frame slots (retail colour 0xE0, pos[4] 0xB0, uv[4] 0x80, CGtV2d operator temps 0x100-0x18F with ld/sd copies), s-registers (retail keeps only &pos[1] / &uv[1] in s1/s0), the 1/6 lit4 read twice
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001A8180 -- hand-written from the Ghidra draft (ghvu11). Unnamed in every table: placeholder, C linkage.
// A Gt2d render helper: a0 = the object space (CGt2dObject::CGt2dObjectSpace [L]: +8 size, +0xC, +0x10 colour), a1 = a
// count, f12/f13 floats. Every type is [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using namespace GtMathPs2;

struct UnkStruct_D_004B7800 { CGtV4d field_0; };
extern UnkStruct_D_004B7800 D_004B7800;
// [L] N185: SetA from a w lane (vmulw.w d, $vf0, s w) stand-in
static inline void func_001A8180_inl1(CGtV4d &r, WAxisType w) { asm("vmulw.w %0, $vf0, %1w" : "+j"(r.mData) : "j"(*(const u_long128 *)&w.lVector)); }

// 0x001A8180
extern "C" void func_001A8180(const CGt2dObject::CGt2dObjectSpace *space, int n, float a, float b)
{
    CGtV2d pos[4];
    CGtV2d uv[4];
    float w = a * space->mSize.marValues[0];
    int cnt = 1;
    if (n > 1) {
        cnt++;
        pos[3].marValues[0] = w;
        pos[3].marValues[1] = space->mSize.marValues[1];
        pos[2].marValues[1] = 0.0f;
        uv[2].marValues[0] = 0.0f;
        uv[3].marValues[0] = 1.0f;
        w = 0.0f + w - 0.16666667f * space->mSize.marValues[0];
        pos[2].marValues[0] = w;
        uv[2].marValues[1] = 0.0f + -0.244140625f + 0.25f * (float)n;
        uv[3].marValues[1] = 0.11328125f + uv[2].marValues[1];
        a -= 0.16666667f;
    }
    pos[0].marValues[0] = 0.0f;
    pos[0].marValues[1] = 0.0f;
    pos[1].marValues[0] = w;
    pos[1].marValues[1] = space->mSize.marValues[1];
    uv[0].marValues[0] = 0.0f;
    uv[0].marValues[1] = 0.130859375f;
    uv[1].marValues[0] = 6.0f * a;
    uv[1].marValues[1] = 0.244140625f;
    CGtV4d col = D_004B7800.field_0 * space->mColour;
    Gt2dRenderer::RenderSpritesTex(col, space->mTopLeftPos, cnt, pos, uv);
    if (b > 0.0f) {
        func_001A8180_inl1(col, col.W() * b);
        float k = 0.0f + 5.0f - 4.0f * b;
        uv[0].marValues[0] = uv[2].marValues[0];
        uv[1].marValues[0] = uv[3].marValues[0];
        uv[3].marValues[1] += 0.125f;
        uv[1].marValues[1] = uv[3].marValues[1];
        uv[2].marValues[1] += 0.125f;
        uv[0].marValues[1] = uv[2].marValues[1];
        CGtV2d d = pos[3] - pos[2];
        CGtV2d h = d * 0.6f;
        CGtV2d c = pos[2] + h;
        CGtV2d e1 = pos[2] - c;
        CGtV2d e2 = pos[3] - c;
        pos[0] = c + e1 * k;
        pos[1] = c + e2 * k;
        Gt2dRenderer::RenderSpritesTex(col, space->mTopLeftPos, 2, pos, uv);
    }
}
