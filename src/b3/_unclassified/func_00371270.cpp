// func_00371270 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E8970C.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8E7E0.h"

struct UnkStruct_00371270;

struct UnkStruct_00371270 {
    unsigned char pad_0[0x4];
    short field_4;
    short field_6;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x3];
    int field_10;
    unsigned char field_14;
    unsigned char pad_15[0x3];
    int field_18;
    unsigned char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    unsigned char field_24;
    unsigned char pad_25[0x3];
    int field_28;
    unsigned char field_2C;
    unsigned char pad_2D[0x3];
    int field_30;
    unsigned char field_34;
};

extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E8E7E0 D_01E8E7E0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E8970C D_01E8970C;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int PrepareSpinning__17CB3GlobeComponentFv(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void func_0039C150(void *, void *, void *);

// 0x00371270
extern "C" int func_00371270(UnkStruct_00371270 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    func_00319C80(&D_01E89518, 664, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 325, 3);
    D_01E894FC.Prepare();
    PrepareSpinning__17CB3GlobeComponentFv(&D_01E8E7E0);
    self->field_4 = 0;
    self->field_6 = 6;
    int r6 = func_00271A00(&D_0051BA44, 668);
    self->field_8 = r6;
    self->field_C = 0;
    int r7 = func_00271A00(&D_0051BA44, 669);
    self->field_10 = r7;
    self->field_14 = 0;
    int r8 = func_00271A00(&D_0051BA44, 671);
    self->field_18 = r8;
    self->field_1C = 0;
    int r9 = func_00271A00(&D_0051BA44, 674);
    self->field_20 = r9;
    self->field_24 = 0;
    int r10 = func_00271A00(&D_0051BA44, 675);
    self->field_28 = r10;
    self->field_2C = 0;
    int r11 = func_00271A00(&D_0051BA44, 676);
    self->field_30 = r11;
    self->field_34 = 0;
    func_0039C150(&D_01E8970C, ((char *)self + 0x4), ((char *)self + 0x8));
    return 1;
}
