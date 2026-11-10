// OnKeyboardCancel__26CB3OnlineOptimatchMenuPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"

struct UnkStruct_0037C520;

struct UnkStruct_0037C520 {
    unsigned char pad_0[0x50];
    unsigned char field_50;
};

extern CB3OnScreenKeyboardComponent D_01E899C0;

// 0x0037C520
extern "C" void OnKeyboardCancel__26CB3OnlineOptimatchMenuPageFv(UnkStruct_0037C520 * self)
{
    if (self->field_50 == 1) {
        self->field_50 = 0;
        D_01E899C0.Show(0, 0);
    }
}
