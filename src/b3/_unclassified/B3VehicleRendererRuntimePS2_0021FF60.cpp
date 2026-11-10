// CB3VehicleRenderer::SetTexture(CGtTexture*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehicleRendererRuntimePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it ('ret: return;' label after the tail, early-exit arm ends 'goto ret;': the shared return block is 'b epi; ld ra' and the else branches to it unthreaded (sdra rule 2)).

typedef unsigned int u_long128 __attribute__((mode(TI)));

enum EGtTextureCachePS2_FilterMode {};
class CGtTexture;
class CGtTextureCache;
class CB3VehicleRenderer;

class CGtTexture {
public:
    unsigned char pad_0[0x3C];
    unsigned int field_3C;
    unsigned int field_40;
    unsigned char pad_44[0x4C];
    unsigned short field_90[8];  // [G] element count
    unsigned char field_A0;
};

class CGtTextureCache {
public:
    void AccessTexture(CGtTexture*, float, EGtTextureCachePS2_FilterMode, bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_skyTextureRaster {
    void * field_0;
};

class CB3VehicleRenderer {
public:
    void SetTexture(CGtTexture * p0, int p1);

    unsigned char pad_0[0x20];
    u_long128 field_20;
};

extern CGtTextureCache gTextureCache;
extern UnkStruct_skyTextureRaster skyTextureRaster;

// 0x0021FF60
void CB3VehicleRenderer::SetTexture(CGtTexture * p0, int p1)
{
    if (p0 != 0 && skyTextureRaster.field_0 != p0) {
        gTextureCache.AccessTexture(p0, 90.0f, (EGtTextureCachePS2_FilterMode)1, 0, 0);
        skyTextureRaster.field_0 = this;
        unsigned short * arr = p0->field_90;
        unsigned long lo;
        u_long128 q;
        if (p1 >= p0->field_A0) {
            goto small;  // [G] goto: retail lays the small arm out of line after the shared tail
        }
        {
            unsigned int a = p0->field_40 + (arr[p1] << 5);
            lo = p0->field_3C | ((unsigned long)a << 32);
        }
    tail:
        asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(6), "r"(lo));
        field_20 = q;
    ret:
        return;
    small:
        lo = p0->field_3C | ((unsigned long)p0->field_40 << 32);
        goto tail;
    }
    skyTextureRaster.field_0 = 0;
    goto ret;
}
