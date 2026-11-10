// NONMATCHING: SetTileTexture__13CGtVideoImageFii -- retail 124 / ours 124 instructions, 80 in changed runs
// gif4: 124/124, 80 in changed runs (was 102). Constants re-derived: q1/q5 low halves are 0x1000000000008003/8002 (the old archive's 0x10000004_0000800x was wrong); _rwDMAOpenVIFPkt takes 2 args. *p++ form, q0/q5/q6 as locals reused in the loop. Left: register numbering throughout (retail p=t0, q6 zero in t8 created first)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// h2 none
// CGtVideoImage::SetTileTexture(int,int) -- hand-matched (gif4).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtVideoDecoderPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// GIF quads (N218): pcpyld asm straight into *p++; constants re-derived from retail's lui/ori/dsll32 chains.
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};
class CGtVideoImage {
public:
    void SetTileTexture(int p0, int p1);

    int field_0;
    unsigned char pad_4[0xC];
    int field_10;
    int field_14;
};
extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x00325BD0
void CGtVideoImage::SetTileTexture(int p0, int p1)
{
    int m0 = field_0 + (((p0 << 2) * field_10) << 10) + (p1 << 12);
    _rwDMAOpenVIFPkt(0, 32);
    u_long128 * p = farFogPlane.field_0;
    u_long128 q0, q5, q6;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000004UL), "r"(0x5000000400000000UL));
    *p++ = q0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008003UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)field_14 << 32) | 0x1000000000000UL), "r"(80));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x4000000010UL), "r"(82));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(field_14 | 0x198004000UL), "r"(6));
    asm("pcpyld %0, %2, %1" : "=r"(q6) : "r"(0UL), "r"(83));
    asm("pcpyld %0, %2, %1" : "=r"(q5) : "r"(0x1000000000008002UL), "r"(14));
    for (int i = 0; i < 4; i++) {
        *p++ = q0;
        *p++ = q5;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(i << 4) << 32), "r"(81));
        *p++ = q6;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(i == 3) << 15) | 0x0800000000000100UL), "r"(0UL));
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(unsigned int)m0 << 32) | 0x30000100UL), "r"(0x5000010000000000UL));
        m0 += field_10 << 10;
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10000002UL), "r"(0x5000000200000000UL));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008001UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0UL), "r"(63));
    farFogPlane.field_0 = p;
}
