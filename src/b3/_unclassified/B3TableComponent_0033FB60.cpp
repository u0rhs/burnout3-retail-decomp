// CB3TableComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const CGt2dObjectTableData*,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (scene = &D_01E90240.field_1A0 and mgr = &D_01E90240 locals (sibling-component shape, mgr spilled to stack); pass mgr->field_100).

// CB3TableComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const CGt2dObjectTableData*,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TableComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CGt2dObjectTableData;
class CGt2dFrame;

class CB3TableComponent;
struct UnkStruct_D_01E90240;
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
    int Prepare(const GtMathPs2::CGtV2d& p0, const GtMathPs2::CGtV2d& p1, const GtMathPs2::CGtV2d& p2, const CGt2dObjectTableData* p3, bool p4, bool p5);

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    int field_C;
    int field_10;
    unsigned char pad_14[0x8];
    int field_1C;
    unsigned char pad_20[0x10];
    int field_30;
};

extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const void *, const void *, const void *, const void *, GtMathPs2::CGtV4d);  // CGt2dObjectTable::Prepare(const CGt2dObjectTableData*,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d)
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const void *, const void *, const void *, unsigned int, int);  // CB3RoundedPanel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned int), passed 1 more argument(s) [G]

// 0x0033FB60
int CB3TableComponent::Prepare(const GtMathPs2::CGtV2d& p0, const GtMathPs2::CGtV2d& p1, const GtMathPs2::CGtV2d& p2, const CGt2dObjectTableData* p3, bool p4, bool p5)
{
    Prepare__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 *scene = &D_01E90240.field_1A0;
    int root = scene->field_14;
    UnkStruct_D_01E90240 *mgr = &D_01E90240;
    field_30 = 0;
    if (p4) {
        field_30 |= 1;
    }
    if (p5) {
        field_30 |= 2;
    }
    field_1C = 0;
    field_C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8 + 1, (CGt2dFrame*)root);
    Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d((void *)field_C, p3, &p0, &p1, &p2, mgr->field_100);
    if ((field_30 & 1) != 0) {
        field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8, (CGt2dFrame*)root);
        if ((field_30 & 2) != 0) {
            Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi((void *)field_10, &p0, &p1, (void *)(field_C + 8), 31, 0);
        } else {
            Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi((void *)field_10, &p0, &p1, &p2, 31, 0);
        }
    }
    return 1;
}
