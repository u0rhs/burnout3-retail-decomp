// func_0038D680 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3StageLogic.h"
#include "b3/classes/UnkStruct_D_00522660.h"
#include "b3/classes/UnkStruct_D_0064D37C.h"

extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_00522660 D_00522660;

// 0x0038D680
extern "C" void func_0038D680(CB3StageLogic * self)
{
    for (int i = 0; (i < D_0064D37C.field_0); i++) {
        D_00522660.field_12AD28[i]->field_1390 = 30.0f;
    }
    self->OnWorldPrepared();
}
