// NONMATCHING: BuildPacket__5CBlitFUiUiUiUiUiUiUiUlb -- retail 187 / ours 187 instructions, 61 in changed runs
// gif7: all 18 quads decoded and in order (DMA end tag, A+D FRAME/TEX0/TEXA/SCISSOR/CLAMP/TEST/TEX1/DTHE/ALPHA/RGBAQ, UV/XYZ2 strip loop, sync); q0 hi-first; y1/y2 locals placed after Q13/Q14 (49 placements swept); left 61: register allocation of the middle block (mag in a1, 0x44 shared reg, Q4/Q5 zero hoist) and head n/fbw order. 15 pragmas inert
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"

class CBlit {
public:
    unsigned int BuildPacket(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4,
                             unsigned int p5, unsigned int p6, unsigned long p7, bool p8);

    u_long128 field_0[1];
};

// 0x0022B540
unsigned int CBlit::BuildPacket(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4,
                                unsigned int p5, unsigned int p6, unsigned long p7, bool p8)
{
    unsigned int n = (p0 + 31) >> 5;
    unsigned int fbw = (p0 + 63) >> 6;
    u_long128 * p = field_0;
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(0), "r"((long)(int)(n * 2 + 16) | 0x70000000));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x11AB40000000000CUL), "r"(0xE));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)fbw << 16) | 0x0A000000), "r"(0x4D));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)((fbw * ((p2 + 63) >> 6)) << 5) | ((unsigned long)fbw << 14) | 0x6A8100000UL), "r"(0x7));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x80), "r"(0x3B));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x19));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x07FF000007FF0000UL), "r"(0x41));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(p0 - 1) << 14) | 0xA | ((unsigned long)(p1 - 1) << 34)), "r"(0x9));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(0x48));
    unsigned long mag;
    if ((p6 & 0xF) == 8 && (p5 & 0xF) == 8 && p1 == p2) {
        mag = 1;
    } else {
        mag = 0x61;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(mag), "r"(0x15));
    unsigned long c = ((unsigned long)p4 << 24) | ((unsigned long)p3 << 16) | ((unsigned long)p3 | ((unsigned long)p3 << 8)) | (0x3F800000UL << 32);
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(1), "r"(0x45));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(p7), "r"(0x44));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x44), "r"(0x43));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(c), "r"(1));
    unsigned int y2 = p2 << 4;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)n | 0x4400000000000000UL), "r"(0x5353));
    unsigned int y1 = p6 + (p1 << 4);
    unsigned int x;
    int step;
    if (p8) {
        x = n << 9;
        step = -0x200;
    } else {
        x = 0;
        step = 0x200;
    }
    unsigned int i;
    for (i = 0; i < n; i++) {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)p5 | ((unsigned long)p6 << 16)), "r"((unsigned long)x));
        p5 += 0x200;
        x += step;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)p5 | ((unsigned long)y1 << 16)), "r"((unsigned long)x | ((unsigned long)y2 << 16)));
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008001UL), "r"(0xE));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x45));
    asm("sync");
    return (unsigned int)field_0 & 0xCFFFFFFF;
}

