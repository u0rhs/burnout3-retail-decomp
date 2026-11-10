// NONMATCHING: ClearOffscreenBuffer__18CB3GraphicsManagerFUi -- retail 111 / ours 111 instructions, 36 in changed runs
// gif4: 111/111, 36 in changed runs. 13 quads via local *p++ (p never written back), then farFogPlane.field_0 += 13 / *++ copies of D_006664F0 through a const pointer. Left: q(78,v0) output register (retail reuses the lo input a2), the 326 quad's register, and the tail's fp/lq/new-pointer numbering (retail a1/v1/a0, D address lui late)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// z7 c
// CB3GraphicsManager::ClearOffscreenBuffer(unsigned int) -- hand-matched (gif4).
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_D_006662D8 {
    unsigned int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_006662DC {
    unsigned int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};
struct UnkStruct_D_006664F0 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
};
class CB3GraphicsManager {
public:
    void ClearOffscreenBuffer(unsigned int p0);
};
extern UnkStruct_D_006662D8 D_006662D8;
extern UnkStruct_D_006662DC D_006662DC;
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_D_006664F0 D_006664F0;
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x00222F70
void CB3GraphicsManager::ClearOffscreenBuffer(unsigned int p0)
{
    unsigned int v0;
    switch (p0) {
    case 3:
        v0 = D_006662D8.field_0 >> 5;
        break;
    case 4:
        v0 = D_006662DC.field_0 >> 5;
        break;
    }
    _rwDMAOpenVIFPkt(0x80000000, 17);
    u_long128 *p = farFogPlane.field_0;
    unsigned long z;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008004UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(v0 | 0x10000)), "r"(76));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)v0), "r"(78));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0UL), "r"(24));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x7FF000007FF0000UL), "r"(64));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008003UL), "r"(14));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x30003UL), "r"(71));
    z = 0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(168UL), "r"(66));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(z), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x3400000000008001UL), "r"(1360));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(326UL), "r"(z));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x40000200UL), "r"(z));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1000000000008004UL), "r"(14));
    UnkStruct_D_006664F0 * const d = &D_006664F0;
    *(farFogPlane.field_0 += 13) = d->field_0;
    *++farFogPlane.field_0 = d->field_10;
    *++farFogPlane.field_0 = d->field_20;
    *++farFogPlane.field_0 = d->field_30;
    farFogPlane.field_0++;
}
