// NONMATCHING: DebugRenderEdges__13CB3ConvexHullCFRCQ29GtMathPs212CGtMatrix3x4b -- retail 312 / ours 320 instructions, 165 in changed runs
// draftAF C-first: hull verts to world, camera matrix (CGtQuatPos::ConvertToMatrix through an accessor inline, Revenge's two lResult), within 50 units: green DrawLine per edge + yellow vertex numbers (sprintf + DrawVectorText) when lbShowNumbers. 320/312 (the .o also carries the weak CGtV4d ctor); calls identical (6); VU op counts equal; left: lq/sq copy traffic, retail rematerialises %hi per use (lui 8/4), frame 0x5A0 vs 0x700
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block mapped (vertex loop, colours (0,1,0,1)/(1,1,0,1), distance^2 < 2500, edge loop with both labels); calls.sh identical; locals/layout from Revenge STABS

// CB3ConvexHull::DebugRenderEdges(const CGtMatrix3x4&, bool) const -- draftAF (0x2B9C10, 0x4E0). [C] name: the mangled symbol;
// locals after Revenge's DebugRenderEdges__C13CB4ConvexHull (STABS: lCameraMatrix, laWorldVerts[16], lLine, lnEdge,
// lacMessage[10], two lResult) [L]; hull layout [L] Revenge CB4ConvexHull (maVerts +0x8, maEdges +0xC, mu8NumVerts +0x18,
// mu8NumEdges +0x1A). [L] the hull's vertices to world space, then (camera within 50 units) every edge as a green debug line,
// with yellow vertex numbers when lbShowNumbers. Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct CGtLine { CGtV3d field_0; CGtV3d field_10; };   // [L] Revenge CGtLine: mStartPoint, mEndPoint
class CB3DebugManager {
public:
    void DrawLine(const CGtLine &, CGtV4d);
    void DrawVectorText(const char *, CGtV3d, CGtMatrix3x4 *, float, CGtV4d);
};
struct UnkStruct_002B9C10_edge { unsigned char field_0; unsigned char field_1; };   // [L] CB4ConvexHullEdge: two vertex indices
class CB3ConvexHull {
public:
    void DebugRenderEdges(const CGtMatrix3x4 &lMatrix, bool lbShowNumbers) const;
    void *field_0;
    void *field_4;
    CGtV3d *field_8;                  // [L] maVerts
    UnkStruct_002B9C10_edge *field_C; // [L] maEdges
    void *field_10;
    unsigned int field_14;
    unsigned char field_18;           // [L] mu8NumVerts
    unsigned char field_19;
    unsigned char field_1A;           // [L] mu8NumEdges
};
struct UnkStruct_002B9C10_cam { unsigned char pad_0[0x10]; CGtQuatPos field_10; };
struct UnkStruct_002B9C10_cm { unsigned char pad_0[0x68]; UnkStruct_002B9C10_cam *field_68; };
extern UnkStruct_002B9C10_cm *D_00666270;   // [G] the active camera manager
extern CB3DebugManager D_004EB1E0;
extern const char D_004C1C30[];             // [G] "%d"-style format
extern float D_004E0E24;                    // [G] text scale (0.1)
extern "C" int sprintf(char *, const char *, ...);

// [G] the camera's matrix accessor (Revenge inlines one with its own lResult around the quaternion conversion)
static inline CGtMatrix3x4 func_002B9C10_inl1(UnkStruct_002B9C10_cam *cam)
{
    CGtMatrix3x4 lResult = cam->field_10.ConvertToMatrix();
    return lResult;
}

// 0x002B9C10
void CB3ConvexHull::DebugRenderEdges(const CGtMatrix3x4 &lMatrix, bool lbShowNumbers) const
{
    CGtV4d lGreen(0.0f, 1.0f, 0.0f, 1.0f);
    CGtV4d lYellow(1.0f, 1.0f, 0.0f, 1.0f);
    CGtV3d laWorldVerts[16];
    for (int i = 0; i < field_18; i++) laWorldVerts[i] = TransformPoint(lMatrix, field_8[i]);
    CGtMatrix3x4 lCameraMatrix = func_002B9C10_inl1(D_00666270->field_68);
    if ((float)(lMatrix.mPos - lCameraMatrix.mPos).GetSquaredLength() < (float)2500) {
        for (unsigned int lnEdge = 0; lnEdge < field_1A; lnEdge++) {
            CGtLine lLine;
            lLine.field_0 = laWorldVerts[field_C[lnEdge].field_0];
            lLine.field_10 = laWorldVerts[field_C[lnEdge].field_1];
            D_004EB1E0.DrawLine(lLine, lGreen);
            if (lbShowNumbers) {
                char lacMessage[10];
                sprintf(lacMessage, D_004C1C30, field_C[lnEdge].field_0);
                D_004EB1E0.DrawVectorText(lacMessage, lLine.field_0, &lCameraMatrix, D_004E0E24, lYellow);
                sprintf(lacMessage, D_004C1C30, field_C[lnEdge].field_1);
                D_004EB1E0.DrawVectorText(lacMessage, lLine.field_10, &lCameraMatrix, D_004E0E24, lYellow);
            }
        }
    }
}
