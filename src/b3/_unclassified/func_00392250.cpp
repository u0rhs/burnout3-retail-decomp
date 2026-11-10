// func_00392250 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_00522660.h"
#include "b3/classes/UnkStruct_D_00665E50.h"
#include "b3/classes/UnkStruct_D_00665E51.h"

struct UnkStruct_00392250;

struct UnkStruct_00392250 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
};

extern UnkStruct_D_00665E50 D_00665E50;
extern UnkStruct_D_00665E51 D_00665E51;
extern UnkStruct_D_00522660 D_00522660;
extern "C" void Stop__8CGtTimerFv(void *);
extern "C" void Start__8CGtTimerFv(void *);

// 0x00392250
extern "C" void func_00392250(UnkStruct_00392250 * self)
{
    D_00665E50.field_0 = 0;
    if (D_00665E50.field_0 != 0) {
        Stop__8CGtTimerFv(&D_00522660);
    } else {
        if (D_00665E51.field_0 == 0) {
            Start__8CGtTimerFv(&D_00522660);
        }
    }
    self->vfunc_8();
}
