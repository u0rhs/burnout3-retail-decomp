// CB3SparkRenderer::EndRender() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C mangled def; farFogPlane field u_long128* (stride 0x10, reload); early return).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_00263350_1 { u_long128 field_0; u_long128 field_10; u_long128 field_20; u_long128 field_30; u_long128 field_40; };
struct UnkStruct_farFogPlane { u_long128 *field_0; };
struct UnkStruct_skyUserSwitch1 { unsigned int field_0; };
struct UnkStruct_skyTextureRaster { void *field_0; };
struct UnkStruct_00263420_arr { unsigned char pad_0[0x9C]; void *field_9C; unsigned char pad_A0[4]; unsigned char field_A4; };
extern UnkStruct_farFogPlane farFogPlane;
extern UnkStruct_skyUserSwitch1 skyUserSwitch1;
extern UnkStruct_skyTextureRaster skyTextureRaster;
extern char vu_game_0046D090[];
extern UnkStruct_00263420_arr *D_01E327B0[];
extern int mnNumRenderableArrays__16CB3SparkRenderer;
extern "C" void _rwDMAOpenVIFPkt(int, int);
extern "C" void RpSkyTexCacheAccessSpeculate(void *);
extern "C" void *RpSkyTexCacheAccessRaster(void *, int);
extern "C" void SetRenderstates__16CB3SparkRendererFv();
extern "C" void RestoreRenderstates__16CB3SparkRendererFv();
extern "C" void UploadStaticDataAndCallCode__16CB3SparkRendererFPC13CB3SparkArrayb(const void *, bool);
extern "C" void EndRender__16CB3SparkRendererFv()
{
    if (mnNumRenderableArrays__16CB3SparkRenderer == 0) return;
    {
        _rwDMAOpenVIFPkt(0, 6);
        u_long128 q0;
        unsigned long lo = ((unsigned long)(unsigned int)vu_game_0046D090 << 32) | 0x50000000UL;
        asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(lo), "r"(0x0200006303000000UL));
        *farFogPlane.field_0 = q0;
        skyUserSwitch1.field_0 = (unsigned int)vu_game_0046D090;
        farFogPlane.field_0 = farFogPlane.field_0 + 1;
        SetRenderstates__16CB3SparkRendererFv();
        for (int i = 0; i < mnNumRenderableArrays__16CB3SparkRenderer; i++) {
            UnkStruct_00263420_arr *a = D_01E327B0[i];
            void *r = D_01E327B0[0]->field_9C;
            if (skyTextureRaster.field_0 != r) {
                RpSkyTexCacheAccessSpeculate(r);
                if (RpSkyTexCacheAccessRaster(r, 0) != 0) skyTextureRaster.field_0 = r;
            }
            _rwDMAOpenVIFPkt(0, (a->field_A4 ? 2 : 1) + 0x72);
            UploadStaticDataAndCallCode__16CB3SparkRendererFPC13CB3SparkArrayb(a, true);
        }
        _rwDMAOpenVIFPkt(0, 2);
        RestoreRenderstates__16CB3SparkRendererFv();
    }
}
