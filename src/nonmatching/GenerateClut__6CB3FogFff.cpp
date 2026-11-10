// NONMATCHING: GenerateClut__6CB3FogFff -- retail 192 / ours 192 instructions, 6 in changed runs
// 6 off: loop body only -- retail ORs (i & 0xE0) | y' into the andi's register (or t0,t0,t1), ours into y's (or t1,t1,t0); everything else exact. Tried operand orders, associativity, locals, int/unsigned params, 6 scoped pragmas
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3Fog::GenerateClut(float,float) -- [C] name: the mangled symbol in retail's tables.
// Area not evidenced, so _unclassified/. Fields are placeholders; every type is [G] (instruction widths).
// Hand-written (fresh5): lifter refused. GIF packet in the N218 form (u_long128 *p = farFogPlane.field_0, one
// pcpyld per quad into *p++, field written back once); siblings B3FogPS2_00240FD0/00240F30.

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};
struct UnkStruct_D_006662D0 { int field_0; int pad_4[3]; };

class CB3Fog {
public:
    void GenerateClut(float p0, float p1);
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_006662D0 D_006662D0;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// [G] placeholder for the inlined CLUT entry position (CSM1 swizzle of index i inside the 16x16 block at x, y).
static inline unsigned long func_002413E0_inl1(unsigned int x, unsigned int y, int i)
{
    y = y | (i & 8) << 1;
    y = (i & 0xE0) | y;
    x = x | (i & 7) << 4;
    x = x | (i & 0x10) << 3;
    return (unsigned long)y << 16 | (unsigned long)x;
}

// 0x002413E0
void CB3Fog::GenerateClut(float p0, float p1)
{
    unsigned int tbp = D_006662D0.field_0 + 0x17C;
    unsigned int x = ((tbp & 1) << 7) + ((tbp & 4) << 6) + ((tbp & 0x10) << 5);
    unsigned int y = ((tbp & 2) << 6) + ((tbp & 8) << 5);
    _rwDMAOpenVIFPkt(0x80000000, 0x106);
    int i;
    u_long128 *p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000400000000004UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(tbp >> 5) | 0x10000), "r"(0x4C));
    unsigned int x4 = x >> 4;
    unsigned int y4 = y >> 4;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)x4 | (unsigned long)(x4 + 15) << 16 | (unsigned long)y4 << 32 | (unsigned long)(y4 + 15) << 48), "r"(0x40));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(0x47));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2A), "r"(0x42));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2400000000008100UL), "r"(0x51));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)(int)(0.5f + 128.0f * p1) << 24 | 0xFFFFFF), "r"((unsigned long)x | (unsigned long)y << 16));
    for (i = 1; i < 256; i++) {
        int v;
        if (i < 12) {
            v = (int)(0.5f + 128.0f * p0);
        } else {
            float t = (1.4f / (0.4f + (float)(i - 12) / 243.0f) - 1.0f) / 2.5f;
            if (t < 0.75f) {
                t = t * t;
                t = t * 1.3333334f;
            } else {
                t = 1.0f - t;
                t = t * t;
                t *= 4.0f;
                t = 1.0f - t;
            }
            v = (int)(0.5f + 128.0f * (t * p0));
        }
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)v << 24 | 0xFFFFFF), "r"(func_002413E0_inl1(x, y, i)));
    }
    farFogPlane.field_0 = p;
}
