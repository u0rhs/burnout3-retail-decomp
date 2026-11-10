// NONMATCHING: _RenderDropShadow__20CGt2dObjectParagraphFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 153 / ours 153 instructions, 71 in changed runs
// near38: retail statement order (text, shadow, k, style, font, lineH, then size = ..., off, a CGtTexture *tex = font->field_4 local before the step/last code so its load sits above the branch), last declared uninitialised: 153/153, 71 changed (was 151/153, 91); float registers now exact (y f20, k f21, lineH f22, off.y f23, step f24), first/last s1/s0 exact. Left: prologue schedule -- retail loads text (lw t0,8(a1)) and the style pointer first, reads size.y once through addiu a2,sp,0x114 for off and step, line/n s2/s3 swapped; pragmas inert
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a124: 151/153 instrs, ~90 in changed runs; control flow now believed exact (render if first==-1 || (line>=first && line<=last), no break; shadow at pos+off then colour at pos). Left: prologue schedule (retail keeps style ptr in a3 and loads lh 0x16/0x14 before mul; s-regs last=s0 first=s1 line=s2 n=s3 font=s6, f20=y f21=k f22=lineH f23=off.y f24=step). Decl-order sweep of 144 failed. Correction to archived func_002F9140: first==-1 is the render-all test (not last==-1), and there is no break on line>last
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

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

extern "C" void _RenderDropShadow__20CGt2dObjectParagraphFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace & space, const void * pdata)
{
    const UnkStruct_2F8C50_data * d = (const UnkStruct_2F8C50_data *)pdata;
    const CGt2dFont * font;
    int line = 0;
    int last;
    int first;
    float lineH;
    float step;
    float k;
    float y = 0.0f;
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
    first = st->field_14;
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
        if (first == -1 || (line >= first && line <= last)) {
            if (n != -1) {
                CGtV2d pos(0.0f, y);
                Gt2dRenderer::RenderSpritesTex(shadow, pos + off, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData, (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
                Gt2dRenderer::RenderSpritesTex(space.mColour, pos, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData, (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
            }
        }
        y += step;
        line++;
    }
}
