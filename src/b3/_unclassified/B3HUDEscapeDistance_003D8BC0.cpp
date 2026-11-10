// CB3HUDEscapeDistance::ActualPrepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDEscapeDistance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (CGtV2d ctor temporaries as call args (sibling func_003824D0 signature from B3HeadingComponent); const mgr = &D_0066A4C0; scene/layer locals; FLT_MAX literal).

// from build/vt\try_ActualPrepare__20CB3HUDEscapeDistanceFv_best.cpp
// CB3HUDEscapeDistance::ActualPrepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDEscapeDistance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

enum EHUDAlign {};
class CGt2dFrame;

class CB3HUDEscapeDistance;
struct UnkStruct_003D8BC0_2;
struct UnkStruct_003D8BC0_e1;
struct UnkStruct_D_004E0C14;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0066A4C0;

struct UnkStruct_003D8BC0_2 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    int field_20;
    float field_24;
};

struct UnkStruct_D_004E0C14 {
    float field_0;
};

struct UnkStruct_003D8BC0_e1 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    unsigned char pad_20[0x20];
    GtMathPs2::CGtV4d field_40;
};

class CB3HUDEscapeDistance {
public:
    void ActualPrepare();

    unsigned char pad_0[0x4];
    UnkStruct_003D8BC0_e1 * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20[1];  // [G] element count unknown
    int field_24;
    unsigned char pad_28[0x4];
    int field_2C;
    unsigned char pad_30[0x10];
    unsigned char field_40;
    unsigned char pad_41[0x3];
    int field_44;
    int field_48;
};

extern UnkStruct_D_004E0C14 D_004E0C14;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0066A4C0 D_0066A4C0;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, unsigned int);  // CB3HUDBackground2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,unsigned int)
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, float, GtMathPs2::CGtV4d, GtMathPs2::CGtV4d, void *, int, float, float);
extern "C" void func_003D8920(CB3HUDEscapeDistance *);

// 0x003D8BC0
void CB3HUDEscapeDistance::ActualPrepare()
{
    field_40 = 1;
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(this, 1, 3, 1, 0, (EHUDAlign)field_44, field_48);
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    void * scene = (char *)&field_4[field_1C] + 0x14;
    short layer = field_10;
    for (int i = 0; i < 3; i++) {
        field_20[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)field_8);
    }
    field_2C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)field_8);
    int text = func_00271A00(&D_0051BA44, 2223);
    func_003824D0((void *)(field_24), GtMathPs2::CGtV2d(0.0f, 14.0f), GtMathPs2::CGtV2d(1.0f, 0.5f), 27.0f, mgr->field_40, mgr->field_40, (void *)(text), 9, 1.0f, 3.402823466e+38f);
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi((void *)field_2C, GtMathPs2::CGtV2d(30.0f, 14.0f), GtMathPs2::CGtV2d(1.0f, 0.5f), GtMathPs2::CGtV2d(216.0f, 27.0f), mgr->field_10, 1);
    func_003D8920(this);
}
