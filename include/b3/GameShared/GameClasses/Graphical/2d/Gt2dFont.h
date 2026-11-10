// CGt2dFont (E map: Gt2dFont.cpp). Header name/folder: project convention (K18/K19).
// Layout from retail code only (Gt2dFont.cpp 0x1D7A70-0x1D8260; docs/hud2d.md). Burnout 2's C2dFont (4,508 bytes, inline
// stream data) does not carry over.
// The font is relocatable data: Prepare turns stored offsets (relative to the font) into absolute pointers once, then
// sets field_18. On the host those slots must stay 32-bit guest pointers (B3_PTR), which is why they are not T*.
#ifndef B3_GT2DFONT_H
#define B3_GT2DFONT_H

#include "b3/B3Ptr.h"
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"   // Gt2dRenderer

class CGtTexture;

// One character, 0x20 bytes (type name: placeholder). Cf. B2 C2dFontChar (mTopLeftUV, mrWidth, mrKernLeft,
// mrKernRight) [G]: Burnout 3's record differs.
struct UnkStruct_Gt2dFont_Glyph {
    GtMathPs2::CGtV2d field_0;     // [C] RenderString: second UV pair's base (texture top-left [L])
    GtMathPs2::CGtV2d field_8;     // [C] RenderString: quad size and UV extent; GetStringWidth: the last glyph's width
    GtMathPs2::CGtV2d field_10;    // [C] offset: x (GetStringWidth starts at -x; MakeNumberCharactersFixedWidth centres it), y
    float field_18;                // [C] advance
    unsigned short field_1c;       // [C] character code (UTF-16)
    unsigned short field_1e;       // not seen yet
};
B3_CHECK_SIZE(UnkStruct_Gt2dFont_Glyph, 0x20);

class CGt2dFont {
public:
    void MakeNumberCharactersFixedWidth();                                                     // 0x1D7A70
    void RenderString(const unsigned short*, float, float, float, const GtMathPs2::CGtV4d) const;    // 0x1D7B90
    float GetStringStartAndEnd(const unsigned short*, float, const unsigned short**, const unsigned short**,
                              bool) const;                                                     // 0x1D7E10 (returns in $f0, like the sibling width functions below [L]); mangled name confirms bool (ends in 'b'), not int
    float GetStringWidthIncludingLRKern(const unsigned short*) const;   // 0x1D80A0 (returns in $f0 [C])
    float GetStringWidth(const unsigned short*) const;                  // 0x1D8150 (returns in $f0 [C])
    void Prepare(CGtTexture*);                                          // 0x1D8210
    // E map: CGt2dFont::FixupPointers(unsigned int): no out-of-line copy in retail; inlined in Prepare [L].
    void FixupPointers(unsigned int base)
    {
        field_1c = (UnkStruct_Gt2dFont_Glyph*)(base + (unsigned int)field_1c);
        for (unsigned int i = 0; i < 0x80; i++)
            field_20[i] = (UnkStruct_Gt2dFont_Glyph*)(base + (unsigned int)field_20[i]);
    }
    // The character lookup inlined in every function (never out of line, so its name is not in any map; this name is a
    // project placeholder): start at the bucket for c & 0x7F, walk the glyph array until the code matches or the end.
    UnkStruct_Gt2dFont_Glyph* UnkInline_FindGlyph(unsigned short c) const
    {
        UnkStruct_Gt2dFont_Glyph* g = field_20[c & 0x7F];
        while (g->field_1c != c) {
            if (g == field_1c)
                break;
            g++;
        }
        return g;
    }

    unsigned int field_0;                      // not seen yet
    B3_PTR(CGtTexture) field_4;                // [C] Prepare a1; RenderString passes it to Gt2dRenderer::SetTexture
    GtMathPs2::CGtV2d field_8;                 // [C] cell scale: every width is multiplied by .x, RenderString by both
    float field_10;                            // [C] float: func_003816E0 reads it with lwc1 0x10 at 0x381784 as the
                                               // text baseline y offset [L] (fix3; draftAO 2026-11-01)
    unsigned char pad_14[4];                   // not seen yet
    unsigned int field_18;                     // [C] 0 until Prepare has fixed the offsets up, then 1
    B3_PTR(UnkStruct_Gt2dFont_Glyph) field_1c; // [C] end of the glyph array (offset until Prepare)
    B3_PTR(UnkStruct_Gt2dFont_Glyph) field_20[0x80];  // [C] buckets by c & 0x7F (offsets until Prepare)
    // size not known yet (>= 0x220); the glyph array follows somewhere after
};
B3_CHECK_OFFSET(CGt2dFont, field_4, 0x4);
B3_CHECK_OFFSET(CGt2dFont, field_8, 0x8);
B3_CHECK_OFFSET(CGt2dFont, field_18, 0x18);
B3_CHECK_OFFSET(CGt2dFont, field_1c, 0x1C);
B3_CHECK_OFFSET(CGt2dFont, field_20, 0x20);

#endif
