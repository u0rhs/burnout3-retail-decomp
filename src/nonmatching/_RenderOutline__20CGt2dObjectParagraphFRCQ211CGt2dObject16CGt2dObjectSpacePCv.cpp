// NONMATCHING: _RenderOutline__20CGt2dObjectParagraphFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 158 / ours 158 instructions, 69 in changed runs
// near38: the _RenderDropShadow prologue order (text, shadow, k, style, font, lineH, size, off, CGtTexture *tex local, step) + floats declared step, k, y, lineH: 158/158, 69 changed (was 157/158, 87). Float registers y f21 / k f22 / step f23 exact; left: lineH and the per-pass off.y load swapped (retail lineH f24, off.y f20), prologue load schedule (text / style pointer first, size.y read once through a pointer)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_2F8C50_style {
    CGtV2d field_0;
    float field_8;
    float field_C;
    const CGt2dFont * field_10;
    short field_14;
    short field_16;
};

struct UnkStruct_2F8C50_data {
    CGtV2d field_0;
    const unsigned short * field_8;
    const UnkStruct_2F8C50_style * field_C;
    unsigned int field_10;
    float field_14;
};

extern const float D_004C4520[];

extern "C" int func_002F9310(const CGt2dObject::CGt2dObjectSpace *, const unsigned short **, const CGt2dFont *, const CGtV2d *, unsigned int, float, float, float);

extern "C" void _RenderOutline__20CGt2dObjectParagraphFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace & space, const void * pdata)
{
    const UnkStruct_2F8C50_data * d = (const UnkStruct_2F8C50_data *)pdata;
    const CGt2dFont * font;
    float step;
    float k;
    float y = 0.0f;
    float lineH;
    const unsigned short * text = d->field_8;
    CGtV4d shadow(0.0f, 0.0f, 0.0f, space.mColour.W());
    k = D_004C4520[d->field_10 & 3];
    const UnkStruct_2F8C50_style * st = d->field_C;
    font = st->field_10;
    lineH = st->field_8;
    CGtV2d size = space.mSize * d->field_0;
    CGtV2d off = st->field_0 * size;
    CGtTexture * tex = font->field_4;
    step = (st->field_8 + st->field_C) * size.marValues[1];
    Gt2dRenderer::SetTexture(tex);
    while (*text != 0) {
        int n = func_002F9310(&space, &text, font, &size, d->field_10, lineH, d->field_14, k);
        if (n == 0) {
            break;
        }
        if (n != -1) {
            CGtV2d pos(0.0f, y);
            for (int j = 0; j < 2; j++) {
                Gt2dRenderer::RenderSpritesTex(shadow, pos + off, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData, (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
                Gt2dRenderer::RenderSpritesTex(shadow, pos - off, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData, (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
                off.marValues[0] = -off.marValues[0];
            }
            Gt2dRenderer::RenderSpritesTex(space.mColour, pos, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData, (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
        }
        y += step;
    }
}
