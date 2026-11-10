// func_00459770 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"

struct UnkStruct_00459770;

struct UnkStruct_00459770 {
    unsigned char pad_0[0xD4D];
    signed char field_D4D;
};

extern CB3OnScreenKeyboardComponent D_01E899C0;

// 0x00459770
extern "C" void func_00459770(UnkStruct_00459770 * self)
{
    if (self->field_D4D == 3) {
        self->field_D4D = 1;
        D_01E899C0.Show(0, 1);
    }
}
