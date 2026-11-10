// NONMATCHING: func_00148DF0 -- retail 212 / ours 212 instructions, 196 in changed runs
// L270: logic + block layout exact (goto form + scoped opt_repositioncode off [G]; sqrt.s via extern C sqrtf intrinsic); left: frame 0x240 vs 0x1D0 -- retail keeps p's x store at 0x218, b2 named at 0x210-0x200, b3/general copies interleaved low (0x130-0x108), so some values are by-value inline args; FPR numbering follows
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (L270): parameter of a 2D point (x/z of a CGtV3d) across a lane quad (inverse bilinear: linear in two
// degenerate cases, else the quadratic root). Vertices: one from D_0064D354's array, three from D_00522660+0x12ACF4's.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV3d;

struct UnkStruct_00148DF0_4 {
    unsigned short * field_0;
};
struct UnkStruct_00148DF0 {
    unsigned char pad_0[0x4];
    UnkStruct_00148DF0_4 * field_4;
};
struct UnkStruct_D_0064D354 {
    CGtV3d * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x10];
};

extern UnkStruct_D_0064D354 D_0064D354;
extern UnkStruct_D_00522660 D_00522660;
extern "C" float sqrtf(float);

// N182 [G] scoped to this function: #pragma opt_repositioncode off
#pragma push
#pragma opt_repositioncode off
// 0x00148DF0
extern "C" float func_00148DF0(UnkStruct_00148DF0 * self, const CGtV3d & pt, unsigned short idx)
{
    unsigned short * e = &self->field_4->field_0[idx * 2];
    CGtV3d * va = D_0064D354.field_0;
    CGtV3d * vb = *(CGtV3d **)((unsigned int)&D_00522660 + 0x12ACF4);
    unsigned short i0 = e[0];
    unsigned short i1 = e[1];
    unsigned short i2 = e[2];
    unsigned short i3 = e[3];
    CGtV2d a(va[i0].X(), va[i0].Z());
    CGtV2d b(vb[i1].X(), vb[i1].Z());
    CGtV2d c(vb[i2].X(), vb[i2].Z());
    CGtV2d d(vb[i3].X(), vb[i3].Z());
    CGtV2d p(pt.X(), pt.Z());
    float r;
    if (i2 == i3) goto lb2;
    if (i0 == i1) goto lb3;
    {
        CGtV2d pa = p - a;
        CGtV2d ab = a - b;
        CGtV2d ba = b - a;
        CGtV2d ca = c - a;
        CGtV2d ee = ab - c + d;
        float qa = ee.marValues[1] * ca.marValues[0] - ee.marValues[0] * ca.marValues[1];
        float qb = ee.marValues[0] * pa.marValues[1] - ee.marValues[1] * pa.marValues[0] - ba.marValues[0] * ca.marValues[1] +
                   ba.marValues[1] * ca.marValues[0];
        float qc = pa.marValues[1] * ba.marValues[0] - pa.marValues[0] * ba.marValues[1];
        float disc = qb * qb - 4.0f * qa * qc;
        float root = sqrtf(disc);
        if (GtMath::Abs(qa) < 0.01f) {
            r = -qc / qb;
        } else {
            r = (-qb + root) / (qa + qa);
        }
    }
out:
    return r;
lb2:
    {
        CGtV2d pa = p - a;
        CGtV2d ba = b - a;
        CGtV2d ca = c - a;
        r = (pa.marValues[1] * ba.marValues[0] - pa.marValues[0] * ba.marValues[1]) /
            (ca.marValues[1] * ba.marValues[0] - ca.marValues[0] * ba.marValues[1]);
    }
    goto out;
lb3:
    {
        CGtV2d pc = p - c;
        CGtV2d ac = a - c;
        CGtV2d dc = d - c;
        r = (pc.marValues[1] * dc.marValues[0] - pc.marValues[0] * dc.marValues[1]) /
            (ac.marValues[1] * dc.marValues[0] - ac.marValues[0] * dc.marValues[1]);
    }
    goto out;
}
#pragma pop
