// CB3AICar::CalcSeparationAlongTrack(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (safe-normalise as static inline CGtV3d inl(CGtV3d v by value, const CGtV3d &fallback) with local dir returned: dir's slot lowest like retail).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3RaceCar { public: unsigned char pad_0[0x30]; CGtV3d field_30; };
class CB3AICar {
public:
    float CalcSeparationAlongTrack(CB3RaceCar *p0);
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    CGtV3d field_30;
    unsigned char pad_40[0x1890];
    CGtV3d field_18D0;
};
// [L] N185 stand-ins (no header API yet): compiler-chosen vsub with the result on the other operand's register (v296),
// XAxisType unary minus (Revenge stabs list it; B3 header lacks it), Normalise with the vector on a compiler-chosen register.
static inline CGtV3d near20_sub(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}
static inline XAxisType near20_neg(XAxisType a)
{
    u_long128 t;
    asm("qmtc2.i %1, $vf1" "\n\t" "vsub.x $vf1, $vf0, $vf1" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "r"(a.lVector));
    return XAxisType(t);
}
static inline void near20_norm(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 t;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v.mData));
    asm(".set reorder");
    v.mData = t;
}
static inline CGtV3d func_001419F0_inl1(CGtV3d fwd, const CGtV3d &alt)
{
    CGtV3d dir;
    if (!(fwd.GetSquaredLength() < 2.3283064e-10f)) {
        near20_norm(fwd);
        dir = fwd;
    } else {
        dir = alt;
    }
    return dir;
}
// 0x001419F0
float CB3AICar::CalcSeparationAlongTrack(CB3RaceCar *p0)
{
    CGtV3d fwd = field_18D0;
    CGtV3d d = near20_sub(field_30, p0->field_30);
    d.SetY(0.0f);
    fwd.SetY(0.0f);
    CGtV3d dir = func_001419F0_inl1(fwd, field_20);
    return near20_neg(DotProduct(d, dir));
}
