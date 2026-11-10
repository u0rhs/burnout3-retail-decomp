// func_003787D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3TableComponent.h"
#include "b3/classes/CGt2dObjectTableData.h"
#include "b3/classes/UnkStruct_D_004C9018.h"
#include "b3/classes/UnkStruct_D_004C9020.h"
#include "b3/classes/UnkStruct_D_01E89544.h"
#include "b3/classes/UnkStruct_D_01E8954E.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E898F2.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"
#include "b3/classes/UnkStruct_D_01E8D490.h"
#include "b3/classes/UnkStruct_D_01E8D49A.h"
#include "b3/classes/UnkStruct_D_01E8EAF8.h"
#include "b3/classes/UnkStruct_D_01E8EB02.h"

struct UnkStruct_003787D0;
struct UnkStruct_003787D0_10;

struct UnkStruct_003787D0_v {
    float field_0;
    float field_4;
};

struct UnkStruct_003787D0 {
    unsigned char pad_0[0xEDC];
    short field_EDC;
    short field_EDE;
    short field_EE0;
    short field_EE2;
    unsigned char pad_EE4[0x1C];
    int field_F00;
    unsigned char pad_F04[0x1];
    unsigned char field_F05;
};

extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8EB02 D_01E8EB02;
extern UnkStruct_D_01E8EAF8 D_01E8EAF8;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_004C9018 D_004C9018;
extern UnkStruct_D_004C9020 D_004C9020;
extern "C" void PrepareSplitBackground__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatab(void *, const void *, const void *, const void *, const void *, bool);  // CB3TableComponent::PrepareSplitBackground(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const CGt2dObjectTableData*,bool)
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x003787D0
extern "C" void func_003787D0(UnkStruct_003787D0 * self)
{
    UnkStruct_003787D0_v a;
    UnkStruct_003787D0_v b;
    UnkStruct_003787D0_v c;
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8EB02.field_0 != 0) {
        ((UnkStruct_D_01E8EAF8 *)&D_01E8EAF8)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    c.field_0 = 544.0f;
    c.field_4 = 272.0f;
    a.field_0 = 48.0f;
    a.field_4 = 112.0f;
    b.field_0 = 0;
    b.field_4 = 0;
    PrepareSplitBackground__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatab(&D_01E8D450, &a, &b, &c, (const CGt2dObjectTableData*)((char *)self + 0xC88), 0);
    self->field_EDC = 0;
    self->field_EDE = 5;
    int t0 = self->field_F00;
    self->field_EE0 = 0;
    self->field_EE2 = t0;
    Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C9018, &D_004C9020, ((char *)self + 0xEE0), 224.0f);
    self->field_F05 = 1;
    func_0032D080(&D_01E898E8, 0, 1261, 15, 0);
}
