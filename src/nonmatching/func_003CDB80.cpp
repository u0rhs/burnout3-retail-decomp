// NONMATCHING: func_003CDB80 -- retail 326 / ours 331 instructions, 360 in changed runs
// L286: [L] DNAT CB3StylisedText2dObject::_BuildBatchData (static). Logic complete from the asm: dead first FindGlyph, space-glyph advance -0.2f, \\1..\\3 style escapes (s[1]-'1') indexing D_004A5220/D_004A5230, sheared 4-vertex quads + 2-vertex strip connector, n < 503 cap, returns n. 331/326, ~360 changed. Retail frame 0x100: temps 0x18-0x5C (size, sc, P0=base+off, P3, UV3, loop sc, off, base, sz), named P0..P3 at 0xE8..0xD0, UV0..UV3 at 0xC8..0xB0, fontScale 0xA0, base 0x88, off 0x80, sz 0x70; the n>0 connector block is inline (blez), shears are mul+add (no madd: s0 = slant*(half-P0.y); P.x = s0 + P.x), only f20 saved. Sibling archives (Text/ComboText/BoostBar _BuildBatchData) are equally far.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [L] DNAT: CB3StylisedText2dObject::_BuildBatchData(const CGtV2d&, const CB3StylisedText2dObjectData&)
// (research/proto/new_names.csv, medium). Static member (no this).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_003CDB80_data {
    CGt2dFont *field_0;
    const unsigned short *field_4;
    float field_8;
    unsigned char pad_C[0x7];
    unsigned char field_13;
    float field_14;
};
extern float D_004A5220[4];
extern float D_004A5230[4];

// 0x003CDB80
extern "C" int func_003CDB80(const CGtV2d &scale, const UnkStruct_003CDB80_data &d)
{
    CGtV2d size;
    CGtV2d sc;
    CGtV2d P0;
    CGtV2d P1;
    CGtV2d P2;
    CGtV2d P3;
    CGtV2d UV0;
    CGtV2d UV1;
    CGtV2d UV2;
    CGtV2d UV3;
    const unsigned short *s = d.field_4;
    CGt2dFont *font = d.field_0;
    unsigned short c = *s;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(c);
    float slant = 0.4f * d.field_8 * scale.marValues[0] / scale.marValues[1];
    float half = 0.5f * scale.marValues[1];
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    unsigned int n = 0;
    UnkStruct_Gt2dFont_Glyph *sp = font->UnkInline_FindGlyph(0x20);
    CGtV2d fontScale = font->field_8;
    size = fontScale * scale;
    float spadv = -0.2f * sp->field_18;
    float w = d.field_14 * (d.field_8 * size.marValues[0]);
    int idx = 3;
    if (c == 0x5C && d.field_13 == 0) {
        idx = s[1] - 0x31;
        s += 2;
    }
    float ox = 0.0f;
    float yoff = scale.marValues[1] * (0.0f + D_004A5230[idx] + (1.0f - D_004A5220[idx]) * font->field_10);
    sc = CGtV2d(w, size.marValues[1]) * D_004A5220[idx];
    g = font->UnkInline_FindGlyph(*s);
    float x = -g->field_10.marValues[0] * sc.marValues[0];
    while (n < 0x1F7) {
        if (!(g->field_0.marValues[0] < 0.0f)) {
            CGtV2d base = CGtV2d(x + ox, 0.0f + yoff);
            CGtV2d off = g->field_10 * sc;
            UV0 = g->field_0;
            CGtV2d sz = sc * g->field_8;
            UV3 = g->field_0 + g->field_8;
            P0 = base + off;
            P3 = P0 + sz;
            P1.Set(P3.marValues[0], P0.marValues[1]);
            P2.Set(P0.marValues[0], P3.marValues[1]);
            UV1.Set(UV3.marValues[0], UV0.marValues[1]);
            UV2.Set(UV0.marValues[0], UV3.marValues[1]);
            P0.marValues[0] = P0.marValues[0] + slant * (half - P0.marValues[1]);
            P1.marValues[0] = P1.marValues[0] + slant * (half - P1.marValues[1]);
            P2.marValues[0] = P2.marValues[0] + slant * (half - P2.marValues[1]);
            P3.marValues[0] = P3.marValues[0] + slant * (half - P3.marValues[1]);
            if (n > 0) {
                pos[0] = pos[-1];
                uv[0] = uv[-1];
                pos[1] = P0;
                uv[1] = UV0;
                n += 2;
                pos += 2;
                uv += 2;
            }
            n += 4;
            pos[0] = P0;
            uv[0] = UV0;
            pos[1] = P1;
            uv[1] = UV1;
            pos[2] = P2;
            uv[2] = UV2;
            pos[3] = P3;
            uv[3] = UV3;
            pos += 4;
            uv += 4;
        }
        c = *++s;
        if (c == 0)
            return n;
        float a = g->field_18 + spadv;
        if (g->field_0.marValues[0] < 0.0f && s[1] == 0x5C)
            a *= 0.5f;
        x = 0.0f + x + a * sc.marValues[0];
        if (c == 0x5C && d.field_13 == 0) {
            idx = s[1] - 0x31;
            s += 2;
            ox = 0.0f;
            yoff = scale.marValues[1] * (0.0f + D_004A5230[idx] + (1.0f - D_004A5220[idx]) * font->field_10);
            sc = CGtV2d(w, size.marValues[1]) * D_004A5220[idx];
        }
        g = font->UnkInline_FindGlyph(*s);
    }
    return n;
}
