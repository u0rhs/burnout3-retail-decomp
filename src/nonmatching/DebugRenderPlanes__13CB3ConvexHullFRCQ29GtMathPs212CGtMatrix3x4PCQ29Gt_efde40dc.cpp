// NONMATCHING: DebugRenderPlanes__13CB3ConvexHullFRCQ29GtMathPs212CGtMatrix3x4PCQ29GtMathPs28CGtPlanePCQ29GtMathPs26CGtV3db -- retail 334 / ours 343 instructions, 332 in changed runs
// draftAF C-first: camera within 50 units: per plane, red DrawLine from the centroid of its three deformed verts (sum * 1/3) half a unit along the deformed plane normal, to world space; white plane numbers (sprintf + DrawVectorText, scale 0.05) when lbShowNumbers. 343/334 (the .o also carries the weak CGtV4d ctor); calls identical (4); VU op counts equal; left: lq/sq copy traffic, lui rematerialisation, frame 0x4F0 vs 0x620
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block mapped (red/white colours, distance^2 < 2500, plane loop, 3-vertex centroid, 2-point transform loop, label); calls.sh identical; names/layout from Revenge STABS

// CB3ConvexHull::DebugRenderPlanes(const CGtMatrix3x4&, const CGtPlane*, const CGtV3d*, bool) -- draftAF (0x2B96D0, 0x538).
// [C] name: the mangled symbol; parameter and local names after Revenge's DebugRenderPlanes__13CB4ConvexHull (STABS:
// lpaDeformedPlanes, lpaDeformedVerts, laWorldVerts[2], lLine, lu8Plane, lnVert, lCameraMatrix, two lResult, lacMessage[10]) [L];
// hull layout [L] Revenge CB4ConvexHull (maPlaneVerts +0x0: three vertex indices per plane, mu8NumPlanes +0x19). [L] (camera
// within 50 units) each plane's normal as a red debug line from its centroid (the mean of its three deformed vertices) half a
// unit out, in world space; white plane numbers when lbShowNumbers. Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct CGtLine { CGtV3d field_0; CGtV3d field_10; };   // [L] Revenge CGtLine: mStartPoint, mEndPoint
class CB3DebugManager {
public:
    void DrawLine(const CGtLine &, CGtV4d);
    void DrawVectorText(const char *, CGtV3d, CGtMatrix3x4 *, float, CGtV4d);
};
struct UnkStruct_002B96D0_pv { unsigned char field_0[3]; };   // [L] CB4ConvexHullPlane: the plane's three vertex indices
class CB3ConvexHull {
public:
    void DebugRenderPlanes(const CGtMatrix3x4 &lMatrix, const CGtPlane *lpaDeformedPlanes, const CGtV3d *lpaDeformedVerts, bool lbShowNumbers);
    UnkStruct_002B96D0_pv *field_0;   // [L] maPlaneVerts
    void *field_4;
    CGtV3d *field_8;                  // [L] maVerts
    void *field_C;                    // [L] maEdges
    void *field_10;
    unsigned int field_14;
    unsigned char field_18;           // [L] mu8NumVerts
    unsigned char field_19;           // [L] mu8NumPlanes
    unsigned char field_1A;           // [L] mu8NumEdges
};
struct UnkStruct_002B96D0_cam { unsigned char pad_0[0x10]; CGtQuatPos field_10; };
struct UnkStruct_002B96D0_cm { unsigned char pad_0[0x68]; UnkStruct_002B96D0_cam *field_68; };
extern UnkStruct_002B96D0_cm *D_00666270;   // [G] the active camera manager
extern CB3DebugManager D_004EB1E0;
extern const char D_004C1C30[];             // [G] "%d"-style format
extern float D_004E0ED8;                    // [G] text scale (0.05)
extern float D_004E0F9C;                    // [G] 1/3
extern "C" int sprintf(char *, const char *, ...);

// [G] the camera's matrix accessor (Revenge inlines one with its own lResult around the quaternion conversion)
static inline CGtMatrix3x4 func_002B96D0_inl1(UnkStruct_002B96D0_cam *cam)
{
    CGtMatrix3x4 lResult = cam->field_10.ConvertToMatrix();
    return lResult;
}

// 0x002B96D0
void CB3ConvexHull::DebugRenderPlanes(const CGtMatrix3x4 &lMatrix, const CGtPlane *lpaDeformedPlanes, const CGtV3d *lpaDeformedVerts, bool lbShowNumbers)
{
    CGtV4d lRed(1.0f, 0.0f, 0.0f, 1.0f);
    CGtMatrix3x4 lCameraMatrix = func_002B96D0_inl1(D_00666270->field_68);
    if (!((float)(lMatrix.mPos - lCameraMatrix.mPos).GetSquaredLength() < (float)2500)) return;
    for (unsigned char lu8Plane = 0; lu8Plane < field_19; lu8Plane++) {
        CGtV3d lNormal = lpaDeformedPlanes[lu8Plane].Normal();
        CGtV3d laWorldVerts[2];
        laWorldVerts[0].Zero();
        for (int lnVert = 0; lnVert < 3; lnVert++) laWorldVerts[0] += lpaDeformedVerts[field_0[lu8Plane].field_0[lnVert]];
        laWorldVerts[0] = laWorldVerts[0] * D_004E0F9C;
        laWorldVerts[1] = laWorldVerts[0] + lNormal * 0.5f;
        for (int i = 0; i < 2; i++) laWorldVerts[i] = TransformPoint(lMatrix, laWorldVerts[i]);
        CGtLine lLine;
        lLine.field_0 = laWorldVerts[0];
        lLine.field_10 = laWorldVerts[1];
        D_004EB1E0.DrawLine(lLine, lRed);
        if (lbShowNumbers) {
            char lacMessage[10];
            sprintf(lacMessage, D_004C1C30, lu8Plane);
            D_004EB1E0.DrawVectorText(lacMessage, lLine.field_0, &lCameraMatrix, D_004E0ED8, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
        }
    }
}
