// NONMATCHING: _Render__23CB3RoundedPanel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 590 / ours 593 instructions, 467 in changed runs
// draftAL C-first: corner size from the data scale (x1.9 large), palette colours x object colour (+0x120/+0x130 or +0x150) and their Interpolate midpoint, corner texture by flags 4 / 0x80|0x100, five-piece RenderSpritesTex, left/right/top/bottom RenderTriStripGouraudUntex edge strips (flags 8/0x10, fades 0x20/0x40, extensions 1/2); 593/590, calls identical; textures and corner sizes as unsized arrays (retail lui, not gp)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every batch-buffer store (10 corners, 10 UVs, 4 vertices + 4 colours per strip) traced to its source value, each flag test and branch sense, all 9 calls' argument lists

// CB3RoundedPanel2dObject::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAL (C-first draft). 0x3A2850,
// 0x938. [C] name: the mangled symbol in retail's tables. Written from the retail asm (Ghidra's draft as a reading aid); the data
// block as the proven Prepare (B3RoundedPanel2dObject_003A3190.cpp: +0 the inverse size, +8 / +0xC its two unsigned ints).
// What it draws [L]: a panel with rounded corners: the corner size r = data scale x object size (x 1.9 when the data's +0xC
// is set, the edge offset then half of that), one RenderSpritesTex call for five pieces (top-left corner, left edge, middle,
// right edge, bottom-right corner; corner textures D_01EA46C8..D4 by flags 4 / 0x80|0x100) and up to four gradient edge strips
// (RenderTriStripGouraudUntex: left (flag 8), right (0x10), top, bottom) whose colours are the object colour times the
// palette entries of D_01E90240 (+0x120 / +0x130, or +0x150 twice when +0xC is set) and their midpoint; flags 1 / 2 extend
// the panel by the edge offset at the top-left / bottom-right, 0x20 / 0x40 fade the top and bottom strips, 0x80 takes the
// sprite colour from +0x100. Types and field meanings [G].
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003A2850_data {            // the object's data block (Prepare: 1 / size, then two unsigned ints)
    CGtV2d field_0;
    unsigned int field_8;                   // flags
    unsigned int field_C;                   // [G] "large corners"
};
struct UnkStruct_003A2850_m {               // D_01E90240's colour palette (as used here)
    unsigned char pad_0[0x100];
    CGtV4d field_100;
    unsigned char pad_110[0x10];
    CGtV4d field_120;
    CGtV4d field_130;
    unsigned char pad_140[0x10];
    CGtV4d field_150;
};
extern UnkStruct_003A2850_m D_01E90240;
// [C] retail addresses the textures and the corner sizes with lui/%lo (not $gp): unsized arrays (rules section 5)
extern CGtTexture * D_01EA46C8[];
extern CGtTexture * D_01EA46CC[];
extern CGtTexture * D_01EA46D0[];
extern CGtTexture * D_01EA46D4[];
extern CGtV2d D_004C9D70[];                   // corner piece size (x r), flag 4 clear
extern CGtV2d D_004C9D78[];                   // corner piece size (x r), flag 4 set
extern CGtV2d D_004C9D80[2];                // UV rectangle, edge pieces
extern CGtV2d D_004C9D90[2];                // UV rectangle, top-left corner with flag 1
extern CGtV2d D_004C9DA0[2];                // UV rectangle, bottom-right corner with flag 2

class CB3RoundedPanel2dObject : public CGt2dObject {
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace &, const void *);
};

// 0x003A2850
void CB3RoundedPanel2dObject::_Render(const CGt2dObject::CGt2dObjectSpace & space, const void * lpData)
{
    const UnkStruct_003A2850_data * data = (const UnkStruct_003A2850_data *)lpData;
    UnkStruct_003A2850_m * m = &D_01E90240;
    CGtV4d c0(space.mColour.mData);
    CGtV4d cA = m->field_120 * space.mColour;
    CGtV4d cB = m->field_130 * space.mColour;
    if (data->field_C) {
        cB = m->field_150 * space.mColour;
        cA = m->field_150 * space.mColour;
    }
    CGtV4d cM = Interpolate(cB, cA, 0.5f);
    CGtV2d lOffset(0.0f, 0.0f);
    CGtV2d r = data->field_0 * space.mSize;
    CGtV2d r1 = r * 1.0f;
    CGtV2d r2 = r * 2.0f;
    if (data->field_C) {
        CGtV2d rk = r * 1.9f;
        r2 = r * 1.9f;
        r1 = rk * 0.5f;
    }
    CGtV2d uv;
    if ((data->field_8 & 0x80) || (data->field_8 & 0x100)) {
        if (data->field_8 & 4) {
            uv = D_004C9D78[0] * r;
            Gt2dRenderer::SetTexture(D_01EA46D4[0]);
        } else {
            uv = D_004C9D70[0] * r;
            Gt2dRenderer::SetTexture(D_01EA46D0[0]);
        }
        if (data->field_8 & 0x80) {
            c0 = m->field_100;
            cB = m->field_100;
        } else if (data->field_8 & 0x100) {
            c0 = cB;
        }
    } else {
        if (data->field_8 & 4) {
            uv = D_004C9D78[0] * r;
            Gt2dRenderer::SetTexture(D_01EA46CC[0]);
        } else {
            uv = D_004C9D70[0] * r;
            Gt2dRenderer::SetTexture(D_01EA46C8[0]);
        }
        c0 = cB;
    }

    // five sprites: p[2k], p[2k+1] the corners of piece k; their UVs q[2k], q[2k+1]
    CGtV2d * p = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    if (data->field_8 & 1)
        p[0] = space.mTopLeftPos - r1;
    else
        p[0] = space.mTopLeftPos;
    p[1] = p[0] + uv;
    if (data->field_8 & 2)
        p[9] = space.mTopLeftPos + space.mSize + r1;
    else
        p[9] = space.mTopLeftPos + space.mSize;
    CGtV2d t3 = p[9] - uv;
    p[2].Set(space.mTopLeftPos.X(), p[1].Y());
    p[3].Set(p[1].X(), space.mTopLeftPos.Y() + space.mSize.Y());
    p[4].Set(p[1].X(), space.mTopLeftPos.Y());
    p[5].Set(t3.X(), space.mTopLeftPos.Y() + space.mSize.Y());
    p[6].Set(t3.X(), space.mTopLeftPos.Y());
    p[7].Set(space.mTopLeftPos.X() + space.mSize.X(), t3.Y());
    p[8] = t3;
    CGtV2d * q = p + 10;
    if (data->field_8 & 1) {
        q[0] = D_004C9D90[0];
        q[1] = D_004C9D90[1];
    } else {
        q[0] = D_004C9D80[0];
        q[1] = D_004C9D80[1];
    }
    q[2] = D_004C9D80[0];
    q[3] = D_004C9D80[1];
    q[4] = D_004C9D80[0];
    q[5] = D_004C9D80[1];
    q[6] = D_004C9D80[0];
    q[7] = D_004C9D80[1];
    if (data->field_8 & 2) {
        q[8] = D_004C9DA0[0];
        q[9] = D_004C9DA0[1];
    } else {
        q[8] = D_004C9D80[0];
        q[9] = D_004C9D80[1];
    }
    Gt2dRenderer::RenderSpritesTex(c0, lOffset, 5, p, q);

    // gradient edge strips: 4 vertices v[], colours col[]
    CGtV2d * v = q + 10;
    CGtV4d * col = (CGtV4d *)(v + 4);
    if (data->field_8 & 8) {
        if (data->field_8 & 1)
            v[0].Set(p[2].X() - r1.X(), p[2].Y());
        else
            v[0].Set(p[2].X() - r1.X(), p[0].Y() - r1.Y());
        v[1].Set(v[0].X(), p[3].Y() + r1.Y());
        v[2].Set(v[0].X() + r2.X(), v[0].Y());
        v[3].Set(v[0].X() + r2.X(), p[3].Y() + r1.Y());
        col[0] = cB;
        col[1] = cA;
        col[2] = cB;
        col[3] = cA;
        Gt2dRenderer::RenderTriStripGouraudUntex(lOffset, 4, v, col);
    }
    if (data->field_8 & 0x10) {
        v[0].Set(p[7].X() - r1.X(), p[6].Y() - r1.Y());
        if (data->field_8 & 2)
            v[1].Set(v[0].X(), p[7].Y());
        else
            v[1].Set(v[0].X(), p[9].Y() + r1.Y());
        v[2].Set(v[0].X() + r2.X(), v[0].Y());
        v[3].Set(v[0].X() + r2.X(), v[1].Y());
        col[0] = cA;
        col[1] = cB;
        col[2] = cA;
        col[3] = cB;
        Gt2dRenderer::RenderTriStripGouraudUntex(lOffset, 4, v, col);
    }
    v[0].Set(p[7].X() + r1.X(), p[6].Y() - r1.Y());
    if (data->field_8 & 1)
        v[1].Set(p[4].X(), v[0].Y());
    else
        v[1].Set(p[0].X(), v[0].Y());
    v[2].Set(v[0].X(), v[0].Y() + r2.Y());
    v[3].Set(v[1].X(), v[0].Y() + r2.Y());
    if (data->field_8 & 0x20) {
        col[0] = cA;
        col[1] = cM;
        col[2] = cA;
        col[3] = cM;
    } else if (data->field_8 & 0x40) {
        col[0] = cM;
        col[1] = cB;
        col[2] = cM;
        col[3] = cB;
    } else {
        col[0] = cA;
        col[1] = cB;
        col[2] = cA;
        col[3] = cB;
    }
    Gt2dRenderer::RenderTriStripGouraudUntex(lOffset, 4, v, col);
    if (data->field_8 & 2)
        v[0].Set(p[5].X(), p[5].Y() - r1.Y());
    else
        v[0].Set(p[9].X() + r1.X(), p[9].Y() - r1.Y());
    v[1].Set(p[2].X() - r1.X(), v[0].Y());
    v[2].Set(v[0].X(), v[0].Y() + r2.Y());
    v[3].Set(v[1].X(), v[0].Y() + r2.Y());
    if (data->field_8 & 0x20) {
        col[0] = cB;
        col[1] = cM;
        col[2] = cB;
        col[3] = cM;
    } else if (data->field_8 & 0x40) {
        col[0] = cM;
        col[1] = cA;
        col[2] = cM;
        col[3] = cA;
    } else {
        col[0] = cB;
        col[1] = cA;
        col[2] = cB;
        col[3] = cA;
    }
    Gt2dRenderer::RenderTriStripGouraudUntex(lOffset, 4, v, col);
}
