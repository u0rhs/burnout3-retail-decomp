// NONMATCHING: func_0021D8E0 -- retail 154 / ours 154 instructions, 110 in changed runs
// a96: hand draft from the asm (GIF/VIF packet: 9 pcpyld quads at farFogPlane after _rwDMAOpenVIFPkt(0x80000000,9), gradient Tex0 quad, maParams+0x190/0x340 cleared). Logic believed right; 64-bit zext arithmetic per field applied; scheduling/register order of the pcpyld operand setup differs throughout (retail interleaves quad setup with sq; ours computes constants first). Needs the real packet-builder inline shape
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_mbTexturesUploaded { unsigned char field_0; };
struct UnkStruct_D_006662D0 { int field_0; int pad_4[3]; };
struct UnkStruct_D_00666270 { int field_0; int pad_4[3]; };
struct UnkStruct_maParams {
    unsigned char pad_0[0x190];
    u_long128 field_190;
    unsigned char pad_1A0[0x1A0];
    u_long128 field_340;
};
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
class CB3SkyDomeRenderer {
public:
    static unsigned char mbTexturesUploaded;
    static UnkStruct_maParams maParams;
    static u_long128 mu128SourceGradientTex0_1;
};
extern UnkStruct_D_006662D0 D_006662D0;
extern UnkStruct_D_00666270 D_00666270;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern u_long128 *farFogPlane;
extern "C" void func_0021E350();
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void _rwDMAOpenVIFPkt(unsigned int, int);

#define PCPYLD(out, hi, lo) asm("pcpyld %0, %1, %2" : "=r"(out) : "r"(hi), "r"(lo))

// 0x0021D8E0
extern "C" void func_0021D8E0()
{
    if (CB3SkyDomeRenderer::mbTexturesUploaded == 0) {
        return;
    }
    func_0021E350();
    u_long128 z;
    PCPYLD(z, 0UL, 0UL);
    CB3SkyDomeRenderer::maParams.field_190 = z;
    CB3SkyDomeRenderer::maParams.field_340 = z;
    unsigned int s3 = D_006662D0.field_0 + 0x50;
    u_long128 g;
    PCPYLD(g, 6UL, (0x54004000UL | (5UL << 32) | (unsigned long)s3));
    CB3SkyDomeRenderer::mu128SourceGradientTex0_1 = g;
    bool s2 = D_00666270.field_0 == 0;
    if (s2) {
        OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(&D_00665EC0, 0);
    }
    unsigned int s1 = ((s3 & 1) << 7) + ((s3 & 4) << 6) + ((s3 & 0x10) << 5);
    unsigned int s0 = ((s3 & 2) << 6) + ((s3 & 8) << 5);
    _rwDMAOpenVIFPkt(0x80000000, 9);
    u_long128 *p = farFogPlane;
    u_long128 q;
    PCPYLD(q, 0xEUL, (unsigned long)(0x11234000UL << 32 | 0x8008));
    p[0] = q;
    PCPYLD(q, 0x4DUL, ((unsigned long)(s3 >> 5) | 0x10000UL));
    p[1] = q;
    PCPYLD(q, 0x19UL, 0UL);
    p[2] = q;
    unsigned int a = s1 >> 4;
    unsigned int b = s0 >> 4;
    PCPYLD(q, 0x41UL, (((unsigned long)(b + 0x1F) << 48) | (((unsigned long)b << 32) | ((unsigned long)a | ((unsigned long)(a + 0x1F) << 16)))));
    p[3] = q;
    PCPYLD(q, 0x48UL, 0x31001UL);
    p[4] = q;
    PCPYLD(q, 0x43UL, 0x2AUL);
    p[5] = q;
    PCPYLD(q, 1UL, (unsigned long)(0x80FFFFFFUL | (0x3F800000UL << 32)));
    p[6] = q;
    PCPYLD(q, 5UL, ((unsigned long)s1 | ((unsigned long)s0 << 16)));
    p[7] = q;
    PCPYLD(q, 5UL, ((unsigned long)(s1 + 0x200) | ((unsigned long)(s0 + 0x200) << 16)));
    p[8] = q;
    farFogPlane = p + 9;
    if (s2) {
        CloseViewport__22CB3GraphicsManagerBaseFv(&D_00665EC0);
    }
}
