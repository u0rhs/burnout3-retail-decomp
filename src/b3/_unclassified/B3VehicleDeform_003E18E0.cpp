// CB3VehicleDeform::GetClosestBitToPoint(const GtMathPs2::CGtV3d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3VehicleDeform has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (pass2b: mid+TransformPoint as a nested static inline (this, i) and the vsub written in the body give retail's VU numbering (8 -> 0)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_E0FE0_b { unsigned char pad_0[0xC]; signed char field_C; unsigned char pad_D[0xE93]; CGtV3d field_EA0[1][2]; };
struct UnkStruct_E0FE0_a { unsigned char pad_0[0x40]; UnkStruct_E0FE0_b* field_40; };
struct UnkStruct_E0FE0_r { CGtV3d rows[4]; };
struct UnkStruct_E0FE0_m { unsigned char pad_0[0x180]; UnkStruct_E0FE0_r field_180[1]; };
#include "b3/classes/UnkStruct_D_004E0C14.h"
extern UnkStruct_D_004E0C14 D_004E0C14;
class CB3VehicleDeform {
public:
    int GetClosestBitToPoint(const CGtV3d* p);
    unsigned char pad_0[0x10];
    UnkStruct_E0FE0_a* field_10;
    UnkStruct_E0FE0_m* field_14;
};
// [L] N185: stands in for a missing GtMathPs2 inline (TransformPoint(CGtMatrix3x4, CGtV3d)): row0 as a VU operand, rows 1-3 via $vf1
static inline CGtV3d TP(const CGtV3d* m, CGtV3d v)
{
    u_long128 t;
    asm(".set noreorder\n\t" "vmulax.xyz $ACC, %1, %2x" "\n\t" "qmtc2.ni %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %2y" "\n\t" "qmtc2.ni %4, $vf1" "\n\t"
        "vmaddaz.xyz $ACC, $vf1, %2z" "\n\t" "qmtc2.ni %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.ni %0, $vf1" "\n\t" ".set reorder"
        : "=r"(t) : "j"(m[0].mData), "j"(v.mData), "r"(m[1].mData), "r"(m[2].mData), "r"(m[3].mData));
    return CGtV3d(t);
}
static inline CGtV3d SUB(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
static inline CGtV3d ADD(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
static inline CGtV3d HALF(CGtV3d a, float s)
{
    u_long128 t;
    asm("qmtc2.ni %2, %0" "\n\t" "vmulx.xyz %0, %1, %0x" : "=j"(t) : "j"(a.mData), "r"(s));
    return CGtV3d(t);
}
// 0x003E18E0
// [G] pass2b: unnamed inlined helper (midpoint of the bone pair, transformed). As a nested inline it numbers the VU
// registers like retail (row0/half/one/pp = vf3/4/5/6); the vsub is written in the body for the same reason.
static inline CGtV3d func_003E18E0_inl1(CB3VehicleDeform* self, int i)
{
    UnkStruct_E0FE0_b* b = self->field_10->field_40;
    CGtV3d mid = (b->field_EA0[i][1] + b->field_EA0[i][0]) * 0.5f;
    return TP(self->field_14->field_180[i].rows, mid);
}
int CB3VehicleDeform::GetClosestBitToPoint(const CGtV3d* p)
{
    float best = 3.402823466e+38f;
    int idx = -1;
    CGtV3d pp = *p;
    for (int i = 0; i < field_10->field_40->field_C; i++) {
        CGtV3d w = func_003E18E0_inl1(this, i);
        u_long128 t;
        asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(w.mData), "j"(pp.mData));
        CGtV3d dv(t);
        float d = dv.GetSquaredLength();
        if (d < best) { best = d; idx = i; }
    }
    return idx;
}
