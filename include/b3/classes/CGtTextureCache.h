// CGtTextureCache -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTTEXTURECACHE_H
#define B3_CLASSES_CGTTEXTURECACHE_H

#include "b3/GtMath.h"

class CGtTextureCache;
class RwRaster;

class CGtTextureCache {
public:
    void AddRasterToCache(RwRaster*, int);
    void Construct(unsigned int, int, int);
    void FlushCache();
    void InvalidateCurrentTexture();
    void RemoveRasterFromCache(RwRaster*);

    unsigned char pad_0[0xC0];
    int field_C0;
    int field_C4;
    int field_C8[1];  // [G] element count unknown
    unsigned char pad_CC[0x74];
    int field_140;
    int field_144;
    int field_148[1];  // [G] element count unknown
    unsigned char pad_14C[0x74];
    int field_1C0;
    unsigned char field_1C4;
    unsigned char pad_1C5[0x3];
    int field_1C8;
    int field_1CC;
};

#endif
