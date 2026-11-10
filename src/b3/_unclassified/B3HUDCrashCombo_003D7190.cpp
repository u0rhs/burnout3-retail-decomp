// CB3HUDCrashCombo::Prepare(int,EHUDAlign,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDCrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (CGtV2d temps; size/pos/offset in static inline helpers (stack order); element ptr &field_4[field_1C] local).

// CB3HUDCrashCombo::Prepare(int,EHUDAlign,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDCrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

enum EHUDAlign {};
class CGt2dFrame;

class CB3HUDCrashCombo;
struct UnkStruct_003D7190_1;
struct UnkStruct_003D7190_2;
struct UnkStruct_003D7190_3;
struct UnkStruct_003D7190_e0;
struct UnkStruct_003D7190_e1;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0066A4D0;
struct UnkStruct_func_003D76C0;

struct UnkStruct_003D7190_1 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    unsigned long field_18;
    int field_20;
    int field_24;
    float field_28;
    float field_2C;
    int field_30;
    int field_34;
    int field_38;
    float field_3C;
};

struct UnkStruct_003D7190_2 {
    unsigned char pad_0[0x278];
    int field_278;
};

struct UnkStruct_003D7190_3 {
    unsigned char pad_0[0x20];
    int field_20;
    int field_24;
    int field_28;
};

struct UnkStruct_003D7190_e0 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_D_00522660 {
    UnkStruct_003D7190_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_003D7190_e1 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_D_0066A4D0 {
    GtMathPs2::CGtV4d field_0;
};

struct UnkStruct_func_003D76C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDCrashCombo {
public:
    int Prepare(int p0, EHUDAlign p1, int p2);

    unsigned char pad_0[0x4];
    UnkStruct_003D7190_e1 * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    int field_24;
    UnkStruct_003D7190_2 * field_28;
    UnkStruct_003D7190_3 * field_2C;
};

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0066A4D0 D_0066A4D0;
extern UnkStruct_func_003D76C0 func_003D76C0;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__23CPromptBarPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &);  // CPromptBarPanel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);  // CGt2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,void (*)(const CGt2dObject::CGt2dObjectSpace&,const void*),unsigned int,unsigned int)

static inline GtMathPs2::CGtV2d func_003D7190_inl2(const GtMathPs2::CGtV2d & size)
{
    GtMathPs2::CGtV2d off = size * GtMathPs2::CGtV2d(0.0f, 0.5f);
    return GtMathPs2::CGtV2d(0.0f, 404.0f) - off;
}

static inline void func_003D7190_inl1(CB3HUDCrashCombo * self)
{
    int t4 = self->field_28->field_278;
    GtMathPs2::CGtV2d size(640.0f, 25.0f);
    UnkStruct_003D7190_3 * o = self->field_2C;
    o->field_24 = t4;
    o->field_28 = -1;
    o->field_20 = 0;
    GtMathPs2::CGtV2d pos = func_003D7190_inl2(size);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, pos, size, D_0066A4D0.field_0, (const void *)&func_003D76C0, 64, 12);
}

// 0x003D7190
int CB3HUDCrashCombo::Prepare(int p0, EHUDAlign p1, int p2)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(this, 1, 2, 0, p0, p1, p2);
    UnkStruct_003D7190_e1 * t1 = &field_4[field_1C];
    int t2 = field_10;
    field_28 = (UnkStruct_003D7190_2 *)((char *)&D_00522660.field_0[p0] + 0x12BE10);
    field_24 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(((char *)t1 + 0x14), t2, (CGt2dFrame*)field_8);
    field_20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(((char *)t1 + 0x14), t2, (CGt2dFrame*)field_8);
    Prepare__23CPromptBarPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d((void *)field_20, GtMathPs2::CGtV2d(0.0f, 388.0f), GtMathPs2::CGtV2d(0.0f, 0.0f), GtMathPs2::CGtV2d(640.0f, 32.0f));
    field_2C = (UnkStruct_003D7190_3 *)field_24;
    func_003D7190_inl1(this);
    return 1;
}
