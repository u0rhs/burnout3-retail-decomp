// NONMATCHING: NearestPointOnHull__16CB3VehicleDeformFP13CB3ConvexHullPQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d -- retail 92 / ours 95 instructions, 64 in changed runs
// v241: logic right (face loop over CB3ConvexHull index triples + normals, NearestPointOnTriangle, header operator- + parked-1.0 sqlen, sqrt.s of the best, returns FLT_MAX when none); left: retail copies the by-value args in order n,a,b,c and passes the entry copy of pos without a second copy (frame 0xF0 vs 0x110), counters s2=i,s1=idx,s0=n, found-block inline (ours out of line)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3ConvexHull;
extern "C" float sqrtf(float);
struct UnkStruct_003DAA70_1 {
    unsigned char * field_0;
    CGtV3d * field_4;
    unsigned char pad_8[0x11];
    unsigned char field_19;
};

static inline u_long128 v241_one() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
// [L] N185: GetSquaredLength with the 1.0 parked in a GPR (retail's usual non-hoisted form, N191)
static inline float v241_sqlen(CGtV3d v)
{
    u_long128 one = v241_one();
    u_long128 m, d;
    asm("vmul.xyz %0, %1, %1" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(v.mData));
    u_long128 w;
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    return XAxisType(d);
}

class CB3VehicleDeform {
public:
    static float NearestPointOnHull(CB3ConvexHull * hull, CGtV3d * verts, CGtV3d pos, CGtV3d * out);
    static bool NearestPointOnTriangle(CGtV3d p, CGtV3d a, CGtV3d b, CGtV3d c, CGtV3d n, float maxd, CGtV3d * out);
};

// 0x003DAA70
float CB3VehicleDeform::NearestPointOnHull(CB3ConvexHull * hull, CGtV3d * verts, CGtV3d pos, CGtV3d * out)
{
    CGtV3d pc = pos;
    const UnkStruct_003DAA70_1 * h = (const UnkStruct_003DAA70_1 *)hull;
    float best = 3.4028235e38f;
    CGtV3d bestPt;
    unsigned char * idx = h->field_0;
    CGtV3d * n = h->field_4;
    for (int i = 0; i < h->field_19; i++) {
        CGtV3d pt;
        if (NearestPointOnTriangle(pc, verts[idx[0]], verts[idx[1]], verts[idx[2]], *n, best, &pt)) {
            float d = v241_sqlen(pc - pt);
            if (d < best) {
                bestPt = pt;
                best = d;
            }
        }
        idx += 3;
        n++;
    }
    if (best < 3.4028235e38f) {
        float r = sqrtf(best);
        *out = bestPt;
        return r;
    }
    return 3.4028235e38f;
}
