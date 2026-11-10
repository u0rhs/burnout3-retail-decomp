// func_004457C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89800.h"

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int FindCrashStageName__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x004457C0
extern "C" int func_004457C0(void *n0_)
{
    int n0 = (int)n0_;
    UnkStruct_00154A30_4 * t0 = D_0051BA88.field_0;
    t0->field_1B4->vfunc_3C();
    Prepare__15CB3MenuPageBaseFb((void *)n0, 0);
    int r2 = FindCrashStageName__26CB3HardCodedCrashStageListFUl(t0->field_68);
    func_00319C80(&D_01E89518, r2, 5);
    func_0031ECD0(&D_01E89800, 16, 3);
    D_01E894FC.Prepare();
    return 1;
}
