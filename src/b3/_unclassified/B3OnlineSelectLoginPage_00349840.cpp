// CB3OnlineSelectLoginPage::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/CB3OnlineSelectLoginPage.h"
#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_004C6EB0.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E90438.h"

extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_004C6EB0 D_004C6EB0;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short*, bool, float);  // CB3HelpBarComponent::Prepare(const unsigned short*,bool,float)
extern "C" char * strcpy(char *, const char *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_003517F0(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003496C0(CB3OnlineSelectLoginPage *);

// 0x00349840
int CB3OnlineSelectLoginPage::Prepare()
{
    Prepare__15CB3MenuPageBaseFb(this, 0);
    int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 50);
    field_F4 = r1;
    int r2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    field_15C = r2;
    int r3 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    field_160 = r3;
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    func_003517F0(&D_01E899C0);
    int r8 = func_00271A00(&D_0051BA44, 192);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short*)r8, 1, 80.0f);
    D_01E899C0.RegisterKeyboardCallbacks();
    strcpy((char *)((char *)this + 0x4), (const char *)&D_004C6EB0);
    strcpy((char *)((char *)this + 0x36), (const char *)&D_004C6EB0);
    if (field_68 == 0) {
        func_003496C0(this);
        field_F0 = 0;
        field_F2 = 1;
    } else {
        PrepareExistingAccountControls();
    }
    field_68 = 0;
    field_164 = 0;
    return 1;
}
