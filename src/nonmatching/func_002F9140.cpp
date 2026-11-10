// NONMATCHING: func_002F9140 -- retail 113 / ours 113 instructions, 35 in changed runs
// near31: 35 off, 113/113: non-const style pointer + lineH read before the 'CGtV2d size = ...' copy gives retail's second field_8 load; step computed before an explicit 'last = -1' arm (bne/b/nop); texture pointer local before the if. Left: prologue order (retail loads d->field_10 first, before sd ra) and the size-copy / lineH scheduling around it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [G] the text style the object keeps at +0x0C of its data block: two line-metric floats, the font at +0x10, first/count line range
struct UnkStruct_002F9140_style {
    unsigned char pad_0[0x8];
    float field_8;
    float field_C;
    const CGt2dFont * field_10;
    short field_14;
    short field_16;
};

struct UnkStruct_002F9140_data {
    CGtV2d field_0;
    const unsigned short * field_8;
    UnkStruct_002F9140_style * field_C;
    unsigned int field_10;
    float field_14;
};

extern const float D_004C4520[];

extern "C" int func_002F9310(const CGt2dObject::CGt2dObjectSpace *, const unsigned short **, const CGt2dFont *, const CGtV2d *, unsigned int, float, float, float);  // CGt2dObjectParagraph::_BuildLineOfText

// 0x002F9140
extern "C" void func_002F9140(const CGt2dObject::CGt2dObjectSpace & space, const void * pdata)
{
    const UnkStruct_002F9140_data * d = (const UnkStruct_002F9140_data *)pdata;
    const CGt2dFont * font;
    int line = 0;
    int last = -1;
    int first;
    float step;
    float k;
    float y = 0.0f;
    float lineH;
    k = D_004C4520[d->field_10 & 3];
    UnkStruct_002F9140_style * st = d->field_C;
    lineH = st->field_8;
    CGtV2d size = space.mSize * d->field_0;
    const unsigned short * text = d->field_8;
    font = st->field_10;
    first = st->field_14;
    CGtTexture * tex = font->field_4;
    step = (st->field_8 + st->field_C) * size.marValues[1];
    if (st->field_16 == -1) {
        last = -1;
    } else {
        last = first + st->field_16;
    }
    Gt2dRenderer::SetTexture(tex);
    while (*text != 0) {
        int n = func_002F9310(&space, &text, font, &size, d->field_10, lineH, d->field_14, k);
        if (n == 0) {
            break;
        }
        if (last == -1 || (line >= first && line <= last)) {
            if (n != -1) {
                CGtV2d off(0.0f, y);
                Gt2dRenderer::RenderSpritesTex(space.mColour, off, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData, (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
            }
        }
        if (last != -1 && line > last) {
            break;
        }
        y += step;
        line++;
    }
}
