// func_00134930 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_006481A0.h"

extern UnkStruct_D_006481A0 D_006481A0;
extern "C" int func_0014E860(void *);

// Returns the tail call's value (retail `j func_0014E860`: v0 passes through to the caller).
// 0x00134930
extern "C" int func_00134930()
{
    return func_0014E860(&D_006481A0);
}
