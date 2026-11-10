// func_00453DC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8F090.h"

extern UnkStruct_D_01E8F090 D_01E8F090;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_0044D400(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x00453DC0
extern "C" int func_00453DC0(void *n0_, int p0)
{
    int n0 = (int)n0_;
    Prepare__15CB3MenuPageBaseFb((void *)n0, 0);
    int v1;
    int v0;
    switch (p0) {
    default:
        v1 = 883;
        v0 = 8;
        break;
    case 1:
        v1 = 2550;
        v0 = 9;
        break;
    case 2:
        v1 = 2540;
        v0 = 7;
        break;
    }
    func_0044D400(&D_01E8F090, p0);
    func_00319C80(&D_01E89518, v1, v0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 16, 3);
    D_01E894FC.Prepare();
    return 1;
}
