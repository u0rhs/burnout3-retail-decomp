// NONMATCHING: PrepareEnvmapSunCoronaData__14CB3SunRendererFv -- retail 349 / ours 362 instructions, 389 in changed runs
// draftAG: logic complete; retail 349 / ours 362; calls identical; VU arithmetic op counts identical with header CrossProduct / Normalise / Interpolate(CGtV3d) / operator+/-; the 12 extra vmove come from the header CGtV3d +/- bodies' fixed $vf1/$vf2 registers (RenderEnvmapBlob's draft used compiler-chosen stand-ins instead; kept the header APIs for portability); left: frame 0x260 vs 0x1C0, lq/sq vs lqc2/sqc2 split
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Revenge's STABS locals (same function, 181 instrs); every store (16 grid positions + UVs, TEX0 qword), loop bound and call accounted for; call sequence identical (calls.sh)

// CB3SunRenderer::PrepareEnvmapSunCoronaData() -- draftAG (C-first draft; the lifter refused it).
// [C] name: retail symbol table. Written from the retail asm; local names after Revenge's own PrepareEnvmapSunCoronaData (STABS,
// B4SunRendererPS2.cpp: laCornerVerts, laCornerUVs, lnCount, lrStep, lInput, lpRasExt) [L]. Globals as the archived siblings
// RenderEnvmapBlob / RenderEnvmapCorona (D_00666320 camera position, D_01D9B940 sun direction, D_01D9B980[16] / D_01D9BA80[16]
// the corona grid read by RenderEnvmapCorona, D_01D9BB00 its TEX0 GIF qword).
// What it does [L]: a 50 x 50 billboard 50 units along the sun direction from the camera, facing it (right = dir x up,
// up' = right x dir, both normalised); its 4 corners and UVs go to the corners of a 4 x 4 grid, the edge columns and then
// every row are filled by linear interpolation in thirds; the corona texture is touched in the texture cache, its TEX0 is
// stored for the GIF packet, and offscreen buffer 4 is cleared.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGtTexture {                          // [G] fields seen here only
public:
    unsigned char pad_0[0x3C];
    unsigned int field_3C;                  // [C] TEX0 low word (lwu)
    unsigned int field_40;                  // [C] TEX0 high word
};
enum EGtTextureCachePS2_FilterMode { };
class CGtTextureCache {
public:
    void AccessTexture(CGtTexture *, float, EGtTextureCachePS2_FilterMode, bool, bool);
};
class CB3GraphicsManager {
public:
    void ClearOffscreenBuffer(unsigned int);
};
class CB3SunRenderer {
public:
    static CGtTexture *mpEnvmapCoronaTexture;   // [C] mangled name
    static void PrepareEnvmapSunCoronaData();
};
extern CGtTextureCache gTextureCache;       // [C] symbol name
extern CB3GraphicsManager D_00665EC0;       // [L] the graphics manager (RenderEnvmapBlob draft's D_00665EC0)
extern CGtV3d D_00666320;                   // [C] camera position (RenderEnvmapBlob draft)
extern CGtV3d D_01D9B930;                   // [C] its copy for the corona render [G]
extern CGtV3d D_01D9B940;                   // [C] sun direction
extern CGtV3d D_01D9B980[16];               // [C] grid positions
extern CGtV2d D_01D9BA80[16];               // [C] grid UVs
extern u_long128 D_01D9BB00;                // [C] TEX0 GIF qword

// [L] N185-style stand-in: a GIF A+D qword {data, register} (pcpyld, as RenderEnvmapCorona's packet)
static inline u_long128 func_0024B9E0_inl1(unsigned long lo, unsigned long hi) { u_long128 r; asm("pcpyld %0, %2, %1" : "=r"(r) : "r"(lo), "r"(hi)); return r; }

// 0x0024B9E0
void CB3SunRenderer::PrepareEnvmapSunCoronaData()
{
    CGtV3d laCornerVerts[4];
    CGtV2d laCornerUVs[4];
    CGtV3d lUp(0.0f, 1.0f, 0.0f);
    D_01D9B930 = D_00666320;
    CGtV3d lDir = D_01D9B940;
    CGtV3d lRight = CrossProduct(lDir, lUp);
    lRight.Normalise();
    CGtV3d lUp2 = CrossProduct(lRight, lDir);
    lUp2.Normalise();
    laCornerUVs[0] = CGtV2d(0.0f, 0.0f);
    laCornerUVs[1] = CGtV2d(1.0f, 0.0f);
    laCornerUVs[2] = CGtV2d(0.0f, 1.0f);
    laCornerUVs[3] = CGtV2d(1.0f, 1.0f);
    CGtV3d lCentre = D_00666320 + lDir * 50.0f;
    lRight = lRight * 25.0f;
    lUp2 = lUp2 * 25.0f;
    laCornerVerts[0] = lCentre - lRight + lUp2;
    laCornerVerts[1] = lCentre + lRight + lUp2;
    laCornerVerts[2] = lCentre - lRight - lUp2;
    ((float *)&laCornerVerts[2])[3] = ((const float *)&D_00666320)[3]; // [C] 0x24BA08 lq v0, D_00666320 (vf2's register); 0x24BBB0 / 0x24BBB4 vsub.xyz keep vf2's w; 0x24BBB8 sqc2 vf2, D_01D9BA40 (port lane vu0, culprit #13)
    laCornerVerts[3] = lCentre + lRight - lUp2;
    ((float *)&laCornerVerts[3])[3] = ((const float *)&laCornerVerts[1])[3]; // [C] 0x24BBA8/0x24BBAC build corner 1 in vf1;
    // 0x24BBC8 vadd.xyz vf1, vf3, vf5 into that register and 0x24BBCC vsub.xyz vf1, vf1, vf4 keep its w; 0x24BBD0 sqc2 vf1, D_01D9BA70
    // -- the port's `(a + b) - c` took lRight's w. Corners 0/1 (0x24BB88, 0x24BBAC) need nothing: their w is vf1's from 0x24BAE8
    // qmtc2 v1 (lui 50.0 over 0x24BAA4's qmfc2 v1, vf4: upper half = lUp2) = lUp2.w [L], which `... + lUp2` also gives
    D_01D9B980[0] = laCornerVerts[0];
    D_01D9B980[3] = laCornerVerts[1];
    D_01D9B980[12] = laCornerVerts[2];
    D_01D9B980[15] = laCornerVerts[3];
    D_01D9BA80[0] = laCornerUVs[0];
    D_01D9BA80[3] = laCornerUVs[1];
    D_01D9BA80[12] = laCornerUVs[2];
    D_01D9BA80[15] = laCornerUVs[3];
    float lrStep = 0.33333334f;
    CGtV3d lStep(lrStep, 0.0f, 0.0f);
    // the left and right columns
    CGtV3d lInput;
    lInput.Zero();
    for (int lnCount = 4; lnCount < 12; lnCount += 4) {
        lInput = lInput + lStep;
        float t = lInput.X();
        D_01D9BA80[lnCount] = D_01D9BA80[0] + (D_01D9BA80[12] - D_01D9BA80[0]) * t;
        D_01D9B980[lnCount] = Interpolate(D_01D9B980[0], D_01D9B980[12], t);
    }
    lInput.Zero();
    for (int lnCount = 7; lnCount < 12; lnCount += 4) {
        lInput = lInput + lStep;
        float t = lInput.X();
        D_01D9BA80[lnCount] = D_01D9BA80[3] + (D_01D9BA80[15] - D_01D9BA80[3]) * t;
        D_01D9B980[lnCount] = Interpolate(D_01D9B980[3], D_01D9B980[15], t);
    }
    // every row between its two ends
    for (int lnRow = 0; lnRow < 4; lnRow++) {
        int k = lnRow * 4;
        lInput.Zero();
        for (int lnCount = k + 1; lnCount < k + 3; lnCount++) {
            lInput = lInput + lStep;
            float t = lInput.X();
            D_01D9BA80[lnCount] = D_01D9BA80[k] + (D_01D9BA80[k + 3] - D_01D9BA80[k]) * t;
            D_01D9B980[lnCount] = Interpolate(D_01D9B980[k], D_01D9B980[k + 3], t);
        }
    }
    gTextureCache.AccessTexture(mpEnvmapCoronaTexture, 0.0f, (EGtTextureCachePS2_FilterMode)1, false, false);
    CGtTexture *lpRasExt = mpEnvmapCoronaTexture;   // [L] Revenge: GtSkyRasterExt *lpRasExt (the raster extension's TEX0)
    D_01D9BB00 = func_0024B9E0_inl1((unsigned long)lpRasExt->field_3C | ((unsigned long)lpRasExt->field_40 << 32), 6);
    D_00665EC0.ClearOffscreenBuffer(4);
}
