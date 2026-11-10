// NONMATCHING: Render__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams -- retail 548 / ours 547 instructions, 379 in changed runs
// draftAH C-first: deform debug view (8 bone arrows, 2 box squares, 2 pivot squares, 2 arrows per hinged part via end*part matrix, unused camera matrix from CGtQuatPos::ConvertToMatrix, RenderClampBoxes); 547/548, calls identical, VU op counts equal except vmove 6/0 (copies); left: row reloads (lqc2 14/22), frame 0x980 vs 0xC00
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; arrow points, colours (6 CGtV4d constants, 2 unused as in retail), square arguments and loop bounds traced; header operator*, ConvertToMatrix, lane ops

// CB3VehicleDeform::Render(CB3VehicleEssentialParams*, CB3VehicleParams*) -- draftAH (C-first draft; the lifter refused it).
// 0x4601C0, 0x890. [C] name: retail symbol table (Revenge's Render__16CB4VehicleDeform in B4VehicleDeformExtra.cpp is empty).
// Written from the retail asm. What it does [L]: the deformation debug view -- for each of 8 deform bones an arrow along its
// at axis (length per bone from the vehicle data) through its matrix in the params, the body box as two squares at the two
// heights from func_003E6F90 / func_003E6F50, a small square round the pivots of virtual bones 4 and 5, an arrow per hinged
// body part end (2 per part: the end matrix in part space times the part matrix), then the clamp boxes. A camera matrix from
// D_00666270's quat-pos is built and left unused (retail keeps it). Each arrow: SetArrowVertices (func_00461020, DNAT name in
// its archive) then a 6-vertex trilist through the car matrix (func_00364670, as RenderClampBoxes).
// Types [G]; layouts as RenderClampBoxes / SetArrowVertices (CB3Im3dVertex) and CB3VehiclePhysics::Prepare (params, vehicle data).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CGtTexture;
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    unsigned char pad_10[8];
    unsigned int field_18;
    unsigned char pad_1C[4];
    CB3Im3dVertex() { field_0.SetPlus(0.0f); }   // [L] B3O0PCH map ctor; [G] body: w = 0 (as RenderClampBoxes')
};
struct CGtAxisAlignedBox { CGtV3d mSup; CGtV3d mInf; };   // [L] Revenge layout (class_layouts.tsv)
struct UnkStruct_004601C0_40 {              // the vehicle data block (essential params +0x40, as Prepare's)
    unsigned char pad_0[0xC];
    signed char field_C;                    // hinged body part count
    unsigned char pad_D[0xA63];
    float field_A70[8];                     // deform bone arrow lengths [G]
    unsigned char pad_A90[0x30];
    int field_AC0;                          // debug view enabled [G]
    unsigned char pad_AC4[0x3BC];
    CGtAxisAlignedBox field_E80;            // bounding box
};
class CB3VehicleEssentialParams {
public:
    CGtMatrix3x4 field_0;                   // the car matrix (CB3VehiclePhysics::field_204 points here)
    UnkStruct_004601C0_40 * field_40;
};
class CB3VehicleParams {
public:
    unsigned char pad_0[0x180];
    CGtMatrix3x4 field_180[6];              // body part matrices (as Prepare's)
    unsigned char pad_300[0x400];
    CGtMatrix3x4 field_700[8];              // deform bone matrices [G]
    unsigned char pad_900[0x300];
    CGtMatrix3x4 field_C00[6][2];           // body part end matrices, part space [G]
    float field_F30[6][2];                  // their arrow lengths [G]
};
enum EVirtualBoneIndex { };
struct UnkStruct_004601C0_cam { unsigned char pad_0[0x10]; CGtQuatPos field_10; };
struct UnkStruct_004601C0_cfg { unsigned char pad_0[0x68]; UnkStruct_004601C0_cam *field_68; };
struct UnkStruct_D_00666270 { UnkStruct_004601C0_cfg *field_0; };
extern UnkStruct_D_00666270 D_00666270;
extern float D_004E0E00, D_004E0F5C;        // [G] arrow head width factors
extern float D_004E0B18;                    // [G] pivot square half size
namespace B3Im3d {
void BeginRendering();
void EndRendering();
void SetTexture(CGtTexture *);
}

class CB3VehicleDeform {
public:
    void Render(CB3VehicleEssentialParams *, CB3VehicleParams *);
    void RenderSquare(float, float, float, float, float, float, CGtV4d *);
    CGtV3d GetPivotPos(EVirtualBoneIndex);
    void RenderClampBoxes();

    unsigned char pad_0[0x10];
    CB3VehicleEssentialParams *field_10;
    CB3VehicleParams *field_14;
    UnkStruct_004601C0_40 *field_18;
};
extern "C" void func_00461020(CB3VehicleDeform *self, CB3Im3dVertex *v, CGtV3d a, CGtV3d b, CGtV3d c, CGtV3d d, CGtV4d col);
extern "C" void func_00364670(const void *m, const CB3Im3dVertex *v, int n);   // [L] B3Im3d trilist through a matrix
extern "C" float func_003E6F50(CB3VehicleDeform *self, bool p0);
extern "C" float func_003E6F90(CB3VehicleDeform *self, bool p0);

// [G] one arrow: from pos along at by lrLength, the head's two barbs back along (+-right - at), drawn through the car matrix
static inline void func_004601C0_inl1(CB3VehicleDeform *self, CB3Im3dVertex *v, const CGtV3d &pos, const CGtV3d &right,
                                      const CGtV3d &at, float lrLength, const CGtV4d &col)
{
    CGtV3d p0 = pos;
    CGtV3d p1 = p0 + at * lrLength;
    CGtV3d p2 = p1 + (right - at) * D_004E0E00 * D_004E0F5C;
    CGtV3d p3 = p1 + (-right - at) * D_004E0E00 * D_004E0F5C;
    func_00461020(self, v, p0, p1, p2, p3, col);
    B3Im3d::BeginRendering();
    B3Im3d::SetTexture(0);
    func_00364670(self->field_10, v, 6);
    B3Im3d::EndRendering();
}

// [G] draw one arrow: SetArrowVertices, then the trilist through the car matrix
static inline void func_004601C0_inl2(CB3VehicleDeform *self, CB3Im3dVertex *v, const CGtV3d &p0, const CGtV3d &p1,
                                      const CGtV3d &p2, const CGtV3d &p3, const CGtV4d &col)
{
    func_00461020(self, v, p0, p1, p2, p3, col);
    B3Im3d::BeginRendering();
    B3Im3d::SetTexture(0);
    func_00364670(self->field_10, v, 6);
    B3Im3d::EndRendering();
}

// 0x004601C0
void CB3VehicleDeform::Render(CB3VehicleEssentialParams * lpEssentialParams, CB3VehicleParams * lpVehicleParams)
{
    CB3Im3dVertex v[6];
    field_14 = lpVehicleParams;
    if (field_14 == 0)
        return;
    field_10 = lpEssentialParams;
    if (lpEssentialParams == 0)
        return;
    field_18 = field_10->field_40;
    if (field_18 == 0)
        return;
    if (field_18->field_AC0 == 0)
        return;
    CGtV4d c0(1.0f, 0.0f, 0.0f, 1.0f);      // bone arrows
    CGtV4d c1(1.0f, 1.0f, 0.0f, 1.0f);      // body part arrows
    CGtV4d c2(0.0f, 0.0f, 1.0f, 1.0f);      // [G] unused
    CGtV4d c3(0.0f, 1.0f, 0.0f, 0.5f);      // box squares
    CGtV4d c4(1.0f, 0.0f, 0.0f, 1.0f);      // pivot squares
    CGtV4d c5(0.0f, 1.0f, 1.0f, 1.0f);      // [G] unused
    for (int i = 0; i < 8; i++) {
        float lrLength = field_18->field_A70[i];
        CGtV3d p0 = field_14->field_700[i].mPos;
        CGtV3d p1 = p0 + field_14->field_700[i].mAt * lrLength;
        CGtV3d p2 = p1 + (field_14->field_700[i].mRight - field_14->field_700[i].mAt) * D_004E0E00 * D_004E0F5C;
        CGtV3d p3 = p1 + (-field_14->field_700[i].mRight - field_14->field_700[i].mAt) * D_004E0E00 * D_004E0F5C;
        func_004601C0_inl2(this, v, p0, p1, p2, p3, c0);
    }
    float lrLow = func_003E6F90(this, false);
    float lrHigh = func_003E6F50(this, false);
    RenderSquare(field_18->field_E80.mInf.X(), field_18->field_E80.mInf.Y(), lrLow,
                 field_18->field_E80.mSup.X(), field_18->field_E80.mSup.Y(), lrLow, &c3);
    RenderSquare(field_18->field_E80.mInf.X(), field_18->field_E80.mInf.Y(), lrHigh,
                 field_18->field_E80.mSup.X(), field_18->field_E80.mSup.Y(), lrHigh, &c3);
    CGtV3d p = GetPivotPos((EVirtualBoneIndex)4);
    float k = D_004E0B18;
    RenderSquare(p.X(), p.Y() - k, p.Z() - k, p.X(), p.Y() + k, p.Z() + k, &c4);
    CGtV3d q = GetPivotPos((EVirtualBoneIndex)5);
    RenderSquare(q.X(), q.Y() - k, q.Z() - k, q.X(), q.Y() + k, q.Z() + k, &c4);
    for (int i = 0; i < field_10->field_40->field_C; i++) {
        for (int j = 0; j < 2; j++) {
            CGtMatrix3x4 lMatrix = field_14->field_C00[i][j] * field_14->field_180[i];
            func_004601C0_inl1(this, v, lMatrix.mPos, lMatrix.mRight, lMatrix.mAt, field_14->field_F30[i][j], c1);
        }
    }
    CGtMatrix3x4 lCamera = D_00666270.field_0->field_68->field_10.ConvertToMatrix();   // [C asm] built, unused
    RenderClampBoxes();
}
