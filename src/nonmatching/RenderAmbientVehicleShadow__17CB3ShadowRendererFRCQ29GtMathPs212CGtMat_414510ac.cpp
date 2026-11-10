// NONMATCHING: RenderAmbientVehicleShadow__17CB3ShadowRendererFRCQ29GtMathPs212CGtMatrix3x4RC17CGtAxisAlignedBoxRC17CGtAxisAlignedBoxfff -- retail 114 / ours 114 instructions, 6 in changed runs
// psweep: scoped #pragma opt_propagation off [G] improves 10 -> 6
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off
using namespace GtMathPs2;
namespace GtMathPs2 {
// [L] N185: stand-ins for missing/mismatching GtMathPs2 inlines.
// CGtV3d::CGtV3d(float,float,float) (B3O0PCH map, 72 bytes; not in the header): lane stores into the object.
static inline CGtV3d func_00303A40_inl1(float x, float y, float z) { union { u_long128 q; float f[4]; } r; r.f[0] = x; r.f[1] = y; r.f[2] = z; return CGtV3d(r.q); }
// CGtV3d::SetX(XAxisType) / SetZ(ZAxisType) (B3O0PCH map, 56 bytes) on compiler-chosen registers (the header hard-codes $vf1/$vf2)
static inline void SetXc(CGtV3d &d, XAxisType a) { XAxisType c = a; asm("vaddx.x %0, $vf0, %1x" : "+j"(d.mData) : "j"(*(const u_long128*)&c.lVector)); }
static inline void SetZc(CGtV3d &d, ZAxisType a) { XAxisType c(*(const XAxisType*)&a); asm("vaddz.z %0, $vf0, %1z" : "+j"(d.mData) : "j"(*(const u_long128*)&c.lVector)); }
}
struct CGtAxisAlignedBox { CGtV3d field_0; CGtV3d field_10; };
struct CB3Im3dVertex {
    CGtV3dPlus field_0;
    int field_10;
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char field_1B;
    int field_1C;
};
extern CB3Im3dVertex *_gpCache;
extern "C" void RenderTristrip__6B3Im3dFRCQ29GtMathPs212CGtMatrix3x4PC13CB3Im3dVertexi(const CGtMatrix3x4 &, const CB3Im3dVertex *, int);
static inline void func_00303A40_inl2(CB3Im3dVertex &v, int a) { v.field_18 = 0x80; v.field_19 = 0x80; v.field_1A = 0x80; v.field_1B = a; }
static inline float func_00303A40_inl3(float a, float b, float t) { return a + (b - a) * t; }
// [G] N140 frame pad: nine dead 16-byte slots of retail's frame above the corner temporaries
struct UnkStruct_00303A40_pad { int x[36]; UnkStruct_00303A40_pad() {} ~UnkStruct_00303A40_pad() {} };
class CB3ShadowRenderer {
public:
    static void RenderAmbientVehicleShadow(const CGtMatrix3x4 &m, const CGtAxisAlignedBox &a, const CGtAxisAlignedBox &b, float f0, float f1, float f2);
};

// 0x00303A40
void CB3ShadowRenderer::RenderAmbientVehicleShadow(const CGtMatrix3x4 &m, const CGtAxisAlignedBox &a, const CGtAxisAlignedBox &b, float f0, float f1, float f2)
{
    UnkStruct_00303A40_pad pad;
    CGtV3d base(0.0f, f2, 0.0f);
    CGtV3d p0 = base; SetXc(p0, a.field_10.X()); SetZc(p0, a.field_0.Z()); _gpCache[0].field_0.SetGtV3d(p0);
    CGtV3d p1 = base; SetXc(p1, a.field_0.X()); SetZc(p1, a.field_0.Z()); _gpCache[1].field_0.SetGtV3d(p1);
    CGtV3d p2 = base; SetXc(p2, a.field_10.X()); SetZc(p2, b.field_0.Z()); _gpCache[2].field_0.SetGtV3d(p2);
    CGtV3d p3 = base; SetXc(p3, a.field_0.X()); SetZc(p3, b.field_0.Z()); _gpCache[3].field_0.SetGtV3d(p3);
    CGtV3d p4 = base; SetXc(p4, a.field_10.X()); SetZc(p4, b.field_10.Z()); _gpCache[4].field_0.SetGtV3d(p4);
    CGtV3d p5 = base; SetXc(p5, a.field_0.X()); SetZc(p5, b.field_10.Z()); _gpCache[5].field_0.SetGtV3d(p5);
    CGtV3d p6 = base; SetXc(p6, a.field_10.X()); SetZc(p6, a.field_10.Z()); _gpCache[6].field_0.SetGtV3d(p6);
    CGtV3d p7 = base; SetXc(p7, a.field_0.X()); SetZc(p7, a.field_10.Z()); _gpCache[7].field_0.SetGtV3d(p7);
    float l = func_00303A40_inl3(0.0f, 90.0f, f1);
    int alpha = (int)(l * f0);
    func_00303A40_inl2(_gpCache[0], alpha);
    func_00303A40_inl2(_gpCache[1], alpha);
    func_00303A40_inl2(_gpCache[2], alpha);
    func_00303A40_inl2(_gpCache[3], alpha);
    func_00303A40_inl2(_gpCache[4], alpha);
    func_00303A40_inl2(_gpCache[5], alpha);
    func_00303A40_inl2(_gpCache[6], alpha);
    func_00303A40_inl2(_gpCache[7], alpha);
    RenderTristrip__6B3Im3dFRCQ29GtMathPs212CGtMatrix3x4PC13CB3Im3dVertexi(m, _gpCache, 8);
}

#pragma pop
