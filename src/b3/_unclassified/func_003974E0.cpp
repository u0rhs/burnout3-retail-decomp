// func_003974E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/EGlobalStrings.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CB3OnScreenKeyboardComponent D_01E899C0;

// 0x003974E0
extern "C" void func_003974E0()
{
    D_01E899C0.UnRegisterKeyboardCallbacks();
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_CC(0, 0);
}
