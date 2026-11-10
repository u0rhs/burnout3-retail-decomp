// CB3ChatDisplayComponent::PrepareWithoutStrings(EB3ChatDisplayOrientation) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near35: text obj fields at +0x40..0x4C (old archive offsets wrong), cells field_C0[10][2], field_7F0/field_818 split, indexed stores, field_2C before field_28).

// near35: text object = CGtV4d at +0x20, 0x10 pad, then float/font/string/int at +0x40..0x4C (old archive had +0x30);
// cells as field_C0[10][2]; field_7F0/field_818 as two arrays (as the proven Prepare); field_2C stored before field_28.


#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
enum EB3ChatDisplayOrientation {};
struct UnkStruct_WS_Slot { unsigned char pad_0[0xC]; void *field_C; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void *field_14; unsigned char pad_18[0x14]; UnkStruct_WS_Slot *field_2C; };
struct UnkStruct_D_01E90240 { CGtV4d field_0; unsigned char pad_10[0xF0]; };
struct UnkStruct_D_00665ED8 { CGt2dFont *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
struct UnkStruct_WS_Row { float field_0; float field_4; unsigned char field_8; unsigned char pad_9[3]; };
struct UnkStruct_WS_Text { CGtV4d field_0; unsigned char pad_10[0x10]; float field_20; CGt2dFont *field_24; unsigned short *field_28; int field_2C; };
struct UnkStruct_WS_Obj { unsigned char pad_0[0x20]; UnkStruct_WS_Text field_20; };
struct UnkStruct_WS_Cell { void *field_0; void *field_4; void *field_8; };
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void *ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);
extern "C" void RecalculateSize__16CGt2dObjectTableFv(void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);

class CB3ChatDisplayComponent {
public:
    int PrepareWithoutStrings(EB3ChatDisplayOrientation p0);
    void SetOrientation(EB3ChatDisplayOrientation p0);
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[6];
    CGtV2d field_10;
    int field_18;
    int field_1C;
    void *field_20;
    void *field_24;
    void *field_28;
    int field_2C;
    UnkStruct_WS_Row field_30[10];
    float field_A8;
    float field_AC;
    unsigned char field_B0;
    unsigned char pad_B1[3];
    float field_B4;
    float field_B8;
    unsigned char field_BC;
    unsigned char pad_BD[3];
    UnkStruct_WS_Cell field_C0[10][2];
    UnkStruct_WS_Obj field_1B0[10];
    UnkStruct_WS_Obj field_4D0[10];
    unsigned short *field_7F0[10];
    unsigned short *field_818[10];
    CGtV2d field_840;
    CGtV2d field_848;
    CGtV2d field_850;
    CGtV2d field_858;
    void *field_860;
    void *field_864;
    void *field_868;
};

// 0x003322F0
int CB3ChatDisplayComponent::PrepareWithoutStrings(EB3ChatDisplayOrientation p0)
{
    UnkStruct_D_01E903E0 *const scene = &D_01E903E0;
    void *frame = scene->field_14;
    UnkStruct_D_01E90240 *mgr = &D_01E90240;
    Prepare__20CB3MenuComponentBaseFv(this);
    field_864 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8, frame);
    field_860 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8 + 1, frame);
    field_868 = ConstructChild__10CGt2dFrameFv(frame);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(field_868);
    int k = field_8 + 1;
    scene->field_2C[k].field_C = field_868;
    SetOrientation(p0);
    field_18 = 10;
    field_1C = 2;
    field_20 = &field_30[0];
    field_24 = &field_A8;
    field_2C = 0;
    field_28 = &field_C0[0][0];
    field_10 = field_858;
    field_AC = 10.0f;
    field_B0 = 1;
    field_B4 = 10.0f;
    field_B8 = 10.0f;
    field_BC = 1;
    field_30[0].field_0 = 1.0f;
    field_30[0].field_4 = 23.0f;
    field_30[0].field_8 = 0;
    for (int j = 1; j < 10; j++) {
        field_30[j].field_0 = 1.0f;
        field_30[j].field_4 = 23.0f;
        field_30[j].field_8 = 0;
    }
    int j;
    int i;
    for (i = 0; i < 10; i++) {
        field_1B0[i].field_20.field_0 = mgr->field_0;
        field_1B0[i].field_20.field_20 = 23.0f;
        field_1B0[i].field_20.field_24 = D_00665ED8.field_0;
        field_1B0[i].field_20.field_2C = 0;
        field_1B0[i].field_20.field_28 = field_7F0[i];
        field_4D0[i].field_20.field_0 = mgr->field_0;
        field_4D0[i].field_20.field_20 = 23.0f;
        field_4D0[i].field_20.field_24 = D_00665ED8.field_0;
        field_4D0[i].field_20.field_2C = 0;
        field_4D0[i].field_20.field_28 = field_818[i];
        for (j = 0; j < 2; j++) {
            if (j == 0) {
                field_C0[i][j].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_C0[i][j].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                field_C0[i][j].field_8 = &field_1B0[i];
            } else if (j == 1) {
                field_C0[i][j].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_C0[i][j].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                field_C0[i][j].field_8 = &field_4D0[i];
            }
        }
        *field_7F0[i] = 0x20;
        *field_818[i] = 0x20;
    }
    RecalculateSize__16CGt2dObjectTableFv(field_860);
    return 1;
}
