// NONMATCHING: _BuildBatchData__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 143 / ours 135 instructions, 148 in changed runs
// a95: logic right, far in codegen (143 vs 133-145 instrs, ~148 changed). Glyph batch builder: per-glyph CGtV2d temporaries each ld/sd-copied into named 8-byte locals (retail slots 0x38 uv1, 0x40 size*scale, 0x48 corner1, 0x50 off*scale, 0x58 corner0 tmp, 0x60 dead copy of font.field_8, 0x68 origin(0,0) (adda.s zero,x), 0x70 corner0, 0x78 scale), frame 128. Left: loop layout (retail rotates the loop: next-glyph search exit loads uv.x for the test; 'a0=1; c.lt; xori; beqz' bool form for uv.x<0), temp slots, madd/msub operand regs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectText_data {
    const CGt2dFont *field_0;
    const unsigned short *field_4;
    float field_8;
};

extern "C" int _BuildBatchData__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_Gt2dObjectText_data *d = (const UnkStruct_Gt2dObjectText_data *)data;
    const CGt2dFont *font = d->field_0;
    const unsigned short *s = d->field_4;
    CGtV2d scale;
    CGtV2d c0;
    CGtV2d origin(0.0f, 0.0f);
    CGtV2d fs;
    CGtV2d p;
    CGtV2d offs;
    CGtV2d c1;
    CGtV2d sz;
    CGtV2d uv1;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(*s);
    fs = font->field_8;
    scale = font->field_8 * space.mSize;
    float k = d->field_8 * scale.marValues[0];
    float x = origin.marValues[0] + space.mTopLeftPos.marValues[0] - g->field_10.marValues[0] * k;
    float y = space.mTopLeftPos.marValues[1];
    CGtV2d *corners = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uvs = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    int n = 0;
    CGtV2d scale2(k, scale.marValues[1]);
    for (;;) {
        if (!(g->field_0.marValues[0] < 0.0f)) {
            offs = g->field_10 * scale2;
            p = CGtV2d(x, y) + offs;
            c0 = p;
            corners[0] = p;
            uvs[0] = g->field_0;
            sz = g->field_8 * scale2;
            c1 = c0 + sz;
            corners[1] = c1;
            uv1 = g->field_0 + g->field_8;
            uvs[1] = uv1;
            corners += 2;
            uvs += 2;
            n++;
        }
        unsigned short c = *++s;
        if (c == 0) break;
        float advance = g->field_18;
        g = font->UnkInline_FindGlyph(c);
        x += advance * k;
    }
    return n;
}
