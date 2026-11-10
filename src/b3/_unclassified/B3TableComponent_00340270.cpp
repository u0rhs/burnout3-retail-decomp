// CB3TableComponent::PrepareSplitBackground(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const CGt2dObjectTableData*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (kept early stores: whole CGtV2d copy vA8 = p2 then SetY(vA8.Y() - ...) reading the copy back).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGt2dObjectTableData;
class CGt2dFrame;

class CGt2dObjectTable {
public:
    CGtV2d GetRowPos(int);   // [G] return type: an 8-byte result through a0 (hidden pointer)
    CGtV2d GetRowSize(int);  // [G] as GetRowPos
};

class CB3TableComponent;
struct UnkStruct_D_01E903E0;

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x100];
    GtMathPs2::CGtV4d field_100;
    unsigned char pad_110[0x90];
    UnkStruct_D_01E903E0 field_1A0;  // = D_01E903E0 (N65)
};

class CB3TableComponent {
public:
    int PrepareSplitBackground(const GtMathPs2::CGtV2d& p0, const GtMathPs2::CGtV2d& p1, const GtMathPs2::CGtV2d& p2, const CGt2dObjectTableData* p3, bool p4);

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObjectTable * field_C;
    int field_10;
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    unsigned char pad_20[0x10];
    int field_30;
};

extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const void *, const void *, const void *, const void *, GtMathPs2::CGtV4d);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const void *, const void *, const void *, unsigned int, int);

// 0x00340270
int CB3TableComponent::PrepareSplitBackground(const GtMathPs2::CGtV2d& p0, const GtMathPs2::CGtV2d& p1, const GtMathPs2::CGtV2d& p2, const CGt2dObjectTableData* p3, bool p4)
{
    CGtV2d vA8;
    CGtV2d vA0;
    Prepare__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 *scene = &D_01E90240.field_1A0;
    int root = scene->field_14;
    field_30 = 0;
    field_30 |= 1;
    field_30 |= 4;
    field_1C = 0;
    field_C = (CGt2dObjectTable *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8 + 1, (CGt2dFrame*)root);
    Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d((void *)field_C, p3, &p0, &p1, &p2, D_01E90240.field_100);
    vA0.SetX(p0.X());
    vA0.SetY(field_C->GetRowPos(1).Y());
    vA8 = p2;
    vA8.SetY(vA8.Y() - (vA0.Y() - p0.Y()));
    field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8, (CGt2dFrame*)root);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi((void *)field_10, &vA0, &CGtV2d(0.0f, 0.0f), &vA8, 30, 0);
    vA8 = p2;
    vA8.SetY(field_C->GetRowSize(0).Y());
    field_14 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8, (CGt2dFrame*)root);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi((void *)field_14, &p0, &CGtV2d(0.0f, 0.0f), &vA8, 29, 0);
    return 1;
}
