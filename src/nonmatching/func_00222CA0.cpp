// NONMATCHING: func_00222CA0 -- retail 179 / ours 181 instructions, 106 in changed runs
// fresh4: GIF builder in N218 *p++ shape, goto loop + scoped opt_repositioncode off [G] (keeps the optional 5th quad inline); left: head/tail quad scheduling + loop register numbering (p t7 vs t6, i t3 vs t7), ~106 in changed runs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00222CA0 -- hand-written (the lifter's draft rewritten in the N218 GIF packet-builder shape).
// Unnamed in every table, so a placeholder with C linkage; file and Area unknown, so _unclassified/.
// Layout and types are [G] (instruction widths). Every pcpyld half read off retail's lui/ori/dsll32 chains.

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtTextureCache {
public:
    void InvalidateCurrentTexture();
    unsigned char pad_0[0x10];
};
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_D_006662D8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_006662DC { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_006664F0 { u_long128 field_0[4]; };
struct UnkStruct_00222CA0 {
    unsigned char pad_0[0x1194];
    int field_1194;
    unsigned char pad_1198[0x8];
    int field_11A0[5];
    int field_11B4[5];
    int field_11C8[5];
};

extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_006662D8 D_006662D8;
extern UnkStruct_D_006662DC D_006662DC;
extern UnkStruct_D_006664F0 D_006664F0;
extern CGtTextureCache gTextureCache;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// N182: [G] scoped to this function -- opt_repositioncode off keeps the optional quad inline as retail.
#pragma push
#pragma opt_repositioncode off
// 0x00222CA0
extern "C" void func_00222CA0(UnkStruct_00222CA0 *self)
{
    _rwDMAOpenVIFPkt(0, (self->field_1194 << 2) + 16);
    u_long128 *p = farFogPlane.field_0;
    unsigned long z;
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(0x5000000800000000), "r"(0x10000008));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008007), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(unsigned int)(((unsigned int)D_006662D8.field_0 >> 5) | 0x40000)), "r"(76));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x80000000800), "r"(24));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0xFF000000FF0000), "r"(64));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(71));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x80000000A8), "r"(66));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(5), "r"(8));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(97), "r"(20));
    int m0 = 0;
    if (0 < self->field_1194 - 1) {
        u_long128 q9;
        u_long128 q10;
        asm("pcpyld %0, %1, %2" : "=r"(q9) : "r"(0x5000000200000000), "r"(0x10000002));
        asm("pcpyld %0, %2, %1" : "=r"(q10) : "r"(0x1000000000008001), "r"(14));
        int i = 0;
        goto test;
    body:
        {
            int base = m0 + D_006662DC.field_0;
            *p++ = q9;
            *p++ = q10;
            int t2 = self->field_11B4[i];
            int t3 = self->field_11C8[i];
            int w = 1 << t2;
            int h = 1 << t3;
            m0 += (w * h) / 64;
            asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((((long)t3 << 30) | (((long)t2 << 26) | ((unsigned long)(unsigned int)base | ((long)(w / 64) << 14)))) | 0x400000000), "r"(6));
            int t4 = self->field_11A0[i];
            if (t4 != 0) {
                asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(unsigned int)t4 << 32) | 0x50000000), "r"(0));
            }
        }
        i++;
    test:
        if (i < self->field_1194 - 1) goto body;
    }
    const u_long128 *s = D_006664F0.field_0;
    asm("pcpyld %0, %1, %2" : "=r"(*p++) : "r"(0x5000000600000000), "r"(0x10000006));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008005), "r"(14));
    z = 0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(z), "r"(63));
    *p++ = s[0];
    *p++ = s[1];
    *p++ = s[2];
    *p++ = s[3];
    farFogPlane.field_0 = p;
    gTextureCache.InvalidateCurrentTexture();
}
#pragma pop
