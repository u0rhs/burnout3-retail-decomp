// NONMATCHING: func_002F9310 -- retail 222 / ours 222 instructions, 71 in changed runs
// L262: logic + frame right (222/222, 0x110 with an N140 8-byte pad after p). Left: loop FPR numbering (retail f0=0,f1/f2=fsc,f3=py,f4=px,f5=x; ours px coalesced with x), retail re-extends c (andi a1,a3) at the loop head, count==0 -> -1 block order.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_002F9310 -- hand-written (L262); the lifter refused it (static member's class CGt2dObject has a header).
// [L] DNAT: CGt2dObjectParagraph::_BuildLineOfText(const CGt2dObject::CGt2dObjectSpace&,const unsigned short**,
// const CGt2dFont*,float,float,...) (research/proto/new_names.csv, high). Parameter order of the int/float
// arguments is [G] (the register assignment does not fix it).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;

// N140 frame-slot pad [G]
struct UnkStruct_002F9310_pad { float x[2]; UnkStruct_002F9310_pad() {} ~UnkStruct_002F9310_pad() {} };

// 0x002F9310
extern "C" int func_002F9310(const CGt2dObject::CGt2dObjectSpace & space, const unsigned short ** text,
                             const CGt2dFont * font, const CGtV2d & scale, unsigned int flags, float size,
                             float maxWidth, float align)
{
    const unsigned short * start;
    const unsigned short * end;
    CGtV2d sc = scale * size;
    float left = space.mTopLeftPos.marValues[0];
    CGtV2d fsc = CGtV2d(font->field_8) * sc;
    CGtV2d * corners = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d * uvs = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    int count = 0;
    CGtV2d p;
    UnkStruct_002F9310_pad pad;
    float width = font->GetStringStartAndEnd(*text, maxWidth, &start, &end, (flags & 0x64) == 0x64);
    *text = end;
    float x = left + align * (space.mSize.marValues[0] - width * sc.marValues[0]);
    unsigned short c = *start;
    if (c == 0) return 0;
    UnkStruct_Gt2dFont_Glyph * g = font->UnkInline_FindGlyph(c);
    float px = x - g->field_10.marValues[0] * fsc.marValues[0];
    float py = space.mTopLeftPos.marValues[1];
    for (;;) {
        if (c == '\n' || c == '\r') {
            if (++start == end) {
                if (count == 0) count = -1;
                return count;
            }
            c = *start;
            g = font->UnkInline_FindGlyph(c);
            continue;
        }
        if (g->field_0.marValues[0] >= 0.0f) {
            count++;
            p = CGtV2d(px, py) + g->field_10 * fsc;
            corners[0] = p;
            uvs[0] = g->field_0;
            corners[1] = p + fsc * g->field_8;
            uvs[1] = g->field_0 + g->field_8;
            corners += 2;
            uvs += 2;
        }
        if (++start == end) return count;
        c = *start;
        px += g->field_18 * fsc.marValues[0];
        g = font->UnkInline_FindGlyph(c);
    }
}
