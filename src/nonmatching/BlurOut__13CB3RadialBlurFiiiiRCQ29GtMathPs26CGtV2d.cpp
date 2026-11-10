// NONMATCHING: BlurOut__13CB3RadialBlurFiiiiRCQ29GtMathPs26CGtV2d -- retail 162 / ours 162 instructions, 18 in changed runs
// gif7: structure exact (two do-while 4-quad loops, quad3 CSE'd with quad1, <<16 terms written inline so LICM hoists them; long y0/y1/ya/yb); left 18: hoisted y0/y1 <<16 registers (retail a1/a2/t0/t1 = y0/y1/yb/ya, ours y1/y0/yb/ya) and q0's pcpyld output reusing px. Inert: 128 '|' operand orders, asm operand order (q0/q1), 24 loop statement orders, u_long128 locals, explicit preheader invariants (132), 15 pragmas
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_farFogPlane farFogPlane;

class CB3RadialBlur {
public:
    void BlurOut(int p0, int p1, int p2, int p3, const CGtV2d& v);
};

// 0x002FA130
void CB3RadialBlur::BlurOut(int p0, int p1, int p2, int p3, const CGtV2d& v)
{
    int x16 = p0 << 4;
    float u0 = 8.5f + (float)x16;
    long y0 = p1 << 4;
    int dy = (p3 - p1) << 4;
    long y1 = p3 << 4;
    float vy = v.Y();
    float fy0 = (float)(p1 << 4);
    long ya = (int)(fy0 - fy0 * vy);
    long yb = (int)(fy0 + (float)dy * vy);
    float vx = v.X();
    int n1 = (p0 + 31) / 32;
    int n2 = (p2 + 31) / 32 - p0 / 32;
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(unsigned)(n1 + n2) | 0x8400000000000000UL), "r"(0x53535353));
    int x = 0;
    int nx = 512;
    do {
        if (--n1 == 0) nx = x16;
        long s0 = (long)(int)(u0 - vx * (float)(x16 - x));
        long s1 = (long)(int)(u0 - vx * (float)(x16 - nx));
        long px = (long)x;
        long qx = (long)nx;
        x = nx;
        nx += 512;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(s0 | (ya << 16)), "r"(px));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(s1 | (y0 << 16)), "r"(qx | (y0 << 16)));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(s0 | (yb << 16)), "r"(px | (y1 << 16)));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(s1 | (y0 << 16)), "r"(qx | (y0 << 16)));
    } while (n1 != 0);
    x = p2 << 4;
    nx = (x - 1) & -512;
    do {
        if (--n2 == 0) nx = x16;
        long s0 = (long)(int)(u0 + vx * (float)(x - x16));
        long s1 = (long)(int)(u0 + vx * (float)(nx - x16));
        long px = (long)x;
        long qx = (long)nx;
        x = nx;
        nx -= 512;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(s1 | (ya << 16)), "r"(qx));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(s0 | (y0 << 16)), "r"(px | (y0 << 16)));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(s1 | (yb << 16)), "r"(qx | (y1 << 16)));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(s0 | (y0 << 16)), "r"(px | (y0 << 16)));
    } while (n2 != 0);
    farFogPlane.field_0 = p;
}

