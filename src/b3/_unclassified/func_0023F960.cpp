// Hand-written; the lifter refused it (near20: one static inline 'bool k = a && b; return k;' range test used for X/Y/Z in one && chain).

// func_0023F960: per-lane range test of a vector ([-5, 5] on X, Y, Z); clears *out on failure.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [G] unnamed inlined helper; a named bool result gives retail's andi/beqz pattern
static inline bool func_0023F960_inl1(float v) { bool k = v <= 5.0f && v >= -5.0f; return k; }
// 0x0023F960
extern "C" void func_0023F960(const CGtV4d *p0, bool *out)
{
    CGtV4d c;
    c = *p0;
    *out = true;
    if (!(func_0023F960_inl1(c.X()) && func_0023F960_inl1(c.Y()) && func_0023F960_inl1(c.Z()))) *out = false;
}
