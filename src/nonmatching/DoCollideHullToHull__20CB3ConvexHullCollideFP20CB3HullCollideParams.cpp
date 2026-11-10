// NONMATCHING: DoCollideHullToHull__20CB3ConvexHullCollideFP20CB3HullCollideParams -- retail 695 / ours 626 instructions, 529 in changed runs
// draftAE C-first: 626/695, call sequence identical (BuildClippedEdgeList/ClipEdgesByHull x2, func_002B7BF0 x2); VU op counts agree; left: the two matrix products' copy levels (retail r -> temp by row-0 sq + three 16-byte lb/sb loops each, then lq/sq: 6 byte loops, 42 instrs; ours direct), stack-array address materialisation (addiu 35/72), frame 0x14A0 vs 0x15B0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (A->B / B->A matrices, vertex transforms, edge build + clip both ways, world-space points, bbox centre, nearest faces, normal difference + zero test, exit faces, depths clamped at 0, push-outs); header operator*/TransformPoint/TransformVector/Min/Max/DotProduct/Normalise/lane ops; TransformPoints + operator-(W,X) stand-ins (gap queued)

// DoCollideHullToHull__20CB3ConvexHullCollideFP20CB3HullCollideParams -- draftAE (0x2B8920, 0xADC) --
// CB3ConvexHullCollide::DoCollideHullToHull(CB3HullCollideParams*), a static member (CollideBodyHulls' archive).
// Written from the retail asm. [L] convex hull vs convex hull: each hull's vertices into the other's space, the edges of each
// hull facing the other (BuildClippedEdgeList) clipped by the other hull's planes (ClipEdgesByHull) and taken back to world
// space; fewer than two points = no contact. Otherwise the contact point is the centre of the points' bounding box, the normal
// the difference of the two hulls' nearest face normals (zero = no contact), and each body is pushed out along the face its
// own centre-ray crosses (func_002B7BF0) by its penetration depth (field_1E4 = 1).
// Types and field meanings [G] (instruction widths, use). Layout of the params as CollideBodyHulls' archive.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct CB3ConvexHull {
    void * field_0;                 // [G] passed on to func_002B7BF0
    CGtPlane * field_4;             // [G] face planes
    CGtV3d * field_8;               // [G] vertices
    unsigned char (*field_C)[2];    // [G] edges
    unsigned char pad_10[8];
    unsigned char field_18;         // [G] vertex count
    unsigned char field_19;         // [G] plane count
    unsigned char field_1A;         // [G] edge count
};
struct CB3HullCollideParams {
    CB3ConvexHull * field_0;        // [G] hull A
    unsigned char pad_4[0x2C];
    CGtMatrix3x4 field_30;          // [G] body A world matrix
    CGtMatrix3x4 field_70;          // [G] its inverse
    unsigned char pad_B0[0x40];
    CB3ConvexHull * field_F0;       // [G] hull B
    unsigned char pad_F4[0x2C];
    CGtMatrix3x4 field_120;         // [G] body B world matrix
    CGtMatrix3x4 field_160;         // [G] its inverse
    unsigned char pad_1A0[0x40];
    int field_1E0;
    int field_1E4;                  // [G] contact found
    unsigned char pad_1E8[0x8];
    CGtV3d field_1F0;               // [G] contact normal
    CGtV3d field_200;               // [G] contact point
};
class CB3ConvexHullCollide {
public:
    static bool DoCollideHullToHull(CB3HullCollideParams * p);
    static void BuildClippedEdgeList(CGtV3d * out, unsigned * n, CGtV3d pl, const CB3ConvexHull * h, CGtV3d * vtx);
    static unsigned int ClipEdgesByHull(CGtV3d * out, int n, CGtV3d * in, unsigned int nIn, CGtPlane * planes, unsigned int nPlanes);
};
// [G] (func_002B7BF0's archive) the face the ray from pos along dir leaves the hull through, and the distance; the CGtV3d
// arguments passed by address in retail (the queued by-value gap), so const& here
extern "C" float func_002B7BF0(int * out, unsigned char n, void * hull, CGtPlane * planes, const CGtV3d & pos, const CGtV3d & dir);

// [G] the face of the hull nearest to a point (smallest |n.c - d|)
static inline unsigned char func_002B8920_inl1(const CGtPlane * planes, unsigned char n, CGtV3d c)
{
    unsigned char lnBest = 0;
    float lrBest = GtMath::Abs(DotProduct(planes[0].Normal(), c) - planes[0].Distance());
    for (unsigned char i = 1; i < n; i++) {
        float d = GtMath::Abs(DotProduct(planes[i].Normal(), c) - planes[i].Distance());
        if (d < lrBest) {
            lrBest = d;
            lnBest = i;
        }
    }
    return lnBest;
}

bool CB3ConvexHullCollide::DoCollideHullToHull(CB3HullCollideParams * p)
{
    void * lpShapeA = p->field_0->field_0;
    CGtPlane * lpPlanesA = p->field_0->field_4;
    CGtV3d * lpVertsA = p->field_0->field_8;
    void * lpShapeB = p->field_F0->field_0;
    CGtPlane * lpPlanesB = p->field_F0->field_4;
    CGtV3d * lpVertsB = p->field_F0->field_8;
    CGtMatrix3x4 lAToB;
    lAToB = p->field_30 * p->field_160;
    CGtMatrix3x4 lBToA;
    lBToA = p->field_120 * p->field_70;
    CGtV3d lAInB = TransformPoint(p->field_160, p->field_30.mPos);
    CGtV3d lBInA = TransformPoint(p->field_70, p->field_120.mPos);
    CGtV3d laVertsB[22];
    CGtV3d laVertsA[22];
    TransformPoints(lAToB, laVertsA, lpVertsA, p->field_0->field_18);
    TransformPoints(lBToA, laVertsB, lpVertsB, p->field_F0->field_18);

    CGtV3d laEdges[120];
    CGtV3d laPoints[64];
    unsigned int lnEdges;
    CGtV3d lDir = lBInA;
    lDir.Normalise();
    BuildClippedEdgeList(laEdges, &lnEdges, lDir, p->field_0, laVertsA);
    unsigned int lnFromA = ClipEdgesByHull(laPoints, 64, laEdges, lnEdges, lpPlanesB, p->field_F0->field_19);
    lDir = lAInB;
    lDir.Normalise();
    BuildClippedEdgeList(laEdges, &lnEdges, lDir, p->field_F0, laVertsB);
    unsigned int lnFromB = ClipEdgesByHull(&laPoints[lnFromA], 64 - lnFromA, laEdges, lnEdges, lpPlanesA, p->field_0->field_19);
    unsigned int lnPoints = lnFromA + lnFromB;
    if (lnPoints < 2)
        return false;
    int i;
    for (i = 0; i < (int)lnFromA; i++)
        laPoints[i] = TransformPoint(p->field_120, laPoints[i]);
    unsigned int lnRest = lnPoints - lnFromA;
    for (i = 0; i < (int)lnRest; i++)
        laPoints[lnFromA + i] = TransformPoint(p->field_30, laPoints[lnFromA + i]);
    CGtV3d lMin = laPoints[0];
    CGtV3d lMax = laPoints[0];
    for (i = 1; i < (int)lnPoints; i++) {
        lMin = Min(lMin, laPoints[i]);
        lMax = Max(lMax, laPoints[i]);
    }
    CGtV3d lContact = (lMin + lMax) * 0.5f;
    CGtV3d lContactA = TransformPoint(p->field_70, lContact);
    CGtV3d lContactB = TransformPoint(p->field_160, lContact);
    unsigned char lnFaceA = func_002B8920_inl1(lpPlanesA, p->field_0->field_19, lContactA);
    CGtV3d lNormalA = TransformVector(p->field_30, lpPlanesA[lnFaceA].Normal());
    unsigned char lnFaceB = func_002B8920_inl1(lpPlanesB, p->field_F0->field_19, lContactB);
    CGtV3d lNormal = lNormalA - TransformVector(p->field_120, lpPlanesB[lnFaceB].Normal());
    if (lNormal.GetSquaredLength() < 2.3283064e-10f)
        return false;
    lNormal.Normalise();
    p->field_200 = lContact;
    p->field_1F0 = lNormal;

    int lnExitA;
    int lnExitB;
    func_002B7BF0(&lnExitA, p->field_0->field_19, lpShapeA, lpPlanesA, lContactA, lBInA);
    func_002B7BF0(&lnExitB, p->field_F0->field_19, lpShapeB, lpPlanesB, lContactB, lAInB);
    XAxisType lDotA = DotProduct(lContactA, lpPlanesA[lnExitA].Normal());
    XAxisType lDotB = DotProduct(lContactB, lpPlanesB[lnExitB].Normal());
    float lrDepthA = (lpPlanesA[lnExitA].Distance() - lDotA);
    float lrDepthB = (lpPlanesB[lnExitB].Distance() - lDotB);
    if (lrDepthA < 0.0f)
        lrDepthA = 0.0f;
    if (lrDepthB < 0.0f)
        lrDepthB = 0.0f;
    CGtV3d lPushA = lpPlanesA[lnExitA].Normal() * -lrDepthA;
    CGtV3d lPushB = lpPlanesB[lnExitB].Normal() * -lrDepthB;
    p->field_30.mPos += TransformVector(p->field_30, lPushA);
    p->field_120.mPos += TransformVector(p->field_120, lPushB);
    p->field_1E4 = 1;
    return true;
}
