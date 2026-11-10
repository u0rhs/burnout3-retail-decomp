// CB3CollidingBody.cpp (E map). Split out of game/unit_001AB6B0 2026-10-20 (Target #16), where it
// sat right after the much larger, not-yet-decompiled CollideWithWorld().
#include "b3/gamesource/Physics/B3CollidingBody.h"

extern "C" void *memset(void *s, int c, unsigned int n);

// Same idiom as N37/N38 (CB3CollidingBody::StopImmediately): a plain per-field .Zero() translation
// gets every value right but not retail's exact VU0 register reuse/interleaving (confirmed
// empirically -- the naive version used three different vf registers, one per field, instead of
// reusing $vf1 across all three with the third one's compute moved ahead of the scalar stores).
void CB3CollidingBody::StopCrashing()
{
    mbCrashing = false;
    field_218 = -1;
    field_20E = 0;
    memset(&field_160, 0, 0x60);
    asm volatile(
        "vadd.xyz $vf1, $vf0, $vf0"   "\n\t"
        "sqc2     $vf1, 0x160(%0)"    "\n\t"
        "vadd.xyz $vf1, $vf0, $vf0"   "\n\t"
        "sqc2     $vf1, 0x170(%0)"    "\n\t"
        "vadd.xyz $vf1, $vf0, $vf0"   "\n\t"
        "sh       $zero, 0x190(%0)"   "\n\t"
        "sw       $zero, 0x194(%0)"   "\n\t"
        "sw       $zero, 0x198(%0)"   "\n\t"
        "sqc2     $vf1, 0x150(%0)"
        :
        : "r"(this)
        : "vf1"
    );
}
