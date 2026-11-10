// CB3RadialBlur::BlurSetRenderstates(unsigned long,unsigned long,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RadialBlurPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a72: operands computed inline in each pcpyld asm (no named temps), clamp/tag/tex/frame/alpha packed as unsigned long).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3RadialBlur;
struct UnkStruct_farFogPlane;
struct UnkStruct_002FA3C0_1;

struct UnkStruct_002FA3C0_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
};

struct UnkStruct_farFogPlane {
    UnkStruct_002FA3C0_1 * field_0;
};

class CB3RadialBlur {
public:
    void BlurSetRenderstates(unsigned long p0, unsigned long p1, int p2, int p3);
};

extern UnkStruct_farFogPlane farFogPlane;

// [L] GIF packet: tag NLOOP=4 REGS=A+D, then TEX0-like(6), FRAME_1(0x4C), ALPHA_1(0x42), CLAMP_1(8) A+D pairs (GS register ids); asm pcpyld as in RestoreRenderstates
// 0x002FA3C0
void CB3RadialBlur::BlurSetRenderstates(unsigned long p0, unsigned long p1, int p2, int p3)
{
    UnkStruct_002FA3C0_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(4 | ((unsigned long)0x10AB4000 << 32)), "r"(14));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"((p0 << 5) | (p1 << 14) | ((6UL << 32) | ((unsigned long)0xA800 << 16))), "r"(6));
    t0->field_10 = q1;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"((p0 | (p1 << 16)) | ((unsigned long)0xFF000000 << 32)), "r"(76));
    t0->field_20 = q2;
    u_long128 q3;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"(100 | ((unsigned long)64 << 32)), "r"(66));
    t0->field_30 = q3;
    u_long128 q4;
    asm("pcpyld %0, %2, %1" : "=r"(q4) : "r"((((unsigned long)(p2 - 1) << 14) | 0xA) | ((unsigned long)(p3 - 1) << 34)), "r"(8));
    t0->field_40 = q4;
    farFogPlane.field_0 = t0 + 1;
}
