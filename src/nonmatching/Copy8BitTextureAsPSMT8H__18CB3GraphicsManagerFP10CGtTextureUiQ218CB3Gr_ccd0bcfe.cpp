// NONMATCHING: Copy8BitTextureAsPSMT8H__18CB3GraphicsManagerFP10CGtTextureUiQ218CB3GraphicsManager7EClutIDUi -- retail 392 / ours 393 instructions, 259 in changed runs
// draftAB: CopyTextureAs32Bit shape + Revenge locals; 7+256+21-quad packet decoded (CLUT upload loop, FRAME/SCISSOR/TEX0 quads), lu64ClutTex0_bits37_63 local, ST words from float locals read back as u32 (retail lwu), CLUT CBP from lu64RasterTex0>>37, signed XY in the CLUT loop; left: 1 extra nop and the scheduling/spill order of the prologue offsets (luTexOffsetX/Y spill slots)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every packet quadword, the CLUT loop and the returned TEX0 accounted for

// CB3GraphicsManager::Copy8BitTextureAsPSMT8H(CGtTexture*, unsigned int, EClutID, unsigned int) -- hand-written (draftAB).
// Shape of CopyTextureAs32Bit (B3GraphicsManagerPS2_002260D0.cpp, matched); [L] local names from Revenge STABS
// (CB4GraphicsManager::Copy8BitTextureAsPSMT8H, B4GraphicsManagerPS2.cpp). Layout [G].
#include "b3/GtMathPs2.h"

class CGtTexture {
public:
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[0x28];
    unsigned int field_3C;
    unsigned int field_40;
};
struct UnkStruct_gTextureCache { unsigned char pad_0[0x10]; };
struct UnkStruct_farFogPlane { u_long128 * field_0; };
extern UnkStruct_gTextureCache gTextureCache;
extern UnkStruct_farFogPlane farFogPlane;

class CB3GraphicsManager {
public:
    enum EClutID {};
    u_long128 Copy8BitTextureAsPSMT8H(CGtTexture * lpTexture, unsigned int luDestinationAddress, EClutID leClutBufferID, unsigned int luStride);

    unsigned char pad_0[0x3B0];
    void * field_3B0;
    unsigned char pad_3B4[0x5C];
    unsigned int field_410;
};

extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void AccessTexture__15CGtTextureCacheFP10CGtTexturef29EGtTextureCachePS2_FilterModebb(void *, CGtTexture *, float, int, bool, bool);
extern "C" void RemoveRasterFromCache__15CGtTextureCacheFP8RwRaster(void *, void *);
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x00226A90
u_long128 CB3GraphicsManager::Copy8BitTextureAsPSMT8H(CGtTexture * lpTexture, unsigned int luDestinationAddress, EClutID leClutBufferID, unsigned int luStride)
{
    float lrS;
    float lrT;
    u_long128 lu128ClutFrame_2;
    u_long128 lu128ClutScissor_2;
    u_long128 lu128Tex0_1;
    unsigned long lu64RasterTex0;
    unsigned long lu64ClutTex0_bits37_63;
    unsigned long lu64TBW;
    unsigned int luClutOffsetX;
    unsigned int luClutOffsetY;
    unsigned int luTexOffsetX;
    unsigned int luTexOffsetY;
    unsigned int luIndex;
    bool lbOpenViewport;

    if (luStride == 0) {
        lu64TBW = (lpTexture->field_C + 63) / 64;
    } else {
        lu64TBW = luStride;
    }
    unsigned int luBlockAddress = field_410 + 0x110 + (leClutBufferID & 4) * 24 + (leClutBufferID & 3) * 4;
    luTexOffsetX = ((luDestinationAddress & 1) << 7) + ((luDestinationAddress & 4) << 6) + ((luDestinationAddress & 0x10) << 5);
    luTexOffsetY = ((luDestinationAddress & 2) << 6) + ((luDestinationAddress & 8) << 5);
    luClutOffsetX = ((luBlockAddress & 1) << 7) + ((luBlockAddress & 4) << 6) + ((luBlockAddress & 0x10) << 5);
    luClutOffsetY = ((luBlockAddress & 2) << 6) + ((luBlockAddress & 8) << 5);
    lu64ClutTex0_bits37_63 = ((unsigned long)luBlockAddress << 37) | 0x2000000000000000UL;
    asm("pcpyld %0, %2, %1" : "=r"(lu128ClutFrame_2) : "r"((unsigned long)(luBlockAddress >> 5) | 0x10000), "r"(0x4D));
    asm("pcpyld %0, %2, %1" : "=r"(lu128ClutScissor_2) : "r"((unsigned long)(luClutOffsetX >> 4) | ((unsigned long)((luClutOffsetX >> 4) + 15) << 16) | ((unsigned long)(luClutOffsetY >> 4) << 32) | ((unsigned long)((luClutOffsetY >> 4) + 15) << 48)), "r"(0x41));
    lbOpenViewport = field_3B0 == 0;
    if (lbOpenViewport) {
        OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(this, 0);
    }
    AccessTexture__15CGtTextureCacheFP10CGtTexturef29EGtTextureCachePS2_FilterModebb(&gTextureCache, lpTexture, 0.0f, 0, true, false);
    lu64RasterTex0 = (unsigned long)lpTexture->field_3C | ((unsigned long)lpTexture->field_40 << 32);
    _rwDMAOpenVIFPkt(0x80000000, 0x11C);
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1120400000000005UL), "r"(0xE));
    *p++ = lu128ClutFrame_2;
    *p++ = lu128ClutScissor_2;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x19));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2A), "r"(0x43));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(0x48));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2400000000000100UL), "r"(0x51));
    for (luIndex = 0; luIndex < 0x100; luIndex++) {
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)luIndex << 24) | 0x3F80000000000000UL),
            "r"((long)(int)(luClutOffsetX + (luIndex & 7) * 16 + (luIndex & 0x10) * 8) | ((long)(int)((luIndex & 0xE0) + luClutOffsetY + (luIndex & 8) * 2) << 16)));
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x112B40000000000BUL), "r"(0xE));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x3F));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(luDestinationAddress >> 5) | (lu64TBW << 16) | 0xFFFFFF00000000UL), "r"(0x4D));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((long)(lpTexture->field_C - 1) << 16) | ((long)(lpTexture->field_10 - 1) << 48)), "r"(0x41));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((lu64RasterTex0 & 0x1FFFFFFFFFUL) | lu64ClutTex0_bits37_63), "r"(7));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(1), "r"(0x15));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(5), "r"(9));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x3F80000080808080UL), "r"(1));
    lrS = 0.5f / (float)lpTexture->field_C;
    lrT = 0.5f / (float)lpTexture->field_10;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)*(unsigned int *)&lrS | ((unsigned long)*(unsigned int *)&lrT << 32)), "r"(2));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)luTexOffsetX | ((unsigned long)luTexOffsetY << 16)), "r"(5));
    lrS += 1.0f;
    lrT += 1.0f;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)*(unsigned int *)&lrS | ((unsigned long)*(unsigned int *)&lrT << 32)), "r"(2));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(luTexOffsetX + lpTexture->field_C * 16) | ((unsigned long)(luTexOffsetY + lpTexture->field_10 * 16) << 16)), "r"(5));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x11AB400000000008UL), "r"(0xE));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x3F));
    *p++ = lu128ClutFrame_2;
    *p++ = lu128ClutScissor_2;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((lu64RasterTex0 >> 37) & 0x3FFF) | 0x510004000UL), "r"(7));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x80008), "r"(3));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)luClutOffsetX | ((unsigned long)luClutOffsetY << 16)), "r"(5));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1080108), "r"(3));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(luClutOffsetX + 0x100) | ((unsigned long)(luClutOffsetY + 0x100) << 16)), "r"(5));
    asm("pcpyld %0, %2, %1" : "=r"(lu128Tex0_1) : "r"((lu64RasterTex0 & 0x1FFC000000UL) | (unsigned long)luDestinationAddress | (lu64TBW << 14) | 0x1B00000 | lu64ClutTex0_bits37_63), "r"(6));
    farFogPlane.field_0 = p;
    RemoveRasterFromCache__15CGtTextureCacheFP8RwRaster(&gTextureCache, lpTexture);
    if (lbOpenViewport) {
        CloseViewport__22CB3GraphicsManagerBaseFv(this);
    }
    return lu128Tex0_1;
}



