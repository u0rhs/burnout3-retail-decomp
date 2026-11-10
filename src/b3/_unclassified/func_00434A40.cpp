// func_00434A40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_00516DF4.h"
#include "b3/classes/UnkStruct_D_00516E18.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E8961C.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E90438.h"

struct UnkStruct_00434A40;
struct UnkStruct_00434A40_1;
struct UnkStruct_00434A40_2;

struct UnkStruct_00434A40_1 {
    short field_0;
};

struct UnkStruct_00434A40_2 {
    short field_0;
};

struct UnkStruct_00434A40 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    void * field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char pad_13[0x1];
    int field_14;
    int field_18;
    int field_1C;
    void * field_20;
    unsigned char field_24;
    unsigned char field_25;
    unsigned char field_26;
    unsigned char pad_27[0x1];
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    unsigned char field_38;
    unsigned char field_39;
    unsigned char field_3A;
    unsigned char pad_3B[0x1];
    int field_3C;
    UnkStruct_00434A40_1 * field_40;
    UnkStruct_00434A40_2 * field_44;
    short field_48;
    short field_4A;
    unsigned char field_4C;
};

extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_00516DF4 D_00516DF4;
extern UnkStruct_D_00516E18 D_00516E18;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E8961C D_01E8961C;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, void *);
extern "C" int func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" int func_003517F0(void *);

// 0x00434A40
extern "C" int func_00434A40(UnkStruct_00434A40 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 9);
    self->field_40 = (UnkStruct_00434A40_1 *)r1;
    self->field_40->field_0 = 0;
    int r2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 9);
    self->field_44 = (UnkStruct_00434A40_2 *)r2;
    self->field_44->field_0 = 0;
    func_00319C80(&D_01E89518, 440, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_40, 9, &D_00516DF4);
    CopyN__10CGtUnicodeFPUsiPCUs(self->field_44, 9, &D_00516E18);
    self->field_48 = 0;
    self->field_4A = 3;
    UnkStruct_00434A40_1 * t0 = self->field_40;
    int r9 = func_00271A00(&D_0051BA44, 441);
    self->field_4 = r9;
    self->field_C = (void *)t0;
    self->field_10 = 1;
    self->field_11 = 1;
    self->field_12 = 0;
    self->field_14 = 0;
    self->field_8 = 0;
    UnkStruct_00434A40_2 * t1 = self->field_44;
    int r10 = func_00271A00(&D_0051BA44, 442);
    self->field_18 = r10;
    self->field_20 = (void *)t1;
    self->field_24 = 1;
    self->field_25 = 1;
    self->field_26 = 0;
    self->field_28 = 0;
    self->field_1C = 0;
    int r11 = func_00271A00(&D_0051BA44, 307);
    self->field_2C = r11;
    self->field_34 = 0;
    self->field_38 = 0;
    self->field_39 = 0;
    self->field_3A = 0;
    self->field_3C = 0;
    self->field_30 = 0;
    func_003BE5A0(&D_01E8961C, ((char *)self + 0x48), ((char *)self + 0x4));
    self->field_4C = 0;
    func_003517F0(&D_01E899C0);
    D_01E899C0.RegisterKeyboardCallbacks();
    return 1;
}
