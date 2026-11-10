// NONMATCHING: func_00447AB0 -- retail 231 / ours 229 instructions, 247 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: L262 first draft, logic decoded (italic-text strip builder called by func_00447640: tl/tr/bl/br + 4 UV locals, degenerate join when count>0, 0x1FC vertex cap, sheared x = shear*(base-y)+x); frame 0xB0 vs 0xC0 and temp/slot layout not yet worked; visible test materialises differently (retail bc1f/dad
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00447AB0 -- hand-written (L262); the lifter refused it. Called by func_00447640 (the render callback that
// func_00447E50 installs) with its space, data block and font: builds the italic text's triangle strip in
// CGt2dObject::mgu8RenderBatchData (positions, UVs at +0xFE0) and returns the vertex count [L].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/classes/UnkStruct_D_004E0B14.h"

using namespace GtMathPs2;

extern UnkStruct_D_004E0B14 D_004E0B14;

struct UnkStruct_00447E50_data {
    const unsigned short *field_0;
    float field_4;
    float field_8;
};

// [G] glyph-visible test, as archived func_00447E50's helper
static inline bool func_00447AB0_inl1(UnkStruct_Gt2dFont_Glyph *g)
{
    return !(g->field_0.marValues[0] < 0.0f);
}

// 0x00447AB0
extern "C" int func_00447AB0(const CGt2dObject::CGt2dObjectSpace &space, const UnkStruct_00447E50_data *d, CGt2dFont *font)
{
    const unsigned short *s = d->field_0;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(*s);
    CGtV2d pos = space.mTopLeftPos;
    CGtV2d scl = CGtV2d(font->field_8) * space.mSize;
    CGtV2d tl;
    CGtV2d tr;
    CGtV2d bl;
    CGtV2d br;
    CGtV2d uvtl;
    CGtV2d uvtr;
    CGtV2d uvbl;
    CGtV2d uvbr;
    CGtV2d *verts = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uvs = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    int count = 0;
    float shear = D_004E0B14.field_0 * d->field_4 * space.mSize.marValues[0] / space.mSize.marValues[1];
    float base = space.mTopLeftPos.marValues[1] + space.mSize.marValues[1] * font->field_10;
    scl.marValues[0] = d->field_8 * (d->field_4 * scl.marValues[0]);
    float px = pos.marValues[0] - g->field_10.marValues[0] * scl.marValues[0];
    UnkStruct_Gt2dFont_Glyph *sp = font->UnkInline_FindGlyph(0x20);
    float spacing = -0.2f * (sp->field_18 * scl.marValues[0]);
    for (;;) {
        if (func_00447AB0_inl1(g)) {
            if (count + 5 > 0xFE0 / sizeof(CGtV2d)) return count;
            tl = CGtV2d(px, pos.marValues[1]) + g->field_10 * scl;
            br = tl + scl * g->field_8;
            uvtl = g->field_0;
            uvbr = g->field_0 + g->field_8;
            uvtr.marValues[0] = uvbr.marValues[0];
            uvtr.marValues[1] = uvtl.marValues[1];
            uvbl.marValues[0] = uvtl.marValues[0];
            uvbl.marValues[1] = uvbr.marValues[1];
            float st = shear * (base - tl.marValues[1]);
            float sb = shear * (base - br.marValues[1]);
            tr.marValues[0] = st + br.marValues[0];
            tr.marValues[1] = tl.marValues[1];
            bl.marValues[0] = sb + tl.marValues[0];
            bl.marValues[1] = br.marValues[1];
            tl.marValues[0] = st + tl.marValues[0];
            br.marValues[0] = sb + br.marValues[0];
            if (count > 0) {
                verts[0] = verts[-1];
                uvs[0] = uvs[-1];
                verts[1] = tl;
                uvs[1] = uvtl;
                verts += 2;
                uvs += 2;
                count += 2;
            }
            count += 4;
            verts[0] = tl;
            uvs[0] = uvtl;
            verts[1] = tr;
            uvs[1] = uvtr;
            verts[2] = bl;
            uvs[2] = uvbl;
            verts[3] = br;
            uvs[3] = uvbr;
            verts += 4;
            uvs += 4;
        }
        unsigned short c = *++s;
        if (c == 0) return count;
        px = spacing + (px + g->field_18 * scl.marValues[0]);
        g = font->UnkInline_FindGlyph(c);
    }
}
