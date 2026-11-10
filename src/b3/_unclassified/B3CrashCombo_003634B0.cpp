// CB3CrashCombo::GetSideFacingUp(const GtMathPs2::CGtMatrix3x4&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu14: Ghidra draft + IsVehicleTouchingHorizontalSurface normalise stand-ins; row copied before the kYAxis normalise (lq+qmtc2)).

// CB3CrashCombo::GetSideFacingUp(const CGtMatrix3x4&) -- hand-written (ghvu14, Ghidra draft).
// [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// ghvu14: the angle between kYAxis and each matrix row (rows 1, 2, 0), with IsVehicleTouchingHorizontalSurface's two
// Normalise stand-ins ([L] N185), header CosAngleBetweenNormalisedVectors, acosf = func_0011E328 [L], 57.29578 rad->deg.
// Static: a0 is the matrix (no `this` read) [C asm]. Return values 0..6 [G] meaning (side index).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_kYAxis { CGtV3d field_0; };
class CB3CrashCombo {
public:
    static int GetSideFacingUp(const CGtMatrix3x4 &);
};
extern UnkStruct_kYAxis kYAxis;
extern "C" float func_0011E328(float);  // [L] acosf (E_B3DEBUG map: LIBM.A wf_acos.o at this address)

// [L] N185: Normalise on a compiler-chosen register that also forms 1.0*Q (as func_0027BCE0_inl1).
static inline void func_003634B0_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one;
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData), "=&r"(one) : "r"(l.lVector));
    asm("qmtc2.i %1, $vf1" "\n\t" "qmfc2.i %0, %2" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1" : "=r"(r.mData), "+r"(one) : "j"(v.mData));
    asm(".set reorder");
    v = r;
}
// [L] N185: XAxisType -> float without the address-taken read.
static inline float func_003634B0_inl2(XAxisType x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector)); return f; }

// [L] N185: Normalise of a constant vector, the vector routed through a GPR onto $vf1 (retail's second form: header
// GetSquaredLength, then `qmtc2 l,$vf1` split off as header Normalise does, the vector re-read [G volatile pun: retail loads
// kYAxis twice, lqc2 for the square and lq for the scale], `vmulq.xyz $vf1,$vf1,$Q`, 1.0*Q formed as in the first form).
static inline CGtV3d func_003634B0_inl3(const CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one;
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2.i %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1" "\n\t"
        "qmtc2.i %1, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1"
        : "=&r"(r.mData), "=&r"(one) : "r"(*(volatile const u_long128 *)&v.mData));
    asm(".set reorder");
    return r;
}

static inline float func_003634B0_inl4(const CGtV3d &row)
{
    CGtV3d n = row;
    CGtV3d y = func_003634B0_inl3(kYAxis.field_0);
    func_003634B0_inl1(n);
    return 57.29578018f * func_0011E328(func_003634B0_inl2(CosAngleBetweenNormalisedVectors(y, n)));
}
// 0x003634B0
int CB3CrashCombo::GetSideFacingUp(const CGtMatrix3x4 &m)
{
    float a = func_003634B0_inl4(m.mUp);
    if (a < 40.0f) return 1;
    if (a > 140.0f) return 2;
    a = func_003634B0_inl4(m.mAt);
    if (a < 40.0f) return 3;
    if (a > 140.0f) return 4;
    a = func_003634B0_inl4(m.mRight);
    if (a < 40.0f) return 6;
    if (a > 140.0f) return 5;
    return 0;
}
