// func_00352130 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01E90438.h"

struct UnkStruct_00352130;

struct UnkStruct_00352130 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, int, int);
extern "C" void func_0032CF60(void *, int, void *, int, int);

// 0x00352130
extern "C" int func_00352130(UnkStruct_00352130 * self, int p0, void *p1_, int p2)
{
    int p1 = (int)p1_;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 8, 3);
    D_01E894FC.Prepare();
    func_00319C80(&D_01E89518, p0, 14);
    int r5 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 256);
    self->field_4 = r5;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(p1, self->field_4, 256);
    func_0032CF60(&D_01E898E8, p2, (void *)(self->field_4), 15, 0);
    return 1;
}
