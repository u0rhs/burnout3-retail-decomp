// func_0043FA90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
#include "b3/classes/UnkStruct_D_004E2F60.h"
#include "b3/classes/UnkStruct_D_004E2F68.h"
#include "b3/classes/UnkStruct_D_004E2F70.h"
#include "b3/classes/UnkStruct_D_004E2F78.h"
#include "b3/classes/UnkStruct_D_004E2F80.h"
#include "b3/classes/UnkStruct_D_01E88A80.h"
#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8F940.h"
#include "b3/classes/UnkStruct_D_01ECDEE0.h"

struct UnkStruct_0043FA90;
struct UnkStruct_0043FA90_0;

struct UnkStruct_0043FA90_0 {
    int field_0;
};

struct UnkStruct_0043FA90 {
    unsigned char pad_0[0x64];
    int field_64;
    int field_68;
};

extern UnkStruct_D_01E8F940 D_01E8F940;
extern UnkStruct_D_004E2F60 D_004E2F60;
extern UnkStruct_D_004E2F68 D_004E2F68;
extern UnkStruct_D_004E2F70 D_004E2F70;
extern UnkStruct_D_01ECDEE0 D_01ECDEE0;
extern UnkStruct_D_004E2F78 D_004E2F78;
extern UnkStruct_D_004E2F80 D_004E2F80;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" int func_00456780(void *, UnkStruct_0043FA90_0 *, void *, void *, void *, void *, void *, void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_0043F680(UnkStruct_0043FA90 *);

// 0x0043FA90
extern "C" int func_0043FA90(UnkStruct_0043FA90 * self, int p0)
{
    UnkStruct_0043FA90_0 local;  // [G] the frame's one local (size: up to the frame top)
    Prepare__15CB3MenuPageBaseFb(self, 0);
    local.field_0 = 137;
    func_00456780(&D_01E8F940, &local, &D_004E2F60, &D_004E2F68, &D_004E2F70, &D_01ECDEE0, &D_004E2F78, &D_004E2F80, 1);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    self->field_64 = p0;
    if (self->field_64 == 0) {
        self->field_68 = 0;
    }
    func_0043F680(self);
    return 1;
}
