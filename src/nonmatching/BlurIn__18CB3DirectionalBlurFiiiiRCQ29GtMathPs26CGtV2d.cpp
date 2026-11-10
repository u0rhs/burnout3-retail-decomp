// NONMATCHING: BlurIn__18CB3DirectionalBlurFiiiiRCQ29GtMathPs26CGtV2d -- retail 206 / ours 204 instructions, 238 in changed runs
// logic-complete hand-write (lifter refused pmaxw); 204 vs 206 instrs; left: prelude scheduling/float reg numbering, 3rd s-reg (s2) and 0x50 frame, loop temp reg allocation
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3DirectionalBlur::BlurIn/BlurOut -- hand-written (lifter refused: pmaxw). GIF reglist quads (ST,XYZ2) x4 per loop.
#include "b3/GtMathPs2.h"
struct UnkStruct_farFogPlane { u_long128 * field_0; };
class CB3DirectionalBlur {
public:
    static void BlurIn(int a, int b, int c, int d, const GtMathPs2::CGtV2d &v);
    static void BlurOut(int a, int b, int c, int d, const GtMathPs2::CGtV2d &v);
};
extern UnkStruct_farFogPlane farFogPlane;
static inline int a237_pmaxw(int a, int b) { int r; asm("pmaxw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int a237_pminw(int a, int b) { int r; asm("pminw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int a237_pextlw(int a) { int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
union UnkStruct_00426290_fu { float f; unsigned int u; };
void CB3DirectionalBlur::BlurIn(int a, int b, int c, int d, const GtMathPs2::CGtV2d &v)
{
    int x16 = a << 4;
    int y16 = d << 4;
    int cl = a237_pextlw(a237_pminw(a237_pmaxw(b, 0), d));
    int cl16 = cl << 4;
    float k = 0.0009765625f;
    float fb = (float)b;
    float u0 = k * (0.5f + (float)a);
    float base = 0.5f + fb;
    float vx = v.X();
    float vy = v.Y();
    UnkStruct_00426290_fu t4c, t48, t44;
    t4c.f = (base - fb * vy) * k;
    t48.f = (base - (float)(b - cl) * vy) * k;
    t44.f = (base - (float)(b - d) * vy) * k;
    int n1;
    if (a > 0) n1 = ((a < c ? a : c) + 31) / 32;
    else n1 = 0;
    int n2;
    if (a < c) n2 = (c + 31) / 32 - (a > 0 ? a : 0) / 32;
    else n2 = 0;
    float k2 = 0.00006103515625f;
    float sx = vx * k2;
    u_long128 * p = farFogPlane.field_0;
    unsigned long hdr = (unsigned long)(unsigned)(n1 + n2) | 0x8400000000000000UL;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(hdr), "r"(0x52525252));
    long vA = (long)t4c.u << 32, vB = (long)t48.u << 32, vC = (long)t44.u << 32;
    long ya = (long)cl16 << 16, yb = (long)y16 << 16;
    int end1 = a237_pextlw(a237_pminw(x16, c << 4));
    int x = end1;
    int nx = (end1 - 1) & -512;
    while (n1-- != 0) {
        UnkStruct_00426290_fu s0, s1;
        s0.f = u0 - sx * (float)(x16 - x);
        s1.f = u0 - sx * (float)(x16 - nx);
        long px = (long)x, qx = (long)nx;
        x = nx; nx -= 512;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)s1.u | vB), "r"(qx | yb));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)s0.u | vA), "r"(px));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)s1.u | vB), "r"(qx | yb));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)s0.u | vC), "r"(px | ya));
    }
    int x2 = a237_pextlw(a237_pmaxw(x16, 0));
    x = x2;
    nx = (x2 + 512) & -512;
    while (n2-- != 0) {
        if (n2 == 0) nx = c << 4;
        UnkStruct_00426290_fu s0, s1;
        s0.f = u0 + sx * (float)(x - x16);
        s1.f = u0 + sx * (float)(nx - x16);
        long px = (long)x, qx = (long)nx;
        x = nx; nx += 512;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)s1.u | vB), "r"(qx | yb));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)s0.u | vA), "r"(px));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)s1.u | vB), "r"(qx | yb));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)s0.u | vC), "r"(px | ya));
    }
    farFogPlane.field_0 = p;
}
