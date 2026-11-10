// NONMATCHING: _BuildBatchData__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 217 / ours 217 instructions, 35 in changed runs
// L259: logic, length (217/217) and frame slots exact; loop body and tail identical. Left (35): prologue only -- float register numbering/scheduling of the slant/scale setup (retail field_8 f9, size.y f10, font.x f8 kept live past the mul so the CGtV2d(font->field_8) copy stores land late; retail loads d->field_0 into t2 then reloads it into t1). Key shapes: N140 8-byte pad after scale (stands in for retail's unused slot at 0x60), x += adv*k before the next lookup, corner copies via Set(x,y) (right-to-left loads), 'bool e = uv.x >= 0.0f; if (e)', float bottom declared before slant. Same family as the archived Text::_BuildBatchData and func_004392D0.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CGt2dObjectItalicText::_BuildBatchData(const CGt2dObject::CGt2dObjectSpace&,const void*) -- hand-written (L259).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> Gt2dObjectItalicText.cpp.
// Area not evidenced, so _unclassified/. Structs carry only the touched fields; every type is [G].
// Builds one 5-vertex tri-strip quad per drawable glyph (plus a repeated joining vertex between glyphs),
// sheared by the italic slant; returns the vertex count (capped below 0x1FD).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectItalicText_bdata {
    const CGt2dFont *field_0;
    const unsigned short *field_4;
    float field_8;
};

struct UnkStruct_0033D010_pad { int x[2]; UnkStruct_0033D010_pad() {} ~UnkStruct_0033D010_pad() {} };

extern "C" int _BuildBatchData__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_Gt2dObjectItalicText_bdata *d = (const UnkStruct_Gt2dObjectItalicText_bdata *)data;
    const unsigned short *s = d->field_4;
    UnkStruct_Gt2dFont_Glyph *g = d->field_0->UnkInline_FindGlyph(*s);
    float bottom;
    float slant = 0.6f * d->field_8 * space.mSize.marValues[0] / (2.0f * space.mSize.marValues[1]);
    CGtV2d scale = CGtV2d(d->field_0->field_8) * space.mSize;
    UnkStruct_0033D010_pad pad;  // [G] N140 frame slot
    CGtV2d scale2;
    CGtV2d p;
    CGtV2d c2;
    CGtV2d uv1;
    CGtV2d *corners = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uvs = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    unsigned int n = 0;
    bottom = space.mTopLeftPos.marValues[1] + space.mSize.marValues[1];
    float k = d->field_8 * scale.marValues[0];
    float x = space.mTopLeftPos.marValues[0] - g->field_10.marValues[0] * k;
    float y = space.mTopLeftPos.marValues[1];
    scale2.Set(k, scale.marValues[1]);
    for (;;) {
        bool e = g->field_0.marValues[0] >= 0.0f;
        if (e) {
            if (!(n + 5 < 0x1FD)) return n;
            n += 5;
            p = CGtV2d(x, y) + g->field_10 * scale2;
            corners[3] = p;
            uvs[3] = g->field_0;
            c2 = corners[3] + scale2 * g->field_8;
            corners[2] = c2;
            uv1 = g->field_0 + g->field_8;
            uvs[2] = uv1;
            corners[1].Set(corners[3].marValues[0], corners[2].marValues[1]);
            uvs[1].Set(uvs[3].marValues[0], uvs[2].marValues[1]);
            corners[4].Set(corners[2].marValues[0], corners[3].marValues[1]);
            uvs[4].Set(uvs[2].marValues[0], uvs[3].marValues[1]);
            corners[1].marValues[0] += slant * (bottom - corners[1].marValues[1]);
            corners[2].marValues[0] += slant * (bottom - corners[2].marValues[1]);
            corners[3].marValues[0] += slant * (bottom - corners[3].marValues[1]);
            corners[4].marValues[0] += slant * (bottom - corners[4].marValues[1]);
            corners[0] = corners[1];
            uvs[0] = uvs[1];
            corners += 5;
            uvs += 5;
        }
        if (*++s == 0) return n;
        if (!(n + 1 < 0x1FD)) return n;
        n += 1;
        corners[0] = corners[-1];
        corners++;
        uvs[0] = uvs[-1];
        uvs++;
        x += g->field_18 * k;
        g = d->field_0->UnkInline_FindGlyph(*s);
    }
}
