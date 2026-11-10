#include "b3/gamesource/Physics/B3CollidingBody.h"

// Hand-inlined, not a plain field-by-field translation: retail interleaves the independent VU0
// zero-computes for field_F0/field_100/field_110/field_120 around the mpMatrix load/copy to hide
// its load-use latency, then batches all four stores afterward (verified: a straightforward
// `field.Zero()`-per-statement translation, in any source order, compiles each Zero() as an
// atomic compute+store pair with no cross-statement scheduling -- confirmed empirically this
// session, not assumed). Same technique already precedented in this header for
// CGtV3d::GetSquaredLength (see GtMathPs2.h's "VU0 GPR spill pattern" note).
void CB3CollidingBody::StopImmediately()
{
    asm volatile(
        "vadd.xyz  $vf1, $vf0, $vf0"   "\n\t"
        "sqc2      $vf1, 0xD0(%0)"     "\n\t"
        "vadd.xyz  $vf1, $vf0, $vf0"   "\n\t"
        "sqc2      $vf1, 0xE0(%0)"     "\n\t"
        "vsub.xyzw $vf1, $vf0, $vf0"   "\n\t"
        "sqc2      $vf1, 0xB0(%0)"     "\n\t"
        "lw        $v1,  0x204(%0)"    "\n\t"
        "vadd.xyz  $vf4, $vf0, $vf0"   "\n\t"
        "vadd.xyz  $vf3, $vf0, $vf0"   "\n\t"
        "lq        $v1,  0x20($v1)"    "\n\t"
        "vadd.xyz  $vf2, $vf0, $vf0"   "\n\t"
        "sq        $v1,  0xC0(%0)"     "\n\t"
        "vadd.xyz  $vf1, $vf0, $vf0"   "\n\t"
        "sqc2      $vf4, 0xF0(%0)"     "\n\t"
        "sqc2      $vf3, 0x100(%0)"    "\n\t"
        "sqc2      $vf2, 0x110(%0)"    "\n\t"
        "sqc2      $vf1, 0x120(%0)"    "\n\t"
        "vadd.xyz  $vf1, $vf0, $vf0"   "\n\t"
        "sqc2      $vf1, 0x130(%0)"
        :
        : "r"(this)
        : "v1", "vf1", "vf2", "vf3", "vf4"
    );
}
