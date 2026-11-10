// NONMATCHING: BeginRendering__6B3Im3dFv -- retail 143 / ours 144 instructions, 146 in changed runs
// a258: logic complete (all 15 quad constants re-derived from retail's lui/ori/dsll32 chains; 0x50000000 shared reg k5 feeds Q4 hi and the skyUserSwitch1 quad lo). 143 vs 144; remaining = register numbering (retail walks the copy loop with a1 = farFogPlane+0x20 and keeps farFogPlane ptr in v1 for Q0/Q1; ours uses a0). The skyUserSwitch1 if-body only lays out inline (beq skip) with scoped #pragma opt_repositioncode off [G]; without it the body goes out of line.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_skyUserSwitch1 { unsigned int field_0; };
struct UnkStruct_D_00667050 { int field_0; unsigned char pad[0xC]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x230]; };
class B3Im3d {
public:
    static void BeginRendering();
    static float _grATestThreshold;
    static u_long128 *_gpau128Registers;
    static unsigned char _gbBFC;
    static unsigned char _gbTextured;
    static unsigned char _gbIsReady;
};
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;
extern UnkStruct_D_00667050 D_00667050;
extern UnkStruct_D_00665EC0 D_00665EC0[];
extern char vu_game_0047A060[];
extern "C" void _rwDMAOpenVIFPkt(int, int);
#define PCP(q, lo, hi) asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(lo), "r"(hi))
#pragma push
#pragma opt_repositioncode off
void B3Im3d::BeginRendering()
{
    int idx = D_00667050.field_0;
    B3Im3d::_grATestThreshold = 0;
    _rwDMAOpenVIFPkt(0, 0x19);
    char *cam = (char *)&D_00665EC0[idx] + 0x470;
    u_long128 *src = (u_long128 *)(cam + 0x120);
    B3Im3d::_gpau128Registers = (u_long128 *)(cam + 0x1C0);
    u_long128 *p = farFogPlane.field_0;
    u_long128 q;
    PCP(*p++, 0x10000000UL, 0x1100000011000000UL);
    PCP(*p++, 0x1000000AUL, 0x6C0A03F601000404UL);
    for (int i = 0; i < 10; i++) *p++ = src[i];
    PCP(*p++, 0x10000001UL, 0x6C0103F501000404UL);
        PCP(*p++, ((unsigned long)B3Im3d::_gbBFC << 32) | 0xAUL, 3UL << 32);
    unsigned long k5 = 0x50000000UL;
    PCP(*p++, 0x10000008UL, (k5 | 8UL) << 32);
    PCP(*p++, 0x1000000000008007UL, 0xEUL);
    u_long128 *r = B3Im3d::_gpau128Registers;
    *p++ = r[0];
    *p++ = r[1];
    *p++ = r[2];
    *p++ = r[3];
    PCP(*p++, 0x8000000044UL, 0x42UL);
    PCP(*p++, ((long)(int)(128.0f * B3Im3d::_grATestThreshold) << 4) | 0x5000BUL, 0x47UL);
    PCP(*p++, 0UL, 8UL);
    if (skyUserSwitch1.field_0 != (unsigned int)vu_game_0047A060) {
        skyUserSwitch1.field_0 = (unsigned int)vu_game_0047A060;
        PCP(*p++, ((unsigned long)(unsigned int)vu_game_0047A060 << 32) | k5, 0x020000FC03000000UL);
    }
    PCP(*p++, 0x10000000UL, 0x1400000000000000UL);
    farFogPlane.field_0 = p;
    B3Im3d::_gbTextured = 1;
    B3Im3d::_gbIsReady = 1;
}
#pragma pop
