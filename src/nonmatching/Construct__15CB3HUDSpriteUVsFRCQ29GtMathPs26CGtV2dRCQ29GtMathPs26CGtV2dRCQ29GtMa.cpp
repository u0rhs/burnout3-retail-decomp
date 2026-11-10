// NONMATCHING: Construct__15CB3HUDSpriteUVsFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi -- retail 59 / ours 59 instructions, 8 in changed runs
// near11: archive had drifted to 16 off under the 8-aligned CGtV2d header (struct copy-out became ld/sd); copy-out through a 4-float struct pun restores retail's lwc1/swc1 (8 off). Left: FP numbering of the y-component loads (retail p2.y,p1.y,p0.y = f4,f0,f2; ours p0.y,p2.y,p1.y); operator/ stand-ins, non-const u, named p1/p2 tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



// CB3HUDSpriteUVs::Construct(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3HUDSpriteUVs;

class CB3HUDSpriteUVs {
public:
    void Construct(const GtMathPs2::CGtV2d& p0, const GtMathPs2::CGtV2d& p1, const GtMathPs2::CGtV2d& p2, unsigned int p3);

    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_0019FE40_loc { GtMathPs2::CGtV2d uv0; GtMathPs2::CGtV2d uv1; };
struct UnkStruct_0019FE40_f4 { float f[4]; };

// 0x0019FE40
void CB3HUDSpriteUVs::Construct(const GtMathPs2::CGtV2d& p0, const GtMathPs2::CGtV2d& p1, const GtMathPs2::CGtV2d& p2, unsigned int p3)
{
    UnkStruct_0019FE40_loc L;
    const GtMathPs2::CGtV2d u = p0 / p2;
    L.uv0 = u;
    GtMathPs2::CGtV2d e = L.uv0 + p1 / p2;
    { GtMathPs2::CGtV2d *q = &L.uv1;
    q->Set(e.X(), e.Y());
    if ((p3 & 1) != 0) {
        q->SetX(L.uv0.X());
        L.uv0.SetX(e.X());
    }
    if ((p3 & 2) != 0) {
        float t = L.uv0.Y();
        L.uv0.SetY(L.uv1.Y());
        L.uv1.SetY(t);
    }
    }
    *(UnkStruct_0019FE40_f4 *)&field_0 = *(UnkStruct_0019FE40_f4 *)&L;
}

