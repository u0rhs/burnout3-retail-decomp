// CB3OnScreenKeyboardComponent::PrepareObjects(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (PrepareObjects).

#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGt2dObjectTableData;

extern CGt2dScene D_01E903E0;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const CGt2dObjectTableData *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);
extern "C" void *memset(void *, int, unsigned int);

class CB3OnScreenKeyboardComponent {
public:
    bool PrepareObjects(bool);
    void SetupTable();
    void SetupKeys(bool, bool, bool);
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[2];
    int field_C;
    unsigned char pad_10[8];
    unsigned char field_18;
    unsigned char field_19;
    bool field_1A;
    bool field_1B;
    unsigned char field_1C;
    unsigned char field_1D;
    unsigned char field_1E;
    unsigned char pad_1F;
    int field_20;
    unsigned char pad_24[4];
    unsigned char field_28[0x20];
    CGt2dObject *field_48;
    CGt2dObject *field_4C;
    unsigned char pad_50[0x3030];
    unsigned char field_3080[5][15];
    unsigned char pad_30CB[1];
    unsigned short *field_30CC;
    unsigned short *field_30D0;
    unsigned short *field_30D4;
    unsigned char pad_30D8[0x130];
    int field_3208;
    int field_320C;
};
// 0x003515D0
bool CB3OnScreenKeyboardComponent::PrepareObjects(bool top)
{
    CGt2dScene * const scene = &D_01E903E0;
    CGt2dFrame *root = scene->field_14;
    float y = 200.0f;
    Prepare__20CB3MenuComponentBaseFv(this);
    field_48 = scene->ConstructObject(field_8, root);
    if (top) y = 192.0f;
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(field_48, CGtV2d(48.0f, y), CGtV2d(0.0f, 0.0f), CGtV2d(561.0f, 184.0f), 287, 0);
    field_4C = scene->ConstructObject(field_8 + 1, root);
    float y2 = 207.0f;
    if (top) y2 = 199.0f;
    Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(field_4C, (const CGt2dObjectTableData *)&field_28, CGtV2d(52.0f, y2), CGtV2d(0.0f, 0.0f), CGtV2d(512.0f, 150.0f), CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
    field_1E = 1;
    field_20 = 0;
    field_18 = 0; field_19 = 0; field_1A = 0; field_1B = 0; field_1C = 0; field_1D = 0;
    field_320C = 0x40;
    field_3208 = 0x293;
    field_C = 0;
    memset(field_30D4, 0, 0x40);
    field_30CC = field_30D4;
    field_30D0 = field_30D4;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 15; j++)
            field_3080[i][j] = 1;
    SetupTable();
    SetupKeys((field_19 ^ field_18) != 0, field_1A, field_1B);
    return true;
}
