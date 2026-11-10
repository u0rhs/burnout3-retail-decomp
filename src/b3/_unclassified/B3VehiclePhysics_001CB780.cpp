// CB3VehiclePhysics::IsVehicleTouchingHorizontalSurface(bool,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehiclePhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu10: Ghidra draft; two Normalise forms ([L] N185 stand-ins: compiler-chosen with 1.0*Q; GPR/vf1 form with header GetSquaredLength, split qmtc2 l and a volatile re-read of kYAxis [G]); header CosAngleBetweenNormalisedVectors; acosf = func_0011E328; wheel rows as byte-offset view; while (i--) int counter; nested return false).

// CB3VehiclePhysics::IsVehicleTouchingHorizontalSurface(bool, float) -- hand-written (ghvu10, Ghidra draft).
// [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G].

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001CB780_cc4 { unsigned char pad_0[0x4AC]; signed char field_4AC[4]; };
struct UnkStruct_kYAxis { CGtV3d field_0; };
struct UnkStruct_001CB780_row { unsigned char pad_0[0x840]; CGtV3d field_840; unsigned char pad_850[0x83]; unsigned char field_8D3; };
class CB3VehiclePhysics {
public:
    bool IsVehicleTouchingHorizontalSurface(bool, float);
    unsigned char pad_0[0x170];
    CGtV3d field_170;
    unsigned char pad_180[0x18];
    void *field_198;
    unsigned char pad_19C[0x76];
    unsigned char field_212;
    unsigned char pad_213[0xAB1];
    UnkStruct_001CB780_cc4 *field_CC4;
    unsigned char pad_CC8[0x4A1];
    signed char field_1169;
};
extern UnkStruct_kYAxis kYAxis;
extern "C" float func_0011E328(float);  // [L] acosf (E_B3DEBUG map: LIBM.A wf_acos.o at this address)

// [L] N185: Normalise on a compiler-chosen register that also forms 1.0*Q (as func_0027BCE0_inl1).
static inline void func_001CB780_inl1(CGtV3d &v)
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
static inline float func_001CB780_inl2(XAxisType x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector)); return f; }

// [L] N185: Normalise of a constant vector, the vector routed through a GPR onto $vf1 (retail's second form: header
// GetSquaredLength, then `qmtc2 l,$vf1` split off as header Normalise does, the vector re-read [G volatile pun: retail loads
// kYAxis twice, lqc2 for the square and lq for the scale], `vmulq.xyz $vf1,$vf1,$Q`, 1.0*Q formed as in the first form).
static inline CGtV3d func_001CB780_inl3(const CGtV3d &v)
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

// 0x001CB780
bool CB3VehiclePhysics::IsVehicleTouchingHorizontalSurface(bool wheels, float maxAngle)
{
    if (field_212 && field_198) {
        CGtV3d n = field_170;
        func_001CB780_inl1(n);
        CGtV3d y = func_001CB780_inl3(kYAxis.field_0);
        if (57.29578018f * func_0011E328(func_001CB780_inl2(CosAngleBetweenNormalisedVectors(n, y))) < maxAngle) return true;
    }
    if (wheels) {
        int i = field_1169;
        while (i--) {
            UnkStruct_001CB780_row *w = (UnkStruct_001CB780_row *)((char *)this + i * 0xC0);
            if (w->field_8D3 && field_CC4->field_4AC[i] != 3) {
                CGtV3d n = w->field_840;
                func_001CB780_inl1(n);
                CGtV3d y = func_001CB780_inl3(kYAxis.field_0);
                if (57.29578018f * func_0011E328(func_001CB780_inl2(CosAngleBetweenNormalisedVectors(n, y))) < maxAngle) return true;
            }
        }
        return false;
    }
    return false;
}
