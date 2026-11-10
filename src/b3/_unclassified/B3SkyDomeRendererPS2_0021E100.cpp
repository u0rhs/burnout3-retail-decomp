// CB3SkyDomeRenderer::Prepare(CGtTexture*,CGtTexture*,CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a119: switch 1,0x18,2,3; int r=1 default; zero-pcpyld via int hi/ulong lo locals; gradient quad one/t locals).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_D_006662D0 { int field_0; int pad_4[3]; };
struct UnkStruct_D_00665EC0 { unsigned char pad_0[0x10]; };
struct UnkStruct_maParams {
    unsigned char pad_0[0x190];
    u_long128 field_190;
    unsigned char pad_1A0[0x1A0];
    u_long128 field_340;
};
struct UnkStruct_D_0051BA88 { void *field_0; int pad_4[3]; };
struct UnkStruct_D_0051A6A8 { int pad_0[4]; };
class CGtTexture;
class CB3SkyDomeRenderer {
public:
    static int Prepare(CGtTexture *, CGtTexture *, CGtTexture *);
    static int mePrepareState;
    static unsigned char mbTexturesUploaded;
    static UnkStruct_maParams maParams;
    static u_long128 mu128SourceGradientTex0_1;
    static u_long128 mu128BackdropScissor_1;
    static u_long128 mu128BackdropTest_1;
};
extern UnkStruct_D_006662D0 D_006662D0;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern unsigned long skyZbuf_1;
extern "C" void func_0021E350();
extern "C" void func_0021D8E0();
extern "C" u_long128 Copy8BitTextureAsPSMT8H__18CB3GraphicsManagerFP10CGtTextureUiQ218CB3GraphicsManager7EClutIDUi(void *, CGtTexture *, unsigned int, int, unsigned int);
extern "C" u_long128 CopyTextureAs32Bit__18CB3GraphicsManagerFP10CGtTextureUiUi(void *, CGtTexture *, unsigned int, unsigned int);

// 0x0021E100
int CB3SkyDomeRenderer::Prepare(CGtTexture *c, CGtTexture *a, CGtTexture *b)
{
    int r = 1;
    switch (mePrepareState) {
    case 1:
    case 0x18:
        if (mbTexturesUploaded == 1) return 1;
        func_0021E350();
        {
            unsigned long lo = ((unsigned long)0x1F0000 << 32) | 0x3F0000UL;
            asm("pcpyld %0, %2, %1" : "=r"(mu128BackdropScissor_1) : "r"(lo), "r"(0x40));
            asm("pcpyld %0, %2, %1" : "=r"(mu128BackdropTest_1) : "r"(0x31001UL), "r"(0x47));
        }
        if (a) {
            maParams.field_190 = Copy8BitTextureAsPSMT8H__18CB3GraphicsManagerFP10CGtTextureUiQ218CB3GraphicsManager7EClutIDUi(&D_00665EC0, a, (int)(skyZbuf_1 & 0x1FF) * 32 + 0x80, 0, 0);
        } else {
            { int hi = 0; unsigned long lo = 0; asm("pcpyld %0, %2, %1" : "=r"(maParams.field_190) : "r"(lo), "r"(hi)); }
        }
        if (b) {
            maParams.field_340 = Copy8BitTextureAsPSMT8H__18CB3GraphicsManagerFP10CGtTextureUiQ218CB3GraphicsManager7EClutIDUi(&D_00665EC0, b, (int)(skyZbuf_1 & 0x1FF) * 32 + 0x1080, 1, 0);
        } else {
            { int hi = 0; unsigned long lo = 0; asm("pcpyld %0, %2, %1" : "=r"(maParams.field_340) : "r"(lo), "r"(hi)); }
        }
        if (c) {
            mu128SourceGradientTex0_1 = CopyTextureAs32Bit__18CB3GraphicsManagerFP10CGtTextureUiUi(&D_00665EC0, c, D_006662D0.field_0 + 0x50, 0);
        } else {
            int g = D_006662D0.field_0;
            unsigned long one = 1UL << 32;
            unsigned long t = 0x54004000UL | one;
            unsigned long lo = (unsigned long)(unsigned int)(g + 0x50) | t;
            asm("pcpyld %0, %2, %1" : "=r"(mu128SourceGradientTex0_1) : "r"(lo), "r"(6));
        }
        mePrepareState = 2;
        return 0;
    case 2:
        mePrepareState = 3;
        mbTexturesUploaded = 1;
        return 0;
    case 3:
        if (D_0051BA88.field_0 == &D_0051A6A8) {
            func_0021D8E0();
        }
        mePrepareState = 0x17;
        return 0;
    }
    return r;
}
