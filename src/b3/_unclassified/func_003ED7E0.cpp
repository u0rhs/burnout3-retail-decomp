// func_003ED7E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_0051A998.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E90438.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

struct UnkStruct_003ED7E0;

struct UnkStruct_003ED7E0 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};

extern UnkStruct_D_0051A998 D_0051A998;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00319C80(void *, int, int);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_003ECCD0(UnkStruct_003ED7E0 *, int);
extern "C" void StartLoadProfileFlow__24CB3MemCardControllerBaseFv(void *);

// 0x003ED7E0
extern "C" int func_003ED7E0(UnkStruct_003ED7E0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)1);
    func_00319C80(&D_01E89518, 423, 14);
    int r3 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 256);
    self->field_8 = r3;
    if (D_0051A998.field_0 == 0) {
        self->field_4 = 0;
        func_003ECCD0(self, 0);
    } else {
        self->field_4 = 1;
        func_003ECCD0(self, 1);
        StartLoadProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
    }
    D_01E894FC.Prepare();
    return 1;
}
