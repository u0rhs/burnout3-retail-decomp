// Hand-written; the lifter refused it (near18: compiler-chosen vsub + GetLength stand-in with 1.0/result in one GPR + local mtc1 (no operator float slot); store via field_0[n-1]).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002F5770_e { CGtV3d field_0; unsigned char pad_10[0x10]; float field_20; unsigned char pad_24[0xC]; };
struct UnkStruct_002F5770 { UnkStruct_002F5770_e field_0[0x32]; float field_960; int field_964; };
// [G] CGtV3d::GetLength stand-in (near18): retail keeps the 1.0 and the result in one GPR (the header's tail uses two,
// near9 note); the lane moved to the FPR without the operator float slot.
static inline u_long128 func_002F5770_inl1(const CGtV3d& v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r;
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vsqrt $Q, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %0, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1"
        : "=&r"(r) : "r"(l.lVector));
    asm(".set reorder");
    return r;
}
// 0x002F5770
extern "C" void func_002F5770(UnkStruct_002F5770 *self, const CGtV3d *p)
{
    CGtV3d pos = *p;
    int n = self->field_964;
    if (n == 0) {
        self->field_960 = 0.0f;
    } else {
        UnkStruct_002F5770_e *prev = &self->field_0[n - 1];
        u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(prev->field_0.mData), "j"(pos.mData));
        CGtV3d v(t);
        float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(func_002F5770_inl1(v)));
        self->field_0[n - 1].field_20 = f;
        self->field_960 += self->field_0[self->field_964 - 1].field_20;
    }
    self->field_0[self->field_964].field_0 = pos;
    self->field_964++;
}
