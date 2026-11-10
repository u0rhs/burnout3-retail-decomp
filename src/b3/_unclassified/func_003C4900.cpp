// func_003C4900 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3InputManager.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"

struct UnkStruct_003C4900;

struct UnkStruct_003C4900 {
    unsigned char pad_0[0x8];
    float field_8;
};

extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_004F50A0 D_004F50A0;
extern CB3InputManager D_004F50C0;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" void func_003C47C0(UnkStruct_003C4900 *);

// 0x003C4900
extern "C" int func_003C4900(UnkStruct_003C4900 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 1);
    D_004F50C0.ResetDeadInputTime(0);
    D_004F50C0.ResetDeadInputTime(1);
    int r3 = D_0051BA88.field_0->field_1B4->vfunc_9C();
    if (r3 != 0) {
        self->field_8 = -1.0f;
        func_003C47C0(self);
    } else {
        self->field_8 = (1.0f + D_004F50A0.field_0);
    }
    return 1;
}
