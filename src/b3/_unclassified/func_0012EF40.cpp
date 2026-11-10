// func_0012EF40 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGtInputDevicePS2DualShock.h"

struct UnkStruct_0012EF40 {
    unsigned char pad_0[0x4];
    CGtInputDevicePS2DualShock * field_4;
};

// 0x0012EF40
extern "C" unsigned char func_0012EF40(UnkStruct_0012EF40 *self)
{
    return self->field_4->IsConnected();
}
