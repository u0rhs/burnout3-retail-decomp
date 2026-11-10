// NONMATCHING: SecondDownsample__8CB3BloomFUiUiUiUiUiUi -- retail 124 / ours 124 instructions, 40 in changed runs
// gif6: 40 changed (was 41): c45 written ((unsigned long)p5 << 16) | p4. Inert: 12 preheader statement orders with/without a separate q pointer (q: 105), p[k]+q=p+9 (Blend's shape: 111-119), 15 pragmas. Left: head schedule, 9th quad registers, loop i/pointer t1/a2 swap.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// near36: 41 changed (was 72). h1 = p1>>1 moved after the packet pointer load and the p4|p5<<16 / p2<<5|p3<<14 halves in their own unsigned long locals first (fixes the h1/n/p head register rotation); plain for loop = goto form. Left: head scheduling (retail starts dsll32 v1,t2), 9th quad (retail li 0x5353 first, or t0,t0,K into n's register), loop i/pointer in t1/a2 swapped (ours a2/t1). All 360 orders of the 6 head statements give 41; operand-order/for/p[0..1] forms inert.

// gif4: 124/124, 72 in changed runs (was 104). *p++ quads, N24 goto loop, u/x updated in place (u first), decl order u,x,i. Left: head temp numbering (retail h0 early in t3, h1 in v1, p in a0; ours h1 early, p in v1) shifting the loop registers. Inert: 60 head declaration orders; an inline loop helper with long/int params is worse (119)

// uxi ux inl goto
// CB3Bloom::SecondDownsample(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) -- hand-matched (gif4).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BloomPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};
class CB3Bloom {
public:
    void SecondDownsample(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5);
};
extern UnkStruct_farFogPlane farFogPlane;

// 0x002651C0
void CB3Bloom::SecondDownsample(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5)
{
    unsigned int h0 = p0 >> 1;
    unsigned long c45 = ((unsigned long)p5 << 16) | p4;
    unsigned long c23 = (unsigned int)(p2 << 5) | ((unsigned long)p3 << 14);
    unsigned int n = (h0 + 63) >> 6;
    u_long128 * p = farFogPlane.field_0;
    unsigned int h1 = p1 >> 1;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x10AB400000000007UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(c45 | 0xFF00000000000000UL), "r"(76));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(c23 | 0x6A8000000UL), "r"(6));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(97), "r"(20));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(h0 - 1) << 14) | 5 | ((unsigned long)(h1 - 1) << 34)), "r"(8));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(71));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(42), "r"(66));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x878787), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)n | 0x4400000000000000UL), "r"(21331));
    unsigned long u = 0;
    unsigned long x = 16;
    unsigned int i;
    for (i = 0; i < n; i++) {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(x | 0x100000), "r"(u));
        if (i < n - 1) {
            u += 512;
            x += 1024;
        } else {
            u = (unsigned int)(h0 << 3);
            x = (unsigned int)((h0 << 4) + 16);
        }
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(x | ((unsigned long)(unsigned int)((h1 << 4) + 16) << 16)), "r"(u | ((unsigned long)(unsigned int)(h1 << 3) << 16)));
    }
    farFogPlane.field_0 = p;
}


