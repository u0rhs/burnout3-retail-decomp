// func_00393360 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_0051BAD6.h"
#include "b3/classes/UnkStruct_D_00665EA0.h"
#include "b3/classes/UnkStruct_D_00665EA1.h"
#include "b3/classes/UnkStruct_D_00665EC0.h"

struct UnkStruct_00393360;

struct UnkStruct_00393360 {
    unsigned char pad_0[0x51];
    unsigned char field_51;
};

extern UnkStruct_D_0051BAD6 D_0051BAD6;
extern UnkStruct_D_00665EA0 D_00665EA0;
extern UnkStruct_D_00665EA1 D_00665EA1;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_00665EC0 D_00665EC0;
extern "C" void func_003960A0();
extern "C" int func_00131CA0(void *);
extern "C" void func_0019E760(void *);

// 0x00393360
extern "C" void func_00393360(UnkStruct_00393360 * self)
{
    self->field_51 = 1;
    D_0051BAD6.field_0 = 1;
    func_003960A0();
    int r1 = func_00131CA0(&D_004EE040);
    if (r1 != 0) {
        func_0019E760(&D_00665EC0);
    }
    D_00665EA0.field_0 = 0;
    D_00665EA1.field_0 = 0;
}
