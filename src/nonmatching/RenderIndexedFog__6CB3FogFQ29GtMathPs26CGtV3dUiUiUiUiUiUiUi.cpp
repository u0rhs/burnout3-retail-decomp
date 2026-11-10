// NONMATCHING: RenderIndexedFog__6CB3FogFQ29GtMathPs26CGtV3dUiUiUiUiUiUiUi -- retail 231 / ours 226 instructions, 238 in changed runs
// draftAN C-first: GS packet redrawing the fog rectangle's frame-buffer alpha from the indexed Z texture: FRAME (alpha mask), ZBUF, SCISSOR, TEX0 (frame buffer as PSMT8H through the CLUT at D_006662D0 + 0x17C, CLD 1), TEST, ALPHA, RGBAQ (colour x 64 + 0.5 truncated, A 0x80, Q 1.0), GIF tag n x (UV, XYZ2, UV, XYZ2), one sprite per 32-pixel strip (last strip ends at the right edge); 226/231, calls identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every qword's lo/hi halves and each bit field's source (zero- vs sign-extended), the strip count and do-while loop (no entry test), the 0x200 strip step / last-strip clamp traced; behaviour_audit quiet (branch census only)

// RenderIndexedFog__6CB3FogFQ29GtMathPs26CGtV3dUiUiUiUiUiUiUi -- draftAN (C-first draft). 0x241040, 0x39C. [C] name: the mangled
// symbol; a static member (a0 is the colour's address, a1..t3 the seven integers: no this). Parameter / local names from Revenge
// STABS RenderIndexedFog__6CB4Fog (B4FogPS2.cpp: lFogColour, lnLeft, lnTop, lnWidth, lnHeight, lnFBP, lnFBW, lnZBP, lnNumStrips,
// lnX) [L]; register meanings [L] from the GS register each one lands in.
// What it does [L]: a GS packet that redraws the fog rectangle's frame-buffer alpha from the indexed Z texture: FRAME (alpha only),
// ZBUF, SCISSOR, TEX0 (the frame buffer read as an 8H indexed texture through the fog CLUT at D_006662D0 + 0x17C), TEST, ALPHA,
// RGBAQ (the colour x 64, rounded, A 0x80, Q 1.0), then one sprite pair (UV + XYZ2) per 32-pixel strip.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_farFogPlane { u_long128 *field_0; };
extern UnkStruct_farFogPlane farFogPlane;   // [C] symbol name (the DMA packet cursor)
struct UnkStruct_D_006662D0 { int field_0; int pad_4[3]; };   // as B3SkyDomeRendererPS2_0021E100.cpp
extern UnkStruct_D_006662D0 D_006662D0;     // [G] the frame-buffer / VRAM layout (base block)
extern "C" void _rwDMAOpenVIFPkt(unsigned int, int);

static inline u_long128 func_00241040_q(unsigned long lo, unsigned long hi)
{
    u_long128 r;
    asm("pcpyld %0, %2, %1" : "=r"(r) : "r"(lo), "r"(hi));
    return r;
}

// 0x00241040
extern "C" void RenderIndexedFog__6CB3FogFQ29GtMathPs26CGtV3dUiUiUiUiUiUiUi(const CGtV3d &rFogColour, unsigned int lnLeft,
                                                                          unsigned int lnTop, unsigned int lnWidth, unsigned int lnHeight,
                                                                          unsigned int lnFBP, unsigned int lnFBW, unsigned int lnZBP)
{
    CGtV3d lFogColour = rFogColour;
    unsigned int luRight = lnLeft + lnWidth;
    int lnNumStrips = ((luRight + 31) >> 5) - (lnLeft >> 5);
    _rwDMAOpenVIFPkt(0x80000000, lnNumStrips * 2 + 10);
    u_long128 *p = farFogPlane.field_0;
    p[0] = func_00241040_q(0x10AB400000000008UL, 0xE);
    p[1] = func_00241040_q(0, 0x3F);
    p[2] = func_00241040_q((unsigned long)lnFBP | ((unsigned long)lnFBW << 16) | 0xFF00000000000000UL, 0x4C);      // FRAME_1
    p[3] = func_00241040_q((unsigned long)lnZBP | 0x1000000, 0x4E);                                               // ZBUF_1
    p[4] = func_00241040_q((unsigned long)lnLeft | ((unsigned long)(luRight - 1) << 16) | ((unsigned long)lnTop << 32) |
                           ((unsigned long)(lnTop + lnHeight - 1) << 48), 0x40);                                    // SCISSOR_1
    p[5] = func_00241040_q((unsigned long)(lnFBP << 5) | ((unsigned long)lnFBW << 14) | 0xA9B00000UL | (6UL << 32) |
                           ((unsigned long)(unsigned int)(D_006662D0.field_0 + 0x17C) << 37) | (0x20000000UL << 32), 6);   // TEX0_1
    p[6] = func_00241040_q(0x71001, 0x47);   // TEST_1
    p[7] = func_00241040_q(0x44, 0x42);      // ALPHA_1
    int lnBlue = (int)(float)(lFogColour.Z() * 64.0f + 0.5f);
    int lnRed = (int)(float)(lFogColour.X() * 64.0f + 0.5f);
    int lnGreen = (int)(float)(lFogColour.Y() * 64.0f + 0.5f);
    p[8] = func_00241040_q(((long)lnBlue << 16) | ((long)lnRed | ((long)lnGreen << 8)) | (0x8000UL << 16) | (0x3F800000UL << 32), 1);   // RGBAQ
    p[9] = func_00241040_q((long)lnNumStrips | 0x8000 | (0x44000000UL << 32), 0x5353);   // GIF tag: n x (UV, XYZ2, UV, XYZ2)
    int luTop = lnTop << 4;
    int luBottom = (lnTop + lnHeight) << 4;
    int lnX = lnLeft << 4;
    int luRight16 = luRight << 4;
    unsigned long lTopUV = (long)(luTop + 8) << 16, lTopXY = (long)luTop << 16;
    unsigned long lBotUV = (long)(luBottom + 8) << 16, lBotXY = (long)luBottom << 16;
    unsigned long lZ = 0xFFFFUL << 32;
    u_long128 *s = p + 10;
    do {                                     // [C] no entry test (bnez at the bottom): a zero strip count would never end
        s[0] = func_00241040_q((long)(lnX + 8) | lTopUV, (long)lnX | lTopXY | lZ);
        if (--lnNumStrips == 0)
            lnX = luRight16;
        else
            lnX = (lnX + 0x200) & -0x200;
        s[1] = func_00241040_q((long)(lnX + 8) | lBotUV, (long)lnX | lBotXY | lZ);
        s += 2;
    } while (lnNumStrips != 0);
    farFogPlane.field_0 = s;
}
