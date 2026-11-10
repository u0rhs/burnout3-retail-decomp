// CB3PageTextComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const unsigned short*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PageTextComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gif7: TextComponent sibling shapes; kB3PageTextBorder as CGtV2d (add operand order), int i = field_8 + 1 index local, D_01EA4980 fill order swept (720), field_10 CGtV2d copy).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00379690_ent { unsigned char pad_0[0xC]; void * field_C; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void * field_14; unsigned char pad_18[0x14]; UnkStruct_00379690_ent * field_2C; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00665ED8 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA4980 {
    CGtV2d field_0;
    float field_8;
    float field_C;
    void * field_10;
    short field_14;
    short field_16;
};
struct UnkStruct_00379690_border { CGtV2d field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_00379690_frm { CGtV2d field_0; CGtV2d field_8; };
struct UnkStruct_00379690_obj { CGtV2d field_0; };

class CB3PageTextComponent {
public:
    int Prepare(const CGtV2d& p0, const CGtV2d& p1, const unsigned short* p2, unsigned int p3);

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    CGtV2d field_10;
    UnkStruct_00379690_obj * field_18;
    UnkStruct_00379690_frm * field_1C;
    void * field_20;
    int field_24;
    float field_28;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_D_01EA4980 D_01EA4980;
extern UnkStruct_00379690_border kB3PageTextBorder;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_002F9690(const void *, const CGtV2d &, float, const CGtV2d &, const void *, const unsigned short *, void *, int, int);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);

// 0x00379690
int CB3PageTextComponent::Prepare(const CGtV2d& p0, const CGtV2d& p1, const unsigned short* p2, unsigned int p3)
{
    Prepare__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    void * parent = scene->field_14;
    field_1C = (UnkStruct_00379690_frm *)ConstructChild__10CGt2dFrameFv(parent);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(field_1C);
    field_1C->field_0 = CGtV2d(p0.X() + 0.5f * kB3PageTextBorder.field_0.X(), p0.Y() + kB3PageTextBorder.field_0.Y());
    field_1C->field_8 = CGtV2d(p1.X() - kB3PageTextBorder.field_0.X(), p1.Y() - (2.0f + kB3PageTextBorder.field_0.Y()));
    int i = field_8 + 1;
    scene->field_2C[i].field_C = field_1C;
    D_01EA4980.field_0 = CGtV2d(0.0f, 0.0f);
    D_01EA4980.field_10 = D_00665ED8.field_0;
    D_01EA4980.field_C = 1.0f;
    D_01EA4980.field_8 = 26.0f;
    D_01EA4980.field_14 = 0;
    D_01EA4980.field_16 = 2.0f + p1.Y() / 27.0f;
    field_18 = (UnkStruct_00379690_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8 + 1, parent);
    func_002F9690(field_18, CGtV2d(p0.X() + kB3PageTextBorder.field_0.X(), p0.Y() + kB3PageTextBorder.field_0.Y()),
                  p1.X() - 2.0f * kB3PageTextBorder.field_0.X(), CGtV2d(0.0f, 0.0f), &D_01E90240, p2, &D_01EA4980, p3, 0);
    field_20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8, parent);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(field_20, p0, CGtV2d(0.0f, 0.0f), p1, 27, 0);
    field_24 = 0;
    field_28 = p0.Y() + kB3PageTextBorder.field_0.Y();
    field_10 = field_18->field_0;
    return 1;
}
