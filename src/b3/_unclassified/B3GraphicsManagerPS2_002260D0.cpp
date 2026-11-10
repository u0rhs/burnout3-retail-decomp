// CB3GraphicsManager::CopyTextureAs32Bit(CGtTexture*,unsigned int,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManagerPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gif7: N218 packet (q0 local before the pointer load), TEX0 return quad lo written raster-mask | (p1 | w<<14) inline (a tex0 local flips the or), u_long128 return via paddub).

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
    u_long128 CopyTextureAs32Bit(CGtTexture * p0, unsigned int p1, unsigned int p2);

    unsigned char pad_0[0x3B0];
    void * field_3B0;
};

extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" void AccessTexture__15CGtTextureCacheFP10CGtTexturef29EGtTextureCachePS2_FilterModebb(void *, CGtTexture *, float, int, bool, bool);
extern "C" void RemoveRasterFromCache__15CGtTextureCacheFP8RwRaster(void *, void *);
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x002260D0
u_long128 CB3GraphicsManager::CopyTextureAs32Bit(CGtTexture * p0, unsigned int p1, unsigned int p2)
{
    unsigned long w;
    if (p2 == 0) {
        w = (p0->field_C + 63) / 64;
    } else {
        w = p2;
    }
    bool open = field_3B0 == 0;
    if (open) {
        OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(this, 0);
    }
    AccessTexture__15CGtTextureCacheFP10CGtTexturef29EGtTextureCachePS2_FilterModebb(&gTextureCache, p0, 0.0f, 0, true, false);
    unsigned int x = ((p1 & 1) << 7) + ((p1 & 4) << 6) + ((p1 & 0x10) << 5);
    unsigned int y = ((p1 & 2) << 6) + ((p1 & 8) << 5);
    _rwDMAOpenVIFPkt(0x80000000, 0xD);
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x11AB40000000800CUL), "r"(0xE));
    u_long128 * p = farFogPlane.field_0;
    *p++ = q0;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(p1 >> 5) | (w << 16)), "r"(0x4D));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0), "r"(0x19));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)(y >> 4) << 32) | ((unsigned long)(x >> 4) | ((unsigned long)((x >> 4) + p0->field_C - 1) << 16)) | ((unsigned long)((y >> 4) + p0->field_10 - 1) << 48)), "r"(0x41));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x31001), "r"(0x48));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(1), "r"(0x15));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(5), "r"(9));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x2A), "r"(0x43));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x3F80000080808080UL), "r"(1));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(0x80008), "r"(3));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)x | ((unsigned long)y << 16)), "r"(5));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((long)(p0->field_C * 16 + 8) | ((long)(p0->field_10 * 16 + 8) << 16)), "r"(3));
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)(x + p0->field_C * 16) | ((unsigned long)(y + p0->field_10 * 16) << 16)), "r"(5));
    farFogPlane.field_0 = p;
    u_long128 q;
    asm("pcpyld %0, %2, %1" : "=r"(q) : "r"((((p0->field_3C | ((unsigned long)p0->field_40 << 32))) & 0x1FFC000000UL) | ((unsigned long)p1 | (w << 14))), "r"(6));
    RemoveRasterFromCache__15CGtTextureCacheFP8RwRaster(&gTextureCache, p0);
    if (open) {
        CloseViewport__22CB3GraphicsManagerBaseFv(this);
    }
    return q;
}
