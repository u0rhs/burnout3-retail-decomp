// NONMATCHING: Construct__14CB3HUDImageUVsFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d -- retail 54 / ours 50 instructions, 30 in changed runs
// psweep: scoped #pragma opt_dead_assignments off [G] improves 47 -> 46
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3HUDImageUVs::Construct -- [C] name: retail tables; file B3HUDComponent.cpp (research/retail_names.csv).
#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_dead_assignments off
using namespace GtMathPs2;

class CB3HUDImageUVs {
public:
    void Construct(const CGtV2d& p0, const CGtV2d& p1, const CGtV2d& p2);
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV2d field_10;
    CGtV2d field_18;
};

void CB3HUDImageUVs::Construct(const CGtV2d& p0, const CGtV2d& p1, const CGtV2d& p2)
{
    CB3HUDImageUVs t;
    t.field_0 = p0 / p2;
    t.field_8 = t.field_0 + p1 / p2;
    t.field_10.SetX(t.field_8.X());
    t.field_10.SetY(t.field_0.Y());
    t.field_18.SetX(t.field_0.X());
    t.field_18.SetY(t.field_8.Y());
    field_0.marValues[0] = t.field_0.marValues[0]; field_0.marValues[1] = t.field_0.marValues[1];
    field_8.marValues[0] = t.field_8.marValues[0]; field_8.marValues[1] = t.field_8.marValues[1];
    field_10.marValues[0] = t.field_10.marValues[0]; field_10.marValues[1] = t.field_10.marValues[1];
    field_18.marValues[0] = t.field_18.marValues[0]; field_18.marValues[1] = t.field_18.marValues[1];
}

#pragma pop
