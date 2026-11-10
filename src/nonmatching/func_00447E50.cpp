// NONMATCHING: func_00447E50 -- retail 164 / ours 164 instructions, 1 in changed runs
// pass3b: by-reference inline param (advance the caller's text, save a copy for d->field_0) at three definition points is worse (34): retail has TWO copies (s1=a3, v1=s1) and reads the first *s through v1; ruled out together with the earlier list.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lit4fix: .lit4 externs rewritten as literals; was: near14: GetStringWidth idiom (width += last glyph; then CGtV2d fs copy; w = width*fs.x) fixed the fs copy order: 9 -> 1. Left: first *s lhu reads through s1 (text) where retail uses its v1 copy; tried s[0], local copies in inline/caller, const& param, const font, sreg run, pragmas (propagation off 2


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

#pragma auto_inline on

using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
extern "C" void func_00447630(const CGt2dObject::CGt2dObjectSpace &, const void *);
extern "C" void func_00447640(const CGt2dObject::CGt2dObjectSpace &, const void *);
struct UnkStruct_00447E50_data {
    const unsigned short *field_0;
    float field_4;
    float field_8;
};

static inline int func_00447E50_inl1(UnkStruct_Gt2dFont_Glyph *g)
{
    int r = 1;
    if (g->field_0.marValues[0] < 0.0f) r = 0;
    return r;
}

// 0x00447E50
// [G] stack investigator: the string-width computation as an inline helper (cf. CGt2dFont::GetStringWidth): its
// CGtV2d copy of the font scale then sits below the caller's Prepare temporaries, as in retail's frame.
static inline float func_00447E50_inl2(CGt2dFont *font, const unsigned short *s)
{
    UnkStruct_Gt2dFont_Glyph *sp = font->UnkInline_FindGlyph(0x20);
    float spacing = -0.2f * sp->field_18;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(*s);
    unsigned char any = func_00447E50_inl1(g);
    float width = -g->field_10.marValues[0];
    while (*++s) {
        width += g->field_18 + spacing;
        g = font->UnkInline_FindGlyph(*s);
        if ((bool)any == false) any = func_00447E50_inl1(g);
    }
    float w;
    if (!any) {
        w = 0.0f;
    } else {
        width += g->field_10.marValues[0] + g->field_8.marValues[0];
        CGtV2d fs = font->field_8;
        w = width * fs.marValues[0];
    }
    return w;
}

extern "C" void func_00447E50(CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const unsigned short *text, float size, float maxw)
{
    UnkStruct_00447E50_data *d = (UnkStruct_00447E50_data *)self->mauDataBlock;
    CGtV4d colour(1.0f, 1.0f, 1.0f, 1.0f);
    CGtV2d sz;
    CGt2dFont *font = D_00665ED0.pFont;
    float w = func_00447E50_inl2(font, text);
    float inv = 0.0f;
    float sx;
    CGt2dObject::UnkFn_RenderCallback cb;
    if (w <= inv) {
        sx = size;
        cb = func_00447630;
    } else {
        cb = func_00447640;
        sx = w * size;
        inv = 1.0f / w;
    }
    float ratio = 1.0f;
    if (!(sx <= maxw)) {
        ratio = maxw / sx;
        sx = maxw;
    }
    sz.marValues[0] = sx;
    sz.marValues[1] = size;
    self->CGt2dObject::Prepare(pos - sz * anchor, sz, colour, cb, 0x40, 0x18);
    d->field_0 = text;
    d->field_4 = inv;
    d->field_8 = ratio;
}

