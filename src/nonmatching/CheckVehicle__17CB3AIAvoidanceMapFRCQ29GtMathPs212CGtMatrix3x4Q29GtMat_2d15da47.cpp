// NONMATCHING: CheckVehicle__17CB3AIAvoidanceMapFRCQ29GtMathPs212CGtMatrix3x4Q29GtMathPs26CGtV3dbb16EAIAvoidanceRiskRC17CGtAxisAlignedBox -- retail 303 / ours 308 instructions, 74 in changed runs
// near37: .set noreorder inside the NGL stand-in's asm string (hdr15) removes the mtc1/mfc1 hazard nops: 303/308, 74 changed. Left: carPos copied through a stack slot (sq/lq 432) where retail keeps it in t3 -> vf4 (all later carPos uses differ), frame 0x1D0 vs 0x260, p3 arm's adda/madd constant order (D_ loads before mtc1 zero), b in f4 vs f6, h = 0.5*K scheduled late
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// CB3AIAvoidanceMap::CheckVehicle(const CGtMatrix3x4&, CGtV3d, bool, bool, EAIAvoidanceRisk, const CGtAxisAlignedBox&)
// -- [C] name: the mangled symbol in retail's tables; file B3AIAvoidance.cpp (retail_names.csv). Fields are placeholders;
// every type is [G] (instruction widths). Hand-written (lifter refused: label in an if body reached from outside).

typedef unsigned int u_long128 __attribute__((mode(TI)));
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

enum EAIAvoidanceRisk {};
class CGtAxisAlignedBox;
struct UnkStruct_0013F090_y {
    unsigned char pad_0[0x30];
    CGtV3d field_30;
};
struct UnkStruct_0013F090_x {
    unsigned char pad_0[0xB0];
    CGtSphere field_B0;
    CGtV3d field_C0;
    unsigned char pad_D0[0x134];
    UnkStruct_0013F090_y * field_204;
};
struct UnkStruct_0013F090_own {
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    unsigned char pad_30[0x1AB0];
    CGtV3d field_1AE0;
    unsigned char pad_1AF0[0x940];
    UnkStruct_0013F090_x * field_2430;
    unsigned char pad_2434[4];
    float field_2438;
};
class CB3AIAvoidanceMap {
public:
    void CheckVehicle(const CGtMatrix3x4 &, CGtV3d, bool, bool, EAIAvoidanceRisk, const CGtAxisAlignedBox &);
    void AddCarToMap(EAIAvoidanceRisk, float, float, float, CGtV3d, CGtV3d, CGtV3d, CGtV3d, const CGtAxisAlignedBox &);
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    unsigned char pad_30[0x424];
    UnkStruct_0013F090_own * field_454;
};
extern float D_01E7551C[];
extern float D_01E75530[];
extern float D_01E75534[];
extern float D_01E75538[];
extern float D_01E7555C[];
extern float D_01E75560[];
extern float D_01E75564[];
extern float D_01E75568[];
// The callee by its link name with const CGtV3d& operands: retail passes m's rows by address with no caller copy.
extern "C" void AddCarToMap__17CB3AIAvoidanceMapF16EAIAvoidanceRiskfffQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dRC17CGtAxisAlignedBox(
    CB3AIAvoidanceMap *, EAIAvoidanceRisk, float, float, float, const CGtV3d &, const CGtV3d &, const CGtV3d &, const CGtV3d &,
    const CGtAxisAlignedBox &);
// [L] N185: stands in for CGtV3d::operator*(float) with retail's hard-coded body here (the header's earlier
// `qmtc2 v,$vf1; qmtc2.ni s,$vf2; vmulx.xyz $vf1,$vf1,$vf2x`, v288); the header body is compiler-chosen.
static inline CGtV3d func_0013F090_inl1(const CGtV3d & v, float s) {
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2.ni %2, $vf2" "\n\t" "vmulx.xyz $vf1, $vf1, $vf2x" "\n\t" "qmfc2 %0, $vf1"
        : "=r"(t) : "r"(v.mData), "r"(s));
    return CGtV3d(t);
}
// [L] DotProduct's body without its result move (retail leaves an unused dot's result in $vf1, no qmfc2).
static inline XAxisType func_0013F090_inl2(CGtV3d a, CGtV3d b)
{
    u_long128 m, one, t;
    asm("vmul.xyz %0, %1, %2" : "=j"(m) : "j"(a.mData), "j"(b.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm(".set noreorder");
    asm("vadday.x $ACC, %1, %1y" "\n\t" "vmaddz.x %0, %2, %1z" : "=j"(t) : "j"(m), "j"(one));
    asm(".set reorder");
    return XAxisType(t);
}
// [L] probe: NormaliseGetLength with the vector kept in its own VU register (retail `vmulq.xyz $vf3,$vf3,$Q`).
static inline XAxisType func_0013F090_inl3(CGtV3d & v) {
    XAxisType l = v.GetSquaredLength();
    u_long128 r, d = v.mData;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %0, $vf1" "\n\t" "mtc1 %0, %1" "\n\t" "sqrt.s %1, %1" "\n\t" "mfc1 %0, %1" "\n\t"
        "qmtc2 %0, $vf1" "\n\t" "qmfc2 %0, $vf1" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %2, %2, $Q" "\n\t" ".set reorder" : "=&r"(r), "=&f"(f), "+j"(d));
    asm(".set reorder");
    v.mData = d;
    return XAxisType(r);
}

// 0x0013F090
void CB3AIAvoidanceMap::CheckVehicle(const CGtMatrix3x4 & m, CGtV3d pos, bool p2, bool p3, EAIAvoidanceRisk risk, const CGtAxisAlignedBox & box)
{
    CGtV3d p = pos;
    CGtV3d fwd;
    CGtV3d d = field_454->field_2430->field_B0.Position() - p;
    float len;
    if (d.GetSquaredLength() < 2.3283064e-10f) {
        fwd = field_454->field_20;
        len = 0.1f;
    } else {
        len = func_0013F090_inl3(d);
        fwd = d;
        if (len < 0.1f)
            len = 0.1f;
    }
    CGtV3d carPos = m.mPos;
    CGtV3d rel = carPos - field_20;
    if (!(GtMath::Abs(rel.Y()) <= D_01E75534[0]))
        return;
    CGtV3d dir = rel;
    float dist = func_0013F090_inl3(dir);
    if (p2) {
        if (!(dist <= D_01E75530[0]))
            return;
        if (DotProduct(field_454->field_2430->field_C0, dir) < -0.3f)
            return;
        XAxisType facing = func_0013F090_inl2(fwd, dir);
        float h = 0.5f * D_01E75538[0];
        CGtV3d ahead = carPos + func_0013F090_inl1(p, D_01E75538[0]);
        AddCarToMap__17CB3AIAvoidanceMapF16EAIAvoidanceRiskfffQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dRC17CGtAxisAlignedBox(this, risk, DotProduct(field_454->field_1AE0, carPos - field_454->field_2430->field_204->field_30), dist, h,
                    carPos, ahead, m.mAt, m.mAt, box);
        return;
    }
    if (p3 && !(dist <= D_01E7551C[0]))
        return;
    float side = DotProduct(field_454->field_1AE0, rel);
    if (p3 && side < -field_454->field_2438 / 2.0f)
        return;
    float facing = DotProduct(fwd, dir);
    if (facing < 0.1f)
        facing = 0.1f;
    float a, b;
    if (dist < 12.0f) {
        a = 0.0f;
        b = a;
    } else {
        float t = dist / (facing * len);
        if (t < 0.0f)
            return;
        a = t - 0.5f * D_01E75538[0];
        if (!(a <= 8.0f))
            return;
        b = facing * (t * (float)field_454->field_2430->field_B0.Radius());  // [C] retail FPU form, not a VU lane op: 0x13F444 lwc1 / 0x13F448 mul.s (the cast keeps the port's PS2 float model)
    }
    if (p3) {
        float one = 1.0f;
        a = GtMath::Max(a + (D_01E75564[0] + one * D_01E7555C[0]), 0.0f);
        b = GtMath::Max((b + D_01E75568[0]) + one * D_01E75560[0], 0.0f);
    } else {
        a = 2.0f * GtMath::Max(a, 0.0f);
    }
    AddCarToMap__17CB3AIAvoidanceMapF16EAIAvoidanceRiskfffQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dRC17CGtAxisAlignedBox(this, risk, DotProduct(field_454->field_1AE0, m.mPos - field_454->field_2430->field_204->field_30), b / 1.5f, a,
                m.mPos, m.mPos, m.mAt, m.mAt, box);
}

