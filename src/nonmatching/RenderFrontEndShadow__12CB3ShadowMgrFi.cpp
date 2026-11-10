// NONMATCHING: RenderFrontEndShadow__12CB3ShadowMgrFi -- retail 147 / ours 148 instructions, 21 in changed runs
// mat1 (N239): real CGtMatrix3x4 copies replace the char[16] pun: m (rows up/right/at, mPos unwritten) -> m2 = m (row-0 sq + three lb/sb loops, m2 not modified) -> m3 = m2 (lq/sq rows, then m3.mPos zeroed + SetY(0.005)); locals declared m3, a, b, m2, 7 N140 pads, m (frame exact); field_BB0 is 64-byte records (sll 6); D_00666270 sized [4] (not gp); b.mMax = a.mMax; b.mMin = a.mMin (box tail exact). Normalise stand-in = header GetSquaredLength + region {qmtc2 l; vrsqrt; vwaitq} + vmulq '+j' with qmfc2.i out. Left 21: the square lands on vf1 and is moved (retail: 1.0 on vf1, square on vf2), GPR v0/v1/a3 numbering of up and the normalised row follow
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (v257); the lifter refused it. CB3ShadowMgr::RenderFrontEndShadow(int). Field names placeholders [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00303750_16 { signed char b[16]; };
struct UnkStruct_00303750_pad { int x[4]; UnkStruct_00303750_pad() {} ~UnkStruct_00303750_pad() {} };
struct CGtAxisAlignedBox { CGtV3d mMin; CGtV3d mMax; };
struct UnkStruct_00303750_rec { CGtV3d field_0; unsigned char pad_10[0x30]; };   // [G] 64-byte records (retail sll 6)
struct UnkStruct_00303750_body {
    unsigned char pad_0[0xD];
    signed char field_D;
    unsigned char pad_E[0xBA2];
    UnkStruct_00303750_rec field_BB0[1];
    CGtV3d field_BF0;
    unsigned char pad_C00[0x280];
    CGtV3d field_E80;
    CGtV3d field_E90;
};
struct UnkStruct_00303750_car { unsigned char pad_0[0x20]; CGtV3d field_20; unsigned char pad_30[0x10]; UnkStruct_00303750_body * field_40; };
struct UnkStruct_00303750_66270_b { unsigned char pad_0[0x20]; CGtV4d field_20; };
struct UnkStruct_D_00666270 { unsigned char pad_0[0x68]; UnkStruct_00303750_66270_b * field_68; unsigned char pad_6C[0xC]; };
struct UnkStruct_D_01E85900_e { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_D_01E85900 { unsigned char pad_0[0x80]; UnkStruct_D_01E85900_e field_80[1]; };
struct UnkStruct_D_01E85A30 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00666270 * D_00666270[4];   // [G] sized so it is not $gp-addressed (as the proven a187 unit)
extern UnkStruct_D_01E85A30 D_01E85A30;
extern UnkStruct_D_01E85900 D_01E85900;
extern UnkStruct_00303750_car * D_0064D388[];
extern "C" void BeginShadowRendering__17CB3ShadowRendererFv();
extern "C" void BeginShadowPlaneRendering__17CB3ShadowRendererFv();
extern "C" void EndShadowPlaneRendering__17CB3ShadowRendererFv();
extern "C" void EndShadowRendering__17CB3ShadowRendererFv();
extern "C" void RenderAmbientVehicleShadow__17CB3ShadowRendererFRCQ29GtMathPs212CGtMatrix3x4RC17CGtAxisAlignedBoxRC17CGtAxisAlignedBoxfff(const CGtMatrix3x4 &, const CGtAxisAlignedBox &, const CGtAxisAlignedBox &, float, float, float);
class CB3ShadowMgr {
public:
    void RenderFrontEndShadow(int p0);
    CGtV4d field_0;
    unsigned char pad_10[0x10];
    CGtV3d field_20;
};
// [L] N185 stand-ins (compiler-chosen VU registers)
static inline u_long128 func_00303750_inl1() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
static inline void func_00303750_inl2(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" : : "r"(l.lVector));
    asm(".set reorder");
    u_long128 t, x = v.mData;
    asm("vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(x));
    v.mData = t;
}
static inline CGtV3d func_00303750_inl3(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm volatile("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
static inline void func_00303750_inl4(CGtV3d &v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.y %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }
static inline void func_00303750_inl5(CGtV3d &v, const CGtV3d &s) { asm("vaddz.z %0, $vf0, %1z" : "+j"(v.mData) : "j"(s.mData)); }
static inline void func_00303750_inl6(CGtV3d &v) { asm("vadd.xyz %0, $vf0, $vf0" : "=j"(v.mData)); }

// [G] a matrix-returning inline (the E map's Matrix3x4SetLookAt(CGtV3d, CGtV3d), 432 bytes, would fit: right =
// Normalise(up x at), at = right x up, mPos untouched) -- placeholder until a site settles it
static inline CGtMatrix3x4 func_00303750_inl7(CGtV3d at, CGtV3d up)
{
    CGtMatrix3x4 m;
    m.mUp = up;
    m.mRight = func_00303750_inl3(m.mUp, at);
    func_00303750_inl2(m.mRight);
    m.mAt = func_00303750_inl3(m.mRight, m.mUp);
    return m;
}

// 0x00303750
void CB3ShadowMgr::RenderFrontEndShadow(int p0)
{
    UnkStruct_00303750_car * car = D_0064D388[p0];
    field_0 = D_00666270[0]->field_68->field_20;
    field_20 = -D_01E85900.field_80[D_01E85A30.field_0].field_30;
    BeginShadowRendering__17CB3ShadowRendererFv();
    BeginShadowPlaneRendering__17CB3ShadowRendererFv();
    CGtMatrix3x4 m3;
    CGtAxisAlignedBox a;
    CGtAxisAlignedBox b;
    CGtMatrix3x4 m2;
    UnkStruct_00303750_pad p0_, p1_, p2_, p3_, p4_, p5_, p6_;
    CGtMatrix3x4 m;
    m.mUp = CGtV3d(0.0f, 1.0f, 0.0f);
    m.mRight = func_00303750_inl3(m.mUp, car->field_20);
    func_00303750_inl2(m.mRight);
    m.mAt = func_00303750_inl3(m.mRight, m.mUp);
    m2 = m;
    m3 = m2;
    func_00303750_inl6(m3.mPos);
    func_00303750_inl4(m3.mPos, 0.005f);
    a.mMax = car->field_40->field_E90;
    func_00303750_inl4(a.mMax, 0.0f);
    a.mMin = car->field_40->field_E80;
    func_00303750_inl4(a.mMin, 0.0f);
    b.mMax = a.mMax;
    b.mMin = a.mMin;
    func_00303750_inl5(b.mMax, car->field_40->field_BB0[car->field_40->field_D - 2].field_0);
    func_00303750_inl5(b.mMin, car->field_40->field_BF0);
    RenderAmbientVehicleShadow__17CB3ShadowRendererFRCQ29GtMathPs212CGtMatrix3x4RC17CGtAxisAlignedBoxRC17CGtAxisAlignedBoxfff(m3, a, b, 1.0f, 1.0f, 0.0f);
    EndShadowPlaneRendering__17CB3ShadowRendererFv();
    EndShadowRendering__17CB3ShadowRendererFv();
}
