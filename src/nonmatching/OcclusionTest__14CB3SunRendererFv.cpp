// NONMATCHING: OcclusionTest__14CB3SunRendererFv -- retail 385 / ours 384 instructions, 353 in changed runs
// draftAM C-first: sun on-screen test (mSunPos x mScreenSize within -6.5 .. size + 6.5, else mbBehind), corona sample box +-0x70 (1/16 px) clamped to the screen, fade = box area / 256 / 196 scales the corona colour D_01D9B970 into mnCoronaRed/Green/Blue, then a 0x21-qword VIF packet: CLAMP/TEST/ALPHA, a 3-strip alpha-only sprite over the box, TEX1/TEXFLUSH/TEX0 from the frame table, a box-copy sprite and two halving copy passes, sky TEST/ALPHA/TEX1 restore; 384/385, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every one of the 33 qwords' lo/hi halves (pcpyld operand order), the four visibility compares' senses (c.le/bc1t x2, c.lt/bc1f x2), the clamps (bltz, slt maxX<right), the signed /256 and >>1, and the colour lanes (vmulx.x/.y/.z) traced

// CB3SunRenderer::OcclusionTest() -- draftAM (C-first draft). 0x24C7E0, 0x604. [C] name: the mangled symbol in retail's tables;
// the static members by their mangled names. Written from the retail asm (Ghidra draft as a reading aid). Local names from the
// Revenge STABS of CB4SunRenderer::OcclusionTest (B4SunRendererPS2.cpp: lScreenPos, lnSampleLeft/Right/Top/Bottom, lrFade,
// lnSampleSize, lnCount); Revenge's body differs (430 instrs), so the structure here is retail's own.
// What it does [L]: the sun's screen position decides mbBehind; when on screen, the corona brightness is the clamped sample box's
// area (a sun near a screen edge gets a smaller box and a dimmer corona), and the GS packet [G] draws the sample box into the
// frame buffer's alpha and copies/reduces it (UV 0x80 -> 0x40 -> 0x20) for the corona's occlusion read-back. Meanings [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_0024BF60_tab { unsigned char pad_0[0x630]; u_long128 field_630; unsigned char pad_640[0x230 - 0x10]; };
extern UnkStruct_0024BF60_tab D_00665EC0[];   // [G] per-frame table, 0x230 per entry (as RenderCorona)
extern int D_00667050;                        // [G] the current frame
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_farFogPlane farFogPlane;     // [C] symbol name (the DMA packet cursor)
extern unsigned long skyTest_1;
extern unsigned long skyAlpha_1;
extern unsigned long skyTex1_1;
extern CGtV4d D_01D9B970;                     // [L] the corona colour (SetupCamera__14CB3SunRenderer: colour x 128)
extern "C" void _rwDMAOpenVIFPkt(int, int);

class CB3SunRenderer {
public:
    static void OcclusionTest();
    static bool mbBehind;
    static CGtV2d mSunPos;
    static CGtV2d mScreenSize;
    static int mnScreenSizeX;
    static int mnScreenSizeY;
    static CGtV2d mScreenOffset;
    static int mnCoronaRed;
    static int mnCoronaGreen;
    static int mnCoronaBlue;
    static int mnCoronaX;
    static int mnCoronaY;
    static int mnGSOffsetX;
    static int mnGSOffsetY;
};

static inline u_long128 func_0024C7E0_q(unsigned long lo, unsigned long hi)
{
    u_long128 r;
    asm("pcpyld %0, %2, %1" : "=r"(r) : "r"(lo), "r"(hi));
    return r;
}
static inline unsigned long func_0024C7E0_xy(int x, int y) { return (long)x | (long)y << 16; }

// 0x0024C7E0
void CB3SunRenderer::OcclusionTest()
{
    u_long128 * lpFrame = &D_00665EC0[D_00667050].field_630;
    if (mbBehind)
        return;
    CGtV2d lScreenPos = mSunPos * mScreenSize;
    float x = lScreenPos.marValues[0];
    float y = lScreenPos.marValues[1];
    if (x > -6.5f && y > -6.5f && x < 6.5f + (float)mnScreenSizeX && y < 6.5f + (float)mnScreenSizeY) {
        int lnMaxX = mnScreenSizeX << 4;
        int lnMaxY = mnScreenSizeY << 4;
        mnCoronaX = (int)(16.0f * x);
        mnCoronaY = (int)(16.0f * y);
        int lnSampleLeft = mnCoronaX - 0x70;
        int lnSampleRight = mnCoronaX + 0x70;
        int lnSampleTop = mnCoronaY - 0x70;
        int lnSampleBottom = mnCoronaY + 0x70;
        if (lnSampleLeft < 0)
            lnSampleLeft = 0;
        if (lnSampleRight > lnMaxX)
            lnSampleRight = lnMaxX;
        if (lnSampleTop < 0)
            lnSampleTop = 0;
        if (lnSampleBottom > lnMaxY)
            lnSampleBottom = lnMaxY;
        float lrFade = (float)(((lnSampleRight - lnSampleLeft) * (lnSampleBottom - lnSampleTop)) / 256) / 196.0f;
        mnCoronaRed = (int)(float)(D_01D9B970.X() * lrFade);
        mnCoronaGreen = (int)(float)(D_01D9B970.Y() * lrFade);
        mnCoronaBlue = (int)(float)(D_01D9B970.Z() * lrFade);
        _rwDMAOpenVIFPkt(0x80000000, 0x21);
        u_long128 * q = farFogPlane.field_0;
        u_long128 lAD3 = func_0024C7E0_q(0x1000000000000003UL, 0xE);                      // GIFtag A+D, 3 regs
        q[0] = lAD3;
        q[1] = func_0024C7E0_q(5, 8);                                                    // CLAMP_1
        q[2] = func_0024C7E0_q(0x51001, 0x47);                                           // TEST_1
        q[3] = func_0024C7E0_q(0x6A, 0x42);                                              // ALPHA_1
        // GIFtag REGLIST: PRIM RGBAQ XYZ2 XYZ2 RGBAQ XYZ2 XYZ2 RGBAQ XYZ2 XYZ2
        q[4] = func_0024C7E0_q(0xA400000000000001UL, 0x5515515510UL);
        q[5] = func_0024C7E0_q(0x46, 0x3F80000000000000UL);                              // PRIM sprite+ABE, RGBAQ
        unsigned long lu64XY0 = func_0024C7E0_xy((lnSampleLeft & ~15) + mnGSOffsetX, (lnSampleTop & ~15) + mnGSOffsetY);
        unsigned long lu64XY1 = func_0024C7E0_xy(((lnSampleRight + 15) & ~15) + mnGSOffsetX,
                                                 ((lnSampleBottom + 15) & ~15) + mnGSOffsetY);
        q[6] = func_0024C7E0_q(lu64XY0 | 0x00FFFFFF00000000UL, lu64XY1 | 0x00FFFFFF00000000UL);
        q[7] = func_0024C7E0_q(0x3F80000040000000UL, lu64XY0 | 0x0000000100000000UL);
        q[8] = func_0024C7E0_q(lu64XY1 | 0x0000000100000000UL, 0x3F80000080000000UL);
        q[9] = func_0024C7E0_q(lu64XY0, lu64XY1);
        q[10] = lAD3;
        q[11] = func_0024C7E0_q(0x61, 0x14);                                             // TEX1_1
        u_long128 lFlush = func_0024C7E0_q(0, 0x3F);                                     // TEXFLUSH
        q[12] = lFlush;
        unsigned long t = (unsigned long)*lpFrame;
        q[13] = func_0024C7E0_q((t & 0x1FF) << 5 | ((t >> 16) & 0x3F) << 14 | 0x0000000E68000000UL, 6);   // TEX0_1
        q[14] = func_0024C7E0_q(0x5400000000000001UL, 0x53530);                          // GIFtag REGLIST: PRIM UV XYZ2 UV XYZ2
        unsigned long lu64Origin = func_0024C7E0_xy(mnGSOffsetX, mnGSOffsetY) | 0x00FFFFFF00000000UL;
        int ny = (int)(16.0f * mScreenOffset.marValues[1]);
        int nx = (int)(16.0f * mScreenOffset.marValues[0]);
        q[15] = func_0024C7E0_q(0x156, func_0024C7E0_xy(lnSampleLeft + nx + 8, lnSampleTop + ny + 8));
        q[16] = func_0024C7E0_q(lu64Origin, func_0024C7E0_xy(lnSampleRight + nx, lnSampleBottom + ny));
        q[17] = func_0024C7E0_q(func_0024C7E0_xy(mnGSOffsetX + 0x80, mnGSOffsetY + 0x80) | 0x00FFFFFF00000000UL, 0);
        q += 18;
        int lnSampleSize = 0x80;
        for (int lnCount = 0; lnCount < 2; lnCount++) {
            q[0] = func_0024C7E0_q(0x1000000000000001UL, 0xE);                           // GIFtag A+D, 1 reg
            q[1] = lFlush;
            q[2] = func_0024C7E0_q(0x4400000000000001UL, 0x5353);                        // GIFtag REGLIST: UV XYZ2 UV XYZ2
            q[3] = func_0024C7E0_q(func_0024C7E0_xy(nx + 16, ny + 16), lu64Origin);
            unsigned long uv = func_0024C7E0_xy(nx + 16 + lnSampleSize, ny + 16 + lnSampleSize);
            lnSampleSize >>= 1;
            q[4] = func_0024C7E0_q(uv, func_0024C7E0_xy(lnSampleSize + mnGSOffsetX, lnSampleSize + mnGSOffsetY) | 0x00FFFFFF00000000UL);
            q += 5;
        }
        q[0] = func_0024C7E0_q(0x1000000000008004UL, 0xE);
        q[1] = *lpFrame;
        q[2] = func_0024C7E0_q(skyTest_1, 0x47);
        q[3] = func_0024C7E0_q(skyAlpha_1, 0x42);
        q[4] = func_0024C7E0_q(skyTex1_1, 0x14);
        farFogPlane.field_0 = q + 5;
    } else {
        mbBehind = true;
    }
}
