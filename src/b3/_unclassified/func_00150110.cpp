// func_00150110 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/EB3ScoreFinishState.h"

// 0x00150110
extern "C" void func_00150110(CB3RaceCar *self)
{
    self->Update();
}
