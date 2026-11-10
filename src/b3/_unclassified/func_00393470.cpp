// func_00393470 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OfflineStageLogic.h"
#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/EB3ScoreFinishState.h"

// 0x00393470
extern "C" void func_00393470(CB3OfflineStageLogic *self, CB3RaceCar* p0, CB3RaceCar* p1)
{
    self->OnTakedown(p0, p1);
}
