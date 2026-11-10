// NONMATCHING: Update__11CGtViewportFv -- retail 426 / ours 436 instructions, 533 in changed runs
// draftAO (2026-11-01): complete from the asm: CGtQuatPos::ConvertToMatrix of the camera +0x10, its rows float by float into the RW frame matrix (the skeleton wrote the frame position from +0x40/+0x44/+0x50: wrong), flags = 3 twice at frame+0x1C (the skeleton wrote +0x2C), view window, and the 300-instruction VU0 middle decoded: viewport matrix +0x00 = transpose(col0, col1, A) with col0 = R a + A b, col1 = U c + A g and the -P.col translation row | Before: son6 skeleton (112 vs 426), VU0 middle replaced by scalar placeholder maths
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x211ED0..0x212574), every VU lane traced: calls identical, non-stack stores as retail (frame rows, flags x2, +0x48..+0x54, +0x6C, +0x00..+0x3F); behaviour_audit quiet

// CGtViewport::Update() -- 0x211ED0. draftAO (2026-11-01): complete, written from the asm (was son6's skeleton with the VU0
// middle replaced by placeholder maths and the RwFrame position taken from the wrong fields).
// [C] decode (retail 0x211ED0..0x212574):
//  1. The camera's CGtQuatPos (+0x10 quat, +0x20 position) -> CGtQuatPos::ConvertToMatrix (GtMathPs2Quat.h: sqrt(2) scale
//     D_004E07B8, the nine lane products, (1-xx)-yy rows; the CGtV4d(u_long128) of CGtQuat::operator* is retail's one
//     out-of-line call, __ct__Q29GtMathPs26CGtV4dF1), through the return copies (16-byte lb/sb loops) into the local m.
//  2. m's four rows copied float by float into the RW camera's frame matrix (RwFrame +0x10 = modelling RwMatrix [L], RW 3.x
//     layout: right/up/at/pos, flags +0x1C); flags = 3 (rwMATRIXTYPEORTHONORMAL [L]) before RwMatrixUpdate and again before
//     RwFrameUpdateObjects (retail stores 3 to frame+0x1C twice, 0x212260 / 0x212270).
//  3. View window: t = tanf(D_004E06F0 * (0.5 * fov)), +0x48 = +0x70 * t, +0x4C = +0x48 / +0x74, +0x50 = 1 / +0x48,
//     +0x54 = 1 / +0x4C; RwCameraSetViewWindow(camera, &+0x48); +0x6C = fov.
//  4. The viewport matrix +0x00..+0x3F (an inline returning CGtMatrix3x4: row 0 from its register, rows 1-3 by byte loops):
//     with k = (-0.5, 0.5, 0) built on the stack, a = +0x50 * k.x, b = k.y - a * +0x40, c = +0x54 * k.x, g = k.y + c * +0x44,
//     col0 = R * a + A * b, col1 = U * c + A * g (R/U/A/P = m's rows), the result's rows are the transpose of (col0, col1, A)
//     and its position row (k.y - (b + P.col0), k.y - (g + P.col1), -(P.A)). Every lane write is partial on an uninitialised
//     stack matrix: the four w lanes stored into the viewport are stale stack data (retail reads them too, never written).
// +0x40 / +0x44 are floats here (raw words moved into VU lanes, qmtc2 + vaddx.x 0x2122FC / 0x212310). Names: placeholders.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct RwV3d { float x, y, z; };
struct RwMatrix { RwV3d right; unsigned int flags; RwV3d up; unsigned int pad1; RwV3d at; unsigned int pad2; RwV3d pos; unsigned int pad3; };
struct RwFrame { unsigned char object[8]; unsigned char inDirtyListLink[8]; RwMatrix modelling; };   // [L] RW 3.x layout (RW SDK 3.1/3.5 headers)
struct RwCamera { unsigned char type, subType, flags, privateFlags; RwFrame *parent; };              // [L] RwObject head; parent = the frame
class CGtCamera {
public:
    unsigned char pad_0[4];
    float field_4;                  // [G] field of view (degrees; D_004E06F0 converts)
    unsigned char pad_8[8];
    CGtQuatPos field_10;            // [L] orientation + position (lqc2 0x10 / lq 0x20, s0 = +0x10)
};
class CGtViewport {
public:
    void Update();
    CGtMatrix3x4 field_0;           // [C] view matrix (sq 0x0..0x30($s4) at the end)
    float field_40;                 // [G] view window offset x / y (used with the reciprocal sizes)
    float field_44;
    float field_48;                 // view window (RwCameraSetViewWindow(camera, &field_48)): half width
    float field_4C;                 //   half height
    float field_50;                 //   1 / field_48
    float field_54;                 //   1 / field_4C
    RwCamera *field_58;
    int field_5C;
    int field_60;
    int field_64;
    CGtCamera *field_68;
    float field_6C;                 // last fov
    float field_70;                 // [G] view distance scale
    float field_74;                 // aspect ratio
};
extern float D_004E06F0;            // deg -> rad (gp_rel)
extern "C" void RwMatrixUpdate(RwMatrix *);
extern "C" void RwFrameUpdateObjects(RwFrame *);
extern "C" float tanf(float);
extern "C" void RwCameraSetViewWindow(RwCamera *, const void *);

static inline CGtMatrix3x4 func_00211ED0_inl1(const CGtMatrix3x4 &m, float ox, float oy, float sx, float sy)
{
    CGtV3d k(-0.5f, 0.5f, 0.0f);
    CGtMatrix3x4 r;
    float a = sx * (float)k.X();
    float b = (float)k.Y() - a * ox;
    CGtV3d c0 = m.mRight * a + m.mAt * b;
    r.mRight.SetX((float)c0.X());
    r.mUp.SetX((float)c0.Y());
    r.mAt.SetX((float)c0.Z());
    r.mPos.SetX((float)k.Y() - (b + (float)DotProduct(m.mPos, c0)));
    float c = sy * (float)k.X();
    float g = (float)k.Y() + c * oy;
    CGtV3d c1 = m.mUp * c + m.mAt * g;
    r.mRight.SetY((float)c1.X());
    r.mUp.SetY((float)c1.Y());
    r.mAt.SetY((float)c1.Z());
    r.mPos.SetY((float)k.Y() - (g + (float)DotProduct(m.mPos, c1)));
    r.mRight.SetZ((float)m.mAt.X());
    r.mUp.SetZ((float)m.mAt.Y());
    r.mAt.SetZ((float)m.mAt.Z());
    r.mPos.SetZ(0.0f - (float)DotProduct(m.mPos, m.mAt));   // [C] retail vsub.x from vf0 (0 - d: +0 for d = 0); MWCC folds this to neg.s (-0) -- signed zero only
    return r;
}

// 0x00211ED0
void CGtViewport::Update()
{
    CGtMatrix3x4 m;
    m = field_68->field_10.ConvertToMatrix();
    RwFrame *f = field_58->parent;
    f->modelling.right.x = m.mRight.X();
    f->modelling.right.y = m.mRight.Y();
    f->modelling.right.z = m.mRight.Z();
    f->modelling.up.x = m.mUp.X();
    f->modelling.up.y = m.mUp.Y();
    f->modelling.up.z = m.mUp.Z();
    f->modelling.at.x = m.mAt.X();
    f->modelling.at.y = m.mAt.Y();
    f->modelling.at.z = m.mAt.Z();
    f->modelling.pos.x = m.mPos.X();
    f->modelling.pos.y = m.mPos.Y();
    f->modelling.pos.z = m.mPos.Z();
    f->modelling.flags = 3;
    RwMatrixUpdate(&f->modelling);
    f->modelling.flags = 3;
    RwFrameUpdateObjects(f);
    float fov = field_68->field_4;
    float t = tanf(D_004E06F0 * (0.5f * fov));
    field_48 = field_70 * t;
    field_4C = field_48 / field_74;
    field_50 = 1.0f / field_48;
    field_54 = 1.0f / field_4C;
    RwCameraSetViewWindow(field_58, &field_48);
    field_6C = fov;
    field_0 = func_00211ED0_inl1(m, field_40, field_44, field_50, field_54);
}
