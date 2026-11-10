// CGtTextureCache::ForceBufferSwap() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a72: two 0x80-stride buffers {count, field_4, raster[30]} indexed by field_1C0; declaration fix).

class RwRaster;
struct UnkStruct_skyTextureRaster { RwRaster * field_0; };
struct UnkStruct_002215_buf {
    int field_0;
    int field_4;
    int field_8[30];
};

class CGtTextureCache {
public:
    void RemoveRasterFromCache(RwRaster*);
    void ForceBufferSwap();

    unsigned char pad_0[0xC0];
    UnkStruct_002215_buf field_C0[2];
    int field_1C0;
    unsigned char field_1C4;
    unsigned char pad_1C5[0x3];
    int field_1C8;
    int field_1CC;
};

extern UnkStruct_skyTextureRaster skyTextureRaster;

// 0x00221580
void CGtTextureCache::ForceBufferSwap()
{
    if (field_C0[field_1C0].field_0 != 0) {
        for (int i = 0; i < field_C0[field_1C0].field_0; i++) {
            RemoveRasterFromCache((RwRaster*)field_C0[field_1C0].field_8[i]);
            field_C0[field_1C0].field_8[i] = 0;
        }
        field_C0[field_1C0].field_0 = 0;
        field_C0[field_1C0].field_4 = 0;
        field_1C0 = 1 - field_1C0;
        field_1C8 = 0;
    }
    skyTextureRaster.field_0 = 0;
    field_1CC = 0;
}
