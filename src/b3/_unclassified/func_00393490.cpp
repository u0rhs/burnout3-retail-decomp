// func_00393490 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3RaceCarPhysics.h"
#include "b3/classes/CB3StageLogic.h"

// 0x00393490
extern "C" void func_00393490(CB3StageLogic *self, CB3RaceCarPhysics* p0)
{
    self->OnPostCrashReset(p0);
}
