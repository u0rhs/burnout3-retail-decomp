// func_0037E270 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004C9268.h"
#include "b3/classes/UnkStruct_D_004C9270.h"
#include "b3/classes/UnkStruct_D_004C9278.h"
#include "b3/classes/UnkStruct_D_004C9280.h"
#include "b3/classes/UnkStruct_D_004C9288.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E8970C.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8D4B0.h"

struct UnkStruct_0037E270;

struct UnkStruct_0037E270 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char field_8;
    unsigned char pad_9[0x3];
    int field_C;
    unsigned char field_10;
    unsigned char pad_11[0x3];
    short field_14;
    short field_16;
    unsigned char field_18;
    unsigned char field_19;
};

extern UnkStruct_D_004C9288 D_004C9288;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E8970C D_01E8970C;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_D_004C9268 D_004C9268;
extern UnkStruct_D_004C9270 D_004C9270;
extern UnkStruct_D_004C9278 D_004C9278;
extern UnkStruct_D_004C9280 D_004C9280;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_0039BCD0(void *, void *, void *, int, int, float);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);

// 0x0037E270
extern "C" bool func_0037E270(UnkStruct_0037E270 * self, int p0)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 260, 3);
    D_01E894FC.Prepare();
    self->field_14 = 0;
    self->field_16 = 2;
    int r4 = func_00271A00(&D_0051BA44, 448);
    self->field_4 = r4;
    self->field_8 = 0;
    int r5 = func_00271A00(&D_0051BA44, 449);
    self->field_C = r5;
    self->field_10 = 0;
    func_0039BCD0(&D_01E8970C, ((char *)self + 0x14), ((char *)self + 0x4), 3, 0, 516.0f);
    self->field_19 = p0;
    if (self->field_19 != 0) {
        func_00319C80(&D_01E89518, 128, 14);
        func_00351F00(&D_01E8D4B0, &D_004C9268, &D_004C9270, &D_004C9278, &D_004C9280, &D_004C9288, 131, 3, 1, 3, 0, 32.0f, D_004C9288.field_0);
    } else {
        func_00319C80(&D_01E89518, 1007, 14);
        func_00351F00(&D_01E8D4B0, &D_004C9268, &D_004C9270, &D_004C9278, &D_004C9280, &D_004C9288, 1042, 3, 1, 3, 0, 32.0f, D_004C9288.field_0);
    }
    self->field_18 = 0;
    return true;
}
