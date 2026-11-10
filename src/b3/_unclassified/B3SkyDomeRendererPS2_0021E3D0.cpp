// CB3SkyDomeRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a73: pcpyld asm with 64-bit operands; unrolled hemisphere Construct calls).

// [G] the two 128-bit mCameraParams[7]/[8] values are built with an explicit pcpyld (hi:lo from two 64-bit constants); MWCC has no
// 128-bit constant builder, same idiom as B3SparkRendererPS2.cpp. No DNAT row. maParams/mCameraParams are class statics (extents [G]).
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern "C" void Construct__Q218CB3SkyDomeRenderer26CB3SkyDomeHemisphereParamsFQ222CB3SkyDomeRendererBase13ESkyComponent(void *, int);

struct UnkStruct_0021E3D0_hp {
    unsigned char pad_0[0x90];
};

union UnkUnion_0021E3D0_q {
    u_long128 q;
    struct { unsigned long lo; unsigned long hi; } s;
};

class CB3SkyDomeRenderer {
public:
    static void Construct();
    static u_long128 mCameraParams[10];
    static UnkStruct_0021E3D0_hp maParams[6];
    static int mePrepareState;
    static unsigned char mbTexturesUploaded;
};

// 0x0021E3D0
void CB3SkyDomeRenderer::Construct()
{
    u_long128 t0;
    asm("pcpyld %0, %2, %1" : "=r"(t0) : "r"(0x302A400000000000UL), "r"(0x512));
    mCameraParams[7] = t0;
    u_long128 t1;
    asm("pcpyld %0, %2, %1" : "=r"(t1) : "r"(0x1000000000000008UL), "r"(0xE));
    mCameraParams[8] = t1;
    Construct__Q218CB3SkyDomeRenderer26CB3SkyDomeHemisphereParamsFQ222CB3SkyDomeRendererBase13ESkyComponent(&maParams[0], 0);
    Construct__Q218CB3SkyDomeRenderer26CB3SkyDomeHemisphereParamsFQ222CB3SkyDomeRendererBase13ESkyComponent(&maParams[1], 1);
    Construct__Q218CB3SkyDomeRenderer26CB3SkyDomeHemisphereParamsFQ222CB3SkyDomeRendererBase13ESkyComponent(&maParams[2], 2);
    Construct__Q218CB3SkyDomeRenderer26CB3SkyDomeHemisphereParamsFQ222CB3SkyDomeRendererBase13ESkyComponent(&maParams[3], 3);
    Construct__Q218CB3SkyDomeRenderer26CB3SkyDomeHemisphereParamsFQ222CB3SkyDomeRendererBase13ESkyComponent(&maParams[4], 4);
    Construct__Q218CB3SkyDomeRenderer26CB3SkyDomeHemisphereParamsFQ222CB3SkyDomeRendererBase13ESkyComponent(&maParams[5], 5);
    mbTexturesUploaded = 0;
    mePrepareState = 1;
}
