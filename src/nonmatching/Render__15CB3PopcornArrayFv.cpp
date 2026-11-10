// NONMATCHING: Render__15CB3PopcornArrayFv -- retail 342 / ours 341 instructions, 302 in changed runs
// draftAM C-first: popcorn VU1 render setup: texture made resident (RpSkyTexCacheAccess*), a 0x22-qword VIF packet: microprogram call when vu_game_0047C6F0 is not resident (skyUserSwitch1), GS A+D TEX0 (field_0) / TEST / CLAMP / ST / RGBAQ, then the VU data: view matrix rows with the z-clip terms (far = min(camera far, field_44), (n+f)/(f-n), -2nf/(f-n)), XYZ scale/shift/offset, time, view window, two colours x 128, two raw rows, a constant row, the frame step, the unpack header (field_20) and the sky TEST/ALPHA/CLAMP restore; 341/342, calls identical, every store at retail's offset (sq/sqc2 kinds differ)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; each of the 31 qwords' lo/hi halves (pcpyld operand order), every lane of the VU data rows including the two lanes retail never sets (row 11 z keeps the far clip, row 23 x/w keep 0/1.0 from row 22: one CGtV4d reused, as retail's single $vf1), row 19 stored twice, the min.s far clip and the product orders traced; behaviour_audit clean

// CB3PopcornArray::Render() -- draftAM (C-first draft). 0x365920, 0x558. [C] name: the mangled symbol. Local names from the Revenge
// STABS of CB4PopcornArray::Render (B4PopcornRendererPS2.cpp: lPack, lpCamera, lpViewMatrix, lrCurrentTime, lrTimestep, lrNearClip,
// lrFarClip, lrRecipD, lrZClipA, lrZClipB). The camera is RenderWare's RwCamera (3.x layout: view matrix at +0x20, view window,
// near/far planes) [L]; placeholders kept. Meanings of the popcorn fields [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00365920_cam {             // [L] the current RwCamera (RW 3.x layout; placeholders)
    unsigned char pad_0[0x20];
    float field_20[16];                     // [L] the view matrix (right, up, at, pos; 4 floats each)
    unsigned char pad_60[0x8];
    float field_68;                         // [L] view window x
    unsigned char pad_6C[0x4];
    float field_70;                         // [L] reciprocal view window
    float field_74;
    unsigned char pad_78[0x8];
    float field_80;                         // [L] near plane
    float field_84;                         // [L] far plane
};
struct UnkStruct_00365920_g { UnkStruct_00365920_cam * field_0; };
struct UnkStruct_00365920_prm {             // [G] the popcorn array's render parameters
    unsigned char pad_0[0xC];
    float field_C;
    float field_10;
    float field_14[4];                      // [G] colour 0 (x 128)
    float field_24[4];                      // [G] colour 1 (x 128)
    float field_34[4];
    float field_44;                         // [G] draw distance
};
class CB3PopcornArray {
public:
    void Render();
    u_long128 field_0;                      // [G] TEX0 register data
    float field_10;                         // [G] copied raw into the VU data (count or time)
    unsigned char pad_14[0xC];
    unsigned int field_20;                  // [G] VIF unpack size
    unsigned char pad_24[0x8];
    void * field_2C;                        // the texture (raster)
    UnkStruct_00365920_prm * field_30;
};
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_farFogPlane farFogPlane;   // [C] symbol name (the DMA packet cursor)
struct UnkStruct_skyUserSwitch1 { void * field_0; };
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;   // [L] the VU1 microcode currently resident
extern UnkStruct_00365920_g ourGlobals;
extern void * skyTextureRaster;
extern unsigned long skyTest_1;
extern unsigned long skyAlpha_1;
extern unsigned long skyClamp_1;
extern char vu_game_0047C6F0[];             // the popcorn VU1 microprogram
extern u_long128 vu1DataXYZScale;
extern u_long128 vu1DataXYZShift;
extern u_long128 vu1DataOffset3D;
extern float D_00522680[];                  // [G] the clock (lui/%lo: part of a larger object)
extern float D_0052267C[];                  // [G] the frame time step
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void RpSkyTexCacheAccessSpeculate(void *);
extern "C" void * RpSkyTexCacheAccessRaster(void *, int);

static inline u_long128 func_00365920_q(unsigned long lo, unsigned long hi)
{
    u_long128 r;
    asm("pcpyld %0, %2, %1" : "=r"(r) : "r"(lo), "r"(hi));
    return r;
}

// 0x00365920
void CB3PopcornArray::Render()
{
    float lrCurrentTime = D_00522680[0];
    void * tex = field_2C;
    float lrTimestep = D_0052267C[0];
    UnkStruct_00365920_cam * lpCamera = ourGlobals.field_0;
    const float * lpViewMatrix = lpCamera->field_20;
    if (skyTextureRaster != tex) {
        RpSkyTexCacheAccessSpeculate(tex);
        if (RpSkyTexCacheAccessRaster(tex, 0) != 0)
            skyTextureRaster = tex;
    }
    _rwDMAOpenVIFPkt(0, 0x22);
    u_long128 * p = farFogPlane.field_0;
    if (skyUserSwitch1.field_0 != vu_game_0047C6F0) {
        // DMA call of the microprogram (address in the upper word)
        p[0] = func_00365920_q((unsigned long)(unsigned int)vu_game_0047C6F0 << 32 | 0x50000000, 0);
        skyUserSwitch1.field_0 = vu_game_0047C6F0;
    } else {
        p[0] = func_00365920_q(0x10000000, 0x1000000000000000UL);
    }
    u_long128 * q = p + 1;
    q[0] = func_00365920_q(0x10000006, 0x5000000600000000UL);
    q[1] = func_00365920_q(0x1000000000008005UL, 0xE);       // GIFtag A+D, 5 regs
    q[2] = field_0;                                          // TEX0_1
    q[3] = func_00365920_q(0x53001, 0x47);                   // TEST_1
    q[4] = func_00365920_q(5, 8);                            // CLAMP_1
    q[5] = func_00365920_q(0, 2);                            // ST
    q[6] = func_00365920_q(0x3F80000000000000UL, 1);         // RGBAQ (Q 1.0)
    q[7] = func_00365920_q(0x10000010, 0x6C1003F001000101UL);
    UnkStruct_00365920_prm * prm = field_30;
    float lrNearClip = lpCamera->field_80;
    float lrFarClip = GtMath::Min(lpCamera->field_84, prm->field_44);
    float lrRecipD = 1.0f / (lrFarClip - lrNearClip);
    float lrZClipB = lrRecipD * (-2.0f * lrNearClip * lrFarClip);
    float lrZClipA = lrRecipD * (lrNearClip + lrFarClip);
    CGtV4d lPack;                           // one vector reused for every row: lanes not set keep the previous row's value
    lPack.SetX(lpViewMatrix[0]);
    lPack.SetY(lpViewMatrix[1]);
    lPack.SetZ(lrZClipB);
    lPack.SetA(lpViewMatrix[2]);
    q[8] = lPack.mData;
    lPack.SetX(lpViewMatrix[4]);
    lPack.SetY(lpViewMatrix[5]);
    lPack.SetZ(lrZClipA);
    lPack.SetA(lpViewMatrix[6]);
    q[9] = lPack.mData;
    lPack.SetX(lpViewMatrix[8]);
    lPack.SetY(lpViewMatrix[9]);
    lPack.SetZ(lrFarClip);
    lPack.SetA(lpViewMatrix[10]);
    q[10] = lPack.mData;
    lPack.SetX(lpViewMatrix[12]);
    lPack.SetY(lpViewMatrix[13]);
    lPack.SetA(lpViewMatrix[14]);           // [C] z not set: keeps lrFarClip from the row before
    q[11] = lPack.mData;
    lPack.SetX(0.0f);
    q[12] = vu1DataXYZScale;
    q[13] = vu1DataXYZShift;
    q[14] = vu1DataOffset3D;
    lPack.SetY(field_10);
    lPack.SetZ(0.0f);
    lPack.SetA(lrCurrentTime);
    q[15] = lPack.mData;
    lPack.SetX(lpCamera->field_70);
    lPack.SetY(lpCamera->field_74);
    lPack.SetZ(prm->field_10 * (0.2f + lpCamera->field_68));
    lPack.SetA(prm->field_C);
    q[16] = lPack.mData;
    lPack.SetX(128.0f * prm->field_14[0]);
    lPack.SetY(128.0f * prm->field_14[1]);
    lPack.SetZ(128.0f * prm->field_14[2]);
    lPack.SetA(128.0f * prm->field_14[3]);
    q[17] = lPack.mData;
    lPack.SetX(128.0f * prm->field_24[0]);
    lPack.SetY(128.0f * prm->field_24[1]);
    lPack.SetZ(128.0f * prm->field_24[2]);
    lPack.SetA(128.0f * prm->field_24[3]);
    q[18] = lPack.mData;
    lPack.SetX(prm->field_34[0]);
    lPack.SetY(prm->field_34[1]);
    lPack.SetZ(prm->field_34[2]);
    lPack.SetA(prm->field_34[3]);
    q[19] = lPack.mData;
    q[20] = lPack.mData;                    // [C] the same row twice
    q[21] = func_00365920_q(0x402B400000000000UL, 0x4124);
    lPack.SetX(0.0f);
    lPack.SetY(0.0f);
    lPack.SetZ(1.0f);
    lPack.SetA(1.0f);
    q[22] = lPack.mData;
    lPack.SetY(0.0f);
    lPack.SetZ(lrTimestep);
    q[23] = lPack.mData;
    q[24] = func_00365920_q((unsigned long)field_20 << 32 | 0x50000000, 0x020000B403000000UL);
    q[25] = func_00365920_q(0x10000004, 0x5000000410000000UL);
    q[26] = func_00365920_q(0x1000000000008003UL, 0xE);      // GIFtag A+D, 3 regs, EOP
    q[27] = func_00365920_q(skyTest_1, 0x47);
    q[28] = func_00365920_q(skyAlpha_1, 0x42);
    q[29] = func_00365920_q(skyClamp_1, 8);
    farFogPlane.field_0 = q + 30;
}
