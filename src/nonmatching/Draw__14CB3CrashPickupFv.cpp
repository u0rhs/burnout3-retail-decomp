// NONMATCHING: Draw__14CB3CrashPickupFv -- retail 335 / ours 353 instructions, 248 in changed runs
// draftAF C-first: camera-facing pickup diamond (2 triangles: pos +/- kPickupUp, pos -/+ camera right * D_004E0EE0, k*UV, colour D_004C9BF0 via the proven CB3Im3dVertex::SetColour stand-in), B3Im3d draw. Player index read from a1 (not in B3's mangled name; Revenge has EPlayerCarIndex). 353/335 (the .o also carries the weak CGtV4d ctor); calls identical (6, incl. retail's out-of-line CGtV4d(u_long128)); VU op counts equal; matrix copy levels as retail (camera accessor inline [G], Revenge's two lResult); left: idx*0xBB0 computed twice (mult 2/1), lq/sq copies
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block mapped (vertex ctor x6, early outs, quat->matrix, colour pack loop, 6 positions + UVs in retail's assignment, alpha 0.078125, texture field_C, 6 vertices); calls.sh identical

// CB3CrashPickup::Draw() -- draftAF (0x3A0AA0, 0x53C). [C] name: config/symbol_addrs_b3names.txt; locals after Revenge's
// Draw__14CB4CrashPickup15EPlayerCarIndex (STABS: laPoints[6], lCameraMatrix) [L]. Retail reads a player index from a1 although
// B3's mangled name has no parameter (Revenge's has EPlayerCarIndex): declared through its link name with that argument [G].
// [L] a camera-facing diamond (two triangles) at the pickup's position: top/bottom = position -/+ kPickupUp, left/right =
// position -/+ the camera's right axis * D_004E0EE0, UVs kTopUV/kLeftUV/kBottomUV/kRightUV, colour D_004C9BF0, drawn with
// B3Im3d (alpha-test 0.078125, the pickup's texture). The camera is player idx's camera manager's CGtQuatPos (gGame +
// 0x28E00 + idx * 0xBB0, + 0x210). CB3Im3dVertex's constructor / SetColour: the proven B3VehicleDeform_00460C20 stand-ins.
// Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;
namespace GtMathPs2 {
// [L] N185: stand-ins for GtMathPs2 inlines whose header bodies hard-code a scalar register (retail: compiler-chosen).
// CGtV3dPlus::SetPlus(float) (B3O0PCH map, 72 bytes): the scalar moved by its own statement, as CGtV4d::SetW.
static inline void func_003A0AA0_inl1(CGtV3dPlus &d, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubw.w %0, $vf0, $vf0w" "\n\t" "vaddx.w %0, %0, %1x" : "+j"(d.mData) : "j"(s)); }
// CGtV4d::operator*(float) with the scalar moved by its own statement (hoisted out of the colour loop in retail)
static inline CGtV4d func_003A0AA0_mul(const CGtV4d &v, float f) { u_long128 s, t; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s)); return CGtV4d(t); }
}
class CGtTexture;
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    CGtV2d field_10;                 // [L] mUV (Revenge CB4Im3dVertex)
    unsigned int field_18;
    unsigned char pad_1C[4];
    // [L] CB3Im3dVertex::CB3Im3dVertex() / Construct() (B3O0PCH map); [G] body: w = 0
    CB3Im3dVertex() { func_003A0AA0_inl1(field_0, 0.0f); }
    // [L] CB3Im3dVertex::SetColour(GtMathPs2::CGtV4d) (B3O0PCH map, 0x44); [G] body: col * 128, to int, clamped to (255,255,255,128), packed
    void SetColour(const CGtV4d &c) {
        CGtV4d s = func_003A0AA0_mul(c, 128.0f);
        u_long128 i, lim, m, h;
        unsigned int b;
        asm("vftoi0.xyzw %0, %1" : "=j"(i) : "j"(s.mData));
        unsigned long k = 0x00FF00FFUL | (0x008000FFUL << 32);
        asm("pextlh %0, $0, %1" : "=r"(lim) : "r"(k));
        asm("pminw %0, %1, %2" : "=r"(m) : "r"(i), "r"(lim));
        asm("ppach %0, $0, %1" : "=r"(h) : "r"(m));
        asm("ppacb %0, $0, %1" : "=r"(b) : "r"(h));
        field_18 = b;
    }
};
class CGtTexture;
extern "C" {
void BeginRendering__6B3Im3dFv();
void SetAlphaTestThreshold__6B3Im3dFf(float);
void SetTexture__6B3Im3dFP10CGtTexture(CGtTexture *);
void RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(const CB3Im3dVertex *, int);
void EndRendering__6B3Im3dFv();
}
struct UnkStruct_003A0AA0_data { CGtV3d field_0; };   // [L] Revenge mpPickupData (CB4CrashModePickupStruct): position first
struct UnkStruct_003A0AA0_cam { unsigned char pad_0[0x210]; CGtQuatPos field_210; unsigned char pad_230[0x980]; };   // [G] 0xBB0 apart
struct UnkStruct_003A0AA0 {
    UnkStruct_003A0AA0_data *field_0;
    float field_4;
    unsigned char field_8;            // [G] picked up (no draw)
    unsigned char pad_9[3];
    CGtTexture *field_C;
};
extern unsigned char D_004EE040[];
extern const CGtV3d kPickupUp;
extern const CGtV2d kTopUV, kBottomUV, kRightUV, kLeftUV;
extern const CGtV4d D_004C9BF0;       // [G] the pickup's colour
extern float D_004E0EE0;              // [G] half width

// [L] the camera manager's camera matrix accessor (Revenge's Draw inlines one: CB4PlayerCameraManager *this plus a second
// lResult around the quaternion conversion's own); name unknown, placeholder [G]
static inline CGtMatrix3x4 func_003A0AA0_inl2(UnkStruct_003A0AA0_cam *cam)
{
    CGtMatrix3x4 lResult = cam->field_210.ConvertToMatrix();
    return lResult;
}
// 0x003A0AA0
extern "C" void Draw__14CB3CrashPickupFv(UnkStruct_003A0AA0 *self, int idx)
{
    CB3Im3dVertex laPoints[6];
    if (self->field_8 != 0) return;
    if (self->field_0 == 0) return;
    CGtV3d lPos = self->field_0->field_0;
    CGtMatrix3x4 lCameraMatrix = func_003A0AA0_inl2(&((UnkStruct_003A0AA0_cam *)(D_004EE040 + 0x28E00))[idx]);
    for (int i = 0; i < 6; i++) laPoints[i].SetColour(D_004C9BF0);
    CGtV3d lTop = lPos + kPickupUp;
    CGtV3d lBottom = lPos - kPickupUp;
    CGtV3d lLeft = lPos - lCameraMatrix.mRight * D_004E0EE0;
    CGtV3d lRight = lPos + lCameraMatrix.mRight * D_004E0EE0;
    laPoints[0].field_0.SetGtV3d(lTop);
    laPoints[0].field_10 = kTopUV;
    laPoints[1].field_0.SetGtV3d(lLeft);
    laPoints[1].field_10 = kLeftUV;
    laPoints[2].field_0.SetGtV3d(lBottom);
    laPoints[2].field_10 = kBottomUV;
    laPoints[3].field_0.SetGtV3d(lTop);
    laPoints[3].field_10 = kTopUV;
    laPoints[4].field_0.SetGtV3d(lBottom);
    laPoints[4].field_10 = kBottomUV;
    laPoints[5].field_0.SetGtV3d(lRight);
    laPoints[5].field_10 = kRightUV;
    BeginRendering__6B3Im3dFv();
    SetAlphaTestThreshold__6B3Im3dFf(0.078125f);
    SetTexture__6B3Im3dFP10CGtTexture(self->field_C);
    RenderTrilist__6B3Im3dFPC13CB3Im3dVertexi(laPoints, 6);
    EndRendering__6B3Im3dFv();
}
