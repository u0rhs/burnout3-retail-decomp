// NONMATCHING: Copy4BitTextureAsPSMT4H__18CB3GraphicsManagerFP10CGtTextureUiQ218CB3GraphicsManager7EClutIDbUi -- retail 411 / ours 411 instructions, 272 in changed runs
// draftAC c6c: 411/411, 272 changed. Twin (Copy8Bit archive) adapted; head block now exact except the CLUT loop's Y term order (lnX local from STABS helped 1), s7/fp fixed by declaring lu64DestFormat before luFBMask, lu64ClutTex0_bits37_63 after the scissor quad (341 -> 278). Left: the post-loop block schedule/colouring (TEX0/FRAME/ST pieces, the shared 0x1F<<32 mask term), same wall as the twin.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every packet quadword, the 16-entry CLUT loop, the lbHigh selections and the returned TEX0 accounted for (draftAC)

// CB3GraphicsManager::Copy4BitTextureAsPSMT4H(CGtTexture*, unsigned int, EClutID, bool, unsigned int) -- hand-written
// (draftAC) from the Copy8BitTextureAsPSMT8H twin archive (draftAB). [L] local names from Revenge STABS
// (CB4GraphicsManager::Copy4BitTextureAsPSMT4H, B4GraphicsManagerPS2.cpp: lu64DestFormat, luFBMask, lnX). Layout [G].
// Differences from the twin, all read from the retail asm: lbHigh adds 2 to the CLUT block and picks PSM 0x2C/0x24
// and FBMSK 0x0FFFFFFF/0xF0FFFFFF; 16-entry CLUT loop (index | index << 4 in the RGBA word); scissor Y + 1; 44 quads.
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
    u_long128 Copy4BitTextureAsPSMT4H(CGtTexture * lpTexture, unsigned int luDestinationAddress, EClutID leClutBufferID, bool lbHigh, unsigned int luStride);

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

// 0x00226420
u_long128 CB3GraphicsManager::Copy4BitTextureAsPSMT4H(CGtTexture * lpTexture, unsigned int luDestinationAddress, EClutID leClutBufferID, bool lbHigh, unsigned int luStride)
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
    unsigned long lu64DestFormat;
    unsigned int luFBMask;
    bool lbOpenViewport;

    if (luStride == 0) {
        lu64TBW = (lpTexture->field_C + 63) / 64;
    } else {
        lu64TBW = luStride;
    }
    unsigned int luBlockAddress = field_410 + 0x110 + (leClutBufferID & 4) * 24 + (leClutBufferID & 3) * 4;
    if (lbHigh) {
        luBlockAddress += 2;
        lu64DestFormat = 0x2C;
        luFBMask = 0x0FFFFFFF;
    } else {
        lu64DestFormat = 0x24;
        luFBMask = 0xF0FFFFFF;
    }
    luTexOffsetX = ((luDestinationAddress & 1) << 7) + ((luDestinationAddress & 4) << 6) + ((luDestinationAddress & 0x10) << 5);
    luTexOffsetY = ((luDestinationAddress & 2) << 6) + ((luDestinationAddress & 8) << 5);
    luClutOffsetX = ((luBlockAddress & 1) << 7) + ((luBlockAddress & 4) << 6) + ((luBlockAddress & 0x10) << 5);
    luClutOffsetY = ((luBlockAddress & 2) << 6) + ((luBlockAddress & 8) << 5);
    asm("pcpyld %0, %2, %1" : "=r"(lu128ClutFrame_2) : "r"((unsigned long)(luBlockAddress >> 5) | 0x10000), "r"(0x4D));
    asm("pcpyld %0, %2, %1" : "=r"(lu128ClutScissor_2) : "r"((unsigned long)(luClutOffsetX >> 4) | ((unsigned long)((luClutOffsetX >> 4) + 15) << 16) | ((unsigned long)(luClutOffsetY >> 4) << 32) | ((unsigned long)((luClutOffsetY >> 4) + 1) << 48)), "r"(0x41));
    lu64ClutTex0_bits37_63 = ((unsigned long)luBlockAddress << 37) | 0x2000000000000000UL;
    lbOpenViewport = field_3B0 == 0;
    if (lbOpenViewport) {
        OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(this, 0);
    }
    AccessTexture__15CGtTextureCacheFP10CGtTexturef29EGtTextureCachePS2_FilterModebb(&gTextureCache, lpTexture, 0.0f, 0, true, false);
    lu64RasterTex0 = (unsigned long)lpTexture->field_3C | ((unsigned long)lpTexture->field_40 << 32);
    _rwDMAOpenVIFPkt(0x80000000, 0x2C);
    u_long128 * p = farFogPlane.field_0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x1120400000000005UL), "r"(0xE));
    *p++ = lu128ClutFrame_2;
    *p++ = lu128ClutScissor_2;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x19));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2A), "r"(0x43));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(0x48));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2400000000000010UL), "r"(0x51));
    for (luIndex = 0; luIndex < 0x10; luIndex++) {
        int lnX = luClutOffsetX + (luIndex & 7) * 16 + (luIndex & 0x10) * 8;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(luIndex | (luIndex << 4)) << 24) | 0x3F80000000000000UL),
            "r"((long)lnX | ((long)(int)((luIndex & 0xE0) + (luClutOffsetY + (luIndex & 8) * 2)) << 16)));
    }
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x112B40000000000BUL), "r"(0xE));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x3F));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(luDestinationAddress >> 5) | (lu64TBW << 16) | ((unsigned long)luFBMask << 32)), "r"(0x4D));
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
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((lu64RasterTex0 >> 37) & 0x3FFF) | 0x450004000UL), "r"(7));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x80008), "r"(3));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)luClutOffsetX | ((unsigned long)luClutOffsetY << 16)), "r"(5));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x280108), "r"(3));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(luClutOffsetX + 0x100) | ((unsigned long)(luClutOffsetY + 0x20) << 16)), "r"(5));
    asm("pcpyld %0, %2, %1" : "=r"(lu128Tex0_1) : "r"((lu64RasterTex0 & 0x1FFC000000UL) | (unsigned long)luDestinationAddress | (lu64TBW << 14) | (lu64DestFormat << 20) | lu64ClutTex0_bits37_63), "r"(6));
    farFogPlane.field_0 = p;
    RemoveRasterFromCache__15CGtTextureCacheFP8RwRaster(&gTextureCache, lpTexture);
    if (lbOpenViewport) {
        CloseViewport__22CB3GraphicsManagerBaseFv(this);
    }
    return lu128Tex0_1;
}



