// NONMATCHING: func_0045B510 -- retail 254 / ours 249 instructions, 42 in changed runs
// v297: Gt2d _Render callback (CGt2dObjectSpace&, flags*): horizontal 3-slice 10-vertex strip -> Gt2dRenderer::RenderTriStripGouraudTex. Frame 0x230 exact, colour block (g = &D_01E90240 const pointer, g->field_150/120 * s.mColour into out-of-line CGtV4d::operator= func_001D4E80), out-of-line CGtV2d::operator= for pos[1], UV block (inline helper per table D_004D3698/D_004D3660, 6 CGtV2d each) and texture/render tail all exact. Left (42 changed, -4 instrs): the pos[] block -- retail materialises &pos[2/4/6/8] in a3/a2/a1/a0 and stores their .x through them (y's and pos[0].x via sp), reads pos[1].y via addiu v0,sp,0x1EC, and computes y+h late. Tried Set/SetX/SetY orders, CGtV2d(...) temporaries (pointer regs appear but frame +0x50), reference locals/ref-returning inlines (fold away), a walking CGtV2d* -- none.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using namespace GtMathPs2;

namespace Gt2dRenderer {
void RenderTriStripGouraudTex(const CGtV2d&, int, const CGtV2d*, const CGtV2d*, const CGtV4d*);
}

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x120];
    CGtV4d field_120;
    unsigned char pad_130[0x20];
    CGtV4d field_150;
};
extern UnkStruct_D_01E90240 D_01E90240;

// [G] three UV rectangles (top-left, bottom-right) for a horizontal 3-slice strip
struct UnkStruct_0045B510_uv {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
};
extern UnkStruct_0045B510_uv D_004D3660;
extern UnkStruct_0045B510_uv D_004D3698;
struct UnkStruct_D_004D3650 { CGtV2d field_0; unsigned char pad_8[0x8]; };
extern UnkStruct_D_004D3650 D_004D3650;
struct UnkStruct_D_tex { CGtTexture * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_tex D_01EA4624;
extern UnkStruct_D_tex D_01EA4720;

extern "C" CGtV4d * func_001D4E80(CGtV4d *, const CGtV4d &);  // [L] DNAT: GtMathPs2::CGtV4d::operator=(const CGtV4d&) (out of line)
extern "C" CGtV2d * __as__Q29GtMathPs26CGtV2dFRCQ29GtMathPs26CGtV2d(CGtV2d *, const CGtV2d &);  // CGtV2d::operator= (out of line)

static inline void func_0045B510_inl1(CGtV2d * uv, const UnkStruct_0045B510_uv & t, unsigned int f)
{
    uv[0].Set(t.field_0.X(), t.field_8.Y());
    uv[1].Set(t.field_0.X(), t.field_0.Y());
    uv[2].Set(t.field_8.X(), t.field_8.Y());
    uv[3].Set(t.field_8.X(), t.field_0.Y());
    uv[4].Set(t.field_18.X(), t.field_18.Y());
    uv[5].Set(t.field_18.X(), t.field_10.Y());
    uv[6].Set(t.field_18.X(), t.field_18.Y());
    uv[7].Set(t.field_18.X(), t.field_10.Y());
    if (f & 1) {
        uv[8].Set(t.field_28.X(), t.field_28.Y());
        uv[9].Set(t.field_28.X(), t.field_20.Y());
    } else {
        uv[8].Set(t.field_18.X(), t.field_18.Y());
        uv[9].Set(t.field_18.X(), t.field_10.Y());
    }
}

// 0x0045B510
extern "C" void func_0045B510(const CGt2dObject::CGt2dObjectSpace & s, const unsigned int * data)
{
    CGtV2d pos[10];
    CGtV2d uv[10];
    CGtV4d col[10];
    CGtV4d c0;
    CGtV4d c1;
    UnkStruct_D_01E90240 * const g = &D_01E90240;
    if (*data & 2) {
        func_001D4E80(&c0, g->field_150 * s.mColour);
        func_001D4E80(&c1, g->field_120 * s.mColour);
    } else {
        func_001D4E80(&c0, g->field_150 * s.mColour);
        func_001D4E80(&c1, g->field_150 * s.mColour);
    }
    float a;
    float b;
    if (*data & 4) {
        a = 49.0f;
        b = 22.0f;
    } else {
        a = 38.0f;
        b = 17.0f;
    }
    CGtV2d * p1 = &pos[1];
    __as__Q29GtMathPs26CGtV2dFRCQ29GtMathPs26CGtV2d(p1, s.mTopLeftPos);
    float x = p1->X();
    float y = p1->Y();
    float mid = 0.5f * (s.mSize.X() - a - b);
    float y1 = y + s.mSize.Y();
    pos[0].Set(x, y1);
    float x1 = a + x;
    pos[2].Set(x1, y1);
    pos[3].Set(x1, y);
    float x2 = mid + x1;
    pos[4].Set(x2, y1);
    pos[5].Set(x2, y);
    float x3 = mid + x2;
    pos[6].Set(x3, y1);
    pos[7].Set(x3, y);
    float x4 = b + x3;
    pos[8].Set(x4, y1);
    pos[9].Set(x4, y);
    if (*data & 4) func_0045B510_inl1(uv, D_004D3698, *data);
    else func_0045B510_inl1(uv, D_004D3660, *data);
    func_001D4E80(&col[0], c0);
    func_001D4E80(&col[1], c0);
    func_001D4E80(&col[2], c0);
    func_001D4E80(&col[3], c1);
    func_001D4E80(&col[4], c1);
    func_001D4E80(&col[5], c1);
    func_001D4E80(&col[6], c1);
    func_001D4E80(&col[7], c0);
    func_001D4E80(&col[8], c0);
    func_001D4E80(&col[9], c0);
    if (*data & 4) {
        Gt2dRenderer::SetTexture(D_01EA4624.field_0);
    } else {
        Gt2dRenderer::SetTexture(D_01EA4720.field_0);
    }
    Gt2dRenderer::RenderTriStripGouraudTex(D_004D3650.field_0, 10, pos, uv, col);
}
