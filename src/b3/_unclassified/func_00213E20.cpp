// func_00213E20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ControllerMapping.h"
#include "b3/classes/CB3InputManager.h"

struct UnkStruct_00213E20_0;

struct UnkStruct_00213E20_0 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

extern "C" bool func_0012FB50(CB3ControllerMapping *, int);

// 0x00213E20
extern "C" bool func_00213E20(CB3InputManager * self, int p0, signed char p1)
{
    CB3ControllerMapping * local[2];
    signed char i;
    bool m0 = false;
    self->GetAvailableControllers(local, p1);
    for (i = 0; i < 2; i++) {
        if (local[i] != 0) {
            m0 |= func_0012FB50(local[i], p0);
        }
    }
    return m0;
}
