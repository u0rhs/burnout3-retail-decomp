// NONMATCHING: FirstDownsample__8CB3BloomFUiUiUiUiUiUiUiUiUi -- retail 358 / ours 358 instructions, 253 in changed runs
// draftAC ac5: 358/358, 253 changed (ac4 with k3 rgb outside the loop: 227). Every quad decoded (FRAME/ZBUF ping-pong quads qa..qd built once before the loop, q += 3 inside each parity branch, k3 colour inside the loop -> preheader like retail; float head exact up to k1/k3 colouring). Left: head-block schedule (retail starts with the p4/p5 TEX0 term, ours with the k2 ALPHA term) and the colouring that follows; 24 head declaration orders and the *p++ form inert (siblings' wall).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every quad's lo/hi and every loop store accounted for (draftAC)

// CB3Bloom::FirstDownsample(unsigned int x9) -- hand-written from the retail asm (draftAC).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3BloomPS2.cpp.
// Field names are placeholders and every type is [G] (instruction widths).
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

class CB3Bloom {
public:
    void FirstDownsample(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7, unsigned int p8);

    float field_0;
};

extern UnkStruct_farFogPlane farFogPlane;

// 0x002653B0
void CB3Bloom::FirstDownsample(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6, unsigned int p7, unsigned int p8)
{
    unsigned long c = (int)(field_0 * 255.0f + 0.5f);
    if (c > 254)
        c = 254;
    unsigned long rgb = c | (c << 8) | (c << 16);
    float s = 32768.0f / (float)(int)(255 - c);
    s *= 1.05f;
    unsigned int k1 = (int)(s + 0.9999f);
    if (k1 > 255)
        k1 = 255;
    s *= 128.0f / k1;
    unsigned int k2 = (int)(s + 0.9999f);
    if (k2 > 255)
        k2 = 255;
    s *= 128.0f / k2;
    unsigned int k3 = (int)(s + 0.9999f);
    if (k3 > 255)
        k3 = 255;

    unsigned long c23 = (unsigned int)(p4 << 5) | ((unsigned long)p5 << 14);
    unsigned long ka = ((unsigned long)k1 << 32) | 0xA4;
    unsigned long kb = ((unsigned long)k2 << 32) | 0xA8;
    u_long128 *p = farFogPlane.field_0;
    u_long128 qa, qb, qc, qd;
    asm("pcpyld %0, %2, %1" : "=r"(qa) : "r"(p6 | 0xFF00000000020000UL), "r"(0x4C));
    asm("pcpyld %0, %2, %1" : "=r"(qb) : "r"((p6 + 1) | 0xFF00000000020000UL), "r"(0x4C));
    asm("pcpyld %0, %2, %1" : "=r"(qc) : "r"((p6 + 1) | 0x1000000UL), "r"(0x4E));
    asm("pcpyld %0, %2, %1" : "=r"(qd) : "r"(p6 | 0x1000000UL), "r"(0x4E));
    asm("pcpyld %0, %2, %1" : "=r"(p[0]) : "r"(0x10A3400000000011UL), "r"(14));
    p[1] = qa;
    p[2] = qd;
    asm("pcpyld %0, %2, %1" : "=r"(p[3]) : "r"(0x2A), "r"(0x42));
    asm("pcpyld %0, %2, %1" : "=r"(p[4]) : "r"(0x30003), "r"(0x47));
    asm("pcpyld %0, %2, %1" : "=r"(p[5]) : "r"(rgb), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(p[6]) : "r"(rgb << 32), "r"(5));
    unsigned long x2 = (rgb << 32) | ((unsigned long)(p1 << 4) << 16) | 0x200;
    asm("pcpyld %0, %2, %1" : "=r"(p[7]) : "r"(x2), "r"(5));
    asm("pcpyld %0, %2, %1" : "=r"(p[8]) : "r"(p7 | ((unsigned long)p8 << 16) | 0xFF00000000000000UL), "r"(0x4D));
    asm("pcpyld %0, %2, %1" : "=r"(p[9]) : "r"(c23 | 0x6A8000000UL), "r"(6));
    asm("pcpyld %0, %2, %1" : "=r"(p[10]) : "r"((unsigned int)(p6 << 5) | 0x6A8008000UL), "r"(7));
    asm("pcpyld %0, %2, %1" : "=r"(p[11]) : "r"(1), "r"(0x14));
    asm("pcpyld %0, %2, %1" : "=r"(p[12]) : "r"(0x61), "r"(0x15));
    asm("pcpyld %0, %2, %1" : "=r"(p[13]) : "r"(0x31001), "r"(0x48));
    asm("pcpyld %0, %2, %1" : "=r"(p[14]) : "r"(((unsigned long)p2 << 4) | 0xA | ((unsigned long)(p2 + p0 - 1) << 14) | ((unsigned long)p3 << 24) | ((unsigned long)(p3 + p1 - 1) << 34)), "r"(8));
    asm("pcpyld %0, %2, %1" : "=r"(p[15]) : "r"(0x30003), "r"(9));
    asm("pcpyld %0, %2, %1" : "=r"(p[16]) : "r"(ka), "r"(0x42));
    asm("pcpyld %0, %2, %1" : "=r"(p[17]) : "r"(kb), "r"(0x43));

    unsigned int n = p0 >> 6;
    unsigned long y0 = (unsigned int)((p3 << 4) + 8);
    unsigned long y1 = y0 + (unsigned int)(p1 << 4);
    unsigned long x = (unsigned int)((p2 << 4) + 8);
    unsigned long u = 0;
    u_long128 *q = p + 18;
    for (unsigned int i = 0; i < n; i++) {
        unsigned long m;
        asm("pcpyld %0, %2, %1" : "=r"(*q++) : "r"(0x10AB400000000002UL), "r"(14));
        if (i & 1) {
            *q++ = qb;
            *q++ = qd;
            m = 0x410;
        } else {
            *q++ = qa;
            *q++ = qc;
            m = 0x10;
        }
        asm("pcpyld %0, %2, %1" : "=r"(q[0]) : "r"(0xE400000000000001UL), "r"(0x0053531053553531UL));
        asm("pcpyld %0, %2, %1" : "=r"(q[1]) : "r"(x | (y0 << 16)), "r"(0x808080));
        asm("pcpyld %0, %2, %1" : "=r"(q[2]) : "r"((x + 0x200) | (y1 << 16)), "r"(rgb << 32));
        x += 0x400;
        asm("pcpyld %0, %2, %1" : "=r"(q[3]) : "r"(x2), "r"(x2));
        asm("pcpyld %0, %2, %1" : "=r"(q[4]) : "r"(x | (y0 << 16)), "r"((rgb << 32) | 0x400));
        asm("pcpyld %0, %2, %1" : "=r"(q[5]) : "r"(0x356), "r"(k3 | ((unsigned long)k3 << 8) | ((unsigned long)k3 << 16)));
        asm("pcpyld %0, %2, %1" : "=r"(q[6]) : "r"(m | ((unsigned long)((p1 << 4) + 16) << 16)), "r"(u | ((unsigned long)(p1 << 3) << 16)));
        u += 0x200;
        asm("pcpyld %0, %2, %1" : "=r"(q[7]) : "r"((m + 0x400) | 0x100000), "r"(u));
        q += 8;
    }
    farFogPlane.field_0 = q;
}
