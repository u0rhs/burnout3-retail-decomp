// B3Im3d::SetTexture(CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Im3DPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtTexture;
enum EGtTextureCachePS2_FilterMode {};

class B3Im3d;
class CGtTextureCache;
struct UnkStruct_00365510_2;
struct UnkStruct_farFogPlane;

class CGtTextureCache {
public:
    void AccessTexture(CGtTexture*, float, EGtTextureCachePS2_FilterMode, bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_farFogPlane {
    UnkStruct_00365510_2 * field_0;
};

struct UnkStruct_00365510_2 {
    u_long128 field_0;
};

class B3Im3d {
public:
    static void SetTexture(CGtTexture* p0);
    static unsigned char _gbTextured;
};

extern UnkStruct_farFogPlane farFogPlane;
extern CGtTextureCache gTextureCache;

extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x00365510
void B3Im3d::SetTexture(CGtTexture* p0)
{
    if (p0 == 0) {
        B3Im3d::_gbTextured = 0;
    } else {
        _rwDMAOpenVIFPkt(0, 1);
        u_long128 q0;
        asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(0x10000000), "r"(0x1100000011000000));
        farFogPlane.field_0->field_0 = q0;
        farFogPlane.field_0++;
        gTextureCache.AccessTexture(p0, 0.0f, (EGtTextureCachePS2_FilterMode)1, 0, 0);
        B3Im3d::_gbTextured = 1;
    }
}
