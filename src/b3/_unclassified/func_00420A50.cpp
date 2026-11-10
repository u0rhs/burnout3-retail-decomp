// func_00420A50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004F507F.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E90438.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

struct UnkStruct_00420A50;

struct UnkStruct_00420A50 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
};

extern UnkStruct_D_004F507F D_004F507F;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89518 D_01E89518;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00319C80(void *, int, int);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_0041FE00(UnkStruct_00420A50 *, int);
extern "C" void StartSaveProfileFlow__24CB3MemCardControllerBaseFv(void *);

// 0x00420A50
extern "C" int func_00420A50(UnkStruct_00420A50 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    if (D_004F507F.field_0 != 0) {
        func_00319C80(&D_01E89518, 433, 14);
    } else {
        func_00319C80(&D_01E89518, 424, 14);
    }
    D_01E894FC.Prepare();
    int r5 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 256);
    self->field_C = r5;
    self->field_8 = 0;
    if (D_004F507F.field_0 != 0) {
        self->field_4 = 2;
        func_0041FE00(self, 0);
        StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
    } else {
        self->field_4 = 0;
        func_0041FE00(self, 6);
    }
    return 1;
}
