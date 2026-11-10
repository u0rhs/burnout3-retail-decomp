// CB3TextComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const unsigned short*,float,bool,float,unsigned int,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TextComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (BuddyReadMail shapes: const mgr/scene, params struct fill order, &CGtV2d(2,2) temp, shared field_34 store, func_002F9690 float 3rd).

// CB3TextComponent::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const unsigned short*,float,bool,float,unsigned int,bool)
// -- hand-written (fresh1) on CB3BuddyReadMailComponent::Prepare's shapes (B3BuddyReadMailComponent_00372600.cpp).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TextComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void * field_14; unsigned char pad_18[0x8]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x110]; unsigned char field_110[0x10]; };
struct UnkStruct_D_00665ED0 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA3F80 {
    CGtV2d field_0;
    float field_8;
    float field_C;
    void * field_10;
    short field_14;
    short field_16;
};
extern UnkStruct_D_01EA3F80 D_01EA3F80;

class CB3TextComponent {
public:
    int Prepare(const CGtV2d& p0, const CGtV2d& p1, const unsigned short* p2, float p3, bool p4, float p5, unsigned int p6, bool p7);

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x26];
    void * field_30;
    int field_34;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED0 D_00665ED0;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_001D6AD0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, const unsigned short *, const CGtV2d *, int);
// [G] float declared third (f12 either way under the EABI): this parameter order gives retail's argument setup
// order (mov.s f12 early); the proven B3BuddyReadMailComponent declares it last.
extern "C" void func_002F9690(void *, const CGtV2d &, float, const CGtV2d &, const void *, const unsigned short *, void *, int, int);
// [G] colour taken as `const void *`: retail passes &mgr->field_110 with no by-value copy (the proven declaration's
// CGtV4d by value would copy it).
extern "C" void func_003D0710(void *, const CGtV2d &, const CGtV2d &, const void *, int, int, int, void *, float, float,
                              const unsigned short *, bool);

// 0x00351C60
int CB3TextComponent::Prepare(const CGtV2d& p0, const CGtV2d& p1, const unsigned short* p2, float p3, bool p4, float p5, unsigned int p6, bool p7)
{
    Prepare__20CB3MenuComponentBaseFv(this);
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    void * parent = scene->field_14;
    if (p4) {
        D_01EA3F80.field_0 = CGtV2d(0.0f, 0.0f);
        D_01EA3F80.field_10 = D_00665ED0.field_0;
        D_01EA3F80.field_C = 1.0f;
        D_01EA3F80.field_8 = p3;
        D_01EA3F80.field_14 = -1;
        D_01EA3F80.field_16 = -1;
        field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8 + 1, parent);
        func_002F9690(field_30, p0, p5, p1, mgr, p2, &D_01EA3F80, p6, 0);
    } else if (p7) {
        field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8 + 1, parent);
        func_003D0710(field_30, p0, p1, mgr->field_110, 1, 0, 0, D_00665ED0.field_0, p3, 3.402823466e+38f, p2, false);
    } else {
        field_30 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, field_8 + 1, parent);
        func_001D6AD0(field_30, p0, p1, p3, mgr, D_00665ED0.field_0, p2, &CGtV2d(2.0f, 2.0f), 1);
    }
    field_34 = 0;
    return 1;
}
