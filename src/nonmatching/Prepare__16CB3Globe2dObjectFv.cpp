// NONMATCHING: Prepare__16CB3Globe2dObjectFv -- retail 787 / ours 658 instructions, 719 in changed runs
// draftAD C-first: CGt2dObject::Prepare + AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(0x13) globe tables, 33x65 grid: sphere normal (CreateRotationMatrix3x4 kUp yaw then its mRight pitch, .mUp), flat map point turned about kUp (TransformPoint), flat map point; every VU/FPU arithmetic op count equal; residue: retail keeps CreateRotationMatrix3x4's XAxisType(u_long128) out of line (func_0023E3D0 x6; inline_depth 2..6 do not reproduce it) -> its copies, saved f20-f24, frame 0xBA0 vs 0x360
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded (asm + Ghidra); per-mnemonic counts equal for all VU and FPU arithmetic; calls equal except the 6 out-of-line XAxisType(u_long128) ctor copies (an inlining-depth artifact, not logic)

// CB3Globe2dObject::Prepare() -- hand-written C-first draft (draftAD, 2026-10-31); the lifter refused it. No Revenge counterpart.
// [C] name: retail symbol table. [L] reading: the 2d object is prepared (no position/size, colour D_01E90350, _Render, 0x40, 0x18), then
// the shared globe tables (AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki block 0x13 -> gmpStaticGlobeData) are built once: 33 latitude rows x 65 longitude columns
// (lat = (i-16)/16, lon = (j-32)/32), per point
//   field_0     = the unit sphere normal: about kUp by -180*lon degrees, then about that frame's right axis by 90*lat - 90;
//   field_8610  = the flat map point (kUp * clamped lat / 0.875 - D_004CA100) turned about kUp by -180*lon;
//   field_10C20 = the flat map point kRight * 2*lon + kUp * clamped lat / 0.875 (lat clamped to +-0.875).
// VU math: header CreateRotationMatrix3x4 x3 and TransformPoint; retail keeps CreateRotationMatrix3x4's two XAxisType(u_long128)
// constructions out of line (func_0023E3D0, 6 calls) -- the scoped inline_depth below (as ImpactBody's archive) [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;
#pragma push
#pragma inline_depth(6)   // [G] N262/N182: leaves retail's out-of-line XAxisType(u_long128) (func_0023E3D0)

struct UnkStruct_003B55A0_data {   // [G] 3 x 33 x 65 CGtV3d (0x8610 each: retail's +0x8610 / +0x10C20 tables)
    CGtV3d field_0[33][65];
    CGtV3d field_8610[33][65];
    CGtV3d field_10C20[33][65];
};
class CGt2dObject;
class CB3Globe2dObject {
public:
    int Prepare();
    static UnkStruct_003B55A0_data * gmpStaticGlobeData;   // [C] name: gmpStaticGlobeData__16CB3Globe2dObject
    unsigned char pad_0[0x38];
};
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
extern UnkStruct_theMemMgr theMemMgr;
extern CGtV4d D_01E90350;     // [L] a CB3MenuPageManager colour (field_110, BRIEF big2 notes)
extern CGtV3d kRight, kUp;    // [C] names: symbol table
extern CGtV3d D_004CA100;     // (0, 0, 0) [G] the map's origin offset
extern float D_004E06F0;      // 0.017453292 (degrees -> radians)
extern "C" void * AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void _Render__16CB3Globe2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const void *, const void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(
    void *, const CGtV2d &, const CGtV2d &, const CGtV4d *, const void *, unsigned int, unsigned int);

// [G] the latitude clamp used for the flat map (inlined twice)
static inline float func_003B55A0_inl1(float lat)
{
    float c = lat;
    if (!(lat <= 0.875f)) c = 0.875f;
    else if (lat < -0.875f) c = -0.875f;
    return c;
}

// 0x003B55A0
int CB3Globe2dObject::Prepare()
{
    CGtV2d d0(0.0f, 0.0f);
    CGtV2d d1(0.0f, 0.0f);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(
        this, d0, d1, &D_01E90350, (const void *)&_Render__16CB3Globe2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 0x40, 0x18);
    UnkStruct_003B55A0_data * d = (UnkStruct_003B55A0_data *)AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0x13, 0);
    gmpStaticGlobeData = d;
    if (d == 0) return 0;
    for (int i = 0; i < 33; i++) {
        float lat = (float)(i - 16) / 16.0f;
        float lrPitch = 90.0f * lat - 90.0f;
        for (int j = 0; j < 65; j++) {
            float lon = (float)(j - 32) / 32.0f;
            d->field_10C20[i][j] = kRight * (2.0f * lon) + kUp * (func_003B55A0_inl1(lat) / 0.875f);
            float lrYaw = D_004E06F0 * (-180.0f * lon);
            CGtMatrix3x4 lYaw = CreateRotationMatrix3x4(kUp, lrYaw);
            CGtMatrix3x4 lPitch = CreateRotationMatrix3x4(lYaw.mRight, D_004E06F0 * lrPitch);
            d->field_0[i][j] = lPitch.mUp;
            CGtMatrix3x4 lMap = CreateRotationMatrix3x4(kUp, lrYaw);
            d->field_8610[i][j] = TransformPoint(lMap, -D_004CA100 + kUp * (func_003B55A0_inl1(lat) / 0.875f));
        }
    }
    return 1;
}
#pragma pop
