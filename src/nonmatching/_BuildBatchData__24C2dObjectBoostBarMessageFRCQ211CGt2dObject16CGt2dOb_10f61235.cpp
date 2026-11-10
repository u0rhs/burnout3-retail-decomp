// NONMATCHING: _BuildBatchData__24C2dObjectBoostBarMessageFRCQ211CGt2dObject16CGt2dObjectSpaceRCQ29GtMathPs26CGtV2dPCQ224C2dObjectBoostBarMessage28C2dObjectBoostBarMessageData -- retail 163 / ours 164 instructions, 99 in changed runs
// L261: logic, block layout and frame slots exact (size = CGtV2d(font->field_8) * scale * 26.0f; assigned locals reserve retail's dead temps; off.x *= size.x avoids msub). Left (99 in changed runs, 164/163): FPR colouring -- retail keeps the 0.0 constant in f0 (ours f1, costing one size.x reload) -- the font-scale temp's y-before-x stores, and a v1/a3 swap for uv/glyph. Sibling func_00382200 (same shape with flags 0x20/0x40) unattempted
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

struct UnkStruct_001A6000_msg {
    unsigned char pad_0[4];
    const unsigned short *field_4;
};

struct UnkStruct_001A6000_quad {
    CGtV2d field_0;
    CGtV2d field_8;
};

class C2dObjectBoostBarMessage {
public:
    struct C2dObjectBoostBarMessageData {
        UnkStruct_001A6000_msg *field_0;
    };
    static int _BuildBatchData(const CGt2dObject::CGt2dObjectSpace &space, const CGtV2d &scale,
                               const C2dObjectBoostBarMessageData *data);
};

int C2dObjectBoostBarMessage::_BuildBatchData(const CGt2dObject::CGt2dObjectSpace &space, const CGtV2d &scale,
                                              const C2dObjectBoostBarMessageData *data)
{
    int n = 0;
    const unsigned short *s = data->field_0->field_4;
    CGt2dFont *font = D_00665ED0.pFont;
    UnkStruct_001A6000_quad *uv = (UnkStruct_001A6000_quad *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    UnkStruct_001A6000_quad *pos = (UnkStruct_001A6000_quad *)CGt2dObject::mgu8RenderBatchData;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(*s);
    CGtV2d cursor;
    CGtV2d size;
    CGtV2d p;
    size = CGtV2d(font->field_8) * scale * 26.0f;
    CGtV2d off(g->field_10.marValues[0], 0.0f);
    off.marValues[0] *= size.marValues[0];
    cursor = space.mTopLeftPos - off;
    for (;;) {
        bool skip = !(g->field_0.marValues[0] >= 0.0f);
        if (!skip) {
            n++;
            p = cursor + g->field_10 * size;
            pos->field_0 = p;
            uv->field_0 = g->field_0;
            pos->field_8 = p + size * g->field_8;
            uv->field_8 = g->field_0 + g->field_8;
            pos++;
            uv++;
        }
        unsigned short c = *++s;
        if (c == 0)
            break;
        cursor.marValues[0] = cursor.marValues[0] + g->field_18 * size.marValues[0];
        g = D_00665ED0.pFont->UnkInline_FindGlyph(c);
    }
    return n;
}
