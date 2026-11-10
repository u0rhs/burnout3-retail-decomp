// func_001AD850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0066C580.h"
#include "b3/classes/UnkStruct_D_0066C584.h"
#include "b3/classes/UnkStruct_D_0066C588.h"
#include "b3/classes/UnkStruct_D_0066C590.h"
#include "b3/classes/UnkStruct_D_0066DD90.h"

struct UnkStruct_001AD850;

struct UnkStruct_001AD850 {
    unsigned char pad_0[0x200];
    void * field_200;
    int field_204;
    unsigned char pad_208[0xD];
    unsigned char field_215;
};

extern UnkStruct_D_0066C580 D_0066C580;
extern UnkStruct_D_0066C584 D_0066C584;
extern UnkStruct_D_0066C588 D_0066C588;
extern UnkStruct_D_0066C590 D_0066C590;
extern UnkStruct_D_0066DD90 D_0066DD90;
extern "C" bool func_001AD380(UnkStruct_001AD850 *);

// Returns the tail call's value (retail `j func_001AD380`: v0 passes through to the caller).
// 0x001AD850
extern "C" bool func_001AD850(UnkStruct_001AD850 * self)
{
    self->field_215 = 0;
    self->field_204 = 0;
    self->field_200 = &D_0066C580;
    D_0066C580.field_0 = 0;
    D_0066C584.field_0 = &D_0066C590;
    D_0066C588.field_0 = &D_0066DD90;
    return func_001AD380(self);
}
