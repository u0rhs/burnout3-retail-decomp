// NONMATCHING: func_00382950 -- retail 161 / ours 161 instructions, 7 in changed runs
// fresh3: Gt2d sprite pair render; logic/frame/layout exact; 7 FP-register diffs in the second RenderSpritesTex block (half.x/half.y/pos+half numbering); tried ref/pointer/inline/copy forms of half and T
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGtTexture;
namespace Gt2dRenderer {
void RenderSpritesTex(GtMathPs2::CGtV4d, const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*, const GtMathPs2::CGtV2d*);
void SetTexture(CGtTexture*);
}
struct UnkStruct_00382950 {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
};
struct UnkStruct_00382950_a1 {
    CGtV2d field_0;
    int field_8;
};
struct UnkStruct_00382950_uv {
    CGtV2d field_0[2];
};
extern CGtV2d D_004C9620[30];
extern CGtV2d D_004C9530[30];
extern CGtV4d D_01E90310;
struct UnkStruct_00382950_tex {
    CGtTexture *field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_00382950_tex D_01EA46E0;
extern UnkStruct_00382950_tex D_01EA4728;
extern UnkStruct_00382950_tex D_01EA472C;
extern UnkStruct_00382950_uv D_01EA4A50[];
extern UnkStruct_00382950_uv D_01EA49A0[];
// 0x00382950
extern "C" void func_00382950(const UnkStruct_00382950 *self, const UnkStruct_00382950_a1 *p)
{
    CGtV4d col = D_01E90310 * self->field_10;
    CGtV2d s = self->field_8 * p->field_0;
    int idx = p->field_8;
    const CGtV2d &b = D_004C9530[idx];
    const CGtV2d &a = D_004C9620[idx];
    CGtV2d half = ((a - b) * s) * 0.5f;
    CGtV2d zero(0.0f, 0.0f);
    if (idx == 5) {
        col = self->field_10;
        Gt2dRenderer::SetTexture(D_01EA472C.field_0);
    } else if (idx == 8) {
        col = self->field_10;
        Gt2dRenderer::SetTexture(D_01EA4728.field_0);
    } else {
        Gt2dRenderer::SetTexture(D_01EA46E0.field_0);
    }
    CGtV2d T[2];
    T[0] = self->field_0;
    T[1] = self->field_0 + self->field_8;
    Gt2dRenderer::RenderSpritesTex(col, zero, 1, T, D_01EA4A50[p->field_8].field_0);
    T[0] = half + self->field_0;
    T[1] = (self->field_0 + self->field_8) - half;
    Gt2dRenderer::RenderSpritesTex(self->field_10, zero, 1, T, D_01EA49A0[p->field_8].field_0);
}
