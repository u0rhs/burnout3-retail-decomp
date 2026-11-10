// func_003F0700 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8EB40.h"
#include "b3/classes/UnkStruct_D_01E8EC30.h"

struct UnkStruct_003F0700;

struct UnkStruct_003F0700 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned long field_8;
    unsigned char field_10;
};

extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E8EC30 D_01E8EC30;
extern UnkStruct_D_01E8EB40 D_01E8EB40;
extern UnkStruct_D_01E89788 D_01E89788;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFv(void *);  // CB3HelpBarComponent::Prepare()
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" void func_0042CFA0(void *, int, int, int, int, int, int, int);
extern "C" int func_0042B030(void *, int, int);
extern "C" int GetEntryCount__20CB3CarouselComponentFv(void *);
extern "C" int func_0042BC70(void *);
extern "C" unsigned long func_0042B700(void *, int);
extern "C" void func_0042B010(void *, unsigned long, int);
extern "C" int func_0042B5F0(void *, int);

// 0x003F0700
extern "C" int func_003F0700(UnkStruct_003F0700 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)11);
    func_0031ECD0(&D_01E89800, 257, 15);
    D_01E894FC.Prepare();
    func_00319C80(&D_01E89518, 456, 14);
    func_0042CFA0(&D_01E8EC30, 9, -1, 0, 0, 1, 1, 0);
    func_0042B030(&D_01E8EB40, 0, 1);
    Prepare__19CB3HelpBarComponentFv(&D_01E89788);
    self->field_10 = 1;
    int r8 = GetEntryCount__20CB3CarouselComponentFv(&D_01E8EC30);
    self->field_4 = r8;
    unsigned long r10;
    int r9 = func_0042BC70(&D_01E8EC30);
    r10 = func_0042B700(&D_01E8EC30, r9);
    if (r10 == 0) {
        func_0042B010(&D_01E8EB40, 0, 0);
    } else {
        func_0042B010(&D_01E8EB40, r10, func_0042B5F0(&D_01E8EC30, r9));
    }
    self->field_8 = 0;
    return 1;
}
