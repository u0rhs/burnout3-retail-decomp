// NONMATCHING: func_003A6CC0 -- retail 71 / ours 72 instructions, 79 in changed runs
// ghvu1: 72 vs 71 instrs, 79 changed; frame 0x110 exact, colours (CGtV4d * CGtV4d(1,1,1,a)) right; left: float store scheduling/forwarding of the CGtV2d position/uv arrays (retail stores p[3]/uv[3] through an address register and reloads [3].y for [1].y).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003A6CC0 -- hand-written (ghvu1, Ghidra-draft trial). Unnamed: placeholder with C linkage. [L] a 2d-object render
// callback (static; a0 = the object, a1 = its by-value object space, as the Prepare callbacks of func_003A6E80).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_003A6CC0 { CGtV2d field_0; CGtV2d field_8; CGtV4d field_10; };
struct UnkStruct_003A6CC0_s { float field_0; float field_4; float field_8; float field_C; float field_10; float field_14; };
extern "C" void RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d(const CGtV2d &, int, const CGtV2d *, const CGtV2d *, const CGtV4d *);
// 0x003A6CC0
extern "C" void func_003A6CC0(const UnkStruct_003A6CC0 &o, const UnkStruct_003A6CC0_s &s)
{
    CGtV2d p[4];
    CGtV2d uv[4];
    CGtV4d c[4];
    CGtV2d br = o.field_0 + o.field_8;
    p[0].marValues[0] = o.field_0.marValues[0];
    p[0].marValues[1] = o.field_0.marValues[1];
    p[3] = br;
    p[1].marValues[0] = o.field_0.marValues[0];
    p[1].marValues[1] = p[3].marValues[1];
    p[2].marValues[0] = p[3].marValues[0];
    p[2].marValues[1] = o.field_0.marValues[1];
    uv[0].marValues[0] = s.field_0;
    uv[0].marValues[1] = s.field_4;
    uv[3] = CGtV2d(s.field_8, s.field_C);
    uv[1].marValues[0] = s.field_0;
    uv[1].marValues[1] = uv[3].marValues[1];
    uv[2].marValues[0] = uv[3].marValues[0];
    uv[2].marValues[1] = s.field_4;
    c[0] = o.field_10 * CGtV4d(1.0f, 1.0f, 1.0f, s.field_10);
    c[1] = o.field_10 * CGtV4d(1.0f, 1.0f, 1.0f, s.field_14);
    c[2] = c[0];
    c[3] = c[1];
    RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d(CGtV2d(0.0f, 0.0f), 4, p, uv, c);
}
