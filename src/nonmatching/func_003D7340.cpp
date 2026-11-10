// NONMATCHING: func_003D7340 -- retail 221 / ours 222 instructions, 156 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a83: 222/221 instrs; text batch builder adapted from the CB3ScrollingText2dObject draft (skip=!(u>=0) bool, cell init/size assign, advance after the join vertex, no u<0 break); remaining = register numbering (font in t2/glyph t0, 25.0f in t1 in retail; ours t1/v0) and scheduling of the bottom/slant 
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003D7340 -- CGt2dObjectComboText::_BuildBatchData(const CGtV2d&, const CGtV2d&, const unsigned short*, const CGt2dObjectSpace&) [L] DNAT
// (research/proto/new_names.csv, medium). Static member (no this). Twin of CB3ScrollingText2dObject::_BuildBatchData (B3HelpBarComponent_0031C5D0).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using GtMathPs2::CGtV2d;
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };

// [L] DNAT: CGt2dObjectComboText::_BuildBatchData (research/proto/new_names.csv, medium)
// 0x003D7340
extern "C" int func_003D7340(const CGtV2d &scale, const CGtV2d &cursor0, const unsigned short *s, const CGt2dObject::CGt2dObjectSpace &space, void *t0 /* passed by every caller, not read here */)
{
    CGtV2d cursor = cursor0;
    CGt2dFont *font = D_00665ED0.pFont;
    unsigned short c = *s;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(c);
    CGtV2d size;
    CGtV2d fontScale = font->field_8;
    CGtV2d cell = fontScale * scale;
    float bottom = space.mTopLeftPos.marValues[1] + space.mSize.marValues[1];
    float slant = 0.36f * scale.marValues[0];
    size = cell * 25.0f;
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    unsigned int n = 0;
    for (;;) {
        bool skip = !(g->field_0.marValues[0] >= 0.0f);
        if (!skip) {
            if (n + 5 >= 0x1FD)
                break;
            n += 5;
            pos[3] = cursor + g->field_10 * size;
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
        c = *++s;
        if (c == 0)
            break;
        pos[0] = pos[-1];
        uv[0] = uv[-1];
        pos++;
        uv++;
        n++;
        cursor.marValues[0] = cursor.marValues[0] + g->field_18 * size.marValues[0];
        g = D_00665ED0.pFont->UnkInline_FindGlyph(c);
    }
    return n;
}
