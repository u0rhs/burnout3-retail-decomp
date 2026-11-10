// NONMATCHING: Blur__8CB3BloomFUiUiUiUi -- retail 213 / ours 213 instructions, 168 in changed runs
// gif7: structure exact (Blend's shape: p[k] header, q = p + 6, four N24 goto loops of 2 UV/XYZ2 quads with an i < n - 1 clamp; x/u unsigned long, the y/x bounds as unsigned long locals before loop 1, loop-2 step (x - 1UL) & ~511UL); left 168, all register colouring (n t3, loop-1 u in s0, i/u per loop, hoisted <<16 terms). Inert: int i at top, head orders, 150 of 5040 bound-local orders (171 -> 168), per-loop variables (worse), 15 pragmas
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

class CB3Bloom {
public:
    void Blur(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3);
};

extern UnkStruct_farFogPlane farFogPlane;

// 0x00264E60
void CB3Bloom::Blur(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3)
{
    unsigned int w = p0 >> 2;
    unsigned int h = p1 >> 2;
    unsigned int n = (w + 31) >> 5;
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(p[0]) : "r"(0x10AB400000000004UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(p[1]) : "r"(0x8A8A8A), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(p[2]) : "r"((unsigned int)(p2 << 5) | ((unsigned long)p3 << 14) | 0x6A8000000UL), "r"(6));
    asm("pcpyld %0, %2, %1" : "=r"(p[3]) : "r"(((unsigned long)(w - 1) << 14) | 0xA | ((unsigned long)(h - 1) << 34)), "r"(8));
    asm("pcpyld %0, %2, %1" : "=r"(p[4]) : "r"(0x5400000064UL), "r"(0x42));
    asm("pcpyld %0, %2, %1" : "=r"(p[5]) : "r"((unsigned long)(n * 4) | 0x4400000000000000UL), "r"(0x5353));
    unsigned long x;
    unsigned long u;
    unsigned int i;
    u_long128 *q;
    q = p + 6;
    unsigned int w16 = w << 4;
    unsigned int h16 = h << 4;
    unsigned long W = w16;
    unsigned long Hm32 = h16 - 32;
    unsigned long Hm16 = h16 - 16;
    unsigned long Wm32 = w16 - 32;
    unsigned long W8 = w16 + 8;
    unsigned long H8 = h16 + 8;
    unsigned long H = h16;
    x = 0;
    u = 0x20;
    i = 0;
    goto test1;
body1:
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(u | (8 << 16)), "r"(x));
    if (i < n - 1) {
        x += 512;
        u += 512;
    } else {
        x = Wm32;
        u = W;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(u | (H8 << 16)), "r"(x | (H << 16)));
    i++;
test1:
    if (i < n) goto body1;
    x = W;
    u = W - 16UL;
    i = 0;
    goto test2;
body2:
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(u | (8 << 16)), "r"(x));
    if (i < n - 1) {
        x = (x - 1UL) & ~511UL;
        u = x - 16UL;
    } else {
        x = 32;
        u = 16;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(u | (H8 << 16)), "r"(x | (H << 16)));
    i++;
test2:
    if (i < n) goto body2;
    x = 0;
    u = 8;
    i = 0;
    goto test3;
body3:
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(u | (0x20 << 16)), "r"(x));
    if (i < n - 1) {
        x += 512;
        u += 512;
    } else {
        x = W;
        u = W8;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(u | (H << 16)), "r"(x | (Hm32 << 16)));
    i++;
test3:
    if (i < n) goto body3;
    x = 0;
    u = 8;
    i = 0;
    goto test4;
body4:
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(u | (Hm16 << 16)), "r"(x | (H << 16)));
    if (i < n - 1) {
        x += 512;
        u += 512;
    } else {
        x = W;
        u = W8;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(u | (0x10 << 16)), "r"(x | (0x20 << 16)));
    i++;
test4:
    if (i < n) goto body4;
    farFogPlane.field_0 = q;
}
