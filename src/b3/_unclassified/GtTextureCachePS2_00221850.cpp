// CGtTextureCache::AddRasterToCurrentDoubleBuffer(RwRaster*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near24: sibling RemoveRasterFromCache 64-bit idiom + unsigned field_30/field_1DC).

struct UnkStruct_ARCDB_buf {
    int field_0;      // 0xC0 count
    int field_4;      // 0xC4
    UnkStruct_ARCDB_buf *field_8[1];
    unsigned char pad_C[0x74];
};
struct UnkStruct_ARCDB_lh { unsigned int lo; unsigned int hi; };
struct UnkStruct_ARCDB_ext {
    unsigned char pad_0[8];
    unsigned int field_8;
    unsigned int field_C;
    int field_10;
    unsigned char pad_14[4];
    UnkStruct_ARCDB_lh field_18;
    UnkStruct_ARCDB_lh field_20;
    unsigned char pad_28[8];
    unsigned int field_30;
    unsigned char pad_34[0x24];
    void *field_58;
};
struct RwRaster;
struct UnkStruct_ARCDB_cache {
    unsigned char pad_0[0xC0];
    UnkStruct_ARCDB_buf field_C0[2];
    unsigned char pad_1C0_[0];
};
class CGtTextureCache {
public:
    void AddRasterToCurrentDoubleBuffer(RwRaster *);
    void BuildPacketToSendRasterToGS(RwRaster *, unsigned int);
};
struct UnkStruct_ARCDB_full {
    unsigned char pad_0[0xC0];
    UnkStruct_ARCDB_buf field_C0[2];
    int field_1C0;
    unsigned char field_1C4[1];
    unsigned char field_1C5;
    unsigned char pad_1C6[2];
    int field_1C8;
    unsigned char pad_1CC[4];
    int field_1D0;
    unsigned char pad_1D4[8];
    unsigned int field_1DC[2];
    int field_1E4;
    unsigned char pad_1E8[8];
    int field_1F0;
    int field_1F4;
};
struct UnkStruct_ARCDB_gp { int field_0; };
extern int skyRasterExt;
extern void *_gOldRasterShowRasterFunc;
extern "C" void _rwDMAAddImageUpload(unsigned int, unsigned int);

// 0x00221850
void CGtTextureCache::AddRasterToCurrentDoubleBuffer(RwRaster *raster)
{
    UnkStruct_ARCDB_full *self = (UnkStruct_ARCDB_full *)this;
    UnkStruct_ARCDB_ext *ext = (UnkStruct_ARCDB_ext *)((int)raster + skyRasterExt);
    int n = self->field_C0[self->field_1C0].field_0;
    if (n == 0 || _gOldRasterShowRasterFunc == 0) {
        if (_gOldRasterShowRasterFunc == 0) {
            self->field_1C8 = 0;
        }
        unsigned int a = self->field_1E4 * 24;
        self->field_1D0 = 0;
        if (self->field_1F4 == 0) {
            a += self->field_1F0 * 24;
        }
        _rwDMAAddImageUpload(self->field_1C5, a);
    }
    self->field_C0[self->field_1C0].field_8[n] = (UnkStruct_ARCDB_buf *)raster;
    ext->field_58 = &self->field_C0[self->field_1C0].field_8[n];
    unsigned int off = self->field_1DC[self->field_1C0] + self->field_C0[self->field_1C0].field_4;
    BuildPacketToSendRasterToGS(raster, off);
    unsigned int pg = off >> 6;
    ext->field_8 = ext->field_8 & 0xFFFFC000;
    ext->field_8 = ext->field_8 | (pg & 0x3FFF);
    unsigned int s = pg + ext->field_10;
    ext->field_C = ext->field_C & 0xFFF8001F;
    unsigned long t = s & 0x3FFF;
    t = t & 0x3FFF;
    ext->field_C = ext->field_C | (int)(t << 5);
    unsigned long m = ext->field_8 & 0x3FFF;
    unsigned long add = m | (m << 20) | (m << 40);
    unsigned long v = (unsigned long)ext->field_18.lo | ((unsigned long)ext->field_18.hi << 32);
    v += add;
    ext->field_18.lo = (unsigned int)v;
    ext->field_18.hi = (unsigned int)(v >> 32);
    v = (unsigned long)ext->field_20.lo | ((unsigned long)ext->field_20.hi << 32);
    v += add;
    ext->field_20.lo = (unsigned int)v;
    ext->field_20.hi = (unsigned int)(v >> 32);
    self->field_C0[self->field_1C0].field_4 += ext->field_30;
    self->field_C0[self->field_1C0].field_0 += 1;
}
