// CB3PromptBarComponent::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PromptBarComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a130: CGtV2d v at top, const scene ptr after base Prepare, u_long128 field_0[2] struct copy).

#include "b3/GtMathPs2.h"
class CGt2dFrame;
struct UnkStruct_0038AD80_sp {
    unsigned long field_0;
    unsigned long field_8;
};
struct UnkStruct_0038AD80_obj {
    u_long128 field_0[2];
    int field_20[6];
    int field_38;
    int field_3C;
};
struct UnkStruct_0038AD80_frm {
    GtMathPs2::CGtV2d field_0;
};
struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    void * field_14;
    unsigned char pad_18[8];
};
struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0051BA88 {
    void * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];
};
class CB3PromptBarComponent {
public:
    int Prepare();
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_0038AD80_obj * field_C;
    UnkStruct_0038AD80_obj * field_10;
    void * field_14;
    UnkStruct_0038AD80_frm * field_18;
};
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__23CPromptBarPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &);
// 0x0038AD80
int CB3PromptBarComponent::Prepare()
{
    GtMathPs2::CGtV2d v;
    Prepare__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * const sc = &D_01E903E0;
    int t1 = field_8;
    int t0 = t1 + 1;
    field_18 = (UnkStruct_0038AD80_frm *)ConstructChild__10CGt2dFrameFv(sc->field_14);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(field_18);
    if (D_01E90424.field_0 == 0) {
        v = GtMathPs2::CGtV2d(0.0f, 96.0f);
        field_18->field_0 = v;
    }
    field_C = (UnkStruct_0038AD80_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(sc, t1, field_18);
    field_14 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(sc, t0, field_18);
    Prepare__23CPromptBarPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(field_C, GtMathPs2::CGtV2d(0.0f, 512.0f), GtMathPs2::CGtV2d(0.0f, 1.0f), GtMathPs2::CGtV2d(640.0f, 96.0f));
    Prepare__23CPromptBarPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(field_14, GtMathPs2::CGtV2d(0.0f, 480.0f), GtMathPs2::CGtV2d(0.0f, 1.0f), GtMathPs2::CGtV2d(640.0f, 64.0f));
    if (D_0051BA88.field_0 == &D_0051A6A8) {
        return 1;
    }
    field_10 = (UnkStruct_0038AD80_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(sc, t0, field_18);
    *field_10 = *field_C;
    return 1;
}
