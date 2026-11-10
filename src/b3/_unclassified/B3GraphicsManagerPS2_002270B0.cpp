// CB3GraphicsManager::PresentDrawBuffer() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManagerPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near1: Revenge's function-local static lnRotate (= retail .sbss D_004E294C, retargeted by tools/sdata_retarget.py's new .sbss path); stabs1's exact source).

// CB3GraphicsManager::PresentDrawBuffer() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManagerPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3GraphicsManager;
struct UnkStruct_D_004E294C;
struct UnkStruct_D_01E90222;
struct UnkStruct__gnNextBlit;
struct UnkStruct__rwDMAFlipData;

struct UnkStruct_D_01E90222 {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct__gnNextBlit {
    int field_0;
};

struct UnkStruct_D_004E294C {
    int field_0;
};

struct UnkStruct__rwDMAFlipData {
    unsigned char pad_0[0x3C0];
    int field_3C0;
    int field_3C4;
    int field_3C8;
    int field_3CC;
};

class CB3GraphicsManager {
public:
    void PresentDrawBuffer();
    void RenderPalOrHdtvContrastFilter();

    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
    bool field_C;
    unsigned char pad_D[0x257];
    float field_264;
    float field_268;
    unsigned char pad_26C[0xFC];
    int field_368;
    unsigned char pad_36C[0x54];
    int field_3C0;
    unsigned char pad_3C4[0x60];
    int field_424;
    int field_428;
};

extern UnkStruct_D_01E90222 D_01E90222;
extern UnkStruct__gnNextBlit _gnNextBlit;
extern int D_01D6EDC0[];  // [G] element count unknown
extern UnkStruct_D_004E294C D_004E294C;
extern unsigned long D_0049B520[];  // [G] element count unknown
extern UnkStruct__rwDMAFlipData _rwDMAFlipData;

extern "C" int BuildPacket__5CBlitFUiUiUiUiUiUiUiUlb(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned long, bool);  // CBlit::BuildPacket(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned long,bool)
extern "C" void RwCameraShowRaster(int, int, int);

// 0x002270B0
void CB3GraphicsManager::PresentDrawBuffer()
{
    // [L] Revenge's PresentDrawBuffer__18CB4GraphicsManager has function-local statics `lnRotate` (RwInt32) and
    // `lau64DimXA[4]` (research/stabs); here lnRotate is retail's D_004E294C (.sbss). Static-ness is what matches [C]
    // (stabs1: the same statement through `extern int D_004E294C` = 14 changed, through this static = 0).
    static int lnRotate;
    if (D_01E90222.field_0 != 0) {
        RenderPalOrHdtvContrastFilter();
    } else {
    }
    int t0 = _gnNextBlit.field_0;
    void *pk = (void *)(D_01D6EDC0[t0] | 0x30000000);
    _gnNextBlit.field_0 = ((t0 + 1) % 3);
    lnRotate = (lnRotate + 1) % 4;
    unsigned int luBrightness = (int)(0.5f + (256.0f * field_268));
    if (luBrightness > 255) {
        luBrightness = 255;
    }
    int r1 = BuildPacket__5CBlitFUiUiUiUiUiUiUiUlb(pk, field_0, field_4, field_3C0, luBrightness, (128 - ((int)(96.0f * field_264))), field_424, field_428, D_0049B520[(long)lnRotate], field_C);
    _rwDMAFlipData.field_3C0 = r1;
    _rwDMAFlipData.field_3C4 = r1;
    _rwDMAFlipData.field_3C8 = r1;
    _rwDMAFlipData.field_3CC = r1;
    RwCameraShowRaster(field_368, 0, 1);
}
