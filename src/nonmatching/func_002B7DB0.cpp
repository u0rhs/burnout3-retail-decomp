// NONMATCHING: func_002B7DB0 -- retail 112 / ours 115 instructions, 43 in changed runs
// fix1 (2026-11-01): plane test sense was inverted (retail 0x2B7E40 c.lt.s + bc1f: update when the end is not inside); found by the port6 checker | Before: repair1: header DotProduct/GetLength/operator*(float)/operator+=, GtMath::Abs, compiler-chosen vsub/vadd stand-ins (func_002B7DB0_inl1/2), operator-(WAxisType,float) stand-in inl3, p0 local copy (retail's 0x120 slot), clamp as dist = 0.005f; left: plane Normal() goes lq+qmtc2 (retail lqc2/sqc2), field_19/field_4 hoisted by const h (non-const: 50), if-body block placement (bc1t vs bc1f), d[] slot 0xC0 vs retail 0x70
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [C] fix1 (2026-11-01): 24/24 port6 live captures pass the Burn3 checker at tolerance 0 (result f0 and memory); 6 replay identical on the host (capture_replay) -- on those inputs


#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
// [G] a - b / a + b with compiler-chosen VU registers (retail `vsub.xyz $vf1,$vf7,$vf5`, `vadd.xyz $vf1,$vf5,$vf1`); the header's
// binary operators hard-code $vf1/$vf2 inputs
static inline CGtV3d func_002B7DB0_inl1(const CGtV3d& a, const CGtV3d& b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_002B7DB0_inl2(const CGtV3d& a, const CGtV3d& b)
{
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185 stand-in: operator-(WAxisType, float) (B3O0PCH map; no header body yet)
static inline WAxisType func_002B7DB0_inl3(WAxisType a, float f)
{
    u_long128 r;
    asm("qmtc2.ni %2, $vf2" "\n\t" "vsubx.w %0, %1, $vf2x" : "=j"(r) : "j"(a.lVector), "r"(f));
    return WAxisType(r);
}
struct UnkStruct_002B7DB0_h {
    unsigned char pad_0[4];
    CGtPlane *field_4;
    unsigned char pad_8[0x11];
    unsigned char field_19;
};
// 0x002B7DB0
extern "C" float func_002B7DB0(int *idx, const UnkStruct_002B7DB0_h *h, CGtV3d p0, CGtV3d p1)
{
    CGtV3d a = p0;
    float d[20];
    *idx = -1;
    CGtV3d end = p1 * 100.0f;
    end += a;
    for (int i = 0; i < h->field_19; i++) {
        CGtPlane pl = h->field_4[i];
        d[i] = DotProduct(end, pl.Normal());
        // fix1: the update runs when the end point is NOT inside this plane [C] retail 0x2B7E40 `c.lt.s d, dist; bc1f .L002B7ED8`
        if (!(d[i] < (float)pl.Distance())) {
            *idx = i;
            CGtPlane q = h->field_4[i];
            float e = DotProduct(a, q.Normal());
            if (!(e < (float)q.Distance())) return 0.005f;
            if (GtMath::Abs(d[i] - e) <= 0.0001f) continue;
            float w = (float)func_002B7DB0_inl3(q.Distance(), e);
            float t = w / (d[i] - e);
            end = func_002B7DB0_inl2(a, func_002B7DB0_inl1(end, a) * t);
        }
    }
    if (*idx < 0) { *idx = 0; return 0.005f; }
    float dist = func_002B7DB0_inl1(a, end).GetLength();
    if (dist < 0.005f) dist = 0.005f;
    return dist;
}
