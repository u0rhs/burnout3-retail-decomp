// NONMATCHING: _RenderStars__23CB3PositiveIcon2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 145 / ours 145 instructions, 52 in changed runs
// sm9: logic, layout, frame 0xE0, every slot and FPR exact; left: retail keeps os in s3 and the data block in s2 (ours swapped), which reschedules the head loads (52 changed). void*/typed-param/pointer-local levers, sreg run (2 rounds) tried.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

class CGtTexture;
struct UnkStruct_003D5FA0_d { CGtTexture * field_0; float field_4; int field_8; };

extern "C" void _RenderStars__23CB3PositiveIcon2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &os, const void *pv)
{
    CGtV4d col;
    const UnkStruct_003D5FA0_d *d = (const UnkStruct_003D5FA0_d *)pv;
    Gt2dRenderer::SetTexture(d->field_0);
    int n = d->field_8;
    float t;
    CGtV2d c;
    CGtV2d sz;
    CGtV2d T[2];
    CGtV2d V[2];
    T[0].marValues[0] = 0.0f;
    T[0].marValues[1] = 0.0f;
    T[1] = os.mSize;
    V[0].marValues[1] = 0.0f;
    V[0].marValues[0] = 0.0f;
    V[1].marValues[0] = 1.0f;
    V[1].marValues[1] = 1.0f;
    float hx = 0.5f * os.mSize.X();
    CGtV2d half = os.mSize * 0.5f;
    c = os.mTopLeftPos + half;
    c.marValues[0] = c.marValues[0] + hx * (float)n;
    t = d->field_4 - 0.1875f * (float)n;
    do {
        t += 0.1875f;
        c.marValues[0] -= hx;
        if (t > 0.0f) {

            col = os.mColour;
            sz = os.mSize * 0.5f;
            if (t < 0.25f) {
                col.SetA(4.0f * t);
                sz *= 2.5f - 6.0f * t;
                float k = 0.25f - t;
                sz.marValues[0] *= cosf(100.53097f * (k * k));
            }
            T[0] = -sz;
            T[1] = sz;
            Gt2dRenderer::RenderSpritesTex(col, c, 1, T, V);
        }
    } while (--n);
}




