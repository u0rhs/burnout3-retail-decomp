// func_0037ED80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"

extern CB3OnScreenKeyboardComponent D_01E899C0;

// 0x0037ED80
extern "C" void func_0037ED80()
{
    D_01E899C0.UnRegisterKeyboardCallbacks();
}
