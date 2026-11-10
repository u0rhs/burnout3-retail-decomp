// NONMATCHING: _BuildBatchData__24CB3ScrollingText2dObjectFRCQ29GtMathPs26CGtV2dPPCUsRCQ211CGt2dObject16CGt2dObjectSpaceRCQ224CB3ScrollingText2dObject34CGt2dObjectScrollingTextRenderData -- diff unavailable
// a260: unchanged draft (61 changed, 236 vs 237): register numbering, two stack slots, lhu/andi order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// DRAFT -- NOT MATCHING, NOT WIRED IN (retail's asm is still linked: game/unit_0031C5D0.s). 236/237 instructions,
// frame 0x80 right; register numbering and two stack slots differ (docs/known.md N101).
#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;

// Same declaration and N51 padding as B3HeadingComponent_00319A90.cpp.
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

// 0x0031C5D0. Fills mgu8RenderBatchData (positions; UVs at +0xFE0) with a tri-strip for the text from *text at
// *cursor: per drawn glyph five vertices (the first repeats the second, joining it to the previous glyph), slanted
// by 0.36 * scale.x per unit above the strip's bottom edge, the cursor advancing by each glyph's advance. Stops when
// the buffer would overflow, at the end of the text (then wraps to its start, the cursor moving on by the gap
// `data.field_C`) or after a glyph with no image; returns the vertex count.
int CB3ScrollingText2dObject::_BuildBatchData(const CGtV2d &scale, CGtV2d *cursor, const unsigned short **text,
                                              const CGt2dObject::CGt2dObjectSpace &space,
                                              const CGt2dObjectScrollingTextRenderData &data)
{
    const unsigned short *s = *text;
    CGt2dFont *font = D_00665ED0.pFont;
    unsigned short c = *s;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(c);
    // Declared size, fontScale, cell; cell initialised (an assignment would reserve an extra empty slot and give
    // 0x90), size assigned later: retail's frame 0x80 (N101). fontScale is only ever stored (retail's 0x60).
    CGtV2d size;
    CGtV2d fontScale = font->field_8;
    CGtV2d cell = fontScale * scale;
    float bottom = space.mTopLeftPos.marValues[1] + space.mSize.marValues[1];
    float slant = 0.36f * scale.marValues[0];
    size = cell * 28.0f;
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    unsigned int n = 0;
    for (;;) {
        // `!(u >= 0)` as a bool, then `!skip`: retail materialises it and xori's it (N101); a plain `if (u >= 0)` or
        // `if (!(u < 0))` branches directly and shifts every register.
        bool skip = !(g->field_0.marValues[0] >= 0.0f);
        if (!skip) {
            if (n + 5 >= 0x1FD)
                break;
            n += 5;
            pos[3] = *cursor + g->field_10 * size;
            uv[3] = g->field_0;
            pos[2] = pos[3] + size * g->field_8;
            uv[2] = g->field_0 + g->field_8;
            pos[1].Set(pos[3].marValues[0], pos[2].marValues[1]);
            uv[1].Set(uv[3].marValues[0], uv[2].marValues[1]);
            pos[4].Set(pos[2].marValues[0], pos[3].marValues[1]);
            uv[4].Set(uv[2].marValues[0], uv[3].marValues[1]);
            pos[1].marValues[0] = pos[1].marValues[0] + slant * (bottom - pos[1].marValues[1]);
            pos[2].marValues[0] = pos[2].marValues[0] + slant * (bottom - pos[2].marValues[1]);
            pos[3].marValues[0] = pos[3].marValues[0] + slant * (bottom - pos[3].marValues[1]);
            pos[4].marValues[0] = pos[4].marValues[0] + slant * (bottom - pos[4].marValues[1]);
            pos[0] = pos[1];
            uv[0] = uv[1];
            pos += 5;
            uv += 5;
        }
        cursor->marValues[0] = cursor->marValues[0] + g->field_18 * size.marValues[0];
        c = *++s;
        if (c == 0)
            break;
        if (g->field_0.marValues[0] < 0.0f)
            break;
        pos[0] = pos[-1];
        uv[0] = uv[-1];
        pos++;
        uv++;
        n++;
        g = D_00665ED0.pFont->UnkInline_FindGlyph(c);
    }
    if (c == 0) {
        *text = data.field_0;
        cursor->marValues[0] = cursor->marValues[0] + data.field_C * scale.marValues[0];
    } else {
        *text = s;
    }
    return n;
}
