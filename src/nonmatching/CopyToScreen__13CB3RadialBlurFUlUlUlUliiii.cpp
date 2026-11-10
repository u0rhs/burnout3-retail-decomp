// NONMATCHING: CopyToScreen__13CB3RadialBlurFUlUlUlUliiii -- retail 117 / ours 118 instructions, 82 in changed runs
// 117/118, 82 changed (a249's lifter shape: 150): DirectionalBlur archive shape + RadialBlur constants (quad0 low ...04, quad3 68/66), colour quad c|c<<8|c<<16|c2<<24|1.0f<<32 with hi 1, n-quad built into q4 before it and stored after. Left: GIF register allocation/scheduling, one extra instruction.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3RadialBlur::CopyToScreen(unsigned long, unsigned long, unsigned long, unsigned long, int, int, int, int) -- hand-written (fresh1)
// from the CB3DirectionalBlur::CopyToScreen archive's shape (GIF packet, N218 form).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3RadialBlurPS2.cpp.
// Field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

struct UnkStruct_farFogPlane { u_long128 * field_0; };

class CB3RadialBlur {
public:
    void CopyToScreen(unsigned long p0, unsigned long p1, unsigned long p2, unsigned long p3, int p4, int p5, int p6, int p7);

    unsigned char pad_0[0x18];
    float field_18;
    float field_1C;
};

extern UnkStruct_farFogPlane farFogPlane;

// 0x002F9F50
void CB3RadialBlur::CopyToScreen(unsigned long p0, unsigned long p1, unsigned long p2, unsigned long p3, int p4, int p5, int p6, int p7)
{
    int n = (p6 + 31) / 32;
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10AB400000000004UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((p0 | (p1 << 16)) | 0xFF00000000000000UL), "r"(76));
    unsigned long six = 6;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((p3 << 14) | (p2 << 5)) | (0xA8000000UL | six << 32)), "r"(six));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(68), "r"(66));
    u_long128 q4;
    asm("pcpyld %0, %2, %1" : "=r"(q4) : "r"((unsigned long)(unsigned int)n | 0x4400000000000000UL), "r"(0x5353));
    long c = (int)(0.5f + 128.0f * field_18);
    long c2 = (int)(0.5f + 128.0f * field_1C);
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((c2 << 24 | (c << 16 | (c | c << 8))) | 0x3F80000000000000UL), "r"(1));
    *p++ = q4;
    long x = p4 << 4;
    long u = 8;
    long y0 = (long)(p5 << 4) << 16;
    long xe = (p4 + p6) << 4;
    long ue = (long)(p6 << 3) + 8;
    long y1 = (long)((p5 + p7) << 4) << 16;
    long v = ((long)(p7 << 3) + 8) << 16;
    do {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(u | 0x80000), "r"(x | y0));
        n--;
        if (n != 0) {
            x += 0x200;
            u += 0x100;
        } else {
            x = xe;
            u = ue;
        }
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(u | v), "r"(x | y1));
    } while (n != 0);
    farFogPlane.field_0 = p;
}
