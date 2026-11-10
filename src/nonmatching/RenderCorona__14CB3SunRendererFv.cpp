// NONMATCHING: RenderCorona__14CB3SunRendererFv -- retail 542 / ours 540 instructions, 462 in changed runs
// draftAL C-first: corona texture made resident (RpSkyTexCache), VIF packet 0x17/0x3C, GS A+D data: FRAME_1, TEX0_1 (frame table), CLAMP_1, TEST_1, SCISSOR_1, ALPHA_1, the corona sprite (RGBAQ, UV/XYZ2 by radius x aspect), 12 lens-flare secondaries (D_004BB610 table, frame-clock flicker from the float's bits), sky TEST/ALPHA/TEX1 restore; 540/542, calls identical; pcpyld through one helper; left: retail re-loads the frame-table qword (lq x2), constant materialisation order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra's folded 64-bit constants checked against it); every one of the 23 + 12x3 qwords' lo/hi halves, register ids, sign-extension (dsll32/dsra32 = (long)int), signed /16 and /2, the flicker xor and the colour divides traced

// CB3SunRenderer::RenderCorona() -- draftAL (C-first draft). 0x24BF60, 0x878. [C] name: the mangled symbol in retail's tables;
// the static members by their mangled names in retail's symbol table. Written from the retail asm (Ghidra's draft as a reading
// aid for the folded 64-bit constants); local names from the Revenge STABS of CB4SunRenderer::RenderCorona (B4SunRendererPS2.cpp:
// lnRadiusX/Y, lpRasExt, lbSecondaries -- a function-scope `static bool` there, D_004E1978 here, initial value 1 --,
// lnSecondaryX/Y, lnSecondaryRadiusX/Y, lrRandom, lnRandom, lnU, lnV, lnUWidth, lnVHeight).
// What it does [L]: unless the sun is behind the camera, makes the corona texture resident (RpSkyTexCache), opens a VIF packet
// (0x17 qwords, 0x3C with the secondaries) and writes GS A+D register data: FRAME_1 (frame mask 0xFFFFFF), TEX0_1 from the
// current frame's table entry, CLAMP_1 5, TEST_1, SCISSOR_1, ALPHA_1; then one sprite (RGBAQ = corona colour, UV/XYZ2 corners
// around mnCoronaX/Y by the corona radius in 1/16 pixels; the texture's TEX0, a full-screen scissor) and, with lbSecondaries,
// 12 lens-flare sprites placed along the line from the screen centre through the sun (table D_004BB610: position, size, rgb
// scale, UV quadrant flags), dimmed by a per-frame pseudo-random flicker; last the sky's TEST_1 / ALPHA_1 / TEX1_1 restore.
// Types and field meanings [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_0024BF60_ext { unsigned char pad_0[0x8]; unsigned int field_8; unsigned int field_C; };   // [L] GtSkyRasterExt
struct UnkStruct_0024BF60_ras {             // [L] the corona texture's raster
    unsigned char pad_0[0xC];
    int field_C;                            // width
    int field_10;                           // height
    unsigned char pad_14[0x20];
    UnkStruct_0024BF60_ext field_34;
};
struct UnkStruct_0024BF60_sec {             // D_004BB610[12], 0x18 bytes: one lens-flare secondary
    float field_0;                          // position along the centre-sun line
    float field_4;                          // size (x the corona radius)
    float field_8;                          // red scale
    float field_C;                          // green scale
    float field_10;                         // blue scale
    unsigned int field_14;                  // UV quadrant (bit 0: right half, bit 1: lower half)
};
extern UnkStruct_0024BF60_sec D_004BB610[12];
struct UnkStruct_0024BF60_tab { unsigned char pad_0[0x630]; u_long128 field_630; unsigned char pad_640[0x230 - 0x10]; };
extern UnkStruct_0024BF60_tab D_00665EC0[];   // [G] per-frame table, 0x230 per entry (as RenderEnvmapCorona)
extern int D_00667050;                        // [G] the current frame
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_farFogPlane farFogPlane;     // [C] symbol name (the DMA packet cursor)
extern void * skyTextureRaster;
extern unsigned long skyTest_1;
extern unsigned long skyAlpha_1;
extern unsigned long skyTex1_1;
extern float D_00522680[];                    // [G] a clock (lui/%lo: part of a larger object)
extern bool D_004E1978;                       // [L] Revenge's `static bool lbSecondaries` (initial value 1)
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void RpSkyTexCacheAccessSpeculate(void *);
extern "C" void * RpSkyTexCacheAccessRaster(void *, int);

class CB3SunRenderer {
public:
    static void RenderCorona();
    static bool mbBehind;
    static UnkStruct_0024BF60_ras * mpCoronaTexture;
    static float mrCoronaRadius;
    static float mrAspectRatio;
    static int mnScreenSizeX;
    static int mnScreenSizeY;
    static CGtV2d mScreenOffset;
    static int mnCoronaRed;
    static int mnCoronaGreen;
    static int mnCoronaBlue;
    static int mnXYOffsetX;
    static int mnXYOffsetY;
    static int mnCoronaX;
    static int mnCoronaY;
    static int mnGSOffsetX;
    static int mnGSOffsetY;
};

// one GS qword: lo 64 bits, hi 64 bits (pcpyld, as the sibling archives)
static inline u_long128 func_0024BF60_q(unsigned long lo, unsigned long hi)
{
    u_long128 r;
    asm("pcpyld %0, %2, %1" : "=r"(r) : "r"(lo), "r"(hi));
    return r;
}
// GS XY / UV pair: x | y << 16 (each sign-extended from int)
static inline unsigned long func_0024BF60_xy(int x, int y) { return (long)x | (long)y << 16; }

// 0x0024BF60
void CB3SunRenderer::RenderCorona()
{
    UnkStruct_0024BF60_tab * tab = &D_00665EC0[D_00667050];
    if (mbBehind)
        return;
    bool ok;
    UnkStruct_0024BF60_ras * tex = mpCoronaTexture;
    if (skyTextureRaster != tex) {
        RpSkyTexCacheAccessSpeculate(tex);
        if (RpSkyTexCacheAccessRaster(tex, 0) == 0) {
            ok = false;
            goto done;
        }
        skyTextureRaster = tex;
    }
    ok = true;
done:
    if (!ok)
        return;

    float r16 = 16.0f * mrCoronaRadius;
    int lnScreenMaxX = mnScreenSizeX << 4;
    int lnScreenMaxY = mnScreenSizeY << 4;
    int lnRadiusX = (int)r16;
    int lnRadiusY = (int)(r16 * mrAspectRatio);
    UnkStruct_0024BF60_ext * lpRasExt = &mpCoronaTexture->field_34;
    if (D_004E1978)
        _rwDMAOpenVIFPkt(0x80000000, 0x3C);
    else
        _rwDMAOpenVIFPkt(0x80000000, 0x17);
    u_long128 * q = farFogPlane.field_0;
    q[0] = func_0024BF60_q(0x10AB400000000009UL, 0xE);
    q[1] = func_0024BF60_q((unsigned long)((lpRasExt->field_C & 0x7FFE0) >> 10) | 0x00FFFFFF00010000UL, 0x4C);   // FRAME_1
    unsigned long t = (unsigned long)tab->field_630;
    q[2] = func_0024BF60_q((t & 0x1FF) << 5 | ((t >> 16) & 0x3F) << 14 | 0x0000000E68000000UL, 6);              // TEX0_1
    q[3] = func_0024BF60_q(5, 8);                                                                                 // CLAMP_1
    q[4] = func_0024BF60_q(0x31001, 0x47);                                                                        // TEST_1
    q[5] = func_0024BF60_q(0x000F0000000F0000UL, 0x40);                                                           // SCISSOR_1
    q[6] = func_0024BF60_q(((long)mnCoronaBlue << 16 | ((long)mnCoronaRed | (long)mnCoronaGreen << 8)) | 0x3F80000080000000UL, 1);   // RGBAQ
    int ny = (int)(16.0f * mScreenOffset.Y());
    int nx = (int)(16.0f * mScreenOffset.X());
    q[7] = func_0024BF60_q(func_0024BF60_xy(nx + 16, ny + 16), 3);                                                // UV
    q[8] = func_0024BF60_q(func_0024BF60_xy(mnXYOffsetX, mnXYOffsetY) | 0x00FFFFFF00000000UL, 5);                 // XYZ2
    q[9] = func_0024BF60_q(func_0024BF60_xy(mnXYOffsetX + 0x100, mnXYOffsetY + 0x100) | 0x00FFFFFF00000000UL, 5);
    q[10] = func_0024BF60_q(0x1000000000000005UL, 0xE);
    q[11] = func_0024BF60_q(0, 0x3F);                                                                             // TEXFLUSH
    q[12] = tab->field_630;
    q[13] = func_0024BF60_q((unsigned long)lpRasExt->field_C << 32 | lpRasExt->field_8, 6);                       // TEX0_1
    q[14] = func_0024BF60_q(0x48, 0x42);                                                                          // ALPHA_1
    int sx = nx / 16;
    int sy = ny / 16;
    q[15] = func_0024BF60_q((long)sy << 32 | ((long)sx | (long)(mnScreenSizeX + sx - 1) << 16) | (long)(mnScreenSizeY + sy - 1) << 48,
                            0x40);                                                                                // SCISSOR_1
    q[16] = func_0024BF60_q(0x4400000000000001UL, 0x5353);                                                        // GIFtag: UV XYZ2 UV XYZ2
    q[17] = func_0024BF60_q(0x80008, func_0024BF60_xy(mnGSOffsetX + (mnCoronaX - lnRadiusX), mnGSOffsetY + (mnCoronaY - lnRadiusY)) |
                                         0x00FFFFFF00000000UL);
    unsigned long uv;
    if (D_004E1978)
        uv = func_0024BF60_xy(mpCoronaTexture->field_C * 16 - 8, mpCoronaTexture->field_10 * 8 - 8);
    else
        uv = func_0024BF60_xy(mpCoronaTexture->field_C * 16 - 8, mpCoronaTexture->field_10 * 16 - 8);
    q[18] = func_0024BF60_q(uv, func_0024BF60_xy(mnGSOffsetX + (mnCoronaX + lnRadiusX), mnGSOffsetY + (mnCoronaY + lnRadiusY)) |
                                    0x00FFFFFF00000000UL);
    q += 19;
    if (D_004E1978) {
        // 12 secondaries: GIFtag NLOOP 12, REGLIST RGBAQ RGBAQ UV XYZ2 UV XYZ2
        *q++ = func_0024BF60_q(0x640000000000000CUL, 0x535311);
        int lnUWidth = mpCoronaTexture->field_C * 8 - 8;
        int lnVHeight = mpCoronaTexture->field_10 * 4 - 8;
        union { float f; int i; } lrRandom;
        lrRandom.f = D_00522680[0] * (0.93456787f * D_00522680[0]);
        lrRandom.f = lrRandom.f - (float)(int)lrRandom.f;
        int cx = lnScreenMaxX / 2;
        int dx = mnCoronaX - cx;
        int cy = lnScreenMaxY / 2;
        int dy = mnCoronaY - cy;
        for (int i = 0; i < 12; i++) {
            UnkStruct_0024BF60_sec * e = &D_004BB610[i];
            lrRandom.f = (lrRandom.f - 0.93456787f) * (lrRandom.f - 0.93456787f);
            int b = lrRandom.i;
            int lnRandom = 0xFF00 - ((((b & 0xFF0000) >> 16) ^ ((b & 0xFF) ^ ((b & 0xFF00) >> 8))) << 6);
            int lnSecondaryX = cx + (int)(e->field_0 * (float)dx);
            int lnSecondaryY = cy + (int)(e->field_0 * (float)dy);
            int lnSecondaryRadiusX = (int)(e->field_4 * (float)lnRadiusX);
            int lnSecondaryRadiusY = (int)(e->field_4 * (float)lnRadiusY);
            int lnSecondaryRed = (int)(e->field_8 * (float)((mnCoronaRed * lnRandom) / 0xFF00));
            int lnSecondaryGreen = (int)(e->field_C * (float)((mnCoronaGreen * lnRandom) / 0xFF00));
            int lnSecondaryBlue = (int)(e->field_10 * (float)((mnCoronaBlue * lnRandom) / 0xFF00));
            unsigned long rgba = ((long)lnSecondaryBlue << 16 | ((long)lnSecondaryRed | (long)lnSecondaryGreen << 8)) | 0x3F80000080000000UL;
            q[0] = func_0024BF60_q(rgba, rgba);
            unsigned int f = e->field_14;
            int lnU = (f & 1) * 8 * mpCoronaTexture->field_C + 8;
            int lnV = (f & 2) * 2 * mpCoronaTexture->field_10 + 8 + mpCoronaTexture->field_10 * 8;
            q[1] = func_0024BF60_q(func_0024BF60_xy(lnU, lnV),
                                   func_0024BF60_xy(mnGSOffsetX + (lnSecondaryX - lnSecondaryRadiusX),
                                                    mnGSOffsetY + (lnSecondaryY - lnSecondaryRadiusY)) | 0x00FFFFFF00000000UL);
            q[2] = func_0024BF60_q(func_0024BF60_xy(lnU + lnUWidth, lnV + lnVHeight),
                                   func_0024BF60_xy(mnGSOffsetX + (lnSecondaryX + lnSecondaryRadiusX),
                                                    mnGSOffsetY + (lnSecondaryY + lnSecondaryRadiusY)) | 0x00FFFFFF00000000UL);
            q += 3;
        }
    }
    q[0] = func_0024BF60_q(0x1000000000008003UL, 0xE);
    q[1] = func_0024BF60_q(skyTest_1, 0x47);
    q[2] = func_0024BF60_q(skyAlpha_1, 0x42);
    q[3] = func_0024BF60_q(skyTex1_1, 0x14);
    farFogPlane.field_0 = q + 4;
}
