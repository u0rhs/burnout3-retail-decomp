// func_004343F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"

struct UnkStruct_004343F0;

struct UnkStruct_004343F0 {
    unsigned char pad_0[0x4C];
    unsigned char field_4C;
};

extern CB3OnScreenKeyboardComponent D_01E899C0;

// 0x004343F0
extern "C" void func_004343F0(UnkStruct_004343F0 * self)
{
    if (self->field_4C == 1) {
        self->field_4C = 0;
        D_01E899C0.Show(0, 0);
    }
}
