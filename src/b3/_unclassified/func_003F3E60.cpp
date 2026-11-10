// func_003F3E60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004F5070.h"
#include "b3/classes/UnkStruct_D_004F5071.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E8961C.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

struct UnkStruct_003F3E60;

struct UnkStruct_003F3E60 {
    unsigned char pad_0[0x4];
    short field_4;
    short field_6;
    int field_8;
    int field_C;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char pad_17[0x1];
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char field_2A;
    unsigned char pad_2B[0x1];
    int field_2C;
};

extern UnkStruct_D_004F5070 D_004F5070;
extern UnkStruct_D_004F5071 D_004F5071;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void func_003BC500(void *, int, signed char);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003F3E60
extern "C" int func_003F3E60(UnkStruct_003F3E60 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_4 = 0;
    self->field_6 = 2;
    int r1 = func_00271A00(&D_0051BA44, 139);
    self->field_15 = 8;
    self->field_8 = r1;
    self->field_10 = 0;
    self->field_14 = 9;
    self->field_16 = 0;
    self->field_18 = 0;
    self->field_C = 0;
    int r2 = func_00271A00(&D_0051BA44, 140);
    self->field_29 = 8;
    self->field_1C = r2;
    self->field_24 = 0;
    self->field_28 = 9;
    self->field_2A = 0;
    self->field_2C = 0;
    self->field_20 = 0;
    func_003BE5A0(&D_01E8961C, ((char *)self + 0x4), ((char *)self + 0x8));
    func_003BC500(&D_01E8961C, 0, D_004F5070.field_0);
    func_003BC500(&D_01E8961C, 1, D_004F5071.field_0);
    func_00319C80(&D_01E89518, 134, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 266, 15);
    D_01E894FC.Prepare();
    return 1;
}
