// func_001A9D60 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3NetworkMessage.h"

// 0x001A9D60
extern "C" void func_001A9D60(CB3NetworkMessage *self, int a1 /* passed by every caller, not read here */)
{
    self->Prepare(8, 0);
}
