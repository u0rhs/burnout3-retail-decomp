// NONMATCHING: Downsample__13CB3RadialBlurFUlUlUlUliiii -- retail 97 / ours 97 instructions, 71 in changed runs
// 97/97, 71 changed: ported from the CB3DirectionalBlur::Downsample archive (member, 8th arg on stack); a shared 'six' local for the 6 in both halves cut 83->71. Left: GIF quad scheduling/register allocation (retail computes A/B dsll32 before loading p).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"

struct UnkStruct_farFogPlane { u_long128 * field_0; };
class CB3RadialBlur {
public:
    void Downsample(unsigned long a, unsigned long b, unsigned long c, unsigned long d, int e, int f, int g, int h);
};
extern UnkStruct_farFogPlane farFogPlane;

// 0x002FA770
void CB3RadialBlur::Downsample(unsigned long a, unsigned long b, unsigned long c, unsigned long d, int e, int f, int g, int h)
{
    int n = (e + g + 31) / 32 - e / 32;
    unsigned long x0 = a << 5 | b << 14;
    int Ai = (e << 4) + 16;
    int Bi = ((e + g) << 4) + 16;
    int Ci = g << 3;
    unsigned long x1 = c | d << 16;
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(3 | 0x10AB400000000000UL), "r"(14));
    unsigned long six = 6;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(x0 | (0xA8000000UL | six << 32)), "r"(six));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(x1), "r"(0x4C));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2A), "r"(0x42));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(unsigned)n | 0x4400000000000000UL), "r"(0x5353));
    long y0 = (long)((f << 4) + 16) << 16;
    long y1 = (long)(((f + h) << 4) + 16) << 16;
    long y2 = (long)(h << 3) << 16;
    long A = Ai, B = Bi, C = Ci;
    long hi = 0;
    do {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(A | y0), "r"(hi));
        if (--n != 0) { A = (A + 0x200) & ~31UL; hi = (hi + 0x100) & ~15UL; }
        else { A = B; hi = C; }
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(A | y1), "r"(hi | y2));
    } while (n != 0);
    farFogPlane.field_0 = p;
}

