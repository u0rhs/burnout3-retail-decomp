// Hand-written; the lifter refused it (ghvu1: m-form temps a,b + [L] N185 const float& scale stand-in + scoped opt_propagation off [G]).

// Hand-written (ghvu1, Ghidra-draft trial): segment walk then a call on the two segment ends.
// [L] CGtV3d returned through the hidden pointer in a0 (retail sqc2 to 0(a0) in func_002F5860); self in a1, unread by the callee.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002F4F90_e { CGtV3d field_0; CGtV3d field_10; float field_20; unsigned char pad_24[0xC]; };
struct UnkStruct_002F4F90 { UnkStruct_002F4F90_e field_0[0x32]; float field_960; int field_964; };
extern "C" CGtV3d func_002F5860(UnkStruct_002F4F90 *self, const CGtV3d &a, const CGtV3d &b, const CGtV3d &c, const CGtV3d &d, float t);
// [L] N185: stands in for a missing GtMathPs2 inline -- CGtV3d * float with the scalar read by reference (retail
// `lw` straight into the GPR for each product; the header operator*(float) reuses the loop FPR via mfc1, 5 off).
static inline CGtV3d func_002F4F90_inl1(const CGtV3d &v, const float &s)
{
    u_long128 t, sv;
    asm("qmtc2 %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(sv));
    return CGtV3d(t);
}
// N182: opt_propagation off, [G] scoped to this function (retail keeps the loop test unpropagated / a,b temps order).
#pragma push
#pragma opt_propagation off
// 0x002F4F90
extern "C" CGtV3d func_002F4F90(UnkStruct_002F4F90 *self, float t)
{
    float target = t * self->field_960;
    float sum = 0.0f;
    int i = 0;
    float len;
    for (;;) {
        len = self->field_0[i].field_20;
        if (!(sum + len < target) || !(i <= 49)) break;
        sum += len;
        i++;
    }
    float r = (target - sum) / len;
    CGtV3d a = func_002F4F90_inl1(self->field_0[i].field_10, self->field_0[i].field_20);
    CGtV3d b = func_002F4F90_inl1(self->field_0[i + 1].field_10, self->field_0[i].field_20);
    return func_002F5860(self, self->field_0[i].field_0, a, self->field_0[i + 1].field_0, b, r);
}
#pragma pop
