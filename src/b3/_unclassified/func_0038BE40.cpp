// func_0038BE40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3StageLogic.h"
#include "b3/classes/UnkStruct_D_00522660.h"
#include "b3/classes/UnkStruct_D_0064D37C.h"

struct UnkStruct_0038BE40;

struct UnkStruct_0038BE40 {
    unsigned char pad_0[0x4C];
    int field_4C;
};

extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_00522660 D_00522660;
extern "C" void OnWorldPrepared__13CB3StageLogicFv(void *);  // CB3StageLogic::OnWorldPrepared()

// 0x0038BE40
extern "C" void func_0038BE40(UnkStruct_0038BE40 * self)
{
    OnWorldPrepared__13CB3StageLogicFv(self);
    self->field_4C = 0;
    for (int i = 0; (i < D_0064D37C.field_0); i++) {
        D_00522660.field_12AD28[i]->field_1384 = (D_0064D37C.field_0 + -1);
    }
}
