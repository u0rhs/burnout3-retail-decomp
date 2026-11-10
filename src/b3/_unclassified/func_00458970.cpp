// func_00458970 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"

struct UnkStruct_00458970;

struct UnkStruct_00458970 {
    int field_0;
};

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x00458970
extern "C" void func_00458970(UnkStruct_00458970 * self, void *p0_, int p1)
{
    int p0 = (int)p0_;
    DestructObject__10CGt2dSceneFiP11CGt2dObject((void *)p0, p1, (CGt2dObject*)self->field_0);
    self->field_0 = 0;
}
