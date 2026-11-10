// NONMATCHING: func_0043DE60 -- retail 103 / ours 104 instructions, 21 in changed runs
// near22: madd fusion removed (p.x = cw*tx; p.x += tl.x) -> 21. Left: retail loads mTopLeftPos.y at the loop-body top, stores p0.y through addiu v1,sp,0xBC (pointer form) and schedules the zero-vector sw's into the mtc1/cvt gap (ours a nop); f0/f1 numbering of the tx/ty conversions. A float *py / ly local did not reproduce it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
using namespace GtMathPs2;
struct UnkStruct_D_01EA4658 { CGtTexture *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0043DE60 {
    unsigned char pad_0[8];
    signed char field_8[4];
    signed char field_C;
};
extern UnkStruct_D_01EA4658 D_01EA4658;
union U2 { unsigned long l; struct { float x, y; } f; };
extern const CGtV2d D_004D2010[];
extern const CGtV2d D_004D2030[];

extern "C" void func_0043DE60(const CGt2dObject::CGt2dObjectSpace * space, const UnkStruct_0043DE60 * d)
{
    Gt2dRenderer::SetTexture(D_01EA4658.field_0);
    float cw = space->mSize.marValues[0] / 6.0f;
    float ch = space->mSize.marValues[1] / (float)d->field_C;
    int n = 0;
    int k;
    for (k = 3; k >= 0; k--) {
        CGtV2d corners[2];
        CGtV2d uvs[2];
        uvs[0] = D_004D2010[k];
        uvs[1] = D_004D2030[k];
        for (int j = 0; j < d->field_8[k]; j++) {
            U2 p0; U2 q; CGtV2d zero(0.0f, 0.0f); U2 p1;
            float tx = (float)(n % 6);
            p0.f.x = cw * tx;
            p0.f.x += space->mTopLeftPos.marValues[0];
            p1.f.x = p0.f.x + cw;
            float ty = (float)(n / 6);
            p0.f.y = ch * ty;
            p0.f.y += space->mTopLeftPos.marValues[1];
            p1.f.y = p0.f.y + ch;
            *(unsigned long *)&corners[0] = p0.l;
            q.l = p1.l;
            corners[1].marValues[0] = q.f.x;
            corners[1].marValues[1] = q.f.y;
            Gt2dRenderer::RenderSpritesTex(space->mColour, zero, 1, corners, uvs);
            n++;
        }
    }
}
