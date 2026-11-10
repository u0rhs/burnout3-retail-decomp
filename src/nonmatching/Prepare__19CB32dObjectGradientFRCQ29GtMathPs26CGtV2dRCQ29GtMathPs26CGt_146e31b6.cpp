// NONMATCHING: Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df -- retail 100 / ours 112 instructions, 127 in changed runs
// v241 first draft: logic believed right (8 colour lanes * 255 -> bytes at +0x20..0x27 via lane*float stand-ins, f at +0x28, base Prepare(pos - size*anchor, size, CGtV4d(1,1,1,1), _Render, 0x40, 0xC)); 112 vs 100 instrs: ours spills to s0-s3 and schedules differently; frame 0x210 vs 0x250. Header gap: operator*(X/Y/Z/WAxisType, float) (B3O0PCH, 0x50 each)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00352F50_d {
    unsigned char field_0[4];
    unsigned char field_4[4];
    float field_8;
};
struct UnkStruct_00352F50 {
    unsigned char pad_0[0x20];
    UnkStruct_00352F50_d field_20;
};
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
struct UnkStruct_00352F50_fn { unsigned char pad_0[0x10]; };
extern UnkStruct_00352F50_fn _Render__19CB32dObjectGradientFRCQ211CGt2dObject16CGt2dObjectSpacePCv;

// [L] N185: stand in for GtMathPs2::operator*(XAxisType/YAxisType/ZAxisType/WAxisType, float) (B3O0PCH map, 0x50 bytes each):
// the scalar moved by its own statement, then the lane product, compiler-chosen registers
static inline XAxisType v241_xmul(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }
static inline YAxisType v241_ymul(YAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return YAxisType(r); }
static inline ZAxisType v241_zmul(ZAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.z %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return ZAxisType(r); }
static inline WAxisType v241_wmul(WAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return WAxisType(r); }
static inline CGtV2d func_00352F50_inl1(const CGtV2d &a, const CGtV2d &b) { return a - b; }

extern "C" void Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(
    UnkStruct_00352F50 * self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const CGtV4d c0, const CGtV4d c1, float f)
{
    UnkStruct_00352F50_d * d = &self->field_20;
    d->field_0[0] = (int)(float)v241_xmul(c0.X(), 255.0f);
    d->field_0[1] = (int)(float)v241_ymul(c0.Y(), 255.0f);
    d->field_0[2] = (int)(float)v241_zmul(c0.Z(), 255.0f);
    d->field_0[3] = (int)(float)v241_wmul(c0.W(), 255.0f);
    d->field_4[0] = (int)(float)v241_xmul(c1.X(), 255.0f);
    d->field_4[1] = (int)(float)v241_ymul(c1.Y(), 255.0f);
    d->field_4[2] = (int)(float)v241_zmul(c1.Z(), 255.0f);
    d->field_4[3] = (int)(float)v241_wmul(c1.W(), 255.0f);
    d->field_8 = f;
    CGtV2d tp = func_00352F50_inl1(pos, size * anchor);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(
        self, tp, size, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), (const void *)&_Render__19CB32dObjectGradientFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 64, 12);
}
