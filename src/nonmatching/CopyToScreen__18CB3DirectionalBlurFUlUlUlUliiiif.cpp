// NONMATCHING: CopyToScreen__18CB3DirectionalBlurFUlUlUlUliiiif -- retail 93 / ours 93 instructions, 86 in changed runs
// gif3: constants re-derived (0xFF00..UL unsigned literal gives retail's pcpyld x,zero,x; 0x6A8000000 shares li 6), *p++ form, if (n != 0) {+=} else {=end}: 93/93 instrs, block layout exact; left: register numbering/schedule throughout (retail n=t6, x=t5, u=t0, loop p=t4; ours n=t7, one extra temp t8); c/d locals, loop-locals placement, q0/loop operand order swept (64 variants) without effect
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// 1 0 0xFF00000000000000UL (1, 0, 0, 0, 0, 0, 0)
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane { u_long128 * field_0; };
class CB3DirectionalBlur {
public:
    static void CopyToScreen(unsigned long p0, unsigned long p1, unsigned long p2, unsigned long p3, int p4, int p5, int p6, int p7, float p8);
};
extern UnkStruct_farFogPlane farFogPlane;

// 0x00426110
void CB3DirectionalBlur::CopyToScreen(unsigned long p0, unsigned long p1, unsigned long p2, unsigned long p3, int p4, int p5, int p6, int p7, float p8)
{
    int n = (p6 + 31) / 32;
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(14), "r"(0x10AB400000000003UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((p0 | (p1 << 16)) | 0xFF00000000000000UL), "r"(76));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((p3 << 14) | (p2 << 5)) | 0x6A8000000UL), "r"(6));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((long)(int)(0.5f + 128.0f * p8) << 32) | 100), "r"(66));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(unsigned int)n | 0x4400000000000000UL), "r"(0x5353));
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
