// func_003EF7F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89518.h"
#include "b3/classes/UnkStruct_D_01E90438.h"
#include "b3/classes/UnkStruct_D_01ECD520.h"

struct UnkStruct_003EF7F0;

struct UnkStruct_003EF7F0 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3];
    int field_8;
    unsigned char pad_C[0x4];
    int field_10;
    int field_14[1];  // [G] element count unknown
    unsigned char pad_18[0xC];
    int field_24;
};

extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" void func_003EE470(UnkStruct_003EF7F0 *, int);
extern "C" void StartSaveProfileFlow__24CB3MemCardControllerBaseFv(void *);
extern "C" int func_003517F0(void *);

// 0x003EF7F0
extern "C" int func_003EF7F0(UnkStruct_003EF7F0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)1);
    D_01E894FC.Prepare();
    int r3 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 256);
    self->field_10 = r3;
    for (int i = 0; (i < 3); i++) {
        int r4 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 18);
        self->field_14[i] = r4;
    }
    if (self->field_4 != 0) {
        func_00319C80(&D_01E89518, 426, 14);
        self->field_24 = 0;
    } else {
        func_00319C80(&D_01E89518, 424, 14);
        self->field_24 = 0;
    }
    if (self->field_4 != 0) {
        self->field_8 = 15;
        func_003EE470(self, 13);
    } else {
        self->field_8 = 0;
        func_003EE470(self, 0);
        StartSaveProfileFlow__24CB3MemCardControllerBaseFv(&D_01ECD520);
    }
    func_003517F0(&D_01E899C0);
    D_01E899C0.RegisterKeyboardCallbacks();
    return 1;
}
