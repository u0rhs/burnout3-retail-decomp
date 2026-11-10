// NONMATCHING: SetPos__16CB3Globe2dObjectFQ29GtMathPs26CGtV3d -- retail 13 / ours 13 instructions, 2 in changed runs
// hdrrd: with the header Y() (YAxisType copy as Z/W) no pad object or local asm is needed; left: lwc1 f0,8(sp) scheduled before the sw (2 instrs). Was a202 (4 changed, local sq asm + pad).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
struct F3 { float x, y, z; };
class CB3Globe2dObject {
public:
    void SetPos(GtMathPs2::CGtV3d p0);
    unsigned char pad_0[0x20];
    F3 field_20;
};
void CB3Globe2dObject::SetPos(GtMathPs2::CGtV3d p0)
{
    GtMathPs2::CGtV3d c = p0;
    float y = c.Y(); field_20.x = c.X(); field_20.y = y; float z = c.Z(); field_20.z = z;
}

