// NONMATCHING: _Render__16CB3Panel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 404 / ours 402 instructions, 267 in changed runs
// draftAL C-first: palette colours x object colour, 0.2 Interpolate blend and (cB+cA)*0.5 average, body quad (flag 1: one colour with flags 3 or four tinted corners), two-sprite drop shadow (flag 0x10), bevel of four RenderTriStripGouraudUntex strips (flags 4|0x20; all m+0x120 with 0x20); 402/404, calls identical; CGtV4d operator+ stand-in (E-map API missing from the header, queued)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the corner/bevel vertex sets (q0..q3, the 8 left-strip vertices A..H from +-r1 / +-r2, the reused B/D for the top strip), each colour array, the two shifted offsets (width, height) and every branch sense traced

// CB3Panel2dObject::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAL (C-first draft). 0x380250, 0x650.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm; declarations as the RoundedPanel _Render draft.
// What it draws [L]: a flat panel: the body quad (flag 1; one colour m+0x100 with flags 3, else m+0xC0 x the four corner
// tints D_004C9360..90), a two-sprite drop shadow (flag 0x10: D_004C93A0 x colour, offset by r x data +0xC) and, with flag 4
// or 0x20, a bevelled frame of four gradient strips (left 8 vertices and the same shifted by the width, top and bottom 4)
// in the palette colours (m+0x130 / +0x120, their 0.2 blend and their average; all m+0x120 with flag 0x20). r = data scale x
// object size. Types and field meanings [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00380250_data {            // the object's data block
    CGtV2d field_0;                         // scale (x object size = the bevel size)
    unsigned int field_8;                   // flags
    float field_C;                          // shadow offset (x the bevel size)
};
struct UnkStruct_00380250_m {               // D_01E90240's colour palette (as the RoundedPanel draft)
    unsigned char pad_0[0xC0];
    CGtV4d field_C0;
    unsigned char pad_D0[0x30];
    CGtV4d field_100;
    unsigned char pad_110[0x10];
    CGtV4d field_120;
    CGtV4d field_130;
};
extern UnkStruct_00380250_m D_01E90240;
extern CGtV4d D_004C9360;                   // body corner tints
extern CGtV4d D_004C9370;
extern CGtV4d D_004C9380;
extern CGtV4d D_004C9390;
extern CGtV4d D_004C93A0;                   // shadow colour

class CB3Panel2dObject : public CGt2dObject {
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace &, const void *);
};


// 0x00380250
void CB3Panel2dObject::_Render(const CGt2dObject::CGt2dObjectSpace & space, const void * lpData)
{
    const UnkStruct_00380250_data * data = (const UnkStruct_00380250_data *)lpData;
    UnkStruct_00380250_m * m = &D_01E90240;
    CGtV4d cB = m->field_130 * space.mColour;
    CGtV4d cA = m->field_120 * space.mColour;
    CGtV4d cM = Interpolate(cB, cA, 0.2f);
    CGtV4d cH = (cB + cA) * 0.5f;
    CGtV4d * col = (CGtV4d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d * p = (CGtV2d *)(col + 8);
    CGtV2d * q = p + 8;
    CGtV2d lOffset(0.0f, 0.0f);
    CGtV2d r = data->field_0 * space.mSize;
    q[0].Set(space.mTopLeftPos.X(), space.mTopLeftPos.Y());
    q[1].SetX(space.mTopLeftPos.X());
    q[2].SetY(space.mTopLeftPos.Y());
    CGtV2d lBottomRight = space.mTopLeftPos + space.mSize;
    CGtV2d r1 = r * 1.0f;
    q[3].SetY(lBottomRight.Y());
    q[1].SetY(lBottomRight.Y());
    q[3].SetX(lBottomRight.X());
    q[2].SetX(lBottomRight.X());
    CGtV2d r2 = r1 * CGtV2d(1.0f, -1.0f);
    if (data->field_8 & 1) {
        if ((data->field_8 & 3) == 3) {
            CGtV4d c = m->field_100 * space.mColour;
            for (int i = 0; i < 4; i++)
                col[i] = c;
        } else {
            CGtV4d c = m->field_C0 * space.mColour;
            col[0] = c * D_004C9360;
            col[2] = c * D_004C9380;
            col[1] = c * D_004C9370;
            col[3] = c * D_004C9390;
        }
        Gt2dRenderer::RenderTriStripGouraudUntex(lOffset, 4, q, col);
    }
    if (data->field_8 & 0x10) {
        CGtV2d d = r * data->field_C;
        CGtV2d e = q[3] + d;
        CGtV2d f = q[0] + d;
        p[0].Set(q[2].X(), f.Y());
        p[1] = e;
        p[2].Set(f.X(), q[3].Y());
        p[3].Set(q[2].X(), e.Y());
        Gt2dRenderer::RenderSpritesUntex(D_004C93A0 * space.mColour, lOffset, 2, p);
    }
    if (data->field_8 & 0x20) {
        cB = m->field_120 * space.mColour;
        cA = m->field_120 * space.mColour;
        cM = m->field_120 * space.mColour;
        cH = m->field_120 * space.mColour;
    }
    if (!(data->field_8 & 4) && !(data->field_8 & 0x20))
        return;
    // the bevel: left strip (8 vertices), the same at +width, then the top and bottom strips
    p[0] = q[0] - r1;
    p[1] = q[0] + r2;
    p[2] = q[0] - r2;
    p[3] = q[0] + r1;
    p[4] = q[1] - r1;
    p[5] = q[1] + r2;
    p[6] = q[1] - r2;
    p[7] = q[1] + r1;
    for (int i = 0; i < 4; i++) {
        col[i] = cB;
        col[i + 4] = cM;
    }
    Gt2dRenderer::RenderTriStripGouraudUntex(lOffset, 8, p, col);
    for (int i = 0; i < 4; i++) {
        col[i] = cH;
        col[i + 4] = cA;
    }
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(space.mSize.X(), 0.0f), 8, p, col);
    col[0] = cB;
    col[1] = cB;
    col[2] = cH;
    col[3] = cH;
    p[0] = p[1];
    p[1] = p[3];
    p[2] = q[2] - r1;
    p[3] = q[2] - r2;
    Gt2dRenderer::RenderTriStripGouraudUntex(lOffset, 4, p, col);
    col[0] = cM;
    col[1] = cM;
    col[2] = cA;
    col[3] = cA;
    Gt2dRenderer::RenderTriStripGouraudUntex(CGtV2d(0.0f, space.mSize.Y()), 4, p, col);
}
