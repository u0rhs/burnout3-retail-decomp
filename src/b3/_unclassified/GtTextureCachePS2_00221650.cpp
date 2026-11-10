// CGtTextureCache::AddRasterToCache(RwRaster*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a251: hand-written (lifter refused); int return, reversed-sense compares, separate loop vars i/j/k declared k,j,i).

class RwRaster;
struct UnkStruct_arc_buf {
    int field_0;
    int field_4;
    int field_8[30];
};
struct UnkStruct_arc_ext {
    unsigned char pad_0[0x30];
    unsigned int field_30;
};
struct UnkStruct_rwDMAPktPtr { int field_0; };
extern int skyRasterExt;
extern int _rwDMAPktPtr;
class CGtTextureCache {
public:
    int AddRasterToCache(RwRaster*, int);
    void RemoveRasterFromCache(RwRaster*);
    void AddRasterToCurrentDoubleBuffer(RwRaster*);
    unsigned char pad_0[0xC0];
    UnkStruct_arc_buf field_C0[2];
    int field_1C0;
    unsigned char field_1C4;
    unsigned char field_1C5;
    unsigned char pad_1C6[2];
    int field_1C8;
    int field_1CC;
    unsigned char pad_1D0[8];
    unsigned int field_1D8;
    unsigned char pad_1DC[8];
    int field_1E4;
    unsigned char pad_1E8[12];
    int field_1F4;
};
// 0x00221650
int CGtTextureCache::AddRasterToCache(RwRaster *p0, int)
{
    int k, j, i;
    unsigned int sz = ((UnkStruct_arc_ext *)((char *)p0 + skyRasterExt))->field_30;
    unsigned int cap = field_1D8;
    if (field_C0[field_1C0].field_4 + sz <= cap && field_C0[field_1C0].field_0 < field_1E4) {
        AddRasterToCurrentDoubleBuffer(p0);
        field_1C5 = 1;
    } else if (sz <= cap) {
        for (i = 0; i < field_C0[field_1C0].field_0; i++) {
            RemoveRasterFromCache((RwRaster *)field_C0[field_1C0].field_8[i]);
            field_C0[field_1C0].field_8[i] = 0;
        }
        field_C0[field_1C0].field_0 = 0;
        field_C0[field_1C0].field_4 = 0;
        field_1C0 = 1 - field_1C0;
        field_1C8 = 0;
        AddRasterToCurrentDoubleBuffer(p0);
        field_1C5 = 1;
    } else if (sz <= cap * 2) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < field_C0[field_1C0].field_0; k++) {
                RemoveRasterFromCache((RwRaster *)field_C0[field_1C0].field_8[k]);
                field_C0[field_1C0].field_8[k] = 0;
            }
            field_C0[field_1C0].field_0 = 0;
            field_C0[field_1C0].field_4 = 0;
        }
        field_1C0 = 0;
        field_1C8 = 0;
        field_1C5 = 0;
        AddRasterToCurrentDoubleBuffer(p0);
        _rwDMAPktPtr = 0;
    } else {
        return 0;
    }
    field_1C4 = 0;
    field_1F4++;
    field_1CC = (int)p0;
    return 1;
}
