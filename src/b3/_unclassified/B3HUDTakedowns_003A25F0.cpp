// CB3HUDTakedowns::Prepare(int,EHUDAlign,int,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDTakedowns.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten on B3HUDEscapeDistance's model: CGtV2d temporaries, const mgr, scene pointer, int layer + layer1 locals, if/else width+text id, FLT_MAX literal).

// lifter variant 0
// CB3HUDTakedowns::Prepare(int,EHUDAlign,int,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDTakedowns.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

enum EHUDAlign {};
class CGt2dFrame;

class CB3HUDTakedowns;
struct UnkStruct_003A25F0_2;
struct UnkStruct_003A25F0_e0;
struct UnkStruct_003A25F0_e1;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_00522660;
struct UnkStruct_D_00665ECF;
struct UnkStruct_D_0066A4C0;

struct UnkStruct_D_00665ECF {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A25F0_2 {
    int field_0;
    float field_4;
    int field_8;
    float field_C;
    float field_10;
    float field_14;
    int field_18;
    float field_1C;
    float field_20;
    float field_24;
};

struct UnkStruct_003A25F0_e0 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_D_00522660 {
    UnkStruct_003A25F0_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_003A25F0_e1 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    unsigned char pad_20[0x20];
    GtMathPs2::CGtV4d field_40;
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDTakedowns {
public:
    int Prepare(int p0, EHUDAlign p1, int p2, bool p3, bool p4);
    void PrepareTakedownsObjects();

    unsigned char pad_0[0x4];
    UnkStruct_003A25F0_e1 * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    void * field_34;
    unsigned char pad_38[0x4];
    int field_3C;
    int field_40;
    unsigned char pad_44[0x50];
    unsigned char field_94;
    bool field_95;
};

extern UnkStruct_D_00665ECF D_00665ECF;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);  // CB3HUDComponent::AdjustScalingForSplitScreen()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, unsigned int);  // CB3HUDBackground2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,unsigned int)
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, float, GtMathPs2::CGtV4d, GtMathPs2::CGtV4d, void *, int, float, float);

// 0x003A25F0
int CB3HUDTakedowns::Prepare(int p0, EHUDAlign p1, int p2, bool p3, bool p4)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(this, 2, 5, 1, p0, p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(this);
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    void * scene = (char *)&field_4[field_1C] + 0x14;
    int layer = field_10;
    int layer1 = layer + 1;
    field_40 = 0;
    field_34 = ((char *)&D_00522660.field_0[p0] + 0x12BE10);
    field_94 = 0;
    field_95 = p4;
    field_3C = 0;
    field_20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)field_8);
    field_24 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)field_8);
    if (field_94 != 0) {
        field_28 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, (CGt2dFrame *)field_8);
        field_2C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, (CGt2dFrame *)field_8);
    } else {
        field_28 = 0;
        field_2C = 0;
    }
    field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)field_8);
    float w;
    int id;
    if (D_00665ECF.field_0 != 0) {
        w = 64.0f;
        id = 2043;
    } else {
        w = 188.0f;
        id = 2042;
    }
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi((void *)field_30, GtMathPs2::CGtV2d(-30.0f, 14.0f), GtMathPs2::CGtV2d(0.0f, 0.5f), GtMathPs2::CGtV2d(w, 27.0f), mgr->field_10, 2);
    int text = func_00271A00(&D_0051BA44, id);
    func_003824D0((void *)(field_20), GtMathPs2::CGtV2d(0.0f, 14.0f), GtMathPs2::CGtV2d(0.0f, 0.5f), 27.0f, mgr->field_40, mgr->field_40, (void *)(text), 9, 1.0f, 3.402823466e+38f);
    PrepareTakedownsObjects();
    return 1;
}
