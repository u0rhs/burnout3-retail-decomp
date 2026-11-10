// NONMATCHING: func_002F0640 -- retail 2286 / ours 2316 instructions, 2557 in changed runs
// d5a3 (draft5): written from the asm + Revenge _BoxBoxTest STABS; call sequence identical, per-kind op counts equal except 23 lq+qmtc2 where retail has lqc2 (projection temps, cross-product operands), frame 0xD40 vs 0x1690. Header gaps: Abs(CGtV3d), CGtV3d*lane
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (every branch, store and return path accounted for: 15 axis tests, min-axis loop, three contact cases); call order identical

// func_002F0640 -- [L] the static box-vs-box separating-axis test of B3BoundingBox.cpp: Revenge's
// `static bool _BoxBoxTest(const CGtAxisAlignedBox &lBoxA, const CGtAxisAlignedBox &lBoxB, CGtMatrix3x4 *lpTransform,
// RwReal *lprPenetration, CGtV3d *lpPoint, CGtV3d *lpNormal)` (STABS 0x1D2338, same six parameters, same locals:
// laAxis[15], larDist[15], two CB4BoxTestData, larLimits[6]); its only caller func_002F0440 is BoxBoxCollision
// (E map, B3BoundingBox.cpp). Name not adopted: B3's E map has no symbol at this shape. Box A is moved into box B's
// frame by lpTransform; B keeps the identity axes D_004C3FF0/4000/4010 ((1,0,0)/(0,1,0)/(0,0,1), set by the
// __sinit func_004D6B30 [C]). 15 axes (A's 3, B's 3, the 9 cross products, each set in the order 0, 2, 1 [C]),
// early-out on the first separating one, then the axis of least penetration (each depth divided by its axis length)
// gives the contact: face of A -> B's support point, face of B -> A's support point, edge/edge -> closest point of
// the two edges (func_002F2A00 = [L] Revenge _GetSupportPointWithLimits, func_002F2CD0 = the plain support point).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

// [L] Revenge stabs: CGtAxisAlignedBox { CGtV3d mSup; CGtV3d mInf; } (0x20)
struct CGtAxisAlignedBox { CGtV3d field_0; CGtV3d field_10; };
// [L] = Revenge CB4BoxTestData (0x70): box, three axes, centre, half extents (func_002F2CD0 reads +0x20..+0x60)
struct UnkStruct_002F2CD0 { CGtAxisAlignedBox field_0; CGtV3d field_20[3]; CGtV3d field_50; CGtV3d field_60; };

extern "C" CGtV3d func_002F2CD0(const UnkStruct_002F2CD0 *box, const CGtV3d &dir);
extern "C" CGtV3d func_002F2A00(UnkStruct_002F2CD0 *box, CGtV3d dir, float *limits);

// [C] .rodata, filled by the __sinit func_004D6B30
static const CGtV3d D_004C3FF0(1.0f, 0.0f, 0.0f);
static const CGtV3d D_004C4000(0.0f, 1.0f, 0.0f);
static const CGtV3d D_004C4010(0.0f, 0.0f, 1.0f);
// [C] .rodata bytes {0, 2, 1}: edge index -> axis index (the 0, 2, 1 order of the axis list)
static const signed char D_004C3FE8[3] = { 0, 2, 1 };

// [L] N185 stand-ins: CGtV3d * lane (vmulx/vmuly/vmulz.xyz), as func_002F2CD0's
static inline CGtV3d func_002F0640_inl1(const CGtV3d &v, XAxisType s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
static inline CGtV3d func_002F0640_inl2(const CGtV3d &v, YAxisType s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
static inline CGtV3d func_002F0640_inl3(const CGtV3d &v, ZAxisType s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
// [L] stands in for GtMathPs2::Abs(CGtV3d) (B3O0PCH map, 60 bytes; not in the header yet): vabs.xyz
static inline CGtV3d func_002F0640_inl4(CGtV3d v) { u_long128 t; asm("vabs.xyz %0, %1" : "=j"(t) : "j"(v.mData)); return CGtV3d(t); }
// [L] lane-wise product (vmul.xyz), as CGtV4d::operator*(CGtV4d)
static inline CGtV3d func_002F0640_inl5(CGtV3d a, CGtV3d b) { u_long128 t; asm("vmul.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }

// [G] one box projected on an axis: centre +- the sum of |axis . dir_i| * half extent i
static inline void func_002F0640_inl6(const CGtV3d &axis, const UnkStruct_002F2CD0 &b, float &rMin, float &rMax)
{
    CGtV3d p;
    p.SetX(DotProduct(axis, b.field_20[0]));
    p.SetY(DotProduct(axis, b.field_20[1]));
    p.SetZ(DotProduct(axis, b.field_20[2]));
    CGtV3d e = func_002F0640_inl5(func_002F0640_inl4(p), b.field_60);
    float r = e.X() + e.Y() + e.Z();
    float c = DotProduct(b.field_50, axis);
    rMin = c - r;
    rMax = c + r;
}

// [G] true when the axis separates the boxes; else the overlap depth into dist
static inline bool func_002F0640_inl7(const CGtV3d &axis, const UnkStruct_002F2CD0 &a, const UnkStruct_002F2CD0 &b, float &dist)
{
    float minA, maxA, minB, maxB;
    func_002F0640_inl6(axis, a, minA, maxA);
    func_002F0640_inl6(axis, b, minB, maxB);
    if (minA <= maxB && minB <= maxA) {
        float hi = GtMath::Min(maxA, maxB);
        float lo = GtMath::Max(minA, minB);
        dist = hi - lo;
        return false;
    }
    return true;
}

// 0x002F0640
extern "C" bool func_002F0640(const CGtAxisAlignedBox &lBoxA, const CGtAxisAlignedBox &lBoxB, const CGtMatrix3x4 *lpTransform,
    float *lprPenetration, CGtV3d *lpPoint, CGtV3d *lpNormal)
{
    CGtV3d laAxis[15];
    CGtV3d lAxis;
    CGtV3d lPointA;
    CGtV3d lPointB;
    float larDist[15];
    int lnAxis;
    float lrMinDist;
    int lnMinAxis;
    UnkStruct_002F2CD0 lBoxDataA;
    UnkStruct_002F2CD0 lBoxDataB;
    float larLimits[6];

    CGtV3d c = (lBoxA.field_10 + lBoxA.field_0) * 0.5f;
    lBoxDataA.field_50 = lpTransform->mPos + func_002F0640_inl1(lpTransform->mRight, c.X())
        + func_002F0640_inl2(lpTransform->mUp, c.Y()) + func_002F0640_inl3(lpTransform->mAt, c.Z());
    ((float *)&lBoxDataA.field_50)[3] = ((const float *)&lpTransform->mUp)[3]; // [C] 0x2F06F8 lqc2 vf1, 0x10(a2) (mUp); 0x2F0700 vmuly.xyz
    // vf1, vf1, vf6y; 0x2F0704 vadd.xyz vf1, vf3, vf1 / 0x2F0708 vadd.xyz vf1, vf1, vf5 keep its w; 0x2F070C sqc2 vf1 -- the port took mAt's
    lBoxDataA.field_20[0] = lpTransform->mRight;
    lBoxDataA.field_60 = (lBoxA.field_0 - lBoxA.field_10) * 0.5f;
    lBoxDataA.field_20[1] = lpTransform->mUp;
    lBoxDataA.field_20[2] = lpTransform->mAt;
    lBoxDataB.field_60 = (lBoxB.field_0 - lBoxB.field_10) * 0.5f;
    lBoxDataB.field_0 = lBoxB;
    lBoxDataA.field_0 = lBoxA;
    lBoxDataB.field_20[0] = D_004C3FF0;
    lBoxDataB.field_20[1] = D_004C4000;
    lBoxDataB.field_20[2] = D_004C4010;
    lBoxDataB.field_50 = (lBoxB.field_10 + lBoxB.field_0) * 0.5f;

    laAxis[0] = lBoxDataA.field_20[0];
    if (func_002F0640_inl7(laAxis[0], lBoxDataA, lBoxDataB, larDist[0])) return false;
    laAxis[1] = lBoxDataA.field_20[2];
    if (func_002F0640_inl7(laAxis[1], lBoxDataA, lBoxDataB, larDist[1])) return false;
    laAxis[2] = lBoxDataA.field_20[1];
    if (func_002F0640_inl7(laAxis[2], lBoxDataA, lBoxDataB, larDist[2])) return false;
    laAxis[3] = lBoxDataB.field_20[0];
    if (func_002F0640_inl7(laAxis[3], lBoxDataA, lBoxDataB, larDist[3])) return false;
    laAxis[4] = lBoxDataB.field_20[2];
    if (func_002F0640_inl7(laAxis[4], lBoxDataA, lBoxDataB, larDist[4])) return false;
    laAxis[5] = lBoxDataB.field_20[1];
    if (func_002F0640_inl7(laAxis[5], lBoxDataA, lBoxDataB, larDist[5])) return false;
    laAxis[6] = CrossProduct(lBoxDataA.field_20[0], lBoxDataB.field_20[0]);
    if (func_002F0640_inl7(laAxis[6], lBoxDataA, lBoxDataB, larDist[6])) return false;
    laAxis[7] = CrossProduct(lBoxDataA.field_20[0], lBoxDataB.field_20[2]);
    if (func_002F0640_inl7(laAxis[7], lBoxDataA, lBoxDataB, larDist[7])) return false;
    laAxis[8] = CrossProduct(lBoxDataA.field_20[0], lBoxDataB.field_20[1]);
    if (func_002F0640_inl7(laAxis[8], lBoxDataA, lBoxDataB, larDist[8])) return false;
    laAxis[9] = CrossProduct(lBoxDataA.field_20[2], lBoxDataB.field_20[0]);
    if (func_002F0640_inl7(laAxis[9], lBoxDataA, lBoxDataB, larDist[9])) return false;
    laAxis[10] = CrossProduct(lBoxDataA.field_20[2], lBoxDataB.field_20[2]);
    if (func_002F0640_inl7(laAxis[10], lBoxDataA, lBoxDataB, larDist[10])) return false;
    laAxis[11] = CrossProduct(lBoxDataA.field_20[2], lBoxDataB.field_20[1]);
    if (func_002F0640_inl7(laAxis[11], lBoxDataA, lBoxDataB, larDist[11])) return false;
    laAxis[12] = CrossProduct(lBoxDataA.field_20[1], lBoxDataB.field_20[0]);
    if (func_002F0640_inl7(laAxis[12], lBoxDataA, lBoxDataB, larDist[12])) return false;
    laAxis[13] = CrossProduct(lBoxDataA.field_20[1], lBoxDataB.field_20[2]);
    if (func_002F0640_inl7(laAxis[13], lBoxDataA, lBoxDataB, larDist[13])) return false;
    laAxis[14] = CrossProduct(lBoxDataA.field_20[1], lBoxDataB.field_20[1]);
    if (func_002F0640_inl7(laAxis[14], lBoxDataA, lBoxDataB, larDist[14])) return false;

    if (lpPoint == 0) return true;

    lrMinDist = 3.402823466e+38f;
    lnMinAxis = -1;
    for (lnAxis = 0; lnAxis < 15; lnAxis++) {
        if (!(DotProduct(laAxis[lnAxis], laAxis[lnAxis]) < 2.3283064e-10f)) {
            float len = laAxis[lnAxis].NormaliseGetLength();
            larDist[lnAxis] /= len;
            if (larDist[lnAxis] < lrMinDist) {
                lrMinDist = larDist[lnAxis];
                lnMinAxis = lnAxis;
            }
        }
    }
    if (lnMinAxis == -1) return false;

    lAxis = laAxis[lnMinAxis];
    if (DotProduct(lBoxDataB.field_50 - lBoxDataA.field_50, lAxis) > 0.0f) lAxis = lAxis * -1.0f;

    if (lnMinAxis < 3) {
        lPointB = func_002F2CD0(&lBoxDataB, -lAxis);
        *lprPenetration = lrMinDist;
        *lpPoint = lPointB - lAxis * lrMinDist;
        ((float *)lpPoint)[3] = ((const float *)&lAxis)[3]; // [C] 0x2F28C4 lqc2 vf1, 0x1590(sp) (lAxis); 0x2F28D4 vmulx.xyz vf1, vf1, vf2x;
        // 0x2F28DC vsub.xyz vf1, vf3, vf1 keeps its w; 0x2F28E0 sqc2 vf1, 0(s1) -- `a - b` took lPointB's w
        *lpNormal = lAxis;
        return true;
    }
    if (lnMinAxis < 6) {
        lPointA = func_002F2CD0(&lBoxDataA, lAxis);
        *lprPenetration = lrMinDist;
        *lpPoint = lPointA + lAxis * lrMinDist;
        *lpNormal = lAxis;
        return true;
    }
    int lnIndex = lnMinAxis - 6;
    int lnIndexA = D_004C3FE8[lnIndex / 3];
    int lnIndexB = D_004C3FE8[lnIndex - (lnIndex / 3) * 3];
    lPointA = func_002F2A00(&lBoxDataA, lAxis, larLimits);
    lPointB = func_002F2CD0(&lBoxDataB, -lAxis);
    CGtV3d lCross = CrossProduct(lAxis, lBoxDataB.field_20[lnIndexB]);
    float lrB = DotProduct(lCross, lPointB);
    float lrDen = DotProduct(lBoxDataA.field_20[lnIndexA], lCross);
    if (GtMath::Abs(lrDen) < 0.0001f) return false;
    float lrT = (lrB - DotProduct(lPointA, lCross)) / lrDen;
    float lrMin = larLimits[lnIndexA * 2];
    float lrMax = larLimits[lnIndexA * 2 + 1];
    lrT = GtMath::Min(GtMath::Max(lrT, lrMin), lrMax);
    *lprPenetration = lrMinDist;
    *lpPoint = lPointA + lBoxDataA.field_20[lnIndexA] * lrT + lAxis * lrMinDist;
    *lpNormal = lAxis;
    return true;
}
