// func_0022B850 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ControllerMapping.h"
#include "b3/classes/CB3InputManager.h"

struct UnkStruct_0022B850_0;

struct UnkStruct_0022B850_0 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

extern "C" int func_0012F460(CB3ControllerMapping *);

// 0x0022B850
extern "C" bool func_0022B850(CB3InputManager * self)
{
    CB3ControllerMapping * maps[2];
    signed char i;
    bool r = false;
    self->GetAvailableControllers(maps, 0);
    for (i = 0; i < 2; i++) {
        if (maps[i] != 0) {
            r = r || func_0012F460(maps[i]);
        }
    }
    return r;
}
