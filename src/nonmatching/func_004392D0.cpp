// NONMATCHING: func_004392D0 -- retail 211 / ours 211 instructions, 39 in changed runs
// L259: logic, length (211/211) and frame (0x90) exact. Left (39): a register rotation in the prologue/first loop -- retail iterates the width loop on a copy (v1) and the draw loop on s (a3) yet reloads *s for the second lookup; ours gets the reload only with loop 1 advancing s and loop 2 a copy (start), which swaps a3/v1/t4/a0. Shapes found: scale.X() for the x start/advance (one scale.x register), x += adv*X() before the next lookup, 'bool e = uv.x >= 0.0f; if (e)', w declared first (mtc1 f4 early), CGtV2d(font->field_8) copy temp for the dead 0x78 stores.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_004392D0 -- hand-written (L259); the lifter refused it.
// Unnamed in every table: placeholder with C linkage; file and Area unknown, so _unclassified/.
// [G] a static text helper: sums the glyph advances, shrinks the x scale to fit maxW, then fills
// CGt2dObject::mgu8RenderBatchData with one sprite per drawable glyph and renders them.

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

// 0x004392D0
extern "C" void func_004392D0(const CGtV4d colour, const CGtV2d &origin, const CGtV2d &size, const unsigned short *s, const CGt2dFont *font, float maxW)
{
    float w = 0.0f;
    CGtV2d scale = CGtV2d(font->field_8) * size;
    CGtV2d c0;
    CGtV2d p;
    CGtV2d c1;
    CGtV2d uv1;
    const unsigned short *start = s;
    CGtV2d *base0 = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *base1 = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    CGtV2d *corners = base0;
    CGtV2d *uvs = base1;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(*s);
    for (;;) {
        w += g->field_18;
        unsigned short c = *++s;
        if (c == 0) break;
        g = font->UnkInline_FindGlyph(c);
    }
    if (w * scale.marValues[0] > maxW) {
        scale.marValues[0] = maxW / w;
    }
    g = font->UnkInline_FindGlyph(*start);
    float x = -g->field_10.marValues[0] * scale.X();
    float y = 0.0f;
    for (;;) {
        bool e = g->field_0.marValues[0] >= 0.0f;
        if (e) {
            p = CGtV2d(x, y) + g->field_10 * scale;
            c0 = p;
            *corners++ = p;
            *uvs++ = g->field_0;
            c1 = c0 + scale * g->field_8;
            *corners++ = c1;
            uv1 = g->field_0 + g->field_8;
            *uvs++ = uv1;
        }
        unsigned short c = *++start;
        if (c == 0) break;
        x += g->field_18 * scale.X();
        g = font->UnkInline_FindGlyph(c);
    }
    if (corners > base0) {
        Gt2dRenderer::RenderSpritesTex(colour, origin, (corners - base0) / 2, base0, base1);
    }
}
