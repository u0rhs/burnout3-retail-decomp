// NONMATCHING: func_003816E0 -- retail 242 / ours 259 instructions, 271 in changed runs
// fix3 (2026-11-01): constants from retail gp literals: slant ratio 0.3 (D_004E06B8, was 2.0), space advance -0.2 (D_004E0864, was 1.0); baseline from font+0x10 (was font->field_8.y at +0xC) | Before: a151: logic-complete draft (glyph quad builder, 4 vertices/glyph + 2 strip-join verts, slanted by ratio*(bottom-y); decoded from asm: A=g.off*(k,scale.y), B=g.size*(k,scale.y), pq[4]/uq[4] stack arrays at 0x90/0x70 filled in reverse, x advance = extra + (0.0f + x + adv*k)). Not close: 258 vs 242 instrs, 313 changed, frame 0xD0 vs 0xC0; ours keeps pq/uq addresses in s0/s1 where retail uses a leaf frame with no saved regs. Same family as the open CB3ScrollingText2dObject::_BuildBatchData (a147: 61 changed, N101/N140 stack-slot problem), so skipped after one draft per BRIEF.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

struct UnkStruct_003816E0_data {
    const unsigned short * field_0;
    float field_4;
    float field_8;
    float field_C;
    unsigned char pad_10[3];
    unsigned char field_13;
};

// 0x003816E0
extern "C" int func_003816E0(const CGt2dObject::CGt2dObjectSpace * space, const UnkStruct_003816E0_data * d)
{
    const unsigned short * s = d->field_0;
    CGt2dFont * font = D_00665ED0.pFont;
    unsigned short c = *s;
    UnkStruct_Gt2dFont_Glyph * g = font->UnkInline_FindGlyph(c);
    CGtV2d fs;
    CGtV2d scale;
    CGtV2d cur;
    CGtV2d * pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d * uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    unsigned int n = 0;
    float ratio = 0.3f * (space->mSize.marValues[0] / space->mSize.marValues[1]) * (d->field_8 / d->field_C);   // fix3 [C] D_004E06B8 = 0.3 (0x381758; was 2.0)
    float bottom = 0.0f + space->mTopLeftPos.marValues[1];
    bottom += font->field_10 * space->mSize.marValues[1];   // fix3 [C] retail lwc1 0x10(font) (0x381784), not field_8.y (0xC)
    fs = font->field_8;
    scale = font->field_8 * space->mSize;
    float k = d->field_4 * scale.marValues[0];
    cur.Set(space->mTopLeftPos.marValues[0], space->mTopLeftPos.marValues[1]);
    if (!(d->field_13 & 0x40)) {
        cur.marValues[0] = 0.0f + cur.marValues[0] - g->field_10.marValues[0] * k;
    }
    float extra = 0.0f;
    if (d->field_13 & 0x20) {
        UnkStruct_Gt2dFont_Glyph * sp = font->UnkInline_FindGlyph(0x20);
        extra = -0.2f * (sp->field_18 * k);   // fix3 [C] D_004E0864 = -0.2 (0x381814; was 1.0)
    }
    for (;;) {
        if (!(g->field_0.marValues[0] < 0.0f)) {
            if (n + 5 >= 0x1FD) {
                return n;
            }
            CGtV2d sv(k, scale.marValues[1]);
            CGtV2d A = g->field_10 * sv;
            CGtV2d B = g->field_8 * sv;
            CGtV2d uv1 = g->field_0 + g->field_8;
            CGtV2d c0 = cur + A;
            CGtV2d c1 = c0 + B;
            CGtV2d pq[4];
            CGtV2d uq[4];
            uq[3] = g->field_0;
            uq[0] = uv1;
            uq[2].Set(uv1.marValues[0], g->field_0.marValues[1]);
            uq[1].Set(g->field_0.marValues[0], uv1.marValues[1]);
            pq[3] = c0;
            pq[0] = c1;
            pq[2].Set(c1.marValues[0], c0.marValues[1]);
            pq[1].Set(c0.marValues[0], c1.marValues[1]);
            pq[3].marValues[0] = pq[3].marValues[0] + ratio * (bottom - pq[3].marValues[1]);
            pq[2].marValues[0] = pq[2].marValues[0] + ratio * (bottom - pq[2].marValues[1]);
            pq[1].marValues[0] = pq[1].marValues[0] + ratio * (bottom - pq[1].marValues[1]);
            pq[0].marValues[0] = pq[0].marValues[0] + ratio * (bottom - pq[0].marValues[1]);
            if (n > 0) {
                n += 2;
                pos[0] = pos[-1];
                uv[0] = uv[-1];
                pos[1] = pq[3];
                uv[1] = uq[3];
                pos += 2;
                uv += 2;
            }
            n += 4;
            pos[0] = pq[3];
            pos[1] = pq[2];
            pos[2] = pq[1];
            pos[3] = pq[0];
            uv[0] = uq[3];
            uv[1] = uq[2];
            uv[2] = uq[1];
            uv[3] = uq[0];
            pos += 4;
            uv += 4;
        }
        cur.marValues[0] = extra + (0.0f + cur.marValues[0] + g->field_18 * k);
        c = *++s;
        if (c == 0) {
            return n;
        }
        g = D_00665ED0.pFont->UnkInline_FindGlyph(c);
    }
}
