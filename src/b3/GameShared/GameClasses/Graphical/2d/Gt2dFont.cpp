// NOT WIRED IN, NOT PROVEN HERE: seeded from the earlier research repo (docs/provenance.md); not a separate unit in this repo's
// split, so it can't be verified yet (docs/known.md N16).
// Gt2dFont.cpp (E map), retail 0x1D7A70-0x1D8260: the whole file. Local fork unit (docs/conventions.md "Original structure").
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

// 0x1D7A70: give '0'-'9' the widest digit's advance, each centred in it (counters do not jiggle)
void CGt2dFont::MakeNumberCharactersFixedWidth()
{
    float widest = -3.4028235e+38f;
    for (unsigned short c = '0'; c <= '9'; c++) {
        UnkStruct_Gt2dFont_Glyph* g = UnkInline_FindGlyph(c);
        if (g->field_1c == c && widest < g->field_18)
            widest = g->field_18;
    }
    if (widest < 0.0f)
        return;
    for (unsigned short d = '0'; d <= '9'; d++) {
        UnkStruct_Gt2dFont_Glyph* h = UnkInline_FindGlyph(d);
        if (h->field_1c == d) {
            h->field_10.marValues[0] += (widest - h->field_18) * 0.5f;
            h->field_18 = widest;
        }
    }
}

// 0x1D7B90: one textured sprite per character; glyphs with a negative UV x (spaces) are not drawn.
// Best 78.08% (time-boxed): differs in register colouring (x kept in f22 plus a move), the char code masked before the
// lookup, and stack slots of the vector temporaries. Permuter candidate.
void CGt2dFont::RenderString(const unsigned short* s, float x, float y, float size, const CGtV4d colour) const
{
    UnkStruct_Gt2dFont_Glyph* g = UnkInline_FindGlyph(*s);
    CGtV2d scale = field_8 * size;
    const CGtV2d origin(0.0f, 0.0f);
    x -= g->field_10.marValues[0] * scale.marValues[0];
    for (;;) {
        if (g->field_0.marValues[0] >= 0.0f) {
            CGtV2d corners[2];
            CGtV2d uvs[2];
            corners[0] = CGtV2d(x, y) + g->field_10 * scale;
            uvs[0] = g->field_0;
            corners[1] = corners[0] + scale * g->field_8;
            uvs[1] = g->field_0 + g->field_8;
            Gt2dRenderer::SetTexture(field_4);
            Gt2dRenderer::RenderSpritesTex(colour, origin, 1, corners, uvs);
        }
        unsigned short c = *++s;
        if (!c)
            break;
        float advance = g->field_18;
        g = UnkInline_FindGlyph(c);
        x += advance * scale.marValues[0];
    }
}

// 0x1D7E10: like GetStringWidth, but stops at the first point the text would exceed maxWidth, preferring
// to break at the last space seen (lastBreak/breakWidth) over mid-word; newlines always break. flag enables
// a mid-word hard break when no space was found yet. [L]: inferred from the disassembly, not yet objdiff-verified.
float CGt2dFont::GetStringStartAndEnd(const unsigned short* s, float maxWidth, const unsigned short** outStart,
                                       const unsigned short** outEnd, bool flag) const
{
    bool foundBreak = false;
    float maxW = maxWidth / field_8.marValues[0];
    while (*s == ' ' || *s == '\n') {
        s++;
        if (*s == 0) {
            *outStart = s;
            *outEnd = s;
            return 0.0f;
        }
    }

    *outStart = s;
    UnkStruct_Gt2dFont_Glyph* g = UnkInline_FindGlyph(*s);
    float width = -g->field_10.marValues[0];
    const unsigned short* lastBreak = 0;
    float breakWidth;

    unsigned short c;

    for (;;) {
        c = *++s;
        if (c == 0)
            break;

        if (c == '\n') {
            float extent = width + g->field_10.marValues[0] + g->field_8.marValues[0];
            if (!(extent < maxW) && foundBreak) {
                *outEnd = lastBreak;
                return breakWidth * field_8.marValues[0];
            }
            *outEnd = s;
            return extent * field_8.marValues[0];
        }
        if (c == ' ') {
            float extent = width + g->field_10.marValues[0] + g->field_8.marValues[0];
            if (extent < maxW) {
                foundBreak = true;
                breakWidth = extent;
                lastBreak = s;
            } else if (lastBreak) {
                *outEnd = lastBreak;
                return breakWidth * field_8.marValues[0];
            }
        } else if (!flag && !foundBreak) {
            float extent = width + g->field_10.marValues[0] + g->field_8.marValues[0];
            if (extent < maxW)
                breakWidth = extent;
        }

        float advance = g->field_18;
        g = UnkInline_FindGlyph(c);
        width += advance;

        if (flag && !foundBreak && !(width < maxW)) {
            *outEnd = s - 1;
            return (width - g->field_18 + g->field_10.marValues[0] + g->field_8.marValues[0]) * field_8.marValues[0];
        }
    }

    if (lastBreak) {
        float extent = width + g->field_10.marValues[0] + g->field_8.marValues[0];
        if (extent < maxW) {
            *outEnd = s;
            return extent * field_8.marValues[0];
        }
        *outEnd = lastBreak;
        return breakWidth * field_8.marValues[0];
    }
    if (!flag) {
        *outEnd = s;
        return (width + g->field_10.marValues[0] + g->field_8.marValues[0]) * field_8.marValues[0];
    }
    {
        float extent = width + g->field_10.marValues[0] + g->field_8.marValues[0];
        if (extent < maxW) {
            *outEnd = s;
            return extent * field_8.marValues[0];
        }
        *outEnd = s - 1;
        return breakWidth * field_8.marValues[0];
    }
}

// 0x1D80A0: the advances added up
float CGt2dFont::GetStringWidthIncludingLRKern(const unsigned short* s) const
{
    float width = UnkInline_FindGlyph(*s)->field_18;
    while (*++s)
        width += UnkInline_FindGlyph(*s)->field_18;
    return width * field_8.marValues[0];
}

// 0x1D8150: from the first glyph's left edge to the last glyph's right edge
float CGt2dFont::GetStringWidth(const unsigned short* s) const
{
    UnkStruct_Gt2dFont_Glyph* g = UnkInline_FindGlyph(*s);
    float width = -g->field_10.marValues[0];
    while (*++s) {
        width += g->field_18;
        g = UnkInline_FindGlyph(*s);
    }
    width += g->field_10.marValues[0] + g->field_8.marValues[0];
    return width * field_8.marValues[0];
}

// 0x1D8210
void CGt2dFont::Prepare(CGtTexture* texture)
{
    field_4 = texture;
    if (!field_18) {
        FixupPointers((unsigned int)this);
        field_18 = 1;
    }
}
