// NONMATCHING: func_001BA4C0 -- retail 292 / ours 292 instructions, 114 in changed runs
// 292/292, 114 changed: frame 0x150 and every stack slot exact, FPU ops identical; left = GPR choice for the four CSE'd &local.y pointers (retail t7/t6/t4/t5, ours t6/t7/v1/v0) and lDir1's x/y store order at entry; accessor, operand-order, by-value and declaration forms negative -> permuter
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm, Ghidra and the Revenge STABS body (parameter/local names); every store accounted for (draftW)

// func_001BA4C0 -- [L] _ShortestVectorBetween2DLines(const CGtV2d&, const CGtV2d&, const CGtV2d&, const CGtV2d&, CGtV2d*,
// CGtV2d*, float*, float*) (research/proto/new_names.csv high, B3PhysicsManager.cpp; full signature and parameter / local
// names: Revenge map + research/stabs/revenge_jul14_functions.cpp 0x1E5880 [L]). Returns the distance between two 2D
// segments, the closest points and their parameters.

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"

using namespace GtMathPs2;

// [G] 2D dot product (Revenge stabs list an inlined lrDotProduct after each CGtV2d difference)
static inline float func_001BA4C0_inl1(const CGtV2d& a, const CGtV2d& b)
{
    float lrDotProduct = a.marValues[0] * b.marValues[0] + a.marValues[1] * b.marValues[1];
    return lrDotProduct;
}

// 0x001BA4C0
extern "C" float func_001BA4C0(const CGtV2d& lStart1, const CGtV2d& lEnd1, const CGtV2d& lStart2, const CGtV2d& lEnd2,
                               CGtV2d * lpPoint1Out, CGtV2d * lpPoint2Out, float * lprParam1Out, float * lprParam2Out)
{
    CGtV2d lDir1;
    CGtV2d lDir2;
    CGtV2d lPointToLine;
    CGtV2d lPoint1;
    CGtV2d lPoint2;
    CGtV2d lVector;
    lDir1 = lEnd1 - lStart1;
    lDir2 = lEnd2 - lStart2;
    if (GtMath::IsEffectivelyZero(func_001BA4C0_inl1(lDir1, lDir2))) {
        return 1000.0f;
    }
    float lrLenSq = 0.0f + func_001BA4C0_inl1(lDir1, lDir1);
    lPointToLine = lStart2 - lStart1;
    float lrParam1 = (0.0f + func_001BA4C0_inl1(lPointToLine, lDir1)) / lrLenSq;
    lPointToLine = lEnd2 - lStart1;
    float lrParam2 = (0.0f + func_001BA4C0_inl1(lPointToLine, lDir1)) / lrLenSq;
    lrParam1 = GtMath::Min(GtMath::Max(lrParam1, 0.0f), 1.0f);
    lrParam2 = GtMath::Min(GtMath::Max(lrParam2, 0.0f), 1.0f);
    lPoint1 = lStart1 + lDir1 * lrParam1;
    lPoint2 = lStart1 + lDir1 * lrParam2;
    *lpPoint1Out = lPoint1;
    *lpPoint2Out = lStart2;
    *lprParam1Out = lrParam1;
    *lprParam2Out = 0.0f;
    lVector = lStart2 - lPoint1;
    float lrMinDistSq = 0.0f + func_001BA4C0_inl1(lVector, lVector);
    lVector = lEnd2 - lPoint2;
    float lrDistSq = 0.0f + func_001BA4C0_inl1(lVector, lVector);
    if (lrDistSq < lrMinDistSq) {
        *lpPoint1Out = lPoint2;
        *lpPoint2Out = lEnd2;
        *lprParam1Out = lrParam2;
        *lprParam2Out = 1.0f;
        lrMinDistSq = lrDistSq;
    }
    lrLenSq = func_001BA4C0_inl1(lDir2, lDir2);
    lPointToLine = lStart1 - lStart2;
    lrParam1 = func_001BA4C0_inl1(lPointToLine, lDir2) / lrLenSq;
    lPointToLine = lEnd1 - lStart2;
    lrParam2 = func_001BA4C0_inl1(lPointToLine, lDir2) / lrLenSq;
    lrParam1 = GtMath::Min(GtMath::Max(lrParam1, 0.0f), 1.0f);
    lrParam2 = GtMath::Min(GtMath::Max(lrParam2, 0.0f), 1.0f);
    lPoint1 = lStart2 + lDir2 * lrParam1;
    lPoint2 = lStart2 + lDir2 * lrParam2;
    lVector = lStart1 - lPoint1;
    lrDistSq = func_001BA4C0_inl1(lVector, lVector);
    if (lrDistSq < lrMinDistSq) {
        *lpPoint1Out = lStart1;
        *lpPoint2Out = lPoint1;
        *lprParam1Out = 0.0f;
        *lprParam2Out = lrParam1;
        lrMinDistSq = lrDistSq;
    }
    lVector = lEnd1 - lPoint2;
    lrDistSq = func_001BA4C0_inl1(lVector, lVector);
    if (lrDistSq < lrMinDistSq) {
        *lpPoint1Out = lEnd1;
        *lpPoint2Out = lPoint2;
        *lprParam1Out = 1.0f;
        *lprParam2Out = lrParam2;
        lrMinDistSq = lrDistSq;
    }
    return GtMath::Sqrt(lrMinDistSq);
}

