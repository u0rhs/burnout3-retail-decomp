// func_0045BF40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004D36D0.h"
#include "b3/classes/UnkStruct_D_004D36F0.h"
#include "b3/classes/UnkStruct_D_004D3700.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E8961C.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

struct UnkStruct_0045BF40;
struct UnkStruct_0045BF40_1;

struct UnkStruct_0045BF40_1 {
    int field_0;
    short field_4;
    short field_6;
};

struct UnkStruct_0045BF40 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    short field_10;
    short field_12;
    int field_14;
    int field_18;
    void * field_1C;
    unsigned char field_20;
    unsigned char field_21;
    unsigned char field_22;
    unsigned char pad_23[0x1];
    int field_24;
    int field_28;
    int field_2C;
    void * field_30;
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
    unsigned char pad_37[0x1];
    int field_38;
    int field_3C;
    int field_40;
    void * field_44;
    unsigned char field_48;
    unsigned char field_49;
    unsigned char field_4A;
    unsigned char pad_4B[0x1];
    int field_4C;
    UnkStruct_0045BF40_1 * field_50;
};

extern int D_004D3730[];  // [G] element count unknown
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004D36D0 D_004D36D0;
extern UnkStruct_D_004D36F0 D_004D36F0;
extern UnkStruct_D_004D3700 D_004D3700;
extern UnkStruct_D_01E8961C D_01E8961C;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);

// 0x0045BF40
extern "C" int func_0045BF40(UnkStruct_0045BF40 * self, UnkStruct_0045BF40_1 * p0)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_50 = p0;
    func_00319C80(&D_01E89518, 3163, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 0x10000000041, 0);
    D_01E894FC.Prepare();
    self->field_10 = 0;
    self->field_12 = 3;
    int r5 = func_00271A00(&D_0051BA44, 718);
    self->field_14 = r5;
    self->field_1C = &D_004D36D0;
    self->field_20 = 6;
    self->field_21 = 4;
    self->field_22 = 0;
    self->field_24 = 0;
    self->field_18 = 0;
    int r6 = func_00271A00(&D_0051BA44, 976);
    self->field_28 = r6;
    self->field_30 = &D_004D36F0;
    self->field_34 = 4;
    self->field_35 = 4;
    self->field_36 = 0;
    self->field_38 = 0;
    self->field_2C = 0;
    int r7 = func_00271A00(&D_0051BA44, 1026);
    self->field_3C = r7;
    self->field_44 = &D_004D3700;
    self->field_48 = 11;
    self->field_49 = 4;
    self->field_4A = 0;
    self->field_4C = 0;
    self->field_40 = 0;
    func_003BE5A0(&D_01E8961C, ((char *)self + 0x10), ((char *)self + 0x14));
    self->field_8 = self->field_50->field_4;
    self->field_4 = 0;
    self->field_C = self->field_50->field_6;
    for (unsigned int i = 0; i < 11; i++) {
        if (self->field_50->field_0 == D_004D3730[i]) {
            self->field_4 = i;
            break;
        }
    }
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_C);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_8);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_4);
    return 1;
}
