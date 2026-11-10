// NONMATCHING: CopyToScreen__8CB3BloomFUiUiUiUiUiUiUiUi -- retail 149 / ours 149 instructions, 14 in changed runs
// fresh2: 149/149, 14 in changed runs. n = p0>>5 first (fills the clamp's bnez delay slot), *p++ head, i = 0 assigned after u/x/v0/v1 (71 -> 14). Left: loop pointer p (retail v1, created by addiu v1,a1,0x90 before x) and x (retail a1) swapped. p[k]+q=p+9 or a q copy spills (frame 0x10); p += 9 anywhere, x/u order no effect
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3Bloom::CopyToScreen(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) -- hand-written (fresh2).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BloomPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// GIF quads (N175): one pcpyld asm per quad (lo-first). p4/p5 are never read by retail [C] (registers overwritten).

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

struct UnkStruct_D_006662D0 {
    unsigned int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3Bloom {
public:
    void CopyToScreen(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7);

    unsigned char pad_0[0x4];
    float field_4;
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_006662D0 D_006662D0;

// 0x002649D0
void CB3Bloom::CopyToScreen(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7)
{
    unsigned int n = p0 >> 5;
    unsigned long c = (int)(128.0f * field_4);
    if (c > 255) {
        c = 255;
    }
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10AB400000000007UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(p6 | ((unsigned long)p7 << 16) | 0xFF00000000000000UL), "r"(76));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(D_006662D0.field_0 | 0x6A800C000UL), "r"(6));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(97), "r"(20));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(p2 >> 2) << 4) | 0xA | ((unsigned long)(((p2 + p0) >> 2) - 1) << 14) | ((unsigned long)(p3 >> 2) << 24) | ((unsigned long)(((p3 + p1) >> 2) - 1) << 34)), "r"(8));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(71));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x8000000029UL), "r"(66));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((c << 16) | (c | (c << 8))), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)n | 0x4400000000000000UL), "r"(21331));
    unsigned long u;
    unsigned long x;
    unsigned long v0;
    unsigned long v1;
    unsigned int i;
    u = (unsigned long)(unsigned int)(p2 << 2) + 8;
    x = (unsigned int)(p2 << 4);
    v0 = (unsigned long)(unsigned int)(p3 << 2) + 8;
    v1 = v0 + (unsigned int)(p1 << 2);
    i = 0;
    for (; i < n; i++) {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(u | (v0 << 16)), "r"(x | ((unsigned long)(unsigned int)(p3 << 4) << 16)));
        u += 128;
        x += 512;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(u | (v1 << 16)), "r"(x | ((unsigned long)(unsigned int)((p3 + p1) << 4) << 16)));
    }
    farFogPlane.field_0 = p;
}

