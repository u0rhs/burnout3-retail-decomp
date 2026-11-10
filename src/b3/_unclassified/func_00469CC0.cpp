// func_00469CC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E8F360.h"
#include "b3/classes/UnkStruct_D_01E8F36A.h"

extern UnkStruct_D_01E8F36A D_01E8F36A;
extern UnkStruct_D_01E8F360 D_01E8F360;
extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00319C80(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x00469CC0
extern "C" int func_00469CC0(void *n0_)
{
    int n0 = (int)n0_;
    Prepare__15CB3MenuPageBaseFb((void *)n0, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)1);
    func_00319C80(&D_01E89518, 3064, 14);
    if (D_01E8F36A.field_0 != 0) {
        ((UnkStruct_D_01E8F360 *)&D_01E8F360)->vfunc_C();
    }
    func_0032D080(&D_01E898E8, 7, 2265, 5, 1);
    if (D_01E8980A.field_0 != 0) {
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    }
    func_0031ECD0(&D_01E89800, 265, 3);
    D_01E894FC.Prepare();
    return 1;
}
