// func_003C60B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
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

struct UnkStruct_003C60B0;

struct UnkStruct_003C60B0 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
};

extern int D_004CA360[];  // [G] element count unknown
extern UnkStruct_D_01E8E5D8 D_01E8E5D8;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E89518 D_01E89518;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" bool func_003A6330(void *, int, unsigned long, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00319C80(void *, int, int);

// 0x003C60B0
extern "C" int func_003C60B0(UnkStruct_003C60B0 * self, int p0, int p1)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_4 = 0;
    func_003A6330(&D_01E8E5D8, 4, 0, p1, 1, 1);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 16, 3);
    func_00319C80(&D_01E89518, D_004CA360[p1], 9);
    D_01E894FC.Prepare();
    return 1;
}
