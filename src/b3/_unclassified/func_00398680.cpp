// OnKeyboardCancel__30CB3OnlineGameCreateOptionsPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"

struct UnkStruct_00398680;

struct UnkStruct_00398680 {
    unsigned char pad_0[0xE0];
    int field_E0;
};

extern CB3OnScreenKeyboardComponent D_01E899C0;

// 0x00398680
extern "C" void OnKeyboardCancel__30CB3OnlineGameCreateOptionsPageFv(UnkStruct_00398680 * self)
{
    self->field_E0 = 0;
    D_01E899C0.UnRegisterKeyboardCallbacks();
    D_01E899C0.Show(0, 0);
}
