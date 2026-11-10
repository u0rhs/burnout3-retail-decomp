// NONMATCHING: ZGreen2FBAlpha__6CB3FogFUiUiUiUiUiUiUi -- retail 182 / ours 184 instructions, 144 in changed runs
// a253: logic right (phantom call args dropped, n int, m0/m1 long); 144 instrs scheduling diffs from GIF asm interleave, 182 vs 184 instrs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// lifter variant 0
// CB3Fog::ZGreen2FBAlpha(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3FogPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3Fog;
struct UnkStruct_002416E0_1;
struct UnkStruct_002416E0_2;
struct UnkStruct_farFogPlane;

struct UnkStruct_farFogPlane {
    UnkStruct_002416E0_1 * field_0;
};

struct UnkStruct_002416E0_1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
    u_long128 field_50;
    u_long128 field_60;
    u_long128 field_70;
    u_long128 field_80;
    u_long128 field_90;
    u_long128 field_A0;
};

struct UnkStruct_002416E0_2 {
    u_long128 field_0;
    u_long128 field_10;
};

class CB3Fog {
public:
    void ZGreen2FBAlpha(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6);
};

extern UnkStruct_farFogPlane farFogPlane;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x002416E0
void CB3Fog::ZGreen2FBAlpha(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6)
{
    int n = (int)((unsigned int)((((p2 + p4) + 15) & -16) - (p2 & -16)) >> 4);
    _rwDMAOpenVIFPkt(0x80000000, (n << 1) + 11);
    UnkStruct_002416E0_1 * t0 = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10AB400000000009), "r"(14));
    t0->field_0 = q0;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(0), "r"(63));
    t0->field_10 = q1;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(((((unsigned int)this) | (((unsigned long)((unsigned int)p0)) << 16)) | 0x3FFF02000000)), "r"(76));
    t0->field_20 = q2;
    u_long128 q3;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"(((((unsigned int)(p1 << 5)) | (((unsigned long)((unsigned int)p0)) << 14)) | 0xEAB200000)), "r"(6));
    t0->field_30 = q3;
    u_long128 q4;
    asm("pcpyld %0, %2, %1" : "=r"(q4) : "r"(0x8000000000), "r"(59));
    t0->field_40 = q4;
    u_long128 q5;
    asm("pcpyld %0, %2, %1" : "=r"(q5) : "r"(0x31001), "r"(71));
    t0->field_50 = q5;
    u_long128 q6;
    asm("pcpyld %0, %2, %1" : "=r"(q6) : "r"(0), "r"(69));
    t0->field_60 = q6;
    u_long128 q7;
    asm("pcpyld %0, %2, %1" : "=r"(q7) : "r"((((((unsigned int)p2) | (((unsigned long)((unsigned int)((p2 + p4) + -1))) << 16)) | (((unsigned long)((unsigned int)(p3 << 1))) << 32)) | (((unsigned long)((unsigned int)(((p3 + p5) << 1) + -1))) << 48))), "r"(64));
    t0->field_70 = q7;
    u_long128 q8;
    asm("pcpyld %0, %2, %1" : "=r"(q8) : "r"(42), "r"(66));
    t0->field_80 = q8;
    u_long128 q9;
    asm("pcpyld %0, %2, %1" : "=r"(q9) : "r"(0x3F80000080FFFFFF), "r"(1));
    t0->field_90 = q9;
    u_long128 q10;
    asm("pcpyld %0, %2, %1" : "=r"(q10) : "r"(((long)n | 0x4400000000008000)), "r"(21331));
    t0->field_A0 = q10;
    long m0 = (((p2 & -16) + 8) << 4);
    long m1 = ((int)(((p2 & -16) << 4) + 8));
    UnkStruct_002416E0_2 * m2 = (UnkStruct_002416E0_2 *)((char *)t0 + 0xB0);
    for (int i = 0; i < n; i++) {
        u_long128 q11;
        asm("pcpyld %0, %2, %1" : "=r"(q11) : "r"((m1 | (((unsigned long)((unsigned int)((p3 << 5) + 8))) << 16))), "r"((m0 | (((unsigned long)((unsigned int)(p3 << 5))) << 16))));
        m2->field_0 = q11;
        u_long128 q12;
        asm("pcpyld %0, %2, %1" : "=r"(q12) : "r"(((m1 + 128) | (((unsigned long)((unsigned int)(((p3 + p5) << 5) + 8))) << 16))), "r"(((m0 + 128) | (((unsigned long)((unsigned int)((p3 + p5) << 5))) << 16))));
        m2->field_10 = q12;
        m0 = (m0 + 256);
        m1 = (m1 + 256);
        m2 = (UnkStruct_002416E0_2 *)((char *)m2 + 0x20);
    }
    farFogPlane.field_0 = (UnkStruct_002416E0_1 *)m2;
}

