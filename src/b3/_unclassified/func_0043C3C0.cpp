// func_0043C3C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01EA5470.h"

extern UnkStruct_D_01EA5470 D_01EA5470;
extern UnkStruct_D_01E89518 D_01E89518;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_003C22A0(void *, unsigned int);
extern "C" void func_00272E50(void *);
extern "C" void func_00319C80(void *, int, int);
extern "C" void func_0043B770(void *);

// 0x0043C3C0
// pass1: a1 (an id, 0x220000 from func_003F7150) goes to func_003C22A0 untouched
extern "C" int func_0043C3C0(void *n0_, unsigned int id)
{
    int n0 = (int)n0_;
    func_003C22A0((void *)(n0), id);
    for (int i = 0; (i < 8); i++) {
        func_00272E50(&D_01EA5470.field_0[i]);
    }
    func_00319C80(&D_01E89518, 598, 14);
    D_01E894FC.Prepare();
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)8);
    func_0043B770((void *)(n0));
    return 1;
}
