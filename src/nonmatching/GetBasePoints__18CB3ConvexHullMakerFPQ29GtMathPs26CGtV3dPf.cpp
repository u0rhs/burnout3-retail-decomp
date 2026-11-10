// NONMATCHING: GetBasePoints__18CB3ConvexHullMakerFPQ29GtMathPs26CGtV3dPf -- retail 321 / ours 327 instructions, 562 in changed runs
// draftAN fork B C-first: four bottom corners at the lowest y of points 0/4/8/12/16/20 with the outermost x/z of each corner's points (Min/Max chains as retail's min.s/max.s order), the 0-1 / 2-3 edges shifted in x along (1,0,0) by Min(0,d) / Max(0,d) so they clear points 8 / 12, top corners = copies with y = point y + height[k], raised to at least D_004E0CD0 (0.05) above the bottom; 327/321, calls identical (none), lane ops written as scalar float reads where retail uses VU lane ops (same values)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every min.s/max.s operand pair, the two edge offsets' operand order ((x0 - p.x) + dx * (p.z - z0) / dz), the in-place xyz subtract keeping out[] w, the copies and the height loop traced

// CB3ConvexHullMaker::GetBasePoints(GtMathPs2::CGtV3d*, float*) -- draftAN fork B (C-first draft). 0x3D9740, 0x504.
// [C] name: the mangled symbol in retail's tables; class header include/b3/classes/CB3ConvexHullMaker.h (field_0 = the vertex array
// MakeConvexHull stores; read here as 16-byte CGtV3d points). Caller: the proven MakeConvexHull (0x3D8D60), out = its 0xC0-byte local.
// What it does [L]: from the source points (indices 0,2,4,6,8,12,16,18,20,22,28,30) builds an 8-point base box: four bottom corners
// at the lowest y of points 0/4/8/12/16/20 (x/z the outermost of each corner's points), the 0-1 and 2-3 edges pushed out in x so the
// line through them clears point 8 (Min(0, d)) / point 12 (Max(0, d)), then four top corners (copies, y = point y + height[k]) raised
// to at least D_004E0CD0 (0.05) above the bottom. Types and field meanings [G]; no Revenge counterpart.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/classes/CB3ConvexHullMaker.h"
using namespace GtMathPs2;

extern float D_004E0CD0;                    // [C] 0.05 (0x3D4CCCCD), gp-relative variable: minimum box height

// [G] in-place lane-xyz subtract (retail `vsub.xyz` into the loaded out[] quad, its w kept)
static inline void func_003D9740_inl1(CGtV3d &a, const CGtV3d &b)
{
    asm("vsub.xyz %0, %0, %1" : "+j"(a.mData) : "j"(b.mData));
}

// 0x003D9740
void CB3ConvexHullMaker::GetBasePoints(CGtV3d * out, float * lpHeights)
{
    const CGtV3d * v = (const CGtV3d *)field_0;
    float yA = (float)v[0].Y() + lpHeights[0];
    float yB = (float)v[16].Y() + lpHeights[1];
    float yC = (float)v[4].Y() + lpHeights[2];
    float yD = (float)v[20].Y() + lpHeights[3];
    CGtV3d lDir;                            // [C] x axis; w never set (stack value)
    lDir.SetX(1.0f);
    lDir.SetY(0.0f);
    lDir.SetZ(0.0f);
    float lrMinY = GtMath::Min(GtMath::Min(GtMath::Min(GtMath::Min(GtMath::Min((float)v[0].Y(), (float)v[4].Y()), (float)v[8].Y()),
                                                       (float)v[12].Y()), (float)v[16].Y()), (float)v[20].Y());
    float x0 = GtMath::Max((float)v[0].X(), (float)v[2].X());
    float z0 = GtMath::Max((float)v[0].Z(), (float)v[2].Z());
    float x2 = GtMath::Min((float)v[4].X(), (float)v[6].X());
    float z2 = GtMath::Max((float)v[4].Z(), (float)v[6].Z());
    float x1 = GtMath::Max(GtMath::Max((float)v[16].X(), (float)v[18].X()), (float)v[28].X());
    float z1 = GtMath::Min(GtMath::Min((float)v[16].Z(), (float)v[18].Z()), (float)v[28].Z());
    float x3 = GtMath::Min(GtMath::Min((float)v[20].X(), (float)v[22].X()), (float)v[30].X());
    float z3 = GtMath::Min(GtMath::Min((float)v[20].Z(), (float)v[22].Z()), (float)v[30].Z());
    out[0].SetX(x0);
    out[0].SetY(lrMinY);
    out[0].SetZ(z0);
    out[1].SetX(x1);
    out[1].SetY(lrMinY);
    out[1].SetZ(z1);
    out[2].SetX(x2);
    out[2].SetY(lrMinY);
    out[2].SetZ(z2);
    out[3].SetX(x3);
    out[3].SetY(lrMinY);
    out[3].SetZ(z3);

    // the 0-1 edge's x at point 8's z, relative to point 8: only an outward (negative) offset moves the edge
    const CGtV3d * p = (const CGtV3d *)field_0;
    float d = ((float)out[0].X() - (float)p[8].X())
            + ((float)out[1].X() - (float)out[0].X()) * ((float)p[8].Z() - (float)out[0].Z()) / ((float)out[1].Z() - (float)out[0].Z());
    d = GtMath::Min(0.0f, d);
    func_003D9740_inl1(out[0], lDir * d);
    func_003D9740_inl1(out[1], lDir * d);
    p = (const CGtV3d *)field_0;
    d = ((float)out[2].X() - (float)p[12].X())
      + ((float)out[3].X() - (float)out[2].X()) * ((float)p[12].Z() - (float)out[2].Z()) / ((float)out[3].Z() - (float)out[2].Z());
    d = GtMath::Max(0.0f, d);
    func_003D9740_inl1(out[2], lDir * d);
    func_003D9740_inl1(out[3], lDir * d);

    out[4] = out[0];
    out[5] = out[1];
    out[6] = out[2];
    out[7] = out[3];
    out[4].SetY(yA);
    out[5].SetY(yB);
    out[6].SetY(yC);
    out[7].SetY(yD);
    for (int i = 0; i < 4; i++) {
        float h = GtMath::Max((float)out[4 + i].Y() - (float)out[i].Y(), D_004E0CD0);
        out[4 + i].SetY((float)out[i].Y() + h);
    }
}
