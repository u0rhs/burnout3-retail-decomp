// func_003F01B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8E5D8.h"
#include "b3/classes/UnkStruct_D_01E8E5E2.h"
#include "b3/classes/UnkStruct_D_01E8F960.h"

struct UnkStruct_003F01B0;

struct UnkStruct_003F01B0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};

extern UnkStruct_D_01E8E5E2 D_01E8E5E2;
extern UnkStruct_D_01E8E5D8 D_01E8E5D8;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E8F960 D_01E8F960;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E89800 D_01E89800;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_004600B0(void *, int, int, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" unsigned long func_0045FF90(void *);
extern "C" bool func_003A6330(void *, int, unsigned long, int, int, int);

// 0x003F01B0
extern "C" int func_003F01B0(UnkStruct_003F01B0 * self, int p0, int p1)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    int v1 = 12;
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    D_01E894FC.Prepare();
    func_004600B0(&D_01E8F960, p0, p1, 0);
    self->field_4 = p0;
    self->field_8 = p1;
    switch (self->field_4) {
    case 0:
        func_00319C80(&D_01E89518, 3251, 14);
        v1 = 15;
        break;
    case 1:
        func_00319C80(&D_01E89518, 677, 14);
        break;
    case 2:
        func_00319C80(&D_01E89518, 690, 14);
        break;
    }
    func_0031ECD0(&D_01E89800, 257, v1);
    if (D_01E8E5E2.field_0 != 0) {
        ((UnkStruct_D_01E8E5D8 *)&D_01E8E5D8)->vfunc_C();
    }
    switch (self->field_4) {
    case 0:
        func_003A6330(&D_01E8E5D8, 0, func_0045FF90(&D_01E8F960), 0, 1, 0);
        break;
    case 1:
        func_003A6330(&D_01E8E5D8, 1, func_0045FF90(&D_01E8F960), 0, 1, 0);
        break;
    case 2:
        func_003A6330(&D_01E8E5D8, 2, func_0045FF90(&D_01E8F960), 0, 1, 0);
        break;
    }
    return 1;
}
