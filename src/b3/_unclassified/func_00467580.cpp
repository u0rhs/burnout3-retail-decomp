// func_00467580 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC8.h"
#include "b3/classes/UnkStruct_D_004E2FCC.h"

struct UnkStruct_00467580;

struct UnkStruct_00467580 {
    int field_0;
};

extern UnkStruct_D_004E2FCC D_004E2FCC;
extern UnkStruct_D_004E2FC8 D_004E2FC8;
extern "C" void * memcpy(void *, const void *, unsigned int);

// 0x00467580
extern "C" int func_00467580(UnkStruct_00467580 * self)
{
    if ((D_004E2FCC.field_0 != 0) == false) {
        return 2;
    }
    if (self == 0) {
        return 12;
    }
    UnkStruct_00467580_2 * t0 = D_004E2FC8.field_0;
    if (t0->field_0 == 0) {
        memcpy(((char *)t0 + 0xC), self, 96);
        D_004E2FC8.field_0->field_0 = 7;
        D_004E2FC8.field_0->field_4 = 24;
        ((void (*)(int, int))D_004E2FCC.field_0->field_38)(self->field_0, 7);
        return 0;
    }
    return 13;
}
