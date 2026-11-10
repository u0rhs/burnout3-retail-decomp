// CB3SparkRenderer::RenderSparkArray(CB3SparkArray*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void; nested GtMath::Max; bool a = x > limit; field_A4 = crash && y > limit in one statement; if (a || field_A4)).

// CB3SparkRenderer::RenderSparkArray(CB3SparkArray*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMath.h"

class CB3SparkArray;

class CB3SparkRenderer;
struct UnkStruct_002637F0_1;
struct UnkStruct_D_00522680;

struct UnkStruct_002637F0_1 {
    unsigned char pad_0[0x40];
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    unsigned char pad_50[0xC];
    float field_5C;
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SparkRenderer {
public:
    void RenderSparkArray(CB3SparkArray* p0);
    static unsigned char mbIsCrash;
    static int mnNumRenderableArrays;
    static float mrMaxMotionBlurTime;

    unsigned char pad_0[0x44];
    float field_44;
    unsigned char pad_48[0x48];
    float field_90;
    unsigned char pad_94[0x4];
    UnkStruct_002637F0_1 * field_98;
    unsigned char pad_9C[0x8];
    unsigned char field_A4;
};

extern UnkStruct_D_00522680 D_00522680;
extern CB3SparkRenderer * D_01E327B0[];  // [G] element count unknown

// 0x002637F0
void CB3SparkRenderer::RenderSparkArray(CB3SparkArray* p0)
{
    UnkStruct_002637F0_1 * m = field_98;
    float r = GtMath::Max(m->field_4C, GtMath::Max(m->field_48, GtMath::Max(m->field_40, m->field_44)));
    float limit = D_00522680.field_0 - r;
    bool a = field_44 > limit;
    field_A4 = CB3SparkRenderer::mbIsCrash != 0 && field_90 > limit;
    if (a || field_A4) {
        D_01E327B0[CB3SparkRenderer::mnNumRenderableArrays++] = this;
        CB3SparkRenderer::mrMaxMotionBlurTime = GtMath::Max(CB3SparkRenderer::mrMaxMotionBlurTime, field_98->field_5C);
    }
}
