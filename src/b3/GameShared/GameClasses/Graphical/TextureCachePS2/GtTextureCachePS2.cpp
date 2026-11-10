// GtTextureCachePS2.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtTextureCachePS2.cpp.
// Area: src/b3/GameShared/GameClasses/Graphical/TextureCachePS2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Graphical/TextureCachePS2/GtTextureCachePS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtTextureCache.h"
#include "b3/classes/RwRaster.h"
#include "b3/classes/UnkStruct_skyTextureRaster.h"

struct UnkStruct_00222030_ent {
    int field_0;
};

struct UnkStruct_00222030_ext {
    unsigned char pad_0[0x8];
    unsigned int field_8;
    unsigned char pad_C[0xC];
    unsigned int field_18;
    unsigned int field_1C;
    unsigned int field_20;
    unsigned int field_24;
    unsigned char pad_28[0x30];
    UnkStruct_00222030_ent * field_58;
};

extern UnkStruct_skyTextureRaster skyTextureRaster;
extern int skyRasterExt;

// CGtTextureCache::FlushCache() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// 0x00221490
void CGtTextureCache::FlushCache()
{
    if (field_1C4 == 0) {
        for (int i = 0; (i < field_C0); i++) {
            RemoveRasterFromCache((RwRaster*)field_C8[i]);
            field_C8[i] = 0;
        }
        for (int i1 = 0; (i1 < field_140); i1++) {
            RemoveRasterFromCache((RwRaster*)field_148[i1]);
            field_148[i1] = 0;
        }
        field_C0 = 0;
        field_140 = 0;
        field_C4 = 0;
        field_144 = 0;
        field_1C0 = (1 - field_1C0);
        field_1C8 = 0;
        field_1C4 = 1;
        field_1CC = 0;
    }
    skyTextureRaster.field_0 = 0;
}

// CGtTextureCache::InvalidateCurrentTexture() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// 0x00221570
void CGtTextureCache::InvalidateCurrentTexture()
{
    field_1CC = 0;
}

// CGtTextureCache::RemoveRasterFromCache(RwRaster*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// 0x00222030
void CGtTextureCache::RemoveRasterFromCache(RwRaster * p0)
{
    if (p0 != 0) {
        UnkStruct_00222030_ext * ext = (UnkStruct_00222030_ext *)((char *)p0 + skyRasterExt);
        if (ext->field_58 != 0) {
            ext->field_58->field_0 = 0;
            ext->field_58 = 0;
            unsigned long m = ext->field_8 & 0x3FFF;
            unsigned long sub = m | (m << 20) | (m << 40);
            unsigned long v = (unsigned long)ext->field_18 | ((unsigned long)ext->field_1C << 32);
            v -= sub;
            ext->field_18 = (unsigned int)v;
            ext->field_1C = (unsigned int)(v >> 32);
            v = (unsigned long)ext->field_20 | ((unsigned long)ext->field_24 << 32);
            v -= sub;
            ext->field_20 = (unsigned int)v;
            ext->field_24 = (unsigned int)(v >> 32);
        }
    }
}
