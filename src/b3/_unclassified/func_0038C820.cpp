// func_0038C820 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3StageLogic.h"

struct UnkStruct_00389A50_a1;

extern "C" void func_00389A50(CB3StageLogic *, UnkStruct_00389A50_a1 *);

// 0x0038C820
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_0038C820(CB3StageLogic *self, UnkStruct_00389A50_a1 *p0)
{
    func_00389A50(self, p0);
}
