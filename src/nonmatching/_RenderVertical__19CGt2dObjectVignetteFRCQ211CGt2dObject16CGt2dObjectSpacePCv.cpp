// NONMATCHING: _RenderVertical__19CGt2dObjectVignetteFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 159 / ours 160 instructions, 54 in changed runs
// near35: as _RenderHorizontal (same fixes): frame 0xF0 exact via CGtV4d(top) copy temp, corner before zero, pos[3] first. 160 vs 159. Left: VU numbering of the (col*colour)*(1/255) products (retail colour vf2, in-place vf1, k qmtc2.ni twice vf4/vf3; header operator*(float) pins $vf2) and one 16-byte temp slot at 0x50 in ours vs retail 0xB0 (above pos[])
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: _RenderVertical__19CGt2dObjectVignetteFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 159 / ours 158 instructions, 69 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: retail 159 / ours 158 instrs, frame 240 vs 208: retail keeps an unused 16-byte slot (the N140 UnkStruct_001D6E80_pad local gives frame 224 and hoists the zero-offset stores) plus an lq/sq copy of the first colour to 0xC0 (CGtV4d top; top = CGtV4d(...)); logic: two RGBA byte quads -> CGtV4d (unsigned
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;


extern "C" void _RenderVertical__19CGt2dObjectVignetteFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace& space, const void* data)
{
    const unsigned char* d = (const unsigned char*)data;
    CGtV4d top((float)d[0], (float)d[1], (float)d[2], (float)d[3]);
    CGtV4d bottom((float)d[4], (float)d[5], (float)d[6], (float)d[7]);
    CGtV2d corner = space.mTopLeftPos + space.mSize;
    CGtV2d zero(0.0f, 0.0f);
    CGtV2d pos[4];
    CGtV4d cols[4];
    pos[0] = space.mTopLeftPos;
    pos[3] = corner;
    pos[1].Set(space.mTopLeftPos.marValues[0], pos[3].marValues[1]);
    pos[2].Set(pos[3].marValues[0], space.mTopLeftPos.marValues[1]);
    cols[1] = cols[3] = (bottom * space.mColour) * 0.003921569f;
    cols[0] = cols[2] = (CGtV4d(top) * space.mColour) * 0.003921569f;
    Gt2dRenderer::RenderTriStripGouraudUntex(zero, 4, pos, cols);
}
